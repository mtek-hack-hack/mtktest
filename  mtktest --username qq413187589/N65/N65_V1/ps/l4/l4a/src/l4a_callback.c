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
 *	l4a_callback.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for L4A callback functions.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifdef __MOD_L4A__


#ifdef __MMI_FMI__
#include "kal_release.h"      	/* Basic data type */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */
#include "stacklib.h"        	/* Basic type for dll, evshed, stacktimer */
#include "app_buff_alloc.h"
#include "stack_timer.h"
#include "event_shed.h"
#include "syscomp_config.h"
#include "task_config.h"
#include "custom_config.h"

#include "l4a.h"
#include "l4a_cmd.h"
#include "l4a_callback.h"

#include "l3_inc_enums.h"

/*Brad Begin*/
#include "smsal_peer_struct.h"
#include "mnsms_struct.h"
#include "smsal_structs.h"
#include "smsal_utils.h"

/*Brad End*/

#include "l4c_context.h"
#include "layer4_context.h"
#include "Wapadp.h"

#include <stdarg.h>

/* l4a_cmd_ft */
/******************************************************************************************
 * macro
 ******************************************************************************************/

/*
* FUNCTION
*	NONE_FUNCTION
* DESCRIPTION
*   an error function, put in function table.
*   when protocol stack running, this function should not be executed.
*
* CALLS
*	CALL_FUNC macro
*	SEND_FUNC macro
* PARAMETERS
* 	none
* RETURNS
*   KAL_FALSE
* GLOBALS AFFECTED
*   none
*/

kal_bool NONE_FUNCTION()
{
	kal_print("WRONG FUNCTION !!\n");
	return KAL_FALSE;
}

/******************************************************************************************
 * message structure
 ******************************************************************************************/
#ifdef NONE
#undef NONE
#endif
#define NONE

/*
* FUNCTION
*	message member macro
* DESCRIPTION
*   define message member macro, each type and each array size should be assign a new type.
*
* CALLS
*	MSGSTRUCT macro
* PARAMETERS
* 	x : postfix string for message member name. ( In l4a, x should be number )
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/

/*MTK:BEGIN:generate_member_delcare_macro*/
#define m9A_k_8(x) kal_uint8 a##x[9];
#define mS_k_bool(x) kal_bool a##x;
#define mS_k_16(x) kal_uint16 a##x;
#define mS_k_32(x) kal_uint32 a##x;
#define mS_k_8(x) kal_uint8 a##x;
#define mS_l_call_list_s(x) l4c_call_list_struct a##x;
#define mS_l_number_s(x) l4c_number_struct a##x;
#define mS_l_sub_addr_s(x) l4c_sub_addr_struct a##x;
#define m80A_k_8(x) kal_uint8 a##x[80];
#define mS_l_result_s(x) l4c_result_struct a##x;
#define m30A_k_8(x) kal_uint8 a##x[30];
#define m32A_k_8(x) kal_uint8 a##x[32];
#define m4A_k_8(x) kal_uint8 a##x[4];
#define mS_l4_name_s(x) l4_name_struct a##x;
#define m13A_forwarding_list_s(x) forwarding_list_struct a##x[13];
#define m13A_k_8(x) kal_uint8 a##x[13];
#define m13A_barring_list_s(x) barring_list_struct a##x[13];
#define m183A_k_8(x) kal_uint8 a##x[183];
#define m21A_k_8(x) kal_uint8 a##x[21];
#define mS_l_ss_string_info_s(x) l4c_ss_string_info_struct a##x;
#define mS_ccbs_list_s(x) ccbs_list_struct a##x;
#define mS_k_8_p(x) kal_uint8* a##x;
#define m300A_k_8(x) kal_uint8 a##x[300];
#define m50A_k_wchar(x) kal_wchar a##x[50];
#define mS_audio_profile_s(x) audio_profile_struct a##x;
#define mS_audio_param_s(x) audio_param_struct a##x;
#define mS_k_int32(x) kal_int32 a##x;
#define mS_l_hw_profile_s(x) l4c_hw_profile_struct a##x;
#define m10A_k_8(x) kal_uint8 a##x[10];
#define mS_rtc_alarm_info_s(x) rtc_alarm_info_struct a##x;
#define m3A_rtc_alarm_info_s(x) rtc_alarm_info_struct a##x[3];
#define mS_void_p(x) void* a##x;
#define mS_eventid(x) eventid a##x;
#define mS_rtc_format_s(x) rtc_format_struct a##x;
#define mS_mmi_at_alarm_info_s_p(x) mmi_at_alarm_info_struct* a##x;
#define mS_mmi_at_alarm_info_s(x) mmi_at_alarm_info_struct a##x;
#define mS_drv_get_key_func(x) drv_get_key_func a##x;
#define m62A_k_8(x) kal_uint8 a##x[62];
#define mS_pmic_config_param_s(x) pmic_config_param_struct a##x;
#define mS_rf_test_gsm_param_s(x) rf_test_gsm_param_struct a##x;
#define mS_fm_radio_config_param_s(x) fm_radio_config_param_struct a##x;
#define mS_rf_test_wifi_param_s(x) rf_test_wifi_param_struct a##x;
#define m1A_k_8(x) kal_uint8 a##x[1];
#define mS_module_type(x) module_type a##x;
#define mS_UART_PORT(x) UART_PORT a##x;
#define m16A_k_8(x) kal_uint8 a##x[16];
#define m3A_k_8(x) kal_uint8 a##x[3];
#define mv0A_k_8(x) kal_uint8 a##x[MAX_PLMN_LEN+1];
#define m16A_l_rat_plmn_info_s(x) l4c_rat_plmn_info_struct a##x[16];
#define m2A_k_8(x) kal_uint8 a##x[2];
#define m24A_k_8(x) kal_uint8 a##x[24];
#define mS_l_nw_time_zone_time_s(x) l4c_nw_time_zone_time_struct a##x;
#define m17A_k_8(x) kal_uint8 a##x[17];
#define mS_sim_chv_info_s(x) sim_chv_info_struct a##x;
#define mv1A_k_8(x) kal_uint8 a##x[MAX_SUPPORT_EF_PLMNSEL_REC*7];
#define mv2A_k_8(x) kal_uint8 a##x[MAX_SUPPORT_EF_PLMNSEL_REC*2];
#define m18A_k_8(x) kal_uint8 a##x[18];
#define m256A_k_8(x) kal_uint8 a##x[256];
#define m260A_k_8(x) kal_uint8 a##x[260];
#define m6A_k_8(x) kal_uint8 a##x[6];
#define mS_sim_chv_status_s(x) sim_chv_status_struct a##x;
#define m35A_k_8(x) kal_uint8 a##x[35];
#define m5A_k_8(x) kal_uint8 a##x[5];
#define m8A_k_8(x) kal_uint8 a##x[8];
#define m7A_k_8(x) kal_uint8 a##x[7];
#define m15A_l_phb_entry_s(x) l4c_phb_entry_struct a##x[15];
#define mS_l_phb_entry_s(x) l4c_phb_entry_struct a##x;
#define m26A_k_16(x) kal_uint16 a##x[26];
#define m1A_l_phb_ln_entry_s(x) l4c_phb_ln_entry_struct a##x[1];
#define mS_l_phb_ln_entry_s(x) l4c_phb_ln_entry_struct a##x;
#define m1A_l_phb_entry_s(x) l4c_phb_entry_struct a##x[1];
#define m1A_l_phb_entries_s(x) l4c_phb_entries_struct a##x[1];
#define mv3A_l_phb_bcd_anr_s(x) l4c_phb_bcd_anr_struct a##x[2000/PHB_ANR_SIZE];
#define mv4A_l_phb_email_s(x) l4c_phb_email_struct a##x[2000/PHB_EMAIL_SIZE];
#define mS_l_phb_email_s_p(x) l4c_phb_email_struct* a##x;
#define m5A_l_phb_entry_s(x) l4c_phb_entry_struct a##x[5];
#define m1000A_k_8(x) kal_uint8 a##x[1000];
#define mS_l_phb_anr_s(x) l4c_phb_anr_struct a##x;
#define mS_l_phb_email_s(x) l4c_phb_email_struct a##x;
#define m156A_k_8(x) kal_uint8 a##x[156];
#define m480A_k_8(x) kal_uint8 a##x[480];
#define mS_smsal_concat_s(x) smsal_concat_struct a##x;
#define m160A_k_8(x) kal_uint8 a##x[160];
#define mS_smsal_prefer_storage_s(x) smsal_prefer_storage_struct a##x;
#define mv5A_k_32(x) kal_uint32 a##x[(sizeof(smsal_concat_struct)+3)/4];
#define m2A_l_sms_mailbox_info_s(x) l4c_sms_mailbox_info_struct a##x[2];
#define mS_smsal_inbox_list_s(x) smsal_inbox_list_struct a##x;
#define mS_smsal_outbox_list_s(x) smsal_outbox_list_struct a##x;
#define mS_l_prim_pdp_info_s(x) l4c_prim_pdp_info_struct a##x;
#define mS_l_prim_pdp_info_list_s(x) l4c_prim_pdp_info_list_struct a##x;
#define mS_l_sec_pdp_info_s(x) l4c_sec_pdp_info_struct a##x;
#define mS_l_sec_pdp_info_list_s(x) l4c_sec_pdp_info_list_struct a##x;
#define m128A_k_8(x) kal_uint8 a##x[128];
#define mS_l_tft_s(x) l4c_tft_struct a##x;
#define mS_l_qos_s(x) l4c_qos_struct a##x;
#define mS_l_eqos_s(x) l4c_eqos_struct a##x;
#define mS_l_gprs_statistics_info_s(x) l4c_gprs_statistics_info_struct a##x;
#define mS_l_gprs_account_info_s(x) l4c_gprs_account_info_struct a##x;
#define mS_sat_icon_s(x) sat_icon_struct a##x;
#define m41A_k_8(x) kal_uint8 a##x[41];
#define m15A_k_8(x) kal_uint8 a##x[15];
#define m175A_k_8(x) kal_uint8 a##x[175];
#define m255A_k_8(x) kal_uint8 a##x[255];
#define m120A_k_8(x) kal_uint8 a##x[120];
#define mS_l_cb_info_s(x) l4c_cb_info_struct a##x;
#define mS_peer_buff_s_p(x) peer_buff_struct* a##x;
#define mS_request_info_type(x) request_info_type a##x;
#define m16A_rr_em_lai_info_s(x) rr_em_lai_info_struct a##x[16];
#define m20A_module_type(x) module_type a##x[20];
#define m20A_k_wchar(x) kal_wchar a##x[20];
#define mv6A_k_wchar(x) kal_wchar a##x[MAX_VM_FILE_NAME*MAX_NUM_OF_VM_LIST];
#define m11A_k_8(x) kal_uint8 a##x[11];
#define m2A_l4csmu_addr_s(x) l4csmu_addr_struct a##x[2];
#define m20A_l4csmu_info_num_s(x) l4csmu_info_num_struct a##x[20];
#define m22A_k_8(x) kal_uint8 a##x[22];
#define m520A_k_8(x) kal_uint8 a##x[520];
#define m100A_k_8(x) kal_uint8 a##x[100];
#define m50A_k_8(x) kal_uint8 a##x[50];
#define m250A_k_8(x) kal_uint8 a##x[250];
#define mS_k_wchar_p(x) kal_wchar* a##x;
#define m12A_k_8(x) kal_uint8 a##x[12];
#define mv7A_k_16(x) kal_uint16 a##x[CTM_SEND_TEXT_CHAR_MAX_NUM+1];

/*MTK:END*/

/*
* FUNCTION
*	MSGSTRUCT macro
*
* DESCRIPTION
*   the MSGSTRUCT macro declare an message structure.
*   All the message structure will be local parameter structure.
*   and the message members name will be a0,a1,a2,a3,....
*
* CALLS
*	none
* PARAMETERS
* 	none
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
#define MSGSTRUCT(name,MEMBER)  typedef struct\
						{\
							LOCAL_PARA_HDR\
							MEMBER\
						} msg_##name##_struct;

/*MTK:BEGIN:generate_message_struct*/
/* Call Control Related Messages */
#if defined(__MOD_CSM__)
#ifndef _MSGSTRUCT_9A_K_8_
#define _MSGSTRUCT_9A_K_8_
	/* MSG_ID_MMI_CC_RESET_ACM_REQ */	MSGSTRUCT(9A_k_8_,	m9A_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_CC_RESET_ACM_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
MSGSTRUCT(none,NONE)
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_32_
#define _MSGSTRUCT_S_K_BOOL_S_K_32_
	/* MSG_ID_MMI_CC_GET_ACM_RSP */	MSGSTRUCT(S_k_bool_S_k_32_,	mS_k_bool(0) mS_k_32(1) )

#endif
#ifndef _MSGSTRUCT_9A_K_8_S_K_32_
#define _MSGSTRUCT_9A_K_8_S_K_32_
	/* MSG_ID_MMI_CC_SET_MAX_ACM_REQ */	MSGSTRUCT(9A_k_8_S_k_32_,	m9A_k_8(0) mS_k_32(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_CC_SET_MAX_ACM_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_32_
#define _MSGSTRUCT_S_K_BOOL_S_K_32_
	/* MSG_ID_MMI_CC_GET_MAX_ACM_RSP */	MSGSTRUCT(S_k_bool_S_k_32_,	mS_k_bool(0) mS_k_32(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_32_
#define _MSGSTRUCT_S_K_BOOL_S_K_32_
	/* MSG_ID_MMI_CC_GET_CCM_RSP */	MSGSTRUCT(S_k_bool_S_k_32_,	mS_k_bool(0) mS_k_32(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_CC_SET_CUG_REQ */	MSGSTRUCT(S_k_8_S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_CC_SET_CUG_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_CC_GET_CUG_RSP */	MSGSTRUCT(S_k_bool_S_k_8_S_k_8_S_k_8_,	mS_k_bool(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_CC_CHLD_REQ */	MSGSTRUCT(S_k_8_S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_S_K_8_
	/* MSG_ID_MMI_CC_CHLD_RSP */	MSGSTRUCT(S_k_bool_S_k_16_S_k_8_,	mS_k_bool(0) mS_k_16(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_CC_ATH_REQ */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_L_CALL_LIST_S_
#define _MSGSTRUCT_S_K_BOOL_S_L_CALL_LIST_S_
	/* MSG_ID_MMI_CC_GET_CALL_LIST_RSP */	MSGSTRUCT(S_k_bool_S_l_call_list_s_,	mS_k_bool(0) mS_l_call_list_s(1) )

#endif
#ifndef _MSGSTRUCT_S_L_NUMBER_S_S_K_BOOL_S_L_SUB_ADDR_S_
#define _MSGSTRUCT_S_L_NUMBER_S_S_K_BOOL_S_L_SUB_ADDR_S_
	/* MSG_ID_MMI_CC_CALL_DEFLECT_REQ */	MSGSTRUCT(S_l_number_s_S_k_bool_S_l_sub_addr_s_,	mS_l_number_s(0) mS_k_bool(1) mS_l_sub_addr_s(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_CC_CALL_DEFLECT_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_CC_START_DTMF_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_CC_START_DTMF_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_CC_STOP_DTMF_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_80A_K_8_
#define _MSGSTRUCT_80A_K_8_
	/* MSG_ID_MMI_CC_START_AUTO_DTMF_REQ */	MSGSTRUCT(80A_k_8_,	m80A_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_CC_START_AUTO_DTMF_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_80A_K_8_
#define _MSGSTRUCT_S_K_8_80A_K_8_
	/* MSG_ID_MMI_CC_START_AUTO_DTMF_IND */	MSGSTRUCT(S_k_8_80A_k_8_,	mS_k_8(0) m80A_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_CC_START_AUTO_DTMF_FINISH_IND */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_CC_ATA_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_8_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_8_
	/* MSG_ID_MMI_CC_ATA_RSP */	MSGSTRUCT(S_l_result_s_S_k_8_,	mS_l_result_s(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_CC_DISCONNECT_AUX_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_CC_SET_LINE_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_CC_SET_LINE_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_BOOL_
#define _MSGSTRUCT_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_BOOL_
	/* MSG_ID_MMI_CC_DIAL_REQ */	MSGSTRUCT(S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_bool_,	mS_l_number_s(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) mS_k_bool(4) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_CC_DIAL_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_L_NUMBER_S_S_K_8_S_K_8_S_K_BOOL_
#define _MSGSTRUCT_S_L_NUMBER_S_S_K_8_S_K_8_S_K_BOOL_
	/* MSG_ID_MMI_CC_DIAL_REQ_IND */	MSGSTRUCT(S_l_number_s_S_k_8_S_k_8_S_k_bool_,	mS_l_number_s(0) mS_k_8(1) mS_k_8(2) mS_k_bool(3) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_8_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_8_
	/* MSG_ID_MMI_CC_DIAL_IND */	MSGSTRUCT(S_l_result_s_S_k_8_,	mS_l_result_s(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_8_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_8_
	/* MSG_ID_MMI_CC_CALL_MODIFY_RSP */	MSGSTRUCT(S_l_result_s_S_k_8_,	mS_l_result_s(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_CC_SET_SINGLE_NUM_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_CC_SET_SINGLE_NUM_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_CC_GET_SINGLE_NUM_RSP */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_32_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_32_S_K_8_
	/* MSG_ID_MMI_CC_CCM_IND */	MSGSTRUCT(S_k_8_S_k_32_S_k_8_,	mS_k_8(0) mS_k_32(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_CC_INTERNAL_ALERT_IND */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_8_30A_K_8_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_8_30A_K_8_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_CC_CALL_WAIT_IND */	MSGSTRUCT(S_k_8_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_30A_k_8_S_k_8_S_k_8_S_k_8_,	mS_k_8(0) mS_l_number_s(1) mS_k_8(2) mS_k_8(3) mS_k_8(4) mS_k_8(5) m30A_k_8(6) mS_k_8(7) mS_k_8(8) mS_k_8(9) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_L_NUMBER_S_S_L_SUB_ADDR_S_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_30A_K_8_S_K_8_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_L_NUMBER_S_S_L_SUB_ADDR_S_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_30A_K_8_S_K_8_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_CC_CALL_RING_IND */	MSGSTRUCT(S_k_8_S_l_number_s_S_l_sub_addr_s_S_l_number_s_S_k_8_S_k_8_S_k_8_30A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_,	mS_k_8(0) mS_l_number_s(1) mS_l_sub_addr_s(2) mS_l_number_s(3) mS_k_8(4) mS_k_8(5) mS_k_8(6) m30A_k_8(7) mS_k_8(8) mS_k_8(9) mS_k_8(10) mS_k_8(11) )

#endif
#ifndef _MSGSTRUCT_S_L_NUMBER_S_S_L_SUB_ADDR_S_S_K_8_S_K_8_
#define _MSGSTRUCT_S_L_NUMBER_S_S_L_SUB_ADDR_S_S_K_8_S_K_8_
	/* MSG_ID_MMI_CC_CALL_CONNECT_IND */	MSGSTRUCT(S_l_number_s_S_l_sub_addr_s_S_k_8_S_k_8_,	mS_l_number_s(0) mS_l_sub_addr_s(1) mS_k_8(2) mS_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_BOOL_
#define _MSGSTRUCT_S_K_8_S_K_BOOL_
	/* MSG_ID_MMI_CC_CALL_DISCONNECT_IND */	MSGSTRUCT(S_k_8_S_k_bool_,	mS_k_8(0) mS_k_bool(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_16_
#define _MSGSTRUCT_S_K_8_S_K_16_
	/* MSG_ID_MMI_CC_CALL_RELEASE_IND */	MSGSTRUCT(S_k_8_S_k_16_,	mS_k_8(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_CC_SPEECH_IND */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_BOOL_S_K_8_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_BOOL_S_K_8_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_CC_NOTIFY_SS_IND */	MSGSTRUCT(S_k_8_S_k_8_S_k_bool_S_k_8_S_k_bool_S_k_8_,	mS_k_8(0) mS_k_8(1) mS_k_bool(2) mS_k_8(3) mS_k_bool(4) mS_k_8(5) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_16_
#define _MSGSTRUCT_S_K_8_S_K_16_
	/* MSG_ID_MMI_CC_NOTIFY_SS_CUG_IND */	MSGSTRUCT(S_k_8_S_k_16_,	mS_k_8(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_BOOL_S_L_NUMBER_S_S_L_SUB_ADDR_S_
#define _MSGSTRUCT_S_K_8_S_K_BOOL_S_L_NUMBER_S_S_L_SUB_ADDR_S_
	/* MSG_ID_MMI_CC_NOTIFY_SS_ECT_IND */	MSGSTRUCT(S_k_8_S_k_bool_S_l_number_s_S_l_sub_addr_s_,	mS_k_8(0) mS_k_bool(1) mS_l_number_s(2) mS_l_sub_addr_s(3) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_K_8_30A_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_K_8_30A_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_CC_NOTIFY_SS_CNAP_IND */	MSGSTRUCT(S_k_8_S_k_8_S_k_8_S_k_8_30A_k_8_S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) m30A_k_8(4) mS_k_8(5) mS_k_8(6) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_BOOL_S_L_NUMBER_S_S_K_BOOL_S_L_SUB_ADDR_S_S_K_BOOL_S_K_8_S_K_BOOL_S_K_8_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_BOOL_S_L_NUMBER_S_S_K_BOOL_S_L_SUB_ADDR_S_S_K_BOOL_S_K_8_S_K_BOOL_S_K_8_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_CC_NOTIFY_SS_CCBS_IND */	MSGSTRUCT(S_k_8_S_k_bool_S_l_number_s_S_k_bool_S_l_sub_addr_s_S_k_bool_S_k_8_S_k_bool_S_k_8_S_k_bool_S_k_8_,	mS_k_8(0) mS_k_bool(1) mS_l_number_s(2) mS_k_bool(3) mS_l_sub_addr_s(4) mS_k_bool(5) mS_k_8(6) mS_k_bool(7) mS_k_8(8) mS_k_bool(9) mS_k_8(10) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_CC_CALL_ACCEPT_REQ_IND */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_CC_VIDEO_CALL_STATUS_IND */	MSGSTRUCT(S_k_8_S_k_8_S_k_bool_S_k_8_,	mS_k_8(0) mS_k_8(1) mS_k_bool(2) mS_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_CC_REL_COMP_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_CC_REL_COMP_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#endif /* defined(__MOD_CSM__) */
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_CC_SET_BEARER_SERVICE_REQ */	MSGSTRUCT(S_k_8_S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_CC_SET_BEARER_SERVICE_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_CC_GET_BEARER_SERVICE_RSP */	MSGSTRUCT(S_k_bool_S_k_8_S_k_8_S_k_8_,	mS_k_bool(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_BOOL_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_8_32A_K_8_32A_K_8_4A_K_8_S_L4_NAME_S_
#define _MSGSTRUCT_S_K_8_S_K_BOOL_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_8_32A_K_8_32A_K_8_4A_K_8_S_L4_NAME_S_
	/* MSG_ID_MMI_CC_SET_CSD_PROFILE_REQ */	MSGSTRUCT(S_k_8_S_k_bool_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_32A_k_8_32A_k_8_4A_k_8_S_l4_name_s_,	mS_k_8(0) mS_k_bool(1) mS_l_number_s(2) mS_k_8(3) mS_k_8(4) mS_k_8(5) mS_k_8(6) m32A_k_8(7) m32A_k_8(8) m4A_k_8(9) mS_l4_name_s(10) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_8_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_CC_SET_CSD_PROFILE_RSP */	MSGSTRUCT(S_k_8_S_k_bool_S_k_16_,	mS_k_8(0) mS_k_bool(1) mS_k_16(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_CC_GET_CSD_PROFILE_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_8_32A_K_8_32A_K_8_4A_K_8_S_L4_NAME_S_
#define _MSGSTRUCT_S_K_BOOL_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_8_32A_K_8_32A_K_8_4A_K_8_S_L4_NAME_S_
	/* MSG_ID_MMI_CC_GET_CSD_PROFILE_RSP */	MSGSTRUCT(S_k_bool_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_32A_k_8_32A_k_8_4A_k_8_S_l4_name_s_,	mS_k_bool(0) mS_l_number_s(1) mS_k_8(2) mS_k_8(3) mS_k_8(4) mS_k_8(5) m32A_k_8(6) m32A_k_8(7) m4A_k_8(8) mS_l4_name_s(9) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_CC_GET_FREE_CSD_PROFILE_NUM_RSP */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_SS_GET_EMLPP_PRIORITY_RSP */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_SS_EMLPP_REQ */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SS_EMLPP_RSP */	MSGSTRUCT(S_l_result_s_S_k_8_S_k_8_S_k_8_S_k_8_,	mS_l_result_s(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) mS_k_8(4) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_K_8_S_L_NUMBER_S_S_K_BOOL_S_L_SUB_ADDR_S_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_K_8_S_L_NUMBER_S_S_K_BOOL_S_L_SUB_ADDR_S_
	/* MSG_ID_MMI_SS_CALL_FORWARD_REQ */	MSGSTRUCT(S_k_8_S_k_8_S_k_8_S_k_8_S_l_number_s_S_k_bool_S_l_sub_addr_s_,	mS_k_8(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) mS_l_number_s(4) mS_k_bool(5) mS_l_sub_addr_s(6) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_S_K_8_13A_FORWARDING_LIST_S_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_S_K_8_13A_FORWARDING_LIST_S_
	/* MSG_ID_MMI_SS_CALL_FORWARD_RSP */	MSGSTRUCT(S_l_result_s_S_k_8_S_k_8_S_k_8_S_k_8_13A_forwarding_list_s_,	mS_l_result_s(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) mS_k_8(4) m13A_forwarding_list_s(5) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_SS_CALL_WAIT_REQ */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_S_K_8_13A_K_8_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_S_K_8_13A_K_8_
	/* MSG_ID_MMI_SS_CALL_WAIT_RSP */	MSGSTRUCT(S_l_result_s_S_k_8_S_k_8_S_k_8_S_k_8_13A_k_8_,	mS_l_result_s(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) mS_k_8(4) m13A_k_8(5) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_SS_INTERROGATE_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_SS_INTERROGATE_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_
	/* MSG_ID_MMI_SS_CDIP_INTERROGATE_IND */	MSGSTRUCT(S_l_result_s_S_k_8_S_k_8_,	mS_l_result_s(0) mS_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SS_CLIP_INTERROGATE_IND */	MSGSTRUCT(S_l_result_s_S_k_8_S_k_8_S_k_8_,	mS_l_result_s(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SS_CLIR_INTERROGATE_IND */	MSGSTRUCT(S_l_result_s_S_k_8_S_k_8_S_k_8_,	mS_l_result_s(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SS_CNAP_INTERROGATE_IND */	MSGSTRUCT(S_l_result_s_S_k_8_S_k_8_S_k_8_,	mS_l_result_s(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SS_COLP_INTERROGATE_IND */	MSGSTRUCT(S_l_result_s_S_k_8_S_k_8_S_k_8_,	mS_l_result_s(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SS_COLR_INTERROGATE_IND */	MSGSTRUCT(S_l_result_s_S_k_8_S_k_8_S_k_8_,	mS_l_result_s(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_8_9A_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_8_9A_K_8_
	/* MSG_ID_MMI_SS_CALL_BARRING_REQ */	MSGSTRUCT(S_k_8_S_k_8_S_k_8_9A_k_8_,	mS_k_8(0) mS_k_8(1) mS_k_8(2) m9A_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_S_K_8_13A_BARRING_LIST_S_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_S_K_8_13A_BARRING_LIST_S_
	/* MSG_ID_MMI_SS_CALL_BARRING_RSP */	MSGSTRUCT(S_l_result_s_S_k_8_S_k_8_S_k_8_S_k_8_13A_barring_list_s_,	mS_l_result_s(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) mS_k_8(4) m13A_barring_list_s(5) )

#endif
#ifndef _MSGSTRUCT_183A_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_183A_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SS_USSD_REQ */	MSGSTRUCT(183A_k_8_S_k_8_S_k_8_,	m183A_k_8(0) mS_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_183A_K_8_S_K_8_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_183A_K_8_S_K_8_
	/* MSG_ID_MMI_SS_USSD_RSP */	MSGSTRUCT(S_l_result_s_S_k_8_S_k_8_S_k_8_183A_k_8_S_k_8_,	mS_l_result_s(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) m183A_k_8(4) mS_k_8(5) )

#endif
#ifndef _MSGSTRUCT_S_K_8_183A_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_183A_K_8_S_K_8_
	/* MSG_ID_MMI_SS_USSR_IND */	MSGSTRUCT(S_k_8_183A_k_8_S_k_8_,	mS_k_8(0) m183A_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_183A_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_183A_K_8_S_K_8_
	/* MSG_ID_MMI_SS_USSN_IND */	MSGSTRUCT(S_k_8_183A_k_8_S_k_8_,	mS_k_8(0) m183A_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_9A_K_8_9A_K_8_9A_K_8_
#define _MSGSTRUCT_S_K_8_9A_K_8_9A_K_8_9A_K_8_
	/* MSG_ID_MMI_SS_CHANGE_PASSWORD_REQ */	MSGSTRUCT(S_k_8_9A_k_8_9A_k_8_9A_k_8_,	mS_k_8(0) m9A_k_8(1) m9A_k_8(2) m9A_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_
#define _MSGSTRUCT_S_L_RESULT_S_
	/* MSG_ID_MMI_SS_CHANGE_PASSWORD_RSP */	MSGSTRUCT(S_l_result_s_,	mS_l_result_s(0) )

#endif
#ifndef _MSGSTRUCT_183A_K_8_S_K_8_S_K_8_21A_K_8_S_K_8_S_K_8_S_K_BOOL_
#define _MSGSTRUCT_183A_K_8_S_K_8_S_K_8_21A_K_8_S_K_8_S_K_8_S_K_BOOL_
	/* MSG_ID_MMI_SS_PARSING_STRING_REQ */	MSGSTRUCT(183A_k_8_S_k_8_S_k_8_21A_k_8_S_k_8_S_k_8_S_k_bool_,	m183A_k_8(0) mS_k_8(1) mS_k_8(2) m21A_k_8(3) mS_k_8(4) mS_k_8(5) mS_k_bool(6) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_L_SS_STRING_INFO_S_
#define _MSGSTRUCT_S_L_RESULT_S_S_L_SS_STRING_INFO_S_
	/* MSG_ID_MMI_SS_PARSING_STRING_RSP */	MSGSTRUCT(S_l_result_s_S_l_ss_string_info_s_,	mS_l_result_s(0) mS_l_ss_string_info_s(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_SS_CB_PASSWORD_IND */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_SMS_CB_GS_CHANGE_IND */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_SS_CCBS_REQ */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_S_CCBS_LIST_S_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_S_CCBS_LIST_S_
	/* MSG_ID_MMI_SS_CCBS_RSP */	MSGSTRUCT(S_l_result_s_S_k_8_S_k_8_S_k_8_S_ccbs_list_s_,	mS_l_result_s(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) mS_ccbs_list_s(4) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_SS_ABORT_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_SS_SET_CLIR_FLAG_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_SS_SET_CLIR_FLAG_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
/* Hardware - Audio Related Service Messages */
#if defined(__MOD_UEM__)
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_SET_VOLUME_REQ */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_EQ_SET_VOLUME_RSP */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_EXE_VOLUME_REQ_IND */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_VOLUME_CHANGE_IND */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_BOOL_
#define _MSGSTRUCT_S_K_8_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SET_MUTE_REQ */	MSGSTRUCT(S_k_8_S_k_bool_,	mS_k_8(0) mS_k_bool(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_EQ_SET_MUTE_RSP */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_BOOL_
#define _MSGSTRUCT_S_K_8_S_K_BOOL_
	/* MSG_ID_MMI_EQ_EXE_MUTE_REQ_IND */	MSGSTRUCT(S_k_8_S_k_bool_,	mS_k_8(0) mS_k_bool(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_BOOL_
#define _MSGSTRUCT_S_K_8_S_K_BOOL_
	/* MSG_ID_MMI_EQ_MUTE_CHANGE_IND */	MSGSTRUCT(S_k_8_S_k_bool_,	mS_k_8(0) mS_k_bool(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SET_SILENT_MODE_REQ */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SET_SILENT_MODE_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SET_SILENT_MODE_REQ_IND */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_SET_GPIO_LEVEL_REQ */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SET_GPIO_LEVEL_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_SET_GPIO_LEVEL_REQ_IND */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_EQ_GET_GPIO_LEVEL_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_EQ_GET_GPIO_LEVEL_RSP */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_EXE_GPIO_LEVEL_REQ */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_EXE_GPIO_LEVEL_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_EXE_GPIO_LEVEL_REQ_IND */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_16_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_16_
	/* MSG_ID_MMI_EQ_PLAY_AUDIO_REQ */	MSGSTRUCT(S_k_8_S_k_8_S_k_16_,	mS_k_8(0) mS_k_8(1) mS_k_16(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_PLAY_AUDIO_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_16_
#define _MSGSTRUCT_S_K_8_S_K_16_
	/* MSG_ID_MMI_EQ_PLAY_AUDIO_FINISH_IND */	MSGSTRUCT(S_k_8_S_k_16_,	mS_k_8(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_EQ_STOP_AUDIO_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_STOP_AUDIO_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_P_S_K_32_S_K_8_S_K_8_S_K_16_
#define _MSGSTRUCT_S_K_8_P_S_K_32_S_K_8_S_K_8_S_K_16_
	/* MSG_ID_MMI_EQ_PLAY_AUDIO_STREAM_REQ */	MSGSTRUCT(S_k_8_p_S_k_32_S_k_8_S_k_8_S_k_16_,	mS_k_8_p(0) mS_k_32(1) mS_k_8(2) mS_k_8(3) mS_k_16(4) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EQ_PLAY_AUDIO_STREAM_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EQ_STOP_AUDIO_STREAM_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_300A_K_8_S_K_16_S_K_8_S_K_16_
#define _MSGSTRUCT_300A_K_8_S_K_16_S_K_8_S_K_16_
	/* MSG_ID_MMI_EQ_PLAY_EXT_IMELODY_REQ */	MSGSTRUCT(300A_k_8_S_k_16_S_k_8_S_k_16_,	m300A_k_8(0) mS_k_16(1) mS_k_8(2) mS_k_16(3) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_PLAY_EXT_IMELODY_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_BOOL_
#define _MSGSTRUCT_S_K_8_S_K_BOOL_
	/* MSG_ID_MMI_EQ_GPIO_DETECT_IND */	MSGSTRUCT(S_k_8_S_k_bool_,	mS_k_8(0) mS_k_bool(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_EQ_GPIO_DETECT_RES_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_GPIO_DETECT_RES_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SET_SPEECH_MODE_REQ */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SET_SPEECH_MODE_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_50A_K_WCHAR_S_K_8_S_K_16_
#define _MSGSTRUCT_50A_K_WCHAR_S_K_8_S_K_16_
	/* MSG_ID_MMI_EQ_PLAY_AUDIO_BY_NAME_REQ */	MSGSTRUCT(50A_k_wchar_S_k_8_S_k_16_,	m50A_k_wchar(0) mS_k_8(1) mS_k_16(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EQ_PLAY_AUDIO_BY_NAME_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_50A_K_WCHAR_
#define _MSGSTRUCT_50A_K_WCHAR_
	/* MSG_ID_MMI_EQ_STOP_AUDIO_BY_NAME_REQ */	MSGSTRUCT(50A_k_wchar_,	m50A_k_wchar(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EQ_STOP_AUDIO_BY_NAME_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_AUDIO_PROFILE_S_
#define _MSGSTRUCT_S_AUDIO_PROFILE_S_
	/* MSG_ID_MMI_EQ_SET_AUDIO_PROFILE_REQ */	MSGSTRUCT(S_audio_profile_s_,	mS_audio_profile_s(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EQ_SET_AUDIO_PROFILE_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_AUDIO_PROFILE_S_
#define _MSGSTRUCT_S_AUDIO_PROFILE_S_
	/* MSG_ID_MMI_EQ_GET_AUDIO_PROFILE_REQ */	MSGSTRUCT(S_audio_profile_s_,	mS_audio_profile_s(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_AUDIO_PROFILE_S_
#define _MSGSTRUCT_S_K_BOOL_S_AUDIO_PROFILE_S_
	/* MSG_ID_MMI_EQ_GET_AUDIO_PROFILE_RSP */	MSGSTRUCT(S_k_bool_S_audio_profile_s_,	mS_k_bool(0) mS_audio_profile_s(1) )

#endif
#ifndef _MSGSTRUCT_S_AUDIO_PARAM_S_
#define _MSGSTRUCT_S_AUDIO_PARAM_S_
	/* MSG_ID_MMI_EQ_SET_AUDIO_PARAM_REQ */	MSGSTRUCT(S_audio_param_s_,	mS_audio_param_s(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EQ_SET_AUDIO_PARAM_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_AUDIO_PARAM_S_
#define _MSGSTRUCT_S_K_BOOL_S_AUDIO_PARAM_S_
	/* MSG_ID_MMI_EQ_GET_AUDIO_PARAM_RSP */	MSGSTRUCT(S_k_bool_S_audio_param_s_,	mS_k_bool(0) mS_audio_param_s(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_START_ADC_ALL_CHANNEL_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_STOP_ADC_ALL_CHANNEL_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_INT32_S_K_INT32_S_K_INT32_S_K_INT32_S_K_INT32_
#define _MSGSTRUCT_S_K_INT32_S_K_INT32_S_K_INT32_S_K_INT32_S_K_INT32_
	/* MSG_ID_MMI_EQ_ADC_ALL_CHANNEL_IND */	MSGSTRUCT(S_k_int32_S_k_int32_S_k_int32_S_k_int32_S_k_int32_,	mS_k_int32(0) mS_k_int32(1) mS_k_int32(2) mS_k_int32(3) mS_k_int32(4) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_EQ_SET_AUDIO_MODE_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SET_AUDIO_MODE_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_PLAY_PATTERN_REQ */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_PLAY_PATTERN_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_L_HW_PROFILE_S_
#define _MSGSTRUCT_S_L_HW_PROFILE_S_
	/* MSG_ID_MMI_EQ_SET_HW_LEVEL_REQ */	MSGSTRUCT(S_l_hw_profile_s_,	mS_l_hw_profile_s(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EQ_SET_HW_LEVEL_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_L_HW_PROFILE_S_
#define _MSGSTRUCT_S_K_BOOL_S_L_HW_PROFILE_S_
	/* MSG_ID_MMI_EQ_GET_HW_LEVEL_RSP */	MSGSTRUCT(S_k_bool_S_l_hw_profile_s_,	mS_k_bool(0) mS_l_hw_profile_s(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SET_SLEEP_MODE_REQ */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SET_SLEEP_MODE_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SET_SLEEP_MODE_REQ_IND */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_GET_MS_IMEI_REQ */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_GET_MS_IMEI_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_10A_K_8_S_K_8_
#define _MSGSTRUCT_10A_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_SET_MS_IMEI_REQ */	MSGSTRUCT(10A_k_8_S_k_8_,	m10A_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SET_MS_IMEI_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_RTC_POWERON_STATE_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#endif /* defined(__MOD_UEM__) */
/* Hardware - RTC, Clock, Alarm Related Messages */
#if defined(__MOD_UEM__)
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_RTC_ALARM_INFO_S_
#define _MSGSTRUCT_S_K_8_S_K_8_S_RTC_ALARM_INFO_S_
	/* MSG_ID_MMI_EQ_SET_RTC_TIME_REQ */	MSGSTRUCT(S_k_8_S_k_8_S_rtc_alarm_info_s_,	mS_k_8(0) mS_k_8(1) mS_rtc_alarm_info_s(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EQ_SET_RTC_TIME_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_RTC_ALARM_INFO_S_
#define _MSGSTRUCT_S_K_8_S_K_8_S_RTC_ALARM_INFO_S_
	/* MSG_ID_MMI_EQ_SET_RTC_TIME_REQ_IND */	MSGSTRUCT(S_k_8_S_k_8_S_rtc_alarm_info_s_,	mS_k_8(0) mS_k_8(1) mS_rtc_alarm_info_s(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_RTC_ALARM_INFO_S_
#define _MSGSTRUCT_S_K_8_S_K_8_S_RTC_ALARM_INFO_S_
	/* MSG_ID_MMI_EQ_EXE_RTC_TIMER_REQ */	MSGSTRUCT(S_k_8_S_k_8_S_rtc_alarm_info_s_,	mS_k_8(0) mS_k_8(1) mS_rtc_alarm_info_s(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_EXE_RTC_TIMER_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_EQ_GET_RTC_TIME_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_3A_RTC_ALARM_INFO_S_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_3A_RTC_ALARM_INFO_S_
	/* MSG_ID_MMI_EQ_GET_RTC_TIME_RSP */	MSGSTRUCT(S_k_bool_S_k_8_3A_rtc_alarm_info_s_,	mS_k_bool(0) mS_k_8(1) m3A_rtc_alarm_info_s(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_DEL_RTC_TIMER_REQ */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EQ_DEL_RTC_TIMER_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_DEL_RTC_TIMER_REQ_IND */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_EXE_DEL_RTC_TIMER_REQ */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_EXE_DEL_RTC_TIMER_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_EXE_DEL_RTC_TIMER_REQ_IND */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_EQ_SET_DATE_TIME_FORMAT_REQ */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SET_DATE_TIME_FORMAT_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_EQ_SET_DATE_TIME_FORMAT_REQ_IND */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_VOID_P_S_K_16_S_VOID_P_
#define _MSGSTRUCT_S_VOID_P_S_K_16_S_VOID_P_
	/* MSG_ID_MMI_EQ_START_TIMER_REQ */	MSGSTRUCT(S_void_p_S_k_16_S_void_p_,	mS_void_p(0) mS_k_16(1) mS_void_p(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_EVENTID_S_VOID_P_
#define _MSGSTRUCT_S_K_BOOL_S_EVENTID_S_VOID_P_
	/* MSG_ID_MMI_EQ_START_TIMER_RSP */	MSGSTRUCT(S_k_bool_S_eventid_S_void_p_,	mS_k_bool(0) mS_eventid(1) mS_void_p(2) )

#endif
#ifndef _MSGSTRUCT_S_EVENTID_
#define _MSGSTRUCT_S_EVENTID_
	/* MSG_ID_MMI_EQ_STOP_TIMER_REQ */	MSGSTRUCT(S_eventid_,	mS_eventid(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_STOP_TIMER_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_RTC_FORMAT_S_
#define _MSGSTRUCT_S_K_8_S_RTC_FORMAT_S_
	/* MSG_ID_MMI_EQ_CLOCK_TICK_IND */	MSGSTRUCT(S_k_8_S_rtc_format_s_,	mS_k_8(0) mS_rtc_format_s(1) )

#endif
#ifndef _MSGSTRUCT_S_RTC_FORMAT_S_
#define _MSGSTRUCT_S_RTC_FORMAT_S_
	/* MSG_ID_MMI_EQ_ALARM_IND */	MSGSTRUCT(S_rtc_format_s_,	mS_rtc_format_s(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_MMI_AT_ALARM_INFO_S_P_
#define _MSGSTRUCT_S_K_8_S_K_8_S_MMI_AT_ALARM_INFO_S_P_
	/* MSG_ID_MMI_AT_ALARM_QUERY_RES_REQ */	MSGSTRUCT(S_k_8_S_k_8_S_mmi_at_alarm_info_s_p_,	mS_k_8(0) mS_k_8(1) mS_mmi_at_alarm_info_s_p(2) )

#endif
#ifndef _MSGSTRUCT_S_MMI_AT_ALARM_INFO_S_
#define _MSGSTRUCT_S_MMI_AT_ALARM_INFO_S_
	/* MSG_ID_MMI_AT_ALARM_SET_REQ_IND */	MSGSTRUCT(S_mmi_at_alarm_info_s_,	mS_mmi_at_alarm_info_s(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_AT_ALARM_SET_RES_REQ */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_AT_ALARM_DELETE_REQ_IND */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_AT_ALARM_DELETE_RES_REQ */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#endif /* defined(__MOD_UEM__) */
/* Hardware - Keypad, Indicator, LCD Related Messages */
#if defined(__MOD_UEM__)
#ifndef _MSGSTRUCT_32A_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_32A_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_SIMULATE_KEY_PRESS_REQ */	MSGSTRUCT(32A_k_8_S_k_8_S_k_8_,	m32A_k_8(0) mS_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SIMULATE_KEY_PRESS_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_SIMULATE_KEY_PRESS_REQ_IND */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_SET_INDICATOR_REQ */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SET_INDICATOR_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_SET_INDICATOR_REQ_IND */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_EQ_GET_INDICATOR_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_EQ_GET_INDICATOR_RSP */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_30A_K_8_
#define _MSGSTRUCT_30A_K_8_
	/* MSG_ID_MMI_EQ_DISPLAY_TEXT_REQ */	MSGSTRUCT(30A_k_8_,	m30A_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_DISPLAY_TEXT_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_30A_K_8_
#define _MSGSTRUCT_30A_K_8_
	/* MSG_ID_MMI_EQ_DISPLAY_TEXT_REQ_IND */	MSGSTRUCT(30A_k_8_,	m30A_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_DRV_GET_KEY_FUNC_
#define _MSGSTRUCT_S_DRV_GET_KEY_FUNC_
	/* MSG_ID_MMI_EQ_KEYPAD_DETECT_IND */	MSGSTRUCT(S_drv_get_key_func_,	mS_drv_get_key_func(0) )

#endif
#endif /* defined(__MOD_UEM__) */
/* Hardware - Misc Messages */
#if defined(__MOD_UEM__)
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_EQ_SET_LANGUAGE_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EQ_SET_LANGUAGE_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_EQ_SET_LANGUAGE_REQ_IND */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_62A_K_8_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_62A_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_SET_GREETING_TEXT_REQ */	MSGSTRUCT(S_k_bool_S_k_8_62A_k_8_S_k_8_,	mS_k_bool(0) mS_k_8(1) m62A_k_8(2) mS_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EQ_SET_GREETING_TEXT_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_62A_K_8_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_62A_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_SET_GREETING_TEXT_REQ_IND */	MSGSTRUCT(S_k_bool_S_k_8_62A_k_8_S_k_8_,	mS_k_bool(0) mS_k_8(1) m62A_k_8(2) mS_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SET_VIBRATOR_MODE_REQ_IND */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_EQ_SET_VIBRATOR_MODE_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EQ_SET_VIBRATOR_MODE_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_EQ_SET_COUNTRY_CODE_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EQ_SET_COUNTRY_CODE_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_EQ_GET_COUNTRY_CODE_RSP */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_GET_BATTERY_STATUS_RSP */	MSGSTRUCT(S_k_bool_S_k_8_S_k_8_,	mS_k_bool(0) mS_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_EQ_GET_EQUIP_ID_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_30A_K_8_
#define _MSGSTRUCT_S_K_BOOL_30A_K_8_
	/* MSG_ID_MMI_EQ_GET_EQUIP_ID_RSP */	MSGSTRUCT(S_k_bool_30A_k_8_,	mS_k_bool(0) m30A_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_LOAD_DEFAULT_CONFIG_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_POWER_ON_REQ */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_POWER_ON_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_POWER_OFF_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_RTC_FORMAT_S_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_RTC_FORMAT_S_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_POWER_ON_IND */	MSGSTRUCT(S_k_8_S_k_8_S_k_8_S_rtc_format_s_S_k_8_S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) mS_k_8(2) mS_rtc_format_s(3) mS_k_8(4) mS_k_8(5) mS_k_8(6) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_BATTERY_STATUS_IND */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_PMIC_CONFIG_PARAM_S_
#define _MSGSTRUCT_S_K_8_S_PMIC_CONFIG_PARAM_S_
	/* MSG_ID_MMI_EQ_PMIC_CONFIG_REQ */	MSGSTRUCT(S_k_8_S_pmic_config_param_s_,	mS_k_8(0) mS_pmic_config_param_s(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_PMIC_CONFIG_PARAM_S_
#define _MSGSTRUCT_S_K_8_S_PMIC_CONFIG_PARAM_S_
	/* MSG_ID_MMI_EQ_PMIC_CONFIG_RSP */	MSGSTRUCT(S_k_8_S_pmic_config_param_s_,	mS_k_8(0) mS_pmic_config_param_s(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_EQ_BATTERY_STATUS_RES_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_RF_TEST_GSM_PARAM_S_
#define _MSGSTRUCT_S_K_8_S_RF_TEST_GSM_PARAM_S_
	/* MSG_ID_MMI_EQ_RF_TEST_GSM_REQ */	MSGSTRUCT(S_k_8_S_rf_test_gsm_param_s_,	mS_k_8(0) mS_rf_test_gsm_param_s(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_RF_TEST_GSM_PARAM_S_
#define _MSGSTRUCT_S_K_8_S_RF_TEST_GSM_PARAM_S_
	/* MSG_ID_MMI_EQ_RF_TEST_GSM_RSP */	MSGSTRUCT(S_k_8_S_rf_test_gsm_param_s_,	mS_k_8(0) mS_rf_test_gsm_param_s(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_FM_RADIO_CONFIG_PARAM_S_
#define _MSGSTRUCT_S_K_8_S_FM_RADIO_CONFIG_PARAM_S_
	/* MSG_ID_MMI_EQ_FM_RADIO_CONFIG_REQ */	MSGSTRUCT(S_k_8_S_fm_radio_config_param_s_,	mS_k_8(0) mS_fm_radio_config_param_s(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_FM_RADIO_CONFIG_PARAM_S_
#define _MSGSTRUCT_S_K_8_S_FM_RADIO_CONFIG_PARAM_S_
	/* MSG_ID_MMI_EQ_FM_RADIO_CONFIG_RSP */	MSGSTRUCT(S_k_8_S_fm_radio_config_param_s_,	mS_k_8(0) mS_fm_radio_config_param_s(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_RF_TEST_WIFI_PARAM_S_
#define _MSGSTRUCT_S_K_8_S_RF_TEST_WIFI_PARAM_S_
	/* MSG_ID_MMI_EQ_RF_TEST_WIFI_REQ */	MSGSTRUCT(S_k_8_S_rf_test_wifi_param_s_,	mS_k_8(0) mS_rf_test_wifi_param_s(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_RF_TEST_WIFI_PARAM_S_
#define _MSGSTRUCT_S_K_8_S_RF_TEST_WIFI_PARAM_S_
	/* MSG_ID_MMI_EQ_RF_TEST_WIFI_RSP */	MSGSTRUCT(S_k_8_S_rf_test_wifi_param_s_,	mS_k_8(0) mS_rf_test_wifi_param_s(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_EQ_CALL_STATUS_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#endif /* defined(__MOD_UEM__) */
/* Hardware - NVRAM messages */
#if defined(__MOD_NVRAM__)
#ifndef _MSGSTRUCT_S_K_8_S_K_16_S_K_16_
#define _MSGSTRUCT_S_K_8_S_K_16_S_K_16_
	/* MSG_ID_MMI_EQ_NVRAM_READ_REQ */	MSGSTRUCT(S_k_8_S_k_16_S_k_16_,	mS_k_8(0) mS_k_16(1) mS_k_16(2) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_16_1A_K_8_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_16_1A_K_8_
	/* MSG_ID_MMI_EQ_NVRAM_READ_RSP */	MSGSTRUCT(S_l_result_s_S_k_8_S_k_16_1A_k_8_,	mS_l_result_s(0) mS_k_8(1) mS_k_16(2) m1A_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_16_S_K_16_1A_K_8_
#define _MSGSTRUCT_S_K_8_S_K_16_S_K_16_1A_K_8_
	/* MSG_ID_MMI_EQ_NVRAM_WRITE_REQ */	MSGSTRUCT(S_k_8_S_k_16_S_k_16_1A_k_8_,	mS_k_8(0) mS_k_16(1) mS_k_16(2) m1A_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_16_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_16_
	/* MSG_ID_MMI_EQ_NVRAM_WRITE_RSP */	MSGSTRUCT(S_l_result_s_S_k_8_S_k_16_,	mS_l_result_s(0) mS_k_8(1) mS_k_16(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_NVRAM_RESET_REQ */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_
#define _MSGSTRUCT_S_L_RESULT_S_
	/* MSG_ID_MMI_EQ_NVRAM_RESET_RSP */	MSGSTRUCT(S_l_result_s_,	mS_l_result_s(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_K_32_S_K_32_S_K_BOOL_S_K_8_S_K_8_S_K_8_S_K_32_S_K_8_S_K_32_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_K_32_S_K_32_S_K_BOOL_S_K_8_S_K_8_S_K_8_S_K_32_S_K_8_S_K_32_
	/* MSG_ID_MMI_EQ_SET_UART_REQ */	MSGSTRUCT(S_k_8_S_k_8_S_k_8_S_k_32_S_k_32_S_k_bool_S_k_8_S_k_8_S_k_8_S_k_32_S_k_8_S_k_32_,	mS_k_8(0) mS_k_8(1) mS_k_8(2) mS_k_32(3) mS_k_32(4) mS_k_bool(5) mS_k_8(6) mS_k_8(7) mS_k_8(8) mS_k_32(9) mS_k_8(10) mS_k_32(11) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SET_UART_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_32_S_K_8_S_K_32_S_K_8_S_K_32_S_K_8_S_K_32_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_32_S_K_8_S_K_32_S_K_8_S_K_32_S_K_8_S_K_32_
	/* MSG_ID_MMI_EQ_GET_UART_RSP */	MSGSTRUCT(S_k_bool_S_k_8_S_k_32_S_k_8_S_k_32_S_k_8_S_k_32_S_k_8_S_k_32_,	mS_k_bool(0) mS_k_8(1) mS_k_32(2) mS_k_8(3) mS_k_32(4) mS_k_8(5) mS_k_32(6) mS_k_8(7) mS_k_32(8) )

#endif
#ifndef _MSGSTRUCT_S_MODULE_TYPE_S_UART_PORT_S_K_32_
#define _MSGSTRUCT_S_MODULE_TYPE_S_UART_PORT_S_K_32_
	/* MSG_ID_MMI_ATTACH_UART_PORT_REQ */	MSGSTRUCT(S_module_type_S_UART_PORT_S_k_32_,	mS_module_type(0) mS_UART_PORT(1) mS_k_32(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_ATTACH_UART_PORT_RSP */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_MODULE_TYPE_S_UART_PORT_
#define _MSGSTRUCT_S_MODULE_TYPE_S_UART_PORT_
	/* MSG_ID_MMI_DETACH_UART_PORT_REQ */	MSGSTRUCT(S_module_type_S_UART_PORT_,	mS_module_type(0) mS_UART_PORT(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_DETACH_UART_PORT_RSP */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_DCM_ENABLE_REQ */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#endif /* defined(__MOD_NVRAM__) */
/* Network Related Messages */
#if defined(__MOD_RAC__)
#ifndef _MSGSTRUCT_S_K_BOOL_16A_K_8_3A_K_8_
#define _MSGSTRUCT_S_K_BOOL_16A_K_8_3A_K_8_
	/* MSG_ID_MMI_NW_GET_IMEI_RSP */	MSGSTRUCT(S_k_bool_16A_k_8_3A_k_8_,	mS_k_bool(0) m16A_k_8(1) m3A_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_NW_ABORT_PLMN_LIST_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_BOOL_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_BOOL_
	/* MSG_ID_MMI_NW_SET_ATTACH_REQ */	MSGSTRUCT(S_k_8_S_k_8_S_k_bool_,	mS_k_8(0) mS_k_8(1) mS_k_bool(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_NW_SET_ATTACH_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_NW_GET_ATTACH_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_NW_GET_ATTACH_RSP */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_NW_SET_MOBILE_CLASS_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_NW_SET_MOBILE_CLASS_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_NW_GET_MOBILE_CLASS_RSP */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_NW_SET_PLMN_SELECT_MODE_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_NW_SET_PLMN_SELECT_MODE_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_NW_GET_PLMN_SELECT_MODE_RSP */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_V0A_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_V0A_K_8_S_K_8_
	/* MSG_ID_MMI_NW_SET_PLMN_REQ */	MSGSTRUCT(S_k_8_v0A_k_8_S_k_8_,	mS_k_8(0) mv0A_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_8_V0A_K_8_S_K_8_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_8_V0A_K_8_S_K_8_
	/* MSG_ID_MMI_NW_SET_PLMN_RSP */	MSGSTRUCT(S_l_result_s_S_k_8_v0A_k_8_S_k_8_,	mS_l_result_s(0) mS_k_8(1) mv0A_k_8(2) mS_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_8_16A_L_RAT_PLMN_INFO_S_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_8_16A_L_RAT_PLMN_INFO_S_
	/* MSG_ID_MMI_NW_GET_PLMN_LIST_RSP */	MSGSTRUCT(S_l_result_s_S_k_8_16A_l_rat_plmn_info_s_,	mS_l_result_s(0) mS_k_8(1) m16A_l_rat_plmn_info_s(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_V0A_K_8_
#define _MSGSTRUCT_S_K_BOOL_V0A_K_8_
	/* MSG_ID_MMI_NW_GET_CURRENT_PLMN_RSP */	MSGSTRUCT(S_k_bool_v0A_k_8_,	mS_k_bool(0) mv0A_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_
	/* MSG_ID_MMI_NW_GET_SIGNAL_LEVEL_RSP */	MSGSTRUCT(S_k_bool_S_k_8_S_k_8_,	mS_k_bool(0) mS_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_NW_GET_BAND_RSP */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_V0A_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_2A_K_8_
#define _MSGSTRUCT_S_K_8_V0A_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_2A_K_8_
	/* MSG_ID_MMI_NW_ATTACH_IND */	MSGSTRUCT(S_k_8_v0A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_2A_k_8_,	mS_k_8(0) mv0A_k_8(1) mS_k_8(2) mS_k_8(3) mS_k_8(4) mS_k_8(5) mS_k_8(6) m2A_k_8(7) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_16_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_16_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_NW_REG_STATE_IND */	MSGSTRUCT(S_k_8_S_k_16_S_k_8_S_k_8_S_k_8_,	mS_k_8(0) mS_k_16(1) mS_k_8(2) mS_k_8(3) mS_k_8(4) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_NW_RX_LEVEL_IND */	MSGSTRUCT(S_k_8_S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_BOOL_S_K_8_24A_K_8_S_K_8_S_K_8_S_K_BOOL_S_K_8_24A_K_8_S_K_8_S_K_8_S_K_8_S_L_NW_TIME_ZONE_TIME_S_S_K_8_S_K_8_3A_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_BOOL_S_K_8_24A_K_8_S_K_8_S_K_8_S_K_BOOL_S_K_8_24A_K_8_S_K_8_S_K_8_S_K_8_S_L_NW_TIME_ZONE_TIME_S_S_K_8_S_K_8_3A_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_NW_TIME_ZONE_IND */	MSGSTRUCT(S_k_8_S_k_8_S_k_bool_S_k_8_24A_k_8_S_k_8_S_k_8_S_k_bool_S_k_8_24A_k_8_S_k_8_S_k_8_S_k_8_S_l_nw_time_zone_time_s_S_k_8_S_k_8_3A_k_8_S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) mS_k_bool(2) mS_k_8(3) m24A_k_8(4) mS_k_8(5) mS_k_8(6) mS_k_bool(7) mS_k_8(8) m24A_k_8(9) mS_k_8(10) mS_k_8(11) mS_k_8(12) mS_l_nw_time_zone_time_s(13) mS_k_8(14) mS_k_8(15) m3A_k_8(16) mS_k_8(17) mS_k_8(18) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_NW_SEL_MODE_IND */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_NW_MMRR_SERVICE_STATUS_IND */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_NW_SET_PREFERRED_BAND_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_NW_SET_PREFERRED_BAND_RSP */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_NW_SET_GPRS_CONNECT_TYPE_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_NW_SET_GPRS_CONNECT_TYPE_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_NW_GET_GPRS_CONNECT_TYPE_RSP */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_
#define _MSGSTRUCT_S_L_RESULT_S_
	/* MSG_ID_MMI_NW_PWROFF_DETACH_RSP */	MSGSTRUCT(S_l_result_s_,	mS_l_result_s(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_NW_CFUN_STATE_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_NW_CFUN_STATE_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_NW_GET_RAT_MODE_RSP */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_NW_SET_RAT_MODE_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_NW_SET_RAT_MODE_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_NW_GET_PREFER_RAT_RSP */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_NW_SET_PREFER_RAT_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_NW_SET_PREFER_RAT_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#endif /* defined(__MOD_RAC__) */
/* Security Related Messages */
#if defined(__MOD_SMU__)
#ifndef _MSGSTRUCT_S_K_BOOL_17A_K_8_
#define _MSGSTRUCT_S_K_BOOL_17A_K_8_
	/* MSG_ID_MMI_SMU_GET_IMSI_RSP */	MSGSTRUCT(S_k_bool_17A_k_8_,	mS_k_bool(0) m17A_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_9A_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_9A_K_8_
	/* MSG_ID_MMI_SMU_LOCK_REQ */	MSGSTRUCT(S_k_8_S_k_8_9A_k_8_,	mS_k_8(0) mS_k_8(1) m9A_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_S_SIM_CHV_INFO_S_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_S_SIM_CHV_INFO_S_
	/* MSG_ID_MMI_SMU_LOCK_RSP */	MSGSTRUCT(S_k_bool_S_k_16_S_sim_chv_info_s_,	mS_k_bool(0) mS_k_16(1) mS_sim_chv_info_s(2) )

#endif
#ifndef _MSGSTRUCT_9A_K_8_
#define _MSGSTRUCT_9A_K_8_
	/* MSG_ID_MMI_SMU_RESET_DATA_REQ */	MSGSTRUCT(9A_k_8_,	m9A_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_SMU_RESET_DATA_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_SMU_GET_DIAL_MODE_RSP */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_9A_K_8_9A_K_8_
#define _MSGSTRUCT_S_K_8_9A_K_8_9A_K_8_
	/* MSG_ID_MMI_SMU_VERIFY_PIN_REQ */	MSGSTRUCT(S_k_8_9A_k_8_9A_k_8_,	mS_k_8(0) m9A_k_8(1) m9A_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_S_SIM_CHV_INFO_S_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_S_SIM_CHV_INFO_S_
	/* MSG_ID_MMI_SMU_VERIFY_PIN_RSP */	MSGSTRUCT(S_k_bool_S_k_8_S_sim_chv_info_s_,	mS_k_bool(0) mS_k_8(1) mS_sim_chv_info_s(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_SMU_GET_PIN_TYPE_RSP */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_V0A_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_V0A_K_8_S_K_8_
	/* MSG_ID_MMI_SMU_SET_PREFERRED_OPER_LIST_REQ */	MSGSTRUCT(S_k_8_S_k_8_v0A_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) mv0A_k_8(2) mS_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_SMU_SET_PREFERRED_OPER_LIST_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_16_S_K_16_
#define _MSGSTRUCT_S_K_8_S_K_16_S_K_16_
	/* MSG_ID_MMI_SMU_GET_PREFERRED_OPER_LIST_REQ */	MSGSTRUCT(S_k_8_S_k_16_S_k_16_,	mS_k_8(0) mS_k_16(1) mS_k_16(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_V1A_K_8_V2A_K_8_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_V1A_K_8_V2A_K_8_S_K_16_
	/* MSG_ID_MMI_SMU_GET_PREFERRED_OPER_LIST_RSP */	MSGSTRUCT(S_k_bool_S_k_16_v1A_k_8_v2A_k_8_S_k_16_,	mS_k_bool(0) mS_k_16(1) mv1A_k_8(2) mv2A_k_8(3) mS_k_16(4) )

#endif
#ifndef _MSGSTRUCT_9A_K_8_3A_K_8_18A_K_8_
#define _MSGSTRUCT_9A_K_8_3A_K_8_18A_K_8_
	/* MSG_ID_MMI_SMU_SET_PUC_REQ */	MSGSTRUCT(9A_k_8_3A_k_8_18A_k_8_,	m9A_k_8(0) m3A_k_8(1) m18A_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_SMU_SET_PUC_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_3A_K_8_18A_K_8_
#define _MSGSTRUCT_S_K_BOOL_3A_K_8_18A_K_8_
	/* MSG_ID_MMI_SMU_GET_PUC_RSP */	MSGSTRUCT(S_k_bool_3A_k_8_18A_k_8_,	mS_k_bool(0) m3A_k_8(1) m18A_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_9A_K_8_9A_K_8_9A_K_8_
#define _MSGSTRUCT_S_K_8_9A_K_8_9A_K_8_9A_K_8_
	/* MSG_ID_MMI_SMU_CHANGE_PASSWORD_REQ */	MSGSTRUCT(S_k_8_9A_k_8_9A_k_8_9A_k_8_,	mS_k_8(0) m9A_k_8(1) m9A_k_8(2) m9A_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_S_SIM_CHV_INFO_S_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_S_SIM_CHV_INFO_S_
	/* MSG_ID_MMI_SMU_CHANGE_PASSWORD_RSP */	MSGSTRUCT(S_k_bool_S_k_16_S_sim_chv_info_s_,	mS_k_bool(0) mS_k_16(1) mS_sim_chv_info_s(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_16_S_K_8_S_K_8_S_K_8_256A_K_8_
#define _MSGSTRUCT_S_K_8_S_K_16_S_K_8_S_K_8_S_K_8_256A_K_8_
	/* MSG_ID_MMI_SMU_RESTRICTED_ACCESS_REQ */	MSGSTRUCT(S_k_8_S_k_16_S_k_8_S_k_8_S_k_8_256A_k_8_,	mS_k_8(0) mS_k_16(1) mS_k_8(2) mS_k_8(3) mS_k_8(4) m256A_k_8(5) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_S_K_16_256A_K_8_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_S_K_16_256A_K_8_
	/* MSG_ID_MMI_SMU_RESTRICTED_ACCESS_RSP */	MSGSTRUCT(S_l_result_s_S_k_8_S_k_8_S_k_16_256A_k_8_,	mS_l_result_s(0) mS_k_8(1) mS_k_8(2) mS_k_16(3) m256A_k_8(4) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_9A_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_9A_K_8_
	/* MSG_ID_MMI_SMU_SET_DIAL_MODE_REQ */	MSGSTRUCT(S_k_8_S_k_8_9A_k_8_,	mS_k_8(0) mS_k_8(1) m9A_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_SMU_SET_DIAL_MODE_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_260A_K_8_S_K_16_6A_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_260A_K_8_S_K_16_6A_K_8_
	/* MSG_ID_MMI_SMU_WRITE_SIM_REQ */	MSGSTRUCT(S_k_8_S_k_8_260A_k_8_S_k_16_6A_k_8_,	mS_k_8(0) mS_k_8(1) m260A_k_8(2) mS_k_16(3) m6A_k_8(4) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_SMU_WRITE_SIM_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_16_S_K_16_6A_K_8_
#define _MSGSTRUCT_S_K_8_S_K_16_S_K_16_6A_K_8_
	/* MSG_ID_MMI_SMU_READ_SIM_REQ */	MSGSTRUCT(S_k_8_S_k_16_S_k_16_6A_k_8_,	mS_k_8(0) mS_k_16(1) mS_k_16(2) m6A_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_16_260A_K_8_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_16_260A_K_8_
	/* MSG_ID_MMI_SMU_READ_SIM_RSP */	MSGSTRUCT(S_l_result_s_S_k_16_260A_k_8_,	mS_l_result_s(0) mS_k_16(1) m260A_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_SMU_POWER_OFF_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_SMU_REMOVE_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_SMU_REMOVE_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_BOOL_S_SIM_CHV_INFO_S_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_BOOL_S_SIM_CHV_INFO_S_S_K_8_
	/* MSG_ID_MMI_SMU_PASSWORD_REQUIRED_IND */	MSGSTRUCT(S_k_8_S_k_bool_S_sim_chv_info_s_S_k_8_,	mS_k_8(0) mS_k_bool(1) mS_sim_chv_info_s(2) mS_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_K_16_
#define _MSGSTRUCT_S_K_16_
	/* MSG_ID_MMI_SMU_SUPPORT_PLMN_LIST_IND */	MSGSTRUCT(S_k_16_,	mS_k_16(0) )

#endif
#ifndef _MSGSTRUCT_S_K_16_
#define _MSGSTRUCT_S_K_16_
	/* MSG_ID_MMI_SMU_FAIL_IND */	MSGSTRUCT(S_k_16_,	mS_k_16(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_6A_K_8_
#define _MSGSTRUCT_S_K_8_6A_K_8_
	/* MSG_ID_MMI_SMU_READ_FILE_INFO_REQ */	MSGSTRUCT(S_k_8_6A_k_8_,	mS_k_8(0) m6A_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_16_S_K_8_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_16_S_K_8_
	/* MSG_ID_MMI_SMU_READ_FILE_INFO_RSP */	MSGSTRUCT(S_l_result_s_S_k_16_S_k_8_,	mS_l_result_s(0) mS_k_16(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_SIM_CHV_INFO_S_S_SIM_CHV_STATUS_S_
#define _MSGSTRUCT_S_K_BOOL_S_SIM_CHV_INFO_S_S_SIM_CHV_STATUS_S_
	/* MSG_ID_MMI_SMU_CHECK_PIN_STATUS_RSP */	MSGSTRUCT(S_k_bool_S_sim_chv_info_s_S_sim_chv_status_s_,	mS_k_bool(0) mS_sim_chv_info_s(1) mS_sim_chv_status_s(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_35A_K_8_5A_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_35A_K_8_5A_K_8_S_K_8_
	/* MSG_ID_MMI_SMU_STARTUP_INFO_IND */	MSGSTRUCT(S_k_8_35A_k_8_5A_k_8_S_k_8_,	mS_k_8(0) m35A_k_8(1) m5A_k_8(2) mS_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SMU_CIPHER_IND */	MSGSTRUCT(S_k_bool_S_k_8_S_k_8_S_k_8_,	mS_k_bool(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_8A_K_8_S_K_8_10A_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_8A_K_8_S_K_8_10A_K_8_
	/* MSG_ID_MMI_SMU_SET_PERSONALIZATION_REQ */	MSGSTRUCT(S_k_8_S_k_8_8A_k_8_S_k_8_10A_k_8_,	mS_k_8(0) mS_k_8(1) m8A_k_8(2) mS_k_8(3) m10A_k_8(4) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SMU_SET_PERSONALIZATION_RSP */	MSGSTRUCT(S_l_result_s_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_,	mS_l_result_s(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) mS_k_8(4) mS_k_8(5) mS_k_8(6) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_7A_K_8_7A_K_8_7A_K_8_7A_K_8_7A_K_8_7A_K_8_16A_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_L_RESULT_S_7A_K_8_7A_K_8_7A_K_8_7A_K_8_7A_K_8_7A_K_8_16A_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SMU_SML_STATUS_RSP */	MSGSTRUCT(S_l_result_s_7A_k_8_7A_k_8_7A_k_8_7A_k_8_7A_k_8_7A_k_8_16A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_,	mS_l_result_s(0) m7A_k_8(1) m7A_k_8(2) m7A_k_8(3) m7A_k_8(4) m7A_k_8(5) m7A_k_8(6) m16A_k_8(7) mS_k_8(8) mS_k_8(9) mS_k_8(10) mS_k_8(11) mS_k_8(12) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_SIM_CHV_INFO_S_
#define _MSGSTRUCT_S_K_8_S_SIM_CHV_INFO_S_
	/* MSG_ID_MMI_SMU_VERIFY_PIN_RESULT_IND */	MSGSTRUCT(S_k_8_S_sim_chv_info_s_,	mS_k_8(0) mS_sim_chv_info_s(1) )

#endif
#endif /* defined(__MOD_SMU__) */
/* PhoneBook Related Messages */
#if defined(__MOD_PHB__)
#ifndef _MSGSTRUCT_S_K_8_S_K_16_S_L4_NAME_S_
#define _MSGSTRUCT_S_K_8_S_K_16_S_L4_NAME_S_
	/* MSG_ID_MMI_PHB_GET_ENTRY_BY_NAME_REQ */	MSGSTRUCT(S_k_8_S_k_16_S_l4_name_s_,	mS_k_8(0) mS_k_16(1) mS_l4_name_s(2) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_16_15A_L_PHB_ENTRY_S_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_16_15A_L_PHB_ENTRY_S_
	/* MSG_ID_MMI_PHB_GET_ENTRY_BY_NAME_RSP */	MSGSTRUCT(S_l_result_s_S_k_16_15A_l_phb_entry_s_,	mS_l_result_s(0) mS_k_16(1) m15A_l_phb_entry_s(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_16_S_K_16_S_K_16_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_16_S_K_16_S_K_16_
	/* MSG_ID_MMI_PHB_GET_ENTRY_BY_INDEX_REQ */	MSGSTRUCT(S_k_8_S_k_8_S_k_16_S_k_16_S_k_16_,	mS_k_8(0) mS_k_8(1) mS_k_16(2) mS_k_16(3) mS_k_16(4) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_16_15A_L_PHB_ENTRY_S_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_16_15A_L_PHB_ENTRY_S_
	/* MSG_ID_MMI_PHB_GET_ENTRY_BY_INDEX_RSP */	MSGSTRUCT(S_l_result_s_S_k_16_15A_l_phb_entry_s_,	mS_l_result_s(0) mS_k_16(1) m15A_l_phb_entry_s(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_PHB_SET_PREFERRED_STORAGE_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_PHB_SET_PREFERRED_STORAGE_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_16_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_16_S_K_16_
	/* MSG_ID_MMI_PHB_GET_PREFERRED_STORAGE_RSP */	MSGSTRUCT(S_k_bool_S_k_8_S_k_16_S_k_16_,	mS_k_bool(0) mS_k_8(1) mS_k_16(2) mS_k_16(3) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_16_S_L_PHB_ENTRY_S_
#define _MSGSTRUCT_S_K_8_S_K_16_S_L_PHB_ENTRY_S_
	/* MSG_ID_MMI_PHB_SET_ENTRY_REQ */	MSGSTRUCT(S_k_8_S_k_16_S_l_phb_entry_s_,	mS_k_8(0) mS_k_16(1) mS_l_phb_entry_s(2) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_16_15A_L_PHB_ENTRY_S_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_16_15A_L_PHB_ENTRY_S_
	/* MSG_ID_MMI_PHB_SET_ENTRY_RSP */	MSGSTRUCT(S_l_result_s_S_k_16_15A_l_phb_entry_s_,	mS_l_result_s(0) mS_k_16(1) m15A_l_phb_entry_s(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_16_S_K_8_S_K_8_S_K_BOOL_
#define _MSGSTRUCT_S_K_8_S_K_16_S_K_8_S_K_8_S_K_BOOL_
	/* MSG_ID_MMI_PHB_DEL_ENTRY_REQ */	MSGSTRUCT(S_k_8_S_k_16_S_k_8_S_k_8_S_k_bool_,	mS_k_8(0) mS_k_16(1) mS_k_8(2) mS_k_8(3) mS_k_bool(4) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_16_15A_L_PHB_ENTRY_S_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_16_15A_L_PHB_ENTRY_S_
	/* MSG_ID_MMI_PHB_DEL_ENTRY_RSP */	MSGSTRUCT(S_l_result_s_S_k_16_15A_l_phb_entry_s_,	mS_l_result_s(0) mS_k_16(1) m15A_l_phb_entry_s(2) )

#endif
#ifndef _MSGSTRUCT_S_L_NUMBER_S_
#define _MSGSTRUCT_S_L_NUMBER_S_
	/* MSG_ID_MMI_PHB_SET_VOICE_MAIL_SERVER_REQ */	MSGSTRUCT(S_l_number_s_,	mS_l_number_s(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_PHB_SET_VOICE_MAIL_SERVER_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_PHB_GET_ALPHA_LIST_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_26A_K_16_
#define _MSGSTRUCT_S_K_BOOL_26A_K_16_
	/* MSG_ID_MMI_PHB_GET_ALPHA_LIST_RSP */	MSGSTRUCT(S_k_bool_26A_k_16_,	mS_k_bool(0) m26A_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_PHB_GET_TYPE_STATUS_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_S_K_16_
	/* MSG_ID_MMI_PHB_GET_TYPE_STATUS_RSP */	MSGSTRUCT(S_k_bool_S_k_16_S_k_16_,	mS_k_bool(0) mS_k_16(1) mS_k_16(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_PHB_GET_LAST_NUMBER_REQ */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_1A_L_PHB_LN_ENTRY_S_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_1A_L_PHB_LN_ENTRY_S_
	/* MSG_ID_MMI_PHB_GET_LAST_NUMBER_RSP */	MSGSTRUCT(S_l_result_s_S_k_8_S_k_8_S_k_8_1A_l_phb_ln_entry_s_,	mS_l_result_s(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) m1A_l_phb_ln_entry_s(4) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_L_PHB_LN_ENTRY_S_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_L_PHB_LN_ENTRY_S_
	/* MSG_ID_MMI_PHB_SET_LAST_NUMBER_REQ */	MSGSTRUCT(S_k_8_S_k_8_S_k_8_S_l_phb_ln_entry_s_,	mS_k_8(0) mS_k_8(1) mS_k_8(2) mS_l_phb_ln_entry_s(3) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_16_S_K_8_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_16_S_K_8_
	/* MSG_ID_MMI_PHB_SET_LAST_NUMBER_RSP */	MSGSTRUCT(S_l_result_s_S_k_16_S_k_8_,	mS_l_result_s(0) mS_k_16(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_PHB_DEL_LAST_NUMBER_REQ */	MSGSTRUCT(S_k_8_S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_16_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_16_
	/* MSG_ID_MMI_PHB_DEL_LAST_NUMBER_RSP */	MSGSTRUCT(S_l_result_s_S_k_16_,	mS_l_result_s(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_16_S_K_16_S_K_8_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_16_S_K_16_S_K_8_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_PHB_STARTUP_FINISH_IND */	MSGSTRUCT(S_k_16_S_k_16_S_k_8_S_k_8_S_k_8_S_k_8_,	mS_k_16(0) mS_k_16(1) mS_k_8(2) mS_k_8(3) mS_k_8(4) mS_k_8(5) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_16_S_K_16_S_K_16_S_K_16_1A_L_PHB_ENTRY_S_
#define _MSGSTRUCT_S_K_8_S_K_16_S_K_16_S_K_16_S_K_16_1A_L_PHB_ENTRY_S_
	/* MSG_ID_MMI_PHB_UPDATE_IND */	MSGSTRUCT(S_k_8_S_k_16_S_k_16_S_k_16_S_k_16_1A_l_phb_entry_s_,	mS_k_8(0) mS_k_16(1) mS_k_16(2) mS_k_16(3) mS_k_16(4) m1A_l_phb_entry_s(5) )

#endif
#ifndef _MSGSTRUCT_1A_L_PHB_ENTRIES_S_S_K_8_
#define _MSGSTRUCT_1A_L_PHB_ENTRIES_S_S_K_8_
	/* MSG_ID_MMI_PHB_STARTUP_READ_IND */	MSGSTRUCT(1A_l_phb_entries_s_S_k_8_,	m1A_l_phb_entries_s(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_PHB_STARTUP_READ_NEXT_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_PHB_STARTUP_READ_NEXT_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_16_S_K_16_S_K_8_S_K_8_S_K_8_S_K_8_S_K_BOOL_S_K_BOOL_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_16_S_K_16_S_K_16_S_K_16_S_K_16_S_K_16_
#define _MSGSTRUCT_S_K_16_S_K_16_S_K_8_S_K_8_S_K_8_S_K_8_S_K_BOOL_S_K_BOOL_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_16_S_K_16_S_K_16_S_K_16_S_K_16_S_K_16_
	/* MSG_ID_MMI_PHB_STARTUP_PHASE1_IND */	MSGSTRUCT(S_k_16_S_k_16_S_k_8_S_k_8_S_k_8_S_k_8_S_k_bool_S_k_bool_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_16_S_k_16_S_k_16_S_k_16_S_k_16_S_k_16_,	mS_k_16(0) mS_k_16(1) mS_k_8(2) mS_k_8(3) mS_k_8(4) mS_k_8(5) mS_k_bool(6) mS_k_bool(7) mS_k_8(8) mS_k_8(9) mS_k_8(10) mS_k_8(11) mS_k_8(12) mS_k_8(13) mS_k_8(14) mS_k_8(15) mS_k_16(16) mS_k_16(17) mS_k_16(18) mS_k_16(19) mS_k_16(20) mS_k_16(21) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_PHB_STARTUP_READ_NEXT_USIM_FIELD_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_V3A_L_PHB_BCD_ANR_S_S_K_8_
#define _MSGSTRUCT_S_K_8_V3A_L_PHB_BCD_ANR_S_S_K_8_
	/* MSG_ID_MMI_PHB_STARTUP_READ_ANR_IND */	MSGSTRUCT(S_k_8_v3A_l_phb_bcd_anr_s_S_k_8_,	mS_k_8(0) mv3A_l_phb_bcd_anr_s(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_V4A_L_PHB_EMAIL_S_S_K_8_
#define _MSGSTRUCT_S_K_8_V4A_L_PHB_EMAIL_S_S_K_8_
	/* MSG_ID_MMI_PHB_STARTUP_READ_EMAIL_IND */	MSGSTRUCT(S_k_8_v4A_l_phb_email_s_S_k_8_,	mS_k_8(0) mv4A_l_phb_email_s(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_16_S_K_16_
#define _MSGSTRUCT_S_K_16_S_K_16_
	/* MSG_ID_MMI_PHB_READ_EMAIL_REQ */	MSGSTRUCT(S_k_16_S_k_16_,	mS_k_16(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_16_S_L_PHB_EMAIL_S_P_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_16_S_L_PHB_EMAIL_S_P_
	/* MSG_ID_MMI_PHB_READ_EMAIL_RSP */	MSGSTRUCT(S_l_result_s_S_k_16_S_l_phb_email_s_p_,	mS_l_result_s(0) mS_k_16(1) mS_l_phb_email_s_p(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_5A_L_PHB_ENTRY_S_S_K_8_
#define _MSGSTRUCT_S_K_8_5A_L_PHB_ENTRY_S_S_K_8_
	/* MSG_ID_MMI_PHB_STARTUP_READ_GAS_IND */	MSGSTRUCT(S_k_8_5A_l_phb_entry_s_S_k_8_,	mS_k_8(0) m5A_l_phb_entry_s(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_1000A_K_8_S_K_8_
#define _MSGSTRUCT_1000A_K_8_S_K_8_
	/* MSG_ID_MMI_PHB_STARTUP_READ_GRP_IND */	MSGSTRUCT(1000A_k_8_S_k_8_,	m1000A_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_16_S_K_8_
#define _MSGSTRUCT_S_K_16_S_K_8_
	/* MSG_ID_MMI_PHB_SET_GRP_REQ */	MSGSTRUCT(S_k_16_S_k_8_,	mS_k_16(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_16_S_K_8_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_16_S_K_8_
	/* MSG_ID_MMI_PHB_SET_GRP_RSP */	MSGSTRUCT(S_l_result_s_S_k_16_S_k_8_,	mS_l_result_s(0) mS_k_16(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_16_S_L_PHB_ENTRY_S_S_K_8_S_L_PHB_ANR_S_S_L_PHB_ANR_S_S_L_PHB_ANR_S_S_L_PHB_EMAIL_S_S_L4_NAME_S_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_16_S_L_PHB_ENTRY_S_S_K_8_S_L_PHB_ANR_S_S_L_PHB_ANR_S_S_L_PHB_ANR_S_S_L_PHB_EMAIL_S_S_L4_NAME_S_S_K_8_S_K_8_
	/* MSG_ID_MMI_PHB_WRITE_USIM_REQ */	MSGSTRUCT(S_k_8_S_k_16_S_l_phb_entry_s_S_k_8_S_l_phb_anr_s_S_l_phb_anr_s_S_l_phb_anr_s_S_l_phb_email_s_S_l4_name_s_S_k_8_S_k_8_,	mS_k_8(0) mS_k_16(1) mS_l_phb_entry_s(2) mS_k_8(3) mS_l_phb_anr_s(4) mS_l_phb_anr_s(5) mS_l_phb_anr_s(6) mS_l_phb_email_s(7) mS_l4_name_s(8) mS_k_8(9) mS_k_8(10) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_L_PHB_ENTRY_S_S_K_8_S_L_PHB_ANR_S_S_L_PHB_ANR_S_S_L_PHB_ANR_S_S_L_PHB_EMAIL_S_S_L4_NAME_S_S_K_8_S_K_8_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_L_PHB_ENTRY_S_S_K_8_S_L_PHB_ANR_S_S_L_PHB_ANR_S_S_L_PHB_ANR_S_S_L_PHB_EMAIL_S_S_L4_NAME_S_S_K_8_S_K_8_
	/* MSG_ID_MMI_PHB_WRITE_USIM_RSP */	MSGSTRUCT(S_l_result_s_S_k_8_S_l_phb_entry_s_S_k_8_S_l_phb_anr_s_S_l_phb_anr_s_S_l_phb_anr_s_S_l_phb_email_s_S_l4_name_s_S_k_8_S_k_8_,	mS_l_result_s(0) mS_k_8(1) mS_l_phb_entry_s(2) mS_k_8(3) mS_l_phb_anr_s(4) mS_l_phb_anr_s(5) mS_l_phb_anr_s(6) mS_l_phb_email_s(7) mS_l4_name_s(8) mS_k_8(9) mS_k_8(10) )

#endif
#endif /* defined(__MOD_PHB__) */
#ifndef _MSGSTRUCT_S_K_16_S_K_8_S_K_8_S_K_8_S_K_8_S_L_NUMBER_S_S_L4_NAME_S_
#define _MSGSTRUCT_S_K_16_S_K_8_S_K_8_S_K_8_S_K_8_S_L_NUMBER_S_S_L4_NAME_S_
	/* MSG_ID_MMI_SMS_SET_PROFILE_PARAMS_REQ */	MSGSTRUCT(S_k_16_S_k_8_S_k_8_S_k_8_S_k_8_S_l_number_s_S_l4_name_s_,	mS_k_16(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) mS_k_8(4) mS_l_number_s(5) mS_l4_name_s(6) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_SMS_SET_PROFILE_PARAMS_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_S_K_8_S_L_NUMBER_S_S_L4_NAME_S_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_S_K_8_S_L_NUMBER_S_S_L4_NAME_S_
	/* MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_RSP */	MSGSTRUCT(S_k_bool_S_k_8_S_k_8_S_k_8_S_l_number_s_S_l4_name_s_,	mS_k_bool(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) mS_l_number_s(4) mS_l4_name_s(5) )

#endif
#ifndef _MSGSTRUCT_S_K_16_S_K_8_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_16_S_K_8_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SMS_SET_COMMON_PARAMS_REQ */	MSGSTRUCT(S_k_16_S_k_8_S_k_8_S_k_8_S_k_8_,	mS_k_16(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) mS_k_8(4) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_SMS_SET_COMMON_PARAMS_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SMS_GET_COMMON_PARAMS_RSP */	MSGSTRUCT(S_k_bool_S_k_8_S_k_8_S_k_8_S_k_8_,	mS_k_bool(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) mS_k_8(4) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_K_8_S_L_NUMBER_S_S_K_8_156A_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_K_8_S_L_NUMBER_S_S_K_8_156A_K_8_
	/* MSG_ID_MMI_SMS_SEND_COMMAND_REQ */	MSGSTRUCT(S_k_8_S_k_8_S_k_8_S_k_8_S_l_number_s_S_k_8_156A_k_8_,	mS_k_8(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) mS_l_number_s(4) mS_k_8(5) m156A_k_8(6) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_S_K_8_7A_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_S_K_8_7A_K_8_
	/* MSG_ID_MMI_SMS_SEND_COMMAND_RSP */	MSGSTRUCT(S_k_bool_S_k_16_S_k_8_7A_k_8_,	mS_k_bool(0) mS_k_16(1) mS_k_8(2) m7A_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_16_480A_K_8_S_K_BOOL_
#define _MSGSTRUCT_S_K_8_S_K_16_480A_K_8_S_K_BOOL_
	/* MSG_ID_MMI_SMS_DEL_MSG_REQ */	MSGSTRUCT(S_k_8_S_k_16_480A_k_8_S_k_bool_,	mS_k_8(0) mS_k_16(1) m480A_k_8(2) mS_k_bool(3) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_S_K_8_S_K_16_S_K_8_480A_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_S_K_8_S_K_16_S_K_8_480A_K_8_
	/* MSG_ID_MMI_SMS_DEL_MSG_RSP */	MSGSTRUCT(S_k_bool_S_k_16_S_k_8_S_k_16_S_k_8_480A_k_8_,	mS_k_bool(0) mS_k_16(1) mS_k_8(2) mS_k_16(3) mS_k_8(4) m480A_k_8(5) )

#endif
#ifndef _MSGSTRUCT_S_K_16_S_K_BOOL_
#define _MSGSTRUCT_S_K_16_S_K_BOOL_
	/* MSG_ID_MMI_SMS_GET_MSG_REQ */	MSGSTRUCT(S_k_16_S_k_bool_,	mS_k_16(0) mS_k_bool(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_S_SMSAL_CONCAT_S_S_K_8_S_K_8_S_K_8_S_K_8_7A_K_8_S_L_NUMBER_S_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_7A_K_8_S_K_8_S_K_16_S_K_16_S_K_16_1A_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_S_SMSAL_CONCAT_S_S_K_8_S_K_8_S_K_8_S_K_8_7A_K_8_S_L_NUMBER_S_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_7A_K_8_S_K_8_S_K_16_S_K_16_S_K_16_1A_K_8_
	/* MSG_ID_MMI_SMS_GET_MSG_RSP */	MSGSTRUCT(S_k_bool_S_k_16_S_smsal_concat_s_S_k_8_S_k_8_S_k_8_S_k_8_7A_k_8_S_l_number_s_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_7A_k_8_S_k_8_S_k_16_S_k_16_S_k_16_1A_k_8_,	mS_k_bool(0) mS_k_16(1) mS_smsal_concat_s(2) mS_k_8(3) mS_k_8(4) mS_k_8(5) mS_k_8(6) m7A_k_8(7) mS_l_number_s(8) mS_l_number_s(9) mS_k_8(10) mS_k_8(11) mS_k_8(12) mS_k_8(13) mS_k_8(14) m7A_k_8(15) mS_k_8(16) mS_k_16(17) mS_k_16(18) mS_k_16(19) m1A_k_8(20) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_16_S_L_NUMBER_S_S_K_8_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_8_S_K_16_160A_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_16_S_L_NUMBER_S_S_K_8_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_8_S_K_16_160A_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SMS_SEND_MSG_REQ */	MSGSTRUCT(S_k_8_S_k_16_S_l_number_s_S_k_8_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_S_k_16_160A_k_8_S_k_8_S_k_8_,	mS_k_8(0) mS_k_16(1) mS_l_number_s(2) mS_k_8(3) mS_l_number_s(4) mS_k_8(5) mS_k_8(6) mS_k_8(7) mS_k_8(8) mS_k_16(9) m160A_k_8(10) mS_k_8(11) mS_k_8(12) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_S_K_8_7A_K_8_S_K_8_S_SMSAL_CONCAT_S_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_S_K_8_7A_K_8_S_K_8_S_SMSAL_CONCAT_S_
	/* MSG_ID_MMI_SMS_SEND_MSG_RSP */	MSGSTRUCT(S_k_bool_S_k_16_S_k_8_7A_k_8_S_k_8_S_smsal_concat_s_,	mS_k_bool(0) mS_k_16(1) mS_k_8(2) m7A_k_8(3) mS_k_8(4) mS_smsal_concat_s(5) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_L_NUMBER_S_S_K_8_S_L_NUMBER_S_7A_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_16_S_K_16_160A_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_L_NUMBER_S_S_K_8_S_L_NUMBER_S_7A_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_16_S_K_16_160A_K_8_
	/* MSG_ID_MMI_SMS_SET_MSG_REQ */	MSGSTRUCT(S_k_8_S_k_8_S_l_number_s_S_k_8_S_l_number_s_7A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_16_S_k_16_160A_k_8_,	mS_k_8(0) mS_k_8(1) mS_l_number_s(2) mS_k_8(3) mS_l_number_s(4) m7A_k_8(5) mS_k_8(6) mS_k_8(7) mS_k_8(8) mS_k_8(9) mS_k_16(10) mS_k_16(11) m160A_k_8(12) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_S_K_16_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_S_K_16_S_K_8_S_K_8_
	/* MSG_ID_MMI_SMS_SET_MSG_RSP */	MSGSTRUCT(S_k_bool_S_k_16_S_k_16_S_k_8_S_k_8_,	mS_k_bool(0) mS_k_16(1) mS_k_16(2) mS_k_8(3) mS_k_8(4) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SMS_SET_PREFERRED_STORAGE_REQ */	MSGSTRUCT(S_k_8_S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_SMSAL_PREFER_STORAGE_S_
#define _MSGSTRUCT_S_K_BOOL_S_SMSAL_PREFER_STORAGE_S_
	/* MSG_ID_MMI_SMS_SET_PREFERRED_STORAGE_RSP */	MSGSTRUCT(S_k_bool_S_smsal_prefer_storage_s_,	mS_k_bool(0) mS_smsal_prefer_storage_s(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_SMSAL_PREFER_STORAGE_S_
#define _MSGSTRUCT_S_K_BOOL_S_SMSAL_PREFER_STORAGE_S_
	/* MSG_ID_MMI_SMS_GET_PREFERRED_STORAGE_RSP */	MSGSTRUCT(S_k_bool_S_smsal_prefer_storage_s_,	mS_k_bool(0) mS_smsal_prefer_storage_s(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_32_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_32_S_K_16_
	/* MSG_ID_MMI_SMS_REG_PORT_NUM_REQ */	MSGSTRUCT(S_k_bool_S_k_32_S_k_16_,	mS_k_bool(0) mS_k_32(1) mS_k_16(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_S_K_32_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_S_K_32_S_K_16_
	/* MSG_ID_MMI_SMS_REG_PORT_NUM_RSP */	MSGSTRUCT(S_k_bool_S_k_16_S_k_32_S_k_16_,	mS_k_bool(0) mS_k_16(1) mS_k_32(2) mS_k_16(3) )

#endif
#ifndef _MSGSTRUCT_S_K_8_7A_K_8_S_L_NUMBER_S_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_16_S_K_16_S_K_16_S_K_8_S_K_8_S_K_8_S_K_32_S_K_16_1A_K_8_
#define _MSGSTRUCT_S_K_8_7A_K_8_S_L_NUMBER_S_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_16_S_K_16_S_K_16_S_K_8_S_K_8_S_K_8_S_K_32_S_K_16_1A_K_8_
	/* MSG_ID_MMI_SMS_DELIVER_MSG_IND */	MSGSTRUCT(S_k_8_7A_k_8_S_l_number_s_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_16_S_k_16_S_k_16_S_k_8_S_k_8_S_k_8_S_k_32_S_k_16_1A_k_8_,	mS_k_8(0) m7A_k_8(1) mS_l_number_s(2) mS_l_number_s(3) mS_k_8(4) mS_k_8(5) mS_k_8(6) mS_k_16(7) mS_k_16(8) mS_k_16(9) mS_k_8(10) mS_k_8(11) mS_k_8(12) mS_k_32(13) mS_k_16(14) m1A_k_8(15) )

#endif
#ifndef _MSGSTRUCT_S_K_8_7A_K_8_7A_K_8_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_8_S_K_16_1A_K_8_
#define _MSGSTRUCT_S_K_8_7A_K_8_7A_K_8_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_8_S_K_16_1A_K_8_
	/* MSG_ID_MMI_SMS_STATUS_REPORT_IND */	MSGSTRUCT(S_k_8_7A_k_8_7A_k_8_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_S_k_16_1A_k_8_,	mS_k_8(0) m7A_k_8(1) m7A_k_8(2) mS_l_number_s(3) mS_k_8(4) mS_k_8(5) mS_k_8(6) mS_k_8(7) mS_k_16(8) m1A_k_8(9) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_SMS_MEM_AVAILABLE_IND */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_SMS_MEM_EXCEED_IND */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_SMS_MEM_FULL_IND */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_SMS_READY_IND */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_16_S_K_16_S_K_16_S_K_8_S_K_8_S_K_16_V5A_K_32_S_L_NUMBER_S_7A_K_8_160A_K_8_
#define _MSGSTRUCT_S_K_16_S_K_16_S_K_16_S_K_8_S_K_8_S_K_16_V5A_K_32_S_L_NUMBER_S_7A_K_8_160A_K_8_
	/* MSG_ID_MMI_SMS_APP_DATA_IND */	MSGSTRUCT(S_k_16_S_k_16_S_k_16_S_k_8_S_k_8_S_k_16_v5A_k_32_S_l_number_s_7A_k_8_160A_k_8_,	mS_k_16(0) mS_k_16(1) mS_k_16(2) mS_k_8(3) mS_k_8(4) mS_k_16(5) mv5A_k_32(6) mS_l_number_s(7) m7A_k_8(8) m160A_k_8(9) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_BOOL_S_K_16_S_K_16_S_K_16_S_K_16_S_K_16_S_K_16_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_BOOL_S_K_16_S_K_16_S_K_16_S_K_16_S_K_16_S_K_16_S_K_16_
	/* MSG_ID_MMI_SMS_GET_MSG_NUM_RSP */	MSGSTRUCT(S_k_bool_S_k_bool_S_k_16_S_k_16_S_k_16_S_k_16_S_k_16_S_k_16_S_k_16_,	mS_k_bool(0) mS_k_bool(1) mS_k_16(2) mS_k_16(3) mS_k_16(4) mS_k_16(5) mS_k_16(6) mS_k_16(7) mS_k_16(8) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_
	/* MSG_ID_MMI_SMS_GET_PROFILE_NUM_RSP */	MSGSTRUCT(S_k_bool_S_k_8_S_k_8_,	mS_k_bool(0) mS_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_SMS_ABORT_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_K_BOOL_S_K_BOOL_S_K_BOOL_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_K_BOOL_S_K_BOOL_S_K_BOOL_
	/* MSG_ID_MMI_SMS_MSG_WAITING_IND */	MSGSTRUCT(S_k_8_S_k_8_S_k_8_S_k_bool_S_k_bool_S_k_bool_,	mS_k_8(0) mS_k_8(1) mS_k_8(2) mS_k_bool(3) mS_k_bool(4) mS_k_bool(5) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_L_NUMBER_S_S_L4_NAME_S_
#define _MSGSTRUCT_S_K_8_S_L_NUMBER_S_S_L4_NAME_S_
	/* MSG_ID_MMI_SMS_SET_MAILBOX_ADDRESS_REQ */	MSGSTRUCT(S_k_8_S_l_number_s_S_l4_name_s_,	mS_k_8(0) mS_l_number_s(1) mS_l4_name_s(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_SMS_SET_MAILBOX_ADDRESS_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_2A_L_SMS_MAILBOX_INFO_S_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_2A_L_SMS_MAILBOX_INFO_S_
	/* MSG_ID_MMI_SMS_GET_MAILBOX_ADDRESS_RSP */	MSGSTRUCT(S_k_bool_S_k_8_S_k_8_2A_l_sms_mailbox_info_s_,	mS_k_bool(0) mS_k_8(1) mS_k_8(2) m2A_l_sms_mailbox_info_s(3) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_16_S_K_8_480A_K_8_
#define _MSGSTRUCT_S_K_8_S_K_16_S_K_8_480A_K_8_
	/* MSG_ID_MMI_SMS_SYNC_MSG_IND */	MSGSTRUCT(S_k_8_S_k_16_S_k_8_480A_k_8_,	mS_k_8(0) mS_k_16(1) mS_k_8(2) m480A_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_SMS_SYNC_MSG_RES_REQ */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_SMS_SEND_ABORT_FINISH_IND */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_SMS_STARTUP_READ_NEXT_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_16_7A_K_8_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_7A_K_8_S_K_8_S_K_16_S_K_16_S_K_32_S_K_16_1A_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_16_7A_K_8_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_7A_K_8_S_K_8_S_K_16_S_K_16_S_K_32_S_K_16_1A_K_8_
	/* MSG_ID_MMI_SMS_STARTUP_READ_MSG_IND */	MSGSTRUCT(S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_16_7A_k_8_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_7A_k_8_S_k_8_S_k_16_S_k_16_S_k_32_S_k_16_1A_k_8_,	mS_k_8(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) mS_k_8(4) mS_k_16(5) m7A_k_8(6) mS_l_number_s(7) mS_k_8(8) mS_k_8(9) mS_k_8(10) mS_k_8(11) mS_k_8(12) m7A_k_8(13) mS_k_8(14) mS_k_16(15) mS_k_16(16) mS_k_32(17) mS_k_16(18) m1A_k_8(19) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_16_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_16_
	/* MSG_ID_MMI_SMS_COPY_MSG_REQ */	MSGSTRUCT(S_k_8_S_k_8_S_k_16_,	mS_k_8(0) mS_k_8(1) mS_k_16(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_16_S_K_8_S_K_8_S_K_16_S_K_16_
#define _MSGSTRUCT_S_K_8_S_K_16_S_K_8_S_K_8_S_K_16_S_K_16_
	/* MSG_ID_MMI_SMS_COPY_MSG_RSP */	MSGSTRUCT(S_k_8_S_k_16_S_k_8_S_k_8_S_k_16_S_k_16_,	mS_k_8(0) mS_k_16(1) mS_k_8(2) mS_k_8(3) mS_k_16(4) mS_k_16(5) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_16_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_16_S_K_8_
	/* MSG_ID_MMI_SMS_GET_MSG_LIST_REQ */	MSGSTRUCT(S_k_8_S_k_8_S_k_16_S_k_8_,	mS_k_8(0) mS_k_8(1) mS_k_16(2) mS_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_SMSAL_INBOX_LIST_S_S_SMSAL_OUTBOX_LIST_S_
#define _MSGSTRUCT_S_SMSAL_INBOX_LIST_S_S_SMSAL_OUTBOX_LIST_S_
	/* MSG_ID_MMI_SMS_GET_MSG_LIST_RSP */	MSGSTRUCT(S_smsal_inbox_list_s_S_smsal_outbox_list_s_,	mS_smsal_inbox_list_s(0) mS_smsal_outbox_list_s(1) )

#endif
#ifndef _MSGSTRUCT_S_K_16_S_K_BOOL_S_L_NUMBER_S_S_K_BOOL_
#define _MSGSTRUCT_S_K_16_S_K_BOOL_S_L_NUMBER_S_S_K_BOOL_
	/* MSG_ID_MMI_SMS_SEND_FROM_STORAGE_REQ */	MSGSTRUCT(S_k_16_S_k_bool_S_l_number_s_S_k_bool_,	mS_k_16(0) mS_k_bool(1) mS_l_number_s(2) mS_k_bool(3) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_S_K_8_S_K_16_S_SMSAL_CONCAT_S_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_S_K_8_S_K_16_S_SMSAL_CONCAT_S_
	/* MSG_ID_MMI_SMS_SEND_FROM_STORAGE_RSP */	MSGSTRUCT(S_k_bool_S_k_16_S_k_8_S_k_16_S_smsal_concat_s_,	mS_k_bool(0) mS_k_16(1) mS_k_8(2) mS_k_16(3) mS_smsal_concat_s(4) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_16_S_K_BOOL_
#define _MSGSTRUCT_S_K_8_S_K_16_S_K_BOOL_
	/* MSG_ID_MMI_SMS_SET_STATUS_REQ */	MSGSTRUCT(S_k_8_S_k_16_S_k_bool_,	mS_k_8(0) mS_k_16(1) mS_k_bool(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_S_K_16_
	/* MSG_ID_MMI_SMS_SET_STATUS_RSP */	MSGSTRUCT(S_k_bool_S_k_16_S_k_16_,	mS_k_bool(0) mS_k_16(1) mS_k_16(2) )

#endif
/* Data Related Messages */
#if defined(__MOD_DATA__)
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_DF_SET_RLP_PARAMS_REQ */	MSGSTRUCT(S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) mS_k_8(4) mS_k_8(5) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_DF_SET_RLP_PARAMS_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_DF_GET_RLP_PARAMS_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_DF_SET_V120_PARAMS_REQ */	MSGSTRUCT(S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) mS_k_8(4) mS_k_8(5) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_DF_SET_V120_PARAMS_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_DF_GET_V120_PARAMS_RSP */	MSGSTRUCT(S_k_bool_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_,	mS_k_bool(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) mS_k_8(4) mS_k_8(5) mS_k_8(6) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_16_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_16_S_K_8_
	/* MSG_ID_MMI_DF_SET_COMP_PARAMS_REQ */	MSGSTRUCT(S_k_8_S_k_8_S_k_16_S_k_8_,	mS_k_8(0) mS_k_8(1) mS_k_16(2) mS_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_DF_SET_COMP_PARAMS_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_S_K_16_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_S_K_16_S_K_8_
	/* MSG_ID_MMI_DF_GET_COMP_PARAMS_RSP */	MSGSTRUCT(S_k_bool_S_k_8_S_k_8_S_k_16_S_k_8_,	mS_k_bool(0) mS_k_8(1) mS_k_8(2) mS_k_16(3) mS_k_8(4) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_DF_SET_BEARER_MODE_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_DF_SET_BEARER_MODE_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_DF_GET_BEARER_MODE_RSP */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_DF_SET_CHAR_FRAMING_REQ */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_DF_SET_CHAR_FRAMING_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_
	/* MSG_ID_MMI_DF_GET_CHAR_FRAMING_RSP */	MSGSTRUCT(S_k_bool_S_k_8_S_k_8_,	mS_k_bool(0) mS_k_8(1) mS_k_8(2) )

#endif
#endif /* defined(__MOD_DATA__) */
/* GPRS Related Messages */
#if defined(__MOD_TCM__)
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_PS_ACT_REQ */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_PS_ACT_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_PS_ACT_TEST_REQ */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_PS_ACT_TEST_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_PS_ANSWER_REQ */	MSGSTRUCT(S_k_8_S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_PS_ANSWER_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_PS_SET_AUTO_ANSWER_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_PS_SET_AUTO_ANSWER_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_PS_GET_AUTO_ANSWER_RSP */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_PS_MODIFY_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_PS_MODIFY_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_PS_ENTER_DATA_STATE_REQ */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_PS_ENTER_DATA_STATE_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_L_PRIM_PDP_INFO_S_
#define _MSGSTRUCT_S_L_PRIM_PDP_INFO_S_
	/* MSG_ID_MMI_PS_SET_DEFINITION_REQ */	MSGSTRUCT(S_l_prim_pdp_info_s_,	mS_l_prim_pdp_info_s(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_PS_SET_DEFINITION_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_L_PRIM_PDP_INFO_LIST_S_
#define _MSGSTRUCT_S_K_BOOL_S_L_PRIM_PDP_INFO_LIST_S_
	/* MSG_ID_MMI_PS_GET_DEFINITION_RSP */	MSGSTRUCT(S_k_bool_S_l_prim_pdp_info_list_s_,	mS_k_bool(0) mS_l_prim_pdp_info_list_s(1) )

#endif
#ifndef _MSGSTRUCT_S_L_SEC_PDP_INFO_S_
#define _MSGSTRUCT_S_L_SEC_PDP_INFO_S_
	/* MSG_ID_MMI_PS_SET_SEC_DEFINITION_REQ */	MSGSTRUCT(S_l_sec_pdp_info_s_,	mS_l_sec_pdp_info_s(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_PS_SET_SEC_DEFINITION_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_L_SEC_PDP_INFO_LIST_S_
#define _MSGSTRUCT_S_K_BOOL_S_L_SEC_PDP_INFO_LIST_S_
	/* MSG_ID_MMI_PS_GET_SEC_DEFINITION_RSP */	MSGSTRUCT(S_k_bool_S_l_sec_pdp_info_list_s_,	mS_k_bool(0) mS_l_sec_pdp_info_list_s(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_PS_GET_PDP_ADDR_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_128A_K_8_
#define _MSGSTRUCT_S_K_BOOL_128A_K_8_
	/* MSG_ID_MMI_PS_GET_PDP_ADDR_RSP */	MSGSTRUCT(S_k_bool_128A_k_8_,	mS_k_bool(0) m128A_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_L_TFT_S_
#define _MSGSTRUCT_S_L_TFT_S_
	/* MSG_ID_MMI_PS_SET_TFT_REQ */	MSGSTRUCT(S_l_tft_s_,	mS_l_tft_s(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_PS_SET_TFT_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_L_TFT_S_
#define _MSGSTRUCT_S_K_BOOL_S_L_TFT_S_
	/* MSG_ID_MMI_PS_GET_TFT_RSP */	MSGSTRUCT(S_k_bool_S_l_tft_s_,	mS_k_bool(0) mS_l_tft_s(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_L_QOS_S_
#define _MSGSTRUCT_S_K_8_S_L_QOS_S_
	/* MSG_ID_MMI_PS_SET_QOS_REQ */	MSGSTRUCT(S_k_8_S_l_qos_s_,	mS_k_8(0) mS_l_qos_s(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_PS_SET_QOS_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_L_EQOS_S_
#define _MSGSTRUCT_S_K_8_S_L_EQOS_S_
	/* MSG_ID_MMI_PS_SET_EQOS_REQ */	MSGSTRUCT(S_k_8_S_l_eqos_s_,	mS_k_8(0) mS_l_eqos_s(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_PS_SET_EQOS_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_32_
#define _MSGSTRUCT_S_K_8_S_K_32_
	/* MSG_ID_MMI_PS_SEND_DATA_REQ */	MSGSTRUCT(S_k_8_S_k_32_,	mS_k_8(0) mS_k_32(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_PS_SEND_DATA_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_PS_GPRS_STATUS_UPDATE_IND */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_PS_GET_GPRS_EMPTY_PROFILE_RSP */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_L_GPRS_STATISTICS_INFO_S_
#define _MSGSTRUCT_S_K_BOOL_S_L_GPRS_STATISTICS_INFO_S_
	/* MSG_ID_MMI_PS_GET_GPRS_DATA_COUNTER_RSP */	MSGSTRUCT(S_k_bool_S_l_gprs_statistics_info_s_,	mS_k_bool(0) mS_l_gprs_statistics_info_s(1) )

#endif
#ifndef _MSGSTRUCT_S_L_GPRS_ACCOUNT_INFO_S_
#define _MSGSTRUCT_S_L_GPRS_ACCOUNT_INFO_S_
	/* MSG_ID_MMI_PS_SET_GPRS_DATA_ACCOUNT_REQ */	MSGSTRUCT(S_l_gprs_account_info_s_,	mS_l_gprs_account_info_s(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_PS_SET_GPRS_DATA_ACCOUNT_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_PS_GET_GPRS_DATA_ACCOUNT_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_L_GPRS_ACCOUNT_INFO_S_
#define _MSGSTRUCT_S_K_BOOL_S_L_GPRS_ACCOUNT_INFO_S_
	/* MSG_ID_MMI_PS_GET_GPRS_DATA_ACCOUNT_RSP */	MSGSTRUCT(S_k_bool_S_l_gprs_account_info_s_,	mS_k_bool(0) mS_l_gprs_account_info_s(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_PS_RESET_GPRS_DATA_COUNTER_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#endif /* defined(__MOD_TCM__) */
/* STK/SAT Related Messages */
#if defined(__SAT__)
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_SAT_ICON_S_S_K_16_S_K_8_P_S_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_SAT_ICON_S_S_K_16_S_K_8_P_S_K_8_
	/* MSG_ID_MMI_SAT_DISPLAY_TEXT_IND */	MSGSTRUCT(5A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_16_S_k_8_p_S_k_8_,	m5A_k_8(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) mS_k_8(4) mS_sat_icon_s(5) mS_k_16(6) mS_k_8_p(7) mS_k_8(8) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_DISPLAY_TEXT_RES_REQ */	MSGSTRUCT(5A_k_8_S_k_8_S_k_8_,	m5A_k_8(0) mS_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_SAT_DISPLAY_TEXT_RES_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_S_K_8_S_SAT_ICON_S_S_K_16_S_K_8_P_S_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_S_K_8_S_SAT_ICON_S_S_K_16_S_K_8_P_S_K_8_
	/* MSG_ID_MMI_SAT_GET_INKEY_IND */	MSGSTRUCT(5A_k_8_S_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_16_S_k_8_p_S_k_8_,	m5A_k_8(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) mS_sat_icon_s(4) mS_k_16(5) mS_k_8_p(6) mS_k_8(7) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_S_K_8_S_K_8_1A_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_S_K_8_S_K_8_1A_K_8_
	/* MSG_ID_MMI_SAT_GET_INKEY_RES_REQ */	MSGSTRUCT(5A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_1A_k_8_,	m5A_k_8(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) mS_k_8(4) m1A_k_8(5) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_SAT_GET_INKEY_RES_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_S_K_16_S_K_8_P_S_K_8_S_K_16_S_K_8_P_S_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_S_K_16_S_K_8_P_S_K_8_S_K_16_S_K_8_P_S_K_8_
	/* MSG_ID_MMI_SAT_GET_INPUT_IND */	MSGSTRUCT(5A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_S_k_16_S_k_8_p_S_k_8_S_k_16_S_k_8_p_S_k_8_,	m5A_k_8(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) mS_k_8(4) mS_sat_icon_s(5) mS_k_8(6) mS_k_8(7) mS_k_16(8) mS_k_8_p(9) mS_k_8(10) mS_k_16(11) mS_k_8_p(12) mS_k_8(13) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_S_K_8_1A_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_S_K_8_1A_K_8_
	/* MSG_ID_MMI_SAT_GET_INPUT_RES_REQ */	MSGSTRUCT(5A_k_8_S_k_8_S_k_8_S_k_8_1A_k_8_,	m5A_k_8(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) m1A_k_8(4) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_SAT_GET_INPUT_RES_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_16_S_K_8_P_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_P_
#define _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_16_S_K_8_P_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_P_
	/* MSG_ID_MMI_SAT_SETUP_MENU_IND */	MSGSTRUCT(5A_k_8_S_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_16_S_k_8_p_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p_,	m5A_k_8(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) mS_sat_icon_s(4) mS_k_8(5) mS_k_8(6) mS_k_8_p(7) mS_k_8(8) mS_k_16(9) mS_k_8_p(10) mS_k_8(11) mS_k_8_p(12) mS_k_8(13) mS_k_8(14) mS_k_8_p(15) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_SETUP_MENU_RES_REQ */	MSGSTRUCT(5A_k_8_S_k_8_,	m5A_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_SAT_SETUP_MENU_RES_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_16_S_K_8_P_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_P_
#define _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_16_S_K_8_P_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_P_
	/* MSG_ID_MMI_SAT_SELECT_ITEM_IND */	MSGSTRUCT(5A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_16_S_k_8_p_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_p_,	m5A_k_8(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) mS_k_8(4) mS_sat_icon_s(5) mS_k_8(6) mS_k_8(7) mS_k_8(8) mS_k_8(9) mS_k_8_p(10) mS_k_8(11) mS_k_16(12) mS_k_8_p(13) mS_k_8(14) mS_k_8(15) mS_k_8_p(16) mS_k_8(17) mS_k_8_p(18) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_SELECT_ITEM_RES_REQ */	MSGSTRUCT(5A_k_8_S_k_8_S_k_8_,	m5A_k_8(0) mS_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_SAT_SELECT_ITEM_RES_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_S_K_32_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_P_S_K_8_S_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_S_K_32_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_P_S_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_PLAY_TONE_IND */	MSGSTRUCT(5A_k_8_S_k_8_S_k_32_S_k_8_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8_,	m5A_k_8(0) mS_k_8(1) mS_k_32(2) mS_k_8(3) mS_sat_icon_s(4) mS_k_8(5) mS_k_8_p(6) mS_k_8(7) mS_k_8(8) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_PLAY_TONE_RES_REQ */	MSGSTRUCT(5A_k_8_S_k_8_,	m5A_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_SAT_PLAY_TONE_RES_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_MENU_SELECT_REQ */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_SAT_MENU_SELECT_RSP */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_SAT_EVDL_IDLE_SCREEN_AVAILABLE_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_2A_K_8_
#define _MSGSTRUCT_2A_K_8_
	/* MSG_ID_MMI_SAT_LANGUAGE_SELECTION_REQ */	MSGSTRUCT(2A_k_8_,	m2A_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_SAT_LANGUAGE_SELECTION_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_SAT_EVDL_BROWSER_TERMINATION_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_SAT_EVDL_BROWSER_TERMINATION_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_S_K_32_S_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_SAT_ICON_S_S_K_8_13A_K_8_S_K_8_21A_K_8_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_P_S_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_S_K_32_S_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_SAT_ICON_S_S_K_8_13A_K_8_S_K_8_21A_K_8_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_P_S_K_8_
	/* MSG_ID_MMI_SAT_CALL_SETUP_IND */	MSGSTRUCT(5A_k_8_S_k_8_S_k_32_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_sat_icon_s_S_k_8_13A_k_8_S_k_8_21A_k_8_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p_S_k_8_,	m5A_k_8(0) mS_k_8(1) mS_k_32(2) mS_k_8(3) mS_k_8(4) mS_sat_icon_s(5) mS_k_8(6) mS_sat_icon_s(7) mS_k_8(8) m13A_k_8(9) mS_k_8(10) m21A_k_8(11) mS_k_8(12) mS_k_8(13) mS_k_8_p(14) mS_k_8(15) mS_k_8(16) mS_k_8_p(17) mS_k_8(18) mS_k_8(19) mS_k_8_p(20) mS_k_8(21) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_41A_K_8_S_K_8_21A_K_8_S_K_8_15A_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_41A_K_8_S_K_8_21A_K_8_S_K_8_15A_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_CALL_SETUP_STAGE1_REQ */	MSGSTRUCT(S_k_8_S_k_8_41A_k_8_S_k_8_21A_k_8_S_k_8_15A_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) m41A_k_8(2) mS_k_8(3) m21A_k_8(4) mS_k_8(5) m15A_k_8(6) mS_k_8(7) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_CALL_SETUP_STAGE1_RSP */	MSGSTRUCT(S_l_result_s_S_k_8_S_k_8_,	mS_l_result_s(0) mS_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_CALL_SETUP_STAGE2_REQ */	MSGSTRUCT(5A_k_8_S_k_8_S_k_8_,	m5A_k_8(0) mS_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_SAT_CALL_SETUP_STAGE2_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_41A_K_8_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_P_
#define _MSGSTRUCT_5A_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_41A_K_8_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_P_
	/* MSG_ID_MMI_SAT_SEND_SMS_IND */	MSGSTRUCT(5A_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_41A_k_8_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p_,	m5A_k_8(0) mS_k_8(1) mS_sat_icon_s(2) mS_k_8(3) mS_k_8(4) m41A_k_8(5) mS_k_8(6) mS_k_8(7) mS_k_8_p(8) mS_k_8(9) mS_k_8(10) mS_k_8_p(11) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_41A_K_8_S_K_8_175A_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_41A_K_8_S_K_8_175A_K_8_
	/* MSG_ID_MMI_SAT_SEND_SMS_STAGE1_REQ */	MSGSTRUCT(S_k_8_S_k_8_41A_k_8_S_k_8_175A_k_8_,	mS_k_8(0) mS_k_8(1) m41A_k_8(2) mS_k_8(3) m175A_k_8(4) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_16_
#define _MSGSTRUCT_S_K_8_S_K_16_
	/* MSG_ID_MMI_SAT_SEND_SMS_STAGE1_RSP */	MSGSTRUCT(S_k_8_S_k_16_,	mS_k_8(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_SEND_SMS_STAGE2_REQ */	MSGSTRUCT(5A_k_8_S_k_8_S_k_8_,	m5A_k_8(0) mS_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_SAT_SEND_SMS_STAGE2_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_P_
#define _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_P_
	/* MSG_ID_MMI_SAT_SEND_SS_IND */	MSGSTRUCT(5A_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p_,	m5A_k_8(0) mS_k_8(1) mS_k_8(2) mS_sat_icon_s(3) mS_k_8(4) mS_k_8(5) mS_k_8_p(6) mS_k_8(7) mS_k_8(8) mS_k_8_p(9) )

#endif
#ifndef _MSGSTRUCT_183A_K_8_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_183A_K_8_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_SEND_SS_STAGE1_REQ */	MSGSTRUCT(183A_k_8_S_k_8_S_k_8_S_k_8_,	m183A_k_8(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_255A_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_255A_K_8_
	/* MSG_ID_MMI_SAT_SEND_SS_STAGE1_RSP */	MSGSTRUCT(S_k_8_S_k_8_255A_k_8_,	mS_k_8(0) mS_k_8(1) m255A_k_8(2) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_255A_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_255A_K_8_
	/* MSG_ID_MMI_SAT_SEND_SS_STAGE2_REQ */	MSGSTRUCT(5A_k_8_S_k_8_S_k_8_255A_k_8_,	m5A_k_8(0) mS_k_8(1) mS_k_8(2) m255A_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_SAT_SEND_SS_STAGE2_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_P_S_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_P_S_K_8_
	/* MSG_ID_MMI_SAT_SEND_USSD_IND */	MSGSTRUCT(5A_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p_S_k_8_,	m5A_k_8(0) mS_k_8(1) mS_k_8(2) mS_sat_icon_s(3) mS_k_8(4) mS_k_8(5) mS_k_8_p(6) mS_k_8(7) mS_k_8(8) mS_k_8_p(9) mS_k_8(10) )

#endif
#ifndef _MSGSTRUCT_183A_K_8_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_183A_K_8_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_SEND_USSD_STAGE1_REQ */	MSGSTRUCT(183A_k_8_S_k_8_S_k_8_S_k_8_,	m183A_k_8(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_255A_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_255A_K_8_
	/* MSG_ID_MMI_SAT_SEND_USSD_STAGE1_RSP */	MSGSTRUCT(S_k_8_S_k_8_255A_k_8_,	mS_k_8(0) mS_k_8(1) m255A_k_8(2) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_255A_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_255A_K_8_
	/* MSG_ID_MMI_SAT_SEND_USSD_STAGE2_REQ */	MSGSTRUCT(5A_k_8_S_k_8_S_k_8_255A_k_8_,	m5A_k_8(0) mS_k_8(1) mS_k_8(2) m255A_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_SAT_SEND_USSD_STAGE2_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_41A_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_41A_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_MMI_INFO_IND */	MSGSTRUCT(S_k_8_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_41A_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) mS_k_8(2) mS_k_8_p(3) mS_k_8(4) mS_k_8(5) m41A_k_8(6) mS_k_8(7) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_SETUP_IDLE_DISPLAY_RES_REQ */	MSGSTRUCT(5A_k_8_S_k_8_,	m5A_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_SAT_SETUP_IDLE_DISPLAY_RES_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_S_SAT_ICON_S_S_K_16_S_K_8_P_S_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_S_SAT_ICON_S_S_K_16_S_K_8_P_S_K_8_
	/* MSG_ID_MMI_SAT_SETUP_IDLE_DISPLAY_IND */	MSGSTRUCT(5A_k_8_S_k_8_S_sat_icon_s_S_k_16_S_k_8_p_S_k_8_,	m5A_k_8(0) mS_k_8(1) mS_sat_icon_s(2) mS_k_16(3) mS_k_8_p(4) mS_k_8(5) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_S_K_8_P_
#define _MSGSTRUCT_5A_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_S_K_8_P_
	/* MSG_ID_MMI_SAT_RUN_AT_COMMAND_IND */	MSGSTRUCT(5A_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_S_k_8_p_,	m5A_k_8(0) mS_k_8(1) mS_sat_icon_s(2) mS_k_8(3) mS_k_8_p(4) mS_k_8(5) mS_k_8(6) mS_k_8(7) mS_k_8_p(8) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_S_K_8_P_
#define _MSGSTRUCT_5A_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_S_K_8_P_
	/* MSG_ID_MMI_SAT_SEND_DTMF_IND */	MSGSTRUCT(5A_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_S_k_8_p_,	m5A_k_8(0) mS_k_8(1) mS_sat_icon_s(2) mS_k_8(3) mS_k_8_p(4) mS_k_8(5) mS_k_8(6) mS_k_8(7) mS_k_8_p(8) )

#endif
#ifndef _MSGSTRUCT_21A_K_8_S_K_8_
#define _MSGSTRUCT_21A_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_SEND_DTMF_STAGE1_REQ */	MSGSTRUCT(21A_k_8_S_k_8_,	m21A_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_SEND_DTMF_STAGE1_RSP */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_SEND_DTMF_STAGE2_REQ */	MSGSTRUCT(5A_k_8_S_k_8_S_k_8_,	m5A_k_8(0) mS_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_SAT_SEND_DTMF_STAGE2_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_SAT_ABORT_DTMF_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_LANG_NOTIFY_RES_REQ */	MSGSTRUCT(5A_k_8_S_k_8_,	m5A_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_SAT_LANG_NOTIFY_RES_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_2A_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_2A_K_8_
	/* MSG_ID_MMI_SAT_LANG_NOTIFY_IND */	MSGSTRUCT(5A_k_8_S_k_8_2A_k_8_,	m5A_k_8(0) mS_k_8(1) m2A_k_8(2) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_255A_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_255A_K_8_
	/* MSG_ID_MMI_SAT_LAUNCH_BROWSER_RES_REQ */	MSGSTRUCT(5A_k_8_S_k_8_S_k_8_255A_k_8_,	m5A_k_8(0) mS_k_8(1) mS_k_8(2) m255A_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_SAT_LAUNCH_BROWSER_RES_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_10A_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_P_S_K_16_S_K_8_P_S_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_10A_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_P_S_K_16_S_K_8_P_S_K_8_
	/* MSG_ID_MMI_SAT_LAUNCH_BROWSER_IND */	MSGSTRUCT(5A_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_10A_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_p_S_k_16_S_k_8_p_S_k_8_,	m5A_k_8(0) mS_k_8(1) mS_sat_icon_s(2) mS_k_8(3) mS_k_8(4) m10A_k_8(5) mS_k_8(6) mS_k_8_p(7) mS_k_8(8) mS_k_8(9) mS_k_8(10) mS_k_8_p(11) mS_k_8(12) mS_k_8_p(13) mS_k_16(14) mS_k_8_p(15) mS_k_8(16) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_8_120A_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_8_120A_K_8_
	/* MSG_ID_MMI_SAT_SIM_FILE_CHANGE_IND */	MSGSTRUCT(S_k_8_S_k_8_S_k_8_120A_k_8_,	mS_k_8(0) mS_k_8(1) mS_k_8(2) m120A_k_8(3) )

#endif
#endif /* defined(__SAT__) */
/* STK_CE */
#if defined(__SATCE__)
#ifndef _MSGSTRUCT_5A_K_8_S_K_BOOL_S_SAT_ICON_S_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_BOOL_S_SAT_ICON_S_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_OPEN_CHANNEL_IND */	MSGSTRUCT(5A_k_8_S_k_bool_S_sat_icon_s_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_,	m5A_k_8(0) mS_k_bool(1) mS_sat_icon_s(2) mS_k_8(3) mS_k_8(4) mS_k_8_p(5) mS_k_8(6) mS_k_8(7) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_OPEN_CHANNEL_REQ */	MSGSTRUCT(5A_k_8_S_k_8_S_k_8_,	m5A_k_8(0) mS_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_SAT_OPEN_CHANNEL_RSP */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_BOOL_S_SAT_ICON_S_S_K_8_S_K_8_P_S_K_8_S_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_BOOL_S_SAT_ICON_S_S_K_8_S_K_8_P_S_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_CLOSE_CHANNEL_IND */	MSGSTRUCT(5A_k_8_S_k_bool_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8_,	m5A_k_8(0) mS_k_bool(1) mS_sat_icon_s(2) mS_k_8(3) mS_k_8_p(4) mS_k_8(5) mS_k_8(6) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_CLOSE_CHANNEL_REQ */	MSGSTRUCT(5A_k_8_S_k_8_,	m5A_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_SAT_CLOSE_CHANNEL_RSP */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_BOOL_S_SAT_ICON_S_S_K_8_S_K_8_P_S_K_8_S_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_BOOL_S_SAT_ICON_S_S_K_8_S_K_8_P_S_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_SEND_DATA_IND */	MSGSTRUCT(5A_k_8_S_k_bool_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8_,	m5A_k_8(0) mS_k_bool(1) mS_sat_icon_s(2) mS_k_8(3) mS_k_8_p(4) mS_k_8(5) mS_k_8(6) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_SEND_DATA_REQ */	MSGSTRUCT(5A_k_8_S_k_8_,	m5A_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_SEND_DATA_RSP */	MSGSTRUCT(5A_k_8_S_k_8_S_k_8_,	m5A_k_8(0) mS_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_BOOL_S_SAT_ICON_S_S_K_8_S_K_8_P_S_K_8_S_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_BOOL_S_SAT_ICON_S_S_K_8_S_K_8_P_S_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_RECV_DATA_IND */	MSGSTRUCT(5A_k_8_S_k_bool_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8_,	m5A_k_8(0) mS_k_bool(1) mS_sat_icon_s(2) mS_k_8(3) mS_k_8_p(4) mS_k_8(5) mS_k_8(6) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_RECV_DATA_REQ */	MSGSTRUCT(5A_k_8_S_k_8_,	m5A_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_5A_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_RECV_DATA_RSP */	MSGSTRUCT(5A_k_8_S_k_8_S_k_8_,	m5A_k_8(0) mS_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_SAT_NOTIFY_MMI_IND */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#endif /* defined(__SATCE__) */
#ifndef _MSGSTRUCT_S_K_16_S_K_16_S_K_8_S_K_8_S_K_8_S_K_16_1A_K_8_
#define _MSGSTRUCT_S_K_16_S_K_16_S_K_8_S_K_8_S_K_8_S_K_16_1A_K_8_
	/* MSG_ID_MMI_CB_MSG_IND */	MSGSTRUCT(S_k_16_S_k_16_S_k_8_S_k_8_S_k_8_S_k_16_1A_k_8_,	mS_k_16(0) mS_k_16(1) mS_k_8(2) mS_k_8(3) mS_k_8(4) mS_k_16(5) m1A_k_8(6) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_CB_SUBSCRIBE_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_CB_SUBSCRIBE_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_L_CB_INFO_S_
#define _MSGSTRUCT_S_L_CB_INFO_S_
	/* MSG_ID_MMI_SMS_SET_CB_MODE_REQ */	MSGSTRUCT(S_l_cb_info_s_,	mS_l_cb_info_s(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_SMS_SET_CB_MODE_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_S_K_8_S_K_8_S_L_CB_INFO_S_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_S_K_8_S_K_8_S_L_CB_INFO_S_
	/* MSG_ID_MMI_SMS_GET_CB_MODE_RSP */	MSGSTRUCT(S_k_bool_S_k_8_S_k_8_S_k_8_S_k_8_S_l_cb_info_s_,	mS_k_bool(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) mS_k_8(4) mS_l_cb_info_s(5) )

#endif
/* Engineer Mode-UEM */
#if defined(__MOD_UEM__)
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_EM_SET_GAIN_REQ */	MSGSTRUCT(S_k_8_S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EM_SET_GAIN_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#endif /* defined(__MOD_UEM__) */
/* Engineer Mode */
#if defined(__EM_MODE__)
#ifndef _MSGSTRUCT_S_K_8_S_K_32_S_PEER_BUFF_S_P_
#define _MSGSTRUCT_S_K_8_S_K_32_S_PEER_BUFF_S_P_
	/* MSG_ID_MMI_EM_STATUS_IND */	MSGSTRUCT(S_k_8_S_k_32_S_peer_buff_s_p_,	mS_k_8(0) mS_k_32(1) mS_peer_buff_s_p(2) )

#endif
#ifndef _MSGSTRUCT_S_MODULE_TYPE_S_REQUEST_INFO_TYPE_
#define _MSGSTRUCT_S_MODULE_TYPE_S_REQUEST_INFO_TYPE_
	/* MSG_ID_MMI_EM_START_REQ */	MSGSTRUCT(S_module_type_S_request_info_type_,	mS_module_type(0) mS_request_info_type(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_S_K_32_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_S_K_32_
	/* MSG_ID_MMI_EM_START_RSP */	MSGSTRUCT(S_k_bool_S_k_8_S_k_8_S_k_32_,	mS_k_bool(0) mS_k_8(1) mS_k_8(2) mS_k_32(3) )

#endif
#ifndef _MSGSTRUCT_S_MODULE_TYPE_S_REQUEST_INFO_TYPE_
#define _MSGSTRUCT_S_MODULE_TYPE_S_REQUEST_INFO_TYPE_
	/* MSG_ID_MMI_EM_STOP_REQ */	MSGSTRUCT(S_module_type_S_request_info_type_,	mS_module_type(0) mS_request_info_type(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_S_K_32_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_8_S_K_32_
	/* MSG_ID_MMI_EM_STOP_RSP */	MSGSTRUCT(S_k_bool_S_k_8_S_k_8_S_k_32_,	mS_k_bool(0) mS_k_8(1) mS_k_8(2) mS_k_32(3) )

#endif
#ifndef _MSGSTRUCT_S_K_8_16A_RR_EM_LAI_INFO_S_
#define _MSGSTRUCT_S_K_8_16A_RR_EM_LAI_INFO_S_
	/* MSG_ID_MMI_EM_SET_CELL_ID_LOCK_REQ */	MSGSTRUCT(S_k_8_16A_rr_em_lai_info_s_,	mS_k_8(0) m16A_rr_em_lai_info_s(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EM_SET_CELL_ID_LOCK_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#endif /* defined(__EM_MODE__) */
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_EM_KEYPAD_EVENT_OUTPUT_REQ */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EM_KEYPAD_EVENT_OUTPUT_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_EM_LCM_TEST_IND */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EM_KEYPAD_EVENT_ACT_IND */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_FACTORY_TEST_IND */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_10A_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_10A_K_8_
	/* MSG_ID_MMI_SET_MMI_DEFAULT_PROF_IND */	MSGSTRUCT(S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_10A_k_8_,	mS_k_8(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) mS_k_8(4) m10A_k_8(5) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_UPDATE_MMI_DEFAULT_PROF_VALUE_REQ */	MSGSTRUCT(S_k_8_S_k_8_S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_UPDATE_MMI_DEFAULT_PROF_VALUE_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_EM_CELL_RESEL_SUSPEND_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_EM_CELL_RESEL_SUSPEND_RSP */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_EM_CELL_RESEL_RESUME_RSP */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_BOOL_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_BOOL_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EM_GET_CELL_LOCK_RSP */	MSGSTRUCT(S_k_bool_S_k_bool_S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_bool(1) mS_k_bool(2) mS_k_16(3) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EM_SET_CELL_LOCK_REQ */	MSGSTRUCT(S_k_bool_S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_bool(1) mS_k_16(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EM_SET_CELL_LOCK_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_16_S_K_16_S_K_16_
#define _MSGSTRUCT_S_K_8_S_K_16_S_K_16_S_K_16_
	/* MSG_ID_MMI_EM_RGB_TEST_REQ_IND */	MSGSTRUCT(S_k_8_S_k_16_S_k_16_S_k_16_,	mS_k_8(0) mS_k_16(1) mS_k_16(2) mS_k_16(3) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_20A_MODULE_TYPE_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_20A_MODULE_TYPE_
	/* MSG_ID_MMI_EM_NW_EVENT_NOTIFY_REQ */	MSGSTRUCT(S_k_bool_S_k_8_20A_module_type_,	mS_k_bool(0) mS_k_8(1) m20A_module_type(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EM_NW_EVENT_NOTIFY_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_32_
#define _MSGSTRUCT_S_K_8_S_K_32_
	/* MSG_ID_MMI_EM_NW_EVENT_NOTIFY_IND */	MSGSTRUCT(S_k_8_S_k_32_,	mS_k_8(0) mS_k_32(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_EM_FEATURE_COMMAND_REQ */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_EM_FEATURE_COMMAND_RSP */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
/* Audio Task - Voice Memo(via FS) */
#if defined(__FS_ON__)
#ifndef _MSGSTRUCT_20A_K_WCHAR_
#define _MSGSTRUCT_20A_K_WCHAR_
	/* MSG_ID_MMI_VM_PLAY_REQ */	MSGSTRUCT(20A_k_wchar_,	m20A_k_wchar(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_VM_PLAY_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_20A_K_WCHAR_S_K_BOOL_
#define _MSGSTRUCT_20A_K_WCHAR_S_K_BOOL_
	/* MSG_ID_MMI_VM_DEL_REQ */	MSGSTRUCT(20A_k_wchar_S_k_bool_,	m20A_k_wchar(0) mS_k_bool(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_VM_DEL_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_20A_K_WCHAR_
#define _MSGSTRUCT_20A_K_WCHAR_
	/* MSG_ID_MMI_VM_APPEND_REQ */	MSGSTRUCT(20A_k_wchar_,	m20A_k_wchar(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_VM_APPEND_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_20A_K_WCHAR_20A_K_WCHAR_
#define _MSGSTRUCT_20A_K_WCHAR_20A_K_WCHAR_
	/* MSG_ID_MMI_VM_RENAME_REQ */	MSGSTRUCT(20A_k_wchar_20A_k_wchar_,	m20A_k_wchar(0) m20A_k_wchar(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_VM_RENAME_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_VM_PLAY_FINISH_IND */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_16_V6A_K_WCHAR_S_K_BOOL_S_K_32_
#define _MSGSTRUCT_S_K_16_V6A_K_WCHAR_S_K_BOOL_S_K_32_
	/* MSG_ID_MMI_VM_GET_INFO_RSP */	MSGSTRUCT(S_k_16_v6A_k_wchar_S_k_bool_S_k_32_,	mS_k_16(0) mv6A_k_wchar(1) mS_k_bool(2) mS_k_32(3) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_20A_K_WCHAR_
#define _MSGSTRUCT_S_L_RESULT_S_20A_K_WCHAR_
	/* MSG_ID_MMI_VM_STOP_RSP */	MSGSTRUCT(S_l_result_s_20A_k_wchar_,	mS_l_result_s(0) m20A_k_wchar(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_VM_ABORT_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_20A_K_WCHAR_
#define _MSGSTRUCT_S_L_RESULT_S_20A_K_WCHAR_
	/* MSG_ID_MMI_VM_PAUSE_RSP */	MSGSTRUCT(S_l_result_s_20A_k_wchar_,	mS_l_result_s(0) m20A_k_wchar(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_VM_RESUME_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_VM_RECORD_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_16_
#define _MSGSTRUCT_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_VM_RECORD_RSP */	MSGSTRUCT(S_k_bool_S_k_16_,	mS_k_bool(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_20A_K_WCHAR_
#define _MSGSTRUCT_S_K_8_20A_K_WCHAR_
	/* MSG_ID_MMI_VM_RECORD_FINISH_IND */	MSGSTRUCT(S_k_8_20A_k_wchar_,	mS_k_8(0) m20A_k_wchar(1) )

#endif
#endif /* defined(__FS_ON__) */
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_CPHS_DISPLAY_CFU_IND */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_17A_K_8_S_K_8_21A_K_8_S_K_8_11A_K_8_S_K_8_2A_L4CSMU_ADDR_S_S_K_8_20A_L4CSMU_INFO_NUM_S_S_K_8_22A_K_8_S_K_8_5A_K_8_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_17A_K_8_S_K_8_21A_K_8_S_K_8_11A_K_8_S_K_8_2A_L4CSMU_ADDR_S_S_K_8_20A_L4CSMU_INFO_NUM_S_S_K_8_22A_K_8_S_K_8_5A_K_8_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_CPHS_MMI_INFO_IND */	MSGSTRUCT(S_k_8_S_k_8_17A_k_8_S_k_8_21A_k_8_S_k_8_11A_k_8_S_k_8_2A_l4csmu_addr_s_S_k_8_20A_l4csmu_info_num_s_S_k_8_22A_k_8_S_k_8_5A_k_8_S_k_8_S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) m17A_k_8(2) mS_k_8(3) m21A_k_8(4) mS_k_8(5) m11A_k_8(6) mS_k_8(7) m2A_l4csmu_addr_s(8) mS_k_8(9) m20A_l4csmu_info_num_s(10) mS_k_8(11) m22A_k_8(12) mS_k_8(13) m5A_k_8(14) mS_k_8(15) mS_k_8(16) mS_k_8(17) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_CPHS_UPDATE_ALS_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_16_
#define _MSGSTRUCT_S_K_8_S_K_16_
	/* MSG_ID_MMI_CPHS_UPDATE_ALS_RSP */	MSGSTRUCT(S_k_8_S_k_16_,	mS_k_8(0) mS_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_CPHS_DISPLAY_ALS_IND */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_WAP_START_DTMF_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_K_8_S_K_16_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_K_8_S_K_16_
	/* MSG_ID_WAP_START_DTMF_RSP */	MSGSTRUCT(S_k_8_S_k_8_S_k_8_S_k_8_S_k_16_,	mS_k_8(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) mS_k_16(4) )

#endif
#ifndef _MSGSTRUCT_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_BOOL_
#define _MSGSTRUCT_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_BOOL_
	/* MSG_ID_WAP_DIAL_REQ */	MSGSTRUCT(S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_bool_,	mS_l_number_s(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) mS_k_bool(4) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_8_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_8_
	/* MSG_ID_WAP_DIAL_RSP */	MSGSTRUCT(S_l_result_s_S_k_8_,	mS_l_result_s(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_16_S_L_PHB_ENTRY_S_
#define _MSGSTRUCT_S_K_8_S_K_16_S_L_PHB_ENTRY_S_
	/* MSG_ID_WAP_SET_ENTRY_REQ */	MSGSTRUCT(S_k_8_S_k_16_S_l_phb_entry_s_,	mS_k_8(0) mS_k_16(1) mS_l_phb_entry_s(2) )

#endif
#ifndef _MSGSTRUCT_S_L_RESULT_S_S_K_16_15A_L_PHB_ENTRY_S_
#define _MSGSTRUCT_S_L_RESULT_S_S_K_16_15A_L_PHB_ENTRY_S_
	/* MSG_ID_WAP_SET_ENTRY_RSP */	MSGSTRUCT(S_l_result_s_S_k_16_15A_l_phb_entry_s_,	mS_l_result_s(0) mS_k_16(1) m15A_l_phb_entry_s(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_WAP_AUTO_DTMF_COMPLETE_IND */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
/* IrDA */
#if defined(__IRDA_SUPPORT__)
#ifndef _MSGSTRUCT_S_K_16_
#define _MSGSTRUCT_S_K_16_
	/* MSG_ID_MMI_EQ_IRDA_OPEN_REQ */	MSGSTRUCT(S_k_16_,	mS_k_16(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_IRDA_OPEN_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_IRDA_CLOSE_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#endif /* defined(__IRDA_SUPPORT__) */
/* USB */
#if defined(__USB_ENABLE__)
#ifndef _MSGSTRUCT_S_K_8_S_K_32_
#define _MSGSTRUCT_S_K_8_S_K_32_
	/* MSG_ID_MMI_EQ_USBCONFIG_REQ */	MSGSTRUCT(S_k_8_S_k_32_,	mS_k_8(0) mS_k_32(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_32_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_S_K_32_
	/* MSG_ID_MMI_EQ_USBCONFIG_RSP */	MSGSTRUCT(S_k_bool_S_k_8_S_k_32_,	mS_k_bool(0) mS_k_8(1) mS_k_32(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_EQ_USBDETECT_IND */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_UART_PORT_
#define _MSGSTRUCT_S_K_8_S_UART_PORT_
	/* MSG_ID_MMI_EQ_USBUART_SWITCH_PORT_REQ */	MSGSTRUCT(S_k_8_S_UART_PORT_,	mS_k_8(0) mS_UART_PORT(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_USBUART_SWITCH_PORT_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_EQ_USBDETECT_RES_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#endif /* defined(__USB_ENABLE__) */
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_EQ_DATA_DL_FILELIST_INFO_REQ_IND */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_VOID_P_S_K_8_
#define _MSGSTRUCT_S_K_8_S_VOID_P_S_K_8_
	/* MSG_ID_MMI_EQ_DATA_DL_FILELIST_REPORT_REQ */	MSGSTRUCT(S_k_8_S_void_p_S_k_8_,	mS_k_8(0) mS_void_p(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_DATA_DL_FILELIST_REPORT_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_520A_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_520A_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_DATA_DL_FILE_MODIFY_REQ_IND */	MSGSTRUCT(S_k_8_520A_k_8_S_k_8_,	mS_k_8(0) m520A_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_DATA_DL_FILE_MODIFY_REQ */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_DATA_DL_FILE_MODIFY_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_520A_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_520A_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_DATA_DL_EXECUTE_REQ_IND */	MSGSTRUCT(S_k_8_520A_k_8_S_k_8_,	mS_k_8(0) m520A_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_DATA_DL_EXECUTE_REQ */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_DATA_DL_EXECUTE_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_WAP_MMC_READ_FOLDER_STATUS_REQ_IND */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_32_S_K_32_100A_K_8_100A_K_8_
#define _MSGSTRUCT_S_K_8_S_K_32_S_K_32_100A_K_8_100A_K_8_
	/* MSG_ID_WAP_MMC_READ_FOLDER_STATUS_OUTPUT_REQ */	MSGSTRUCT(S_k_8_S_k_32_S_k_32_100A_k_8_100A_k_8_,	mS_k_8(0) mS_k_32(1) mS_k_32(2) m100A_k_8(3) m100A_k_8(4) )

#endif
#ifndef _MSGSTRUCT_100A_K_8_
#define _MSGSTRUCT_100A_K_8_
	/* MSG_ID_WAP_MMC_UPLOAD_MSG_REQ_IND */	MSGSTRUCT(100A_k_8_,	m100A_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_32_
#define _MSGSTRUCT_S_K_8_S_K_32_
	/* MSG_ID_WAP_MMC_UPLOAD_MSG_OUTPUT_REQ */	MSGSTRUCT(S_k_8_S_k_32_,	mS_k_8(0) mS_k_32(1) )

#endif
#ifndef _MSGSTRUCT_S_K_32_S_K_8_
#define _MSGSTRUCT_S_K_32_S_K_8_
	/* MSG_ID_WAP_MMC_DELETE_MSG_REQ_IND */	MSGSTRUCT(S_k_32_S_k_8_,	mS_k_32(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_WAP_MMC_DELETE_MSG_OUTPUT_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_62A_K_8_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_62A_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_QUERY_GREETING_TEXT_RES_REQ */	MSGSTRUCT(S_k_bool_S_k_8_62A_k_8_S_k_8_,	mS_k_bool(0) mS_k_8(1) m62A_k_8(2) mS_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_EQ_QUERY_LANGUAGE_RES_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_QUERY_SILENT_MODE_RES_REQ */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_QUERY_VIBRATOR_MODE_RES_REQ */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_QUERY_DATE_TIME_FORMAT_REQ_IND */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_EQ_QUERY_DATE_TIME_FORMAT_RES_REQ */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_QUERY_MUTE_MODE_RES_REQ */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_POWER_RESET_IND */	MSGSTRUCT(S_k_8_S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_AT_GENERAL_RES_REQ */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_16A_K_8_
#define _MSGSTRUCT_16A_K_8_
	/* MSG_ID_MMI_FACTORY_RESTORE_REQ_IND */	MSGSTRUCT(16A_k_8_,	m16A_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_16_50A_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_16_50A_K_8_
	/* MSG_ID_MMI_EQ_VCARD_REQ_IND */	MSGSTRUCT(S_k_8_S_k_8_S_k_16_50A_k_8_,	mS_k_8(0) mS_k_8(1) mS_k_16(2) m50A_k_8(3) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_BOOL_50A_K_8_
#define _MSGSTRUCT_S_K_8_S_K_BOOL_50A_K_8_
	/* MSG_ID_MMI_EQ_VCARD_RES_REQ */	MSGSTRUCT(S_k_8_S_k_bool_50A_k_8_,	mS_k_8(0) mS_k_bool(1) m50A_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_16_50A_K_8_
#define _MSGSTRUCT_S_K_8_S_K_16_50A_K_8_
	/* MSG_ID_MMI_EQ_VCALENDAR_REQ_IND */	MSGSTRUCT(S_k_8_S_k_16_50A_k_8_,	mS_k_8(0) mS_k_16(1) m50A_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_BOOL_S_K_8_S_K_8_50A_K_8_
#define _MSGSTRUCT_S_K_8_S_K_BOOL_S_K_8_S_K_8_50A_K_8_
	/* MSG_ID_MMI_EQ_VCALENDAR_RES_REQ */	MSGSTRUCT(S_k_8_S_k_bool_S_k_8_S_k_8_50A_k_8_,	mS_k_8(0) mS_k_bool(1) mS_k_8(2) mS_k_8(3) m50A_k_8(4) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_EQ_STR_ENABLE_REQ_IND */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_16_250A_K_8_
#define _MSGSTRUCT_S_K_16_250A_K_8_
	/* MSG_ID_MMI_EQ_STR_REQ_IND */	MSGSTRUCT(S_k_16_250A_k_8_,	mS_k_16(0) m250A_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_16_250A_K_8_
#define _MSGSTRUCT_S_K_16_250A_K_8_
	/* MSG_ID_MMI_EQ_STR_RES_REQ */	MSGSTRUCT(S_k_16_250A_k_8_,	mS_k_16(0) m250A_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_BOOL_S_K_8_50A_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_BOOL_S_K_8_50A_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_UCM_AT_REQ_IND */	MSGSTRUCT(S_k_8_S_k_8_S_k_bool_S_k_8_50A_k_8_S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) mS_k_bool(2) mS_k_8(3) m50A_k_8(4) mS_k_8(5) mS_k_8(6) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_UCM_AT_RES_REQ */	MSGSTRUCT(S_k_8_S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_K_8_S_L_NUMBER_S_
#define _MSGSTRUCT_S_K_8_S_K_8_S_K_8_S_K_8_S_L_NUMBER_S_
	/* MSG_ID_MMI_UCM_GENERAL_RCODE_REQ */	MSGSTRUCT(S_k_8_S_k_8_S_k_8_S_k_8_S_l_number_s_,	mS_k_8(0) mS_k_8(1) mS_k_8(2) mS_k_8(3) mS_l_number_s(4) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_K_8_
#define _MSGSTRUCT_S_K_8_S_K_8_
	/* MSG_ID_MMI_UCM_HF_CIEV_RCODE_REQ */	MSGSTRUCT(S_k_8_S_k_8_,	mS_k_8(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_WCHAR_P_S_K_WCHAR_P_
#define _MSGSTRUCT_S_K_BOOL_S_K_WCHAR_P_S_K_WCHAR_P_
	/* MSG_ID_MMI_JAVA_LOCAL_INSTALL_REQ_IND */	MSGSTRUCT(S_k_bool_S_k_wchar_p_S_k_wchar_p_,	mS_k_bool(0) mS_k_wchar_p(1) mS_k_wchar_p(2) )

#endif
#ifndef _MSGSTRUCT_S_K_32_
#define _MSGSTRUCT_S_K_32_
	/* MSG_ID_MMI_JAVA_LOCAL_INSTALL_RES_REQ */	MSGSTRUCT(S_k_32_,	mS_k_32(0) )

#endif
/* Bluetooth */
#if defined(__BT_SUPPORT__)
#ifndef _MSGSTRUCT_32A_K_8_6A_K_8_S_K_8_
#define _MSGSTRUCT_32A_K_8_6A_K_8_S_K_8_
	/* MSG_ID_MMI_L4_BT_FCTY_SET_PARAM_IND */	MSGSTRUCT(32A_k_8_6A_k_8_S_k_8_,	m32A_k_8(0) m6A_k_8(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_6A_K_8_17A_K_8_
#define _MSGSTRUCT_6A_K_8_17A_K_8_
	/* MSG_ID_MMI_L4_BT_LOOPBACK_TEST_REQ_IND */	MSGSTRUCT(6A_k_8_17A_k_8_,	m6A_k_8(0) m17A_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_L4_BT_SET_VR_REQ_IND */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_L4_BT_SET_VR_REQ */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_L4_BT_SET_VR_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#endif /* defined(__BT_SUPPORT__) */
/* HOMEZONE */
#if defined(__HOMEZONE_SUPPORT__)
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_BOOL_12A_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_BOOL_12A_K_8_
	/* MSG_ID_MMI_HZ_TAG_IND */	MSGSTRUCT(S_k_bool_S_k_bool_12A_k_8_,	mS_k_bool(0) mS_k_bool(1) m12A_k_8(2) )

#endif
#endif /* defined(__HOMEZONE_SUPPORT__) */
/* CTM */
#if defined(__CTM_SUPPORT__)
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_CTM_OPEN_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_CTM_OPEN_RSP */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_CTM_CLOSE_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_CTM_CONNECT_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_16_V7A_K_16_
#define _MSGSTRUCT_S_K_16_V7A_K_16_
	/* MSG_ID_MMI_CTM_SEND_TEXT_REQ */	MSGSTRUCT(S_k_16_v7A_k_16_,	mS_k_16(0) mv7A_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_CTM_SEND_TEXT_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_16_V7A_K_16_
#define _MSGSTRUCT_S_K_16_V7A_K_16_
	/* MSG_ID_MMI_CTM_RECV_TEXT_IND */	MSGSTRUCT(S_k_16_v7A_k_16_,	mS_k_16(0) mv7A_k_16(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_CTM_TTY_PLUG_IND */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_CTM_SET_DEFAULT_REQ */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_CTM_SET_DEFAULT_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_CTM_DEFAULT_CHANGED_IND */	MSGSTRUCT(S_k_bool_S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_bool(1) mS_k_8(2) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_CTM_GET_DEFAULT_RSP */	MSGSTRUCT(S_k_bool_S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_bool(1) mS_k_8(2) )

#endif
#endif /* defined(__CTM_SUPPORT__) */
/* VOIP */
#if defined(__VOIP__)
#ifndef _MSGSTRUCT_S_K_8_S_K_8_S_VOID_P_S_VOID_P_S_VOID_P_
#define _MSGSTRUCT_S_K_8_S_K_8_S_VOID_P_S_VOID_P_S_VOID_P_
	/* MSG_ID_MMI_VOIP_AT_CALL_CTRL_APPROVE_RES_REQ */	MSGSTRUCT(S_k_8_S_k_8_S_void_p_S_void_p_S_void_p_,	mS_k_8(0) mS_k_8(1) mS_void_p(2) mS_void_p(3) mS_void_p(4) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_
#define _MSGSTRUCT_S_K_BOOL_
	/* MSG_ID_MMI_VOIP_AT_CALL_CTRL_APPROVE_RES_RSP */	MSGSTRUCT(S_k_bool_,	mS_k_bool(0) )

#endif
#ifndef _MSGSTRUCT_S_K_8_S_VOID_P_S_VOID_P_S_VOID_P_
#define _MSGSTRUCT_S_K_8_S_VOID_P_S_VOID_P_S_VOID_P_
	/* MSG_ID_MMI_VOIP_AT_CALL_CTRL_APPROVE_IND */	MSGSTRUCT(S_k_8_S_void_p_S_void_p_S_void_p_,	mS_k_8(0) mS_void_p(1) mS_void_p(2) mS_void_p(3) )

#endif
#endif /* defined(__VOIP__) */
/* GEMINI */
#if defined(__GEMINI__)
#ifndef _MSGSTRUCT_S_K_8_
#define _MSGSTRUCT_S_K_8_
	/* MSG_ID_MMI_SMU_SIM_STATUS_UPDATE_REQ */	MSGSTRUCT(S_k_8_,	mS_k_8(0) )

#endif
#ifndef _MSGSTRUCT_S_K_BOOL_S_K_8_
#define _MSGSTRUCT_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_SMU_SIM_STATUS_UPDATE_IND */	MSGSTRUCT(S_k_bool_S_k_8_,	mS_k_bool(0) mS_k_8(1) )

#endif
#endif /* defined(__GEMINI__) */

/*MTK:END*/


/******************************************************************************************
 * send functions
 ******************************************************************************************/
/*
* FUNCTION
*	SEND_FUNC
* DESCRIPTION
*   1. each SEND_FUNC macro will generate one send function for one mesage id.
*   2. it received message id and several parameters.
*   3. allocate a message structure from control buffer space.
*   4. assign all the parameter values into this message structure.
*   5. call l4a_send_ilm to send this message structure to destination module
*
* CALLS
*	l4a_send_msg()
* PARAMETERS
*   src: source module
*   dest: destination module
*   msg: message id
*   args: depends on message id
* RETURNS
*	none
* GLOBALS AFFECTED
*   none
*/

/*
#define SEND_FUNC(FUNCNAME,POSTFIX, MEMBERASSIGN) \
	void _send_##FUNCNAME##(module_type src,module_type dest,msg_type msg,va_list args)\
	{\
		msg_##POSTFIX##_struct *p= construct_local_para(sizeof(msg_##POSTFIX##_struct),0);\
		MEMBERASSIGN\
		l4a_sendmsg_ilm(src,dest,msg,p);\
	}
*/

/*Assign singleton */
/*
* FUNCTION
*	assignS
* DESCRIPTION
*   this macro will copy one value into one message structure field.
*
* CALLS
*	SEND_FUNC macro
* PARAMETERS
* 	x: the message structure field index.
* 	type: the message structure field type.
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*/
#define assignS(x,type)		{p->a##x=va_arg(args,type);}

#define assign_kal_bool(x)		p->a##x=(kal_bool)va_arg(args, kal_uint32);

#define assign_kal_uint8(x)		p->a##x=(kal_uint8)va_arg(args, kal_uint32);

#define assign_kal_uint16(x)	p->a##x=(kal_uint16)va_arg(args, kal_uint32);
/*
* FUNCTION
*	assignSP
* DESCRIPTION
*   this macro will copy one pointer value into one message structure field.
*
* CALLS
*	SEND_FUNC macro
* PARAMETERS
* 	x: the message structure field index.
* 	type: the message structure field type.
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*/
#define assignSP(x,type)	\
	{\
		void *src=(void*)va_arg(args,type*);\
		if(src) \
			p->a##x=*(type*)src;\
		else \
			memset(&p->a##x,0,sizeof(type));\
	}

/*Assign array */
/*
* FUNCTION
*	assignA
* DESCRIPTION
*   this macro will copy an array into one message structure field.
*
* CALLS
*	SEND_FUNC macro
* PARAMETERS
* 	x: the message structure field index.
* 	type: the message structure field type.
* 	len: the length of the array.
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*/
#define assignA(x,type,len)	\
	{\
		void* src=(void*)va_arg(args,type*);\
		if(src==NULL)\
			memset(p->a##x,0,len*sizeof(type));\
		else\
			memcpy(p->a##x,src,len*sizeof(type));\
	}

/*MTK:BEGIN:generate_send_function*/
/* Call Control Related Messages */
#if defined(__MOD_CSM__)
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_CC_RESET_ACM_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_32_
#define _SEND_FUNC_S_K_BOOL_S_K_32_
	/* MSG_ID_MMI_CC_GET_ACM_RSP */
void _send_S_k_bool_S_k_32_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_32__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_32__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assignS(1,kal_uint32) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_CC_SET_MAX_ACM_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_32_
#define _SEND_FUNC_S_K_BOOL_S_K_32_
	/* MSG_ID_MMI_CC_GET_MAX_ACM_RSP */
void _send_S_k_bool_S_k_32_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_32__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_32__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assignS(1,kal_uint32) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_32_
#define _SEND_FUNC_S_K_BOOL_S_K_32_
	/* MSG_ID_MMI_CC_GET_CCM_RSP */
void _send_S_k_bool_S_k_32_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_32__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_32__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assignS(1,kal_uint32) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_CC_SET_CUG_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_CC_GET_CUG_RSP */
void _send_S_k_bool_S_k_8_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_16_S_K_8_
	/* MSG_ID_MMI_CC_CHLD_RSP */
void _send_S_k_bool_S_k_16_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) assign_kal_uint8(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
void _send_none(module_type src,module_type dest,kal_uint32 msg,...)
{
	va_list args;
	msg_none_struct *p = construct_local_para(sizeof(msg_none_struct),0);

	va_start(args, msg);
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}
#ifndef _SEND_FUNC_S_K_BOOL_S_L_CALL_LIST_S_
#define _SEND_FUNC_S_K_BOOL_S_L_CALL_LIST_S_
	/* MSG_ID_MMI_CC_GET_CALL_LIST_RSP */
void _send_S_k_bool_S_l_call_list_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_l_call_list_s__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_l_call_list_s__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assignS(1,l4c_call_list_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_CC_CALL_DEFLECT_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_CC_START_DTMF_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_CC_STOP_DTMF_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_CC_START_AUTO_DTMF_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_A80A_K_8_
#define _SEND_FUNC_S_K_8_A80A_K_8_
	/* MSG_ID_MMI_CC_START_AUTO_DTMF_IND */
void _send_S_k_8_A80A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_80A_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_80A_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assignA(1,kal_uint8,80) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_
#define _SEND_FUNC_S_K_8_
	/* MSG_ID_MMI_CC_START_AUTO_DTMF_FINISH_IND */
void _send_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_8_
#define _SEND_FUNC_S_L_RESULT_S_S_K_8_
	/* MSG_ID_MMI_CC_ATA_RSP */
void _send_S_l_result_s_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_8__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_8__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_CC_DISCONNECT_AUX_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_CC_SET_LINE_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_CC_DIAL_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_NUMBER_S_S_K_8_S_K_8_S_K_BOOL_
#define _SEND_FUNC_S_L_NUMBER_S_S_K_8_S_K_8_S_K_BOOL_
	/* MSG_ID_MMI_CC_DIAL_REQ_IND */
void _send_S_l_number_s_S_k_8_S_k_8_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_number_s_S_k_8_S_k_8_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_l_number_s_S_k_8_S_k_8_S_k_bool__struct),0);

	va_start(args, msg);
	assignS(0,l4c_number_struct) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_bool(3) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_8_
#define _SEND_FUNC_S_L_RESULT_S_S_K_8_
	/* MSG_ID_MMI_CC_DIAL_IND */
void _send_S_l_result_s_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_8__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_8__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_8_
#define _SEND_FUNC_S_L_RESULT_S_S_K_8_
	/* MSG_ID_MMI_CC_CALL_MODIFY_RSP */
void _send_S_l_result_s_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_8__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_8__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_CC_SET_SINGLE_NUM_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_CC_GET_SINGLE_NUM_RSP */
void _send_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_32_S_K_8_
#define _SEND_FUNC_S_K_8_S_K_32_S_K_8_
	/* MSG_ID_MMI_CC_CCM_IND */
void _send_S_k_8_S_k_32_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_32_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_32_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assignS(1,kal_uint32) assign_kal_uint8(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_
#define _SEND_FUNC_S_K_8_
	/* MSG_ID_MMI_CC_INTERNAL_ALERT_IND */
void _send_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_PS_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_8_A30A_K_8_S_K_8_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_8_PS_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_8_A30A_K_8_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_CC_CALL_WAIT_IND */
void _send_S_k_8_PS_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_A30A_k_8_S_k_8_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_30A_k_8_S_k_8_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_30A_k_8_S_k_8_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assignSP(1,l4c_number_struct) assign_kal_uint8(2) assign_kal_uint8(3) assign_kal_uint8(4) assign_kal_uint8(5) assignA(6,kal_uint8,30) assign_kal_uint8(7) assign_kal_uint8(8) assign_kal_uint8(9) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_PS_L_NUMBER_S_PS_L_SUB_ADDR_S_PS_L_NUMBER_S_S_K_8_S_K_8_S_K_8_A30A_K_8_S_K_8_S_K_8_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_8_PS_L_NUMBER_S_PS_L_SUB_ADDR_S_PS_L_NUMBER_S_S_K_8_S_K_8_S_K_8_A30A_K_8_S_K_8_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_CC_CALL_RING_IND */
void _send_S_k_8_PS_l_number_s_PS_l_sub_addr_s_PS_l_number_s_S_k_8_S_k_8_S_k_8_A30A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_l_number_s_S_l_sub_addr_s_S_l_number_s_S_k_8_S_k_8_S_k_8_30A_k_8_S_k_8_S_k_8_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_l_number_s_S_l_sub_addr_s_S_l_number_s_S_k_8_S_k_8_S_k_8_30A_k_8_S_k_8_S_k_8_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assignSP(1,l4c_number_struct) assignSP(2,l4c_sub_addr_struct) assignSP(3,l4c_number_struct) assign_kal_uint8(4) assign_kal_uint8(5) assign_kal_uint8(6) assignA(7,kal_uint8,30) assign_kal_uint8(8) assign_kal_uint8(9) assign_kal_uint8(10) assign_kal_uint8(11) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_PS_L_NUMBER_S_PS_L_SUB_ADDR_S_S_K_8_S_K_8_
#define _SEND_FUNC_PS_L_NUMBER_S_PS_L_SUB_ADDR_S_S_K_8_S_K_8_
	/* MSG_ID_MMI_CC_CALL_CONNECT_IND */
void _send_PS_l_number_s_PS_l_sub_addr_s_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_number_s_S_l_sub_addr_s_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_l_number_s_S_l_sub_addr_s_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assignSP(0,l4c_number_struct) assignSP(1,l4c_sub_addr_struct) assign_kal_uint8(2) assign_kal_uint8(3) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_BOOL_
#define _SEND_FUNC_S_K_8_S_K_BOOL_
	/* MSG_ID_MMI_CC_CALL_DISCONNECT_IND */
void _send_S_k_8_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_bool(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_16_
#define _SEND_FUNC_S_K_8_S_K_16_
	/* MSG_ID_MMI_CC_CALL_RELEASE_IND */
void _send_S_k_8_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_CC_SPEECH_IND */
void _send_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_S_K_BOOL_S_K_8_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_S_K_BOOL_S_K_8_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_CC_NOTIFY_SS_IND */
void _send_S_k_8_S_k_8_S_k_bool_S_k_8_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8_S_k_bool_S_k_8_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8_S_k_bool_S_k_8_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) assign_kal_bool(2) assign_kal_uint8(3) assign_kal_bool(4) assign_kal_uint8(5) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_16_
#define _SEND_FUNC_S_K_8_S_K_16_
	/* MSG_ID_MMI_CC_NOTIFY_SS_CUG_IND */
void _send_S_k_8_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_BOOL_PS_L_NUMBER_S_PS_L_SUB_ADDR_S_
#define _SEND_FUNC_S_K_8_S_K_BOOL_PS_L_NUMBER_S_PS_L_SUB_ADDR_S_
	/* MSG_ID_MMI_CC_NOTIFY_SS_ECT_IND */
void _send_S_k_8_S_k_bool_PS_l_number_s_PS_l_sub_addr_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_bool_S_l_number_s_S_l_sub_addr_s__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_bool_S_l_number_s_S_l_sub_addr_s__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_bool(1) assignSP(2,l4c_number_struct) assignSP(3,l4c_sub_addr_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_S_K_8_S_K_8_A30A_K_8_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_S_K_8_S_K_8_A30A_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_CC_NOTIFY_SS_CNAP_IND */
void _send_S_k_8_S_k_8_S_k_8_S_k_8_A30A_k_8_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8_S_k_8_S_k_8_30A_k_8_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8_S_k_8_S_k_8_30A_k_8_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) assignA(4,kal_uint8,30) assign_kal_uint8(5) assign_kal_uint8(6) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_BOOL_PS_L_NUMBER_S_S_K_BOOL_PS_L_SUB_ADDR_S_S_K_BOOL_S_K_8_S_K_BOOL_S_K_8_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_8_S_K_BOOL_PS_L_NUMBER_S_S_K_BOOL_PS_L_SUB_ADDR_S_S_K_BOOL_S_K_8_S_K_BOOL_S_K_8_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_CC_NOTIFY_SS_CCBS_IND */
void _send_S_k_8_S_k_bool_PS_l_number_s_S_k_bool_PS_l_sub_addr_s_S_k_bool_S_k_8_S_k_bool_S_k_8_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_bool_S_l_number_s_S_k_bool_S_l_sub_addr_s_S_k_bool_S_k_8_S_k_bool_S_k_8_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_bool_S_l_number_s_S_k_bool_S_l_sub_addr_s_S_k_bool_S_k_8_S_k_bool_S_k_8_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_bool(1) assignSP(2,l4c_number_struct) assign_kal_bool(3) assignSP(4,l4c_sub_addr_struct) assign_kal_bool(5) assign_kal_uint8(6) assign_kal_bool(7) assign_kal_uint8(8) assign_kal_bool(9) assign_kal_uint8(10) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_
#define _SEND_FUNC_S_K_8_
	/* MSG_ID_MMI_CC_CALL_ACCEPT_REQ_IND */
void _send_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_CC_VIDEO_CALL_STATUS_IND */
void _send_S_k_8_S_k_8_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) assign_kal_bool(2) assign_kal_uint8(3) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_CC_REL_COMP_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#endif /* defined(__MOD_CSM__) */
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_CC_SET_BEARER_SERVICE_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_CC_GET_BEARER_SERVICE_RSP */
void _send_S_k_bool_S_k_8_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_8_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_CC_SET_CSD_PROFILE_RSP */
void _send_S_k_8_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_bool(1) assign_kal_uint16(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_8_A32A_K_8_A32A_K_8_A4A_K_8_S_L4_NAME_S_
#define _SEND_FUNC_S_K_BOOL_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_8_A32A_K_8_A32A_K_8_A4A_K_8_S_L4_NAME_S_
	/* MSG_ID_MMI_CC_GET_CSD_PROFILE_RSP */
void _send_S_k_bool_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_A32A_k_8_A32A_k_8_A4A_k_8_S_l4_name_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_32A_k_8_32A_k_8_4A_k_8_S_l4_name_s__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_32A_k_8_32A_k_8_4A_k_8_S_l4_name_s__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assignS(1,l4c_number_struct) assign_kal_uint8(2) assign_kal_uint8(3) assign_kal_uint8(4) assign_kal_uint8(5) assignA(6,kal_uint8,32) assignA(7,kal_uint8,32) assignA(8,kal_uint8,4) assignS(9,l4_name_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_CC_GET_FREE_CSD_PROFILE_NUM_RSP */
void _send_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_SS_GET_EMLPP_PRIORITY_RSP */
void _send_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_S_K_8_
#define _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SS_EMLPP_RSP */
void _send_S_l_result_s_S_k_8_S_k_8_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_8_S_k_8_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_8_S_k_8_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) assign_kal_uint8(4) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_S_K_8_A13A_FORWARDING_LIST_S_
#define _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_S_K_8_A13A_FORWARDING_LIST_S_
	/* MSG_ID_MMI_SS_CALL_FORWARD_RSP */
void _send_S_l_result_s_S_k_8_S_k_8_S_k_8_S_k_8_A13A_forwarding_list_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_8_S_k_8_S_k_8_S_k_8_13A_forwarding_list_s__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_8_S_k_8_S_k_8_S_k_8_13A_forwarding_list_s__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) assign_kal_uint8(4) assignA(5,forwarding_list_struct,13) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_S_K_8_A13A_K_8_
#define _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_S_K_8_A13A_K_8_
	/* MSG_ID_MMI_SS_CALL_WAIT_RSP */
void _send_S_l_result_s_S_k_8_S_k_8_S_k_8_S_k_8_A13A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_8_S_k_8_S_k_8_S_k_8_13A_k_8__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_8_S_k_8_S_k_8_S_k_8_13A_k_8__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) assign_kal_uint8(4) assignA(5,kal_uint8,13) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_SS_INTERROGATE_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_
#define _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_
	/* MSG_ID_MMI_SS_CDIP_INTERROGATE_IND */
void _send_S_l_result_s_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint8(1) assign_kal_uint8(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_
#define _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SS_CLIP_INTERROGATE_IND */
void _send_S_l_result_s_S_k_8_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_8_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_8_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_
#define _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SS_CLIR_INTERROGATE_IND */
void _send_S_l_result_s_S_k_8_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_8_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_8_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_
#define _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SS_CNAP_INTERROGATE_IND */
void _send_S_l_result_s_S_k_8_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_8_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_8_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_
#define _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SS_COLP_INTERROGATE_IND */
void _send_S_l_result_s_S_k_8_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_8_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_8_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_
#define _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SS_COLR_INTERROGATE_IND */
void _send_S_l_result_s_S_k_8_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_8_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_8_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_S_K_8_A13A_BARRING_LIST_S_
#define _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_S_K_8_A13A_BARRING_LIST_S_
	/* MSG_ID_MMI_SS_CALL_BARRING_RSP */
void _send_S_l_result_s_S_k_8_S_k_8_S_k_8_S_k_8_A13A_barring_list_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_8_S_k_8_S_k_8_S_k_8_13A_barring_list_s__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_8_S_k_8_S_k_8_S_k_8_13A_barring_list_s__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) assign_kal_uint8(4) assignA(5,barring_list_struct,13) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_A183A_K_8_S_K_8_
#define _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_A183A_K_8_S_K_8_
	/* MSG_ID_MMI_SS_USSD_RSP */
void _send_S_l_result_s_S_k_8_S_k_8_S_k_8_A183A_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_8_S_k_8_S_k_8_183A_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_8_S_k_8_S_k_8_183A_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) assignA(4,kal_uint8,183) assign_kal_uint8(5) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_A183A_K_8_S_K_8_
#define _SEND_FUNC_S_K_8_A183A_K_8_S_K_8_
	/* MSG_ID_MMI_SS_USSR_IND */
void _send_S_k_8_A183A_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_183A_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_183A_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assignA(1,kal_uint8,183) assign_kal_uint8(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_A183A_K_8_S_K_8_
#define _SEND_FUNC_S_K_8_A183A_K_8_S_K_8_
	/* MSG_ID_MMI_SS_USSN_IND */
void _send_S_k_8_A183A_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_183A_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_183A_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assignA(1,kal_uint8,183) assign_kal_uint8(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_
#define _SEND_FUNC_S_L_RESULT_S_
	/* MSG_ID_MMI_SS_CHANGE_PASSWORD_RSP */
void _send_S_l_result_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s__struct *p = construct_local_para(sizeof(msg_S_l_result_s__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_PS_L_SS_STRING_INFO_S_
#define _SEND_FUNC_S_L_RESULT_S_PS_L_SS_STRING_INFO_S_
	/* MSG_ID_MMI_SS_PARSING_STRING_RSP */
void _send_S_l_result_s_PS_l_ss_string_info_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_l_ss_string_info_s__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_l_ss_string_info_s__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assignSP(1,l4c_ss_string_info_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_
#define _SEND_FUNC_S_K_8_
	/* MSG_ID_MMI_SS_CB_PASSWORD_IND */
void _send_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_
#define _SEND_FUNC_S_K_8_
	/* MSG_ID_MMI_SMS_CB_GS_CHANGE_IND */
void _send_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_PS_CCBS_LIST_S_
#define _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_PS_CCBS_LIST_S_
	/* MSG_ID_MMI_SS_CCBS_RSP */
void _send_S_l_result_s_S_k_8_S_k_8_S_k_8_PS_ccbs_list_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_8_S_k_8_S_k_8_S_ccbs_list_s__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_8_S_k_8_S_k_8_S_ccbs_list_s__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) assignSP(4,ccbs_list_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_SS_ABORT_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_SS_SET_CLIR_FLAG_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
/* Hardware - Audio Related Service Messages */
#if defined(__MOD_UEM__)
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_EQ_SET_VOLUME_RSP */
void _send_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_EXE_VOLUME_REQ_IND */
void _send_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_VOLUME_CHANGE_IND */
void _send_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_EQ_SET_MUTE_RSP */
void _send_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_BOOL_
#define _SEND_FUNC_S_K_8_S_K_BOOL_
	/* MSG_ID_MMI_EQ_EXE_MUTE_REQ_IND */
void _send_S_k_8_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_bool(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_BOOL_
#define _SEND_FUNC_S_K_8_S_K_BOOL_
	/* MSG_ID_MMI_EQ_MUTE_CHANGE_IND */
void _send_S_k_8_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_bool(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SET_SILENT_MODE_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SET_SILENT_MODE_REQ_IND */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SET_GPIO_LEVEL_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_SET_GPIO_LEVEL_REQ_IND */
void _send_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_EQ_GET_GPIO_LEVEL_RSP */
void _send_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_EXE_GPIO_LEVEL_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_EXE_GPIO_LEVEL_REQ_IND */
void _send_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_PLAY_AUDIO_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_16_
#define _SEND_FUNC_S_K_8_S_K_16_
	/* MSG_ID_MMI_EQ_PLAY_AUDIO_FINISH_IND */
void _send_S_k_8_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_STOP_AUDIO_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EQ_PLAY_AUDIO_STREAM_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EQ_STOP_AUDIO_STREAM_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_PLAY_EXT_IMELODY_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_BOOL_
#define _SEND_FUNC_S_K_8_S_K_BOOL_
	/* MSG_ID_MMI_EQ_GPIO_DETECT_IND */
void _send_S_k_8_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_bool(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_GPIO_DETECT_RES_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SET_SPEECH_MODE_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EQ_PLAY_AUDIO_BY_NAME_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EQ_STOP_AUDIO_BY_NAME_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EQ_SET_AUDIO_PROFILE_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_AUDIO_PROFILE_S_
#define _SEND_FUNC_S_K_BOOL_S_AUDIO_PROFILE_S_
	/* MSG_ID_MMI_EQ_GET_AUDIO_PROFILE_RSP */
void _send_S_k_bool_S_audio_profile_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_audio_profile_s__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_audio_profile_s__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assignS(1,audio_profile_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EQ_SET_AUDIO_PARAM_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_PS_AUDIO_PARAM_S_
#define _SEND_FUNC_S_K_BOOL_PS_AUDIO_PARAM_S_
	/* MSG_ID_MMI_EQ_GET_AUDIO_PARAM_RSP */
void _send_S_k_bool_PS_audio_param_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_audio_param_s__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_audio_param_s__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assignSP(1,audio_param_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_START_ADC_ALL_CHANNEL_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_STOP_ADC_ALL_CHANNEL_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_INT32_S_K_INT32_S_K_INT32_S_K_INT32_S_K_INT32_
#define _SEND_FUNC_S_K_INT32_S_K_INT32_S_K_INT32_S_K_INT32_S_K_INT32_
	/* MSG_ID_MMI_EQ_ADC_ALL_CHANNEL_IND */
void _send_S_k_int32_S_k_int32_S_k_int32_S_k_int32_S_k_int32_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_int32_S_k_int32_S_k_int32_S_k_int32_S_k_int32__struct *p = construct_local_para(sizeof(msg_S_k_int32_S_k_int32_S_k_int32_S_k_int32_S_k_int32__struct),0);

	va_start(args, msg);
	assignS(0,kal_int32) assignS(1,kal_int32) assignS(2,kal_int32) assignS(3,kal_int32) assignS(4,kal_int32) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SET_AUDIO_MODE_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_PLAY_PATTERN_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EQ_SET_HW_LEVEL_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_L_HW_PROFILE_S_
#define _SEND_FUNC_S_K_BOOL_S_L_HW_PROFILE_S_
	/* MSG_ID_MMI_EQ_GET_HW_LEVEL_RSP */
void _send_S_k_bool_S_l_hw_profile_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_l_hw_profile_s__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_l_hw_profile_s__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assignS(1,l4c_hw_profile_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SET_SLEEP_MODE_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SET_SLEEP_MODE_REQ_IND */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_GET_MS_IMEI_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SET_MS_IMEI_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_RTC_POWERON_STATE_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#endif /* defined(__MOD_UEM__) */
/* Hardware - RTC, Clock, Alarm Related Messages */
#if defined(__MOD_UEM__)
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EQ_SET_RTC_TIME_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_S_RTC_ALARM_INFO_S_
#define _SEND_FUNC_S_K_8_S_K_8_S_RTC_ALARM_INFO_S_
	/* MSG_ID_MMI_EQ_SET_RTC_TIME_REQ_IND */
void _send_S_k_8_S_k_8_S_rtc_alarm_info_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8_S_rtc_alarm_info_s__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8_S_rtc_alarm_info_s__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) assignS(2,rtc_alarm_info_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_EXE_RTC_TIMER_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_A3A_RTC_ALARM_INFO_S_
#define _SEND_FUNC_S_K_BOOL_S_K_8_A3A_RTC_ALARM_INFO_S_
	/* MSG_ID_MMI_EQ_GET_RTC_TIME_RSP */
void _send_S_k_bool_S_k_8_A3A_rtc_alarm_info_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8_3A_rtc_alarm_info_s__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8_3A_rtc_alarm_info_s__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) assignA(2,rtc_alarm_info_struct,3) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EQ_DEL_RTC_TIMER_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_DEL_RTC_TIMER_REQ_IND */
void _send_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_EXE_DEL_RTC_TIMER_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_EXE_DEL_RTC_TIMER_REQ_IND */
void _send_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SET_DATE_TIME_FORMAT_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_EQ_SET_DATE_TIME_FORMAT_REQ_IND */
void _send_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_EVENTID_S_VOID_P_
#define _SEND_FUNC_S_K_BOOL_S_EVENTID_S_VOID_P_
	/* MSG_ID_MMI_EQ_START_TIMER_RSP */
void _send_S_k_bool_S_eventid_S_void_p_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_eventid_S_void_p__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_eventid_S_void_p__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assignS(1,eventid) assignS(2,void*) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_STOP_TIMER_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_PS_RTC_FORMAT_S_
#define _SEND_FUNC_S_K_8_PS_RTC_FORMAT_S_
	/* MSG_ID_MMI_EQ_CLOCK_TICK_IND */
void _send_S_k_8_PS_rtc_format_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_rtc_format_s__struct *p = construct_local_para(sizeof(msg_S_k_8_S_rtc_format_s__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assignSP(1,rtc_format_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_PS_RTC_FORMAT_S_
#define _SEND_FUNC_PS_RTC_FORMAT_S_
	/* MSG_ID_MMI_EQ_ALARM_IND */
void _send_PS_rtc_format_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_rtc_format_s__struct *p = construct_local_para(sizeof(msg_S_rtc_format_s__struct),0);

	va_start(args, msg);
	assignSP(0,rtc_format_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_MMI_AT_ALARM_INFO_S_
#define _SEND_FUNC_S_MMI_AT_ALARM_INFO_S_
	/* MSG_ID_MMI_AT_ALARM_SET_REQ_IND */
void _send_S_mmi_at_alarm_info_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_mmi_at_alarm_info_s__struct *p = construct_local_para(sizeof(msg_S_mmi_at_alarm_info_s__struct),0);

	va_start(args, msg);
	assignS(0,mmi_at_alarm_info_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_
#define _SEND_FUNC_S_K_8_
	/* MSG_ID_MMI_AT_ALARM_DELETE_REQ_IND */
void _send_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#endif /* defined(__MOD_UEM__) */
/* Hardware - Keypad, Indicator, LCD Related Messages */
#if defined(__MOD_UEM__)
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SIMULATE_KEY_PRESS_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_SIMULATE_KEY_PRESS_REQ_IND */
void _send_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SET_INDICATOR_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_SET_INDICATOR_REQ_IND */
void _send_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_EQ_GET_INDICATOR_RSP */
void _send_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_DISPLAY_TEXT_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_A30A_K_8_
#define _SEND_FUNC_A30A_K_8_
	/* MSG_ID_MMI_EQ_DISPLAY_TEXT_REQ_IND */
void _send_A30A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_30A_k_8__struct *p = construct_local_para(sizeof(msg_30A_k_8__struct),0);

	va_start(args, msg);
	assignA(0,kal_uint8,30) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_DRV_GET_KEY_FUNC_
#define _SEND_FUNC_S_DRV_GET_KEY_FUNC_
	/* MSG_ID_MMI_EQ_KEYPAD_DETECT_IND */
void _send_S_drv_get_key_func_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_drv_get_key_func__struct *p = construct_local_para(sizeof(msg_S_drv_get_key_func__struct),0);

	va_start(args, msg);
	assignS(0,drv_get_key_func) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#endif /* defined(__MOD_UEM__) */
/* Hardware - Misc Messages */
#if defined(__MOD_UEM__)
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EQ_SET_LANGUAGE_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_
#define _SEND_FUNC_S_K_8_
	/* MSG_ID_MMI_EQ_SET_LANGUAGE_REQ_IND */
void _send_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EQ_SET_GREETING_TEXT_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_A62A_K_8_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_A62A_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_SET_GREETING_TEXT_REQ_IND */
void _send_S_k_bool_S_k_8_A62A_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8_62A_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8_62A_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) assignA(2,kal_uint8,62) assign_kal_uint8(3) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SET_VIBRATOR_MODE_REQ_IND */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EQ_SET_VIBRATOR_MODE_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EQ_SET_COUNTRY_CODE_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_EQ_GET_COUNTRY_CODE_RSP */
void _send_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_GET_BATTERY_STATUS_RSP */
void _send_S_k_bool_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) assign_kal_uint8(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_A30A_K_8_
#define _SEND_FUNC_S_K_BOOL_A30A_K_8_
	/* MSG_ID_MMI_EQ_GET_EQUIP_ID_RSP */
void _send_S_k_bool_A30A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_30A_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_30A_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assignA(1,kal_uint8,30) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_LOAD_DEFAULT_CONFIG_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_POWER_ON_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_POWER_OFF_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_S_K_8_PS_RTC_FORMAT_S_S_K_8_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_S_K_8_PS_RTC_FORMAT_S_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_POWER_ON_IND */
void _send_S_k_8_S_k_8_S_k_8_PS_rtc_format_s_S_k_8_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8_S_k_8_S_rtc_format_s_S_k_8_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8_S_k_8_S_rtc_format_s_S_k_8_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) assign_kal_uint8(2) assignSP(3,rtc_format_struct) assign_kal_uint8(4) assign_kal_uint8(5) assign_kal_uint8(6) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_BATTERY_STATUS_IND */
void _send_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_PMIC_CONFIG_PARAM_S_
#define _SEND_FUNC_S_K_8_S_PMIC_CONFIG_PARAM_S_
	/* MSG_ID_MMI_EQ_PMIC_CONFIG_RSP */
void _send_S_k_8_S_pmic_config_param_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_pmic_config_param_s__struct *p = construct_local_para(sizeof(msg_S_k_8_S_pmic_config_param_s__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assignS(1,pmic_config_param_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_RF_TEST_GSM_PARAM_S_
#define _SEND_FUNC_S_K_8_S_RF_TEST_GSM_PARAM_S_
	/* MSG_ID_MMI_EQ_RF_TEST_GSM_RSP */
void _send_S_k_8_S_rf_test_gsm_param_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_rf_test_gsm_param_s__struct *p = construct_local_para(sizeof(msg_S_k_8_S_rf_test_gsm_param_s__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assignS(1,rf_test_gsm_param_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_FM_RADIO_CONFIG_PARAM_S_
#define _SEND_FUNC_S_K_8_S_FM_RADIO_CONFIG_PARAM_S_
	/* MSG_ID_MMI_EQ_FM_RADIO_CONFIG_RSP */
void _send_S_k_8_S_fm_radio_config_param_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_fm_radio_config_param_s__struct *p = construct_local_para(sizeof(msg_S_k_8_S_fm_radio_config_param_s__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assignS(1,fm_radio_config_param_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_RF_TEST_WIFI_PARAM_S_
#define _SEND_FUNC_S_K_8_S_RF_TEST_WIFI_PARAM_S_
	/* MSG_ID_MMI_EQ_RF_TEST_WIFI_RSP */
void _send_S_k_8_S_rf_test_wifi_param_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_rf_test_wifi_param_s__struct *p = construct_local_para(sizeof(msg_S_k_8_S_rf_test_wifi_param_s__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assignS(1,rf_test_wifi_param_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#endif /* defined(__MOD_UEM__) */
/* Hardware - NVRAM messages */
#if defined(__MOD_NVRAM__)
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_16_A1A_K_8_
#define _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_16_A1A_K_8_
	/* MSG_ID_MMI_EQ_NVRAM_READ_RSP */
void _send_S_l_result_s_S_k_8_S_k_16_A1A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_8_S_k_16_1A_k_8__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_8_S_k_16_1A_k_8__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint8(1) assign_kal_uint16(2) assignA(3,kal_uint8,1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_16_
#define _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_16_
	/* MSG_ID_MMI_EQ_NVRAM_WRITE_RSP */
void _send_S_l_result_s_S_k_8_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_8_S_k_16__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_8_S_k_16__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint8(1) assign_kal_uint16(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_
#define _SEND_FUNC_S_L_RESULT_S_
	/* MSG_ID_MMI_EQ_NVRAM_RESET_RSP */
void _send_S_l_result_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s__struct *p = construct_local_para(sizeof(msg_S_l_result_s__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_SET_UART_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_S_K_32_S_K_8_S_K_32_S_K_8_S_K_32_S_K_8_S_K_32_
#define _SEND_FUNC_S_K_BOOL_S_K_8_S_K_32_S_K_8_S_K_32_S_K_8_S_K_32_S_K_8_S_K_32_
	/* MSG_ID_MMI_EQ_GET_UART_RSP */
void _send_S_k_bool_S_k_8_S_k_32_S_k_8_S_k_32_S_k_8_S_k_32_S_k_8_S_k_32_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8_S_k_32_S_k_8_S_k_32_S_k_8_S_k_32_S_k_8_S_k_32__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8_S_k_32_S_k_8_S_k_32_S_k_8_S_k_32_S_k_8_S_k_32__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) assignS(2,kal_uint32) assign_kal_uint8(3) assignS(4,kal_uint32) assign_kal_uint8(5) assignS(6,kal_uint32) assign_kal_uint8(7) assignS(8,kal_uint32) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_
#define _SEND_FUNC_S_K_8_
	/* MSG_ID_MMI_ATTACH_UART_PORT_RSP */
void _send_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_
#define _SEND_FUNC_S_K_8_
	/* MSG_ID_MMI_DETACH_UART_PORT_RSP */
void _send_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#endif /* defined(__MOD_NVRAM__) */
/* Network Related Messages */
#if defined(__MOD_RAC__)
#ifndef _SEND_FUNC_S_K_BOOL_A16A_K_8_A3A_K_8_
#define _SEND_FUNC_S_K_BOOL_A16A_K_8_A3A_K_8_
	/* MSG_ID_MMI_NW_GET_IMEI_RSP */
void _send_S_k_bool_A16A_k_8_A3A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_16A_k_8_3A_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_16A_k_8_3A_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assignA(1,kal_uint8,16) assignA(2,kal_uint8,3) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_NW_ABORT_PLMN_LIST_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_NW_SET_ATTACH_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_NW_GET_ATTACH_RSP */
void _send_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_NW_SET_MOBILE_CLASS_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_NW_GET_MOBILE_CLASS_RSP */
void _send_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_NW_SET_PLMN_SELECT_MODE_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_NW_GET_PLMN_SELECT_MODE_RSP */
void _send_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_8_AV0A_K_8_S_K_8_
#define _SEND_FUNC_S_L_RESULT_S_S_K_8_AV0A_K_8_S_K_8_
	/* MSG_ID_MMI_NW_SET_PLMN_RSP */
void _send_S_l_result_s_S_k_8_Av0A_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_8_v0A_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_8_v0A_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint8(1) assignA(2,kal_uint8,MAX_PLMN_LEN+1) assign_kal_uint8(3) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_8_A16A_L_RAT_PLMN_INFO_S_
#define _SEND_FUNC_S_L_RESULT_S_S_K_8_A16A_L_RAT_PLMN_INFO_S_
	/* MSG_ID_MMI_NW_GET_PLMN_LIST_RSP */
void _send_S_l_result_s_S_k_8_A16A_l_rat_plmn_info_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_8_16A_l_rat_plmn_info_s__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_8_16A_l_rat_plmn_info_s__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint8(1) assignA(2,l4c_rat_plmn_info_struct,16) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_AV0A_K_8_
#define _SEND_FUNC_S_K_BOOL_AV0A_K_8_
	/* MSG_ID_MMI_NW_GET_CURRENT_PLMN_RSP */
void _send_S_k_bool_Av0A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_v0A_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_v0A_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assignA(1,kal_uint8,MAX_PLMN_LEN+1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_
	/* MSG_ID_MMI_NW_GET_SIGNAL_LEVEL_RSP */
void _send_S_k_bool_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) assign_kal_uint8(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_NW_GET_BAND_RSP */
void _send_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_AV0A_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_A2A_K_8_
#define _SEND_FUNC_S_K_8_AV0A_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_A2A_K_8_
	/* MSG_ID_MMI_NW_ATTACH_IND */
void _send_S_k_8_Av0A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_A2A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_v0A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_2A_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_v0A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_2A_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assignA(1,kal_uint8,MAX_PLMN_LEN+1) assign_kal_uint8(2) assign_kal_uint8(3) assign_kal_uint8(4) assign_kal_uint8(5) assign_kal_uint8(6) assignA(7,kal_uint8,2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_PS_K_8_S_K_16_S_K_8_S_K_8_S_K_8_
#define _SEND_FUNC_PS_K_8_S_K_16_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_NW_REG_STATE_IND */
void _send_PS_k_8_S_k_16_S_k_8_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_16_S_k_8_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_16_S_k_8_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assignSP(0,kal_uint8) assign_kal_uint16(1) assign_kal_uint8(2) assign_kal_uint8(3) assign_kal_uint8(4) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_NW_RX_LEVEL_IND */
void _send_S_k_8_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) assign_kal_uint8(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_S_K_BOOL_S_K_8_A24A_K_8_S_K_8_S_K_8_S_K_BOOL_S_K_8_A24A_K_8_S_K_8_S_K_8_S_K_8_S_L_NW_TIME_ZONE_TIME_S_S_K_8_S_K_8_A3A_K_8_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_S_K_BOOL_S_K_8_A24A_K_8_S_K_8_S_K_8_S_K_BOOL_S_K_8_A24A_K_8_S_K_8_S_K_8_S_K_8_S_L_NW_TIME_ZONE_TIME_S_S_K_8_S_K_8_A3A_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_NW_TIME_ZONE_IND */
void _send_S_k_8_S_k_8_S_k_bool_S_k_8_A24A_k_8_S_k_8_S_k_8_S_k_bool_S_k_8_A24A_k_8_S_k_8_S_k_8_S_k_8_S_l_nw_time_zone_time_s_S_k_8_S_k_8_A3A_k_8_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8_S_k_bool_S_k_8_24A_k_8_S_k_8_S_k_8_S_k_bool_S_k_8_24A_k_8_S_k_8_S_k_8_S_k_8_S_l_nw_time_zone_time_s_S_k_8_S_k_8_3A_k_8_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8_S_k_bool_S_k_8_24A_k_8_S_k_8_S_k_8_S_k_bool_S_k_8_24A_k_8_S_k_8_S_k_8_S_k_8_S_l_nw_time_zone_time_s_S_k_8_S_k_8_3A_k_8_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) assign_kal_bool(2) assign_kal_uint8(3) assignA(4,kal_uint8,24) assign_kal_uint8(5) assign_kal_uint8(6) assign_kal_bool(7) assign_kal_uint8(8) assignA(9,kal_uint8,24) assign_kal_uint8(10) assign_kal_uint8(11) assign_kal_uint8(12) assignS(13,l4c_nw_time_zone_time_struct) assign_kal_uint8(14) assign_kal_uint8(15) assignA(16,kal_uint8,3) assign_kal_uint8(17) assign_kal_uint8(18) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_
#define _SEND_FUNC_S_K_8_
	/* MSG_ID_MMI_NW_SEL_MODE_IND */
void _send_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_
#define _SEND_FUNC_S_K_8_
	/* MSG_ID_MMI_NW_MMRR_SERVICE_STATUS_IND */
void _send_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_NW_SET_PREFERRED_BAND_RSP */
void _send_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_NW_SET_GPRS_CONNECT_TYPE_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_NW_GET_GPRS_CONNECT_TYPE_RSP */
void _send_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_
#define _SEND_FUNC_S_L_RESULT_S_
	/* MSG_ID_MMI_NW_PWROFF_DETACH_RSP */
void _send_S_l_result_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s__struct *p = construct_local_para(sizeof(msg_S_l_result_s__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_NW_CFUN_STATE_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_NW_GET_RAT_MODE_RSP */
void _send_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_NW_SET_RAT_MODE_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_NW_GET_PREFER_RAT_RSP */
void _send_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_NW_SET_PREFER_RAT_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#endif /* defined(__MOD_RAC__) */
/* Security Related Messages */
#if defined(__MOD_SMU__)
#ifndef _SEND_FUNC_S_K_BOOL_A17A_K_8_
#define _SEND_FUNC_S_K_BOOL_A17A_K_8_
	/* MSG_ID_MMI_SMU_GET_IMSI_RSP */
void _send_S_k_bool_A17A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_17A_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_17A_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assignA(1,kal_uint8,17) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_S_SIM_CHV_INFO_S_
#define _SEND_FUNC_S_K_BOOL_S_K_16_S_SIM_CHV_INFO_S_
	/* MSG_ID_MMI_SMU_LOCK_RSP */
void _send_S_k_bool_S_k_16_S_sim_chv_info_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16_S_sim_chv_info_s__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16_S_sim_chv_info_s__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) assignS(2,sim_chv_info_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_SMU_RESET_DATA_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_SMU_GET_DIAL_MODE_RSP */
void _send_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_S_SIM_CHV_INFO_S_
#define _SEND_FUNC_S_K_BOOL_S_K_8_S_SIM_CHV_INFO_S_
	/* MSG_ID_MMI_SMU_VERIFY_PIN_RSP */
void _send_S_k_bool_S_k_8_S_sim_chv_info_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8_S_sim_chv_info_s__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8_S_sim_chv_info_s__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) assignS(2,sim_chv_info_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_SMU_GET_PIN_TYPE_RSP */
void _send_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_SMU_SET_PREFERRED_OPER_LIST_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_AV1A_K_8_AV2A_K_8_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_AV1A_K_8_AV2A_K_8_S_K_16_
	/* MSG_ID_MMI_SMU_GET_PREFERRED_OPER_LIST_RSP */
void _send_S_k_bool_S_k_16_Av1A_k_8_Av2A_k_8_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16_v1A_k_8_v2A_k_8_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16_v1A_k_8_v2A_k_8_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) assignA(2,kal_uint8,MAX_SUPPORT_EF_PLMNSEL_REC*7) assignA(3,kal_uint8,MAX_SUPPORT_EF_PLMNSEL_REC*2) assign_kal_uint16(4) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_SMU_SET_PUC_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_A3A_K_8_A18A_K_8_
#define _SEND_FUNC_S_K_BOOL_A3A_K_8_A18A_K_8_
	/* MSG_ID_MMI_SMU_GET_PUC_RSP */
void _send_S_k_bool_A3A_k_8_A18A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_3A_k_8_18A_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_3A_k_8_18A_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assignA(1,kal_uint8,3) assignA(2,kal_uint8,18) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_S_SIM_CHV_INFO_S_
#define _SEND_FUNC_S_K_BOOL_S_K_16_S_SIM_CHV_INFO_S_
	/* MSG_ID_MMI_SMU_CHANGE_PASSWORD_RSP */
void _send_S_k_bool_S_k_16_S_sim_chv_info_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16_S_sim_chv_info_s__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16_S_sim_chv_info_s__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) assignS(2,sim_chv_info_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_S_K_16_A256A_K_8_
#define _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_S_K_16_A256A_K_8_
	/* MSG_ID_MMI_SMU_RESTRICTED_ACCESS_RSP */
void _send_S_l_result_s_S_k_8_S_k_8_S_k_16_A256A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_8_S_k_8_S_k_16_256A_k_8__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_8_S_k_8_S_k_16_256A_k_8__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint16(3) assignA(4,kal_uint8,256) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_SMU_SET_DIAL_MODE_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_SMU_WRITE_SIM_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_16_A260A_K_8_
#define _SEND_FUNC_S_L_RESULT_S_S_K_16_A260A_K_8_
	/* MSG_ID_MMI_SMU_READ_SIM_RSP */
void _send_S_l_result_s_S_k_16_A260A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_16_260A_k_8__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_16_260A_k_8__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint16(1) assignA(2,kal_uint8,260) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_SMU_POWER_OFF_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_SMU_REMOVE_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_BOOL_S_SIM_CHV_INFO_S_S_K_8_
#define _SEND_FUNC_S_K_8_S_K_BOOL_S_SIM_CHV_INFO_S_S_K_8_
	/* MSG_ID_MMI_SMU_PASSWORD_REQUIRED_IND */
void _send_S_k_8_S_k_bool_S_sim_chv_info_s_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_bool_S_sim_chv_info_s_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_bool_S_sim_chv_info_s_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_bool(1) assignS(2,sim_chv_info_struct) assign_kal_uint8(3) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_16_
#define _SEND_FUNC_S_K_16_
	/* MSG_ID_MMI_SMU_SUPPORT_PLMN_LIST_IND */
void _send_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_uint16(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_16_
#define _SEND_FUNC_S_K_16_
	/* MSG_ID_MMI_SMU_FAIL_IND */
void _send_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_uint16(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_16_S_K_8_
#define _SEND_FUNC_S_L_RESULT_S_S_K_16_S_K_8_
	/* MSG_ID_MMI_SMU_READ_FILE_INFO_RSP */
void _send_S_l_result_s_S_k_16_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_16_S_k_8__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_16_S_k_8__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint16(1) assign_kal_uint8(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_SIM_CHV_INFO_S_S_SIM_CHV_STATUS_S_
#define _SEND_FUNC_S_K_BOOL_S_SIM_CHV_INFO_S_S_SIM_CHV_STATUS_S_
	/* MSG_ID_MMI_SMU_CHECK_PIN_STATUS_RSP */
void _send_S_k_bool_S_sim_chv_info_s_S_sim_chv_status_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_sim_chv_info_s_S_sim_chv_status_s__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_sim_chv_info_s_S_sim_chv_status_s__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assignS(1,sim_chv_info_struct) assignS(2,sim_chv_status_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_A35A_K_8_A5A_K_8_S_K_8_
#define _SEND_FUNC_S_K_8_A35A_K_8_A5A_K_8_S_K_8_
	/* MSG_ID_MMI_SMU_STARTUP_INFO_IND */
void _send_S_k_8_A35A_k_8_A5A_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_35A_k_8_5A_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_35A_k_8_5A_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assignA(1,kal_uint8,35) assignA(2,kal_uint8,5) assign_kal_uint8(3) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SMU_CIPHER_IND */
void _send_S_k_bool_S_k_8_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_
#define _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SMU_SET_PERSONALIZATION_RSP */
void _send_S_l_result_s_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) assign_kal_uint8(4) assign_kal_uint8(5) assign_kal_uint8(6) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_A7A_K_8_A7A_K_8_A7A_K_8_A7A_K_8_A7A_K_8_A7A_K_8_A16A_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_
#define _SEND_FUNC_S_L_RESULT_S_A7A_K_8_A7A_K_8_A7A_K_8_A7A_K_8_A7A_K_8_A7A_K_8_A16A_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SMU_SML_STATUS_RSP */
void _send_S_l_result_s_A7A_k_8_A7A_k_8_A7A_k_8_A7A_k_8_A7A_k_8_A7A_k_8_A16A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_7A_k_8_7A_k_8_7A_k_8_7A_k_8_7A_k_8_7A_k_8_16A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_l_result_s_7A_k_8_7A_k_8_7A_k_8_7A_k_8_7A_k_8_7A_k_8_16A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assignA(1,kal_uint8,7) assignA(2,kal_uint8,7) assignA(3,kal_uint8,7) assignA(4,kal_uint8,7) assignA(5,kal_uint8,7) assignA(6,kal_uint8,7) assignA(7,kal_uint8,16) assign_kal_uint8(8) assign_kal_uint8(9) assign_kal_uint8(10) assign_kal_uint8(11) assign_kal_uint8(12) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_SIM_CHV_INFO_S_
#define _SEND_FUNC_S_K_8_S_SIM_CHV_INFO_S_
	/* MSG_ID_MMI_SMU_VERIFY_PIN_RESULT_IND */
void _send_S_k_8_S_sim_chv_info_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_sim_chv_info_s__struct *p = construct_local_para(sizeof(msg_S_k_8_S_sim_chv_info_s__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assignS(1,sim_chv_info_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#endif /* defined(__MOD_SMU__) */
/* PhoneBook Related Messages */
#if defined(__MOD_PHB__)
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_16_A15A_L_PHB_ENTRY_S_
#define _SEND_FUNC_S_L_RESULT_S_S_K_16_A15A_L_PHB_ENTRY_S_
	/* MSG_ID_MMI_PHB_GET_ENTRY_BY_NAME_RSP */
void _send_S_l_result_s_S_k_16_A15A_l_phb_entry_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_16_15A_l_phb_entry_s__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_16_15A_l_phb_entry_s__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint16(1) assignA(2,l4c_phb_entry_struct,15) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_16_A15A_L_PHB_ENTRY_S_
#define _SEND_FUNC_S_L_RESULT_S_S_K_16_A15A_L_PHB_ENTRY_S_
	/* MSG_ID_MMI_PHB_GET_ENTRY_BY_INDEX_RSP */
void _send_S_l_result_s_S_k_16_A15A_l_phb_entry_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_16_15A_l_phb_entry_s__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_16_15A_l_phb_entry_s__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint16(1) assignA(2,l4c_phb_entry_struct,15) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_PHB_SET_PREFERRED_STORAGE_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_S_K_16_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_8_S_K_16_S_K_16_
	/* MSG_ID_MMI_PHB_GET_PREFERRED_STORAGE_RSP */
void _send_S_k_bool_S_k_8_S_k_16_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8_S_k_16_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8_S_k_16_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) assign_kal_uint16(2) assign_kal_uint16(3) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_16_A15A_L_PHB_ENTRY_S_
#define _SEND_FUNC_S_L_RESULT_S_S_K_16_A15A_L_PHB_ENTRY_S_
	/* MSG_ID_MMI_PHB_SET_ENTRY_RSP */
void _send_S_l_result_s_S_k_16_A15A_l_phb_entry_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_16_15A_l_phb_entry_s__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_16_15A_l_phb_entry_s__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint16(1) assignA(2,l4c_phb_entry_struct,15) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_16_A15A_L_PHB_ENTRY_S_
#define _SEND_FUNC_S_L_RESULT_S_S_K_16_A15A_L_PHB_ENTRY_S_
	/* MSG_ID_MMI_PHB_DEL_ENTRY_RSP */
void _send_S_l_result_s_S_k_16_A15A_l_phb_entry_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_16_15A_l_phb_entry_s__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_16_15A_l_phb_entry_s__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint16(1) assignA(2,l4c_phb_entry_struct,15) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_PHB_SET_VOICE_MAIL_SERVER_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_A26A_K_16_
#define _SEND_FUNC_S_K_BOOL_A26A_K_16_
	/* MSG_ID_MMI_PHB_GET_ALPHA_LIST_RSP */
void _send_S_k_bool_A26A_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_26A_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_26A_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assignA(1,kal_uint16,26) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_S_K_16_
	/* MSG_ID_MMI_PHB_GET_TYPE_STATUS_RSP */
void _send_S_k_bool_S_k_16_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) assign_kal_uint16(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_A1A_L_PHB_LN_ENTRY_S_
#define _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_S_K_8_A1A_L_PHB_LN_ENTRY_S_
	/* MSG_ID_MMI_PHB_GET_LAST_NUMBER_RSP */
void _send_S_l_result_s_S_k_8_S_k_8_S_k_8_A1A_l_phb_ln_entry_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_8_S_k_8_S_k_8_1A_l_phb_ln_entry_s__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_8_S_k_8_S_k_8_1A_l_phb_ln_entry_s__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) assignA(4,l4c_phb_ln_entry_struct,1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_16_S_K_8_
#define _SEND_FUNC_S_L_RESULT_S_S_K_16_S_K_8_
	/* MSG_ID_MMI_PHB_SET_LAST_NUMBER_RSP */
void _send_S_l_result_s_S_k_16_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_16_S_k_8__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_16_S_k_8__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint16(1) assign_kal_uint8(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_16_
#define _SEND_FUNC_S_L_RESULT_S_S_K_16_
	/* MSG_ID_MMI_PHB_DEL_LAST_NUMBER_RSP */
void _send_S_l_result_s_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_16__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_16__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_16_S_K_16_S_K_8_S_K_8_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_16_S_K_16_S_K_8_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_PHB_STARTUP_FINISH_IND */
void _send_S_k_16_S_k_16_S_k_8_S_k_8_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_16_S_k_16_S_k_8_S_k_8_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_16_S_k_16_S_k_8_S_k_8_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint16(0) assign_kal_uint16(1) assign_kal_uint8(2) assign_kal_uint8(3) assign_kal_uint8(4) assign_kal_uint8(5) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_16_S_K_16_S_K_16_S_K_16_A1A_L_PHB_ENTRY_S_
#define _SEND_FUNC_S_K_8_S_K_16_S_K_16_S_K_16_S_K_16_A1A_L_PHB_ENTRY_S_
	/* MSG_ID_MMI_PHB_UPDATE_IND */
void _send_S_k_8_S_k_16_S_k_16_S_k_16_S_k_16_A1A_l_phb_entry_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_16_S_k_16_S_k_16_S_k_16_1A_l_phb_entry_s__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_16_S_k_16_S_k_16_S_k_16_1A_l_phb_entry_s__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint16(1) assign_kal_uint16(2) assign_kal_uint16(3) assign_kal_uint16(4) assignA(5,l4c_phb_entry_struct,1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_A1A_L_PHB_ENTRIES_S_S_K_8_
#define _SEND_FUNC_A1A_L_PHB_ENTRIES_S_S_K_8_
	/* MSG_ID_MMI_PHB_STARTUP_READ_IND */
void _send_A1A_l_phb_entries_s_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_1A_l_phb_entries_s_S_k_8__struct *p = construct_local_para(sizeof(msg_1A_l_phb_entries_s_S_k_8__struct),0);

	va_start(args, msg);
	assignA(0,l4c_phb_entries_struct,1) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_PHB_STARTUP_READ_NEXT_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_16_S_K_16_S_K_8_S_K_8_S_K_8_S_K_8_S_K_BOOL_S_K_BOOL_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_16_S_K_16_S_K_16_S_K_16_S_K_16_S_K_16_
#define _SEND_FUNC_S_K_16_S_K_16_S_K_8_S_K_8_S_K_8_S_K_8_S_K_BOOL_S_K_BOOL_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_16_S_K_16_S_K_16_S_K_16_S_K_16_S_K_16_
	/* MSG_ID_MMI_PHB_STARTUP_PHASE1_IND */
void _send_S_k_16_S_k_16_S_k_8_S_k_8_S_k_8_S_k_8_S_k_bool_S_k_bool_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_16_S_k_16_S_k_16_S_k_16_S_k_16_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_16_S_k_16_S_k_8_S_k_8_S_k_8_S_k_8_S_k_bool_S_k_bool_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_16_S_k_16_S_k_16_S_k_16_S_k_16_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_16_S_k_16_S_k_8_S_k_8_S_k_8_S_k_8_S_k_bool_S_k_bool_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_16_S_k_16_S_k_16_S_k_16_S_k_16_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_uint16(0) assign_kal_uint16(1) assign_kal_uint8(2) assign_kal_uint8(3) assign_kal_uint8(4) assign_kal_uint8(5) assign_kal_bool(6) assign_kal_bool(7) assign_kal_uint8(8) assign_kal_uint8(9) assign_kal_uint8(10) assign_kal_uint8(11) assign_kal_uint8(12) assign_kal_uint8(13) assign_kal_uint8(14) assign_kal_uint8(15) assign_kal_uint16(16) assign_kal_uint16(17) assign_kal_uint16(18) assign_kal_uint16(19) assign_kal_uint16(20) assign_kal_uint16(21) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_AV3A_L_PHB_BCD_ANR_S_S_K_8_
#define _SEND_FUNC_S_K_8_AV3A_L_PHB_BCD_ANR_S_S_K_8_
	/* MSG_ID_MMI_PHB_STARTUP_READ_ANR_IND */
void _send_S_k_8_Av3A_l_phb_bcd_anr_s_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_v3A_l_phb_bcd_anr_s_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_v3A_l_phb_bcd_anr_s_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assignA(1,l4c_phb_bcd_anr_struct,2000/PHB_ANR_SIZE) assign_kal_uint8(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_AV4A_L_PHB_EMAIL_S_S_K_8_
#define _SEND_FUNC_S_K_8_AV4A_L_PHB_EMAIL_S_S_K_8_
	/* MSG_ID_MMI_PHB_STARTUP_READ_EMAIL_IND */
void _send_S_k_8_Av4A_l_phb_email_s_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_v4A_l_phb_email_s_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_v4A_l_phb_email_s_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assignA(1,l4c_phb_email_struct,2000/PHB_EMAIL_SIZE) assign_kal_uint8(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_16_S_L_PHB_EMAIL_S_P_
#define _SEND_FUNC_S_L_RESULT_S_S_K_16_S_L_PHB_EMAIL_S_P_
	/* MSG_ID_MMI_PHB_READ_EMAIL_RSP */
void _send_S_l_result_s_S_k_16_S_l_phb_email_s_p_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_16_S_l_phb_email_s_p__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_16_S_l_phb_email_s_p__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint16(1) assignS(2,l4c_phb_email_struct*) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_A5A_L_PHB_ENTRY_S_S_K_8_
#define _SEND_FUNC_S_K_8_A5A_L_PHB_ENTRY_S_S_K_8_
	/* MSG_ID_MMI_PHB_STARTUP_READ_GAS_IND */
void _send_S_k_8_A5A_l_phb_entry_s_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_5A_l_phb_entry_s_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_5A_l_phb_entry_s_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assignA(1,l4c_phb_entry_struct,5) assign_kal_uint8(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_A1000A_K_8_S_K_8_
#define _SEND_FUNC_A1000A_K_8_S_K_8_
	/* MSG_ID_MMI_PHB_STARTUP_READ_GRP_IND */
void _send_A1000A_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_1000A_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_1000A_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assignA(0,kal_uint8,1000) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_16_S_K_8_
#define _SEND_FUNC_S_L_RESULT_S_S_K_16_S_K_8_
	/* MSG_ID_MMI_PHB_SET_GRP_RSP */
void _send_S_l_result_s_S_k_16_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_16_S_k_8__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_16_S_k_8__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint16(1) assign_kal_uint8(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_8_PS_L_PHB_ENTRY_S_S_K_8_S_L_PHB_ANR_S_S_L_PHB_ANR_S_S_L_PHB_ANR_S_S_L_PHB_EMAIL_S_S_L4_NAME_S_S_K_8_S_K_8_
#define _SEND_FUNC_S_L_RESULT_S_S_K_8_PS_L_PHB_ENTRY_S_S_K_8_S_L_PHB_ANR_S_S_L_PHB_ANR_S_S_L_PHB_ANR_S_S_L_PHB_EMAIL_S_S_L4_NAME_S_S_K_8_S_K_8_
	/* MSG_ID_MMI_PHB_WRITE_USIM_RSP */
void _send_S_l_result_s_S_k_8_PS_l_phb_entry_s_S_k_8_S_l_phb_anr_s_S_l_phb_anr_s_S_l_phb_anr_s_S_l_phb_email_s_S_l4_name_s_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_8_S_l_phb_entry_s_S_k_8_S_l_phb_anr_s_S_l_phb_anr_s_S_l_phb_anr_s_S_l_phb_email_s_S_l4_name_s_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_8_S_l_phb_entry_s_S_k_8_S_l_phb_anr_s_S_l_phb_anr_s_S_l_phb_anr_s_S_l_phb_email_s_S_l4_name_s_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint8(1) assignSP(2,l4c_phb_entry_struct) assign_kal_uint8(3) assignS(4,l4c_phb_anr_struct) assignS(5,l4c_phb_anr_struct) assignS(6,l4c_phb_anr_struct) assignS(7,l4c_phb_email_struct) assignS(8,l4_name_struct) assign_kal_uint8(9) assign_kal_uint8(10) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#endif /* defined(__MOD_PHB__) */
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_SMS_SET_PROFILE_PARAMS_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_S_K_8_S_L_NUMBER_S_S_L4_NAME_S_
#define _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_S_K_8_S_L_NUMBER_S_S_L4_NAME_S_
	/* MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_RSP */
void _send_S_k_bool_S_k_8_S_k_8_S_k_8_S_l_number_s_S_l4_name_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8_S_k_8_S_k_8_S_l_number_s_S_l4_name_s__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8_S_k_8_S_k_8_S_l_number_s_S_l4_name_s__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) assignS(4,l4c_number_struct) assignS(5,l4_name_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_SMS_SET_COMMON_PARAMS_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SMS_GET_COMMON_PARAMS_RSP */
void _send_S_k_bool_S_k_8_S_k_8_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8_S_k_8_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8_S_k_8_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) assign_kal_uint8(4) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_S_K_8_A7A_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_16_S_K_8_A7A_K_8_
	/* MSG_ID_MMI_SMS_SEND_COMMAND_RSP */
void _send_S_k_bool_S_k_16_S_k_8_A7A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16_S_k_8_7A_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16_S_k_8_7A_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) assign_kal_uint8(2) assignA(3,kal_uint8,7) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_S_K_8_S_K_16_S_K_8_A480A_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_16_S_K_8_S_K_16_S_K_8_A480A_K_8_
	/* MSG_ID_MMI_SMS_DEL_MSG_RSP */
void _send_S_k_bool_S_k_16_S_k_8_S_k_16_S_k_8_A480A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16_S_k_8_S_k_16_S_k_8_480A_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16_S_k_8_S_k_16_S_k_8_480A_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) assign_kal_uint8(2) assign_kal_uint16(3) assign_kal_uint8(4) assignA(5,kal_uint8,480) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_S_SMSAL_CONCAT_S_S_K_8_S_K_8_S_K_8_S_K_8_A7A_K_8_S_L_NUMBER_S_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_A7A_K_8_S_K_8_S_K_16_S_K_16_S_K_16_A1A_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_16_S_SMSAL_CONCAT_S_S_K_8_S_K_8_S_K_8_S_K_8_A7A_K_8_S_L_NUMBER_S_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_A7A_K_8_S_K_8_S_K_16_S_K_16_S_K_16_A1A_K_8_
	/* MSG_ID_MMI_SMS_GET_MSG_RSP */
void _send_S_k_bool_S_k_16_S_smsal_concat_s_S_k_8_S_k_8_S_k_8_S_k_8_A7A_k_8_S_l_number_s_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_A7A_k_8_S_k_8_S_k_16_S_k_16_S_k_16_A1A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16_S_smsal_concat_s_S_k_8_S_k_8_S_k_8_S_k_8_7A_k_8_S_l_number_s_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_7A_k_8_S_k_8_S_k_16_S_k_16_S_k_16_1A_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16_S_smsal_concat_s_S_k_8_S_k_8_S_k_8_S_k_8_7A_k_8_S_l_number_s_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_7A_k_8_S_k_8_S_k_16_S_k_16_S_k_16_1A_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) assignS(2,smsal_concat_struct) assign_kal_uint8(3) assign_kal_uint8(4) assign_kal_uint8(5) assign_kal_uint8(6) assignA(7,kal_uint8,7) assignS(8,l4c_number_struct) assignS(9,l4c_number_struct) assign_kal_uint8(10) assign_kal_uint8(11) assign_kal_uint8(12) assign_kal_uint8(13) assign_kal_uint8(14) assignA(15,kal_uint8,7) assign_kal_uint8(16) assign_kal_uint16(17) assign_kal_uint16(18) assign_kal_uint16(19) assignA(20,kal_uint8,1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_S_K_8_A7A_K_8_S_K_8_S_SMSAL_CONCAT_S_
#define _SEND_FUNC_S_K_BOOL_S_K_16_S_K_8_A7A_K_8_S_K_8_S_SMSAL_CONCAT_S_
	/* MSG_ID_MMI_SMS_SEND_MSG_RSP */
void _send_S_k_bool_S_k_16_S_k_8_A7A_k_8_S_k_8_S_smsal_concat_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16_S_k_8_7A_k_8_S_k_8_S_smsal_concat_s__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16_S_k_8_7A_k_8_S_k_8_S_smsal_concat_s__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) assign_kal_uint8(2) assignA(3,kal_uint8,7) assign_kal_uint8(4) assignS(5,smsal_concat_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_S_K_16_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_16_S_K_16_S_K_8_S_K_8_
	/* MSG_ID_MMI_SMS_SET_MSG_RSP */
void _send_S_k_bool_S_k_16_S_k_16_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16_S_k_16_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16_S_k_16_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) assign_kal_uint16(2) assign_kal_uint8(3) assign_kal_uint8(4) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_PS_SMSAL_PREFER_STORAGE_S_
#define _SEND_FUNC_S_K_BOOL_PS_SMSAL_PREFER_STORAGE_S_
	/* MSG_ID_MMI_SMS_SET_PREFERRED_STORAGE_RSP */
void _send_S_k_bool_PS_smsal_prefer_storage_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_smsal_prefer_storage_s__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_smsal_prefer_storage_s__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assignSP(1,smsal_prefer_storage_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_SMSAL_PREFER_STORAGE_S_
#define _SEND_FUNC_S_K_BOOL_S_SMSAL_PREFER_STORAGE_S_
	/* MSG_ID_MMI_SMS_GET_PREFERRED_STORAGE_RSP */
void _send_S_k_bool_S_smsal_prefer_storage_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_smsal_prefer_storage_s__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_smsal_prefer_storage_s__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assignS(1,smsal_prefer_storage_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_S_K_32_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_S_K_32_S_K_16_
	/* MSG_ID_MMI_SMS_REG_PORT_NUM_RSP */
void _send_S_k_bool_S_k_16_S_k_32_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16_S_k_32_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16_S_k_32_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) assignS(2,kal_uint32) assign_kal_uint16(3) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_A7A_K_8_S_L_NUMBER_S_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_16_S_K_16_S_K_16_S_K_8_S_K_8_S_K_8_S_K_32_S_K_16_A1A_K_8_
#define _SEND_FUNC_S_K_8_A7A_K_8_S_L_NUMBER_S_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_16_S_K_16_S_K_16_S_K_8_S_K_8_S_K_8_S_K_32_S_K_16_A1A_K_8_
	/* MSG_ID_MMI_SMS_DELIVER_MSG_IND */
void _send_S_k_8_A7A_k_8_S_l_number_s_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_16_S_k_16_S_k_16_S_k_8_S_k_8_S_k_8_S_k_32_S_k_16_A1A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_7A_k_8_S_l_number_s_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_16_S_k_16_S_k_16_S_k_8_S_k_8_S_k_8_S_k_32_S_k_16_1A_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_7A_k_8_S_l_number_s_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_16_S_k_16_S_k_16_S_k_8_S_k_8_S_k_8_S_k_32_S_k_16_1A_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assignA(1,kal_uint8,7) assignS(2,l4c_number_struct) assignS(3,l4c_number_struct) assign_kal_uint8(4) assign_kal_uint8(5) assign_kal_uint8(6) assign_kal_uint16(7) assign_kal_uint16(8) assign_kal_uint16(9) assign_kal_uint8(10) assign_kal_uint8(11) assign_kal_uint8(12) assignS(13,kal_uint32) assign_kal_uint16(14) assignA(15,kal_uint8,1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_A7A_K_8_A7A_K_8_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_8_S_K_16_A1A_K_8_
#define _SEND_FUNC_S_K_8_A7A_K_8_A7A_K_8_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_8_S_K_16_A1A_K_8_
	/* MSG_ID_MMI_SMS_STATUS_REPORT_IND */
void _send_S_k_8_A7A_k_8_A7A_k_8_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_S_k_16_A1A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_7A_k_8_7A_k_8_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_S_k_16_1A_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_7A_k_8_7A_k_8_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_S_k_16_1A_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assignA(1,kal_uint8,7) assignA(2,kal_uint8,7) assignS(3,l4c_number_struct) assign_kal_uint8(4) assign_kal_uint8(5) assign_kal_uint8(6) assign_kal_uint8(7) assign_kal_uint16(8) assignA(9,kal_uint8,1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_
#define _SEND_FUNC_S_K_8_
	/* MSG_ID_MMI_SMS_MEM_AVAILABLE_IND */
void _send_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_
#define _SEND_FUNC_S_K_8_
	/* MSG_ID_MMI_SMS_MEM_EXCEED_IND */
void _send_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_
#define _SEND_FUNC_S_K_8_
	/* MSG_ID_MMI_SMS_MEM_FULL_IND */
void _send_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_SMS_READY_IND */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_16_S_K_16_S_K_16_S_K_8_S_K_8_S_K_16_AV5A_K_32_PS_L_NUMBER_S_A7A_K_8_A160A_K_8_
#define _SEND_FUNC_S_K_16_S_K_16_S_K_16_S_K_8_S_K_8_S_K_16_AV5A_K_32_PS_L_NUMBER_S_A7A_K_8_A160A_K_8_
	/* MSG_ID_MMI_SMS_APP_DATA_IND */
void _send_S_k_16_S_k_16_S_k_16_S_k_8_S_k_8_S_k_16_Av5A_k_32_PS_l_number_s_A7A_k_8_A160A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_16_S_k_16_S_k_16_S_k_8_S_k_8_S_k_16_v5A_k_32_S_l_number_s_7A_k_8_160A_k_8__struct *p = construct_local_para(sizeof(msg_S_k_16_S_k_16_S_k_16_S_k_8_S_k_8_S_k_16_v5A_k_32_S_l_number_s_7A_k_8_160A_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint16(0) assign_kal_uint16(1) assign_kal_uint16(2) assign_kal_uint8(3) assign_kal_uint8(4) assign_kal_uint16(5) assignA(6,kal_uint32,(sizeof(smsal_concat_struct)+3)/4) assignSP(7,l4c_number_struct) assignA(8,kal_uint8,7) assignA(9,kal_uint8,160) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_BOOL_S_K_16_S_K_16_S_K_16_S_K_16_S_K_16_S_K_16_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_BOOL_S_K_16_S_K_16_S_K_16_S_K_16_S_K_16_S_K_16_S_K_16_
	/* MSG_ID_MMI_SMS_GET_MSG_NUM_RSP */
void _send_S_k_bool_S_k_bool_S_k_16_S_k_16_S_k_16_S_k_16_S_k_16_S_k_16_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_bool_S_k_16_S_k_16_S_k_16_S_k_16_S_k_16_S_k_16_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_bool_S_k_16_S_k_16_S_k_16_S_k_16_S_k_16_S_k_16_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_bool(1) assign_kal_uint16(2) assign_kal_uint16(3) assign_kal_uint16(4) assign_kal_uint16(5) assign_kal_uint16(6) assign_kal_uint16(7) assign_kal_uint16(8) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_
	/* MSG_ID_MMI_SMS_GET_PROFILE_NUM_RSP */
void _send_S_k_bool_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) assign_kal_uint8(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_SMS_ABORT_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_S_K_8_S_K_BOOL_S_K_BOOL_S_K_BOOL_
#define _SEND_FUNC_S_K_8_S_K_8_S_K_8_S_K_BOOL_S_K_BOOL_S_K_BOOL_
	/* MSG_ID_MMI_SMS_MSG_WAITING_IND */
void _send_S_k_8_S_k_8_S_k_8_S_k_bool_S_k_bool_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8_S_k_8_S_k_bool_S_k_bool_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8_S_k_8_S_k_bool_S_k_bool_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_bool(3) assign_kal_bool(4) assign_kal_bool(5) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_SMS_SET_MAILBOX_ADDRESS_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_A2A_L_SMS_MAILBOX_INFO_S_
#define _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_A2A_L_SMS_MAILBOX_INFO_S_
	/* MSG_ID_MMI_SMS_GET_MAILBOX_ADDRESS_RSP */
void _send_S_k_bool_S_k_8_S_k_8_A2A_l_sms_mailbox_info_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8_S_k_8_2A_l_sms_mailbox_info_s__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8_S_k_8_2A_l_sms_mailbox_info_s__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) assign_kal_uint8(2) assignA(3,l4c_sms_mailbox_info_struct,2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_16_S_K_8_A480A_K_8_
#define _SEND_FUNC_S_K_8_S_K_16_S_K_8_A480A_K_8_
	/* MSG_ID_MMI_SMS_SYNC_MSG_IND */
void _send_S_k_8_S_k_16_S_k_8_A480A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_16_S_k_8_480A_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_16_S_k_8_480A_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint16(1) assign_kal_uint8(2) assignA(3,kal_uint8,480) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_SMS_SEND_ABORT_FINISH_IND */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_SMS_STARTUP_READ_NEXT_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_16_A7A_K_8_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_A7A_K_8_S_K_8_S_K_16_S_K_16_S_K_32_S_K_16_A1A_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_16_A7A_K_8_S_L_NUMBER_S_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_A7A_K_8_S_K_8_S_K_16_S_K_16_S_K_32_S_K_16_A1A_K_8_
	/* MSG_ID_MMI_SMS_STARTUP_READ_MSG_IND */
void _send_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_16_A7A_k_8_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_A7A_k_8_S_k_8_S_k_16_S_k_16_S_k_32_S_k_16_A1A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_16_7A_k_8_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_7A_k_8_S_k_8_S_k_16_S_k_16_S_k_32_S_k_16_1A_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_16_7A_k_8_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_7A_k_8_S_k_8_S_k_16_S_k_16_S_k_32_S_k_16_1A_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) assign_kal_uint8(4) assign_kal_uint16(5) assignA(6,kal_uint8,7) assignS(7,l4c_number_struct) assign_kal_uint8(8) assign_kal_uint8(9) assign_kal_uint8(10) assign_kal_uint8(11) assign_kal_uint8(12) assignA(13,kal_uint8,7) assign_kal_uint8(14) assign_kal_uint16(15) assign_kal_uint16(16) assignS(17,kal_uint32) assign_kal_uint16(18) assignA(19,kal_uint8,1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_16_S_K_8_S_K_8_S_K_16_S_K_16_
#define _SEND_FUNC_S_K_8_S_K_16_S_K_8_S_K_8_S_K_16_S_K_16_
	/* MSG_ID_MMI_SMS_COPY_MSG_RSP */
void _send_S_k_8_S_k_16_S_k_8_S_k_8_S_k_16_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_16_S_k_8_S_k_8_S_k_16_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_16_S_k_8_S_k_8_S_k_16_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint16(1) assign_kal_uint8(2) assign_kal_uint8(3) assign_kal_uint16(4) assign_kal_uint16(5) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_SMSAL_INBOX_LIST_S_S_SMSAL_OUTBOX_LIST_S_
#define _SEND_FUNC_S_SMSAL_INBOX_LIST_S_S_SMSAL_OUTBOX_LIST_S_
	/* MSG_ID_MMI_SMS_GET_MSG_LIST_RSP */
void _send_S_smsal_inbox_list_s_S_smsal_outbox_list_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_smsal_inbox_list_s_S_smsal_outbox_list_s__struct *p = construct_local_para(sizeof(msg_S_smsal_inbox_list_s_S_smsal_outbox_list_s__struct),0);

	va_start(args, msg);
	assignS(0,smsal_inbox_list_struct) assignS(1,smsal_outbox_list_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_S_K_8_S_K_16_S_SMSAL_CONCAT_S_
#define _SEND_FUNC_S_K_BOOL_S_K_16_S_K_8_S_K_16_S_SMSAL_CONCAT_S_
	/* MSG_ID_MMI_SMS_SEND_FROM_STORAGE_RSP */
void _send_S_k_bool_S_k_16_S_k_8_S_k_16_S_smsal_concat_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16_S_k_8_S_k_16_S_smsal_concat_s__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16_S_k_8_S_k_16_S_smsal_concat_s__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) assign_kal_uint8(2) assign_kal_uint16(3) assignS(4,smsal_concat_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_S_K_16_
	/* MSG_ID_MMI_SMS_SET_STATUS_RSP */
void _send_S_k_bool_S_k_16_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) assign_kal_uint16(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
/* Data Related Messages */
#if defined(__MOD_DATA__)
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_DF_SET_RLP_PARAMS_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_DF_GET_RLP_PARAMS_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_DF_SET_V120_PARAMS_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_DF_GET_V120_PARAMS_RSP */
void _send_S_k_bool_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) assign_kal_uint8(4) assign_kal_uint8(5) assign_kal_uint8(6) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_DF_SET_COMP_PARAMS_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_S_K_16_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_S_K_16_S_K_8_
	/* MSG_ID_MMI_DF_GET_COMP_PARAMS_RSP */
void _send_S_k_bool_S_k_8_S_k_8_S_k_16_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8_S_k_8_S_k_16_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8_S_k_8_S_k_16_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint16(3) assign_kal_uint8(4) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_DF_SET_BEARER_MODE_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_DF_GET_BEARER_MODE_RSP */
void _send_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_DF_SET_CHAR_FRAMING_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_
	/* MSG_ID_MMI_DF_GET_CHAR_FRAMING_RSP */
void _send_S_k_bool_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) assign_kal_uint8(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#endif /* defined(__MOD_DATA__) */
/* GPRS Related Messages */
#if defined(__MOD_TCM__)
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_PS_ACT_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_PS_ACT_TEST_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_PS_ANSWER_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_PS_SET_AUTO_ANSWER_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_PS_GET_AUTO_ANSWER_RSP */
void _send_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_PS_MODIFY_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_PS_ENTER_DATA_STATE_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_PS_SET_DEFINITION_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_L_PRIM_PDP_INFO_LIST_S_
#define _SEND_FUNC_S_K_BOOL_S_L_PRIM_PDP_INFO_LIST_S_
	/* MSG_ID_MMI_PS_GET_DEFINITION_RSP */
void _send_S_k_bool_S_l_prim_pdp_info_list_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_l_prim_pdp_info_list_s__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_l_prim_pdp_info_list_s__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assignS(1,l4c_prim_pdp_info_list_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_PS_SET_SEC_DEFINITION_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_L_SEC_PDP_INFO_LIST_S_
#define _SEND_FUNC_S_K_BOOL_S_L_SEC_PDP_INFO_LIST_S_
	/* MSG_ID_MMI_PS_GET_SEC_DEFINITION_RSP */
void _send_S_k_bool_S_l_sec_pdp_info_list_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_l_sec_pdp_info_list_s__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_l_sec_pdp_info_list_s__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assignS(1,l4c_sec_pdp_info_list_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_A128A_K_8_
#define _SEND_FUNC_S_K_BOOL_A128A_K_8_
	/* MSG_ID_MMI_PS_GET_PDP_ADDR_RSP */
void _send_S_k_bool_A128A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_128A_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_128A_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assignA(1,kal_uint8,128) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_PS_SET_TFT_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_L_TFT_S_
#define _SEND_FUNC_S_K_BOOL_S_L_TFT_S_
	/* MSG_ID_MMI_PS_GET_TFT_RSP */
void _send_S_k_bool_S_l_tft_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_l_tft_s__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_l_tft_s__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assignS(1,l4c_tft_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_PS_SET_QOS_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_PS_SET_EQOS_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_PS_SEND_DATA_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_
	/* MSG_ID_MMI_PS_GPRS_STATUS_UPDATE_IND */
void _send_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_PS_GET_GPRS_EMPTY_PROFILE_RSP */
void _send_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_L_GPRS_STATISTICS_INFO_S_
#define _SEND_FUNC_S_K_BOOL_S_L_GPRS_STATISTICS_INFO_S_
	/* MSG_ID_MMI_PS_GET_GPRS_DATA_COUNTER_RSP */
void _send_S_k_bool_S_l_gprs_statistics_info_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_l_gprs_statistics_info_s__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_l_gprs_statistics_info_s__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assignS(1,l4c_gprs_statistics_info_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_PS_SET_GPRS_DATA_ACCOUNT_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_L_GPRS_ACCOUNT_INFO_S_
#define _SEND_FUNC_S_K_BOOL_S_L_GPRS_ACCOUNT_INFO_S_
	/* MSG_ID_MMI_PS_GET_GPRS_DATA_ACCOUNT_RSP */
void _send_S_k_bool_S_l_gprs_account_info_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_l_gprs_account_info_s__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_l_gprs_account_info_s__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assignS(1,l4c_gprs_account_info_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_PS_RESET_GPRS_DATA_COUNTER_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#endif /* defined(__MOD_TCM__) */
/* STK/SAT Related Messages */
#if defined(__SAT__)
#ifndef _SEND_FUNC_A5A_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_SAT_ICON_S_S_K_16_S_K_8_P_S_K_8_
#define _SEND_FUNC_A5A_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_SAT_ICON_S_S_K_16_S_K_8_P_S_K_8_
	/* MSG_ID_MMI_SAT_DISPLAY_TEXT_IND */
void _send_A5A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_16_S_k_8_p_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_5A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_16_S_k_8_p_S_k_8__struct *p = construct_local_para(sizeof(msg_5A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_16_S_k_8_p_S_k_8__struct),0);

	va_start(args, msg);
	assignA(0,kal_uint8,5) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) assign_kal_uint8(4) assignS(5,sat_icon_struct) assign_kal_uint16(6) assignS(7,kal_uint8*) assign_kal_uint8(8) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_SAT_DISPLAY_TEXT_RES_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_A5A_K_8_S_K_8_S_K_8_S_K_8_S_SAT_ICON_S_S_K_16_S_K_8_P_S_K_8_
#define _SEND_FUNC_A5A_K_8_S_K_8_S_K_8_S_K_8_S_SAT_ICON_S_S_K_16_S_K_8_P_S_K_8_
	/* MSG_ID_MMI_SAT_GET_INKEY_IND */
void _send_A5A_k_8_S_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_16_S_k_8_p_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_5A_k_8_S_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_16_S_k_8_p_S_k_8__struct *p = construct_local_para(sizeof(msg_5A_k_8_S_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_16_S_k_8_p_S_k_8__struct),0);

	va_start(args, msg);
	assignA(0,kal_uint8,5) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) assignS(4,sat_icon_struct) assign_kal_uint16(5) assignS(6,kal_uint8*) assign_kal_uint8(7) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_SAT_GET_INKEY_RES_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_A5A_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_S_K_16_S_K_8_P_S_K_8_S_K_16_S_K_8_P_S_K_8_
#define _SEND_FUNC_A5A_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_S_K_16_S_K_8_P_S_K_8_S_K_16_S_K_8_P_S_K_8_
	/* MSG_ID_MMI_SAT_GET_INPUT_IND */
void _send_A5A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_S_k_16_S_k_8_p_S_k_8_S_k_16_S_k_8_p_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_5A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_S_k_16_S_k_8_p_S_k_8_S_k_16_S_k_8_p_S_k_8__struct *p = construct_local_para(sizeof(msg_5A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_S_k_16_S_k_8_p_S_k_8_S_k_16_S_k_8_p_S_k_8__struct),0);

	va_start(args, msg);
	assignA(0,kal_uint8,5) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) assign_kal_uint8(4) assignS(5,sat_icon_struct) assign_kal_uint8(6) assign_kal_uint8(7) assign_kal_uint16(8) assignS(9,kal_uint8*) assign_kal_uint8(10) assign_kal_uint16(11) assignS(12,kal_uint8*) assign_kal_uint8(13) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_SAT_GET_INPUT_RES_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_A5A_K_8_S_K_8_S_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_16_S_K_8_P_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_P_
#define _SEND_FUNC_A5A_K_8_S_K_8_S_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_16_S_K_8_P_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_P_
	/* MSG_ID_MMI_SAT_SETUP_MENU_IND */
void _send_A5A_k_8_S_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_16_S_k_8_p_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_5A_k_8_S_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_16_S_k_8_p_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p__struct *p = construct_local_para(sizeof(msg_5A_k_8_S_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_16_S_k_8_p_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p__struct),0);

	va_start(args, msg);
	assignA(0,kal_uint8,5) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) assignS(4,sat_icon_struct) assign_kal_uint8(5) assign_kal_uint8(6) assignS(7,kal_uint8*) assign_kal_uint8(8) assign_kal_uint16(9) assignS(10,kal_uint8*) assign_kal_uint8(11) assignS(12,kal_uint8*) assign_kal_uint8(13) assign_kal_uint8(14) assignS(15,kal_uint8*) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_SAT_SETUP_MENU_RES_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_A5A_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_16_S_K_8_P_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_P_
#define _SEND_FUNC_A5A_K_8_S_K_8_S_K_8_S_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_16_S_K_8_P_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_P_
	/* MSG_ID_MMI_SAT_SELECT_ITEM_IND */
void _send_A5A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_16_S_k_8_p_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_p_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_5A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_16_S_k_8_p_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_p__struct *p = construct_local_para(sizeof(msg_5A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_16_S_k_8_p_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_p__struct),0);

	va_start(args, msg);
	assignA(0,kal_uint8,5) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) assign_kal_uint8(4) assignS(5,sat_icon_struct) assign_kal_uint8(6) assign_kal_uint8(7) assign_kal_uint8(8) assign_kal_uint8(9) assignS(10,kal_uint8*) assign_kal_uint8(11) assign_kal_uint16(12) assignS(13,kal_uint8*) assign_kal_uint8(14) assign_kal_uint8(15) assignS(16,kal_uint8*) assign_kal_uint8(17) assignS(18,kal_uint8*) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_SAT_SELECT_ITEM_RES_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_A5A_K_8_S_K_8_S_K_32_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_P_S_K_8_S_K_8_
#define _SEND_FUNC_A5A_K_8_S_K_8_S_K_32_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_P_S_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_PLAY_TONE_IND */
void _send_A5A_k_8_S_k_8_S_k_32_S_k_8_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_5A_k_8_S_k_8_S_k_32_S_k_8_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_5A_k_8_S_k_8_S_k_32_S_k_8_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assignA(0,kal_uint8,5) assign_kal_uint8(1) assignS(2,kal_uint32) assign_kal_uint8(3) assignS(4,sat_icon_struct) assign_kal_uint8(5) assignS(6,kal_uint8*) assign_kal_uint8(7) assign_kal_uint8(8) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_SAT_PLAY_TONE_RES_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_
#define _SEND_FUNC_S_K_8_
	/* MSG_ID_MMI_SAT_MENU_SELECT_RSP */
void _send_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_SAT_EVDL_IDLE_SCREEN_AVAILABLE_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_SAT_LANGUAGE_SELECTION_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_SAT_EVDL_BROWSER_TERMINATION_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_A5A_K_8_S_K_8_S_K_32_S_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_SAT_ICON_S_S_K_8_A13A_K_8_S_K_8_A21A_K_8_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_P_S_K_8_
#define _SEND_FUNC_A5A_K_8_S_K_8_S_K_32_S_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_SAT_ICON_S_S_K_8_A13A_K_8_S_K_8_A21A_K_8_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_P_S_K_8_
	/* MSG_ID_MMI_SAT_CALL_SETUP_IND */
void _send_A5A_k_8_S_k_8_S_k_32_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_sat_icon_s_S_k_8_A13A_k_8_S_k_8_A21A_k_8_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_5A_k_8_S_k_8_S_k_32_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_sat_icon_s_S_k_8_13A_k_8_S_k_8_21A_k_8_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p_S_k_8__struct *p = construct_local_para(sizeof(msg_5A_k_8_S_k_8_S_k_32_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_sat_icon_s_S_k_8_13A_k_8_S_k_8_21A_k_8_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p_S_k_8__struct),0);

	va_start(args, msg);
	assignA(0,kal_uint8,5) assign_kal_uint8(1) assignS(2,kal_uint32) assign_kal_uint8(3) assign_kal_uint8(4) assignS(5,sat_icon_struct) assign_kal_uint8(6) assignS(7,sat_icon_struct) assign_kal_uint8(8) assignA(9,kal_uint8,13) assign_kal_uint8(10) assignA(11,kal_uint8,21) assign_kal_uint8(12) assign_kal_uint8(13) assignS(14,kal_uint8*) assign_kal_uint8(15) assign_kal_uint8(16) assignS(17,kal_uint8*) assign_kal_uint8(18) assign_kal_uint8(19) assignS(20,kal_uint8*) assign_kal_uint8(21) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_
#define _SEND_FUNC_S_L_RESULT_S_S_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_CALL_SETUP_STAGE1_RSP */
void _send_S_l_result_s_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint8(1) assign_kal_uint8(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_SAT_CALL_SETUP_STAGE2_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_A5A_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_A41A_K_8_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_P_
#define _SEND_FUNC_A5A_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_A41A_K_8_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_P_
	/* MSG_ID_MMI_SAT_SEND_SMS_IND */
void _send_A5A_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_A41A_k_8_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_5A_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_41A_k_8_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p__struct *p = construct_local_para(sizeof(msg_5A_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_41A_k_8_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p__struct),0);

	va_start(args, msg);
	assignA(0,kal_uint8,5) assign_kal_uint8(1) assignS(2,sat_icon_struct) assign_kal_uint8(3) assign_kal_uint8(4) assignA(5,kal_uint8,41) assign_kal_uint8(6) assign_kal_uint8(7) assignS(8,kal_uint8*) assign_kal_uint8(9) assign_kal_uint8(10) assignS(11,kal_uint8*) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_16_
#define _SEND_FUNC_S_K_8_S_K_16_
	/* MSG_ID_MMI_SAT_SEND_SMS_STAGE1_RSP */
void _send_S_k_8_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_SAT_SEND_SMS_STAGE2_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_A5A_K_8_S_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_P_
#define _SEND_FUNC_A5A_K_8_S_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_P_
	/* MSG_ID_MMI_SAT_SEND_SS_IND */
void _send_A5A_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_5A_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p__struct *p = construct_local_para(sizeof(msg_5A_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p__struct),0);

	va_start(args, msg);
	assignA(0,kal_uint8,5) assign_kal_uint8(1) assign_kal_uint8(2) assignS(3,sat_icon_struct) assign_kal_uint8(4) assign_kal_uint8(5) assignS(6,kal_uint8*) assign_kal_uint8(7) assign_kal_uint8(8) assignS(9,kal_uint8*) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_A255A_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_A255A_K_8_
	/* MSG_ID_MMI_SAT_SEND_SS_STAGE1_RSP */
void _send_S_k_8_S_k_8_A255A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8_255A_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8_255A_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) assignA(2,kal_uint8,255) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_SAT_SEND_SS_STAGE2_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_A5A_K_8_S_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_P_S_K_8_
#define _SEND_FUNC_A5A_K_8_S_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_P_S_K_8_
	/* MSG_ID_MMI_SAT_SEND_USSD_IND */
void _send_A5A_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_5A_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p_S_k_8__struct *p = construct_local_para(sizeof(msg_5A_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p_S_k_8__struct),0);

	va_start(args, msg);
	assignA(0,kal_uint8,5) assign_kal_uint8(1) assign_kal_uint8(2) assignS(3,sat_icon_struct) assign_kal_uint8(4) assign_kal_uint8(5) assignS(6,kal_uint8*) assign_kal_uint8(7) assign_kal_uint8(8) assignS(9,kal_uint8*) assign_kal_uint8(10) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_A255A_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_A255A_K_8_
	/* MSG_ID_MMI_SAT_SEND_USSD_STAGE1_RSP */
void _send_S_k_8_S_k_8_A255A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8_255A_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8_255A_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) assignA(2,kal_uint8,255) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_SAT_SEND_USSD_STAGE2_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_A41A_K_8_S_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_A41A_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_MMI_INFO_IND */
void _send_S_k_8_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_A41A_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_41A_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_41A_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) assign_kal_uint8(2) assignS(3,kal_uint8*) assign_kal_uint8(4) assign_kal_uint8(5) assignA(6,kal_uint8,41) assign_kal_uint8(7) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_SAT_SETUP_IDLE_DISPLAY_RES_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_A5A_K_8_S_K_8_S_SAT_ICON_S_S_K_16_S_K_8_P_S_K_8_
#define _SEND_FUNC_A5A_K_8_S_K_8_S_SAT_ICON_S_S_K_16_S_K_8_P_S_K_8_
	/* MSG_ID_MMI_SAT_SETUP_IDLE_DISPLAY_IND */
void _send_A5A_k_8_S_k_8_S_sat_icon_s_S_k_16_S_k_8_p_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_5A_k_8_S_k_8_S_sat_icon_s_S_k_16_S_k_8_p_S_k_8__struct *p = construct_local_para(sizeof(msg_5A_k_8_S_k_8_S_sat_icon_s_S_k_16_S_k_8_p_S_k_8__struct),0);

	va_start(args, msg);
	assignA(0,kal_uint8,5) assign_kal_uint8(1) assignS(2,sat_icon_struct) assign_kal_uint16(3) assignS(4,kal_uint8*) assign_kal_uint8(5) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_A5A_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_S_K_8_P_
#define _SEND_FUNC_A5A_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_S_K_8_P_
	/* MSG_ID_MMI_SAT_RUN_AT_COMMAND_IND */
void _send_A5A_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_S_k_8_p_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_5A_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_S_k_8_p__struct *p = construct_local_para(sizeof(msg_5A_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_S_k_8_p__struct),0);

	va_start(args, msg);
	assignA(0,kal_uint8,5) assign_kal_uint8(1) assignS(2,sat_icon_struct) assign_kal_uint8(3) assignS(4,kal_uint8*) assign_kal_uint8(5) assign_kal_uint8(6) assign_kal_uint8(7) assignS(8,kal_uint8*) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_A5A_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_S_K_8_P_
#define _SEND_FUNC_A5A_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_S_K_8_P_
	/* MSG_ID_MMI_SAT_SEND_DTMF_IND */
void _send_A5A_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_S_k_8_p_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_5A_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_S_k_8_p__struct *p = construct_local_para(sizeof(msg_5A_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_S_k_8_p__struct),0);

	va_start(args, msg);
	assignA(0,kal_uint8,5) assign_kal_uint8(1) assignS(2,sat_icon_struct) assign_kal_uint8(3) assignS(4,kal_uint8*) assign_kal_uint8(5) assign_kal_uint8(6) assign_kal_uint8(7) assignS(8,kal_uint8*) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_SEND_DTMF_STAGE1_RSP */
void _send_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_SAT_SEND_DTMF_STAGE2_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_SAT_ABORT_DTMF_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_SAT_LANG_NOTIFY_RES_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_A5A_K_8_S_K_8_A2A_K_8_
#define _SEND_FUNC_A5A_K_8_S_K_8_A2A_K_8_
	/* MSG_ID_MMI_SAT_LANG_NOTIFY_IND */
void _send_A5A_k_8_S_k_8_A2A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_5A_k_8_S_k_8_2A_k_8__struct *p = construct_local_para(sizeof(msg_5A_k_8_S_k_8_2A_k_8__struct),0);

	va_start(args, msg);
	assignA(0,kal_uint8,5) assign_kal_uint8(1) assignA(2,kal_uint8,2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_SAT_LAUNCH_BROWSER_RES_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_A5A_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_A10A_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_P_S_K_16_S_K_8_P_S_K_8_
#define _SEND_FUNC_A5A_K_8_S_K_8_S_SAT_ICON_S_S_K_8_S_K_8_A10A_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_P_S_K_16_S_K_8_P_S_K_8_
	/* MSG_ID_MMI_SAT_LAUNCH_BROWSER_IND */
void _send_A5A_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_A10A_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_p_S_k_16_S_k_8_p_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_5A_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_10A_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_p_S_k_16_S_k_8_p_S_k_8__struct *p = construct_local_para(sizeof(msg_5A_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_10A_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_p_S_k_16_S_k_8_p_S_k_8__struct),0);

	va_start(args, msg);
	assignA(0,kal_uint8,5) assign_kal_uint8(1) assignS(2,sat_icon_struct) assign_kal_uint8(3) assign_kal_uint8(4) assignA(5,kal_uint8,10) assign_kal_uint8(6) assignS(7,kal_uint8*) assign_kal_uint8(8) assign_kal_uint8(9) assign_kal_uint8(10) assignS(11,kal_uint8*) assign_kal_uint8(12) assignS(13,kal_uint8*) assign_kal_uint16(14) assignS(15,kal_uint8*) assign_kal_uint8(16) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_S_K_8_A120A_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_S_K_8_A120A_K_8_
	/* MSG_ID_MMI_SAT_SIM_FILE_CHANGE_IND */
void _send_S_k_8_S_k_8_S_k_8_A120A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8_S_k_8_120A_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8_S_k_8_120A_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) assign_kal_uint8(2) assignA(3,kal_uint8,120) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#endif /* defined(__SAT__) */
/* STK_CE */
#if defined(__SATCE__)
#ifndef _SEND_FUNC_A5A_K_8_S_K_BOOL_S_SAT_ICON_S_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_
#define _SEND_FUNC_A5A_K_8_S_K_BOOL_S_SAT_ICON_S_S_K_8_S_K_8_S_K_8_P_S_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_OPEN_CHANNEL_IND */
void _send_A5A_k_8_S_k_bool_S_sat_icon_s_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_5A_k_8_S_k_bool_S_sat_icon_s_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_5A_k_8_S_k_bool_S_sat_icon_s_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assignA(0,kal_uint8,5) assign_kal_bool(1) assignS(2,sat_icon_struct) assign_kal_uint8(3) assign_kal_uint8(4) assignS(5,kal_uint8*) assign_kal_uint8(6) assign_kal_uint8(7) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_
#define _SEND_FUNC_S_K_8_
	/* MSG_ID_MMI_SAT_OPEN_CHANNEL_RSP */
void _send_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_A5A_K_8_S_K_BOOL_S_SAT_ICON_S_S_K_8_S_K_8_P_S_K_8_S_K_8_
#define _SEND_FUNC_A5A_K_8_S_K_BOOL_S_SAT_ICON_S_S_K_8_S_K_8_P_S_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_CLOSE_CHANNEL_IND */
void _send_A5A_k_8_S_k_bool_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_5A_k_8_S_k_bool_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_5A_k_8_S_k_bool_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assignA(0,kal_uint8,5) assign_kal_bool(1) assignS(2,sat_icon_struct) assign_kal_uint8(3) assignS(4,kal_uint8*) assign_kal_uint8(5) assign_kal_uint8(6) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_
#define _SEND_FUNC_S_K_8_
	/* MSG_ID_MMI_SAT_CLOSE_CHANNEL_RSP */
void _send_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_A5A_K_8_S_K_BOOL_S_SAT_ICON_S_S_K_8_S_K_8_P_S_K_8_S_K_8_
#define _SEND_FUNC_A5A_K_8_S_K_BOOL_S_SAT_ICON_S_S_K_8_S_K_8_P_S_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_SEND_DATA_IND */
void _send_A5A_k_8_S_k_bool_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_5A_k_8_S_k_bool_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_5A_k_8_S_k_bool_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assignA(0,kal_uint8,5) assign_kal_bool(1) assignS(2,sat_icon_struct) assign_kal_uint8(3) assignS(4,kal_uint8*) assign_kal_uint8(5) assign_kal_uint8(6) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_A5A_K_8_S_K_8_S_K_8_
#define _SEND_FUNC_A5A_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_SEND_DATA_RSP */
void _send_A5A_k_8_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_5A_k_8_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_5A_k_8_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assignA(0,kal_uint8,5) assign_kal_uint8(1) assign_kal_uint8(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_A5A_K_8_S_K_BOOL_S_SAT_ICON_S_S_K_8_S_K_8_P_S_K_8_S_K_8_
#define _SEND_FUNC_A5A_K_8_S_K_BOOL_S_SAT_ICON_S_S_K_8_S_K_8_P_S_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_RECV_DATA_IND */
void _send_A5A_k_8_S_k_bool_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_5A_k_8_S_k_bool_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_5A_k_8_S_k_bool_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assignA(0,kal_uint8,5) assign_kal_bool(1) assignS(2,sat_icon_struct) assign_kal_uint8(3) assignS(4,kal_uint8*) assign_kal_uint8(5) assign_kal_uint8(6) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_A5A_K_8_S_K_8_S_K_8_
#define _SEND_FUNC_A5A_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_SAT_RECV_DATA_RSP */
void _send_A5A_k_8_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_5A_k_8_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_5A_k_8_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assignA(0,kal_uint8,5) assign_kal_uint8(1) assign_kal_uint8(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_
#define _SEND_FUNC_S_K_8_
	/* MSG_ID_MMI_SAT_NOTIFY_MMI_IND */
void _send_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#endif /* defined(__SATCE__) */
#ifndef _SEND_FUNC_S_K_16_S_K_16_S_K_8_S_K_8_S_K_8_S_K_16_A1A_K_8_
#define _SEND_FUNC_S_K_16_S_K_16_S_K_8_S_K_8_S_K_8_S_K_16_A1A_K_8_
	/* MSG_ID_MMI_CB_MSG_IND */
void _send_S_k_16_S_k_16_S_k_8_S_k_8_S_k_8_S_k_16_A1A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_16_S_k_16_S_k_8_S_k_8_S_k_8_S_k_16_1A_k_8__struct *p = construct_local_para(sizeof(msg_S_k_16_S_k_16_S_k_8_S_k_8_S_k_8_S_k_16_1A_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint16(0) assign_kal_uint16(1) assign_kal_uint8(2) assign_kal_uint8(3) assign_kal_uint8(4) assign_kal_uint16(5) assignA(6,kal_uint8,1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_CB_SUBSCRIBE_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_SMS_SET_CB_MODE_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_S_K_8_S_K_8_S_L_CB_INFO_S_
#define _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_S_K_8_S_K_8_S_L_CB_INFO_S_
	/* MSG_ID_MMI_SMS_GET_CB_MODE_RSP */
void _send_S_k_bool_S_k_8_S_k_8_S_k_8_S_k_8_S_l_cb_info_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8_S_k_8_S_k_8_S_k_8_S_l_cb_info_s__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8_S_k_8_S_k_8_S_k_8_S_l_cb_info_s__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) assign_kal_uint8(4) assignS(5,l4c_cb_info_struct) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
/* Engineer Mode-UEM */
#if defined(__MOD_UEM__)
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EM_SET_GAIN_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#endif /* defined(__MOD_UEM__) */
/* Engineer Mode */
#if defined(__EM_MODE__)
#ifndef _SEND_FUNC_S_K_8_S_K_32_S_PEER_BUFF_S_P_
#define _SEND_FUNC_S_K_8_S_K_32_S_PEER_BUFF_S_P_
	/* MSG_ID_MMI_EM_STATUS_IND */
void _send_S_k_8_S_k_32_S_peer_buff_s_p_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_32_S_peer_buff_s_p__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_32_S_peer_buff_s_p__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assignS(1,kal_uint32) assignS(2,peer_buff_struct*) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_S_K_32_
#define _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_S_K_32_
	/* MSG_ID_MMI_EM_START_RSP */
void _send_S_k_bool_S_k_8_S_k_8_S_k_32_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8_S_k_8_S_k_32__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8_S_k_8_S_k_32__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) assign_kal_uint8(2) assignS(3,kal_uint32) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_S_K_32_
#define _SEND_FUNC_S_K_BOOL_S_K_8_S_K_8_S_K_32_
	/* MSG_ID_MMI_EM_STOP_RSP */
void _send_S_k_bool_S_k_8_S_k_8_S_k_32_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8_S_k_8_S_k_32__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8_S_k_8_S_k_32__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) assign_kal_uint8(2) assignS(3,kal_uint32) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EM_SET_CELL_ID_LOCK_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#endif /* defined(__EM_MODE__) */
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EM_KEYPAD_EVENT_OUTPUT_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_
#define _SEND_FUNC_S_K_8_
	/* MSG_ID_MMI_EM_LCM_TEST_IND */
void _send_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EM_KEYPAD_EVENT_ACT_IND */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_FACTORY_TEST_IND */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_A10A_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_S_K_8_S_K_8_S_K_8_A10A_K_8_
	/* MSG_ID_MMI_SET_MMI_DEFAULT_PROF_IND */
void _send_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_A10A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_10A_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_10A_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) assign_kal_uint8(4) assignA(5,kal_uint8,10) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_UPDATE_MMI_DEFAULT_PROF_VALUE_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_EM_CELL_RESEL_SUSPEND_RSP */
void _send_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_EM_CELL_RESEL_RESUME_RSP */
void _send_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_BOOL_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_BOOL_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_EM_GET_CELL_LOCK_RSP */
void _send_S_k_bool_S_k_bool_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_bool_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_bool_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_bool(1) assign_kal_bool(2) assign_kal_uint16(3) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EM_SET_CELL_LOCK_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_16_S_K_16_S_K_16_
#define _SEND_FUNC_S_K_8_S_K_16_S_K_16_S_K_16_
	/* MSG_ID_MMI_EM_RGB_TEST_REQ_IND */
void _send_S_k_8_S_k_16_S_k_16_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_16_S_k_16_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_16_S_k_16_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint16(1) assign_kal_uint16(2) assign_kal_uint16(3) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EM_NW_EVENT_NOTIFY_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_32_
#define _SEND_FUNC_S_K_8_S_K_32_
	/* MSG_ID_MMI_EM_NW_EVENT_NOTIFY_IND */
void _send_S_k_8_S_k_32_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_32__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_32__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assignS(1,kal_uint32) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_EM_FEATURE_COMMAND_RSP */
void _send_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
/* Audio Task - Voice Memo(via FS) */
#if defined(__FS_ON__)
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_VM_PLAY_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_VM_DEL_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_VM_APPEND_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_VM_RENAME_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_
#define _SEND_FUNC_S_K_8_
	/* MSG_ID_MMI_VM_PLAY_FINISH_IND */
void _send_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_16_AV6A_K_WCHAR_S_K_BOOL_S_K_32_
#define _SEND_FUNC_S_K_16_AV6A_K_WCHAR_S_K_BOOL_S_K_32_
	/* MSG_ID_MMI_VM_GET_INFO_RSP */
void _send_S_k_16_Av6A_k_wchar_S_k_bool_S_k_32_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_16_v6A_k_wchar_S_k_bool_S_k_32__struct *p = construct_local_para(sizeof(msg_S_k_16_v6A_k_wchar_S_k_bool_S_k_32__struct),0);

	va_start(args, msg);
	assign_kal_uint16(0) assignA(1,kal_wchar,MAX_VM_FILE_NAME*MAX_NUM_OF_VM_LIST) assign_kal_bool(2) assignS(3,kal_uint32) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_A20A_K_WCHAR_
#define _SEND_FUNC_S_L_RESULT_S_A20A_K_WCHAR_
	/* MSG_ID_MMI_VM_STOP_RSP */
void _send_S_l_result_s_A20A_k_wchar_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_20A_k_wchar__struct *p = construct_local_para(sizeof(msg_S_l_result_s_20A_k_wchar__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assignA(1,kal_wchar,20) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_VM_ABORT_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_A20A_K_WCHAR_
#define _SEND_FUNC_S_L_RESULT_S_A20A_K_WCHAR_
	/* MSG_ID_MMI_VM_PAUSE_RSP */
void _send_S_l_result_s_A20A_k_wchar_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_20A_k_wchar__struct *p = construct_local_para(sizeof(msg_S_l_result_s_20A_k_wchar__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assignA(1,kal_wchar,20) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_VM_RESUME_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_16_
#define _SEND_FUNC_S_K_BOOL_S_K_16_
	/* MSG_ID_MMI_VM_RECORD_RSP */
void _send_S_k_bool_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_A20A_K_WCHAR_
#define _SEND_FUNC_S_K_8_A20A_K_WCHAR_
	/* MSG_ID_MMI_VM_RECORD_FINISH_IND */
void _send_S_k_8_A20A_k_wchar_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_20A_k_wchar__struct *p = construct_local_para(sizeof(msg_S_k_8_20A_k_wchar__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assignA(1,kal_wchar,20) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#endif /* defined(__FS_ON__) */
#ifndef _SEND_FUNC_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_
	/* MSG_ID_MMI_CPHS_DISPLAY_CFU_IND */
void _send_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_A17A_K_8_S_K_8_A21A_K_8_S_K_8_A11A_K_8_S_K_8_A2A_L4CSMU_ADDR_S_S_K_8_A20A_L4CSMU_INFO_NUM_S_S_K_8_A22A_K_8_S_K_8_A5A_K_8_S_K_8_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_A17A_K_8_S_K_8_A21A_K_8_S_K_8_A11A_K_8_S_K_8_A2A_L4CSMU_ADDR_S_S_K_8_A20A_L4CSMU_INFO_NUM_S_S_K_8_A22A_K_8_S_K_8_A5A_K_8_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_CPHS_MMI_INFO_IND */
void _send_S_k_8_S_k_8_A17A_k_8_S_k_8_A21A_k_8_S_k_8_A11A_k_8_S_k_8_A2A_l4csmu_addr_s_S_k_8_A20A_l4csmu_info_num_s_S_k_8_A22A_k_8_S_k_8_A5A_k_8_S_k_8_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8_17A_k_8_S_k_8_21A_k_8_S_k_8_11A_k_8_S_k_8_2A_l4csmu_addr_s_S_k_8_20A_l4csmu_info_num_s_S_k_8_22A_k_8_S_k_8_5A_k_8_S_k_8_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8_17A_k_8_S_k_8_21A_k_8_S_k_8_11A_k_8_S_k_8_2A_l4csmu_addr_s_S_k_8_20A_l4csmu_info_num_s_S_k_8_22A_k_8_S_k_8_5A_k_8_S_k_8_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) assignA(2,kal_uint8,17) assign_kal_uint8(3) assignA(4,kal_uint8,21) assign_kal_uint8(5) assignA(6,kal_uint8,11) assign_kal_uint8(7) assignA(8,l4csmu_addr_struct,2) assign_kal_uint8(9) assignA(10,l4csmu_info_num_struct,20) assign_kal_uint8(11) assignA(12,kal_uint8,22) assign_kal_uint8(13) assignA(14,kal_uint8,5) assign_kal_uint8(15) assign_kal_uint8(16) assign_kal_uint8(17) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_16_
#define _SEND_FUNC_S_K_8_S_K_16_
	/* MSG_ID_MMI_CPHS_UPDATE_ALS_RSP */
void _send_S_k_8_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint16(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_
#define _SEND_FUNC_S_K_8_
	/* MSG_ID_MMI_CPHS_DISPLAY_ALS_IND */
void _send_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_S_K_8_S_K_8_S_K_16_
#define _SEND_FUNC_S_K_8_S_K_8_S_K_8_S_K_8_S_K_16_
	/* MSG_ID_WAP_START_DTMF_RSP */
void _send_S_k_8_S_k_8_S_k_8_S_k_8_S_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8_S_k_8_S_k_8_S_k_16__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8_S_k_8_S_k_8_S_k_16__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) assign_kal_uint8(2) assign_kal_uint8(3) assign_kal_uint16(4) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_8_
#define _SEND_FUNC_S_L_RESULT_S_S_K_8_
	/* MSG_ID_WAP_DIAL_RSP */
void _send_S_l_result_s_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_8__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_8__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_L_RESULT_S_S_K_16_A15A_L_PHB_ENTRY_S_
#define _SEND_FUNC_S_L_RESULT_S_S_K_16_A15A_L_PHB_ENTRY_S_
	/* MSG_ID_WAP_SET_ENTRY_RSP */
void _send_S_l_result_s_S_k_16_A15A_l_phb_entry_s_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_l_result_s_S_k_16_15A_l_phb_entry_s__struct *p = construct_local_para(sizeof(msg_S_l_result_s_S_k_16_15A_l_phb_entry_s__struct),0);

	va_start(args, msg);
	assignS(0,l4c_result_struct) assign_kal_uint16(1) assignA(2,l4c_phb_entry_struct,15) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_
#define _SEND_FUNC_S_K_8_
	/* MSG_ID_WAP_AUTO_DTMF_COMPLETE_IND */
void _send_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
/* IrDA */
#if defined(__IRDA_SUPPORT__)
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_IRDA_OPEN_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_IRDA_CLOSE_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#endif /* defined(__IRDA_SUPPORT__) */
/* USB */
#if defined(__USB_ENABLE__)
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_S_K_32_
#define _SEND_FUNC_S_K_BOOL_S_K_8_S_K_32_
	/* MSG_ID_MMI_EQ_USBCONFIG_RSP */
void _send_S_k_bool_S_k_8_S_k_32_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8_S_k_32__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8_S_k_32__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) assignS(2,kal_uint32) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_
#define _SEND_FUNC_S_K_8_
	/* MSG_ID_MMI_EQ_USBDETECT_IND */
void _send_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_USBUART_SWITCH_PORT_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#endif /* defined(__USB_ENABLE__) */
#ifndef _SEND_FUNC_S_K_8_
#define _SEND_FUNC_S_K_8_
	/* MSG_ID_MMI_EQ_DATA_DL_FILELIST_INFO_REQ_IND */
void _send_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_DATA_DL_FILELIST_REPORT_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_A520A_K_8_S_K_8_
#define _SEND_FUNC_S_K_8_A520A_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_DATA_DL_FILE_MODIFY_REQ_IND */
void _send_S_k_8_A520A_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_520A_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_520A_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assignA(1,kal_uint8,520) assign_kal_uint8(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_DATA_DL_FILE_MODIFY_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_A520A_K_8_S_K_8_
#define _SEND_FUNC_S_K_8_A520A_K_8_S_K_8_
	/* MSG_ID_MMI_EQ_DATA_DL_EXECUTE_REQ_IND */
void _send_S_k_8_A520A_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_520A_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_520A_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assignA(1,kal_uint8,520) assign_kal_uint8(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_DATA_DL_EXECUTE_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_
	/* MSG_ID_WAP_MMC_READ_FOLDER_STATUS_REQ_IND */
void _send_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_A100A_K_8_
#define _SEND_FUNC_A100A_K_8_
	/* MSG_ID_WAP_MMC_UPLOAD_MSG_REQ_IND */
void _send_A100A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_100A_k_8__struct *p = construct_local_para(sizeof(msg_100A_k_8__struct),0);

	va_start(args, msg);
	assignA(0,kal_uint8,100) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_32_S_K_8_
#define _SEND_FUNC_S_K_32_S_K_8_
	/* MSG_ID_WAP_MMC_DELETE_MSG_REQ_IND */
void _send_S_k_32_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_32_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_32_S_k_8__struct),0);

	va_start(args, msg);
	assignS(0,kal_uint32) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_QUERY_DATE_TIME_FORMAT_REQ_IND */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_POWER_RESET_IND */
void _send_S_k_8_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) assign_kal_uint8(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_A16A_K_8_
#define _SEND_FUNC_A16A_K_8_
	/* MSG_ID_MMI_FACTORY_RESTORE_REQ_IND */
void _send_A16A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_16A_k_8__struct *p = construct_local_para(sizeof(msg_16A_k_8__struct),0);

	va_start(args, msg);
	assignA(0,kal_uint8,16) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_S_K_16_A50A_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_S_K_16_A50A_K_8_
	/* MSG_ID_MMI_EQ_VCARD_REQ_IND */
void _send_S_k_8_S_k_8_S_k_16_A50A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8_S_k_16_50A_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8_S_k_16_50A_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) assign_kal_uint16(2) assignA(3,kal_uint8,50) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_16_A50A_K_8_
#define _SEND_FUNC_S_K_8_S_K_16_A50A_K_8_
	/* MSG_ID_MMI_EQ_VCALENDAR_REQ_IND */
void _send_S_k_8_S_k_16_A50A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_16_50A_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_16_50A_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint16(1) assignA(2,kal_uint8,50) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_EQ_STR_ENABLE_REQ_IND */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_16_A250A_K_8_
#define _SEND_FUNC_S_K_16_A250A_K_8_
	/* MSG_ID_MMI_EQ_STR_REQ_IND */
void _send_S_k_16_A250A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_16_250A_k_8__struct *p = construct_local_para(sizeof(msg_S_k_16_250A_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint16(0) assignA(1,kal_uint8,250) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_K_8_S_K_BOOL_S_K_8_A50A_K_8_S_K_8_S_K_8_
#define _SEND_FUNC_S_K_8_S_K_8_S_K_BOOL_S_K_8_A50A_K_8_S_K_8_S_K_8_
	/* MSG_ID_MMI_UCM_AT_REQ_IND */
void _send_S_k_8_S_k_8_S_k_bool_S_k_8_A50A_k_8_S_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_k_8_S_k_bool_S_k_8_50A_k_8_S_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_8_S_k_8_S_k_bool_S_k_8_50A_k_8_S_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assign_kal_uint8(1) assign_kal_bool(2) assign_kal_uint8(3) assignA(4,kal_uint8,50) assign_kal_uint8(5) assign_kal_uint8(6) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_WCHAR_P_S_K_WCHAR_P_
#define _SEND_FUNC_S_K_BOOL_S_K_WCHAR_P_S_K_WCHAR_P_
	/* MSG_ID_MMI_JAVA_LOCAL_INSTALL_REQ_IND */
void _send_S_k_bool_S_k_wchar_p_S_k_wchar_p_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_wchar_p_S_k_wchar_p__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_wchar_p_S_k_wchar_p__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assignS(1,kal_wchar*) assignS(2,kal_wchar*) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
/* Bluetooth */
#if defined(__BT_SUPPORT__)
#ifndef _SEND_FUNC_A32A_K_8_A6A_K_8_S_K_8_
#define _SEND_FUNC_A32A_K_8_A6A_K_8_S_K_8_
	/* MSG_ID_MMI_L4_BT_FCTY_SET_PARAM_IND */
void _send_A32A_k_8_A6A_k_8_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_32A_k_8_6A_k_8_S_k_8__struct *p = construct_local_para(sizeof(msg_32A_k_8_6A_k_8_S_k_8__struct),0);

	va_start(args, msg);
	assignA(0,kal_uint8,32) assignA(1,kal_uint8,6) assign_kal_uint8(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_A6A_K_8_A17A_K_8_
#define _SEND_FUNC_A6A_K_8_A17A_K_8_
	/* MSG_ID_MMI_L4_BT_LOOPBACK_TEST_REQ_IND */
void _send_A6A_k_8_A17A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_6A_k_8_17A_k_8__struct *p = construct_local_para(sizeof(msg_6A_k_8_17A_k_8__struct),0);

	va_start(args, msg);
	assignA(0,kal_uint8,6) assignA(1,kal_uint8,17) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_L4_BT_SET_VR_REQ_IND */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_L4_BT_SET_VR_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#endif /* defined(__BT_SUPPORT__) */
/* HOMEZONE */
#if defined(__HOMEZONE_SUPPORT__)
#ifndef _SEND_FUNC_S_K_BOOL_S_K_BOOL_A12A_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_BOOL_A12A_K_8_
	/* MSG_ID_MMI_HZ_TAG_IND */
void _send_S_k_bool_S_k_bool_A12A_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_bool_12A_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_bool_12A_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_bool(1) assignA(2,kal_uint8,12) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#endif /* defined(__HOMEZONE_SUPPORT__) */
/* CTM */
#if defined(__CTM_SUPPORT__)
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_CTM_OPEN_RSP */
void _send_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_CTM_CLOSE_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_CTM_CONNECT_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_CTM_SEND_TEXT_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_16_AV7A_K_16_
#define _SEND_FUNC_S_K_16_AV7A_K_16_
	/* MSG_ID_MMI_CTM_RECV_TEXT_IND */
void _send_S_k_16_Av7A_k_16_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_16_v7A_k_16__struct *p = construct_local_para(sizeof(msg_S_k_16_v7A_k_16__struct),0);

	va_start(args, msg);
	assign_kal_uint16(0) assignA(1,kal_uint16,CTM_SEND_TEXT_CHAR_MAX_NUM+1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_CTM_TTY_PLUG_IND */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_CTM_SET_DEFAULT_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_CTM_DEFAULT_CHANGED_IND */
void _send_S_k_bool_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_bool(1) assign_kal_uint8(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_BOOL_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_CTM_GET_DEFAULT_RSP */
void _send_S_k_bool_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_bool(1) assign_kal_uint8(2) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#endif /* defined(__CTM_SUPPORT__) */
/* VOIP */
#if defined(__VOIP__)
#ifndef _SEND_FUNC_S_K_BOOL_
#define _SEND_FUNC_S_K_BOOL_
	/* MSG_ID_MMI_VOIP_AT_CALL_CTRL_APPROVE_RES_RSP */
void _send_S_k_bool_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool__struct *p = construct_local_para(sizeof(msg_S_k_bool__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#ifndef _SEND_FUNC_S_K_8_S_VOID_P_S_VOID_P_S_VOID_P_
#define _SEND_FUNC_S_K_8_S_VOID_P_S_VOID_P_S_VOID_P_
	/* MSG_ID_MMI_VOIP_AT_CALL_CTRL_APPROVE_IND */
void _send_S_k_8_S_void_p_S_void_p_S_void_p_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_8_S_void_p_S_void_p_S_void_p__struct *p = construct_local_para(sizeof(msg_S_k_8_S_void_p_S_void_p_S_void_p__struct),0);

	va_start(args, msg);
	assign_kal_uint8(0) assignS(1,void*) assignS(2,void*) assignS(3,void*) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#endif /* defined(__VOIP__) */
/* GEMINI */
#if defined(__GEMINI__)
#ifndef _SEND_FUNC_S_K_BOOL_S_K_8_
#define _SEND_FUNC_S_K_BOOL_S_K_8_
	/* MSG_ID_MMI_SMU_SIM_STATUS_UPDATE_IND */
void _send_S_k_bool_S_k_8_(module_type src, module_type dest, kal_uint32 msg,...)
{
	va_list args;
	msg_S_k_bool_S_k_8__struct *p = construct_local_para(sizeof(msg_S_k_bool_S_k_8__struct),0);

	va_start(args, msg);
	assign_kal_bool(0) assign_kal_uint8(1) 
	l4a_sendmsg_ilm(src, dest, msg, p);
	va_end(args);
}

#endif
#endif /* defined(__GEMINI__) */

/*MTK:END*/

/******************************************************************************************
 * call functions
 ******************************************************************************************/
//#define RESULT	,result
/*
#define nP(n)	p->a##n
#define nA(n)	a##n
#define nPp(n)	&(p->a##n)
#define nAp(n)	&a##n

#define P(n)	,nP(n)
#define A(n)	,nA(n)
#define Pp(n)	,nPp(n)
#define Ap(n)	,nAp(n)
*/

/*
 * a special message structure, only for send boolean fail message to MMI
 */
typedef struct
{
	LOCAL_PARA_HDR
	kal_bool	result;
} l4a_kal_bool_rsp_struct;

/*
 * a special message structure, only for send l4c_result_struct fail message to MMI
 */
typedef struct
{
	LOCAL_PARA_HDR
	l4c_result_struct	result;
} l4a_result_struct_rsp_struct;

/*
* FUNCTION
*	l4a_send_kal_bool_fail
* DESCRIPTION
*   this macro will send boolean fail to destination module.
*
* CALLS
*	CALL_FUNC macro
* PARAMETERS
* 	src: source module
* 	dest: destination module
* 	msg: message id
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*/
void l4a_send_kal_bool_fail(module_type src,module_type dest,msg_type msg)
{
	//struct ilm_struct *ilm_ptr=NULL;

	l4a_kal_bool_rsp_struct *p
		= (l4a_kal_bool_rsp_struct*) construct_local_para((kal_uint16)(sizeof(l4a_kal_bool_rsp_struct)),0);

   p->result = KAL_FALSE;

   l4a_sendmsg_ilm(src,dest,msg,p);
}

/*
* FUNCTION
*	l4a_send_result_struct_fail
* DESCRIPTION
*   this macro will send l4c_result_struct fail to destination module.
*
* CALLS
*	CALL_FUNC macro
* PARAMETERS
* 	src: source module
* 	dest: destination module
* 	msg: message id
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*/
void l4a_send_result_struct_fail(module_type src,module_type dest,msg_type msg)
{
	//struct ilm_struct *ilm_ptr=NULL;

	l4a_result_struct_rsp_struct *p
		= (l4a_result_struct_rsp_struct*) construct_local_para((kal_uint16)(sizeof(l4a_result_struct_rsp_struct)),0);

   p->result.flag = L4C_ERROR;

   l4a_sendmsg_ilm(src,dest,msg,p);
}
/*
* FUNCTION
*	IF_CALL_FAIL_RETURN_BOOL macro
* DESCRIPTION
*   this macro will call l4a_send_kal_bool_fail to destination
*
* CALLS
*	CALL_FUNC macro
* PARAMETERS
* 	none
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*/
#define IF_CALL_FAIL_RETURN_BOOL \
	if(!result)\
	{\
	   l4a_send_kal_bool_fail(l4c_current_mod_id,MOD_MMI,msg_req+1);\
	}

/*
* FUNCTION
*	IF_CALL_FAIL_RETURN_RESULT_STRUCT macro
* DESCRIPTION
*   this macro will call l4a_send_result_struct_fail to destination
*
* CALLS
*	CALL_FUNC macro
* PARAMETERS
* 	none
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*/
#define IF_CALL_FAIL_RETURN_RESULT_STRUCT \
	if(!result)\
	{\
	   l4a_send_result_struct_fail(l4c_current_mod_id,MOD_MMI,msg_req+1);\
	}


/*
* FUNCTION
*	CALL_FUNC macro
* DESCRIPTION
*   1. this macro will execute L4C function
*   2. return the response message to MMI if the L4C function didn't have callback function.
*   3. return the error code to MMI if the L4C function return fail.
*
* CALLS
*	CALL_FUNC macro
* PARAMETERS
* 	none
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*/

/*
#define CALL_FUNC(POSTFIX,MSG_POSTFIX, LOCALMEMBER, CALL_ARG,RET_TYPE,RET_ARG,RET_ERR)\
	void _call_##POSTFIX##(module_type RSP_DEST,kal_uint8 SRC_ID,msg_type msg_req,msg_##MSG_POSTFIX##_struct *p)\
	{\
		LOCALMEMBER\
		RET_TYPE result=(RET_TYPE) l4a_req_ft[msg_req -MSG_ID_L4A_CODE_BEGIN]( CALL_ARG);\
		if(l4a_rsp_table[msg_req -MSG_ID_L4A_CODE_BEGIN]!=MSG_ID_L4A_CODE_END)\
			l4a_sendmsg(l4c_current_mod_id,RSP_DEST,l4a_rsp_table[msg_req -MSG_ID_L4A_CODE_BEGIN] RET_ARG);\
		RET_ERR\
	}

*/

/*MTK:BEGIN:generate_call_function*/
/* Call Control Related Messages */
#if defined(__MOD_CSM__)
#ifndef _CALL_FUNC_MSG_ID_MMI_CC_RESET_ACM_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CC_RESET_ACM_REQ_
	/* MSG_ID_MMI_CC_RESET_ACM_REQ */
void _call_MSG_ID_MMI_CC_RESET_ACM_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_9A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_cc_exe_reset_acm_req(SRC_ID, p->a0 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CC_GET_ACM_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CC_GET_ACM_REQ_
	/* MSG_ID_MMI_CC_GET_ACM_REQ */
void _call_MSG_ID_MMI_CC_GET_ACM_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_32(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_cc_get_acm_value_req(SRC_ID, &a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_CC_GET_ACM_RSP /* MSG_ID_MMI_CC_GET_ACM_RSP */
		_send_S_k_bool_S_k_32_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_CC_GET_ACM_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CC_SET_MAX_ACM_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CC_SET_MAX_ACM_REQ_
	/* MSG_ID_MMI_CC_SET_MAX_ACM_REQ */
void _call_MSG_ID_MMI_CC_SET_MAX_ACM_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_9A_k_8_S_k_32__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_cc_set_acm_max_req(SRC_ID, p->a0 , p->a1 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CC_GET_MAX_ACM_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CC_GET_MAX_ACM_REQ_
	/* MSG_ID_MMI_CC_GET_MAX_ACM_REQ 	 CALL_FUNC S_k_bool_L_ipS_k_32_ */
void _call_MSG_ID_MMI_CC_GET_MAX_ACM_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_32(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_cc_get_acm_max_req(SRC_ID, &a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_CC_GET_MAX_ACM_RSP /* MSG_ID_MMI_CC_GET_MAX_ACM_RSP */
		_send_S_k_bool_S_k_32_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_CC_GET_MAX_ACM_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CC_GET_CCM_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CC_GET_CCM_REQ_
	/* MSG_ID_MMI_CC_GET_CCM_REQ 	 CALL_FUNC S_k_bool_L_ipS_k_32_ */
void _call_MSG_ID_MMI_CC_GET_CCM_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_32(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_cc_get_ccm_value_req(SRC_ID, &a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_CC_GET_CCM_RSP /* MSG_ID_MMI_CC_GET_CCM_RSP */
		_send_S_k_bool_S_k_32_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_CC_GET_CCM_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CC_SET_CUG_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CC_SET_CUG_REQ_
	/* MSG_ID_MMI_CC_SET_CUG_REQ */
void _call_MSG_ID_MMI_CC_SET_CUG_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_cc_set_cug_params_req(SRC_ID, p->a0 , p->a1 , p->a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_CC_SET_CUG_RSP /* MSG_ID_MMI_CC_SET_CUG_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_CC_SET_CUG_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CC_GET_CUG_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CC_GET_CUG_REQ_
	/* MSG_ID_MMI_CC_GET_CUG_REQ */
void _call_MSG_ID_MMI_CC_GET_CUG_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_8(2) mS_k_8(3) mS_k_8(4)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_cc_get_cug_params_req(SRC_ID, &a2 , &a3 , &a4 );
	{
		#ifndef DISABLE_MSG_ID_MMI_CC_GET_CUG_RSP /* MSG_ID_MMI_CC_GET_CUG_RSP */
		_send_S_k_bool_S_k_8_S_k_8_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_CC_GET_CUG_RSP , result , a2 , a3 , a4 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CC_CHLD_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CC_CHLD_REQ_
	/* MSG_ID_MMI_CC_CHLD_REQ */
void _call_MSG_ID_MMI_CC_CHLD_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4a_cc_exe_chld_req(SRC_ID, p->a0 , p->a1 , p->a2 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CC_HANGUP_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CC_HANGUP_REQ_
	/* MSG_ID_MMI_CC_HANGUP_REQ */
void _call_MSG_ID_MMI_CC_HANGUP_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_cc_exe_hangup_active_call_req(SRC_ID);
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CC_ATH_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CC_ATH_REQ_
	/* MSG_ID_MMI_CC_ATH_REQ */
void _call_MSG_ID_MMI_CC_ATH_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4a_cc_exe_ath_req(SRC_ID, p->a0 , p->a1 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CC_GET_CALL_LIST_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CC_GET_CALL_LIST_REQ_
	/* MSG_ID_MMI_CC_GET_CALL_LIST_REQ */
void _call_MSG_ID_MMI_CC_GET_CALL_LIST_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_l_call_list_s(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_cc_get_call_list_req(SRC_ID, &a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_CC_GET_CALL_LIST_RSP /* MSG_ID_MMI_CC_GET_CALL_LIST_RSP */
		_send_S_k_bool_S_l_call_list_s_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_CC_GET_CALL_LIST_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CC_CALL_DEFLECT_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CC_CALL_DEFLECT_REQ_
	/* MSG_ID_MMI_CC_CALL_DEFLECT_REQ */
void _call_MSG_ID_MMI_CC_CALL_DEFLECT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_l_number_s_S_k_bool_S_l_sub_addr_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_cc_exe_call_deflect_req(SRC_ID, p->a0 , p->a1 , p->a2 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CC_START_DTMF_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CC_START_DTMF_REQ_
	/* MSG_ID_MMI_CC_START_DTMF_REQ */
void _call_MSG_ID_MMI_CC_START_DTMF_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_cc_exe_send_dtmf_req(SRC_ID, p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_CC_START_DTMF_RSP /* MSG_ID_MMI_CC_START_DTMF_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_CC_START_DTMF_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CC_STOP_DTMF_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CC_STOP_DTMF_REQ_
	/* MSG_ID_MMI_CC_STOP_DTMF_REQ */
void _call_MSG_ID_MMI_CC_STOP_DTMF_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_cc_exe_stop_dtmf_req(SRC_ID);
	{
		#ifndef DISABLE_MSG_ID_MMI_CC_STOP_DTMF_RSP /* MSG_ID_MMI_CC_STOP_DTMF_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_CC_STOP_DTMF_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CC_START_AUTO_DTMF_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CC_START_AUTO_DTMF_REQ_
	/* MSG_ID_MMI_CC_START_AUTO_DTMF_REQ */
void _call_MSG_ID_MMI_CC_START_AUTO_DTMF_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_80A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_cc_exe_start_auto_dtmf_req(SRC_ID, p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_CC_START_AUTO_DTMF_RSP /* MSG_ID_MMI_CC_START_AUTO_DTMF_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_CC_START_AUTO_DTMF_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CC_ATA_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CC_ATA_REQ_
	/* MSG_ID_MMI_CC_ATA_REQ */
void _call_MSG_ID_MMI_CC_ATA_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4a_cc_exe_ata_req(SRC_ID, p->a0 );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CC_DISCONNECT_AUX_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CC_DISCONNECT_AUX_REQ_
	/* MSG_ID_MMI_CC_DISCONNECT_AUX_REQ 	 CALL_FUNC S_k_bool_L_ */
void _call_MSG_ID_MMI_CC_DISCONNECT_AUX_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_cc_exe_disc_aux_req(SRC_ID);
	{
		#ifndef DISABLE_MSG_ID_MMI_CC_DISCONNECT_AUX_RSP /* MSG_ID_MMI_CC_DISCONNECT_AUX_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_CC_DISCONNECT_AUX_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CC_SET_LINE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CC_SET_LINE_REQ_
	/* MSG_ID_MMI_CC_SET_LINE_REQ 	 CALL_FUNC S_k_bool_L_vS_k_8_ */
void _call_MSG_ID_MMI_CC_SET_LINE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_cc_set_line_req(SRC_ID, p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_CC_SET_LINE_RSP /* MSG_ID_MMI_CC_SET_LINE_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_CC_SET_LINE_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CC_DIAL_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CC_DIAL_REQ_
	/* MSG_ID_MMI_CC_DIAL_REQ */
void _call_MSG_ID_MMI_CC_DIAL_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_bool__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_cc_exe_call_setup_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 , p->a4 );
	{
		#ifndef DISABLE_MSG_ID_MMI_CC_DIAL_RSP /* MSG_ID_MMI_CC_DIAL_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_CC_DIAL_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CC_CALL_MODIFY_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CC_CALL_MODIFY_REQ_
	/* MSG_ID_MMI_CC_CALL_MODIFY_REQ */
void _call_MSG_ID_MMI_CC_CALL_MODIFY_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_cc_exe_call_modify_req(SRC_ID);
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CC_SET_SINGLE_NUM_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CC_SET_SINGLE_NUM_REQ_
	/* MSG_ID_MMI_CC_SET_SINGLE_NUM_REQ 	 CALL_FUNC S_k_bool_L_vS_k_8_ */
void _call_MSG_ID_MMI_CC_SET_SINGLE_NUM_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_cc_set_single_num_req(SRC_ID, p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_CC_SET_SINGLE_NUM_RSP /* MSG_ID_MMI_CC_SET_SINGLE_NUM_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_CC_SET_SINGLE_NUM_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CC_GET_SINGLE_NUM_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CC_GET_SINGLE_NUM_REQ_
	/* MSG_ID_MMI_CC_GET_SINGLE_NUM_REQ */
void _call_MSG_ID_MMI_CC_GET_SINGLE_NUM_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_8(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_cc_get_single_num_req(SRC_ID, &a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_CC_GET_SINGLE_NUM_RSP /* MSG_ID_MMI_CC_GET_SINGLE_NUM_RSP */
		_send_S_k_bool_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_CC_GET_SINGLE_NUM_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CC_REL_COMP_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CC_REL_COMP_REQ_
	/* MSG_ID_MMI_CC_REL_COMP_REQ 	 CALL_FUNC S_k_bool_L_vS_k_8_ */
void _call_MSG_ID_MMI_CC_REL_COMP_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_cc_rel_comp_req(SRC_ID, p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_CC_REL_COMP_RSP /* MSG_ID_MMI_CC_REL_COMP_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_CC_REL_COMP_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#endif /* defined(__MOD_CSM__) */
#ifndef _CALL_FUNC_MSG_ID_MMI_CC_SET_BEARER_SERVICE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CC_SET_BEARER_SERVICE_REQ_
	/* MSG_ID_MMI_CC_SET_BEARER_SERVICE_REQ 	 CALL_FUNC S_k_bool_L_vS_k_8_vS_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_CC_SET_BEARER_SERVICE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_cc_set_bearer_service_req(SRC_ID, p->a0 , p->a1 , p->a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_CC_SET_BEARER_SERVICE_RSP /* MSG_ID_MMI_CC_SET_BEARER_SERVICE_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_CC_SET_BEARER_SERVICE_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CC_GET_BEARER_SERVICE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CC_GET_BEARER_SERVICE_REQ_
	/* MSG_ID_MMI_CC_GET_BEARER_SERVICE_REQ 	 CALL_FUNC S_k_bool_L_ipS_k_8_ipS_k_8_ipS_k_8_ */
void _call_MSG_ID_MMI_CC_GET_BEARER_SERVICE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_8(2) mS_k_8(3) mS_k_8(4)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_cc_get_bearer_service_req(SRC_ID, &a2 , &a3 , &a4 );
	{
		#ifndef DISABLE_MSG_ID_MMI_CC_GET_BEARER_SERVICE_RSP /* MSG_ID_MMI_CC_GET_BEARER_SERVICE_RSP */
		_send_S_k_bool_S_k_8_S_k_8_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_CC_GET_BEARER_SERVICE_RSP , result , a2 , a3 , a4 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CC_SET_CSD_PROFILE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CC_SET_CSD_PROFILE_REQ_
	/* MSG_ID_MMI_CC_SET_CSD_PROFILE_REQ */
void _call_MSG_ID_MMI_CC_SET_CSD_PROFILE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_bool_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_32A_k_8_32A_k_8_4A_k_8_S_l4_name_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_cc_set_csd_profile_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 , p->a4 , p->a5 , p->a6 , p->a7 , p->a8 , p->a9 , &(p->a10) );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CC_GET_CSD_PROFILE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CC_GET_CSD_PROFILE_REQ_
	/* MSG_ID_MMI_CC_GET_CSD_PROFILE_REQ */
void _call_MSG_ID_MMI_CC_GET_CSD_PROFILE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	mS_l_number_s(2) mS_k_8(3) mS_k_8(4) mS_k_8(5) mS_k_8(6) m32A_k_8(7) m32A_k_8(8) m4A_k_8(9) mS_l4_name_s(10)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_cc_get_csd_profile_req(SRC_ID, p->a0 , &a2 , &a3 , &a4 , &a5 , &a6 , a7 , a8 , a9 , &a10 );
	{
		#ifndef DISABLE_MSG_ID_MMI_CC_GET_CSD_PROFILE_RSP /* MSG_ID_MMI_CC_GET_CSD_PROFILE_RSP */
		_send_S_k_bool_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_A32A_k_8_A32A_k_8_A4A_k_8_S_l4_name_s_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_CC_GET_CSD_PROFILE_RSP , result , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CC_GET_FREE_CSD_PROFILE_NUM_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CC_GET_FREE_CSD_PROFILE_NUM_REQ_
	/* MSG_ID_MMI_CC_GET_FREE_CSD_PROFILE_NUM_REQ 	 CALL_FUNC S_k_bool_L_ipS_k_8_ */
void _call_MSG_ID_MMI_CC_GET_FREE_CSD_PROFILE_NUM_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_8(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_cc_get_no_free_csd_profile_req(SRC_ID, &a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_CC_GET_FREE_CSD_PROFILE_NUM_RSP /* MSG_ID_MMI_CC_GET_FREE_CSD_PROFILE_NUM_RSP */
		_send_S_k_bool_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_CC_GET_FREE_CSD_PROFILE_NUM_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SS_GET_EMLPP_PRIORITY_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SS_GET_EMLPP_PRIORITY_REQ_
	/* MSG_ID_MMI_SS_GET_EMLPP_PRIORITY_REQ 	 CALL_FUNC S_k_bool_L_ipS_k_8_ */
void _call_MSG_ID_MMI_SS_GET_EMLPP_PRIORITY_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_8(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ss_get_priority_status_req(SRC_ID, &a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SS_GET_EMLPP_PRIORITY_RSP /* MSG_ID_MMI_SS_GET_EMLPP_PRIORITY_RSP */
		_send_S_k_bool_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SS_GET_EMLPP_PRIORITY_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SS_EMLPP_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SS_EMLPP_REQ_
	/* MSG_ID_MMI_SS_EMLPP_REQ */
void _call_MSG_ID_MMI_SS_EMLPP_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ss_exe_emlpp_req(SRC_ID, p->a0 , p->a1 );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SS_CALL_FORWARD_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SS_CALL_FORWARD_REQ_
	/* MSG_ID_MMI_SS_CALL_FORWARD_REQ */
void _call_MSG_ID_MMI_SS_CALL_FORWARD_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_S_k_8_S_k_8_S_l_number_s_S_k_bool_S_l_sub_addr_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ss_exe_call_forward_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 , p->a4 , p->a5 , p->a6 );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SS_CALL_WAIT_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SS_CALL_WAIT_REQ_
	/* MSG_ID_MMI_SS_CALL_WAIT_REQ 	 CALL_FUNC S_k_bool_retr_L_vS_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_SS_CALL_WAIT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ss_exe_call_wait_req(SRC_ID, p->a0 , p->a1 );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SS_INTERROGATE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SS_INTERROGATE_REQ_
	/* MSG_ID_MMI_SS_INTERROGATE_REQ 	 CALL_FUNC S_k_bool_L_vS_k_8_ */
void _call_MSG_ID_MMI_SS_INTERROGATE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ss_exe_interrogate_req(SRC_ID, p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SS_INTERROGATE_RSP /* MSG_ID_MMI_SS_INTERROGATE_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SS_INTERROGATE_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SS_CALL_BARRING_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SS_CALL_BARRING_REQ_
	/* MSG_ID_MMI_SS_CALL_BARRING_REQ */
void _call_MSG_ID_MMI_SS_CALL_BARRING_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_S_k_8_9A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ss_exe_call_barring_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SS_USSD_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SS_USSD_REQ_
	/* MSG_ID_MMI_SS_USSD_REQ */
void _call_MSG_ID_MMI_SS_USSD_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_183A_k_8_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ss_exe_ussd_req(SRC_ID, p->a0 , p->a1 , p->a2 );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SS_CHANGE_PASSWORD_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SS_CHANGE_PASSWORD_REQ_
	/* MSG_ID_MMI_SS_CHANGE_PASSWORD_REQ */
void _call_MSG_ID_MMI_SS_CHANGE_PASSWORD_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_9A_k_8_9A_k_8_9A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ss_exe_change_password_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SS_PARSING_STRING_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SS_PARSING_STRING_REQ_
	/* MSG_ID_MMI_SS_PARSING_STRING_REQ */
void _call_MSG_ID_MMI_SS_PARSING_STRING_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_183A_k_8_S_k_8_S_k_8_21A_k_8_S_k_8_S_k_8_S_k_bool__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4a_ss_string_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 , p->a4 , p->a5 , p->a6 );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SS_CCBS_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SS_CCBS_REQ_
	/* MSG_ID_MMI_SS_CCBS_REQ 	 CALL_FUNC S_k_bool_retr_L_vS_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_SS_CCBS_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ss_exe_ccbs_req(SRC_ID, p->a0 , p->a1 );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SS_ABORT_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SS_ABORT_REQ_
	/* MSG_ID_MMI_SS_ABORT_REQ 	 CALL_FUNC S_k_bool_L_ */
void _call_MSG_ID_MMI_SS_ABORT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ss_exe_abort_req(SRC_ID);
	{
		#ifndef DISABLE_MSG_ID_MMI_SS_ABORT_RSP /* MSG_ID_MMI_SS_ABORT_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SS_ABORT_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SS_SET_CLIR_FLAG_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SS_SET_CLIR_FLAG_REQ_
	/* MSG_ID_MMI_SS_SET_CLIR_FLAG_REQ 	 CALL_FUNC S_k_bool_L_vS_k_8_ */
void _call_MSG_ID_MMI_SS_SET_CLIR_FLAG_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ss_set_clir_flag_req(SRC_ID, p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SS_SET_CLIR_FLAG_RSP /* MSG_ID_MMI_SS_SET_CLIR_FLAG_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SS_SET_CLIR_FLAG_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
/* Hardware - Audio Related Service Messages */
#if defined(__MOD_UEM__)
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_SET_VOLUME_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_SET_VOLUME_REQ_
	/* MSG_ID_MMI_EQ_SET_VOLUME_REQ */
void _call_MSG_ID_MMI_EQ_SET_VOLUME_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8__struct *p)
{
	mS_k_8(3)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4a_eq_exe_volume_req(SRC_ID, p->a0 , p->a1 , &a3 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_SET_VOLUME_RSP /* MSG_ID_MMI_EQ_SET_VOLUME_RSP */
		_send_S_k_bool_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_SET_VOLUME_RSP , result , a3 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_SET_MUTE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_SET_MUTE_REQ_
	/* MSG_ID_MMI_EQ_SET_MUTE_REQ */
void _call_MSG_ID_MMI_EQ_SET_MUTE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_bool__struct *p)
{
	mS_k_8(3)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4a_eq_exe_mute_mode_req(SRC_ID, p->a0 , p->a1 , &a3 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_SET_MUTE_RSP /* MSG_ID_MMI_EQ_SET_MUTE_RSP */
		_send_S_k_bool_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_SET_MUTE_RSP , result , a3 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_SET_SILENT_MODE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_SET_SILENT_MODE_REQ_
	/* MSG_ID_MMI_EQ_SET_SILENT_MODE_REQ */
void _call_MSG_ID_MMI_EQ_SET_SILENT_MODE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_bool__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_set_silent_mode_req(SRC_ID, p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_SET_SILENT_MODE_RSP /* MSG_ID_MMI_EQ_SET_SILENT_MODE_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_SET_SILENT_MODE_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_SET_GPIO_LEVEL_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_SET_GPIO_LEVEL_REQ_
	/* MSG_ID_MMI_EQ_SET_GPIO_LEVEL_REQ */
void _call_MSG_ID_MMI_EQ_SET_GPIO_LEVEL_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4a_eq_set_gpio_level_req(SRC_ID, p->a0 , p->a1 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_SET_GPIO_LEVEL_RSP /* MSG_ID_MMI_EQ_SET_GPIO_LEVEL_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_SET_GPIO_LEVEL_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_GET_GPIO_LEVEL_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_GET_GPIO_LEVEL_REQ_
	/* MSG_ID_MMI_EQ_GET_GPIO_LEVEL_REQ */
void _call_MSG_ID_MMI_EQ_GET_GPIO_LEVEL_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	mS_k_8(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_get_gpio_level_req(SRC_ID, p->a0 , &a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_GET_GPIO_LEVEL_RSP /* MSG_ID_MMI_EQ_GET_GPIO_LEVEL_RSP */
		_send_S_k_bool_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_GET_GPIO_LEVEL_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_EXE_GPIO_LEVEL_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_EXE_GPIO_LEVEL_REQ_
	/* MSG_ID_MMI_EQ_EXE_GPIO_LEVEL_REQ 	 CALL_FUNC S_k_bool_L_vS_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_EQ_EXE_GPIO_LEVEL_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_exe_gpio_level_req(SRC_ID, p->a0 , p->a1 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_EXE_GPIO_LEVEL_RSP /* MSG_ID_MMI_EQ_EXE_GPIO_LEVEL_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_EXE_GPIO_LEVEL_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_PLAY_AUDIO_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_PLAY_AUDIO_REQ_
	/* MSG_ID_MMI_EQ_PLAY_AUDIO_REQ */
void _call_MSG_ID_MMI_EQ_PLAY_AUDIO_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_S_k_16__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_audio_play_req(SRC_ID, p->a0 , p->a1 , p->a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_PLAY_AUDIO_RSP /* MSG_ID_MMI_EQ_PLAY_AUDIO_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_PLAY_AUDIO_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_STOP_AUDIO_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_STOP_AUDIO_REQ_
	/* MSG_ID_MMI_EQ_STOP_AUDIO_REQ 	 CALL_FUNC S_k_bool_L_vS_k_8_ */
void _call_MSG_ID_MMI_EQ_STOP_AUDIO_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_audio_stop_req(SRC_ID, p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_STOP_AUDIO_RSP /* MSG_ID_MMI_EQ_STOP_AUDIO_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_STOP_AUDIO_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_PLAY_AUDIO_STREAM_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_PLAY_AUDIO_STREAM_REQ_
	/* MSG_ID_MMI_EQ_PLAY_AUDIO_STREAM_REQ */
void _call_MSG_ID_MMI_EQ_PLAY_AUDIO_STREAM_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_p_S_k_32_S_k_8_S_k_8_S_k_16__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_audio_play_by_string_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 , p->a4 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_STOP_AUDIO_STREAM_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_STOP_AUDIO_STREAM_REQ_
	/* MSG_ID_MMI_EQ_STOP_AUDIO_STREAM_REQ */
void _call_MSG_ID_MMI_EQ_STOP_AUDIO_STREAM_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_audio_stop_by_string_req(SRC_ID);
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_PLAY_EXT_IMELODY_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_PLAY_EXT_IMELODY_REQ_
	/* MSG_ID_MMI_EQ_PLAY_EXT_IMELODY_REQ */
void _call_MSG_ID_MMI_EQ_PLAY_EXT_IMELODY_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_300A_k_8_S_k_16_S_k_8_S_k_16__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_demo_ext_midi_ring_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_PLAY_EXT_IMELODY_RSP /* MSG_ID_MMI_EQ_PLAY_EXT_IMELODY_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_PLAY_EXT_IMELODY_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_GPIO_DETECT_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_GPIO_DETECT_RES_REQ_
	/* MSG_ID_MMI_EQ_GPIO_DETECT_RES_REQ */
void _call_MSG_ID_MMI_EQ_GPIO_DETECT_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_gpio_detect_res_req(p->a0 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_SET_SPEECH_MODE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_SET_SPEECH_MODE_REQ_
	/* MSG_ID_MMI_EQ_SET_SPEECH_MODE_REQ */
void _call_MSG_ID_MMI_EQ_SET_SPEECH_MODE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_bool__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_set_speech_mode_req(p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_SET_SPEECH_MODE_RSP /* MSG_ID_MMI_EQ_SET_SPEECH_MODE_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_SET_SPEECH_MODE_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_PLAY_AUDIO_BY_NAME_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_PLAY_AUDIO_BY_NAME_REQ_
	/* MSG_ID_MMI_EQ_PLAY_AUDIO_BY_NAME_REQ */
void _call_MSG_ID_MMI_EQ_PLAY_AUDIO_BY_NAME_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_50A_k_wchar_S_k_8_S_k_16__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_audio_play_by_name_req(SRC_ID, p->a0 , p->a1 , p->a2 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_STOP_AUDIO_BY_NAME_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_STOP_AUDIO_BY_NAME_REQ_
	/* MSG_ID_MMI_EQ_STOP_AUDIO_BY_NAME_REQ */
void _call_MSG_ID_MMI_EQ_STOP_AUDIO_BY_NAME_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_50A_k_wchar__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_audio_stop_by_name_req(SRC_ID, p->a0 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_SET_AUDIO_PROFILE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_SET_AUDIO_PROFILE_REQ_
	/* MSG_ID_MMI_EQ_SET_AUDIO_PROFILE_REQ */
void _call_MSG_ID_MMI_EQ_SET_AUDIO_PROFILE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_audio_profile_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_set_audio_profile_req(SRC_ID, &(p->a0) );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_GET_AUDIO_PROFILE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_GET_AUDIO_PROFILE_REQ_
	/* MSG_ID_MMI_EQ_GET_AUDIO_PROFILE_REQ 	 CALL_FUNC S_k_bool_retb_L_pS_audio_profile_s_ */
void _call_MSG_ID_MMI_EQ_GET_AUDIO_PROFILE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_audio_profile_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4a_eq_get_audio_profile_req(SRC_ID, &(p->a0) );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_SET_AUDIO_PARAM_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_SET_AUDIO_PARAM_REQ_
	/* MSG_ID_MMI_EQ_SET_AUDIO_PARAM_REQ */
void _call_MSG_ID_MMI_EQ_SET_AUDIO_PARAM_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_audio_param_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_set_audio_param_req(SRC_ID, &(p->a0) );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_GET_AUDIO_PARAM_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_GET_AUDIO_PARAM_REQ_
	/* MSG_ID_MMI_EQ_GET_AUDIO_PARAM_REQ 	 CALL_FUNC S_k_bool_retb_L_ */
void _call_MSG_ID_MMI_EQ_GET_AUDIO_PARAM_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_get_audio_param_req(SRC_ID);
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_START_ADC_ALL_CHANNEL_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_START_ADC_ALL_CHANNEL_REQ_
	/* MSG_ID_MMI_EQ_START_ADC_ALL_CHANNEL_REQ */
void _call_MSG_ID_MMI_EQ_START_ADC_ALL_CHANNEL_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_get_adc_all_channel_start_req(NONE);
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_START_ADC_ALL_CHANNEL_RSP /* MSG_ID_MMI_EQ_START_ADC_ALL_CHANNEL_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_START_ADC_ALL_CHANNEL_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_STOP_ADC_ALL_CHANNEL_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_STOP_ADC_ALL_CHANNEL_REQ_
	/* MSG_ID_MMI_EQ_STOP_ADC_ALL_CHANNEL_REQ 	 CALL_FUNC S_k_bool_ */
void _call_MSG_ID_MMI_EQ_STOP_ADC_ALL_CHANNEL_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_get_adc_all_channel_stop_req(NONE);
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_STOP_ADC_ALL_CHANNEL_RSP /* MSG_ID_MMI_EQ_STOP_ADC_ALL_CHANNEL_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_STOP_ADC_ALL_CHANNEL_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_SET_AUDIO_MODE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_SET_AUDIO_MODE_REQ_
	/* MSG_ID_MMI_EQ_SET_AUDIO_MODE_REQ */
void _call_MSG_ID_MMI_EQ_SET_AUDIO_MODE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_set_audio_mode_req(p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_SET_AUDIO_MODE_RSP /* MSG_ID_MMI_EQ_SET_AUDIO_MODE_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_SET_AUDIO_MODE_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_PLAY_PATTERN_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_PLAY_PATTERN_REQ_
	/* MSG_ID_MMI_EQ_PLAY_PATTERN_REQ 	 CALL_FUNC S_k_bool_L_vS_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_EQ_PLAY_PATTERN_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_pattern_play_req(SRC_ID, p->a0 , p->a1 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_PLAY_PATTERN_RSP /* MSG_ID_MMI_EQ_PLAY_PATTERN_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_PLAY_PATTERN_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_SET_HW_LEVEL_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_SET_HW_LEVEL_REQ_
	/* MSG_ID_MMI_EQ_SET_HW_LEVEL_REQ */
void _call_MSG_ID_MMI_EQ_SET_HW_LEVEL_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_l_hw_profile_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_set_hw_level_req(SRC_ID, &(p->a0) );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_GET_HW_LEVEL_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_GET_HW_LEVEL_REQ_
	/* MSG_ID_MMI_EQ_GET_HW_LEVEL_REQ */
void _call_MSG_ID_MMI_EQ_GET_HW_LEVEL_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_l_hw_profile_s(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_get_hw_level_req(SRC_ID, &a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_GET_HW_LEVEL_RSP /* MSG_ID_MMI_EQ_GET_HW_LEVEL_RSP */
		_send_S_k_bool_S_l_hw_profile_s_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_GET_HW_LEVEL_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_SET_SLEEP_MODE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_SET_SLEEP_MODE_REQ_
	/* MSG_ID_MMI_EQ_SET_SLEEP_MODE_REQ 	 CALL_FUNC S_k_bool_vS_k_bool_ */
void _call_MSG_ID_MMI_EQ_SET_SLEEP_MODE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_bool__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_em_sleep_mode_req(p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_SET_SLEEP_MODE_RSP /* MSG_ID_MMI_EQ_SET_SLEEP_MODE_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_SET_SLEEP_MODE_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_GET_MS_IMEI_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_GET_MS_IMEI_REQ_
	/* MSG_ID_MMI_EQ_GET_MS_IMEI_REQ 	 CALL_FUNC S_k_bool_L_vS_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_EQ_GET_MS_IMEI_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_read_ms_imei_req(SRC_ID, p->a0 , p->a1 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_GET_MS_IMEI_RSP /* MSG_ID_MMI_EQ_GET_MS_IMEI_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_GET_MS_IMEI_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_SET_MS_IMEI_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_SET_MS_IMEI_REQ_
	/* MSG_ID_MMI_EQ_SET_MS_IMEI_REQ */
void _call_MSG_ID_MMI_EQ_SET_MS_IMEI_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_10A_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_set_ms_imei_req(SRC_ID, p->a0 , p->a1 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_SET_MS_IMEI_RSP /* MSG_ID_MMI_EQ_SET_MS_IMEI_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_SET_MS_IMEI_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_RTC_POWERON_STATE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_RTC_POWERON_STATE_REQ_
	/* MSG_ID_MMI_EQ_RTC_POWERON_STATE_REQ 	 CALL_FUNC S_k_bool_ */
void _call_MSG_ID_MMI_EQ_RTC_POWERON_STATE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_rtc_poweron_state_req(NONE);
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_RTC_POWERON_STATE_RSP /* MSG_ID_MMI_EQ_RTC_POWERON_STATE_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_RTC_POWERON_STATE_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#endif /* defined(__MOD_UEM__) */
/* Hardware - RTC, Clock, Alarm Related Messages */
#if defined(__MOD_UEM__)
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_SET_RTC_TIME_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_SET_RTC_TIME_REQ_
	/* MSG_ID_MMI_EQ_SET_RTC_TIME_REQ */
void _call_MSG_ID_MMI_EQ_SET_RTC_TIME_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_S_rtc_alarm_info_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_set_rtc_time_req(SRC_ID, p->a0 , p->a1 , p->a2 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_EXE_RTC_TIMER_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_EXE_RTC_TIMER_REQ_
	/* MSG_ID_MMI_EQ_EXE_RTC_TIMER_REQ */
void _call_MSG_ID_MMI_EQ_EXE_RTC_TIMER_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_S_rtc_alarm_info_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_exe_rtc_time_req(SRC_ID, p->a0 , p->a1 , p->a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_EXE_RTC_TIMER_RSP /* MSG_ID_MMI_EQ_EXE_RTC_TIMER_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_EXE_RTC_TIMER_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_GET_RTC_TIME_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_GET_RTC_TIME_REQ_
	/* MSG_ID_MMI_EQ_GET_RTC_TIME_REQ */
void _call_MSG_ID_MMI_EQ_GET_RTC_TIME_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	mS_k_8(2) m3A_rtc_alarm_info_s(3)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_get_rtc_time_req(SRC_ID, p->a0 , &a2 , a3 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_GET_RTC_TIME_RSP /* MSG_ID_MMI_EQ_GET_RTC_TIME_RSP */
		_send_S_k_bool_S_k_8_A3A_rtc_alarm_info_s_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_GET_RTC_TIME_RSP , result , a2 , a3 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_DEL_RTC_TIMER_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_DEL_RTC_TIMER_REQ_
	/* MSG_ID_MMI_EQ_DEL_RTC_TIMER_REQ */
void _call_MSG_ID_MMI_EQ_DEL_RTC_TIMER_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_rtc_delete_req(SRC_ID, p->a0 , p->a1 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_EXE_DEL_RTC_TIMER_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_EXE_DEL_RTC_TIMER_REQ_
	/* MSG_ID_MMI_EQ_EXE_DEL_RTC_TIMER_REQ 	 CALL_FUNC S_k_bool_L_vS_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_EQ_EXE_DEL_RTC_TIMER_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_exe_rtc_delete_req(SRC_ID, p->a0 , p->a1 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_EXE_DEL_RTC_TIMER_RSP /* MSG_ID_MMI_EQ_EXE_DEL_RTC_TIMER_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_EXE_DEL_RTC_TIMER_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_SET_DATE_TIME_FORMAT_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_SET_DATE_TIME_FORMAT_REQ_
	/* MSG_ID_MMI_EQ_SET_DATE_TIME_FORMAT_REQ */
void _call_MSG_ID_MMI_EQ_SET_DATE_TIME_FORMAT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_bool_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_set_date_time_format_req(SRC_ID, p->a0 , p->a1 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_SET_DATE_TIME_FORMAT_RSP /* MSG_ID_MMI_EQ_SET_DATE_TIME_FORMAT_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_SET_DATE_TIME_FORMAT_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_START_TIMER_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_START_TIMER_REQ_
	/* MSG_ID_MMI_EQ_START_TIMER_REQ */
void _call_MSG_ID_MMI_EQ_START_TIMER_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_void_p_S_k_16_S_void_p__struct *p)
{
	mS_eventid(4) mS_void_p(5)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4a_set_timer_req(p->a0 , p->a1 , p->a2 , &a4 , &a5 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_START_TIMER_RSP /* MSG_ID_MMI_EQ_START_TIMER_RSP */
		_send_S_k_bool_S_eventid_S_void_p_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_START_TIMER_RSP , result , a4 , a5 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_STOP_TIMER_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_STOP_TIMER_REQ_
	/* MSG_ID_MMI_EQ_STOP_TIMER_REQ */
void _call_MSG_ID_MMI_EQ_STOP_TIMER_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_eventid__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_stop_timer_req(p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_STOP_TIMER_RSP /* MSG_ID_MMI_EQ_STOP_TIMER_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_STOP_TIMER_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_AT_ALARM_QUERY_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_AT_ALARM_QUERY_RES_REQ_
	/* MSG_ID_MMI_AT_ALARM_QUERY_RES_REQ */
void _call_MSG_ID_MMI_AT_ALARM_QUERY_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_S_mmi_at_alarm_info_s_p__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_eq_at_alarm_query_res_req(p->a0 , p->a1 , p->a2 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_AT_ALARM_SET_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_AT_ALARM_SET_RES_REQ_
	/* MSG_ID_MMI_AT_ALARM_SET_RES_REQ */
void _call_MSG_ID_MMI_AT_ALARM_SET_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_bool__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_eq_at_alarm_set_res_req(p->a0 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_AT_ALARM_DELETE_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_AT_ALARM_DELETE_RES_REQ_
	/* MSG_ID_MMI_AT_ALARM_DELETE_RES_REQ 	 CALL_FUNC V_vS_k_bool_ */
void _call_MSG_ID_MMI_AT_ALARM_DELETE_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_bool__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_eq_at_alarm_delete_res_req(p->a0 );
	NONE
}

#endif
#endif /* defined(__MOD_UEM__) */
/* Hardware - Keypad, Indicator, LCD Related Messages */
#if defined(__MOD_UEM__)
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_SIMULATE_KEY_PRESS_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_SIMULATE_KEY_PRESS_REQ_
	/* MSG_ID_MMI_EQ_SIMULATE_KEY_PRESS_REQ */
void _call_MSG_ID_MMI_EQ_SIMULATE_KEY_PRESS_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_32A_k_8_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_set_keypad_input_req(SRC_ID, p->a0 , p->a1 , p->a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_SIMULATE_KEY_PRESS_RSP /* MSG_ID_MMI_EQ_SIMULATE_KEY_PRESS_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_SIMULATE_KEY_PRESS_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_SET_INDICATOR_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_SET_INDICATOR_REQ_
	/* MSG_ID_MMI_EQ_SET_INDICATOR_REQ 	 CALL_FUNC S_k_bool_L_vS_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_EQ_SET_INDICATOR_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_set_indicator_req(SRC_ID, p->a0 , p->a1 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_SET_INDICATOR_RSP /* MSG_ID_MMI_EQ_SET_INDICATOR_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_SET_INDICATOR_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_GET_INDICATOR_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_GET_INDICATOR_REQ_
	/* MSG_ID_MMI_EQ_GET_INDICATOR_REQ 	 CALL_FUNC S_k_bool_L_vS_k_8_ipS_k_8_ */
void _call_MSG_ID_MMI_EQ_GET_INDICATOR_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	mS_k_8(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_get_indicator_req(SRC_ID, p->a0 , &a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_GET_INDICATOR_RSP /* MSG_ID_MMI_EQ_GET_INDICATOR_RSP */
		_send_S_k_bool_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_GET_INDICATOR_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_DISPLAY_TEXT_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_DISPLAY_TEXT_REQ_
	/* MSG_ID_MMI_EQ_DISPLAY_TEXT_REQ */
void _call_MSG_ID_MMI_EQ_DISPLAY_TEXT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_30A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_set_dspl_text_req(SRC_ID, p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_DISPLAY_TEXT_RSP /* MSG_ID_MMI_EQ_DISPLAY_TEXT_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_DISPLAY_TEXT_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#endif /* defined(__MOD_UEM__) */
/* Hardware - Misc Messages */
#if defined(__MOD_UEM__)
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_SET_LANGUAGE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_SET_LANGUAGE_REQ_
	/* MSG_ID_MMI_EQ_SET_LANGUAGE_REQ */
void _call_MSG_ID_MMI_EQ_SET_LANGUAGE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_set_language_req(SRC_ID, p->a0 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_SET_GREETING_TEXT_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_SET_GREETING_TEXT_REQ_
	/* MSG_ID_MMI_EQ_SET_GREETING_TEXT_REQ */
void _call_MSG_ID_MMI_EQ_SET_GREETING_TEXT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_bool_S_k_8_62A_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_set_greeting_text_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_SET_VIBRATOR_MODE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_SET_VIBRATOR_MODE_REQ_
	/* MSG_ID_MMI_EQ_SET_VIBRATOR_MODE_REQ 	 CALL_FUNC S_k_bool_retb_L_vS_k_8_ */
void _call_MSG_ID_MMI_EQ_SET_VIBRATOR_MODE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_set_vibrator_mode_req(SRC_ID, p->a0 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_SET_COUNTRY_CODE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_SET_COUNTRY_CODE_REQ_
	/* MSG_ID_MMI_EQ_SET_COUNTRY_CODE_REQ 	 CALL_FUNC S_k_bool_retb_L_vS_k_8_ */
void _call_MSG_ID_MMI_EQ_SET_COUNTRY_CODE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_set_country_code_req(SRC_ID, p->a0 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_GET_COUNTRY_CODE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_GET_COUNTRY_CODE_REQ_
	/* MSG_ID_MMI_EQ_GET_COUNTRY_CODE_REQ 	 CALL_FUNC S_k_bool_L_ipS_k_8_ */
void _call_MSG_ID_MMI_EQ_GET_COUNTRY_CODE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_8(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_get_country_code_req(SRC_ID, &a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_GET_COUNTRY_CODE_RSP /* MSG_ID_MMI_EQ_GET_COUNTRY_CODE_RSP */
		_send_S_k_bool_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_GET_COUNTRY_CODE_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_GET_BATTERY_STATUS_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_GET_BATTERY_STATUS_REQ_
	/* MSG_ID_MMI_EQ_GET_BATTERY_STATUS_REQ */
void _call_MSG_ID_MMI_EQ_GET_BATTERY_STATUS_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_8(2) mS_k_8(3)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_get_battery_status_req(SRC_ID, &a2 , &a3 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_GET_BATTERY_STATUS_RSP /* MSG_ID_MMI_EQ_GET_BATTERY_STATUS_RSP */
		_send_S_k_bool_S_k_8_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_GET_BATTERY_STATUS_RSP , result , a2 , a3 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_GET_EQUIP_ID_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_GET_EQUIP_ID_REQ_
	/* MSG_ID_MMI_EQ_GET_EQUIP_ID_REQ */
void _call_MSG_ID_MMI_EQ_GET_EQUIP_ID_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	m30A_k_8(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_get_equip_id_req(SRC_ID, p->a0 , a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_GET_EQUIP_ID_RSP /* MSG_ID_MMI_EQ_GET_EQUIP_ID_RSP */
		_send_S_k_bool_A30A_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_GET_EQUIP_ID_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_LOAD_DEFAULT_CONFIG_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_LOAD_DEFAULT_CONFIG_REQ_
	/* MSG_ID_MMI_EQ_LOAD_DEFAULT_CONFIG_REQ 	 CALL_FUNC S_k_bool_L_ */
void _call_MSG_ID_MMI_EQ_LOAD_DEFAULT_CONFIG_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_load_default_config_req(SRC_ID);
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_LOAD_DEFAULT_CONFIG_RSP /* MSG_ID_MMI_EQ_LOAD_DEFAULT_CONFIG_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_LOAD_DEFAULT_CONFIG_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_POWER_ON_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_POWER_ON_REQ_
	/* MSG_ID_MMI_EQ_POWER_ON_REQ 	 CALL_FUNC S_k_bool_L_vS_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_EQ_POWER_ON_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_exe_functionality_req(SRC_ID, p->a0 , p->a1 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_POWER_ON_RSP /* MSG_ID_MMI_EQ_POWER_ON_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_POWER_ON_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_POWER_OFF_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_POWER_OFF_REQ_
	/* MSG_ID_MMI_EQ_POWER_OFF_REQ 	 CALL_FUNC S_k_bool_L_ */
void _call_MSG_ID_MMI_EQ_POWER_OFF_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_power_off_req(SRC_ID);
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_POWER_OFF_RSP /* MSG_ID_MMI_EQ_POWER_OFF_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_POWER_OFF_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_PMIC_CONFIG_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_PMIC_CONFIG_REQ_
	/* MSG_ID_MMI_EQ_PMIC_CONFIG_REQ */
void _call_MSG_ID_MMI_EQ_PMIC_CONFIG_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_pmic_config_param_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_eq_pmic_config_req(SRC_ID, p->a0 , p->a1 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_BATTERY_STATUS_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_BATTERY_STATUS_RES_REQ_
	/* MSG_ID_MMI_EQ_BATTERY_STATUS_RES_REQ */
void _call_MSG_ID_MMI_EQ_BATTERY_STATUS_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_eq_battery_status_res_req(SRC_ID, p->a0 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_RF_TEST_GSM_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_RF_TEST_GSM_REQ_
	/* MSG_ID_MMI_EQ_RF_TEST_GSM_REQ */
void _call_MSG_ID_MMI_EQ_RF_TEST_GSM_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_rf_test_gsm_param_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_eq_rf_test_gsm_req(SRC_ID, p->a0 , p->a1 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_FM_RADIO_CONFIG_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_FM_RADIO_CONFIG_REQ_
	/* MSG_ID_MMI_EQ_FM_RADIO_CONFIG_REQ */
void _call_MSG_ID_MMI_EQ_FM_RADIO_CONFIG_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_fm_radio_config_param_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_eq_fm_radio_config_req(SRC_ID, p->a0 , p->a1 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_RF_TEST_WIFI_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_RF_TEST_WIFI_REQ_
	/* MSG_ID_MMI_EQ_RF_TEST_WIFI_REQ */
void _call_MSG_ID_MMI_EQ_RF_TEST_WIFI_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_rf_test_wifi_param_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_eq_rf_test_wifi_req(SRC_ID, p->a0 , p->a1 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_CALL_STATUS_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_CALL_STATUS_REQ_
	/* MSG_ID_MMI_EQ_CALL_STATUS_REQ 	 CALL_FUNC V_L_vS_k_8_ */
void _call_MSG_ID_MMI_EQ_CALL_STATUS_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_mmi_eq_call_status_req(SRC_ID, p->a0 );
	NONE
}

#endif
#endif /* defined(__MOD_UEM__) */
/* Hardware - NVRAM messages */
#if defined(__MOD_NVRAM__)
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_NVRAM_READ_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_NVRAM_READ_REQ_
	/* MSG_ID_MMI_EQ_NVRAM_READ_REQ */
void _call_MSG_ID_MMI_EQ_NVRAM_READ_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_16_S_k_16__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_read_nvram_req(SRC_ID, p->a0 , p->a1 , p->a2 );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_NVRAM_WRITE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_NVRAM_WRITE_REQ_
	/* MSG_ID_MMI_EQ_NVRAM_WRITE_REQ */
void _call_MSG_ID_MMI_EQ_NVRAM_WRITE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_16_S_k_16_1A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4a_eq_write_nvram_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_NVRAM_RESET_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_NVRAM_RESET_REQ_
	/* MSG_ID_MMI_EQ_NVRAM_RESET_REQ 	 CALL_FUNC S_k_bool_retr_L_vS_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_EQ_NVRAM_RESET_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_reset_nvram_req(SRC_ID, p->a0 , p->a1 );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_SET_UART_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_SET_UART_REQ_
	/* MSG_ID_MMI_EQ_SET_UART_REQ */
void _call_MSG_ID_MMI_EQ_SET_UART_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_S_k_8_S_k_32_S_k_32_S_k_bool_S_k_8_S_k_8_S_k_8_S_k_32_S_k_8_S_k_32__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_set_uart_port_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 , p->a4 , p->a5 , p->a6 , p->a7 , p->a8 , p->a9 , p->a10 , p->a11 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_SET_UART_RSP /* MSG_ID_MMI_EQ_SET_UART_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_SET_UART_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_GET_UART_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_GET_UART_REQ_
	/* MSG_ID_MMI_EQ_GET_UART_REQ 	 CALL_FUNC S_k_bool_retb_L_ */
void _call_MSG_ID_MMI_EQ_GET_UART_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_get_uart_port_req(SRC_ID);
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_ATTACH_UART_PORT_REQ_
#define _CALL_FUNC_MSG_ID_MMI_ATTACH_UART_PORT_REQ_
	/* MSG_ID_MMI_ATTACH_UART_PORT_REQ */
void _call_MSG_ID_MMI_ATTACH_UART_PORT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_module_type_S_UART_PORT_S_k_32__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_attach_uart_port_req(SRC_ID, p->a0 , p->a1 , p->a2 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_DETACH_UART_PORT_REQ_
#define _CALL_FUNC_MSG_ID_MMI_DETACH_UART_PORT_REQ_
	/* MSG_ID_MMI_DETACH_UART_PORT_REQ */
void _call_MSG_ID_MMI_DETACH_UART_PORT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_module_type_S_UART_PORT__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_detach_uart_port_req(SRC_ID, p->a0 , p->a1 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_DCM_ENABLE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_DCM_ENABLE_REQ_
	/* MSG_ID_MMI_EQ_DCM_ENABLE_REQ */
void _call_MSG_ID_MMI_EQ_DCM_ENABLE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_bool__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_eq_dcm_enable_req(SRC_ID, p->a0 );
	NONE
}

#endif
#endif /* defined(__MOD_NVRAM__) */
/* Network Related Messages */
#if defined(__MOD_RAC__)
#ifndef _CALL_FUNC_MSG_ID_MMI_NW_GET_IMEI_REQ_
#define _CALL_FUNC_MSG_ID_MMI_NW_GET_IMEI_REQ_
	/* MSG_ID_MMI_NW_GET_IMEI_REQ */
void _call_MSG_ID_MMI_NW_GET_IMEI_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	m16A_k_8(2) m3A_k_8(3)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_nw_get_imei_req(SRC_ID, a2 , a3 );
	{
		#ifndef DISABLE_MSG_ID_MMI_NW_GET_IMEI_RSP /* MSG_ID_MMI_NW_GET_IMEI_RSP */
		_send_S_k_bool_A16A_k_8_A3A_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_NW_GET_IMEI_RSP , result , a2 , a3 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_NW_ABORT_PLMN_LIST_REQ_
#define _CALL_FUNC_MSG_ID_MMI_NW_ABORT_PLMN_LIST_REQ_
	/* MSG_ID_MMI_NW_ABORT_PLMN_LIST_REQ 	 CALL_FUNC S_k_bool_retb_L_ */
void _call_MSG_ID_MMI_NW_ABORT_PLMN_LIST_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_nw_abort_plmn_list_req(SRC_ID);
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_NW_SET_ATTACH_REQ_
#define _CALL_FUNC_MSG_ID_MMI_NW_SET_ATTACH_REQ_
	/* MSG_ID_MMI_NW_SET_ATTACH_REQ */
void _call_MSG_ID_MMI_NW_SET_ATTACH_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_S_k_bool__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_nw_exe_att_req(SRC_ID, p->a0 , p->a1 , p->a2 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_NW_GET_ATTACH_REQ_
#define _CALL_FUNC_MSG_ID_MMI_NW_GET_ATTACH_REQ_
	/* MSG_ID_MMI_NW_GET_ATTACH_REQ 	 CALL_FUNC S_k_bool_L_vS_k_8_ipS_k_8_ */
void _call_MSG_ID_MMI_NW_GET_ATTACH_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	mS_k_8(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_nw_get_attach_status_req(SRC_ID, p->a0 , &a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_NW_GET_ATTACH_RSP /* MSG_ID_MMI_NW_GET_ATTACH_RSP */
		_send_S_k_bool_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_NW_GET_ATTACH_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_NW_SET_MOBILE_CLASS_REQ_
#define _CALL_FUNC_MSG_ID_MMI_NW_SET_MOBILE_CLASS_REQ_
	/* MSG_ID_MMI_NW_SET_MOBILE_CLASS_REQ 	 CALL_FUNC S_k_bool_retb_L_vS_k_8_ */
void _call_MSG_ID_MMI_NW_SET_MOBILE_CLASS_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_nw_set_class_req(SRC_ID, p->a0 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_NW_GET_MOBILE_CLASS_REQ_
#define _CALL_FUNC_MSG_ID_MMI_NW_GET_MOBILE_CLASS_REQ_
	/* MSG_ID_MMI_NW_GET_MOBILE_CLASS_REQ 	 CALL_FUNC S_k_bool_L_ipS_k_8_ */
void _call_MSG_ID_MMI_NW_GET_MOBILE_CLASS_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_8(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_nw_get_class_req(SRC_ID, &a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_NW_GET_MOBILE_CLASS_RSP /* MSG_ID_MMI_NW_GET_MOBILE_CLASS_RSP */
		_send_S_k_bool_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_NW_GET_MOBILE_CLASS_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_NW_SET_PLMN_SELECT_MODE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_NW_SET_PLMN_SELECT_MODE_REQ_
	/* MSG_ID_MMI_NW_SET_PLMN_SELECT_MODE_REQ 	 CALL_FUNC S_k_bool_L_vS_k_8_ */
void _call_MSG_ID_MMI_NW_SET_PLMN_SELECT_MODE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_nw_set_sel_mode_req(SRC_ID, p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_NW_SET_PLMN_SELECT_MODE_RSP /* MSG_ID_MMI_NW_SET_PLMN_SELECT_MODE_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_NW_SET_PLMN_SELECT_MODE_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_NW_GET_PLMN_SELECT_MODE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_NW_GET_PLMN_SELECT_MODE_REQ_
	/* MSG_ID_MMI_NW_GET_PLMN_SELECT_MODE_REQ 	 CALL_FUNC S_k_bool_L_ipS_k_8_ */
void _call_MSG_ID_MMI_NW_GET_PLMN_SELECT_MODE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_8(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_nw_get_sel_mode_req(SRC_ID, &a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_NW_GET_PLMN_SELECT_MODE_RSP /* MSG_ID_MMI_NW_GET_PLMN_SELECT_MODE_RSP */
		_send_S_k_bool_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_NW_GET_PLMN_SELECT_MODE_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_NW_SET_PLMN_REQ_
#define _CALL_FUNC_MSG_ID_MMI_NW_SET_PLMN_REQ_
	/* MSG_ID_MMI_NW_SET_PLMN_REQ */
void _call_MSG_ID_MMI_NW_SET_PLMN_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_v0A_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_nw_exe_cops_req(SRC_ID, p->a0 , p->a1 , p->a2 );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_NW_GET_PLMN_LIST_REQ_
#define _CALL_FUNC_MSG_ID_MMI_NW_GET_PLMN_LIST_REQ_
	/* MSG_ID_MMI_NW_GET_PLMN_LIST_REQ 	 CALL_FUNC S_k_bool_retr_L_ */
void _call_MSG_ID_MMI_NW_GET_PLMN_LIST_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_nw_get_plmn_list_req(SRC_ID);
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_NW_GET_CURRENT_PLMN_REQ_
#define _CALL_FUNC_MSG_ID_MMI_NW_GET_CURRENT_PLMN_REQ_
	/* MSG_ID_MMI_NW_GET_CURRENT_PLMN_REQ */
void _call_MSG_ID_MMI_NW_GET_CURRENT_PLMN_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mv0A_k_8(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_nw_get_current_oper_req(SRC_ID, a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_NW_GET_CURRENT_PLMN_RSP /* MSG_ID_MMI_NW_GET_CURRENT_PLMN_RSP */
		_send_S_k_bool_Av0A_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_NW_GET_CURRENT_PLMN_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_NW_GET_SIGNAL_LEVEL_REQ_
#define _CALL_FUNC_MSG_ID_MMI_NW_GET_SIGNAL_LEVEL_REQ_
	/* MSG_ID_MMI_NW_GET_SIGNAL_LEVEL_REQ 	 CALL_FUNC S_k_bool_L_ipS_k_8_ipS_k_8_ */
void _call_MSG_ID_MMI_NW_GET_SIGNAL_LEVEL_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_8(2) mS_k_8(3)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_nw_get_signal_level_req(SRC_ID, &a2 , &a3 );
	{
		#ifndef DISABLE_MSG_ID_MMI_NW_GET_SIGNAL_LEVEL_RSP /* MSG_ID_MMI_NW_GET_SIGNAL_LEVEL_RSP */
		_send_S_k_bool_S_k_8_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_NW_GET_SIGNAL_LEVEL_RSP , result , a2 , a3 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_NW_GET_BAND_REQ_
#define _CALL_FUNC_MSG_ID_MMI_NW_GET_BAND_REQ_
	/* MSG_ID_MMI_NW_GET_BAND_REQ 	 CALL_FUNC S_k_bool_L_ipS_k_8_ */
void _call_MSG_ID_MMI_NW_GET_BAND_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_8(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_nw_get_band_req(SRC_ID, &a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_NW_GET_BAND_RSP /* MSG_ID_MMI_NW_GET_BAND_RSP */
		_send_S_k_bool_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_NW_GET_BAND_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_NW_SET_PREFERRED_BAND_REQ_
#define _CALL_FUNC_MSG_ID_MMI_NW_SET_PREFERRED_BAND_REQ_
	/* MSG_ID_MMI_NW_SET_PREFERRED_BAND_REQ 	 CALL_FUNC S_k_bool_retb_L_vS_k_8_ */
void _call_MSG_ID_MMI_NW_SET_PREFERRED_BAND_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_nw_set_preferred_band_req(SRC_ID, p->a0 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_NW_SET_GPRS_CONNECT_TYPE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_NW_SET_GPRS_CONNECT_TYPE_REQ_
	/* MSG_ID_MMI_NW_SET_GPRS_CONNECT_TYPE_REQ 	 CALL_FUNC S_k_bool_L_vS_k_8_ */
void _call_MSG_ID_MMI_NW_SET_GPRS_CONNECT_TYPE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_nw_set_gprs_connect_type_req(SRC_ID, p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_NW_SET_GPRS_CONNECT_TYPE_RSP /* MSG_ID_MMI_NW_SET_GPRS_CONNECT_TYPE_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_NW_SET_GPRS_CONNECT_TYPE_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_NW_GET_GPRS_CONNECT_TYPE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_NW_GET_GPRS_CONNECT_TYPE_REQ_
	/* MSG_ID_MMI_NW_GET_GPRS_CONNECT_TYPE_REQ */
void _call_MSG_ID_MMI_NW_GET_GPRS_CONNECT_TYPE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_8(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_nw_get_gprs_connect_type_req(&a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_NW_GET_GPRS_CONNECT_TYPE_RSP /* MSG_ID_MMI_NW_GET_GPRS_CONNECT_TYPE_RSP */
		_send_S_k_bool_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_NW_GET_GPRS_CONNECT_TYPE_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_NW_PWROFF_DETACH_REQ_
#define _CALL_FUNC_MSG_ID_MMI_NW_PWROFF_DETACH_REQ_
	/* MSG_ID_MMI_NW_PWROFF_DETACH_REQ 	 CALL_FUNC S_k_bool_retr_L_ */
void _call_MSG_ID_MMI_NW_PWROFF_DETACH_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_nw_powroff_detach_req(SRC_ID);
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_NW_CFUN_STATE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_NW_CFUN_STATE_REQ_
	/* MSG_ID_MMI_NW_CFUN_STATE_REQ 	 CALL_FUNC S_k_bool_retb_L_vS_k_8_ */
void _call_MSG_ID_MMI_NW_CFUN_STATE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_nw_cfun_state_req(SRC_ID, p->a0 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_NW_GET_RAT_MODE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_NW_GET_RAT_MODE_REQ_
	/* MSG_ID_MMI_NW_GET_RAT_MODE_REQ 	 CALL_FUNC S_k_bool_L_ipS_k_8_ */
void _call_MSG_ID_MMI_NW_GET_RAT_MODE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_8(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_nw_get_rat_mode_req(SRC_ID, &a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_NW_GET_RAT_MODE_RSP /* MSG_ID_MMI_NW_GET_RAT_MODE_RSP */
		_send_S_k_bool_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_NW_GET_RAT_MODE_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_NW_SET_RAT_MODE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_NW_SET_RAT_MODE_REQ_
	/* MSG_ID_MMI_NW_SET_RAT_MODE_REQ 	 CALL_FUNC S_k_bool_retb_L_vS_k_8_ */
void _call_MSG_ID_MMI_NW_SET_RAT_MODE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_nw_set_rat_mode_req(SRC_ID, p->a0 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_NW_GET_PREFER_RAT_REQ_
#define _CALL_FUNC_MSG_ID_MMI_NW_GET_PREFER_RAT_REQ_
	/* MSG_ID_MMI_NW_GET_PREFER_RAT_REQ 	 CALL_FUNC S_k_bool_ipS_k_8_ */
void _call_MSG_ID_MMI_NW_GET_PREFER_RAT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_8(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_nw_get_prefer_rat_req(&a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_NW_GET_PREFER_RAT_RSP /* MSG_ID_MMI_NW_GET_PREFER_RAT_RSP */
		_send_S_k_bool_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_NW_GET_PREFER_RAT_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_NW_SET_PREFER_RAT_REQ_
#define _CALL_FUNC_MSG_ID_MMI_NW_SET_PREFER_RAT_REQ_
	/* MSG_ID_MMI_NW_SET_PREFER_RAT_REQ 	 CALL_FUNC S_k_bool_retb_L_vS_k_8_ */
void _call_MSG_ID_MMI_NW_SET_PREFER_RAT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_nw_set_prefer_rat_req(SRC_ID, p->a0 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#endif /* defined(__MOD_RAC__) */
/* Security Related Messages */
#if defined(__MOD_SMU__)
#ifndef _CALL_FUNC_MSG_ID_MMI_SMU_GET_IMSI_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMU_GET_IMSI_REQ_
	/* MSG_ID_MMI_SMU_GET_IMSI_REQ */
void _call_MSG_ID_MMI_SMU_GET_IMSI_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	m17A_k_8(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_smu_get_imsi_req(SRC_ID, a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SMU_GET_IMSI_RSP /* MSG_ID_MMI_SMU_GET_IMSI_RSP */
		_send_S_k_bool_A17A_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SMU_GET_IMSI_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMU_LOCK_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMU_LOCK_REQ_
	/* MSG_ID_MMI_SMU_LOCK_REQ */
void _call_MSG_ID_MMI_SMU_LOCK_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_9A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_smu_exe_lock_req(SRC_ID, p->a0 , p->a1 , p->a2 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMU_RESET_DATA_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMU_RESET_DATA_REQ_
	/* MSG_ID_MMI_SMU_RESET_DATA_REQ 	 CALL_FUNC S_k_bool_retb_L_v9A_k_8_ */
void _call_MSG_ID_MMI_SMU_RESET_DATA_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_9A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_smu_exe_master_reset_req(SRC_ID, p->a0 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMU_GET_DIAL_MODE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMU_GET_DIAL_MODE_REQ_
	/* MSG_ID_MMI_SMU_GET_DIAL_MODE_REQ 	 CALL_FUNC S_k_bool_ipS_k_8_ */
void _call_MSG_ID_MMI_SMU_GET_DIAL_MODE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_8(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_smu_get_dial_mode_req(&a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SMU_GET_DIAL_MODE_RSP /* MSG_ID_MMI_SMU_GET_DIAL_MODE_RSP */
		_send_S_k_bool_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SMU_GET_DIAL_MODE_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMU_VERIFY_PIN_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMU_VERIFY_PIN_REQ_
	/* MSG_ID_MMI_SMU_VERIFY_PIN_REQ */
void _call_MSG_ID_MMI_SMU_VERIFY_PIN_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_9A_k_8_9A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_smu_exe_verify_pin_req(SRC_ID, p->a0 , p->a1 , p->a2 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMU_GET_PIN_TYPE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMU_GET_PIN_TYPE_REQ_
	/* MSG_ID_MMI_SMU_GET_PIN_TYPE_REQ 	 CALL_FUNC S_k_bool_L_ipS_k_8_ */
void _call_MSG_ID_MMI_SMU_GET_PIN_TYPE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_8(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_smu_get_pin_type_req(SRC_ID, &a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SMU_GET_PIN_TYPE_RSP /* MSG_ID_MMI_SMU_GET_PIN_TYPE_RSP */
		_send_S_k_bool_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SMU_GET_PIN_TYPE_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMU_SET_PREFERRED_OPER_LIST_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMU_SET_PREFERRED_OPER_LIST_REQ_
	/* MSG_ID_MMI_SMU_SET_PREFERRED_OPER_LIST_REQ */
void _call_MSG_ID_MMI_SMU_SET_PREFERRED_OPER_LIST_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_v0A_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_smu_set_preferred_oper_list_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMU_GET_PREFERRED_OPER_LIST_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMU_GET_PREFERRED_OPER_LIST_REQ_
	/* MSG_ID_MMI_SMU_GET_PREFERRED_OPER_LIST_REQ */
void _call_MSG_ID_MMI_SMU_GET_PREFERRED_OPER_LIST_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_16_S_k_16__struct *p)
{
	mS_k_16(4) mv1A_k_8(5) mv2A_k_8(6) mS_k_16(7)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4a_smu_get_preferred_oper_list_req(SRC_ID, p->a0 , p->a1 , p->a2 , &a4 , a5 , a6 , &a7 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SMU_GET_PREFERRED_OPER_LIST_RSP /* MSG_ID_MMI_SMU_GET_PREFERRED_OPER_LIST_RSP */
		_send_S_k_bool_S_k_16_Av1A_k_8_Av2A_k_8_S_k_16_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SMU_GET_PREFERRED_OPER_LIST_RSP , result , a4 , a5 , a6 , a7 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMU_SET_PUC_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMU_SET_PUC_REQ_
	/* MSG_ID_MMI_SMU_SET_PUC_REQ */
void _call_MSG_ID_MMI_SMU_SET_PUC_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_9A_k_8_3A_k_8_18A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_smu_set_puc_params_req(SRC_ID, p->a0 , p->a1 , p->a2 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMU_GET_PUC_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMU_GET_PUC_REQ_
	/* MSG_ID_MMI_SMU_GET_PUC_REQ */
void _call_MSG_ID_MMI_SMU_GET_PUC_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	m3A_k_8(2) m18A_k_8(3)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_smu_get_puc_params_req(SRC_ID, a2 , a3 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SMU_GET_PUC_RSP /* MSG_ID_MMI_SMU_GET_PUC_RSP */
		_send_S_k_bool_A3A_k_8_A18A_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SMU_GET_PUC_RSP , result , a2 , a3 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMU_CHANGE_PASSWORD_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMU_CHANGE_PASSWORD_REQ_
	/* MSG_ID_MMI_SMU_CHANGE_PASSWORD_REQ */
void _call_MSG_ID_MMI_SMU_CHANGE_PASSWORD_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_9A_k_8_9A_k_8_9A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_smu_exe_change_password_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMU_RESTRICTED_ACCESS_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMU_RESTRICTED_ACCESS_REQ_
	/* MSG_ID_MMI_SMU_RESTRICTED_ACCESS_REQ */
void _call_MSG_ID_MMI_SMU_RESTRICTED_ACCESS_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_16_S_k_8_S_k_8_S_k_8_256A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_smu_exe_restricted_access_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 , p->a4 , p->a5 );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMU_SET_DIAL_MODE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMU_SET_DIAL_MODE_REQ_
	/* MSG_ID_MMI_SMU_SET_DIAL_MODE_REQ 	 CALL_FUNC S_k_bool_retb_L_vS_k_8_vS_k_8_v9A_k_8_ */
void _call_MSG_ID_MMI_SMU_SET_DIAL_MODE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_9A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_smu_exe_dial_mode_req(SRC_ID, p->a0 , p->a1 , p->a2 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMU_WRITE_SIM_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMU_WRITE_SIM_REQ_
	/* MSG_ID_MMI_SMU_WRITE_SIM_REQ */
void _call_MSG_ID_MMI_SMU_WRITE_SIM_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_260A_k_8_S_k_16_6A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_smu_write_sim_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 , p->a4 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMU_READ_SIM_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMU_READ_SIM_REQ_
	/* MSG_ID_MMI_SMU_READ_SIM_REQ */
void _call_MSG_ID_MMI_SMU_READ_SIM_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_16_S_k_16_6A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_smu_read_sim_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMU_POWER_OFF_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMU_POWER_OFF_REQ_
	/* MSG_ID_MMI_SMU_POWER_OFF_REQ 	 CALL_FUNC S_k_bool_L_ */
void _call_MSG_ID_MMI_SMU_POWER_OFF_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sim_power_off_req(SRC_ID);
	{
		#ifndef DISABLE_MSG_ID_MMI_SMU_POWER_OFF_RSP /* MSG_ID_MMI_SMU_POWER_OFF_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SMU_POWER_OFF_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMU_REMOVE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMU_REMOVE_REQ_
	/* MSG_ID_MMI_SMU_REMOVE_REQ 	 CALL_FUNC S_k_bool_L_vS_k_8_ */
void _call_MSG_ID_MMI_SMU_REMOVE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sim_remove_req(SRC_ID, p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SMU_REMOVE_RSP /* MSG_ID_MMI_SMU_REMOVE_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SMU_REMOVE_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMU_READ_FILE_INFO_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMU_READ_FILE_INFO_REQ_
	/* MSG_ID_MMI_SMU_READ_FILE_INFO_REQ */
void _call_MSG_ID_MMI_SMU_READ_FILE_INFO_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_6A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_smu_read_file_info_req(SRC_ID, p->a0 , p->a1 );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMU_CHECK_PIN_STATUS_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMU_CHECK_PIN_STATUS_REQ_
	/* MSG_ID_MMI_SMU_CHECK_PIN_STATUS_REQ */
void _call_MSG_ID_MMI_SMU_CHECK_PIN_STATUS_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_sim_chv_info_s(2) mS_sim_chv_status_s(3)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sim_check_pin_status_req(&a2 , &a3 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SMU_CHECK_PIN_STATUS_RSP /* MSG_ID_MMI_SMU_CHECK_PIN_STATUS_RSP */
		_send_S_k_bool_S_sim_chv_info_s_S_sim_chv_status_s_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SMU_CHECK_PIN_STATUS_RSP , result , a2 , a3 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMU_SET_PERSONALIZATION_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMU_SET_PERSONALIZATION_REQ_
	/* MSG_ID_MMI_SMU_SET_PERSONALIZATION_REQ */
void _call_MSG_ID_MMI_SMU_SET_PERSONALIZATION_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_8A_k_8_S_k_8_10A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_smu_set_personalization_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 , p->a4 );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMU_SML_STATUS_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMU_SML_STATUS_REQ_
	/* MSG_ID_MMI_SMU_SML_STATUS_REQ 	 CALL_FUNC S_k_bool_retr_L_ */
void _call_MSG_ID_MMI_SMU_SML_STATUS_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_smu_sml_status_req(SRC_ID);
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#endif /* defined(__MOD_SMU__) */
/* PhoneBook Related Messages */
#if defined(__MOD_PHB__)
#ifndef _CALL_FUNC_MSG_ID_MMI_PHB_GET_ENTRY_BY_NAME_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PHB_GET_ENTRY_BY_NAME_REQ_
	/* MSG_ID_MMI_PHB_GET_ENTRY_BY_NAME_REQ */
void _call_MSG_ID_MMI_PHB_GET_ENTRY_BY_NAME_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_16_S_l4_name_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_phb_get_entry_by_text_req(SRC_ID, p->a0 , p->a1 , &(p->a2) );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PHB_GET_ENTRY_BY_INDEX_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PHB_GET_ENTRY_BY_INDEX_REQ_
	/* MSG_ID_MMI_PHB_GET_ENTRY_BY_INDEX_REQ */
void _call_MSG_ID_MMI_PHB_GET_ENTRY_BY_INDEX_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_S_k_16_S_k_16_S_k_16__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_phb_get_entry_by_index_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 , p->a4 );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PHB_SET_PREFERRED_STORAGE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PHB_SET_PREFERRED_STORAGE_REQ_
	/* MSG_ID_MMI_PHB_SET_PREFERRED_STORAGE_REQ 	 CALL_FUNC S_k_bool_L_vS_k_8_ */
void _call_MSG_ID_MMI_PHB_SET_PREFERRED_STORAGE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_phb_set_storage_req(SRC_ID, p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_PHB_SET_PREFERRED_STORAGE_RSP /* MSG_ID_MMI_PHB_SET_PREFERRED_STORAGE_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_PHB_SET_PREFERRED_STORAGE_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PHB_GET_PREFERRED_STORAGE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PHB_GET_PREFERRED_STORAGE_REQ_
	/* MSG_ID_MMI_PHB_GET_PREFERRED_STORAGE_REQ */
void _call_MSG_ID_MMI_PHB_GET_PREFERRED_STORAGE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_8(2) mS_k_16(3) mS_k_16(4)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_phb_get_storage_req(SRC_ID, &a2 , &a3 , &a4 );
	{
		#ifndef DISABLE_MSG_ID_MMI_PHB_GET_PREFERRED_STORAGE_RSP /* MSG_ID_MMI_PHB_GET_PREFERRED_STORAGE_RSP */
		_send_S_k_bool_S_k_8_S_k_16_S_k_16_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_PHB_GET_PREFERRED_STORAGE_RSP , result , a2 , a3 , a4 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PHB_SET_ENTRY_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PHB_SET_ENTRY_REQ_
	/* MSG_ID_MMI_PHB_SET_ENTRY_REQ */
void _call_MSG_ID_MMI_PHB_SET_ENTRY_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_16_S_l_phb_entry_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_phb_exe_write_entry_req(SRC_ID, p->a0 , p->a1 , &(p->a2) );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PHB_DEL_ENTRY_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PHB_DEL_ENTRY_REQ_
	/* MSG_ID_MMI_PHB_DEL_ENTRY_REQ */
void _call_MSG_ID_MMI_PHB_DEL_ENTRY_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_16_S_k_8_S_k_8_S_k_bool__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_phb_exe_delete_entry_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 , p->a4 );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PHB_SET_VOICE_MAIL_SERVER_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PHB_SET_VOICE_MAIL_SERVER_REQ_
	/* MSG_ID_MMI_PHB_SET_VOICE_MAIL_SERVER_REQ */
void _call_MSG_ID_MMI_PHB_SET_VOICE_MAIL_SERVER_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_l_number_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_phb_set_voice_mail_server_req(SRC_ID, p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_PHB_SET_VOICE_MAIL_SERVER_RSP /* MSG_ID_MMI_PHB_SET_VOICE_MAIL_SERVER_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_PHB_SET_VOICE_MAIL_SERVER_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PHB_GET_ALPHA_LIST_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PHB_GET_ALPHA_LIST_REQ_
	/* MSG_ID_MMI_PHB_GET_ALPHA_LIST_REQ */
void _call_MSG_ID_MMI_PHB_GET_ALPHA_LIST_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	m26A_k_16(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_phb_get_alpha_list_req(p->a0 , a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_PHB_GET_ALPHA_LIST_RSP /* MSG_ID_MMI_PHB_GET_ALPHA_LIST_RSP */
		_send_S_k_bool_A26A_k_16_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_PHB_GET_ALPHA_LIST_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PHB_GET_TYPE_STATUS_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PHB_GET_TYPE_STATUS_REQ_
	/* MSG_ID_MMI_PHB_GET_TYPE_STATUS_REQ */
void _call_MSG_ID_MMI_PHB_GET_TYPE_STATUS_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	mS_k_16(2) mS_k_16(3)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_phb_get_type_status_req(SRC_ID, p->a0 , &a2 , &a3 );
	{
		#ifndef DISABLE_MSG_ID_MMI_PHB_GET_TYPE_STATUS_RSP /* MSG_ID_MMI_PHB_GET_TYPE_STATUS_RSP */
		_send_S_k_bool_S_k_16_S_k_16_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_PHB_GET_TYPE_STATUS_RSP , result , a2 , a3 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PHB_GET_LAST_NUMBER_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PHB_GET_LAST_NUMBER_REQ_
	/* MSG_ID_MMI_PHB_GET_LAST_NUMBER_REQ 	 CALL_FUNC S_k_bool_retr_L_vS_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_PHB_GET_LAST_NUMBER_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_phb_exe_read_ln_entry_req(SRC_ID, p->a0 , p->a1 );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PHB_SET_LAST_NUMBER_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PHB_SET_LAST_NUMBER_REQ_
	/* MSG_ID_MMI_PHB_SET_LAST_NUMBER_REQ */
void _call_MSG_ID_MMI_PHB_SET_LAST_NUMBER_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_S_k_8_S_l_phb_ln_entry_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_phb_exe_write_ln_entry_req(SRC_ID, p->a0 , p->a1 , p->a2 , &(p->a3) );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PHB_DEL_LAST_NUMBER_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PHB_DEL_LAST_NUMBER_REQ_
	/* MSG_ID_MMI_PHB_DEL_LAST_NUMBER_REQ */
void _call_MSG_ID_MMI_PHB_DEL_LAST_NUMBER_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_phb_exe_delete_ln_entry_req(SRC_ID, p->a0 , p->a1 , p->a2 );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PHB_STARTUP_READ_NEXT_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PHB_STARTUP_READ_NEXT_REQ_
	/* MSG_ID_MMI_PHB_STARTUP_READ_NEXT_REQ 	 CALL_FUNC S_k_bool_vS_k_8_ */
void _call_MSG_ID_MMI_PHB_STARTUP_READ_NEXT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_phb_startup_read_next_req(p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_PHB_STARTUP_READ_NEXT_RSP /* MSG_ID_MMI_PHB_STARTUP_READ_NEXT_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_PHB_STARTUP_READ_NEXT_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PHB_STARTUP_READ_NEXT_USIM_FIELD_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PHB_STARTUP_READ_NEXT_USIM_FIELD_REQ_
	/* MSG_ID_MMI_PHB_STARTUP_READ_NEXT_USIM_FIELD_REQ 	 CALL_FUNC S_k_bool_L_vS_k_8_ */
void _call_MSG_ID_MMI_PHB_STARTUP_READ_NEXT_USIM_FIELD_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_phb_startup_read_next_usim_field_req(SRC_ID, p->a0 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PHB_READ_EMAIL_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PHB_READ_EMAIL_REQ_
	/* MSG_ID_MMI_PHB_READ_EMAIL_REQ */
void _call_MSG_ID_MMI_PHB_READ_EMAIL_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_16_S_k_16__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_phb_read_email_req(SRC_ID, p->a0 , p->a1 );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PHB_SET_GRP_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PHB_SET_GRP_REQ_
	/* MSG_ID_MMI_PHB_SET_GRP_REQ */
void _call_MSG_ID_MMI_PHB_SET_GRP_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_16_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_phb_set_grp_req(SRC_ID, p->a0 , p->a1 );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PHB_WRITE_USIM_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PHB_WRITE_USIM_REQ_
	/* MSG_ID_MMI_PHB_WRITE_USIM_REQ */
void _call_MSG_ID_MMI_PHB_WRITE_USIM_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_16_S_l_phb_entry_s_S_k_8_S_l_phb_anr_s_S_l_phb_anr_s_S_l_phb_anr_s_S_l_phb_email_s_S_l4_name_s_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_phb_write_usim_req(SRC_ID, p->a0 , p->a1 , &(p->a2) , p->a3 , p->a4 , p->a5 , p->a6 , p->a7 , p->a8 , p->a9 , p->a10 );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#endif /* defined(__MOD_PHB__) */
#ifndef _CALL_FUNC_MSG_ID_MMI_SMS_SET_PROFILE_PARAMS_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMS_SET_PROFILE_PARAMS_REQ_
	/* MSG_ID_MMI_SMS_SET_PROFILE_PARAMS_REQ */
void _call_MSG_ID_MMI_SMS_SET_PROFILE_PARAMS_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_16_S_k_8_S_k_8_S_k_8_S_k_8_S_l_number_s_S_l4_name_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sms_set_profile_params_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 , p->a4 , p->a5 , p->a6 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_REQ_
	/* MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_REQ */
void _call_MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	mS_k_8(2) mS_k_8(3) mS_k_8(4) mS_l_number_s(5) mS_l4_name_s(6)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sms_get_profile_params_req(SRC_ID, p->a0 , &a2 , &a3 , &a4 , &a5 , &a6 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_RSP /* MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_RSP */
		_send_S_k_bool_S_k_8_S_k_8_S_k_8_S_l_number_s_S_l4_name_s_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_RSP , result , a2 , a3 , a4 , a5 , a6 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMS_SET_COMMON_PARAMS_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMS_SET_COMMON_PARAMS_REQ_
	/* MSG_ID_MMI_SMS_SET_COMMON_PARAMS_REQ */
void _call_MSG_ID_MMI_SMS_SET_COMMON_PARAMS_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_16_S_k_8_S_k_8_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sms_set_common_params_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 , p->a4 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMS_GET_COMMON_PARAMS_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMS_GET_COMMON_PARAMS_REQ_
	/* MSG_ID_MMI_SMS_GET_COMMON_PARAMS_REQ */
void _call_MSG_ID_MMI_SMS_GET_COMMON_PARAMS_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_8(2) mS_k_8(3) mS_k_8(4) mS_k_8(5)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sms_get_common_params_req(SRC_ID, &a2 , &a3 , &a4 , &a5 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SMS_GET_COMMON_PARAMS_RSP /* MSG_ID_MMI_SMS_GET_COMMON_PARAMS_RSP */
		_send_S_k_bool_S_k_8_S_k_8_S_k_8_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SMS_GET_COMMON_PARAMS_RSP , result , a2 , a3 , a4 , a5 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMS_SEND_COMMAND_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMS_SEND_COMMAND_REQ_
	/* MSG_ID_MMI_SMS_SEND_COMMAND_REQ */
void _call_MSG_ID_MMI_SMS_SEND_COMMAND_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_S_k_8_S_k_8_S_l_number_s_S_k_8_156A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sms_exe_post_command_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 , p->a4 , p->a5 , p->a6 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMS_DEL_MSG_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMS_DEL_MSG_REQ_
	/* MSG_ID_MMI_SMS_DEL_MSG_REQ */
void _call_MSG_ID_MMI_SMS_DEL_MSG_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_16_480A_k_8_S_k_bool__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sms_exe_delete_msg_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMS_GET_MSG_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMS_GET_MSG_REQ_
	/* MSG_ID_MMI_SMS_GET_MSG_REQ */
void _call_MSG_ID_MMI_SMS_GET_MSG_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_16_S_k_bool__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sms_exe_read_msg_req(SRC_ID, p->a0 , p->a1 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMS_SEND_MSG_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMS_SEND_MSG_REQ_
	/* MSG_ID_MMI_SMS_SEND_MSG_REQ */
void _call_MSG_ID_MMI_SMS_SEND_MSG_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_16_S_l_number_s_S_k_8_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_S_k_16_160A_k_8_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sms_exe_post_msg_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 , p->a4 , p->a5 , p->a6 , p->a7 , p->a8 , p->a9 , p->a10 , p->a11 , p->a12 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMS_SET_MSG_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMS_SET_MSG_REQ_
	/* MSG_ID_MMI_SMS_SET_MSG_REQ */
void _call_MSG_ID_MMI_SMS_SET_MSG_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_S_l_number_s_S_k_8_S_l_number_s_7A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_16_S_k_16_160A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sms_exe_write_msg_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 , p->a4 , p->a5 , p->a6 , p->a7 , p->a8 , p->a9 , p->a10 , p->a11 , p->a12 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMS_SET_PREFERRED_STORAGE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMS_SET_PREFERRED_STORAGE_REQ_
	/* MSG_ID_MMI_SMS_SET_PREFERRED_STORAGE_REQ 	 CALL_FUNC S_k_bool_retb_L_vS_k_8_vS_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_SMS_SET_PREFERRED_STORAGE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sms_set_preferred_mem_req(SRC_ID, p->a0 , p->a1 , p->a2 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMS_GET_PREFERRED_STORAGE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMS_GET_PREFERRED_STORAGE_REQ_
	/* MSG_ID_MMI_SMS_GET_PREFERRED_STORAGE_REQ */
void _call_MSG_ID_MMI_SMS_GET_PREFERRED_STORAGE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_smsal_prefer_storage_s(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sms_get_preferred_mem_req(SRC_ID, &a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SMS_GET_PREFERRED_STORAGE_RSP /* MSG_ID_MMI_SMS_GET_PREFERRED_STORAGE_RSP */
		_send_S_k_bool_S_smsal_prefer_storage_s_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SMS_GET_PREFERRED_STORAGE_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMS_REG_PORT_NUM_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMS_REG_PORT_NUM_REQ_
	/* MSG_ID_MMI_SMS_REG_PORT_NUM_REQ */
void _call_MSG_ID_MMI_SMS_REG_PORT_NUM_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_bool_S_k_32_S_k_16__struct *p)
{
	mS_k_16(4) mS_k_32(5) mS_k_16(6)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sms_reg_port_num_req(SRC_ID, p->a0 , p->a1 , p->a2 , &a4 , &a5 , &a6 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SMS_REG_PORT_NUM_RSP /* MSG_ID_MMI_SMS_REG_PORT_NUM_RSP */
		_send_S_k_bool_S_k_16_S_k_32_S_k_16_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SMS_REG_PORT_NUM_RSP , result , a4 , a5 , a6 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMS_GET_MSG_NUM_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMS_GET_MSG_NUM_REQ_
	/* MSG_ID_MMI_SMS_GET_MSG_NUM_REQ */
void _call_MSG_ID_MMI_SMS_GET_MSG_NUM_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_bool(2) mS_k_16(3) mS_k_16(4) mS_k_16(5) mS_k_16(6) mS_k_16(7) mS_k_16(8) mS_k_16(9)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sms_get_no_msgs_req(SRC_ID, &a2 , &a3 , &a4 , &a5 , &a6 , &a7 , &a8 , &a9 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SMS_GET_MSG_NUM_RSP /* MSG_ID_MMI_SMS_GET_MSG_NUM_RSP */
		_send_S_k_bool_S_k_bool_S_k_16_S_k_16_S_k_16_S_k_16_S_k_16_S_k_16_S_k_16_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SMS_GET_MSG_NUM_RSP , result , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMS_GET_PROFILE_NUM_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMS_GET_PROFILE_NUM_REQ_
	/* MSG_ID_MMI_SMS_GET_PROFILE_NUM_REQ 	 CALL_FUNC S_k_bool_L_ipS_k_8_ipS_k_8_ */
void _call_MSG_ID_MMI_SMS_GET_PROFILE_NUM_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_8(2) mS_k_8(3)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sms_get_no_profiles_req(SRC_ID, &a2 , &a3 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SMS_GET_PROFILE_NUM_RSP /* MSG_ID_MMI_SMS_GET_PROFILE_NUM_RSP */
		_send_S_k_bool_S_k_8_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SMS_GET_PROFILE_NUM_RSP , result , a2 , a3 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMS_ABORT_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMS_ABORT_REQ_
	/* MSG_ID_MMI_SMS_ABORT_REQ 	 CALL_FUNC S_k_bool_L_ */
void _call_MSG_ID_MMI_SMS_ABORT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sms_exe_abort_req(SRC_ID);
	{
		#ifndef DISABLE_MSG_ID_MMI_SMS_ABORT_RSP /* MSG_ID_MMI_SMS_ABORT_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SMS_ABORT_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMS_SET_MAILBOX_ADDRESS_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMS_SET_MAILBOX_ADDRESS_REQ_
	/* MSG_ID_MMI_SMS_SET_MAILBOX_ADDRESS_REQ */
void _call_MSG_ID_MMI_SMS_SET_MAILBOX_ADDRESS_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_l_number_s_S_l4_name_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sms_set_mailbox_addr_req(SRC_ID, p->a0 , p->a1 , p->a2 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMS_GET_MAILBOX_ADDRESS_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMS_GET_MAILBOX_ADDRESS_REQ_
	/* MSG_ID_MMI_SMS_GET_MAILBOX_ADDRESS_REQ */
void _call_MSG_ID_MMI_SMS_GET_MAILBOX_ADDRESS_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_8(2) mS_k_8(3) m2A_l_sms_mailbox_info_s(4)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sms_get_mailbox_addr_req(SRC_ID, &a2 , &a3 , a4 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SMS_GET_MAILBOX_ADDRESS_RSP /* MSG_ID_MMI_SMS_GET_MAILBOX_ADDRESS_RSP */
		_send_S_k_bool_S_k_8_S_k_8_A2A_l_sms_mailbox_info_s_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SMS_GET_MAILBOX_ADDRESS_RSP , result , a2 , a3 , a4 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMS_SYNC_MSG_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMS_SYNC_MSG_RES_REQ_
	/* MSG_ID_MMI_SMS_SYNC_MSG_RES_REQ 	 CALL_FUNC V_vS_k_bool_ */
void _call_MSG_ID_MMI_SMS_SYNC_MSG_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_bool__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_sms_sync_msg_res_req(p->a0 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMS_STARTUP_READ_NEXT_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMS_STARTUP_READ_NEXT_REQ_
	/* MSG_ID_MMI_SMS_STARTUP_READ_NEXT_REQ 	 CALL_FUNC S_k_bool_L_ */
void _call_MSG_ID_MMI_SMS_STARTUP_READ_NEXT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sms_startup_read_next_req(SRC_ID);
	{
		#ifndef DISABLE_MSG_ID_MMI_SMS_STARTUP_READ_NEXT_RSP /* MSG_ID_MMI_SMS_STARTUP_READ_NEXT_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SMS_STARTUP_READ_NEXT_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMS_COPY_MSG_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMS_COPY_MSG_REQ_
	/* MSG_ID_MMI_SMS_COPY_MSG_REQ */
void _call_MSG_ID_MMI_SMS_COPY_MSG_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_S_k_16__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_sms_copy_msg_req(SRC_ID, p->a0 , p->a1 , p->a2 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMS_GET_MSG_LIST_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMS_GET_MSG_LIST_REQ_
	/* MSG_ID_MMI_SMS_GET_MSG_LIST_REQ */
void _call_MSG_ID_MMI_SMS_GET_MSG_LIST_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_S_k_16_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_sms_exe_read_msg_list_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMS_SEND_FROM_STORAGE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMS_SEND_FROM_STORAGE_REQ_
	/* MSG_ID_MMI_SMS_SEND_FROM_STORAGE_REQ */
void _call_MSG_ID_MMI_SMS_SEND_FROM_STORAGE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_16_S_k_bool_S_l_number_s_S_k_bool__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sms_send_from_storage_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMS_SET_STATUS_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMS_SET_STATUS_REQ_
	/* MSG_ID_MMI_SMS_SET_STATUS_REQ */
void _call_MSG_ID_MMI_SMS_SET_STATUS_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_16_S_k_bool__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sms_set_status_req(SRC_ID, p->a0 , p->a1 , p->a2 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
/* Data Related Messages */
#if defined(__MOD_DATA__)
#ifndef _CALL_FUNC_MSG_ID_MMI_DF_SET_RLP_PARAMS_REQ_
#define _CALL_FUNC_MSG_ID_MMI_DF_SET_RLP_PARAMS_REQ_
	/* MSG_ID_MMI_DF_SET_RLP_PARAMS_REQ */
void _call_MSG_ID_MMI_DF_SET_RLP_PARAMS_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_df_set_rlp_params_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 , p->a4 , p->a5 );
	{
		#ifndef DISABLE_MSG_ID_MMI_DF_SET_RLP_PARAMS_RSP /* MSG_ID_MMI_DF_SET_RLP_PARAMS_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_DF_SET_RLP_PARAMS_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_DF_GET_RLP_PARAMS_REQ_
#define _CALL_FUNC_MSG_ID_MMI_DF_GET_RLP_PARAMS_REQ_
	/* MSG_ID_MMI_DF_GET_RLP_PARAMS_REQ 	 CALL_FUNC S_k_bool_L_ */
void _call_MSG_ID_MMI_DF_GET_RLP_PARAMS_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_df_get_rlp_params_req(SRC_ID);
	{
		#ifndef DISABLE_MSG_ID_MMI_DF_GET_RLP_PARAMS_RSP /* MSG_ID_MMI_DF_GET_RLP_PARAMS_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_DF_GET_RLP_PARAMS_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_DF_SET_V120_PARAMS_REQ_
#define _CALL_FUNC_MSG_ID_MMI_DF_SET_V120_PARAMS_REQ_
	/* MSG_ID_MMI_DF_SET_V120_PARAMS_REQ 	 CALL_FUNC S_k_bool_L_vS_k_8_vS_k_8_vS_k_8_vS_k_8_vS_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_DF_SET_V120_PARAMS_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_df_set_v120_params_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 , p->a4 , p->a5 );
	{
		#ifndef DISABLE_MSG_ID_MMI_DF_SET_V120_PARAMS_RSP /* MSG_ID_MMI_DF_SET_V120_PARAMS_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_DF_SET_V120_PARAMS_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_DF_GET_V120_PARAMS_REQ_
#define _CALL_FUNC_MSG_ID_MMI_DF_GET_V120_PARAMS_REQ_
	/* MSG_ID_MMI_DF_GET_V120_PARAMS_REQ */
void _call_MSG_ID_MMI_DF_GET_V120_PARAMS_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_8(2) mS_k_8(3) mS_k_8(4) mS_k_8(5) mS_k_8(6) mS_k_8(7)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_df_get_v120_params_req(SRC_ID, &a2 , &a3 , &a4 , &a5 , &a6 , &a7 );
	{
		#ifndef DISABLE_MSG_ID_MMI_DF_GET_V120_PARAMS_RSP /* MSG_ID_MMI_DF_GET_V120_PARAMS_RSP */
		_send_S_k_bool_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_DF_GET_V120_PARAMS_RSP , result , a2 , a3 , a4 , a5 , a6 , a7 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_DF_SET_COMP_PARAMS_REQ_
#define _CALL_FUNC_MSG_ID_MMI_DF_SET_COMP_PARAMS_REQ_
	/* MSG_ID_MMI_DF_SET_COMP_PARAMS_REQ */
void _call_MSG_ID_MMI_DF_SET_COMP_PARAMS_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_S_k_16_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_df_set_comp_params_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 );
	{
		#ifndef DISABLE_MSG_ID_MMI_DF_SET_COMP_PARAMS_RSP /* MSG_ID_MMI_DF_SET_COMP_PARAMS_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_DF_SET_COMP_PARAMS_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_DF_GET_COMP_PARAMS_REQ_
#define _CALL_FUNC_MSG_ID_MMI_DF_GET_COMP_PARAMS_REQ_
	/* MSG_ID_MMI_DF_GET_COMP_PARAMS_REQ */
void _call_MSG_ID_MMI_DF_GET_COMP_PARAMS_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_8(2) mS_k_8(3) mS_k_16(4) mS_k_8(5)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_df_get_comp_params_req(SRC_ID, &a2 , &a3 , &a4 , &a5 );
	{
		#ifndef DISABLE_MSG_ID_MMI_DF_GET_COMP_PARAMS_RSP /* MSG_ID_MMI_DF_GET_COMP_PARAMS_RSP */
		_send_S_k_bool_S_k_8_S_k_8_S_k_16_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_DF_GET_COMP_PARAMS_RSP , result , a2 , a3 , a4 , a5 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_DF_SET_BEARER_MODE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_DF_SET_BEARER_MODE_REQ_
	/* MSG_ID_MMI_DF_SET_BEARER_MODE_REQ 	 CALL_FUNC S_k_bool_L_vS_k_8_ */
void _call_MSG_ID_MMI_DF_SET_BEARER_MODE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_df_set_bearer_mode_req(SRC_ID, p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_DF_SET_BEARER_MODE_RSP /* MSG_ID_MMI_DF_SET_BEARER_MODE_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_DF_SET_BEARER_MODE_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_DF_GET_BEARER_MODE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_DF_GET_BEARER_MODE_REQ_
	/* MSG_ID_MMI_DF_GET_BEARER_MODE_REQ 	 CALL_FUNC S_k_bool_L_ipS_k_8_ */
void _call_MSG_ID_MMI_DF_GET_BEARER_MODE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_8(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_df_get_bearer_mode_req(SRC_ID, &a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_DF_GET_BEARER_MODE_RSP /* MSG_ID_MMI_DF_GET_BEARER_MODE_RSP */
		_send_S_k_bool_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_DF_GET_BEARER_MODE_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_DF_SET_CHAR_FRAMING_REQ_
#define _CALL_FUNC_MSG_ID_MMI_DF_SET_CHAR_FRAMING_REQ_
	/* MSG_ID_MMI_DF_SET_CHAR_FRAMING_REQ 	 CALL_FUNC S_k_bool_L_vS_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_DF_SET_CHAR_FRAMING_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_df_set_char_framing_req(SRC_ID, p->a0 , p->a1 );
	{
		#ifndef DISABLE_MSG_ID_MMI_DF_SET_CHAR_FRAMING_RSP /* MSG_ID_MMI_DF_SET_CHAR_FRAMING_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_DF_SET_CHAR_FRAMING_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_DF_GET_CHAR_FRAMING_REQ_
#define _CALL_FUNC_MSG_ID_MMI_DF_GET_CHAR_FRAMING_REQ_
	/* MSG_ID_MMI_DF_GET_CHAR_FRAMING_REQ 	 CALL_FUNC S_k_bool_L_ipS_k_8_ipS_k_8_ */
void _call_MSG_ID_MMI_DF_GET_CHAR_FRAMING_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_8(2) mS_k_8(3)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_df_get_char_framing_req(SRC_ID, &a2 , &a3 );
	{
		#ifndef DISABLE_MSG_ID_MMI_DF_GET_CHAR_FRAMING_RSP /* MSG_ID_MMI_DF_GET_CHAR_FRAMING_RSP */
		_send_S_k_bool_S_k_8_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_DF_GET_CHAR_FRAMING_RSP , result , a2 , a3 );
		#else
		(void) result;
		#endif
	}
}

#endif
#endif /* defined(__MOD_DATA__) */
#ifndef _CALL_FUNC_MSG_ID_MMI_DF_BACK_DATA_STATE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_DF_BACK_DATA_STATE_REQ_
	/* MSG_ID_MMI_DF_BACK_DATA_STATE_REQ 	 CALL_FUNC S_k_bool_N_L_ */
void _call_MSG_ID_MMI_DF_BACK_DATA_STATE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_df_exe_back_data_state_req(SRC_ID);
	NONE
}

#endif
/* GPRS Related Messages */
#if defined(__MOD_TCM__)
#ifndef _CALL_FUNC_MSG_ID_MMI_PS_ACT_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PS_ACT_REQ_
	/* MSG_ID_MMI_PS_ACT_REQ 	 CALL_FUNC S_k_bool_retb_L_vS_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_PS_ACT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ps_exe_act_req(SRC_ID, p->a0 , p->a1 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PS_ACT_TEST_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PS_ACT_TEST_REQ_
	/* MSG_ID_MMI_PS_ACT_TEST_REQ 	 CALL_FUNC S_k_bool_retb_L_vS_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_PS_ACT_TEST_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ps_exe_act_test_req(SRC_ID, p->a0 , p->a1 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PS_ANSWER_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PS_ANSWER_REQ_
	/* MSG_ID_MMI_PS_ANSWER_REQ 	 CALL_FUNC S_k_bool_L_vS_k_8_vS_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_PS_ANSWER_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ps_exe_answer_req(SRC_ID, p->a0 , p->a1 , p->a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_PS_ANSWER_RSP /* MSG_ID_MMI_PS_ANSWER_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_PS_ANSWER_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PS_SET_AUTO_ANSWER_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PS_SET_AUTO_ANSWER_REQ_
	/* MSG_ID_MMI_PS_SET_AUTO_ANSWER_REQ 	 CALL_FUNC S_k_bool_L_vS_k_8_ */
void _call_MSG_ID_MMI_PS_SET_AUTO_ANSWER_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ps_set_auto_answer_req(SRC_ID, p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_PS_SET_AUTO_ANSWER_RSP /* MSG_ID_MMI_PS_SET_AUTO_ANSWER_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_PS_SET_AUTO_ANSWER_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PS_GET_AUTO_ANSWER_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PS_GET_AUTO_ANSWER_REQ_
	/* MSG_ID_MMI_PS_GET_AUTO_ANSWER_REQ 	 CALL_FUNC S_k_bool_L_ipS_k_8_ */
void _call_MSG_ID_MMI_PS_GET_AUTO_ANSWER_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_8(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ps_get_auto_answer_req(SRC_ID, &a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_PS_GET_AUTO_ANSWER_RSP /* MSG_ID_MMI_PS_GET_AUTO_ANSWER_RSP */
		_send_S_k_bool_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_PS_GET_AUTO_ANSWER_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PS_MODIFY_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PS_MODIFY_REQ_
	/* MSG_ID_MMI_PS_MODIFY_REQ 	 CALL_FUNC S_k_bool_retb_L_vS_k_8_ */
void _call_MSG_ID_MMI_PS_MODIFY_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ps_exe_modify_req(SRC_ID, p->a0 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PS_ENTER_DATA_STATE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PS_ENTER_DATA_STATE_REQ_
	/* MSG_ID_MMI_PS_ENTER_DATA_STATE_REQ 	 CALL_FUNC S_k_bool_L_vS_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_PS_ENTER_DATA_STATE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ps_exe_enter_data_state_req(SRC_ID, p->a0 , p->a1 );
	{
		#ifndef DISABLE_MSG_ID_MMI_PS_ENTER_DATA_STATE_RSP /* MSG_ID_MMI_PS_ENTER_DATA_STATE_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_PS_ENTER_DATA_STATE_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PS_SET_DEFINITION_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PS_SET_DEFINITION_REQ_
	/* MSG_ID_MMI_PS_SET_DEFINITION_REQ */
void _call_MSG_ID_MMI_PS_SET_DEFINITION_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_l_prim_pdp_info_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ps_set_definition_req(SRC_ID, &(p->a0) );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PS_GET_DEFINITION_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PS_GET_DEFINITION_REQ_
	/* MSG_ID_MMI_PS_GET_DEFINITION_REQ */
void _call_MSG_ID_MMI_PS_GET_DEFINITION_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_l_prim_pdp_info_list_s(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ps_get_definition_list_req(SRC_ID, &a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_PS_GET_DEFINITION_RSP /* MSG_ID_MMI_PS_GET_DEFINITION_RSP */
		_send_S_k_bool_S_l_prim_pdp_info_list_s_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_PS_GET_DEFINITION_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PS_SET_SEC_DEFINITION_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PS_SET_SEC_DEFINITION_REQ_
	/* MSG_ID_MMI_PS_SET_SEC_DEFINITION_REQ */
void _call_MSG_ID_MMI_PS_SET_SEC_DEFINITION_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_l_sec_pdp_info_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_ps_set_sec_definition_req(SRC_ID, &(p->a0) );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PS_GET_SEC_DEFINITION_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PS_GET_SEC_DEFINITION_REQ_
	/* MSG_ID_MMI_PS_GET_SEC_DEFINITION_REQ */
void _call_MSG_ID_MMI_PS_GET_SEC_DEFINITION_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_l_sec_pdp_info_list_s(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ps_get_sec_definition_list_req(SRC_ID, &a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_PS_GET_SEC_DEFINITION_RSP /* MSG_ID_MMI_PS_GET_SEC_DEFINITION_RSP */
		_send_S_k_bool_S_l_sec_pdp_info_list_s_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_PS_GET_SEC_DEFINITION_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PS_GET_PDP_ADDR_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PS_GET_PDP_ADDR_REQ_
	/* MSG_ID_MMI_PS_GET_PDP_ADDR_REQ */
void _call_MSG_ID_MMI_PS_GET_PDP_ADDR_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	m128A_k_8(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ps_get_pdp_addr_req(SRC_ID, p->a0 , a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_PS_GET_PDP_ADDR_RSP /* MSG_ID_MMI_PS_GET_PDP_ADDR_RSP */
		_send_S_k_bool_A128A_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_PS_GET_PDP_ADDR_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PS_SET_TFT_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PS_SET_TFT_REQ_
	/* MSG_ID_MMI_PS_SET_TFT_REQ */
void _call_MSG_ID_MMI_PS_SET_TFT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_l_tft_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ps_set_tft_req(SRC_ID, &(p->a0) );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PS_GET_TFT_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PS_GET_TFT_REQ_
	/* MSG_ID_MMI_PS_GET_TFT_REQ */
void _call_MSG_ID_MMI_PS_GET_TFT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_l_tft_s(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ps_get_tft_req(SRC_ID, &a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_PS_GET_TFT_RSP /* MSG_ID_MMI_PS_GET_TFT_RSP */
		_send_S_k_bool_S_l_tft_s_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_PS_GET_TFT_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PS_SET_QOS_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PS_SET_QOS_REQ_
	/* MSG_ID_MMI_PS_SET_QOS_REQ */
void _call_MSG_ID_MMI_PS_SET_QOS_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_l_qos_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ps_set_qos_req(SRC_ID, p->a0 , &(p->a1) );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PS_SET_EQOS_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PS_SET_EQOS_REQ_
	/* MSG_ID_MMI_PS_SET_EQOS_REQ */
void _call_MSG_ID_MMI_PS_SET_EQOS_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_l_eqos_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ps_set_eqos_req(SRC_ID, p->a0 , &(p->a1) );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PS_SEND_DATA_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PS_SEND_DATA_REQ_
	/* MSG_ID_MMI_PS_SEND_DATA_REQ */
void _call_MSG_ID_MMI_PS_SEND_DATA_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_32__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ps_exe_send_data_req(SRC_ID, p->a0 , p->a1 );
	{
		#ifndef DISABLE_MSG_ID_MMI_PS_SEND_DATA_RSP /* MSG_ID_MMI_PS_SEND_DATA_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_PS_SEND_DATA_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PS_GET_GPRS_EMPTY_PROFILE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PS_GET_GPRS_EMPTY_PROFILE_REQ_
	/* MSG_ID_MMI_PS_GET_GPRS_EMPTY_PROFILE_REQ 	 CALL_FUNC S_k_bool_L_ipS_k_8_ */
void _call_MSG_ID_MMI_PS_GET_GPRS_EMPTY_PROFILE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_8(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_tcm_get_empty_gprs_prof_req(SRC_ID, &a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_PS_GET_GPRS_EMPTY_PROFILE_RSP /* MSG_ID_MMI_PS_GET_GPRS_EMPTY_PROFILE_RSP */
		_send_S_k_bool_S_k_8_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_PS_GET_GPRS_EMPTY_PROFILE_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PS_GET_GPRS_DATA_COUNTER_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PS_GET_GPRS_DATA_COUNTER_REQ_
	/* MSG_ID_MMI_PS_GET_GPRS_DATA_COUNTER_REQ */
void _call_MSG_ID_MMI_PS_GET_GPRS_DATA_COUNTER_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_l_gprs_statistics_info_s(2)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ps_get_gprs_data_counter_req(&a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_PS_GET_GPRS_DATA_COUNTER_RSP /* MSG_ID_MMI_PS_GET_GPRS_DATA_COUNTER_RSP */
		_send_S_k_bool_S_l_gprs_statistics_info_s_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_PS_GET_GPRS_DATA_COUNTER_RSP , result , a2 );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PS_SET_GPRS_DATA_ACCOUNT_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PS_SET_GPRS_DATA_ACCOUNT_REQ_
	/* MSG_ID_MMI_PS_SET_GPRS_DATA_ACCOUNT_REQ */
void _call_MSG_ID_MMI_PS_SET_GPRS_DATA_ACCOUNT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_l_gprs_account_info_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ps_set_gprs_data_account_req(SRC_ID, &(p->a0) );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PS_GET_GPRS_DATA_ACCOUNT_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PS_GET_GPRS_DATA_ACCOUNT_REQ_
	/* MSG_ID_MMI_PS_GET_GPRS_DATA_ACCOUNT_REQ 	 CALL_FUNC S_k_bool_retb_L_vS_k_8_ */
void _call_MSG_ID_MMI_PS_GET_GPRS_DATA_ACCOUNT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ps_get_gprs_data_account_req(SRC_ID, p->a0 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_PS_RESET_GPRS_DATA_COUNTER_REQ_
#define _CALL_FUNC_MSG_ID_MMI_PS_RESET_GPRS_DATA_COUNTER_REQ_
	/* MSG_ID_MMI_PS_RESET_GPRS_DATA_COUNTER_REQ 	 CALL_FUNC S_k_bool_retb_L_ */
void _call_MSG_ID_MMI_PS_RESET_GPRS_DATA_COUNTER_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ps_reset_gprs_data_counter_req(SRC_ID);
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#endif /* defined(__MOD_TCM__) */
/* STK/SAT Related Messages */
#if defined(__SAT__)
#ifndef _CALL_FUNC_MSG_ID_MMI_SAT_DISPLAY_TEXT_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SAT_DISPLAY_TEXT_RES_REQ_
	/* MSG_ID_MMI_SAT_DISPLAY_TEXT_RES_REQ */
void _call_MSG_ID_MMI_SAT_DISPLAY_TEXT_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_5A_k_8_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4a_sat_dspl_text_res(p->a0 , p->a1 , p->a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SAT_DISPLAY_TEXT_RES_RSP /* MSG_ID_MMI_SAT_DISPLAY_TEXT_RES_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SAT_DISPLAY_TEXT_RES_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SAT_GET_INKEY_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SAT_GET_INKEY_RES_REQ_
	/* MSG_ID_MMI_SAT_GET_INKEY_RES_REQ */
void _call_MSG_ID_MMI_SAT_GET_INKEY_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_5A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_1A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4a_sat_get_inkey_res(p->a0 , p->a1 , p->a2 , p->a3 , p->a4 , p->a5 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SAT_GET_INKEY_RES_RSP /* MSG_ID_MMI_SAT_GET_INKEY_RES_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SAT_GET_INKEY_RES_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SAT_GET_INPUT_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SAT_GET_INPUT_RES_REQ_
	/* MSG_ID_MMI_SAT_GET_INPUT_RES_REQ */
void _call_MSG_ID_MMI_SAT_GET_INPUT_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_5A_k_8_S_k_8_S_k_8_S_k_8_1A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4a_sat_get_input_res(p->a0 , p->a1 , p->a2 , p->a3 , p->a4 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SAT_GET_INPUT_RES_RSP /* MSG_ID_MMI_SAT_GET_INPUT_RES_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SAT_GET_INPUT_RES_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SAT_SETUP_MENU_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SAT_SETUP_MENU_RES_REQ_
	/* MSG_ID_MMI_SAT_SETUP_MENU_RES_REQ */
void _call_MSG_ID_MMI_SAT_SETUP_MENU_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_5A_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4a_sat_setup_menu_res(p->a0 , p->a1 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SAT_SETUP_MENU_RES_RSP /* MSG_ID_MMI_SAT_SETUP_MENU_RES_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SAT_SETUP_MENU_RES_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SAT_SELECT_ITEM_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SAT_SELECT_ITEM_RES_REQ_
	/* MSG_ID_MMI_SAT_SELECT_ITEM_RES_REQ 	 CALL_FUNC S_k_bool_v5A_k_8_vS_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_SAT_SELECT_ITEM_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_5A_k_8_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4a_sat_select_item_res(p->a0 , p->a1 , p->a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SAT_SELECT_ITEM_RES_RSP /* MSG_ID_MMI_SAT_SELECT_ITEM_RES_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SAT_SELECT_ITEM_RES_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SAT_PLAY_TONE_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SAT_PLAY_TONE_RES_REQ_
	/* MSG_ID_MMI_SAT_PLAY_TONE_RES_REQ 	 CALL_FUNC S_k_bool_v5A_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_SAT_PLAY_TONE_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_5A_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4a_sat_play_tone_res(p->a0 , p->a1 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SAT_PLAY_TONE_RES_RSP /* MSG_ID_MMI_SAT_PLAY_TONE_RES_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SAT_PLAY_TONE_RES_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SAT_MENU_SELECT_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SAT_MENU_SELECT_REQ_
	/* MSG_ID_MMI_SAT_MENU_SELECT_REQ */
void _call_MSG_ID_MMI_SAT_MENU_SELECT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4a_sat_exe_menu_select_req(p->a0 , p->a1 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SAT_EVDL_IDLE_SCREEN_AVAILABLE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SAT_EVDL_IDLE_SCREEN_AVAILABLE_REQ_
	/* MSG_ID_MMI_SAT_EVDL_IDLE_SCREEN_AVAILABLE_REQ 	 CALL_FUNC S_k_bool_ */
void _call_MSG_ID_MMI_SAT_EVDL_IDLE_SCREEN_AVAILABLE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sat_evdl_idle_screen_available_req(NONE);
	{
		#ifndef DISABLE_MSG_ID_MMI_SAT_EVDL_IDLE_SCREEN_AVAILABLE_RSP /* MSG_ID_MMI_SAT_EVDL_IDLE_SCREEN_AVAILABLE_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SAT_EVDL_IDLE_SCREEN_AVAILABLE_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SAT_LANGUAGE_SELECTION_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SAT_LANGUAGE_SELECTION_REQ_
	/* MSG_ID_MMI_SAT_LANGUAGE_SELECTION_REQ */
void _call_MSG_ID_MMI_SAT_LANGUAGE_SELECTION_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_2A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sat_evdl_language_selection_req(p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SAT_LANGUAGE_SELECTION_RSP /* MSG_ID_MMI_SAT_LANGUAGE_SELECTION_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SAT_LANGUAGE_SELECTION_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SAT_EVDL_BROWSER_TERMINATION_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SAT_EVDL_BROWSER_TERMINATION_REQ_
	/* MSG_ID_MMI_SAT_EVDL_BROWSER_TERMINATION_REQ 	 CALL_FUNC S_k_bool_vS_k_8_ */
void _call_MSG_ID_MMI_SAT_EVDL_BROWSER_TERMINATION_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sat_evdl_browser_termination_req(p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SAT_EVDL_BROWSER_TERMINATION_RSP /* MSG_ID_MMI_SAT_EVDL_BROWSER_TERMINATION_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SAT_EVDL_BROWSER_TERMINATION_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SAT_CALL_SETUP_STAGE1_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SAT_CALL_SETUP_STAGE1_REQ_
	/* MSG_ID_MMI_SAT_CALL_SETUP_STAGE1_REQ */
void _call_MSG_ID_MMI_SAT_CALL_SETUP_STAGE1_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_41A_k_8_S_k_8_21A_k_8_S_k_8_15A_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4a_sat_call_setup_req(p->a0 , p->a1 , p->a2 , p->a3 , p->a4 , p->a5 , p->a6 , p->a7 );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SAT_CALL_SETUP_STAGE2_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SAT_CALL_SETUP_STAGE2_REQ_
	/* MSG_ID_MMI_SAT_CALL_SETUP_STAGE2_REQ 	 CALL_FUNC S_k_bool_v5A_k_8_vS_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_SAT_CALL_SETUP_STAGE2_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_5A_k_8_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4a_sat_setup_call_res(p->a0 , p->a1 , p->a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SAT_CALL_SETUP_STAGE2_RSP /* MSG_ID_MMI_SAT_CALL_SETUP_STAGE2_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SAT_CALL_SETUP_STAGE2_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SAT_SEND_SMS_STAGE1_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SAT_SEND_SMS_STAGE1_REQ_
	/* MSG_ID_MMI_SAT_SEND_SMS_STAGE1_REQ */
void _call_MSG_ID_MMI_SAT_SEND_SMS_STAGE1_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_41A_k_8_S_k_8_175A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4a_sat_send_sms_req(p->a0 , p->a1 , p->a2 , p->a3 , p->a4 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SAT_SEND_SMS_STAGE2_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SAT_SEND_SMS_STAGE2_REQ_
	/* MSG_ID_MMI_SAT_SEND_SMS_STAGE2_REQ 	 CALL_FUNC S_k_bool_v5A_k_8_vS_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_SAT_SEND_SMS_STAGE2_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_5A_k_8_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4a_sat_send_sms_res(p->a0 , p->a1 , p->a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SAT_SEND_SMS_STAGE2_RSP /* MSG_ID_MMI_SAT_SEND_SMS_STAGE2_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SAT_SEND_SMS_STAGE2_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SAT_SEND_SS_STAGE1_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SAT_SEND_SS_STAGE1_REQ_
	/* MSG_ID_MMI_SAT_SEND_SS_STAGE1_REQ */
void _call_MSG_ID_MMI_SAT_SEND_SS_STAGE1_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_183A_k_8_S_k_8_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4a_sat_send_ss_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SAT_SEND_SS_STAGE2_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SAT_SEND_SS_STAGE2_REQ_
	/* MSG_ID_MMI_SAT_SEND_SS_STAGE2_REQ */
void _call_MSG_ID_MMI_SAT_SEND_SS_STAGE2_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_5A_k_8_S_k_8_S_k_8_255A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4a_sat_send_ss_res(p->a0 , p->a1 , p->a2 , p->a3 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SAT_SEND_SS_STAGE2_RSP /* MSG_ID_MMI_SAT_SEND_SS_STAGE2_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SAT_SEND_SS_STAGE2_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SAT_SEND_USSD_STAGE1_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SAT_SEND_USSD_STAGE1_REQ_
	/* MSG_ID_MMI_SAT_SEND_USSD_STAGE1_REQ */
void _call_MSG_ID_MMI_SAT_SEND_USSD_STAGE1_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_183A_k_8_S_k_8_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4a_sat_send_ussd_req(p->a0 , p->a1 , p->a2 , p->a3 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SAT_SEND_USSD_STAGE2_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SAT_SEND_USSD_STAGE2_REQ_
	/* MSG_ID_MMI_SAT_SEND_USSD_STAGE2_REQ 	 CALL_FUNC S_k_bool_v5A_k_8_vS_k_8_vS_k_8_v255A_k_8_ */
void _call_MSG_ID_MMI_SAT_SEND_USSD_STAGE2_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_5A_k_8_S_k_8_S_k_8_255A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4a_sat_send_ussd_res(p->a0 , p->a1 , p->a2 , p->a3 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SAT_SEND_USSD_STAGE2_RSP /* MSG_ID_MMI_SAT_SEND_USSD_STAGE2_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SAT_SEND_USSD_STAGE2_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SAT_SETUP_IDLE_DISPLAY_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SAT_SETUP_IDLE_DISPLAY_RES_REQ_
	/* MSG_ID_MMI_SAT_SETUP_IDLE_DISPLAY_RES_REQ 	 CALL_FUNC S_k_bool_v5A_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_SAT_SETUP_IDLE_DISPLAY_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_5A_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4a_sat_setup_idle_dspl_res(p->a0 , p->a1 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SAT_SETUP_IDLE_DISPLAY_RES_RSP /* MSG_ID_MMI_SAT_SETUP_IDLE_DISPLAY_RES_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SAT_SETUP_IDLE_DISPLAY_RES_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SAT_SEND_DTMF_STAGE1_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SAT_SEND_DTMF_STAGE1_REQ_
	/* MSG_ID_MMI_SAT_SEND_DTMF_STAGE1_REQ */
void _call_MSG_ID_MMI_SAT_SEND_DTMF_STAGE1_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_21A_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_sat_send_dtmf_req(SRC_ID, p->a0 , p->a1 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SAT_SEND_DTMF_STAGE2_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SAT_SEND_DTMF_STAGE2_REQ_
	/* MSG_ID_MMI_SAT_SEND_DTMF_STAGE2_REQ 	 CALL_FUNC S_k_bool_v5A_k_8_vS_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_SAT_SEND_DTMF_STAGE2_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_5A_k_8_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sat_send_dtmf_res(p->a0 , p->a1 , p->a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SAT_SEND_DTMF_STAGE2_RSP /* MSG_ID_MMI_SAT_SEND_DTMF_STAGE2_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SAT_SEND_DTMF_STAGE2_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SAT_ABORT_DTMF_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SAT_ABORT_DTMF_REQ_
	/* MSG_ID_MMI_SAT_ABORT_DTMF_REQ 	 CALL_FUNC S_k_bool_L_ */
void _call_MSG_ID_MMI_SAT_ABORT_DTMF_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sat_abort_dtmf_req(SRC_ID);
	{
		#ifndef DISABLE_MSG_ID_MMI_SAT_ABORT_DTMF_RSP /* MSG_ID_MMI_SAT_ABORT_DTMF_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SAT_ABORT_DTMF_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SAT_LANG_NOTIFY_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SAT_LANG_NOTIFY_RES_REQ_
	/* MSG_ID_MMI_SAT_LANG_NOTIFY_RES_REQ 	 CALL_FUNC S_k_bool_v5A_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_SAT_LANG_NOTIFY_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_5A_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4a_sat_lang_notify_res(p->a0 , p->a1 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SAT_LANG_NOTIFY_RES_RSP /* MSG_ID_MMI_SAT_LANG_NOTIFY_RES_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SAT_LANG_NOTIFY_RES_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SAT_LAUNCH_BROWSER_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SAT_LAUNCH_BROWSER_RES_REQ_
	/* MSG_ID_MMI_SAT_LAUNCH_BROWSER_RES_REQ 	 CALL_FUNC S_k_bool_v5A_k_8_vS_k_8_vS_k_8_v255A_k_8_ */
void _call_MSG_ID_MMI_SAT_LAUNCH_BROWSER_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_5A_k_8_S_k_8_S_k_8_255A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sat_launch_browser_res(p->a0 , p->a1 , p->a2 , p->a3 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SAT_LAUNCH_BROWSER_RES_RSP /* MSG_ID_MMI_SAT_LAUNCH_BROWSER_RES_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SAT_LAUNCH_BROWSER_RES_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#endif /* defined(__SAT__) */
/* STK_CE */
#if defined(__SATCE__)
#ifndef _CALL_FUNC_MSG_ID_MMI_SAT_OPEN_CHANNEL_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SAT_OPEN_CHANNEL_REQ_
	/* MSG_ID_MMI_SAT_OPEN_CHANNEL_REQ */
void _call_MSG_ID_MMI_SAT_OPEN_CHANNEL_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_5A_k_8_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_sat_open_channel_req(p->a0 , p->a1 , p->a2 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SAT_CLOSE_CHANNEL_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SAT_CLOSE_CHANNEL_REQ_
	/* MSG_ID_MMI_SAT_CLOSE_CHANNEL_REQ */
void _call_MSG_ID_MMI_SAT_CLOSE_CHANNEL_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_5A_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_sat_close_channel_req(p->a0 , p->a1 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SAT_SEND_DATA_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SAT_SEND_DATA_REQ_
	/* MSG_ID_MMI_SAT_SEND_DATA_REQ 	 CALL_FUNC S_k_bool_N_v5A_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_SAT_SEND_DATA_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_5A_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_sat_send_data_req(p->a0 , p->a1 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SAT_RECV_DATA_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SAT_RECV_DATA_REQ_
	/* MSG_ID_MMI_SAT_RECV_DATA_REQ 	 CALL_FUNC S_k_bool_N_v5A_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_SAT_RECV_DATA_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_5A_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_sat_recv_data_req(p->a0 , p->a1 );
	NONE
}

#endif
#endif /* defined(__SATCE__) */
#ifndef _CALL_FUNC_MSG_ID_MMI_CB_SUBSCRIBE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CB_SUBSCRIBE_REQ_
	/* MSG_ID_MMI_CB_SUBSCRIBE_REQ 	 CALL_FUNC S_k_bool_L_vS_k_8_ */
void _call_MSG_ID_MMI_CB_SUBSCRIBE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_cb_subscribe_req(SRC_ID, p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_CB_SUBSCRIBE_RSP /* MSG_ID_MMI_CB_SUBSCRIBE_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_CB_SUBSCRIBE_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMS_SET_CB_MODE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMS_SET_CB_MODE_REQ_
	/* MSG_ID_MMI_SMS_SET_CB_MODE_REQ */
void _call_MSG_ID_MMI_SMS_SET_CB_MODE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_l_cb_info_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sms_set_cb_mode_req(SRC_ID, &(p->a0) );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMS_GET_CB_MODE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMS_GET_CB_MODE_REQ_
	/* MSG_ID_MMI_SMS_GET_CB_MODE_REQ */
void _call_MSG_ID_MMI_SMS_GET_CB_MODE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	mS_k_8(2) mS_k_8(3) mS_k_8(4) mS_k_8(5) mS_l_cb_info_s(6)  /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_sms_get_cb_mode_req(SRC_ID, &a2 , &a3 , &a4 , &a5 , &a6 );
	{
		#ifndef DISABLE_MSG_ID_MMI_SMS_GET_CB_MODE_RSP /* MSG_ID_MMI_SMS_GET_CB_MODE_RSP */
		_send_S_k_bool_S_k_8_S_k_8_S_k_8_S_k_8_S_l_cb_info_s_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_SMS_GET_CB_MODE_RSP , result , a2 , a3 , a4 , a5 , a6 );
		#else
		(void) result;
		#endif
	}
}

#endif
/* Engineer Mode-UEM */
#if defined(__MOD_UEM__)
#ifndef _CALL_FUNC_MSG_ID_MMI_EM_SET_GAIN_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EM_SET_GAIN_REQ_
	/* MSG_ID_MMI_EM_SET_GAIN_REQ 	 CALL_FUNC S_k_bool_retb_L_vS_k_8_vS_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_EM_SET_GAIN_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_set_gain_req(SRC_ID, p->a0 , p->a1 , p->a2 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#endif /* defined(__MOD_UEM__) */
/* Engineer Mode */
#if defined(__EM_MODE__)
#ifndef _CALL_FUNC_MSG_ID_MMI_EM_START_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EM_START_REQ_
	/* MSG_ID_MMI_EM_START_REQ */
void _call_MSG_ID_MMI_EM_START_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_module_type_S_request_info_type__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_em_start_req(SRC_ID, p->a0 , p->a1 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EM_STOP_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EM_STOP_REQ_
	/* MSG_ID_MMI_EM_STOP_REQ 	 CALL_FUNC V_L_vS_module_type_vS_request_info_type_ */
void _call_MSG_ID_MMI_EM_STOP_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_module_type_S_request_info_type__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_em_stop_req(SRC_ID, p->a0 , p->a1 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EM_SET_CELL_ID_LOCK_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EM_SET_CELL_ID_LOCK_REQ_
	/* MSG_ID_MMI_EM_SET_CELL_ID_LOCK_REQ */
void _call_MSG_ID_MMI_EM_SET_CELL_ID_LOCK_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_16A_rr_em_lai_info_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_em_set_cell_id_lock_req(SRC_ID, p->a0 , p->a1 );
	NONE
}

#endif
#endif /* defined(__EM_MODE__) */
#ifndef _CALL_FUNC_MSG_ID_MMI_EM_KEYPAD_EVENT_OUTPUT_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EM_KEYPAD_EVENT_OUTPUT_REQ_
	/* MSG_ID_MMI_EM_KEYPAD_EVENT_OUTPUT_REQ 	 CALL_FUNC S_k_bool_L_vS_k_8_vS_k_8_ */
void _call_MSG_ID_MMI_EM_KEYPAD_EVENT_OUTPUT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_em_keypad_event_output_req(SRC_ID, p->a0 , p->a1 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EM_KEYPAD_EVENT_OUTPUT_RSP /* MSG_ID_MMI_EM_KEYPAD_EVENT_OUTPUT_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EM_KEYPAD_EVENT_OUTPUT_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_UPDATE_MMI_DEFAULT_PROF_VALUE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_UPDATE_MMI_DEFAULT_PROF_VALUE_REQ_
	/* MSG_ID_MMI_UPDATE_MMI_DEFAULT_PROF_VALUE_REQ */
void _call_MSG_ID_MMI_UPDATE_MMI_DEFAULT_PROF_VALUE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_update_mmi_default_prof_value_req(p->a0 , p->a1 , p->a2 , p->a3 );
	{
		#ifndef DISABLE_MSG_ID_MMI_UPDATE_MMI_DEFAULT_PROF_VALUE_RSP /* MSG_ID_MMI_UPDATE_MMI_DEFAULT_PROF_VALUE_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_UPDATE_MMI_DEFAULT_PROF_VALUE_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EM_CELL_RESEL_SUSPEND_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EM_CELL_RESEL_SUSPEND_REQ_
	/* MSG_ID_MMI_EM_CELL_RESEL_SUSPEND_REQ 	 CALL_FUNC V_L_vS_k_8_ */
void _call_MSG_ID_MMI_EM_CELL_RESEL_SUSPEND_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_em_cell_resel_suspend_req(SRC_ID, p->a0 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EM_CELL_RESEL_RESUME_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EM_CELL_RESEL_RESUME_REQ_
	/* MSG_ID_MMI_EM_CELL_RESEL_RESUME_REQ */
void _call_MSG_ID_MMI_EM_CELL_RESEL_RESUME_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_em_cell_resel_resume_req(SRC_ID);
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EM_GET_CELL_LOCK_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EM_GET_CELL_LOCK_REQ_
	/* MSG_ID_MMI_EM_GET_CELL_LOCK_REQ 	 CALL_FUNC V_L_ */
void _call_MSG_ID_MMI_EM_GET_CELL_LOCK_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_em_get_cell_lock_req(SRC_ID);
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EM_SET_CELL_LOCK_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EM_SET_CELL_LOCK_REQ_
	/* MSG_ID_MMI_EM_SET_CELL_LOCK_REQ */
void _call_MSG_ID_MMI_EM_SET_CELL_LOCK_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_bool_S_k_bool_S_k_16__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_em_set_cell_lock_req(SRC_ID, p->a0 , p->a1 , p->a2 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EM_NW_EVENT_NOTIFY_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EM_NW_EVENT_NOTIFY_REQ_
	/* MSG_ID_MMI_EM_NW_EVENT_NOTIFY_REQ */
void _call_MSG_ID_MMI_EM_NW_EVENT_NOTIFY_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_bool_S_k_8_20A_module_type__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_em_nw_event_notify_req(SRC_ID, p->a0 , p->a1 , p->a2 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EM_FEATURE_COMMAND_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EM_FEATURE_COMMAND_REQ_
	/* MSG_ID_MMI_EM_FEATURE_COMMAND_REQ */
void _call_MSG_ID_MMI_EM_FEATURE_COMMAND_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_em_feature_command_req(SRC_ID, p->a0 , p->a1 );
	NONE
}

#endif
/* Audio Task - Voice Memo(via FS) */
#if defined(__FS_ON__)
#ifndef _CALL_FUNC_MSG_ID_MMI_VM_PLAY_REQ_
#define _CALL_FUNC_MSG_ID_MMI_VM_PLAY_REQ_
	/* MSG_ID_MMI_VM_PLAY_REQ */
void _call_MSG_ID_MMI_VM_PLAY_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_20A_k_wchar__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_vm_play_req(SRC_ID, p->a0 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_VM_DEL_REQ_
#define _CALL_FUNC_MSG_ID_MMI_VM_DEL_REQ_
	/* MSG_ID_MMI_VM_DEL_REQ */
void _call_MSG_ID_MMI_VM_DEL_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_20A_k_wchar_S_k_bool__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_vm_delete_req(SRC_ID, p->a0 , p->a1 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_VM_APPEND_REQ_
#define _CALL_FUNC_MSG_ID_MMI_VM_APPEND_REQ_
	/* MSG_ID_MMI_VM_APPEND_REQ 	 CALL_FUNC S_k_bool_retb_L_v20A_k_wchar_ */
void _call_MSG_ID_MMI_VM_APPEND_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_20A_k_wchar__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_vm_append_req(SRC_ID, p->a0 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_VM_RENAME_REQ_
#define _CALL_FUNC_MSG_ID_MMI_VM_RENAME_REQ_
	/* MSG_ID_MMI_VM_RENAME_REQ */
void _call_MSG_ID_MMI_VM_RENAME_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_20A_k_wchar_20A_k_wchar__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_vm_rename_req(SRC_ID, p->a0 , p->a1 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_VM_GET_INFO_REQ_
#define _CALL_FUNC_MSG_ID_MMI_VM_GET_INFO_REQ_
	/* MSG_ID_MMI_VM_GET_INFO_REQ 	 CALL_FUNC S_k_bool_N_L_ */
void _call_MSG_ID_MMI_VM_GET_INFO_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_eq_vm_get_info_req(SRC_ID);
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_VM_STOP_REQ_
#define _CALL_FUNC_MSG_ID_MMI_VM_STOP_REQ_
	/* MSG_ID_MMI_VM_STOP_REQ 	 CALL_FUNC S_k_bool_retr_L_ */
void _call_MSG_ID_MMI_VM_STOP_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_vm_stop_req(SRC_ID);
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_VM_ABORT_REQ_
#define _CALL_FUNC_MSG_ID_MMI_VM_ABORT_REQ_
	/* MSG_ID_MMI_VM_ABORT_REQ 	 CALL_FUNC S_k_bool_retb_L_ */
void _call_MSG_ID_MMI_VM_ABORT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_vm_abort_req(SRC_ID);
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_VM_PAUSE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_VM_PAUSE_REQ_
	/* MSG_ID_MMI_VM_PAUSE_REQ 	 CALL_FUNC S_k_bool_retr_L_ */
void _call_MSG_ID_MMI_VM_PAUSE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_vm_pause_req(SRC_ID);
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_VM_RESUME_REQ_
#define _CALL_FUNC_MSG_ID_MMI_VM_RESUME_REQ_
	/* MSG_ID_MMI_VM_RESUME_REQ 	 CALL_FUNC S_k_bool_retb_L_ */
void _call_MSG_ID_MMI_VM_RESUME_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_vm_resume_req(SRC_ID);
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_VM_RECORD_REQ_
#define _CALL_FUNC_MSG_ID_MMI_VM_RECORD_REQ_
	/* MSG_ID_MMI_VM_RECORD_REQ 	 CALL_FUNC S_k_bool_retb_L_vS_k_8_ */
void _call_MSG_ID_MMI_VM_RECORD_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_vm_record_req(SRC_ID, p->a0 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#endif /* defined(__FS_ON__) */
#ifndef _CALL_FUNC_MSG_ID_MMI_CPHS_UPDATE_ALS_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CPHS_UPDATE_ALS_REQ_
	/* MSG_ID_MMI_CPHS_UPDATE_ALS_REQ */
void _call_MSG_ID_MMI_CPHS_UPDATE_ALS_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_cphs_update_als_req(SRC_ID, p->a0 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_WAP_START_DTMF_REQ_
#define _CALL_FUNC_MSG_ID_WAP_START_DTMF_REQ_
	/* MSG_ID_WAP_START_DTMF_REQ 	 CALL_FUNC S_k_bool_N_L_vS_k_8_ */
void _call_MSG_ID_WAP_START_DTMF_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4a_wap_cc_send_dtmf_req(SRC_ID, p->a0 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_WAP_STOP_DTMF_REQ_
#define _CALL_FUNC_MSG_ID_WAP_STOP_DTMF_REQ_
	/* MSG_ID_WAP_STOP_DTMF_REQ 	 CALL_FUNC S_k_bool_N_L_ */
void _call_MSG_ID_WAP_STOP_DTMF_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	l4a_wap_cc_stop_dtmf_req(SRC_ID);
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_WAP_DIAL_REQ_
#define _CALL_FUNC_MSG_ID_WAP_DIAL_REQ_
	/* MSG_ID_WAP_DIAL_REQ */
void _call_MSG_ID_WAP_DIAL_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_bool__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4a_wap_cc_call_setup_req(SRC_ID, p->a0 , p->a1 , p->a2 , p->a3 , p->a4 );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
#ifndef _CALL_FUNC_MSG_ID_WAP_SET_ENTRY_REQ_
#define _CALL_FUNC_MSG_ID_WAP_SET_ENTRY_REQ_
	/* MSG_ID_WAP_SET_ENTRY_REQ 	 CALL_FUNC S_k_bool_retr_L_vS_k_8_vS_k_16_pS_l_phb_entry_s_ */
void _call_MSG_ID_WAP_SET_ENTRY_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_16_S_l_phb_entry_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4a_wap_phb_exe_write_entry_req(SRC_ID, p->a0 , p->a1 , &(p->a2) );
	IF_CALL_FAIL_RETURN_RESULT_STRUCT
}

#endif
/* IrDA */
#if defined(__IRDA_SUPPORT__)
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_IRDA_OPEN_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_IRDA_OPEN_REQ_
	/* MSG_ID_MMI_EQ_IRDA_OPEN_REQ */
void _call_MSG_ID_MMI_EQ_IRDA_OPEN_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_16__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_irda_open_req(p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_IRDA_OPEN_RSP /* MSG_ID_MMI_EQ_IRDA_OPEN_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_IRDA_OPEN_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_IRDA_CLOSE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_IRDA_CLOSE_REQ_
	/* MSG_ID_MMI_EQ_IRDA_CLOSE_REQ 	 CALL_FUNC S_k_bool_ */
void _call_MSG_ID_MMI_EQ_IRDA_CLOSE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_irda_close_req(NONE);
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_IRDA_CLOSE_RSP /* MSG_ID_MMI_EQ_IRDA_CLOSE_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_IRDA_CLOSE_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#endif /* defined(__IRDA_SUPPORT__) */
/* USB */
#if defined(__USB_ENABLE__)
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_USBCONFIG_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_USBCONFIG_REQ_
	/* MSG_ID_MMI_EQ_USBCONFIG_REQ */
void _call_MSG_ID_MMI_EQ_USBCONFIG_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_32__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_usbconfig_req(SRC_ID, p->a0 , p->a1 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_USBUART_SWITCH_PORT_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_USBUART_SWITCH_PORT_REQ_
	/* MSG_ID_MMI_EQ_USBUART_SWITCH_PORT_REQ */
void _call_MSG_ID_MMI_EQ_USBUART_SWITCH_PORT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_UART_PORT__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_usbuart_switch_port_req(SRC_ID, p->a0 , p->a1 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_USBUART_SWITCH_PORT_RSP /* MSG_ID_MMI_EQ_USBUART_SWITCH_PORT_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_USBUART_SWITCH_PORT_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_USBDETECT_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_USBDETECT_RES_REQ_
	/* MSG_ID_MMI_EQ_USBDETECT_RES_REQ 	 CALL_FUNC V_L_vS_k_8_ */
void _call_MSG_ID_MMI_EQ_USBDETECT_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_eq_usbdetect_res_req(SRC_ID, p->a0 );
	NONE
}

#endif
#endif /* defined(__USB_ENABLE__) */
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_DATA_DL_FILELIST_REPORT_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_DATA_DL_FILELIST_REPORT_REQ_
	/* MSG_ID_MMI_EQ_DATA_DL_FILELIST_REPORT_REQ */
void _call_MSG_ID_MMI_EQ_DATA_DL_FILELIST_REPORT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_void_p_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_data_dl_filelist_report_req(SRC_ID, p->a0 , p->a1 , p->a2 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_DATA_DL_FILELIST_REPORT_RSP /* MSG_ID_MMI_EQ_DATA_DL_FILELIST_REPORT_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_DATA_DL_FILELIST_REPORT_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_DATA_DL_FILE_MODIFY_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_DATA_DL_FILE_MODIFY_REQ_
	/* MSG_ID_MMI_EQ_DATA_DL_FILE_MODIFY_REQ 	 CALL_FUNC S_k_bool_vS_k_bool_ */
void _call_MSG_ID_MMI_EQ_DATA_DL_FILE_MODIFY_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_bool__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_data_dl_file_modify_req(p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_DATA_DL_FILE_MODIFY_RSP /* MSG_ID_MMI_EQ_DATA_DL_FILE_MODIFY_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_DATA_DL_FILE_MODIFY_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_DATA_DL_EXECUTE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_DATA_DL_EXECUTE_REQ_
	/* MSG_ID_MMI_EQ_DATA_DL_EXECUTE_REQ 	 CALL_FUNC S_k_bool_vS_k_bool_ */
void _call_MSG_ID_MMI_EQ_DATA_DL_EXECUTE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_bool__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_eq_data_dl_execute_req(p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_EQ_DATA_DL_EXECUTE_RSP /* MSG_ID_MMI_EQ_DATA_DL_EXECUTE_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_EQ_DATA_DL_EXECUTE_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#ifndef _CALL_FUNC_MSG_ID_WAP_MMC_READ_FOLDER_STATUS_OUTPUT_REQ_
#define _CALL_FUNC_MSG_ID_WAP_MMC_READ_FOLDER_STATUS_OUTPUT_REQ_
	/* MSG_ID_WAP_MMC_READ_FOLDER_STATUS_OUTPUT_REQ */
void _call_MSG_ID_WAP_MMC_READ_FOLDER_STATUS_OUTPUT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_32_S_k_32_100A_k_8_100A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_mms_folder_status_output_req(p->a0 , p->a1 , p->a2 , p->a3 , p->a4 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_WAP_MMC_UPLOAD_MSG_OUTPUT_REQ_
#define _CALL_FUNC_MSG_ID_WAP_MMC_UPLOAD_MSG_OUTPUT_REQ_
	/* MSG_ID_WAP_MMC_UPLOAD_MSG_OUTPUT_REQ */
void _call_MSG_ID_WAP_MMC_UPLOAD_MSG_OUTPUT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_32__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_mms_upload_msg_output_req(p->a0 , p->a1 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_WAP_MMC_DELETE_MSG_OUTPUT_REQ_
#define _CALL_FUNC_MSG_ID_WAP_MMC_DELETE_MSG_OUTPUT_REQ_
	/* MSG_ID_WAP_MMC_DELETE_MSG_OUTPUT_REQ */
void _call_MSG_ID_WAP_MMC_DELETE_MSG_OUTPUT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_mms_delete_msg_output_req(p->a0 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_QUERY_GREETING_TEXT_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_QUERY_GREETING_TEXT_RES_REQ_
	/* MSG_ID_MMI_EQ_QUERY_GREETING_TEXT_RES_REQ */
void _call_MSG_ID_MMI_EQ_QUERY_GREETING_TEXT_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_bool_S_k_8_62A_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_eq_query_greeting_text_res_req(p->a0 , p->a1 , p->a2 , p->a3 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_QUERY_LANGUAGE_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_QUERY_LANGUAGE_RES_REQ_
	/* MSG_ID_MMI_EQ_QUERY_LANGUAGE_RES_REQ 	 CALL_FUNC V_vS_k_8_ */
void _call_MSG_ID_MMI_EQ_QUERY_LANGUAGE_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_eq_query_language_res_req(p->a0 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_QUERY_SILENT_MODE_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_QUERY_SILENT_MODE_RES_REQ_
	/* MSG_ID_MMI_EQ_QUERY_SILENT_MODE_RES_REQ 	 CALL_FUNC V_vS_k_bool_ */
void _call_MSG_ID_MMI_EQ_QUERY_SILENT_MODE_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_bool__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_eq_query_silent_mode_res_req(p->a0 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_QUERY_VIBRATOR_MODE_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_QUERY_VIBRATOR_MODE_RES_REQ_
	/* MSG_ID_MMI_EQ_QUERY_VIBRATOR_MODE_RES_REQ 	 CALL_FUNC V_vS_k_bool_ */
void _call_MSG_ID_MMI_EQ_QUERY_VIBRATOR_MODE_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_bool__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_eq_query_vibrator_mode_res_req(p->a0 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_QUERY_DATE_TIME_FORMAT_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_QUERY_DATE_TIME_FORMAT_RES_REQ_
	/* MSG_ID_MMI_EQ_QUERY_DATE_TIME_FORMAT_RES_REQ */
void _call_MSG_ID_MMI_EQ_QUERY_DATE_TIME_FORMAT_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_bool_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_eq_query_datetime_format_res_req(p->a0 , p->a1 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_QUERY_MUTE_MODE_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_QUERY_MUTE_MODE_RES_REQ_
	/* MSG_ID_MMI_EQ_QUERY_MUTE_MODE_RES_REQ 	 CALL_FUNC V_vS_k_bool_ */
void _call_MSG_ID_MMI_EQ_QUERY_MUTE_MODE_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_bool__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_eq_query_mute_mode_res_req(p->a0 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_READY_NOTIFY_REQ_
#define _CALL_FUNC_MSG_ID_MMI_READY_NOTIFY_REQ_
	/* MSG_ID_MMI_READY_NOTIFY_REQ */
void _call_MSG_ID_MMI_READY_NOTIFY_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_mmi_ready_notify_req(NONE);
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_AT_GENERAL_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_AT_GENERAL_RES_REQ_
	/* MSG_ID_MMI_AT_GENERAL_RES_REQ 	 CALL_FUNC V_vS_k_bool_ */
void _call_MSG_ID_MMI_AT_GENERAL_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_bool__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_at_general_res_req(p->a0 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_VCARD_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_VCARD_RES_REQ_
	/* MSG_ID_MMI_EQ_VCARD_RES_REQ */
void _call_MSG_ID_MMI_EQ_VCARD_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_bool_50A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_eq_vcard_res_req(p->a0 , p->a1 , p->a2 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_VCALENDAR_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_VCALENDAR_RES_REQ_
	/* MSG_ID_MMI_EQ_VCALENDAR_RES_REQ */
void _call_MSG_ID_MMI_EQ_VCALENDAR_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_bool_S_k_8_S_k_8_50A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_eq_vcalendar_res_req(p->a0 , p->a1 , p->a2 , p->a3 , p->a4 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_EQ_STR_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_EQ_STR_RES_REQ_
	/* MSG_ID_MMI_EQ_STR_RES_REQ */
void _call_MSG_ID_MMI_EQ_STR_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_16_250A_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_eq_str_res_req(p->a0 , p->a1 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_UCM_AT_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_UCM_AT_RES_REQ_
	/* MSG_ID_MMI_UCM_AT_RES_REQ */
void _call_MSG_ID_MMI_UCM_AT_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_mmi_ucm_at_res_req(p->a0 , p->a1 , p->a2 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_UCM_GENERAL_RCODE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_UCM_GENERAL_RCODE_REQ_
	/* MSG_ID_MMI_UCM_GENERAL_RCODE_REQ */
void _call_MSG_ID_MMI_UCM_GENERAL_RCODE_REQ_ (module_type RSP_DEST,kal_uint8 SRC_ID,msg_type msg_req,msg_S_k_8_S_k_8_S_k_8_S_k_8_S_l_number_s__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_mmi_ucm_rcode_req(p->a0 , p->a1 , p->a2 , p->a3 , p->a4 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_UCM_HF_CIEV_RCODE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_UCM_HF_CIEV_RCODE_REQ_
	/* MSG_ID_MMI_UCM_HF_CIEV_RCODE_REQ */
void _call_MSG_ID_MMI_UCM_HF_CIEV_RCODE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_mmi_ucm_hf_ciev_req(p->a0 , p->a1 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_JAVA_LOCAL_INSTALL_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_JAVA_LOCAL_INSTALL_RES_REQ_
	/* MSG_ID_MMI_JAVA_LOCAL_INSTALL_RES_REQ */
void _call_MSG_ID_MMI_JAVA_LOCAL_INSTALL_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_32__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_mmi_java_local_install_res_req(p->a0 );
	NONE
}

#endif
/* Bluetooth */
#if defined(__BT_SUPPORT__)
#ifndef _CALL_FUNC_MSG_ID_MMI_L4_BT_SET_VR_REQ_
#define _CALL_FUNC_MSG_ID_MMI_L4_BT_SET_VR_REQ_
	/* MSG_ID_MMI_L4_BT_SET_VR_REQ 	 CALL_FUNC S_k_bool_L_vS_k_bool_ */
void _call_MSG_ID_MMI_L4_BT_SET_VR_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_bool__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_bt_set_vr_req(SRC_ID, p->a0 );
	{
		#ifndef DISABLE_MSG_ID_MMI_L4_BT_SET_VR_RSP /* MSG_ID_MMI_L4_BT_SET_VR_RSP */
		_send_S_k_bool_(l4c_current_mod_id, RSP_DEST, MSG_ID_MMI_L4_BT_SET_VR_RSP , result );
		#else
		(void) result;
		#endif
	}
}

#endif
#endif /* defined(__BT_SUPPORT__) */
/* HOMEZONE */
#if defined(__HOMEZONE_SUPPORT__)
#endif /* defined(__HOMEZONE_SUPPORT__) */
/* CTM */
#if defined(__CTM_SUPPORT__)
#ifndef _CALL_FUNC_MSG_ID_MMI_CTM_OPEN_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CTM_OPEN_REQ_
	/* MSG_ID_MMI_CTM_OPEN_REQ 	 CALL_FUNC S_k_bool_retb_L_vS_k_8_ */
void _call_MSG_ID_MMI_CTM_OPEN_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ctm_open_req(SRC_ID, p->a0 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CTM_CLOSE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CTM_CLOSE_REQ_
	/* MSG_ID_MMI_CTM_CLOSE_REQ 	 CALL_FUNC S_k_bool_retb_L_ */
void _call_MSG_ID_MMI_CTM_CLOSE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ctm_close_req(SRC_ID);
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CTM_CONNECT_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CTM_CONNECT_REQ_
	/* MSG_ID_MMI_CTM_CONNECT_REQ 	 CALL_FUNC S_k_bool_retb_L_ */
void _call_MSG_ID_MMI_CTM_CONNECT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ctm_connect_req(SRC_ID);
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CTM_SEND_TEXT_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CTM_SEND_TEXT_REQ_
	/* MSG_ID_MMI_CTM_SEND_TEXT_REQ */
void _call_MSG_ID_MMI_CTM_SEND_TEXT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_16_v7A_k_16__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ctm_send_text_req(SRC_ID, p->a0 , p->a1 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CTM_SET_DEFAULT_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CTM_SET_DEFAULT_REQ_
	/* MSG_ID_MMI_CTM_SET_DEFAULT_REQ */
void _call_MSG_ID_MMI_CTM_SET_DEFAULT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_bool_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ctm_set_default_req(SRC_ID, p->a0 , p->a1 );
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_CTM_GET_DEFAULT_REQ_
#define _CALL_FUNC_MSG_ID_MMI_CTM_GET_DEFAULT_REQ_
	/* MSG_ID_MMI_CTM_GET_DEFAULT_REQ 	 CALL_FUNC S_k_bool_retb_L_ */
void _call_MSG_ID_MMI_CTM_GET_DEFAULT_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	kal_bool result = (kal_bool) l4c_ctm_get_default_req(SRC_ID);
	IF_CALL_FAIL_RETURN_BOOL
}

#endif
#endif /* defined(__CTM_SUPPORT__) */
/* VOIP */
#if defined(__VOIP__)
#ifndef _CALL_FUNC_MSG_ID_MMI_VOIP_AT_CALL_CTRL_APPROVE_RES_REQ_
#define _CALL_FUNC_MSG_ID_MMI_VOIP_AT_CALL_CTRL_APPROVE_RES_REQ_
	/* MSG_ID_MMI_VOIP_AT_CALL_CTRL_APPROVE_RES_REQ */
void _call_MSG_ID_MMI_VOIP_AT_CALL_CTRL_APPROVE_RES_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8_S_k_8_S_void_p_S_void_p_S_void_p__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_mmi_voip_at_call_ctrl_approve_req(p->a0 , p->a1 , p->a2 , p->a3 , p->a4 );
	NONE
}

#endif
#endif /* defined(__VOIP__) */
/* GEMINI */
#if defined(__GEMINI__)
#ifndef _CALL_FUNC_MSG_ID_MMI_SMU_SIM_STATUS_UPDATE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMU_SIM_STATUS_UPDATE_REQ_
	/* MSG_ID_MMI_SMU_SIM_STATUS_UPDATE_REQ 	 CALL_FUNC V_vS_k_8_ */
void _call_MSG_ID_MMI_SMU_SIM_STATUS_UPDATE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_S_k_8__struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_smu_sim_status_update_req(p->a0 );
	NONE
}

#endif
#ifndef _CALL_FUNC_MSG_ID_MMI_SMU_DUAL_SIM_TO_FLIGHT_MODE_REQ_
#define _CALL_FUNC_MSG_ID_MMI_SMU_DUAL_SIM_TO_FLIGHT_MODE_REQ_
	/* MSG_ID_MMI_SMU_DUAL_SIM_TO_FLIGHT_MODE_REQ 	 CALL_FUNC V_ */
void _call_MSG_ID_MMI_SMU_DUAL_SIM_TO_FLIGHT_MODE_REQ_ (module_type RSP_DEST, kal_uint8 SRC_ID, msg_type msg_req, msg_none_struct *p)
{
	NONE /* LOCALMEMBER*/

	l4c_smu_dual_sim_to_flight_mode_req(NONE);
	NONE
}

#endif
#endif /* defined(__GEMINI__) */

/*MTK:END*/

/******************************************************************************************
 * function pointer table
 ******************************************************************************************/

/*MTK:BEGIN:generate_function_pointer_tables*/
const L4A_VOID_FUNCTION l4a_recv_msg_ft[MSG_ID_MMI_MESSAGE_SUM]=
{
	/* Call Control Related Messages */
#if defined(__MOD_CSM__)
	/* MSG_ID_MMI_CC_RESET_ACM_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CC_RESET_ACM_REQ_,
	/* MSG_ID_MMI_CC_RESET_ACM_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_GET_ACM_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CC_GET_ACM_REQ_,
	/* MSG_ID_MMI_CC_GET_ACM_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_SET_MAX_ACM_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CC_SET_MAX_ACM_REQ_,
	/* MSG_ID_MMI_CC_SET_MAX_ACM_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_GET_MAX_ACM_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CC_GET_MAX_ACM_REQ_,
	/* MSG_ID_MMI_CC_GET_MAX_ACM_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_GET_CCM_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CC_GET_CCM_REQ_,
	/* MSG_ID_MMI_CC_GET_CCM_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_SET_CUG_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CC_SET_CUG_REQ_,
	/* MSG_ID_MMI_CC_SET_CUG_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_GET_CUG_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CC_GET_CUG_REQ_,
	/* MSG_ID_MMI_CC_GET_CUG_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_CHLD_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CC_CHLD_REQ_,
	/* MSG_ID_MMI_CC_CHLD_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_HANGUP_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CC_HANGUP_REQ_,
	/* MSG_ID_MMI_CC_HANGUP_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_ATH_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CC_ATH_REQ_,
	/* MSG_ID_MMI_CC_ATH_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_GET_CALL_LIST_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CC_GET_CALL_LIST_REQ_,
	/* MSG_ID_MMI_CC_GET_CALL_LIST_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_CALL_DEFLECT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CC_CALL_DEFLECT_REQ_,
	/* MSG_ID_MMI_CC_CALL_DEFLECT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_START_DTMF_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CC_START_DTMF_REQ_,
	/* MSG_ID_MMI_CC_START_DTMF_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_STOP_DTMF_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CC_STOP_DTMF_REQ_,
	/* MSG_ID_MMI_CC_STOP_DTMF_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_START_AUTO_DTMF_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CC_START_AUTO_DTMF_REQ_,
	/* MSG_ID_MMI_CC_START_AUTO_DTMF_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_START_AUTO_DTMF_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_START_AUTO_DTMF_FINISH_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_ATA_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CC_ATA_REQ_,
	/* MSG_ID_MMI_CC_ATA_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_DISCONNECT_AUX_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CC_DISCONNECT_AUX_REQ_,
	/* MSG_ID_MMI_CC_DISCONNECT_AUX_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_SET_LINE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CC_SET_LINE_REQ_,
	/* MSG_ID_MMI_CC_SET_LINE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_DIAL_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CC_DIAL_REQ_,
	/* MSG_ID_MMI_CC_DIAL_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_DIAL_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_DIAL_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_CALL_MODIFY_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CC_CALL_MODIFY_REQ_,
	/* MSG_ID_MMI_CC_CALL_MODIFY_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_SET_SINGLE_NUM_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CC_SET_SINGLE_NUM_REQ_,
	/* MSG_ID_MMI_CC_SET_SINGLE_NUM_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_GET_SINGLE_NUM_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CC_GET_SINGLE_NUM_REQ_,
	/* MSG_ID_MMI_CC_GET_SINGLE_NUM_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_CCM_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_INTERNAL_ALERT_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_CALL_WAIT_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_CALL_RING_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_CALL_CONNECT_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_CALL_DISCONNECT_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_CALL_RELEASE_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_SPEECH_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_NAME_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_NOTIFY_SS_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_NOTIFY_SS_CUG_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_NOTIFY_SS_ECT_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_NOTIFY_SS_CNAP_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_NOTIFY_SS_CCBS_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_CALL_ACCEPT_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_CALL_ABORT_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_CALL_SYNC_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_VIDEO_CALL_STATUS_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_REL_COMP_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CC_REL_COMP_REQ_,
	/* MSG_ID_MMI_CC_REL_COMP_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
#endif /* defined(__MOD_CSM__) */
	/* MSG_ID_MMI_CC_SET_BEARER_SERVICE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CC_SET_BEARER_SERVICE_REQ_,
	/* MSG_ID_MMI_CC_SET_BEARER_SERVICE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_GET_BEARER_SERVICE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CC_GET_BEARER_SERVICE_REQ_,
	/* MSG_ID_MMI_CC_GET_BEARER_SERVICE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_SET_CSD_PROFILE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CC_SET_CSD_PROFILE_REQ_,
	/* MSG_ID_MMI_CC_SET_CSD_PROFILE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_GET_CSD_PROFILE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CC_GET_CSD_PROFILE_REQ_,
	/* MSG_ID_MMI_CC_GET_CSD_PROFILE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CC_GET_FREE_CSD_PROFILE_NUM_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CC_GET_FREE_CSD_PROFILE_NUM_REQ_,
	/* MSG_ID_MMI_CC_GET_FREE_CSD_PROFILE_NUM_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SS_GET_EMLPP_PRIORITY_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SS_GET_EMLPP_PRIORITY_REQ_,
	/* MSG_ID_MMI_SS_GET_EMLPP_PRIORITY_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SS_EMLPP_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SS_EMLPP_REQ_,
	/* MSG_ID_MMI_SS_EMLPP_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SS_CALL_FORWARD_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SS_CALL_FORWARD_REQ_,
	/* MSG_ID_MMI_SS_CALL_FORWARD_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SS_CALL_WAIT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SS_CALL_WAIT_REQ_,
	/* MSG_ID_MMI_SS_CALL_WAIT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SS_INTERROGATE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SS_INTERROGATE_REQ_,
	/* MSG_ID_MMI_SS_INTERROGATE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SS_CDIP_INTERROGATE_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SS_CLIP_INTERROGATE_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SS_CLIR_INTERROGATE_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SS_CNAP_INTERROGATE_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SS_COLP_INTERROGATE_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SS_COLR_INTERROGATE_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SS_CALL_BARRING_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SS_CALL_BARRING_REQ_,
	/* MSG_ID_MMI_SS_CALL_BARRING_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SS_USSD_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SS_USSD_REQ_,
	/* MSG_ID_MMI_SS_USSD_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SS_USSR_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SS_USSN_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SS_CHANGE_PASSWORD_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SS_CHANGE_PASSWORD_REQ_,
	/* MSG_ID_MMI_SS_CHANGE_PASSWORD_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SS_PARSING_STRING_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SS_PARSING_STRING_REQ_,
	/* MSG_ID_MMI_SS_PARSING_STRING_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SS_CB_PASSWORD_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_CB_GS_CHANGE_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SS_CCBS_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SS_CCBS_REQ_,
	/* MSG_ID_MMI_SS_CCBS_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SS_ABORT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SS_ABORT_REQ_,
	/* MSG_ID_MMI_SS_ABORT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SS_SET_CLIR_FLAG_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SS_SET_CLIR_FLAG_REQ_,
	/* MSG_ID_MMI_SS_SET_CLIR_FLAG_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
/* Hardware - Audio Related Service Messages */
#if defined(__MOD_UEM__)
	/* MSG_ID_MMI_EQ_SET_VOLUME_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_SET_VOLUME_REQ_,
	/* MSG_ID_MMI_EQ_SET_VOLUME_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_EXE_VOLUME_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_VOLUME_CHANGE_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_SET_MUTE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_SET_MUTE_REQ_,
	/* MSG_ID_MMI_EQ_SET_MUTE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_EXE_MUTE_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_MUTE_CHANGE_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_SET_SILENT_MODE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_SET_SILENT_MODE_REQ_,
	/* MSG_ID_MMI_EQ_SET_SILENT_MODE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_SET_SILENT_MODE_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_SET_GPIO_LEVEL_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_SET_GPIO_LEVEL_REQ_,
	/* MSG_ID_MMI_EQ_SET_GPIO_LEVEL_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_SET_GPIO_LEVEL_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_GET_GPIO_LEVEL_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_GET_GPIO_LEVEL_REQ_,
	/* MSG_ID_MMI_EQ_GET_GPIO_LEVEL_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_EXE_GPIO_LEVEL_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_EXE_GPIO_LEVEL_REQ_,
	/* MSG_ID_MMI_EQ_EXE_GPIO_LEVEL_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_EXE_GPIO_LEVEL_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_PLAY_AUDIO_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_PLAY_AUDIO_REQ_,
	/* MSG_ID_MMI_EQ_PLAY_AUDIO_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_PLAY_AUDIO_FINISH_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_STOP_AUDIO_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_STOP_AUDIO_REQ_,
	/* MSG_ID_MMI_EQ_STOP_AUDIO_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_PLAY_AUDIO_STREAM_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_PLAY_AUDIO_STREAM_REQ_,
	/* MSG_ID_MMI_EQ_PLAY_AUDIO_STREAM_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_STOP_AUDIO_STREAM_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_STOP_AUDIO_STREAM_REQ_,
	/* MSG_ID_MMI_EQ_STOP_AUDIO_STREAM_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_PLAY_EXT_IMELODY_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_PLAY_EXT_IMELODY_REQ_,
	/* MSG_ID_MMI_EQ_PLAY_EXT_IMELODY_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_GPIO_DETECT_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_GPIO_DETECT_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_GPIO_DETECT_RES_REQ_,
	/* MSG_ID_MMI_EQ_GPIO_DETECT_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_SET_SPEECH_MODE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_SET_SPEECH_MODE_REQ_,
	/* MSG_ID_MMI_EQ_SET_SPEECH_MODE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_PLAY_AUDIO_BY_NAME_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_PLAY_AUDIO_BY_NAME_REQ_,
	/* MSG_ID_MMI_EQ_PLAY_AUDIO_BY_NAME_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_STOP_AUDIO_BY_NAME_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_STOP_AUDIO_BY_NAME_REQ_,
	/* MSG_ID_MMI_EQ_STOP_AUDIO_BY_NAME_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_SET_AUDIO_PROFILE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_SET_AUDIO_PROFILE_REQ_,
	/* MSG_ID_MMI_EQ_SET_AUDIO_PROFILE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_GET_AUDIO_PROFILE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_GET_AUDIO_PROFILE_REQ_,
	/* MSG_ID_MMI_EQ_GET_AUDIO_PROFILE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_SET_AUDIO_PARAM_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_SET_AUDIO_PARAM_REQ_,
	/* MSG_ID_MMI_EQ_SET_AUDIO_PARAM_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_GET_AUDIO_PARAM_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_GET_AUDIO_PARAM_REQ_,
	/* MSG_ID_MMI_EQ_GET_AUDIO_PARAM_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_START_ADC_ALL_CHANNEL_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_START_ADC_ALL_CHANNEL_REQ_,
	/* MSG_ID_MMI_EQ_START_ADC_ALL_CHANNEL_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_STOP_ADC_ALL_CHANNEL_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_STOP_ADC_ALL_CHANNEL_REQ_,
	/* MSG_ID_MMI_EQ_STOP_ADC_ALL_CHANNEL_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_ADC_ALL_CHANNEL_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_SET_AUDIO_MODE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_SET_AUDIO_MODE_REQ_,
	/* MSG_ID_MMI_EQ_SET_AUDIO_MODE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_PLAY_PATTERN_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_PLAY_PATTERN_REQ_,
	/* MSG_ID_MMI_EQ_PLAY_PATTERN_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_SET_HW_LEVEL_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_SET_HW_LEVEL_REQ_,
	/* MSG_ID_MMI_EQ_SET_HW_LEVEL_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_GET_HW_LEVEL_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_GET_HW_LEVEL_REQ_,
	/* MSG_ID_MMI_EQ_GET_HW_LEVEL_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_SET_SLEEP_MODE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_SET_SLEEP_MODE_REQ_,
	/* MSG_ID_MMI_EQ_SET_SLEEP_MODE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_SET_SLEEP_MODE_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_GET_MS_IMEI_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_GET_MS_IMEI_REQ_,
	/* MSG_ID_MMI_EQ_GET_MS_IMEI_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_SET_MS_IMEI_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_SET_MS_IMEI_REQ_,
	/* MSG_ID_MMI_EQ_SET_MS_IMEI_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_RTC_POWERON_STATE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_RTC_POWERON_STATE_REQ_,
	/* MSG_ID_MMI_EQ_RTC_POWERON_STATE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
#endif /* defined(__MOD_UEM__) */
/* Hardware - RTC, Clock, Alarm Related Messages */
#if defined(__MOD_UEM__)
	/* MSG_ID_MMI_EQ_SET_RTC_TIME_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_SET_RTC_TIME_REQ_,
	/* MSG_ID_MMI_EQ_SET_RTC_TIME_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_SET_RTC_TIME_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_EXE_RTC_TIMER_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_EXE_RTC_TIMER_REQ_,
	/* MSG_ID_MMI_EQ_EXE_RTC_TIMER_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_GET_RTC_TIME_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_GET_RTC_TIME_REQ_,
	/* MSG_ID_MMI_EQ_GET_RTC_TIME_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_DEL_RTC_TIMER_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_DEL_RTC_TIMER_REQ_,
	/* MSG_ID_MMI_EQ_DEL_RTC_TIMER_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_DEL_RTC_TIMER_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_EXE_DEL_RTC_TIMER_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_EXE_DEL_RTC_TIMER_REQ_,
	/* MSG_ID_MMI_EQ_EXE_DEL_RTC_TIMER_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_EXE_DEL_RTC_TIMER_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_SET_DATE_TIME_FORMAT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_SET_DATE_TIME_FORMAT_REQ_,
	/* MSG_ID_MMI_EQ_SET_DATE_TIME_FORMAT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_SET_DATE_TIME_FORMAT_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_START_TIMER_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_START_TIMER_REQ_,
	/* MSG_ID_MMI_EQ_START_TIMER_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_STOP_TIMER_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_STOP_TIMER_REQ_,
	/* MSG_ID_MMI_EQ_STOP_TIMER_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_CLOCK_TICK_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_ALARM_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_AT_ALARM_QUERY_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_AT_ALARM_QUERY_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_AT_ALARM_QUERY_RES_REQ_,
	/* MSG_ID_MMI_AT_ALARM_QUERY_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_AT_ALARM_SET_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_AT_ALARM_SET_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_AT_ALARM_SET_RES_REQ_,
	/* MSG_ID_MMI_AT_ALARM_SET_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_AT_ALARM_DELETE_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_AT_ALARM_DELETE_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_AT_ALARM_DELETE_RES_REQ_,
	/* MSG_ID_MMI_AT_ALARM_DELETE_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
#endif /* defined(__MOD_UEM__) */
/* Hardware - Keypad, Indicator, LCD Related Messages */
#if defined(__MOD_UEM__)
	/* MSG_ID_MMI_EQ_SIMULATE_KEY_PRESS_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_SIMULATE_KEY_PRESS_REQ_,
	/* MSG_ID_MMI_EQ_SIMULATE_KEY_PRESS_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_SIMULATE_KEY_PRESS_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_SET_INDICATOR_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_SET_INDICATOR_REQ_,
	/* MSG_ID_MMI_EQ_SET_INDICATOR_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_SET_INDICATOR_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_GET_INDICATOR_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_GET_INDICATOR_REQ_,
	/* MSG_ID_MMI_EQ_GET_INDICATOR_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_DISPLAY_TEXT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_DISPLAY_TEXT_REQ_,
	/* MSG_ID_MMI_EQ_DISPLAY_TEXT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_DISPLAY_TEXT_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_KEYPAD_DETECT_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
#endif /* defined(__MOD_UEM__) */
/* Hardware - Misc Messages */
#if defined(__MOD_UEM__)
	/* MSG_ID_MMI_EQ_SET_LANGUAGE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_SET_LANGUAGE_REQ_,
	/* MSG_ID_MMI_EQ_SET_LANGUAGE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_SET_LANGUAGE_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_SET_GREETING_TEXT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_SET_GREETING_TEXT_REQ_,
	/* MSG_ID_MMI_EQ_SET_GREETING_TEXT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_SET_GREETING_TEXT_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_SET_VIBRATOR_MODE_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_SET_VIBRATOR_MODE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_SET_VIBRATOR_MODE_REQ_,
	/* MSG_ID_MMI_EQ_SET_VIBRATOR_MODE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_SET_COUNTRY_CODE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_SET_COUNTRY_CODE_REQ_,
	/* MSG_ID_MMI_EQ_SET_COUNTRY_CODE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_GET_COUNTRY_CODE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_GET_COUNTRY_CODE_REQ_,
	/* MSG_ID_MMI_EQ_GET_COUNTRY_CODE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_GET_BATTERY_STATUS_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_GET_BATTERY_STATUS_REQ_,
	/* MSG_ID_MMI_EQ_GET_BATTERY_STATUS_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_GET_EQUIP_ID_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_GET_EQUIP_ID_REQ_,
	/* MSG_ID_MMI_EQ_GET_EQUIP_ID_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_LOAD_DEFAULT_CONFIG_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_LOAD_DEFAULT_CONFIG_REQ_,
	/* MSG_ID_MMI_EQ_LOAD_DEFAULT_CONFIG_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_POWER_ON_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_POWER_ON_REQ_,
	/* MSG_ID_MMI_EQ_POWER_ON_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_POWER_OFF_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_POWER_OFF_REQ_,
	/* MSG_ID_MMI_EQ_POWER_OFF_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_POWER_ON_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_BATTERY_STATUS_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_LEAVE_PRECHARGE_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_PMIC_CONFIG_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_PMIC_CONFIG_REQ_,
	/* MSG_ID_MMI_EQ_PMIC_CONFIG_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_BATTERY_STATUS_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_BATTERY_STATUS_RES_REQ_,
	/* MSG_ID_MMI_EQ_BATTERY_STATUS_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_RF_TEST_GSM_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_RF_TEST_GSM_REQ_,
	/* MSG_ID_MMI_EQ_RF_TEST_GSM_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_FM_RADIO_CONFIG_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_FM_RADIO_CONFIG_REQ_,
	/* MSG_ID_MMI_EQ_FM_RADIO_CONFIG_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_RF_TEST_WIFI_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_RF_TEST_WIFI_REQ_,
	/* MSG_ID_MMI_EQ_RF_TEST_WIFI_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_CALL_STATUS_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_CALL_STATUS_REQ_,
	/* MSG_ID_MMI_EQ_CALL_STATUS_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
#endif /* defined(__MOD_UEM__) */
/* Hardware - NVRAM messages */
#if defined(__MOD_NVRAM__)
	/* MSG_ID_MMI_EQ_NVRAM_READ_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_NVRAM_READ_REQ_,
	/* MSG_ID_MMI_EQ_NVRAM_READ_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_NVRAM_WRITE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_NVRAM_WRITE_REQ_,
	/* MSG_ID_MMI_EQ_NVRAM_WRITE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_NVRAM_RESET_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_NVRAM_RESET_REQ_,
	/* MSG_ID_MMI_EQ_NVRAM_RESET_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_SET_UART_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_SET_UART_REQ_,
	/* MSG_ID_MMI_EQ_SET_UART_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_GET_UART_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_GET_UART_REQ_,
	/* MSG_ID_MMI_EQ_GET_UART_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_ATTACH_UART_PORT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_ATTACH_UART_PORT_REQ_,
	/* MSG_ID_MMI_ATTACH_UART_PORT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_DETACH_UART_PORT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_DETACH_UART_PORT_REQ_,
	/* MSG_ID_MMI_DETACH_UART_PORT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_NVRAM_READY_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_DCM_ENABLE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_DCM_ENABLE_REQ_,
	/* MSG_ID_MMI_EQ_DCM_ENABLE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
#endif /* defined(__MOD_NVRAM__) */
/* Network Related Messages */
#if defined(__MOD_RAC__)
	/* MSG_ID_MMI_NW_GET_IMEI_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_NW_GET_IMEI_REQ_,
	/* MSG_ID_MMI_NW_GET_IMEI_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_ABORT_PLMN_LIST_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_NW_ABORT_PLMN_LIST_REQ_,
	/* MSG_ID_MMI_NW_ABORT_PLMN_LIST_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_SET_ATTACH_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_NW_SET_ATTACH_REQ_,
	/* MSG_ID_MMI_NW_SET_ATTACH_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_GET_ATTACH_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_NW_GET_ATTACH_REQ_,
	/* MSG_ID_MMI_NW_GET_ATTACH_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_SET_MOBILE_CLASS_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_NW_SET_MOBILE_CLASS_REQ_,
	/* MSG_ID_MMI_NW_SET_MOBILE_CLASS_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_GET_MOBILE_CLASS_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_NW_GET_MOBILE_CLASS_REQ_,
	/* MSG_ID_MMI_NW_GET_MOBILE_CLASS_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_SET_PLMN_SELECT_MODE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_NW_SET_PLMN_SELECT_MODE_REQ_,
	/* MSG_ID_MMI_NW_SET_PLMN_SELECT_MODE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_GET_PLMN_SELECT_MODE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_NW_GET_PLMN_SELECT_MODE_REQ_,
	/* MSG_ID_MMI_NW_GET_PLMN_SELECT_MODE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_SET_PLMN_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_NW_SET_PLMN_REQ_,
	/* MSG_ID_MMI_NW_SET_PLMN_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_GET_PLMN_LIST_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_NW_GET_PLMN_LIST_REQ_,
	/* MSG_ID_MMI_NW_GET_PLMN_LIST_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_GET_CURRENT_PLMN_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_NW_GET_CURRENT_PLMN_REQ_,
	/* MSG_ID_MMI_NW_GET_CURRENT_PLMN_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_GET_SIGNAL_LEVEL_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_NW_GET_SIGNAL_LEVEL_REQ_,
	/* MSG_ID_MMI_NW_GET_SIGNAL_LEVEL_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_GET_BAND_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_NW_GET_BAND_REQ_,
	/* MSG_ID_MMI_NW_GET_BAND_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_ATTACH_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_REG_STATE_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_RX_LEVEL_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_TIME_ZONE_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_SEL_MODE_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_MMRR_SERVICE_STATUS_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_SET_PREFERRED_BAND_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_NW_SET_PREFERRED_BAND_REQ_,
	/* MSG_ID_MMI_NW_SET_PREFERRED_BAND_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_SET_GPRS_CONNECT_TYPE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_NW_SET_GPRS_CONNECT_TYPE_REQ_,
	/* MSG_ID_MMI_NW_SET_GPRS_CONNECT_TYPE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_GET_GPRS_CONNECT_TYPE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_NW_GET_GPRS_CONNECT_TYPE_REQ_,
	/* MSG_ID_MMI_NW_GET_GPRS_CONNECT_TYPE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_PWROFF_DETACH_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_NW_PWROFF_DETACH_REQ_,
	/* MSG_ID_MMI_NW_PWROFF_DETACH_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_CFUN_STATE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_NW_CFUN_STATE_REQ_,
	/* MSG_ID_MMI_NW_CFUN_STATE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_GET_RAT_MODE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_NW_GET_RAT_MODE_REQ_,
	/* MSG_ID_MMI_NW_GET_RAT_MODE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_SET_RAT_MODE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_NW_SET_RAT_MODE_REQ_,
	/* MSG_ID_MMI_NW_SET_RAT_MODE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_GET_PREFER_RAT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_NW_GET_PREFER_RAT_REQ_,
	/* MSG_ID_MMI_NW_GET_PREFER_RAT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_SET_PREFER_RAT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_NW_SET_PREFER_RAT_REQ_,
	/* MSG_ID_MMI_NW_SET_PREFER_RAT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
#endif /* defined(__MOD_RAC__) */
/* Security Related Messages */
#if defined(__MOD_SMU__)
	/* MSG_ID_MMI_SMU_GET_IMSI_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMU_GET_IMSI_REQ_,
	/* MSG_ID_MMI_SMU_GET_IMSI_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_LOCK_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMU_LOCK_REQ_,
	/* MSG_ID_MMI_SMU_LOCK_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_RESET_DATA_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMU_RESET_DATA_REQ_,
	/* MSG_ID_MMI_SMU_RESET_DATA_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_GET_DIAL_MODE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMU_GET_DIAL_MODE_REQ_,
	/* MSG_ID_MMI_SMU_GET_DIAL_MODE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_VERIFY_PIN_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMU_VERIFY_PIN_REQ_,
	/* MSG_ID_MMI_SMU_VERIFY_PIN_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_GET_PIN_TYPE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMU_GET_PIN_TYPE_REQ_,
	/* MSG_ID_MMI_SMU_GET_PIN_TYPE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_SET_PREFERRED_OPER_LIST_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMU_SET_PREFERRED_OPER_LIST_REQ_,
	/* MSG_ID_MMI_SMU_SET_PREFERRED_OPER_LIST_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_GET_PREFERRED_OPER_LIST_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMU_GET_PREFERRED_OPER_LIST_REQ_,
	/* MSG_ID_MMI_SMU_GET_PREFERRED_OPER_LIST_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_SET_PUC_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMU_SET_PUC_REQ_,
	/* MSG_ID_MMI_SMU_SET_PUC_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_GET_PUC_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMU_GET_PUC_REQ_,
	/* MSG_ID_MMI_SMU_GET_PUC_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_CHANGE_PASSWORD_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMU_CHANGE_PASSWORD_REQ_,
	/* MSG_ID_MMI_SMU_CHANGE_PASSWORD_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_RESTRICTED_ACCESS_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMU_RESTRICTED_ACCESS_REQ_,
	/* MSG_ID_MMI_SMU_RESTRICTED_ACCESS_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_SET_DIAL_MODE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMU_SET_DIAL_MODE_REQ_,
	/* MSG_ID_MMI_SMU_SET_DIAL_MODE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_WRITE_SIM_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMU_WRITE_SIM_REQ_,
	/* MSG_ID_MMI_SMU_WRITE_SIM_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_READ_SIM_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMU_READ_SIM_REQ_,
	/* MSG_ID_MMI_SMU_READ_SIM_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_POWER_OFF_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMU_POWER_OFF_REQ_,
	/* MSG_ID_MMI_SMU_POWER_OFF_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_REMOVE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMU_REMOVE_REQ_,
	/* MSG_ID_MMI_SMU_REMOVE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_PASSWORD_REQUIRED_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_SUPPORT_PLMN_LIST_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_FAIL_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_READ_FILE_INFO_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMU_READ_FILE_INFO_REQ_,
	/* MSG_ID_MMI_SMU_READ_FILE_INFO_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_CHECK_PIN_STATUS_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMU_CHECK_PIN_STATUS_REQ_,
	/* MSG_ID_MMI_SMU_CHECK_PIN_STATUS_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_STARTUP_INFO_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_CIPHER_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_SET_PERSONALIZATION_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMU_SET_PERSONALIZATION_REQ_,
	/* MSG_ID_MMI_SMU_SET_PERSONALIZATION_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_SML_STATUS_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMU_SML_STATUS_REQ_,
	/* MSG_ID_MMI_SMU_SML_STATUS_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_VERIFY_PIN_RESULT_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
#endif /* defined(__MOD_SMU__) */
/* PhoneBook Related Messages */
#if defined(__MOD_PHB__)
	/* MSG_ID_MMI_PHB_GET_ENTRY_BY_NAME_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PHB_GET_ENTRY_BY_NAME_REQ_,
	/* MSG_ID_MMI_PHB_GET_ENTRY_BY_NAME_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PHB_GET_ENTRY_BY_INDEX_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PHB_GET_ENTRY_BY_INDEX_REQ_,
	/* MSG_ID_MMI_PHB_GET_ENTRY_BY_INDEX_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PHB_SET_PREFERRED_STORAGE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PHB_SET_PREFERRED_STORAGE_REQ_,
	/* MSG_ID_MMI_PHB_SET_PREFERRED_STORAGE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PHB_GET_PREFERRED_STORAGE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PHB_GET_PREFERRED_STORAGE_REQ_,
	/* MSG_ID_MMI_PHB_GET_PREFERRED_STORAGE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PHB_SET_ENTRY_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PHB_SET_ENTRY_REQ_,
	/* MSG_ID_MMI_PHB_SET_ENTRY_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PHB_DEL_ENTRY_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PHB_DEL_ENTRY_REQ_,
	/* MSG_ID_MMI_PHB_DEL_ENTRY_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PHB_SET_VOICE_MAIL_SERVER_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PHB_SET_VOICE_MAIL_SERVER_REQ_,
	/* MSG_ID_MMI_PHB_SET_VOICE_MAIL_SERVER_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PHB_GET_ALPHA_LIST_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PHB_GET_ALPHA_LIST_REQ_,
	/* MSG_ID_MMI_PHB_GET_ALPHA_LIST_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PHB_GET_TYPE_STATUS_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PHB_GET_TYPE_STATUS_REQ_,
	/* MSG_ID_MMI_PHB_GET_TYPE_STATUS_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PHB_GET_LAST_NUMBER_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PHB_GET_LAST_NUMBER_REQ_,
	/* MSG_ID_MMI_PHB_GET_LAST_NUMBER_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PHB_SET_LAST_NUMBER_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PHB_SET_LAST_NUMBER_REQ_,
	/* MSG_ID_MMI_PHB_SET_LAST_NUMBER_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PHB_DEL_LAST_NUMBER_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PHB_DEL_LAST_NUMBER_REQ_,
	/* MSG_ID_MMI_PHB_DEL_LAST_NUMBER_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PHB_LAST_NUMBER_READY_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PHB_STARTUP_FINISH_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PHB_MEM_FULL_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PHB_UPDATE_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PHB_STARTUP_READ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PHB_STARTUP_BEGIN_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PHB_STARTUP_READ_NEXT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PHB_STARTUP_READ_NEXT_REQ_,
	/* MSG_ID_MMI_PHB_STARTUP_READ_NEXT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PHB_STARTUP_PHASE1_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PHB_STARTUP_READ_NEXT_USIM_FIELD_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PHB_STARTUP_READ_NEXT_USIM_FIELD_REQ_,
	/* MSG_ID_MMI_PHB_STARTUP_READ_ANR_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PHB_STARTUP_READ_EMAIL_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PHB_READ_EMAIL_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PHB_READ_EMAIL_REQ_,
	/* MSG_ID_MMI_PHB_READ_EMAIL_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PHB_STARTUP_READ_GAS_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PHB_STARTUP_READ_GRP_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PHB_SET_GRP_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PHB_SET_GRP_REQ_,
	/* MSG_ID_MMI_PHB_SET_GRP_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PHB_WRITE_USIM_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PHB_WRITE_USIM_REQ_,
	/* MSG_ID_MMI_PHB_WRITE_USIM_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
#endif /* defined(__MOD_PHB__) */
	/* MSG_ID_MMI_SMS_SET_PROFILE_PARAMS_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMS_SET_PROFILE_PARAMS_REQ_,
	/* MSG_ID_MMI_SMS_SET_PROFILE_PARAMS_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_REQ_,
	/* MSG_ID_MMI_SMS_GET_PROFILE_PARAMS_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_SET_COMMON_PARAMS_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMS_SET_COMMON_PARAMS_REQ_,
	/* MSG_ID_MMI_SMS_SET_COMMON_PARAMS_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_GET_COMMON_PARAMS_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMS_GET_COMMON_PARAMS_REQ_,
	/* MSG_ID_MMI_SMS_GET_COMMON_PARAMS_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_SEND_COMMAND_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMS_SEND_COMMAND_REQ_,
	/* MSG_ID_MMI_SMS_SEND_COMMAND_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_DEL_MSG_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMS_DEL_MSG_REQ_,
	/* MSG_ID_MMI_SMS_DEL_MSG_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_GET_MSG_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMS_GET_MSG_REQ_,
	/* MSG_ID_MMI_SMS_GET_MSG_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_SEND_MSG_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMS_SEND_MSG_REQ_,
	/* MSG_ID_MMI_SMS_SEND_MSG_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_SET_MSG_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMS_SET_MSG_REQ_,
	/* MSG_ID_MMI_SMS_SET_MSG_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_SET_PREFERRED_STORAGE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMS_SET_PREFERRED_STORAGE_REQ_,
	/* MSG_ID_MMI_SMS_SET_PREFERRED_STORAGE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_GET_PREFERRED_STORAGE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMS_GET_PREFERRED_STORAGE_REQ_,
	/* MSG_ID_MMI_SMS_GET_PREFERRED_STORAGE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_REG_PORT_NUM_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMS_REG_PORT_NUM_REQ_,
	/* MSG_ID_MMI_SMS_REG_PORT_NUM_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_DELIVER_MSG_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_STATUS_REPORT_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_MEM_AVAILABLE_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_MEM_EXCEED_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_MEM_FULL_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_READY_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_APP_DATA_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_GET_MSG_NUM_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMS_GET_MSG_NUM_REQ_,
	/* MSG_ID_MMI_SMS_GET_MSG_NUM_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_GET_PROFILE_NUM_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMS_GET_PROFILE_NUM_REQ_,
	/* MSG_ID_MMI_SMS_GET_PROFILE_NUM_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_ABORT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMS_ABORT_REQ_,
	/* MSG_ID_MMI_SMS_ABORT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_MSG_WAITING_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_SET_MAILBOX_ADDRESS_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMS_SET_MAILBOX_ADDRESS_REQ_,
	/* MSG_ID_MMI_SMS_SET_MAILBOX_ADDRESS_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_GET_MAILBOX_ADDRESS_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMS_GET_MAILBOX_ADDRESS_REQ_,
	/* MSG_ID_MMI_SMS_GET_MAILBOX_ADDRESS_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_SYNC_MSG_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_SYNC_MSG_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMS_SYNC_MSG_RES_REQ_,
	/* MSG_ID_MMI_SMS_SYNC_MSG_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_SEND_ABORT_START_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_SEND_ABORT_FINISH_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_STARTUP_BEGIN_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_STARTUP_FINISH_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_STARTUP_READ_NEXT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMS_STARTUP_READ_NEXT_REQ_,
	/* MSG_ID_MMI_SMS_STARTUP_READ_NEXT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_STARTUP_READ_MSG_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_COPY_MSG_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMS_COPY_MSG_REQ_,
	/* MSG_ID_MMI_SMS_COPY_MSG_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_GET_MSG_LIST_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMS_GET_MSG_LIST_REQ_,
	/* MSG_ID_MMI_SMS_GET_MSG_LIST_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_SEND_FROM_STORAGE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMS_SEND_FROM_STORAGE_REQ_,
	/* MSG_ID_MMI_SMS_SEND_FROM_STORAGE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_SET_STATUS_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMS_SET_STATUS_REQ_,
	/* MSG_ID_MMI_SMS_SET_STATUS_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
/* Data Related Messages */
#if defined(__MOD_DATA__)
	/* MSG_ID_MMI_DF_SET_RLP_PARAMS_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_DF_SET_RLP_PARAMS_REQ_,
	/* MSG_ID_MMI_DF_SET_RLP_PARAMS_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_DF_GET_RLP_PARAMS_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_DF_GET_RLP_PARAMS_REQ_,
	/* MSG_ID_MMI_DF_GET_RLP_PARAMS_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_DF_SET_V120_PARAMS_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_DF_SET_V120_PARAMS_REQ_,
	/* MSG_ID_MMI_DF_SET_V120_PARAMS_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_DF_GET_V120_PARAMS_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_DF_GET_V120_PARAMS_REQ_,
	/* MSG_ID_MMI_DF_GET_V120_PARAMS_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_DF_SET_COMP_PARAMS_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_DF_SET_COMP_PARAMS_REQ_,
	/* MSG_ID_MMI_DF_SET_COMP_PARAMS_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_DF_GET_COMP_PARAMS_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_DF_GET_COMP_PARAMS_REQ_,
	/* MSG_ID_MMI_DF_GET_COMP_PARAMS_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_DF_SET_BEARER_MODE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_DF_SET_BEARER_MODE_REQ_,
	/* MSG_ID_MMI_DF_SET_BEARER_MODE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_DF_GET_BEARER_MODE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_DF_GET_BEARER_MODE_REQ_,
	/* MSG_ID_MMI_DF_GET_BEARER_MODE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_DF_SET_CHAR_FRAMING_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_DF_SET_CHAR_FRAMING_REQ_,
	/* MSG_ID_MMI_DF_SET_CHAR_FRAMING_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_DF_GET_CHAR_FRAMING_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_DF_GET_CHAR_FRAMING_REQ_,
	/* MSG_ID_MMI_DF_GET_CHAR_FRAMING_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
#endif /* defined(__MOD_DATA__) */
	/* MSG_ID_MMI_DF_BACK_DATA_STATE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_DF_BACK_DATA_STATE_REQ_,
	/* MSG_ID_MMI_DF_BACK_DATA_STATE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
/* GPRS Related Messages */
#if defined(__MOD_TCM__)
	/* MSG_ID_MMI_PS_ACT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PS_ACT_REQ_,
	/* MSG_ID_MMI_PS_ACT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PS_ACT_TEST_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PS_ACT_TEST_REQ_,
	/* MSG_ID_MMI_PS_ACT_TEST_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PS_ANSWER_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PS_ANSWER_REQ_,
	/* MSG_ID_MMI_PS_ANSWER_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PS_SET_AUTO_ANSWER_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PS_SET_AUTO_ANSWER_REQ_,
	/* MSG_ID_MMI_PS_SET_AUTO_ANSWER_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PS_GET_AUTO_ANSWER_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PS_GET_AUTO_ANSWER_REQ_,
	/* MSG_ID_MMI_PS_GET_AUTO_ANSWER_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PS_MODIFY_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PS_MODIFY_REQ_,
	/* MSG_ID_MMI_PS_MODIFY_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PS_ENTER_DATA_STATE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PS_ENTER_DATA_STATE_REQ_,
	/* MSG_ID_MMI_PS_ENTER_DATA_STATE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PS_SET_DEFINITION_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PS_SET_DEFINITION_REQ_,
	/* MSG_ID_MMI_PS_SET_DEFINITION_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PS_GET_DEFINITION_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PS_GET_DEFINITION_REQ_,
	/* MSG_ID_MMI_PS_GET_DEFINITION_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PS_SET_SEC_DEFINITION_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PS_SET_SEC_DEFINITION_REQ_,
	/* MSG_ID_MMI_PS_SET_SEC_DEFINITION_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PS_GET_SEC_DEFINITION_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PS_GET_SEC_DEFINITION_REQ_,
	/* MSG_ID_MMI_PS_GET_SEC_DEFINITION_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PS_GET_PDP_ADDR_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PS_GET_PDP_ADDR_REQ_,
	/* MSG_ID_MMI_PS_GET_PDP_ADDR_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PS_SET_TFT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PS_SET_TFT_REQ_,
	/* MSG_ID_MMI_PS_SET_TFT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PS_GET_TFT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PS_GET_TFT_REQ_,
	/* MSG_ID_MMI_PS_GET_TFT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PS_SET_QOS_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PS_SET_QOS_REQ_,
	/* MSG_ID_MMI_PS_SET_QOS_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PS_SET_EQOS_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PS_SET_EQOS_REQ_,
	/* MSG_ID_MMI_PS_SET_EQOS_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PS_SEND_DATA_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PS_SEND_DATA_REQ_,
	/* MSG_ID_MMI_PS_SEND_DATA_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PS_ACTIVE_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PS_GPRS_STATUS_UPDATE_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PS_GET_GPRS_EMPTY_PROFILE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PS_GET_GPRS_EMPTY_PROFILE_REQ_,
	/* MSG_ID_MMI_PS_GET_GPRS_EMPTY_PROFILE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PS_GET_GPRS_DATA_COUNTER_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PS_GET_GPRS_DATA_COUNTER_REQ_,
	/* MSG_ID_MMI_PS_GET_GPRS_DATA_COUNTER_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PS_SET_GPRS_DATA_ACCOUNT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PS_SET_GPRS_DATA_ACCOUNT_REQ_,
	/* MSG_ID_MMI_PS_SET_GPRS_DATA_ACCOUNT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PS_GET_GPRS_DATA_ACCOUNT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PS_GET_GPRS_DATA_ACCOUNT_REQ_,
	/* MSG_ID_MMI_PS_GET_GPRS_DATA_ACCOUNT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_PS_RESET_GPRS_DATA_COUNTER_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_PS_RESET_GPRS_DATA_COUNTER_REQ_,
	/* MSG_ID_MMI_PS_RESET_GPRS_DATA_COUNTER_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
#endif /* defined(__MOD_TCM__) */
/* STK/SAT Related Messages */
#if defined(__SAT__)
	/* MSG_ID_MMI_SAT_DISPLAY_TEXT_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_DISPLAY_TEXT_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SAT_DISPLAY_TEXT_RES_REQ_,
	/* MSG_ID_MMI_SAT_DISPLAY_TEXT_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_GET_INKEY_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_GET_INKEY_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SAT_GET_INKEY_RES_REQ_,
	/* MSG_ID_MMI_SAT_GET_INKEY_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_GET_INPUT_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_GET_INPUT_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SAT_GET_INPUT_RES_REQ_,
	/* MSG_ID_MMI_SAT_GET_INPUT_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_SETUP_MENU_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_SETUP_MENU_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SAT_SETUP_MENU_RES_REQ_,
	/* MSG_ID_MMI_SAT_SETUP_MENU_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_SELECT_ITEM_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_SELECT_ITEM_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SAT_SELECT_ITEM_RES_REQ_,
	/* MSG_ID_MMI_SAT_SELECT_ITEM_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_PLAY_TONE_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_PLAY_TONE_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SAT_PLAY_TONE_RES_REQ_,
	/* MSG_ID_MMI_SAT_PLAY_TONE_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_MENU_SELECT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SAT_MENU_SELECT_REQ_,
	/* MSG_ID_MMI_SAT_MENU_SELECT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_EVDL_IDLE_SCREEN_AVAILABLE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SAT_EVDL_IDLE_SCREEN_AVAILABLE_REQ_,
	/* MSG_ID_MMI_SAT_EVDL_IDLE_SCREEN_AVAILABLE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_LANGUAGE_SELECTION_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SAT_LANGUAGE_SELECTION_REQ_,
	/* MSG_ID_MMI_SAT_LANGUAGE_SELECTION_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_EVDL_BROWSER_TERMINATION_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SAT_EVDL_BROWSER_TERMINATION_REQ_,
	/* MSG_ID_MMI_SAT_EVDL_BROWSER_TERMINATION_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_CALL_SETUP_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_CALL_SETUP_STAGE1_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SAT_CALL_SETUP_STAGE1_REQ_,
	/* MSG_ID_MMI_SAT_CALL_SETUP_STAGE1_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_CALL_SETUP_STAGE2_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SAT_CALL_SETUP_STAGE2_REQ_,
	/* MSG_ID_MMI_SAT_CALL_SETUP_STAGE2_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_SEND_SMS_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_SEND_SMS_STAGE1_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SAT_SEND_SMS_STAGE1_REQ_,
	/* MSG_ID_MMI_SAT_SEND_SMS_STAGE1_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_SEND_SMS_STAGE2_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SAT_SEND_SMS_STAGE2_REQ_,
	/* MSG_ID_MMI_SAT_SEND_SMS_STAGE2_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_SEND_SS_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_SEND_SS_STAGE1_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SAT_SEND_SS_STAGE1_REQ_,
	/* MSG_ID_MMI_SAT_SEND_SS_STAGE1_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_SEND_SS_STAGE2_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SAT_SEND_SS_STAGE2_REQ_,
	/* MSG_ID_MMI_SAT_SEND_SS_STAGE2_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_SEND_USSD_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_SEND_USSD_STAGE1_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SAT_SEND_USSD_STAGE1_REQ_,
	/* MSG_ID_MMI_SAT_SEND_USSD_STAGE1_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_SEND_USSD_STAGE2_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SAT_SEND_USSD_STAGE2_REQ_,
	/* MSG_ID_MMI_SAT_SEND_USSD_STAGE2_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_MMI_INFO_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_SETUP_IDLE_DISPLAY_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SAT_SETUP_IDLE_DISPLAY_RES_REQ_,
	/* MSG_ID_MMI_SAT_SETUP_IDLE_DISPLAY_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_SETUP_IDLE_DISPLAY_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_RUN_AT_COMMAND_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_SEND_DTMF_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_SEND_DTMF_STAGE1_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SAT_SEND_DTMF_STAGE1_REQ_,
	/* MSG_ID_MMI_SAT_SEND_DTMF_STAGE1_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_SEND_DTMF_STAGE2_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SAT_SEND_DTMF_STAGE2_REQ_,
	/* MSG_ID_MMI_SAT_SEND_DTMF_STAGE2_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_ABORT_DTMF_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SAT_ABORT_DTMF_REQ_,
	/* MSG_ID_MMI_SAT_ABORT_DTMF_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_LANG_NOTIFY_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SAT_LANG_NOTIFY_RES_REQ_,
	/* MSG_ID_MMI_SAT_LANG_NOTIFY_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_LANG_NOTIFY_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_LAUNCH_BROWSER_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SAT_LAUNCH_BROWSER_RES_REQ_,
	/* MSG_ID_MMI_SAT_LAUNCH_BROWSER_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_LAUNCH_BROWSER_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_NO_OTHER_CMD_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_SIM_FILE_CHANGE_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
#endif /* defined(__SAT__) */
/* STK_CE */
#if defined(__SATCE__)
	/* MSG_ID_MMI_SAT_OPEN_CHANNEL_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_OPEN_CHANNEL_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SAT_OPEN_CHANNEL_REQ_,
	/* MSG_ID_MMI_SAT_OPEN_CHANNEL_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_CLOSE_CHANNEL_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_CLOSE_CHANNEL_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SAT_CLOSE_CHANNEL_REQ_,
	/* MSG_ID_MMI_SAT_CLOSE_CHANNEL_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_SEND_DATA_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_SEND_DATA_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SAT_SEND_DATA_REQ_,
	/* MSG_ID_MMI_SAT_SEND_DATA_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_RECV_DATA_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_RECV_DATA_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SAT_RECV_DATA_REQ_,
	/* MSG_ID_MMI_SAT_RECV_DATA_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SAT_NOTIFY_MMI_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
#endif /* defined(__SATCE__) */
	/* MSG_ID_MMI_CB_DOWNLOAD_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CB_MSG_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CB_SUBSCRIBE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CB_SUBSCRIBE_REQ_,
	/* MSG_ID_MMI_CB_SUBSCRIBE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_SET_CB_MODE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMS_SET_CB_MODE_REQ_,
	/* MSG_ID_MMI_SMS_SET_CB_MODE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMS_GET_CB_MODE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMS_GET_CB_MODE_REQ_,
	/* MSG_ID_MMI_SMS_GET_CB_MODE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
/* Engineer Mode-UEM */
#if defined(__MOD_UEM__)
	/* MSG_ID_MMI_EM_SET_GAIN_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EM_SET_GAIN_REQ_,
	/* MSG_ID_MMI_EM_SET_GAIN_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
#endif /* defined(__MOD_UEM__) */
/* Engineer Mode */
#if defined(__EM_MODE__)
	/* MSG_ID_MMI_EM_STATUS_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EM_START_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EM_START_REQ_,
	/* MSG_ID_MMI_EM_START_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EM_STOP_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EM_STOP_REQ_,
	/* MSG_ID_MMI_EM_STOP_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EM_SET_CELL_ID_LOCK_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EM_SET_CELL_ID_LOCK_REQ_,
	/* MSG_ID_MMI_EM_SET_CELL_ID_LOCK_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
#endif /* defined(__EM_MODE__) */
	/* MSG_ID_MMI_EM_KEYPAD_EVENT_OUTPUT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EM_KEYPAD_EVENT_OUTPUT_REQ_,
	/* MSG_ID_MMI_EM_KEYPAD_EVENT_OUTPUT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EM_LCM_TEST_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EM_KEYPAD_EVENT_ACT_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_FACTORY_TEST_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SET_MMI_DEFAULT_PROF_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_UPDATE_MMI_DEFAULT_PROF_VALUE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_UPDATE_MMI_DEFAULT_PROF_VALUE_REQ_,
	/* MSG_ID_MMI_UPDATE_MMI_DEFAULT_PROF_VALUE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EM_CELL_RESEL_SUSPEND_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EM_CELL_RESEL_SUSPEND_REQ_,
	/* MSG_ID_MMI_EM_CELL_RESEL_SUSPEND_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EM_CELL_RESEL_RESUME_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EM_CELL_RESEL_RESUME_REQ_,
	/* MSG_ID_MMI_EM_CELL_RESEL_RESUME_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EM_GET_CELL_LOCK_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EM_GET_CELL_LOCK_REQ_,
	/* MSG_ID_MMI_EM_GET_CELL_LOCK_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EM_SET_CELL_LOCK_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EM_SET_CELL_LOCK_REQ_,
	/* MSG_ID_MMI_EM_SET_CELL_LOCK_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EM_RGB_TEST_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EM_NW_EVENT_NOTIFY_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EM_NW_EVENT_NOTIFY_REQ_,
	/* MSG_ID_MMI_EM_NW_EVENT_NOTIFY_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EM_NW_EVENT_NOTIFY_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EM_FEATURE_COMMAND_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EM_FEATURE_COMMAND_REQ_,
	/* MSG_ID_MMI_EM_FEATURE_COMMAND_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
/* Audio Task - Voice Memo(via FS) */
#if defined(__FS_ON__)
	/* MSG_ID_MMI_VM_PLAY_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_VM_PLAY_REQ_,
	/* MSG_ID_MMI_VM_PLAY_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_VM_DEL_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_VM_DEL_REQ_,
	/* MSG_ID_MMI_VM_DEL_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_VM_APPEND_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_VM_APPEND_REQ_,
	/* MSG_ID_MMI_VM_APPEND_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_VM_RENAME_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_VM_RENAME_REQ_,
	/* MSG_ID_MMI_VM_RENAME_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_VM_PLAY_FINISH_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_VM_GET_INFO_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_VM_GET_INFO_REQ_,
	/* MSG_ID_MMI_VM_GET_INFO_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_VM_STOP_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_VM_STOP_REQ_,
	/* MSG_ID_MMI_VM_STOP_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_VM_ABORT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_VM_ABORT_REQ_,
	/* MSG_ID_MMI_VM_ABORT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_VM_PAUSE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_VM_PAUSE_REQ_,
	/* MSG_ID_MMI_VM_PAUSE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_VM_RESUME_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_VM_RESUME_REQ_,
	/* MSG_ID_MMI_VM_RESUME_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_VM_RECORD_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_VM_RECORD_REQ_,
	/* MSG_ID_MMI_VM_RECORD_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_VM_RECORD_FINISH_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
#endif /* defined(__FS_ON__) */
	/* MSG_ID_MMI_CPHS_DISPLAY_CFU_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CPHS_MMI_INFO_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CPHS_UPDATE_ALS_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CPHS_UPDATE_ALS_REQ_,
	/* MSG_ID_MMI_CPHS_UPDATE_ALS_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CPHS_DISPLAY_ALS_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_WAP_START_DTMF_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_WAP_START_DTMF_REQ_,
	/* MSG_ID_WAP_START_DTMF_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_WAP_STOP_DTMF_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_WAP_STOP_DTMF_REQ_,
	/* MSG_ID_WAP_STOP_DTMF_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_WAP_DIAL_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_WAP_DIAL_REQ_,
	/* MSG_ID_WAP_DIAL_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_WAP_SET_ENTRY_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_WAP_SET_ENTRY_REQ_,
	/* MSG_ID_WAP_SET_ENTRY_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_WAP_AUTO_DTMF_COMPLETE_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
/* IrDA */
#if defined(__IRDA_SUPPORT__)
	/* MSG_ID_MMI_EQ_IRDA_OPEN_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_IRDA_OPEN_REQ_,
	/* MSG_ID_MMI_EQ_IRDA_OPEN_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_IRDA_CLOSE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_IRDA_CLOSE_REQ_,
	/* MSG_ID_MMI_EQ_IRDA_CLOSE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_IRCOMM_CONNECT_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_IRCOMM_DISCONNECT_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
#endif /* defined(__IRDA_SUPPORT__) */
/* USB */
#if defined(__USB_ENABLE__)
	/* MSG_ID_MMI_EQ_USBCONFIG_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_USBCONFIG_REQ_,
	/* MSG_ID_MMI_EQ_USBCONFIG_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_USBDETECT_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_USBUART_SWITCH_PORT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_USBUART_SWITCH_PORT_REQ_,
	/* MSG_ID_MMI_EQ_USBUART_SWITCH_PORT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_USBDETECT_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_USBDETECT_RES_REQ_,
	/* MSG_ID_MMI_EQ_USBDETECT_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
#endif /* defined(__USB_ENABLE__) */
	/* MSG_ID_MMI_EQ_DATA_DL_FILELIST_INFO_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_DATA_DL_FILELIST_REPORT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_DATA_DL_FILELIST_REPORT_REQ_,
	/* MSG_ID_MMI_EQ_DATA_DL_FILELIST_REPORT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_DATA_DL_FILE_MODIFY_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_DATA_DL_FILE_MODIFY_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_DATA_DL_FILE_MODIFY_REQ_,
	/* MSG_ID_MMI_EQ_DATA_DL_FILE_MODIFY_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_DATA_DL_EXECUTE_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_DATA_DL_EXECUTE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_DATA_DL_EXECUTE_REQ_,
	/* MSG_ID_MMI_EQ_DATA_DL_EXECUTE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_WAP_MMC_READ_FOLDER_STATUS_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_WAP_MMC_READ_FOLDER_STATUS_OUTPUT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_WAP_MMC_READ_FOLDER_STATUS_OUTPUT_REQ_,
	/* MSG_ID_WAP_MMC_READ_FOLDER_STATUS_OUTPUT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_WAP_MMC_UPLOAD_MSG_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_WAP_MMC_UPLOAD_MSG_OUTPUT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_WAP_MMC_UPLOAD_MSG_OUTPUT_REQ_,
	/* MSG_ID_WAP_MMC_UPLOAD_MSG_OUTPUT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_WAP_MMC_DELETE_MSG_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_WAP_MMC_DELETE_MSG_OUTPUT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_WAP_MMC_DELETE_MSG_OUTPUT_REQ_,
	/* MSG_ID_WAP_MMC_DELETE_MSG_OUTPUT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_QUERY_GREETING_TEXT_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_QUERY_GREETING_TEXT_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_QUERY_GREETING_TEXT_RES_REQ_,
	/* MSG_ID_MMI_EQ_QUERY_GREETING_TEXT_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_QUERY_LANGUAGE_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_QUERY_LANGUAGE_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_QUERY_LANGUAGE_RES_REQ_,
	/* MSG_ID_MMI_EQ_QUERY_LANGUAGE_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_QUERY_SILENT_MODE_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_QUERY_SILENT_MODE_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_QUERY_SILENT_MODE_RES_REQ_,
	/* MSG_ID_MMI_EQ_QUERY_SILENT_MODE_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_QUERY_VIBRATOR_MODE_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_QUERY_VIBRATOR_MODE_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_QUERY_VIBRATOR_MODE_RES_REQ_,
	/* MSG_ID_MMI_EQ_QUERY_VIBRATOR_MODE_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_QUERY_DATE_TIME_FORMAT_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_QUERY_DATE_TIME_FORMAT_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_QUERY_DATE_TIME_FORMAT_RES_REQ_,
	/* MSG_ID_MMI_EQ_QUERY_DATE_TIME_FORMAT_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_QUERY_MUTE_MODE_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_QUERY_MUTE_MODE_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_QUERY_MUTE_MODE_RES_REQ_,
	/* MSG_ID_MMI_EQ_QUERY_MUTE_MODE_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_POWER_RESET_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_READY_NOTIFY_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_READY_NOTIFY_REQ_,
	/* MSG_ID_MMI_READY_NOTIFY_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_AT_GENERAL_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_AT_GENERAL_RES_REQ_,
	/* MSG_ID_MMI_AT_GENERAL_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_FACTORY_RESTORE_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_VCARD_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_VCARD_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_VCARD_RES_REQ_,
	/* MSG_ID_MMI_EQ_VCARD_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_VCALENDAR_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_VCALENDAR_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_VCALENDAR_RES_REQ_,
	/* MSG_ID_MMI_EQ_VCALENDAR_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_STR_ENABLE_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_STR_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_EQ_STR_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_EQ_STR_RES_REQ_,
	/* MSG_ID_MMI_EQ_STR_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_UCM_AT_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_UCM_AT_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_UCM_AT_RES_REQ_,
	/* MSG_ID_MMI_UCM_AT_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_UCM_GENERAL_RCODE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_UCM_GENERAL_RCODE_REQ_,
	/* MSG_ID_MMI_UCM_GENERAL_RCODE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_UCM_HF_CIEV_RCODE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_UCM_HF_CIEV_RCODE_REQ_,
	/* MSG_ID_MMI_UCM_HF_CIEV_RCODE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_JAVA_LOCAL_INSTALL_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_JAVA_LOCAL_INSTALL_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_JAVA_LOCAL_INSTALL_RES_REQ_,
	/* MSG_ID_MMI_JAVA_LOCAL_INSTALL_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
/* Bluetooth */
#if defined(__BT_SUPPORT__)
	/* MSG_ID_MMI_L4_BT_FCTY_SET_PARAM_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_L4_BT_LOOPBACK_TEST_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_L4_BT_SET_VR_REQ_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_L4_BT_SET_VR_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_L4_BT_SET_VR_REQ_,
	/* MSG_ID_MMI_L4_BT_SET_VR_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
#endif /* defined(__BT_SUPPORT__) */
/* HOMEZONE */
#if defined(__HOMEZONE_SUPPORT__)
	/* MSG_ID_MMI_HZ_TAG_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
#endif /* defined(__HOMEZONE_SUPPORT__) */
/* CTM */
#if defined(__CTM_SUPPORT__)
	/* MSG_ID_MMI_CTM_OPEN_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CTM_OPEN_REQ_,
	/* MSG_ID_MMI_CTM_OPEN_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CTM_CLOSE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CTM_CLOSE_REQ_,
	/* MSG_ID_MMI_CTM_CLOSE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CTM_CONNECT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CTM_CONNECT_REQ_,
	/* MSG_ID_MMI_CTM_CONNECT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CTM_CONNECTED_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CTM_SEND_TEXT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CTM_SEND_TEXT_REQ_,
	/* MSG_ID_MMI_CTM_SEND_TEXT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CTM_RECV_TEXT_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CTM_TTY_PLUG_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CTM_SET_DEFAULT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CTM_SET_DEFAULT_REQ_,
	/* MSG_ID_MMI_CTM_SET_DEFAULT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CTM_DEFAULT_CHANGED_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_CTM_GET_DEFAULT_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_CTM_GET_DEFAULT_REQ_,
	/* MSG_ID_MMI_CTM_GET_DEFAULT_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
#endif /* defined(__CTM_SUPPORT__) */
/* VOIP */
#if defined(__VOIP__)
	/* MSG_ID_MMI_VOIP_AT_CALL_CTRL_APPROVE_RES_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_VOIP_AT_CALL_CTRL_APPROVE_RES_REQ_,
	/* MSG_ID_MMI_VOIP_AT_CALL_CTRL_APPROVE_RES_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_VOIP_AT_CALL_CTRL_APPROVE_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
#endif /* defined(__VOIP__) */
/* GEMINI */
#if defined(__GEMINI__)
	/* MSG_ID_MMI_EQ_PWNON_DUAL_SIM_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_SIM_STATUS_UPDATE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMU_SIM_STATUS_UPDATE_REQ_,
	/* MSG_ID_MMI_SMU_SIM_STATUS_UPDATE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_SIM_STATUS_UPDATE_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_RAC_ACTIVATED_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_SMU_DUAL_SIM_TO_FLIGHT_MODE_REQ */ (L4A_VOID_FUNCTION) _call_MSG_ID_MMI_SMU_DUAL_SIM_TO_FLIGHT_MODE_REQ_,
	/* MSG_ID_MMI_SMU_DUAL_SIM_TO_FLIGHT_MODE_RSP */ (L4A_VOID_FUNCTION) NONE_FUNCTION,
	/* MSG_ID_MMI_NW_SEARCH_NORMAL_FINISH_IND */ (L4A_VOID_FUNCTION) NONE_FUNCTION
#endif /* defined(__GEMINI__) */

};

/*MTK:END*/

void l4c_init_lmmi(void)
{
}

/* l4a_cmd_ft.c */
/* l4a_callback.c */

/*
* FUNCTION
*	l4c_null_function_lrsp
* DESCRIPTION
*   this function should not be executed.
*
* CALLS
*	l4a_send_ft[]
* PARAMETERS
* 	none
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/

void l4c_null_function_lrsp(void)
{
	ASSERT(0);
}

void l4a_mms_read_folder_status_wind(kal_uint8  folderId,kal_uint8  retrievalMode)
{
	module_type dest = MOD_WAP;
	//mtk01616_070504:sometimes the message is handled by MOD_MMI instead of MOD_WAP 
#ifdef WAP_SUPPORT	
	dest = wap_get_service_module(MSG_ID_WAP_MMC_READ_FOLDER_STATUS_REQ_IND);
#endif
	_send_S_k_8_S_k_8_(l4c_current_mod_id,dest,MSG_ID_WAP_MMC_READ_FOLDER_STATUS_REQ_IND ,folderId,retrievalMode);
}

void l4a_mms_upload_msg_wind(kal_uint8*  filePath) 
{
	module_type dest = MOD_WAP;
	//mtk01616_070504:sometimes the message is handled by MOD_MMI instead of MOD_WAP 
#ifdef WAP_SUPPORT	
	dest = wap_get_service_module((kal_uint32)MSG_ID_WAP_MMC_UPLOAD_MSG_REQ_IND);
#endif
	_send_A100A_k_8_(l4c_current_mod_id,dest,MSG_ID_WAP_MMC_UPLOAD_MSG_REQ_IND ,filePath);
}

void l4a_mms_delete_msg_wind(kal_uint32  msgId,kal_uint8  folderId) 
{
	module_type dest = MOD_WAP;
	//mtk01616_070504:sometimes the message is handled by MOD_MMI instead of MOD_WAP 
#ifdef WAP_SUPPORT	
	dest = wap_get_service_module(MSG_ID_WAP_MMC_DELETE_MSG_REQ_IND);
#endif	
	_send_S_k_32_S_k_8_(l4c_current_mod_id,dest,MSG_ID_WAP_MMC_DELETE_MSG_REQ_IND ,msgId,folderId);
}

/*
* FUNCTION
*	l4c_ps_set_gprs_data_account_lrsp
* DESCRIPTION
*	send the gprs data account profile response to MMI or WAP
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC or WAP_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
#ifdef __MOD_TCM__
void l4c_ps_set_gprs_data_account_lrsp(kal_uint8 src_id,kal_bool result, kal_uint16 cause)
{
	module_type dest;
	if(src_id == WAP_SRC)
		dest = MOD_WAP;
	else
		dest = MOD_MMI;
	_send_S_k_bool_S_k_16_(l4c_current_mod_id,dest,MSG_ID_MMI_PS_SET_GPRS_DATA_ACCOUNT_RSP ,result,cause); //special case
}
#endif /* __MOD_TCM__ */

/*
* FUNCTION
*	l4c_cc_set_csd_profile_lrsp
* DESCRIPTION
*	send the csd profile response to MMI
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC or WAP_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_cc_set_csd_profile_lrsp(kal_uint8 src_id,kal_bool result, kal_uint16 cause)
{
	module_type dest;
	if(src_id == WAP_SRC)
		dest = MOD_WAP;
	else
		dest = MOD_MMI;
	_send_S_k_8_S_k_bool_S_k_16_(l4c_current_mod_id,dest,MSG_ID_MMI_CC_SET_CSD_PROFILE_RSP ,src_id,result,cause); //special case
}

/*
* FUNCTION
*	l4c_eq_keypad_detect_lind
* DESCRIPTION
*	send the keypad detect indicate to MMI
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_eq_keypad_detect_lind(drv_get_key_func func)
{
	l4a_eq_keypad_detect_lind(func);
}
/*
* FUNCTION
*	l4c_cphs_mmi_info_lind
* DESCRIPTION
*	send the cphs mmi info indicate to MMI
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_cphs_mmi_info_lind(kal_uint8 is_spn_valid,     // spn
							   kal_uint8 is_spn_RPLMN_required,
							   kal_uint8 *spn,
							   kal_uint8 is_opname_valid,  // opn
							   kal_uint8 *opname,
							   kal_uint8 is_sopname_valid, // sopn
							   kal_uint8 *sopname,
							   kal_uint8 no_msisdn,        // MSISDN
							   l4csmu_addr_struct msisdn[2],
							   kal_uint8 no_info_num,      // Information Numbers
							   l4csmu_info_num_struct *info_num,
							   kal_uint8 is_valid_csp,
							   kal_uint8 *csp,
							   kal_uint8 is_puct_valid,
							   kal_uint8 *ef_puct,
							   kal_uint8 is_autolock_enable,
							   kal_uint8 autolock_result,
							   kal_uint8 autolock_remain)
{
	struct ilm_struct *ilm_ptr=NULL;

	mmi_cphs_mmi_info_ind_struct *p
		= (mmi_cphs_mmi_info_ind_struct*) construct_local_para(
				(kal_uint16)
				(
					sizeof(mmi_cphs_mmi_info_ind_struct)
					+no_info_num*sizeof(l4csmu_info_num_struct)
				),0);
	p->is_spn_valid = is_spn_valid;
	p->is_spn_RPLMN_required = is_spn_RPLMN_required;
	if(spn) memcpy(p->spn,spn,17);
	p->is_opname_valid = is_opname_valid;
	if(opname) memcpy(p->opname,opname,21);
	p->is_sopname_valid = is_sopname_valid;
	if(sopname) memcpy(p->sopname,sopname,11);
	p->no_msisdn = no_msisdn;
	memcpy(p->msisdn,msisdn,sizeof(l4csmu_addr_struct)*2);
	p->no_info_num = no_info_num;
	if(info_num) memcpy(p->info_num,info_num,sizeof(l4csmu_info_num_struct)*no_info_num);
	p->is_valid_csp = is_valid_csp;
	if(csp) memcpy(p->csp,csp,22);
	p->is_puct_valid = is_puct_valid;
	if(ef_puct) memcpy(p->ef_puct, ef_puct, 5);
        p->is_autolock_enable = is_autolock_enable;
        p->autolock_result = autolock_result;
        p->autolock_remain = autolock_remain;        

	/* First allocate a memory for an interlayer message structure */
	ilm_ptr = allocate_ilm(l4c_current_mod_id);

	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_CPHS_MMI_INFO_IND;/* Set the message id */
	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;

	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
}


/*
* FUNCTION
*	l4c_cb_msg_lind
* DESCRIPTION
*	send the cell broadcast indicate to MMI
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_cb_msg_lind(l4csmsal_cb_msg_text_ind_struct* local_ptr)
{
	struct ilm_struct *ilm_ptr=NULL;

	mmi_cb_msg_ind_struct *p
		= (mmi_cb_msg_ind_struct*) construct_local_para(
				(kal_uint16)(
				sizeof(mmi_cb_msg_ind_struct)
				+local_ptr->msg_length),0);

	p->sn =local_ptr->sn;
	p->mi = local_ptr->mi;
	p->dcs = local_ptr->dcs;
	p->page = local_ptr->page;
	p->pages = local_ptr->pages;
	p->msg_length = (kal_uint16)local_ptr->msg_length;
	if(local_ptr->msg_data) memcpy(p->msg_data,local_ptr->msg_data,p->msg_length);

	/* First allocate a memory for an interlayer message structure */
	ilm_ptr = allocate_ilm(l4c_current_mod_id);

	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_CB_MSG_IND;/* Set the message id */
	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;

	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
}
/*
* FUNCTION
*	l4c_eq_read_nvram_lrsp
* DESCRIPTION
*	send the read nvram response message to MMI
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_eq_read_nvram_lrsp (l4c_result_struct result,
                                    kal_uint8 file_idx,
                                    kal_uint16 length,
                                    kal_uint8 *data)
{
	struct ilm_struct *ilm_ptr=NULL;

	mmi_eq_nvram_read_rsp_struct *p
		= (mmi_eq_nvram_read_rsp_struct*) construct_local_para((kal_uint16)(sizeof(mmi_eq_nvram_read_rsp_struct)+length+4),0);

	p->file_idx = file_idx;
	p->result = result;
	p->length = length;
	if(data) memcpy(p->data,data,length);

	/* First allocate a memory for an interlayer message structure */
	ilm_ptr = allocate_ilm(l4c_current_mod_id);

	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_EQ_NVRAM_READ_RSP;/* Set the message id */
	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;

	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
}
extern void l4a_send_result_struct_fail(module_type src,module_type dest,msg_type msg);

/*
* FUNCTION
*	l4c_sms_exe_read_msg_lrsp
* DESCRIPTION
*	send the read sms message response to MMI
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_sms_exe_read_msg_lrsp(kal_bool  result, kal_uint16 cause, smsal_concat_struct concat_info, 
									 kal_uint16 dest_port, kal_uint16 src_port,
                                                                         kal_uint16 length, kal_uint8 mti, kal_uint8 status, kal_uint8 hex_dspl,
									 kal_uint8 storage_type, l4_name_struct alpha_id, 
									 kal_uint8 *scts_submit, /* Johnny: only for SMSAL_MTI_SUBMIT */
									 void* msg_header, void* data)
{

#ifndef SMS_FOR_NEPTUNE
	ilm_struct *ilm_ptr;
	mmi_sms_get_msg_rsp_struct *p;


    /*kevin--begin*/
    l4c_number_struct *addr_num1=NULL;
    l4c_number_struct *addr_num2=NULL;
    l4_addr_bcd_struct *addr_bcd1=NULL;
    l4_addr_bcd_struct *addr_bcd2=NULL;
    /*kevin--end*/

	if(result == KAL_FALSE)
	{
    ilm_ptr=allocate_ilm(l4c_current_mod_id);

   	p=(mmi_sms_get_msg_rsp_struct*) construct_local_para(
   				(kal_uint16)(sizeof(mmi_sms_get_msg_rsp_struct)),0);
   
   	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_SMS_GET_MSG_RSP;/* Set the message id */
   	p->result = result;
   	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
   	ilm_ptr->local_para_ptr = (local_para_struct *)p;
   	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);	
		return ;
	}
    ilm_ptr=allocate_ilm(l4c_current_mod_id);

	p=(mmi_sms_get_msg_rsp_struct*) construct_local_para(
				(kal_uint16)(sizeof(mmi_sms_get_msg_rsp_struct)+length),0);

	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_SMS_GET_MSG_RSP;/* Set the message id */
	p->result = result;
	p->cause = cause;
	p->mti = mti;
	p->status = status;
	p->storage_type = storage_type;
	//p->hex_dspl = hex_dspl;
	//p->alpha_id = alpha_id;
        p->dest_port = dest_port;
        p->src_port = src_port;

	if(mti==SMSAL_MTI_SUBMIT)
	{
		smsal_submit_msg_hdr_struct* src = (smsal_submit_msg_hdr_struct*)msg_header;
		p->fo = src->fo;

                if(scts_submit) memcpy(p->scts,scts_submit,7); /* Johnny: only for SMSAL_MTI_SUBMIT */

		addr_num1 = &p->sca_number;
		addr_num2 = &p->addr_number;

		addr_bcd1 = &src->sca;
		addr_bcd2 = &src->da;

		p->pid = src->pid;
		p->dcs = src->dcs;
		p->ori_dcs = src->ori_dcs;
		p->vp = src->vp;
		p->no_msg_data = length;
		if(length) memcpy(p->msg_data,data,length);
	}
	else if(mti==SMSAL_MTI_DELIVER)
	{
		smsal_deliver_msg_hdr_struct* src = (smsal_deliver_msg_hdr_struct*)msg_header;
		p->fo = src->fo;
		if(src->scts) memcpy(p->scts,src->scts,7);


		addr_num1 = &p->sca_number;
		addr_num2 = &p->addr_number;

		addr_bcd1 = &src->sca;
		addr_bcd2 = &src->oa;


		p->pid = src->pid;
		p->dcs = src->dcs;
		p->ori_dcs = src->ori_dcs;
		p->no_msg_data = length;
		if(length) memcpy(p->msg_data,data,length);
	}
	else if(mti==SMSAL_MTI_STATUS_REPORT)
	{
		smsal_status_report_msg_hdr_struct* src = (smsal_status_report_msg_hdr_struct*)msg_header;
		p->fo = src->fo;
		p->mr = src->mr;
		if(src->scts) memcpy(p->scts,src->scts,7);

		addr_num1 = &p->addr_number;
		p->sca_number.length = 0;

		addr_bcd1 = &src->ra;

		if(src->dt) memcpy(p->dt  ,src->dt,7);
		p->st = src->st;
		p->pid = src->pid;
		p->dcs = src->dcs;
		p->ori_dcs = src->ori_dcs;
		p->no_msg_data = length;
		if(length) memcpy(p->msg_data,data,length);
	}

	/* add l4c_number_struct address modified by kevin -- begin */
	/* address1 */
	if(addr_num1)
	{
	   if(addr_bcd1->addr_length > 0)
	   addr_num1->type = addr_bcd1->addr_bcd[0];

	   /*Brad Begin*/
	   if((addr_num1->type & 0xf0) == 0xd0) /*See 03.40 9.1.2.5 Type-of-number: Alphanumeric(7-bit default alphabet)*/
	   {
	   	if(addr_bcd1->addr_length > 1)
	   	{
              kal_uint8 temp[41];
              kal_uint16 out_len;

	   	      addr_num1->length = smsal_msg_len_in_character(0,
                                             (kal_uint16)(addr_bcd1->addr_length-1),
                                             addr_bcd1->addr_bcd[addr_bcd1->addr_length-1]);

	   	      smsal_gsm7_unpack((kal_uint8 *)&(addr_bcd1->addr_bcd[1]),
                        	(kal_uint8 *)addr_num1->number,
                        	addr_num1->length,
                        	0);

              l4c_ConvertGSM7BitDefaultEncodingToAscii(temp, addr_num1->number, (kal_uint16)addr_num1->length, &out_len);
	   	      kal_mem_cpy(addr_num1->number, temp, out_len);
	   	      addr_num1->number[out_len] = 0x00;
	   	      addr_num1->length = out_len;

                }
                else
                {
                 	addr_num1->length = 0;
                }

	   }
	   /*Brad End*/
	   else
	   {
	   if(addr_bcd1->addr_length > 1)
	   {
           addr_num1->length = convert_to_digit((kal_uint8 *)&(addr_bcd1->addr_bcd[1]),
                                                (kal_uint8 *)addr_num1->number);
        }
           else
           {
              addr_num1->length = 0;
           }
        }
        }
        /* address2 */
	if(addr_num2)
	{
	   if(addr_bcd2->addr_length > 0)
	   addr_num2->type = addr_bcd2->addr_bcd[0];

	   /*Brad Begin*/
	   if((addr_num2->type & 0xf0) == 0xd0) /*See 03.40 9.1.2.5 Type-of-number: Alphanumeric(7-bit default alphabet)*/
	   {
	   	if(addr_bcd2->addr_length > 1)
	   	{
              kal_uint8 temp[41];
              kal_uint16 out_len;

	   	      //addr_num2->length = smsal_msg_len_in_character(0,
                      //                       (kal_uint16)(addr_bcd2->addr_length-1),
                      //                       addr_bcd2->addr_bcd[addr_bcd2->addr_length-1]);

	   	      //smsal_gsm7_unpack((kal_uint8 *)&(addr_bcd2->addr_bcd[1]),
                      //  	(kal_uint8 *)addr_num2->number,
                      //  	addr_num2->length,
                      // 	0);

              l4c_ConvertGSM7BitDefaultEncodingToAscii(temp, (kal_uint8 *)&(addr_bcd2->addr_bcd[1]), (kal_uint16)addr_bcd2->addr_length-1, &out_len);
	   	      kal_mem_cpy(addr_num2->number, temp, out_len);
	   	      addr_num2->number[out_len] = 0x00;
	   	      addr_num2->length = out_len;

                 }
                 else
                 {
                 	addr_num2->length = 0;
                 }

	   }
	   /*Brad End*/
	   else
	   {
		   if(addr_bcd2->addr_length > 1)
	   {
           addr_num2->length = convert_to_digit((kal_uint8 *)&(addr_bcd2->addr_bcd[1]),
                                                (kal_uint8 *)addr_num2->number);
        }
           else
           {
              addr_num2->length = 0;
           }
        }
        }

        kal_mem_cpy(&(p->concat_info), &concat_info, sizeof(smsal_concat_struct));
        
	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;
	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
	#endif
}


/*
* FUNCTION
*	l4c_sms_new_msg_text_lind
* DESCRIPTION
*	send the sms new message indicate to MMI
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_sms_new_msg_text_lind(kal_uint16 index,
								kal_uint16 dest_port,
								kal_uint16 src_port,
      								kal_uint8 mti,
      								kal_uint8 display_type,
      								kal_uint8 storage_type,
      								smsal_concat_struct *concat_info,
      								kal_uint16 message_len,
      								void *msg_header,
			                                   void *data)

{

#ifndef SMS_FOR_NEPTUNE
	struct ilm_struct *ilm_ptr=NULL;

	/*kevin--begin*/
        l4c_number_struct *addr_num1=NULL;
        l4c_number_struct *addr_num2=NULL;
        l4_addr_bcd_struct *addr_bcd1=NULL;
        l4_addr_bcd_struct *addr_bcd2=NULL;
        /*kevin--end*/

	switch (mti)
	{
		case (SMSAL_MTI_DELIVER):
		{
			mmi_sms_deliver_msg_ind_struct *p;
			smsal_deliver_msg_hdr_struct *msg_p = (smsal_deliver_msg_hdr_struct*)msg_header;

			ilm_ptr = allocate_ilm(l4c_current_mod_id);
			ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_SMS_DELIVER_MSG_IND;/* Set the message id */

			p= (mmi_sms_deliver_msg_ind_struct*) construct_local_para(
								(kal_uint16)(sizeof(mmi_sms_deliver_msg_ind_struct)
											+message_len+4),0);
			p->index = index;
			p->dest_port = dest_port;
			p->src_port = src_port;
			p->display_type = display_type;
			p->storage_type = storage_type;
			p->mti = mti;
			p->fo = msg_p->fo;
			if(msg_p->scts) memcpy(p->scts,msg_p->scts,7);

			/*kevin--start*/
			addr_num1 = &p->sca_number;
			addr_num2 = &p->oa_number;
			/*kevin--end*/


			/* kevin -- start */
			addr_bcd1 = &msg_p->sca;
			addr_bcd2 = &msg_p->oa;
                	/* kevin -- end */



                     memcpy(&(p->concat_info),concat_info,sizeof(smsal_concat_struct));

			p->pid = msg_p->pid;
			p->dcs = msg_p->dcs;
			p->ori_dcs = msg_p->ori_dcs;
			p->no_msg_data = message_len;
			if(message_len) memcpy(p->msg_data,data,message_len);

			ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
			ilm_ptr->local_para_ptr = (local_para_struct *)p;

			break;
		}
		case (SMSAL_MTI_STATUS_REPORT):
		{
			mmi_sms_status_report_ind_struct *p;
			smsal_status_report_msg_hdr_struct *msg_p = (smsal_status_report_msg_hdr_struct*)msg_header;

			ilm_ptr = allocate_ilm(l4c_current_mod_id);
			ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_SMS_STATUS_REPORT_IND;/* Set the message id */

			p= (mmi_sms_status_report_ind_struct*) construct_local_para(
								(kal_uint16)(sizeof(mmi_sms_status_report_ind_struct)
											+message_len+4),0);
			p->fo = msg_p->fo;
			//p->mr = msg_p->mr;
			if(msg_p->scts) memcpy(p->scts,msg_p->scts,7);
			if(msg_p->dt) memcpy(p->dt  ,msg_p->dt,7);


			addr_num1 = &p->ra_number;/*kevin*/


			//memcpy(&(p->ra),&(msg_p->ra),sizeof(l4_addr_bcd_struct));
			addr_bcd1 = &msg_p->ra;/*kevin*/

			p->st = msg_p->st;
			p->pid= msg_p->pid;
			p->dcs= msg_p->dcs;
			p->no_msg_data = message_len;
			if(message_len) memcpy(p->msg_data,data,message_len);
                        p->mr = msg_p->mr;

			ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
			ilm_ptr->local_para_ptr = (local_para_struct *)p;

			break;
		}


		default: ASSERT(0);/*kevin*/
		         break;
	}


	/* add l4c_number_struct address modified by kevin -- begin */
	/* address1 */
	if(addr_num1)
	{
	   if(addr_bcd1->addr_length > 0)
	   addr_num1->type = addr_bcd1->addr_bcd[0];

	   /*Brad Begin*/
	   if((addr_num1->type & 0xf0) == 0xd0) /*See 03.40 9.1.2.5 Type-of-number: Alphanumeric(7-bit default alphabet)*/
	   {
	   	if(addr_bcd1->addr_length > 1)
	   	{
              kal_uint8 temp[41];
              kal_uint16 out_len;

	   	      addr_num1->length = smsal_msg_len_in_character(0,
                                             (kal_uint16)(addr_bcd1->addr_length-1),
                                             addr_bcd1->addr_bcd[addr_bcd1->addr_length-1]);

	   	      smsal_gsm7_unpack((kal_uint8 *)&(addr_bcd1->addr_bcd[1]),
                        	(kal_uint8 *)addr_num1->number,
                        	addr_num1->length,
                        	0);

              l4c_ConvertGSM7BitDefaultEncodingToAscii(temp, addr_num1->number, (kal_uint16)addr_num1->length, &out_len);
	   	      kal_mem_cpy(addr_num1->number, temp, out_len);
	   	      addr_num1->number[out_len] = 0x00;
	   	      addr_num1->length = out_len;

                }
                else
                {
                 	addr_num1->length = 0;
                }

	   }
	   /*Brad End*/
	   else
	   {
	   if(addr_bcd1->addr_length > 1)
	   {
           addr_num1->length = convert_to_digit((kal_uint8 *)&(addr_bcd1->addr_bcd[1]),
                                                (kal_uint8 *)addr_num1->number);
        }
           else
           {
              addr_num1->length = 0;
           }
        }
        }
        /* address2 */
	if(addr_num2)
	{
	   if(addr_bcd2->addr_length > 0)
	   addr_num2->type = addr_bcd2->addr_bcd[0];

	   /*Brad Begin*/
	   if((addr_num2->type & 0xf0) == 0xd0) /*See 03.40 9.1.2.5 Type-of-number: Alphanumeric(7-bit default alphabet)*/
	   {
	   	if(addr_bcd2->addr_length > 1)
	   	{
              kal_uint8 temp[41];
              kal_uint16 out_len;

	   	      //addr_num2->length = smsal_msg_len_in_character(0,
                      //                       (kal_uint16)(addr_bcd2->addr_length-1),
                      //                       addr_bcd2->addr_bcd[addr_bcd2->addr_length-1]);

	   	      //smsal_gsm7_unpack((kal_uint8 *)&(addr_bcd2->addr_bcd[1]),
                      //  	(kal_uint8 *)addr_num2->number,
                      //  	addr_num2->length,
                      //  	0);

              l4c_ConvertGSM7BitDefaultEncodingToAscii(temp, (kal_uint8 *)&(addr_bcd2->addr_bcd[1]), (kal_uint16)addr_bcd2->addr_length-1, &out_len);
	   	      kal_mem_cpy(addr_num2->number, temp, out_len);
	   	      addr_num2->number[out_len] = 0x00;
	   	      addr_num2->length = out_len;

                 }
                 else
                 {
                 	addr_num2->length = 0;
                 }

	   }
	   /*Brad End*/
	   else
	   {
	   if(addr_bcd2->addr_length > 1)
	   {
           addr_num2->length = convert_to_digit((kal_uint8 *)&(addr_bcd2->addr_bcd[1]),
                                                (kal_uint8 *)addr_num2->number);
        }
           else
           {
              addr_num2->length = 0;
           }
        }
        }

       SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
       /* kevin -- end */
       #endif
}


void l4c_sms_startup_read_msg_lind(kal_uint8 startup_seq_num,
					kal_uint8 mti,
					kal_uint8 status,
					kal_uint8 storage_type,
					kal_uint16 index,
					kal_uint16 dest_port,
					kal_uint16 src_port,
					smsal_concat_struct *concat_info,
					kal_uint8 *submit_scts, /* Johnny: only for SMSAL_MTI_SUBMIT */
					kal_uint16 message_len,
					void *msg_header,
                                       	void *data)
{
#ifndef SMS_FOR_NEPTUNE
	struct ilm_struct *ilm_ptr;
	mmi_sms_startup_read_msg_ind_struct *p;

    /*kevin--begin*/
    l4c_number_struct *addr_num1=NULL;
    l4c_number_struct *addr_num2=NULL;
    l4_addr_bcd_struct *addr_bcd1=NULL;
    l4_addr_bcd_struct *addr_bcd2=NULL;
    /*kevin--end*/
    ilm_ptr=allocate_ilm(l4c_current_mod_id);


	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_SMS_STARTUP_READ_MSG_IND;/* Set the message id */

    	p= (mmi_sms_startup_read_msg_ind_struct*) construct_local_para(
								(kal_uint16)(sizeof(mmi_sms_startup_read_msg_ind_struct)
											+message_len+4),0);


    p->startup_seq_num = startup_seq_num;
    p->mti = mti;
    p->status = status;
    p->storage_type = storage_type;
    p->index = index;
    p->dest_port = dest_port;
    p->src_port = src_port;
    memcpy(&(p->concat_info),concat_info,sizeof(smsal_concat_struct));

	if(mti==SMSAL_MTI_SUBMIT)
	{
		smsal_submit_msg_hdr_struct* src = (smsal_submit_msg_hdr_struct*)msg_header;
		p->fo = src->fo;

                if(submit_scts) memcpy(p->scts,submit_scts,7); /* Johnny: only for SMSAL_MTI_SUBMIT */

		//addr_num1 = &p->sca_number;
		addr_num2 = &p->addr_number;

		//addr_bcd1 = &src->sca;
		addr_bcd2 = &src->da;

		p->pid = src->pid;
		p->dcs = src->dcs;
		p->ori_dcs = src->ori_dcs;
		p->vp = src->vp;
		p->no_msg_data = message_len;
		if(message_len) memcpy(p->msg_data,data,message_len);
	}
	else if(mti==SMSAL_MTI_DELIVER)
	{
		smsal_deliver_msg_hdr_struct* src = (smsal_deliver_msg_hdr_struct*)msg_header;
		p->fo = src->fo;
		if(src->scts) memcpy(p->scts,src->scts,7);


		//addr_num1 = &p->sca_number;
		addr_num2 = &p->addr_number;

		//addr_bcd1 = &src->sca;
		addr_bcd2 = &src->oa;


		p->pid = src->pid;
		p->dcs = src->dcs;
		p->ori_dcs = src->ori_dcs;
		p->no_msg_data = message_len;
		if(message_len) memcpy(p->msg_data,data,message_len);
	}
	else if(mti==SMSAL_MTI_STATUS_REPORT)
	{
		smsal_status_report_msg_hdr_struct* src = (smsal_status_report_msg_hdr_struct*)msg_header;
		p->fo = src->fo;
		p->mr = src->mr;
		if(src->scts) memcpy(p->scts,src->scts,7);

		addr_num1 = &p->addr_number;
		//p->sca_number.length = 0;

		addr_bcd1 = &src->ra;

		if(src->dt) memcpy(p->dt  ,src->dt,7);
		p->st = src->st;
		p->pid = src->pid;
		p->dcs = src->dcs;
		p->ori_dcs = src->ori_dcs;
		p->no_msg_data = message_len;
		if(message_len) memcpy(p->msg_data,data,message_len);
	}

	/* add l4c_number_struct address modified by kevin -- begin */
	/* address1 */
	if(addr_num1)
	{
	   if(addr_bcd1->addr_length > 0)
	   addr_num1->type = addr_bcd1->addr_bcd[0];

	   /*Brad Begin*/
	   if((addr_num1->type & 0xf0) == 0xd0) /*See 03.40 9.1.2.5 Type-of-number: Alphanumeric(7-bit default alphabet)*/
	   {
	   	if(addr_bcd1->addr_length > 1)
	   	{
              kal_uint8 temp[41];
              kal_uint16 out_len;

	   	      addr_num1->length = smsal_msg_len_in_character(0,
                                             (kal_uint16)(addr_bcd1->addr_length-1),
                                             addr_bcd1->addr_bcd[addr_bcd1->addr_length-1]);

	   	      smsal_gsm7_unpack((kal_uint8 *)&(addr_bcd1->addr_bcd[1]),
                        	(kal_uint8 *)addr_num1->number,
                        	addr_num1->length,
                        	0);

              l4c_ConvertGSM7BitDefaultEncodingToAscii(temp, addr_num1->number, (kal_uint16)addr_num1->length, &out_len);
	   	      kal_mem_cpy(addr_num1->number, temp, out_len);
	   	      addr_num1->number[out_len] = 0x00;
	   	      addr_num1->length = out_len;

                }
                else
                {
                 	addr_num1->length = 0;
                }

	   }
	   /*Brad End*/
	   else
	   {
	   if(addr_bcd1->addr_length > 1)
	   {
           addr_num1->length = convert_to_digit((kal_uint8 *)&(addr_bcd1->addr_bcd[1]),
                                                (kal_uint8 *)addr_num1->number);
        }
           else
           {
              addr_num1->length = 0;
           }
        }
        }
        /* address2 */
	if(addr_num2)
	{
	   if(addr_bcd2->addr_length > 0)
	   addr_num2->type = addr_bcd2->addr_bcd[0];

	   /*Brad Begin*/
	   if((addr_num2->type & 0xf0) == 0xd0) /*See 03.40 9.1.2.5 Type-of-number: Alphanumeric(7-bit default alphabet)*/
	   {
	   	if(addr_bcd2->addr_length > 1)
	   	{
              kal_uint8 temp[41];
              kal_uint16 out_len;

	   	      //addr_num2->length = smsal_msg_len_in_character(0,
                      //                       (kal_uint16)(addr_bcd2->addr_length-1),
                      //                       addr_bcd2->addr_bcd[addr_bcd2->addr_length-1]);

	   	      //smsal_gsm7_unpack((kal_uint8 *)&(addr_bcd2->addr_bcd[1]),
                      //  	(kal_uint8 *)addr_num2->number,
                      //  	addr_num2->length,
                      //  	0);

              l4c_ConvertGSM7BitDefaultEncodingToAscii(temp, (kal_uint8 *)&(addr_bcd2->addr_bcd[1]), (kal_uint16)addr_bcd2->addr_length-1, &out_len);
	   	      kal_mem_cpy(addr_num2->number, temp, out_len);
	   	      addr_num2->number[out_len] = 0x00;
	   	      addr_num2->length = out_len;

                 }
                 else
                 {
                 	addr_num2->length = 0;
                 }

	   }
	   /*Brad End*/
	   else
	   {
		   if(addr_bcd2->addr_length > 1)
	   {
           addr_num2->length = convert_to_digit((kal_uint8 *)&(addr_bcd2->addr_bcd[1]),
                                                (kal_uint8 *)addr_num2->number);
        }
           else
           {
              addr_num2->length = 0;
           }
        }
        }

	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;
	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
#endif
}
/*
* FUNCTION
*	l4c_eq_power_on_lind
* DESCRIPTION
*	send the power on indicate to MMI
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_eq_power_on_lind(kal_uint8  poweron_mode,kal_uint8  battery_level,kal_uint8  build_label,rtc_format_struct *rtc_time, kal_uint8 flightmode_state, kal_uint8 dual_sim_mode_setting, kal_uint8 dual_sim_uart_setting)
{
    l4a_eq_power_on_lind(poweron_mode,battery_level,build_label,rtc_time,flightmode_state,dual_sim_mode_setting, dual_sim_uart_setting);
	#ifndef __FLIGHT_MODE_SUPPORT__
	l4c_eq_load_power_on_data_req (LMMI_SRC, 0, 0);
	#endif
}
#define ALLOC_LOCAL_STRUCT(STRUCT,PADD_LEN) \
	(STRUCT*) construct_local_para((kal_uint16)(sizeof(STRUCT)+(PADD_LEN)),0); \
	MEMORY_END = ((kal_uint8*)p) + sizeof(STRUCT);

#define STRUCT_PSEUDO_ALLOC(LEN) MEMORY_END; MEMORY_END += LEN
#define STRUCT_ASSIGN_VALUE(DEST,SRC,MEMBER)  DEST->MEMBER = SRC->MEMBER
#define STRUCT_ASSIGN_ARRAY(DEST,SRC,MEMBER,LEN) if(SRC->MEMBER) memcpy(DEST->MEMBER,SRC->MEMBER,LEN)
#define STRUCT_ASSIGN_STRING(DEST,SRC,MEMBER,LEN)\
	{\
		kal_uint32 SIZE = LEN; \
		DEST->MEMBER = STRUCT_PSEUDO_ALLOC(SIZE); \
		STRUCT_ASSIGN_ARRAY (DEST,SRC,MEMBER,SIZE); \
	}

#ifdef __SAT__
/*
* FUNCTION
*	l4c_sat_dspl_text_lind
* DESCRIPTION
*	send the sim toolkit display text indicate to MMI
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_sat_dspl_text_lind(sat_dspl_text_ind_struct*  local_ptr,sat_dspl_text_ind_peer_struct*  peer_ptr)
{
	ilm_struct *ilm_ptr;
	kal_uint8 *MEMORY_END;

	mmi_sat_display_text_ind_struct *p=ALLOC_LOCAL_STRUCT(mmi_sat_display_text_ind_struct
		,peer_ptr->no_text_string);


	STRUCT_ASSIGN_ARRAY (p,local_ptr,cmd_detail,5);
	STRUCT_ASSIGN_VALUE (p,local_ptr,priority);
	STRUCT_ASSIGN_VALUE (p,local_ptr,clear_text_type);
	STRUCT_ASSIGN_VALUE (p,local_ptr,immediate_res);
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_icon_available);
	STRUCT_ASSIGN_VALUE (p,local_ptr,icon_info);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_text_string);
	STRUCT_ASSIGN_STRING(p,peer_ptr,text_string, p->no_text_string);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,dcs_of_text_string);

	ilm_ptr = allocate_ilm(l4c_current_mod_id);
	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_SAT_DISPLAY_TEXT_IND;

	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;
	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
}
/*
* FUNCTION
*	l4c_sat_get_inkey_lind
* DESCRIPTION
*	send the sim toolkit get key indicate to MMI
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_sat_get_inkey_lind(sat_get_inkey_ind_struct*  local_ptr,sat_get_inkey_ind_peer_struct*  peer_ptr)
{
	ilm_struct *ilm_ptr;
	kal_uint8 *MEMORY_END;

	mmi_sat_get_inkey_ind_struct *p=ALLOC_LOCAL_STRUCT(mmi_sat_get_inkey_ind_struct
		,peer_ptr->no_text_string);

	STRUCT_ASSIGN_ARRAY (p,local_ptr,cmd_detail,5);
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_help_info_available);
	STRUCT_ASSIGN_VALUE (p,local_ptr,type_of_input);
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_icon_available);
	STRUCT_ASSIGN_VALUE (p,local_ptr,icon_info);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_text_string);
	STRUCT_ASSIGN_STRING(p,peer_ptr,text_string, p->no_text_string);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,dcs_of_text_string);

	ilm_ptr = allocate_ilm(l4c_current_mod_id);
	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_SAT_GET_INKEY_IND;

	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;
	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
}
/*
* FUNCTION
*	l4c_sat_get_input_lind
* DESCRIPTION
*	send the simtoolkit get input indicate to MMI
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_sat_get_input_lind(sat_get_input_ind_struct*  local_ptr,sat_get_input_ind_peer_struct*  peer_ptr)
{
	ilm_struct *ilm_ptr;
	kal_uint8 *MEMORY_END;

	mmi_sat_get_input_ind_struct *p=ALLOC_LOCAL_STRUCT(mmi_sat_get_input_ind_struct
		,peer_ptr->no_text_string
		+peer_ptr->no_default_text);

	STRUCT_ASSIGN_ARRAY (p,local_ptr,cmd_detail,5);
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_help_info_available);
	STRUCT_ASSIGN_VALUE (p,local_ptr,type_of_input);
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_input_revealed_to_user);
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_icon_available);
	STRUCT_ASSIGN_VALUE (p,local_ptr,len_of_min_input);
	STRUCT_ASSIGN_VALUE (p,local_ptr,icon_info);
	STRUCT_ASSIGN_VALUE (p,local_ptr,len_of_max_input);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_text_string);
	STRUCT_ASSIGN_STRING(p,peer_ptr,text_string, p->no_text_string);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,dcs_of_text_string);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_default_text);
	STRUCT_ASSIGN_STRING(p,peer_ptr,default_text, p->no_default_text);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,dcs_of_default_text);

	ilm_ptr = allocate_ilm(l4c_current_mod_id);
	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_SAT_GET_INPUT_IND;

	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;
	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
}
/*
* FUNCTION
*	l4c_sat_setup_menu_lind
* DESCRIPTION
*	send the simtoolkit setup menu indicate to MMI
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_sat_setup_menu_lind(sat_setup_menu_ind_struct*  local_ptr,sat_setup_menu_ind_peer_struct*  peer_ptr)
{
	ilm_struct *ilm_ptr;
	kal_uint8 *MEMORY_END;

	mmi_sat_setup_menu_ind_struct *p=ALLOC_LOCAL_STRUCT(mmi_sat_setup_menu_ind_struct
		,peer_ptr->no_alpha_id
		+peer_ptr->no_item_data
		+peer_ptr->no_item_icon_id_list
		+peer_ptr->no_next_action_ind_list);

	STRUCT_ASSIGN_ARRAY (p,local_ptr,cmd_detail,5);
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_help_info_available);
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_softkey_preferred);
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_icon_available);
	STRUCT_ASSIGN_VALUE (p,local_ptr,icon_info);
	STRUCT_ASSIGN_VALUE (p,local_ptr,num_of_item);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_alpha_id);
	STRUCT_ASSIGN_STRING(p,peer_ptr,alpha_id, p->no_alpha_id);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,dcs_of_alpha_id);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_item_data);
	STRUCT_ASSIGN_STRING(p,peer_ptr,item_data, p->no_item_data);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_item_icon_id_list);
	STRUCT_ASSIGN_STRING(p,peer_ptr,item_icon_id_list, p->no_item_icon_id_list);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,item_icon_list_attr);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_next_action_ind_list);
	STRUCT_ASSIGN_STRING(p,peer_ptr,next_action_ind_list, p->no_next_action_ind_list);

	ilm_ptr = allocate_ilm(l4c_current_mod_id);
	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_SAT_SETUP_MENU_IND;

	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;
	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
}
/*
* FUNCTION
*	l4c_sat_select_item_lind
* DESCRIPTION
*	send the simtoolkit select item indicate to MMI
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_sat_select_item_lind(sat_select_item_ind_struct*  local_ptr,sat_select_item_ind_peer_struct*  peer_ptr)
{
	ilm_struct *ilm_ptr;
	kal_uint8 *MEMORY_END;

	mmi_sat_select_item_ind_struct *p=ALLOC_LOCAL_STRUCT(mmi_sat_select_item_ind_struct
		,peer_ptr->no_alpha_id
		+peer_ptr->no_item_data
		+peer_ptr->no_item_icon_id_list
		+peer_ptr->no_next_action_ind_list);

	STRUCT_ASSIGN_ARRAY (p,local_ptr,cmd_detail,5);
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_help_info_available);
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_softkey_preferred);
	STRUCT_ASSIGN_VALUE (p,local_ptr,type_of_presentation);
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_icon_available);
	STRUCT_ASSIGN_VALUE (p,local_ptr,icon_info);
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_item_id_available);
	STRUCT_ASSIGN_VALUE (p,local_ptr,item_id);
	STRUCT_ASSIGN_VALUE (p,local_ptr,num_of_item);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_alpha_id);
	STRUCT_ASSIGN_STRING(p,peer_ptr,alpha_id, p->no_alpha_id);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,dcs_of_alpha_id);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_item_data);
	STRUCT_ASSIGN_STRING(p,peer_ptr,item_data, p->no_item_data);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_item_icon_id_list);
	STRUCT_ASSIGN_STRING(p,peer_ptr,item_icon_id_list, p->no_item_icon_id_list);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,item_icon_list_attr);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_next_action_ind_list);
	STRUCT_ASSIGN_STRING(p,peer_ptr,next_action_ind_list, p->no_next_action_ind_list);

	ilm_ptr = allocate_ilm(l4c_current_mod_id);
	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_SAT_SELECT_ITEM_IND;

	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;
	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
}
/*
* FUNCTION
*	l4c_sat_select_item_lind
* DESCRIPTION
*	send the simtoolkit play tone indicate to MMI
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_sat_play_tone_lind(sat_play_tone_ind_struct*  local_ptr,sat_play_tone_ind_peer_struct*  peer_ptr)
{
	ilm_struct *ilm_ptr;
	kal_uint8 *MEMORY_END;

	mmi_sat_play_tone_ind_struct *p=ALLOC_LOCAL_STRUCT(mmi_sat_play_tone_ind_struct
		,peer_ptr->no_alpha_id);

	STRUCT_ASSIGN_ARRAY (p,local_ptr,cmd_detail,5);
	STRUCT_ASSIGN_VALUE (p,local_ptr,tone_id);
	STRUCT_ASSIGN_VALUE (p,local_ptr,duration);
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_icon_available);
	STRUCT_ASSIGN_VALUE (p,local_ptr,icon_info);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_alpha_id);
	STRUCT_ASSIGN_STRING(p,peer_ptr,alpha_id, p->no_alpha_id);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,dcs_of_alpha_id);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,is_alpha_id_present);

	ilm_ptr = allocate_ilm(l4c_current_mod_id);
	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_SAT_PLAY_TONE_IND;

	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;
	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
}
/*
* FUNCTION
*	l4c_sat_setup_call_lind
* DESCRIPTION
*	send the simtoolkit setup call indicate to MMI
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_sat_setup_call_lind(sat_setup_call_ind_struct*  local_ptr,sat_setup_call_ind_peer_struct*  peer_ptr)
{
	ilm_struct *ilm_ptr;
	kal_uint8 *MEMORY_END;

	mmi_sat_call_setup_ind_struct *p=ALLOC_LOCAL_STRUCT(mmi_sat_call_setup_ind_struct
		,peer_ptr->no_alpha_id1
		+peer_ptr->no_addr
		+peer_ptr->no_alpha_id2);

	STRUCT_ASSIGN_ARRAY (p,local_ptr,cmd_detail,5);
	STRUCT_ASSIGN_VALUE (p,local_ptr,condition);
	STRUCT_ASSIGN_VALUE (p,local_ptr,duration);
////	STRUCT_ASSIGN_VALUE (p,local_ptr,is_changed_from_ss);
	STRUCT_ASSIGN_VALUE (p,local_ptr,type_of_modification);//mtk01616_070521
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_icon1_available);
	STRUCT_ASSIGN_VALUE (p,local_ptr,icon_info1);
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_icon2_available);
	STRUCT_ASSIGN_VALUE (p,local_ptr,icon_info2);
	STRUCT_ASSIGN_VALUE (p,local_ptr,size_of_ccp);
	STRUCT_ASSIGN_ARRAY (p,local_ptr,ccp,p->size_of_ccp);
	STRUCT_ASSIGN_VALUE (p,local_ptr,size_of_subaddr);
	STRUCT_ASSIGN_ARRAY (p,local_ptr,subaddr,p->size_of_subaddr);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,is_alpha_id1_present);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_alpha_id1);
	STRUCT_ASSIGN_STRING(p,peer_ptr,alpha_id1, p->no_alpha_id1);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,dcs_of_alpha_id1);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_addr);
	STRUCT_ASSIGN_STRING(p,peer_ptr,addr, p->no_addr);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,is_alpha_id2_present);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_alpha_id2);
	STRUCT_ASSIGN_STRING(p,peer_ptr,alpha_id2, p->no_alpha_id2);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,dcs_of_alpha_id2);


	ilm_ptr = allocate_ilm(l4c_current_mod_id);
	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_SAT_CALL_SETUP_IND;

	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;
	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
}
/*
* FUNCTION
*	l4c_sat_send_sms_lind
* DESCRIPTION
*	send the simtoolkit send sms indicate to MMI
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_sat_send_sms_lind(sat_send_sms_ind_struct*  local_ptr,sat_send_sms_ind_peer_struct*  peer_ptr)
{
	ilm_struct *ilm_ptr;
	kal_uint8 *MEMORY_END;

	mmi_sat_send_sms_ind_struct *p=ALLOC_LOCAL_STRUCT(mmi_sat_send_sms_ind_struct
		,peer_ptr->no_alpha_id
		+peer_ptr->no_sms_tpdu);

	STRUCT_ASSIGN_ARRAY (p,local_ptr,cmd_detail,5);
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_icon_available);
	STRUCT_ASSIGN_VALUE (p,local_ptr,icon_info);
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_sms_packed_required);
	STRUCT_ASSIGN_VALUE (p,local_ptr,size_of_addr);
	STRUCT_ASSIGN_ARRAY (p,local_ptr,addr,p->size_of_addr);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,is_alpha_id_present);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_alpha_id);
	STRUCT_ASSIGN_STRING(p,peer_ptr,alpha_id, p->no_alpha_id);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,dcs_of_alpha_id);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_sms_tpdu);
	STRUCT_ASSIGN_STRING(p,peer_ptr,sms_tpdu, p->no_sms_tpdu);

	ilm_ptr = allocate_ilm(l4c_current_mod_id);
	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_SAT_SEND_SMS_IND;

	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;
	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
}
/*
* FUNCTION
*	l4c_sat_send_ss_lind
* DESCRIPTION
*	send the simtoolkit send ss string indicate to MMI
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_sat_send_ss_lind(sat_send_ss_ind_struct*  local_ptr,sat_send_ss_ind_peer_struct*  peer_ptr)
{
	ilm_struct *ilm_ptr;
	kal_uint8 *MEMORY_END;

	mmi_sat_send_ss_ind_struct *p=ALLOC_LOCAL_STRUCT(mmi_sat_send_ss_ind_struct
		,peer_ptr->no_alpha_id
		+peer_ptr->no_ss_string);

	STRUCT_ASSIGN_ARRAY (p,local_ptr,cmd_detail,5);
////	STRUCT_ASSIGN_VALUE (p,local_ptr,is_changed_from_setupcall);
	STRUCT_ASSIGN_VALUE (p,local_ptr,type_of_modification); //mtk01616_070521
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_icon_available);
	STRUCT_ASSIGN_VALUE (p,local_ptr,icon_info);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,is_alpha_id_present);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_alpha_id);
	STRUCT_ASSIGN_STRING(p,peer_ptr,alpha_id, p->no_alpha_id);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,dcs_of_alpha_id);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_ss_string);
	STRUCT_ASSIGN_STRING(p,peer_ptr,ss_string, p->no_ss_string);

	ilm_ptr = allocate_ilm(l4c_current_mod_id);
	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_SAT_SEND_SS_IND;

	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;
	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
}
/*
* FUNCTION
*	l4c_sat_send_ussd_lind
* DESCRIPTION
*	send the simtoolkit send ussd string indicate to MMI
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_sat_send_ussd_lind(sat_send_ussd_ind_struct*  local_ptr,sat_send_ussd_ind_peer_struct*  peer_ptr)
{
	ilm_struct *ilm_ptr;
	kal_uint8 *MEMORY_END;

	mmi_sat_send_ussd_ind_struct *p=ALLOC_LOCAL_STRUCT(mmi_sat_send_ussd_ind_struct
		,peer_ptr->no_alpha_id
		+peer_ptr->no_ussd_string);

	STRUCT_ASSIGN_ARRAY (p,local_ptr,cmd_detail,5);
////	STRUCT_ASSIGN_VALUE (p,local_ptr,is_changed_from_setupcall);
	STRUCT_ASSIGN_VALUE (p,local_ptr,type_of_modification); //mtk01616_070521
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_icon_available);
	STRUCT_ASSIGN_VALUE (p,local_ptr,icon_info);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,is_alpha_id_present);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_alpha_id);
	STRUCT_ASSIGN_STRING(p,peer_ptr,alpha_id, p->no_alpha_id);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,dcs_of_alpha_id);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_ussd_string);
	STRUCT_ASSIGN_STRING(p,peer_ptr,ussd_string, p->no_ussd_string);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,dcs_of_ussd_string);

	ilm_ptr = allocate_ilm(l4c_current_mod_id);
	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_SAT_SEND_USSD_IND;

	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;
	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
}
/*
* FUNCTION
*	l4c_sat_mmi_info_lind
* DESCRIPTION
*	send the simtoolkit mmi info indicate to MMI
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_sat_mmi_info_lind(sat_mmi_info_ind_struct*  local_ptr,sat_mmi_info_ind_peer_struct*  peer_ptr)
{
	ilm_struct *ilm_ptr;
	kal_uint8 *MEMORY_END;

	mmi_sat_mmi_info_ind_struct *p=ALLOC_LOCAL_STRUCT(mmi_sat_mmi_info_ind_struct
		,peer_ptr->no_alpha_id);

	STRUCT_ASSIGN_VALUE (p,local_ptr,mmi_info_type);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,is_alpha_id_present);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_alpha_id);
	STRUCT_ASSIGN_STRING(p,peer_ptr,alpha_id, p->no_alpha_id);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,dcs_of_alpha_id);
	if ( local_ptr->len_of_address == 0 )
	   p->len_of_address=0;
	else
	{
           p->ton = local_ptr->address[0];
           p->len_of_address = convert_to_digit (&(local_ptr->address[1]), p->address);
        }
	ilm_ptr = allocate_ilm(l4c_current_mod_id);
	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_SAT_MMI_INFO_IND;

	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;
	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
}
/*
* FUNCTION
*	l4c_sat_setup_idle_dspl_lind
* DESCRIPTION
*	send the simtoolkit setup idle display indicate to MMI
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_sat_setup_idle_dspl_lind(sat_setup_idle_dspl_ind_struct*  local_ptr,sat_setup_idle_dspl_ind_peer_struct*  peer_ptr)
{
	ilm_struct *ilm_ptr;
	kal_uint8 *MEMORY_END;

	mmi_sat_setup_idle_display_ind_struct *p=ALLOC_LOCAL_STRUCT(mmi_sat_setup_idle_display_ind_struct
		,peer_ptr->no_text_string);


	STRUCT_ASSIGN_ARRAY (p,local_ptr,cmd_detail,5);
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_icon_available);
	STRUCT_ASSIGN_VALUE (p,local_ptr,icon_info);


	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_text_string);
	STRUCT_ASSIGN_STRING(p,peer_ptr,text_string, p->no_text_string);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,dcs_of_text_string);

	ilm_ptr = allocate_ilm(l4c_current_mod_id);
	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_SAT_SETUP_IDLE_DISPLAY_IND;

	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;
	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
}
/*
* FUNCTION
*	l4c_sat_run_at_command_lind
* DESCRIPTION
*	send the simtoolkit run at command indicate to MMI
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_sat_run_at_command_lind(sat_run_at_command_ind_struct *local_ptr,
                                         sat_run_at_command_ind_peer_struct *peer_ptr)
{
	ilm_struct *ilm_ptr;
	kal_uint8 *MEMORY_END;

	mmi_sat_run_at_command_ind_struct *p=ALLOC_LOCAL_STRUCT(mmi_sat_run_at_command_ind_struct
		,peer_ptr->no_alpha_id
		+peer_ptr->no_at_command);


	STRUCT_ASSIGN_ARRAY (p,local_ptr,cmd_detail,5);
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_icon_available);
	STRUCT_ASSIGN_VALUE (p,local_ptr,icon_info);


	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_alpha_id);
	STRUCT_ASSIGN_STRING(p,peer_ptr,alpha_id, p->no_alpha_id);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,is_alpha_id_present);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,dcs_of_alpha_id);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_at_command);
	STRUCT_ASSIGN_STRING(p,peer_ptr,at_command, p->no_at_command);


	ilm_ptr = allocate_ilm(l4c_current_mod_id);
	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_SAT_RUN_AT_COMMAND_IND;

	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;
	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
}
/*
* FUNCTION
*	l4c_sat_send_dtmf_lind
* DESCRIPTION
*	send the simtoolkit send dtmf indicate to MMI
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_sat_send_dtmf_lind (sat_send_dtmf_ind_struct *local_ptr,
                                    sat_send_dtmf_ind_peer_struct *peer_ptr)
{
	ilm_struct *ilm_ptr;
	kal_uint8 *MEMORY_END;

	mmi_sat_send_dtmf_ind_struct *p=ALLOC_LOCAL_STRUCT(mmi_sat_send_dtmf_ind_struct
		,peer_ptr->no_alpha_id
		+peer_ptr->no_dtmf);

	STRUCT_ASSIGN_ARRAY (p,local_ptr,cmd_detail,5);
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_icon_available);
	STRUCT_ASSIGN_VALUE (p,local_ptr,icon_info);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_alpha_id);
	STRUCT_ASSIGN_STRING(p,peer_ptr,alpha_id, p->no_alpha_id);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,is_alpha_id_present);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,dcs_of_alpha_id);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_dtmf);
	STRUCT_ASSIGN_STRING(p,peer_ptr,dtmf, p->no_dtmf);


	ilm_ptr = allocate_ilm(l4c_current_mod_id);
	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_SAT_SEND_DTMF_IND;

	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;
	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
}
/*
* FUNCTION
*	l4c_sat_lang_notify_lind
* DESCRIPTION
*	send the simtoolkit language notify indicate to MMI
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_sat_lang_notify_lind (sat_lang_notify_ind_struct *local_ptr)
{
	ilm_struct *ilm_ptr;
	kal_uint8 *MEMORY_END;

	mmi_sat_lang_notify_ind_struct *p=ALLOC_LOCAL_STRUCT(
		mmi_sat_lang_notify_ind_struct
		,0);

	STRUCT_ASSIGN_ARRAY (p,local_ptr,cmd_detail,5);
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_language_specified);
	STRUCT_ASSIGN_ARRAY (p,local_ptr,iso639_language,2);

	ilm_ptr = allocate_ilm(l4c_current_mod_id);
	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_SAT_LANG_NOTIFY_IND;

	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;
	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
}
/*
* FUNCTION
*	l4c_sat_launch_browser_lind
* DESCRIPTION
*	send the simtoolkit launch browser indicate to MMI
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_sat_launch_browser_lind (sat_launch_browser_ind_struct *local_ptr,
                                  sat_launch_browser_ind_peer_struct *peer_ptr)
{
	ilm_struct *ilm_ptr;
	kal_uint8 *MEMORY_END;

	mmi_sat_launch_browser_ind_struct *p=ALLOC_LOCAL_STRUCT(
		mmi_sat_launch_browser_ind_struct
		,peer_ptr->no_url
		+peer_ptr->no_alpha_id
		+peer_ptr->no_bearer
		+peer_ptr->no_gateway
		);


	STRUCT_ASSIGN_ARRAY (p,local_ptr,cmd_detail,5);
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_icon_available);
	STRUCT_ASSIGN_VALUE (p,local_ptr,icon_info);
	STRUCT_ASSIGN_VALUE (p,local_ptr,browser_mode);
	STRUCT_ASSIGN_VALUE (p,local_ptr,browser_identity);
	STRUCT_ASSIGN_ARRAY (p,local_ptr,provision_file_id,10);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_alpha_id);
	STRUCT_ASSIGN_STRING(p,peer_ptr,alpha_id, p->no_alpha_id);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,is_alpha_id_present);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,dcs_of_alpha_id);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_url);
	STRUCT_ASSIGN_STRING(p,peer_ptr,url, p->no_url);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_bearer);
	STRUCT_ASSIGN_STRING(p,peer_ptr,bearer, p->no_bearer);

	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_gateway);
	STRUCT_ASSIGN_STRING(p,peer_ptr,gateway, p->no_gateway);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,dcs_of_gateway);

	ilm_ptr = allocate_ilm(l4c_current_mod_id);
	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_SAT_LAUNCH_BROWSER_IND;

	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;
	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
}

/*
* FUNCTION
*	l4c_sat_no_other_cmd_lind
* DESCRIPTION
*	send the simtoolkit launch browser indicate to MMI
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_sat_no_other_cmd_lind (void)
{
	ilm_struct *ilm_ptr;


	ilm_ptr = allocate_ilm(l4c_current_mod_id);
	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_SAT_NO_OTHER_CMD_IND;

	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = NULL;
	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
}

#endif /* end of __sat__ */
#ifdef __SATCE__

void l4c_sat_open_channel_lind (l4csmu_sat_open_channel_ind_struct *local_ptr,
                                  l4csmu_sat_open_channel_ind_peer_struct *peer_ptr)
{
	ilm_struct *ilm_ptr;
	kal_uint8 *MEMORY_END;

	mmi_sat_open_channel_ind_struct *p=ALLOC_LOCAL_STRUCT(
		mmi_sat_open_channel_ind_struct
		,peer_ptr->no_alpha_id

		);


	STRUCT_ASSIGN_ARRAY (p,local_ptr,cmd_detail,5);
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_icon_available);
	STRUCT_ASSIGN_VALUE (p,local_ptr,icon_info);


	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_alpha_id);
	STRUCT_ASSIGN_STRING(p,peer_ptr,alpha_id, p->no_alpha_id);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,is_alpha_id_present);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,dcs_of_alpha_id);



	ilm_ptr = allocate_ilm(l4c_current_mod_id);
	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_SAT_OPEN_CHANNEL_IND;

	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;
	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
}


void l4c_sat_close_channel_lind (l4csmu_sat_close_channel_ind_struct *local_ptr,
                                  l4csmu_sat_close_channel_ind_peer_struct *peer_ptr)
{
	ilm_struct *ilm_ptr;
	kal_uint8 *MEMORY_END;

	mmi_sat_close_channel_ind_struct *p=ALLOC_LOCAL_STRUCT(
		mmi_sat_close_channel_ind_struct
		,peer_ptr->no_alpha_id

		);


	STRUCT_ASSIGN_ARRAY (p,local_ptr,cmd_detail,5);
	///STRUCT_ASSIGN_VALUE (p,local_ptr,state);
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_icon_available);
	STRUCT_ASSIGN_VALUE (p,local_ptr,icon_info);


	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_alpha_id);
	STRUCT_ASSIGN_STRING(p,peer_ptr,alpha_id, p->no_alpha_id);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,is_alpha_id_present);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,dcs_of_alpha_id);



	ilm_ptr = allocate_ilm(l4c_current_mod_id);
	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_SAT_CLOSE_CHANNEL_IND;

	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;
	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
}

void l4c_sat_send_data_lind (l4csmu_sat_send_data_ind_struct *local_ptr,
                                  l4csmu_sat_send_data_ind_peer_struct *peer_ptr)
{
	ilm_struct *ilm_ptr;
	kal_uint8 *MEMORY_END;

	mmi_sat_send_data_ind_struct *p=ALLOC_LOCAL_STRUCT(
		mmi_sat_send_data_ind_struct
		,peer_ptr->no_alpha_id

		);


	STRUCT_ASSIGN_ARRAY (p,local_ptr,cmd_detail,5);
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_icon_available);
	STRUCT_ASSIGN_VALUE (p,local_ptr,icon_info);
/////	STRUCT_ASSIGN_VALUE (p,local_ptr,data_size);


	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_alpha_id);
	STRUCT_ASSIGN_STRING(p,peer_ptr,alpha_id, p->no_alpha_id);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,is_alpha_id_present);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,dcs_of_alpha_id);



	ilm_ptr = allocate_ilm(l4c_current_mod_id);
	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_SAT_SEND_DATA_IND;

	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;
	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
}

void l4c_sat_recv_data_lind (l4csmu_sat_recv_data_ind_struct *local_ptr,
                                  l4csmu_sat_recv_data_ind_peer_struct *peer_ptr)
{
	ilm_struct *ilm_ptr;
	kal_uint8 *MEMORY_END;

	mmi_sat_recv_data_ind_struct *p=ALLOC_LOCAL_STRUCT(
		mmi_sat_recv_data_ind_struct
		,peer_ptr->no_alpha_id

		);


	STRUCT_ASSIGN_ARRAY (p,local_ptr,cmd_detail,5);
	STRUCT_ASSIGN_VALUE (p,local_ptr,is_icon_available);
	STRUCT_ASSIGN_VALUE (p,local_ptr,icon_info);
////	STRUCT_ASSIGN_VALUE (p,local_ptr,ch_data_length);//mtk01616_070530


	STRUCT_ASSIGN_VALUE (p,peer_ptr,no_alpha_id);
	STRUCT_ASSIGN_STRING(p,peer_ptr,alpha_id, p->no_alpha_id);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,is_alpha_id_present);
	STRUCT_ASSIGN_VALUE (p,peer_ptr,dcs_of_alpha_id);



	ilm_ptr = allocate_ilm(l4c_current_mod_id);
	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_SAT_RECV_DATA_IND;

	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;
	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
}
#endif /* __SATCE__*/


////////////////////////////////////////////////////////////////////////////////////////////////
/// the follow codes will be removed !!!
/// BEGIN:REMOVE
/*
void l4a_eq_volume_change_ind(kal_uint8  volume_type,kal_uint8  volume_level)
{
	l4c_eq_set_volume_req_ind(volume_type,volume_level);
}
void l4a_eq_mute_change_ind(kal_uint8  audio_device,kal_bool  mute_onoff)
{
	l4c_eq_set_mute_mode_req_ind(audio_device,mute_onoff);
}
void l4a_eq_set_gpio_level_req_ind (kal_uint8 gpio_dev_type,   kal_uint8 gpio_dev_level)
{

}
void l4a_eq_exe_rtc_delete_req_ind (kal_uint8 rtc_type,
                                      kal_uint8 rtc_index){}

*/
kal_bool l4a_eq_set_gpio_level_req (kal_uint8 src_id, kal_uint8 gpio_dev_type, kal_uint8 gpio_dev_level)
{
	return KAL_TRUE;
}
/// END:REMOVE
///////////////////////////////////////////////////////////////////////////////////////////////////

void l4c_eq_get_audio_param_lrsp(kal_bool  result,audio_param_struct  *param ) 
			{//_send_S_k_bool_S_audio_param_s_(l4c_current_mod_id,RSP_DEST,MSG_ID_MMI_EQ_GET_AUDIO_PARAM_RSP , result , param );}
			//{_send_S_k_bool_PS_audio_param_s_(l4c_current_mod_id,MOD_MMI,MSG_ID_MMI_EQ_GET_AUDIO_PARAM_RSP ,result,audio_para);}				
	msg_S_k_bool_S_audio_param_s__struct *p= construct_local_para(sizeof(msg_S_k_bool_S_audio_param_s__struct),0);
	p->a0 = result;
	kal_mem_cpy(&(p->a1), param, sizeof(audio_param_struct));
	l4a_sendmsg_ilm(l4c_current_mod_id,MOD_MMI,MSG_ID_MMI_EQ_GET_AUDIO_PARAM_RSP,p);
}

/*
* FUNCTION
*	l4c_phb_exe_read_ln_entry_lrsp
* DESCRIPTION
*	send the phonebook read last number entry response message to MMI
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_phb_exe_read_ln_entry_lrsp (l4c_result_struct result,
                                    kal_uint8 no_list,
                                    kal_uint8 type,
                                    kal_uint8 more_data,
                                    l4c_phb_ln_entry_struct *list)
{
	struct ilm_struct *ilm_ptr=NULL;

	mmi_phb_get_last_number_rsp_struct *p
		= (mmi_phb_get_last_number_rsp_struct*) construct_local_para(
				(kal_uint16)(
				sizeof(mmi_phb_get_last_number_rsp_struct)
				+no_list*sizeof(l4c_phb_ln_entry_struct)
				),0);

	p->result = result;
	p->no_list = no_list;
	p->type = type;
	p->more_data = more_data;

	if(list) memcpy(
		p->list,
		list,
		no_list*sizeof(l4c_phb_ln_entry_struct));

	/* First allocate a memory for an interlayer message structure */
	ilm_ptr = allocate_ilm(l4c_current_mod_id);

	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_PHB_GET_LAST_NUMBER_RSP;/* Set the message id */
	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;

	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
}

/*
* FUNCTION
*	l4c_phb_exe_write_ln_entry_lrsp
* DESCRIPTION
*	send the phonebook write last number entry response message to MMI
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_phb_exe_write_ln_entry_lrsp (l4c_result_struct result,
                                    kal_uint16 no_list
                                    /*l4c_phb_ln_entry_struct *list*/,kal_uint8 type) 
{
	struct ilm_struct *ilm_ptr=NULL;

	mmi_phb_set_last_number_rsp_struct *p
		= (mmi_phb_set_last_number_rsp_struct*) construct_local_para(
				(kal_uint16)(
				sizeof(mmi_phb_set_last_number_rsp_struct)
				//+no_list*sizeof(l4c_phb_ln_entry_struct)
				),0);

	p->result = result;
	p->no_list = no_list;
	p->type = type;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	/* First allocate a memory for an interlayer message structure */
	ilm_ptr = allocate_ilm(l4c_current_mod_id);

	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_PHB_SET_LAST_NUMBER_RSP;/* Set the message id */
	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;

	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
}

/*
* FUNCTION
*	l4c_phb_exe_delete_ln_entry_lrsp
* DESCRIPTION
*	send the phonebook delete last number entry response message to MMI
* CALLS
* 	l4a_sendmsg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_phb_exe_delete_ln_entry_lrsp (l4c_result_struct result,
                                    kal_uint16 no_list
                                    /*l4c_phb_ln_entry_struct *list*/)
{
	struct ilm_struct *ilm_ptr=NULL;

	mmi_phb_del_last_number_rsp_struct *p
		= (mmi_phb_del_last_number_rsp_struct*) construct_local_para(
				(kal_uint16)(
				sizeof(mmi_phb_del_last_number_rsp_struct)
				//+no_list*sizeof(l4c_phb_ln_entry_struct)
				),0);

	p->result = result;
	p->no_list = no_list;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	/* First allocate a memory for an interlayer message structure */
	ilm_ptr = allocate_ilm(l4c_current_mod_id);

	ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_PHB_DEL_LAST_NUMBER_RSP;/* Set the message id */
	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;

	SEND_ILM(l4c_current_mod_id,MOD_MMI,MMI_L4C_SAP,ilm_ptr);
}
//mtk00758 - customer needs to turn BT/IRDA on/off by themself
//provide empty function for L4C link if not define __IRDA_SUPPORT__, __BT_SUPPORT__, __BTVCSR_HP__
/* IrDA */
#ifndef __IRDA_SUPPORT__
void l4c_eq_ircomm_connect_lind()
			{}
void l4c_eq_ircomm_disconnect_lind()
			{}
#endif /* (__IRDA_SUPPORT__) */
/* Bluetooth */
#ifndef __BT_SUPPORT__
void l4c_bt_fcty_set_param_lind(kal_uint8*  name,kal_uint8*  bd_addr,kal_uint8  dcs)
			{}
void l4c_bt_loopback_test_req_lind(kal_uint8*  bd_addr,kal_uint8*  pin_code) 
			{}
void l4c_bt_set_vr_req_ind(kal_bool  on_off) 
			{}			
#endif /*(__BT_SUPPORT__) */
/* Bluetooth */
/*******************************************************************************/
/* dummy functions    */
/*******************************************************************************/
void l4c_sms_new_msg_pdu_lind(kal_uint8 mti, kal_uint16 length, kal_uint8 id, void *data){}
/*MTK:BEGIN:generate_callback_function*/
/* Call Control Related Messages */
#if defined(__MOD_CSM__)
void l4c_cc_exe_reset_acm_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_RESET_ACM_RSP ,result,cause);}
void l4c_cc_set_acm_max_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_SET_MAX_ACM_RSP ,result,cause);}
void l4c_cc_exe_chld_lrsp(kal_bool  result,kal_uint16  cause,kal_uint8  opcode) 
			{_send_S_k_bool_S_k_16_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_CHLD_RSP ,result,cause,opcode);}
void l4c_cc_exe_hangup_active_call_lrsp() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_HANGUP_RSP, NULL);}
void l4c_cc_exe_ath_lrsp() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_ATH_RSP, NULL);}
void l4c_cc_exe_call_deflect_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_CALL_DEFLECT_RSP ,result,cause);}
void l4c_cc_auto_dtmf_start_lind(kal_uint8  call_id,kal_uint8*  digits) 
			{_send_S_k_8_A80A_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_START_AUTO_DTMF_IND ,call_id,digits);}
void l4c_cc_auto_dtmf_compl_lind(kal_uint8  call_id) 
			{_send_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_START_AUTO_DTMF_FINISH_IND ,call_id);}
void l4c_cc_exe_ata_lrsp(l4c_result_struct  result,kal_uint8  call_mode) 
			{_send_S_l_result_s_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_ATA_RSP ,result,call_mode);}
void l4c_cc_call_setup_req_ind(l4c_number_struct  dest,kal_uint8  call_type,kal_uint8  clir_flag,kal_bool  cug_option) 
			{_send_S_l_number_s_S_k_8_S_k_8_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_DIAL_REQ_IND ,dest,call_type,clir_flag,cug_option);}
void l4c_cc_exe_call_setup_lrsp(l4c_result_struct  result,kal_uint8  call_id) 
			{_send_S_l_result_s_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_DIAL_IND ,result,call_id);}
void l4c_cc_exe_call_modify_lrsp(l4c_result_struct  result,kal_uint8  call_mode) 
			{_send_S_l_result_s_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_CALL_MODIFY_RSP ,result,call_mode);}
void l4c_cc_call_meter_lind(kal_uint8  call_id,kal_uint32  ccm,kal_uint8  warning) 
			{_send_S_k_8_S_k_32_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_CCM_IND ,call_id,ccm,warning);}
void l4c_cc_call_alert_lind(kal_uint8  alert) 
			{_send_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_INTERNAL_ALERT_IND ,alert);}
void l4c_cc_call_wait_lind(kal_uint8  call_id,l4c_number_struct*  num,kal_uint8  call_mode,kal_uint8  name_present,kal_uint8  cnap_info_exist,kal_uint8  tag,kal_uint8*  name,kal_uint8  dcs,kal_uint8  length,kal_uint8  signal) 
			{_send_S_k_8_PS_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_A30A_k_8_S_k_8_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_CALL_WAIT_IND ,call_id,num,call_mode,name_present,cnap_info_exist,tag,name,dcs,length,signal);}
void l4c_cc_call_ring_lind(kal_uint8  call_id,l4c_number_struct*  num,l4c_sub_addr_struct*  sub_addr,l4c_number_struct*  redirect_num,kal_uint8  name_present,kal_uint8  cnap_info_exist,kal_uint8  tag,kal_uint8*  name,kal_uint8  dcs,kal_uint8  length,kal_uint8  auto_answer,kal_uint8  call_type) 
			{_send_S_k_8_PS_l_number_s_PS_l_sub_addr_s_PS_l_number_s_S_k_8_S_k_8_S_k_8_A30A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_CALL_RING_IND ,call_id,num,sub_addr,redirect_num,name_present,cnap_info_exist,tag,name,dcs,length,auto_answer,call_type);}
void l4c_cc_call_connect_lind(l4c_number_struct*  num,l4c_sub_addr_struct*  sub_addr,kal_uint8  call_type,kal_uint8  call_id) 
			{_send_PS_l_number_s_PS_l_sub_addr_s_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_CALL_CONNECT_IND ,num,sub_addr,call_type,call_id);}
void l4c_cc_call_disc_lind(kal_uint8  call_id,kal_bool  ccbs) 
			{_send_S_k_8_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_CALL_DISCONNECT_IND ,call_id,ccbs);}
void l4c_cc_call_release_lind(kal_uint8  call_id,kal_uint16  cause) 
			{_send_S_k_8_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_CALL_RELEASE_IND ,call_id,cause);}
void l4c_cc_speech_lind(kal_bool  on_off,kal_uint8  rat) 
			{_send_S_k_bool_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_SPEECH_IND ,on_off,rat);}
void l4c_cc_name_lind() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_NAME_IND, NULL);}
void l4c_cc_notify_ss_lind(kal_uint8  call_id,kal_uint8  type,kal_bool  status_present,kal_uint8  status,kal_bool  notification_present,kal_uint8  notification) 
			{_send_S_k_8_S_k_8_S_k_bool_S_k_8_S_k_bool_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_NOTIFY_SS_IND ,call_id,type,status_present,status,notification_present,notification);}
void l4c_cc_notify_ss_cug_lind(kal_uint8  call_id,kal_uint16  index) 
			{_send_S_k_8_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_NOTIFY_SS_CUG_IND ,call_id,index);}
void l4c_cc_notify_ss_ect_lind(kal_uint8  call_id,kal_bool  present,l4c_number_struct*  addr,l4c_sub_addr_struct*  sub_addr) 
			{_send_S_k_8_S_k_bool_PS_l_number_s_PS_l_sub_addr_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_NOTIFY_SS_ECT_IND ,call_id,present,addr,sub_addr);}
void l4c_cc_notify_ss_cnap_lind(kal_uint8  call_id,kal_uint8  name_present,kal_uint8  cnap_info_exist,kal_uint8  tag,kal_uint8*  name,kal_uint8  dcs,kal_uint8  length) 
			{_send_S_k_8_S_k_8_S_k_8_S_k_8_A30A_k_8_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_NOTIFY_SS_CNAP_IND ,call_id,name_present,cnap_info_exist,tag,name,dcs,length);}
void l4c_cc_notify_ss_ccbs_lind(kal_uint8  call_id,kal_bool  number_present,l4c_number_struct*  addr,kal_bool  sub_addr_present,l4c_sub_addr_struct*  sub_addr,kal_bool  index_present,kal_uint8  index,kal_bool  bs_code_present,kal_uint8  bs_code,kal_bool  alert_present,kal_uint8  alert_pattern) 
			{_send_S_k_8_S_k_bool_PS_l_number_s_S_k_bool_PS_l_sub_addr_s_S_k_bool_S_k_8_S_k_bool_S_k_8_S_k_bool_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_NOTIFY_SS_CCBS_IND ,call_id,number_present,addr,sub_addr_present,sub_addr,index_present,index,bs_code_present,bs_code,alert_present,alert_pattern);}
void l4c_cc_call_accept_req_ind(kal_uint8  call_id) 
			{_send_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_CALL_ACCEPT_REQ_IND ,call_id);}
void l4c_cc_call_abort_req_ind() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_CALL_ABORT_REQ_IND, NULL);}
void l4c_cc_call_sync_req_ind() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_CALL_SYNC_REQ_IND, NULL);}
void l4c_cc_video_call_status_ind(kal_uint8  call_id,kal_uint8  action,kal_bool  result,kal_uint8  cause) 
			{_send_S_k_8_S_k_8_S_k_bool_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_VIDEO_CALL_STATUS_IND ,call_id,action,result,cause);}
#endif /* defined(__MOD_CSM__) */
void l4a_cc_set_csd_profile_lrsp(kal_uint8  src_id,kal_bool  result,kal_uint16  cause) 
			{_send_S_k_8_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CC_SET_CSD_PROFILE_RSP ,src_id,result,cause);}
void l4c_ss_exe_emlpp_lrsp(l4c_result_struct  result,kal_uint8  para_present,kal_uint8  opcode,kal_uint8  default_pri,kal_uint8  max_pri) 
			{_send_S_l_result_s_S_k_8_S_k_8_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SS_EMLPP_RSP ,result,para_present,opcode,default_pri,max_pri);}
void l4c_ss_exe_call_forward_lrsp(l4c_result_struct  result,kal_uint8  para_present,kal_uint8  opcode,kal_uint8  type,kal_uint8  count,forwarding_list_struct*  list) 
			{_send_S_l_result_s_S_k_8_S_k_8_S_k_8_S_k_8_A13A_forwarding_list_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SS_CALL_FORWARD_RSP ,result,para_present,opcode,type,count,list);}
void l4c_ss_exe_call_wait_lrsp(l4c_result_struct  result,kal_uint8  para_present,kal_uint8  opcode,kal_uint8  count,kal_uint8  status,kal_uint8*  list) 
			{_send_S_l_result_s_S_k_8_S_k_8_S_k_8_S_k_8_A13A_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SS_CALL_WAIT_RSP ,result,para_present,opcode,count,status,list);}
void l4c_ss_exe_cdip_interrogate_lrsp(l4c_result_struct  result,kal_uint8  para_present,kal_uint8  status) 
			{_send_S_l_result_s_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SS_CDIP_INTERROGATE_IND ,result,para_present,status);}
void l4c_ss_exe_clip_interrogate_lrsp(l4c_result_struct  result,kal_uint8  para_present,kal_uint8  status,kal_uint8  clir_option) 
			{_send_S_l_result_s_S_k_8_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SS_CLIP_INTERROGATE_IND ,result,para_present,status,clir_option);}
void l4c_ss_exe_clir_interrogate_lrsp(l4c_result_struct  result,kal_uint8  para_present,kal_uint8  status,kal_uint8  clir_option) 
			{_send_S_l_result_s_S_k_8_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SS_CLIR_INTERROGATE_IND ,result,para_present,status,clir_option);}
void l4c_ss_exe_cnap_interrogate_lrsp(l4c_result_struct  result,kal_uint8  para_present,kal_uint8  status,kal_uint8  clir_option) 
			{_send_S_l_result_s_S_k_8_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SS_CNAP_INTERROGATE_IND ,result,para_present,status,clir_option);}
void l4c_ss_exe_colp_interrogate_lrsp(l4c_result_struct  result,kal_uint8  para_present,kal_uint8  status,kal_uint8  clir_option) 
			{_send_S_l_result_s_S_k_8_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SS_COLP_INTERROGATE_IND ,result,para_present,status,clir_option);}
void l4c_ss_exe_colr_interrogate_lrsp(l4c_result_struct  result,kal_uint8  para_present,kal_uint8  status,kal_uint8  clir_option) 
			{_send_S_l_result_s_S_k_8_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SS_COLR_INTERROGATE_IND ,result,para_present,status,clir_option);}
void l4c_ss_exe_call_barring_lrsp(l4c_result_struct  result,kal_uint8  para_present,kal_uint8  opcode,kal_uint8  type,kal_uint8  count,barring_list_struct*  list) 
			{_send_S_l_result_s_S_k_8_S_k_8_S_k_8_S_k_8_A13A_barring_list_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SS_CALL_BARRING_RSP ,result,para_present,opcode,type,count,list);}
void l4c_ss_exe_ussd_lrsp(l4c_result_struct  result,kal_uint8  para_present,kal_uint8  op_code,kal_uint8  dcs,kal_uint8*  ussd_str,kal_uint8  length) 
			{_send_S_l_result_s_S_k_8_S_k_8_S_k_8_A183A_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SS_USSD_RSP ,result,para_present,op_code,dcs,ussd_str,length);}
void l4c_ss_ussr_lind(kal_uint8  dcs,kal_uint8*  ussd_string,kal_uint8  length) 
			{_send_S_k_8_A183A_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SS_USSR_IND ,dcs,ussd_string,length);}
void l4c_ss_ussn_lind(kal_uint8  dcs,kal_uint8*  ussd_string,kal_uint8  length) 
			{_send_S_k_8_A183A_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SS_USSN_IND ,dcs,ussd_string,length);}
void l4c_ss_exe_change_password_lrsp(l4c_result_struct  result) 
			{_send_S_l_result_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SS_CHANGE_PASSWORD_RSP ,result);}
void l4c_ss_string_parsing_lrsp(l4c_result_struct  result,l4c_ss_string_info_struct*  info) 
			{_send_S_l_result_s_PS_l_ss_string_info_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SS_PARSING_STRING_RSP ,result,info);}
void l4c_ss_cb_passwd_lind(kal_uint8  pwd_no) 
			{_send_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SS_CB_PASSWORD_IND ,pwd_no);}
void l4c_sms_cb_gs_change_lind(kal_uint8  geography_type) 
			{_send_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_CB_GS_CHANGE_IND ,geography_type);}
void l4c_ss_exe_ccbs_lrsp(l4c_result_struct  result,kal_uint8  para_present,kal_uint8  opcode,kal_uint8  ccbs_count,ccbs_list_struct*  list) 
			{_send_S_l_result_s_S_k_8_S_k_8_S_k_8_PS_ccbs_list_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SS_CCBS_RSP ,result,para_present,opcode,ccbs_count,list);}
/* Hardware - Audio Related Service Messages */
#if defined(__MOD_UEM__)
void l4c_eq_set_volume_req_ind(kal_uint8  volume_type,kal_uint8  volume_level) 
			{_send_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_EXE_VOLUME_REQ_IND ,volume_type,volume_level);}
void l4a_eq_volume_change_ind(kal_uint8  volume_type,kal_uint8  volume_level) 
			{_send_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_VOLUME_CHANGE_IND ,volume_type,volume_level);}
void l4c_eq_set_mute_mode_req_ind(kal_uint8  audio_device,kal_bool  mute_onoff) 
			{_send_S_k_8_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_EXE_MUTE_REQ_IND ,audio_device,mute_onoff);}
void l4a_eq_mute_change_ind(kal_uint8  audio_device,kal_bool  mute_onoff) 
			{_send_S_k_8_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_MUTE_CHANGE_IND ,audio_device,mute_onoff);}
void l4c_eq_set_silent_mode_req_ind(kal_bool  mode) 
			{_send_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_SET_SILENT_MODE_REQ_IND ,mode);}
void l4a_eq_set_gpio_level_req_ind(kal_uint8  gpio_dev_type,kal_uint8  gpio_dev_level) 
			{_send_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_SET_GPIO_LEVEL_REQ_IND ,gpio_dev_type,gpio_dev_level);}
void l4c_eq_set_gpio_level_req_ind(kal_uint8  gpio_dev_type,kal_uint8  gpio_dev_level) 
			{_send_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_EXE_GPIO_LEVEL_REQ_IND ,gpio_dev_type,gpio_dev_level);}
void l4c_eq_audio_play_finish_lind(kal_uint8  result,kal_uint16  identifier) 
			{_send_S_k_8_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_PLAY_AUDIO_FINISH_IND ,result,identifier);}
void l4c_eq_audio_play_by_string_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_PLAY_AUDIO_STREAM_RSP ,result,cause);}
void l4c_eq_audio_stop_by_string_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_STOP_AUDIO_STREAM_RSP ,result,cause);}
void l4c_eq_gpio_detect_lind(kal_uint8  gpio_device,kal_bool  on_off) 
			{_send_S_k_8_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_GPIO_DETECT_IND ,gpio_device,on_off);}
void l4c_eq_gpio_detect_res_lrsp(kal_bool  result) 
			{_send_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_GPIO_DETECT_RES_RSP ,result);}
void l4c_eq_audio_play_by_name_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_PLAY_AUDIO_BY_NAME_RSP ,result,cause);}
void l4c_eq_audio_stop_by_name_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_STOP_AUDIO_BY_NAME_RSP ,result,cause);}
void l4c_eq_set_audio_profile_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_SET_AUDIO_PROFILE_RSP ,result,cause);}
void l4c_eq_get_audio_profile_lrsp(kal_bool  result,audio_profile_struct  audio_prof_out) 
			{_send_S_k_bool_S_audio_profile_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_GET_AUDIO_PROFILE_RSP ,result,audio_prof_out);}
void l4c_eq_set_audio_param_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_SET_AUDIO_PARAM_RSP ,result,cause);}
void l4a_eq_get_audio_param_lrsp(kal_bool  result,audio_param_struct*  audio_para) 
			{_send_S_k_bool_PS_audio_param_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_GET_AUDIO_PARAM_RSP ,result,audio_para);}
void l4c_get_adc_all_channel_lind(kal_int32  vbat,kal_int32  bat_temp,kal_int32  vaux,kal_int32  charge_current,kal_int32  vcharge) 
			{_send_S_k_int32_S_k_int32_S_k_int32_S_k_int32_S_k_int32_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_ADC_ALL_CHANNEL_IND ,vbat,bat_temp,vaux,charge_current,vcharge);}
void l4c_eq_set_hw_level_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_SET_HW_LEVEL_RSP ,result,cause);}
void l4c_em_lcm_sleep_mode_req_lind(kal_bool  on_off) 
			{_send_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_SET_SLEEP_MODE_REQ_IND ,on_off);}
#endif /* defined(__MOD_UEM__) */
/* Hardware - RTC, Clock, Alarm Related Messages */
#if defined(__MOD_UEM__)
void l4c_eq_set_rtc_time_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_SET_RTC_TIME_RSP ,result,cause);}
void l4c_eq_set_rtc_time_req_ind(kal_uint8  rtc_type,kal_uint8  set_type,rtc_alarm_info_struct  alarm) 
			{_send_S_k_8_S_k_8_S_rtc_alarm_info_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_SET_RTC_TIME_REQ_IND ,rtc_type,set_type,alarm);}
void l4c_eq_rtc_delete_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_DEL_RTC_TIMER_RSP ,result,cause);}
void l4a_eq_exe_rtc_delete_req_ind(kal_uint8  rtc_type,kal_uint8  rtc_index) 
			{_send_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_DEL_RTC_TIMER_REQ_IND ,rtc_type,rtc_index);}
void l4c_eq_exe_rtc_delete_req_ind(kal_uint8  rtc_type,kal_uint8  rtc_index) 
			{_send_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_EXE_DEL_RTC_TIMER_REQ_IND ,rtc_type,rtc_index);}
void l4c_eq_set_date_time_format_req_ind(kal_bool  is_date_set,kal_uint8  mode) 
			{_send_S_k_bool_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_SET_DATE_TIME_FORMAT_REQ_IND ,is_date_set,mode);}
void l4c_eq_rtc_period_lind(kal_uint8  rtc_type,rtc_format_struct*  rtc_time) 
			{_send_S_k_8_PS_rtc_format_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_CLOCK_TICK_IND ,rtc_type,rtc_time);}
void l4c_eq_alarm_detect_lind(rtc_format_struct*  rtc_time) 
			{_send_PS_rtc_format_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_ALARM_IND ,rtc_time);}
void l4c_eq_at_alarm_query_req_lind() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_AT_ALARM_QUERY_REQ_IND, NULL);}
void l4c_eq_at_alarm_set_req_lind(mmi_at_alarm_info_struct  alarm) 
			{_send_S_mmi_at_alarm_info_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_AT_ALARM_SET_REQ_IND ,alarm);}
void l4c_eq_at_alarm_delete_req_lind(kal_uint8  alarm_index) 
			{_send_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_AT_ALARM_DELETE_REQ_IND ,alarm_index);}
#endif /* defined(__MOD_UEM__) */
/* Hardware - Keypad, Indicator, LCD Related Messages */
#if defined(__MOD_UEM__)
void l4c_eq_set_keypad_input_req_ind(kal_uint8  keypad_status,kal_uint8  keycode) 
			{_send_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_SIMULATE_KEY_PRESS_REQ_IND ,keypad_status,keycode);}
void l4c_eq_set_indicator_req_ind(kal_uint8  icon_id,kal_uint8  value) 
			{_send_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_SET_INDICATOR_REQ_IND ,icon_id,value);}
void l4c_eq_set_dspl_text_req_ind(kal_uint8*  text_string) 
			{_send_A30A_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_DISPLAY_TEXT_REQ_IND ,text_string);}
void l4a_eq_keypad_detect_lind(drv_get_key_func  func) 
			{_send_S_drv_get_key_func_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_KEYPAD_DETECT_IND ,func);}
#endif /* defined(__MOD_UEM__) */
/* Hardware - Misc Messages */
#if defined(__MOD_UEM__)
void l4c_eq_set_language_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_SET_LANGUAGE_RSP ,result,cause);}
void l4c_eq_set_language_req_ind(kal_uint8  lang_code) 
			{_send_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_SET_LANGUAGE_REQ_IND ,lang_code);}
void l4c_eq_set_greeting_text_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_SET_GREETING_TEXT_RSP ,result,cause);}
void l4c_eq_set_greeting_text_req_ind(kal_bool  mode,kal_uint8  dcs,kal_uint8*  text,kal_uint8  length) 
			{_send_S_k_bool_S_k_8_A62A_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_SET_GREETING_TEXT_REQ_IND ,mode,dcs,text,length);}
void l4c_eq_set_vibrator_mode_req_ind(kal_bool  mode) 
			{_send_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_SET_VIBRATOR_MODE_REQ_IND ,mode);}
void l4c_eq_set_vibrator_mode_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_SET_VIBRATOR_MODE_RSP ,result,cause);}
void l4c_eq_set_country_code_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_SET_COUNTRY_CODE_RSP ,result,cause);}
void l4a_eq_power_on_lind(kal_uint8  poweron_mode,kal_uint8  battery_level,kal_uint8  build_label,rtc_format_struct*  rtc_time,kal_uint8  flightmode_state,kal_uint8  dual_sim_mode_setting,kal_uint8  dual_sim_uart_setting) 
			{_send_S_k_8_S_k_8_S_k_8_PS_rtc_format_s_S_k_8_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_POWER_ON_IND ,poweron_mode,battery_level,build_label,rtc_time,flightmode_state,dual_sim_mode_setting,dual_sim_uart_setting);}
void l4c_eq_battery_status_lind(kal_uint8  battery_status,kal_uint8  battery_voltage) 
			{_send_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_BATTERY_STATUS_IND ,battery_status,battery_voltage);}
void l4c_eq_leave_precharge_lind() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_LEAVE_PRECHARGE_IND, NULL);}
void l4c_eq_pmic_config_lrsp(kal_uint8  request_type,pmic_config_param_struct  request) 
			{_send_S_k_8_S_pmic_config_param_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_PMIC_CONFIG_RSP ,request_type,request);}
void l4c_eq_rf_test_gsm_lrsp(kal_uint8  request_type,rf_test_gsm_param_struct  request) 
			{_send_S_k_8_S_rf_test_gsm_param_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_RF_TEST_GSM_RSP ,request_type,request);}
void l4c_eq_fm_radio_config_lrsp(kal_uint8  request_type,fm_radio_config_param_struct  request) 
			{_send_S_k_8_S_fm_radio_config_param_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_FM_RADIO_CONFIG_RSP ,request_type,request);}
void l4c_eq_rf_test_wifi_lrsp(kal_uint8  request_type,rf_test_wifi_param_struct  request) 
			{_send_S_k_8_S_rf_test_wifi_param_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_RF_TEST_WIFI_RSP ,request_type,request);}
#endif /* defined(__MOD_UEM__) */
/* Hardware - NVRAM messages */
#if defined(__MOD_NVRAM__)
void l4a_eq_read_nvram_lrsp(l4c_result_struct  result,kal_uint8  file_idx,kal_uint16  length,kal_uint8*  data) 
			{_send_S_l_result_s_S_k_8_S_k_16_A1A_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_NVRAM_READ_RSP ,result,file_idx,length,data);}
void l4c_eq_write_nvram_lrsp(l4c_result_struct  result,kal_uint8  file_idx,kal_uint16  para) 
			{_send_S_l_result_s_S_k_8_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_NVRAM_WRITE_RSP ,result,file_idx,para);}
void l4c_eq_reset_nvram_lrsp(l4c_result_struct  result) 
			{_send_S_l_result_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_NVRAM_RESET_RSP ,result);}
void l4c_eq_get_uart_port_lrsp(kal_bool  result,kal_uint8  ps_uart_port,kal_uint32  ps_baud_rate,kal_uint8  tst_uart_port_ps,kal_uint32  tst_baud_rate_ps,kal_uint8  cti_uart_port,kal_uint32  cti_baud_rate,kal_uint8  tst_uart_port_l1,kal_uint32  tst_baud_rate_l1) 
			{_send_S_k_bool_S_k_8_S_k_32_S_k_8_S_k_32_S_k_8_S_k_32_S_k_8_S_k_32_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_GET_UART_RSP ,result,ps_uart_port,ps_baud_rate,tst_uart_port_ps,tst_baud_rate_ps,cti_uart_port,cti_baud_rate,tst_uart_port_l1,tst_baud_rate_l1);}
void l4c_attach_uart_port_lrsp(kal_uint8  result) 
			{_send_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_ATTACH_UART_PORT_RSP ,result);}
void l4c_detach_uart_port_lrsp(kal_uint8  result) 
			{_send_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_DETACH_UART_PORT_RSP ,result);}
void l4c_nvm_ready_lind() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_NVRAM_READY_IND, NULL);}
void l4c_eq_dcm_enable_lrsp() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_DCM_ENABLE_RSP, NULL);}
#endif /* defined(__MOD_NVRAM__) */
/* Network Related Messages */
#if defined(__MOD_RAC__)
void l4c_nw_abort_plmn_list_lrsp(kal_bool  result) 
			{_send_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_NW_ABORT_PLMN_LIST_RSP ,result);}
void l4c_nw_exe_att_lrsp(kal_bool  result) 
			{_send_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_NW_SET_ATTACH_RSP ,result);}
void l4c_nw_set_class_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_NW_SET_MOBILE_CLASS_RSP ,result,cause);}
void l4c_nw_exe_cops_lrsp(l4c_result_struct  result,kal_uint8  status,kal_uint8*  plmn,kal_uint8  rat) 
			{_send_S_l_result_s_S_k_8_Av0A_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_NW_SET_PLMN_RSP ,result,status,plmn,rat);}
void l4c_nw_get_plmn_list_lrsp(l4c_result_struct  result,kal_uint8  length,l4c_rat_plmn_info_struct*  list) 
			{_send_S_l_result_s_S_k_8_A16A_l_rat_plmn_info_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_NW_GET_PLMN_LIST_RSP ,result,length,list);}
void l4c_nw_attach_lind(kal_uint8  status,kal_uint8*  plmn,kal_uint8  gsm_state,kal_uint8  gprs_state,l4c_gprs_status_enum  gprs_status,kal_uint8  rat,kal_uint8  cell_support_egprs,kal_uint8*  lac) 
			{_send_S_k_8_Av0A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_A2A_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_NW_ATTACH_IND ,status,plmn,gsm_state,gprs_state,gprs_status,rat,cell_support_egprs,lac);}
void l4c_nw_reg_state_lind(kal_uint8*  lac,kal_uint16  cell_id,kal_uint8  status,kal_uint8  gprs_state,l4c_gprs_status_enum  gprs_status) 
			{_send_PS_k_8_S_k_16_S_k_8_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_NW_REG_STATE_IND ,lac,cell_id,status,gprs_state,gprs_status);}
void l4c_nw_rx_level_lind(kal_uint8  level,kal_uint8  current_band,kal_uint8  rat) 
			{_send_S_k_8_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_NW_RX_LEVEL_IND ,level,current_band,rat);}
void l4c_nw_time_zone_lind(kal_uint8  full_nw_nameP,kal_uint8  full_nw_name_dcs,kal_bool  full_nw_name_add_ci,kal_uint8  full_nw_name_len,kal_uint8*  full_nw_name,kal_uint8  short_nw_nameP,kal_uint8  short_nw_name_dcs,kal_bool  short_nw_name_add_ci,kal_uint8  short_nw_name_len,kal_uint8*  short_nw_name,kal_uint8  nw_time_zoneP,kal_uint8  nw_time_zone,kal_uint8  nw_time_zone_timeP,l4c_nw_time_zone_time_struct  nw_time_zone_time,kal_uint8  lsa_idP,kal_uint8  lsa_id_len,kal_uint8*  lsa_id,kal_uint8  nw_day_light_saving_timeP,kal_uint8  nw_day_light_saving_time) 
			{_send_S_k_8_S_k_8_S_k_bool_S_k_8_A24A_k_8_S_k_8_S_k_8_S_k_bool_S_k_8_A24A_k_8_S_k_8_S_k_8_S_k_8_S_l_nw_time_zone_time_s_S_k_8_S_k_8_A3A_k_8_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_NW_TIME_ZONE_IND ,full_nw_nameP,full_nw_name_dcs,full_nw_name_add_ci,full_nw_name_len,full_nw_name,short_nw_nameP,short_nw_name_dcs,short_nw_name_add_ci,short_nw_name_len,short_nw_name,nw_time_zoneP,nw_time_zone,nw_time_zone_timeP,nw_time_zone_time,lsa_idP,lsa_id_len,lsa_id,nw_day_light_saving_timeP,nw_day_light_saving_time);}
void l4c_nw_sel_mode_lind(kal_uint8  network_mode) 
			{_send_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_NW_SEL_MODE_IND ,network_mode);}
void l4c_nw_mmrr_service_status_lind(kal_uint8  service_status) 
			{_send_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_NW_MMRR_SERVICE_STATUS_IND ,service_status);}
void l4c_nw_set_preferred_band_lrsp(kal_bool  result,kal_uint8  status) 
			{_send_S_k_bool_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_NW_SET_PREFERRED_BAND_RSP ,result,status);}
void l4c_nw_powroff_detach_lrsp(l4c_result_struct  result) 
			{_send_S_l_result_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_NW_PWROFF_DETACH_RSP ,result);}
void l4c_nw_cfun_state_lrsp(kal_bool  result) 
			{_send_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_NW_CFUN_STATE_RSP ,result);}
void l4c_nw_set_rat_mode_lrsp(kal_bool  result) 
			{_send_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_NW_SET_RAT_MODE_RSP ,result);}
void l4c_nw_set_prefer_rat_lrsp(kal_bool  result) 
			{_send_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_NW_SET_PREFER_RAT_RSP ,result);}
#endif /* defined(__MOD_RAC__) */
/* Security Related Messages */
#if defined(__MOD_SMU__)
void l4c_smu_exe_lock_lrsp(kal_bool  result,kal_uint16  cause,sim_chv_info_struct  chv_info) 
			{_send_S_k_bool_S_k_16_S_sim_chv_info_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMU_LOCK_RSP ,result,cause,chv_info);}
void l4c_smu_exe_master_reset_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMU_RESET_DATA_RSP ,result,cause);}
void l4c_smu_exe_verify_pin_lrsp(kal_bool  result,kal_uint8  next_type,sim_chv_info_struct  chv_info) 
			{_send_S_k_bool_S_k_8_S_sim_chv_info_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMU_VERIFY_PIN_RSP ,result,next_type,chv_info);}
void l4c_smu_set_preferred_oper_list_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMU_SET_PREFERRED_OPER_LIST_RSP ,result,cause);}
void l4c_smu_set_puc_params_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMU_SET_PUC_RSP ,result,cause);}
void l4c_smu_exe_change_password_lrsp(kal_bool  result,kal_uint16  cause,sim_chv_info_struct  chv_info) 
			{_send_S_k_bool_S_k_16_S_sim_chv_info_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMU_CHANGE_PASSWORD_RSP ,result,cause,chv_info);}
void l4c_smu_exe_restricted_access_lrsp(l4c_result_struct  result,kal_uint8  sw1,kal_uint8  sw2,kal_uint16  length,kal_uint8*  resp) 
			{_send_S_l_result_s_S_k_8_S_k_8_S_k_16_A256A_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMU_RESTRICTED_ACCESS_RSP ,result,sw1,sw2,length,resp);}
void l4c_smu_exe_dial_mode_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMU_SET_DIAL_MODE_RSP ,result,cause);}
void l4c_smu_write_sim_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMU_WRITE_SIM_RSP ,result,cause);}
void l4c_smu_read_sim_lrsp(l4c_result_struct  result,kal_uint16  length,kal_uint8*  data) 
			{_send_S_l_result_s_S_k_16_A260A_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMU_READ_SIM_RSP ,result,length,data);}
void l4c_sim_passwd_required_lind(kal_uint8  type,kal_bool  is_sim_change,sim_chv_info_struct  chv_info,kal_uint8  cphs_retry_count) 
			{_send_S_k_8_S_k_bool_S_sim_chv_info_s_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMU_PASSWORD_REQUIRED_IND ,type,is_sim_change,chv_info,cphs_retry_count);}
void l4c_sim_support_plmn_list_lind(kal_uint16  length) 
			{_send_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMU_SUPPORT_PLMN_LIST_IND ,length);}
void l4c_sim_fail_lind(kal_uint16  cause) 
			{_send_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMU_FAIL_IND ,cause);}
void l4c_smu_read_file_info_lrsp(l4c_result_struct  result,kal_uint16  file_size,kal_uint8  num_of_rec) 
			{_send_S_l_result_s_S_k_16_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMU_READ_FILE_INFO_RSP ,result,file_size,num_of_rec);}
void l4c_sim_startup_info_lind(kal_uint8  num,kal_uint8*  ecc,kal_uint8*  language,kal_uint8  alpha_set) 
			{_send_S_k_8_A35A_k_8_A5A_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMU_STARTUP_INFO_IND ,num,ecc,language,alpha_set);}
void l4c_sim_cipher_lind(kal_bool  cipher_ind,kal_uint8  is_gsm_conn_exist,kal_uint8  gsm_cipher_cond,kal_uint8  gprs_cipher_cond) 
			{_send_S_k_bool_S_k_8_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMU_CIPHER_IND ,cipher_ind,is_gsm_conn_exist,gsm_cipher_cond,gprs_cipher_cond);}
void l4c_smu_set_personalization_lrsp(l4c_result_struct  result,kal_uint8  category,kal_uint8  op,kal_uint8  state,kal_uint8  retry_count,kal_uint8  num_of_sets,kal_uint8  space_of_sets) 
			{_send_S_l_result_s_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMU_SET_PERSONALIZATION_RSP ,result,category,op,state,retry_count,num_of_sets,space_of_sets);}
void l4c_smu_sml_status_lrsp(l4c_result_struct  result,kal_uint8*  state,kal_uint8*  retry_count,kal_uint8*  autolock_count,kal_uint8*  num_of_sets,kal_uint8*  total_size_of_cat,kal_uint8*  key_state,kal_uint8*  imsi,kal_uint8  is_valid_gid1,kal_uint8  ef_gid1,kal_uint8  is_valid_gid2,kal_uint8  ef_gid2,kal_uint8  digits_of_mnc) 
			{_send_S_l_result_s_A7A_k_8_A7A_k_8_A7A_k_8_A7A_k_8_A7A_k_8_A7A_k_8_A16A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMU_SML_STATUS_RSP ,result,state,retry_count,autolock_count,num_of_sets,total_size_of_cat,key_state,imsi,is_valid_gid1,ef_gid1,is_valid_gid2,ef_gid2,digits_of_mnc);}
void l4c_sim_verify_pin_result_lind(kal_uint8  next_type,sim_chv_info_struct  chv_info) 
			{_send_S_k_8_S_sim_chv_info_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMU_VERIFY_PIN_RESULT_IND ,next_type,chv_info);}
#endif /* defined(__MOD_SMU__) */
/* PhoneBook Related Messages */
#if defined(__MOD_PHB__)
void l4c_phb_get_entry_by_text_lrsp(l4c_result_struct  result,kal_uint16  no_list,l4c_phb_entry_struct*  list) 
			{_send_S_l_result_s_S_k_16_A15A_l_phb_entry_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PHB_GET_ENTRY_BY_NAME_RSP ,result,no_list,list);}
void l4c_phb_get_entry_by_index_lrsp(l4c_result_struct  result,kal_uint16  no_list,l4c_phb_entry_struct*  list) 
			{_send_S_l_result_s_S_k_16_A15A_l_phb_entry_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PHB_GET_ENTRY_BY_INDEX_RSP ,result,no_list,list);}
void l4c_phb_exe_write_entry_lrsp(l4c_result_struct  result,kal_uint16  no_list,l4c_phb_entry_struct*  list) 
			{_send_S_l_result_s_S_k_16_A15A_l_phb_entry_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PHB_SET_ENTRY_RSP ,result,no_list,list);}
void l4c_phb_exe_delete_entry_lrsp(l4c_result_struct  result,kal_uint16  no_list,l4c_phb_entry_struct*  list) 
			{_send_S_l_result_s_S_k_16_A15A_l_phb_entry_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PHB_DEL_ENTRY_RSP ,result,no_list,list);}
void l4a_phb_exe_read_ln_entry_lrsp(l4c_result_struct  result,kal_uint8  no_list,kal_uint8  type,kal_uint8  more_data,l4c_phb_ln_entry_struct*  list) 
			{_send_S_l_result_s_S_k_8_S_k_8_S_k_8_A1A_l_phb_ln_entry_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PHB_GET_LAST_NUMBER_RSP ,result,no_list,type,more_data,list);}
void l4a_phb_exe_write_ln_entry_lrsp(l4c_result_struct  result,kal_uint16  no_list,kal_uint8  type) 
			{_send_S_l_result_s_S_k_16_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PHB_SET_LAST_NUMBER_RSP ,result,no_list,type);}
void l4a_phb_exe_delete_ln_entry_lrsp(l4c_result_struct  result,kal_uint16  no_list) 
			{_send_S_l_result_s_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PHB_DEL_LAST_NUMBER_RSP ,result,no_list);}
void l4c_phb_ln_ready_lind() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PHB_LAST_NUMBER_READY_IND, NULL);}
void l4c_phb_startup_finish_lind(kal_uint16  sim_max_num,kal_uint16  phb_max_num,kal_uint8  phb_len,kal_uint8  fdn_len,kal_uint8  bdn_len,kal_uint8  owner_len) 
			{_send_S_k_16_S_k_16_S_k_8_S_k_8_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PHB_STARTUP_FINISH_IND ,sim_max_num,phb_max_num,phb_len,fdn_len,bdn_len,owner_len);}
void l4c_phb_mem_full_lind() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PHB_MEM_FULL_IND, NULL);}
void l4c_phb_update_lind(kal_uint8  action,kal_uint16  old_index,kal_uint16  sim_used,kal_uint16  nvram_used,kal_uint16  no_list,l4c_phb_entry_struct*  list) 
			{_send_S_k_8_S_k_16_S_k_16_S_k_16_S_k_16_A1A_l_phb_entry_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PHB_UPDATE_IND ,action,old_index,sim_used,nvram_used,no_list,list);}
void l4c_phb_startup_read_lind(l4c_phb_entries_struct*  phb_entries,kal_uint8  access_id) 
			{_send_A1A_l_phb_entries_s_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PHB_STARTUP_READ_IND ,phb_entries,access_id);}
void l4c_phb_startup_begin_lind() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PHB_STARTUP_BEGIN_IND, NULL);}
void l4c_phb_startup_phase1_lind(kal_uint16  sim_max_num,kal_uint16  phb_max_num,kal_uint8  phb_len,kal_uint8  fdn_len,kal_uint8  bdn_len,kal_uint8  owner_len,kal_bool  is_usim,kal_bool  is_group_support,kal_uint8  anra_support_type,kal_uint8  anrb_support_type,kal_uint8  anrc_support_type,kal_uint8  sne_support_type,kal_uint8  email_support_type,kal_uint8  group_len,kal_uint8  sne_len,kal_uint8  email_len,kal_uint16  anra_max_num,kal_uint16  anrb_max_num,kal_uint16  anrc_max_num,kal_uint16  sne_max_num,kal_uint16  email_max_num,kal_uint16  group_max_num) 
			{_send_S_k_16_S_k_16_S_k_8_S_k_8_S_k_8_S_k_8_S_k_bool_S_k_bool_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_16_S_k_16_S_k_16_S_k_16_S_k_16_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PHB_STARTUP_PHASE1_IND ,sim_max_num,phb_max_num,phb_len,fdn_len,bdn_len,owner_len,is_usim,is_group_support,anra_support_type,anrb_support_type,anrc_support_type,sne_support_type,email_support_type,group_len,sne_len,email_len,anra_max_num,anrb_max_num,anrc_max_num,sne_max_num,email_max_num,group_max_num);}
void l4c_phb_startup_read_anr_lind(kal_uint8  num_of_entry,l4c_phb_bcd_anr_struct*  anr_entry,kal_uint8  access_id) 
			{_send_S_k_8_Av3A_l_phb_bcd_anr_s_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PHB_STARTUP_READ_ANR_IND ,num_of_entry,anr_entry,access_id);}
void l4c_phb_startup_read_email_lind(kal_uint8  num_of_entry,l4c_phb_email_struct*  email_entry,kal_uint8  access_id) 
			{_send_S_k_8_Av4A_l_phb_email_s_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PHB_STARTUP_READ_EMAIL_IND ,num_of_entry,email_entry,access_id);}
void l4c_phb_read_email_lrsp(l4c_result_struct  result,kal_uint16  no_list,l4c_phb_email_struct*  list) 
			{_send_S_l_result_s_S_k_16_S_l_phb_email_s_p_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PHB_READ_EMAIL_RSP ,result,no_list,list);}
void l4c_phb_startup_read_gas_lind(kal_uint8  num_of_entry,l4c_phb_entry_struct*  gas_entry,kal_uint8  access_id) 
			{_send_S_k_8_A5A_l_phb_entry_s_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PHB_STARTUP_READ_GAS_IND ,num_of_entry,gas_entry,access_id);}
void l4c_phb_startup_read_grp_lind(kal_uint8*  grp,kal_uint8  access_id) 
			{_send_A1000A_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PHB_STARTUP_READ_GRP_IND ,grp,access_id);}
void l4c_phb_set_grp_lrsp(l4c_result_struct  result,kal_uint16  record_index,kal_uint8  group_type) 
			{_send_S_l_result_s_S_k_16_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PHB_SET_GRP_RSP ,result,record_index,group_type);}
void l4c_phb_write_usim_lrsp(l4c_result_struct  result,kal_uint8  no_data,l4c_phb_entry_struct*  list,kal_uint8  update_field,l4c_phb_anr_struct  anra,l4c_phb_anr_struct  anrb,l4c_phb_anr_struct  anrc,l4c_phb_email_struct  email,l4_name_struct  sne,kal_uint8  group_type,kal_uint8  hidden_info) 
			{_send_S_l_result_s_S_k_8_PS_l_phb_entry_s_S_k_8_S_l_phb_anr_s_S_l_phb_anr_s_S_l_phb_anr_s_S_l_phb_email_s_S_l4_name_s_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PHB_WRITE_USIM_RSP ,result,no_data,list,update_field,anra,anrb,anrc,email,sne,group_type,hidden_info);}
#endif /* defined(__MOD_PHB__) */
void l4c_sms_set_profile_params_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_SET_PROFILE_PARAMS_RSP ,result,cause);}
void l4c_sms_set_common_params_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_SET_COMMON_PARAMS_RSP ,result,cause);}
void l4c_sms_exe_post_command_lrsp(kal_bool  result,kal_uint16  cause,kal_uint8  mr,kal_uint8*  scts) 
			{_send_S_k_bool_S_k_16_S_k_8_A7A_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_SEND_COMMAND_RSP ,result,cause,mr,scts);}
void l4c_sms_exe_delete_msg_lrsp(kal_bool  result,kal_uint16  cause,smsal_del_flag_enum  del_flag,kal_uint16  index,kal_uint8  storage_type,kal_uint8*  del_bitmap) 
			{_send_S_k_bool_S_k_16_S_k_8_S_k_16_S_k_8_A480A_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_DEL_MSG_RSP ,result,cause,del_flag,index,storage_type,del_bitmap);}
void l4a_sms_exe_read_msg_lrsp(kal_bool  result,kal_uint16  cause,smsal_concat_struct  concat_info,kal_uint8  mti,kal_uint8  status,kal_uint8  storage_type,kal_uint8  fo,kal_uint8*  scts,l4c_number_struct  sca_number,l4c_number_struct  addr_number,kal_uint8  pid,kal_uint8  dcs,kal_uint8  ori_dcs,kal_uint8  vp,kal_uint8  mr,kal_uint8*  dt,kal_uint8  st,kal_uint16  dest_port,kal_uint16  src_port,kal_uint16  no_msg_data,kal_uint8*  msg_data) 
			{_send_S_k_bool_S_k_16_S_smsal_concat_s_S_k_8_S_k_8_S_k_8_S_k_8_A7A_k_8_S_l_number_s_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_A7A_k_8_S_k_8_S_k_16_S_k_16_S_k_16_A1A_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_GET_MSG_RSP ,result,cause,concat_info,mti,status,storage_type,fo,scts,sca_number,addr_number,pid,dcs,ori_dcs,vp,mr,dt,st,dest_port,src_port,no_msg_data,msg_data);}
void l4c_sms_exe_post_msg_lrsp(kal_bool  result,kal_uint16  cause,kal_uint8  mr,kal_uint8*  scts,kal_uint8  seq_num,smsal_concat_struct  concat_info) 
			{_send_S_k_bool_S_k_16_S_k_8_A7A_k_8_S_k_8_S_smsal_concat_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_SEND_MSG_RSP ,result,cause,mr,scts,seq_num,concat_info);}
void l4c_sms_exe_write_msg_lrsp(kal_bool  result,kal_uint16  cause,kal_uint16  index,kal_uint8  status,kal_uint8  storage_type) 
			{_send_S_k_bool_S_k_16_S_k_16_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_SET_MSG_RSP ,result,cause,index,status,storage_type);}
void l4c_sms_set_preferred_mem_lrsp(kal_bool  result,smsal_prefer_storage_struct*  param) 
			{_send_S_k_bool_PS_smsal_prefer_storage_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_SET_PREFERRED_STORAGE_RSP ,result,param);}
void l4a_sms_deliver_msg_ind(kal_uint8  fo,kal_uint8*  scts,l4c_number_struct  sca_number,l4c_number_struct  oa_number,kal_uint8  pid,kal_uint8  dcs,kal_uint8  ori_dcs,kal_uint16  index,kal_uint16  dest_port,kal_uint16  src_port,kal_uint8  mti,kal_uint8  display_type,kal_uint8  storage_type,kal_uint32  concat_info,kal_uint16  no_msg_data,kal_uint8*  msg_data) 
			{_send_S_k_8_A7A_k_8_S_l_number_s_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_16_S_k_16_S_k_16_S_k_8_S_k_8_S_k_8_S_k_32_S_k_16_A1A_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_DELIVER_MSG_IND ,fo,scts,sca_number,oa_number,pid,dcs,ori_dcs,index,dest_port,src_port,mti,display_type,storage_type,concat_info,no_msg_data,msg_data);}
void l4a_sms_status_report_ind(kal_uint8  fo,kal_uint8*  scts,kal_uint8*  dt,l4c_number_struct  ra_number,kal_uint8  st,kal_uint8  pid,kal_uint8  dcs,kal_uint8  mr,kal_uint16  no_msg_data,kal_uint8*  msg_data) 
			{_send_S_k_8_A7A_k_8_A7A_k_8_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_S_k_16_A1A_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_STATUS_REPORT_IND ,fo,scts,dt,ra_number,st,pid,dcs,mr,no_msg_data,msg_data);}
void l4c_sms_mem_available_lind(kal_uint8  type) 
			{_send_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_MEM_AVAILABLE_IND ,type);}
void l4c_sms_mem_exceed_lind(kal_uint8  type) 
			{_send_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_MEM_EXCEED_IND ,type);}
void l4c_sms_mem_full_lind(kal_uint8  type) 
			{_send_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_MEM_FULL_IND ,type);}
void l4c_sms_ready_lind(kal_bool  result) 
			{_send_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_READY_IND ,result);}
void l4c_sms_app_data_lind(kal_uint16  dest_mod_id,kal_uint16  dest_port,kal_uint16  src_port,kal_uint8  dcs,kal_uint8  mti,kal_uint16  message_len,void*  concat_info,l4c_number_struct*  oa,kal_uint8*  scts,kal_uint8*  msg_data) 
			{_send_S_k_16_S_k_16_S_k_16_S_k_8_S_k_8_S_k_16_Av5A_k_32_PS_l_number_s_A7A_k_8_A160A_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_APP_DATA_IND ,dest_mod_id,dest_port,src_port,dcs,mti,message_len,concat_info,oa,scts,msg_data);}
void l4c_sms_msg_waiting_lind(kal_uint8  line_no,kal_uint8  waiting_num,kal_uint8  ind_type,kal_bool  is_show_num,kal_bool  is_clear,kal_bool  is_from_storage) 
			{_send_S_k_8_S_k_8_S_k_8_S_k_bool_S_k_bool_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_MSG_WAITING_IND ,line_no,waiting_num,ind_type,is_show_num,is_clear,is_from_storage);}
void l4c_sms_set_mailbox_addr_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_SET_MAILBOX_ADDRESS_RSP ,result,cause);}
void l4c_sms_sync_msg_lind(kal_uint8  action,kal_uint16  index,kal_uint8  status,kal_uint8*  del_bitmap) 
			{_send_S_k_8_S_k_16_S_k_8_A480A_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_SYNC_MSG_IND ,action,index,status,del_bitmap);}
void l4c_sms_send_abort_start_lind() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_SEND_ABORT_START_IND, NULL);}
void l4c_sms_send_abort_finish_lind(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_SEND_ABORT_FINISH_IND ,result,cause);}
void l4c_sms_startup_begin_lind() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_STARTUP_BEGIN_IND, NULL);}
void l4c_sms_startup_finish_lind() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_STARTUP_FINISH_IND, NULL);}
void l4a_sms_startup_read_msg_lind(kal_uint8  startup_seq_num,kal_uint8  mti,kal_uint8  status,kal_uint8  storage_type,kal_uint8  fo,kal_uint16  index,kal_uint8*  scts,l4c_number_struct  addr_number,kal_uint8  pid,kal_uint8  dcs,kal_uint8  ori_dcs,kal_uint8  vp,kal_uint8  mr,kal_uint8*  dt,kal_uint8  st,kal_uint16  dest_port,kal_uint16  src_port,kal_uint32  concat_info,kal_uint16  no_msg_data,kal_uint8*  msg_data) 
			{_send_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_k_16_A7A_k_8_S_l_number_s_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_A7A_k_8_S_k_8_S_k_16_S_k_16_S_k_32_S_k_16_A1A_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_STARTUP_READ_MSG_IND ,startup_seq_num,mti,status,storage_type,fo,index,scts,addr_number,pid,dcs,ori_dcs,vp,mr,dt,st,dest_port,src_port,concat_info,no_msg_data,msg_data);}
void l4c_sms_copy_msg_lrsp(kal_uint8  result,kal_uint16  cause,kal_uint8  action,kal_uint8  dst_storage,kal_uint16  src_index,kal_uint16  dst_index) 
			{_send_S_k_8_S_k_16_S_k_8_S_k_8_S_k_16_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_COPY_MSG_RSP ,result,cause,action,dst_storage,src_index,dst_index);}
void l4c_sms_exe_read_msg_list_lrsp(smsal_inbox_list_struct  inbox,smsal_outbox_list_struct  outbox) 
			{_send_S_smsal_inbox_list_s_S_smsal_outbox_list_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_GET_MSG_LIST_RSP ,inbox,outbox);}
void l4c_sms_send_from_storage_lrsp(kal_bool  result,kal_uint16  cause,kal_uint8  mr,kal_uint16  index,smsal_concat_struct  concat_info) 
			{_send_S_k_bool_S_k_16_S_k_8_S_k_16_S_smsal_concat_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_SEND_FROM_STORAGE_RSP ,result,cause,mr,index,concat_info);}
void l4c_sms_set_status_lrsp(kal_bool  result,kal_uint16  error_cause,kal_uint16  index) 
			{_send_S_k_bool_S_k_16_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_SET_STATUS_RSP ,result,error_cause,index);}
/* Data Related Messages */
#if defined(__MOD_DATA__)
#endif /* defined(__MOD_DATA__) */
void l4c_df_exe_back_data_state_lrsp() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_DF_BACK_DATA_STATE_RSP, NULL);}
/* GPRS Related Messages */
#if defined(__MOD_TCM__)
void l4c_ps_exe_act_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PS_ACT_RSP ,result,cause);}
void l4c_ps_exe_act_test_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PS_ACT_TEST_RSP ,result,cause);}
void l4c_ps_exe_modify_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PS_MODIFY_RSP ,result,cause);}
void l4c_ps_set_definition_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PS_SET_DEFINITION_RSP ,result,cause);}
void l4c_ps_set_sec_definition_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PS_SET_SEC_DEFINITION_RSP ,result,cause);}
void l4c_ps_set_tft_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PS_SET_TFT_RSP ,result,cause);}
void l4c_ps_set_qos_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PS_SET_QOS_RSP ,result,cause);}
void l4c_ps_set_eqos_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PS_SET_EQOS_RSP ,result,cause);}
void l4c_ps_activate_lind() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PS_ACTIVE_IND, NULL);}
void l4c_ps_gprs_status_update_lind(l4c_gprs_status_enum  status,kal_uint8  cell_support_egprs) 
			{_send_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PS_GPRS_STATUS_UPDATE_IND ,status,cell_support_egprs);}
void l4a_ps_set_gprs_data_account_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PS_SET_GPRS_DATA_ACCOUNT_RSP ,result,cause);}
void l4c_ps_get_gprs_data_account_lrsp(kal_bool  result,l4c_gprs_account_info_struct  gprs_account) 
			{_send_S_k_bool_S_l_gprs_account_info_s_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PS_GET_GPRS_DATA_ACCOUNT_RSP ,result,gprs_account);}
void l4c_ps_reset_gprs_data_counter_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_PS_RESET_GPRS_DATA_COUNTER_RSP ,result,cause);}
#endif /* defined(__MOD_TCM__) */
/* STK/SAT Related Messages */
#if defined(__SAT__)
void l4a_sat_dspl_text_lind(kal_uint8*  cmd_detail,kal_uint8  priority,kal_uint8  clear_text_type,kal_uint8  immediate_res,kal_uint8  is_icon_available,sat_icon_struct  icon_info,kal_uint16  no_text_string,kal_uint8*  text_string,kal_uint8  dcs_of_text_string) 
			{_send_A5A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_16_S_k_8_p_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_DISPLAY_TEXT_IND ,cmd_detail,priority,clear_text_type,immediate_res,is_icon_available,icon_info,no_text_string,text_string,dcs_of_text_string);}
void l4a_sat_get_inkey_lind(kal_uint8*  cmd_detail,kal_uint8  is_help_info_available,kal_uint8  type_of_input,kal_uint8  is_icon_available,sat_icon_struct  icon_info,kal_uint16  no_text_string,kal_uint8*  text_string,kal_uint8  dcs_of_text_string) 
			{_send_A5A_k_8_S_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_16_S_k_8_p_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_GET_INKEY_IND ,cmd_detail,is_help_info_available,type_of_input,is_icon_available,icon_info,no_text_string,text_string,dcs_of_text_string);}
void l4a_sat_get_input_lind(kal_uint8*  cmd_detail,kal_uint8  is_help_info_available,kal_uint8  type_of_input,kal_uint8  is_input_revealed_to_user,kal_uint8  is_icon_available,sat_icon_struct  icon_info,kal_uint8  len_of_min_input,kal_uint8  len_of_max_input,kal_uint16  no_text_string,kal_uint8*  text_string,kal_uint8  dcs_of_text_string,kal_uint16  no_default_text,kal_uint8*  default_text,kal_uint8  dcs_of_default_text) 
			{_send_A5A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_S_k_16_S_k_8_p_S_k_8_S_k_16_S_k_8_p_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_GET_INPUT_IND ,cmd_detail,is_help_info_available,type_of_input,is_input_revealed_to_user,is_icon_available,icon_info,len_of_min_input,len_of_max_input,no_text_string,text_string,dcs_of_text_string,no_default_text,default_text,dcs_of_default_text);}
void l4a_sat_setup_menu_lind(kal_uint8*  cmd_detail,kal_uint8  is_help_info_available,kal_uint8  is_softkey_preferred,kal_uint8  is_icon_available,sat_icon_struct  icon_info,kal_uint8  num_of_item,kal_uint8  no_alpha_id,kal_uint8*  alpha_id,kal_uint8  dcs_of_alpha_id,kal_uint16  no_item_data,kal_uint8*  item_data,kal_uint8  no_item_icon_id_list,kal_uint8*  item_icon_id_list,kal_uint8  item_icon_list_attr,kal_uint8  no_next_action_ind_list,kal_uint8*  next_action_ind_list) 
			{_send_A5A_k_8_S_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_16_S_k_8_p_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_SETUP_MENU_IND ,cmd_detail,is_help_info_available,is_softkey_preferred,is_icon_available,icon_info,num_of_item,no_alpha_id,alpha_id,dcs_of_alpha_id,no_item_data,item_data,no_item_icon_id_list,item_icon_id_list,item_icon_list_attr,no_next_action_ind_list,next_action_ind_list);}
void l4a_sat_select_item_lind(kal_uint8*  cmd_detail,kal_uint8  is_help_info_available,kal_uint8  is_softkey_preferred,kal_uint8  type_of_presentation,kal_uint8  is_icon_available,sat_icon_struct  icon_info,kal_uint8  is_item_id_available,kal_uint8  item_id,kal_uint8  num_of_item,kal_uint8  no_alpha_id,kal_uint8*  alpha_id,kal_uint8  dcs_of_alpha_id,kal_uint16  no_item_data,kal_uint8*  item_data,kal_uint8  item_icon_list_attr,kal_uint8  no_item_icon_id_list,kal_uint8*  item_icon_id_list,kal_uint8  no_next_action_ind_list,kal_uint8*  next_action_ind_list) 
			{_send_A5A_k_8_S_k_8_S_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_16_S_k_8_p_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_p_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_SELECT_ITEM_IND ,cmd_detail,is_help_info_available,is_softkey_preferred,type_of_presentation,is_icon_available,icon_info,is_item_id_available,item_id,num_of_item,no_alpha_id,alpha_id,dcs_of_alpha_id,no_item_data,item_data,item_icon_list_attr,no_item_icon_id_list,item_icon_id_list,no_next_action_ind_list,next_action_ind_list);}
void l4a_sat_play_tone_lind(kal_uint8*  cmd_detail,kal_uint8  tone_id,kal_uint32  duration,kal_uint8  is_icon_available,sat_icon_struct  icon_info,kal_uint8  no_alpha_id,kal_uint8*  alpha_id,kal_uint8  dcs_of_alpha_id,kal_uint8  is_alpha_id_present) 
			{_send_A5A_k_8_S_k_8_S_k_32_S_k_8_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_PLAY_TONE_IND ,cmd_detail,tone_id,duration,is_icon_available,icon_info,no_alpha_id,alpha_id,dcs_of_alpha_id,is_alpha_id_present);}
void l4c_sat_exe_menu_select_lrsp(kal_uint8  result) 
			{_send_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_MENU_SELECT_RSP ,result);}
void l4a_sat_setup_call_lind(kal_uint8*  cmd_detail,kal_uint8  condition,kal_uint32  duration,kal_uint8  type_of_modification,kal_uint8  is_icon1_available,sat_icon_struct  icon_info1,kal_uint8  is_icon2_available,sat_icon_struct  icon_info2,kal_uint8  size_of_ccp,kal_uint8*  ccp,kal_uint8  size_of_subaddr,kal_uint8*  subaddr,kal_uint8  is_alpha_id1_present,kal_uint8  no_alpha_id1,kal_uint8*  alpha_id1,kal_uint8  dcs_of_alpha_id1,kal_uint8  no_addr,kal_uint8*  addr,kal_uint8  is_alpha_id2_present,kal_uint8  no_alpha_id2,kal_uint8*  alpha_id2,kal_uint8  dcs_of_alpha_id2) 
			{_send_A5A_k_8_S_k_8_S_k_32_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_sat_icon_s_S_k_8_A13A_k_8_S_k_8_A21A_k_8_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_CALL_SETUP_IND ,cmd_detail,condition,duration,type_of_modification,is_icon1_available,icon_info1,is_icon2_available,icon_info2,size_of_ccp,ccp,size_of_subaddr,subaddr,is_alpha_id1_present,no_alpha_id1,alpha_id1,dcs_of_alpha_id1,no_addr,addr,is_alpha_id2_present,no_alpha_id2,alpha_id2,dcs_of_alpha_id2);}
void l4c_sat_call_setup_lrsp(l4c_result_struct  result,kal_uint8  terminal_res,kal_uint8  additional_res) 
			{_send_S_l_result_s_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_CALL_SETUP_STAGE1_RSP ,result,terminal_res,additional_res);}
void l4a_sat_send_sms_lind(kal_uint8*  cmd_detail,kal_uint8  is_icon_available,sat_icon_struct  icon_info,kal_uint8  is_sms_packed_required,kal_uint8  size_of_addr,kal_uint8*  addr,kal_uint8  is_alpha_id_present,kal_uint8  no_alpha_id,kal_uint8*  alpha_id,kal_uint8  dcs_of_alpha_id,kal_uint8  no_sms_tpdu,kal_uint8*  sms_tpdu) 
			{_send_A5A_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_A41A_k_8_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_SEND_SMS_IND ,cmd_detail,is_icon_available,icon_info,is_sms_packed_required,size_of_addr,addr,is_alpha_id_present,no_alpha_id,alpha_id,dcs_of_alpha_id,no_sms_tpdu,sms_tpdu);}
void l4c_sat_send_sms_lrsp(kal_uint8  res,kal_uint16  cause) 
			{_send_S_k_8_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_SEND_SMS_STAGE1_RSP ,res,cause);}
void l4a_sat_send_ss_lind(kal_uint8*  cmd_detail,kal_uint8  type_of_modification,kal_uint8  is_icon_available,sat_icon_struct  icon_info,kal_uint8  is_alpha_id_present,kal_uint8  no_alpha_id,kal_uint8*  alpha_id,kal_uint8  dcs_of_alpha_id,kal_uint8  no_ss_string,kal_uint8*  ss_string) 
			{_send_A5A_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_SEND_SS_IND ,cmd_detail,type_of_modification,is_icon_available,icon_info,is_alpha_id_present,no_alpha_id,alpha_id,dcs_of_alpha_id,no_ss_string,ss_string);}
void l4c_sat_send_ss_lrsp(kal_uint8  res,kal_uint8  length,kal_uint8*  addition_info) 
			{_send_S_k_8_S_k_8_A255A_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_SEND_SS_STAGE1_RSP ,res,length,addition_info);}
void l4a_sat_send_ussd_lind(kal_uint8*  cmd_detail,kal_uint8  type_of_modification,kal_uint8  is_icon_available,sat_icon_struct  icon_info,kal_uint8  is_alpha_id_present,kal_uint8  no_alpha_id,kal_uint8*  alpha_id,kal_uint8  dcs_of_alpha_id,kal_uint8  no_ussd_string,kal_uint8*  ussd_string,kal_uint8  dcs_of_ussd_string) 
			{_send_A5A_k_8_S_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_p_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_SEND_USSD_IND ,cmd_detail,type_of_modification,is_icon_available,icon_info,is_alpha_id_present,no_alpha_id,alpha_id,dcs_of_alpha_id,no_ussd_string,ussd_string,dcs_of_ussd_string);}
void l4c_sat_send_ussd_lrsp(kal_uint8  res,kal_uint8  length,kal_uint8*  addition_info) 
			{_send_S_k_8_S_k_8_A255A_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_SEND_USSD_STAGE1_RSP ,res,length,addition_info);}
void l4a_sat_mmi_info_lind(kal_uint8  mmi_info_type,kal_uint8  is_alpha_id_present,kal_uint8  no_alpha_id,kal_uint8*  alpha_id,kal_uint8  dcs_of_alpha_id,kal_uint8  len_of_address,kal_uint8*  address,kal_uint8  ton) 
			{_send_S_k_8_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_A41A_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_MMI_INFO_IND ,mmi_info_type,is_alpha_id_present,no_alpha_id,alpha_id,dcs_of_alpha_id,len_of_address,address,ton);}
void l4a_sat_setup_idle_dspl_lind(kal_uint8*  cmd_detail,kal_uint8  is_icon_available,sat_icon_struct  icon_info,kal_uint16  no_text_string,kal_uint8*  text_string,kal_uint8  dcs_of_text_string) 
			{_send_A5A_k_8_S_k_8_S_sat_icon_s_S_k_16_S_k_8_p_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_SETUP_IDLE_DISPLAY_IND ,cmd_detail,is_icon_available,icon_info,no_text_string,text_string,dcs_of_text_string);}
void l4a_sat_run_at_command_lind(kal_uint8*  cmd_detail,kal_uint8  is_icon_available,sat_icon_struct  icon_info,kal_uint8  no_alpha_id,kal_uint8*  alpha_id,kal_uint8  is_alpha_id_present,kal_uint8  dcs_of_alpha_id,kal_uint8  no_at_command,kal_uint8*  at_command) 
			{_send_A5A_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_S_k_8_p_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_RUN_AT_COMMAND_IND ,cmd_detail,is_icon_available,icon_info,no_alpha_id,alpha_id,is_alpha_id_present,dcs_of_alpha_id,no_at_command,at_command);}
void l4a_sat_send_dtmf_lind(kal_uint8*  cmd_detail,kal_uint8  is_icon_available,sat_icon_struct  icon_info,kal_uint8  no_alpha_id,kal_uint8*  alpha_id,kal_uint8  is_alpha_id_present,kal_uint8  dcs_of_alpha_id,kal_uint8  no_dtmf,kal_uint8*  dtmf) 
			{_send_A5A_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_S_k_8_p_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_SEND_DTMF_IND ,cmd_detail,is_icon_available,icon_info,no_alpha_id,alpha_id,is_alpha_id_present,dcs_of_alpha_id,no_dtmf,dtmf);}
void l4c_sat_send_dtmf_lrsp(kal_uint8  terminal_res,kal_uint8  cause) 
			{_send_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_SEND_DTMF_STAGE1_RSP ,terminal_res,cause);}
void l4a_sat_lang_notify_lind(kal_uint8*  cmd_detail,kal_uint8  is_language_specified,kal_uint8*  iso639_language) 
			{_send_A5A_k_8_S_k_8_A2A_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_LANG_NOTIFY_IND ,cmd_detail,is_language_specified,iso639_language);}
void l4a_sat_launch_browser_lind(kal_uint8*  cmd_detail,kal_uint8  is_icon_available,sat_icon_struct  icon_info,kal_uint8  browser_mode,kal_uint8  browser_identity,kal_uint8*  provision_file_id,kal_uint8  no_alpha_id,kal_uint8*  alpha_id,kal_uint8  is_alpha_id_present,kal_uint8  dcs_of_alpha_id,kal_uint8  no_url,kal_uint8*  url,kal_uint8  no_bearer,kal_uint8*  bearer,kal_uint16  no_gateway,kal_uint8*  gateway,kal_uint8  dcs_of_gateway) 
			{_send_A5A_k_8_S_k_8_S_sat_icon_s_S_k_8_S_k_8_A10A_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_p_S_k_16_S_k_8_p_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_LAUNCH_BROWSER_IND ,cmd_detail,is_icon_available,icon_info,browser_mode,browser_identity,provision_file_id,no_alpha_id,alpha_id,is_alpha_id_present,dcs_of_alpha_id,no_url,url,no_bearer,bearer,no_gateway,gateway,dcs_of_gateway);}
void l4a_sat_no_other_cmd_lind() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_NO_OTHER_CMD_IND, NULL);}
void l4c_sat_file_change_lind(kal_uint8  is_full_changed,kal_uint8  refresh_type,kal_uint8  num_of_file,kal_uint8*  file_list) 
			{_send_S_k_8_S_k_8_S_k_8_A120A_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_SIM_FILE_CHANGE_IND ,is_full_changed,refresh_type,num_of_file,file_list);}
#endif /* defined(__SAT__) */
/* STK_CE */
#if defined(__SATCE__)
void l4a_sat_open_channel_lind(kal_uint8*  cmd_detail,kal_bool  is_icon_available,sat_icon_struct  icon_info,kal_uint8  bearer_type,kal_uint8  no_alpha_id,kal_uint8*  alpha_id,kal_uint8  is_alpha_id_present,kal_uint8  dcs_of_alpha_id) 
			{_send_A5A_k_8_S_k_bool_S_sat_icon_s_S_k_8_S_k_8_S_k_8_p_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_OPEN_CHANNEL_IND ,cmd_detail,is_icon_available,icon_info,bearer_type,no_alpha_id,alpha_id,is_alpha_id_present,dcs_of_alpha_id);}
void l4c_sat_open_channel_lrsp(kal_uint8  terminal_res) 
			{_send_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_OPEN_CHANNEL_RSP ,terminal_res);}
void l4a_sat_close_channel_lind(kal_uint8*  cmd_detail,kal_bool  is_icon_available,sat_icon_struct  icon_info,kal_uint8  no_alpha_id,kal_uint8*  alpha_id,kal_uint8  is_alpha_id_present,kal_uint8  dcs_of_alpha_id) 
			{_send_A5A_k_8_S_k_bool_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_CLOSE_CHANNEL_IND ,cmd_detail,is_icon_available,icon_info,no_alpha_id,alpha_id,is_alpha_id_present,dcs_of_alpha_id);}
void l4c_sat_close_channel_lrsp(kal_uint8  terminal_res) 
			{_send_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_CLOSE_CHANNEL_RSP ,terminal_res);}
void l4a_sat_send_data_lind(kal_uint8*  cmd_detail,kal_bool  is_icon_available,sat_icon_struct  icon_info,kal_uint8  no_alpha_id,kal_uint8*  alpha_id,kal_uint8  is_alpha_id_present,kal_uint8  dcs_of_alpha_id) 
			{_send_A5A_k_8_S_k_bool_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_SEND_DATA_IND ,cmd_detail,is_icon_available,icon_info,no_alpha_id,alpha_id,is_alpha_id_present,dcs_of_alpha_id);}
void l4c_sat_send_data_lrsp(kal_uint8*  cmd_detail,kal_uint8  terminal_res,kal_uint8  cause) 
			{_send_A5A_k_8_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_SEND_DATA_RSP ,cmd_detail,terminal_res,cause);}
void l4a_sat_recv_data_lind(kal_uint8*  cmd_detail,kal_bool  is_icon_available,sat_icon_struct  icon_info,kal_uint8  no_alpha_id,kal_uint8*  alpha_id,kal_uint8  is_alpha_id_present,kal_uint8  dcs_of_alpha_id) 
			{_send_A5A_k_8_S_k_bool_S_sat_icon_s_S_k_8_S_k_8_p_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_RECV_DATA_IND ,cmd_detail,is_icon_available,icon_info,no_alpha_id,alpha_id,is_alpha_id_present,dcs_of_alpha_id);}
void l4c_sat_recv_data_lrsp(kal_uint8*  cmd_detail,kal_uint8  terminal_res,kal_uint8  cause) 
			{_send_A5A_k_8_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_RECV_DATA_RSP ,cmd_detail,terminal_res,cause);}
void l4c_sat_notify_mmi_lind(kal_uint8  state) 
			{_send_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SAT_NOTIFY_MMI_IND ,state);}
#endif /* defined(__SATCE__) */
void l4c_cb_dl_lind() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CB_DOWNLOAD_IND, NULL);}
void l4a_cb_msg_lind(kal_uint16  sn,kal_uint16  mi,kal_uint8  dcs,kal_uint8  page,kal_uint8  pages,kal_uint16  msg_length,kal_uint8*  msg_data) 
			{_send_S_k_16_S_k_16_S_k_8_S_k_8_S_k_8_S_k_16_A1A_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CB_MSG_IND ,sn,mi,dcs,page,pages,msg_length,msg_data);}
void l4c_sms_set_cb_mode_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMS_SET_CB_MODE_RSP ,result,cause);}
/* Engineer Mode-UEM */
#if defined(__MOD_UEM__)
void l4c_eq_set_gain_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EM_SET_GAIN_RSP ,result,cause);}
#endif /* defined(__MOD_UEM__) */
/* Engineer Mode */
#if defined(__EM_MODE__)
void l4c_em_status_ind(kal_uint8  mod_id,kal_uint32  em_info,peer_buff_struct*  info) 
			{_send_S_k_8_S_k_32_S_peer_buff_s_p_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EM_STATUS_IND ,mod_id,em_info,info);}
void l4c_em_start_rsp(kal_bool  result,kal_uint8  cause,kal_uint8  mod_id,kal_uint32  info_request) 
			{_send_S_k_bool_S_k_8_S_k_8_S_k_32_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EM_START_RSP ,result,cause,mod_id,info_request);}
void l4c_em_stop_rsp(kal_bool  result,kal_uint8  cause,kal_uint8  mod_id,kal_uint32  info_request) 
			{_send_S_k_bool_S_k_8_S_k_8_S_k_32_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EM_STOP_RSP ,result,cause,mod_id,info_request);}
void l4c_em_set_cell_id_lock_lrsp(kal_bool  result) 
			{_send_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EM_SET_CELL_ID_LOCK_RSP ,result);}
#endif /* defined(__EM_MODE__) */
void l4c_em_lcm_test_lind(kal_uint8  color) 
			{_send_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EM_LCM_TEST_IND ,color);}
void l4c_em_keypad_event_act_lind(kal_bool  on_off) 
			{_send_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EM_KEYPAD_EVENT_ACT_IND ,on_off);}
void l4c_factory_test_lind(kal_bool  on_off) 
			{_send_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_FACTORY_TEST_IND ,on_off);}
void l4c_set_mmi_default_prof_lind(kal_uint8  op,kal_uint8  category,kal_uint8  param1,kal_uint8  param2,kal_uint8  param3,kal_uint8*  param4) 
			{_send_S_k_8_S_k_8_S_k_8_S_k_8_S_k_8_A10A_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SET_MMI_DEFAULT_PROF_IND ,op,category,param1,param2,param3,param4);}
void l4c_em_cell_resel_suspend_rsp(kal_bool  result,kal_uint8  cause) 
			{_send_S_k_bool_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EM_CELL_RESEL_SUSPEND_RSP ,result,cause);}
void l4c_em_cell_resel_resume_rsp(kal_bool  result,kal_uint8  cause) 
			{_send_S_k_bool_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EM_CELL_RESEL_RESUME_RSP ,result,cause);}
void l4c_em_get_cell_lock_rsp(kal_bool  result,kal_bool  turn_on_or_off,kal_bool  band_indicator,kal_uint16  lock_arfcn) 
			{_send_S_k_bool_S_k_bool_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EM_GET_CELL_LOCK_RSP ,result,turn_on_or_off,band_indicator,lock_arfcn);}
void l4c_em_set_cell_lock_rsp(kal_bool  result) 
			{_send_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EM_SET_CELL_LOCK_RSP ,result);}
void l4c_em_rgb_test_req_lind(kal_uint8  type,kal_uint16  red,kal_uint16  green,kal_uint16  blue) 
			{_send_S_k_8_S_k_16_S_k_16_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EM_RGB_TEST_REQ_IND ,type,red,green,blue);}
kal_bool l4c_em_nw_event_notify_rsp(kal_bool  result) 
			{_send_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EM_NW_EVENT_NOTIFY_RSP ,result);}
void l4c_em_nw_event_notify_lind(kal_uint8  group_id,kal_uint32  event_id) 
			{_send_S_k_8_S_k_32_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EM_NW_EVENT_NOTIFY_IND ,group_id,event_id);}
void l4c_em_feature_command_rsp(kal_bool  result,kal_uint8  em_feature) 
			{_send_S_k_bool_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EM_FEATURE_COMMAND_RSP ,result,em_feature);}
/* Audio Task - Voice Memo(via FS) */
#if defined(__FS_ON__)
void l4c_eq_vm_play_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_VM_PLAY_RSP ,result,cause);}
void l4c_eq_vm_delete_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_VM_DEL_RSP ,result,cause);}
void l4c_eq_vm_append_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_VM_APPEND_RSP ,result,cause);}
void l4c_eq_vm_rename_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_VM_RENAME_RSP ,result,cause);}
void l4c_eq_vm_play_finish_lind(kal_uint8  result) 
			{_send_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_VM_PLAY_FINISH_IND ,result);}
void l4c_eq_vm_get_info_lrsp(kal_uint16  no_vm,kal_wchar*  file_list,kal_bool  more_entry,kal_uint32  free_space) 
			{_send_S_k_16_Av6A_k_wchar_S_k_bool_S_k_32_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_VM_GET_INFO_RSP ,no_vm,file_list,more_entry,free_space);}
void l4c_eq_vm_stop_lrsp(l4c_result_struct  result,kal_wchar*  file_name) 
			{_send_S_l_result_s_A20A_k_wchar_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_VM_STOP_RSP ,result,file_name);}
void l4c_eq_vm_abort_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_VM_ABORT_RSP ,result,cause);}
void l4c_eq_vm_pause_lrsp(l4c_result_struct  result,kal_wchar*  file_name) 
			{_send_S_l_result_s_A20A_k_wchar_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_VM_PAUSE_RSP ,result,file_name);}
void l4c_eq_vm_resume_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_VM_RESUME_RSP ,result,cause);}
void l4c_eq_vm_record_lrsp(kal_bool  result,kal_uint16  cause) 
			{_send_S_k_bool_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_VM_RECORD_RSP ,result,cause);}
void l4c_eq_vm_record_finish_lind(kal_uint8  result,kal_wchar*  file_name) 
			{_send_S_k_8_A20A_k_wchar_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_VM_RECORD_FINISH_IND ,result,file_name);}
#endif /* defined(__FS_ON__) */
void l4c_cphs_display_cfu_lind(kal_uint8  action,kal_uint8  line_num) 
			{_send_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CPHS_DISPLAY_CFU_IND ,action,line_num);}
void l4a_cphs_mmi_info_lind(kal_uint8  is_spn_valid,kal_uint8  is_spn_RPLMN_required,kal_uint8*  spn,kal_uint8  is_opname_valid,kal_uint8*  opname,kal_uint8  is_sopname_valid,kal_uint8*  sopname,kal_uint8  no_msisdn,l4csmu_addr_struct*  msisdn,kal_uint8  no_info_num,l4csmu_info_num_struct*  info_num,kal_uint8  is_valid_csp,kal_uint8*  csp,kal_uint8  is_puct_valid,kal_uint8*  ef_puct,kal_uint8  is_autolock_enable,kal_uint8  autolock_result,kal_uint8  autolock_remain) 
			{_send_S_k_8_S_k_8_A17A_k_8_S_k_8_A21A_k_8_S_k_8_A11A_k_8_S_k_8_A2A_l4csmu_addr_s_S_k_8_A20A_l4csmu_info_num_s_S_k_8_A22A_k_8_S_k_8_A5A_k_8_S_k_8_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CPHS_MMI_INFO_IND ,is_spn_valid,is_spn_RPLMN_required,spn,is_opname_valid,opname,is_sopname_valid,sopname,no_msisdn,msisdn,no_info_num,info_num,is_valid_csp,csp,is_puct_valid,ef_puct,is_autolock_enable,autolock_result,autolock_remain);}
void l4c_cphs_update_als_lrsp(kal_uint8  res,kal_uint16  cause) 
			{_send_S_k_8_S_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CPHS_UPDATE_ALS_RSP ,res,cause);}
void l4c_cphs_display_als_lind(kal_uint8  line) 
			{_send_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CPHS_DISPLAY_ALS_IND ,line);}
void l4c_cc_exe_start_dtmf_wrsp(kal_uint8  call_id,kal_uint8  response,kal_uint8  tone,kal_uint8  cause_present,kal_uint16  cause) 
			{_send_S_k_8_S_k_8_S_k_8_S_k_8_S_k_16_(l4c_current_mod_id, MOD_WAP, MSG_ID_WAP_START_DTMF_RSP ,call_id,response,tone,cause_present,cause);}
void l4c_cc_exe_stop_dtmf_wrsp() 
			{_send_none(l4c_current_mod_id, MOD_WAP, MSG_ID_WAP_STOP_DTMF_RSP, NULL);}
void l4c_cc_exe_call_setup_wrsp(l4c_result_struct  result,kal_uint8  call_id) 
			{_send_S_l_result_s_S_k_8_(l4c_current_mod_id, MOD_WAP, MSG_ID_WAP_DIAL_RSP ,result,call_id);}
void l4c_phb_exe_write_entry_wrsp(l4c_result_struct  result,kal_uint16  no_list,l4c_phb_entry_struct*  list) 
			{_send_S_l_result_s_S_k_16_A15A_l_phb_entry_s_(l4c_current_mod_id, MOD_WAP, MSG_ID_WAP_SET_ENTRY_RSP ,result,no_list,list);}
void l4c_cc_auto_dtmf_compl_wind(kal_uint8  call_id) 
			{_send_S_k_8_(l4c_current_mod_id, MOD_WAP, MSG_ID_WAP_AUTO_DTMF_COMPLETE_IND ,call_id);}
/* IrDA */
#if defined(__IRDA_SUPPORT__)
void l4c_eq_ircomm_connect_lind() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_IRCOMM_CONNECT_IND, NULL);}
void l4c_eq_ircomm_disconnect_lind() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_IRCOMM_DISCONNECT_IND, NULL);}
#endif /* defined(__IRDA_SUPPORT__) */
/* USB */
#if defined(__USB_ENABLE__)
void l4c_eq_usbconfig_lrsp(kal_bool  result,kal_uint8  mode,kal_uint32  reserved) 
			{_send_S_k_bool_S_k_8_S_k_32_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_USBCONFIG_RSP ,result,mode,reserved);}
void l4c_eq_usbdetect_lind(kal_uint8  action) 
			{_send_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_USBDETECT_IND ,action);}
#endif /* defined(__USB_ENABLE__) */
void l4c_eq_data_dl_filelist_info_req_lind(l4c_data_dl_folder_enum  data_folder) 
			{_send_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_DATA_DL_FILELIST_INFO_REQ_IND ,data_folder);}
void l4c_eq_data_dl_file_modify_req_lind(l4c_data_dl_folder_enum  data_folder,kal_uint8*  filename,l4c_data_dl_file_action_enum  action) 
			{_send_S_k_8_A520A_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_DATA_DL_FILE_MODIFY_REQ_IND ,data_folder,filename,action);}
void l4c_eq_data_dl_execute_req_lind(l4c_data_dl_folder_enum  data_folder,kal_uint8*  filename,l4c_data_dl_execute_action_enum  action) 
			{_send_S_k_8_A520A_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_DATA_DL_EXECUTE_REQ_IND ,data_folder,filename,action);}
void l4c_mms_read_folder_status_wind(kal_uint8  folderId,kal_uint8  retrievalMode) 
			{_send_S_k_8_S_k_8_(l4c_current_mod_id, MOD_WAP, MSG_ID_WAP_MMC_READ_FOLDER_STATUS_REQ_IND ,folderId,retrievalMode);}
void l4c_mms_upload_msg_wind(kal_uint8*  filePath) 
			{_send_A100A_k_8_(l4c_current_mod_id, MOD_WAP, MSG_ID_WAP_MMC_UPLOAD_MSG_REQ_IND ,filePath);}
void l4c_mms_delete_msg_wind(kal_uint32  msgId,kal_uint8  folderId) 
			{_send_S_k_32_S_k_8_(l4c_current_mod_id, MOD_WAP, MSG_ID_WAP_MMC_DELETE_MSG_REQ_IND ,msgId,folderId);}
void l4c_eq_query_greeting_text_req_lind() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_QUERY_GREETING_TEXT_REQ_IND, NULL);}
void l4c_eq_query_language_req_lind() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_QUERY_LANGUAGE_REQ_IND, NULL);}
void l4c_eq_query_silent_mode_req_lind() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_QUERY_SILENT_MODE_REQ_IND, NULL);}
void l4c_eq_query_vibrator_mode_req_lind() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_QUERY_VIBRATOR_MODE_REQ_IND, NULL);}
void l4c_eq_query_datetime_format_req_lind(kal_bool  is_date) 
			{_send_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_QUERY_DATE_TIME_FORMAT_REQ_IND ,is_date);}
void l4c_eq_query_mute_mode_req_lind() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_QUERY_MUTE_MODE_REQ_IND, NULL);}
void l4c_eq_power_reset_lind(kal_uint8  poweroff,kal_uint8  poweron,kal_uint8  rtc_timer) 
			{_send_S_k_8_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_POWER_RESET_IND ,poweroff,poweron,rtc_timer);}
void l4c_mmi_factory_restore_req_lind(kal_uint8*  pwd) 
			{_send_A16A_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_FACTORY_RESTORE_REQ_IND ,pwd);}
void l4c_eq_vcard_req_lind(kal_uint8  src_id,kal_uint8  mode,kal_uint16  index,kal_uint8*  file_path) 
			{_send_S_k_8_S_k_8_S_k_16_A50A_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_VCARD_REQ_IND ,src_id,mode,index,file_path);}
void l4c_eq_vcalendar_req_lind(kal_uint8  mode,kal_uint16  index,kal_uint8*  file_path) 
			{_send_S_k_8_S_k_16_A50A_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_VCALENDAR_REQ_IND ,mode,index,file_path);}
void l4c_eq_str_enable_req_lind(kal_bool  enable) 
			{_send_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_STR_ENABLE_REQ_IND ,enable);}
void l4c_eq_str_req_lind(kal_uint16  length,kal_uint8*  data_string) 
			{_send_S_k_16_A250A_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_STR_REQ_IND ,length,data_string);}
void l4c_mmi_ucm_at_req_lind(kal_uint8  action,kal_uint8  source_id,kal_bool  cmd_from_bt,kal_uint8  length,kal_uint8*  number,kal_uint8  opcode,kal_uint8  call_id) 
			{_send_S_k_8_S_k_8_S_k_bool_S_k_8_A50A_k_8_S_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_UCM_AT_REQ_IND ,action,source_id,cmd_from_bt,length,number,opcode,call_id);}
void l4c_mmi_java_local_install_req_lind(kal_bool  is_force,kal_wchar*  jad_file_name,kal_wchar*  jar_file_name) 
			{_send_S_k_bool_S_k_wchar_p_S_k_wchar_p_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_JAVA_LOCAL_INSTALL_REQ_IND ,is_force,jad_file_name,jar_file_name);}
/* Bluetooth */
#if defined(__BT_SUPPORT__)
void l4c_bt_fcty_set_param_lind(kal_uint8*  name,kal_uint8*  bd_addr,kal_uint8  dcs) 
			{_send_A32A_k_8_A6A_k_8_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_L4_BT_FCTY_SET_PARAM_IND ,name,bd_addr,dcs);}
void l4c_bt_loopback_test_req_lind(kal_uint8*  bd_addr,kal_uint8*  pin_code) 
			{_send_A6A_k_8_A17A_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_L4_BT_LOOPBACK_TEST_REQ_IND ,bd_addr,pin_code);}
void l4c_bt_set_vr_req_ind(kal_bool  on_off) 
			{_send_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_L4_BT_SET_VR_REQ_IND ,on_off);}
#endif /* defined(__BT_SUPPORT__) */
/* HOMEZONE */
#if defined(__HOMEZONE_SUPPORT__)
void l4c_hz_tag_lind(kal_bool  action,kal_bool  is_hz,kal_uint8*  tag) 
			{_send_S_k_bool_S_k_bool_A12A_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_HZ_TAG_IND ,action,is_hz,tag);}
#endif /* defined(__HOMEZONE_SUPPORT__) */
/* CTM */
#if defined(__CTM_SUPPORT__)
void l4c_ctm_open_lrsp(kal_bool  result,kal_uint8  ctm_interface) 
			{_send_S_k_bool_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CTM_OPEN_RSP ,result,ctm_interface);}
void l4c_ctm_close_lrsp(kal_bool  result) 
			{_send_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CTM_CLOSE_RSP ,result);}
void l4c_ctm_connect_lrsp(kal_bool  result) 
			{_send_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CTM_CONNECT_RSP ,result);}
void l4c_ctm_connected_lind() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CTM_CONNECTED_IND, NULL);}
void l4c_ctm_send_text_lrsp(kal_bool  result) 
			{_send_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CTM_SEND_TEXT_RSP ,result);}
void l4c_ctm_recv_text_lind(kal_uint16  num_of_char,kal_uint16*  text) 
			{_send_S_k_16_Av7A_k_16_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CTM_RECV_TEXT_IND ,num_of_char,text);}
void l4c_ctm_tty_plug_lind(kal_bool  is_plug_in) 
			{_send_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CTM_TTY_PLUG_IND ,is_plug_in);}
void l4c_ctm_set_default_lrsp(kal_bool  result) 
			{_send_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CTM_SET_DEFAULT_RSP ,result);}
void l4c_ctm_default_changed_lind(kal_bool  result,kal_bool  is_turn_on,kal_uint8  ctm_interface) 
			{_send_S_k_bool_S_k_bool_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CTM_DEFAULT_CHANGED_IND ,result,is_turn_on,ctm_interface);}
void l4c_ctm_get_default_lrsp(kal_bool  result,kal_bool  is_turn_on,kal_uint8  ctm_interface) 
			{_send_S_k_bool_S_k_bool_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_CTM_GET_DEFAULT_RSP ,result,is_turn_on,ctm_interface);}
#endif /* defined(__CTM_SUPPORT__) */
/* VOIP */
#if defined(__VOIP__)
void l4c_mmi_voip_at_call_ctrl_approve_lrsp(kal_bool  result) 
			{_send_S_k_bool_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_VOIP_AT_CALL_CTRL_APPROVE_RES_RSP ,result);}
void l4c_mmi_voip_at_call_ctrl_approve_lind(kal_uint8  action,void*  string_ptr,void*  node_ptr,void*  err_id) 
			{_send_S_k_8_S_void_p_S_void_p_S_void_p_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_VOIP_AT_CALL_CTRL_APPROVE_IND ,action,string_ptr,node_ptr,err_id);}
#endif /* defined(__VOIP__) */
/* GEMINI */
#if defined(__GEMINI__)
void l4c_eq_pwnon_dual_sim_lind() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_EQ_PWNON_DUAL_SIM_IND, NULL);}
void l4c_sim_status_update_lind(kal_bool  is_sim_inserted,kal_uint8  dual_sim_mode_setting) 
			{_send_S_k_bool_S_k_8_(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_SMU_SIM_STATUS_UPDATE_IND ,is_sim_inserted,dual_sim_mode_setting);}
void l4c_nw_rac_activated_lind() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_NW_RAC_ACTIVATED_IND, NULL);}
void l4c_nw_search_normal_finish_lind() 
			{_send_none(l4c_current_mod_id, MOD_MMI, MSG_ID_MMI_NW_SEARCH_NORMAL_FINISH_IND, NULL);}
#endif /* defined(__GEMINI__) */

/*MTK:END*/

#endif
#endif



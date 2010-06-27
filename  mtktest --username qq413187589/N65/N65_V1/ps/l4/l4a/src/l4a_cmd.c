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
 *	l4a_cmd.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for L4A.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifdef __MOD_L4A__

#include "kal_release.h"      	/* Basic data type */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */
#include "stacklib.h"        	/* Basic type for dll, evshed, stacktimer */
#include "app_buff_alloc.h"
#include "stack_timer.h"
#include "event_shed.h"

#include "l4a.h"
#include "l4a_cmd.h"
#include "csmss_aux_msg_hdlr.h"

#include "layer4_context.h"
/*
* FUNCTION                                                            
*	l4a_eq_get_audio_profile_req
* DESCRIPTION                                                           
*	send get audio profile request to l4c
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_eq_get_audio_profile_req(kal_uint8 src_id,
										audio_profile_struct* audio_prof_in)
{
//	*audio_prof_out = *audio_prof_in;
	return l4c_eq_get_audio_profile_req(src_id,audio_prof_in->mode);
}

#ifdef VM_SUPPORT
#ifndef __FS_ON__
/*
* FUNCTION                                                            
*	l4a_eq_vm_get_info_nofs_lrsp
* DESCRIPTION                                                           
*	filesystem wrap function, only for difference from vm_fs functions
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_eq_vm_get_info_nofs_req (kal_uint8 src_id)
{
	return l4c_eq_vm_get_info_req (src_id);
}
/*
* FUNCTION                                                            
*	l4a_eq_vm_record_nofs_req
* DESCRIPTION                                                           
*	filesystem wrap function, only for difference from vm_fs functions
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_eq_vm_record_nofs_req (kal_uint8 src_id,kal_uint8 dir)
{
	return l4c_eq_vm_record_req (src_id,dir);
}
/*
* FUNCTION                                                            
*	l4a_eq_vm_stop_nofs_req
* DESCRIPTION                                                           
*	filesystem wrap function, only for difference from vm_fs functions
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_eq_vm_stop_nofs_req (kal_uint8 src_id)
{
	return  l4c_eq_vm_stop_req ( src_id);
}
/*
* FUNCTION                                                            
*	l4a_eq_vm_abort_nofs_req
* DESCRIPTION                                                           
*	filesystem wrap function, only for difference from vm_fs functions
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_eq_vm_abort_nofs_req (kal_uint8 src_id)
{
	return l4c_eq_vm_abort_req (src_id);
}
/*
* FUNCTION                                                            
*	l4a_eq_vm_pause_nofs_req
* DESCRIPTION                                                           
*	filesystem wrap function, only for difference from vm_fs functions
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_eq_vm_pause_nofs_req (kal_uint8 src_id)
{
	return l4c_eq_vm_pause_req (src_id);
}
/*
* FUNCTION                                                            
*	l4a_eq_vm_resume_nofs_req
* DESCRIPTION                                                           
*	filesystem wrap function, only for difference from vm_fs functions
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_eq_vm_resume_nofs_req (kal_uint8 src_id)
{
	return l4c_eq_vm_resume_req ( src_id);
}
/*
* FUNCTION                                                            
*	l4a_eq_vm_play_nofs_lrsp
* DESCRIPTION                                                           
*	filesystem wrap function, only for difference from vm_fs functions
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_eq_vm_play_nofs_req (kal_uint8 src_id, kal_uint8 fileid)
{
	return l4c_eq_vm_play_req (src_id, fileid);
}

/*
* FUNCTION                                                            
*	l4a_eq_vm_delete_nofs_req
* DESCRIPTION                                                           
*	filesystem wrap function, only for difference from vm_fs functions
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_eq_vm_delete_nofs_req (kal_uint8 src_id,
                                      kal_uint8 fileid,
                                      kal_bool delete_all)
{
	return l4c_eq_vm_delete_req (src_id,
                                      fileid,
                                      delete_all);
}
/*
* FUNCTION                                                            
*	l4a_eq_vm_append_nofs_req
* DESCRIPTION                                                           
*	filesystem wrap function, only for difference from vm_fs functions
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_eq_vm_append_nofs_req (kal_uint8 src_id, kal_uint8 fileid)
{
	return l4c_eq_vm_append_req (src_id, fileid);
}
/*
* FUNCTION                                                            
*	l4c_eq_vm_record_lrsp
* DESCRIPTION                                                           
*	filesystem wrap function, only for difference from vm_fs functions
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_eq_vm_record_lrsp(kal_bool result, kal_uint16 cause)
{
	l4a_eq_vm_record_nofs_lrsp(result,cause);
}
/*
* FUNCTION                                                            
*	l4c_eq_vm_play_lrsp
* DESCRIPTION                                                           
*	filesystem wrap function, only for difference from vm_fs functions
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_eq_vm_play_lrsp(kal_bool result, kal_uint16 cause)
{
	l4a_eq_vm_play_nofs_lrsp(result,cause);
}
/*
* FUNCTION                                                            
*	l4c_eq_vm_delete_lrsp
* DESCRIPTION                                                           
*	filesystem wrap function, only for difference from vm_fs functions
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_eq_vm_delete_lrsp(kal_bool result, kal_uint16 cause)
{
	l4a_eq_vm_delete_nofs_lrsp(result,cause);
}
/*
* FUNCTION                                                            
*	l4c_eq_vm_about_lrsp
* DESCRIPTION                                                           
*	filesystem wrap function, only for difference from vm_fs functions
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_eq_vm_abort_lrsp(kal_bool result, kal_uint16 cause)
{
	l4a_eq_vm_abort_nofs_lrsp(result,cause);
}
/*
* FUNCTION                                                            
*	l4c_eq_vm_resume_lrsp
* DESCRIPTION                                                           
*	filesystem wrap function, only for difference from vm_fs functions
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_eq_vm_resume_lrsp(kal_bool result, kal_uint16 cause)
{
	l4a_eq_vm_resume_nofs_lrsp(result,cause);
}
/*
* FUNCTION                                                            
*	l4c_eq_vm_append_lrsp
* DESCRIPTION                                                           
*	filesystem wrap function, only for difference from vm_fs functions
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_eq_vm_append_lrsp(kal_bool result, kal_uint16 cause)
{
	l4a_eq_vm_append_nofs_lrsp(result,cause);
}
/*
* FUNCTION                                                            
*	l4c_eq_vm_get_info_lrsp
* DESCRIPTION                                                           
*	filesystem wrap function, only for difference from vm_fs functions
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_eq_vm_get_info_lrsp(kal_uint32 index, kal_uint32 time)
{
	l4a_eq_vm_get_info_nofs_lrsp(index,time);
}
/*
* FUNCTION                                                            
*	l4c_eq_vm_stop_lrsp
* DESCRIPTION                                                           
*	filesystem wrap function, only for difference from vm_fs functions
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_eq_vm_stop_lrsp(l4c_result_struct result, kal_uint8 file_id)
{
	l4a_eq_vm_stop_nofs_lrsp(result,file_id);
}
/*
* FUNCTION                                                            
*	l4c_eq_vm_pause_lrsp
* DESCRIPTION                                                           
*	filesystem wrap function, only for difference from vm_fs functions
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_eq_vm_pause_lrsp(l4c_result_struct result, kal_uint8 file_id)
{
	l4a_eq_vm_pause_nofs_lrsp(result,file_id);
}
/*
* FUNCTION                                                            
*	l4c_eq_vm_record_finish_lind
* DESCRIPTION                                                           
*	filesystem wrap function, only for difference from vm_fs functions
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_eq_vm_record_finish_lind (kal_uint8 result, kal_uint8 file_id)
{
	l4a_eq_vm_record_finish_nofs_lind (result, file_id);
}
/*
* FUNCTION                                                            
*	l4c_eq_vm_play_finish_lind
* DESCRIPTION                                                           
*	filesystem wrap function, only for difference from vm_fs functions
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
void l4c_eq_vm_play_finish_lind (kal_uint8 result)
{
	l4a_eq_vm_play_finish_nofs_lind (result);
}
#endif //!__FS_ON__
#endif //VM_SUPPORT

/*
* FUNCTION                                                            
*	l4a_wap_cc_send_dtmf_req
* DESCRIPTION                                                           
*	send dtmf request to l4a
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_wap_cc_send_dtmf_req(kal_uint8 src_id, kal_uint8 digit)
{
	return l4c_cc_exe_send_dtmf_req(WAP_SRC,digit);
}
/*
* FUNCTION                                                            
*	l4a_wap_cc_stop_dtmf_req
* DESCRIPTION                                                           
*	send stop dtmf request to l4a
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_wap_cc_stop_dtmf_req(kal_uint8 src_id)
{
	return l4c_cc_exe_stop_dtmf_req(WAP_SRC);
}
/*
* FUNCTION                                                            
*	l4a_wap_cc_call_setup_req
* DESCRIPTION                                                           
*	send call setup request to l4a
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_wap_cc_call_setup_req(kal_uint8 src_id, l4c_number_struct dest, kal_uint8 redial_count, kal_uint8 call_type, kal_uint8 clir_flag, kal_bool cug_option)
{
	return l4c_cc_exe_call_setup_req(WAP_SRC,
		dest,redial_count,call_type,clir_flag,cug_option);
}
/*
* FUNCTION                                                            
*	l4a_wap_phb_exe_write_entry_req
* DESCRIPTION                                                           
*	send phonebook write entry request to l4a
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_wap_phb_exe_write_entry_req(kal_uint8 src_id, kal_uint8 type, kal_uint16 no_data, l4c_phb_entry_struct* list)
{
	return l4c_phb_exe_write_entry_req(WAP_SRC,type,no_data,list);
}

/*
* FUNCTION                                                            
*	l4a_ss_string_req
* DESCRIPTION                                                           
*	send ss string request to l4c
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_ss_string_req (kal_uint8 src_id,
	kal_uint8	input[MAX_DIGITS_USSD],
	kal_uint8	dcs,
	kal_uint8	length,
	kal_uint8	ip_string[21],
	kal_uint8	source_id,
        kal_uint8 call_type,
        kal_bool is_sim_operation) 
{
	l4c_ss_string_info_struct info;
	rmmi_string_struct string;
	string.index = 0;
	string.string_ptr = input;
	string.ip_string = ip_string; 

	#ifdef __UCM_SUPPORT__
		src_id = source_id;
		if(src_id>= RMMI_SRC && src_id <= RMMI_ALL)
		{
			string.string_ptr[length] = ';';
			length++;   
		}	
	#endif

	return l4c_ss_string_parsing(src_id,dcs,&string,length,&info, call_type, is_sim_operation);

}


kal_bool l4a_cc_exe_ata_req (kal_uint8 src_id,kal_uint8 source_id)
{
	#ifdef __UCM_SUPPORT__
		src_id = source_id;
	#endif
	
	return l4c_cc_exe_ata_req(src_id);
}

kal_bool l4a_cc_exe_ath_req (kal_uint8 src_id,l4c_ath_req_enum op_code,kal_uint8 source_id)
{
	#ifdef __UCM_SUPPORT__
		src_id = source_id;
	#endif
	
	return l4c_cc_exe_ath_req(src_id,op_code);
}

kal_bool l4a_cc_exe_chld_req (kal_uint8 src_id,
                                 kal_uint8 opcode,   /* csmcc_crss_req_enum */
                                 kal_uint8 call_id,
                                 kal_uint8 source_id)
{
	#ifdef __UCM_SUPPORT__
		src_id = source_id;
	#endif
	
	return l4c_cc_exe_chld_req(src_id, opcode, call_id);
}
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

/*
* FUNCTION                                                            
*	l4a_sat_send_ss_req
* DESCRIPTION                                                           
*	send ss string to l4c
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/

//mtk01616_070521
#ifdef __SAT__ 
kal_bool l4a_sat_send_ss_req (kal_uint8 src_id,
	kal_uint8	input[MAX_DIGITS_USSD],
	kal_uint8	dcs,
	kal_uint8	length,
	kal_uint8 type_of_modification)
{
	l4ccsm_ciss_ss_parse_req_struct* param_ptr= (l4ccsm_ciss_ss_parse_req_struct *)
                	        construct_local_para((kal_uint16)sizeof(l4ccsm_ciss_ss_parse_req_struct),
                                                TD_CTRL);
	
	if (dcs==0xf)
	{
		kal_uint8 input2[MAX_DIGITS_USSD];
		kal_uint8 length2;

		csmss_gsm7_unpack ((kal_uint8 *)input2,
                         (kal_uint8 *)input,
                         (kal_uint16)length,
                         0);
		if (((length % 7) == 0) && ((input[length-1] & 0xfe)==0x1a))
			length2 = length+length/8;
		else
			length2 = length+length/8+1;

		input2[length2]=0;
		input2[length2+1]=0;

	       param_ptr->src_id = SAT_SRC;
	       param_ptr->ton_npi = 0x81;
	       param_ptr->length = length2;
	       param_ptr->change_phase_req = KAL_FALSE;
	       param_ptr->ss_dcs = dcs;
	       kal_mem_set (param_ptr->ss_string, 0, MAX_DIGITS_USSD);
	       kal_mem_cpy (param_ptr->ss_string, input2, length2+1);
  	       param_ptr->type_of_modification = type_of_modification; //mtk01616_070521


		return l4c_sat_send_ss_req(param_ptr);
	}
	else if (dcs==0x01)
	{
		kal_uint8 addr_type = 0x81;
   		rmmi_string_struct temp;
      		kal_uint8 len;   

	   	input[length] = 0xff;
      		addr_type = input[0];
      		ASSERT((kal_uint16)(2*length) <2048);
      		temp.string_ptr = (kal_uint8 *)get_ctrl_buffer ((kal_uint16)(2*length));
	   	len = convert_to_digit_ext (input+1, temp.string_ptr);
	   	input = temp.string_ptr;
      		length = len;
	  
	       param_ptr->src_id = SAT_SRC;
	       param_ptr->ton_npi = addr_type;
	       param_ptr->length = len;
	       param_ptr->change_phase_req = KAL_FALSE;
	       param_ptr->ss_dcs = dcs;
	       kal_mem_set (param_ptr->ss_string, 0, MAX_DIGITS_USSD);
	       kal_mem_cpy (param_ptr->ss_string, input, len+1);	  
  	       param_ptr->type_of_modification = type_of_modification; //mtk01616_070521

		return l4c_sat_send_ss_req(param_ptr);	   
	}
	else
	{
	       param_ptr->src_id = SAT_SRC;
	       param_ptr->ton_npi = 0x81;
	       param_ptr->length = length;
	       param_ptr->change_phase_req = KAL_FALSE;
	       param_ptr->ss_dcs = dcs;
	       kal_mem_set (param_ptr->ss_string, 0, MAX_DIGITS_USSD);
	       kal_mem_cpy (param_ptr->ss_string, input, length+1);	 
	       param_ptr->type_of_modification = type_of_modification; //mtk01616_070521
		   
		return l4c_sat_send_ss_req(param_ptr);
	}
}
#endif
/*
* FUNCTION                                                            
*	l4a_set_timer_req
* DESCRIPTION                                                           
*	set timer to l4c
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_set_timer_req(void* timeout_hdlr, kal_uint16 time, void *param,eventid *id,void **ret_param)
{
	*ret_param = param;
	*id = l4c_set_timer_req(timeout_hdlr,time,param);
	return KAL_TRUE;
}
/*
* FUNCTION                                                            
*	l4a_eq_write_nvram_req
* DESCRIPTION                                                           
*	send write nvram request to l4c
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_eq_write_nvram_req(
								kal_uint8 src_id,
                                 kal_uint8 file_idx,
                                 kal_uint16 para,
                                 kal_uint16 length,
								 kal_uint8 *data)
{

	return l4c_eq_write_nvram_req(src_id,file_idx,para,data,length);
}
/*
* FUNCTION                                                            
*	l4a_smu_get_preferred_oper_list_req
* DESCRIPTION                                                           
*	send get preferred operator list request to l4c
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_smu_get_preferred_oper_list_req(kal_uint8 src_id, kal_uint8 index, kal_uint16 num, kal_uint16 file_idx_req, kal_uint16* retnum, kal_uint8* oper_list, kal_uint8* rat_list, kal_uint16* file_idx_rsp)
{
	*retnum = num;
	return l4c_smu_get_preferred_oper_list_req(src_id,index,file_idx_req,retnum,oper_list,rat_list,file_idx_rsp);
}

#ifdef __SAT__
#define STRUCT_ASSIGN_VALUE(DEST,MEMBER)     DEST.MEMBER = MEMBER
#define STRUCT_ASSIGN_ARRAY(DEST,MEMBER,LEN) memcpy(DEST.MEMBER,MEMBER,LEN)

/*
* FUNCTION                                                            
*	l4a_sat_dspl_text_res
* DESCRIPTION                                                           
*	simtoolkit display text res
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_dspl_text_res(
								kal_uint8 cmd_detail[5],
								kal_uint8 res,
								kal_uint8 additional_info)
{
	sat_dspl_text_res_struct l;

	STRUCT_ASSIGN_ARRAY(l,cmd_detail,5);
	STRUCT_ASSIGN_VALUE(l,res);
	STRUCT_ASSIGN_VALUE(l,additional_info);

	return l4c_sat_dspl_text_res(&l);
}
/*
* FUNCTION                                                            
*	l4a_sat_get_input_res
* DESCRIPTION                                                           
*	simtoolkit get input res
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_get_inkey_res(
									kal_uint8 cmd_detail[5],
									kal_uint8 res,
									kal_uint8 is_yes_selected,

									kal_uint8 dcs_of_text_string,
									kal_uint8 no_text_string,
									kal_uint8 text_string[1]
									)
{
	sat_get_inkey_res_struct l;
	sat_get_inkey_res_peer_struct p;

	STRUCT_ASSIGN_ARRAY(l,cmd_detail,5);
	STRUCT_ASSIGN_VALUE(l,res);	
	STRUCT_ASSIGN_VALUE(l,is_yes_selected);	
	STRUCT_ASSIGN_VALUE(p,dcs_of_text_string);	
	STRUCT_ASSIGN_VALUE(p,no_text_string);
	STRUCT_ASSIGN_VALUE(p,text_string);

	return l4c_sat_get_inkey_res(&l,&p);
}
/*
* FUNCTION                                                            
*	l4a_sat_get_input_res
* DESCRIPTION                                                           
*	simtoolkit get input res
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_get_input_res(
									kal_uint8 cmd_detail[5],
									kal_uint8 res,

									kal_uint8 dcs_of_text_string,
									kal_uint8 no_text_string,
									kal_uint8 text_string[1]
									)
{
	sat_get_input_res_struct l;
	sat_get_input_res_peer_struct p;

	STRUCT_ASSIGN_ARRAY(l,cmd_detail,5);
	STRUCT_ASSIGN_VALUE(l,res);	
	
	STRUCT_ASSIGN_VALUE(p,dcs_of_text_string);	
	STRUCT_ASSIGN_VALUE(p,no_text_string);
	STRUCT_ASSIGN_VALUE(p,text_string);

	return l4c_sat_get_input_res(&l,&p);
}
/*
* FUNCTION                                                            
*	l4a_sat_setup_menu_res
* DESCRIPTION                                                           
*	simtoolkit setup menu res
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_setup_menu_res(
									kal_uint8 cmd_detail[5],
									kal_uint8 res

								)
{
	sat_setup_menu_res_struct l;

	STRUCT_ASSIGN_ARRAY(l,cmd_detail,5);
	STRUCT_ASSIGN_VALUE(l,res);	

	return l4c_sat_setup_menu_res(&l);
}
/*
* FUNCTION                                                            
*	l4a_sat_select_item_res
* DESCRIPTION                                                           
*	simtoolkit select item res
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_select_item_res(
									kal_uint8 cmd_detail[5],
									kal_uint8 res,
									kal_uint8 item_id
								 )
{
	sat_select_item_res_struct l;

	STRUCT_ASSIGN_ARRAY(l,cmd_detail,5);
	STRUCT_ASSIGN_VALUE(l,res);	
	STRUCT_ASSIGN_VALUE(l,item_id);	

	return l4c_sat_select_item_res(&l);
}
/*
* FUNCTION                                                            
*	l4a_sat_play_tone_res
* DESCRIPTION                                                           
*	simtoolkit play tone res
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_play_tone_res(
									kal_uint8 cmd_detail[5],
									kal_uint8 res
								)
{
	sat_play_tone_res_struct l;

	STRUCT_ASSIGN_ARRAY(l,cmd_detail,5);
	STRUCT_ASSIGN_VALUE(l,res);		

	return l4c_sat_play_tone_res(&l);
}
/*
* FUNCTION                                                            
*	l4a_sat_exe_menu_select_req
* DESCRIPTION                                                           
*	simtoolkit execute the menu select request
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_exe_menu_select_req(
									 kal_uint8 item_id,
									 kal_uint8 is_help_info_requested
									 )
{
	sat_menu_select_req_struct l;

	STRUCT_ASSIGN_VALUE(l,item_id);
	STRUCT_ASSIGN_VALUE(l,is_help_info_requested);

	return l4c_sat_exe_menu_select_req(&l);
}
/*
* FUNCTION                                                            
*	l4a_sat_call_setup_req
* DESCRIPTION                                                           
*	simtoolkit call setup request
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
//mtk01616_070521
kal_bool l4a_sat_call_setup_req(
								kal_uint8 sat_call_type,
								kal_uint8 no_addr,
								kal_uint8 addr[41],
								kal_uint8 no_sub_addr,
								kal_uint8 sub_addr[21],
								kal_uint8 no_ccp,
								kal_uint8 ccp[15],
								kal_uint8 type_of_modification
								)
{
	kal_bool ret_val;
	l4ccsm_cc_sat_setup_req_struct *l= NULL;
	l  = get_ctrl_buffer((kal_uint16)sizeof(l4ccsm_cc_sat_setup_req_struct));

	l->src_id = SAT_SRC;
	l->sat_call_type = sat_call_type;

	l->called_sub_addr_present = (no_sub_addr)?1:0;

	l->called_sub_addr.sub_addr_len = no_sub_addr;
	memcpy(l->called_sub_addr.sub_addr,sub_addr,21);

	l->ccp_present = (no_ccp)?1:0;
	memcpy(l->ccp, ccp,15);
	l->size_of_ccp = no_ccp;

	////l->is_changed_from_ss = is_changed_from_ss;
       l->type_of_modification = type_of_modification; //mtk01616_070521

	l->l4c_retry = KAL_FALSE;

       if(no_addr > 0 && addr[0] == 0xa1)
	   	addr[0] = 0x81;
	   	
   ret_val = l4c_sat_call_setup_req(l, addr, (kal_uint16)no_addr);
   free_ctrl_buffer(l);
   
	return ret_val;
}
/*
* FUNCTION                                                            
*	l4a_sat_setup_call_res
* DESCRIPTION                                                           
*	simtoolkit setup call res
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_setup_call_res(
								kal_uint8 cmd_detail[5],
								kal_uint8 res,
								kal_uint8 cause
								)
{
	sat_setup_call_res_struct *l=(sat_setup_call_res_struct *)
				           construct_local_para((kal_uint16)sizeof(sat_setup_call_res_struct),
                                             TD_CTRL);
	memcpy(l->cmd_detail,cmd_detail,5);
	l->res = res;
	l->cause = cause;

	return l4c_sat_setup_call_res(l);
}
/*
* FUNCTION                                                            
*	l4a_sat_send_sms_req
* DESCRIPTION                                                           
*	simtoolkit send sms request
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_send_sms_req(
								kal_uint8 is_sms_packed_required,
								kal_uint8 no_addr,
								kal_uint8 addr[41],
								kal_uint8 tpdu_length,
								kal_uint8 tpdu[175]
							  )
{
	l4csmsal_sat_send_req_struct *l=(l4csmsal_sat_send_req_struct *)
				           construct_local_para((kal_uint16)sizeof(l4csmsal_sat_send_req_struct),
                                             TD_CTRL);
	l->src_id = SAT_SRC;
	l->is_sms_packed_required = is_sms_packed_required;
	l->sc_addr.addr_length = no_addr;
	memcpy(l->sc_addr.addr_bcd,addr,no_addr);

    l->tpdu_length = tpdu_length;
	memcpy(l->tpdu,tpdu,175);

	return l4c_sat_send_sms_req(l);
}
/*
* FUNCTION                                                            
*	l4a_sat_send_sms_res
* DESCRIPTION                                                           
*	simtoolkit send sms res
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_send_sms_res(
							  kal_uint8 cmd_detail[5],
							  kal_uint8 res,
							  kal_uint8 cause
							  )
{
	sat_send_sms_res_struct* l= (sat_send_sms_res_struct *)
				           construct_local_para((kal_uint16)sizeof(sat_send_sms_res_struct),
                                             TD_CTRL);
	memcpy(l->cmd_detail,cmd_detail,5);
	l->res = res;
	l->cause = cause;

	return l4c_sat_send_sms_res(l);
}
/*
* FUNCTION                                                            
*	l4a_sat_send_ss_res
* DESCRIPTION                                                           
*	simtoolkit send ss string res
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_send_ss_res(
							 kal_uint8 cmd_detail[5],
							 kal_uint8 res,
							 kal_uint8 size_of_additional_info,
							 kal_uint8 additional_info[255]
							 )
{
	sat_send_ss_res_struct* l= (sat_send_ss_res_struct *)
				           construct_local_para((kal_uint16)sizeof(sat_send_ss_res_struct),
                                             TD_CTRL);
	memcpy(l->cmd_detail,cmd_detail,5);
	l->res = res;
	l->size_of_additional_info = size_of_additional_info;
	memcpy(l->additional_info,additional_info,255);

	return l4c_sat_send_ss_res(l);
}
//paul, ussd
/*
* FUNCTION                                                            
*	l4a_sat_send_ussd_req
* DESCRIPTION                                                           
*	simtoolkit send ussd string request
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
//mtk01616_070521
kal_bool l4a_sat_send_ussd_req(
	kal_uint8	input[MAX_DIGITS_USSD],
	kal_uint8	dcs,
	kal_uint8	length,
	kal_uint8 type_of_modification)
{
	//mtk01616  070410 : sat_ussd use l4ccsm_ciss_ss_parse_req instead of l4ccsm_ciss_pussr_begin_req

	l4ccsm_ciss_ss_parse_req_struct* l= (l4ccsm_ciss_ss_parse_req_struct *)
                	        construct_local_para((kal_uint16)sizeof(l4ccsm_ciss_ss_parse_req_struct),
                                                TD_CTRL);

	// ss_parse_req didn't expect SAT ussd string in 7bit pack format
       kal_uint8 lang_type;
       smsal_dcs_enum alphabet_type;
       smsal_msg_class_enum mclass;
       kal_bool is_compress;
       kal_bool is_reserved;

       smsal_decode_cbsdcs(dcs,
                                    &lang_type, &alphabet_type, &mclass,
                                    &is_compress, &is_reserved);               

  	kal_prompt_trace(l4c_current_mod_id,"alphabet_type=%d",alphabet_type);

	if ( alphabet_type == SMSAL_DEFAULT_DCS)
       {
       	 kal_prompt_trace(l4c_current_mod_id,"Do gsm7_unpack");
               csmss_gsm7_unpack((kal_uint8*)l->ss_string, (kal_uint8*)input,
    		 	(kal_uint16)length, 0);

               if (length % 7 == 0 && (input[length-1] & 0x7f) == 0x1A)
               {
                  length = (kal_uint8)length * 8 / 7 - 1;
               }
               else
               {
                  length = (kal_uint8)length  * 8 / 7;								
               }
        }
	else{	
		memcpy(l->ss_string,input,length);
	}
	
	l->ton_npi = 0x81;
	l->src_id = SAT_SRC;
	l->ss_dcs = dcs;
	l->ss_string[length] = 0;
	l->ss_string[length+1] = 0;
       l->length = length;
    l->change_phase_req = KAL_FALSE;
       l->type_of_modification = type_of_modification; //mtk01616_070521
    
	return l4c_sat_send_ussd_req(l);
}

/*
* FUNCTION                                                            
*	l4a_sat_send_ussd_res
* DESCRIPTION                                                           
*	simtoolkit send ussd string res
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_send_ussd_res(
							  kal_uint8 cmd_detail[5],
							  kal_uint8 res,
							 kal_uint8 size_of_additional_info,
							 kal_uint8 additional_info[255]
							   )
{
	sat_send_ussd_res_struct* l= (sat_send_ussd_res_struct *)
				           construct_local_para((kal_uint16)sizeof(sat_send_ussd_res_struct),
                                             TD_CTRL);
	memcpy(l->cmd_detail,cmd_detail,5);
	l->res = res;
	l->size_of_additional_info = size_of_additional_info;
	kal_mem_cpy(l->additional_info, additional_info, size_of_additional_info);

	return l4c_sat_send_ussd_res(l);
}

/*
* FUNCTION                                                            
*	l4a_sat_setup_idle_dspl_res
* DESCRIPTION                                                           
*	simtoolkit setup idle screen display res
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_setup_idle_dspl_res(
									kal_uint8 cmd_detail[5],
									kal_uint8 res
								)
{
	sat_setup_idle_dspl_res_struct* l= (sat_setup_idle_dspl_res_struct *)
				           construct_local_para((kal_uint16)sizeof(sat_setup_idle_dspl_res_struct),
                                             TD_CTRL);

	memcpy(l->cmd_detail, cmd_detail, 5);
	l->res = res;

	return l4c_sat_setup_idle_dspl_res(l);
}
/*
* FUNCTION                                                            
*	l4a_sat_run_at_command_res
* DESCRIPTION                                                           
*	simtoolkit run at command res
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_run_at_command_res(
									kal_uint8 cmd_detail[5],
									kal_uint8 res,
									kal_uint8 size_of_at_response,
									kal_uint8 at_response[240]
									)
{
	sat_run_at_command_res_struct* l= (sat_run_at_command_res_struct *)
				           construct_local_para((kal_uint16)sizeof(sat_run_at_command_res_struct),
                                             TD_CTRL);

	memcpy(l->cmd_detail, cmd_detail, 5);
	l->res = res;
	l->size_of_at_response = size_of_at_response;
	memcpy(l->at_response, at_response, 240);

	return l4c_sat_run_at_command_res(l);
}
/*
* FUNCTION                                                            
*	l4a_sat_lang_notify_res
* DESCRIPTION                                                           
*	simtoolkit language notify res
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_lang_notify_res(
									kal_uint8 cmd_detail[5],
									kal_uint8 res
								)
{
	sat_lang_notify_res_struct* l= (sat_lang_notify_res_struct *)
				           construct_local_para((kal_uint16)sizeof(sat_lang_notify_res_struct),
                                             TD_CTRL);

	memcpy(l->cmd_detail, cmd_detail, 5);
	l->res = res;

	return l4c_sat_lang_notify_res(l);
}


#endif // __SAT__

/*
* FUNCTION                                                            
*	l4a_eq_exe_volume_req
* DESCRIPTION                                                           
*	send execute volume request to l4c
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_eq_exe_volume_req(kal_uint8 src_id,
                                kal_uint8 volume_type,
                                kal_uint8 volume_level,
								kal_uint8 *ret_volume_type)
{
	*ret_volume_type = volume_type;
	return l4c_eq_exe_volume_req(src_id,volume_type,volume_level);
}
/*
* FUNCTION                                                            
*	l4a_eq_exe_mute_mode_req
* DESCRIPTION                                                           
*	send execute mute volume request
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_eq_exe_mute_mode_req(kal_uint8 src_id, kal_uint8 audio_device, kal_bool mute_onoff,kal_uint8 *ret_audio_device)
{
	*ret_audio_device = audio_device;
	return l4c_eq_exe_mute_req(src_id,audio_device,mute_onoff);
}

#endif



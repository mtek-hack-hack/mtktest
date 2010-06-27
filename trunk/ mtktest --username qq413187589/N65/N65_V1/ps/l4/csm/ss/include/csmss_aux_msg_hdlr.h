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
 *
 * Filename:
 * ---------
 *	csmss_aux_msg_hdlr.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for aux. handler of messages from L4C and SS.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef _CSMSS_AUX_MSG_HDLR_H
#define _CSMSS_AUX_MSG_HDLR_H

#ifdef __MCD__

kal_int8 csmss_get_free_call_id(void);
void csmss_free_call_id(kal_uint8 call_id);
void csmss_mark_call_id(kal_uint8 call_id);
void csmss_send_ilm(kal_uint8 dest_id, kal_uint16 msg_id, void *local_para,
                    void *peer_buff);

extern kal_uint8 csmss_get_default_priority_level(void);

void csmss_init_ss_return(ss_return_struct *ss_return);

#ifdef __CPHS__
extern void csmss_cphs_start_hdlr(void);
void csmss_send_sim_read_req(kal_uint8 file_idx, kal_uint16 file_len);
void csmss_send_sim_write_req(kal_uint8 file_idx, kal_uint16 file_len,
                              kal_uint8 *data_ptr);
void csmss_send_sim_file_info_req(kal_uint8 file_idx, kal_uint8 info_type);
#endif

typedef struct
{
    kal_uint16 index;
    kal_uint8 *string_ptr;
} csmss_string_struct;

typedef struct
{
    csmss_string_op_enum opcode;
    csmss_string_struct addr;
} csmss_ss_string_info_struct;

typedef struct
{
    kal_uint8 type;
    kal_uint8 length;
    kal_uint8 number[MAX_CC_ADDR_LEN];
} csmss_number_struct;

typedef csmss_number_struct csmss_sub_addr_struct;

#define csmss_skip_spaces(source_string_ptr)                              \
while( source_string_ptr->string_ptr[ source_string_ptr->index ]    \
== RMMI_SPACE )                          \
{                                                                   \
source_string_ptr->index++;                                       \
}

csmss_string_op_enum is_ss_string(kal_uint8 src_id, kal_uint8 ton_npi,
                                  kal_uint8 length, csmss_string_struct *input);

csmss_string_op_enum process_registration(kal_uint8 src_id, kal_uint8 ton_npi,
    kal_uint8 length, csmss_string_struct *input);

csmss_string_op_enum process_interrogation(kal_uint8 src_id, kal_uint8 ton_npi,
    kal_uint8 length, csmss_string_struct *input);

csmss_string_op_enum process_act_deact(kal_uint8 src_id, kal_uint8 ton_npi,
                                       kal_uint8 length, csmss_string_struct
                                       *input, kal_uint8 op_code);

csmss_string_op_enum process_erasure(kal_uint8 src_id, kal_uint8 ton_npi,
                                     kal_uint8 length, csmss_string_struct
                                     *input);

csmss_string_op_enum process_register_password(kal_uint8 src_id, kal_uint8
    ton_npi, kal_uint8 length, csmss_string_struct *input);

csmss_string_op_enum setup_call_forward_struct(kal_uint8 src_id, kal_uint8
    ton_npi, csmss_string_struct *input, kal_uint8 op_code, kal_uint8 ss_code);

csmss_string_op_enum setup_call_barring_struct(kal_uint8 src_id, kal_uint8
    ton_npi, csmss_string_struct *input, kal_uint8 op_code, kal_uint8 ss_code);

csmss_string_op_enum setup_call_waiting_struct(kal_uint8 src_id, kal_uint8
    ton_npi, csmss_string_struct *input, kal_uint8 op_code);

csmss_string_op_enum setup_interrogate_struct(kal_uint8 src_id, kal_uint8
    ton_npi, csmss_string_struct *input, kal_uint8 ss_code);

csmss_string_op_enum setup_emlpp_struct(kal_uint8 src_id, kal_uint8 ton_npi,
                                        csmss_string_struct *input, kal_uint8
                                        ss_code, kal_uint8 priority);

csmss_string_op_enum setup_ussd_struct(kal_uint8 src_id, kal_uint8 ton_npi,
                                       csmss_string_struct *input);

csmss_string_op_enum setup_ccbs_struct(kal_uint8 src_id, kal_uint8
    ton_npi, csmss_string_struct *input, kal_uint8 op_code);

ss_code_enum csmss_convert_l4_ss_code(l4_ss_code_enum l4_ss);
void csmss_convert_l4_bs_code(l4_bs_code_enum l4_bs, BasicServiceCode *bsc);

l4_ss_code_enum csmss_convert_ss_code_l4(ss_code_enum ss);
l4_bs_code_enum csmss_convert_bs_code_l4(BasicServiceCode *bs);

kal_bool csmss_ss_src_req(kal_uint8 src_id, kal_uint8 ton_npi, csmss_string_struct *input, csmss_string_op_enum *ret);

csmss_string_op_enum csmss_ss_src_ussd_req(kal_uint8 src_id, kal_uint8 ton_npi,
    csmss_string_struct *input);

void csmss_send_ss_ctrl_req(kal_uint8 type, kal_uint8 ton_npi, kal_uint8
                            ss_string[MAX_DIGITS_USSD]);

void csmss_send_ss_parse_cnf(kal_uint8 src_id, kal_uint8 op_code, kal_uint8
                             ss_string[MAX_DIGITS_USSD]);

csmss_string_op_enum csmss_ss_exe_call_forward_req(kal_uint8 src_id, kal_uint8
    op_code, kal_uint8 ss_code, kal_uint8 bs_code, kal_uint8 no_reply_timer,
    l4_addr_bcd_struct address, kal_bool subaddress_flag, l4_addr_bcd_struct
    subaddress);

csmss_string_op_enum csmss_ss_exe_call_wait_req(kal_uint8 src_id, kal_uint8
    op_code, kal_uint8 bs_code);

csmss_string_op_enum csmss_ss_exe_call_barring_req(kal_uint8 src_id, kal_uint8
    op_code, kal_uint8 ss_code, kal_uint8 bs_code, kal_uint8 old_pw[4],
    kal_uint8 new_pw1[4], kal_uint8 new_pw2[4]);

csmss_string_op_enum csmss_ss_exe_emlpp_req(kal_uint8 src_id, kal_uint8 op_code,
    kal_uint8 default_priority_level);

csmss_string_op_enum csmss_ss_exe_cli_req(kal_uint8 src_id, kal_uint8
    ss_code);

csmss_string_op_enum csmss_ss_exe_ccbs_req(kal_uint8 src_id, kal_uint8 op_code,
    kal_uint8 ccbs_index);

csmss_string_op_enum csmss_ss_exe_ussd_req(kal_uint8 src_id, kal_uint8
    *ussd_string, kal_uint8 ussd_len, kal_uint8 op_code);

void csmss_gsm7_unpack(kal_uint8 *unpacked_data, kal_uint8 *packed_data,
                       kal_uint16 data_len, kal_uint16 offset);

void csmss_gsm7_pack(kal_uint8 *packed_data, kal_uint8 *unpacked_data,
                     kal_uint16 data_len, kal_uint16 offset);

void csmss_pack(kal_uint16 msgid, kal_uint8 *parameter, Component *comp);

#define CSMSS_MCD_VAR_START(STRUCT, MSG) \
STRUCT *MSG = get_ctrl_buffer (sizeof(STRUCT)); \
kal_mem_set (MSG, 0, sizeof(STRUCT));

#define CSMSS_MCD_VAR_END(MSG) \
free_ctrl_buffer (MSG);

#define CSMSS_ALLOC_SS_CODE(SS_CODE, SS) \
SS_CODE = get_ctrl_buffer (sizeof(SS_Code)); \
SS_CODE->octs[0] = (kal_uint8)csmss_convert_l4_ss_code ((l4_ss_code_enum)SS);

#define CSMSS_DEALLOC_SS_CODE(SS_CODE) \
free_ctrl_buffer (SS_CODE);

#define CSMSS_ALLOC_BASICSERVICE(BASICSERVICE) \
if (bs_code != 0) { \
BASICSERVICE##Opt = KAL_TRUE; \
BASICSERVICE = get_ctrl_buffer (sizeof(BasicServiceCode)); \
kal_mem_set(BASICSERVICE, 0, sizeof(BasicServiceCode)); \
csmss_convert_l4_bs_code ((l4_bs_code_enum)bs_code, BASICSERVICE); \
} else \
BASICSERVICE##Opt = KAL_FALSE;

#define CSMSS_DEALLOC_BASICSERVICE(BASICSERVICE) \
if (BASICSERVICE##Opt == KAL_TRUE) { \
if (BASICSERVICE->teleserviceOpt == KAL_TRUE) \
free_ctrl_buffer(BASICSERVICE->teleservice); \
else if (BASICSERVICE->bearerServiceOpt == KAL_TRUE) \
free_ctrl_buffer(BASICSERVICE->bearerService); \
free_ctrl_buffer (BASICSERVICE); \
}

#define CSMSS_ALLOC_ADDR(ADDR) \
if (address.addr_length > 1) { \
ADDR##Opt = KAL_TRUE; \
ADDR = get_ctrl_buffer (sizeof(AddressString)); \
ADDR->octsLen = address.addr_length; \
ADDR->octs = get_ctrl_buffer (address.addr_length); \
kal_mem_cpy (ADDR->octs, address.addr_bcd, address.addr_length); \
} else \
ADDR##Opt = KAL_FALSE;

#define CSMSS_DEALLOC_ADDR(ADDR) \
if (ADDR##Opt == KAL_TRUE) { \
free_ctrl_buffer (ADDR->octs); \
free_ctrl_buffer (ADDR); \
}

#define CSMSS_ALLOC_SUBADDR(SUBADDR) \
if (subaddress_flag != KAL_FALSE) { \
SUBADDR##Opt = KAL_TRUE; \
SUBADDR = get_ctrl_buffer (sizeof(ISDN_SubaddressString)); \
SUBADDR->octsLen = subaddress.addr_length; \
SUBADDR->octs = get_ctrl_buffer (subaddress.addr_length); \
kal_mem_cpy (SUBADDR->octs, subaddress.addr_bcd, subaddress.addr_length); \
} else \
SUBADDR##Opt = KAL_FALSE;

#define CSMSS_DEALLOC_SUBADDR(SUBADDR) \
if (SUBADDR##Opt == KAL_TRUE) { \
free_ctrl_buffer (SUBADDR->octs); \
free_ctrl_buffer (SUBADDR); \
}

#define CSMSS_ALLOC_TIMER(TIMER) \
if (no_reply_timer != 0) { \
TIMER##Opt = KAL_TRUE; \
TIMER = get_ctrl_buffer (sizeof(NoReplyConditionTime)); \
TIMER->value = no_reply_timer; \
} else \
TIMER##Opt  = KAL_FALSE;

#define CSMSS_DEALLOC_TIMER(TIMER) \
if (TIMER##Opt == KAL_TRUE) { \
free_ctrl_buffer (TIMER); \
}

#define CSMSS_ALLOC_DPL(DPL) \
if (default_priority_level != 0xff) { \
DPL##Opt = KAL_TRUE; \
DPL = get_ctrl_buffer (sizeof(EMLPP_Priority)); \
DPL->value = default_priority_level; \
} else \
DPL##Opt = KAL_FALSE;

#define CSMSS_DEALLOC_DPL(DPL) \
if (DPL##Opt == KAL_TRUE) { \
free_ctrl_buffer (DPL); \
}

#define CSMSS_ALLOC_CCBS_INDEX(CCBS_INDEX) \
if (ccbs_index != 0xff) { \
CCBS_INDEX##Opt = KAL_TRUE; \
CCBS_INDEX = get_ctrl_buffer (sizeof(CCBS_Index)); \
CCBS_INDEX->value = ccbs_index; \
} else \
CCBS_INDEX##Opt = KAL_FALSE;

#define CSMSS_DEALLOC_CCBS_INDEX(CCBS_INDEX) \
if (CCBS_INDEX##Opt == KAL_TRUE) { \
free_ctrl_buffer (CCBS_INDEX); \
}

#define CSMSS_ALLOC_USSD_DCS(USSD_DCS) \
USSD_DCS = get_ctrl_buffer (sizeof(USSD_DataCodingScheme)); \
USSD_DCS->octs[0] = csmss_ptr_g->ussd_dcs;

#define CSMSS_DEALLOC_USSD_DCS(USSD_DCS) \
free_ctrl_buffer (USSD_DCS);

#define CSMSS_ALLOC_USSD_STRING(USSD_STRING, LEN) \
USSD_STRING = get_ctrl_buffer (sizeof(USSD_String)); \
USSD_STRING->octsLen = LEN; \
USSD_STRING->octs = get_ctrl_buffer (LEN);

#define CSMSS_DEALLOC_USSD_STRING(USSD_STRING) \
free_ctrl_buffer (USSD_STRING->octs); \
free_ctrl_buffer (USSD_STRING);

#define CSMSS_ALLOC_USSDIA5(USSDIA5, LEN) \
USSDIA5->octsLen = LEN; \
USSDIA5->octs = get_ctrl_buffer (LEN);

#define CSMSS_DEALLOC_USSDIA5(USSDIA5) \
free_ctrl_buffer (USSDIA5->octs);

#define CSMSS_ALLOC_PW(PW) \
Password *PW = get_ctrl_buffer(sizeof(Password));

#define CSMSS_DEALLOC_PW(PW) \
free_ctrl_buffer (PW);

#define CSMSS_ALLOC_COMP(COMP) \
COMP = get_ctrl_buffer (sizeof(Component)); \
kal_mem_set (COMP, 0, (sizeof(Component)));

#define CSMSS_ALLOC_COMPSTRUCT(COMP, COMPSTRUCT) \
COMP##Opt = KAL_TRUE; \
COMP = get_ctrl_buffer (sizeof(COMPSTRUCT)); \
kal_mem_set (COMP, 0, sizeof (COMPSTRUCT));

#define CSMSS_FILL_INVOKEID(COMP, VALUE) \
COMP->invokeID = get_ctrl_buffer (sizeof(InvokeIdType)); \
COMP->invokeID->value = VALUE;

#define CSMSS_FILL_LINEDID_NOT(COMP) \
COMP->linkedIDOpt = KAL_FALSE;

#define CSMSS_FILL_OPCODE(COMP, OPCODE) \
COMP->localValueOpt = KAL_TRUE; \
COMP->localValue = OPCODE;

#define CSMSS_FILL_ERROR(COMP, ERROR) \
COMP->localValueOpt = KAL_TRUE; \
COMP->localValue = ERROR;

#define CSMSS_FILL_PARAOPT(COMP, OPT) \
COMP->parameterOpt = OPT;

#define CSMSS_FILL_RESULTOPT(COMP, OPT) \
COMP->resultOpt = OPT;

#define CSMSS_MCD_PUN_START(STRUCT, MSG) \
STRUCT *MSG = NULL;
/*
#define CSMSS_MCD_PUN_STOP(MSG) \
free_ctrl_buffer(MSG);

#define CSMSS_MCD_UNPACK(STRUCTID, MSG, PEER_BUFF, PEER_LEN) \
{ \
kal_uint32  ret_val; \
ret_val = mcd_unpack(STRUCTID, \
(kal_uint32*) MSG, \
0, \
(kal_uint32*)PEER_BUFF, \
PEER_LEN*8); \
ASSERT(ret_val != MCD_ERROR) \
}
 */
#define CSMSS_GET_USSD_DCS(USSD_DCS) \
msg_ptr->ussd_dcs = USSD_DCS->octs[0];

#define CSMSS_GET_USSD_STRING(USSD_STRING) \
kal_mem_cpy (msg_ptr->ussd_string, USSD_STRING->octs, USSD_STRING->octsLen);

#else /* __MCD__ */
;
#endif /* __MCD__ */

#endif /* End of file csmss_aux_msg_hdlr.h */



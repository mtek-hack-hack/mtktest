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
 *	l4c_ciss_cmd.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _L4C_CISS_CMD_H
#define _L4C_CISS_CMD_H

extern kal_bool l4c_ss_exe_emlpp_req (kal_uint8 src_id,
                                  kal_uint8 opcode,    /* op_code_enum*/
                                  kal_uint8 priority);

extern kal_bool l4c_ss_exe_repeat_CCFC_req(kal_uint8 src_id, 
                                  kal_uint8 mode,   /* op_code_enum */
                                  kal_uint8 reason,     /* ss_code_enum */
                                  kal_uint8 bs_code,  /* (class) bs_code_enum */
                                  kal_uint8 timer,
                                  l4c_number_struct dest,
                                  kal_bool sub_addr_flag,
                                  l4c_sub_addr_struct sub_dest);

extern kal_bool l4c_ss_exe_call_forward_req (kal_uint8 src_id,
                                         kal_uint8 opcode,  /* op_code_enum */
                                         kal_uint8 type,    /* ss_code_enum */
                                         kal_uint8 bs_code, /* bs_code_enum */
                                         kal_uint8 timer,
                                         l4c_number_struct dest,
                                         kal_bool  sub_addr_flag,
                                         l4c_sub_addr_struct sub_dest);

extern kal_bool l4c_ss_exe_repeat_CCWA_req(kal_uint8 src_id, kal_uint8 mode,  /* op_code_enum */
kal_uint8 classx  /* (class) bs_code_enum */
);

extern kal_bool l4c_ss_exe_call_wait_req (kal_uint8 src_id,
                                      kal_uint8 opcode,     /* op_code_enum */
                                      kal_uint8 bs_code);   /* bs_code_enum */

extern kal_bool l4c_ss_exe_interrogate_req (kal_uint8 src_id,
                                           kal_uint8 type);

extern kal_bool l4c_ss_exe_repeat_CLCK_SS_req(kal_uint8 src_id, kal_uint8 mode,  /* op_code_enum */
kal_uint8 reason,  /* ss_code_enum */
kal_uint8 classx,  /* (class) bs_code_enum */
kal_uint8 *passwd);

extern kal_bool l4c_ss_exe_call_barring_req (kal_uint8 src_id,
                                         kal_uint8 opcode,  /* op_code_enum */
                                         kal_uint8 type,    /* ss_code_enum */
                                         kal_uint8 bs_code,
                                         kal_uint8 *passwd);

extern kal_bool l4c_ss_get_priority_status_req (kal_uint8 src_id,
                                                kal_uint8 *priority);

extern kal_bool l4c_ss_set_clir_flag_req (kal_uint8 src_id,
                                         kal_uint8 clir_flag);/* rmmi_clir_enum */

extern kal_bool l4c_ss_exe_change_password_req (kal_uint8 src_id,
                                            kal_uint8 type, /* ss_code_enum */
                                            kal_uint8 *old,
                                            kal_uint8 *new1,
                                            kal_uint8 *new2);

extern kal_bool l4c_ss_exe_ussd_req (kal_uint8 src_id,
                                 kal_uint8 *str,
                                 kal_uint8 dcs,
                                 kal_uint8 length);

extern kal_bool l4c_ss_exe_ccbs_req (kal_uint8 src_id,
                              kal_uint8 op_code,kal_uint8 index);

extern kal_bool l4c_ss_exe_abort_req (kal_uint8 src_id);
#endif



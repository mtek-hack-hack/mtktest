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
 *	l4c_phb_cmd.h
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


#ifndef _L4C_PHB_CMD_H
#define _L4C_PHB_CMD_H

extern kal_bool l4c_phb_get_entry_by_text_req (kal_uint8 src_id,
                                               kal_uint8 type,
                                               kal_uint16 no_data,
                                    l4_name_struct *name);  

extern kal_bool l4c_phb_sms_fdn_check_req (kal_uint8 src_id,
                                         l4_addr_bcd_struct sc_addr,
                                         l4_addr_bcd_struct da);

extern kal_bool l4c_phb_get_entry_by_prefix_text_req (kal_uint8 src_id,
                                        kal_uint8 type,
                                        kal_uint16 no_data,
                                    l4_name_struct *name);     

extern kal_bool l4c_phb_get_entry_by_index_req (kal_uint8 src_id,
                                                kal_uint8 type,
                                                kal_uint8 storage,
                                                kal_uint16 index,
                                                kal_uint16 record_index,
                                                kal_uint16 no_data);

extern kal_bool l4c_phb_get_entry_by_range_req (kal_uint8 src_id,
                                         kal_uint8 type,
                                         kal_uint8 storage,
                                     kal_uint16 index,
                                     kal_uint16 record_index,
                                     kal_uint16 record_index_end,
                                     kal_uint16 no_data);

extern kal_bool l4c_phb_set_storage_req (kal_uint8 src_id,
                                         kal_uint8 storage);

extern kal_bool l4c_phb_get_storage_req (kal_uint8 src_id,
                                         kal_uint8 *storage,
                                         kal_uint16 *used,
                                         kal_uint16 *total);

extern kal_bool l4c_phb_get_storage_info (kal_uint8 src_id,
                                     kal_uint8 rmmi_storage,
                                     kal_uint16 *used,
                                     kal_uint16 *total);

extern kal_bool l4c_phb_get_type_status_req (kal_uint8 src_id,
                                     kal_uint8 type,
                                     kal_uint16 *used,
                                     kal_uint16 *total);

extern kal_bool l4c_phb_exe_write_entry_req (kal_uint8 src_id,
                                             kal_uint8 type,
                                             kal_uint16 no_data,
                                         l4c_phb_entry_struct *list);

extern kal_bool l4c_phb_exe_delete_entry_req (kal_uint8 src_id,
                                              kal_uint8 type,
                                       kal_uint16 index,
                                       kal_uint8 no_data,
                                       kal_uint8 storage,
                                       kal_bool del_all);

extern kal_bool l4c_phb_exe_read_ln_entry_req (kal_uint8 src_id,
								  kal_uint8 type,
								  kal_uint8 seq_id);

extern kal_bool l4c_phb_exe_delete_ln_entry_req (kal_uint8 src_id,
								  kal_uint8 type,
								  kal_uint8 index,
								  kal_uint8 no_data);

extern kal_bool l4c_phb_exe_write_ln_entry_req (kal_uint8 src_id,
                                   kal_uint8 type,
                                   kal_uint8 no_data,
                                   kal_uint8 index,
                                   l4c_phb_ln_entry_struct *entry);

extern kal_bool l4c_phb_set_voice_mail_server_req (kal_uint8 src_id,
                                               l4c_number_struct number);

extern kal_bool l4c_phb_get_alpha_list_req (kal_uint8 type,
                                     kal_uint16 *list);

extern kal_bool l4c_phb_startup_read_next_req (kal_uint8 access_id);

extern void l4c_phb_update(void);

extern kal_bool l4c_phb_startup_read_next_usim_field_req (kal_uint8 src_id,
                                                   kal_uint8 access_id);

extern kal_bool l4c_phb_read_email_req (kal_uint8 src_id,
                                 kal_uint16 record_index,
                                 kal_uint16 no_data);
                                 
extern kal_bool l4c_phb_set_grp_req (kal_uint8 src_id,
                              kal_uint16 record_index,
                              kal_uint8 group_type);
                              
extern kal_bool l4c_phb_write_usim_req (kal_uint8 src_id,
                                      kal_uint8 type,
                                      kal_uint16 no_data,
                                      l4c_phb_entry_struct* list,
                                      kal_uint8 update_field,
                                      l4c_phb_anr_struct anra,
                                      l4c_phb_anr_struct anrb,
                                      l4c_phb_anr_struct anrc,
                                      l4c_phb_email_struct email,
                                      l4_name_struct sne,
                                      kal_uint8 group_type,
                                      kal_uint8 hidden_info);
#endif /* l4c_phb_cmd.h */



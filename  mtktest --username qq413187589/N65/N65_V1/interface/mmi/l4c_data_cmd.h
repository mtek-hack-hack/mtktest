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
 *	l4c_data_cmd.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _L4C_DATA_CMD_H
#define _L4C_DATA_CMD_H

#ifdef __MOD_DATA__
extern kal_bool l4c_df_set_rlp_params_req (kal_uint8 src_id,
                                    kal_uint8 iws,
                                    kal_uint8 mws,
                                    kal_uint8 t1,
                                    kal_uint8 n2,
                                    kal_uint8 ver,
                                    kal_uint8 t4);

extern kal_bool l4c_df_get_rlp_params_req (kal_uint8 src_id);

extern kal_bool l4c_df_set_v120_params_req (kal_uint8 src_id,
                                     kal_uint8 rah,
                                     kal_uint8 mfm,
                                     kal_uint8 mode,
                                     kal_uint8 llineg,
                                     kal_uint8 assign,
                                     kal_uint8 neg_type);

extern kal_bool l4c_df_get_v120_params_req (kal_uint8 src_id,
                                     kal_uint8 *rah,
                                     kal_uint8 *mfm,
                                     kal_uint8 *mode,
                                     kal_uint8 *llineg,
                                     kal_uint8 *assign,
                                     kal_uint8 *neg_type);

extern kal_bool l4c_df_set_comp_params_req (kal_uint8 src_id,
                                     kal_uint8 dir,
                                     kal_uint8 comp_neg,
                                     kal_uint16 max_dict,
                                     kal_uint8 max_str);

extern kal_bool l4c_df_get_comp_params_req (kal_uint8 src_id,
                                     kal_uint8 *dir,
                                     kal_uint8 *comp_neg,
                                     kal_uint16 *max_dict,
                                     kal_uint8 *max_str);

extern kal_bool l4c_df_set_bearer_mode_req (kal_uint8 src_id,
                                     kal_uint8 bearer);

extern kal_bool l4c_df_get_bearer_mode_req (kal_uint8 src_id,
                                     kal_uint8 *bearer);

extern kal_bool l4c_df_set_char_framing_req (kal_uint8 src_id,
                                      kal_uint8 format,
                                      kal_uint8 parity);

extern kal_bool l4c_df_get_char_framing_req (kal_uint8 src_id,
                                      kal_uint8 *format,
                                      kal_uint8 *parity);

#endif

extern kal_bool l4c_df_exe_back_data_state_req (kal_uint8 src_id);

#endif



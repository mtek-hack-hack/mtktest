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
 *	csmcc_bc_types.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for type definition of bearer capability, low level 
 *   compatability, and high level compatibility.
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


#ifndef _CSMCC_BC_TYPES_H
#define _CSMCC_BC_TYPES_H

typedef struct {
    kal_uint8 speech_version_ind;
    kal_uint8 CTM;
} csmcc_bc_octet3a_struct;

typedef struct {
    kal_uint8 compress;
    kal_uint8 structure;
    kal_uint8 duplex_mode;
    kal_uint8 configuration;
    kal_uint8 NIRR;
    kal_uint8 establishment;
} csmcc_bc_octet4_struct;

typedef struct {
    kal_uint8 rate_adaption;
    kal_uint8 siganaling_access_protocol;
} csmcc_bc_octet5_struct;

typedef struct {
    kal_uint8 other_ITC;
    kal_uint8 other_rate_adaption;
} csmcc_bc_octet5a_struct;

typedef struct {
    kal_uint8 hdr_or_no_hdr;
    kal_uint8 multi_frame;
    kal_uint8 mode;
    kal_uint8 LLI;
    kal_uint8 assignor;
    kal_uint8 inband_negotiation;
} csmcc_bc_octet5b_struct;

typedef struct {
    kal_uint8 user_info_layer1_protocol;
    kal_uint8 sync_or_async;
} csmcc_bc_octet6_struct;

typedef struct {
    kal_uint8 number_stop_bits;
    kal_uint8 negotiation;
    kal_uint8 number_data_bits;
    kal_uint8 user_rate;
} csmcc_bc_octet6a_struct;

typedef struct {
    kal_uint8 intermediate_rate;
    kal_uint8 NIC_on_TX;
    kal_uint8 NIC_on_RX;
    kal_uint8 parity;
} csmcc_bc_octet6b_struct;

typedef struct {
    kal_uint8 connection_element;
    kal_uint8 modem_type;
} csmcc_bc_octet6c_struct;

typedef struct {
    kal_uint8 other_modem_type;
    kal_uint8 fixed_network_user_rate;
} csmcc_bc_octet6d_struct;

typedef struct {
    kal_uint8 accptable_channel_coding;
    kal_uint8 max_num_traffic_channels;
} csmcc_bc_octet6e_struct;

typedef struct {
    kal_uint8 UIMI;
    kal_uint8 wanted_air_interface_user_rate;
} csmcc_bc_octet6f_struct;

typedef struct {
    kal_uint8 accptable_channel_coding_ext;
    kal_uint8 asymmetry_ind;
} csmcc_bc_octet6g_struct;

typedef struct {
    kal_uint8 user_info_layer2_protocol;
} csmcc_bc_octet7_struct;

typedef struct {
    kal_uint8 radio_chanl_req;
    kal_uint8 transfer_mode;
    kal_uint8 itc;
    kal_uint8 num_octet3a;
    csmcc_bc_octet3a_struct octet3a[5];
    kal_uint8 octet4_present;
    csmcc_bc_octet4_struct octet4;
    kal_uint8 octet5_present;
    csmcc_bc_octet5_struct octet5;
    kal_uint8 octet5a_present;
    csmcc_bc_octet5a_struct octet5a;
    kal_uint8 octet5b_present;
    csmcc_bc_octet5b_struct octet5b;
    kal_uint8 octet6_present;
    csmcc_bc_octet6_struct octet6;
    kal_uint8 octet6a_present;
    csmcc_bc_octet6a_struct octet6a;
    kal_uint8 octet6b_present;
    csmcc_bc_octet6b_struct octet6b;
    kal_uint8 octet6c_present;
    csmcc_bc_octet6c_struct octet6c;
    kal_uint8 octet6d_present;
    csmcc_bc_octet6d_struct octet6d;
    kal_uint8 octet6e_present;
    csmcc_bc_octet6e_struct octet6e;
    kal_uint8 octet6f_present;
    csmcc_bc_octet6f_struct octet6f;
    kal_uint8 octet6g_present;
    csmcc_bc_octet6g_struct octet6g;
    kal_uint8 octet7_present;
    csmcc_bc_octet7_struct octet7;
} csmcc_bc_struct;


typedef struct {
    kal_uint8 negotiation_indicator;
} csmcc_llc_octet3a_struct;

typedef struct {
    kal_uint8 rate_multiplier;
} csmcc_llc_octet4a_struct;

typedef struct {
    kal_uint8 user_info_layer1_protocol;
} csmcc_llc_octet5_struct;

typedef struct {
    kal_uint8 synchronous_flag;
    kal_uint8 negotiation;
    kal_uint8 user_rate;
} csmcc_llc_octet5a_struct;

typedef struct {
    kal_uint8 intermediate_rate;
    kal_uint8 NIC_on_Tx;
    kal_uint8 NIC_on_Rx;
    kal_uint8 flow_control_on_Tx;
    kal_uint8 flow_control_on_Rx;
} csmcc_llc_octet5b1_struct;

typedef struct {
    kal_uint8 header_flag;
    kal_uint8 multi_frame;
    kal_uint8 mode_of_layer1;
    kal_uint8 LLI_negotiation;
    kal_uint8 assignor;
    kal_uint8 inband_negotiation;
} csmcc_llc_octet5b2_struct;

typedef struct {
    kal_uint8 number_of_stop_bits;
    kal_uint8 number_of_data_bits;
    kal_uint8 parity;
} csmcc_llc_octet5c_struct;

typedef struct {
    kal_uint8 duplex_mode;
    kal_uint8 modem_type;
} csmcc_llc_octet5d_struct;

typedef struct {
    kal_uint8 user_info_layer2_protocol;
} csmcc_llc_octet6_struct;

typedef struct {
    kal_uint8 mode_of_layer2;
    kal_uint8 Q933_use;
} csmcc_llc_octet6a1_struct;

typedef struct {
    kal_uint8 user_specified_layer2_protocol_info;
} csmcc_llc_octet6a2_struct;

typedef struct {
    kal_uint8 window_size;
} csmcc_llc_octet6b_struct;

typedef struct {
    kal_uint8 optional_layer3_protocol_info;
} csmcc_llc_octet7a1_struct;

typedef struct {
    kal_uint8 mode_of_layer3;
} csmcc_llc_octet7a2_struct;

typedef struct {
    kal_uint8 default_packet_size;
} csmcc_llc_octet7b1_struct;

typedef struct {
    kal_uint8 packet_window_size;
} csmcc_llc_octet7c_struct;

typedef struct {
    kal_uint32 additional_layer3_protocol_info_MSB:1;
} csmcc_llc_octet7a3_struct;

typedef struct {
    kal_uint8 additional_layer3_protocol_info_LSB;
} csmcc_llc_octet7b2_struct;

typedef struct {
    kal_uint8 information_transfer_capability;
    kal_uint8 octet3a_present;
    csmcc_llc_octet3a_struct octet3a;
    kal_uint8 transfer_mode;
    kal_uint8 information_transfer_rate;
    csmcc_llc_octet4a_struct octet4a;
    kal_uint8 octet5_present;
    csmcc_llc_octet5_struct octet5;
    kal_uint8 octet5a_present;
    csmcc_llc_octet5a_struct octet5a;
    kal_uint8 octet5b1_present;		
    csmcc_llc_octet5b1_struct octet5b1;
    kal_uint8 octet5b2_present;			
    csmcc_llc_octet5b2_struct octet5b2;
    kal_uint8 octet5c_present;
    csmcc_llc_octet5c_struct octet5c;
    kal_uint8 octet5d_present;
    csmcc_llc_octet5d_struct octet5d;
    kal_uint8 octet6_present;
    csmcc_llc_octet6_struct octet6;
    kal_uint8 octet6a1_present;
    csmcc_llc_octet6a1_struct octet6a1;
    kal_uint8 octet6a2_present;
    csmcc_llc_octet6a2_struct octet6a2;
    kal_uint8 octet6b_present;
    csmcc_llc_octet6b_struct octet6b;
    kal_uint8 octet7_present;
    kal_uint8 userInfoLayer3Protocol;
    kal_uint8 octet7a1_present;
    csmcc_llc_octet7a1_struct octet7a1;
    kal_uint8 octet7a2_present;
    csmcc_llc_octet7a2_struct octet7a2;
    kal_uint8 octet7b1_present;
    csmcc_llc_octet7b1_struct octet7b1;
    kal_uint8 octet7c_present;
    csmcc_llc_octet7c_struct octet7c;
    kal_uint8 octet7a3_present;
    csmcc_llc_octet7a3_struct octet7a3;
    kal_uint8 octet7b2_present;
    csmcc_llc_octet7b2_struct octet7b2;
} csmcc_llc_struct;

typedef struct {
    kal_uint8 interpretation;
    kal_uint8 protocol_profile;
} csmcc_hlc_octet3_struct;

typedef struct {
    kal_uint8 high_layer_characteristics_iden;
} csmcc_hlc_octet4_struct;

typedef struct {
    kal_uint8 extended_high_layer_characteristics_Iden;
} csmcc_hlc_octet4a_struct;

typedef struct {
    kal_uint8 octet3_present;
    csmcc_hlc_octet3_struct octet3;
    kal_uint8 octet4_present;
    csmcc_hlc_octet4_struct octet4;
    kal_uint8 octet4a_present;
    csmcc_hlc_octet4a_struct octet4a;
} csmcc_hlc_struct;

#endif /* _CSMCC_BC_TYPES_H */


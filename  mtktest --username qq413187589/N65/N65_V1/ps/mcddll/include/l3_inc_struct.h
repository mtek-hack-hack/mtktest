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
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************
 *  FILENAME : l3_inc_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifndef _L3_INC_STRUCT_H
#define _L3_INC_STRUCT_H

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
} qos_struct;

typedef struct {
    kal_uint8 pfi;
    kal_uint8 epi;
    kal_uint8 contents_len; /* in bytes*/
    kal_uint8 contents[29];
} packet_filter_struct;

typedef struct {
    kal_uint8 tft_op_code;
    kal_uint8 spare;
    kal_uint8 num_packet_filters;
    packet_filter_struct packet_list[8];
} tft_struct;

typedef struct {
    kal_uint8 length; /* LENGTH*/
    kal_uint8 digit0; /* DIGIT 0*/
    kal_uint8 odd_or_even; /* ODD OR EVEN*/
    kal_uint8 identity_type; /* IDENTITY TYPE*/
    kal_uint8 digit_byte[7];
} imsi_struct;

typedef struct {
    kal_uint16 bcch_list[8];
} bcchs_struct;

typedef struct {
    kal_uint8 split_pg_cycle_code; /* Split Pg Cycle Code */
    kal_uint8 drx_cycle_len_coeff; /* DRX Spare */
    kal_uint8 drx_split_ccch; /* DRX Split CCCH*/
    kal_uint8 non_drx_timer; /* Non DRX Timer */
} drx_param_struct;

typedef struct {
    kal_uint8 length;
    kal_uint8 digit0;
    kal_uint8 odd_or_even;
    kal_uint8 identity_type;
    kal_uint8 digit_byte[7];
} imei_struct;

typedef struct {
    kal_uint8 length;
    kal_uint8 digit0;
    kal_uint8 odd_or_even;
    kal_uint8 identity_type;
    kal_uint8 digit_byte[8];
} imeisv_struct;

typedef struct {
    kal_uint8 mcc2;
    kal_uint8 mcc1;
    kal_uint8 mnc3;
    kal_uint8 mcc3;
    kal_uint8 mnc2;
    kal_uint8 mnc1;
} plmn_id_struct;

typedef struct {
    plmn_id_struct plmn_id;
    kal_uint8 rat;  /* rat_enum */
} plmn_id_rat_struct;

typedef struct {
    kal_uint8 mcc2; /* MCC DIGIT2*/
    kal_uint8 mcc1; /* MCC DIGIT1*/
    kal_uint8 mnc3; /* MNC DIGIT3 Always 1111*/
    kal_uint8 mcc3; /* MCC DIGIT3*/
    kal_uint8 mnc2; /* MNC DIGIT2*/
    kal_uint8 mnc1; /* MNC DIGIT1*/
    kal_uint8 la_code[2];
    kal_uint8 ra_code; /* RA CODE*/
    kal_uint16 cell_id; /* CELL ID*/
} cell_info_struct;

typedef struct {
    plmn_id_struct plmn_id;
    kal_uint8 la_code[2];
} lai_struct;

typedef struct {
    kal_uint8 year; /* Year*/
    kal_uint8 month; /* Month*/
    kal_uint8 day; /* Day*/
    kal_uint8 hour; /* Hour*/
    kal_uint8 min; /* Minute*/
    kal_uint8 sec; /* Second*/
    kal_uint8 time_zone; /* Time Zone*/
} nw_time_zone_time_struct;
#endif 

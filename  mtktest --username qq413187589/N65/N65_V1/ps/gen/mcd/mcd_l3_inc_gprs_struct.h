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
 * MCD_L3_INC_GPRS_STRUCT_H
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
#ifndef _MCD_L3_INC_GPRS_STRUCT_H
#define _MCD_L3_INC_GPRS_STRUCT_H
typedef struct concise_qos_struct
{
	kal_uint8 delay_class;
	kal_uint8 reliability_class;
	kal_uint8 peak_throughput;
	kal_uint8 traffic_class;
} concise_qos_struct;


typedef struct qos_struct
{
	kal_uint8 qos_length;
	kal_uint8 unused1;
	kal_uint8 delay_class;
	kal_uint8 reliability_class;
	kal_uint8 peak_throughput;
	kal_uint8 unused2;
	kal_uint8 precedence_class;
	kal_uint8 unused3;
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


#endif /*_MCD_L3_INC_GPRS_STRUCT_H*/

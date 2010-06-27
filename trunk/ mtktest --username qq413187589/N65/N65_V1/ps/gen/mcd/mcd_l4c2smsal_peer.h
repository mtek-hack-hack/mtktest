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
 * MCD_L4C2SMSAL_PEER_H
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
#ifndef _MCD_L4C2SMSAL_PEER_H
#define _MCD_L4C2SMSAL_PEER_H
/*
 * 700 is for concatenated in SMSAL, 
 * currently SMSAL handles single message!!
 * #define SMSAL_MAX_MSG_LEN     700
 */
typedef struct smsal_submit_msg_struct
{
	kal_uint8 fo;
	l4_addr_bcd_struct* sca;
	l4_addr_bcd_struct* da;
	kal_uint8 pid;
	kal_uint8 dcs;
	kal_uint8 ori_dcs;
	kal_uint8 vp;
	kal_uint16 no_msg_data;
	kal_uint8 *msg_data;
} smsal_submit_msg_struct;


typedef struct smsal_deliver_msg_struct
{
	kal_uint8 fo;
	kal_uint8 scts[7];
	l4_addr_bcd_struct* sca;
	l4_addr_bcd_struct* oa;
	kal_uint8 pid;
	kal_uint8 dcs;
	kal_uint8 ori_dcs;
	kal_uint16 no_msg_data;
	kal_uint8 *msg_data;
} smsal_deliver_msg_struct;


typedef struct smsal_status_report_msg_struct
{
	kal_uint8 fo;
	kal_uint8 mr;
	kal_uint8 scts[7];
	kal_uint8 dt[7];
	l4_addr_bcd_struct* ra;
	kal_uint8 st;
	kal_uint8 pid;
	kal_uint8 dcs;
	kal_uint8 ori_dcs;
	kal_uint16 no_msg_data;
	kal_uint8 *msg_data;
} smsal_status_report_msg_struct;


typedef struct smsal_command_msg_struct
{
	kal_uint8 fo;
	kal_uint8 ct;
	kal_uint8 mn;
	l4_addr_bcd_struct* da;
	kal_uint8 pid;
	kal_uint8 no_msg_data;
	kal_uint8 *msg_data;
} smsal_command_msg_struct;


typedef struct smsal_send_msg_req_struct
{
	kal_uint8 da_tag;
	l4_addr_bcd_struct* da;
	kal_uint8 profile_no_tag;
	kal_uint8 profile_no;
	kal_uint8 para_ind;
	kal_uint8 pid;
	kal_uint8 dcs;
	kal_uint8 vp;
	l4_addr_bcd_struct* sc_addr;
	kal_uint8 udhi;
	kal_uint16 no_msg_data;
	kal_uint8 *msg_data;
} smsal_send_msg_req_struct;


#endif /*_MCD_L4C2SMSAL_PEER_H*/

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
/*****************************************************************************
 *
 * Filename:
 * ---------
 * smsal_peer_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for packing and unpacking of SMS-TL peer message.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************
 *  FILENAME : smsal_peer_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifndef _SMSAL_PEER_STRUCT_H
#define _SMSAL_PEER_STRUCT_H

typedef struct {
    kal_uint8 fill_bits2; /* always set to zero*/
    kal_uint8 udh_p; /* indicates the presence of
                                             user data header*/
    kal_uint8 fill_bits1; /* always set to zero*/
    kal_uint8 msg_type; /* deliver report type*/
    kal_uint8 fail_cause;
    kal_uint8 params_p; /* depicts presence of
                                               optional parameters*/
    kal_uint8 pid; /* to be bit-wise encoded*/
    kal_uint8 dcs; /* to be bit-wise encoded*/
    kal_uint8 user_data_len;
    kal_uint8 no_user_data;
    kal_uint8 user_data_size;
    kal_uint8 *user_data; /* can include user data header*/
} smsal_deliver_report_nack_peer_struct;

typedef struct {
    kal_uint8 fill_bits2; /* always set to zero*/
    kal_uint8 udh_p; /* indicates the presence of
                                             user data header*/
    kal_uint8 fill_bits1; /* always set to zero*/
    kal_uint8 msg_type; /* deliver report type*/
    kal_uint8 params_p; /* depicts presence of
                                               optional parameters*/
    kal_uint8 pid; /* to be bit-wise encoded*/
    kal_uint8 dcs; /* to be bit-wise encoded*/
    kal_uint8 user_data_len;
    kal_uint8 no_user_data;
    kal_uint8 user_data_size;
    kal_uint8 *user_data; /* can include user data header*/
} smsal_deliver_report_ack_peer_struct;

typedef struct {
    kal_uint8 reply_flag; /* whether reply is sought*/
    kal_uint8 udh_p; /* indicates presence of
                                             user data header*/
    kal_uint8 status_rep_flag; /* whether status reports
                                             are sought*/
    kal_uint8 vp_flag; /* indicates presence of
                                             validity period*/
    kal_uint8 rej_dup_flag;
    kal_uint8 msg_type; /* sms submit*/
    kal_uint8 msg_ref; /* to be read from SIM*/
    kal_uint8 no_dest_addr;
    kal_uint8 dest_addr_size;
    kal_uint8 *dest_addr; /* assumed to be
                                                         byte-packed*/
    kal_uint8 pid; /* to be bit-wise encoded*/
    kal_uint8 dcs; /* to be bit-wise encoded*/
    kal_uint8 no_validity_period;
    kal_uint8 validity_period_size;
    kal_uint8 *validity_period; /* to be
                                                       bit/byte-wise 
                                                       encoded, cannot 
                                                       be even represnted 
                                                       using CHOICE*/
    kal_uint8 user_data_len;
    kal_uint8 no_user_data;
    kal_uint8 user_data_size;
    kal_uint8 *user_data; /* can have user data header also*/
} smsal_submit_peer_struct;

typedef struct {
    kal_uint8 reply_flag; /* whether reply is sought*/
    kal_uint8 udh_p; /* indicates presence of
                                             user data header*/
    kal_uint8 status_rep_flag; /* whether status reports
                                               are sought*/
    kal_uint8 fill_bits; /* to be ignored*/
    kal_uint8 mms; /* more message to send*/
    kal_uint8 msg_type; /* sms deliver*/
    kal_uint8 no_orig_addr;
    kal_uint8 orig_addr_size;
    kal_uint8 *orig_addr; /* assumed to be
                                                         byte-packed*/
    kal_uint8 pid; /* to be bit-wise decoded*/
    kal_uint8 dcs; /* to be bit-wise decoded*/
    kal_uint8 scts[7];
    kal_uint8 user_data_len;
    kal_uint8 no_user_data;
    kal_uint8 user_data_size;
    kal_uint8 *user_data; /* can have user data header also*/
} smsal_deliver_peer_struct;

typedef struct {
    kal_uint8 fill_bits2; /* to be ignored*/
    kal_uint8 udh_p; /* indicates presence of
                                             user data header*/
    kal_uint8 fill_bits1; /* to be ignored*/
    kal_uint8 msg_type; /* sms submit report*/
    kal_uint8 fail_cause;
    kal_uint8 params_p; /* depicts presence of
                                               optional params*/
    kal_uint8 scts[7];
    kal_uint8 pid; /* to be bit-wise decoded*/
    kal_uint8 dcs; /* to be bit-wise decoded*/
    kal_uint8 user_data_len;
    kal_uint8 no_user_data;
    kal_uint8 user_data_size;
    kal_uint8 *user_data; /* can have user data header also*/
} smsal_submit_report_nack_peer_struct;

typedef struct {
    kal_uint8 fill_bits2; /* to be ignored*/
    kal_uint8 udh_p; /* indicates presence of
                                             user data header*/
    kal_uint8 fill_bits1; /* to be ignored*/
    kal_uint8 msg_type; /* sms submit report*/
    kal_uint8 params_p; /* depicts presence of
                                               optional parameters*/
    kal_uint8 scts[7];
    kal_uint8 pid; /* to be bit-wise decoded*/
    kal_uint8 dcs; /* to be bit-wise decoded*/
    kal_uint8 user_data_len;
    kal_uint8 no_user_data;
    kal_uint8 user_data_size;
    kal_uint8 *user_data; /* can have user data header also*/
} smsal_submit_report_ack_peer_struct;

typedef struct {
    kal_uint8 fill_bits1; /* to be ignored*/
    kal_uint8 udh_p; /* indicates presence of
                                              user data header*/
    kal_uint8 status_rep_type; /* sms command or sms
                                              submit*/
    kal_uint8 fill_bits2; /* to be ignored*/
    kal_uint8 mms;
    kal_uint8 msg_type; /* sms status report*/
    kal_uint8 msg_ref;
    kal_uint8 no_rcpnt_addr;
    kal_uint8 rcpnt_addr_size;
    kal_uint8 *rcpnt_addr;
    kal_uint8 scts[7];
    kal_uint8 dis_time[7];
    kal_uint8 status; /* actual status of submit*/
    kal_uint8 params_p; /* depicts presence of
                                                optional parameters*/
    kal_uint8 pid; /* to be bit-wise decoded*/
    kal_uint8 dcs; /* to be bit-wise decoded*/
    kal_uint8 user_data_len;
    kal_uint8 no_user_data;
    kal_uint8 user_data_size;
    kal_uint8 *user_data; /* can have user data header also*/
} smsal_status_report_peer_struct;

typedef struct {
    kal_uint8 fill_bits1; /* to be ignored*/
    kal_uint8 udh_p; /* indicates presence of user data header*/
    kal_uint8 status_rep_req;
    kal_uint8 fill_bits3; /* to be ignored*/
    kal_uint8 msg_type; /* sms command*/
    kal_uint8 msg_ref; /* TP-MR*/
    kal_uint8 pid; /* TP-PID*/
    kal_uint8 cmd_type; /* TP-CT*/
    kal_uint8 msg_num; /* TP-MN*/
    kal_uint8 no_dest_addr;
    kal_uint8 dest_addr_size;
    kal_uint8 *dest_addr; /* TP-DA*/
    kal_uint8 cmd_data_len; /* TP-CDL*/
    kal_uint8 no_cmd_data;
    kal_uint8 cmd_data_size;
    kal_uint8 *cmd_data; /* TP-CD*/
} smsal_command_peer_struct;
#endif 



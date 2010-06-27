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
 * L4C2ABM_STRUCT.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common struct of ABM and L4C.
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


#ifndef _L4C2ABM_STRUCT_H
#define _L4C2ABM_STRUCT_H
#include "ps2sat_struct.h"

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_bool result;
   kal_uint16 err_cause;
   kal_uint8 profile_id;
   kal_uint8 ip_addr[4];
   kal_uint8 pri_dns_addr[4];
   kal_uint8 sec_dns_addr[4];    
} l4c_ps_abm_setup_rsp_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_bool result;
   kal_uint16 err_cause;
   kal_uint8 profile_id;
} l4c_ps_abm_disc_rsp_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;  
   kal_uint8 profile_id;
   kal_uint16 err_cause;
} l4c_ps_abm_disc_ind_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_bool result;
   kal_uint16 err_cause;   
   kal_uint8 ip_addr[4];
   kal_uint8 pri_dns_addr[4];
   kal_uint8 sec_dns_addr[4];
   kal_uint16 mtu;    
} l4c_cc_abm_setup_rsp_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_bool result;
   kal_uint16 err_cause;
} l4c_cc_abm_disc_rsp_struct;   

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;  
   kal_uint8 csd_profile_id;
   kal_uint16 err_cause;
} l4c_cc_abm_disc_ind_struct;   

#ifdef __UCM_SUPPORT__
typedef struct
{
    kal_uint8  ref_count;
    kal_uint16 msg_len;
    kal_uint8  prof_id;
    kal_uint8  sim_info;
    kal_bool   result;
    kal_uint8  call_num_len;
    kal_uint8  call_num_type;
#define MAX_CC_ADDR_LEN          41
    kal_uint8  call_num[MAX_CC_ADDR_LEN];
} abm_l4c_get_csd_call_num_rsp_struct;
#endif

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
} l4cabm_start_req_struct;

typedef nvram_ef_abm_gprs_profile_struct l4c_gprs_account_info_struct;

#ifdef __SATCE__
typedef struct {
    kal_uint8 ref_count;
    kal_uint8 msg_len;
    kal_uint8 nw_acct_id;    
    kal_bool is_apn_valid;
    kal_uint8 apn_length;
    kal_uint8 apn[50];
    kal_bool is_username_valid;
    kal_uint8 no_username;
    kal_uint8 username[16];
    kal_uint8 dcs_of_username;
    kal_bool is_passwd_valid;
    kal_uint8 no_passwd;
    kal_uint8 passwd[16];
    kal_uint8 dcs_of_passwd;
    kal_bool is_local_addr_valid;
    kal_uint8 no_local_addr;
    kal_uint8 local_addr[16];
    kal_bool is_dest_addr_valid;
    kal_uint8 no_dest_addr;
    kal_uint8 dest_addr[16];
    sat_gprs_bearer_para_struct gprs_bearer;
} l4cabm_sate_set_gprs_account_info_req_struct;
#endif /* __SATCE__ */

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    l4c_gprs_account_info_struct gprs_account_info;
#ifdef __SATCE__
    l4cabm_sate_set_gprs_account_info_req_struct sate_account_info;
#endif /* __SATCE__ */
} l4cabm_set_gprs_account_info_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 profile_id;
} l4cabm_get_gprs_account_info_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    l4c_gprs_account_info_struct gprs_account_info;
} l4cabm_get_gprs_account_info_rsp_struct;

#endif /* ~_L4C2ABM_STRUCT_H */



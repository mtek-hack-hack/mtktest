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
 * ABM_UTIL.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the utilities functions of ABM.
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
#ifndef _ABM_UTIL_H
#define _ABM_UTIL_H

/* Minimum network account ID */
#define ABM_MIN_NWACC_ID 0

#define ABM_DUAL_SIM1   1
#define ABM_DUAL_SIM2   2


extern kal_uint8 abm_get_total_bearer(void);

extern kal_uint8 abm_get_sate_total_bearer(void);

extern kal_uint8 abm_get_wifi_profile_id(void);

extern kal_bool abm_nw2bearer_id(
                    kal_uint32 nw_acc_id,
                    /* IN */ kal_uint8 *bearer,
                    /* OUT */ kal_uint8 *bearer_id /* OUT */ );

extern kal_bool abm_bearer2nw_id(
                    kal_uint8 bearer,
                    /* IN */ kal_uint32 bearer_id,
                    /* IN */ kal_uint32 *nw_acc_id /* OUT */ );

extern kal_bool abm_check_msg(ilm_struct *ilm_ptr);

extern void abm_send_msg2l4c(msg_type msg_id, kal_uint8 sim_info, local_para_struct *p_local_para);

extern void abm_send_act_cnf2soc(
                kal_uint8 bearer,
                kal_uint32 nw_acc_id,
                kal_uint8 *ip_addr,
                kal_uint8 *pri_dns_addr,
                kal_uint8 *sec_dns_addr,
                kal_uint8 *gateway,
                kal_uint8 *netmask,
                kal_uint8 *mac_addr,
                kal_uint8 dhcp_state,
                kal_uint16 mtu);

extern void abm_send_deact_cnf2soc(kal_uint32 nw_acc_id);

extern void abm_send_rej2soc(msg_type msg_id, kal_uint8 bearer, kal_uint16 err_cause, kal_uint32 nw_acc_id);

#ifdef __PS_SERVICE__

extern void abm_send_req2nvram(msg_type msg_id, local_para_struct *p_local_para, peer_buff_struct *p_peer_buf);

extern kal_bool l4cabm_get_gprs_account_info(l4c_gprs_account_info_struct *info);

extern void abm_restore_sib_to_nvram(kal_uint16 record_no, kal_uint8 access_id);

extern void abm_send_get_gprs_acct_cnf(
                kal_uint8 src_id,
                kal_uint8 result,
                kal_uint8 err_cause,
                l4c_gprs_account_info_struct *account_info);

extern kal_bool abm_get_gprs_slot(kal_uint8 state, kal_uint8 *id);
extern kal_bool abm_get_gprs_slot_by_acct_id(kal_uint8 nw_acct_id, kal_uint8 *id);

#endif /* __PS_SERVICE__ */ 

#ifdef __WIFI_SUPPORT__

extern void abm_send_msg2supc(msg_type msg_id, local_para_struct *p_local_para);

extern void abm_send_rej2mmi(msg_type msg_id, kal_uint16 err_cause);

extern void abm_send_ind2soc(msg_type msg_id, local_para_struct *p_local_para);

extern void abm_send_msg2dhcp(msg_type msg_id, local_para_struct *p_local_para);

#endif /* __WIFI_SUPPORT__ */ 

extern void abm_send_msg2mmi(msg_type msg_id, local_para_struct *p_local_para);

#endif /* _ABM_UTIL_H */ 


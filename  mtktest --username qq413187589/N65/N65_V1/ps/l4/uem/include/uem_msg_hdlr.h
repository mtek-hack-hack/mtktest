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
 * uem_msg_hdlr.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for UEM message receive handler.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _UEM_MSG_HDLR_H
#define _UEM_MSG_HDLR_H

/***************************************************************************** 
* Extern Function
*****************************************************************************/
extern void uemdrv_keypad_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void uemdrv_rtc_period_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void uemdrv_power_on_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void uemdrv_pmic_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void uemdrv_aux_id_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void uemnvm_write_data_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void ueml4c_set_profile_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void uemnvm_read_data_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void ueml4c_startup_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void uemsat_language_req_hdlr(kal_uint32 src_mod_id, local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void uemsat_current_time_req_hdlr(kal_uint32 src_mod_id, local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void ueml4c_em_req_hdlr(msg_type msg_id, local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void uemaud_playbyname_req_hdlr
    (msg_type msg_id, local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void ueml4c_playbyname_cnf_hdlr
    (msg_type msg_id, local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void uemaud_playbystring_req_hdlr
    (msg_type msg_id, local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void ueml4c_playbystring_cnf_hdlr
    (msg_type msg_id, local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void uemsys_timer_expiry_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void ueml4c_set_audio_profile_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void ueml4c_set_audio_param_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void ueml4c_set_hw_level_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void uemaux_all_channel_conf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void uemaud_play_finish_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void uemaud_startup_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void uembmt_adc_measure_done_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

#ifdef __USB_ENABLE__
extern void uemdrv_usb_detect_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void uemdrv_usb_config_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif /* __USB_ENABLE__ */ 

extern void uemdrv_bmt_leave_precharge_ind(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void ueml4c_get_audio_param_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void ueml4c_get_audio_profile_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void ueml4c_get_volume_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void ueml4c_get_gain_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

#endif /* _UEM_MSG_HDLR_H */ /* uem_msg_hdlr.h */


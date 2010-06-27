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

#ifndef _mma_env_h
#define _mma_env_h

/**********************************************************************
 * Function declarations
 **********************************************************************/

void MMAc_start(void);

int MMAc_wantsToRun(void);

void MMAc_run(void);

void MMAc_kill(void);

void wap_send_mmi_mms_start_uc_req(kal_uint8 mode, kal_uint32 msg_id);

void wap_send_wap_mma_get_setting_rsp(kal_uint8 app_id, kal_uint32 req_id, kal_uint8 result, kal_uint8 creation, 
    kal_uint8 prio, kal_uint8 validity, kal_uint8 delivery, kal_bool dr, kal_bool rr,
    kal_uint32 max_mms_size, mma_image_resizing_struct *resizing, mma_signature_struct *signature, 
    mma_setting_struct *sliding_time);

void wap_send_wap_mma_get_content_rsp(kal_uint8 app_id, kal_uint32 req_id, kal_uint8 result, kal_uint32 msg_id, 
    kal_uint32 header_size, kal_uint32 body_size, kal_uint32 xml_size, kal_wchar *xml_filepath, 
    kal_uint32 buffer_index, kal_uint32 buffer_size, kal_bool more, char *buff);

void wap_send_wap_mma_create_rsp(kal_uint8 app_id, kal_uint32 req_id, kal_uint8 result, kal_uint32 msg_id, 
    kal_uint32 buffer_index);

void wap_send_wap_mma_preview_rsp(kal_uint8 app_id,kal_uint32 req_id, kal_uint8 result, kal_uint32 msg_id);

void wap_send_wap_mma_save_rsp(kal_uint8 app_id, kal_uint32 req_id, kal_uint8 result, kal_uint32 msg_id);

void wap_send_wap_mma_send_ind(kal_uint8 app_id, kal_uint32 req_id, kal_uint32 msg_id, kal_uint8 retry, kal_uint8 percent);

void wap_send_wap_mma_send_rsp(kal_uint8 app_id, kal_uint32 req_id, kal_uint8 result, kal_uint32 msg_id, 
    kal_uint32 rr_id, kal_wchar *response_text, kal_uint16 box, kal_bool send_and_save);

void wap_send_wap_mma_cancel_send_rsp(kal_uint8 app_id, kal_uint32 req_id, kal_uint8 result, kal_uint32 msg_id);

void wap_send_wap_mma_delete_rsp(kal_uint8 app_id, kal_uint32 req_id, kal_uint8 result, kal_uint32 msg_id);

#endif /* _mma_env_h */

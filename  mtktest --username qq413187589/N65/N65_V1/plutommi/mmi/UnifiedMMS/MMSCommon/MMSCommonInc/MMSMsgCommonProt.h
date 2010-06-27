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
 *  MMSMsgCommonProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Common declaration file dispatch file
 *
 *
 * Author: Sukrit K Mehra (PMT0050)
 * -------
 * -------
 * 
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MMSMsgCOMMONPROT_H__
#define __MMSMsgCOMMONPROT_H__

//#ifdef __MMI_MMS_2__
extern void* umms_malloc( U32 size);
extern void umms_free( void * ptr);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

extern void mmi_uc_save_mms_rsp(void *in_msg);
extern void mmi_uc_send_mms_ind_hdlr(void *inMsg);
extern void mmi_uc_send_mms_rsp(void *inMsg);
extern void mmi_umms_handle_set_profile_rsp(void* inMsg);
extern void mmi_umms_get_msg_num_rsp(void *inMsg);
extern void mmi_umms_get_list_info_rsp(void *inMsg);
extern void mmi_umms_get_msg_info_rsp(void *inMsg);
extern void mmi_umms_delete_folder_rsp(void *inMsg);
extern void mmi_umms_get_mms_setting_rsp(void *inMsg);
extern void mmi_umms_get_mms_content_rsp(void *inMsg);
extern void mmi_umms_create_mms_rsp(void *inMsg);
extern void mmi_umms_save_mms_rsp(void *inMsg);
extern void mmi_umms_preview_mms_rsp(void *inMsg);
extern void mmi_umms_get_msg_id_list_rsp(void *inMsg);
extern void mmi_umms_dispatch_get_memory_status_rsp(void *inMsg);
extern void mmi_umms_set_setting_rsp(void* InMsg);
extern void mmi_umms_send_mms_rsp(void *inMsg);
extern void mmi_umms_delete_mms_rsp(void *inMsg);
extern void mmi_umms_cancel_send_mms_rsp(void *inMsg);
extern void mmi_umms_set_mms_setting_rsp(void *inMsg);
extern void mmi_umms_create_template_mms_rsp(void *inMsg);
extern void mmi_umms_send_create_template_rsp(void *inMsg);
extern void mmi_umms_save_template_mms_rsp(void *in_msg);
extern void mmi_umms_hndl_save_rsp_to_uc(void *inMsg);
extern void mmi_umms_get_templates_num_rsp(void *inMsg);
extern void mmi_umms_total_mms_num_rsp(void *inMsg);
extern void mmi_umms_delete_all_template_rsp(void *inMsg);
extern void mmi_ummi_get_template_message_info_rsp(void *inMsg);
extern void mmi_ummi_get_template_list_info_rsp(void *inMsg);

extern void mmi_umms_usr_def_templ_get_msg_content_rsp(void *inMsg);
extern void mmi_umms_create_mms_rsp(void *inMsg);
extern void mmi_umms_save_mms_rsp(void *inMsg);
extern void mmi_umms_send_mms_ind_hndlr(void *inMsg);
extern void mmi_umms_delete_all_rsp_frm_um(void *inMsg);
extern void mmi_umms_set_readmark_rsp(void *inMsg);
extern void mmi_umms_msg_number_rsp(void *inMsg);
extern void mmi_umms_hndl_delete_rsp(void *inMsg);
extern void mmi_umms_get_content_rsp(void *inMsg);
extern void mmi_umms_hndl_cancel_send_rsp(void *inMsg);

extern void mmi_jsr_get_msg_num_rsp(void* inMsg);
extern void mmi_jsr_get_msg_info_rsp(void* inMsg);
extern void mmi_jsr_get_msg_content_rsp(void* inMsg);
extern void mmi_jsr_create_mms_msg_rsp(void* inMsg);
extern void mmi_jsr_send_msg_rsp(void* inMsg);
extern void mmi_jsr_delete_msg_rsp(void* inMsg);
extern void mmi_jsr_cancel_send_msg_rsp(void* inMsg);
extern void mmi_jsr_get_message_list_rsp(void* inMsg);

extern void mmi_mv_get_mms_content_rsp(void *inMsg);
extern void mmi_mv_send_read_report_rsp(void *inMsg);
extern void mmi_mv_set_readmark_rsp(void *inMsg);
extern void mmi_umms_readmark_rsp(void *inMsg);

extern void mmi_umms_get_msg_number_rsp(void* inMsg);
extern void mmi_umms_get_msg_header_info_rsp(void* inMsg);
extern void mmi_umms_get_delete_all_rsp_from_um(void* inMsg);
extern void mmi_umms_receive_get_content_rsp(void* inMsg);
extern void mmi_umms_create_rsp(void* inMsg);
extern void mmi_umms_get_send_ind(void* inMsg);
extern void mmi_umms_send_rsp(void *inMsg);
extern void mmi_umms_get_save_rsp(void *inMsg);
extern void mmi_umms_get_msg_delete_rsp(void *inMsg);
extern void mmi_umms_get_cancel_rsp(void *inMsg);
extern void mmi_umms_set_data_rsp(void *inMsg);
extern void mmi_umms_set_current_profile_rsp(void *inMsg);
extern void mmi_um_get_msg_num_rsp(void *inMsg);
extern void mmi_um_get_list_info_rsp(void *inMsg);
extern void mmi_um_get_msg_info_rsp(void *inMsg);
extern void mmi_um_delete_folder_rsp(void *inMsg);
extern void mmi_uc_get_mms_content_rsp(void *inMsg);
extern void mmi_uc_create_mms_rsp(void *inMsg);
extern void mmi_um_handle_delete_all_ind(void *inMsg);
extern void mmi_uc_delete_mms_rsp(void *inMsg);
extern void mmi_uc_abort_send_mms_rsp(void *inMsg);
extern void mmi_umms_delete_all_user_def_template_rsp(void *inMsg);
extern void mmi_umms_delete_template_rsp(void *inMsg);
extern void mmi_umms_dispatch_get_msg_header_info_rsp(void *InMsg);
extern void mmi_umms_get_msg_header_info_rsp(void *inMsg);
extern void mmi_jsr_get_msg_info_rsp(void *msgRsp);
extern void mmi_umms_download_mms_rsp(void *inMsg);
extern void mmi_umms_download_mms_ind_hdlr(void *inMsg);
extern void mmi_umms_abort_download_mms_rsp(void *inMsg);
extern void mmi_umms_msg_is_valid_rsp(void *inMsg);


extern void mmi_umms_send_message(
        module_type MOD_SRC,
        module_type MOD_DEST,
        U8 MSG_SAP,
        const U16 MSG_ID,
        void *LOCAL,
        void *PEER);
typedef enum
{
	MMA_APP_ID_UC=0,
	MMA_APP_ID_UM = MMA_APP_ID_UC,		
	MMA_APP_ID_TEMPLATE,
	MMA_APP_ID_MMS_APP,
	MMA_APP_ID_JSR,
	MMA_APP_ID_VIEWER,
	MMA_APP_ID_SETTING
#ifdef __MMI_MMS_BGSR_SUPPORT__
    ,MMA_APP_ID_BGSR
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
}MMA_APP;
#endif /*__MMSMsgCOMMONPROT_H__*/


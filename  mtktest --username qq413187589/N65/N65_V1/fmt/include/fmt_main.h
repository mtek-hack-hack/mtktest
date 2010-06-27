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
 * fmt_main.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
 *==============================================================================
 *******************************************************************************/
#ifndef _FMT_MAIN_H
#define _FMT_MAIN_H

#ifndef FMT_NOT_PRESENT

typedef enum
{
    FMT_MSDC_STATE_UNINIT,
    FMT_MSDC_STATE_PLUG_IN,
    FMT_MSDC_STATE_PLUG_OUT
} fmt_msdc_state_enum;

extern kal_bool fmt_create(comptask_handler_struct **handle);
extern kal_bool fmt_init(task_indx_type task_indx);
extern kal_bool fmt_reset(task_indx_type task_indx);
extern void fmt_init_drive(void);
extern void fmt_main(ilm_struct *ilm_ptr);
extern void fmt_task_main(task_entry_struct *task_entry_ptr);

extern void fmt_copy_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void fmt_delete_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#ifdef __DRM_SUPPORT__
extern void fmt_delete_ro_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void fmt_process_drm_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif

extern void fmt_format_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void fmt_format_done_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void fmt_check_drive_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void fmt_get_msdc_status_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern kal_int32 fmt_delete_by_filter_hdlr(kal_uint8 *path, FMGR_FILTER *filter_mask);
extern int fmt_copy_rsp_hdlr(int action, UINT total, UINT completed, UINT handle);
extern void fmt_abort_copy(void);
extern kal_bool fmt_get_abort_copy(void);

#ifdef __FS_CARD_SUPPORT__
extern void fmt_card_detect_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void fmt_unmount_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif /* __FS_CARD_SUPPORT__ */ 

#ifdef __OTG_ENABLE__
extern void fmt_otg_card_detect_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void fmt_otg_remove_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void fmt_otg_insert_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void fmt_otg_display_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif /* __OTG_ENABLE__ */ 

#ifdef __SIM_PLUS__
extern void fmt_sim_plus_detect_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif

#if defined(__FOTA_ENABLE__)
extern void fmt_fota_init_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void fmt_fota_write_data_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void fmt_fota_finalize_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif /* #if defined(__FOTA_ENABLE__)*/

#endif /* FMT_NOT_PRESENT */ 

#endif /* _FMT_MAIN_H */ 


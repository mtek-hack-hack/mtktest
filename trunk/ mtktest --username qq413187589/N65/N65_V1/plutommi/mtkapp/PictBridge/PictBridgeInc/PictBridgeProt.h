/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *    PictBridgeProt.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for PictBridge appliction.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#ifndef __PICT_BRIDGE_PROT_H__
#define __PICT_BRIDGE_PROT_H__

#ifdef __MMI_PICT_BRIDGE_SUPPORT__

/* PictBridgeMain.c */
extern void mmi_pict_entry_error_connection_to_pc(void);
extern void mmi_pict_entry_print_settings(void);
extern void mmi_pict_entry_print_now(void);
extern void mmi_pict_entry_print_query(void);
extern void mmi_pict_entry_print_abort(void);
extern void mmi_pict_entry_print_preview(void);

extern void mmi_pict_entry_print_done(pBOOL result, U16 error_string);
extern void mmi_pict_update_print_progression(const char *);

extern void mmi_pict_popup_print_error(void);
extern void mmi_pict_go_back_from_print_error(void);
extern void mmi_pict_delete_print_screens(void);
extern void mmi_pict_get_file_dimension(void);
extern void mmi_pict_host_reset_popop(void);

extern U16 mmi_pict_return_title_icon(void);
extern void mmi_pict_convert_date_to_unicode(const FS_DOSDirEntry *fs_entry, U8 *str_buffer);
extern MMI_BOOL mmi_pict_jpg_format_validation(S8 *file);

#ifdef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__
extern void mmi_pict_entry_printer_connected(void);
extern void mmi_pict_popup_idle_state_error(void);
#endif /* __MMI_PICT_BRIDGE_COMPLIANCE_TEST__ */

/* PictBridgeSettings.c */
extern void mmi_pict_entry_print_settings(void);
#ifdef __MMI_PICT_BRIDGE_CROPPING_CAT57__
extern void mmi_pict_entry_image_cropping(void);
#endif
#ifdef __MMI_PICT_BRIDGE_CROPPING_CAT88__
extern void mmi_pict_entry_image_cropping_phase1(void);
extern void mmi_pict_entry_image_cropping_phase2(void);
#endif

/* PictBridgeXML.c */
extern void mmi_pict_parse_xml_script(void);
extern void mmi_pict_prepare_xml_configure_print_service(void);
extern void mmi_pict_prepare_xml_get_capability(void);

extern void mmi_pict_prepare_xml_notify_job_result(void);
extern void mmi_pict_prepare_xml_notify_device_result(void);

extern void mmi_pict_prepare_xml_start_job(void);
extern void mmi_pict_prepare_xml_abort_job(void);
extern void mmi_pict_prepare_xml_continue_job(void);

#ifdef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__
extern void mmi_pict_prepare_xml_return_error(void);
extern void mmi_pict_prepare_xml_return_invalidity(void);
extern void mmi_pict_exec_notify_device_status_cmd(void);
#endif /* __MMI_PICT_BRIDGE_COMPLIANCE_TEST__ */

/* PictBridgeHandler.c */
extern void mmi_pict_dps_discovery_ind(void *info);
extern void mmi_pict_receive_dps_operation_ind(void *info);
extern void mmi_pict_receive_dps_event_ind(void *info);
extern void mmi_pict_send_dps_operation_rsp(void *info);
extern void mmi_pict_send_dps_event_rsp(void *info);

extern void mmi_pict_send_dps_operation_req(void);
extern void mmi_pict_send_dps_event_req(void);

extern void mmi_pict_start_job_req(void);
extern void mmi_pict_close_job_req(void);
extern void mmi_pict_send_pending_message(void);
extern void mmi_pict_proc_pending_message(void *info);

extern void mmi_pict_connect_to_pc_ind(void *info);
extern void mmi_pict_open_file_fail_ind(void *info);
extern void mmi_pict_host_reset(void *info);

extern pBOOL mmi_pict_is_dps_device_present(void);
extern void mmi_pict_protocol_init(void);

#ifdef __MMI_PICT_BRIDGE_KEEP_XML_DATA__
extern void mmi_pict_write_xml_data_to_file(U8 *data_addr, U32 data_len);
extern void mmi_pict_delete_xml_data_file(void);
#endif /* __MMI_PICT_BRIDGE_KEEP_XML_DATA__ */

#ifdef __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__
/* PictBridgeFiles.c */
extern void mmi_pict_entry_multi_file_selection(void);
extern void mmi_pict_entry_file_selection_done(void);
extern void mmi_pict_retrieve_files_from_current_dir(void);
extern void mmi_pict_cat426_mark_selected_file(void);
extern void mmi_pict_cat426_reset_selected_file(void);

extern void mmi_pict_app_mem_stop_callback(void);
extern U8 mmi_pict_delete_multi_file_category_callback(void* ptr);
extern void mmi_pict_go_back_from_file_selection(void);
#endif /* __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__ */

#endif /* __MMI_PICT_BRIDGE_SUPPORT__ */

#endif /* __PICT_BRIDGE_PROT_H__ */


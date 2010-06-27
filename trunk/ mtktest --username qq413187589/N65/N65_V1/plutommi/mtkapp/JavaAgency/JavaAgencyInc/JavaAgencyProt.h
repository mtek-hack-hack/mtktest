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
 * JavaProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for define prototypes of Java related routines.
 *
 * Author:
 * -------
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

#ifndef JAVA_AGENCY_PROT_H
#define JAVA_AGENCY_PROT_H

#ifdef __J2ME__

#include "JavaAgencyDef.h"
#include "JavaAgencyGprot.h"
#include "jam_interface.h"
#include "jam_msg_handler.h"

/*****************************************************************************
** 0. JAVA_BASIC feature:
** 1.JAVA_CONTENT_MANAGER feature:
** 1.1   JAVA_CM_BROWSER
** 1.2   JAVA_CM_LAUNCH
** 1.3   JAVA_CM_UPDATE
** 1.4   JAVA_CM_SETTING
** 1.5   JAVA_CM_INFORMATION
** 1.6   JAVA_CM_DELETE
** 3. JAVA_TCK
** 4. JAVA_INSTALL_UPDATE
** 5. JAVA_TIMEALARM_PUSH
** 6. JAVA_ABORT
**  7. Java Resume / Java Terminate
*****************************************************************************/

/*****************************************************************************
** 0. JAVA_BASIC feature: (5)
**    InitJAVA
**    Highlight_JAVA_MENU
**    EntryScrJavaMenu
**    ExitScrJavaMenu
**    HighlightJavaEM
*****************************************************************************/


extern void Highlight_JAVA_MENU(void);

extern void EntryScrJavaMenu(void);

#ifdef __SUPPORT_INFUSIO__
extern void EntryEurekaMenu(void);
 #endif /* __SUPPORT_INFUSIO__ */

extern void HighlightJavaEM(void);

/*****************************************************************************
** 1.JAVA_CONTENT_MANAGER feature: (22)
** 1.1   JAVA_CM_BROWSER
*****************************************************************************/

extern void mmi_java_highlight_get_mids_index(S32 nIndex);
extern void mmi_java_entry_opt(void);

extern void mmi_java_highlight_opt_select(void);
extern void mmi_java_highlight_opt_launch(void);
extern void mmi_java_highlight_opt_update(void);
extern void mmi_java_highlight_opt_setting(void);
extern void mmi_java_highlight_opt_info(void);
extern void mmi_java_highlight_opt_delete(void);

extern void mmi_java_send_mid_getlist_req(void);
extern void mmi_java_recv_mid_getlist_cnf(void *MsgStruct);

extern void mmi_java_highlight_option_select(S32 nIndex);

extern void mmi_java_entry_opt_select(void);

extern void mmi_java_entry_opt_update(void);

extern void mmi_java_entry_opt_setting(void);

/*****************************************************************************
** 1.JAVA_CONTENT_MANAGER feature: (3)
** 1.2   JAVA_CM_LAUNCH
*****************************************************************************/

extern void mmi_java_send_mid_start_req(game_type_enum game_type);
extern void mmi_java_entry_eureka_by_menu(void);
extern void mmi_java_entry_eureka_by_wap(void);
extern void mmi_java_entry_mid_launch(void);
extern void mmi_java_entry_mid_launch_from_idle(void);
extern void mmi_java_recv_mid_start_cnf(void *MsgStruct);
extern void mmi_java_recv_mid_stop_ind(void *MsgStruct);
extern void mmi_java_send_mid_stop_res(kal_uint32 session_id);

/*****************************************************************************
** 1.JAVA_CONTENT_MANAGER feature: (4)
** 1.5   JAVA_CM_INFORMATION
*****************************************************************************/

extern void mmi_java_send_mids_getinfo_req(void);
extern void mmi_java_recv_mids_getinfo_cnf(void *MsgStruct);
extern void mmi_java_entry_opt_info(void);

/*****************************************************************************
** 1.JAVA_CONTENT_MANAGER feature: (23)
** 1.4   JAVA_CM_SETTING
*****************************************************************************/

extern void mmi_java_highlight_network_access(void);
extern void mmi_java_highlight_auto_invocation(void);
extern void mmi_java_highlight_messaging(void);
extern void mmi_java_highlight_multimedia(void);

extern void mmi_java_save_opt_setting(void);
extern void mmi_java_send_mids_get_setting_req(kal_uint32 session_id, kal_uint32 mids_id);
extern void mmi_java_recv_mids_get_setting_cnf(void *MsgStruct);
extern void mmi_java_send_mids_set_setting_req(void);
extern void mmi_java_recv_mids_set_setting_cnf(void *MsgStruct);

extern void mmi_java_highlight_mids_setting_choice(S32 nIndex);
extern S8 mmi_java_get_choice_level(S8 permisisonLevel);
extern S8 mmi_java_get_new_permission_level(S8 choiceLevel, S8 max_setting, S8 org_seting);
extern void mmi_java_update_mids_setting(void);
extern void mmi_java_entry_opt_setting(void);
extern void mmi_java_entry_opt_setting_network_access(void);
extern void mmi_java_entry_opt_setting_auto_invocation(void);
extern void mmi_java_entry_opt_setting_messaging(void);
extern void mmi_java_entry_opt_setting_multimedia(void);
extern void mmi_java_entry_opt_setting_data_read(void);
extern void mmi_java_entry_opt_setting_data_write(void);

extern void mmi_java_recv_set_default_domain_cnf(void *MsgStruct);
extern void mmi_java_send_set_default_domain_req(void);
extern void mmi_java_recv_get_default_domain_cnf(void *MsgStruct);
extern void mmi_java_send_get_default_domain_req(S32 domain);
extern void mmi_java_recv_pause_ind(void *MsgStruct);

/*****************************************************************************
** 1.JAVA_CONTENT_MANAGER feature: (13)
** 1.6   JAVA_CM_DELETE
*****************************************************************************/

extern void mmi_java_entry_mids_delete_requesting(void);
extern void mmi_java_send_mids_delete_req(void);
extern void mmi_java_recv_mids_delete_confirm_ind(void *MsgStruct);
extern void mmi_java_entry_mids_delete_confirm(void);
extern void mmi_java_entry_mids_delete_confirmed(void);
extern void mmi_java_mids_delete_confirm_yes_hdlr(void);
extern void mmi_java_mids_delete_confirm_no_hdlr(void);
extern void mmi_java_mids_delete_confirm_cancel_hdlr(void);
extern void mmi_java_send_mids_delete_confirm_res(kal_bool confirm);
extern void mmi_java_recv_mids_delete_cnf(void *MsgStruct);

/*****************************************************************************
** 3. JAVA_TCK: (14)
*****************************************************************************/

extern void mmi_java_highlight_em_normal(void);
extern void mmi_java_highlight_em_cldc_tck(void);
extern void mmi_java_highlight_em_midp_tck(void);
extern void mmi_java_highlight_em_wma_tck(void);
extern void mmi_java_highlight_em_mmapi_tck(void);

extern void mmi_java_execute_set_mode(void);
extern void mmi_java_send_set_mode_req(void);
extern void mmi_java_recv_set_mode_cnf(void);

extern void mmi_java_terminate_tck_mode(void);
extern void mmi_java_execute_em_tck(void);

extern void EntryScrJavaEM(void);
extern void ExitScrJavaEM(void);

extern void mmi_java_entry_java_em_tck(void);
extern void mmi_java_exit_java_em_tck(void);

/*****************************************************************************
** 4. JAVA_INSTALL_UPDATE: (16)
*****************************************************************************/
extern void mmi_java_mids_install(
                kal_int32 session_id,
                kal_wchar *jad_file_name,
                kal_wchar *jar_file_name,
                kal_wchar *download_url,
                kal_bool delete);

extern void mmi_java_send_mids_install_req(
                kal_wchar *jad_file_path,
                kal_wchar *jar_file_path,
                kal_wchar *download_url);
extern void mmi_java_entry_mids_install_start(void);
extern void mmi_java_recv_mids_install_confirm_ind(void *MsgStruct);
extern void mmi_java_entry_mids_install_confirm(void);
extern void mmi_java_mids_install_confirm_yes_hdlr(void);
extern void mmi_java_mids_install_confirm_no_hdlr(void);
extern void mmi_java_send_mids_install_confirm_res(kal_bool confirm);
extern void mmi_java_recv_mids_install_cnf(void *MsgStruct);
extern void mmi_java_entry_launch_after_install_confirm(void);
extern void mmi_java_entry_mid_launch_after_install(void);
extern void mmi_java_launch_after_install_confirm_yes_hdlr(void);
extern void mmi_java_launch_after_install_confirm_no_hdlr(void);
extern void mmi_java_mids_install_confirm_cancel_hdlr(void);
extern void mmi_java_recv_show_percentage_ind(void *MsgStruct);
extern void mmi_java_entry_pecentage_bar(void);
extern void mmi_java_recv_get_install_drv_ind(void *MsgStruct);
extern void mmi_java_mids_install_internal(void);
extern void mmi_java_entry_auth(void);
extern void mmi_java_recv_get_auth_ind(void *MsgStruct);
extern void mmi_java_recv_infudio_eureka_start_req(void *MsgStruct);
extern void mmi_java_send_get_auth_res(U8* username, U8* password);
/*****************************************************************************
 * RMS
 ************************************/
extern void mmi_java_recv_reset_rms_ind(void *MsgStruct);
extern void mmi_java_entry_reset_rms_res(void);
extern void mmi_java_send_reset_rms_res_yes(void);
extern void mmi_java_send_reset_rms_res_no(void);
extern void mmi_java_send_reset_rms_res(S8 confirm);

/*****************************************************************************
** 1.JAVA_CONTENT_MANAGER feature: (15)
** 1.3   JAVA_CM_UPDATE
*****************************************************************************/
extern void mmi_java_entry_mids_update(void);
extern void mmi_java_entry_mids_update_confirm(void);
extern void mmi_java_mids_update_confirm_cancel_hdlr(void);
extern void mmi_java_mids_update_confirm_yes_hdlr(void);
extern void mmi_java_mids_update_confirm_no_hdlr(void);
extern void mmi_java_entry_mids_update_start(void);
extern void mmi_java_send_mids_update_req(void);
extern void mmi_java_recv_mids_update_cnf(void *MsgStruct);
extern void mmi_java_recv_get_file_and_save_ind(void *MsgStruct);
extern void mmi_java_entry_mids_vm_installing(void);
extern void mmi_java_send_get_file_and_sav_res(void);
extern void mmi_java_recv_wap_abort_cnf(void *MsgStruct);   /* no used */
extern void mmi_java_mids_abort_hdlr(void);
extern void mmi_java_mids_endkey_abort_hdlr(void);
extern void mmi_java_send_java_abort_req(void);
extern void mmi_java_recv_java_abort_cnf(void *MsgStruct);

/*****************************************************************************
** 5. JAVA_TIMEALARM_PUSH (11)
*****************************************************************************/

extern void mmi_java_recv_timealarm_push_ind(void *MsgStruct);
extern void mmi_java_recv_timealarm_push_get_setting_cnf(void *MsgStruct);
extern void mmi_java_send_timealarm_push_res(kal_uint32 session_id, S8 permission, U8 execute);
extern void mmi_java_entry_timealarm_push_confirm(void);
extern void mmi_java_timealarm_push_confirm_yes_hdlr(void);
extern void mmi_java_timealarm_push_confirm_no_hdlr(void);
extern void mmi_java_entry_timealarm_push_launch(void);
extern void mmi_java_exit_timealarm_push_launch(void);
extern void mmi_java_launch_time_alarm(void);

// #define j2me_launch_time_alarm mmi_java_launch_time_alarm

/*****************************************************************************
** 6. JAVA_ABORT (6)
*****************************************************************************/

extern void mmi_java_recv_wap_abort_cnf(void *MsgStruct);
extern void mmi_java_send_java_abort_req(void);
extern void mmi_java_recv_java_abort_cnf(void *MsgStruct);
extern void mmi_java_launch_after_install_callback(void);

extern void j2me_get_wap_rsp(void *MsgStruct);
extern pBOOL mmi_java_fetch_mids_list(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);

/*****************************************************************************
 *
 * 7. Java Resume / Java Terminate  (JavaAgencyTaskSwitch.c)
 *
 ******************************************************************************/
typedef void (*mmi_java_terminate_hdlr) (BOOL is_terminate);
extern void mmi_java_entry_cb_terminate_dialog(mmi_java_terminate_hdlr fp, U16* str);
extern void mmi_java_terminating_time_out_hdlr(void);

/*****************************************************************************
 *
 *  8. Other tools
 *
 ******************************************************************************/
extern void mmi_java_recv_show_alert_user_req(void *MsgStruct);
extern kal_bool mmi_java_check_and_display_is_timealarmpush(void);
extern void mmi_java_recv_get_imsi_ind(void *MsgStruct);
extern kal_bool mmi_java_is_drm_file(kal_wchar* filename);
/*****************************************************************************
 *
 *  9. Local Install
 *
 ******************************************************************************/

extern kal_bool mmi_java_local_install_session_check(void);
extern void mmi_java_local_install_abort_hdlr(void);
extern void mmi_java_entry_local_install_start(void);
extern void mmi_java_entry_local_install_finish(kal_uint8 cause, int error_code);
extern void mmi_java_entry_local_install_confirm(void);
extern void mmi_java_local_install_confirm(void);
extern void mmi_java_local_install_confirm_yes_hdlr(void);
extern void mmi_java_local_install_confirm_no_hdlr(void);
extern void mmi_java_send_local_install_req(kal_bool is_force);
extern void mmi_java_local_install_init(void);
extern void mmi_java_recv_local_install_cnf(void *msg);
extern void mmi_java_entry_local_install(void);
extern void mmi_java_send_at_loacl_install_cnf(S32 error_code);
extern void mmi_java_recv_at_local_install_req(void *MsgStruct);
extern void mmi_java_recv_drm_local_install_req(void *MsgStruct);

/*****************************************************************************
 *
 *  9. Utility
 *
 ******************************************************************************/

extern void mmi_java_entry_get_permission(void);
extern void mmi_java_recv_get_permission_ind(void *MsgStruct);

extern void mmi_java_recv_get_confirm_ind(void *MsgStruct);
extern void mmi_java_send_mids_get_confirm_res(BOOL confirm);
extern void mmi_java_entry_mids_get_confirm(void);
extern void mmi_java_mids_get_confirm_yes_hdlr(void);
extern void mmi_java_mids_get_confirm_no_hdlr(void);
extern void mmi_java_mids_get_confirm_cancel_hdlr(void);
extern void mmi_java_send_message(S32 src_id, S32 dst_id, S32 sap_id, S32 msg_id, void *local_para_ptr, void *peer_buff_ptr);

typedef struct
{
    U8 *mid_name;
    U32 mid_id;
    U8 *mid_icon;
} java_mid_info_struct;

typedef struct
{
    S32 mids_index;
    S32 mid_index;

    U32 total_java_app_mids;
    U32 total_java_app_mid;
    mids_list_struct mids_info[MAX_SUB_MENUS];
    S32 mids_info_start;
    S32 mids_info_end;
    java_mid_info_struct mid_info[MAX_SUB_MENUS];

    U8 mids_trusted;
    S32 mids_choice_index[J2ME_SETTING_MAX];
    U16 *mids_choice_str[J2ME_CHOICE_PERMISSION_MAX];

    mmi_setting_struct mids_setting;
    mmi_setting_struct mids_max_setting;

    U8 tck_index;
    U8 tck_execute;

    java_install_state_enum mids_install_state;
    java_update_state_enum mids_update_state;
    java_delete_state_enum mids_delete_state;
    BOOL is_select_after_install;   /* launch after install */
    BOOL is_launch_after_install;   /* launch after install */
    BOOL is_launch_eureka_by_wap; /* launch euraka from wap browser */
    BOOL is_jad_file_install;
    BOOL is_local_install;
    BOOL is_at_install;
    S32 screen_after_terminate;

    U8 download_percentage;
    U8* percentage_ind_midlet_name;

    S32 msg_ctrl;

    S32 domain;

} java_context_struct;

#endif /* __J2ME__ */ 
#endif /* JAVA_AGENCY_PROT_H */ /* #define JAVA_AGENCY_PROT_H */


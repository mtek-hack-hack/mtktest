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
 * BTMMIBipScr.h
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *  BIP MMI Screen source file 
 *
 * Author:
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

 /* identify the option selection from user */
typedef enum
{
    MMI_BIP_SCR_SELECT_OPT_GET,
    MMI_BIP_SCR_SELECT_OPT_IMG_DETAIL,
    MMI_BIP_SCR_SELECT_OPT_GET_THM,
    MMI_BIP_SCR_SELECT_OPT_GET_ALL,
    MMI_BIP_SCR_SELECT_OPT_REFRESH,
    MMI_BIP_SCR_SELECT_OPT_DISCONNECT,
    MMI_BIP_SCR_SELECT_OPT_END_OF_NUM
} mmi_bip_scr_select_opt_enum;

typedef enum
{
    MMI_BIP_CLEAR_SCR_ON_DISCONNECT,
    MMI_BIP_CLEAR_SCR_ON_RESET
} mmi_bip_clear_scr_mode;

 /******************************************************************************
     MMI BIP PULL SCR CONTEXT
 ******************************************************************************/
typedef struct
{
    S8 thm_name[FMGR_MAX_PATH_LEN *ENCODING_LENGTH];

} mmi_bip_img_browser_item_struct;

typedef enum
{
    MMI_BIP_NEXT_OPER_IDLE,
    MMI_BIP_NEXT_OPER_GET_IMG,
    MMI_BIP_NEXT_OPER_GET_IMGPROP,
    MMI_BIP_NEXT_OPER_GET_THM,
    MMI_BIP_NEXT_OPER_REFRESH_IMGLIST,
    MMI_BIP_NEXT_OPER_LAST
}mmi_bipi_cur_user_operation_enum;

typedef enum
{
    MMI_BIP_GET_CUR_IMG,
    MMI_BIP_GET_SELECTED_IMG,
    MMI_BIP_GET_ALL_IMG,
    MMI_BIP_GET_LAST
}mmi_bipi_get_type_enum;


typedef struct
{
    U16 sel_obj_id;
    U16 sel_opt_id;

    /* Store END key handler void(*)(void) */
    FuncPtr keydown_fp;
    FuncPtr keyup_fp;

    /* MMI_TRUE: endkey is pressed */
    MMI_BOOL endkey_pressed;

    /* for getting */
    U32 img_total;
    
    U32 selected_img_num;
    U32 received_img_num;

    MMI_BOOL b_refreshed;
    
    mmi_bipi_cur_user_operation_enum next_oper;

    mmi_bipi_get_type_enum get_type;
    
    U32 cur_idx_to_get_img;
    U32 cur_idx_to_get_thm;
    
    MMI_BOOL b_stop_bg_getting_thm;

    MMI_BOOL b_user_get_thm;


    /* for category426 */
    U32 cur_index;
    U8 *checkbox_values;
    U8 *cache_buffer;
    S32 cache_size;

    S8 img_browser_content_path[FMGR_MAX_PATH_LEN *ENCODING_LENGTH];
    S8 cur_img_handle[BT_BIP_IMG_HANDLE_LEN];

    /* img thumbnail */
    S8 img_thm_path[FMGR_MAX_PATH_LEN *ENCODING_LENGTH];

    /* image detail */
    bt_bip_img_format_enum img_encoding;
    U16 img_width;
    U16 img_height;
    U32 img_size;
    S8 img_name[BT_BIP_MAX_IMG_NAME_LEN];
} mmi_bip_scr_cntx_struct;

/******************************************************************************
 MMI FTP SCR EXTERNAL VARIABLE
******************************************************************************/
extern mmi_bip_scr_cntx_struct *g_mmi_bt_bip_scr_cntx_p;

/* function prototype */

void mmi_bt_bip_start_blinking(MMI_BT_PROFILE_ROLE bip_role);
void mmi_bt_bip_stop_blinking(MMI_BT_PROFILE_ROLE bip_role);

/* SETTING func */
void mmi_bt_bipr_menu_hdlr_init(void);
void mmi_bt_bipr_setting_highlight_hdlr(void);
void mmi_bt_bipr_entry_bip_setting(void);

void mmi_bt_bipr_shared_folder_highlight_hdlr(void);
void mmi_bt_bipr_shared_folder_hint(U16 index);
void mmi_bt_bipr_entry_shared_folder_menu(void);
void mmi_bt_bipr_fmgr_select_path_done(void *path, int is_short);
void mmi_bt_bipr_notify_recv_err(U8 cause);

/* PUSH func */
void mmi_bipi_entry_sending_scr(void);
void mmi_bipi_exit_sending_scr(void);
U8 mmi_bipi_sending_screen_del_cb(void *p);

U8 mmi_bipi_aborting_screen_del_cb(void *p);
void mmi_bipi_push_update_prog_tohdlr(void);

/* PULL func */
void mmi_bt_bipi_pull_entry_connect_scr(void);
void mmi_bt_bipi_pull_connect_cancel(void);
U8 mmi_bt_bipi_pull_recving_screen_del_cb(void *p);
void mmi_bt_bipi_pull_entry_canceling(void);
void mmi_bt_bipi_pull_entry_disconnecting(void);

U8 mmi_bt_bipi_pull_disconnecting_screen_del_cb(void *p);
U8 mmi_bt_bipi_pull_recving_screen_del_cb(void *p);
U8 mmi_bt_bipi_pull_canceling_screen_del_cb(void *p);

void mmi_bt_bipi_pull_entry_imglist_browser(void);
U8 mmi_bt_bipi_pull_imglist_browser_del_cb(void *p);

void mmi_bt_bipi_pull_entry_img_detail(void);
void mmi_bt_bipi_pull_entry_getting_img(void);

void mmi_bt_bipi_pull_entry_imglist_option(void);
void mmi_bt_bipi_pull_imglist_option_highlight_hdlr(S32 index);
void mmi_bt_bipi_pull_imglist_option_LSK(void);

void mmi_bt_bipi_pull_exit_image_browser(void);
void mmi_bt_bipi_pull_exit_image_browser_recving(void);
void mmi_bt_bipi_pull_entry_exit_confirm_scr(void);

void mmi_bt_bip_store_endkey_hdlr(void);
void mmi_bt_bip_exe_endkey_hdlr(void);

void mmi_bt_bipi_pull_entry_getting_imgprop(void);
void mmi_bt_bipi_pull_entry_img_detail(void);

void mmi_bt_bipi_get_cur_image(void);

void mmi_bt_bipi_get_selected_images(void);
void mmi_bt_bipi_get_all_images(void);
void mmi_bt_bipi_get_next_image(void);

void mmi_bt_bipi_scr_get_img_cnf(U8 cnf_code);

void mmi_bt_bipi_pull_img_end(U8 result);
void mmi_bt_bipi_get_imgprop_end(U8 result);

void mmi_bt_bipi_pull_imglist_highlight_hdlr(S32 index);

void mmi_bt_bipi_pull_refresh_imglist_category(void);
S32 mmi_bt_bipi_pull_get_img_handle_for_display(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size);
void mmi_bt_bipi_pull_get_img_thm_for_display(S32 index, U8 *image_filename, S32 max_size, U16 *default_image_id);

void mmi_bt_bipi_scr_get_thm_cnf(U8 cnf_code, U8 *thm_path, U8 *name);

void mmi_bt_bipi_pull_app_mem_free(void);
void mmi_bt_bip_app_mem_stop_callback(void);

void mmi_bipi_stop_req_timer(void);

S32 mmi_bt_bipi_pull_get_img_handle_from_index(S32 index, S8 *img_handle);

void mmi_bt_bipi_pull_EndKey_press_handler(void);
void mmi_bt_bipi_pull_exit_recv_img(void);
void mmi_bt_bipi_pull_abort_simple_operation(void);
void mmi_bt_bipi_pull_abort_getting_images_operation(void);

void mmi_bt_bipi_pull_update_prog_tohdlr(void);
U8 mmi_bt_bipi_pull_aborting_screen_del_cb(void *p);
void mmi_bt_bipi_pull_entry_exit_confirm_scr_RSK(void);
void mmi_bt_bipi_pull_exit_image_browser_recving(void);
void mmi_bt_bipi_pull_exit_image_browser(void);
U8 mmi_bt_bipi_pull_getting_imgprop_screen_del_cb(void *p);
void mmi_bt_bipi_pull_update_prog_string(void);
void mmi_bt_bipi_notify_recv_err(U8 cause);
void mmi_bt_bipi_clear_scrs(U8 disc_reset);
void mmi_bt_bipi_pull_clear_abort_scr(void);
void mmi_bipi_entry_abort_scr(void);
void mmi_bt_bipi_pull_clear_get_imgprop_scr(void);
void mmi_bt_bipi_pull_entry_aborting(void);

U8 mmi_bt_bipi_pull_connecting_screen_del_cb(void *p);

void mmi_bt_bipr_entry_recv_confirm_scr(void);
void mmi_bt_bipr_accept_conn(void);
void mmi_bt_bipr_reject_conn(void);

void mmi_bt_bipi_sending_scr_EndKey_press_handler(void);
void mmi_bt_bipi_abort_scr_EndKey_press_handler(void);
void mmi_bt_bipi_pull_exit_cfm_scr_EndKey_press_handler(void);
void mmi_bt_bipi_push_entry_exit_confirm_scr(void);
void mmi_bt_bipi_connecting_scr_EndKey_press_handler(void);

void mmi_bt_bipi_pull_entry_idle_notify_scr(void);
void mmi_bt_bipi_pull_notify_scr_browse(void);

void mmi_bt_bipi_pull_refresh_imglist(void);

void mmi_bt_bip_history_replace(U16 out_scr, U16 in_scr);
void mmi_bt_bip_add_history_before_cm_marker(U16 scrn_id, FuncPtr func_ptr);

void mmi_bt_bip_scr_recv_img_ind(void);

MMI_BOOL mmi_bt_bip_isForegroundScreen(U16 scrn_id);

void mmi_bt_bipi_pull_scr_imglist_gotten(void);
void mmi_bt_bipi_pull_scr_connect_terminated(void);
void mmi_bt_bipi_get_next_thm(S32 index);

MMI_BOOL mmi_bt_bipi_pull_scr_aborted(void);

void mmi_bt_bipi_get_cur_imgprop(void);
void mmi_bt_bipi_get_cur_imgthm(void);
void mmi_bt_bipi_pull_entry_getting_imgthm(void);
void mmi_bt_bipi_pull_entry_preview_thumbnail(void);
void mmi_bt_bipi_pull_exit_preview_scr(void);

void mmi_bt_bipi_refresh_download_list(void);

void mmi_bt_bipi_pull_exec_operation(mmi_bipi_cur_user_operation_enum oper_type);


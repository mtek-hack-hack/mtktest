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
 *  DeviceManagementInc.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Device Management Internal functions.
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
#ifndef __DEVICE_MANAGEMENT_INC_H_
#define __DEVICE_MANAGEMENT_INC_H_

#if defined(__FOTA_ENABLE__)

#include "DataAccountGprot.h"

#if defined(__MMI_FWU_VIA_HTTP__)
#include "wapadp.h"
#endif

/************************************************************************
* Definitions & Structures
************************************************************************/
typedef enum
{
    DM_UPGRADE_NONE,       /* NONE */
        
#if defined(__MMI_FWU_VIA_TFTP__)        
    DM_UPGRADE_TFTP,       /* TFTP */
#endif /* #if defined(__MMI_FWU_VIA_TFTP__) */    

#if defined(__MMI_FWU_VIA_HTTP__)
    DM_UPGRADE_HTTP,       /* HTTP */
#endif /* #if defined(__MMI_FWU_VIA_HTTP__) */    

#if defined(__MMI_FWU_VIA_FILE__)
    DM_UPGRADE_FILE,       /* FILE */
#endif /* #ifdef __MMI_FWU_VIA_FILE__*/    
    DM_UPGRADE_END
} DM_UPGRADE_MEDIA_ENUM;


typedef enum
{
    DM_TFTP_IDX_SN_TITLE,       /* Server Name Title */
    DM_TFTP_IDX_SN,             /* Server Name */
    DM_TFTP_IDX_PORT_TITLE,     /* Port Title */
    DM_TFTP_IDX_PORT,           /* Port */
    DM_TFTP_IDX_FN_TITLE,       /* File Name Title */
    DM_TFTP_IDX_FN,             /* File Name */
    DM_TFTP_IDX_DA_TITLE,       /* Data Account Title */
    DM_TFTP_IDX_DA,             /* Data Account */
    DM_TFTP_IDX_END
} DM_TFTP_SETTINGS_INDEX_ENUM;


typedef enum
{
    DM_HTTP_IDX_URL_TITLE,           /* URL Title */
    DM_HTTP_IDX_URL,                 /* URL */
    DM_HTTP_IDX_PROFILE_TITLE,       /* Data Account Title */
    DM_HTTP_IDX_PROFILE,             /* Data Account */
    DM_HTTP_IDX_END
} DM_HTTP_SETTINGS_INDEX_ENUM;


typedef enum
{
    DM_RESULT_CODE_SUCCESS,                /* success */
    DM_RESULT_CODE_ABORT,                  /* abort */
    DM_RESULT_CODE_FILE_NOT_FOUND,         /* file not found */
    DM_RESULT_CODE_ACCESS_DENIED,          /* access denied */
    DM_RESULT_CODE_SOC_ERROR,              /* socket error */
    DM_RESULT_CODE_TIMEOUT,                /* time out */

    DM_RESULT_CODE_AUTHENTICATION_FAIL,    /* wrong customer */
    DM_RESULT_CODE_FINAL_CHECK_FAIL,       /* final check fail */    

    DM_RESULT_CODE_GEN_ERROR,              /* general error */

    DM_RESULT_CODE_END
} DM_RESULT_CODE_ENUM;


typedef enum
{
    DM_STATE_INIT,               /* init */
    DM_STATE_WAIT_AUTH,          /* wait for FOTA auth. */
    DM_STATE_FOTA_AUTH,                 /* FOTA auth success */
    DM_STATE_HTTP_AUTH,                 /* HTTP auth  */
    DM_STATE_DOWNLOADING,        /* TFTP downloading */
    DM_STATE_DOWNLOAD_FINISH,    /* Download finish */
    DM_STATE_DOWNLOAD_FINISH_PENDING,   /* Download finish Pending */
    DM_STATE_ERROR,              /* Error Occurs */
    DM_STATE_FOTA_AUTH_ERROR,           /* FOTA AUTH Error */
    DM_STATE_FOTA_CHECKSUM_FAIL,        /* FOTA Checksum Fail */
    DM_STATE_ABORT,                     /* ABORT */
    DM_STATE_END
} DM_STATE_ENUM;


/* HTTP Authentication Inline caption */
typedef enum
{
    MMI_DM_FWU_INLINE_USERNAME_CAPTION,
    MMI_DM_FWU_INLINE_USERNAME,
    MMI_DM_FWU_INLINE_PASSWORD_CAPTION,
    MMI_DM_FWU_INLINE_PASSWORD
} mmi_dm_fwu_auth_inline_item_enum;


/* The buffer size when read data from file */
#define DM_FILE_BUFFER_SIZE             2048    

/* The buffer size when get data from TFTP */
#define DM_TFTP_BUFFER_SIZE             512+4   /* add 4 bytes for tftp header */

/* The buffer size when get data from HTTP */
#define DM_HTTP_BUFFER_SIZE             512

#define DM_TFTP_MAX_PORT_DIGITS         5

/* The maximum number of profiles */
#define DM_HTTP_MAX_WAP_PROF_SUM        16

/* The maximum time in seconds to wait HTTP response */
#define DM_HTTP_WPS_TIMEOUT   30

/* The maximum length of http auth username & password */
#define MMI_DM_AUTH_LEN_USERNAME 31
#define MMI_DM_AUTH_LEN_PASSWORD 31

#ifdef __MMI_FOTA_OTAP_DMP__
/* under construction !*/
#endif /*__MMI_FOTA_OTAP_DMP__*/

typedef struct {
    DM_UPGRADE_MEDIA_ENUM   upgrade_media;
    U8         state;     
    U8         is_da_changed;
    U8         *buffer;
    U16        percentage;
    U32        total_size;
    U32        cumul_size;       
    
    U8         job_id;
    U8         general_result_code;
    
    FS_HANDLE  fs_handle;    
    S8         full_filename_buffer[(DM_TFTP_MAX_FILENAME_LEN+1)*ENCODING_LENGTH];    
    
#if defined(__MMI_FWU_VIA_TFTP__)    
    U8         tftp_server_name[(DM_TFTP_MAX_SERVER_NAME_LEN+1)*ENCODING_LENGTH];
    U8         tftp_port[(DM_TFTP_MAX_PORT_DIGITS+1)*ENCODING_LENGTH];
    U8         tftp_da_name[(MAX_DATA_ACCOUNT_NAME_LEN+1)*ENCODING_LENGTH];
    U8         tftp_da_index;
    U8         *history_buffer;
#ifdef __MMI_FOTA_OTAP_DMP__
/* under construction !*/
#endif /*__MMI_FOTA_OTAP_DMP__*/
#endif /* #if defined(__MMI_FWU_VIA_TFTP__) */

#if defined(__MMI_FWU_VIA_HTTP__)
    U8         http_url[(DM_HTTP_MAX_URL_LEN)*ENCODING_LENGTH];
    UI_string_type    http_profile_str_p[DM_HTTP_MAX_WAP_PROF_SUM + 1];    /* default + profiles */
    UI_character_type http_profile_string[DM_HTTP_MAX_WAP_PROF_SUM][WAP_PROF_MAX_NAME_SIZE];    

    S32        http_profile_index;    
    S32        http_auth_request_id;
    
    U8         auth_username[ MMI_DM_AUTH_LEN_USERNAME * ENCODING_LENGTH];
    U8         auth_password[ MMI_DM_AUTH_LEN_PASSWORD * ENCODING_LENGTH];

    MMI_BOOL   more;
    U8         seqnum;
    
    U8         http_profile_sum; 

#endif /* #if defined(__MMI_FWU_VIA_HTTP__) */

} dm_fwu_context_struct;

#ifdef __MMI_FOTA_OTAP_DMP__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/************************************************************************
* Extern Functions
************************************************************************/
extern void mmi_dm_fwu_init_context(void);

extern void mmi_dm_fwu_highlight_hdlr(void);
extern void mmi_dm_entry_firmware_update(void);
extern U8 mmi_dm_fwu_main_del_callback(void *param);

extern void mmi_dm_fwu_tftp_highlight_hdlr(void);
extern void mmi_dm_fwu_tftp_upgrade_highlight_hdlr(void);
extern void mmi_dm_fwu_tftp_settings_highlight_hdlr(void);
extern void mmi_dm_fwu_entry_tftp(void);
extern void mmi_dm_fwu_entry_pre_tftp_settings(void);
extern void mmi_dm_fwu_entry_tftp_settings(void);
extern void mmi_dm_fwu_tftp_settings_submenu_highlight_hdlr(S32 index);
extern void mmi_dm_fwu_exit_tftp_settings(void);
extern void mmi_dm_fwu_save_tftp_settings(void);
extern void mmi_dm_fwu_tftp_DA_cb(U32 index);
extern void mmi_dm_fwu_entry_tftp_DA(void);
extern void mmi_dm_fwu_tftp_start_tftp_req(void);
extern void mmi_dm_fwu_tftp_start_tftp_cnf(void *inMsg);
extern void mmi_dm_fwu_tftp_stop_tftp_req(void);
extern void mmi_dm_fwu_tftp_stop_tftp_cnf(void *inMsg);
extern void mmi_dm_fwu_tftp_receive_ind(void *inMsg);
extern void mmi_dm_fwu_tftp_send_receive_rsp(void *inMsg);
extern void mmi_dm_fwu_tftp_result_ind(void *inMsg);
extern void mmi_dm_fwu_tftp_abort_tftp_req(void);

extern void mmi_dm_fwu_http_highlight_hdlr(void);
extern void mmi_dm_fwu_http_upgrade_highlight_hdlr(void);
extern void mmi_dm_fwu_http_settings_highlight_hdlr(void);
extern void mmi_dm_fwu_entry_http(void);
extern void mmi_dm_fwu_entry_pre_http_settings(void);
extern void mmi_dm_fwu_recv_wap_prof_list_cnf(void *inMsg);
extern void mmi_dm_fwu_entry_http_settings(void);
extern void mmi_dm_fwu_exit_http_settings(void);
extern void mmi_dm_fwu_save_http_settings(void);
extern void mmi_dm_fwu_http_settings_submenu_highlight_hdlr(S32 index);
extern void mmi_dm_fwu_http_get_profile_content_req(void);
extern void mmi_dm_fwu_http_get_profile_content_cnf(void *inMsg);
extern void mmi_dm_fwu_http_set_channel_req(void);
extern void mmi_dm_fwu_http_set_channel_cnf(void *inMsg);
extern void mmi_dm_fwu_http_send_http_req(void);
extern void mmi_dm_fwu_http_send_http_cnf(void *msgStruct, int mod_id , void *peer_buf);
extern void mmi_dm_fwu_recv_http_auth_ind(void *MsgStruct);
extern void mmi_dm_fwu_entry_auth_screen(void);
extern void mmi_dm_fwu_exit_auth_screen(void);
extern void mmi_dm_fwu_auth_confirm_hdlr(void);
extern void mmi_dm_fwu_auth_yes_hdlr(void);
extern void mmi_dm_fwu_auth_no_hdlr(void);
extern void mmi_dm_fwu_auth_full_screen_editor_options(void);
extern void mmi_dm_fwu_softkey_label_highlight_hdlr(S32 index);
extern void mmi_dm_fwu_auth_open_full_screen_editor(void);
extern void mmi_dm_fwu_auth_endkey_hdlr(void);
extern void mmi_dm_fwu_http_send_http_auth_res(void);
extern void mmi_dm_fwu_http_read_content_req(void);
extern void mmi_dm_fwu_http_read_content_cnf(void *msgStruct, int mod_id , void *peer_buf);
extern void mmi_dm_fwu_http_unset_channel_req(void);
extern void mmi_dm_fwu_http_unset_channel_cnf(void *inMsg);
extern void mmi_dm_fwu_http_abort_req(void);

extern void mmi_dm_fwu_file_highlight_hdlr(void);
extern void mmi_dm_fwu_entry_file_select(void);
extern void mmi_dm_fwu_file_select_callback(void *path, int is_short);
extern void mmi_dm_fwu_file_download_to_phone(void);
extern void mmi_dm_fwu_file_abort_download(void);
extern void mmi_dm_fwu_file_abort_result(void);

extern void mmi_dm_fwu_entry_confirm_setting(void);
extern void mmi_dm_fwu_entry_download_confirm(void);
extern void mmi_dm_fwu_entry_download_animation(void);
extern void mmi_dm_fwu_show_upgrade_percentage(S32 percentage);
extern void mmi_dm_fwu_entry_upgrade_now_confirm(void);
extern void mmi_dm_fwu_entry_shutdown_for_upgrade(void);
extern void mmi_dm_fwu_entry_download_result(void);
extern void mmi_dm_fwu_set_full_scr_edit_lsk(void);
extern void mmi_dm_fwu_construct_inline_item(U16 scr_id);
extern void mmi_dm_fwu_ignore_settings(void);
extern void mmi_dm_fwu_get_settings(U16 scr_id);
extern void mmi_dm_fwu_set_settings(U16 scr_id);
extern U8 mmi_dm_fwu_convert_result_code(U8 result);
extern void mmi_dm_fwu_send_msg(U16 src_mod_id, U16 msg_id, void *local_param_ptr, void *peer_buf_ptr);

extern void mmi_dm_fwu_fmt_fota_init_req(void);
extern void mmi_dm_fwu_fmt_fota_init_rsp(void *inMsg);
extern void mmi_dm_fwu_fmt_fota_write_data_req(U32 buffer_size);
extern void mmi_dm_fwu_fmt_fota_write_data_rsp(void *inMsg);
extern void mmi_dm_fwu_fmt_fota_finalize_req(void);
extern void mmi_dm_fwu_fmt_fota_finalize_rsp(void *inMsg);

extern void mmi_dm_fwu_tftp_proc_cca_doc(U16 conf_id, S32 doc_hdl);
extern mmi_dm_otap_struct *mmi_dm_fwu_tftp_new_otap_cntx(U16 conf_id, S32 doc_hdl);
extern void mmi_dm_fwu_tftp_send_cca_app_configure_res(U16 conf_id, S32 doc_hdl, cca_status_enum status);
extern cca_status_enum mmi_dm_fwu_tftp_proc_cca_nodes(
                    S32 doc_hdl, 
                    S32 node_hdl, 
                    U16 symbol, 
                    cca_iterator_struct *param_list, 
                    void *user_data);
extern void mmi_dm_fwu_tftp_free_otap_cntx(void);
extern void mmi_dm_fwu_tftp_entry_installation(void);
extern void mmi_dm_fwu_tftp_update_profile(void);
extern U8 mmi_dm_fwu_tftp_abort_otap_app(void *dummy);
extern void mmi_dm_fwu_tftp_abort_confirm_screen(void);
extern void mmi_dm_fwu_tftp_exit_otap_app(void);
extern U8 mmi_dm_fwu_tftp_is_prov_check(void);
extern void mmi_dm_fwu_tftp_start_auto_update(void);
extern void mmi_dm_fwu_tftp_ignore_auto_update(void);

#endif /* defined(__FOTA_ENABLE__) */

#endif /* __DEVICE_MANAGEMENT_INC_H_ */


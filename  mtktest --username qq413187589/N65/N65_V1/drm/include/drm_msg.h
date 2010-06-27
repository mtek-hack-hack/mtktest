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
 *  drm_msg.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef DRM_MSG_H
#define DRM_MSG_H
#ifdef __DRM_SUPPORT__

#include "wap_ps_struct.h"

typedef void (*drm_proc_callback) (kal_uint8 serial, kal_int32 result, kal_uint32 offset, kal_uint32 len);
typedef enum
{
    DRMT_PROCESS_DATABASE_SWEEP,
    DRMT_PROCESS_DATABASE_DELETE,
    DRMT_PROCESS_DATABASE_BACKUP,
    DRMT_PROCESS_DATABASE_RESTORE,

    DRMT_PROCESS_DATABASE_MAX    
}drmt_process_database_enum;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 serial;
    kal_uint32 new_path_len;
    kal_uint32 type;
    kal_wchar *file_path;
    kal_wchar *new_path;
    drm_proc_callback callback;
} drmt_process_object_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_int32 result;
    kal_uint8 serial;
    kal_wchar *new_path;
    kal_uint32 offset;
    kal_uint32 len;
    drm_proc_callback callback;
} drmt_process_object_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_int32 mime_type;
    kal_uint8 serial;
    kal_wchar *src_path;
    kal_bool src_is_buffer;
    kal_bool src_is_virtual;
    kal_bool src_need_kept;
    kal_wchar* dest_path;
    kal_uint32 dest_buffer_len_in_byte;
    kal_bool dest_need_output;
    void (*callback)(kal_uint8 serial, 
                     kal_int32 result, 
                     kal_char *dest_content_type, 
                     kal_char *dest_file_ext, 
                     kal_uint32 plaintext_len, 
                     kal_uint32 plaintext_offset_in_dm);
} drmt_install_object_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_int32 result;
    kal_uint8 serial;
    kal_char *dest_content_type;
    kal_char *dest_file_ext;
    kal_uint32 plaintext_len;
    kal_uint32 plaintext_offset_in_dm;    
    void (*callback)(kal_uint8 serial, 
                     kal_int32 result, 
                     kal_char *dest_content_type, 
                     kal_char *dest_file_ext, 
                     kal_uint32 plaintext_len, 
                     kal_uint32 plaintext_offset_in_dm);

} drmt_install_object_cnf_struct;


typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 type;
    kal_int32 index;
    kal_uint8 serial;
    kal_char path[260];
    kal_uint8 __nouse__;
} drmt_process_database_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
    kal_uint8 serial;
    kal_uint8 __nouse__;
} drmt_process_database_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_int32 id;
    kal_int32 result;
    void (*callback) (kal_int32 result, kal_int32 id);
} drmt_ro_expiry_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 session_id;
    kal_uint8 auth_type;
    kal_uint8 realm_len;
    kal_uint8 realm[256];
} drmt_get_auth_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 session_id;
    kal_uint8 username[WPS_MAX_AUTH_USERNAME_LENGTH];   /* coding in UTF8 */
    kal_uint8 password[WPS_MAX_AUTH_PASSWORD_LENGTH];   /* coding in UTF8 */
    kal_int32 user_len;
    kal_int32 pass_len;
} drmt_get_auth_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 session_id;
    kal_uint32 current;
    kal_uint32 total;
    kal_int8 info[256 *2];  /* coding in UCS2 */
} drmt_dl_progress_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 session_id;
} drmt_dl_progress_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 session_id;
    kal_uint16 title;
    kal_uint16 image;
    kal_uint16 category;    /* drmt_get_confirm_category_enum */
    kal_int8 msg[256 *2];   /* coding in UCS2 */
} drmt_get_user_confirm_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 session_id;
    kal_uint16 result;
} drmt_get_user_confirm_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 session_id;
    kal_int8 msg[32 *2];    /* coding in UCS2 */
    kal_int8 type;
} drmt_alert_user_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 session_id;
} drmt_alert_user_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 session_id;
    kal_uint16 title;
    kal_uint16 image;
    kal_int8 msg[512 *2];   /* coding in UCS2 */
} drmt_notify_info_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 session_id;
} drmt_notify_info_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 session_id;
} drmt_get_folder_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 session_id;
    kal_int8 path[260 *2];  /* coding in UCS2 */
} drmt_get_folder_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 session_id;
    kal_int8 default_name[260 *2];  /* FMGR_MAX_FILE_LEN , UCS2 */
} drmt_get_filename_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 session_id;
    kal_int8 filename[260 *2];
} drmt_get_filename_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 session_id;
    kal_uint8 option;   /* drmt_browser_option_enum */
    kal_uint8 __nouse__;
    kal_int8 url[768 *2];
} drmt_open_url_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 session_id;
    kal_uint8 result;   /* 0: ok , other : error */
} drmt_open_url_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 session_id;
} drmt_abort_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 session_id;
} drmt_abort_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 session_id;
} drmt_clean_screen_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 session_id;
} drmt_clean_screen_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 session_id;
    kal_int32 result;
    kal_uint8 imsi[17];
} drmt_get_imsi_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 session_id;
    drm_activate_callback callback;
    kal_uint8 serial;
    kal_int8 __nouse__;
    kal_int8 filepath[260 *2];
} drmt_activate_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 session_id;
    kal_int32 result;
    drm_activate_callback callback;
    kal_uint8 serial;
} drmt_activate_cnf_struct;
#endif /*__DRM_SUPPORT__*/
#endif /* DRM_MSG_H */ 


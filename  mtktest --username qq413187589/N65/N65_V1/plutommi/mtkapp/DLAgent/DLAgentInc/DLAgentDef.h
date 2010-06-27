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
 *
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef DOWNLOAD_AGENT_DEF_H
#define DOWNLOAD_AGENT_DEF_H

typedef enum
{
    MMI_DA_SUCCESS,
    MMI_DA_ERROR_CANCELLED = -1,
    MMI_DA_ERROR_INVALID_SESSION_ID = -2,
    MMI_DA_ERROR_CONNECTION_CLOSED = -3,
    MMI_DA_ERROR_INVALID_FILE = -4,
    MMI_DA_ERROR_DISK_FULL = -5,
    MMI_DA_ERROR_FILE_ACCESS = -6,
    MMI_DA_ERROR_BUSY = -1001,
    MMI_DA_ERROR_PARAMETER = -1002,
    MMI_DA_ERROR_SIZE_TOO_LARGE = -1003,
    MMI_DA_ERROR_FAIL = -9999
} mmi_da_error_enum;


typedef enum
{
    MMI_DA_STATE_INIT,
    MMI_DA_STATE_DOWNLOADING,
    MMI_DA_STATE_COMPLETE,
    MMI_DA_STATE_ABORT,
    MMI_DA_STATE_USER_CANCEL
} mmi_da_state_enum;


typedef enum
{
    MMI_DA_STORAGE_NONE,    /* decide by User */
    MMI_DA_STORAGE_PHONE,
    MMI_DA_STORAGE_MEMORY_CARD,

    MMI_DA_STORAGE_AUTO     /* auto choose PHONE or CARD */
    
} mmi_da_storage_enum;

typedef enum
{
    MMI_DA_NONE,
    MMI_DA_WAP_DOWNLOAD,                /* during WAP download */
    MMI_DA_OMA_DOWNLOAD,                /* file download from oma descriptor*/
    MMI_DA_SAVE_AS,                     /* file download from MMS or other AP*/
    MMI_DA_DOWNLOAD = MMI_DA_SAVE_AS,   /* [obsolete] file download from MMS or other AP, only used in 06B*/
    MMI_DA_WAP_SAVE,                    /* [obsolete] file download from WAP */
    MMI_DA_PUSH,                        /* push */
    MMI_DA_PUSH_SIM1 = MMI_DA_PUSH,     /* push from SIM1 */
    MMI_DA_PUSH_SIM2,                   /* push from SIM2 */

    MMI_DA_ACT_TOTAL
} mmi_da_action_enum;


typedef enum
{
    MMI_DA_BYPASS_FALSE,
    MMI_DA_BYPASS_LEVEL_1,  /* bypass without confirm screen before dispatch to AP */
    MMI_DA_BYPASS_LEVEL_2,  /* bypass without all prompt */
    MMI_DA_BYPASS_LEVEL_3   /* bypass even when it is a push object */
} mmi_da_bypass_level_enum;

typedef struct
{
    kal_uint8           ref_count;
    kal_uint16          msg_len;
    mmi_da_action_enum  action;
    kal_int32           mime_type;              /* applib_mime_type_enum */
    kal_int32           mime_subtype;           /* applib_mime_subtype_enum */
    kal_wchar           filepath[260+1];        /* FMGR_MAX_PATH_LEN, UCS2 */
    kal_wchar           filename[255+1];        /* FMGR_MAX_INPUT_FILE_LEN, UCS2 */
    kal_char            url[32];                /* mms:// or something indicate the source*/
    kal_char            mime_type_string[512];  /* WAP_DL_MAX_MIME_TYPE_LEN */
} mmi_da_dispatch_file_req_struct;

typedef struct
{
    kal_uint32          header_len;
    kal_uint8           header[1];              /* Please alloc enough memory to expand the array*/
} mmi_da_dispatch_file_var_struct;

/*
    ex:
    peer_buff_ptr = construct_peer_buff(
        sizeof(mmi_da_dispatch_file_var_struct) + header_len ,
        0 , 0 , TD_RESET);

    peer_buff_ptr->header_len = header_len;
    mempcy( peer_buff_ptr->header, header, len);
 */

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    mmi_da_error_enum error;
} mmi_da_dispatch_file_rsp_struct;

typedef enum
{
    MMI_DA_WAP_NOTIFY_DISPLAY_LIST,
    MMI_DA_WAP_NOTIFY_BROWSER_CLOSED,

    MMI_DA_WAP_NOTIFY_NUM
    
} mmi_da_wap_notify_enum;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint32  job_count;
    kal_uint32  active_job_count;
} mmi_da_download_info_ind_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    mmi_da_wap_notify_enum  notify;
} mmi_da_wap_notify_ind_struct;



/******************************************************************
 * OLD DOWNLOAD AGENT TYPE, THIS MUSH REMOVE AFTER JATAUYU SUPPORT
 ******************************************************************/
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_int32 session_id;
    mmi_da_action_enum action_type;
    kal_wchar *tmp_file;                /* UCS2 Max_len: FMGR_MAX_FILE_LEN+FMGR_MAX_PATH_LEN */
    kal_char *mime_type_string;         /* ASCII */
    kal_char *download_url;             /* ASCII */
    kal_int32 mod_id;                   /* module_type */
} mmi_da_get_file_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_int32 session_id;
    kal_int32 error_code;
} mmi_da_get_file_res_struct;

/******************************************************************
 * END of OLD DOWNLOAD AGENT TYPE, THIS MUSH REMOVE AFTER JATAUYU SUPPORT
 ******************************************************************/

#endif /* DOWNLOAD_AGENT_DEF_H */


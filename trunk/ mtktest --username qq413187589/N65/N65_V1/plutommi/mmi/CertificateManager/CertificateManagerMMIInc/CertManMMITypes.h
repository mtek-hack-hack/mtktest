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
 *  Modification Notice:
 *  --------------------------
 *  This software is modified by MediaTek Inc. and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/
 /*****************************************************************************
 *
 * Filename:
 * ---------
 *  CertManMMITypes.h
 *
 * Project:
 * --------
 * 
 *
 * Description:
 * ------------
 * This file contains constants, enums and structures
 *
 * Author:
 * ------------
 * -------
 *
************************************************************************************/
/* ShriKant */

#ifndef MMI_CERTMAN_TYPES_H
#define MMI_CERTMAN_TYPES_H

#ifdef __CERTMAN_SUPPORT__

#define MMI_CERTMAN_MIN_PASSWORD_LENGTH  0

#define MMI_CERTMAN_MAX_KEY_PURPOSE_LENGTH   50
#define MMI_CERTMAN_MAX_PROTECTION_METHODS 3
#define MMI_CERTMAN_POPUP_DURATION 1000
#define MMI_CERTMAN_MEM_SIZE 1024*9
#define MMI_CERTMAN_MAX_FIELD_SIZE 256

typedef enum
{
    MMI_CERTMAN_IDLE,
    MMI_CERTMAN_IMPORT,
    MMI_CERTMAN_LAUNCH,
    MMI_CERTMAN_SELECT,
    MMI_CERTMAN_PRIVATE_KEY_PWD,
    MMI_CERTMAN_PRIVATE_KEY_CONFIRM,
    MMI_CERTMAN_VIEW,
    MMI_CERTMAN_INVALID,
    MMI_CERTMAN_USER_CERT_LIST
} mmi_certman_status_enum;

/**************************************************************************/
/*****************************IMPORT CERTIFICATES**************************/
/**************************************************************************/

typedef enum
{
    MMI_CERTMAN_IMPORT_IDLE = 0,
    MMI_CERTMAN_IMPORT_CHECK_ENCODING,
    MMI_CERTMAN_IMPORT_GET_DECR_PWD,
    MMI_CERTMAN_IMPORT_PARSING,
    MMI_CERTMAN_IMPORT_DISPLAY_TOTAL_PCERT,
    MMI_CERTMAN_IMPORT_DISPLAY_FILE_INFO,
    MMI_CERTMAN_IMPORT_DETAIL_REQUEST,
    MMI_CERTMAN_IMPORT_DISPLAY,
    MMI_CERTMAN_IMPORT_GET_CERT_INFO,
    MMI_CERTMAN_IMPORT_IMPORT,
    MMI_CERTMAN_IMPORT_SET_KEY_PURPOSE,
    MMI_CERTMAN_IMPORT_END_PARSING
} mmi_certman_import_state_enum;

typedef struct
{
    U8 password[CERTMAN_PASSWORD_SIZE *ENCODING_LENGTH];
    U8 privatekey_pwd[CERTMAN_PKPWD_SIZE + 2];
    U8 privatekey_cnf_pwd[CERTMAN_PKPWD_SIZE + 2];
    U8 certificate_label[CERTMAN_LABEL_SIZE];
    U16 job_id;
    U16 cert_total;
    U16 count;
    U16 num_priv_key;
    U16 current_state;
    U32 protection_method;
    U32 cert_ref_ids[CERTMAN_NUM_PARSED_CERT];
    U32 trans_id;
    U32 cert_group;
    U32 key_purpose;
    U32 cert_id;
    certman_ctx_parse_struct *ctx_parse_p;
    certman_ctx_import_struct *ctx_import_p;
    certman_parsed_data_struct *parsed_data_p;

} mmi_certman_import_context_struct;

/**************************************************************************/
/*****************************LAUNCH / SELECT CERTIFICATES*****************/
/**************************************************************************/
typedef enum
{
    MMI_CERTMAN_LAUNCH_SELECT_IDLE = 0,
    MMI_CERTMAN_LAUNCH_SELECT_GROUP_REQ,
    MMI_CERTMAN_LAUNCH_SELECT_CREATE_LIST,
    MMI_CERTMAN_LAUNCH_SELECT_DISPLAY_LIST,
    MMI_CERTMAN_LAUNCH_SELECT_VIEW_CERT
} mmi_certman_launch_state_enum;

typedef struct
{
    U32 cert_id;
    U32 cert_prop;
    U32 cert_group;
    U32 key_purpose;
    U8 cert_label[CERTMAN_LABEL_SIZE];
} mmi_certman_certificate_list_struct;

typedef struct
{
    U32 count;
    U32 cert_ids[MMI_CERTMAN_CERTIFICATES_MAX];
    /* U8 label[CERTMAN_LABEL_SIZE]; */
} mmi_certman_certificate_ids_struct;

typedef struct
{
    U16 job_id;
    U16 selected_index;
    U16 current_state;
    U32 trans_id;
    U32 cert_group;
    S32 multiple_selection_flag;
    U32 certificate_count;
    certman_cert_display_struct *display_p;
    U8 is_selected[MMI_CERTMAN_CERTIFICATES_MAX];
    mmi_certman_certificate_list_struct certificate_list[MMI_CERTMAN_CERTIFICATES_MAX];
} mmi_certman_launch_select_context_struct;

/**************************************************************************/
/*****************************Private Key Protection Method****************/
/**************************************************************************/

typedef struct
{
    U8 label[CERTMAN_LABEL_SIZE];
    U8 privatekey_pwd[CERTMAN_PASSWORD_SIZE *ENCODING_LENGTH];
    U32 cert_id;
    U32 trans_id;
    certman_fp_pwd_cb pwd_callback;
} mmi_certman_private_key_context_struct;

/***************************************************************************/
/*****************************View / Invalid Certificate********************/
/***************************************************************************/
typedef enum
{
    MMI_CERTMAN_VIEW_INVALID_IDLE = 0,
    MMI_CERTMAN_VIEW_INVALID_PARSING,
    MMI_CERTMAN_VIEW_INVALID_DETAIL,
    MMI_CERTMAN_VIEW_INVALID_DISPLAY,
    MMI_CERTMAN_VIEW_INVALID_CERT_LABEL,
    MMI_CERTMAN_VIEW_INVALID_IMPORT,
    MMI_CERTMAN_VIEW_INVALID_PARSE_END
} mmi_certman_view_invalid_state_enum;

typedef struct
{
    pBOOL install_option;
    U8 label[CERTMAN_LABEL_SIZE];
    U16 job_id;
    U16 current_state;
    U32 trans_id;
    U32 error;
    U32 cert_id;
    U32 ref_id;
    U8 mod_name[16];
    certman_ctx_parse_struct *ctx_parse_p;
    certman_ctx_import_struct *ctx_import_p;
    certman_parsed_data_struct *parsed_data_p;
} mmi_certman_view_invalid_context_struct;

/***************************************************************************/
/*****************************User Certificate List*************************/
/***************************************************************************/

typedef enum
{
    MMI_CERTMAN_USER_CERT_LIST_IDLE = 0,
    MMI_CERTMAN_USER_CERT_LIST_BY_ISSUERS_FILE_REQ,
    MMI_CERTMAN_USER_CERT_LIST_BY_ISSUERS_DATA_IND,
    MMI_CERTMAN_USER_CERT_LIST_DISPLAY
} mmi_certman_user_cert_list_state_enum;
typedef struct
{
    U16 current_state;
    U16 cert_count;
    U16 selected_index;
    U32 trans_id;
    U32 cert_group;
    U32 key_purpose;
    U8 label[CERTMAN_LABEL_SIZE];
    mmi_certman_certificate_list_struct certificate_list[MMI_CERTMAN_CERTIFICATES_MAX];
} mmi_certman_user_certificates_list;

typedef struct
{
    mmi_certman_import_context_struct *import_context_p;    /* Import */
    mmi_certman_launch_select_context_struct *launch_select_context_p;  /* Launch Select */
    mmi_certman_private_key_context_struct *priv_key_context_p; /* Private key protection */
    mmi_certman_view_invalid_context_struct *view_invalid_context_p;
    mmi_certman_user_certificates_list *user_cert_list_context_p;
    U8 show_string[MMI_CERTMAN_TOTAL_KEY_USAGE *(MMI_CERTMAN_MAX_KEY_PURPOSE_LENGTH + ENCODING_LENGTH)];
    U8 key_usage_list[MMI_CERTMAN_TOTAL_KEY_USAGE][MMI_CERTMAN_MAX_KEY_PURPOSE_LENGTH];
    U8 *selected_protection_method[MMI_CERTMAN_MAX_PROTECTION_METHODS];
    U8 list_of_state[MMI_CERTMAN_TOTAL_KEY_USAGE];
    KAL_ADM_ID adm_id;
    kal_uint32 mem_pool[MMI_CERTMAN_MEM_SIZE / 4];
    U16 popup_string_id;
    U16 screen_id;
    U32 current_status;
    U8 *cert_info;
    void (*entry_fun) (void);
    void *rsp_msg_p;
    void (*popup_handler_callback) (void);
    module_type src_module;
} mmi_certman_context;

#endif /* __CERTMAN_SUPPORT__ */ 
#endif /* MMI_CERTMAN_TYPES_H */ 


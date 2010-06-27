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
 * CertManMMIGprots.h
 *
 * Project:
 * --------
 * 
 *
 * Description:
 * ------------
 * This file contains declaration of all the interface function
 *
 * Author:
 * ------------
 * -------
 *
************************************************************************************/

#ifndef MMI_CERTMAN_GPROTS_H
#define MMI_CERTMAN_GPROTS_H

#ifdef __CERTMAN_SUPPORT__

#include "certman_api.h"
/* #include "CertManMMITypes.h" */

#define MMI_CERTMAN_CERTIFICATES_MAX  100
#define MMI_CERTMAN_MAX_CERT_TYPES 10

typedef enum
{
    MMI_CERTMAN_OPEN = 0,
    MMI_CERTMAN_CANCEL
} mmi_certman_action_enum;

typedef enum
{
    MMI_CERTMAN_INVALID_CERT_INSTALL = 0,
    MMI_CERTMAN_INVALID_CERT_ACCEPT,
    MMI_CERTMAN_INVALID_CERT_DENY
} mmi_certman_invalid_certificate_action_enum;

typedef enum
{
    MMI_CERTMAN_CERT_TYPE_RSA_SIGN = CERTMAN_PUBKEY_RSA,
    MMI_CERTMAN_CERT_TYPE_DSA_SIGN,
    MMI_CERTMAN_CERT_TYPE_DH_ANSI_SIGN,
    MMI_CERTMAN_CERT_TYPE_DH_PKCS3_SIGN,
    MMI_CERTMAN_CERT_TYPE_EC_SIGN
} mmi_certman_cert_type_enum;

typedef enum
{
    MMI_CERTMAN_CERT_GROUP_ALL = 0,
    MMI_CERTMAN_CERT_GROUP_ROOT_CA,
    MMI_CERTMAN_CERT_GROUP_INTERMEDIATE_CA,
    MMI_CERTMAN_CERT_GROUP_AUTHORITY,
    MMI_CERTMAN_CERT_GROUP_OTHER_USER,
    MMI_CERTMAN_CERT_GROUP_PERSONAL,
    MMI_CERTMAN_CERT_GROUP_USER
} mmi_certman_cert_group_enum;

typedef enum
{
    MMI_CERTMAN_UPDATE_ACTION_ADD = 0,
    MMI_CERTMAN_UPDATE_ACTION_DELETE,
    MMI_CERTMAN_UPDATE_ACTION_DELETE_ALL,
    MMI_CERTMAN_UPDATE_ACTION_MODIFY
} mmi_certman_update_action_enum;

typedef enum
{
    MMI_CERTMAN_CERT_WARN_NONE = 0x00000000,
    MMI_CERTMAN_WARN_CHAIN = 0x00000001,
    MMI_CERTMAN_WARN_BCONST_NOT_CRITICAL = 0x00000002,
    MMI_CERTMAN_WARN_UNKNOWN_CRITICAL_EXT = 0x00000004,
    MMI_CERTMAN_WARN_VALIDITY = 0x00000008,
    MMI_CERTMAN_WARN_NO_KEY_USAGE = 0x00000010,
    MMI_CERTMAN_WARN_KEY_MISUSE = 0x00000020,
    MMI_CERTMAN_WARN_BCONST_FAIL = 0x00000040,
    MMI_CERTMAN_WARN_NO_TRUSTED_CERTS = 0x00000080,
    MMI_CERTMAN_WARN_INVALID_SIGNATURE = 0x00000100,
    MMI_CERTMAN_WARN_INTERNAL = 0x00000200,
    MMI_CERTMAN_WARN_TRUSTED_KEY_MISUSE = 0x00000400,
    MMI_CERTMAN_WARN_TRUSTED_EXPIRED = 0x00000800,
    MMI_CERTMAN_WARN_CORRUPTED_CERT = 0x00001000,
    MMI_CERTMAN_WARN_TRUSTED_NO_KEY_USAGE = 0x00002000,
    MMI_CERTMAN_WARN_NO_CERT_HASH = 0x00004000,
    MMI_CERTMAN_WARN_URLS_DONT_MATCH = 0x00008000
} mmi_certman_invalid_error_enum;

typedef enum
{
    MMI_CERTMAN_KP_SERVER_AUTH = 0,
    MMI_CERTMAN_KP_CLIENT_AUTH,
    MMI_CERTMAN_KP_CODE_SIGNING,
    MMI_CERTMAN_KP_EMAIL_PROTECTION,
    MMI_CERTMAN_KP_IPSEC_ENDSYSTEM,
    MMI_CERTMAN_KP_IPSEC_TUNNEL,
    MMI_CERTMAN_KP_IPSEC_USER,
    MMI_CERTMAN_KP_TIME_STAMPING,
    MMI_CERTMAN_KP_OCSP_SIGNING,
    MMI_CERTMAN_TOTAL_KEY_USAGE
} mmi_certman_keypurpose_enum;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool action;
    kal_uint32 trans_id;
    kal_wchar cert_filename[200];
} mmi_certman_install_cert_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
    kal_uint32 trans_id;
} mmi_certman_install_cert_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool action;
    kal_uint32 trans_id;
} mmi_certman_launch_cert_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
    kal_uint32 trans_id;
} mmi_certman_launch_cert_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool action;
    kal_bool multiple_selection_flag;
    kal_uint32 trans_id;
    mmi_certman_cert_group_enum cert_group;
} mmi_certman_select_cert_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
    kal_uint32 trans_id;
    kal_uint32 count;
    kal_uint32 cert_ids[MMI_CERTMAN_CERTIFICATES_MAX];
} mmi_certman_select_cert_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool action;
    kal_uint32 trans_id;
    kal_wchar filename[200];
} mmi_certman_view_cert_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
    kal_uint32 trans_id;
} mmi_certman_view_cert_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool action;
    kal_bool disable_install_option;
    kal_uint32 error;
    kal_wchar mod_name[16];
    kal_uint32 trans_id;
    kal_wchar cert_filename[200];
} mmi_certman_invalid_cert_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
    kal_uint32 trans_id;
    kal_uint16 invalid_cert_action;
} mmi_certman_invalid_cert_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool action;
    kal_uint8 cert_type_len;
    kal_uint8 cert_types[MMI_CERTMAN_MAX_CERT_TYPES];
    kal_uint32 key_purpose;
    kal_wchar mod_name[16];
    kal_uint32 trans_id;
    kal_wchar issuer_filename[200];
} mmi_certman_select_user_cert_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
    kal_uint32 trans_id;
    kal_uint32 personal_cert_id;
} mmi_certman_select_user_cert_rsp_struct;

extern void mmi_certman_install_certificates_ind(
                module_type src_mod,
                kal_bool action,
                kal_uint32 trans_id,
                kal_wchar *filename);
extern void mmi_certman_install_certificates_rsp(kal_bool result, kal_uint32 trans_id);
extern void mmi_certman_launch_certificates_ind(module_type src_mod, kal_bool action, kal_uint32 trans_id);
extern void mmi_certman_launch_certificates_rsp(kal_bool result, kal_uint32 trans_id);
extern void mmi_certman_select_certificates_ind(
                module_type src_mod,
                kal_bool action,
                kal_bool multiple_selection_flag,
                kal_uint32 trans_id,
                mmi_certman_cert_group_enum cert_group);
extern void mmi_certman_select_certificates_rsp(
                kal_bool result,
                kal_uint32 count,
                kal_uint32 *certificate_ids,
                kal_uint32 trans_id);
extern void mmi_certman_view_certificates_ind(
                module_type src_mod,
                kal_bool action,
                kal_wchar *filename,
                kal_uint32 trans_id);
extern void mmi_certman_view_certificates_rsp(kal_bool result, kal_uint32 trans_id);

/* extern void mmi_certman_invalid_certificates_ind(module_type src_mod, pBOOL action, U8 *filename); */
extern void mmi_certman_invalid_certificates_ind(
                module_type src_mod,
                kal_bool action,
                kal_bool disable_install,
                kal_uint32 error,
                kal_wchar *mod_name,
                kal_wchar *cert_filename,
                kal_uint32 trans_id);

extern void mmi_certman_invalid_certificates_rsp(kal_uint16 invalid_cert_action, kal_uint32 trans_id);
extern void mmi_certman_select_user_certificates_ind(
                module_type src_mod,
                kal_bool action,
                kal_uint32 key_purpose,
                kal_uint8 cert_type_len,
                kal_uint8 *cert_types,
                kal_wchar *mod_name,
                kal_wchar *issuers_filename,
                kal_uint32 trans_id);
extern void mmi_certman_select_user_certificates_rsp(kal_uint32 cert_id, kal_bool result, kal_uint32 trans_id);

extern void mmi_certman_install_certificates_ind_handler(void *msg);
extern void mmi_certman_launch_certificates_ind_handler(void *msg);
extern void mmi_certman_select_certificates_ind_handler(void *msg);
extern void mmi_certman_view_certificates_ind_handler(void *msg);
extern void mmi_certman_select_user_certificates_ind_handler(void *msg);
extern void mmi_certman_invalid_certificates_ind_handler(void *msg);
extern void mmi_certman_deinit(void);
extern void mmi_certman_highlight_install(void);
extern void mmi_certman_highlight_launch_certficate_manager(void);

extern void mmi_certman_parse_begin_cnf_handler(void *);
extern void mmi_certman_certificates_detail_cnf_handler(void *);
extern void mmi_certman_import_cnf_handler(void *);
extern void mmi_certman_send_parse_end_cnf_handler(void *);
extern void mmi_certman_import_update_key_purpose_cnf_handler(void *);
extern void mmi_certman_send_delete_cert_cnf_handler(void *msg);
extern void mmi_certman_send_delete_all_cert_cnf_handler(void *msg);
extern void mmi_certman_get_cert_list_by_group_cnf_handler(void *msg);
extern void mmi_certman_send_get_cert_disp_by_id_cnf_handler(void *msg);
extern void mmi_certman_launch_update_key_purpose_cnf_handler(void *msg);
extern void mmi_certman_privkey_usage_password_ind_handler(void *msg);
extern void mmi_certman_send_privkey_usage_confirm_ind_handler(void *msg);
extern void mmi_certman_get_cert_list_by_issuers_file_cnf_handler(void *msg);
extern void mmi_certman_get_cert_list_by_issuers_data_ind_handler(void *msg);
extern kal_bool mmi_certman_get_cert_label(kal_uint32 cert_id, kal_uint8 *label_buffer, kal_uint32 buf_size);

#endif /* __CERTMAN_SUPPORT__ */ 
#endif /* MMI_CERTMAN_GPROTS_H */ 


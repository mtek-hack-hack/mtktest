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
 *  inet_msg_api.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains public functions in inet message library.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _INET_MSG_API_H
#define _INET_MSG_API_H

/* if some header should be include before this one */

/* Common inet message structures */
#include "inet_msg_def.h"
#include "inet_msg_struct.h"
#include "inet_msg_res.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#define INET_RM_HDR(inet,  id, name) \
    inet_msg_rm_header_field((inet), (INET_MSG_PROCESS_HEADER), 0, 0, (id), name)

#define INET_RM_DUP_HDR(inet,  id, name) \
    inet_msg_rm_header_field((inet), (INET_MSG_PROCESS_HEADER), 0, -1, (id), name)

#define INET_GET_BDY_HDR_STRUCT_VAL(app_type, inet, bdy_num, id, val) \
    inet_msg_get_header_field(app_type, (inet), (INET_MSG_PROCESS_BODY), 0, bdy_num, (id), NULL, INET_MSG_HDR_VAL_STRUCT, val)

#define INET_GET_BDY_HDR_STRING_VAL(app_type, inet, bdy_num, id, val) \
    inet_msg_get_header_field(app_type, (inet), (INET_MSG_PROCESS_BODY), 0, bdy_num, (id), NULL, INET_MSG_HDR_VAL_STRING, val)

#define INET_GET_DUP_HDR_STRUCT_VAL(app_type, inet,  no, id, val) \
    inet_msg_get_header_field(app_type, (inet), (INET_MSG_PROCESS_HEADER), no, 0, (id), NULL, INET_MSG_HDR_VAL_STRUCT, val)

#define INET_GET_HDR_STRUCT_VAL(app_type, inet,  id, val) \
    inet_msg_get_header_field(app_type, (inet), (INET_MSG_PROCESS_HEADER), 0, 0, (id), NULL, INET_MSG_HDR_VAL_STRUCT, val)

#define INET_GET_HDR_STRING_VAL(app_type, inet, id, name, val) \
    inet_msg_get_header_field(app_type, (inet), (INET_MSG_PROCESS_HEADER), 0, 0, (id), name, INET_MSG_HDR_VAL_STRING, val)

#define INET_INSERT_HDR_TO_FIRST_OF_HDR_LIST(inet, id, name, val) \
    inet_msg_add_header_field((inet), (INET_MSG_PROCESS_HEADER), 0, INET_HDR_IM_ADD_TO_FIRST, (id), (name), INET_MSG_HDR_VAL_STRUCT, val)

#define INET_INSERT_HDR_STRING_TO_FIRST_OF_HDR_LIST(inet, id, name, val) \
    inet_msg_add_header_field((inet), (INET_MSG_PROCESS_HEADER), 0, INET_HDR_IM_ADD_TO_FIRST, (id), (name), INET_MSG_HDR_VAL_STRING, val)

#define INET_APPEND_HDR_TO_HDR_LIST(inet, id, name, val) \
    inet_msg_add_header_field((inet), (INET_MSG_PROCESS_HEADER), 0, INET_HDR_IM_ADD_TO_LAST, (id), (name), INET_MSG_HDR_VAL_STRUCT, val)

#define INET_APPEND_HDR_STRING_TO_HDR_LIST(inet, id, name, val) \
    inet_msg_add_header_field((inet), (INET_MSG_PROCESS_HEADER), 0, INET_HDR_IM_ADD_TO_LAST, (id), (name), INET_MSG_HDR_VAL_STRING, val)

#define INET_APPEND_HDR_TO_BODY_LIST(inet, num, id, name,val) \
    inet_msg_add_header_field((inet), (INET_MSG_PROCESS_BODY), num, INET_HDR_IM_ADD_TO_LAST, (id), (name), INET_MSG_HDR_VAL_STRUCT, val)

#define INET_APPEND_HDR_STRING_TO_BODY_LIST(inet, num, id, name,val) \
    inet_msg_add_header_field((inet), (INET_MSG_PROCESS_BODY), num, INET_HDR_IM_ADD_TO_LAST, (id), (name), INET_MSG_HDR_VAL_STRING, val)
/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

extern inet_result_enum inet_msg_initialize(
                            kal_uint8 app_type,
                            inet_mem_func_struct *mem_func,
                            inet_message_struct *inet);

extern inet_result_enum inet_msg_deinitialize_body(inet_message_struct *inet_msg);

extern inet_result_enum inet_msg_deinitialize(inet_message_struct *inet_msg);

extern inet_result_enum inet_msg_unpack_header_into_msg(
                    inet_message_struct *inet_msg,
                    kal_uint8 app_type,
                    kal_uint16 unpack_mode,
                    kal_char *buffer,
                    kal_int32 buffer_size,
                    kal_wchar *filepath,
                    kal_wchar *folder_store_bodies);


extern inet_result_enum inet_msg_unpack(
                            inet_message_struct *inet_msg,
                            kal_uint8 app_type,
                            kal_uint16 unpack_mode,
                            kal_char *buffer,
                            kal_int32 buffer_size,
                            kal_wchar *filepath,
                            kal_wchar *folder_store_bodies);

extern inet_result_enum inet_msg_unpack_body_into_msg(inet_message_struct *inet_msg, kal_uint8 app_type, kal_uint16 unpack_mode, kal_char *buffer, kal_int32 buffer_size, kal_wchar *filepath, kal_wchar *folder_store_bodies);     /* kevin */

extern inet_result_enum inet_msg_pack_required_size(
                            inet_message_struct *inet_msg,
                            kal_uint8 app_type,
                            kal_uint16 pack_mode,
                            kal_int32 *size);

extern inet_result_enum inet_msg_pack(
                            inet_message_struct *inet_msg,
                            kal_uint8 app_type,
                            kal_uint16 pack_mode,
                            kal_char *buffer,
                            kal_int32 buffer_size,
                            kal_wchar *filepath);

extern kal_bool inet_msg_is_request(inet_message_struct *inet_msg, kal_uint8 app_type);

extern kal_int32 inet_msg_get_header_field_num(
                    inet_message_struct *inet_msg,
                    kal_uint8 process_part,
                    kal_int32 body_num,
                    inet_header_field_enum header_id,
                    kal_char *header_name);

extern inet_result_enum inet_msg_get_header_field(
                            kal_uint8 app_type,
                            inet_message_struct *inet,
                            kal_uint8 process_part,
                            kal_int32 index_in_dup_headers,
                            kal_int32 body_num,
                            inet_header_field_enum header_id,
                            kal_char *header_name,
                            kal_uint8 header_value_form,
                            kal_uint32 *header_value);

extern inet_result_enum inet_msg_add_header_field(
                            inet_message_struct *inet_msg,
                            kal_uint8 process_part,
                            kal_int32 body_num,
                            kal_int32 insert_mode,
                            inet_header_field_enum header_id,
                            kal_char *header_name,
                            kal_uint8 header_value_form,
                            kal_uint32 header_value);

extern inet_result_enum inet_msg_rm_header_field(
                            inet_message_struct *inet,
                            kal_uint8 process_part,
                            kal_int32 index_in_duplicate_headers,
                            kal_int32 body_num,
                            inet_header_field_enum header_id,
                            kal_char *header_name);

extern inet_result_enum inet_msg_cp_header_field(
                            kal_uint8 app_type,
                            inet_message_struct *inet_src_msg,
                            kal_uint8 src_process_part,
                            kal_int32 src_index_in_dup_hdr,
                            kal_int32 src_body_num,
                            inet_header_field_enum header_id,
                            kal_char *header_name,
                            inet_message_struct *inet_dst_msg,
                            kal_uint8 dst_process_part,
                            kal_int32 dst_body_num,
                            kal_int32 insert_mode);

extern inet_result_enum inet_msg_cp_header_field_alone(
                            kal_uint8 app_type,
                            inet_mem_func_struct *mem_func,
                            inet_header_field_enum header_id,
                            void *src_header,
                            void **dst_header);

extern inet_result_enum inet_msg_get_body_data(
                            inet_message_struct *inet_msg,
                            kal_int32 body_num,
                            kal_char **buffer,
                            kal_int32 *buffer_size,
                            kal_wchar **filepath,
                            kal_uint32 *offset,
                            kal_uint32 *length);

extern inet_result_enum inet_msg_add_body_data(
                            inet_message_struct *inet_msg,
                            kal_int32 body_num,
                            kal_char *buffer,
                            kal_int32 buffer_size,
                            kal_wchar *filepath,
                            kal_uint32 offset,
                            kal_uint32 length);

extern inet_result_enum inet_msg_rm_body_file(inet_message_struct *inet_msg, kal_int32 body_num);

extern inet_result_enum inet_msg_cp_body_part(
                            kal_uint8 app_type,
                            inet_message_struct *inet_src_msg,
                            inet_message_struct *inet_dst_msg,
                            kal_int32 src_body_num,
                            kal_int32 dst_body_num);

extern inet_result_enum inet_auth_gen_authorization(
                            module_type mod_id,
                            inet_mem_func_struct *mem_func,
                            inet_authenticate_struct *authenticate,
                            inet_method_enum method,
                            kal_char *url,
                            kal_uint32 nc,
                            kal_char *username,
                            kal_char *password,
                            kal_uint8 *body_data,
                            kal_uint32 body_data_size,
                            kal_wchar *body_data_filepath,
                            kal_uint8 *hentity_md5_array,
                            inet_authorization_struct **authorization,
                            kal_char **rspauth);

extern inet_result_enum inet_msg_reserve_header_list_alone(inet_header_field_enum header_id, void *arg);

extern inet_result_enum inet_msg_rm_all_header_fields(
                            inet_message_struct *inet_msg,
                            kal_uint8 process_part,
                            kal_int32 body_num);

extern kal_int32 inet_msg_get_body_num(inet_message_struct *inet_msg);

/***************************************************************************** 
* Inet message utilities functions
*****************************************************************************/
extern kal_bool inet_msg_add_int_object_to_list(
                    inet_mem_func_struct *mem_func,
                    inet_int_list_struct **list,
                    kal_int32 int_val);

extern kal_bool inet_msg_add_str_object_to_list(
                    inet_mem_func_struct *mem_func,
                    inet_str_list_struct **list,
                    kal_char *str_val);

extern kal_bool inet_msg_add_int_str_object_to_list(
                    inet_mem_func_struct *mem_func,
                    inet_int_str_list_struct *list,
                    kal_int32 int_val,
                    kal_char *str_val);

extern kal_bool inet_msg_add_cookie_to_list(
                    inet_mem_func_struct *mem_func,
                    inet_cookie_list_struct **list,
                    inet_cookie_struct *cookie);

extern void inet_msg_get_token(kal_char *src, kal_uint32 src_len, kal_uint32 *len);

extern kal_int16 inet_msg_compare_cstring(kal_char *s1, kal_char *s2);

extern kal_char *inet_msg_ucase(kal_char *s);

extern kal_char *inet_msg_lcase(kal_char *s);

extern kal_char *inet_msg_mime_quote(kal_char *src);

extern void inet_msg_skipws(kal_char **s);

extern void inet_msg_mime_skipws(kal_char **s);

extern void inet_msg_skipcfws(kal_char **s);

extern kal_char *inet_msg_mime_skip_comment(kal_char **s, kal_int32 trim);

extern void inet_msg_trimcfws(kal_char *s);

extern kal_char *inet_msg_strdup(inet_mem_func_struct *mem_func, const kal_char *s);

extern kal_char *inet_msg_get_line(inet_mem_struct *mem);

extern kal_char *inet_msg_get_param_val(inet_param_list_struct *list, kal_char *param_name);

extern inet_param_struct *inet_msg_get_param(inet_param_list_struct *list, kal_char *param_name);     /* kevin */

extern kal_char *inet_msg_get_next_token(kal_char *text);

extern const kal_char *inet_msg_get_method_string(kal_uint8 method);

extern kal_bool inet_msg_reverse_addr_list(inet_addr_list_struct **in_addrs_list);

extern inet_result_enum inet_msg_get_header_pack_size(
                            kal_uint8 app_type,
                            inet_mem_func_struct *mem_func,
                            inet_header_field_enum header_id,
                            void *arg,
                            kal_int32 *r_size);

extern kal_char *inet_msg_struct_2_string(
                    kal_uint8 app_type,
                    inet_mem_func_struct *mem_func,
                    inet_header_field_enum header_id,
                    void *arg);

extern kal_bool inet_msg_check_value_in_int_list(inet_int_list_struct *list, kal_int32 int_val);

extern kal_bool inet_msg_rm_param_object_from_list(
                    inet_mem_func_struct *mem_func,
                    inet_param_list_struct **list,
                    kal_char *name,
                    kal_char *value /* could be null */ );

extern kal_int32 inet_msg_get_param_object_num(inet_param_list_struct *list);

extern kal_bool inet_msg_add_param_object_to_list(
                    inet_mem_func_struct *mem_func,
                    inet_param_list_struct **list,
                    kal_char *name,
                    kal_char *value);

extern kal_bool inet_msg_check_value_in_str_list(inet_str_list_struct *list, kal_char *str_val);

extern kal_bool inet_msg_check_value_in_int_str_list(
                    inet_int_str_list_struct *list,
                    kal_int32 int_val,
                    kal_char *str_val);

#endif /* _INET_MSG_API_H */ 


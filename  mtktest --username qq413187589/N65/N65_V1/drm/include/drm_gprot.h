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
 * drm_gprot.h
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
#ifndef DRM_GPROT_H
#define DRM_GPROT_H

#if defined (__DRM_SUPPORT__)

#include "kal_release.h"
#include "Fs_type.h"
#include "drm_def.h"

/* Content Access */
extern FS_HANDLE DRM_open_file(kal_wchar *file_path, kal_uint32 flags, kal_uint8 permission);
extern kal_int32 DRM_close_file(FS_HANDLE object);
extern drm_proc_enum DRM_read_file(FS_HANDLE source, void *buffer, kal_uint32 size, kal_uint32 *length);
extern kal_int32 DRM_seek_file(FS_HANDLE source, kal_int32 offset, kal_uint8 ref);
extern kal_int32 DRM_set_seek_hint(FS_HANDLE handle, UINT HintNum, FS_FileLocationHint *Hint);
extern kal_int32 DRM_file_size(FS_HANDLE source, kal_uint32 *size);
extern kal_int32 DRM_file_info(FS_HANDLE source, FS_FileInfo *file_info);
extern kal_int32 DRM_file_pos(FS_HANDLE source, kal_uint32 *pos);
extern kal_wchar *DRM_get_extension(kal_wchar *file_path);
extern kal_int32 DRM_consume_rights(FS_HANDLE source, kal_uint8 permission,
                                    void (*callback) (kal_int32 result, kal_int32 id));
extern kal_int32 DRM_consume_timed_rights(FS_HANDLE source, kal_uint8 permission,
                                          void (*callback) (kal_int32 result, kal_int32 id));

extern kal_int32 DRM_consume_rights_with_module(FS_HANDLE source, kal_uint8 permission,
                                    void (*callback) (kal_int32 result, kal_int32 id), module_type module);
extern kal_int32 DRM_consume_timed_rights_with_module(FS_HANDLE source, kal_uint8 permission,
                                          void (*callback) (kal_int32 result, kal_int32 id), module_type module);


extern void DRM_pause_consume(kal_int32 id);
extern void DRM_resume_consume(kal_int32 id);
extern void DRM_stop_consume(kal_int32 id);
extern kal_uint8 *DRM_get_content_type(FS_HANDLE input, kal_wchar *path);
extern kal_char *DRM_get_content_ext(FS_HANDLE input, kal_wchar *path);
extern kal_uint8 DRM_get_object_method(FS_HANDLE input, kal_wchar *path);
extern kal_uint8 DRM_get_permission(kal_uint8 *mime_string, kal_uint32 mime_type);
extern kal_uint8 DRM_get_permission_by_path(kal_wchar *filepath);
extern kal_bool DRM_validate_permission(FS_HANDLE input, kal_wchar *path, kal_uint8 permission);
extern kal_bool DRM_validate_timed_permission(FS_HANDLE input, kal_uint8 permission);
extern kal_bool DRM_validate_forward_rule(FS_HANDLE handle, kal_uint8 permission);
extern kal_int32 DRM_is_drm_file(FS_HANDLE handle, kal_wchar *path);
extern kal_bool DRM_interdev_movable(FS_HANDLE handle, kal_wchar *path);
extern kal_int32 DRM_get_constraint(
                    FS_HANDLE handle,
                    kal_wchar *path,
                    kal_uint8 permission,
                    drm_constraint_struct *cons);
extern kal_uint32 DRM_get_limit_type(FS_HANDLE handle, kal_uint8 permission);

extern kal_int32 DRM_get_rights_issuer(FS_HANDLE input, kal_char *buffer, kal_uint32 *size);

extern void DRM_set_delivery_time(drm_info_struct *info, kal_uint32 delta);
extern kal_uint32 DRM_get_delivery_time(FS_HANDLE handle);

/* Object Processing */
extern drm_proc_enum DRM_process_direct_file(
                        kal_uint8 *mime_type,
                        kal_wchar *file_path,
                        kal_wchar *new_path,
                        kal_uint32 *len);
extern drm_proc_enum DRM_process_virtual_file(kal_uint8 *mime_type, kal_wchar *file_path, kal_wchar *new_path);
extern drm_proc_enum DRM_process_file(kal_uint8 *mime_type, kal_wchar *file_path, kal_bool temp_use);
extern drm_proc_enum DRM_activate_file(kal_wchar *file_path, kal_uint8 *serial, drm_activate_callback callback);
extern kal_bool DRM_async_cancel_process(kal_uint8 serial);
extern drm_proc_enum DRM_async_process_file(kal_uint8 *mime_type,
                                            kal_wchar *file_path,
                                            kal_wchar *new_path,
                                            kal_uint32 new_path_len,
                                            kal_uint8 *serial,
                                            void (*callback) (kal_uint8 serial, kal_int32 result, kal_uint32 id,
                                                              kal_uint32 len));
extern kal_int32 DRM_install_object(kal_bool is_async, 
                             kal_uint8 *content_type, 
                             kal_uint8 *serial,
                             kal_wchar *src_path,
                             kal_bool src_is_buffer,
                             kal_bool src_is_virtual,
                             kal_bool src_need_kept,
                             kal_wchar* dest_path,
                             kal_uint32 dest_buffer_len_in_byte,
                             kal_bool dest_need_output,
                             kal_char **dest_content_type,
                             kal_char **dest_file_ext,
                             kal_uint32 *plaintext_len,
                             kal_uint32 *plaintext_offset_in_dm,
                             void (*callback)(kal_uint8 serial, 
                                              kal_int32 result, 
                                              kal_char *dest_content_type, 
                                              kal_char *dest_file_ext, 
                                              kal_uint32 plaintext_len, 
                                              kal_uint32 plaintext_offset_in_dm));

/* for Prograssive download */
extern drm_proc_enum DRM_process_buffer(kal_uint8 *mime_type, kal_uint8 *buffer, drm_info_struct *info);

extern drm_proc_enum DRM_read_buffer(drm_rights_struct *rights, kal_uint8 *buffer, kal_uint32 size);

/* Other utilities */
extern kal_int32 DRM_get_version(void);

#ifdef __DRM_V02__
typedef struct
{
    kal_uint32 file_size;
    FS_DOSDateTime creation_date;
    /*
     * kal_uint8  attribute;
     * kal_bool   is_short;
     */
} drm_file_info_struct;
extern void *DRM_get_find_cntx(void);
extern FS_HANDLE DRM_find_firstN(
                    void *find_cntx,
                    kal_wchar *file_path,
                    FS_Pattern_Struct *PatternArray,
                    kal_uint32 PatternNum,
                    drm_file_info_struct *FileInfo,
                    kal_wchar *FileName,
                    kal_uint32 MaxLen,
                    kal_int32 EntryIndex);
extern kal_int32 DRM_find_nextN(
                    void *find_cntx,
                    FS_HANDLE handle,
                    drm_file_info_struct *FileInfo,
                    kal_wchar *FileName,
                    kal_uint32 MaxLen,
                    kal_int32 distance);
extern kal_int32 DRM_find_close(void *find_cntx, FS_HANDLE handle);

extern kal_bool DRM_is_archive(FS_HANDLE handle, kal_wchar *path);
extern kal_int32 DRM_import_certificate(kal_wchar *path);
extern kal_int32 DRM_register_file(kal_wchar* file_path);

extern kal_bool DRM_get_whitelist(kal_char *list_buffer, kal_uint8 index);
extern kal_int32 DRM_add_whitelist(kal_char *list_buffer);
extern kal_bool DRM_del_whitelist(kal_char *list_buffer);
extern void DRM_free_whitelist(void);

#endif /* __DRM_V02__ */ 
extern kal_bool DRM_app_common_hdlr(void *ilm);
extern void DRM_app_process_obj_hdlr(void *local_para_ptr);
extern void DRM_app_install_obj_hdlr(void *local_para_ptr);
extern void DRM_app_ro_expiry_hdlr(void *local_para_ptr);
extern void DRM_app_activate_hdlr(void *local_para_ptr);

#else /* defined (__DRM_SUPPORT__) */ 

#include "drm_def.h"

#define DRM_open_file(a,b,c)    FS_Open(a,b)
#define DRM_close_file          FS_Close
#define DRM_read_file           FS_Read
#define DRM_seek_file           FS_Seek
#define DRM_set_seek_hint       FS_SetSeekHint

#define DRM_file_size           FS_GetFileSize
#define DRM_file_pos            FS_GetFilePosition

#endif /* defined (__DRM_SUPPORT__) */ 

#endif /* DRM_GPROT_H */ 


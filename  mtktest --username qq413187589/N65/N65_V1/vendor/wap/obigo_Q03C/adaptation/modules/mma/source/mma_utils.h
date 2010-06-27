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

#ifndef _mma_utils_h
#define _mma_utils_h

/**********************************************************************
 * Function declarations
 **********************************************************************/
 
mma_result_enum translate_fs_result_to_mma(int result);
mma_result_enum translate_mms_result_to_mma(MmsResult result);
mma_result_enum translate_sls_result_to_mma(SlsResult result);
mma_result_enum translate_sma_result_to_mma(SmaResult result);
mma_priority_enum translate_mms_priority_to_mma(MmsPriority prio);
MmsPriority translate_mma_priority_to_mms(mma_priority_enum prio);
mma_expiry_time_enum translate_mms_expiry_to_mma(MmsTimeType type, MmsTimeSec expiry, MmsTimeSec then);
void translate_mma_expiry_to_mms(mma_expiry_time_enum expiry, MmsTimeSec now, MmsTimeType *type, MmsTimeSec *sec);
mma_delivery_time_enum translate_mms_delivery_to_mma(MmsTimeType type, MmsTimeSec delivery, MmsTimeSec then);
void translate_mma_delivery_to_mms(mma_delivery_time_enum delivery, MmsTimeSec now, MmsTimeType *type, MmsTimeSec *sec);

mma_mms_multipart_enum mma_get_multipart_type(MmsGetHeader *msgHeader);

const char *mma_get_mime_type_from_mmsContentType(const MmsContentType *contentType);
const char *mma_get_mime_type_from_filename(const char *filename);
MmsKnownMediaType mma_get_mmsKnownMediaType_from_mime_type(const char *mime);
SlsMediaType mma_get_slsMediaType_from_mime_type(const char *mime);
SlsMediaType mma_get_slsMediaType_from_filename(const char *filename);
SlsMediaObjectType mma_get_slsMediaObjectType_from_slsMediaType(SlsMediaType mediaType);

#ifdef __DRM_SUPPORT__
kal_bool mma_drm_check_right(const char *filename);
kal_bool mma_drm_check_right(const char *filename);
mma_drm_type_enum mma_drm_check_right_vf(SlsMediaType type, const char *filename, int offset, int size);
mma_drm_method_enum mma_drm_get_method_type(const char *filename);
const char *mma_drm_get_content_type_vf(SlsMediaType type, const char *filename, int offset, int size);
#endif

kal_int32 mma_get_slide_index(mma_body_struct *body, mma_slide_struct *slide);
kal_uint32 mma_get_total_item_count(mma_body_struct *body);

const char *mma_get_name_from_path(char *path);
mma_object_struct *mma_get_object_from_name(mma_body_struct *body, const char *name);

void mma_add_param_string(MmsAllParams **allParams, MmsParam param, const char *strValue);
MmsBodyParams *mma_create_body_params(MmsKnownMediaType mediaType, char *mediaString, 
    const unsigned char *name, MmsCharset charset);

char *mma_create_name_from_nonascii_name(const char *name, kal_bool with_random_suffix);
mma_object_struct *mma_create_object_from_mo(kal_uint32 msg_id, MmsBodyInfoList *mo);
SlsMediaObject *mma_create_sls_object_from_mma_slide_object(const mma_slide_object_struct *s_obj);

void mma_copy_attachment_info(mma_body_struct *body, SlsUnrefItemList *sourceList);
void mma_copy_sls_root_layout(const SlsRootLayout *source, SlsRootLayout *dest);
void mma_copy_sls_region(const SlsRegion *source, SlsRegion *destination );
void mma_copy_slide_info(mma_body_struct *body, const SlsSlideInfo *slsInfo);

void mma_insert_addr_to_list(MmsAddressType addrType, char *address, MmsAddressList **list);
mma_slide_struct *mma_insert_slide(mma_body_struct *body);
mma_object_struct *mma_insert_object_to_tail(mma_body_struct *body);
mma_unref_list_struct *mma_insert_unref_item_to_tail(mma_body_struct *body, mma_object_struct *obj);
void mma_insert_slide_obj(SlsMediaObjectType gType, mma_slide_struct *slide, mma_object_struct *obj);

kal_bool mma_is_ascii_text(const char *filepath);
kal_bool mma_is_ascii_string(const char *str);
kal_bool mma_is_restricted_type(const char *filename);
kal_bool mma_is_restricted_type_vf(const char *filename, const char *mime, kal_uint32 offset, kal_uint32 size);
kal_bool mma_is_supported_mime_type(const char *mime);
MSF_BOOL mma_is_valid_slsMediaType(const char *mime, SlsMediaObjectType sMediaType);

void mma_remove_invalid_address(MmsGetHeader *header);
void mma_remove_slide_by_index(mma_body_struct *body, kal_uint32 index);
void mma_remove_object_in_slide(mma_slide_struct *list, mma_object_struct *obj);
void mma_remove_object_in_unref_list(mma_unref_list_struct **list, mma_object_struct *obj);
void mma_remove_object_list_entry(mma_object_struct **list, mma_object_struct *entry);

void mma_update_unref_list(mma_body_struct *body);

void mma_free_object(mma_object_struct **obj);
void mma_free_sls_media_object(SlsMediaObject **object);
void mma_free_object_list(mma_object_struct **obj);
void mma_free_slide_list(mma_slide_struct **slide);
void mma_free_unref_list(mma_unref_list_struct **list);
void mma_free_body_params(MmsBodyParams **bodyParams);

#endif  /* _mma_utils_h */

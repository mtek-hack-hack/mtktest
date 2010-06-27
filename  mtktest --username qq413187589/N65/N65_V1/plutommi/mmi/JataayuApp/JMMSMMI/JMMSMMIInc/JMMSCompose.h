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
 * JMMSCompose.h
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
#ifndef _MMI_MMS_COMPOSE_H
#define _MMI_MMS_COMPOSE_H

#include "MMI_features.h"
#include "ddlbase.h"
#include "jcerror.h"
#include "jcevent.h"
#include "jcutils.h"
#include "jdd_MMIdatatype.h"
#include "gui_data_types.h"
#include "MessagingDataTypes.h"
#include "JMMSStructs.h"
#include "PhoneBookTypes.h"
#include "prvmessagingdatatypes.h"
#include "custom_wap_config.h"
#include "fmt_def.h"

/* if some header should be include before this one */
/***************************************************************************** 
* Define
*****************************************************************************/

#define JMMS_ICON_GREYSCALE_WHITE_VALUE      8

#define JMMS_HORZN_MARGIN_SPACE           2
#define JMMS_VERT_ICON_MARGIN_SPACE       2
#define JMMS_VERT_IMAGE_MARGIN_SPACE      6
#define JMMS_VERT_FRAME_IMAGE_GAP         10
/* MAUI_00228376 Start */
#define JMMS_MAX_ATTACHMENTS_LIMIT        (wap_custom_get_max_mms_address())
/* MAUI_00228376 End */
#define JMMS_CHINESE_FILE_NAME_PRE_STRING "ch_media_"

typedef enum
{
    JMMS_COMP_FAIL,
    JMMS_COMP_OK,
    JMMS_COMP_POPUP_OK,
    JMMS_COMP_NEW_SLIDE,
    JMMS_COMP_OUT_MEMORY,
    JMMS_CONTENT_CLASS
} JMMS_COMP_ERRCODE;

/* HIMANSHU 05122006 START */
#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
typedef enum
{
    JMMS_IMAGE_RESIZE_FAILED = -1,
    JMMS_IMAGE_RESIZE_SUCCEED,
    JMMS_IMAGE_RESIZE_UNCHANGED,
    JMMS_IMAGE_RESIZING_FAILED_IN_GDI_ENCODER_ERR_DISK_FULL,
    JMMS_IMAGE_RESIZING_FAILED_IN_INSUFFICIENT_DRAWING_BUF,
    JMMS_IMAGE_RESIZING_FAILED_IN_NO_QUOTA,
    JMMS_IMAGE_RESIZING_FAILED_IN_UNKNOWN_DIMENSION,
    JMMS_IMAGE_RESIZING_FAILED_IN_GDI_FAILED,
    JMMS_IMAGE_RESIZING_FAILED_IN_GDI_ENCODER_ERR_NO_DISK,
    JMMS_IMAGE_RESIZING_FAILED_IN_GDI_ENCODER_ERR_WRITE_PROTECTION
} JMMS_IMAGE_RESIZE_ERRCODE;

typedef enum
{
    RESIZE_ANIMATION_DISABLE_OFF,
    RESIZE_ANIMATION_DISABLE_ON
} JMMS_RESIZE_ANIMATION_STATUS;

#endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 
/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern void mmi_jmms_compose_init(void);

#ifdef __DRM_SUPPORT__
extern void mmi_jmms_confirm_add_drm_media(FuncPtr add_media_hdlr);
extern void mmi_jmms_confirm_add_drm_media_yes(void);
extern void mmi_jmms_confirm_add_drm_media_no(void);
#endif /* __DRM_SUPPORT__ */ 
#ifndef __MMI_UNIFIED_COMPOSER__
extern void mmi_jmms_entry_attachment_options(void);
extern void mmi_jmms_entry_attachment_insert(void);
extern void mmi_jmms_entry_attachment_insert_vcard(void);
extern void mmi_jmms_entry_attachment_insert_vcalender(void);
extern void mmi_jmms_show_edit_content_option(void);
extern void mmi_jmms_entry_edit_content_option(void);
extern void mmi_jmms_entry_edit_content_insert(void);
extern void mmi_jmms_entry_edit_content_delete(void);
extern void mmi_jmms_entry_edit_content_replace(void);
extern void mmi_jmms_entry_edit_content_goto(void);
extern void mmi_jmms_entry_edit_content_settings(void);
extern void mmi_jmms_entry_edit_content_text_settings(void);
extern void mmi_mms_exit_text_settings(void);
extern void mmi_jmms_fill_txt_setting_inline_edit_struct(void *inline_edit_p);
extern void mmi_jmms_confirm_save_txt_settings(void);
extern void mmi_jmms_save_txt_settings(void);
extern void mmi_jmms_inline_text_color_hilite_handler(S32 index);
extern void mmi_jmms_entry_txt_custom_color(void);
extern void mmi_jmms_save_txt_custom_color(void);

extern void mmi_jmms_entry_edit_content_smil_settings(void);

extern void mmi_jmms_pre_entry_text_timing_settings(void);
extern void mmi_jmms_pre_entry_image_timing_settings(void);
extern void mmi_jmms_pre_entry_audio_timing_settings(void);
extern void mmi_jmms_pre_entry_video_timing_settings(void);
extern void mmi_jmms_entry_smil_settings_media_timing(void);
extern void mmi_jmms_exit_smil_settings_media_timing(void);

extern void mmi_jmms_confirm_save_text_timing_settings(void);
extern void mmi_jmms_save_text_timing_settings(void);
extern void mmi_jmms_confirm_save_image_timing_settings(void);
extern void mmi_jmms_save_image_timing_settings(void);
extern void mmi_jmms_confirm_save_audio_timing_settings(void);
extern void mmi_jmms_save_audio_timing_settings(void);
extern void mmi_jmms_confirm_save_video_timing_settings(void);
extern void mmi_jmms_save_video_timing_settings(void);

extern void mmi_jmms_fill_media_timing_inline_edit_struct(void *inline_edit_p);
extern void mmi_jmms_inline_media_timings_hilite_handler(S32 index);
extern void mmi_jmms_entry_media_duration(void);
extern void mmi_jmms_entry_smil_bg_color_settings(void);

extern void mmi_jmms_entry_smil_bg_color_settings(void);
extern void mmi_jmms_bg_color_highlight_hdlr(S32 index);
extern void mmi_jmms_select_bg_color(void);
extern void mmi_jmms_entry_bg_custom_color(void);
extern void mmi_jmms_save_smil_bg_custom_color(void);

extern void mmi_jmms_pre_entry_edit_content_slide_time(void);
extern void mmi_jmms_entry_edit_content_slide_time(void);
extern void mmi_jmms_save_edit_content_slide_timing(void);
extern void mmi_jmms_show_image_from_cached_buffer(
                S32 x_offset,
                S32 y_offset,
                S32 width,
                S32 height,
                const U8 *buffer_ptr);
extern void mmi_jmms_pre_entry_edit_content_text_settings(void);

/* edit content screen */
extern void GoBacktoWriteMMS(void);
extern void mmi_jmms_pre_entry_edit_content_screen(void);
extern void mmi_jmms_entry_edit_content_screen(void);
extern void mmi_jmms_exit_edit_content_screen(void);
extern void mmi_jmms_show_smil_editor_title(U32 identifier);
extern void mmi_jmms_show_smil_editor_draw_area_1(
                U32 identifier,
                S32 y_offset,
                S32 clip_x1,
                S32 clip_y1,
                S32 clip_x2,
                S32 clip_y2);
extern void mmi_jmms_show_smil_editor_draw_area_2(
                U32 identifier,
                S32 y_offset,
                S32 clip_x1,
                S32 clip_y1,
                S32 clip_x2,
                S32 clip_y2);

extern void mmi_jmms_smil_editor_show_image_from_file(S32 y_offset);
extern void mmi_jmms_smil_editor_show_video_from_file(S32 y_offset);

//kal_bool mmi_jmms_smil_editor_cache_image(void);
//void mmi_jmms_smil_editor_show_image(U8 *image_buff, S32 x, S32 y, S32 zoom_width, S32 zoom_height, kal_bool resize_image);
extern UI_font_type mmi_jmms_get_edit_content_scr_txt_font(void);
extern color mmi_jmms_get_edit_content_scr_txt_color(void);
extern color mmi_jmms_get_edit_content_scr_bg_color(void);

extern void mmi_jmms_compose_go_back_history_ip_method(void);

/* insert media */
extern void mmi_jmms_callback_filemgr_select_image(void *path_p, int is_short);
extern void mmi_jmms_entry_filemgr_insert_image(void);

extern void mmi_jmms_callback_filemgr_select_audio(void *path_p, int is_short);
extern void mmi_jmms_entry_filemgr_insert_audio(void);

extern void mmi_jmms_callback_filemgr_select_video(void *path_p, int is_short);
extern void mmi_jmms_entry_filemgr_insert_video(void);

extern void mmi_jmms_callback_filemgr_select_vcard(void *path_p, int is_short);
extern void mmi_jmms_entry_filemgr_insert_vcard(void);

extern void mmi_jmms_callback_filemgr_select_vcalander(void *path_p, int is_short);
extern void mmi_jmms_entry_filemgr_insert_vcalander(void);

extern void mmi_jmms_entry_filemgr_insert_attachment(void);
extern void mmi_jmms_callback_filemgr_select_attachment(void *path_p, int is_short);

extern void mmi_jmms_edit_content_insert_slide(void);
extern void mmi_jmms_edit_content_next_slide(void);
extern void mmi_jmms_edit_content_prev_slide(void);
extern void mmi_jmms_edit_content_delete_slide(void);
extern void mmi_jmms_edit_content_delete_attachment(void);
extern void mmi_jmms_edit_content_delete_video(void);
extern void mmi_jmms_edit_content_delete_audio(void);
extern void mmi_jmms_edit_content_delete_image(void);
extern void mmi_jmms_entry_replace_image(void);
extern void mmi_jmms_callback_filemgr_replace_image(void *path_p, int is_short);
extern void mmi_jmms_entry_replace_audio(void);
extern void mmi_jmms_callback_filemgr_replace_audio(void *path_p, int is_short);
extern void mmi_jmms_entry_replace_video(void);
extern void mmi_jmms_callback_filemgr_replace_video(void *path_p, int is_short);

#if defined (__MMI_TODOLIST__) && defined(__MMI_VCALENDAR__)
extern void mmi_jmms_entry_insert_vclndr_tdl(void);
#endif 
extern void mmi_jmms_entry_edit_content_delete_attachment(void);
extern void mmi_jmms_delete_attachment_highlight_hdlr(S32 index);
extern void mmi_jmms_edit_content_goto_slide(void);

#ifdef __MMI_VCARD__
extern void mmi_jmms_entry_insert_vcard_phb(void);
extern void mmi_jmms_insert_vcard_phb(MMI_PHB_VCARD_STRUCT *resut_entry_p);
#endif /* __MMI_VCARD__ */ 

extern void mmi_jmms_convert_u32_to_color(color *out_color_p, U32 incolor_32);

#ifdef __MMI_VCARD__
extern void mmi_jmms_insert_my_vcard(void);
#endif 

extern void mmi_jmms_entry_insert_phb_contact(void);
extern void mmi_jmms_insert_phb_contact(MMI_PHB_VCARD_STRUCT *resut_entry);
extern void mmi_jmms_save_custom_media_duration(void);
extern void mmi_jmms_compose_play_video(void);
extern void mmi_jmms_compose_play_audio(void);

extern void mmi_jmms_fm_add_image(void);
extern void mmi_jmms_fm_add_audio(void);
extern void mmi_jmms_fm_add_video(void);
extern void mmi_jmms_fm_add_vcard(void);
extern void mmi_jmms_fm_add_vcalander(void);
extern void mmi_jmms_fm_add_attachment(void);
extern void mmi_jmms_fm_replace_image(void);
extern void mmi_jmms_fm_replace_video(void);
extern void mmi_jmms_fm_replace_audio(void);

/* hilite functions */
extern void mmi_jmms_highlight_attachment_insert(void);
extern void mmi_jmms_highlight_attachment_delete(void);

extern void mmi_jmms_highlight_attachment_attachment(void);

#ifdef __MMI_VCARD__
extern void mmi_jmms_highlight_attachment_vcard(void);
#endif 

extern void mmi_jmms_highlight_attachment_vcalendar(void);

#ifdef __MMI_VCARD__
extern void mmi_jmms_highlight_attachment_vcard_fm(void);
extern void mmi_jmms_highlight_attachment_vcard_phb(void);
#endif /* __MMI_VCARD__ */ 

#if defined (__MMI_TODOLIST__) && defined(__MMI_VCALENDAR__)
extern void mmi_jmms_highlight_attachment_vcal_todolist(void);
#endif 
extern void mmi_jmms_highlight_attachment_vcal_fm(void);

extern void mmi_jmms_highlight_edit_content_ip_method(void);
extern void mmi_jmms_highlight_edit_content_insert(void);
extern void mmi_jmms_highlight_edit_content_delete(void);
extern void mmi_jmms_highlight_edit_content_replace(void);
extern void mmi_jmms_highlight_edit_content_play_audio(void);
extern void mmi_jmms_highlight_edit_content_play_video(void);
extern void mmi_jmms_highlight_edit_content_goto(void);
extern void mmi_jmms_highlight_edit_content_settings(void);
extern void mmi_jmms_highlight_edit_content_done(void);
extern void mmi_jmms_pre_entry_mms_edit_content_done(void);
extern void mmi_jmms_highlight_edit_content_preview(void);

extern void mmi_jmms_highlight_edit_content_insert_image(void);
extern void mmi_jmms_highlight_edit_content_insert_audio(void);
extern void mmi_jmms_highlight_edit_content_insert_video(void);
extern void mmi_jmms_highlight_edit_content_insert_slide(void);
extern void mmi_jmms_highlight_edit_content_insert_contact(void);

extern void mmi_jmms_highlight_edit_content_delete_image(void);
extern void mmi_jmms_highlight_edit_content_delete_audio(void);
extern void mmi_jmms_highlight_edit_content_delete_video(void);
extern void mmi_jmms_highlight_edit_content_delete_slide(void);

extern void mmi_jmms_highlight_edit_content_replace_image(void);
extern void mmi_jmms_highlight_edit_content_replace_audio(void);
extern void mmi_jmms_highlight_edit_content_replace_video(void);

extern void mmi_jmms_highlight_edit_content_goto_next(void);
extern void mmi_jmms_highlight_edit_content_goto_previous(void);
extern void mmi_jmms_highlight_edit_content_goto_slide_list(void);

extern void mmi_jmms_highlight_edit_content_slide_time(void);
extern void mmi_jmms_highlight_edit_content_text_settings(void);
extern void mmi_jmms_highlight_edit_content_smil_settings(void);

extern void mmi_jmms_highlight_smil_settings_text_timings(void);
extern void mmi_jmms_highlight_smil_settings_image_timings(void);
extern void mmi_jmms_highlight_smil_settings_audio_timings(void);
extern void mmi_jmms_highlight_smil_settings_video_timings(void);
extern void mmi_jmms_highlight_smil_settings_bg_color(void);

#ifdef __MMI_VCARD__
extern void mmi_jmms_highlight_attachment_my_vcard(void);
#endif 

extern void mmi_jmms_create_mms_for_file(JC_CHAR *content_source, fwd_callback callback, void *callback_param_p);
extern void mmi_jmms_create_mms_for_general_insert(
                JC_CHAR *address_p,
                JC_CHAR *subject_p,
                JC_CHAR *content_source_p,
                JC_CHAR *test_p,
                fwd_callback callback,
                void *callback_param_p);
extern void mmi_jmms_create_mms_for_general_insert_internal(
                JC_CHAR *address_p,
                JC_CHAR *subject_p,
                U32 subject_len,
                JC_CHAR *content_source_p,
                JC_CHAR *text_p,
                U32 text_len,
                fwd_callback callback,
                void *callback_param_p);
extern void mmi_jmms_create_mms_to_address(JC_CHAR *address_p);
extern void mmi_jmms_fm_fwd_file_to_mms(void);

#ifdef __MMI_BARCODEREADER__
extern void mmi_jmms_create_mms_for_barcode(JC_CHAR *, U32, JC_CHAR *, U32);
#endif 
/* HIMANSHU 05122006 START */
#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
extern S16 mmi_jmms_ext_image_resizing(
            JC_CHAR *source_file_p,
            JC_CHAR *dest_file_p,
            S32 resize_width,
            S32 resize_height);
extern S16 check_for_image_resize(JC_CHAR *content_source_p, JC_CHAR **dest_fname_p);
extern void mmi_jmms_ext_display_image_animation(void);
extern void mmi_jmms_display_resize_image_animation(void);
extern void mmi_jmms_entry_resize_image_animation(void);
extern void mmi_jmms_delete_resized_temp_file(S8 *file_name_p);
#endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 
/* HIMANSHU 05122006 END */

// #ifdef __MMI_MMS_SIGNATURE__
extern void mmi_jmms_display_auto_signature_error_popup(void);
extern JC_BOOLEAN mmi_jmms_pre_check_for_auto_signature(void);
extern void mmi_jmms_insert_auto_signature(void);
extern JMMS_COMP_ERRCODE mmi_jmms_insert_auto_signature_slide(U8 page_count);
extern JMMS_COMP_ERRCODE mmi_jmms_del_inserted_auto_signature_slide(void);

// #endif /* __MMI_MMS_SIGNATURE__ */

extern JMMS_COMP_ERRCODE mmi_jmms_compose_replace_media(
                            void *path_p,
                            U8 type,
                            U8 is_attachment,
                            U8 page_index,
                            JC_UINT32 old_media_id);
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
/* utilities functions */
extern JMMS_COMP_ERRCODE mmi_jmms_save_post_entry_edit_content_slide_timing(U32 slide_time);
extern void mmi_jmms_compose_fill_default_values_slide_settings(void);
extern JMMS_COMP_ERRCODE mmi_jmms_compose_add_media(void *path_p, U8 type, U8 is_attachment, U8 page_index);
extern JC_RETCODE mmi_jmms_compose_add_media_as_file_offset(
                    JC_CHAR *path_p,
                    S32 offset,
                    JC_CHAR *file_name_p,
                    EMediaType type,
                    U8 is_attachment,
                    U8 page_index,
                    S32 size,
                    E_DRM_TYPE drm_media_type,
                    U32 *media_id);
extern JMMS_COMP_ERRCODE mmi_jmms_compose_add_text_media(
                            U8 page_index,
                            UI_font_type text_font,
                            U32 txt_color,
                            S32 display_error,
                            U32 *media_id);
extern JMMS_COMP_ERRCODE mmi_jmms_compose_add_text(
                            U8 page_index,
                            UI_font_type text_font,
                            U32 txt_color,
                            S32 update_text_id);
extern JMMS_COMP_ERRCODE mmi_jmms_compose_update_text(U8 page_index, U32 media_id);
extern JMMS_COMP_ERRCODE mmi_jmms_compose_new_mms(void);
extern U8 *mmi_mms_get_mms_content_type_file(JC_CHAR *file_name_p, EMediaType type);
extern JMMS_COMP_ERRCODE mmi_jmms_compose_insert_slide(void);
extern JC_RETCODE mmi_jmms_compose_insert_new_slide(S32 duration);
extern JMMS_COMP_ERRCODE mmi_jmms_exit_curr_slide(void);
extern JMMS_COMP_ERRCODE mmi_jmms_extract_slide_media_info(U8 page_index);
extern JMMS_COMP_ERRCODE mmi_jmms_compose_delete_page(U8 page_index);
extern JMMS_COMP_ERRCODE mmi_jmms_compose_delete_media(U32 media_id, U8 page_index, U8 is_attachment);
extern JMMS_COMP_ERRCODE mmi_jmms_compose_get_media_list(
                            U8 page_index,
                            MEDIA_INFO **media_info_p,
                            U8 *media_count,
                            U8 is_attachment);
extern JMMS_COMP_ERRCODE mmi_jmms_save_page_time(U32 slide_time);
extern JMMS_COMP_ERRCODE mmi_jmms_set_media_time(U32 start_time, U32 duration, U32 media_id, U8 page_index);

extern JC_RETCODE mmi_jmms_set_media_time_no_error_handling(U32 start_time, U32 duration, U32 media_id, U8 page_index);
extern JMMS_COMP_ERRCODE mmi_jmms_set_bg_color(U32 bg_color);
extern JC_RETCODE mmi_jmms_set_bg_color_no_error_handling(U32 bg_color);
extern JMMS_COMP_ERRCODE mmi_jmms_get_bg_color(JC_INT32 *bg_color_p);
extern JMMS_COMP_ERRCODE mmi_jmms_get_media_time(U32 *start_time, U32 *duration_p, U32 media_id, U8 page_index);

extern JC_RETCODE mmi_jmms_error_ind_cb(MSG_HANDLE hMsg, void *callback_arg_p, void *cb_struct_p, ErrorCode error);
extern JMMS_COMP_ERRCODE mmi_jmms_compose_add_media_template(
                            U8 *buffer,
                            U8 *content_type,
                            U32 size,
                            U8 type,
                            U8 is_attachment,
                            U8 page_index);
extern JMMS_COMP_ERRCODE mmi_jmms_set_text_attributes(
                            U32 media_id,
                            U8 page_index,
                            mmi_jmms_slide_prop_struct *curr_slide_prop);
extern JMMS_COMP_ERRCODE mmi_jmms_get_region_list(U8 page_index, U8 *isImageFirst);
extern pBOOL mmi_jmms_get_attachment_data(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);

extern void mmi_jmms_convert_hash_col_string_toU32(PS8 ip_colstr, U32 *op_color_p, U8 base);
extern void mmi_jmms_convert_u32To_hash_col_string(U32 ip_color, PS8 op_colstr);

extern JMMS_COMP_ERRCODE mmi_jmms_set_region_list(void);
extern JC_RETCODE mmi_jmms_set_potrait_region_list(U32 image_on_top);

extern mmi_jmms_media_type_enum mmi_jmms_get_mms_media_type_from_file(JC_CHAR *file_name_p, EMediaType type);

extern JC_RETCODE mmi_jmms_convert_chinese_english_filename(JC_CHAR **dst_filename_p, JC_CHAR *src_filename_p);
extern U32 mmi_jmms_get_chinese_file_name_id_from_nvram(void);
extern void mmi_jmms_set_chinese_file_name_id_to_nvram(U32);
extern JC_BOOLEAN mmi_jmms_is_corrupted_video_media_in_mms(
                    MESSAGING_HANDLER *messaging_handle_p,
                    JC_BOOLEAN need_resolution_check);

#ifdef __DRM_SUPPORT__
extern JC_BOOLEAN mmi_jmms_is_drm_fwd_lock_media_in_mms(
                    MESSAGING_HANDLER *messaging_handle_p,
                    JC_BOOLEAN check_for_edit);
#endif /* __DRM_SUPPORT__ */ 

extern pBOOL is_extended_char_present(S8 *Buffer_p);

extern JC_BOOLEAN mmi_jmms_is_mime_found_in_g_content_type_list(JC_INT8 *psz_content_type_p);
extern JC_BOOLEAN mmi_jmms_selected_media_valid_size_check_for_mms(
                    void *path_p,
                    int is_short,
                    U32 *size_p,
                    JC_BOOLEAN is_media_image);
extern S32 mmi_jmms_is_file_can_be_forwarded_to_mms(const char *filename_p);

/* Himanshu Fix PMTSW00006527 START */
extern JC_BOOLEAN mmi_jmms_check_for_image_size_and_resolution(S8 *path_p, S32 width, S32 height, U32 media_size);

/* Himanshu Fix PMTSW00006527 END */
extern JC_BOOLEAN mmi_jmms_get_media_file_size(void *path_p, U32 *media_size_p);
extern JMMS_COMP_ERRCODE mmi_jmms_compose_handle_error(JC_RETCODE ret_code, U8 is_page);
extern void mmi_jmms_handle_error(JC_RETCODE ret_code);
extern void mmi_jmms_delete_compose_temp_files(void);
extern void mmi_jmms_compose_show_error_popup(U16 str_id);
extern void mmi_jmms_copy_with_dot(S8 *dest, S8 *source, S32 max_len);
/* Separate file type filters for restricted media types */
extern void mmi_jmms_set_file_mgr_filter_for_image(FMGR_FILTER* filter);
extern void mmi_jmms_set_file_mgr_filter_for_audio(FMGR_FILTER* filter);
extern void mmi_jmms_set_file_mgr_filter_for_video(FMGR_FILTER* filter);
extern void mmi_jmms_set_file_mgr_filter_for_attachment(FMGR_FILTER* filter);
extern void mmi_jmms_set_file_mgr_filter_for_image_restricted(FMGR_FILTER* filter);
extern void mmi_jmms_set_file_mgr_filter_for_audio_restricted(FMGR_FILTER* filter);
extern void mmi_jmms_set_file_mgr_filter_for_video_restricted(FMGR_FILTER* filter);
extern void mmi_jmms_set_file_mgr_filter_for_attachment_restricted(FMGR_FILTER* filter);

#endif /* _MMI_MMS_COMPOSE_H */ 


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
 * JMMSView.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_JMMS_VIEW_PROT_H
#define _MMI_JMMS_VIEW_PROT_H

#include "ddlbase.h"
#include "jcerror.h"
#include "jcevent.h"
#include "jcutils.h"
#include "jdd_MMIdatatype.h"
#include "gui_data_types.h"
#include "MessagingDataTypes.h"
#include "JMMSStructs.h"

/* if some header should be include before this one */

#define JMMS_VIEW_DEFAULT_TEXT_COLOR            "#000000"
#define JMMS_VIEW_DEFAULT_ACTIVE_LINK_COLOR        "#0000FF"
#define JMMS_VIEW_DEFAULT_INACTIVE_LINK_COLOR      "#993300"
#define JMMS_VIEW_DEFAULT_FOCUS_LINE_WIDTH   2
#define JMMS_VIEW_DEFAULT_FOCUS_LINE_COLOR         "#FF0000"

#define JMMS_VIEW_DEFAULT_TAB_SPACING           4
#define JMMS_VIEW_DEFAULT_FOCUS_LINE_SPACING    4
#define JMMS_VIEW_DEFAULT_TEXT_CONTROL_SPACING     4
#define JMMS_VIEW_DEFAULT_MEDIA_SPACING            10
#define JMMS_VIEW_DEFAULT_RENDERING_RECT_SPACING   10

#define JMMS_VIEW_DEFAULT_BG_COLOR              "#FFFFFF"

// #define JMMS_VIEW_DEFAULT_FORWARD_STRING                     "Fw:"

#define JMMS_VIEW_SLIDING_BAR_UPDATE_TIME       1000

#define  JMMS_VIEW_SCREEN_SCROLL_SIZE           15

#define JMMS_VIEW_DOWNLOADED_WALLPAPER_PATH           "z:\\@mms\\mms_wallpaper"
#define JMMS_VIEW_DOWNLOADED_SCREEN_SAVER_PATH        "z:\\@mms\\mms_scrsaver"

/***************************************************************************** 
* Function
*****************************************************************************/
extern void mmi_jmms_entry_goto_slide_list(void);
extern void mmi_jmms_view_goto_slide_list_highlight_hdlr(S32 index);
extern void mmi_jmms_entry_preview_options(void);
extern void mmi_jmms_entry_save_object(void);

#ifdef __MMI_UNIFIED_MESSAGE__
extern void mmi_jmms_pre_entry_view(void);
extern void mmi_jmms_view_mms(void);
extern void mmi_jmms_restore_view_callbacks(void);
extern void mmi_jmms_back_from_option_screen(void);
#else /* __MMI_UNIFIED_MESSAGE__ */ 
extern void mmi_jmms_entry_view_options(void);
extern void mmi_jmms_entry_goto_options(void);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
extern void mmi_jmms_view_init(void);

/* hilite fns */
#ifndef __MMI_UNIFIED_COMPOSER__
extern void mmi_jmms_highlight_preview_replay(void);
extern void mmi_jmms_highlight_preview_prev_slide(void);
extern void mmi_jmms_highlight_preview_next_slide(void);
extern void mmi_jmms_highlight_preview_slide_list(void);
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
extern void mmi_jmms_highlight_preview_play_audio(void);
extern void mmi_jmms_highlight_preview_play_video(void);
extern void mmi_jmms_highlight_save_video_object(void);
extern void mmi_jmms_highlight_save_audio_object(void);
extern void mmi_jmms_highlight_save_image_object(void);
extern void mmi_jmms_highlight_view_attachments(void);

#ifndef __MMI_UNIFIED_MESSAGE__
extern void mmi_jmms_highlight_view_replay(void);
extern void mmi_jmms_highlight_view_goto(void);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

extern void mmi_jmms_highlight_goto_prev_slide(void);
extern void mmi_jmms_highlight_goto_next_slide(void);
extern void mmi_jmms_highlight_goto_slide_list(void);
extern void mmi_jmms_pre_entry_mms_preview(void);
extern void mmi_jmms_entry_mms_preview(void);
extern void mmi_jmms_update_sliding_bar(void);
extern void mmi_jmms_exit_mms_preview_screen(void);

extern void mmi_jmms_stop_preview(void);
extern void mmi_jmms_exit_preview(void);

extern void mmi_jmms_start_mms_preview(void);

extern void mmi_jmms_preview_next_slide(void);
extern void mmi_jmms_preview_prev_slide(void);
extern void mmi_jmms_preview_play_mms(void);
extern void mmi_jmms_preview_selected_slide(void);

extern JC_RETCODE mmi_jmms_attachment_misc_ind_cb(
                    MSG_HANDLE msg_handle,
                    void *callback_arg_p,
                    ATTACHMENT_MISC_IND *attachment_misc_info_p);
/* JC_RETCODE   mmi_jmms_scroll_bar_ind_cb(MSG_HANDLE msg_handle, void *callback_arg, SCROLLBAR_IND *scroll_bar_info_p);//merge */
extern JC_RETCODE mmi_jmms_audio_video_unknown_ind_cb(
                    MSG_HANDLE msg_handle,
                    void *callback_arg_p,
                    AUDIO_VIDEO_UNKNOWN_IND *audio_video_info_p);
extern JC_RETCODE mmi_jmms_focus_change_ind_cb(
                    MSG_HANDLE msg_handle,
                    void *callback_arg_p,
                    FOCUSED_OBJECT focussed_object_type);
extern JC_RETCODE mmi_jmms_page_presentation_ind_cb(
                    MSG_HANDLE msg_handle,
                    void *callback_arg_p,
                    PAGE_PRESENTATION_IND *page_presentation_info_p);

extern void mmi_jmms_view_handle_error(JC_RETCODE ret_code);
extern void mmi_jmms_view_play_audio(void);
extern void mmi_jmms_view_play_video(void);
extern MEDIA_INFO *mmi_jmms_jdi_get_video_data(U8 page_index);
extern MEDIA_INFO *mmi_jmms_jdi_get_audio_data(U8 page_index);

extern void mmi_jmms_preview_scroll_slide_down(void);
extern void mmi_jmms_preview_scroll_slide_up(void);

extern JC_RETCODE mmi_jmms_pre_entry_mms_view(CONTENT_DATA *content_p);
extern void mmi_jmms_preview_end(void);

extern void mmi_jmms_view_attachment(void);
extern void mmi_jmms_view_attachment_highlight_hdlr(S32 index);

extern void mmi_jmms_entry_save_media_as(void);
extern void mmi_jmms_saving_progress_screen(void);

extern void mmi_jmms_stop_preview_rsk(void);
extern void mmi_jmms_preview_next_slide_right_arrow(void);
extern void mmi_jmms_preview_prev_slide_left_arrow(void);
extern void mmi_jmms_view_show_progressing_screen(void);
extern void mmi_jmms_draw_sliding_bar(U8 sliding_bar_fill_state);

extern void mmi_jmms_pre_entry_mms_view_async_callback(JC_RETCODE ret_code);
extern void Go_Back_from_attachemnt_Only_scr(void);
extern void mmi_jmms_abort_view_progress(void);
extern void mmi_jmms_only_abort_view_progress(void);
extern void mmi_jmms_deinit_view(void);
extern void mmi_jmms_pre_checks_mms_view(void);
extern JC_BOOLEAN mmi_jmms_slide_time_elapsed_complete(void);
extern JC_BOOLEAN mmi_jmms_is_current_slide_play_time_duration_show_complete_slide(void);
extern MEDIA_INFO *mmi_jmms_jdi_get_image_data(U8 page_index);
extern void mmi_jmms_fmgr_mms_copy_rsp(void *info_p);   /* sanjeev added for async loading screen */

#ifdef __MMI_TOUCH_SCREEN__
#ifdef MMS_HORIZONTAL_SCROLLBAR_ENABLE
extern void mmi_jmms_handle_stylus_scroll(JC_UINT32 i_pos, EScrollBarType eScrollType);
#else 
extern void mmi_jmms_handle_stylus_scroll(JC_UINT32 iPos);
#endif 
extern void mmi_jmms_handle_set_stylus_focus(JC_UINT32 uiX, JC_UINT32 uiY, EStylusEvent event);
#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_UNIFIED_COMPOSER__
extern JC_RETCODE mmi_jmms_uc_pre_entery_view(CONTENT_DATA *content);
extern JC_RETCODE mmi_jmms_uc_pre_entery_view(CONTENT_DATA *content);
#endif /* __MMI_UNIFIED_COMPOSER__ */ 

extern JC_CHAR *mmi_jmms_get_to_large_image_string(void);
extern void mmi_jmms_free_media_layer_buffer(void);

#endif /* _MMI_JMMS_VIEW_PROT_H */ 


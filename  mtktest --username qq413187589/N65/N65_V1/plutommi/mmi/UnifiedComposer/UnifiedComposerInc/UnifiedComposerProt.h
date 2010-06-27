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
*  Copyright Statement: *  -------------------- *  This software is protected by 
Copyright and the information contained *  herein is confidential. The software 
may not be copied and the information *  contained herein may not be used or 
disclosed except with the written *  permission of MediaTek Inc. (C) 2002 * 
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 * UnifiedComposerProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines local enum, constant and prototypes for Unified Composer
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
#ifndef _MMI_UNIFIED_COMPOSER_PROT_H
#define _MMI_UNIFIED_COMPOSER_PROT_H

#ifndef _FILE_MGR_H_
#error "Please include FileMgr.h first"
#endif 

#ifndef _KAL_RELEASE_H
#error "Please include kal_release.h first"
#endif 

#ifndef _WAPADP_H
#error "Please include wapadp.h first"
#endif 

#ifndef _MMI_UNIFIED_COMPOSER_GPROT_H
#error "Please include UnifiedComposerGProt.h first"
#endif 


#define MMI_UC_MAX_ATTACHMENT_NUM (MMA_MAX_ATTACHMENT_NO)
#define MMI_UC_MAX_ADDRESS_NUM (MMA_MAX_RECIPIENT_NO)
#define MMI_UC_MAX_MMS_SLIDE_NUM (MMA_MAX_SLIDE_NO)

#define MMI_UC_MAX_SLIDE_TIMING_DIGIT (3)
#define MMI_UC_MAX_SLIDE_NUM_DIGIT (5)

//#define MMI_UC_MAX_SLIDE_TIMING (60)

#define MMI_UC_POPUP_TIME_OUT             (UI_POPUP_NOTIFYDURATION_TIME_2000)

#define MMI_UC_INPROGRESS_TIME_OUT        ((MMA_MAX_PROCESS_TIME) + (1000 * 50))

#define MMI_UC_MSG_TYPE_CHECK_TIME        (1)


#define MMI_UC_MAX_SMS_PAGE_DIGIT (3) /* Support up to 999 SMS segments */
#define MMI_UC_MAX_RECIPIENT_DIGIT (4) /* Support up to 9999 recipients */
#define MMI_UC_MAX_TOTAL_MSG_DIGIT (6) /* Support up to 999999 SMS segments */
#define MMI_UC_MAX_SIZE_DIGIT (10) /* Support up to 9999999 kB */
#define MMI_UC_MAX_ATTACHMENT_DIGIT (MAX_SUBMENU_CHARACTERS)
#define MMI_UC_MAX_ATTACHMENT_FILE_NAME_DIGIT (30)

#ifndef MMI_UC_MAX_IMAGE_WIDTH
#define MMI_UC_MAX_IMAGE_WIDTH (1600)
#endif

#ifndef MMI_UC_MAX_IMAGE_HEIGHT
#define MMI_UC_MAX_IMAGE_HEIGHT (1600)
#endif

/* (999999 kB)  */
#define MMI_UC_MAX_ATTACHMENT_SIZE_DIGIT (MAX_SUBMENU_CHARACTERS - MMI_UC_MAX_ATTACHMENT_FILE_NAME_DIGIT)

#define MMI_UC_DEFAULT_BG_COLOR (MMA_DEFAULT_SMIL_BG_COLOR)
#define MMI_UC_DEFAULT_FG_COLOR (MMA_DEFAULT_SMIL_FG_COLOR)

#define MMI_UC_INVALID_INDEX (0xFFFF)


#define MMI_UC_FOLDER_DRV MMI_PUBLIC_DRV
#define MMI_UC_FOLDER_NAME "_UC"
#define MMI_UC_TEXT_FILENAME "T"
#define MMI_UC_TEXT_FILEEXT "txt"
#define MMI_UC_IMAGE_FILENAME "I"
#define MMI_UC_IMAGE_FILEEXT "jpg"
#define MMI_UC_MAX_TEMP_FILE_LEN ((20 + 1) * ENCODING_LENGTH)
#define MMI_UC_XML_FILENAME "X"
#define MMI_UC_XML_FILEEXT "xml"
#define MMI_UC_XML_TEMP_STR_LEN (1024)
#define MMI_UC_MAX_XML_SIZE_IN_PEER_BUFFER (2000)


#define MMI_UC_MAKE_FOLDER_PATH(x)      \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\%s", \
      MMI_UC_FOLDER_DRV, MMI_UC_FOLDER_NAME);

#define MMI_UC_MAKE_TEXT_FILE_PATH(x, d)   \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\%s\\%s%03d.%s",\
      MMI_UC_FOLDER_DRV, MMI_UC_FOLDER_NAME, MMI_UC_TEXT_FILENAME, d, MMI_UC_TEXT_FILEEXT ); 

#define MMI_UC_MAKE_IMAGE_FILE_PATH(x, d)   \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\%s\\%s%03d.%s",\
      MMI_UC_FOLDER_DRV, MMI_UC_FOLDER_NAME, MMI_UC_IMAGE_FILENAME, d, MMI_UC_IMAGE_FILEEXT ); 

#define MMI_UC_MAKE_MMS_XML_FILE_PATH(x, d)   \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\%s\\%s%03d.%s",\
      MMI_UC_FOLDER_DRV, MMI_UC_FOLDER_NAME, MMI_UC_XML_FILENAME, d, MMI_UC_XML_FILEEXT );

#define MMI_UC_XML_ELEMENT_MMS "mms"
#define MMI_UC_XML_ELEMENT_HEADER "header"
#define MMI_UC_XML_ELEMENT_TO "to"
#define MMI_UC_XML_ELEMENT_CC "cc"
#define MMI_UC_XML_ELEMENT_BCC "bcc"
#define MMI_UC_XML_ELEMENT_FROM "from"
#define MMI_UC_XML_ATTR_TYPE "type"
#define MMI_UC_XML_ATTR_POHNE_NUMBER "P"
#define MMI_UC_XML_ATTR_EMAIL_ADDR "E"
#define MMI_UC_XML_ELEMENT_SUBJECT "subject"
#define MMI_UC_XML_ELEMENT_READ_REPORT "rr"
#define MMI_UC_XML_ELEMENT_DELIVERY_REPORT "dr"
#define MMI_UC_XML_ELEMENT_PRIORITY "prio"
#define MMI_UC_XML_ELEMENT_EXPIRY "expiry"
#define MMI_UC_XML_ELEMENT_DELIVERY_TIME "delivery"
#define MMI_UC_XML_ELEMENT_VISIBLE "visible"
#define MMI_UC_XML_ELEMENT_BODY "body"
#define MMI_UC_XML_ATTR_BGCOLOR "bgColor"
#define MMI_UC_XML_ATTR_FGCOLOR "fgColor"
#define MMI_UC_XML_ATTR_SLIDE_NUM "slideNum"
#define MMI_UC_XML_ATTR_OBJ_NUM "objNum"
#define MMI_UC_XML_ATTR_LAYOUT "layout"
#define MMI_UC_XML_ELEMENT_SLIDE "slide"
#define MMI_UC_XML_ATTR_INDEX "index"
#define MMI_UC_XML_ATTR_DURATION "dur"
#define MMI_UC_XML_ATTR_ID "id"
#define MMI_UC_XML_ATTR_BEGIN "begin"
#define MMI_UC_XML_ATTR_END "end"
#define MMI_UC_XML_ELEMENT_TEXT "text"
#define MMI_UC_XML_ELEMENT_IMAGE "img"
#define MMI_UC_XML_ELEMENT_AUDIO "audio"
#define MMI_UC_XML_ELEMENT_VIDEO "video"
#define MMI_UC_XML_ATTR_ATTACH "attach"
#define MMI_UC_XML_ATTR_VIRTUAL_FILE "vf"
#define MMI_UC_XML_ATTR_DRM "drm"
#define MMI_UC_XML_ATTR_SIZE "size"
#define MMI_UC_XML_ATTR_OFFSET "offset"
#define MMI_UC_XML_ATTR_ENCODING "encoding"
#define MMI_UC_XML_ELEMENT_OBJECT "obj"
#define MMI_UC_XML_ELEMENT_NAME "name"
#define MMI_UC_XML_ELEMENT_FILE_PATH "filepath"


/*
 * Image Resizing
 */
#define MMI_UC_RESIZING_SUCCEED                                         (1)
#define MMI_UC_RESIZING_SUCCEED_WITH_UNCHANGED                          (0)
#define MMI_UC_RESIZING_FAILED_IN_GDI_FAILED                            (-1)
#define MMI_UC_RESIZING_FAILED_IN_GDI_ENCODER_ERR_DISK_FULL             (-5)
#define MMI_UC_RESIZING_FAILED_IN_GDI_ENCODER_ERR_WRITE_PROTECTION      (-6)
#define MMI_UC_RESIZING_FAILED_IN_GDI_ENCODER_ERR_NO_DISK               (-7)
#define MMI_UC_RESIZING_FAILED_IN_NO_QUOTA                              (-10)
#define MMI_UC_RESIZING_FAILED_IN_UNKNOWN_DIMENSION                     (-11)
#define MMI_UC_RESIZING_FAILED_IN_INSUFFICIENT_DRAWING_BUF              (-12)


typedef enum
{
    MMI_UC_DONE_TO_CAPTION,
    MMI_UC_DONE_TO,
    MMI_UC_DONE_CC_CAPTION,
    MMI_UC_DONE_CC,
    MMI_UC_DONE_BCC_CAPTION,
    MMI_UC_DONE_BCC,
    MMI_UC_DONE_SUBJECT_CAPTION,
    MMI_UC_DONE_SUBJECT,
    MMI_UC_DONE_MSG_DETAIL_CAPTION,
    
    MMI_UC_DONE_TOTAL_NUM    
} mmi_uc_done_enum;

typedef enum
{
    MMI_UC_DONE_SMS_ONLY_TO_CAPTION = MMI_UC_DONE_TO_CAPTION, 
    MMI_UC_DONE_SMS_ONLY_TO,
    MMI_UC_DONE_SMS_ONLY_MSG_DETAIL_CAPTION,
    
    MMI_UC_DONE_SMS_ONLY_TOTAL_NUM    
} mmi_uc_done_sms_onlyenum;

typedef enum
{
    MMI_UC_SEND_OPT_VALIDITY_PERIOD_CAPTION,
    MMI_UC_SEND_OPT_VALIDITY_PERIOD,
    MMI_UC_SEND_OPT_DELIVERY_REPORT_CAPTION,
    MMI_UC_SEND_OPT_DELIVERY_REPORT,
    MMI_UC_SEND_OPT_READ_REPORT_CAPTION,
    MMI_UC_SEND_OPT_READ_REPORT,
    MMI_UC_SEND_OPT_PRIORITY_CAPTION,
    MMI_UC_SEND_OPT_PRIORITY,
    MMI_UC_SEND_OPT_DELIVERY_TIME_CAPTION,
    MMI_UC_SEND_OPT_DELIVERY_TIME,    
    
    MMI_UC_SEND_OPT_TOTAL_NUM    
} mmi_uc_send_opt_enum;


typedef enum
{
    MMI_UC_DONE_STATE_ADD_NUMBER,
    MMI_UC_DONE_STATE_ADD_EMAIL,
    MMI_UC_DONE_STATE_EDIT_NUMBER,
    MMI_UC_DONE_STATE_EDIT_EMAIL,
    MMI_UC_DONE_STATE_ADD_NUMBER_GROUP,
    MMI_UC_DONE_STATE_ADD_EMAIL_GROUP,
    
    MMI_UC_DONE_STATE_TOTAL_NUM    
} mmi_uc_done_state_enum;

typedef enum
{
    MMI_UC_OK,
    MMI_UC_SIZE_EXCEEDS,
    MMI_UC_SIZE_NOT_ENOUGH_FOR_REC_VIDEO,
    MMI_UC_PROHIBIT_BY_CREATION_MODE,
    MMI_UC_PROHIBIT_BY_DRM,
    MMI_UC_NO_SPACE,
    MMI_UC_STORAGE_FULL,
    MMI_UC_ERROR,
    MMI_UC_XML_ERROR,
    MMI_UC_NOT_SUPPORT,
    
    MMI_UC_FILE_CORRUPT,
    MMI_UC_FILE_EMPTY,
    MMI_UC_RESULT_TOTAL_NUM
} mmi_uc_result;


typedef enum
{
    MMI_UC_ACTION_IDLE,
    MMI_UC_ACTION_SEND,
    MMI_UC_ACTION_SEND_AND_SAVE,    
    MMI_UC_ACTION_SAVE,
    MMI_UC_ACTION_DELETE,
    MMI_UC_ACTION_PREVIEW,
    MMI_UC_ACTION_SAVE_IN_BACKGROUND,
    MMI_UC_ACTION_SAVE_AS_TEMPLATE,
    MMI_UC_ACTION_SEND_IN_BACKGROUND,
    MMI_UC_ACTION_DELETE_IN_BACKGROUND,
    
    MMI_UC_ACTION_TOTAL_NUM
} mmi_uc_action_type_enum;

typedef enum
{
    MMI_UC_ABORT_NONE,
    MMI_UC_ABORT_BY_END_KEY,
    MMI_UC_ABORT_NORMAL,
    
    MMI_UC_ABORT_TOTAL_NUM
} mmi_uc_abort_type_enum;

typedef struct
{    
    KAL_ADM_ID mem_pool_id; /* ADM pool ID */
    U8 text_buffer[MMI_UC_TEXT_BUFFER_SIZE];
    U8 slide_timing[(MMI_UC_MAX_SLIDE_TIMING_DIGIT + 1) * ENCODING_LENGTH];
    U8 slide_number[(MMI_UC_MAX_SLIDE_NUM_DIGIT + 1) * ENCODING_LENGTH];
    S32 file_handle;
    U8* file_path;
    U32 image_no;
    S32 current_text_file_save_result;
    U16 object_index;
    mmi_uc_object_type highlighted_object_type;
    mmi_uc_state_enum state;
    uc_func_ptr callback;
    void* callback_para;
    
} mmi_uc_main_struct;

typedef struct
{
    mmi_uc_msg_type_enum curr_msg_type; /* only SMS_PREFER and MMS_PREFER */
    mmi_uc_msg_type_enum setting_msg_type; /* only SMS_PREFER and MMS_PREFER */
    mmi_uc_msg_type_enum caller_specific_msg_type;    
    mmi_uc_msg_type_enum backup_msg_type;

} mmi_uc_msg_type_struct;

typedef struct
{
    UI_string_type read_report_str[2];    
    S32 read_report;

    UI_string_type delivery_report_str[2];
    S32 delivery_report;

    UI_string_type priority_str[3];
    S32 priority;

    UI_string_type validity_period_str[6]; 
    S32 validity_period;

    UI_string_type delivery_time_str[4];
    S32 delivery_time;

    UI_string_type sender_visibility_str[2];
    S32 sender_visibility;
} mmi_uc_send_opt_struct;


typedef struct
{
    U16* text_file;
    U16* img_file;
    U16* audio_file;
    U16* video_file;
    BOOL enable;          
} mmi_uc_mms_signature_struct;


typedef struct
{
    mmi_uc_mms_signature_struct signature;
    mma_image_resizing_struct  image_resize;
    mma_setting_struct  sliding_time;
    U32 max_mms_size;
    mma_creation_mode_enum creation_mode;
    mma_priority_enum priority;
    mma_expiry_time_enum validity_period; 
    mma_delivery_time_enum delivery_time; 
    BOOL delivery_report;
    BOOL read_report;
    BOOL sender_visibility;
    
    U8 best_page_duration;
    U32 duration;
} mmi_uc_mms_info_struct;

typedef struct
{

    U16 max_gsm7bit_char_num;
    U16 max_ucs2_char_num;

} mmi_uc_sms_info_struct;


typedef struct
{
    S16 caption_str_id;
    S16 body_str_id;
    U16 animation_image_id;
    U16 RSK_str_id;
} mmi_uc_processing_info_struct;


typedef struct
{   
    /*Use MMI_UC_MAX_EMAIL_LEN, because max(email, phonenumber)*/
    U8 to[(MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH];
    U8 cc[(MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH];
    U8 bcc[(MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH];
    //U8 subject[(MMI_UC_MAX_SUBJECT_LEN + 1) * ENCODING_LENGTH];
    U16 current_addr_index;
    mmi_uc_address_group_type_enum current_addr_type;
    mmi_uc_msg_type_enum pre_msg_type;
    mmi_uc_done_state_enum state;
} mmi_uc_done_struct;

typedef struct
{
    U32 send_result;
    U32 save_result;
    U32 delete_result;
    U32 request_id; 
    U32 buffer_index;
    U32 xml_file_size;
    U8* fail_cause;
    FS_HANDLE fs;
    U16 curr_send_number;
    U32 new_msg_id;
    U32 existed_msg_id;
    U16 percent;
    mmi_uc_msg_type_enum existed_msg_type;
    mmi_uc_action_type_enum action;
    mmi_uc_abort_type_enum abort;
    U16 curr_folder; /* UmMsgBoxType */ 
} mmi_uc_send_info_struct;


typedef struct
{
    XML_PARSER_STRUCT* xml_parser;
    mmi_uc_slide_struct* slide;
    mmi_uc_object_struct* object;
    mmi_uc_address_type_enum addr_type;
    
} mmi_uc_xml_struct;


typedef struct
{
    mmi_uc_main_struct main;
    mmi_uc_msg_type_struct msg_type;
    mmi_uc_mms_info_struct mms_info;
    mmi_uc_sms_info_struct sms_info;    
    mmi_uc_msg_struct msg;
    mmi_uc_done_struct done;
    mmi_uc_processing_info_struct processing;
    mmi_uc_send_opt_struct send_opt;
    mmi_uc_send_info_struct send_info;
    mmi_uc_xml_struct xml;
} mmi_uc_context_struct;


extern mmi_uc_context_struct g_uc_cntx; /* global context of uc */
extern mmi_uc_context_struct *g_uc_p;


extern void mmi_uc_init_context(void);
extern void mmi_uc_set_protocol_event_handler(void);
extern void mmi_uc_create_adm_mem(void);
extern void mmi_uc_entry_option(void);
extern void mmi_uc_set_highlight_handler(void);
extern void mmi_uc_highlight_opt_done(void);
extern void mmi_uc_highlight_opt_insert(void);
extern void mmi_uc_highlight_opt_remove(void);
extern void mmi_uc_highlight_opt_replace(void);
extern void mmi_uc_highlight_opt_preview(void);
extern void mmi_uc_highlight_opt_slide_opt(void);
extern void mmi_uc_highlight_opt_send_opt(void);
extern void mmi_uc_highlight_opt_msg_detail(void);
extern void mmi_uc_highlight_opt_input_method(void);
extern void mmi_uc_entry_done(void);
extern void mmi_uc_exit_done(void);
extern void mmi_uc_done_fill_inline_struct(U16* image_list);
extern void mmi_uc_done_highlight_hdlr(S32 index);
extern void mmi_uc_inline_generic_custom_function(void);
extern void mmi_msg_entry_done_option(void);
extern void mmi_uc_entry_addr_option(void);
extern void mmi_uc_entry_addr_list(void);
extern void mmi_uc_set_addr_index(S32 nIndex);
extern pBOOL mmi_uc_addr_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern void mmi_uc_highlight_addr_opt_done(void);
extern void mmi_uc_highlight_addr_opt_add_number(void);
#ifdef __MMI_UC_MULTI_SELECT__
extern void mmi_uc_get_multi_addr_callback (U16 cnt, U16 *PhbIndex);
extern MMI_BOOL mmi_uc_check_valid_address(U16 cnt_IN, U16 *PhbIndex_IN);
#endif
extern void mmi_uc_add_processing_to_history(void);
extern void mmi_uc_highlight_addr_opt_add_email(void);
extern void mmi_uc_highlight_addr_opt_edit(void);
extern void mmi_uc_highlight_addr_opt_delete(void);
extern void mmi_uc_highlight_addr_opt_delete_all(void);
extern void mmi_uc_highlight_addr_opt_add_number_group(void);
extern void mmi_uc_highlight_addr_opt_add_email_group(void);
extern void mmi_uc_entry_add_number(void);
extern void mmi_uc_add_number_not_empty(void);
extern void mmi_uc_add_number_empty(void);
extern void mmi_uc_search_phb_number(void);
extern void mmi_uc_entry_done_option(void);
extern void mmi_uc_addr_add_number_done(void);
extern BOOL mmi_uc_add_address(U8* addr, mmi_uc_address_type_enum type, mmi_uc_address_group_type_enum group);
extern mmi_uc_addr_struct* mmi_uc_check_duplicate_address(U8* ucs2_addr, mmi_uc_address_type_enum type, mmi_uc_address_group_type_enum group);
extern mmi_uc_addr_struct* mmi_uc_check_duplicate_address_with_start_addr(U8* ucs2_addr, mmi_uc_address_type_enum type, mmi_uc_addr_struct* start_addr);
extern BOOL mmi_uc_change_msg_type_if_needed(void);
extern void mmi_uc_update_msg_size(void);
extern mmi_uc_msg_type_enum mmi_uc_determine_msg_type_by_content(void);
extern void mmi_uc_go_back_to_done(void);
extern void mmi_uc_entry_add_email(void);
extern void mmi_uc_add_email_empty(void);
extern void mmi_uc_add_email_not_empty(void);
extern void mmi_uc_search_phb_email(void);
extern void mmi_uc_addr_add_email_done(void);
extern void mmi_uc_entry_edit_addr(void);
extern mmi_uc_addr_struct* mmi_uc_get_highlighted_addr(void);
extern void mmi_uc_entry_delete_addr(void);
extern void mmi_uc_process_delete_addr(void);
extern void mmi_uc_delete_addr(mmi_uc_addr_struct* addr);
extern void mmi_uc_free_addr_memory(mmi_uc_addr_struct* addr);
extern void mmi_uc_entry_delete_all_addr(void);
extern void mmi_uc_process_delete_all_addr(void);
extern void mmi_uc_delete_all_addr(mmi_uc_address_group_type_enum group);
extern void mmi_uc_entry_msg_detail(void);
extern void mmi_uc_msg_detail_fill_info(U8* info);
extern void mmi_uc_copy_with_dot(S8 *dest, S8 *source, S32 max_len);
extern void mmi_uc_highlight_done_opt_send(void);
extern void mmi_uc_highlight_done_opt_send_and_save(void);
extern void mmi_uc_highlight_done_opt_save(void);
extern void mmi_uc_highlight_done_opt_back_to_edit(void);
extern void mmi_uc_highlight_done_opt_send_opt(void);
extern void mmi_uc_highlight_done_opt_exit(void);
extern void mmi_uc_entry_insert(void);
extern void mmi_uc_highlight_insert_image(void);
extern void mmi_uc_highlight_insert_audio(void);
extern void mmi_uc_highlight_insert_video(void);
extern void mmi_uc_highlight_insert_text_template(void);
extern void mmi_uc_highlight_insert_attachment(void);
extern void mmi_uc_highlight_insert_phb_number(void);
extern void mmi_uc_highlight_insert_phb_name(void);
extern void mmi_uc_highlight_insert_bookmark(void);
extern void mmi_uc_highlight_remove_image(void);
extern void mmi_uc_highlight_remove_audio(void);
extern void mmi_uc_highlight_remove_video(void);
extern void mmi_uc_highlight_remove_attachment(void);
extern void mmi_uc_highlight_replace_image(void);
extern void mmi_uc_highlight_replace_audio(void);
extern void mmi_uc_highlight_replace_video(void);
extern void mmi_uc_highlight_replace_attachment(void);
extern void mmi_uc_entry_insert_phb_name(void);
extern void mmi_uc_entry_insert_phb_number(void);
extern void mmi_uc_insert_number_from_phb(S8* name, S8* number);
extern void mmi_uc_insert_name_from_phb(S8* name, S8* number);
extern void mmi_uc_entry_insert_bookmark(void);
extern void mmi_uc_handle_select_bookmark_rsp(void *inMsg);
extern void mmi_uc_select_fmgr_object(void);
extern void mmi_uc_set_file_mgr_filter(FMGR_FILTER* filter, const char *mime_types);
extern void mmi_uc_set_file_mgr_filter_all(FMGR_FILTER* filter);
extern void mmi_uc_select_object_from_fm_to_insert(PU16 filePath, S32 is_short);
extern void mmi_uc_select_object_from_fm_to_replace(PU16 filePath, S32 is_short);
extern mmi_uc_object_struct* mmi_uc_insert_object(S8* filePath, mmi_uc_object_type object_type);
extern U32 mmi_uc_convert_to_mms_insert_type(mmi_uc_object_type object_type);
extern mmi_uc_result mmi_uc_convert_mms_check_result(mma_insert_check_struct* check_result);
extern void mmi_uc_display_popup(mmi_uc_result result);
extern mmi_uc_slide_struct* mmi_uc_insert_slide(mmi_uc_slide_struct* cur_slide);
extern mmi_uc_object_struct* mmi_uc_check_duplicate_object(U16* filePath);
extern BOOL mmi_uc_check_if_exceed_MMS_size_limitation(U32 size);
extern void mmi_uc_insert_object_to_slide(mmi_uc_object_struct* object, mmi_uc_slide_struct* slide, mmi_uc_object_type object_type);
extern wgui_uce_text_change_result_enum mmi_uc_text_change_callback(wgui_uce_text_info_struct *new_text_info);
extern U32 mmi_uc_get_message_size_callback (wgui_uce_text_info_struct *current_text_info, wgui_uce_msg_type_enum uce_msg_type);
extern void mmi_uc_editor_initialize(void);
extern void mmi_uc_editor_add_object(mmi_uc_object_struct* object, mmi_uc_object_type object_type);
extern U32 mmi_uc_convert_to_editor_object_type(mmi_uc_object_type object_type);
extern U32 mmi_uc_convert_to_editor_layout_type(mmi_uc_layout_enum layout_type);
extern U32 mmi_uc_convert_to_mms_layout_type(mmi_uc_layout_enum layout_type);
extern U32 mmi_uc_convert_mms_layout_type_to_uc(U8 layout_type);
extern void mmi_uc_insert_object_to_attachment(mmi_uc_object_struct*  object, mmi_uc_attachment_info_struct* attachment);
extern U16* mmi_uc_get_file_name(U16* filePath);
extern void mmi_uc_entry_remove(void);
extern void mmi_uc_remove_object(void);
extern void mmi_uc_entry_attachment_list(void);
extern void mmi_uc_set_index(S32 hilited_index);
extern void mmi_uc_delete_object_from_list(mmi_uc_object_struct* object);
extern mmi_uc_attachment_info_struct* mmi_uc_get_attachment_by_index(U16 index);
extern void mmi_uc_delete_attachment_from_list(mmi_uc_attachment_info_struct* att);
extern void mmi_uc_entry_replace(void);
extern mmi_uc_attachment_info_struct* mmi_uc_insert_attachment(void);
extern mmi_uc_object_struct* mmi_uc_get_object_in_slide(mmi_uc_slide_struct* slide, mmi_uc_object_type object_type);  
extern void mmi_uc_entry_slide_opt(void);
extern void mmi_uc_highlight_slide_opt_insert(void);
extern void mmi_uc_highlight_slide_opt_insert_before(void);
extern void mmi_uc_highlight_slide_opt_delete(void);
extern void mmi_uc_highlight_slide_opt_previous(void);
extern void mmi_uc_highlight_slide_opt_next(void);
extern void mmi_uc_highlight_slide_opt_timing(void);
extern void mmi_uc_entry_insert_slide(void);
extern void mmi_uc_entry_insert_slide_before(void);
extern void mmi_uc_reset_text_buffer(void);
extern void mmi_uc_entry_delete_slide(void);
extern void mmi_uc_init_uc_folder(void);
extern S32 mmi_uc_save_buffer_to_file(U8* file_path, U8* buffer, U16 char_num);
extern void mmi_uc_set_editor_info(mmi_uc_slide_struct* slide);
extern void mmi_uc_delete_slide(mmi_uc_slide_struct* slide);
extern void mmi_uc_switch_slide(mmi_uc_slide_struct* slide);
extern void mmi_uc_read_file_to_text_buffer(U8* file_path, U32 encoding);
extern void mmi_uc_set_text_info_to_slide(mmi_uc_slide_struct* slide, wgui_uce_text_info_struct* text_info);
extern void mmi_uc_set_text_info_from_slide(mmi_uc_slide_struct* slide, wgui_uce_text_info_struct* text_info);
extern void mmi_uc_entry_previous_slide(void);
extern void mmi_uc_entry_next_slide(void);
extern void mmi_uc_entry_slide_timing(void);
extern void mmi_uc_entry_slide_timing_done(void);
extern void mmi_uc_entry_goto_slide(void);
extern void mmi_uc_entry_send_opt(void);
extern void mmi_uc_entry_input_method_done(void);
extern void mmi_uc_exit_send_opt(void);
extern void mmi_uc_send_opt_fill_inline_struct(U16* image_list);
extern void mmi_uc_send_opt_done_hdlr(void);
extern void mmi_uc_get_mms_setting_req(void);
extern void mmi_uc_get_mms_setting_rsp(void *inMsg);
extern void mmi_uc_create_mms_req(void);
extern void mmi_uc_create_mms_rsp(void *inMsg);
extern BOOL mmi_uc_insert_signature(void);
extern void mmi_uc_delete_slide_with_object(mmi_uc_slide_struct* slide);
extern BOOL mmi_uc_insert_signature_file(U16* file_path, mmi_uc_slide_struct* slide, mmi_uc_object_type type);
extern void mmi_uc_get_sms_setting(void);
extern void mmi_uc_process_entry_write_msg(void);
extern void mmi_uc_discard_msg_before_enter_write_msg(void);
extern void mmi_uc_reset_msg(void);
extern mmi_uc_msg_type_enum mmi_uc_get_setting_msg_type(void);
extern void mmi_uc_go_back_from_write_msg(void);
extern void mmi_uc_discard_msg_before_exit_write_msg(void);
extern void mmi_uc_save_msg_before_exit_write_msg(void);
extern void mmi_uc_highlight_preferred_type(void);
extern void mmi_uc_entry_preferred_type(void);
extern void mmi_uc_save_preferred_type(void);
extern void mmi_uc_init_setting(void);
extern void mmi_uc_process_exit(void);
extern void mmi_uc_process_back_to_edit(void);
extern void mmi_uc_process_send(void);
extern void mmi_uc_send_sms_req(void);
extern void mmi_uc_send_sms_rsp(void *number, module_type mod, U16 result);
extern void mmi_uc_action_fsm(mmi_uc_action_type_enum action, U32 result);
extern void mmi_uc_create_mms(void);
extern void mmi_uc_send_mms(void);
extern void mmi_uc_save_mms(void);
extern void mmi_uc_send_mms_req(BOOL send_and_save, U16 msg_box_to_save);
extern void mmi_uc_send_mms_rsp(void *inMsg);
extern void mmi_uc_clear_msg_bearer(mmi_uc_msg_type_enum msg_type);
extern void mmi_uc_delete_sms_frm_screen(void);
extern mmi_uc_addr_struct* mmi_uc_get_addr(mmi_uc_address_group_type_enum addr_type, U16 index);
extern void mmi_uc_save_sms_after_send(U8 status, void *number);
extern void mmi_uc_save_sms_rsp(void *status, module_type mod, U16 result);
extern void mmi_uc_process_send_and_save(void);
extern void mmi_uc_process_save(void);
extern void mmi_uc_save_sms_req(void);
extern S32 mmi_uc_create_mms_xml_description_file(void);
extern S32 mmi_uc_create_xml_element_start(FS_HANDLE fh, U8* element_name, U8** attr_list);
extern S32 mmi_uc_create_xml_element_end(FS_HANDLE fh, U8* element_name);
extern S32 mmi_uc_create_xml_element_single(FS_HANDLE fh, U8* element_name, U8** attr_list);
extern S32 mmi_uc_create_xml_data(FS_HANDLE fh, U8* data);
extern S32 mmi_uc_create_xml_new_line(FS_HANDLE fh);
extern S32 mmi_uc_create_xml_addr(FS_HANDLE fh, mmi_uc_address_group_type_enum type);
extern S32 mmi_uc_create_xml_data_usc2_to_utf8(FS_HANDLE fh, U8* data);
extern S32 mmi_uc_create_xml_data_usc2_to_utf8_to_base64(FS_HANDLE fh, U8* data);
extern S32 mmi_uc_create_xml_data_numeric_to_char(FS_HANDLE fh, U32 value);
extern S32 mmi_uc_create_xml_slide_object(FS_HANDLE fh, mmi_uc_slide_struct* slide, mmi_uc_object_type obj_type);
extern S32 mmi_uc_create_xml_object(FS_HANDLE fh, mmi_uc_object_struct* obj);
extern S32 mmi_uc_parse_mms_xml_description_file(U16* file_path);
extern void mmi_uc_update_object_id(void);
extern void mmi_uc_entry_sending_sms(void);
extern void mmi_uc_abort_send_sms_by_end_key(void);
extern void mmi_uc_abort_send_sms(void);
extern void mmi_uc_entry_sending_mms(void);
extern void mmi_uc_update_sending_mms_percent_and_retry(U16 percent, U8 retry);
extern void mmi_uc_abort_send_mms_by_end_key(void);
extern void mmi_uc_abort_send_mms(void);
extern void mmi_uc_delete_mms_req(U32 msg_id);
extern void mmi_uc_delete_mms_rsp(void *in_msg);
extern void mmi_uc_save_mms_req(U32 msg_id, U16 msg_box);
extern void mmi_uc_save_mms_rsp(void *in_msg);
extern void mmi_uc_abort_send_mms_req(U32 msg_id);
extern void mmi_uc_abort_send_mms_rsp(void *in_msg);
extern void mmi_uc_send_sms(void);
extern void mmi_uc_save_sms(void);
extern void mmi_uc_send_and_save_mms(void);
extern void mmi_uc_delete_sms_callback(void *dummy, module_type mod, U16 result);
extern void mmi_uc_start_req(void *inMsg);
extern void mmi_uc_start_rsp(U16 result, U32 msg_id, U16 app_mode);
extern U16 mmi_uc_convert_mms_app_mode_to_uc_state(U16 app_mode);
extern U16 mmi_uc_convert_uc_state_to_mms_app_mode(U16 uc_state);
extern void mmi_uc_get_mms_content_req(void);
extern void mmi_uc_get_mms_content_rsp(void* in_msg);
extern void mmi_uc_xml_start_element_hdlr(void *data, const char *el, const char **attr, S32 error);
extern void mmi_uc_xml_end_element_hdlr(void *data, const char *el, S32 error);
extern void mmi_uc_xml_data_hdlr(void *data, const char *el, const char *value, int len, S32 error);
extern void mmi_uc_xml_data_address_hdlr(U8* utf8_addr,
                                         S32 addr_len,
                                         mmi_uc_address_type_enum addr_type, 
                                         mmi_uc_address_group_type_enum addr_group_type);
extern U32 mmi_uc_convert_ascii_hex_to_dec(U8* character);
extern mmi_uc_slide_struct* mmi_uc_insert_slide_by_number(U8 slide_number);
extern mmi_uc_object_struct* mmi_uc_insert_object_to_list_tail(void);
extern S32 mmi_uc_match_object_id(void);
extern mmi_uc_object_struct* mmi_uc_get_object_by_id(U32 object_id);
extern BOOL mmi_uc_check_only_attachment (void);
extern U16* mmi_uc_get_file_extension(U16* filePath);
extern S32 mmi_uc_resize_image(U8 *file, U8 *dest_file, U32 resize_w, U32 resize_h);
extern U32 mmi_uc_calc_file_size_in_utf8(U8* file_path);
extern void mmi_uc_entry_preview(void);
extern U8 mmi_uc_editor_delete_history_hdlr(void *in_param);
extern void mmi_uc_preview_mms(void);
extern void mmi_uc_preview_mms_req(void);
extern void mmi_uc_preview_mms_rsp(void *in_msg);
extern U8 mmi_uc_preview_delete_history_hdlr(void *in_param);
extern void mmi_uc_pre_entry_option(void);
extern void mmi_uc_entry_write_msg(void);
extern BOOL mmi_uc_is_pending_content(void);
extern U8 mmi_uc_write_msg_delete_history_hdlr(void *in_param);
extern U8 mmi_uc_get_sms_segment_number(void);
extern void mmi_uc_set_processing_screen(U16 captionStrId, U16 bodyStrId, U16 animationImageId, U16 rskStrId);
extern void mmi_uc_entry_processing_generic(void);
extern U32 mmi_uc_convert_to_editor_msg_type(mmi_uc_msg_type_enum msg_type);
extern void mmi_uc_exit_generic(void);
extern void mmi_uc_reset_layout_if_needed(void);
extern S32 mmi_uc_create_xml_slide(FS_HANDLE fh, mmi_uc_slide_struct* slide);
extern void mmi_uc_send_mms_ind_hdlr(void *inMsg);
extern void mmi_uc_send_message(
        module_type MOD_SRC,
        module_type MOD_DEST,
        U8 MSG_SAP,
        const U16 MSG_ID,
        void *LOCAL,
        void *PEER);

extern mmi_uc_object_type mmi_uc_convert_mms_insert_type_to_uc(U32 object_type);
extern BOOL mmi_uc_reset_history_guibuffer(U16 screen_id);
extern S32 mmi_uc_handle_text_in_current_slide(void);
extern void mmi_uc_highlight_opt_msg_type(void);
extern BOOL mmi_uc_is_email_addr_valid(U8* email_addr);
extern void mmi_uc_pre_entry_edit_addr(void);
extern void mmi_uc_handle_msg_type_check(void);
extern void mmi_uc_disply_msg_type_change(void);
extern void mmi_uc_entry_add_addr_group(void);
extern void mmi_uc_entry_exit_option(void);
extern void mmi_uc_highlight_exit_opt_save(void);
extern void mmi_uc_highlight_exit_opt_exit(void);
extern void mmi_uc_highlight_slide_opt_goto(void);
extern void mmi_uc_entry_goto_slide_done(void);
extern void mmi_uc_reset_mms_signature(void);
extern void mmi_uc_insert_signature_check(void);
extern void mmi_uc_replace_duplicate_object_file_name(void);
extern BOOL mmi_uc_compare_string_ignore_case(U16* addr_1, U16* addr_2);
extern U8 mmi_uc_done_delete_history_hdlr(void *in_param);
extern void mmi_uc_delete_existed_mms(void);
extern void mmi_uc_update_text_object_path( mmi_uc_slide_struct* update_slide);
extern mmi_uc_slide_struct* mmi_uc_get_end_slide(void);
extern BOOL mmi_uc_delete_between_screens(U16 start_screen_id, U16 end_screen_id);
extern void mmi_uc_exit_write_msg(void);
extern void mmi_uc_display_mma_result_popup(mma_result_enum result);
extern void mmi_uc_display_mma_send_result_popup(mma_result_enum result);
extern void mmi_uc_display_resize_result_popup(U16 result);
extern void mmi_uc_entry_processing_after_send(void);
extern S32 mmi_uc_check_uc_folder(void);
extern BOOL mmi_uc_is_resized_image(U16* file_path);
extern BOOL mmi_uc_is_valid_image(U16* file_path);

#ifdef __MMI_MMS_2__
extern void mmi_uc_show_preview_slide_list (void);
#endif /* __MMI_MMS_2__ */

mmi_uc_expiry_time_enum mmi_uc_convert_mms_expiry_time_to_uc(U32 mms_expiry_time);
U32 mmi_uc_convert_to_mms_expiry_time(mmi_uc_expiry_time_enum uc_expiry_time);
mmi_uc_delivery_time_enum mmi_uc_convert_mms_delivery_time_to_uc(U32 mms_delivery_time);
U32 mmi_uc_convert_to_mms_delivery_time(mmi_uc_delivery_time_enum uc_delivery_time);

extern pBOOL ComparePhoneNum(PU8 src, PU8 dst);

extern kal_uint32 wap_mma_uc_calc_msg_size(const mmi_uc_msg_struct *mms);
extern kal_uint32 wap_mma_uc_calc_header_size(const mmi_uc_msg_struct *mms);

#ifdef __MMI_MMS_2__
extern void mmi_uc_highlight_slide_opt_text_timing(void);
extern void mmi_uc_highlight_slide_opt_image_timing(void);
extern void mmi_uc_highlight_slide_opt_video_timing(void);
extern void mmi_uc_highlight_slide_opt_audio_timing(void);
extern void mmi_uc_exit_timing(void);
extern void mmi_uc_entry_timing(void);
extern void mmi_uc_entry_timing_done(void);
extern void mmi_uc_entry_timing_check_before_done(void);
extern void mmi_uc_entry_timing_highlight_hdlr(S32 index);
#endif /* __MMI_MMS_2__ */
extern BOOL mmi_uc_check_virtual_file_object_for_creation_mode(mmi_uc_object_struct *obj, mmi_uc_object_type type);

#if defined(__MMI_MMS_2__) || defined(__MMI_OBIGO_Q03C_MMS_USER_DEFINED_TEMPLATES__)
extern void mmi_uc_highlight_done_opt_save_as_template(void);
extern void mmi_uc_process_save_as_template(void);
#endif

extern void mmi_uc_highlight_insert_new_image(void);
extern void mmi_uc_highlight_insert_new_audio(void);
extern void mmi_uc_highlight_insert_new_video(void);
extern void mmi_uc_enter_multimedia_app(void);
extern void mmi_uc_enter_multimedia_app_callback(MMI_BOOL result, S8* file_path);
extern void mmi_uc_enter_multimedia_app_add_object(void);

extern void mmi_uc_save_mms_to_folder(U16 msg_box_id);
extern U8 mmi_uc_check_number_length_for_sms(void);

#ifdef __MMS_SIZE_CONFIRM_BEFORE_SEND__
extern void mmi_uc_process_send_cancel(void);
extern void mmi_uc_entry_mms_size_confirm_send(void);
extern void mmi_uc_entry_mms_size_confirm_send_and_save(void);
#endif /*__MMS_SIZE_CONFIRM_BEFORE_SEND__*/

#endif /* _MMI_UNIFIED_COMPOSER_PROT_H */ 



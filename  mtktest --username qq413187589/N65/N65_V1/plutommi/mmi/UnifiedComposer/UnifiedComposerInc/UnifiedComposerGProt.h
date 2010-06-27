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
 * UnifiedComposerGProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines global enum, constant and prototypes for Unified Composer
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_UNIFIED_COMPOSER_GPROT_H
#define _MMI_UNIFIED_COMPOSER_GPROT_H

#ifdef __MMI_UNIFIED_COMPOSER__

#include "gui_config.h" /* GUI_INPUT_BOX_MAX_LENGTH */

#ifdef __MMI_MMS_2__
#include "custom_uc_config.h" /* MMI_UC_CUSTOM_MAX_ADDR_LEN */
#endif /* __MMI_MMS_2__ */

#ifdef __MMI_UNIFIED_MESSAGE__
#ifndef _MMI_UNIFIED_MESSAGE_GPROT_H
#error "Please include UnifiedMessageGProt.h first"
#endif 
#endif /* __MMI_UNIFIED_MESSAGE__ */

#ifdef __MMI_UNIFIED_MESSAGE__
#define MMI_UC_MAX_SUBJECT_LEN MMI_UM_MAX_SUBJECT_LEN
#else /* __MMI_UNIFIED_MESSAGE__ */
#define MMI_UC_MAX_SUBJECT_LEN (40)
#endif /* __MMI_UNIFIED_MESSAGE__ */


#ifdef __MMI_MMS_2__
#define MMI_UC_MAX_EMAIL_LEN		(MMI_UC_CUSTOM_MAX_ADDR_LEN) 

#else /* __MMI_MMS_2__ */

#ifdef __MMI_UNIFIED_MESSAGE__
#define MMI_UC_MAX_EMAIL_LEN MMI_UM_MAX_ADDR_LEN
#else /* __MMI_UNIFIED_MESSAGE__ */
#define MMI_UC_MAX_EMAIL_LEN (60)
#endif /* __MMI_UNIFIED_MESSAGE__ */

#endif /* __MMI_MMS_2__ */

#define MMI_UC_MAX_PHONE_NUMBER_LEN (60)


#if MMI_UC_MAX_EMAIL_LEN < MMI_UC_MAX_PHONE_NUMBER_LEN
#error email len shall not smaller than phone number
#endif

#define MMI_UC_MIN_ADDR_LEN (3)
#define MMI_UC_INVALID_VALUE (0xFFFFFFFF) 

#define MMI_UC_MAX_CHAR_NUM_IN_ONE_SLIDE (GUI_INPUT_BOX_MAX_LENGTH)
#define MMI_UC_TEXT_BUFFER_SIZE (MMI_UC_MAX_CHAR_NUM_IN_ONE_SLIDE * ENCODING_LENGTH + ENCODING_LENGTH)
#define MMI_UC_UTF8_TEXT_BUFFER_SIZE (MMI_UC_TEXT_BUFFER_SIZE * ENCODING_LENGTH + ENCODING_LENGTH)

typedef void (*uc_func_ptr) (void *);

typedef enum
{
    MMI_UC_MSG_TYPE_DEFAULT,
    MMI_UC_MSG_TYPE_SMS_PREFER,
    MMI_UC_MSG_TYPE_MMS_PREFER,
    MMI_UC_MSG_TYPE_SMS_ONLY,
    MMI_UC_MSG_TYPE_MMS_ONLY,
    MMI_UC_MSG_TYPE_TOTAL_NUM
} mmi_uc_msg_type_enum;

typedef enum
{
    MMI_UC_INFO_TYPE_SMS,
    MMI_UC_INFO_TYPE_MMS,
    MMI_UC_INFO_TYPE_TOTAL_NUM
} mmi_uc_info_type_enum;

/*
typedef enum
{
    MMI_UC_DONE_TYPE_FORWARD,
    MMI_UC_DONE_TYPE_SEND,
    MMI_UC_DONE_TYPE_TOTAL_NUM
} mmi_uc_done_type_enum;*/

typedef enum
{
    MMI_UC_STATE_WRITE_NEW_MSG,
    MMI_UC_STATE_EDIT_EXISTED_MSG,        
    MMI_UC_STATE_FORWARD, /* Only for inbox and sent box msgs*/
    MMI_UC_STATE_SEND, /* Only for outbox and draft box msgs*/
    MMI_UC_STATE_REPLY,
    MMI_UC_STATE_REPLY_ALL,
    
    MMI_UC_STATE_TOTAL_NUM
} mmi_uc_state_enum;
    
typedef mmi_uc_state_enum mmi_uc_done_type_enum;

typedef enum
{
    MMI_UC_ADDRESS_TYPE_PHONE_NUMBER,
    MMI_UC_ADDRESS_TYPE_EMAIL,
    MMI_UC_ADDRESS_TYPE_TOTAL_NUM
} mmi_uc_address_type_enum;


typedef enum
{
    MMI_UC_ADDRESS_GROUP_TYPE_TO,
    MMI_UC_ADDRESS_GROUP_TYPE_CC,
    MMI_UC_ADDRESS_GROUP_TYPE_BCC,
    MMI_UC_ADDRESS_GROUP_TYPE_FROM,
    MMI_UC_ADDRESS_GROUP_TYPE_TOTAL_NUM
} mmi_uc_address_group_type_enum;

typedef enum
{
    MMI_UC_OBJECT_TYPE_IMAGE,
    MMI_UC_OBJECT_TYPE_AUDIO,
    MMI_UC_OBJECT_TYPE_VIDEO,
    MMI_UC_OBJECT_TYPE_TEXT,
    MMI_UC_OBJECT_TYPE_ATTACHMENT,
    MMI_UC_OBJECT_TYPE_UNKNOWN,
    
    MMI_UC_DONE_TYPE_TOTAL_NUM
} mmi_uc_object_type;

typedef enum
{
    MMI_UC_LAYOUT_DEFAULT,
    MMI_UC_LAYOUT_THUMBNAIL_AT_TOP,
    MMI_UC_LAYOUT_THUMBNAIL_AT_BOTTOM,    
    
    MMI_UC_LAYOUT_TOTAL_NUM
} mmi_uc_layout_enum;


typedef enum
{
    MMI_UC_EXPIRY_NOT_SET,
    MMI_UC_EXPIRY_1_HOUR,
    MMI_UC_EXPIRY_6_HOURS,
    MMI_UC_EXPIRY_12_HOURS,
    MMI_UC_EXPIRY_1_DAY,
    MMI_UC_EXPIRY_1_WEEK,
    MMI_UC_EXPIRY_MAX
}mmi_uc_expiry_time_enum;


typedef enum
{
    MMI_UC_DELIVERY_NOT_SET,
    MMI_UC_DELIVERY_IMMEDIATE,
    MMI_UC_DELIVERY_1_HOUR,
    MMI_UC_DELIVERY_12_HOURS,
    MMI_UC_DELIVERY_24_HOURS
}mmi_uc_delivery_time_enum;


typedef struct mmi_uc_addr_struct_t
{    
    struct mmi_uc_addr_struct_t* next;
    struct mmi_uc_addr_struct_t* previous;
    
    kal_uint8* addr; /* ascii for phone number while ucs2 for email address. NULL terminator is needed */
    mmi_uc_address_type_enum type;
    mmi_uc_address_group_type_enum group;    
} mmi_uc_addr_struct;


typedef struct
{
    kal_uint8 addr_num;
    mmi_uc_addr_struct* addr;
    mmi_uc_msg_type_enum msg_type;
    kal_uint8* file_path;
    kal_uint8* text_buffer;
    kal_uint16 text_num;
    kal_uint8* subject;
    mmi_uc_info_type_enum info_type;
    void* info;
    uc_func_ptr callback;
    void* callback_para;
    
} mmi_uc_entry_write_struct;

typedef struct mmi_uc_object_struct_t
{
    struct mmi_uc_object_struct_t* next;
    struct mmi_uc_object_struct_t* previous;
    U32 encoding; /*mma_charset_enum*/
    U32 offset;
    U32 size; /* file size for non-text object. UTF8 size for text object */
    U16* file_path; /* NULL terminator is needed. */
    U16* file_name;
    U32 id;
    U16 reference_count;
    mmi_uc_object_type type;
    U8 drm_type; /* mma_drm_type_enum */    
    BOOL is_virtual_file;
} mmi_uc_object_struct;

typedef struct mmi_uc_attachment_info_struct_t
{
    struct mmi_uc_attachment_info_struct_t* next;
    struct mmi_uc_attachment_info_struct_t* previous;

    mmi_uc_object_struct* object;
} mmi_uc_attachment_info_struct;

typedef struct
{
    mmi_uc_object_struct* object;
    U32 id;
    U32 begin;
    U32 end;    
} mmi_uc_object_info_struct;

typedef struct
{
    mmi_uc_object_struct* object;
    U32 id;
    U32 background_color;
    U32 foreground_color;
    U16 char_count;     /*Total Character Count*/
    U16 utf8_msg_len;       /*Msg Len in UTF8*/
    U16 extension_char_count;       /*EXT CHAR Count*/
    U16 UCS2_count;    /*UCS2 Count except any extension char*/
    U32 begin;
    U32 end;
} mmi_uc_text_object_info_struct;

typedef struct mmi_uc_slide_struct_t
{
    struct mmi_uc_slide_struct_t* next;
    struct mmi_uc_slide_struct_t* previous;

    mmi_uc_text_object_info_struct text;
    mmi_uc_object_info_struct image;
    mmi_uc_object_info_struct audio;
    mmi_uc_object_info_struct video;
    U32 duration;
    U8 slide_num;
} mmi_uc_slide_struct;

typedef struct
{
    U32 msg_size;   /* total = header + body */
    U32 msg_size_without_text_buffer;
    U32 msg_body_size; /* total = header + body */
    
    U32 background_color;
    U32 foreground_color;
        
    mmi_uc_addr_struct* to_head;
    mmi_uc_addr_struct* cc_head;
    mmi_uc_addr_struct* bcc_head;
    mmi_uc_addr_struct* from;
    U16 subject[MMI_UC_MAX_SUBJECT_LEN + 1];
    U8 to_num;
    U8 cc_num;
    U8 bcc_num;
    
    BOOL read_report;
    BOOL delivery_report;
    U8 priority; /* mma_priority_enum */
    U8 expiry_time; /* mmi_uc_expiry_time_enum */
    BOOL sender_visibility;
    U8 delivery_time; /* mmi_uc_delivery_time_enum */
    
    U8 best_page_duration;
    mmi_uc_slide_struct* slide_head;
    mmi_uc_slide_struct* current_slide;
    mmi_uc_object_struct* object_head;
    mmi_uc_attachment_info_struct* attachment_head;
    U16 slide_timing;

    BOOL signature_inserted;
    BOOL fail_to_insert_signature;
    
    U8 total_slide_num;
    U8 current_slide_num;
    U8 total_object_num;
    U8 total_attachment_num;
    mmi_uc_layout_enum layout;    
} mmi_uc_msg_struct;



extern void mmi_uc_init(void);
extern void mmi_uc_pre_entry_write_msg(void);
extern void mmi_uc_get_address_from_phb(S8 *name, S8 *addr);
extern void mmi_uc_entry_write_msg_with_content(mmi_uc_done_type_enum type, mmi_uc_entry_write_struct* data);
extern void mmi_uc_entry_done_option_with_content (mmi_uc_done_type_enum type, mmi_uc_entry_write_struct* data);
extern void mmi_uc_sd_plug_out_hdlr(void);
extern void mmi_uc_insert_text_template(void);
extern kal_bool mmi_uc_is_uc_screen_in_history(void);
extern kal_bool mmi_uc_is_pending_action(void);
extern void mmi_uc_delete_all_uc_screens(void);
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
#endif /* _MMI_UNIFIED_COMPOSER_GPROT_H */ 


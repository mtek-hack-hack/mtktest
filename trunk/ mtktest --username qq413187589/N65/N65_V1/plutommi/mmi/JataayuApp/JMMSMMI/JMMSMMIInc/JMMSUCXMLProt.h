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
 *  JMMSUCXMLProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the enums,constants,structures, function prototypes used in
 * MMSTemplates.c
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
#ifndef __MMI_UC_JMMS_XML_PROT_H
#define __MMI_UC_JMMS_XML_PROT_H

/* JMMS UC XML Deocoder Functions and DataTypes */
#include "xml_def.h"

typedef void (*mmi_jmms_uc_xml_tag_handler_hdlr) (const char **);
typedef void (*mmi_jmms_uc_xml_decoder_result_hdlr) (JC_RETCODE ret_code, U32 msg_id);

#define JMMS_UC_XML_TAG_SIZE 20
#define MMI_JMMS_UC_MAX_MMS_SLIDE_NUM  (wap_custom_get_max_mms_slides())
#define MMI_JMMS_UC_MAX_XML_SIZE_IN_PEER_BUFFER (2000)

#define MMI_JMMS_UC_XML_ELEMENT_MMS "mms"
#define MMI_JMMS_UC_XML_ELEMENT_HEADER "header"
#define MMI_JMMS_UC_XML_ELEMENT_TO "to"
#define MMI_JMMS_UC_XML_ELEMENT_CC "cc"
#define MMI_JMMS_UC_XML_ELEMENT_BCC "bcc"
#define MMI_JMMS_UC_XML_ELEMENT_FROM "from"
#define MMI_JMMS_UC_XML_ATTR_TYPE "type"
#define MMI_JMMS_UC_XML_ATTR_POHNE_NUMBER "P"
#define MMI_JMMS_UC_XML_ATTR_EMAIL_ADDR "E"
#define MMI_JMMS_UC_XML_ELEMENT_SUBJECT "subject"
#define MMI_JMMS_UC_XML_ELEMENT_READ_REPORT "rr"
#define MMI_JMMS_UC_XML_ELEMENT_DELIVERY_REPORT "dr"
#define MMI_JMMS_UC_XML_ELEMENT_PRIORITY "prio"
#define MMI_JMMS_UC_XML_ELEMENT_EXPIRY "expiry"
#define MMI_JMMS_UC_XML_ELEMENT_DELIVERY_TIME "delivery"
#define MMI_JMMS_UC_XML_ELEMENT_VISIBLE "visible"
#define MMI_JMMS_UC_XML_ELEMENT_BODY "body"
#define MMI_JMMS_UC_XML_ATTR_BGCOLOR "bgColor"
#define MMI_JMMS_UC_XML_ATTR_FGCOLOR "fgColor"
#define MMI_JMMS_UC_XML_ATTR_SLIDE_NUM "slideNum"
#define MMI_JMMS_UC_XML_ATTR_OBJ_NUM "objNum"
#define MMI_JMMS_UC_XML_ATTR_LAYOUT "layout"
#define MMI_JMMS_UC_XML_ELEMENT_SLIDE "slide"
#define MMI_JMMS_UC_XML_ATTR_INDEX "index"
#define MMI_JMMS_UC_XML_ATTR_DURATION "dur"
#define MMI_JMMS_UC_XML_ATTR_ID "id"
#define MMI_JMMS_UC_XML_ATTR_BEGIN "begin"
#define MMI_JMMS_UC_XML_ATTR_END "end"
#define MMI_JMMS_UC_XML_ELEMENT_TEXT "text"
#define MMI_JMMS_UC_XML_ELEMENT_IMAGE "img"
#define MMI_JMMS_UC_XML_ELEMENT_AUDIO "audio"
#define MMI_JMMS_UC_XML_ELEMENT_VIDEO "video"
#define MMI_JMMS_UC_XML_ATTR_ATTACH "attach"
#define MMI_JMMS_UC_XML_ATTR_VIRTUAL_FILE "vf"
#define MMI_JMMS_UC_XML_ATTR_DRM "drm"
#define MMI_JMMS_UC_XML_ATTR_SIZE "size"
#define MMI_JMMS_UC_XML_ATTR_OFFSET "offset"
#define MMI_JMMS_UC_XML_ELEMENT_OBJECT "obj"
#define MMI_JMMS_UC_XML_ELEMENT_NAME "name"
#define MMI_JMMS_UC_XML_ELEMENT_FILE_PATH "filepath"

typedef enum
{
    JMMS_UC_XML_NO_ACTIVE_TAG = 0,
    JMMS_UC_XML_ADD_TO_NUM,
    JMMS_UC_XML_ADD_TO_EMAIL,
    JMMS_UC_XML_ADD_CC_NUM,
    JMMS_UC_XML_ADD_CC_EMAIL,
    JMMS_UC_XML_ADD_BCC_NUM,
    JMMS_UC_XML_ADD_BCC_EMAIL,
    JMMS_UC_XML_ADD_FROM_NUM,
    JMMS_UC_XML_ADD_FROM_EMAIL,
    JMMS_UC_XML_ADD_SUBJECT,
    JMMS_UC_XML_SET_RR,
    JMMS_UC_XML_SET_DR,
    JMMS_UC_XML_SET_PRIORITY,
    JMMS_UC_XML_SET_EXPIRY,
    JMMS_UC_XML_SET_DELIVERY,
    JMMS_UC_XML_SET_VISIBLE,
    JMMS_UC_XML_ADD_SLIDE,
    JMMS_UC_XML_ADD_OBJECT
} mmi_jmms_uc_xml_state_enum;

typedef enum
{
    JMMS_UC_XML_OBJECT_TYPE_NONE,
    JMMS_UC_XML_OBJECT_TYPE_TEXT,
    JMMS_UC_XML_OBJECT_TYPE_AUDIO,
    JMMS_UC_XML_OBJECT_TYPE_VIDEO,
    JMMS_UC_XML_OBJECT_TYPE_IMAGE,
    JMMS_UC_XML_OBJECT_TYPE_ATTACHMENT
} mmi_jmms_uc_xml_object_type_enum;

typedef enum
{
    JMMS_UC_XML_PARSING_MODE_EDIT,
    JMMS_UC_XML_PARSING_MODE_FORWARD
} mmi_jmms_uc_xml_parsing_mode;

typedef struct
{
    U32 bg_color;
    U32 fg_color;
} mmi_jmms_uc_xml_text_details_struct;

typedef union
{
    mmi_jmms_uc_xml_text_details_struct text;
    /* If required in furture various object details dependending on object type will be added here */
} mmi_jmms_uc_xml_object_details_union;

typedef struct __mmi_jmms_uc_xml_object_info_struct
{
    U32 id;
    U8 drm;
    U8 vf;
    U8 reserved;
    U8 total_slides;
    U8 *slide_num;
    U8 *begin;
    U8 *end;
    U32 size;
    U32 offset;
    S16 *file_name;
    S16 *file_path;
    U32 type;   /* mmi_jmms_uc_xml_object_type_enum */
    mmi_jmms_uc_xml_object_details_union object;
    struct __mmi_jmms_uc_xml_object_info_struct *next;
    struct __mmi_jmms_uc_xml_object_info_struct *prev;
} mmi_jmms_uc_xml_object_info_struct;

typedef struct
{
    S32 parsing_state;
    S32 current_object_count;
    S32 current_slide_count;
    S32 parsing_mode;
    S32 parsing_error_code; /* JC_RETCODE */
    mmi_jmms_uc_xml_object_info_struct *objects;
    mmi_jmms_uc_xml_object_info_struct *current_object;
    mmi_jmms_uc_xml_decoder_result_hdlr result_hdlr;
    XML_PARSER_STRUCT *xml_parser;
} jmms_uc_xml_parser_context_struct;

typedef struct
{
    U8 xml_tag[JMMS_UC_XML_TAG_SIZE];
    mmi_jmms_uc_xml_tag_handler_hdlr tag_handler;
} mmi_jmms_uc_tags_map_struct;

extern U32 mmi_jmms_uc_convert_ascii_hex_to_dec(U8 *character);
extern JC_RETCODE mmi_jmms_uc_create_msg(U16 *file_path);
extern void mmi_jmms_uc_xml_start_element_hdlr(void *data, const char *el, const char **attr, int error);
extern void mmi_jmms_uc_xml_end_element_hdlr(void *data, const char *el, int error);
extern void mmi_jmms_uc_xml_data_hdlr(void *data, const char *el, const char *value, int len, int error);
extern JC_RETCODE mmi_jmms_uc_init_new_mms(void);

extern void mmi_jmms_uc_xml_to_element_start_handler(const char **attr);
extern void mmi_jmms_uc_xml_cc_element_start_handler(const char **attr);
extern void mmi_jmms_uc_xml_bcc_element_start_handler(const char **attr);
extern void mmi_jmms_uc_xml_from_element_start_handler(const char **attr);
extern void mmi_jmms_uc_xml_address_element_data_handler(const char *value, int len);
extern void mmi_jmms_uc_xml_from_element_data_handler(const char *value, int len);

extern void mmi_jmms_uc_xml_subject_element_start_handler(const char **attr);
extern void mmi_jmms_uc_xml_subject_element_data_handler(const char *value, int len);

extern void mmi_jmms_uc_xml_rr_element_start_handler(const char **attr);
extern void mmi_jmms_uc_xml_rr_element_data_handler(const char *value, int len);

extern void mmi_jmms_uc_xml_dr_element_start_handler(const char **attr);
extern void mmi_jmms_uc_xml_dr_element_data_handler(const char *value, int len);

extern void mmi_jmms_uc_xml_prio_element_start_handler(const char **attr);
extern void mmi_jmms_uc_xml_prio_element_data_handler(const char *value, int len);

extern void mmi_jmms_uc_xml_expiry_element_start_handler(const char **attr);
extern void mmi_jmms_uc_xml_expiry_element_data_handler(const char *value, int len);

extern void mmi_jmms_uc_xml_delivery_element_start_handler(const char **attr);
extern void mmi_jmms_uc_xml_delivery_element_data_handler(const char *value, int len);

extern void mmi_jmms_uc_xml_visible_element_start_handler(const char **attr);
extern void mmi_jmms_uc_xml_visible_element_data_handler(const char *value, int len);

extern void mmi_jmms_uc_xml_header_element_end_handler(void);

extern void mmi_jmms_uc_xml_body_element_start_handler(const char **attr);
extern void mmi_jmms_uc_xml_slide_element_start_handler(const char **attr);

extern void mmi_jmms_uc_xml_free_object_list(void);
extern void mmi_jmms_uc_xml_insert_object_in_object_list(mmi_jmms_uc_xml_object_info_struct *insert_object);
extern void mmi_jmms_uc_xml_remove_object_in_object_list(mmi_jmms_uc_xml_object_info_struct *remove_object);
extern mmi_jmms_uc_xml_object_info_struct *mmi_jmms_uc_xml_find_object_in_object_list(U32 id);
extern mmi_jmms_uc_xml_object_info_struct *mmi_jmms_uc_xml_allocate_object_for_object_list(void);
extern void mmi_jmms_uc_xml_text_element_start_handler(const char **attr);
extern void mmi_jmms_uc_xml_image_element_start_handler(const char **attr);
extern void mmi_jmms_uc_xml_audio_element_start_handler(const char **attr);
extern void mmi_jmms_uc_xml_video_element_start_handler(const char **attr);
extern void mmi_jmms_uc_xml_object_element_start_handler(const char **attr);
extern void mmi_jmms_uc_xml_object_element_end_handler(void);

extern void mmi_jmms_uc_xml_name_element_data_handler(const char *value, int len);
extern void mmi_jmms_uc_xml_filepath_element_data_handler(const char *value, int len);
extern void mmi_jmms_uc_xml_mms_element_end_handler(void);
extern void mmi_jmms_uc_xml_add_text(void);
extern void mmi_jmms_uc_xml_add_audio(void);
extern void mmi_jmms_uc_xml_add_video(void);
extern void mmi_jmms_uc_xml_add_image(void);
extern void mmi_jmms_uc_xml_add_attachment(void);
extern void mmi_jmms_uc_xml_parsing_error(JC_RETCODE ret_code);

#endif /* __MMI_UC_JMMS_XML_PROT_H */ 


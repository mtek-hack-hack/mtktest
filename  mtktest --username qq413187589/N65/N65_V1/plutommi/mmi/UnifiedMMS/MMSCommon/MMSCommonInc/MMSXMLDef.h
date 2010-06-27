/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  MMSXMLDef.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 * XML Related Defines
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
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MMI_MMSXMLDEF_H__
#define __MMI_MMSXMLDEF_H__
#ifdef __MMI_MMS_2__
//#include "FileSystemDef.h"
#include "fmt_struct.h"
#include "FileMgr.h"
#include "FileManagerGprot.h"
#include "mmsadp.h"
#include "xml_def.h"
#include "app_usedetails.h"

#define MMI_UMMS_TXT_BUF_UCS2_SIZE (40960)
#define MMI_UMMS_MAX_UTF8_TXT_SLIDE_LEN (20480)

#define MMI_UMMS_XML_MAX_ADDR_LEN (312)
#define MMI_UMMS_XML_MAX_SUBJECT_LEN (40)

#define MMI_UMMS_XML_TEMP_STR_LEN (1024)
#define MMI_UMMS_XML_INVALID_VALUE (0xFF)
#define MMI_UMMS_VERSION_LEN (8)
#define MMI_UMMS_MAX_ALT_STR_LEN (20)


#define MMI_UMMS_PARSE_ADDRESSES_BY_TYPE    0x00000001
#define MMI_UMMS_MSG_PARSER_IGNORE_SLIDES   0x00000002


typedef enum
{
    MMI_UMMS_ADDRESS_GROUP_TYPE_TO,
    MMI_UMMS_ADDRESS_GROUP_TYPE_CC,
    MMI_UMMS_ADDRESS_GROUP_TYPE_BCC,
    MMI_UMMS_ADDRESS_GROUP_TYPE_FROM,
    MMI_UMMS_ADDRESS_GROUP_TYPE_TOTAL_NUM
} mmi_umms_address_group_type_enum;

typedef enum
{
    MMI_UMMS_OBJECT_TYPE_IMAGE,
    MMI_UMMS_OBJECT_TYPE_AUDIO,
    MMI_UMMS_OBJECT_TYPE_VIDEO,
    MMI_UMMS_OBJECT_TYPE_TEXT,
    MMI_UMMS_OBJECT_TYPE_ATTACHMENT,
    MMI_UMMS_OBJECT_TYPE_UNKNOWN,
    MMI_UMMS_DONE_TYPE_TOTAL_NUM
} mmi_umms_object_type;

typedef enum
{
    MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER,
    MMI_UMMS_ADDRESS_TYPE_EMAIL,
    MMI_UMMS_ADDRESS_TYPE_TOTAL_NUM
} mmi_umms_address_type_enum;

/* 
 * Extern Global Variable
 */
typedef struct mmi_umms_object_struct_t
{
    struct mmi_umms_object_struct_t* next;
    struct mmi_umms_object_struct_t* previous;

    U32 offset;
    U32 size; /* file size for non-text object. UTF8 size for text object */
    /* S32 original_fh; */
    U32 id;
    U8 *mime_type;
    U8 *content_id;
    U8 *content_location;
    U16* file_path; /* NULL terminator is needed. */
    U16* file_name;
    /*U16* virtual_file_name;*/
    U16 reference_count;
    U16 encoding_scheme;
    mmi_umms_object_type type;
    U8 drm_type; /* mma_drm_type_enum */    
    BOOL is_virtual_file;
} mmi_umms_object_struct;

typedef struct mmi_umms_attachment_info_struct_t
{
    struct mmi_umms_attachment_info_struct_t* next;
    struct mmi_umms_attachment_info_struct_t* previous;

    mmi_umms_object_struct* object;
} mmi_umms_attachment_info_struct;

typedef struct
{
    mmi_umms_object_struct* object;
    U32 id;
    U16* alt_str;
    U8 begin;
    U8 end;    
} mmi_umms_object_info_struct;

typedef struct
{
    mmi_umms_object_struct* object;
    U32 id;		/*fill zero*/
    U32 background_color;
    U32 foreground_color;
    U16* alt_str;
    U16 char_count;     /*Total Character Count*/
    U16 utf8_msg_len;       /*Msg Len in UTF8*/
    U16 extension_char_count;       /*EXT CHAR Count*/
    U16 UCS2_count;    /*UCS2 Count except any extension char*/
    U16 str_id;
    U8 begin;
    U8 end;
	U8	txtStyle;		/* mma_text_style_enum */
	U8	txtSize;		/* mma_text_size_enum */
} mmi_umms_text_object_info_struct;

typedef struct mmi_umms_slide_struct_t
{
    struct mmi_umms_slide_struct_t* next;
    struct mmi_umms_slide_struct_t* previous;

    mmi_umms_text_object_info_struct text;
    mmi_umms_object_info_struct image;
    mmi_umms_object_info_struct audio;
    mmi_umms_object_info_struct video;
    U8 duration;
    U8 slide_num;
} mmi_umms_slide_struct;

typedef struct mmi_umms_addr_struct_t
{    
    struct mmi_umms_addr_struct_t* next;
    struct mmi_umms_addr_struct_t* previous;
    
    kal_uint8* addr; /* ascii for phone number while ucs2 for email address. NULL terminator is needed */
    mmi_umms_address_type_enum type;
    mmi_umms_address_group_type_enum group;    
} mmi_umms_addr_struct;

typedef struct
{
    mmi_umms_addr_struct* to_head;
    mmi_umms_addr_struct* cc_head;
    mmi_umms_addr_struct* bcc_head;
    mmi_umms_addr_struct* from;
    mmi_umms_slide_struct* slide_head;
    mmi_umms_slide_struct* current_slide;
    mmi_umms_object_struct* object_head;
    mmi_umms_attachment_info_struct* attachment_head;
    U32 background_color;
    U32 foreground_color;
    U32	date;  
	U32 msgsize;
    U32 download_size;
    U32 reported_msg_id;
    U8 java_app_id[100 *ENCODING_LENGTH];
    U8 java_reply_app_id[100 *ENCODING_LENGTH];

    U16 subject[MMI_UMMS_XML_MAX_SUBJECT_LEN + 1];
    U16 reported_subject[MMI_UMMS_XML_MAX_SUBJECT_LEN + 1];
    U16 slide_timing;
    
    U8 mms_version[MMI_UMMS_VERSION_LEN];
    U8 to_num;
    U8 cc_num;
    U8 bcc_num;
    U8 priority; /* mma_priority_enum */
    U8 expiry_time; /* mma_expiry_time_enum */
    U8 msgStatus; /*mma_msg_status_enum */
	U8 msgclass; /* mma_msg_class_enum */
    U8 total_slide_num;
    U8 current_slide_num;
    U8 total_object_num;
    U8 total_attachment_num;
    U8 total_addresses;
    U8 email_num;
    U8 ph_num;
    U8 delivery_time; /* mma_delivery_time_enum */
    U8 status;
    BOOL sender_visibility;
    BOOL read_report;
    BOOL delivery_report;
    mma_slide_layout_enum layout;
} mmi_umms_xml_msg_struct;

typedef void * (* mmi_umms_alloc_mem )(U32 size);
typedef void (* mmi_umms_free_mem )(void * pmem);

typedef struct 
{
    mmi_umms_alloc_mem mem_alloc_fn;
    mmi_umms_free_mem mem_free_fn;
    mmi_umms_xml_msg_struct *msg;
    mmi_umms_slide_struct *slide;
    mmi_umms_object_struct *object;
    U32 flags;
    mmi_umms_address_type_enum addr_type;
} mmi_umms_msg_parser_cntx;

/* External Interfaces */
extern XML_RESULT_ENUM mmi_umms_parse_mms_xml_description_file(
                        PU16 file_path,
                        mmi_umms_alloc_mem alloc_mem_fn,
                        mmi_umms_free_mem free_mem_fn,
                        mmi_umms_xml_msg_struct *msg_cntx,
                        U32 flags);
extern S32 mmi_umms_create_mms_xml_description_file(mmi_umms_xml_msg_struct *umms_msg,U8* file_path);
#endif /* __MMI_MMS_2__ */
#endif /* __MMI_MMSXMLDEF_H__ */

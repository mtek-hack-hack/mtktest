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
#ifndef _mma_utils_xml_h
#define _mma_utils_xml_h

/**********************************************************************
 * Macro definition
 **********************************************************************/
#define MMA_XML_ELEMENT_MMS "mms"
#define MMA_XML_ELEMENT_HEADER "header"
#define MMA_XML_ELEMENT_TO "to"
#define MMA_XML_ELEMENT_CC "cc"
#define MMA_XML_ELEMENT_BCC "bcc"
#define MMA_XML_ELEMENT_FROM "from"
#define MMA_XML_ATTR_TYPE "type"
#define MMA_XML_ATTR_POHNE_NUMBER "P"
#define MMA_XML_ATTR_EMAIL_ADDR "E"
#define MMA_XML_ELEMENT_SUBJECT "subject"
#define MMA_XML_ELEMENT_READ_REPORT "rr"
#define MMA_XML_ELEMENT_DELIVERY_REPORT "dr"
#define MMA_XML_ELEMENT_PRIORITY "prio"
#define MMA_XML_ELEMENT_EXPIRY "expiry"
#define MMA_XML_ELEMENT_DELIVERY_TIME "delivery"
#define MMA_XML_ELEMENT_VISIBLE "visible"
#define MMA_XML_ELEMENT_BODY "body"
#define MMA_XML_ATTR_BGCOLOR "bgColor"
#define MMA_XML_ATTR_FGCOLOR "fgColor"
#define MMA_XML_ATTR_SLIDE_NUM "slideNum"
#define MMA_XML_ATTR_OBJ_NUM "objNum"
#define MMA_XML_ATTR_LAYOUT "layout"
#define MMA_XML_ELEMENT_SLIDE "slide"
#define MMA_XML_ATTR_INDEX "index"
#define MMA_XML_ATTR_DURATION "dur"
#define MMA_XML_ATTR_ID "id"
#define MMA_XML_ATTR_BEGIN "begin"
#define MMA_XML_ATTR_END "end"
#define MMA_XML_ELEMENT_TEXT "text"
#define MMA_XML_ELEMENT_IMAGE "img"
#define MMA_XML_ELEMENT_AUDIO "audio"
#define MMA_XML_ELEMENT_VIDEO "video"
#define MMA_XML_ATTR_ATTACH "attach"
#define MMA_XML_ATTR_VIRTUAL_FILE "vf"
#define MMA_XML_ATTR_DRM "drm"
#define MMA_XML_ATTR_SIZE "size"
#define MMA_XML_ATTR_OFFSET "offset"
#define MMA_XML_ELEMENT_OBJECT "obj"
#define MMA_XML_ELEMENT_NAME "name"
#define MMA_XML_ELEMENT_FILE_PATH "filepath"

/**********************************************************************
 * Constant definition
 **********************************************************************/
typedef enum
{
    MMA_ADDRESS_GROUP_TYPE_TO,
    MMA_ADDRESS_GROUP_TYPE_CC,
    MMA_ADDRESS_GROUP_TYPE_BCC,
    MMA_ADDRESS_GROUP_TYPE_FROM,
    MMA_ADDRESS_GROUP_TYPE_TOTAL_NUM
} mma_address_group_type_enum;

typedef enum
{
    MMA_MEDIA_TYPE_IMAGE,
    MMA_MEDIA_TYPE_VIDEO,
    MMA_MEDIA_TYPE_AUDIO,
    MMA_MEDIA_TYPE_TEXT
} mma_media_type_enum;

typedef enum
{
    MMA_MMS_BODY_XML_ATTR_BG_COLOR,
    MMA_MMS_BODY_XML_ATTR_FG_COLOR,
    MMA_MMS_BODY_XML_ATTR_SLIDE_NO,
    MMA_MMS_BODY_XML_ATTR_OBJ_NO,
    MMA_MMS_BODY_XML_ATTR_LAYOUT,
    MMA_MMS_BODY_XML_ATTR_TOTAL_NO
} mma_mms_body_xml_attr_type_enum;

typedef enum
{
    MMA_MMS_SLIDE_XML_ATTR_INDEX,
    MMA_MMS_SLIDE_XML_ATTR_DURATION,
    MMA_MMS_SLIDE_XML_ATTR_TOTAL_NO
} mma_mms_slide_xml_attr_type_enum;

typedef enum
{
    MMA_MMS_SLIDE_OBJ_XML_ATTR_ID,
    MMA_MMS_SLIDE_OBJ_XML_ATTR_BGCOLOR,
    MMA_MMS_SLIDE_OBJ_XML_ATTR_FGCOLOR,
    MMA_MMS_SLIDE_OBJ_XML_ATTR_BEGIN,
    MMA_MMS_SLIDE_OBJ_XML_ATTR_END,
    MMA_MMS_SLIDE_OBJ_XML_ATTR_TOTAL_NO
} mma_mms_slide_obj_xml_attr_type_enum;

typedef enum
{
    MMA_MMS_OBJECT_XML_ATTR_ID,
    MMA_MMS_OBJECT_XML_ATTR_ATTACH,
    MMA_MMS_OBJECT_XML_ATTR_VF,
    MMA_MMS_OBJECT_XML_ATTR_DRM,
    MMA_MMS_OBJECT_XML_ATTR_SIZE,
    MMA_MMS_OBJECT_XML_ATTR_OFFSET,
    MMA_MMS_OBJECT_XML_ATTR_TOTAL_NO
} mma_mms_object_xml_attr_type_enum;

/**********************************************************************
 * Structure definition
 **********************************************************************/
typedef struct
{
    /* intermediate info during parsing */
    MmsAddressType addr_type;
    mma_slide_struct *slide;  /* current slide */
    mma_object_struct *object;  /* current object */

    /* parsed info */
    mma_create_mms_info_struct *info;
}mma_xml_parser_info_struct;

/**********************************************************************
 * Function declarations
 **********************************************************************/
long mma_xml_create_mms_description_file(mma_get_content_info_struct *info);
mma_result_enum mma_xml_parse_mms_xml_description_file(mma_create_mms_info_struct *info);

#endif /* _mma_utils_xml_h */

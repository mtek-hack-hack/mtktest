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
#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */
#include "wap_ps_struct.h"

/* MSF */
#include "msf_cfg.h"
#include "msf_file.h"
#include "msf_mem.h"
#include "msf_dcvt.h"
#include "msf_cmmn.h"

/* MMS */
#include "mms_cfg.h"
#include "mms_def.h"
#include "mms_if.h"
#include "mmsl_if.h"
#include "mltypes.h"
#include "msig.h"
#include "fldmgr.h"
    
/* SLS */
#include "sls_cfg.h"
#include "sls_def.h"
#include "sls_if.h"

/* MEA */
#include "meal_if.h"

/* SMA */
#include "sma_def.h"
    
/* MMA */
#include "mmsadp.h"
#include "mma_cfg.h"
#include "mma_def.h"
#include "mma_conf.h"
#include "mma_utils.h"
#include "mma_utils_xml.h"

/* Misc */
#include "wapadp.h"
#include "widget.h"
#include "widget_extension.h"
#include "fs_type.h"
#include "xml_def.h"

#define MMA_XML_TEMP_STR_LEN (1024)
#define MMA_XML_TEMP_SHORT_STR_LEN (5)
#define MMA_XML_TEMP_NORMAL_STR_LEN (10)
#define MMA_XML_TEMP_COLOR_STR_LEN (10)

/* Local variables */
static mma_xml_parser_info_struct *prs_info = NULL;

/*****************************************************************************
 * FUNCTION
 *  mma_xml_assign_id
 * DESCRIPTION
 *  Fill in object/slide XML id for body part. Only objects listed in XML are assigned ID.
 * PARAMETERS
 *  mode
 *  header
 *  body
 * RETURNS
 *  void
 *****************************************************************************/
void mma_xml_assign_id(mma_app_mode_enum mode, MmsGetHeader *header, mma_body_struct *body)
{
    kal_uint32 id = 1;  /* XML index ID starts from 1*/
    mma_object_struct *obj = NULL;
    mma_slide_struct *slide =NULL;
    mma_unref_list_struct *unref_list = NULL;
    kal_uint32 unref_count = 0;

    ASSERT(header != NULL && body != NULL);

    obj = body->objects;
    slide = body->slides;
    unref_list = body->unref_list;

    /* assign slide ID */
    while (slide)
    {
        slide->xmlId = id++;
        slide = slide->next;
    }

    /* assign object ID */
    id = 1;
    if(mode == MMA_MODE_REPLY || mode == MMA_MODE_REPLY_ALL)
    {
        return;
    }
    else if(mode == MMA_MODE_EDIT)
    {
        while(obj)
        {
            if(obj->isAttachment == KAL_FALSE)
            {
                obj->xmlId = id++;
            }
            else if(obj->isAttachment == KAL_TRUE)
            {
                obj->xmlId = (unref_count < wap_custom_get_max_mms_attachment()) ? id++ : 0;
                unref_count++;
            }
            obj = obj->next;
        }
    }
    else if(mode == MMA_MODE_SEND || mode == MMA_MODE_FORWARD) /* send & forward */
    {
        while(unref_list)
        {
            unref_list->attachment->xmlId = 0;
            if(unref_count < wap_custom_get_max_mms_attachment())
            {
                unref_list->attachment->xmlId = id++;
            }
            unref_list = unref_list->next;
            unref_count++;
        }
    }
}

#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mma_xml_translate_drm_type
 * DESCRIPTION
 *  Fill in object XML drm type. Only objects listed in XML are translated.
 * PARAMETERS
 *  id
 *  body
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_xml_translate_drm_type(mma_app_mode_enum mode, MmsMsgId msg_id, mma_body_struct *body)
{
    ASSERT(msg_id != 0 && body != NULL);
    if(mode == MMA_MODE_REPLY || mode == MMA_MODE_REPLY_ALL)
    {
        return;
    }
    else if(mode == MMA_MODE_EDIT)
    {
        mma_object_struct *obj = body->objects;
        char *mms_path = MMSlib_getMessageFullPath(MSF_MODID_MMA, msg_id, fldrGetFileSuffix(msg_id));

        while (obj)
        {
            obj->xmlDrmType = mma_drm_check_right_vf(obj->type, mms_path, obj->offset, obj->size);
            obj = obj->next;
        }
        MMA_FREE(mms_path);
    }
    else if(mode == MMA_MODE_SEND || mode == MMA_MODE_FORWARD) /* send & forward */
    {
        mma_object_struct *obj = body->objects;
        char *mms_path = MMSlib_getMessageFullPath(MSF_MODID_MMA, msg_id, fldrGetFileSuffix(msg_id));

        while(obj)
        {
            if(obj->isAttachment)
            {
                obj->xmlDrmType = mma_drm_check_right_vf(obj->type, mms_path, obj->offset, obj->size);
            }
            obj = obj->next;
        }
        MMA_FREE(mms_path);
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mma_xml_get_object_by_id
 * DESCRIPTION
 *  Get the 1st object of the specified ID
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mma_object_struct *mma_xml_get_object_by_id(mma_body_struct *body, kal_uint32 id)
{
    mma_object_struct *obj = NULL;

    if(body == NULL || body->objects == NULL)
    {
        return NULL;
    }

    obj = body->objects;

    while(obj)
    {
        if(obj->xmlId == id)
        {
            return obj;
        }
        
        obj = obj->next;
    }

    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mma_xml_get_obj_count
 * DESCRIPTION
 *  Get the number of objects which would be listed in xml
 * PARAMETERS
 *  body    [IN]
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
kal_uint32 mma_xml_get_obj_count(mma_body_struct *body)
{
    kal_uint32 count =0;
    mma_object_struct *obj = NULL;
    
    ASSERT(body != NULL);
    obj = body->objects;
    while(obj)
    {
       if(obj->xmlId > 0)
       {
           count++;
       }

       obj = obj->next;
    }
    return count;
}

/*****************************************************************************
 * FUNCTION
 *  mma_xml_create_element_start
 * DESCRIPTION
 *  Create the xml start element
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
long mma_xml_create_element_start(int fh, const char *element_name, const char **attr_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *str = NULL;
    kal_uint32 i = 0, offset = 0;
    long result = HDI_FILE_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMA_CALLOC(str, MMA_XML_TEMP_STR_LEN);
    offset += sprintf(str, "%s%s", XML_TAG_ELEMENT_START, element_name);

    if (attr_list)
    {
        while (attr_list[i])
        {
            offset += sprintf(str + offset, " %s=\"%s\"", attr_list[i], attr_list[i + 1]);
            i = i + 2;
        }
    }

    offset += sprintf(str + offset, "%s", XML_TAG_GENERAL_END);
    ASSERT(offset < MMA_XML_TEMP_STR_LEN);
    result = MSF_FILE_WRITE(fh, str, offset);
    MMA_FREE(str);

    return ((result == offset) ? HDI_FILE_OK : result);
}

/*****************************************************************************
 * FUNCTION
 *  mma_xml_create_element_end
 * DESCRIPTION
 *  Create the xml end element
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
long mma_xml_create_element_end(int fh, const char *element_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *str = NULL;
    kal_uint32 offset = 0;
    long result = HDI_FILE_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMA_CALLOC(str, MMA_XML_TEMP_STR_LEN);
    offset += sprintf(str, "%s%s%s", XML_TAG_ELEMENT_END, element_name, XML_TAG_GENERAL_END);

    ASSERT(offset < MMA_XML_TEMP_STR_LEN);
    result = MSF_FILE_WRITE(fh, str, offset);
    MMA_FREE(str);

    return ((result == offset) ? HDI_FILE_OK : result);
}

/*****************************************************************************
 * FUNCTION
 *  mma_xml_create_xml_new_line
 * DESCRIPTION
 *  Insert new line
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
long mma_xml_create_new_line(int fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char str[10];
    kal_uint32 offset = 0;
    long result = HDI_FILE_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(str,0,10);
    offset += sprintf(str, "\n");
    ASSERT(offset < 10);
    result = MSF_FILE_WRITE(fh, str, offset);

    return ((result == offset) ? HDI_FILE_OK : result);
}

/*****************************************************************************
 * FUNCTION
 *  mma_xml_create_data
 * DESCRIPTION
 *  Add data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
long mma_xml_create_data(int fh, char *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long result = HDI_FILE_OK;
    kal_uint32 offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    offset = strlen(str);
    result = MSF_FILE_WRITE(fh, str, offset);

    return ((result == offset) ? HDI_FILE_OK : result);
}

/*****************************************************************************
 * FUNCTION
 *  mma_xml_create_addr
 * DESCRIPTION
 *  Add data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
long mma_xml_create_addr(int fh, mma_address_group_type_enum type, MmsAddress *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long result;
    const char *xml_addr_type = NULL;
    const char *attr_list[3];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MMA_ADDRESS_GROUP_TYPE_TO:
        {
            xml_addr_type = MMA_XML_ELEMENT_TO;
        }
        break;
            
        case MMA_ADDRESS_GROUP_TYPE_CC:
        {
            xml_addr_type = MMA_XML_ELEMENT_CC;
        }
        break;

        case MMA_ADDRESS_GROUP_TYPE_BCC:
        {
            xml_addr_type = MMA_XML_ELEMENT_BCC;
        }
        break;

        case MMA_ADDRESS_GROUP_TYPE_FROM:
        {
            xml_addr_type = MMA_XML_ELEMENT_FROM;
        }
        break;

        default:
        {
            ASSERT(0);
        }
        break;
    }

    attr_list[0] = MMA_XML_ATTR_TYPE;
    attr_list[2] = NULL;

    if (addr->addrType == MMS_PLMN)
    {
        attr_list[1] = MMA_XML_ATTR_POHNE_NUMBER;
    }
    else if (addr->addrType == MMS_EMAIL)
    {        
        attr_list[1] = MMA_XML_ATTR_EMAIL_ADDR;
    }
    else
    {
        goto ignore;
    }

    if ((result = mma_xml_create_element_start(fh, xml_addr_type, attr_list)) != HDI_FILE_OK)
    {
        return result;
    }
    else if ((result = mma_xml_create_data(fh, addr->address)) != HDI_FILE_OK)
    {
        return result;
    }                    
    else if ((result = mma_xml_create_element_end(fh, xml_addr_type)) != HDI_FILE_OK)
    {
        return result;
    }
    else if ((result = mma_xml_create_new_line(fh)) != HDI_FILE_OK)
    {
        return result;
    }

ignore:
    return HDI_FILE_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mma_xml_create_data_numeric_to_char
 * DESCRIPTION
 *  Add numeric data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
long mma_xml_create_data_numeric_to_char(int fh, kal_uint32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char str[10];
    kal_uint32 offset = 0;
    long result = HDI_FILE_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    memset(str, 0, 10);
    offset += sprintf(str, "%d", value);
    result = mma_xml_create_data(fh, str);

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mma_xml_create_element_single
 * DESCRIPTION
 *  Create the xml single element
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
long mma_xml_create_element_single(int fh, const char *element_name, const char **attr_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *str = NULL;
    kal_uint32 i = 0, offset = 0;
    long result = HDI_FILE_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMA_CALLOC(str, MMA_XML_TEMP_STR_LEN);
    offset += sprintf(str, "%s%s", XML_TAG_ELEMENT_START, element_name);

    if (attr_list)
    {
        while (attr_list[i])
        {
            offset += sprintf(str + offset, " %s=\"%s\"", attr_list[i], attr_list[i + 1]);
            i = i + 2;
        }
    }

    offset += sprintf(str + offset, "%s", XML_TAG_SINGLE_END);
    ASSERT(offset < MMA_XML_TEMP_STR_LEN);
    result = MSF_FILE_WRITE(fh, str, offset);
    MMA_FREE(str);

    return ((result == offset) ? HDI_FILE_OK : result);
}

/*****************************************************************************
 * FUNCTION
 *  mma_xml_create_slide_object
 * DESCRIPTION
 *  Add data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
long mma_xml_create_slide_object(int fh, mma_slide_struct *slide, mma_media_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long result;
//    U32 bg_color = 0;
    U32 fg_color = 0;
    U32 id = 0;
//    U8 begin;
//    U8 end;
//    U8 bg_color_str[MMA_XML_TEMP_COLOR_STR_LEN];
    U8 fg_color_str[MMA_XML_TEMP_COLOR_STR_LEN];
    U8 id_str[MMA_XML_TEMP_SHORT_STR_LEN];
//    U8 start_str[MMA_XML_TEMP_SHORT_STR_LEN];
//    U8 end_str[MMA_XML_TEMP_SHORT_STR_LEN];
    const char *attr_list[MMA_MMS_SLIDE_OBJ_XML_ATTR_TOTAL_NO * 2 + 1];
    const char *obj_type = NULL;
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(slide);
    
    switch (type)
    {
        case MMA_MEDIA_TYPE_TEXT:
        {
            ASSERT(slide->text.obj);
            fg_color = slide->text.text_color;
//            bg_color = ;
            id = slide->text.obj->xmlId;
//            begin = ;
//            end = ;
            obj_type = MMA_XML_ELEMENT_TEXT;
        }
        break;

        case MMA_MEDIA_TYPE_IMAGE:
        {
            ASSERT(slide->image.obj);
            id = slide->image.obj->xmlId;
//            begin = ;
//            end = ;
            obj_type = MMA_XML_ELEMENT_IMAGE;
        }
        break;
        
        case MMA_MEDIA_TYPE_AUDIO:
        {
            ASSERT(slide->audio.obj);
            id = slide->audio.obj->xmlId;
//            begin = ;
//            end = ;
            obj_type = MMA_XML_ELEMENT_AUDIO;
        }
        break;
        
        case MMA_MEDIA_TYPE_VIDEO:
        {
            ASSERT(slide->video.obj);
            id = slide->video.obj->xmlId;
//            begin ;
//            end ;
            obj_type = MMA_XML_ELEMENT_VIDEO;
        }
        break;        

        default:
        {
            ASSERT(0);
        }
        break;
    }


    if (type == MMA_MEDIA_TYPE_TEXT)
    {
/*
        memset(bg_color_str, 0, color_str_len);
        sprintf(bg_color_str, "0x%06x", bg_color);
        attr_list[i++] = MMA_XML_ATTR_BGCOLOR;
        attr_list[i++] = bg_color_str;
*/
        memset(fg_color_str, 0, MMA_XML_TEMP_COLOR_STR_LEN);
        sprintf((char *)fg_color_str, "0x%x", fg_color);
        attr_list[i++] = MMA_XML_ATTR_FGCOLOR;
        attr_list[i++] = (const char *)fg_color_str;
    }

    memset(id_str, 0, MMA_XML_TEMP_SHORT_STR_LEN);
    sprintf((char *)id_str, "%d", id);
    attr_list[i++] = MMA_XML_ATTR_ID;
    attr_list[i++] = (const char *)id_str;

/*
    memset(start_str, 0, str_len);
    sprintf(start_str, "%d", slide->text.begin);
    attr_list[i++] = MMA_XML_ATTR_BEGIN;
    attr_list[i++] = start_str;            

    memset(end_str, 0, str_len);
    sprintf(end_str, "%d", slide->text.end);
    attr_list[i++] = MMA_XML_ATTR_END;
    attr_list[i++] = end_str;
*/    
    attr_list[i] = NULL;

    ASSERT(i <= (MMA_MMS_SLIDE_OBJ_XML_ATTR_TOTAL_NO * 2 + 1));

    if ((result = mma_xml_create_element_single(fh, obj_type, attr_list)) != HDI_FILE_OK)
    {
        return result;
    }
    if ((result = mma_xml_create_new_line(fh)) != HDI_FILE_OK)
    {
        return result;
    }

    return HDI_FILE_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mma_xml_create_slide
 * DESCRIPTION
 *  Add data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
long mma_xml_create_slide(int fh, mma_slide_struct *slide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long result;    
    U8 index_str[MMA_XML_TEMP_SHORT_STR_LEN];
    U8 duration_str[MMA_XML_TEMP_SHORT_STR_LEN];
    const char* attr_list[MMA_MMS_SLIDE_XML_ATTR_TOTAL_NO * 2 + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(slide);

    memset(index_str, 0, MMA_XML_TEMP_SHORT_STR_LEN);
    sprintf((char *)index_str, "%d", slide->xmlId);
    attr_list[MMA_MMS_SLIDE_XML_ATTR_INDEX * 2] = MMA_XML_ATTR_INDEX;
    attr_list[MMA_MMS_SLIDE_XML_ATTR_INDEX * 2 + 1] = (const char *) index_str;

    memset(duration_str, 0, MMA_XML_TEMP_SHORT_STR_LEN);
    sprintf((char *)duration_str, "%d", slide->duration);
    attr_list[MMA_MMS_SLIDE_XML_ATTR_DURATION * 2] = MMA_XML_ATTR_DURATION;
    attr_list[MMA_MMS_SLIDE_XML_ATTR_DURATION * 2 + 1] = (const char *) duration_str;

    attr_list[MMA_MMS_SLIDE_XML_ATTR_TOTAL_NO * 2] = NULL;

    if ((result = mma_xml_create_element_start(fh, MMA_XML_ELEMENT_SLIDE, attr_list)) != HDI_FILE_OK)
    {
        return result;
    }
    if ((result = mma_xml_create_new_line(fh)) != HDI_FILE_OK)
    {
        return result;
    }
    
    /* text */
    if (slide->text.obj)
    {
        if ((result = mma_xml_create_slide_object(fh, slide, MMA_MEDIA_TYPE_TEXT)) != HDI_FILE_OK)
        {
            return result;
        }
    }
    /* image */
    if (slide->image.obj)
    {
        if ((result = mma_xml_create_slide_object(fh, slide, MMA_MEDIA_TYPE_IMAGE)) != HDI_FILE_OK)
        {
            return result;
        }
    }
    /* audio */
    if (slide->audio.obj)
    {
        if ((result = mma_xml_create_slide_object(fh, slide, MMA_MEDIA_TYPE_AUDIO)) != HDI_FILE_OK)
        {
            return result;
        }
    }
    /* video */
    if (slide->video.obj)
    {
        if ((result = mma_xml_create_slide_object(fh, slide, MMA_MEDIA_TYPE_VIDEO)) != HDI_FILE_OK)
        {
            return result;
        }
    }

    if ((result = mma_xml_create_element_end(fh, MMA_XML_ELEMENT_SLIDE)) != HDI_FILE_OK)
    {
        return result;
    }
    if ((result = mma_xml_create_new_line(fh)) != HDI_FILE_OK)
    {
        return result;
    }
    if ((result = mma_xml_create_new_line(fh)) != HDI_FILE_OK)
    {
        return result;
    }

    return HDI_FILE_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mma_xml_create_xml_object
 * DESCRIPTION
 *  Add data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
long mma_xml_create_object(int fh, kal_uint32 msg_id, mma_object_struct* obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long result;    
    U8 id_str[MMA_XML_TEMP_SHORT_STR_LEN];
    U8 attach_str[MMA_XML_TEMP_SHORT_STR_LEN];
    U8 vf_str[MMA_XML_TEMP_SHORT_STR_LEN];
    U8 drm_str[MMA_XML_TEMP_SHORT_STR_LEN];
    U8 size_str[MMA_XML_TEMP_NORMAL_STR_LEN];
    U8 offset_str[MMA_XML_TEMP_NORMAL_STR_LEN];
    const char *attr_list[MMA_MMS_OBJECT_XML_ATTR_TOTAL_NO * 2 + 1];
    U8 j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(obj && msg_id != 0);

    memset(id_str, 0, MMA_XML_TEMP_SHORT_STR_LEN);
    sprintf((char *)id_str, "%d", obj->xmlId);
    attr_list[j++] = MMA_XML_ATTR_ID;
    attr_list[j++] = (const char *)id_str;

    memset(attach_str, 0, MMA_XML_TEMP_SHORT_STR_LEN);
    sprintf((char *)attach_str, "%d", obj->isAttachment);
    attr_list[j++] = MMA_XML_ATTR_ATTACH;
    attr_list[j++] = (const char *)attach_str;

    memset(vf_str, 0, MMA_XML_TEMP_SHORT_STR_LEN);
    sprintf((char *)vf_str, "%d", obj->isVirtualFile);  /* always virtual file when get content */
    attr_list[j++] = MMA_XML_ATTR_VIRTUAL_FILE;
    attr_list[j++] = (const char *)vf_str;

    memset(drm_str, 0, MMA_XML_TEMP_SHORT_STR_LEN);
#ifdef __DRM_SUPPORT__
    sprintf((char *)drm_str, "%d", obj->xmlDrmType);
#else
    sprintf((char *)drm_str, "%d", MMA_DRM_NONE);
#endif
    attr_list[j++] = MMA_XML_ATTR_DRM;
    attr_list[j++] = (const char *)drm_str;

    memset(size_str, 0, MMA_XML_TEMP_NORMAL_STR_LEN);
    sprintf((char *)size_str, "%d", obj->size);
    attr_list[j++] = MMA_XML_ATTR_SIZE;
    attr_list[j++] = (const char *)size_str;

    memset(offset_str, 0, MMA_XML_TEMP_NORMAL_STR_LEN);
    sprintf((char *)offset_str, "%d", obj->offset);
    attr_list[j++] = MMA_XML_ATTR_OFFSET;
    attr_list[j++] = (const char *)offset_str;

    attr_list[j] = NULL;

    ASSERT(j == MMA_MMS_OBJECT_XML_ATTR_TOTAL_NO * 2);

    /* <obj> */
    if ((result = mma_xml_create_element_start(fh, MMA_XML_ELEMENT_OBJECT, attr_list)) != HDI_FILE_OK)
    {
        return result;
    }
    if ((result = mma_xml_create_new_line(fh)) != HDI_FILE_OK)
    {
        return result;
    }
    
    /* name */
    if ((result = mma_xml_create_element_start(fh, MMA_XML_ELEMENT_NAME, 
NULL)) != HDI_FILE_OK)
    {
        return result;
    }
    if ((result = mma_xml_create_data(fh, obj->fileName)) != HDI_FILE_OK)
    {
        return result;
    }                    
    if ((result = mma_xml_create_element_end(fh, MMA_XML_ELEMENT_NAME)) != HDI_FILE_OK)
    {
        return result;
    }
    if ((result = mma_xml_create_new_line(fh)) != HDI_FILE_OK)
    {
        return result;
    }
    
    /* file path */
    {
        kal_uint8 *path_utf8 = NULL, *path_ucs2 = HDI_FileNameTranslate((char *)obj->filePath);
        kal_int32 len = widget_ucs2_to_utf8_length_in_bytes(path_ucs2);
        
        MMA_FREE(path_utf8);
        path_utf8 = MSF_MEM_ALLOC(MSF_MODID_MMA, len + 1);
        widget_ucs2_to_utf8_string(path_utf8, len + 1, path_ucs2);
        HDI_FileNameFree(path_ucs2);

        if ((result = mma_xml_create_element_start(fh, MMA_XML_ELEMENT_FILE_PATH, 
NULL)) != HDI_FILE_OK)
        {
            MMA_FREE(path_utf8);
            return result;
        }
        if ((result = mma_xml_create_data(fh, (char *)path_utf8)) != HDI_FILE_OK)
        {
            MMA_FREE(path_utf8);
            return result;
        }                    
        if ((result = mma_xml_create_element_end(fh, MMA_XML_ELEMENT_FILE_PATH)) != HDI_FILE_OK)
        {
            MMA_FREE(path_utf8);
            return result;
        }
        if ((result = mma_xml_create_new_line(fh)) != HDI_FILE_OK)
        {
            MMA_FREE(path_utf8);
            return result;
        }
        MMA_FREE(path_utf8);
    }   
    /* </obj> */
    if ((result = mma_xml_create_element_end(fh, MMA_XML_ELEMENT_OBJECT)) != HDI_FILE_OK)
    {
        return result;
    }
    if ((result = mma_xml_create_new_line(fh)) != HDI_FILE_OK)
    {
        return result;
    }
    if ((result = mma_xml_create_new_line(fh)) != HDI_FILE_OK)
    {
        return result;
    }

    return HDI_FILE_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mma_xml_create_mms_description_file
 * DESCRIPTION
 *  Create the mms xml description file
 * PARAMETERS
 *  info  [IN/OUT]: info->xml_filepath, info->xml_size would be set if successful
 * RETURNS
 *  void
 *****************************************************************************/
long mma_xml_create_mms_description_file(mma_get_content_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char file_path[MMA_MAX_INTERNAL_FILENAME_LENGTH];
    int fh;
    long result = HDI_FILE_OK;

    MmsGetHeader *header = NULL;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(info != NULL && info->header != NULL && info->header->header.g_header != NULL)
    header = info->header->header.g_header;

    /* prepare data specifically for xml */
    mma_xml_assign_id(info->mode, header, info->body);
#ifdef __DRM_SUPPORT__
    mma_xml_translate_drm_type(info->mode, info->msg_id, info->body);
#endif

    memset(file_path, 0, MMA_MAX_INTERNAL_FILENAME_LENGTH);
    MMA_GET_MMS_XML_FILEPATH(file_path, 0);
    
    /* Open the file to write */
    MSF_FILE_REMOVE(file_path);
    fh = MSF_FILE_OPEN(MSF_MODID_MMA, file_path, 
        MSF_FILE_SET_CREATE | MSF_FILE_SET_WRONLY | HDI_FILE_SET_CUSTOM_BLOCKING,0);
    if (fh > 0)
    {
        /* <mms> */
        if ((result = mma_xml_create_element_start(fh, MMA_XML_ELEMENT_MMS, NULL)) != HDI_FILE_OK)
        {
            MSF_FILE_CLOSE(fh);
            return result;
        }
        if ((result = mma_xml_create_new_line(fh)) != HDI_FILE_OK)
        {
            MSF_FILE_CLOSE(fh);
            return result;
        }

        /* <header> */
        if ((result = mma_xml_create_element_start(fh, MMA_XML_ELEMENT_HEADER, NULL)) != HDI_FILE_OK)
        {
            MSF_FILE_CLOSE(fh);
            return result;
        }
        if ((result = mma_xml_create_new_line(fh)) != HDI_FILE_OK)
        {
            MSF_FILE_CLOSE(fh);
            return result;
        }

        
        /* Address */
        if(header->to != NULL || header->cc != NULL || header->bcc != NULL)
        {
            int i = 0;
            int max = wap_custom_get_max_mms_address();
            MmsAddressList *addr = NULL;

            /* To */
            addr = header->to;
            while(i < max && addr != NULL)
            {
                if ((result = mma_xml_create_addr(fh, MMA_ADDRESS_GROUP_TYPE_TO, &addr->current)) != HDI_FILE_OK)
                {
                    MSF_FILE_CLOSE(fh);
                    return result;
                }
                i++;
                addr = addr->next;
            }
            

            /* Cc */
            addr = header->cc;
            while(i < max && addr != NULL)
            {
                if ((result = mma_xml_create_addr(fh, MMA_ADDRESS_GROUP_TYPE_CC, &addr->current)) != HDI_FILE_OK)
                {
                    MSF_FILE_CLOSE(fh);
                    return result;
                }
                i++;
                addr = addr->next;
            }

            /* Bcc */
            addr = header->bcc;
            while(i < max && addr != NULL)
            {
                if ((result = mma_xml_create_addr(fh, MMA_ADDRESS_GROUP_TYPE_BCC, &addr->current)) != HDI_FILE_OK)
                {
                    MSF_FILE_CLOSE(fh);
                    return result;
                }
                i++;
                addr = addr->next;
            }
        }

        if(header->from.address != NULL)
        {
            if ((result = mma_xml_create_addr(fh, MMA_ADDRESS_GROUP_TYPE_FROM, &header->from)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }
        }

        /* Subject */
        if (header->subject.text)
        {   
            int len = msf_cmmn_base64_encode_len(strlen(header->subject.text)) + 1;
            char *base64_str = NULL;
            
            MMA_CALLOC(base64_str, len);
            msf_cmmn_base64_encode(header->subject.text, strlen(header->subject.text), base64_str, &len);
            if ((result = mma_xml_create_element_start(fh, MMA_XML_ELEMENT_SUBJECT, NULL)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }
            if ((result = mma_xml_create_data(fh, base64_str)) != HDI_FILE_OK)
            {
                MMA_FREE(base64_str);
                MSF_FILE_CLOSE(fh);
                return result;
            }        
            if ((result = mma_xml_create_element_end(fh, MMA_XML_ELEMENT_SUBJECT)) != HDI_FILE_OK)
            {
                MMA_FREE(base64_str);
                MSF_FILE_CLOSE(fh);
                return result;
            }
            if ((result = mma_xml_create_new_line(fh)) != HDI_FILE_OK)
            {
                MMA_FREE(base64_str);
                MSF_FILE_CLOSE(fh);
                return result;
            }
            MMA_FREE(base64_str);
        }

        /* Read Report */
        if(header->readReply != MMS_READ_REPLY_NOT_SET)
        {
            kal_bool rr = (header->readReply == MMS_READ_REPLY_YES);
            if ((result = mma_xml_create_element_start(fh, MMA_XML_ELEMENT_READ_REPORT, NULL)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }
            if ((result = mma_xml_create_data_numeric_to_char(fh, rr)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }        
            if ((result = mma_xml_create_element_end(fh, MMA_XML_ELEMENT_READ_REPORT)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }
            if ((result = mma_xml_create_new_line(fh)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }
        }

        /* Delivery Report */
        if(header->deliveryReport != MMS_DELIVERY_REPORT_NOT_SET)
        {
            kal_bool dr = (header->deliveryReport == MMS_DELIVERY_REPORT_YES);
            if ((result = mma_xml_create_element_start(fh, MMA_XML_ELEMENT_DELIVERY_REPORT, NULL)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }
            if ((result = mma_xml_create_data_numeric_to_char(fh, dr)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }        
            if ((result = mma_xml_create_element_end(fh, MMA_XML_ELEMENT_DELIVERY_REPORT)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }
            if ((result = mma_xml_create_new_line(fh)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }
        }
        
        /* Priority */
        if(header->priority != MMS_PRIORITY_NOT_SET)
        {
            mma_priority_enum prio = translate_mms_priority_to_mma(header->priority);
            if ((result = mma_xml_create_element_start(fh, MMA_XML_ELEMENT_PRIORITY, NULL)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }
            if ((result = mma_xml_create_data_numeric_to_char(fh, prio)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }        
            if ((result = mma_xml_create_element_end(fh, MMA_XML_ELEMENT_PRIORITY)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }
            if ((result = mma_xml_create_new_line(fh)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }
        }
        
        /* Expiry time */
        if(header->expiryTimeType != 0)
        {
            mma_expiry_time_enum expiry = translate_mms_expiry_to_mma(header->expiryTimeType, header->expiryTime, 
                header->date);
            if ((result = mma_xml_create_element_start(fh, MMA_XML_ELEMENT_EXPIRY, NULL)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }
            if ((result = mma_xml_create_data_numeric_to_char(fh, expiry)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }        
            if ((result = mma_xml_create_element_end(fh, MMA_XML_ELEMENT_EXPIRY)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }
            if ((result = mma_xml_create_new_line(fh)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }
        }

        /* Delivery time */
        if(header->deliveryTimeType != 0)
        {
            mma_delivery_time_enum delivery = translate_mms_delivery_to_mma(header->deliveryTimeType, header->deliveryTime, 
                header->date);
            if ((result = mma_xml_create_element_start(fh, MMA_XML_ELEMENT_DELIVERY_TIME, NULL)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }
            if ((result = mma_xml_create_data_numeric_to_char(fh, delivery)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }        
            if ((result = mma_xml_create_element_end(fh, MMA_XML_ELEMENT_DELIVERY_TIME)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }
            if ((result = mma_xml_create_new_line(fh)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }
        }
        
        /* Sender visibility */
        if(header->visibility != MMS_SENDER_VISIBILITY_NOT_SET)
        {
            kal_bool visible = (header->visibility == MMS_SENDER_SHOW);
            if ((result = mma_xml_create_element_start(fh, MMA_XML_ELEMENT_VISIBLE, NULL)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }
            if ((result = mma_xml_create_data_numeric_to_char(fh, visible)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }        
            if ((result = mma_xml_create_element_end(fh, MMA_XML_ELEMENT_VISIBLE)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }
            if ((result = mma_xml_create_new_line(fh)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }
        }

        /* </header> */
        if ((result = mma_xml_create_element_end(fh, MMA_XML_ELEMENT_HEADER)) != HDI_FILE_OK)
        {
            MSF_FILE_CLOSE(fh);
            return result;
        }
        if ((result = mma_xml_create_new_line(fh)) != HDI_FILE_OK)
        {
            MSF_FILE_CLOSE(fh);
            return result;
        }
        if ((result = mma_xml_create_new_line(fh)) != HDI_FILE_OK)
        {
            MSF_FILE_CLOSE(fh);
            return result;
        }

        /* <body> */
        if(info->mode == MMA_MODE_EDIT || info->mode == MMA_MODE_SEND || info->mode == MMA_MODE_FORWARD)
        {
            mma_body_struct *body = info->body;
            mma_object_struct *obj = NULL;
            U8 bg_color_str[MMA_XML_TEMP_NORMAL_STR_LEN];
            U8 fg_color_str[MMA_XML_TEMP_NORMAL_STR_LEN];
            U8 slide_num_str[MMA_XML_TEMP_SHORT_STR_LEN];
            U8 obj_num_str[MMA_XML_TEMP_SHORT_STR_LEN];
            U8 layout_str[MMA_XML_TEMP_SHORT_STR_LEN];
            const char *attr_list[MMA_MMS_BODY_XML_ATTR_TOTAL_NO * 2 + 1];
            kal_uint32 i = 0, obj_num = 0;

            obj_num = mma_xml_get_obj_count(body);
            
            memset(bg_color_str, 0, MMA_XML_TEMP_NORMAL_STR_LEN);
            if (body->root_layout.bgColor != SLS_COLOR_NOT_USED)
            {
                sprintf((char *)bg_color_str, "0x%x", (int)body->root_layout.bgColor);
            }
            else
            {
                sprintf((char *)bg_color_str, "0x%x", (int)MEAlib_getDefaultSmilBgColor());
            }
            attr_list[MMA_MMS_BODY_XML_ATTR_BG_COLOR * 2] = MMA_XML_ATTR_BGCOLOR;
            attr_list[MMA_MMS_BODY_XML_ATTR_BG_COLOR * 2 + 1] = (const char *)bg_color_str;
            
            memset(fg_color_str, 0, MMA_XML_TEMP_NORMAL_STR_LEN);
            sprintf((char *)fg_color_str, "0x%x", (int)MEAlib_getDefaultSmilFgColor());
            attr_list[MMA_MMS_BODY_XML_ATTR_FG_COLOR * 2] = MMA_XML_ATTR_FGCOLOR;
            attr_list[MMA_MMS_BODY_XML_ATTR_FG_COLOR * 2 + 1] = (const char *)fg_color_str;

            memset(slide_num_str, 0, MMA_XML_TEMP_SHORT_STR_LEN);
            sprintf((char *)slide_num_str, "%d", body->slide_no);
            attr_list[MMA_MMS_BODY_XML_ATTR_SLIDE_NO * 2] = MMA_XML_ATTR_SLIDE_NUM;
            attr_list[MMA_MMS_BODY_XML_ATTR_SLIDE_NO * 2 + 1] = (const char *)slide_num_str;

            memset(obj_num_str, 0, MMA_XML_TEMP_SHORT_STR_LEN);
            sprintf((char *)obj_num_str, "%d", obj_num);
            attr_list[MMA_MMS_BODY_XML_ATTR_OBJ_NO * 2] = MMA_XML_ATTR_OBJ_NUM;
            attr_list[MMA_MMS_BODY_XML_ATTR_OBJ_NO * 2 + 1] = (const char *)obj_num_str;            

            memset(layout_str, 0, MMA_XML_TEMP_SHORT_STR_LEN);
            sprintf((char *)layout_str, "%d", body->layout);
            attr_list[MMA_MMS_BODY_XML_ATTR_LAYOUT * 2] = MMA_XML_ATTR_LAYOUT;
            attr_list[MMA_MMS_BODY_XML_ATTR_LAYOUT * 2 + 1] = (const char *)layout_str;

            attr_list[MMA_MMS_BODY_XML_ATTR_TOTAL_NO * 2] = NULL;

            if ((result = mma_xml_create_element_start(fh, MMA_XML_ELEMENT_BODY, attr_list)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }
            if ((result = mma_xml_create_new_line(fh)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }            
            if ((result = mma_xml_create_new_line(fh)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }            

            /* Slide */
            if (info->mode == MMA_MODE_EDIT && body->slide_no > 0)
            {
                mma_slide_struct *slide = body->slides;

                i = 0;
                while (i < body->slide_no)
                {
                    ASSERT(slide);
                    if ((result = mma_xml_create_slide(fh, slide)) != HDI_FILE_OK)
                    {
                        MSF_FILE_CLOSE(fh);
                        return result;
                    }
                    slide = slide->next;
                    i++;
                }
            }

            /* Object */
            i = 0;
            while (i < obj_num)
            {
                obj = mma_xml_get_object_by_id(body, i + 1);
                if (obj == NULL)
                {
                    break;
                }
                
                if ((result = mma_xml_create_object(fh, info->msg_id, obj)) != HDI_FILE_OK)
                {
                    MSF_FILE_CLOSE(fh);
                    return result;
                }
                i++;
            }

            /* </body> */
            if ((result = mma_xml_create_element_end(fh, MMA_XML_ELEMENT_BODY)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }
            if ((result = mma_xml_create_new_line(fh)) != HDI_FILE_OK)
            {
                MSF_FILE_CLOSE(fh);
                return result;
            }
        }
        
        /* </mms> */
        if ((result = mma_xml_create_element_end(fh, MMA_XML_ELEMENT_MMS)) != HDI_FILE_OK)
        {
            MSF_FILE_CLOSE(fh);
            return result;
        }
        if ((result = mma_xml_create_new_line(fh)) != HDI_FILE_OK)
        {
            MSF_FILE_CLOSE(fh);
            return result;
        }
        
        MSF_FILE_CLOSE(fh);
    }
    else
    {
        ASSERT(0);
    }

    info->xml_filepath = (kal_wchar *)HDI_FileNameTranslate(file_path);
    info->xml_size = HDIa_fileGetSize(file_path);

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mma_xml_insert_slide_by_xml_id
 * DESCRIPTION
 *  Insert slide by slide index
 * PARAMETERS
 *  index         [IN]
 * RETURNS
 *  U8 Decimal value.
 *****************************************************************************/
static mma_slide_struct* mma_xml_insert_slide_by_xml_id(mma_body_struct *body, kal_uint8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_slide_struct *slide = NULL;
    mma_setting_struct sliding;

    MMA_CALLOC(slide, sizeof(mma_slide_struct));
    ASSERT(body != NULL && slide != NULL);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    slide->xmlId = index;
    if (index == 1)
    {
        if(body->slides != NULL)
        {
            slide->next = body->slides;
        }
        body->slides = slide;
    }
    else
    {
        mma_slide_struct* cur_slide = body->slides;
        mma_slide_struct* pre_slide = cur_slide;
        while (cur_slide && (cur_slide->xmlId < index))
        {
            pre_slide = cur_slide;
            cur_slide = cur_slide->next;
        }
        slide->next = cur_slide;
        pre_slide->next = slide;
    }

    mma_conf_get_sliding_time(&sliding);
    slide->duration = sliding.value;
    
//    body->slide_no++;
    body->current_slide = slide;
    return slide;
}

/*****************************************************************************
 * FUNCTION
 *  mma_xml_get_object_by_xml_id
 * DESCRIPTION
 *  Get object pointer by object id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mma_object_struct *mma_xml_get_object_by_xml_id(kal_uint16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_object_struct *object = prs_info->info->body->objects;
    U32 object_num = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; object != NULL; object = object->next, object_num++)
    {
        ASSERT(object_num <= prs_info->info->header->body_no);
        
        if (object->xmlId == id)
        {
            return object;
        }
    }

    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mma_associate_object_id
 * DESCRIPTION
 *  Associate object id after parsing xml file
 * PARAMETERS
 * RETURNS
 *  U8 Decimal value.
 *****************************************************************************/
void mma_xml_associate_object_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_object_struct *object = NULL;
    mma_slide_struct *slide = prs_info->info->body->slides;
    U32 slide_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; slide != NULL; slide = slide->next, slide_num++)
    {
        if (slide->text.id)
        {
            ASSERT((object = mma_xml_get_object_by_xml_id(slide->text.id)) != NULL);
            slide->text.obj = object;
        }
        if (slide->image.id)
        {
            ASSERT((object = mma_xml_get_object_by_xml_id(slide->image.id)) != NULL);
            slide->image.obj = object;
        }
        if (slide->audio.id)
        {
            ASSERT((object = mma_xml_get_object_by_xml_id(slide->audio.id)) != NULL);
            slide->audio.obj = object;
        }
        if (slide->video.id)
        {
            ASSERT((object = mma_xml_get_object_by_xml_id(slide->video.id)) != NULL);
            slide->video.obj = object;
        }        
    }

    ASSERT( slide_num == prs_info->info->body->slide_no);
}

/*****************************************************************************
 * FUNCTION
 *  mma_xml_process_parsed_info
 * DESCRIPTION
 *  Associate object id after parsing xml file
 * PARAMETERS
 * RETURNS
 *  U8 Decimal value.
 *****************************************************************************/
void mma_xml_process_parsed_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_object_struct *object = prs_info->info->body->objects;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (object)
    {
        /* type & mime type */
#ifdef __DRM_SUPPORT__
        switch (object->xmlDrmType)
        {
        case MMA_DRM_NONE:
            object->type = mma_get_slsMediaType_from_filename(object->fileName);
            object->mimeType = msf_cmmn_strdup(MSF_MODID_MMA, mma_get_mime_type_from_filename(object->fileName));
            break;
        case MMA_DRM_FL_CD:
            object->type = SLS_DRM_MESSAGE;
            object->mimeType = msf_cmmn_strdup(MSF_MODID_MMA, "application/vnd.oma.drm.message");
            break;
        case MMA_DRM_SD:
        case MMA_DRM_SD_NO_RIGHT:
            object->type = SLS_DRM_CONTENT;
            object->mimeType = msf_cmmn_strdup(MSF_MODID_MMA, "application/vnd.oma.drm.content");
            object->drmType = mma_get_slsMediaType_from_filename(object->fileName);
            break;
        }
#else
        object->type = mma_get_slsMediaType_from_filename(object->fileName);
        object->mimeType = msf_cmmn_strdup(MSF_MODID_MMA, mma_get_mime_type_from_filename(object->fileName));
#endif

        /* Charset */
        if (mma_get_slsMediaObjectType_from_slsMediaType(object->type) == SLS_TEXT_PLAIN && object->size > 0)
        {
            if (object->isVirtualFile == FALSE)
            {
                object->charset = (mma_is_ascii_text(object->filePath)) ? MMS_US_ASCII : MMS_UTF8;
            }
            else
            {
                char *vFileName = NULL; /* vitual file name */
                int fh = MSF_FILE_OPEN(MSF_MODID_MMA, object->filePath, MSF_FILE_SET_RDONLY, 0);
                MMA_CALLOC(vFileName, WIDGET_RAWFILE_NAMELEN);
                ASSERT(vFileName != NULL);
                if(HDIa_fileGenVirtualFileName(fh, vFileName, WIDGET_RAWFILE_NAMELEN, object->offset, object->size) == HDI_FILE_OK)
                {
                    object->charset = (mma_is_ascii_text(vFileName)) ? MMS_US_ASCII : MMS_UTF8;
                }
                MMA_FREE(vFileName);
                MSF_FILE_CLOSE(fh);
            }
        }
        object = object->next;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_xml_start_element_hdlr
 * DESCRIPTION
 *  Start element handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mma_xml_start_element_hdlr(void *data, const char *el, const char **attr, int error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((!strcmp(MMA_XML_ELEMENT_TO, el)) || (!strcmp(MMA_XML_ELEMENT_CC, el)) ||
        (!strcmp(MMA_XML_ELEMENT_BCC, el))||(!strcmp(MMA_XML_ELEMENT_FROM, el)))
    {
        if (!strcmp(MMA_XML_ATTR_TYPE, attr[0]))
        {
            if (!strcmp(MMA_XML_ATTR_POHNE_NUMBER, attr[1]))
            {
                prs_info->addr_type = MMS_PLMN;
            }
            else if (!strcmp(MMA_XML_ATTR_EMAIL_ADDR, attr[1]))
            {
                prs_info->addr_type = MMS_EMAIL;
            }
            else
            {                
                ASSERT(0);
            }
        }        
    }
    else if (!strcmp(MMA_XML_ELEMENT_BODY , el))
    {
        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMA_XML_ATTR_BGCOLOR , attr[i]))
            {
                prs_info->info->body->root_layout.bgColor = msf_cmmn_hex2int((const char *) attr[i + 1] + 2);
            }
            else if (!strcmp(MMA_XML_ATTR_FGCOLOR , attr[i]))
            {
                /* body fgcolor not supported 
                g_uc_p->msg.foreground_color = msf_cmmn_hex2int((U8*) attr[i + 1] + 2); */
            }
            else if (!strcmp(MMA_XML_ATTR_SLIDE_NUM , attr[i]))
            {
                prs_info->info->body->slide_no = atoi((char *) attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_OBJ_NUM , attr[i]))
            {
                prs_info->info->header->body_no = atoi((char *) attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_LAYOUT , attr[i]))
            {
                prs_info->info->body->layout = atoi((char *) attr[i + 1]);
            }                
        }        
    }
    else if (!strcmp(MMA_XML_ELEMENT_SLIDE, el))
    {
        U8 index = 0;
        U8 duration = 0;

        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMA_XML_ATTR_INDEX, attr[i]))
            {
                index = atoi((char *) attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_DURATION , attr[i]))
            {
                duration = atoi((char *) attr[i + 1]);
            }
        }        

        if (index)
        {
            prs_info->slide = mma_xml_insert_slide_by_xml_id(prs_info->info->body, index);

            if (prs_info->slide)
            {
                ASSERT(prs_info->slide->xmlId == index);
                prs_info->slide->duration = duration * MMA_1_SEC_IN_MSEC;  /* s -> ms */
            }
            else
            {
                ASSERT(0);
            }
        }
        else
        {
            ASSERT(0);
        }        
    }
    else if (!strcmp(MMA_XML_ELEMENT_TEXT , el))
    {
        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMA_XML_ATTR_ID , attr[i]))
            {
                prs_info->slide->text.id = (atoi((char *) attr[i + 1]));
            }
            else if (!strcmp(MMA_XML_ATTR_BEGIN , attr[i]))
            {
                prs_info->slide->text.begin = atoi((char *) attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_END , attr[i]))
            {
               prs_info->slide->text.end = atoi((char *) attr[i + 1]);
            }            
            else if (!strcmp(MMA_XML_ATTR_BGCOLOR , attr[i]))
            {
                /* text background color not supported
                prs_info->slide->text->background_color = msf_cmmn_hex2int((char *) attr[i + 1] + 2); */
            }
            else if (!strcmp(MMA_XML_ATTR_FGCOLOR , attr[i]))
            {
                prs_info->slide->text.text_color = msf_cmmn_hex2int((char *) attr[i + 1] + 2);
            }
        }        
    }    
    else if (!strcmp(MMA_XML_ELEMENT_IMAGE, el))
    {
        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMA_XML_ATTR_ID , attr[i]))
            {
                prs_info->slide->image.id = (atoi((char *) attr[i + 1]));
            }
            else if (!strcmp(MMA_XML_ATTR_BEGIN , attr[i]))
            {
                prs_info->slide->image.begin = atoi((char *) attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_END , attr[i]))
            {
                prs_info->slide->image.end = atoi((char *) attr[i + 1]);
            }            
        }        
    }    
    else if (!strcmp(MMA_XML_ELEMENT_AUDIO, el))
    {
        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMA_XML_ATTR_ID , attr[i]))
            {
                prs_info->slide->audio.id = (atoi((char *) attr[i + 1]));
            }
            else if (!strcmp(MMA_XML_ATTR_BEGIN , attr[i]))
            {
                prs_info->slide->audio.begin = atoi((char *) attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_END , attr[i]))
            {
                prs_info->slide->audio.end = atoi((char *) attr[i + 1]);
            }            
        }        
    }    
    else if (!strcmp(MMA_XML_ELEMENT_VIDEO, el))
    {
        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMA_XML_ATTR_ID , attr[i]))
            {
                prs_info->slide->video.id = (atoi((char *) attr[i + 1]));
            }
            else if (!strcmp(MMA_XML_ATTR_BEGIN , attr[i]))
            {
                prs_info->slide->video.begin = atoi((char *) attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_END , attr[i]))
            {
                prs_info->slide->video.end = atoi((char *) attr[i + 1]);
            }            
        }        
    }
    else if (!strcmp(MMA_XML_ELEMENT_OBJECT, el))
    {
        prs_info->object = mma_insert_object_to_tail(prs_info->info->body);
//        prs_info->info->header->body_no++;
        
        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMA_XML_ATTR_ID , attr[i]))
            {
                prs_info->object->xmlId = (atoi((char *) attr[i + 1]));
            }
            else if (!strcmp(MMA_XML_ATTR_ATTACH , attr[i]))
            {
                prs_info->object->isAttachment = atoi((char *) attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_VIRTUAL_FILE , attr[i]))
            {
                prs_info->object->isVirtualFile = atoi((char *) attr[i + 1]);
            }            
            else if (!strcmp(MMA_XML_ATTR_DRM, attr[i]))
            {
#ifdef __DRM_SUPPORT__
                prs_info->object->xmlDrmType = atoi((char *) attr[i + 1]);
#endif
            }
            else if (!strcmp(MMA_XML_ATTR_SIZE , attr[i]))
            {
                prs_info->object->size = atoi((char *) attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_OFFSET  , attr[i]))
            {
                prs_info->object->offset = atoi((char *) attr[i + 1]);
            }            
        }        
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_xml_end_element_hdlr
 * DESCRIPTION
 *  end element handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mma_xml_end_element_hdlr(void *data, const char *el, int error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!strcmp(MMA_XML_ELEMENT_OBJECT, el))
    {   
        if (prs_info->object->isAttachment)
        {
            mma_insert_unref_item_to_tail(prs_info->info->body, prs_info->object);
        }
    }
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mma_xml_data_address_hdlr
 * DESCRIPTION
 *  Add address 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mma_xml_data_address_hdlr(const char *utf8_addr, int addr_len, MmsAddressType addr_type, 
                               mma_address_group_type_enum group)
{
    if (addr_type == MMS_PLMN || addr_type == MMS_EMAIL )
    {
        MmsAddressList **list = NULL;
        
        switch (group)
        {
            case MMA_ADDRESS_GROUP_TYPE_TO:
                list = &prs_info->info->header->header.s_header->to;
                break;
            
            case MMA_ADDRESS_GROUP_TYPE_CC:
                list = &prs_info->info->header->header.s_header->cc;
                break;
        
            case MMA_ADDRESS_GROUP_TYPE_BCC:
                list = &prs_info->info->header->header.s_header->bcc;
                break;
        
            case MMA_ADDRESS_GROUP_TYPE_FROM:
                /* do not set manually 
                prs_info->info->header->header.s_header->from; */
                return;
        
            default:
                ASSERT(0);
                break;        
        }

        mma_insert_addr_to_list(addr_type, (char *)utf8_addr, list);
    }        
    else
    {
        ASSERT(0);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_xml_data_hdlr
 * DESCRIPTION
 *  Start element handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mma_xml_data_hdlr(void *data, const char *el, const char *value, int len, int error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!strcmp(MMA_XML_ELEMENT_TO, el))
    {   
        mma_xml_data_address_hdlr(value, len, prs_info->addr_type, MMA_ADDRESS_GROUP_TYPE_TO);
    }
    else if (!strcmp(MMA_XML_ELEMENT_CC, el))
    {
        mma_xml_data_address_hdlr(value, len, prs_info->addr_type, MMA_ADDRESS_GROUP_TYPE_CC);
    }    
    else if (!strcmp(MMA_XML_ELEMENT_BCC, el))
    {
        mma_xml_data_address_hdlr(value, len, prs_info->addr_type, MMA_ADDRESS_GROUP_TYPE_BCC);
    }    
    else if (!strcmp(MMA_XML_ELEMENT_FROM, el))
    {
        mma_xml_data_address_hdlr(value, len, prs_info->addr_type, MMA_ADDRESS_GROUP_TYPE_FROM);
    }
    else if (!strcmp(MMA_XML_ELEMENT_SUBJECT, el))
    {
        prs_info->info->header->header.s_header->subject.charset = MMS_UTF8;
        if (len > 0)
        {
            int length = msf_cmmn_base64_decode_len(value, len) + 1;
            MMA_CALLOC(prs_info->info->header->header.s_header->subject.text, length);
            msf_cmmn_base64_decode(value, len, prs_info->info->header->header.s_header->subject.text, &length);
        }
        else
        {
            prs_info->info->header->header.s_header->subject.text = NULL;
        }
    }
    else if (!strcmp(MMA_XML_ELEMENT_READ_REPORT, el))
    {
        if (atoi((char *) value))
        {
            prs_info->info->header->header.s_header->readReply = MMS_READ_REPLY_YES;
        }
        else
        {
            prs_info->info->header->header.s_header->readReply = MMS_READ_REPLY_NO;
        }
    }
    else if (!strcmp(MMA_XML_ELEMENT_DELIVERY_REPORT, el))
    {
        if (atoi((char *) value))
        {
            prs_info->info->header->header.s_header->deliveryReport = MMS_DELIVERY_REPORT_YES;
        }
        else
        {
            prs_info->info->header->header.s_header->deliveryReport = MMS_DELIVERY_REPORT_NO;
        }
    }    
    else if (!strcmp(MMA_XML_ELEMENT_PRIORITY , el))
    {
        prs_info->info->header->header.s_header->priority = translate_mma_priority_to_mms(atoi((char *) value));
    }
    else if (!strcmp(MMA_XML_ELEMENT_EXPIRY , el))
    {
        translate_mma_expiry_to_mms(atoi((char *) value), 
            prs_info->info->header->header.s_header->date,
            &prs_info->info->header->header.s_header->expiryTimeType, 
            &prs_info->info->header->header.s_header->expiryTime);
    }
    else if (!strcmp(MMA_XML_ELEMENT_DELIVERY_TIME , el))
    {
        translate_mma_delivery_to_mms(atoi((char *) value), 
            prs_info->info->header->header.s_header->date,
            &prs_info->info->header->header.s_header->deliveryTimeType, 
            &prs_info->info->header->header.s_header->deliveryTime);
    }    
    else if (!strcmp(MMA_XML_ELEMENT_VISIBLE , el))
    {
        /* surrently not supported */
    }    
    else if (!strcmp(MMA_XML_ELEMENT_NAME , el))
    {
        prs_info->object->fileName = msf_cmmn_strdup(MSF_MODID_MMA, value);
    }
    else if (!strcmp(MMA_XML_ELEMENT_FILE_PATH, el))
    {
        MMA_CALLOC(prs_info->object->filePath, HDI_EXTERNAL_LEN + strlen(value) + 1);
        strcpy(prs_info->object->filePath, HDI_EXTERNAL_PATH);
        strcat(prs_info->object->filePath, value);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_xml_parse_mms_xml_description_file
 * DESCRIPTION
 *  Pare mms xml description file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mma_result_enum mma_xml_parse_mms_xml_description_file(mma_create_mms_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    XML_PARSER_STRUCT *xml_parser = NULL;

    MMA_CALLOC(xml_parser, sizeof(XML_PARSER_STRUCT));
    result = xml_new_parser(xml_parser);
    if (result)
    {
        xml_close_parser(xml_parser);
        MMA_FREE(xml_parser);
        xml_parser = NULL;
        return MMA_RESULT_FAIL_PARSE;
    }

    ASSERT(prs_info == NULL);
    MMA_CALLOC(prs_info, sizeof(mma_xml_parser_info_struct));
    prs_info->info = info;

    xml_register_element_handler(xml_parser, mma_xml_start_element_hdlr, mma_xml_end_element_hdlr);
    xml_register_data_handler(xml_parser, mma_xml_data_hdlr);
    result = xml_parse(xml_parser, info->xml_filepath);
    xml_close_parser(xml_parser);

    MMA_FREE(xml_parser);
    xml_parser = NULL;

    if (result == XML_RESULT_OK)
    {
        mma_xml_associate_object_id();
        mma_xml_process_parsed_info();
        result = MMA_RESULT_OK;
    }
    else
    {
        result = MMA_RESULT_FAIL_PARSE;
    }
    
    prs_info->info = NULL;
    MMA_FREE(prs_info);
    prs_info = NULL;

    return result;
}


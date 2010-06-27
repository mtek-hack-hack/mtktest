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
 *  MMSMsgXML.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contains the code to Encode MMS data into XML
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
 *
 
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef __MMI_MMSXMLENCODER_C
#define __MMI_MMSXMLENCODER_C

/***************************************************************************** 
* Include
*****************************************************************************/


#ifdef __MMI_MMS_2__

//#include "FileSystemDef.h"
//#include "xml_def.h"
#include "mmsadp.h"
#include "MMSMsgXMLTags.h"
#include "MMSXMLDef.h"
#include "MMSMsgCommonProt.h"

static S32 mmi_umms_create_xml_element_start(FS_HANDLE fh, U8* element_name, U8** attr_list);
static S32 mmi_umms_create_xml_new_line(FS_HANDLE fh);
static S32 mmi_umms_create_xml_addr(
            FS_HANDLE fh,
            mmi_umms_address_group_type_enum type,
            mmi_umms_xml_msg_struct *umms_msg);
static S32 mmi_umms_create_xml_data_usc2_to_utf8(FS_HANDLE fh, U8* data);
static S32 mmi_umms_create_xml_element_end(FS_HANDLE fh, U8* element_name);
static S32 mmi_umms_create_xml_data_numeric_to_char(FS_HANDLE fh, U32 value);
static S32 mmi_umms_create_xml_slide(FS_HANDLE fh, mmi_umms_slide_struct* slide,mmi_umms_xml_msg_struct *umms_msg);
static S32 mmi_umms_create_xml_object(FS_HANDLE fh, mmi_umms_object_struct* obj);
static S32 mmi_umms_create_xml_slide_object(FS_HANDLE fh, mmi_umms_slide_struct* slide, mmi_umms_object_type obj_type);
static S32 mmi_umms_create_xml_element_single(FS_HANDLE fh, U8* element_name, U8** attr_list);


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_create_mms_xml_description_file
 * DESCRIPTION
 *  Create the mms xml description file
 * PARAMETERS
 *  umms_msg        [?]     
 *  file_path       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_umms_create_mms_xml_description_file(mmi_umms_xml_msg_struct *umms_msg, U8* file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    FS_HANDLE fh;
    S32 result = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Open the file to write, overwrite if already exists. */
    fh = FS_Open((U16*) file_path, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (fh >= 0)
    {
        /* <mms> */
        if ((result = mmi_umms_create_xml_element_start(fh, (U8*)MMI_UMMS_XML_ELEMENT_MMS, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = mmi_umms_create_xml_new_line(fh))!= FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }

        /* <header> */
        if ((result = mmi_umms_create_xml_element_start(fh, (U8*)MMI_UMMS_XML_ELEMENT_HEADER, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }

        /* To address */
        if (umms_msg->to_num)
        {
            if ((result = mmi_umms_create_xml_addr(fh, MMI_UMMS_ADDRESS_GROUP_TYPE_TO, umms_msg)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }
        }
        
        /* Cc address */
        if (umms_msg->cc_num)
        {
            if ((result = mmi_umms_create_xml_addr(fh, MMI_UMMS_ADDRESS_GROUP_TYPE_CC, umms_msg)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }
        }
        
        /* Bcc address */
        if (umms_msg->bcc_num)
        {
            if ((result = mmi_umms_create_xml_addr(fh, MMI_UMMS_ADDRESS_GROUP_TYPE_BCC, umms_msg)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }
        }

        /* subject */
        if (mmi_ucs2strlen((S8*)umms_msg->subject))
        {
            if ((result = mmi_umms_create_xml_element_start(fh, (U8*)MMI_UMMS_XML_ELEMENT_SUBJECT, NULL)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }

			if ((result = mmi_umms_create_xml_data_usc2_to_base64(fh, (U8*)umms_msg->subject)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            } 

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* 0 */ 
            if ((result = mmi_umms_create_xml_element_end(fh, (U8*)MMI_UMMS_XML_ELEMENT_SUBJECT)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }
            if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }
        }

        /* java_app_id */
        if (mmi_ucs2strlen((S8*) umms_msg->java_app_id))
        {
            if ((result = mmi_umms_create_xml_element_start(fh, (U8*) MMI_UMMS_XML_ELEMENT_JAVA_APP_ID, NULL)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }
            if ((result = mmi_umms_create_xml_data_usc2_to_utf8(fh, (U8*) umms_msg->java_app_id)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }
            if ((result = mmi_umms_create_xml_element_end(fh, (U8*) MMI_UMMS_XML_ELEMENT_JAVA_APP_ID)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }
            if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }
        }

        /* java_reply_app_id */
        if (mmi_ucs2strlen((S8*) umms_msg->java_reply_app_id))
        {
            if ((result = mmi_umms_create_xml_element_start(
                            fh,
                            (U8*) MMI_UMMS_XML_ELEMENT_JAVA_REPLY_APP_ID,
                            NULL)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }
            if ((result = mmi_umms_create_xml_data_usc2_to_utf8(fh, (U8*) umms_msg->java_reply_app_id)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }
            if ((result = mmi_umms_create_xml_element_end(fh, (U8*) MMI_UMMS_XML_ELEMENT_JAVA_REPLY_APP_ID)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }
            if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }
        }

        /* Status */
        if ((result = mmi_umms_create_xml_element_start(fh, (U8*) MMI_UMMS_XML_ELEMENT_STATUS, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = mmi_umms_create_xml_data_numeric_to_char(fh, umms_msg->status)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = mmi_umms_create_xml_element_end(fh, (U8*) MMI_UMMS_XML_ELEMENT_STATUS)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }

        /* Read Report */
        if ((result = mmi_umms_create_xml_element_start(fh, (U8*)MMI_UMMS_XML_ELEMENT_READ_REPORT, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = mmi_umms_create_xml_data_numeric_to_char(fh, umms_msg->read_report)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }        
        if ((result = mmi_umms_create_xml_element_end(fh, (U8*)MMI_UMMS_XML_ELEMENT_READ_REPORT)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }

        /* Delivery Report */
        if ((result = mmi_umms_create_xml_element_start(fh, (U8*)MMI_UMMS_XML_ELEMENT_DELIVERY_REPORT, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = mmi_umms_create_xml_data_numeric_to_char(fh, umms_msg->delivery_report)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }        
        if ((result = mmi_umms_create_xml_element_end(fh, (U8*)MMI_UMMS_XML_ELEMENT_DELIVERY_REPORT)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }

        /* Priority */
        if ((result = mmi_umms_create_xml_element_start(fh, (U8*)MMI_UMMS_XML_ELEMENT_PRIORITY, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = mmi_umms_create_xml_data_numeric_to_char(fh, umms_msg->priority)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }        
        if ((result = mmi_umms_create_xml_element_end(fh, (U8*)MMI_UMMS_XML_ELEMENT_PRIORITY)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }

        /* Expiry time */
        if ((result = mmi_umms_create_xml_element_start(fh, (U8*)MMI_UMMS_XML_ELEMENT_EXPIRY, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = mmi_umms_create_xml_data_numeric_to_char(fh, umms_msg->expiry_time)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }        
        if ((result = mmi_umms_create_xml_element_end(fh, (U8*)MMI_UMMS_XML_ELEMENT_EXPIRY)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }

        /* Delivery time */
        if ((result = mmi_umms_create_xml_element_start(fh, (U8*)MMI_UMMS_XML_ELEMENT_DELIVERY_TIME, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = mmi_umms_create_xml_data_numeric_to_char(fh, umms_msg->delivery_time)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }        
        if ((result = mmi_umms_create_xml_element_end(fh, (U8*)MMI_UMMS_XML_ELEMENT_DELIVERY_TIME)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }

		/* mms version number */
        if (mmi_ucs2strlen((S8*)umms_msg->mms_version))
        {
            if ((result = mmi_umms_create_xml_element_start(fh, (U8*)MMI_UMMS_XML_ELEMENT_VERSION, NULL)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }
            if ((result = mmi_umms_create_xml_data_usc2_to_utf8(fh, (U8*)umms_msg->mms_version)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }        
            if ((result = mmi_umms_create_xml_element_end(fh, (U8*)MMI_UMMS_XML_ELEMENT_VERSION)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }
            if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }
        }
		/* date */
        if ((result = mmi_umms_create_xml_element_start(fh, (U8*)MMI_UMMS_XML_ELEMENT_DATE, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = mmi_umms_create_xml_data_numeric_to_char(fh, umms_msg->date)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }        
        if ((result = mmi_umms_create_xml_element_end(fh, (U8*)MMI_UMMS_XML_ELEMENT_DATE)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }

		/* msg class  */
        if ((result = mmi_umms_create_xml_element_start(fh, (U8*)MMI_UMMS_XML_ELEMENT_MSG_CLASS, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = mmi_umms_create_xml_data_numeric_to_char(fh, umms_msg->msgclass)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }        
        if ((result = mmi_umms_create_xml_element_end(fh, (U8*)MMI_UMMS_XML_ELEMENT_MSG_CLASS)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }

		/* msg size */
        if ((result = mmi_umms_create_xml_element_start(fh, (U8*)MMI_UMMS_XML_ELEMENT_MSG_SIZE, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = mmi_umms_create_xml_data_numeric_to_char(fh, umms_msg->msgsize)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }        
        if ((result = mmi_umms_create_xml_element_end(fh, (U8*)MMI_UMMS_XML_ELEMENT_MSG_SIZE)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }

		/*msg status */
        if ((result = mmi_umms_create_xml_element_start(fh, (U8*)MMI_UMMS_XML_ELEMENT_MSG_STATUS, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = mmi_umms_create_xml_data_numeric_to_char(fh, umms_msg->msgStatus)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }        
        if ((result = mmi_umms_create_xml_element_end(fh, (U8*)MMI_UMMS_XML_ELEMENT_MSG_STATUS)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }

        /* Sender visibility */
        if ((result = mmi_umms_create_xml_element_start(fh, (U8*)MMI_UMMS_XML_ELEMENT_VISIBLE, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = mmi_umms_create_xml_data_numeric_to_char(fh, umms_msg->sender_visibility)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }        
        if ((result = mmi_umms_create_xml_element_end(fh, (U8*)MMI_UMMS_XML_ELEMENT_VISIBLE)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }

        /* </header> */
        if ((result = mmi_umms_create_xml_element_end(fh, (U8*)MMI_UMMS_XML_ELEMENT_HEADER)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }

            /* <body> */
            {
                U16 color_str_len = 10; /* size of bg_color and fg_color */
                U16 str_len = 5; /* size of slide_num, obj_num, and layout */
                U16 attr_num = 5; /* size of arrt_list would be attr_num * 2 + 1 */
                U8 bg_color[10];
                U8 fg_color[10];
                U8 slide_num[5];
                U8 obj_num[5];
                U8 layout[5];
                U8* attr_list[5 * 2 + 1];
                U8 i = 0;

                memset(bg_color, 0, color_str_len);
                sprintf((char*)bg_color, "0x%06x", umms_msg->background_color);
                attr_list[i++] = (U8*)MMI_UMMS_XML_ATTR_BGCOLOR;
                attr_list[i++] = bg_color;
                
                memset(fg_color, 0, color_str_len);
                sprintf((char*)fg_color, "0x%06x", umms_msg->foreground_color);
                attr_list[i++] = (U8*)MMI_UMMS_XML_ATTR_FGCOLOR;
                attr_list[i++] = fg_color;

                /* If only attachments and one slide without any content, do not send slide info.*/
                /* reference phone behavior */
                memset(slide_num, 0, str_len);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* 0 */ 
                {
                    sprintf((char*)slide_num, "%d", umms_msg->total_slide_num);
                }
                attr_list[i++] = (U8*)MMI_UMMS_XML_ATTR_SLIDE_NUM;
                attr_list[i++] = slide_num;

                memset(obj_num, 0, str_len);
                sprintf((char*)obj_num, "%d", umms_msg->total_object_num);
                attr_list[i++] = (U8*)MMI_UMMS_XML_ATTR_OBJ_NUM;
                attr_list[i++] = obj_num;            

                memset(layout, 0, str_len);
                sprintf((char*)layout, "%d", umms_msg->layout/*mmi_uc_convert_to_mms_layout_type(umms_msg->layout)*/);
                attr_list[i++] = (U8*)MMI_UMMS_XML_ATTR_LAYOUT;
                attr_list[i++] = layout;

                attr_list[i++] = NULL;

                MMI_ASSERT(i == (attr_num * 2 + 1));

                if ((result = mmi_umms_create_xml_element_start(fh, (U8*)MMI_UMMS_XML_ELEMENT_BODY, attr_list)) != FS_NO_ERROR)
                {
                    FS_Close(fh);
                    return result;
                }
                if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
                {
                    FS_Close(fh);
                    return result;
                }            
            }

            /* Slide */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* 0 */ 
            {
                if (umms_msg->total_slide_num)
                {
                    mmi_umms_slide_struct* slide = umms_msg->slide_head;
                    U16 i = 0;

                    while (i < umms_msg->total_slide_num)
                    {
                        MMI_ASSERT(slide);
                        if ((result = mmi_umms_create_xml_slide(fh, slide,umms_msg)) != FS_NO_ERROR)
                        {
                            FS_Close(fh);
                            return result;
                        }
                        slide = slide->next;
                        i++;
                    }            
                }
            }

            /* Object */
            if (umms_msg->total_object_num)
            {
                mmi_umms_object_struct* object = umms_msg->object_head;
                U16 i = 0;

                while (i < umms_msg->total_object_num)
                {
                    MMI_ASSERT(object);
                    if ((result = mmi_umms_create_xml_object(fh, object)) != FS_NO_ERROR)
                    {
                        FS_Close(fh);
                        return result;
                    }
                    object = object->next;
                    i++;
                }            
            }

            /* </body> */
            if ((result = mmi_umms_create_xml_element_end(fh, (U8*)MMI_UMMS_XML_ELEMENT_BODY)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }
            if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }
        
        /* </mms> */
        if ((result = mmi_umms_create_xml_element_end(fh, (U8*)MMI_UMMS_XML_ELEMENT_MMS)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }            
        
        FS_Close(fh);
    }
    else
    {
		result = fh;
		return result;
//        MMI_ASSERT(0);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_create_xml_element_start
 * DESCRIPTION
 *  Create the xml start element
 * PARAMETERS
 *  fh                  [IN]        
 *  element_name        [?]         
 *  attr_list           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_umms_create_xml_element_start(FS_HANDLE fh, U8* element_name, U8** attr_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* temp_str = (U8*) umms_malloc(MMI_UMMS_XML_TEMP_STR_LEN);
    S32 result = FS_NO_ERROR;
    U32 write_len = 0;
    U32 i = 0;
    U32 offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(temp_str,0,MMI_UMMS_XML_TEMP_STR_LEN);
    offset += sprintf((char*)temp_str, "%s%s", XML_TAG_ELEMENT_START, element_name);

    if (attr_list)
    {
        while (attr_list[i])
        {
            offset += sprintf((char*)temp_str + offset, " %s=\"%s\"", attr_list[i], attr_list[i + 1]);
            i = i + 2;
        }
    }

    offset += sprintf((char*)(temp_str + offset), "%s", XML_TAG_GENERAL_END);

    MMI_ASSERT(offset < MMI_UMMS_XML_TEMP_STR_LEN);

    result = FS_Write(fh, temp_str, offset, &write_len);

    umms_free(temp_str);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_create_xml_element_end
 * DESCRIPTION
 *  Create the xml end element
 * PARAMETERS
 *  fh                  [IN]        
 *  element_name        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_umms_create_xml_element_end(FS_HANDLE fh, U8* element_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* temp_str = (U8*) umms_malloc(MMI_UMMS_XML_TEMP_STR_LEN);
    S32 result = FS_NO_ERROR;
    U32 write_len = 0;
    U32 offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(temp_str,0,MMI_UMMS_XML_TEMP_STR_LEN);
    offset += sprintf((char*)temp_str, "%s%s%s", XML_TAG_ELEMENT_END, element_name,XML_TAG_GENERAL_END);

    MMI_ASSERT(offset < MMI_UMMS_XML_TEMP_STR_LEN);

    result = FS_Write(fh, temp_str, offset, &write_len);

    umms_free(temp_str);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_create_xml_new_line
 * DESCRIPTION
 *  Insert new line
 * PARAMETERS
 *  fh      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_umms_create_xml_new_line(FS_HANDLE fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* temp_str = (U8*) umms_malloc(MMI_UMMS_XML_TEMP_STR_LEN);
    S32 result = FS_NO_ERROR;
    U32 write_len = 0;
    U32 offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(temp_str,0,MMI_UMMS_XML_TEMP_STR_LEN);
    offset += sprintf((char*)temp_str, "\n");

    result = FS_Write(fh, temp_str, offset, &write_len);

    umms_free(temp_str);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_create_xml_data
 * DESCRIPTION
 *  Add data
 * PARAMETERS
 *  fh          [IN]        
 *  data        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_umms_create_xml_data(FS_HANDLE fh, U8* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = FS_NO_ERROR;
    U32 write_len = 0;
    U32 offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    offset = strlen((char*)data);

    result = FS_Write(fh, data, offset, &write_len);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_create_xml_data_usc2_to_utf8
 * DESCRIPTION
 *  Add data
 * PARAMETERS
 *  fh          [IN]        
 *  data        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_umms_create_xml_data_usc2_to_utf8(FS_HANDLE fh, U8* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* utf8_data;
    U32 utf8_data_len = mmi_ucs2strlen((S8*)data) * 3 + 1;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    utf8_data = (U8*) umms_malloc(utf8_data_len);
    memset(utf8_data,0,utf8_data_len);
    
    mmi_chset_ucs2_to_utf8_string((kal_uint8*) utf8_data, utf8_data_len, (kal_uint8*) data);

    result = mmi_umms_create_xml_data(fh, utf8_data);

    umms_free(utf8_data);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_create_xml_data_usc2_to_base64
 * DESCRIPTION
 *  Add data
 * PARAMETERS
 *  fh          [IN]        
 *  data        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_umms_create_xml_data_usc2_to_base64(FS_HANDLE fh, U8* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* utf8_data;
    U32 utf8_data_len = mmi_ucs2strlen((S8*)data) * 3 + 1;
    S32 result;
    U32 utf8_data_actual_len = 0;
    U32 base64_data_len = 0;
    U8* base64_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    utf8_data = (U8*) umms_malloc(utf8_data_len);
    memset(utf8_data,0,utf8_data_len);
    
    utf8_data_actual_len = mmi_chset_ucs2_to_utf8_string((kal_uint8*) utf8_data, utf8_data_len, (kal_uint8*) data);

    base64_data_len = utf8_data_actual_len * 3;

    base64_data = (U8*) umms_malloc(base64_data_len + 1);
    memset(base64_data,0,base64_data_len + 1);
    
    applib_base64_encode((S8*)utf8_data, utf8_data_actual_len, (S8*)base64_data, base64_data_len);

    result = mmi_umms_create_xml_data(fh, base64_data);

    umms_free(base64_data);
    umms_free(utf8_data);

    return result;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_create_xml_data_numeric_to_char
 * DESCRIPTION
 *  Add numeric data
 * PARAMETERS
 *  fh          [IN]        
 *  value       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_umms_create_xml_data_numeric_to_char(FS_HANDLE fh, U32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* data;
    U32 data_len = 10;
    S32 result;
    U32 offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    data = (U8*) umms_malloc(data_len);
    memset(data,0,data_len);
    
    offset += sprintf((char*)data, "%d", value);

    result = mmi_umms_create_xml_data(fh, data);

    umms_free(data);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_create_xml_addr
 * DESCRIPTION
 *  Add data
 * PARAMETERS
 *  fh              [IN]        
 *  type            [IN]        
 *  umms_msg        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_umms_create_xml_addr(FS_HANDLE fh, mmi_umms_address_group_type_enum type,mmi_umms_xml_msg_struct *umms_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    U32 i = 0;
    mmi_umms_addr_struct* addr = NULL;
    U8* attr_list[3];
    U8* xml_addr_type = NULL;
    U32 total = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MMI_UMMS_ADDRESS_GROUP_TYPE_TO:
        {
            addr = umms_msg->to_head;
            total = umms_msg->to_num;
            xml_addr_type = (U8*)MMI_UMMS_XML_ELEMENT_TO;
        }
        break;
            
        case MMI_UMMS_ADDRESS_GROUP_TYPE_CC:
        {
            addr = umms_msg->cc_head;
            total = umms_msg->cc_num;
            xml_addr_type = (U8*)MMI_UMMS_XML_ELEMENT_CC;
        }
        break;

        case MMI_UMMS_ADDRESS_GROUP_TYPE_BCC:
        {
            addr = umms_msg->bcc_head;
            total = umms_msg->bcc_num;
            xml_addr_type = (U8*)MMI_UMMS_XML_ELEMENT_BCC;
        }
        break;

        default:
        {
            MMI_ASSERT(0);
        }
        break;
    }

    attr_list[0] = (U8*)MMI_UMMS_XML_ATTR_TYPE;
    attr_list[2] = NULL;
    while (i < total)
    {
        MMI_ASSERT(addr);
        
        if (addr->type == MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER)
        {
            attr_list[1] = (U8*)MMI_UMMS_XML_ATTR_POHNE_NUMBER;
            if ((result = mmi_umms_create_xml_element_start(fh, xml_addr_type, attr_list)) != FS_NO_ERROR)
            {
                return result;
            }

            if ((result = mmi_umms_create_xml_data(fh, addr->addr)) != FS_NO_ERROR)
            {
                return result;
            }                    
        }
        else if (addr->type == MMI_UMMS_ADDRESS_TYPE_EMAIL)
        {        
            attr_list[1] = (U8*)MMI_UMMS_XML_ATTR_EMAIL_ADDR;
            
            if ((result = mmi_umms_create_xml_element_start(fh, xml_addr_type, attr_list)) != FS_NO_ERROR)
            {
                return result;
            }            
            if ((result = mmi_umms_create_xml_data_usc2_to_utf8(fh, addr->addr)) != FS_NO_ERROR)
            {
                return result;
            }                    
        }
        else
        {
            MMI_ASSERT(0);
        }

        if ((result = mmi_umms_create_xml_element_end(fh, xml_addr_type)) != FS_NO_ERROR)
        {
            return result;
        }
        if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            return result;
        }

        addr = addr->next;
        i++;
    }
    return FS_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_create_xml_slide
 * DESCRIPTION
 *  Add data
 * PARAMETERS
 *  fh              [IN]        
 *  slide           [?]         
 *  umms_msg        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_umms_create_xml_slide(FS_HANDLE fh, mmi_umms_slide_struct* slide,mmi_umms_xml_msg_struct *umms_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;    
    U16 str_len = 5;  /* size of index and duration */
    U16 attr_num = 2; /* size of attr_list would be attr_num * 2 + 1 */
    U8 index[5];
    U8 duration[5];
    U8* attr_list[2 * 2 + 1];
    U8 j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(slide);

    memset(index, 0, str_len);
    sprintf((char*)index, "%d", (slide->slide_num));
    attr_list[j++] = (U8*)MMI_UMMS_XML_ATTR_INDEX;
    attr_list[j++] = index;

    memset(duration, 0, str_len);
    sprintf((char*)duration, "%d", umms_msg->slide_timing);
    attr_list[j++] = (U8*)MMI_UMMS_XML_ATTR_DURATION;
    attr_list[j++] = duration;

    attr_list[j++] = NULL;

    MMI_ASSERT(j == (attr_num * 2 + 1));

    if ((result = mmi_umms_create_xml_element_start(fh, (U8*)MMI_UMMS_XML_ELEMENT_SLIDE, attr_list)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
    {
        return result;
    }
    /* text */
    if (slide->text.object)
    {
        if ((result = mmi_umms_create_xml_slide_object(fh, slide, MMI_UMMS_OBJECT_TYPE_TEXT)) != FS_NO_ERROR)
        {
            return result;
        }
    }
    /* image */
    if (slide->image.object)
    {
        if ((result = mmi_umms_create_xml_slide_object(fh, slide, MMI_UMMS_OBJECT_TYPE_IMAGE)) != FS_NO_ERROR)
        {
            return result;
        }
    }
    /* audio */
    if (slide->audio.object)
    {
        if ((result = mmi_umms_create_xml_slide_object(fh, slide, MMI_UMMS_OBJECT_TYPE_AUDIO)) != FS_NO_ERROR)
        {
            return result;
        }
    }
    /* video */
    if (slide->video.object)
    {
        if ((result = mmi_umms_create_xml_slide_object(fh, slide, MMI_UMMS_OBJECT_TYPE_VIDEO)) != FS_NO_ERROR)
        {
            return result;
        }
    }

    if ((result = mmi_umms_create_xml_element_end(fh, (U8*)MMI_UMMS_XML_ELEMENT_SLIDE)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
    {
        return result;
    }

    return FS_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_create_xml_slide_object
 * DESCRIPTION
 *  Add data
 * PARAMETERS
 *  fh              [IN]        
 *  slide           [?]         
 *  obj_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_umms_create_xml_slide_object(FS_HANDLE fh, mmi_umms_slide_struct* slide, mmi_umms_object_type obj_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    U32 bg_color = 0;
    U32 fg_color = 0;
    U16 color_str_len = 10; /* size of bg_color_str and fg_color_str */
    U16 str_len = 5; /* size of id_str , start_str, and end_str */
    U16 attr_num = 7; /* size of attr_list would be attr_num * 2 + 1 */
    U32 id = 0;    
    U8 bg_color_str[10];
    U8 fg_color_str[10];
    U8 id_str[5];
    U8 start_str[5];
    U8 end_str[5];
	U8 textstrStyle[5];
	U8 textstrSize[5];
    U8* attr_list[7 * 2 + 1];
    U8 txt_style;
	U8 txt_size;
    U8 i = 0;
    U8 begin = 0;
    U8 end = 0;
    U8* obj_xml_type = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(slide);
    
    switch (obj_type)
    {
        case MMI_UMMS_OBJECT_TYPE_TEXT:
        {
            MMI_ASSERT(slide->text.object);
            fg_color = slide->text.foreground_color;
            bg_color = slide->text.background_color;
			txt_style =  slide->text.txtStyle;
			txt_size = slide->text.txtSize;
            id = slide->text.object->id;
            begin = slide->text.begin;            
            end = slide->text.end;
            obj_xml_type = (U8*)MMI_UMMS_XML_ELEMENT_TEXT;
        }
        break;

        case MMI_UMMS_OBJECT_TYPE_IMAGE:
        {
            MMI_ASSERT(slide->image.object);
            id = slide->image.object->id;
            begin = slide->image.begin;            
            end = slide->image.end;
            obj_xml_type = (U8*)MMI_UMMS_XML_ELEMENT_IMAGE;
        }
        break;
        
        case MMI_UMMS_OBJECT_TYPE_AUDIO:
        {
            MMI_ASSERT(slide->audio.object);
            id = slide->audio.object->id;
            begin = slide->audio.begin;            
            end = slide->audio.end;
            obj_xml_type = (U8*)MMI_UMMS_XML_ELEMENT_AUDIO;
        }
        break;
        
        case MMI_UMMS_OBJECT_TYPE_VIDEO:
        {
            MMI_ASSERT(slide->video.object);
            id = slide->video.object->id;
            begin = slide->video.begin;            
            end = slide->video.end;
            obj_xml_type = (U8*)MMI_UMMS_XML_ELEMENT_VIDEO;
        }
        break;        

        default:
        {
            MMI_ASSERT(0);
        }
        break;
    }

    if (obj_type == MMI_UMMS_OBJECT_TYPE_TEXT)
    {
        memset(bg_color_str, 0, color_str_len);
        sprintf((char*)bg_color_str, "0x%06x", bg_color);
        attr_list[i++] = (U8*)MMI_UMMS_XML_ATTR_BGCOLOR;
        attr_list[i++] = bg_color_str;
        
        memset(fg_color_str, 0, color_str_len);
        sprintf((char*)fg_color_str, "0x%06x", fg_color);
        attr_list[i++] = (U8*)MMI_UMMS_XML_ATTR_FGCOLOR;
        attr_list[i++] = fg_color_str;

		memset(textstrStyle, 0, 5);
		sprintf((char*)textstrStyle, "%d", txt_style); 
		attr_list[i++] = (U8*)MMI_UMMS_XML_ATTR_TEXT_STYLE;
        attr_list[i++] = textstrStyle;

		memset(textstrSize, 0, 5);
		sprintf((char*)textstrSize, "%d", txt_size); 
		attr_list[i++] = (U8*)MMI_UMMS_XML_ATTR_TEXT_SIZE;
        attr_list[i++] = textstrSize;
 
    }

    memset(id_str, 0, str_len);
    sprintf((char*)id_str, "%d", id);
    attr_list[i++] = (U8*)MMI_UMMS_XML_ATTR_ID;
    attr_list[i++] = id_str;

    if (begin != MMI_UMMS_XML_INVALID_VALUE && end != MMI_UMMS_XML_INVALID_VALUE)
    {
        memset(start_str, 0, str_len);
        sprintf((char*)start_str, "%d", slide->text.begin);
        attr_list[i++] = (U8*)MMI_UMMS_XML_ATTR_BEGIN;
        attr_list[i++] = start_str;            

        memset(end_str, 0, str_len);
        sprintf((char*)end_str, "%d", slide->text.end);
        attr_list[i++] = (U8*)MMI_UMMS_XML_ATTR_END;
        attr_list[i++] = end_str;
    }
    
    attr_list[i] = NULL;

    MMI_ASSERT(i <= (attr_num * 2 + 1));

    if ((result = mmi_umms_create_xml_element_single(fh, obj_xml_type, attr_list)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
    {
        return result;
    }

    return FS_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_create_xml_element_single
 * DESCRIPTION
 *  Create the xml single element
 * PARAMETERS
 *  fh                  [IN]        
 *  element_name        [?]         
 *  attr_list           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_umms_create_xml_element_single(FS_HANDLE fh, U8* element_name, U8** attr_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* temp_str = (U8*) umms_malloc(MMI_UMMS_XML_TEMP_STR_LEN);
    S32 result = FS_NO_ERROR;
    U32 write_len = 0;
    U32 i = 0;
    U32 offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(temp_str,0,MMI_UMMS_XML_TEMP_STR_LEN);
    offset += sprintf((char*)temp_str, "%s%s", XML_TAG_ELEMENT_START, element_name);

    if (attr_list)
    {
        while (attr_list[i])
        {
            offset += sprintf((char*)(temp_str + offset), " %s=\"%s\"", attr_list[i], attr_list[i + 1]);
            i = i + 2;
        }
    }

    offset += sprintf((char*)(temp_str + offset), "%s", XML_TAG_SINGLE_END);

    MMI_ASSERT(offset < MMI_UMMS_XML_TEMP_STR_LEN);

    result = FS_Write(fh, temp_str, offset, &write_len);

    umms_free(temp_str);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_create_xml_object
 * DESCRIPTION
 *  Add data
 * PARAMETERS
 *  fh      [IN]        
 *  obj     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_umms_create_xml_object(FS_HANDLE fh, mmi_umms_object_struct* obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;    
    U16 str_len = 5; /* size of id, attach, vf, and drm */
    U16 byte_len = 10; /* size of size and offset */
    U16 attr_num = 7;   /* size of attr_list would be attr_num * 2 + 1 */
    U8 id[5];
    U8 attach[5];
    U8 vf[5];
    U8 drm[5];
    U8 encoding_scheme[5];
    U8 size[10];
    U8 offset[10];
    U8 *attr_list[7 * 2 + 1];
    U8 j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    memset(id, 0, str_len);
    sprintf((char*)id, "%d", obj->id);
    attr_list[j++] = (U8*)MMI_UMMS_XML_ATTR_ID;
    attr_list[j++] = id;

    memset(attach, 0, str_len);
    if (obj->type == MMI_UMMS_OBJECT_TYPE_ATTACHMENT)
    {
        sprintf((char*)attach, "%d", 1);
    }
    else
    {
        sprintf((char*)attach, "%d", 0);
    }    
    attr_list[j++] = (U8*)MMI_UMMS_XML_ATTR_ATTACH;
    attr_list[j++] = attach;

    memset(vf, 0, str_len);
    sprintf((char*)vf, "%d", obj->is_virtual_file);
    attr_list[j++] = (U8*)MMI_UMMS_XML_ATTR_VIRTUAL_FILE;
    attr_list[j++] = vf;

    memset(drm, 0, str_len);
    sprintf((char*)drm, "%d", obj->drm_type);
    attr_list[j++] = (U8*)MMI_UMMS_XML_ATTR_DRM;
    attr_list[j++] = drm;

    memset(size, 0, byte_len);
    sprintf((char*)size, "%d", obj->size);
    attr_list[j++] = (U8*)MMI_UMMS_XML_ATTR_SIZE;
    attr_list[j++] = size;

    memset(offset, 0, byte_len);
    sprintf((char*)offset, "%d", obj->offset);
    attr_list[j++] = (U8*)MMI_UMMS_XML_ATTR_OFFSET;
    attr_list[j++] = offset;

    memset(encoding_scheme, 0, str_len);
    sprintf((char*)encoding_scheme, "%d", obj->encoding_scheme);
    attr_list[j++] = (U8*) MMI_UMMS_XML_ATTR_ENCODING_SCHEME;
    attr_list[j++] = encoding_scheme;

    attr_list[j++] = NULL;

    MMI_ASSERT(j == (attr_num * 2 + 1));

    /* <obj> */
    if ((result = mmi_umms_create_xml_element_start(fh, (U8*)MMI_UMMS_XML_ELEMENT_OBJECT, attr_list)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
    {
        return result;
    }
    
    /* Mime */
    if (mmi_ucs2strlen((S8*) obj->mime_type))
    {
        if ((result = mmi_umms_create_xml_element_start(fh, (U8*) MMI_UMMS_XML_ELEMENT_MIME_TYPE, NULL)) != FS_NO_ERROR)
        {
            return result;
        }
        if ((result = mmi_umms_create_xml_data_usc2_to_utf8(fh, (U8*) obj->mime_type)) != FS_NO_ERROR)
        {
            return result;
        }
        if ((result = mmi_umms_create_xml_element_end(fh, (U8*) MMI_UMMS_XML_ELEMENT_MIME_TYPE)) != FS_NO_ERROR)
        {
            return result;
        }
        if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            return result;
        }
    }

    /* Content ID */
    if (mmi_ucs2strlen((S8*) obj->content_id))
    {
        if ((result = mmi_umms_create_xml_element_start(fh, (U8*) MMI_UMMS_XML_ELEMENT_CONTENT_ID, NULL)) != FS_NO_ERROR)
        {
            return result;
        }
        if ((result = mmi_umms_create_xml_data_usc2_to_utf8(fh, (U8*) obj->content_id)) != FS_NO_ERROR)
        {
            return result;
        }
        if ((result = mmi_umms_create_xml_element_end(fh, (U8*) MMI_UMMS_XML_ELEMENT_CONTENT_ID)) != FS_NO_ERROR)
        {
            return result;
        }
        if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            return result;
        }
    }

    /* Content Location */
    if (mmi_ucs2strlen((S8*) obj->content_location))
    {
        if ((result = mmi_umms_create_xml_element_start(fh, (U8*) MMI_UMMS_XML_ELEMENT_CONTENT_LOCATION, NULL)) != FS_NO_ERROR)
        {
            return result;
        }
        if ((result = mmi_umms_create_xml_data_usc2_to_utf8(fh, (U8*) obj->content_location)) != FS_NO_ERROR)
        {
            return result;
        }
        if ((result = mmi_umms_create_xml_element_end(fh, (U8*) MMI_UMMS_XML_ELEMENT_CONTENT_LOCATION)) != FS_NO_ERROR)
        {
            return result;
        }
        if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            return result;
        }
    }

    /* name */
    if ((result = mmi_umms_create_xml_element_start(fh, (U8*)MMI_UMMS_XML_ELEMENT_NAME, NULL)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = mmi_umms_create_xml_data_usc2_to_utf8(fh, (U8*)obj->file_name)) != FS_NO_ERROR)
    {
        return result;
    }                    
    if ((result = mmi_umms_create_xml_element_end(fh, (U8*)MMI_UMMS_XML_ELEMENT_NAME)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
    {
        return result;
    }
    
    /* file path */
    if ((result = mmi_umms_create_xml_element_start(fh, (U8*)MMI_UMMS_XML_ELEMENT_FILE_PATH, NULL)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = mmi_umms_create_xml_data_usc2_to_utf8(fh, (U8*)obj->file_path)) != FS_NO_ERROR)
    {
        return result;
    }                    
    if ((result = mmi_umms_create_xml_element_end(fh, (U8*)MMI_UMMS_XML_ELEMENT_FILE_PATH)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
    {
        return result;
    }
   
    /* </obj> */
    if ((result = mmi_umms_create_xml_element_end(fh, (U8*)MMI_UMMS_XML_ELEMENT_OBJECT)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = mmi_umms_create_xml_new_line(fh)) != FS_NO_ERROR)
    {
        return result;
    }

    return FS_NO_ERROR;
}

#endif /* __MMI_MMS_2__ */
#endif /* __MMI_MMSXMLENCODER_C */ 



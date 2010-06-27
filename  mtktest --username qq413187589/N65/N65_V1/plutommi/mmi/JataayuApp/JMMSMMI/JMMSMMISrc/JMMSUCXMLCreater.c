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
 *  JMMSUCXMLCreater.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for generating the xml from the structure for Jataayu UC integration.
 *
 * Author:
 * -------
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
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef __MMI_JMMSUCXMLCREATER_C
#define __MMI_JMMSUCXMLCREATER_C

/***************************************************************************** 
* Include
*****************************************************************************/
#if defined (JATAAYU_SUPPORT) && defined (MMS_SUPPORT) && defined (__UNIFIED_COMPOSER_SUPPORT__)
#include "SettingProfile.h"
#include "CommonScreens.h"
#include "wgui_inputs.h"
#include "JMMSStoreHandling.h"
#include "MainMenuDef.h"
#include "JMMSStoreHandling.h"
#include "JMMSConfig.h"
#include "JMMSMainMMS.h"
#include "JMMSUseDetails.h"
#include "JMMSDrafts.h"

#include <ddl.h>
#include <jcal.h>
#include <jcalnet.h>
#include "jdi_wspdatatype.h"
#include "jdi_transport.h"
#include "JMMSWriteMMS.h"
#include <MessagingDatatypes.h>
#include <MessagingAPI.h>

#include "JMMSExdcl.h"
#include "JMMSPushHandling.h"

#include "JMMSCompose.h"

#include <PrvMessagingDataTypes.h>
#include <MM1DataTypes.h>
#include <ComposeUtils.h>
#include "JMMSCoreAPI.h"
#include "JMMSResDef.h"
#include "JMMSMainMMS.h"
#include "JMMSProtocols.h"
#include "JMMSView.h"
#include "JMMSMessageSettingsUtils.h"
#include "xml_def.h"
#include "UnifiedComposerGProt.h"
#include "JMMSUCXMLProt.h"
#include "mmsadp.h"
#include "Conversions.h"
#include "app_base64.h"

#define MMI_JMMS_UC_XML_TEMP_STR_LEN (1024)
#define XML_INVALID_VALUE (0xFF)
#define JMMS_MEDIUM_NUMBER_STRING_LENGTH 5
#define JMMS_LARGE_NUMBER_STRING_LENGTH 10

static S32 mmi_jmms_uc_create_xml_element_start(FS_HANDLE fh, U8 *element_name_p, U8 **attr_list_p);
static S32 mmi_jmms_uc_create_xml_new_line(FS_HANDLE fh);
static S32 mmi_jmms_uc_create_xml_addr(FS_HANDLE fh, mmi_uc_address_group_type_enum type);
static S32 mmi_jmms_uc_create_xml_data_ucs2_to_utf8(FS_HANDLE fh, U8 *data);
static S32 mmi_jmms_uc_create_xml_element_end(FS_HANDLE fh, U8 *element_name_p);
static S32 mmi_jmms_uc_create_xml_data_numeric_to_char(FS_HANDLE fh, U32 value);
static S32 mmi_jmms_uc_create_xml_slide(FS_HANDLE fh, mmi_uc_slide_struct *slide_p);
static S32 mmi_jmms_uc_create_xml_object(FS_HANDLE fh, mmi_uc_object_struct *obj_p);
static S32 mmi_jmms_uc_create_xml_slide_object(
            FS_HANDLE fh,
            mmi_uc_slide_struct *slide_p,
            mmi_uc_object_type obj_type);
static S32 mmi_jmms_uc_create_xml_element_single(FS_HANDLE fh, U8 *element_name_p, U8 **attr_list_p);
static S32 mmi_jmms_uc_create_xml_data_ucs2_to_base64(FS_HANDLE fh, U8 *data);


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_create_mms_xml_description_file
 * DESCRIPTION
 *  Create the mms xml description file
 * PARAMETERS
 *  file_path_p     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
JC_RETCODE mmi_jmms_uc_create_mms_xml_description_file(U8 *file_path_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    FS_HANDLE fh;
    S32 result = FS_NO_ERROR;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Open the file to write, overwrite if already exists. */
    fh = FS_Open((U16*) file_path_p, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (fh > 0)
    {
        /* <mms> */
        if ((result = mmi_jmms_uc_create_xml_element_start(fh, (U8*) MMI_JMMS_UC_XML_ELEMENT_MMS, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }
        if ((result = mmi_jmms_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }

        /* <header> */
        if ((result = mmi_jmms_uc_create_xml_element_start(fh, (U8*) MMI_JMMS_UC_XML_ELEMENT_HEADER, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }
        if ((result = mmi_jmms_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }

        /* To address */
        if (g_jmms_context->uc_xml_msg_p->to_num)
        {
            if ((result = mmi_jmms_uc_create_xml_addr(fh, MMI_UC_ADDRESS_GROUP_TYPE_TO)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                goto END;
            }
        }

        /* Cc address */
        if (g_jmms_context->uc_xml_msg_p->cc_num)
        {
            if ((result = mmi_jmms_uc_create_xml_addr(fh, MMI_UC_ADDRESS_GROUP_TYPE_CC)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                goto END;
            }
        }

        /* Bcc address */
        if (g_jmms_context->uc_xml_msg_p->bcc_num)
        {
            if ((result = mmi_jmms_uc_create_xml_addr(fh, MMI_UC_ADDRESS_GROUP_TYPE_BCC)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                goto END;
            }
        }

        /* From address */
        if (g_jmms_context->uc_xml_msg_p->from)
        {
            if ((result = mmi_jmms_uc_create_xml_addr(fh, MMI_UC_ADDRESS_GROUP_TYPE_FROM)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                goto END;
            }
        }

        /* subject */
        if (mmi_ucs2strlen((S8*) g_jmms_context->uc_xml_msg_p->subject))
        {
            if ((result = mmi_jmms_uc_create_xml_element_start(fh, (U8*) MMI_JMMS_UC_XML_ELEMENT_SUBJECT, NULL)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                goto END;
            }
            if ((result = mmi_jmms_uc_create_xml_data_ucs2_to_base64(
                            fh,
                            (U8*) g_jmms_context->uc_xml_msg_p->subject)) !=
                FS_NO_ERROR)
            {
                FS_Close(fh);
                goto END;
            }
            if ((result = mmi_jmms_uc_create_xml_element_end(fh, (U8*) MMI_JMMS_UC_XML_ELEMENT_SUBJECT)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                goto END;
            }
            if ((result = mmi_jmms_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                goto END;
            }
        }

        /* Read Report */
        if ((result = mmi_jmms_uc_create_xml_element_start(fh, (U8*) MMI_JMMS_UC_XML_ELEMENT_READ_REPORT, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }
        if ((result = mmi_jmms_uc_create_xml_data_numeric_to_char(fh, g_jmms_context->uc_xml_msg_p->read_report)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }
        if ((result = mmi_jmms_uc_create_xml_element_end(fh, (U8*) MMI_JMMS_UC_XML_ELEMENT_READ_REPORT)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }
        if ((result = mmi_jmms_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }

        /* Delivery Report */
        if ((result = mmi_jmms_uc_create_xml_element_start(
                        fh,
                        (U8*) MMI_JMMS_UC_XML_ELEMENT_DELIVERY_REPORT,
                        NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }
        if ((result = mmi_jmms_uc_create_xml_data_numeric_to_char(
                        fh,
                        g_jmms_context->uc_xml_msg_p->delivery_report)) !=
            FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }
        if ((result = mmi_jmms_uc_create_xml_element_end(fh, (U8*) MMI_JMMS_UC_XML_ELEMENT_DELIVERY_REPORT)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }
        if ((result = mmi_jmms_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }

        /* Priority */
        if ((result = mmi_jmms_uc_create_xml_element_start(fh, (U8*) MMI_JMMS_UC_XML_ELEMENT_PRIORITY, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }
        if ((result = mmi_jmms_uc_create_xml_data_numeric_to_char(fh, g_jmms_context->uc_xml_msg_p->priority)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }
        if ((result = mmi_jmms_uc_create_xml_element_end(fh, (U8*) MMI_JMMS_UC_XML_ELEMENT_PRIORITY)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }
        if ((result = mmi_jmms_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }

        /* Expiry time */
        if ((result = mmi_jmms_uc_create_xml_element_start(fh, (U8*) MMI_JMMS_UC_XML_ELEMENT_EXPIRY, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }
        if ((result = mmi_jmms_uc_create_xml_data_numeric_to_char(fh, g_jmms_context->uc_xml_msg_p->expiry_time)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }
        if ((result = mmi_jmms_uc_create_xml_element_end(fh, (U8*) MMI_JMMS_UC_XML_ELEMENT_EXPIRY)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }
        if ((result = mmi_jmms_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }

        /* Delivery time */
        if ((result = mmi_jmms_uc_create_xml_element_start(
                        fh,
                        (U8*) MMI_JMMS_UC_XML_ELEMENT_DELIVERY_TIME,
                        NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }
        if ((result = mmi_jmms_uc_create_xml_data_numeric_to_char(
                        fh,
                        g_jmms_context->uc_xml_msg_p->delivery_time)) !=
            FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }
        if ((result = mmi_jmms_uc_create_xml_element_end(fh, (U8*) MMI_JMMS_UC_XML_ELEMENT_DELIVERY_TIME)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }
        if ((result = mmi_jmms_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }

        /* Sender visibility */
        if ((result = mmi_jmms_uc_create_xml_element_start(fh, (U8*) MMI_JMMS_UC_XML_ELEMENT_VISIBLE, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }
        if ((result = mmi_jmms_uc_create_xml_data_numeric_to_char(
                        fh,
                        g_jmms_context->uc_xml_msg_p->sender_visibility)) !=
            FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }
        if ((result = mmi_jmms_uc_create_xml_element_end(fh, (U8*) MMI_JMMS_UC_XML_ELEMENT_VISIBLE)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }
        if ((result = mmi_jmms_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }

        /* </header> */
        if ((result = mmi_jmms_uc_create_xml_element_end(fh, (U8*) MMI_JMMS_UC_XML_ELEMENT_HEADER)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }
        if ((result = mmi_jmms_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }

        /* <body> */
        {
            U16 color_str_len = JMMS_LARGE_NUMBER_STRING_LENGTH;        /* size of bg_color and fg_color */
            U16 str_len = JMMS_MEDIUM_NUMBER_STRING_LENGTH; /* size of slide_num, obj_num, and layout */
            U16 attr_num = 5;                               /* size of arrt_list would be attr_num * 2 + 1 */
            U8 bg_color[JMMS_LARGE_NUMBER_STRING_LENGTH];
            U8 fg_color[JMMS_LARGE_NUMBER_STRING_LENGTH];
            U8 slide_num[JMMS_MEDIUM_NUMBER_STRING_LENGTH];
            U8 obj_num[JMMS_MEDIUM_NUMBER_STRING_LENGTH];
            U8 layout[JMMS_MEDIUM_NUMBER_STRING_LENGTH];
            U8 *attr_list[5 * 2 + 1];
            U8 i = 0;

            memset(bg_color, 0, color_str_len);
            sprintf((char*)bg_color, "0x%06x", g_jmms_context->uc_xml_msg_p->background_color);
            attr_list[i++] = (U8*) MMI_JMMS_UC_XML_ATTR_BGCOLOR;
            attr_list[i++] = bg_color;

            memset(fg_color, 0, color_str_len);
            sprintf((char*)fg_color, "0x%06x", g_jmms_context->uc_xml_msg_p->foreground_color);
            attr_list[i++] = (U8*) MMI_JMMS_UC_XML_ATTR_FGCOLOR;
            attr_list[i++] = fg_color;

            /* If only attachments and one slide without any content, do not send slide info. */
            /* reference phone behavior */
            memset(slide_num, 0, str_len);
            sprintf((char*)slide_num, "%d", g_jmms_context->uc_xml_msg_p->total_slide_num);
            attr_list[i++] = (U8*) MMI_JMMS_UC_XML_ATTR_SLIDE_NUM;
            attr_list[i++] = slide_num;

            memset(obj_num, 0, str_len);
            sprintf((char*)obj_num, "%d", g_jmms_context->uc_xml_msg_p->total_object_num);
            attr_list[i++] = (U8*) MMI_JMMS_UC_XML_ATTR_OBJ_NUM;
            attr_list[i++] = obj_num;

            memset(layout, 0, str_len);
            sprintf(
                (char*)layout,
                "%d",
                g_jmms_context->uc_xml_msg_p->layout /* mmi_uc_convert_to_mms_layout_type(g_jmms_context->uc_xml_msg_p->layout) */ );
            attr_list[i++] = (U8*) MMI_JMMS_UC_XML_ATTR_LAYOUT;
            attr_list[i++] = layout;

            attr_list[i++] = NULL;

            MMI_ASSERT(i == (attr_num * 2 + 1));

            if ((result = mmi_jmms_uc_create_xml_element_start(
                            fh,
                            (U8*) MMI_JMMS_UC_XML_ELEMENT_BODY,
                            attr_list)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                goto END;
            }
            if ((result = mmi_jmms_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                goto END;
            }
        }
        if (g_jmms_context->uc_creation_mode != MMA_MODE_FORWARD && g_jmms_context->uc_creation_mode != MMA_MODE_SEND)
        {
            /* Slide */
            if (g_jmms_context->uc_xml_msg_p->total_slide_num)
            {
                mmi_uc_slide_struct *slide_p = g_jmms_context->uc_xml_msg_p->slide_head;
                U16 i = 0;

                while (i < g_jmms_context->uc_xml_msg_p->total_slide_num)
                {
                    MMI_ASSERT(slide_p);
                    if ((result = mmi_jmms_uc_create_xml_slide(fh, slide_p)) != FS_NO_ERROR)
                    {
                        FS_Close(fh);
                        goto END;
                    }
                    slide_p = slide_p->next;
                    i++;
                }
            }
        }
        /* Object */
        if (g_jmms_context->uc_xml_msg_p->total_object_num)
        {
            mmi_uc_object_struct *object_p = g_jmms_context->uc_xml_msg_p->object_head;
            U16 i = 0;

            if (g_jmms_context->uc_creation_mode == MMA_MODE_FORWARD ||
                g_jmms_context->uc_creation_mode == MMA_MODE_SEND)
            {
                i = g_jmms_context->uc_xml_msg_p->total_object_num - g_jmms_context->uc_xml_msg_p->total_attachment_num;
            }
            while (i < g_jmms_context->uc_xml_msg_p->total_object_num)
            {
                MMI_ASSERT(object_p);
                if (g_jmms_context->uc_creation_mode == MMA_MODE_FORWARD ||
                    g_jmms_context->uc_creation_mode == MMA_MODE_SEND)
                {

                    if (object_p->type == MMI_UC_OBJECT_TYPE_ATTACHMENT)
                    {
                        if ((result = mmi_jmms_uc_create_xml_object(fh, object_p)) != FS_NO_ERROR)
                        {
                            FS_Close(fh);
                            goto END;
                        }
                    }
                    object_p = object_p->next;
                    i++;
                }
                else
                {
                    if ((result = mmi_jmms_uc_create_xml_object(fh, object_p)) != FS_NO_ERROR)
                    {
                        FS_Close(fh);
                        goto END;
                    }
                    object_p = object_p->next;
                    i++;
                }
            }
        }

        /* </body> */
        if ((result = mmi_jmms_uc_create_xml_element_end(fh, (U8*) MMI_JMMS_UC_XML_ELEMENT_BODY)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }
        if ((result = mmi_jmms_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }

        /* </mms> */
        if ((result = mmi_jmms_uc_create_xml_element_end(fh, (U8*) MMI_JMMS_UC_XML_ELEMENT_MMS)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }
        if ((result = mmi_jmms_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            goto END;
        }

        FS_Close(fh);
        return JC_OK;
    }
    else
    {
        ret_code = JC_ERR_FILE_OPEN;
        return ret_code;
    }
  END:
    ret_code = JC_ERR_FILE_WRITE;
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_create_xml_element_start
 * DESCRIPTION
 *  Create the xml start element
 * PARAMETERS
 *  fh                  [IN]        
 *  element_name_p      [IN]         
 *  attr_list           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_jmms_uc_create_xml_element_start(FS_HANDLE fh, U8 *element_name_p, U8 **attr_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *temp_str_p = jdd_MemAlloc(MMI_JMMS_UC_XML_TEMP_STR_LEN, 1);
    S32 result = FS_NO_ERROR;
    U32 write_len = 0;
    U32 i = 0;
    U32 offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(temp_str_p, 0, MMI_JMMS_UC_XML_TEMP_STR_LEN);
    offset += sprintf((char*)temp_str_p, "%s%s", XML_TAG_ELEMENT_START, element_name_p);

    if (attr_list)
    {
        while (attr_list[i])
        {
            offset += sprintf((char*)temp_str_p + offset, " %s=\"%s\"", attr_list[i], attr_list[i + 1]);
            i = i + 2;
        }
    }

    offset += sprintf((char*)(temp_str_p + offset), "%s", XML_TAG_GENERAL_END);

    MMI_ASSERT(offset < MMI_JMMS_UC_XML_TEMP_STR_LEN);

    result = FS_Write(fh, temp_str_p, offset, &write_len);

    jdd_MemFree(temp_str_p);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_create_xml_element_end
 * DESCRIPTION
 *  Create the xml end element
 * PARAMETERS
 *  fh                  [IN]        
 *  element_name_p      [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_jmms_uc_create_xml_element_end(FS_HANDLE fh, U8 *element_name_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *temp_str_p = jdd_MemAlloc(MMI_JMMS_UC_XML_TEMP_STR_LEN, 1);
    S32 result = FS_NO_ERROR;
    U32 write_len = 0;
    U32 offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(temp_str_p, 0, MMI_JMMS_UC_XML_TEMP_STR_LEN);
    offset += sprintf((char*)temp_str_p, "%s%s%s", XML_TAG_ELEMENT_END, element_name_p, XML_TAG_GENERAL_END);

    MMI_ASSERT(offset < MMI_JMMS_UC_XML_TEMP_STR_LEN);

    result = FS_Write(fh, temp_str_p, offset, &write_len);

    jdd_MemFree(temp_str_p);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_create_xml_new_line
 * DESCRIPTION
 *  Insert new line
 * PARAMETERS
 *  fh      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_jmms_uc_create_xml_new_line(FS_HANDLE fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *temp_str_p = jdd_MemAlloc(MMI_JMMS_UC_XML_TEMP_STR_LEN, 1);
    S32 result = FS_NO_ERROR;
    U32 write_len = 0;
    U32 offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(temp_str_p, 0, MMI_JMMS_UC_XML_TEMP_STR_LEN);
    offset += sprintf((char*)temp_str_p, "\n");

    result = FS_Write(fh, temp_str_p, offset, &write_len);

    jdd_MemFree(temp_str_p);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_create_xml_data
 * DESCRIPTION
 *  Add data
 * PARAMETERS
 *  fh          [IN]        
 *  data        [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_jmms_uc_create_xml_data(FS_HANDLE fh, U8 *data)
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
 *  mmi_jmms_uc_create_xml_data_ucs2_to_utf8
 * DESCRIPTION
 *  Add data
 * PARAMETERS
 *  fh          [IN]        
 *  data        [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_jmms_uc_create_xml_data_ucs2_to_utf8(FS_HANDLE fh, U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *utf8_data_p;
    U32 utf8_data_len = mmi_ucs2strlen((S8*) data) * 3 + 1;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    utf8_data_p = jdd_MemAlloc(utf8_data_len, 1);
    memset(utf8_data_p, 0, utf8_data_len);

    mmi_chset_ucs2_to_utf8_string((kal_uint8*) utf8_data_p, utf8_data_len, (kal_uint8*) data);

    result = mmi_jmms_uc_create_xml_data(fh, utf8_data_p);

    jdd_MemFree(utf8_data_p);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_create_xml_data_numeric_to_char
 * DESCRIPTION
 *  Add numeric data
 * PARAMETERS
 *  fh          [IN]        
 *  value       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_jmms_uc_create_xml_data_numeric_to_char(FS_HANDLE fh, U32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *data;
    U32 data_len = JMMS_LARGE_NUMBER_STRING_LENGTH;
    S32 result;
    U32 offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = jdd_MemAlloc(data_len, 1);
    memset(data, 0, data_len);

    offset += sprintf((char*)data, "%d", value);

    result = mmi_jmms_uc_create_xml_data(fh, data);

    jdd_MemFree(data);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_create_xml_addr
 * DESCRIPTION
 *  Add data
 * PARAMETERS
 *  fh          [IN]        
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_jmms_uc_create_xml_addr(FS_HANDLE fh, mmi_uc_address_group_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    U32 i = 0;
    mmi_uc_addr_struct *addr = NULL;
    U8 *attr_list[3];
    U8 *xml_addr_type = NULL;
    U32 total = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MMI_UC_ADDRESS_GROUP_TYPE_TO:
        {
            addr = g_jmms_context->uc_xml_msg_p->to_head;
            total = g_jmms_context->uc_xml_msg_p->to_num;
            xml_addr_type = (U8*) MMI_JMMS_UC_XML_ELEMENT_TO;
        }
            break;

        case MMI_UC_ADDRESS_GROUP_TYPE_CC:
        {
            addr = g_jmms_context->uc_xml_msg_p->cc_head;
            total = g_jmms_context->uc_xml_msg_p->cc_num;
            xml_addr_type = (U8*) MMI_JMMS_UC_XML_ELEMENT_CC;
        }
            break;

        case MMI_UC_ADDRESS_GROUP_TYPE_BCC:
        {
            addr = g_jmms_context->uc_xml_msg_p->bcc_head;
            total = g_jmms_context->uc_xml_msg_p->bcc_num;
            xml_addr_type = (U8*) MMI_JMMS_UC_XML_ELEMENT_BCC;
        }
            break;

        case MMI_UC_ADDRESS_GROUP_TYPE_FROM:
        {
            addr = g_jmms_context->uc_xml_msg_p->from;
            total = 1;
            xml_addr_type = (U8*) MMI_JMMS_UC_XML_ELEMENT_FROM;
        }
            break;

        default:
        {
            MMI_ASSERT(0);
        }
            break;
    }

    attr_list[0] = (U8*) MMI_JMMS_UC_XML_ATTR_TYPE;
    attr_list[2] = NULL;
    while (i < total)
    {
        MMI_ASSERT(addr);

        if (addr->type == MMI_UC_ADDRESS_TYPE_PHONE_NUMBER)
        {
            attr_list[1] = (U8*) MMI_JMMS_UC_XML_ATTR_POHNE_NUMBER;
            if ((result = mmi_jmms_uc_create_xml_element_start(fh, xml_addr_type, attr_list)) != FS_NO_ERROR)
            {
                return result;
            }

            if ((result = mmi_jmms_uc_create_xml_data(fh, addr->addr)) != FS_NO_ERROR)
            {
                return result;
            }
        }
        else if (addr->type == MMI_UC_ADDRESS_TYPE_EMAIL)
        {
            attr_list[1] = (U8*) MMI_JMMS_UC_XML_ATTR_EMAIL_ADDR;

            if ((result = mmi_jmms_uc_create_xml_element_start(fh, xml_addr_type, attr_list)) != FS_NO_ERROR)
            {
                return result;
            }
            if ((result = mmi_jmms_uc_create_xml_data_ucs2_to_utf8(fh, addr->addr)) != FS_NO_ERROR)
            {
                return result;
            }
        }
        else
        {
            MMI_ASSERT(0);
        }

        if ((result = mmi_jmms_uc_create_xml_element_end(fh, xml_addr_type)) != FS_NO_ERROR)
        {
            return result;
        }
        if ((result = mmi_jmms_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
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
 *  mmi_jmms_uc_create_xml_slide
 * DESCRIPTION
 *  Add data
 * PARAMETERS
 *  fh          [IN]        
 *  slide_p     [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_jmms_uc_create_xml_slide(FS_HANDLE fh, mmi_uc_slide_struct *slide_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    U16 str_len = JMMS_MEDIUM_NUMBER_STRING_LENGTH; /* size of index and duration */
    U16 attr_num = 2;                               /* size of attr_list would be attr_num * 2 + 1 */
    U8 index[JMMS_MEDIUM_NUMBER_STRING_LENGTH];
    U8 duration[JMMS_MEDIUM_NUMBER_STRING_LENGTH];
    U8 *attr_list[2 * 2 + 1];
    U8 j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(slide_p);

    memset(index, 0, str_len);
    sprintf((char*)index, "%d", (slide_p->slide_num));
    attr_list[j++] = (U8*) MMI_JMMS_UC_XML_ATTR_INDEX;
    attr_list[j++] = index;

    memset(duration, 0, str_len);
    sprintf((char*)duration, "%d", slide_p->duration);
    attr_list[j++] = (U8*) MMI_JMMS_UC_XML_ATTR_DURATION;
    attr_list[j++] = duration;

    attr_list[j++] = NULL;

    MMI_ASSERT(j == (attr_num * 2 + 1));

    if ((result = mmi_jmms_uc_create_xml_element_start(fh, (U8*) MMI_JMMS_UC_XML_ELEMENT_SLIDE, attr_list)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = mmi_jmms_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
    {
        return result;
    }
    /* text */
    if (slide_p->text.object)
    {
        if ((result = mmi_jmms_uc_create_xml_slide_object(fh, slide_p, MMI_UC_OBJECT_TYPE_TEXT)) != FS_NO_ERROR)
        {
            return result;
        }
    }
    /* image */
    if (slide_p->image.object)
    {
        if ((result = mmi_jmms_uc_create_xml_slide_object(fh, slide_p, MMI_UC_OBJECT_TYPE_IMAGE)) != FS_NO_ERROR)
        {
            return result;
        }
    }
    /* audio */
    if (slide_p->audio.object)
    {
        if ((result = mmi_jmms_uc_create_xml_slide_object(fh, slide_p, MMI_UC_OBJECT_TYPE_AUDIO)) != FS_NO_ERROR)
        {
            return result;
        }
    }
    /* video */
    if (slide_p->video.object)
    {
        if ((result = mmi_jmms_uc_create_xml_slide_object(fh, slide_p, MMI_UC_OBJECT_TYPE_VIDEO)) != FS_NO_ERROR)
        {
            return result;
        }
    }

    if ((result = mmi_jmms_uc_create_xml_element_end(fh, (U8*) MMI_JMMS_UC_XML_ELEMENT_SLIDE)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = mmi_jmms_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
    {
        return result;
    }

    return FS_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_create_xml_slide_object
 * DESCRIPTION
 *  Add data
 * PARAMETERS
 *  fh              [IN]        
 *  slide_p         [IN]         
 *  obj_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_jmms_uc_create_xml_slide_object(FS_HANDLE fh, mmi_uc_slide_struct *slide_p, mmi_uc_object_type obj_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    U32 bg_color = 0;
    U32 fg_color = 0;
    U16 color_str_len = JMMS_LARGE_NUMBER_STRING_LENGTH;    /* size of bg_color_str and fg_color_str */
    U16 str_len = JMMS_MEDIUM_NUMBER_STRING_LENGTH;         /* size of id_str , start_str, and end_str */
    U16 attr_num = 7;                                       /* size of attr_list would be attr_num * 2 + 1 */
    U32 id = 0;
    U8 bg_color_str[JMMS_LARGE_NUMBER_STRING_LENGTH];
    U8 fg_color_str[JMMS_LARGE_NUMBER_STRING_LENGTH];
    U8 id_str[JMMS_MEDIUM_NUMBER_STRING_LENGTH];
    U8 start_str[JMMS_MEDIUM_NUMBER_STRING_LENGTH];
    U8 end_str[JMMS_MEDIUM_NUMBER_STRING_LENGTH];
    U8 *attr_list[7 * 2 + 1];
    U8 i = 0;
    U8 begin = 0;
    U8 end = 0;
    U8 *obj_xml_type = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(slide_p);

    switch (obj_type)
    {
        case MMI_UC_OBJECT_TYPE_TEXT:
        {
            MMI_ASSERT(slide_p->text.object);
            fg_color = slide_p->text.foreground_color;
            bg_color = slide_p->text.background_color;
            id = slide_p->text.object->id;
            begin = slide_p->text.begin;
            end = slide_p->text.end;
            obj_xml_type = (U8*) MMI_JMMS_UC_XML_ELEMENT_TEXT;
        }
            break;

        case MMI_UC_OBJECT_TYPE_IMAGE:
        {
            MMI_ASSERT(slide_p->image.object);
            id = slide_p->image.object->id;
            begin = slide_p->image.begin;
            end = slide_p->image.end;
            obj_xml_type = (U8*) MMI_JMMS_UC_XML_ELEMENT_IMAGE;
        }
            break;

        case MMI_UC_OBJECT_TYPE_AUDIO:
        {
            MMI_ASSERT(slide_p->audio.object);
            id = slide_p->audio.object->id;
            begin = slide_p->audio.begin;
            end = slide_p->audio.end;
            obj_xml_type = (U8*) MMI_JMMS_UC_XML_ELEMENT_AUDIO;
        }
            break;

        case MMI_UC_OBJECT_TYPE_VIDEO:
        {
            MMI_ASSERT(slide_p->video.object);
            id = slide_p->video.object->id;
            begin = slide_p->video.begin;
            end = slide_p->video.end;
            obj_xml_type = (U8*) MMI_JMMS_UC_XML_ELEMENT_VIDEO;
        }
            break;

        default:
        {
            MMI_ASSERT(0);
        }
            break;
    }

    if (obj_type == MMI_UC_OBJECT_TYPE_TEXT)
    {
        memset(bg_color_str, 0, color_str_len);
        sprintf((char*)bg_color_str, "0x%06x", bg_color);
        attr_list[i++] = (U8*) MMI_JMMS_UC_XML_ATTR_BGCOLOR;
        attr_list[i++] = bg_color_str;

        memset(fg_color_str, 0, color_str_len);
        sprintf((char*)fg_color_str, "0x%06x", fg_color);
        attr_list[i++] = (U8*) MMI_JMMS_UC_XML_ATTR_FGCOLOR;
        attr_list[i++] = fg_color_str;
    }

    memset(id_str, 0, str_len);
    sprintf((char*)id_str, "%d", id);
    attr_list[i++] = (U8*) MMI_JMMS_UC_XML_ATTR_ID;
    attr_list[i++] = id_str;

    if (begin != XML_INVALID_VALUE && end != XML_INVALID_VALUE)
    {
        memset(start_str, 0, str_len);
        sprintf((char*)start_str, "%d", slide_p->text.begin);
        attr_list[i++] = (U8*) MMI_JMMS_UC_XML_ATTR_BEGIN;
        attr_list[i++] = start_str;

        memset(end_str, 0, str_len);
        sprintf((char*)end_str, "%d", slide_p->text.end);
        attr_list[i++] = (U8*) MMI_JMMS_UC_XML_ATTR_END;
        attr_list[i++] = end_str;
    }

    attr_list[i] = NULL;

    MMI_ASSERT(i <= (attr_num * 2 + 1));

    if ((result = mmi_jmms_uc_create_xml_element_single(fh, obj_xml_type, attr_list)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = mmi_jmms_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
    {
        return result;
    }

    return FS_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_create_xml_element_single
 * DESCRIPTION
 *  Create the xml single element
 * PARAMETERS
 *  fh                  [IN]        
 *  element_name_p      [IN]         
 *  attr_list           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_jmms_uc_create_xml_element_single(FS_HANDLE fh, U8 *element_name_p, U8 **attr_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *temp_str_p = jdd_MemAlloc(MMI_JMMS_UC_XML_TEMP_STR_LEN, 1);
    S32 result = FS_NO_ERROR;
    U32 write_len = 0;
    U32 i = 0;
    U32 offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(temp_str_p, 0, MMI_JMMS_UC_XML_TEMP_STR_LEN);
    offset += sprintf((char*)temp_str_p, "%s%s", XML_TAG_ELEMENT_START, element_name_p);

    if (attr_list)
    {
        while (attr_list[i])
        {
            offset += sprintf((char*)(temp_str_p + offset), " %s=\"%s\"", attr_list[i], attr_list[i + 1]);
            i = i + 2;
        }
    }

    offset += sprintf((char*)(temp_str_p + offset), "%s", XML_TAG_SINGLE_END);

    MMI_ASSERT(offset < MMI_JMMS_UC_XML_TEMP_STR_LEN);

    result = FS_Write(fh, temp_str_p, offset, &write_len);

    jdd_MemFree(temp_str_p);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_create_xml_object
 * DESCRIPTION
 *  Add data
 * PARAMETERS
 *  fh          [IN]        
 *  obj_p       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_jmms_uc_create_xml_object(FS_HANDLE fh, mmi_uc_object_struct *obj_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    U16 str_len = JMMS_MEDIUM_NUMBER_STRING_LENGTH; /* size of id, attach, vf, and drm */
    U16 byte_len = JMMS_LARGE_NUMBER_STRING_LENGTH; /* size of size and offset */
    U16 attr_num = 6;                               /* size of attr_list would be attr_num * 2 + 1 */
    U8 id[JMMS_MEDIUM_NUMBER_STRING_LENGTH];
    U8 attach[JMMS_MEDIUM_NUMBER_STRING_LENGTH];
    U8 vf[JMMS_MEDIUM_NUMBER_STRING_LENGTH];
    U8 drm[JMMS_MEDIUM_NUMBER_STRING_LENGTH];
    U8 size[JMMS_LARGE_NUMBER_STRING_LENGTH];
    U8 offset[JMMS_LARGE_NUMBER_STRING_LENGTH];
    U8 *attr_list[6 * 2 + 1];
    U8 j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj_p);

    memset(id, 0, str_len);
    sprintf((char*)id, "%d", obj_p->id);
    attr_list[j++] = (U8*) MMI_JMMS_UC_XML_ATTR_ID;
    attr_list[j++] = id;

    memset(attach, 0, str_len);
    if (obj_p->type == MMI_UC_OBJECT_TYPE_ATTACHMENT)
    {
        sprintf((char*)attach, "%d", 1);
    }
    else
    {
        sprintf((char*)attach, "%d", 0);
    }
    attr_list[j++] = (U8*) MMI_JMMS_UC_XML_ATTR_ATTACH;
    attr_list[j++] = attach;

    memset(vf, 0, str_len);
    sprintf((char*)vf, "%d", obj_p->is_virtual_file);
    attr_list[j++] = (U8*) MMI_JMMS_UC_XML_ATTR_VIRTUAL_FILE;
    attr_list[j++] = vf;

    memset(drm, 0, str_len);
    sprintf((char*)drm, "%d", obj_p->drm_type);
    attr_list[j++] = (U8*) MMI_JMMS_UC_XML_ATTR_DRM;
    attr_list[j++] = drm;

    memset(size, 0, byte_len);
    sprintf((char*)size, "%d", obj_p->size);
    attr_list[j++] = (U8*) MMI_JMMS_UC_XML_ATTR_SIZE;
    attr_list[j++] = size;

    memset(offset, 0, byte_len);
    sprintf((char*)offset, "%d", obj_p->offset);
    attr_list[j++] = (U8*) MMI_JMMS_UC_XML_ATTR_OFFSET;
    attr_list[j++] = offset;

    attr_list[j++] = NULL;

    MMI_ASSERT(j == (attr_num * 2 + 1));

    /* <obj> */
    if ((result = mmi_jmms_uc_create_xml_element_start(fh, (U8*) MMI_JMMS_UC_XML_ELEMENT_OBJECT, attr_list)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = mmi_jmms_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
    {
        return result;
    }

    /* name */
    if ((result = mmi_jmms_uc_create_xml_element_start(fh, (U8*) MMI_JMMS_UC_XML_ELEMENT_NAME, NULL)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = mmi_jmms_uc_create_xml_data_ucs2_to_utf8(fh, (U8*) obj_p->file_name)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = mmi_jmms_uc_create_xml_element_end(fh, (U8*) MMI_JMMS_UC_XML_ELEMENT_NAME)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = mmi_jmms_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
    {
        return result;
    }

    /* file path */
    if ((result = mmi_jmms_uc_create_xml_element_start(fh, (U8*) MMI_JMMS_UC_XML_ELEMENT_FILE_PATH, NULL)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = mmi_jmms_uc_create_xml_data_ucs2_to_utf8(fh, (U8*) obj_p->file_path)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = mmi_jmms_uc_create_xml_element_end(fh, (U8*) MMI_JMMS_UC_XML_ELEMENT_FILE_PATH)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = mmi_jmms_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
    {
        return result;
    }

    /* </obj> */
    if ((result = mmi_jmms_uc_create_xml_element_end(fh, (U8*) MMI_JMMS_UC_XML_ELEMENT_OBJECT)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = mmi_jmms_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
    {
        return result;
    }

    return FS_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_create_xml_data_ucs2_to_base64
 * DESCRIPTION
 *  Add data
 * PARAMETERS
 *  fh          [IN]        
 *  data        [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_jmms_uc_create_xml_data_ucs2_to_base64(FS_HANDLE fh, U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *utf8_data;
    U8 *base64_data;
    U32 utf8_data_actual_len = 0;
    U32 utf8_data_len = mmi_ucs2strlen((S8*) data) * 3 + 1;
    U32 base64_length = 0;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    utf8_data = jdd_MemAlloc(utf8_data_len, 1);
    memset(utf8_data, 0, utf8_data_len);

    utf8_data_actual_len = mmi_chset_ucs2_to_utf8_string((kal_uint8*) utf8_data, utf8_data_len, (kal_uint8*) data);

    base64_length = (utf8_data_actual_len) * 3;
    /* base64_length = applib_base64_encode_len(utf8_data_actual_len); */
    base64_data = jdd_MemAlloc(base64_length + 1, 1);
    memset(base64_data, 0, base64_length + 1);

    applib_base64_encode((S8*) utf8_data, utf8_data_actual_len, (S8*) base64_data, base64_length);

    result = mmi_jmms_uc_create_xml_data(fh, base64_data);

    jdd_MemFree(utf8_data);
    jdd_MemFree(base64_data);

    return result;
}

#else /* defined (JATAAYU_SUPPORT) && defined (MMS_SUPPORT) && defined (__UNIFIED_COMPOSER_SUPPORT__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_dummy_uc_xml_creater_fun
 * DESCRIPTION
 *  Just to remove warning
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_dummy_uc_xml_creater_fun(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* dummy */
}
#endif /* defined (JATAAYU_SUPPORT) && defined (MMS_SUPPORT) && defined (__UNIFIED_COMPOSER_SUPPORT__) */ 
#endif /* __MMI_JMMSUCXMLCREATER_C */ 


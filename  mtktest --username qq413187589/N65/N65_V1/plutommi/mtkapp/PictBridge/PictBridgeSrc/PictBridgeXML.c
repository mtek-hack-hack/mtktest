/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *    PictBridgeXML.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for PictBridge appliction.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "MMI_include.h"

#ifdef __MMI_PICT_BRIDGE_SUPPORT__


#include "XML_def.h"

#include "stdlib.h"
#ifdef MMI_ON_HARDWARE_P
#include "Init.h"
#endif

#include "FileManagerGProt.h"
#include "wgui_status_icons.h"

#include "PictBridgeDef.h"
#include "PictBridgeProt.h"
#include "PictBridgeGProt.h"
#include "PictBridgeStruct.h"
#include "PictBridgeXML.h"


/*
 * External Function
 */
extern PS8 Serial_num(void);


/*
 * Global Variable
 */
extern pict_bridge_context_struct g_pict_bridge_context;
extern pict_bridge_setting_struct g_pict_bridge_setting;


/*
 * Local Variable
 */
pict_bridge_xml_struct g_pict_bridge_xml;

const S8* pict_xml_table[] =
{
    "dps",
    "input",
    "output",
    "result",

    "configurePrintService",
    "dpsVersions",
    "vendorName",
    "vendorSpecificVersion",
    "productName",
    "serialNo",
    "printServiceAvailable",

    "getCapability",
    "capability",
    "qualities",
    "paperSizes",
    "paperTypes",
    "fileTypes",
    "datePrints",
    "fileNamePrints",
    "imageOptimizes",
    "layouts",
    "fixedSizes",
    "croppings",

    "startJob",
    "abortJob",
    "continueJob",

    "notifyJobStatus",
    "progress",
    "imagesPrinted",

    "notifyDeviceStatus",
    "dpsPrintServiceStatus",
    "jobEndReason",
    "errorStatus",
    "errorReason",
    "disconnectEnable",
    "capabilityChanged",
    "newJobOK",

    NULL
};


#ifndef __MTK_TARGET__
/*****************************************************************************
 * FUNCTION
 *  mmi_pict_xml_init
 * DESCRIPTION
 *  PictBridge initialization function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_xml_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pict_bridge_xml.paper_sizes = PICT_PAPER_DEFAULT | PICT_PAPER_4x6;
    g_pict_bridge_xml.date_prints = PICT_CAPABILITY_DEFAULT | PICT_CAPABILITY_OFF | PICT_CAPABILITY_ON;
    g_pict_bridge_xml.filename_prints = PICT_CAPABILITY_DEFAULT | PICT_CAPABILITY_OFF | PICT_CAPABILITY_ON;
    g_pict_bridge_xml.croppings = PICT_CAPABILITY_DEFAULT | PICT_CAPABILITY_OFF | PICT_CAPABILITY_ON;
}
#endif /* __MTK_TARGET__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_read_xml_start_element
 * DESCRIPTION
 *  XML start element callback for XML parser
 * PARAMETERS
 *  data            [IN]      Reserved
 *  el              [IN]      Element
 *  attr            [IN]      Attributes
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pict_read_xml_start_element(void *data, const char *el, const char **attr, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U32 xml_attr_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < PICT_XML_TAG_MAX; i++)
    {
        if (strcmp(pict_xml_table[i], el) != 0)
        {
            continue;
        }

        switch(i)
        {
            case PICT_XML_TAG_PRINT_CONFIGURE:
                /* reset necessary fields of GET CAPABILITY for next operation */
                g_pict_bridge_xml.qualities = 0;
                g_pict_bridge_xml.paper_sizes = 0;
                g_pict_bridge_xml.file_types = 0;
                g_pict_bridge_xml.date_prints = 0;
                g_pict_bridge_xml.filename_prints = 0;
                g_pict_bridge_xml.image_optimizes = 0;
                g_pict_bridge_xml.croppings = 0;
                break;

            case PICT_XML_TAG_PAPER_TYPES:
            case PICT_XML_TAG_LAYOUTS:
                if (strcmp(*attr, PICT_XML_ATTR_PAPER_SIZE) == 0)
                {
                    xml_attr_value = (U32) atoi(*(attr + 1));
                    if (xml_attr_value == PICT_XML_VAL_PAPER_DEFAULT)
                    {
                        g_pict_bridge_xml.xml_attr = 0; //PICT_PAPER_DEFAULT;
                    }
                    else if (xml_attr_value == PICT_XML_VAL_PAPER_POSTCARD)
                    {
                        g_pict_bridge_xml.xml_attr = 1; //PICT_PAPER_POSTCARD;
                    }
                    else if (xml_attr_value == PICT_XML_VAL_PAPER_4X6)
                    {
                        g_pict_bridge_xml.xml_attr = 2; //PICT_PAPER_4x6;
                    }
                    else if (xml_attr_value == PICT_XML_VAL_PAPER_LETTER)
                    {
                        g_pict_bridge_xml.xml_attr = 3; //PICT_PAPER_LETTER;
                    }
                    else if (xml_attr_value == PICT_XML_VAL_PAPER_A4)
                    {
                        g_pict_bridge_xml.xml_attr = 4; //PICT_PAPER_A4;
                    }
                    else
                    {
                        g_pict_bridge_xml.xml_attr = 5; //PICT_PAPER_MAX; /* not supported paper by phone */
                    }
                }
                break;

            default:
                break;
        }

        break; /* for loop */
    }

#ifdef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__
    if (i == PICT_XML_TAG_MAX)
    {
        xml_stop_parse(g_pict_bridge_context.parser);
        g_pict_bridge_context.next_event_request = mmi_pict_prepare_xml_return_error;
    }
#endif /* __MMI_PICT_BRIDGE_COMPLIANCE_TEST__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_read_xml_end_element
 * DESCRIPTION
 *  XML end element callback for XML parser
 * PARAMETERS
 *  data            [IN]      Reserved
 *  el              [IN]      Element
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pict_read_xml_end_element(void *data, const char *el, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < PICT_XML_TAG_MAX; i++)
    {
        if (strcmp(pict_xml_table[i], el) != 0)
        {
            continue;
        }

        switch(i)
        {
            case PICT_XML_TAG_PRINT_CONFIGURE:
                g_pict_bridge_context.next_operation_request = mmi_pict_prepare_xml_get_capability;
                g_pict_bridge_context.xml_capability_index = PICT_XML_TAG_QUALITIES;
                break;

            case PICT_XML_TAG_GET_CAPABILITY:
                if (g_pict_bridge_context.xml_capability_index == PICT_XML_TAG_CROPPINGS + 1)
                {
                    /* finish all capability values */
                    g_pict_bridge_context.next_operation_request = NULL;
                }
                break;

            case PICT_XML_TAG_ABORT_JOB:
                if (g_pict_bridge_context.printing != PICT_PRINTING_NONE)
                {
                    mmi_pict_entry_print_done(MMI_TRUE, 0);
                }
            case PICT_XML_TAG_START_JOB:
            case PICT_XML_TAG_CONTINUE_JOB:
                g_pict_bridge_context.next_operation_request = NULL;
                break;

            case PICT_XML_TAG_NOTIFY_JOB:
                g_pict_bridge_context.next_event_request = mmi_pict_prepare_xml_notify_job_result;
                break;

            case PICT_XML_TAG_NOTIFY_DEVICE:
            #ifdef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__
                mmi_pict_exec_notify_device_status_cmd();
            #endif
                g_pict_bridge_context.next_event_request = mmi_pict_prepare_xml_notify_device_result;
                break;

            default:
                break;
        }

        break; /* for loop */
    }

#ifdef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__
    if (i == PICT_XML_TAG_MAX)
    {
        xml_stop_parse(g_pict_bridge_context.parser);
        g_pict_bridge_context.next_event_request = mmi_pict_prepare_xml_return_error;
    }
#endif /* __MMI_PICT_BRIDGE_COMPLIANCE_TEST__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_read_xml_data_element
 * DESCRIPTION
 *  XML data element callback for XML parser
 * PARAMETERS
 *  data            [IN]      Reserved
 *  el              [IN]      Element
 *  value           [IN]      Value
 *  len             [IN]      Value length
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pict_read_xml_data_element(void *data, const char *el, const char *value, kal_int32 len, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    U8 xml_max_length;
    U8 xml_data_count = 0;
    U32 xml_data_value;
#ifdef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__
    MMI_BOOL xml_data_valid = MMI_TRUE;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < PICT_XML_TAG_MAX; i++)
    {
        if (strcmp(pict_xml_table[i], el) != 0)
        {
            continue;
        }

        xml_data_count = (len == PICT_VALUE_LEN) ? 1 : ((len + 1) / (PICT_VALUE_LEN + 1));

        switch(i)
        {
            case PICT_XML_TAG_DPS:
            case PICT_XML_TAG_INPUT:
            case PICT_XML_TAG_OUTPUT:
                break;

            case PICT_XML_TAG_RESULT:
                g_pict_bridge_xml.xml_result = (U32) atoi(value);

                /* IOT: HP cannot support all capabilities */
                if (g_pict_bridge_xml.xml_result != PICT_XML_VAL_OK)
                {
                    if (g_pict_bridge_context.next_operation_request == mmi_pict_prepare_xml_get_capability)
                    {
                         g_pict_bridge_context.printing_capability[g_pict_bridge_context.xml_capability_index - PICT_XML_TAG_QUALITIES - 1] = 1;
                    }

                    if ((g_pict_bridge_context.next_operation_request == mmi_pict_prepare_xml_start_job && g_pict_bridge_context.printing == PICT_PRINTING_NOW) ||
                        (g_pict_bridge_context.next_operation_request == mmi_pict_prepare_xml_continue_job && g_pict_bridge_context.printing == PICT_PRINTING_ERROR))
                    {
                        mmi_pict_entry_print_done(MMI_FALSE, (g_pict_bridge_xml.xml_result == PICT_XML_VAL_NOT_EXECUTED) ? STR_ID_PICT_CMD_NOT_EXECUTED : STR_GLOBAL_UNSUPPORTED_FORMAT);
                    }
                }
                break;

            case PICT_XML_TAG_DPS_VERSION:
                xml_max_length = (len > PICT_MAX_DPS_VERSION_LEN) ? PICT_MAX_DPS_VERSION_LEN : len;
                strncpy(g_pict_bridge_xml.dps_version, value, xml_max_length);
                break;

            case PICT_XML_TAG_PRODUCT_NAME:
                xml_max_length = (len > PICT_MAX_PRODUCT_NAME_LEN) ? PICT_MAX_PRODUCT_NAME_LEN : len;
                strncpy(g_pict_bridge_xml.product_name, value, xml_max_length);
                break;

            case PICT_XML_TAG_PRINT_AVAILABLE:
                xml_data_value = (U32) atoi(value);
                g_pict_bridge_xml.service_available = (xml_data_value == PICT_XML_VAL_AVAILABLE) ? MMI_TRUE : MMI_FALSE;
                break;

            case PICT_XML_TAG_QUALITIES:
                for (j = 0; j < xml_data_count; j++)
                {
                    xml_data_value = (U32) atoi(value + j * (PICT_VALUE_LEN + 1));
                    if (xml_data_value == PICT_XML_VAL_DEFAULT_QUALITY)
                    {
                        g_pict_bridge_xml.qualities |= PICT_QUALITY_DEFAULT;
                    }
                    else if (xml_data_value == PICT_XML_VAL_NORMAL_QUALITY)
                    {
                        g_pict_bridge_xml.qualities |= PICT_QUALITY_NORMAL;
                    }
                    else if (xml_data_value == PICT_XML_VAL_DRAFT_QUALITY)
                    {
                        g_pict_bridge_xml.qualities |= PICT_QUALITY_DRAFT;
                    }
                    else if (xml_data_value == PICT_XML_VAL_FINE_QUALITY)
                    {
                        g_pict_bridge_xml.qualities |= PICT_QUALITY_FINE;
                    }
                    else
                    {
                        MMI_ASSERT(0); /* error syntax */
                    }
                }
                break;

            case PICT_XML_TAG_PAPER_SIZES:
                for (j = 0; j < xml_data_count; j++)
                {
                    xml_data_value = (U32) atoi(value + j * (PICT_VALUE_LEN + 1));
                    if (xml_data_value == PICT_XML_VAL_PAPER_DEFAULT)
                    {
                        g_pict_bridge_xml.paper_sizes |= PICT_PAPER_DEFAULT;
                    }
                    else if (xml_data_value == PICT_XML_VAL_PAPER_POSTCARD)
                    {
                        g_pict_bridge_xml.paper_sizes |= PICT_PAPER_POSTCARD;
                    }
                    else if (xml_data_value == PICT_XML_VAL_PAPER_4X6)
                    {
                        g_pict_bridge_xml.paper_sizes |= PICT_PAPER_4x6;
                    }
                    else if (xml_data_value == PICT_XML_VAL_PAPER_LETTER)
                    {
                        g_pict_bridge_xml.paper_sizes |= PICT_PAPER_LETTER;
                    }
                    else if (xml_data_value == PICT_XML_VAL_PAPER_A4)
                    {
                        g_pict_bridge_xml.paper_sizes |= PICT_PAPER_A4;
                    }
                    else
                    {
                        /* unsupported paper sizes */
                    }
                }
                break;

            case PICT_XML_TAG_FILE_TYPES:
                break;

            case PICT_XML_TAG_DATE_PRINTS:
                for (j = 0; j < xml_data_count; j++)
                {
                    xml_data_value = (U32) atoi(value + j * (PICT_VALUE_LEN + 1));
                    if (xml_data_value == PICT_XML_VAL_DATE_DEFAULT)
                    {
                        g_pict_bridge_xml.date_prints |= PICT_CAPABILITY_DEFAULT;
                    }
                    else if (xml_data_value == PICT_XML_VAL_DATE_OFF)
                    {
                        g_pict_bridge_xml.date_prints |= PICT_CAPABILITY_OFF;
                    }
                    else if (xml_data_value == PICT_XML_VAL_DATE_ON)
                    {
                        g_pict_bridge_xml.date_prints |= PICT_CAPABILITY_ON;
                    }
                    else
                    {
                        MMI_ASSERT(0); /* error syntax */
                    }
                }
                break;

            case PICT_XML_TAG_FILENAME_PRINTS:
                for (j = 0; j < xml_data_count; j++)
                {
                    xml_data_value = (U32) atoi(value + j * (PICT_VALUE_LEN + 1));
                    if (xml_data_value == PICT_XML_VAL_FILE_DEFAULT)
                    {
                        g_pict_bridge_xml.filename_prints |= PICT_CAPABILITY_DEFAULT;
                    }
                    else if (xml_data_value == PICT_XML_VAL_FILE_OFF)
                    {
                        g_pict_bridge_xml.filename_prints |= PICT_CAPABILITY_OFF;
                    }
                    else if (xml_data_value == PICT_XML_VAL_FILE_ON)
                    {
                        g_pict_bridge_xml.filename_prints |= PICT_CAPABILITY_ON;
                    }
                    else
                    {
                        MMI_ASSERT(0); /* error syntax */
                    }
                }
                break;

            case PICT_XML_TAG_IMAGE_OPTIMIZES:
                for (j = 0; j < xml_data_count; j++)
                {
                    xml_data_value = (U32) atoi(value + j * (PICT_VALUE_LEN + 1));
                    if (xml_data_value == PICT_XML_VAL_OPT_DEFAULT)
                    {
                        g_pict_bridge_xml.image_optimizes |= PICT_CAPABILITY_DEFAULT;
                    }
                    else if (xml_data_value == PICT_XML_VAL_OPT_OFF)
                    {
                        g_pict_bridge_xml.image_optimizes |= PICT_CAPABILITY_OFF;
                    }
                    else if (xml_data_value == PICT_XML_VAL_OPT_ON)
                    {
                        g_pict_bridge_xml.image_optimizes |= PICT_CAPABILITY_ON;
                    }
                    else
                    {
                        MMI_ASSERT(0); /* error syntax */
                    }
                }
                break;

            case PICT_XML_TAG_PAPER_TYPES:
                //if (g_pict_bridge_xml.xml_attr < PICT_PAPER_MAX)
                //{
                //    g_pict_bridge_xml.paper_types[g_pict_bridge_xml.xml_attr] = (U32) atoi(value);
                //}
                // skip..
                break;

            case PICT_XML_TAG_LAYOUTS:
                for (j = 0; j < xml_data_count; j++)
                {
                    xml_data_value = (U32) atoi(value + j * (PICT_VALUE_LEN + 1));
                    if (xml_data_value == PICT_XML_VAL_LAYOUT_DEFAULT)
                    {
                        g_pict_bridge_xml.layouts[g_pict_bridge_xml.xml_attr] |= PICT_LAYOUT_DEFAULT;
                    }
                    else if (xml_data_value == PICT_XML_VAL_LAYOUT_1UP)
                    {
                        g_pict_bridge_xml.layouts[g_pict_bridge_xml.xml_attr] |= PICT_LAYOUT_1UP;
                    }
                    else if (xml_data_value == PICT_XML_VAL_LAYOUT_2UP)
                    {
                        g_pict_bridge_xml.layouts[g_pict_bridge_xml.xml_attr] |= PICT_LAYOUT_2UP;
                    }
                    else if (xml_data_value == PICT_XML_VAL_LAYOUT_4UP)
                    {
                        g_pict_bridge_xml.layouts[g_pict_bridge_xml.xml_attr] |= PICT_LAYOUT_4UP;
                    }
                    //else if (xml_data_value == PICT_XML_VAL_LAYOUT_INDEX)
                    else if (strncmp(value + j * (PICT_VALUE_LEN + 1), PICT_XML_VAL_LAYOUT_INDEX, 8) == 0)
                    {
                        g_pict_bridge_xml.layouts[g_pict_bridge_xml.xml_attr] |= PICT_LAYOUT_INDEX;
                    }
                    else
                    {
                        /* unsupported layouts */
                    }
                }
                break;

            case PICT_XML_TAG_CROPPINGS:
                for (j = 0; j < xml_data_count; j++)
                {
                    xml_data_value = (U32) atoi(value + j * (PICT_VALUE_LEN + 1));
                    if (xml_data_value == PICT_XML_VAL_CROP_DEFAULT)
                    {
                        g_pict_bridge_xml.croppings |= PICT_CAPABILITY_DEFAULT;
                    }
                    else if (xml_data_value == PICT_XML_VAL_CROP_OFF)
                    {
                        g_pict_bridge_xml.croppings |= PICT_CAPABILITY_OFF;
                    }
                    else if (xml_data_value == PICT_XML_VAL_CROP_ON)
                    {
                        g_pict_bridge_xml.croppings |= PICT_CAPABILITY_ON;
                    }
                    else
                    {
                        MMI_ASSERT(0); /* error syntax */
                    }
                }
                break;

            case PICT_XML_TAG_PROGRESS:
                if (g_pict_bridge_context.printing != PICT_PRINTING_NONE)
                {
                    mmi_pict_update_print_progression(value);
                }
                break;

            case PICT_XML_TAG_DPS_STATUS:
            #ifdef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__
                g_pict_bridge_xml.nds_service_status = (U32) atoi(value);
            #else
                if ((U32) atoi(value) == PICT_XML_VAL_DPS_IDLE)
                {
                    g_pict_bridge_context.dps_status = PICT_DPS_IDLE;
                }
                else
                {
                    g_pict_bridge_context.dps_status = PICT_DPS_BUSY;
                }
            #endif

            #ifdef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__
                if (g_pict_bridge_xml.nds_service_status != PICT_XML_VAL_DPS_PRINTING &&
                    g_pict_bridge_xml.nds_service_status != PICT_XML_VAL_DPS_IDLE &&
                    g_pict_bridge_xml.nds_service_status != PICT_XML_VAL_DPS_PAUSED)
                {
                    xml_data_valid = MMI_FALSE;
                }
             #endif /* __MMI_PICT_BRIDGE_COMPLIANCE_TEST__ */
                break;

            case PICT_XML_TAG_ERROR_STATUS:
            #ifdef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__
                g_pict_bridge_xml.nds_error_status = (U32) atoi(value);
            #else
                if (g_pict_bridge_context.printing != PICT_PRINTING_NONE)
                {
                    g_pict_bridge_context.printing = ((U32) atoi(value) == PICT_XML_VAL_ERROR_NONE) ? PICT_PRINTING_NOW : PICT_PRINTING_ERROR;
                    if (g_pict_bridge_context.printing == PICT_PRINTING_NOW)
                    {
                        ShowStatusIcon(STATUS_ICON_PRINT); /* show print icon */
                        HideStatusIcon(STATUS_ICON_PRINT_FAIL); /* hide print error icon */
                        UpdateStatusIcons();
                        if (GetActiveScreenId() == SCR_ID_PICT_ERROR)
                        {
                            mmi_pict_go_back_from_print_error();
                        }
                        else
                        {
                            DeleteScreenIfPresent(SCR_ID_PICT_ERROR);
                        }
                    }
                }
            #endif
                break;

            case PICT_XML_TAG_ERROR_REASON:
            #ifdef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__
                g_pict_bridge_xml.nds_error_reason = (U32) atoi(value);
            #else
                xml_data_value = (U32) atoi(value);
                if (g_pict_bridge_context.printing != PICT_PRINTING_NONE && g_pict_bridge_context.dps_status == PICT_DPS_IDLE)
                {
                    if (xml_data_value == PICT_XML_VAL_ERROR_FILE || xml_data_value == PICT_XML_VAL_ERROR_NO_DECODE)
                    {
                        mmi_pict_entry_print_done(MMI_FALSE, STR_ID_PICT_ERROR_FILE);
                    }
                    else
                    {
                        mmi_pict_entry_print_done(MMI_TRUE, 0);
                    }
                }
                else
                {
                    if (g_pict_bridge_context.printing == PICT_PRINTING_ERROR)
                    {
                        if (xml_data_value >= PICT_XML_VAL_ERROR_FILE)
                        {
                            g_pict_bridge_context.error_string_id = STR_ID_PICT_ERROR_FILE;
                        }
                        else if (xml_data_value >= PICT_XML_VAL_ERROR_HARDWARE)
                        {
                            g_pict_bridge_context.error_string_id = STR_ID_PICT_ERROR_HARDWARE;
                        }
                        else if (xml_data_value >= PICT_XML_VAL_ERROR_INK)
                        {
                            g_pict_bridge_context.error_string_id = (xml_data_value == PICT_XML_VAL_ERROR_NO_INK) ? STR_ID_PICT_NO_INK : STR_ID_PICT_ERROR_INK;
                        }
                        else if (xml_data_value >= PICT_XML_VAL_ERROR_PAPER)
                        {
                            g_pict_bridge_context.error_string_id = (xml_data_value == PICT_XML_VAL_ERROR_NO_PAPER) ? STR_ID_PICT_NO_PAPER : STR_ID_PICT_ERROR_PAPER;
                        }
                        else
                        {
                            g_pict_bridge_context.error_string_id = STR_ID_PICT_ERROR;
                        }
                        mmi_pict_popup_print_error();
                    }
                }
            #endif
                break;

            default:
                break;
        }

        break; /* for loop */
    }

#ifdef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__
    if (i == PICT_XML_TAG_MAX)
    {
        xml_stop_parse(g_pict_bridge_context.parser);
        g_pict_bridge_context.next_event_request = mmi_pict_prepare_xml_return_error;
    }
#endif /* __MMI_PICT_BRIDGE_COMPLIANCE_TEST__ */

#ifdef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__
    if (!xml_data_valid)
    {
        xml_stop_parse(g_pict_bridge_context.parser);
        g_pict_bridge_context.next_event_request = mmi_pict_prepare_xml_return_invalidity;
    }
#endif /* __MMI_PICT_BRIDGE_COMPLIANCE_TEST__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_parse_xml_script
 * DESCRIPTION
 *  Enrty function to parse the XML script from the printer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_parse_xml_script(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__
    XML_PARSER_STRUCT parser;
#endif
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__

    if (g_pict_bridge_context.parser == NULL)
    {
        g_pict_bridge_context.parser = OslMalloc(sizeof(XML_PARSER_STRUCT));
    }

    xml_new_parser(g_pict_bridge_context.parser);
    xml_register_element_handler(g_pict_bridge_context.parser, mmi_pict_read_xml_start_element, mmi_pict_read_xml_end_element);
    xml_register_data_handler(g_pict_bridge_context.parser, mmi_pict_read_xml_data_element);
    ret = xml_parse(g_pict_bridge_context.parser, PICT_XML_PATH);
    xml_close_parser(g_pict_bridge_context.parser);

    OslMfree(g_pict_bridge_context.parser);
    g_pict_bridge_context.parser = NULL;

#else /* __MMI_PICT_BRIDGE_COMPLIANCE_TEST__ */

    xml_new_parser(&parser);
    xml_register_element_handler(&parser, mmi_pict_read_xml_start_element, mmi_pict_read_xml_end_element);
    xml_register_data_handler(&parser, mmi_pict_read_xml_data_element);
    ret = xml_parse(&parser, PICT_XML_PATH);
    xml_stop_parse(&parser);
    xml_close_parser(&parser);

#endif /* __MMI_PICT_BRIDGE_COMPLIANCE_TEST__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_is_filename_not_alphanumeric
 * DESCRIPTION
 *  Check function for alphanumeric filname
 * PARAMETERS
 *  pInBuffer       [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_pict_is_filename_not_alphanumeric(U8 *pInBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL rtn = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (!((*pInBuffer == 0) && (*(pInBuffer + 1) == 0)))
    {
        if (*(pInBuffer + 1) != 0)
        {
            rtn = MMI_TRUE;
            break;
        }
        pInBuffer += 2;
    }
    return rtn;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_generate_ansii_8_dot_3_filename
 * DESCRIPTION
 *  Generate 8.3 filename
 * PARAMETERS
 *  output_ansii    [OUT]
 *  input_ucs2      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_generate_ansii_8_dot_3_filename(U8 *output_ansii, U8* input_ucs2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_handle;
    FS_FileInfo fs_fileinfo;
    S8 path[(FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(path, (S8*) g_pict_bridge_context.printing_filepath);
    mmi_fmgr_remove_last_dir(path);
    mmi_ucs2cat(path, (S8*) input_ucs2);

    fs_handle = FS_Open((U16*) path, FS_READ_ONLY);
    FS_GetFileInfo(fs_handle, &fs_fileinfo);
    memset(output_ansii, 0, 13);

    for (i = 0; i < 8; i++)
    {
        if (fs_fileinfo.DirEntry->FileName[i] != 0x20)
        {
            *(output_ansii + i) = fs_fileinfo.DirEntry->FileName[i];
			*(output_ansii + i + 1) = '.';
        }
        else
        {
            break;
        }
    }

    strncat((S8*) output_ansii, (S8*) fs_fileinfo.DirEntry->Extension, 3);

    FS_Close(fs_handle);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_prepare_xml_configure_print_service
 * DESCRIPTION
 *  Enrty function to prepare XML command: configurePrintService
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_prepare_xml_configure_print_service(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef MMI_ON_HARDWARE_P
    version_struct ver_struct;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMI_ON_HARDWARE_P
    INT_VersionNumbers(&ver_struct);
#endif

    strcpy(g_pict_bridge_context.xml_operation_cmd, "<?xml version=\"1.0\"?>");
    strcat(g_pict_bridge_context.xml_operation_cmd, "<dps xmlns=\"http://www.cipa.jp/dps/schema/\">");
    strcat(g_pict_bridge_context.xml_operation_cmd, "<input>");
    strcat(g_pict_bridge_context.xml_operation_cmd, "<configurePrintService>");
    strcat(g_pict_bridge_context.xml_operation_cmd, "<dpsVersions>1.0</dpsVersions>");
    strcat(g_pict_bridge_context.xml_operation_cmd, "<vendorName>MediaTek Inc.</vendorName>");
    strcat(g_pict_bridge_context.xml_operation_cmd, "<vendorSpecificVersion>1.0</vendorSpecificVersion>");
#ifdef MMI_ON_HARDWARE_P
    strcat(g_pict_bridge_context.xml_operation_cmd, "<productName>");
    strcat(g_pict_bridge_context.xml_operation_cmd, (S8*) ver_struct.bb_board);
    strcat(g_pict_bridge_context.xml_operation_cmd, "</productName>");
#endif /* MMI_ON_HARDWARE_P */
    strcat(g_pict_bridge_context.xml_operation_cmd, "<serialNo>");
    strcat(g_pict_bridge_context.xml_operation_cmd, Serial_num());
    strcat(g_pict_bridge_context.xml_operation_cmd, "</serialNo>");
    strcat(g_pict_bridge_context.xml_operation_cmd, "</configurePrintService>");
    strcat(g_pict_bridge_context.xml_operation_cmd, "</input>");
    strcat(g_pict_bridge_context.xml_operation_cmd, "</dps>\n");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_prepare_xml_get_capability
 * DESCRIPTION
 *  Enrty function to prepare XML command: getCapability
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_prepare_xml_get_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strcpy(g_pict_bridge_context.xml_operation_cmd, "<?xml version=\"1.0\"?>");
    strcat(g_pict_bridge_context.xml_operation_cmd, "<dps xmlns=\"http://www.cipa.jp/dps/schema/\">");
    strcat(g_pict_bridge_context.xml_operation_cmd, "<input>");
    strcat(g_pict_bridge_context.xml_operation_cmd, "<getCapability>");
    strcat(g_pict_bridge_context.xml_operation_cmd, "<capability>");

    switch (g_pict_bridge_context.xml_capability_index)
    {
        case PICT_XML_TAG_QUALITIES:
            strcat(g_pict_bridge_context.xml_operation_cmd, "<qualities/>");
            break;
        case PICT_XML_TAG_PAPER_SIZES:
            strcat(g_pict_bridge_context.xml_operation_cmd, "<paperSizes/>");
            break;
        case PICT_XML_TAG_PAPER_TYPES:
            strcat(g_pict_bridge_context.xml_operation_cmd, "<paperTypes paperSize=\"51000000\"/>");
            break;
        case PICT_XML_TAG_FILE_TYPES:
            strcat(g_pict_bridge_context.xml_operation_cmd, "<fileTypes/>");
            break;
        case PICT_XML_TAG_DATE_PRINTS:
            strcat(g_pict_bridge_context.xml_operation_cmd, "<datePrints/>");
            break;
        case PICT_XML_TAG_FILENAME_PRINTS:
            strcat(g_pict_bridge_context.xml_operation_cmd, "<fileNamePrints/>");
            break;
        case PICT_XML_TAG_IMAGE_OPTIMIZES:
            strcat(g_pict_bridge_context.xml_operation_cmd, "<imageOptimizes/>");
            break;
        case PICT_XML_TAG_LAYOUTS:
            if ((g_pict_bridge_xml.paper_sizes & PICT_PAPER_DEFAULT) && !(g_pict_bridge_context.xml_layout_index & PICT_PAPER_DEFAULT))
            {
                strcat(g_pict_bridge_context.xml_operation_cmd, "<layouts paperSize=\"51000000\"/>");
                g_pict_bridge_context.xml_layout_index |= PICT_PAPER_DEFAULT;
            }
            else if ((g_pict_bridge_xml.paper_sizes & PICT_PAPER_POSTCARD) && !(g_pict_bridge_context.xml_layout_index & PICT_PAPER_POSTCARD))
            {
                strcat(g_pict_bridge_context.xml_operation_cmd, "<layouts paperSize=\"51030000\"/>");
                g_pict_bridge_context.xml_layout_index |= PICT_PAPER_POSTCARD;
            }
            else if ((g_pict_bridge_xml.paper_sizes & PICT_PAPER_4x6) && !(g_pict_bridge_context.xml_layout_index & PICT_PAPER_4x6))
            {
                strcat(g_pict_bridge_context.xml_operation_cmd, "<layouts paperSize=\"51060000\"/>");
                g_pict_bridge_context.xml_layout_index |= PICT_PAPER_4x6;
            }
            else if ((g_pict_bridge_xml.paper_sizes & PICT_PAPER_LETTER) && !(g_pict_bridge_context.xml_layout_index & PICT_PAPER_LETTER))
            {
                strcat(g_pict_bridge_context.xml_operation_cmd, "<layouts paperSize=\"51080000\"/>");
                g_pict_bridge_context.xml_layout_index |= PICT_PAPER_LETTER;
            }
            else if ((g_pict_bridge_xml.paper_sizes & PICT_PAPER_A4) && !(g_pict_bridge_context.xml_layout_index & PICT_PAPER_A4))
            {
                strcat(g_pict_bridge_context.xml_operation_cmd, "<layouts paperSize=\"51140000\"/>");
                g_pict_bridge_context.xml_layout_index |= PICT_PAPER_A4;
            }
            else
            {
                strcat(g_pict_bridge_context.xml_operation_cmd, "<layouts paperSize=\"51000000\"/>");
                //g_pict_bridge_context.xml_capability_index++; /* exception case */
            }
            break;
        case PICT_XML_TAG_FIXED_SIZES:
            strcat(g_pict_bridge_context.xml_operation_cmd, "<fixedSizes/>");
            break;
        case PICT_XML_TAG_CROPPINGS:
            strcat(g_pict_bridge_context.xml_operation_cmd, "<croppings/>");
            break;
        default:
            MMI_ASSERT(0); /* error syntax */
            break;
    }

    strcat(g_pict_bridge_context.xml_operation_cmd, "</capability>");
    strcat(g_pict_bridge_context.xml_operation_cmd, "</getCapability>");
    strcat(g_pict_bridge_context.xml_operation_cmd, "</input>");
    strcat(g_pict_bridge_context.xml_operation_cmd, "</dps>\n");

    if (g_pict_bridge_context.xml_capability_index != PICT_XML_TAG_LAYOUTS)
    {
        g_pict_bridge_context.xml_capability_index++;
    }
    else if (g_pict_bridge_xml.paper_sizes == g_pict_bridge_context.xml_layout_index)
    {
        g_pict_bridge_context.xml_capability_index++;
        g_pict_bridge_context.xml_layout_index = 0;
    }
    else
    {
        /* continue for next layout */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_prepare_xml_abort_job
 * DESCRIPTION
 *  Enrty function to prepare XML command: abortJob
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_prepare_xml_abort_job(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strcpy(g_pict_bridge_context.xml_operation_cmd, "<?xml version=\"1.0\"?>");
    strcat(g_pict_bridge_context.xml_operation_cmd, "<dps xmlns=\"http://www.cipa.jp/dps/schema/\">");
    strcat(g_pict_bridge_context.xml_operation_cmd, "<input>");
    strcat(g_pict_bridge_context.xml_operation_cmd, "<abortJob>");
    strcat(g_pict_bridge_context.xml_operation_cmd, "<abortStyle>90000000</abortStyle>"); /* immediately stop printing */
    strcat(g_pict_bridge_context.xml_operation_cmd, "</abortJob>");
    strcat(g_pict_bridge_context.xml_operation_cmd, "</input>");
    strcat(g_pict_bridge_context.xml_operation_cmd, "</dps>\n");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_prepare_xml_continue_job
 * DESCRIPTION
 *  Enrty function to prepare XML command: continueJob
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_prepare_xml_continue_job(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strcpy(g_pict_bridge_context.xml_operation_cmd, "<?xml version=\"1.0\"?>");
    strcat(g_pict_bridge_context.xml_operation_cmd, "<dps xmlns=\"http://www.cipa.jp/dps/schema/\">");
    strcat(g_pict_bridge_context.xml_operation_cmd, "<input>");
    strcat(g_pict_bridge_context.xml_operation_cmd, "<continueJob/>");
    strcat(g_pict_bridge_context.xml_operation_cmd, "</input>");
    strcat(g_pict_bridge_context.xml_operation_cmd, "</dps>\n");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_prepare_xml_start_job
 * DESCRIPTION
 *  Enrty function to prepare XML command: startJob
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_prepare_xml_start_job(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 cnt, i;
    U8 ansii_filename[FMGR_MAX_PATH_LEN + 1];
    U8 ansii_date[PICT_MAX_DATE_LEN + 1];
    U8 ansii_value[PICT_VALUE_LEN + 1];
    U8 ansii_cropping[20]; /* 0000 0000 0280 01E0 */

#ifdef __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__
    U8 j;
    U16 file_id_count = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strcpy(g_pict_bridge_context.xml_operation_cmd, "<?xml version=\"1.0\"?>");
    strcat(g_pict_bridge_context.xml_operation_cmd, "<dps xmlns=\"http://www.cipa.jp/dps/schema/\">");
    strcat(g_pict_bridge_context.xml_operation_cmd, "<input>");
    strcat(g_pict_bridge_context.xml_operation_cmd, "<startJob>");

    strcat(g_pict_bridge_context.xml_operation_cmd, "<jobConfig>");

    if (g_pict_bridge_context.printing_capability[0] == 0)
    {
        strcat(g_pict_bridge_context.xml_operation_cmd, "<quality>50000000</quality>");
    }

    do
    {
        cnt = 0;
        if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_DEFAULT)
        {
            if (cnt == g_pict_bridge_setting.paper_size)
            {
                strcat(g_pict_bridge_context.xml_operation_cmd, "<paperSize>51000000</paperSize>");
                break;
            }
            else
            {
                cnt ++;
            }
        }
        if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_POSTCARD)
        {
            if (cnt == g_pict_bridge_setting.paper_size)
            {
                strcat(g_pict_bridge_context.xml_operation_cmd, "<paperSize>51030000</paperSize>");
                break;
            }
            else
            {
                cnt ++;
            }
        }
        if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_4x6)
        {
            if (cnt == g_pict_bridge_setting.paper_size)
            {
                strcat(g_pict_bridge_context.xml_operation_cmd, "<paperSize>51060000</paperSize>");
                break;
            }
            else
            {
                cnt ++;
            }
        }
        if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_LETTER)
        {
            if (cnt == g_pict_bridge_setting.paper_size)
            {
                strcat(g_pict_bridge_context.xml_operation_cmd, "<paperSize>51080000</paperSize>");
                break;
            }
            else
            {
                cnt ++;
            }
        }
        if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_A4)
        {
            if (cnt == g_pict_bridge_setting.paper_size)
            {
                strcat(g_pict_bridge_context.xml_operation_cmd, "<paperSize>51140000</paperSize>");
                break;
            }
            else
            {
                cnt ++;
            }
        }
    }while(0);

    if (g_pict_bridge_context.printing_capability[2] == 0)
    {
        strcat(g_pict_bridge_context.xml_operation_cmd, "<paperType>52000000</paperType>");
    }

    if (g_pict_bridge_context.printing_capability[3] == 0)
    {
        strcat(g_pict_bridge_context.xml_operation_cmd, "<fileType>53000000</fileType>");
    }

    if (g_pict_bridge_context.printing_capability[4] == 0)
    {
        do
        {
            cnt = 0;
            if (g_pict_bridge_xml.date_prints & PICT_CAPABILITY_DEFAULT)
            {
                if (cnt == g_pict_bridge_setting.date_print)
                {
                    strcat(g_pict_bridge_context.xml_operation_cmd, "<datePrint>54000000</datePrint>");
                    break;
                }
                else
                {
                    cnt ++;
                }
            }
            if (g_pict_bridge_xml.date_prints & PICT_CAPABILITY_OFF)
            {
                if (cnt == g_pict_bridge_setting.date_print)
                {
                    strcat(g_pict_bridge_context.xml_operation_cmd, "<datePrint>54010000</datePrint>");
                    break;
                }
                else
                {
                    cnt ++;
                }
            }
            if (g_pict_bridge_xml.date_prints & PICT_CAPABILITY_ON)
            {
                if (cnt == g_pict_bridge_setting.date_print)
                {
                    strcat(g_pict_bridge_context.xml_operation_cmd, "<datePrint>54020000</datePrint>");
                    break;
                }
                else
                {
                    cnt ++;
                }
            }
        }while(0);
    }

    if (g_pict_bridge_context.printing_capability[5] == 0)
    {
        do
        {
            cnt = 0;
            if (g_pict_bridge_xml.filename_prints & PICT_CAPABILITY_DEFAULT)
            {
                if (cnt == g_pict_bridge_setting.filename_print)
                {
                    strcat(g_pict_bridge_context.xml_operation_cmd, "<fileNamePrint>55000000</fileNamePrint>");
                    break;
                }
                else
                {
                    cnt ++;
                }
            }
            if (g_pict_bridge_xml.filename_prints & PICT_CAPABILITY_OFF)
            {
                if (cnt == g_pict_bridge_setting.filename_print)
                {
                    strcat(g_pict_bridge_context.xml_operation_cmd, "<fileNamePrint>55010000</fileNamePrint>");
                    break;
                }
                else
                {
                    cnt ++;
                }
            }
            if (g_pict_bridge_xml.filename_prints & PICT_CAPABILITY_ON)
            {
                if (cnt == g_pict_bridge_setting.filename_print)
                {
                    strcat(g_pict_bridge_context.xml_operation_cmd, "<fileNamePrint>55020000</fileNamePrint>");
                    break;
                }
                else
                {
                    cnt ++;
                }
            }
        }while(0);
    }

    if (g_pict_bridge_context.printing_capability[6] == 0)
    {
        strcat(g_pict_bridge_context.xml_operation_cmd, "<imageOptimize>56000000</imageOptimize>");
    }

    if (g_pict_bridge_context.printing_capability[7] == 0)
    {
        if (g_pict_bridge_setting.page_format == 0) /* standard */
        {
            if (g_pict_bridge_setting.border == 0) /* border on */
            {
            #ifdef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__
                strcat(g_pict_bridge_context.xml_operation_cmd, "<layout>57000000</layout>");
            #else
                strcat(g_pict_bridge_context.xml_operation_cmd, "<layout>57010000</layout>");
            #endif
            }
            else
            {
                strcat(g_pict_bridge_context.xml_operation_cmd, "<layout>57FF0000</layout>");
            }
        }
        else /* multiple or index */
        {
            if (g_pict_bridge_setting.layout == 0) /* 1-up layout */
            {
            #ifdef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__
                strcat(g_pict_bridge_context.xml_operation_cmd, "<layout>57000000</layout>");
            #else
                strcat(g_pict_bridge_context.xml_operation_cmd, "<layout>57010000</layout>");
            #endif
            }
            else if (g_pict_bridge_setting.layout == 1) /* 2-up layout */
            {
                strcat(g_pict_bridge_context.xml_operation_cmd, "<layout>57020000</layout>");
            }
            else if (g_pict_bridge_setting.layout == 2) /* 4-up layout */
            {
                strcat(g_pict_bridge_context.xml_operation_cmd, "<layout>57040000</layout>");
            }
        #ifdef __MMI_PICT_BRIDGE_INDEX_PRINT__
            else if (g_pict_bridge_setting.layout == 3) /* index layout */
            {
                strcat(g_pict_bridge_context.xml_operation_cmd, "<layout>57FE0000</layout>");
            }
        #endif /* __MMI_PICT_BRIDGE_INDEX_PRINT__ */
            else
            {
                MMI_ASSERT(0);
            }
        }
    }

    if (g_pict_bridge_context.printing_capability[9] == 0)
    {
    #ifdef __MMI_PICT_BRIDGE_CROPPING__
        do
        {
            cnt = 0;
            ansii_cropping[0] = 0;
            if (g_pict_bridge_xml.croppings & PICT_CAPABILITY_DEFAULT)
            {
                if (cnt == g_pict_bridge_setting.cropping)
                {
                    strcat(g_pict_bridge_context.xml_operation_cmd, "<cropping>59000000</cropping>");
                    break;
                }
                else
                {
                    cnt ++;
                }
            }
            if (g_pict_bridge_xml.croppings & PICT_CAPABILITY_OFF)
            {
                if (cnt == g_pict_bridge_setting.cropping)
                {
                    strcat(g_pict_bridge_context.xml_operation_cmd, "<cropping>59010000</cropping>");
                    break;
                }
                else
                {
                    cnt ++;
                }
            }
            if (g_pict_bridge_xml.croppings & PICT_CAPABILITY_ON)
            {
                if (cnt == g_pict_bridge_setting.cropping)
                {
                    strcat(g_pict_bridge_context.xml_operation_cmd, "<cropping>59020000</cropping>");
                #ifdef __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__
                    if (g_pict_bridge_context.multi_file_select == 1)
                #endif
                    {
                        sprintf(
                            (S8*) ansii_cropping,
                            "%04X %04X %04X %04X",
                            g_pict_bridge_setting.x_coordinate,
                            g_pict_bridge_setting.y_coordinate,
                            g_pict_bridge_setting.x_arix,
                            g_pict_bridge_setting.y_arix);
                    }
                    break;
                }
                else
                {
                    cnt ++;
                }
            }
        }while(0);
    #else /* __MMI_PICT_BRIDGE_CROPPING__ */
        ansii_cropping[0] = 0;
        strcat(g_pict_bridge_context.xml_operation_cmd, "<cropping>59000000</cropping>");
    #endif /* __MMI_PICT_BRIDGE_CROPPING__ */
    }
    else
    {
        ansii_cropping[0] = 0;
    }

    strcat(g_pict_bridge_context.xml_operation_cmd, "</jobConfig>");

    if (g_pict_bridge_setting.page_format == 0) /* standard */
    {
    #ifdef __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__
        for (i = 0; i < g_pict_bridge_context.multi_file_select; i++)
        {
            strcat(g_pict_bridge_context.xml_operation_cmd, "<printInfo>");
            if (ansii_cropping[0] != 0 && g_pict_bridge_context.multi_file_select == 1)
            {
                strcat(g_pict_bridge_context.xml_operation_cmd, "<croppingArea>");
                strcat(g_pict_bridge_context.xml_operation_cmd, (S8*) ansii_cropping);
                strcat(g_pict_bridge_context.xml_operation_cmd, "</croppingArea>");
            }
            strcat(g_pict_bridge_context.xml_operation_cmd, "<fileID>");
            sprintf((S8*) ansii_value, "%08X", i + 1);
            strcat(g_pict_bridge_context.xml_operation_cmd, (S8*) ansii_value);
            strcat(g_pict_bridge_context.xml_operation_cmd, "</fileID>");
            strcat(g_pict_bridge_context.xml_operation_cmd, "<fileName>");
            if (mmi_pict_is_filename_not_alphanumeric(g_pict_bridge_context.multi_file_path[i]))
            {
                mmi_ucs2_to_asc((S8*) ansii_filename, (S8*) PICT_DEFAULT_FILENAME);
            }
            else
            {
                mmi_pict_generate_ansii_8_dot_3_filename(ansii_filename, g_pict_bridge_context.multi_file_path[i]);
                /* mmi_ucs2_to_asc((S8*) ansii_filename, (S8*) g_pict_bridge_context.multi_file_path[i]); */
            }
            strcat(g_pict_bridge_context.xml_operation_cmd, (S8*) ansii_filename);
            strcat(g_pict_bridge_context.xml_operation_cmd, "</fileName>");
            strcat(g_pict_bridge_context.xml_operation_cmd, "<date>");
            mmi_ucs2_to_asc((S8*) ansii_date, (S8*) g_pict_bridge_context.multi_file_date[i]);
            strcat(g_pict_bridge_context.xml_operation_cmd, (S8*) ansii_date);
            strcat(g_pict_bridge_context.xml_operation_cmd, "</date>");
            strcat(g_pict_bridge_context.xml_operation_cmd, "<copies>");
            sprintf((S8*) ansii_value, "%03d", g_pict_bridge_setting.number_of_copies + 1);
            strcat(g_pict_bridge_context.xml_operation_cmd, (S8*) ansii_value);
            strcat(g_pict_bridge_context.xml_operation_cmd, "</copies>");
            strcat(g_pict_bridge_context.xml_operation_cmd, "</printInfo>");
        }
    #else /* __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__ */
        strcat(g_pict_bridge_context.xml_operation_cmd, "<printInfo>");
        if (ansii_cropping[0] != 0)
        {
            strcat(g_pict_bridge_context.xml_operation_cmd, "<croppingArea>");
            strcat(g_pict_bridge_context.xml_operation_cmd, (S8*) ansii_cropping);
            strcat(g_pict_bridge_context.xml_operation_cmd, "</croppingArea>");
        }
        strcat(g_pict_bridge_context.xml_operation_cmd, "<fileID>00000001</fileID>");
        strcat(g_pict_bridge_context.xml_operation_cmd, "<fileName>");
        if (mmi_pict_is_filename_not_alphanumeric((U8*) mmi_fmgr_extract_file_name((S8*) g_pict_bridge_context.printing_filepath)))
        {
            mmi_ucs2_to_asc((S8*) ansii_filename, (S8*) PICT_DEFAULT_FILENAME);
        }
        else
        {
            mmi_ucs2_to_asc((S8*) ansii_filename, mmi_fmgr_extract_file_name((S8*) g_pict_bridge_context.printing_filepath));
        }
        strcat(g_pict_bridge_context.xml_operation_cmd, (S8*) ansii_filename);
        strcat(g_pict_bridge_context.xml_operation_cmd, "</fileName>");
        strcat(g_pict_bridge_context.xml_operation_cmd, "<date>");
        mmi_ucs2_to_asc((S8*) ansii_date, (S8*) g_pict_bridge_context.printing_filedate);
        strcat(g_pict_bridge_context.xml_operation_cmd, (S8*) ansii_date);
        strcat(g_pict_bridge_context.xml_operation_cmd, "</date>");
        strcat(g_pict_bridge_context.xml_operation_cmd, "<copies>");
        sprintf((S8*) ansii_value, "%03d", g_pict_bridge_setting.number_of_copies + 1);
        strcat(g_pict_bridge_context.xml_operation_cmd, (S8*) ansii_value);
        strcat(g_pict_bridge_context.xml_operation_cmd, "</copies>");
        strcat(g_pict_bridge_context.xml_operation_cmd, "</printInfo>");
    #endif /* __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__ */
    }
    else if (g_pict_bridge_setting.page_format == 1) /* multiple */
    {
    #ifdef __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__
        for (i = 0; i < g_pict_bridge_context.multi_file_select; i++)
        {
            for (j = 1; ; j++)
            {
                strcat(g_pict_bridge_context.xml_operation_cmd, "<printInfo>");
                if (ansii_cropping[0] != 0 && g_pict_bridge_context.multi_file_select == 1)
                {
                    strcat(g_pict_bridge_context.xml_operation_cmd, "<croppingArea>");
                    strcat(g_pict_bridge_context.xml_operation_cmd, (S8*) ansii_cropping);
                    strcat(g_pict_bridge_context.xml_operation_cmd, "</croppingArea>");
                }
                strcat(g_pict_bridge_context.xml_operation_cmd, "<fileID>");
                file_id_count++;
                sprintf((S8*) ansii_value, "%08X", file_id_count);
                strcat(g_pict_bridge_context.xml_operation_cmd, (S8*) ansii_value);
                strcat(g_pict_bridge_context.xml_operation_cmd, "</fileID>");
                strcat(g_pict_bridge_context.xml_operation_cmd, "<fileName>");
                if (mmi_pict_is_filename_not_alphanumeric(g_pict_bridge_context.multi_file_path[i]))
                {
                    mmi_ucs2_to_asc((S8*) ansii_filename, (S8*) PICT_DEFAULT_FILENAME);
                }
                else
                {
                    mmi_ucs2_to_asc((S8*) ansii_filename, (S8*) g_pict_bridge_context.multi_file_path[i]);
                }
                strcat(g_pict_bridge_context.xml_operation_cmd, (S8*) ansii_filename);
                strcat(g_pict_bridge_context.xml_operation_cmd, "</fileName>");
                strcat(g_pict_bridge_context.xml_operation_cmd, "<date>");
                mmi_ucs2_to_asc((S8*) ansii_date, (S8*) g_pict_bridge_context.multi_file_date[i]);
                strcat(g_pict_bridge_context.xml_operation_cmd, (S8*) ansii_date);
                strcat(g_pict_bridge_context.xml_operation_cmd, "</date>");
                strcat(g_pict_bridge_context.xml_operation_cmd, "</printInfo>");
                if ((j == 1 && g_pict_bridge_setting.layout == 0) ||
                    (j == 2 && g_pict_bridge_setting.layout == 1) ||
                    (j == 4 && g_pict_bridge_setting.layout == 2))
                {
                    break;
                }
            }
        }
    #else /* __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__ */
        for (i = 1; ; i++)
        {
            strcat(g_pict_bridge_context.xml_operation_cmd, "<printInfo>");
            if (ansii_cropping[0] != 0)
            {
                strcat(g_pict_bridge_context.xml_operation_cmd, "<croppingArea>");
                strcat(g_pict_bridge_context.xml_operation_cmd, (S8*) ansii_cropping);
                strcat(g_pict_bridge_context.xml_operation_cmd, "</croppingArea>");
            }
            strcat(g_pict_bridge_context.xml_operation_cmd, "<fileID>");
            sprintf((S8*) ansii_value, "%08X", i);
            strcat(g_pict_bridge_context.xml_operation_cmd, (S8*) ansii_value);
            strcat(g_pict_bridge_context.xml_operation_cmd, "</fileID>");
            strcat(g_pict_bridge_context.xml_operation_cmd, "<fileName>");
            if (mmi_pict_is_filename_not_alphanumeric((U8*) mmi_fmgr_extract_file_name((S8*) g_pict_bridge_context.printing_filepath)))
            {
                mmi_ucs2_to_asc((S8*) ansii_filename, (S8*) PICT_DEFAULT_FILENAME);
            }
            else
            {
                mmi_ucs2_to_asc((S8*) ansii_filename, mmi_fmgr_extract_file_name((S8*) g_pict_bridge_context.printing_filepath));
            }
            strcat(g_pict_bridge_context.xml_operation_cmd, (S8*) ansii_filename);
            strcat(g_pict_bridge_context.xml_operation_cmd, "</fileName>");
            strcat(g_pict_bridge_context.xml_operation_cmd, "<date>");
            mmi_ucs2_to_asc((S8*) ansii_date, (S8*) g_pict_bridge_context.printing_filedate);
            strcat(g_pict_bridge_context.xml_operation_cmd, (S8*) ansii_date);
            strcat(g_pict_bridge_context.xml_operation_cmd, "</date>");
            strcat(g_pict_bridge_context.xml_operation_cmd, "</printInfo>");
            if ((i == 1 && g_pict_bridge_setting.layout == 0) ||
                (i == 2 && g_pict_bridge_setting.layout == 1) ||
                (i == 4 && g_pict_bridge_setting.layout == 2))
            {
                break;
            }
        }
    #endif /* __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__ */
    }
    else /* index */
    {
    #ifdef __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__
        for (i = 0; i < g_pict_bridge_context.multi_file_select; i++)
        {
            strcat(g_pict_bridge_context.xml_operation_cmd, "<printInfo>");
            if (ansii_cropping[0] != 0 && g_pict_bridge_context.multi_file_select == 1)
            {
                strcat(g_pict_bridge_context.xml_operation_cmd, "<croppingArea>");
                strcat(g_pict_bridge_context.xml_operation_cmd, (S8*) ansii_cropping);
                strcat(g_pict_bridge_context.xml_operation_cmd, "</croppingArea>");
            }
            strcat(g_pict_bridge_context.xml_operation_cmd, "<fileID>");
            file_id_count++;
            sprintf((S8*) ansii_value, "%08X", i + 1);
            strcat(g_pict_bridge_context.xml_operation_cmd, (S8*) ansii_value);
            strcat(g_pict_bridge_context.xml_operation_cmd, "</fileID>");
            strcat(g_pict_bridge_context.xml_operation_cmd, "<fileName>");
            if (mmi_pict_is_filename_not_alphanumeric(g_pict_bridge_context.multi_file_path[i]))
            {
                mmi_ucs2_to_asc((S8*) ansii_filename, (S8*) PICT_DEFAULT_FILENAME);
            }
            else
            {
                mmi_ucs2_to_asc((S8*) ansii_filename, (S8*) g_pict_bridge_context.multi_file_path[i]);
            }
            strcat(g_pict_bridge_context.xml_operation_cmd, (S8*) ansii_filename);
            strcat(g_pict_bridge_context.xml_operation_cmd, "</fileName>");
            strcat(g_pict_bridge_context.xml_operation_cmd, "<date>");
            mmi_ucs2_to_asc((S8*) ansii_date, (S8*) g_pict_bridge_context.multi_file_date[i]);
            strcat(g_pict_bridge_context.xml_operation_cmd, (S8*) ansii_date);
            strcat(g_pict_bridge_context.xml_operation_cmd, "</date>");
            strcat(g_pict_bridge_context.xml_operation_cmd, "</printInfo>");
        }
    #endif /* __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__ */
    }

    strcat(g_pict_bridge_context.xml_operation_cmd, "</startJob>");
    strcat(g_pict_bridge_context.xml_operation_cmd, "</input>");
    strcat(g_pict_bridge_context.xml_operation_cmd, "</dps>\n");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_prepare_xml_notify_job_result
 * DESCRIPTION
 *  Enrty function to prepare XML result: notifyJobStatus
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_prepare_xml_notify_job_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strcpy(g_pict_bridge_context.xml_event_cmd, "<?xml version=\"1.0\"?>");
    strcat(g_pict_bridge_context.xml_event_cmd, "<dps xmlns=\"http://www.cipa.jp/dps/schema/\">");
    strcat(g_pict_bridge_context.xml_event_cmd, "<output>");
    strcat(g_pict_bridge_context.xml_event_cmd, "<result>10000000</result>");
    strcat(g_pict_bridge_context.xml_event_cmd, "<notifyJobStatus/>");
    strcat(g_pict_bridge_context.xml_event_cmd, "</output>");
    strcat(g_pict_bridge_context.xml_event_cmd, "</dps>\n");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_prepare_xml_notify_device_result
 * DESCRIPTION
 *  Enrty function to prepare XML result: notifyDeviceStatus
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_prepare_xml_notify_device_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strcpy(g_pict_bridge_context.xml_event_cmd, "<?xml version=\"1.0\"?>");
    strcat(g_pict_bridge_context.xml_event_cmd, "<dps xmlns=\"http://www.cipa.jp/dps/schema/\">");
    strcat(g_pict_bridge_context.xml_event_cmd, "<output>");
    strcat(g_pict_bridge_context.xml_event_cmd, "<result>10000000</result>");
    strcat(g_pict_bridge_context.xml_event_cmd, "<notifyDeviceStatus/>");
    strcat(g_pict_bridge_context.xml_event_cmd, "</output>");
    strcat(g_pict_bridge_context.xml_event_cmd, "</dps>\n");
}


#ifdef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__
/*****************************************************************************
 * FUNCTION
 *  mmi_pict_prepare_xml_return_error
 * DESCRIPTION
 *  Enrty function to prepare XML result: error
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_prepare_xml_return_error(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strcpy(g_pict_bridge_context.xml_event_cmd, "<?xml version=\"1.0\"?>");
    strcat(g_pict_bridge_context.xml_event_cmd, "<dps xmlns=\"http://www.cipa.jp/dps/schema/\">");
    strcat(g_pict_bridge_context.xml_event_cmd, "<output>");
    strcat(g_pict_bridge_context.xml_event_cmd, "<result>10030000</result>");
    strcat(g_pict_bridge_context.xml_event_cmd, "</output>");
    strcat(g_pict_bridge_context.xml_event_cmd, "</dps>\n");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_prepare_xml_return_invalidity
 * DESCRIPTION
 *  Enrty function to prepare XML result: invalidity
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_prepare_xml_return_invalidity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strcpy(g_pict_bridge_context.xml_event_cmd, "<?xml version=\"1.0\"?>");
    strcat(g_pict_bridge_context.xml_event_cmd, "<dps xmlns=\"http://www.cipa.jp/dps/schema/\">");
    strcat(g_pict_bridge_context.xml_event_cmd, "<output>");
    strcat(g_pict_bridge_context.xml_event_cmd, "<result>10020002</result>");
    strcat(g_pict_bridge_context.xml_event_cmd, "</output>");
    strcat(g_pict_bridge_context.xml_event_cmd, "</dps>\n");
}


void mmi_pict_exec_notify_device_status_cmd(void)
{
    if (g_pict_bridge_xml.nds_service_status == PICT_XML_VAL_DPS_IDLE)
    {
        g_pict_bridge_context.dps_status = PICT_DPS_IDLE;
    }
    else
    {
        g_pict_bridge_context.dps_status = PICT_DPS_BUSY;
    }

    /*
     * printing now:
     *                 no error -> finish printing
     *                 error -> printing error
     * printing error:
     *                 no error -> printing now
     *                 error -> X
     * no printing:
     *                 no error -> X
     *                 error -> popup error
     */

    if (g_pict_bridge_context.printing != PICT_PRINTING_NONE)
    {
        if (g_pict_bridge_xml.nds_error_status == PICT_XML_VAL_ERROR_NONE)
        {
            g_pict_bridge_context.printing = PICT_PRINTING_NOW;
            ShowStatusIcon(STATUS_ICON_PRINT); // show print icon
            HideStatusIcon(STATUS_ICON_PRINT_FAIL); // hide print error icon
            UpdateStatusIcons();
            if (GetActiveScreenId() == SCR_ID_PICT_ERROR)
            {
                mmi_pict_go_back_from_print_error();
            }
            else
            {
                DeleteScreenIfPresent(SCR_ID_PICT_ERROR);
            }
        }
        else
        {
            g_pict_bridge_context.printing = PICT_PRINTING_ERROR;
        }
    }
    /* handle the compliance test case */
    else
    {
        if (g_pict_bridge_xml.nds_error_status != PICT_XML_VAL_ERROR_NONE)
        {
            mmi_pict_popup_idle_state_error();
            return;
        }
    }

    if (g_pict_bridge_context.printing != PICT_PRINTING_NONE && g_pict_bridge_context.dps_status == PICT_DPS_IDLE)
    {
        if (g_pict_bridge_xml.nds_error_reason == PICT_XML_VAL_ERROR_FILE || g_pict_bridge_xml.nds_error_reason == PICT_XML_VAL_ERROR_NO_DECODE)
        {
            mmi_pict_entry_print_done(MMI_FALSE, STR_ID_PICT_ERROR_FILE);
        }
        else
        {
            mmi_pict_entry_print_done(MMI_TRUE, 0);
        }
    }
    else
    {
        if (g_pict_bridge_context.printing == PICT_PRINTING_ERROR)
        {
            if (g_pict_bridge_xml.nds_error_reason >= PICT_XML_VAL_ERROR_FILE)
            {
                g_pict_bridge_context.error_string_id = STR_ID_PICT_ERROR_FILE;
            }
            else if (g_pict_bridge_xml.nds_error_reason >= PICT_XML_VAL_ERROR_HARDWARE)
            {
                g_pict_bridge_context.error_string_id = STR_ID_PICT_ERROR_HARDWARE;
            }
            else if (g_pict_bridge_xml.nds_error_reason >= PICT_XML_VAL_ERROR_INK)
            {
                g_pict_bridge_context.error_string_id = (g_pict_bridge_xml.nds_error_reason == PICT_XML_VAL_ERROR_NO_INK) ? STR_ID_PICT_NO_INK : STR_ID_PICT_ERROR_INK;
            }
            else if (g_pict_bridge_xml.nds_error_reason >= PICT_XML_VAL_ERROR_PAPER)
            {
                g_pict_bridge_context.error_string_id = (g_pict_bridge_xml.nds_error_reason == PICT_XML_VAL_ERROR_NO_PAPER) ? STR_ID_PICT_NO_PAPER : STR_ID_PICT_ERROR_PAPER;
            }
            else
            {
                g_pict_bridge_context.error_string_id = STR_ID_PICT_ERROR;
            }
            mmi_pict_popup_print_error();
        }
    }
}

#endif /* __MMI_PICT_BRIDGE_COMPLIANCE_TEST__ */

#endif /* __MMI_PICT_BRIDGE_SUPPORT__ */


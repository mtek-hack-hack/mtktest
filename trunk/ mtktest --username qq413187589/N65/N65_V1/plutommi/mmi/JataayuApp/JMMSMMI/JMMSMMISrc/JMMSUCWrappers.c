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
 *  JMMSUCWrappers.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for providing all wrappers for Jataayu UC integration.
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
#ifndef __MMI_JMMSUCWRAPPER_C
#define __MMI_JMMSUCWRAPPER_C
/***************************************************************************
* System Include Files
**************************************************************************/

/***************************************************************************
* User Include Files
**************************************************************************/
#if defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT) && defined(__UNIFIED_COMPOSER_SUPPORT__)

#include "lcd_sw_rnd.h"
#include "lcd_sw_inc.h"
#include "mdi_datatype.h"
#include "app_mine.h"
#include "gui_data_types.h"
#include "FileManagerGProt.h"
#include "FileMgr.h"
#include "JMMSStructs.h"
#include "JMMSStoreHandling.h"
#include "JMMSCoreAPI.h"
#include "JMMSResDef.h"
#include "JMMSExdcl.h"
#include "JMMSConfig.h"
#include "JMMSMessageSettings.h"
#include "JMMSMessageSettingsUtils.h"
#include "JMMSCompose.h"
#include "JMMSUCWrappersProt.h"
#include "wapadp.h"
#include "mmsadp.h"
#include "wap_ps_struct.h"
#include "JMMSUCHandlingGProt.h"
#include "JMMSUCInterfaceProt.h"
#include "UnifiedMessageGProt.h"
#include "jdd_messagingconfig.h"
#include "ComposeUtils.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#define MMA_MAX_INTERNAL_FILENAME_LENGTH  100

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/
/***************************************************************************** 
* Global Function
*****************************************************************************/
extern JC_RETCODE jdi_UtilsWriteIntoFile(JC_CHAR *pmFileName, JC_UINT8 *pucData, JC_UINT32 uiLength);


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_provide_mma_error_code
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_code        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_result_enum mmi_jmms_uc_provide_mma_error_code(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "mmi_jmms_uc_provide_mma_error_code:", ret_code);
    switch (ret_code)
    {
        case JC_OK:
            return MMA_RESULT_OK;

        case E_MEMORY_FULL_ERROR:
            return MMA_RESULT_FAIL_INSUFFICIENT_STORAGE;

        case JC_ERR_MSG_INVALID_HANDLE:
            return MMA_RESULT_FAIL_INVALID_PARAMETER;

        case JC_ERR_MSG_INVALID_PAGE_INDEX:
            return MMA_RESULT_FAIL_INVALID_PARAMETER;

        case JC_ERR_MSG_INVALID_MEDIA_INDEX:
            return MMA_RESULT_FAIL_INVALID_PARAMETER;

        case JC_ERR_MSG_MAX_REACHED:
            return MMA_RESULT_FAIL_MAX_MSG_NUM_REACHED;

        case JC_ERR_MSG_MORE_THAN_MAX_PAGE:
            return MMA_RESULT_FAIL_MAX_SLIDE_NUM_REACHED;

        case JC_ERR_MSG_MEDIA_RESTRICTED:
        case JC_ERR_MSG_MEDIA_WARNING:
        case JC_ERR_MSG_MMS_CONTENT_CLASS:
        case JC_ERR_MSG_MMS_CONTENT_RESTRICTED:
        case JC_ERR_UNSUPPORTED:
            return MMA_RESULT_FAIL_UNSUPPORT_CONTENT;

        case JC_ERR_MSG_MMS_UNSUPPORTED_TYPE:
            return MMA_RESULT_FAIL_COMM_UNSUPPORT_CONTENT;

        case JC_ERR_MSG_INVALID_MEDIA_INFO:
            return MMA_RESULT_FAIL_UNSUPPORT_CONTENT;

        case JC_ERR_FILE_WRITE:
        case JC_ERR_FILE_SYS_INIT:
        case JC_ERR_MSG_EMPTY_FILE:
            if (JC_ERR_FILE_WRITE)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "MMA_RESULT_FAIL_INSUFFICIENT_STORAGE");
                return MMA_RESULT_FAIL_INSUFFICIENT_STORAGE;
            }
            else
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "MMA_RESULT_FAIL_FILE_IO:");
                return MMA_RESULT_FAIL_FILE_IO;
            }

        case JC_ERR_STORE_FILE_CORRUPTED:
            return MMA_RESULT_FAIL_FILE_CORRUPTED;

        case JC_ERR_MEMORY_ALLOCATION:
            return MMA_RESULT_FAIL_INSUFFICIENT_MEMORY;

        case JC_ERR_NULL_POINTER:
            return MMA_RESULT_FAIL_INVALID_PARAMETER;

        default:
            return MMA_RESULT_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_um_folder_conversion
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_box_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
UmMsgBoxType mmi_jmms_uc_um_folder_conversion(mma_folder_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UmMsgBoxType uc_box_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_box_type & UM_MSG_BOX_TYPE_INBOX)
    {
        uc_box_type |= MMA_FOLDER_INBOX;
    }
    if (msg_box_type & UM_MSG_BOX_TYPE_UNSENT)
    {
        uc_box_type |= MMA_FOLDER_OUTBOX;
    }
    if (msg_box_type & UM_MSG_BOX_TYPE_SENT)
    {
        uc_box_type |= MMA_FOLDER_SENT;
    }
    if (msg_box_type & UM_MSG_BOX_TYPE_DRAFT)
    {
        uc_box_type |= MMA_FOLDER_DRAFT;
    }
    /* when needed */
    /*    if(msg_box_type & UM_MSG_BOX_TYPE_TEMPLATE)
       {
       uc_box_type |= MMA_FOLDER_TEMPLATE;
       } */
    return uc_box_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_mma_jmms_folder_conversion
 * DESCRIPTION
 *  Send MMA_MODE_EDIT mode req to UC
 * PARAMETERS
 *  msg_box_type        [IN]        
 *  msg_id(?)           [IN]        Kal_uint32
 * RETURNS
 *  mma_folder_enum
 *****************************************************************************/
mmi_jmms_folder_info_enum mmi_jmms_uc_mma_jmms_folder_conversion(mma_folder_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_folder_info_enum jmms_folder = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_box_type)
    {
        case MMA_FOLDER_INBOX:
            jmms_folder = MMS_INBOX_FOLDER;
            break;

        case MMA_FOLDER_OUTBOX:
            jmms_folder = MMS_OUTBOX_FOLDER;
            break;

        case MMA_FOLDER_SENT:
            jmms_folder = MMS_SENT_FOLDER;
            break;

        case MMA_FOLDER_DRAFT:
            jmms_folder = MMS_DRAFTS_FOLDER;
            break;
        case MMA_FOLDER_TEMPLATE:
            jmms_folder = MMS_TEMPLATES_FOLDER;
            break;

        default:
            ASSERT(0);
    }
    return jmms_folder;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_get_creation_mode
 * DESCRIPTION
 *  Get creation mode setting value
 * PARAMETERS
 *  void
 * RETURNS
 *  mma_creation_mode_enum
 *****************************************************************************/
mma_creation_mode_enum mmi_jmms_uc_get_creation_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ECreationMode type = E_CREATION_MODE_FREE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    type = mmi_jmms_compose_settings_creation_mode();
    switch (type)
    {
        case E_CREATION_MODE_FREE:
            return MMA_CREATION_MODE_FREE;

        case E_CREATION_MODE_RESTRICTED:
            return MMA_CREATION_MODE_RESTRICTED;

        default:
            ASSERT(0);
    }
    return MMA_CREATION_MODE_FREE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_conf_get_priority
 * DESCRIPTION
 *  Get MMS priority setting value
 * PARAMETERS
 *  void
 * RETURNS
 *  mma_priority_enum
 *****************************************************************************/
mma_priority_enum mmi_jmms_uc_conf_get_priority(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jmms_priority_enum type = E_PRIORITY_NORMAL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    type = mmi_jmms_sending_settings_priority();

    switch (type)
    {
        case E_PRIORITY_LOW:
            return MMA_PRIORITY_LOW;

        case E_PRIORITY_NORMAL:
            return MMA_PRIORITY_MEDIUM;

        case E_PRIORITY_HIGH:
            return MMA_PRIORITY_HIGH;

        default:
            ASSERT(0);
    }
    return MMA_PRIORITY_MEDIUM;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_conf_get_local_priority
 * DESCRIPTION
 *  Get MMS priority setting value
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  mma_priority_enum
 *****************************************************************************/
mma_priority_enum mmi_jmms_uc_conf_get_local_priority(jmms_priority_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case E_PRIORITY_LOW:
            return MMA_PRIORITY_LOW;

        case E_PRIORITY_NORMAL:
            return MMA_PRIORITY_MEDIUM;

        case E_PRIORITY_HIGH:
            return MMA_PRIORITY_HIGH;

        default:
            ASSERT(0);
    }
    return MMA_PRIORITY_MEDIUM;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_conf_get_expiry_time
 * DESCRIPTION
 *  Get MMS expiry time setting value
 * PARAMETERS
 *  void
 * RETURNS
 *  mma_expiry_time_enum
 *****************************************************************************/
mma_expiry_time_enum mmi_jmms_uc_conf_get_expiry_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jmms_validity_period_enum type = E_VALIDITY_PERIOD_MAX;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    type = mmi_jmms_sending_settings_validity_period_enum();

    switch (type)
    {
        case E_VALIDITY_PERIOD_1HR:
            return MMA_EXPIRY_1_HOUR;

        case E_VALIDITY_PERIOD_12HRS:
            return MMA_EXPIRY_12_HOURS;

        case E_VALIDITY_PERIOD_1DAY:
            return MMA_EXPIRY_1_DAY;

        case E_VALIDITY_PERIOD_1WEEK:
            return MMA_EXPIRY_1_WEEK;

        case E_VALIDITY_PERIOD_MAX:
            return MMA_EXPIRY_MAX;

        default:
            ASSERT(0);
    }
    return MMA_EXPIRY_MAX;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_conf_get_local_expiry_time
 * DESCRIPTION
 *  Get MMS expiry time setting value
 * PARAMETERS
 *  expiry_time     [IN]        
 * RETURNS
 *  mma_expiry_time_enum
 *****************************************************************************/
mma_expiry_time_enum mmi_jmms_uc_conf_get_local_expiry_time(JC_UINT32 expiry_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (expiry_time)
    {
        case 3600:
            return MMA_EXPIRY_1_HOUR;

        case 12 * 3600:
            return MMA_EXPIRY_12_HOURS;

        case 1 * 24 * 3600:
            return MMA_EXPIRY_1_DAY;

        case 1 * 7 * 24 * 3600:
            return MMA_EXPIRY_1_WEEK;

        case MAX_VALIDITY_PERIOD_VALUE:
        default:
            return MMA_EXPIRY_MAX;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_conf_get_delivery_time
 * DESCRIPTION
 *  Get MMS delivery time setting value
 * PARAMETERS
 *  void
 * RETURNS
 *  mma_delivery_time_enum
 *****************************************************************************/
mma_delivery_time_enum mmi_jmms_uc_conf_get_delivery_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jmms_delievery_time_enum type = E_IMMEDIATE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    type = mmi_jmms_sending_settings_delivery_time_enum();

    switch (type)
    {
        case E_IMMEDIATE:
            return MMA_DELIVERY_IMMEDIATE;

        case E_1_HR:
            return MMA_DELIVERY_1_HOUR;

        case E_12_HRS:
            return MMA_DELIVERY_12_HOURS;

        case E_24_HRS:
            return MMA_DELIVERY_24_HOURS;

        default:
            ASSERT(0);
    }
    return MMA_DELIVERY_IMMEDIATE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_conf_get_local_delivery_time
 * DESCRIPTION
 *  Get MMS delivery time setting value
 * PARAMETERS
 *  delivery_time       [IN]        
 * RETURNS
 *  mma_delivery_time_enum
 *****************************************************************************/
mma_delivery_time_enum mmi_jmms_uc_conf_get_local_delivery_time(JC_UINT32 delivery_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (delivery_time)
    {
        case 0:
            return MMA_DELIVERY_IMMEDIATE;

        case 3600:
            return MMA_DELIVERY_1_HOUR;

        case 12 * 3600:
            return MMA_DELIVERY_12_HOURS;

        case 24 * 3600:
            return MMA_DELIVERY_24_HOURS;

        default:
            return MMA_DELIVERY_IMMEDIATE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_conf_get_delivery_report
 * DESCRIPTION
 *  Get MMS delivery report setting value
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool mmi_jmms_uc_conf_get_delivery_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jmms_off_on_enum type = E_OFF;
    kal_bool return_type = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    type = mmi_jmms_sending_settings_delivery_report();
    switch (type)
    {
        case E_ON:
            return_type = MMI_TRUE;
            break;
        case E_OFF:
        default:
            return_type = MMI_FALSE;
            break;
    }
    return return_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_conf_get_read_report
 * DESCRIPTION
 *  Get MMS read report setting value
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool mmi_jmms_uc_conf_get_read_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jmms_off_on_enum type = E_OFF;
    kal_bool return_type = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    type = mmi_jmms_sending_settings_read_report();

    switch (type)
    {
        case E_ON:
            return_type = MMI_TRUE;
            break;
        case E_OFF:
        default:
            return_type = MMI_FALSE;
            break;
    }
    return return_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_sending_settings_sender_visibility
 * DESCRIPTION
 *  Get MMS read report setting value
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
BOOL mmi_jmms_uc_sending_settings_sender_visibility(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jmms_off_on_enum type = E_OFF;
    kal_bool return_type = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    type = mmi_jmms_sending_settings_hide_sender();

    switch (type)
    {
        case E_ON:
            return_type = MMI_FALSE;
            break;

        case E_OFF:
        default:
            return_type = MMI_TRUE;
            break;

    }
    return return_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_conf_get_max_mms_size
 * DESCRIPTION
 *  Get MMS maximum size setting value
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_uint32 mmi_jmms_uc_conf_get_max_mms_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_jmms_uc_get_creation_mode() == MMA_CREATION_MODE_FREE)
    {
        return (kal_uint32) mmi_jmms_retrieval_settings_msg_size_filter();
    }
    else
    {
        return (kal_uint32) mmi_jmms_max_allowable_mms_size_in_content_class_limit(wap_get_mms_content_class());
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_conf_get_image_resizing
 * DESCRIPTION
 *  Get image resizing setting value
 * PARAMETERS
 *  resizing_p     [OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_conf_get_image_resizing(mma_image_resizing_struct *resizing_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 image_resize_option = E_IMAGE_RESIZE_OFF;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(resizing_p, 0x00, sizeof(mma_image_resizing_struct));
    image_resize_option = mmi_jmms_image_resige_option();
#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
    if (image_resize_option != E_IMAGE_RESIZE_OFF)
    {
        switch (image_resize_option)
        {
            case E_IMAGE_RESIZE_160x120:
                resizing_p->width = 160;
                resizing_p->height = 120;
                break;

            case E_IMAGE_RESIZE_320x240:
                resizing_p->width = 320;
                resizing_p->height = 240;
                break;

            case E_IMAGE_RESIZE_640x480:
                resizing_p->width = 640;
                resizing_p->height = 480;
                break;

            default:
                ASSERT(0);
        }
        resizing_p->enable = KAL_TRUE;
    }
    else
#endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 
    {
        resizing_p->enable = KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_create_auto_signature_file
 * DESCRIPTION
 *  Create signature file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
JC_CHAR *mmi_jmms_uc_create_auto_signature_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_CHAR text_file[FMGR_MAX_PATH_LEN] = {0};
    U8 *signature_content = NULL;
    S32 buffer_size = (MAX_AUTO_SIGN_LENGTH + 1) * 4;
    JC_CHAR *file_name_p = NULL;
    S32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->jmms_fs_handle == NULL)
    {
        if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
        {
            return NULL;
        }
    }
    signature_content = jdd_MemAlloc(sizeof(U8) * buffer_size, 1);
    mmi_asc_to_ucs2((S8*) text_file, (S8*) MMI_JMMS_UC_AUTO_SIGNATURE_FILE_PATH);
    len = mmi_jmms_compose_settings_auto_sign_content((U8*) signature_content, buffer_size);
    mmi_jmms_jdi_write_into_file(text_file, signature_content, len);
    file_name_p = jdd_FSFileNameTranslate(g_jmms_context->jmms_fs_handle, text_file);

    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
    }
    if (signature_content != NULL)
    {
        jdd_MemFree(signature_content);
    }
    return file_name_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_conf_get_signature
 * DESCRIPTION
 *  Get signature setting value
 * PARAMETERS
 *  sig_p       [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_conf_get_signature(mma_signature_struct *sig_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_CHAR text_file[FMGR_MAX_PATH_LEN] = {0};
    JC_CHAR *file_name_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(sig_p != NULL);
    memset(sig_p, 0x00, sizeof(mma_signature_struct));
    sig_p->enable = (kal_bool) mmi_jmms_compose_settings_auto_sign_status();

    if (sig_p->enable == KAL_TRUE)
    {
        mmi_asc_to_ucs2((S8*) text_file, (S8*) MMI_JMMS_UC_AUTO_SIGNATURE_FILE_PATH);
        file_name_p = mmi_jmms_uc_create_auto_signature_file();
        if (file_name_p == NULL)
        {
            return;
        }
        mmi_ucs2cpy((S8*) sig_p->text_file, (S8*) file_name_p);

        if (file_name_p != NULL)
        {
            jdd_MemFree(file_name_p);
        }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_conf_get_sliding_time
 * DESCRIPTION
 *  Get sliding time setting value
 * PARAMETERS
 *  sliding_p      [OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_conf_get_sliding_time(mma_setting_struct *sliding_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(sliding_p != NULL);
    memset(sliding_p, 0x00, sizeof(mma_setting_struct));

    sliding_p->min = (kal_uint32) 0;
    sliding_p->max = (kal_uint32) 999;
    sliding_p->value = (kal_uint32) mmi_jmms_compose_settings_default_slide_time();
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_conf_get_mms_resion_layout
 * DESCRIPTION
 *  Send mmi_uc_layout_enum mode to UC
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_uc_layout_enum
 *****************************************************************************/
mmi_uc_layout_enum mmi_jmms_uc_conf_get_mms_resion_layout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 page_index = 1, is_image_first = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_get_region_list(page_index, &is_image_first);
    if (is_image_first == 1)
    {
        return MMI_UC_LAYOUT_THUMBNAIL_AT_TOP;
    }
    else
    {
        return MMI_UC_LAYOUT_THUMBNAIL_AT_BOTTOM;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_compose_edit_request
 * DESCRIPTION
 *  Send MMA_MODE_EDIT mode req to UC
 * PARAMETERS
 *  msg_index           [IN]        
 *  folder_name_p       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_compose_edit_request(JC_UINT32 msg_index, S8 *folder_name_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_UINT32 msg_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearAllKeyHandler();
    msg_id = mmi_jmms_get_message_id(folder_name_p, msg_index);
    mmi_jmms_uc_send_mode_start_uc_req(msg_id, MMA_MODE_EDIT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_compose_edit_fw_request
 * DESCRIPTION
 *  Send MMA_MODE_EDIT mode req to UC
 * PARAMETERS
 *  msg_index           [IN]        
 *  folder_name_p       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_compose_edit_fw_request(JC_UINT32 msg_index, S8 *folder_name_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_UINT32 msg_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearAllKeyHandler();
    msg_id = mmi_jmms_get_message_id(folder_name_p, msg_index);
    mmi_jmms_uc_send_mode_start_uc_req(msg_id, MMA_MODE_FORWARD);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_reply_message
 * DESCRIPTION
 *  Send MMA_MODE_REPLY mode req to UC
 * PARAMETERS
 *  reply_status        [IN]        
 *  msg_index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_reply_message(JC_BOOLEAN reply_status, JC_UINT32 msg_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_UINT32 msg_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (reply_status == E_TRUE)
    {
        ClearAllKeyHandler();
        msg_id = mmi_jmms_get_message_id(MMI_JMMS_INBOX, msg_index);
        mmi_jmms_uc_send_mode_start_uc_req(msg_id, MMA_MODE_REPLY_ALL);
    }
    else
    {
        ClearAllKeyHandler();
        msg_id = mmi_jmms_get_message_id(MMI_JMMS_INBOX, msg_index);
        mmi_jmms_uc_send_mode_start_uc_req(msg_id, MMA_MODE_REPLY);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_compose_edit_send_request
 * DESCRIPTION
 *  Send MMA_MODE_EDIT mode req to UC
 * PARAMETERS
 *  msg_index           [IN]        
 *  folder_name_p       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_compose_edit_send_request(JC_UINT32 msg_index, S8 *folder_name_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_UINT32 msg_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearAllKeyHandler();
    msg_id = mmi_jmms_get_message_id(folder_name_p, msg_index);
    mmi_jmms_uc_send_mode_start_uc_req(msg_id, MMA_MODE_SEND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_mma_folder_type_from_id
 * DESCRIPTION
 *  Send MMA_MODE_EDIT mode req to UC
 * PARAMETERS
 *  msg_id      [IN]        Kal_uint32
 * RETURNS
 *  mma_folder_enum
 *****************************************************************************/
mma_folder_enum mmi_jmms_get_mma_folder_type_from_id(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_UINT32 folder_type = mmi_jmms_get_message_folder_type_from_id(msg_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (folder_type)
    {
        case MMS_INBOX_FOLDER:
            return MMA_FOLDER_INBOX;

        case MMS_OUTBOX_FOLDER:
            return MMA_FOLDER_OUTBOX;

        case MMS_SENT_FOLDER:
            return MMA_FOLDER_SENT;

        case MMS_DRAFTS_FOLDER:
            return MMA_FOLDER_DRAFT;

        case MMS_TEMPLATES_FOLDER:
            return MMA_FOLDER_TEMPLATE;

        default:
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_uc_check_image_file
 * DESCRIPTION
 *  Check the image file is valid
 * PARAMETERS
 *  file_p      [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool mmi_mms_uc_check_image_file(kal_uint8 *file_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT gdi_ret = GDI_FAILED;
    kal_uint8 buffer_ptr[(2 * 2 * GDI_MAINLCD_BIT_PER_PIXEL) >> 3];
    gdi_handle fake_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_create_using_outside_memory(
        0,
        0,
        2,
        2,
        &fake_layer,
        (PU8) buffer_ptr,
        (S32) (2 * 2 * GDI_MAINLCD_BIT_PER_PIXEL) >> 3);
    gdi_layer_push_and_set_active(fake_layer);

    gdi_ret = gdi_image_draw_file(0, 0, (S8*) file_p);
    gdi_layer_pop_and_restore_active();
    gdi_layer_free(fake_layer);

    if (gdi_ret == GDI_SUCCEED)
    {
        return KAL_TRUE;
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_display_width
 * DESCRIPTION
 *  Check the image file is valid
 * PARAMETERS
 *  void
 *  void
 * RETURNS
 *  JC_UINT32
 *****************************************************************************/
kal_uint32 mmi_jmms_get_display_width(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DeviceCharacteristics device_characteristics;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_code = jdd_MMIGetDeviceCharacteristics(&device_characteristics);

    if (ret_code != JC_OK)
    {
        return LCD_WIDTH;
    }
    else
    {
        return (device_characteristics.uiActualWidth);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_display_height
 * DESCRIPTION
 *  Check the image file is valid
 * PARAMETERS
 *  void
 * RETURNS
 *  JC_UINT32
 *****************************************************************************/
kal_uint32 mmi_jmms_get_display_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DeviceCharacteristics device_characteristics;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_code = jdd_MMIGetDeviceCharacteristics(&device_characteristics);
    if (ret_code != JC_OK)
    {
        return (LCD_HEIGHT);
    }
    else
    {
        return (device_characteristics.uiActualHeight);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_get_name_from_path
 * DESCRIPTION
 *  Get filename from filepath
 * PARAMETERS
 *  path_p      [IN]        
 * RETURNS
 *  filename
 *****************************************************************************/
const char *mmi_jmms_uc_get_name_from_path(const char *path_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *char1_p = strrchr((const char*)path_p, '\\');
    char *char2_p = strrchr((const char*)path_p, '/');

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (char1_p == NULL && char2_p == NULL)
    {
        return NULL;
    }
    else
    {
        char1_p = (char2_p > char1_p) ? char2_p : char1_p;  /* find the last / or \ */
    }

    ++char1_p;
    /* Skip past "\" */
    return ((const char*)char1_p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_get_name_from_path_ucs2
 * DESCRIPTION
 *  Get file name from complete path
 * PARAMETERS
 *  path_p      [IN]        
 * RETURNS
 *  file size
 *****************************************************************************/
const kal_wchar *mmi_jmms_uc_get_name_from_path_ucs2(const kal_wchar *path_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 end = 0, index = 0, filename_pos = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (path_p[end] != '\0')
    {
        end++;

    }
    for (index = 0; index < end; index++)
    {

        if (path_p[index] == '\\' || path_p[index] == '/')
        {
            filename_pos = index;
        }

    }
    if (filename_pos == -1)
    {
        return NULL;
    }
    else
    {
        return path_p + filename_pos + 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_media_mma_type_convert_in_mms_mime_type
 * DESCRIPTION
 *  returns the content type of media file.
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  applib_mime_type_enum
 *****************************************************************************/
EMediaType mmi_jmms_uc_media_mma_type_convert_in_mms_mime_type(mma_insert_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MMA_INSERT_IMAGE:
            return E_MEDIA_IMAGE;

        case MMA_INSERT_AUDIO:
            return E_MEDIA_AUDIO;

        case MMA_INSERT_VIDEO:
            return E_MEDIA_VIDEO;

        default:
            return E_MEDIA_OTHERS;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_get_mime_string_from_file
 * DESCRIPTION
 *  Please remember to free content type buffer after use in your Api
 * PARAMETERS
 *  filename_p      [IN]        
 *  type            [IN]        
 * RETURNS
 *  kal_uint8*
 *****************************************************************************/
kal_uint8 *mmi_jmms_uc_get_mime_string_from_file(const kal_wchar *filename_p, mma_insert_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *mime_string = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename_p == NULL)
    {
        return mime_string;
    }
    jdd_MemSetActiveModuleID(E_TASK_MMS_UI);
    mime_string = mmi_mms_get_mms_content_type_file(
                    (JC_CHAR*) filename_p,
                    (U8) mmi_jmms_uc_media_mma_type_convert_in_mms_mime_type(type));
    if (mime_string != NULL)
    {
        return mime_string;
    }
    else
    {
        return NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_get_mms_media_type_from_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename_p      [IN]        
 *  mma_type        [IN]        
 * RETURNS
 *  mma_insert_type_enum
 *****************************************************************************/
mma_insert_type_enum mmi_jmms_uc_get_mms_media_type_from_file(
                        const kal_wchar *filename_p,
                        mma_insert_type_enum mma_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_media_type_enum type = MEDIA_OTHER;
    mma_insert_type_enum ret_type = MMA_INSERT_UNKNOWN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jdd_MemSetActiveModuleID(E_TASK_MMS_UI);
    type = mmi_jmms_get_mms_media_type_from_file(
            (JC_CHAR*) filename_p,
            mmi_jmms_uc_media_mma_type_convert_in_mms_mime_type(mma_type));
    switch (type)
    {
        case MEDIA_TEXT:
            ret_type = MMA_INSERT_TEXT;
            break;

        case MEDIA_IMAGE:
            ret_type = MMA_INSERT_IMAGE;
            break;

        case MEDIA_AUDIO:
            ret_type = MMA_INSERT_AUDIO;
            break;

        case MEDIA_VIDEO:
            ret_type = MMA_INSERT_VIDEO;
            break;

        default:
            ret_type = MMA_INSERT_UNKNOWN;
    }
    return ret_type;
}

#else /* defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT) && defined(__UNIFIED_COMPOSER_SUPPORT__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_dummy_uc_wrappers_fun
 * DESCRIPTION
 *  Just to remove warning
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_dummy_uc_wrappers_fun(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* dummy */
}
#endif /* defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT) && defined(__UNIFIED_COMPOSER_SUPPORT__) */ 
#endif /* __MMI_JMMSUCWRAPPER_C */ 


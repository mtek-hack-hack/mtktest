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
 *  JMMSUCHandling.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for providing all functionality for Jataayu UC integration.
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
#ifndef __MMI_JMMSUCHANDLING_C
#define __MMI_JMMSUCHANDLING_C
/***************************************************************************
* System Include Files
**************************************************************************/

/***************************************************************************
* User Include Files
**************************************************************************/
#if defined (JATAAYU_SUPPORT) && defined (MMS_SUPPORT) && defined (__UNIFIED_COMPOSER_SUPPORT__)
#include "ProfileGprots.h"
#include "CommonScreens.h"
#include "wgui_inputs.h"
#include "SettingProfile.h"
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
#include "miscutils.h"
#include "JMMSWriteMMS.h"
#include "messagingdatatypes.h"
#include "MessagingAPI.h"
#include "JMMSExdcl.h"
#include "JMMSPushHandling.h"
#include "JMMSCompose.h"
#include "PrvMessagingDataTypes.h"
#include "MM1DataTypes.h"
#include "ComposeUtils.h"
#include "JMMSCoreAPI.h"
#include "JMMSResDef.h"
#include "JMMSMainMMS.h"
#include "JMMSProtocols.h"
#include "JMMSView.h"
#include "JMMSMessageSettingsUtils.h"
#include "wapadp.h"
#include "UnifiedMessageResDef.h"
#include "UnifiedComposerResDef.h"
#include "UnifiedComposerGProt.h"
#include "JMMSUMHandling.h"
#include "JMMSUCWrappersProt.h"
#include "mmsadp.h"
#include "JMMSUCInterfaceProt.h"
#include "JMMSUCHandlingGProt.h"
#include "jdd_messagingconfig.h"
#include "FileMgr.h"
#include "MessagesResourceData.h"
#include "JMMSConfig.h"
#include "app_str.h"
#include "Conversions.h"
#include "JMMSUCXMLProt.h"
#ifdef __DRM_SUPPORT__
#include "drm_def.h"
#include "JMMSDRMHandler.h"
#endif /* __DRM_SUPPORT__ */ 
/***************************************************************************** 
* Define
*****************************************************************************/

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
* Global Function
*****************************************************************************/
extern kal_uint32 wap_mma_uc_calc_header_size(const mmi_uc_msg_struct *mms);
extern kal_uint32 wap_mma_uc_calc_msg_size(const mmi_uc_msg_struct *mms);
extern JC_INT32 GetColorValue(JC_INT8 *pColorString);
extern JC_BOOLEAN IsValidPhoneNumber(JC_INT8 *pPhoneNumber, JC_CHAR *pPhoneNumberUCS2, JC_INT32 iLengthCheck);
extern JC_RETCODE ComputeMessageSize(MESSAGING_HANDLER *pMsgHandler);

#define JMMS_TEST_GSM_EXTENDED(c) \
(  (c==0x20AC)                    \
|| (c==0x5E)                      \
|| (c==0x7B)                      \
|| (c==0x7D)                      \
|| (c==0x5C)                      \
|| (c==0x5B)                      \
|| (c==0x7E)                      \
|| (c==0x5D)                      \
|| (c==0x7C)                      \
)


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_get_folder_string_from_folder_id
 * DESCRIPTION
 *  Get folder string from folder id
 * PARAMETERS
 *  folder_enum_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JC_CHAR *mmi_jmms_uc_get_folder_string_from_folder_id(mmi_jmms_folder_info_enum folder_enum_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_CHAR *folder_name_p = NULL;
    U8 len = strlen(MMI_JMMS_TEMPLATES) + 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder_name_p = (JC_CHAR*) jdd_MemAlloc(sizeof(JC_CHAR), len);
    memset(folder_name_p, 0, len);

    switch (folder_enum_id)
    {
        case MMS_INBOX_FOLDER:
        {
            strcpy((S8*) folder_name_p, (S8*) MMI_JMMS_INBOX);
            break;
        }

        case MMS_OUTBOX_FOLDER:
        {
            strcpy((S8*) folder_name_p, (S8*) MMI_JMMS_OUTBOX);
            break;
        }

        case MMS_SENT_FOLDER:
        {
            strcpy((S8*) folder_name_p, (S8*) MMI_JMMS_SENT);
            break;
        }

        case MMS_DRAFTS_FOLDER:
        {
            strcpy((S8*) folder_name_p, (S8*) MMI_JMMS_DRAFTS);
            break;
        }

        case MMS_TEMPLATES_FOLDER:
        {
            strcpy((S8*) folder_name_p, (S8*) MMI_JMMS_TEMPLATES);
            break;
        }

        default:
            return NULL;
    }

    return (JC_CHAR*) folder_name_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_new_save_mms_async_callback
 * DESCRIPTION
 *  Save call back
 * PARAMETERS
 *  ret_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_new_save_mms_async_callback(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_result_enum ret_mma_code = MMA_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC : new_save_mms_async_callback(rd:%d)", ret_code);

    ret_mma_code = mmi_jmms_uc_provide_mma_error_code(ret_code);
    mmi_jmms_uc_wap_mma_save_rsp(ret_mma_code, g_jmms_context->saved_mms_id);
    mmi_jmms_deinit_mms_context(g_jmms_context);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_start_save_mms_in_uc_folder
 * DESCRIPTION
 *  Save MMS in folder take input UM box id
 * PARAMETERS
 *  req_id              [IN]        
 *  msg_box_type        [IN]        
 *  msg_id              [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_jmms_start_save_mms_in_uc_folder(kal_uint32 req_id, kal_uint16 msg_box_type, JC_UINT32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    JC_CHAR *folder_name_p = NULL;
    U32 msg_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder_name_p = mmi_jmms_uc_get_folder_string_from_folder_id(mmi_jmms_uc_mma_jmms_folder_conversion(msg_box_type));
    if (folder_name_p == NULL)
    {
        return JC_ERR_NULL_POINTER;
    }
    mmi_jmms_get_message_index(g_jmms_context->store_handle, msg_id, &msg_index);
    ret_code = mmi_jmms_store_move_message(MMI_JMMS_DRAFTS, (S8*) folder_name_p, &msg_index);
    if (folder_name_p != NULL)
    {
        jdd_MemFree(folder_name_p);
        folder_name_p = NULL;
    }
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_start_save_mms
 * DESCRIPTION
 *  start save
 * PARAMETERS
 *  req_id              [IN]        
 *  msg_box_type        [IN]        
 *  msg_id              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_start_save_mms(kal_uint32 req_id, kal_uint16 msg_box_type, JC_UINT32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    mma_result_enum ret_mma_code = MMA_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC : start_save_mms(bx:%d md:%d)", msg_box_type, msg_id);

    mmi_jmms_deinit_mms_context(g_jmms_context);
    ret_code = mmi_jmms_start_save_mms_in_uc_folder(req_id, msg_box_type, msg_id);
    ret_mma_code = mmi_jmms_uc_provide_mma_error_code(ret_code);
    mmi_jmms_uc_wap_mma_save_rsp(ret_mma_code, g_jmms_context->saved_mms_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_delete_all_msgs_list
 * DESCRIPTION
 *  Delete all MMS
 * PARAMETERS
 *  msg_box_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_jmms_uc_delete_all_msgs_list(kal_uint16 msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    S16 number = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    number = mmi_jmms_get_number_of_messages_from_msg_box_type(mmi_jmms_uc_um_folder_conversion(msg_box_type));

    if (number >= 0)
    {
        if (number == 0)
        {
            ret_code = JC_OK;
        }
        else
        {

        #ifdef __USB_IN_NORMAL_MODE__
            if (mmi_jmms_check_usb_mode() == 0)
        #endif 
            {
                ret_code = mmi_jmms_delete_all_msgs_list(mmi_jmms_uc_um_folder_conversion(msg_box_type));
            }
        #ifdef __USB_IN_NORMAL_MODE__
            else
            {
                ret_code = -1;
            }
        #endif /* __USB_IN_NORMAL_MODE__ */ 
        }
    }
    else
    {
        ret_code = -1;
    }
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_delete_message_for_uc
 * DESCRIPTION
 *  Handle delete request
 * PARAMETERS
 *  msg_box_type        [IN]        
 *  msg_id              [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_result_enum mmi_jmms_delete_message_for_uc(kal_uint16 msg_box_type, JC_UINT32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    JC_CHAR *folder_name_p = NULL;
    U32 msg_index = 0;
    mma_result_enum ret_mma_code = MMA_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC : delete_message_for_uc(bx:%d md:%d)", msg_box_type, msg_id);

    if (msg_id == 0xFFFFFFFF)
    {
        ret_code = mmi_jmms_uc_delete_all_msgs_list(msg_box_type);
    }
    else
    {
        mmi_jmms_get_message_index(g_jmms_context->store_handle, msg_id, &msg_index);
        folder_name_p = mmi_jmms_uc_get_folder_string_from_folder_id(mmi_jmms_get_message_folder_type_from_id(msg_id));
        ret_code = mmi_jmms_delete_message((S8*) folder_name_p, msg_index);
        if (folder_name_p != NULL)
        {
            jdd_MemFree(folder_name_p);
            folder_name_p = NULL;
        }
    }
    ret_mma_code = mmi_jmms_uc_provide_mma_error_code(ret_code);
    return ret_mma_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_delete_message
 * DESCRIPTION
 *  Handle delete request
 * PARAMETERS
 *  req_id              [IN]        
 *  msg_box_type        [IN]        
 *  msg_id              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_delete_message(kal_uint32 req_id, kal_uint16 msg_box_type, JC_UINT32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_result_enum ret_mma_code = MMA_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_mma_code = mmi_jmms_delete_message_for_uc(msg_box_type, msg_id);
    mmi_jmms_uc_wap_send_wap_mma_delete_rsp(req_id, ret_mma_code, msg_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_get_message
 * DESCRIPTION
 *  common get message function
 * PARAMETERS
 *  folder_enum_id      [IN]        
 *  content             [IN]
 *  ui_msg_index        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_jmms_uc_get_message(mmi_jmms_folder_info_enum folder_enum_id, CONTENT_DATA *content, U32 ui_msg_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC : get_message(fd:%d mi:%d)", folder_enum_id, ui_msg_index);

    switch (folder_enum_id)
    {
        case MMS_INBOX_FOLDER:
        {
            ret_code = mmi_jmms_get_message(MMI_JMMS_INBOX, content, ui_msg_index);
            break;
        }

        case MMS_OUTBOX_FOLDER:
        {
            ret_code = mmi_jmms_get_message(MMI_JMMS_OUTBOX, content, ui_msg_index);
            break;
        }

        case MMS_SENT_FOLDER:
        {
            ret_code = mmi_jmms_get_message(MMI_JMMS_SENT, content, ui_msg_index);
            break;
        }

        case MMS_DRAFTS_FOLDER:
        {
            ret_code = mmi_jmms_get_message(MMI_JMMS_DRAFTS, content, ui_msg_index);
            break;
        }

        case MMS_TEMPLATES_FOLDER:
        {
            ret_code = mmi_jmms_get_message(MMI_JMMS_TEMPLATES, content, ui_msg_index);
            break;
        }

        default:
        {
            ASSERT(0);
        }
    }
    return ret_code;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_create_parsed_mms_data_common_fun
 * DESCRIPTION
 *  common function to parse MMS
 * PARAMETERS
 *  ui_msg_id                           [IN]        
 *  mode                                [IN]        
 *  mmi_jmms_uc_parsed_end_callback     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_create_parsed_mms_data_common_fun(
        JC_UINT32 ui_msg_id,
        JC_INT32 mode,
        post_parse_mms_callback mmi_jmms_uc_parsed_end_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = 0;
    JC_UINT32 ui_msg_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC : create_parsed_mms_data_common_fun(md:%d mo:%d)", ui_msg_id, mode);

    mmi_jmms_deinit_mms_context(g_jmms_context);
    DeleteScreenIfPresent(SCR_ID_JMMS_PARSING_PROGRESS);
    if (g_jmms_context != NULL && g_jmms_context->parse_content_p != NULL)
    {
        if (g_jmms_context->parse_content_p->pFileName != NULL)
        {
            jdd_MemFree(g_jmms_context->parse_content_p->pFileName);
            g_jmms_context->parse_content_p->pFileName = NULL;
        }
        if (g_jmms_context->parse_content_p != NULL)
        {
            jdd_MemFree(g_jmms_context->parse_content_p);
            g_jmms_context->parse_content_p = NULL;
        }

    }
    g_jmms_context->parse_content_p = (CONTENT_DATA*) jdd_MemAlloc(sizeof(CONTENT_DATA), 1);
    g_jmms_context->parse_content_p->bIsStream = E_TRUE;

    mmi_jmms_get_message_index(g_jmms_context->store_handle, ui_msg_id, &ui_msg_index);
    ret_code = mmi_jmms_uc_get_message(
                mmi_jmms_get_message_folder_type_from_id(ui_msg_id),
                g_jmms_context->parse_content_p,
                ui_msg_index);
    if (ret_code != JC_OK)
    {
        goto END;
    }
    g_jmms_context->uc_creation_mode = mode;
    ret_code = mmi_jmms_jdi_parse_msg_buffer(
                &(g_jmms_context->msg_handle),
                g_jmms_context->parse_content_p,
                E_TYPE_MMS,
                E_TRUE);

    if (ret_code == JC_ERR_MMS_PARSE_PENDING)
    {
        mmi_jmms_parse_continue_start_timer(g_jmms_context->msg_handle, mmi_jmms_uc_parsed_end_callback, NULL); /* mmi_jmms_only_abort_parsing_progress); */
        return;
    }

  END:
    g_jmms_context->uc_creation_mode = mode;
    mmi_jmms_uc_parsed_end_callback(ret_code);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_proceed_edit_content_after_media_removal
 * DESCRIPTION
 *  function to call on selecting restricted media removal
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_proceed_edit_content_after_media_removal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_jdi_deinitview(g_jmms_context->msg_handle);
    ret_code = mmi_jmms_jdi_fit_content_class(g_jmms_context->msg_handle, MMS_SUPPORTED_CONTENT_CLASS);
    mmi_jmms_uc_edit_message_async_callback(ret_code);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_proceed_edit_content_for_media_removal
 * DESCRIPTION
 *  function to call on not selecting restricted media removal
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_proceed_edit_content_for_media_removal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_jmms_context->store_context->current_folder_name)
    {
        case E_JMMS_INBOX:
            mmi_jmms_uc_compose_edit_request(
                g_jmms_context->store_context->num_msg_in_curr_folder - g_jmms_context->curr_scr_hilited_index,
                MMI_JMMS_INBOX);
            break;

        case E_JMMS_OUTBOX:
            mmi_jmms_uc_compose_edit_request(
                g_jmms_context->store_context->num_msg_in_curr_folder - g_jmms_context->curr_scr_hilited_index,
                MMI_JMMS_OUTBOX);
            break;

        case E_JMMS_DRAFTS:
            mmi_jmms_uc_compose_edit_request(
                g_jmms_context->store_context->num_msg_in_curr_folder - g_jmms_context->curr_scr_hilited_index,
                MMI_JMMS_DRAFTS);
            break;

        case E_JMMS_SENT:
            mmi_jmms_uc_compose_edit_request(
                g_jmms_context->store_context->num_msg_in_curr_folder - g_jmms_context->curr_scr_hilited_index,
                MMI_JMMS_SENT);
            break;

        case E_JMMS_TEMPLATES:
            mmi_jmms_uc_compose_edit_request(g_jmms_context->curr_scr_hilited_index + 1, MMI_JMMS_TEMPLATES);
            break;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_edit_content_restricted_mode_query
 * DESCRIPTION
 *  query function to select restricted media removalal
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_edit_content_restricted_mode_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer_p = GetCurrGuiBuffer(SCR_CONFIRM_SCREEN);
    EntryNewScreen(SCR_CONFIRM_SCREEN, NULL, NULL, NULL);
    ShowCategory165Screen(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_JMMS_EDIT_CONTENT_QUERY_RESTRICTED_MODE),
        (U16) IMG_GLOBAL_QUESTION,
        guiBuffer_p);
    playRequestedTone(WARNING_TONE);
    SetLeftSoftkeyFunction(mmi_jmms_uc_proceed_edit_content_for_media_removal, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_get_content_async_callback
 * DESCRIPTION
 *  generate all data for get content req
 * PARAMETERS
 *  ret_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_get_content_async_callback(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ECreationMode create_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC : get_content_async_callback(rd:%d)", ret_code);

    if (ret_code == JC_OK && g_jmms_context->uc_creation_mode == MMA_MODE_EDIT)
    {
        create_mode = mmi_jmms_compose_settings_creation_mode();
        if (create_mode == E_CREATION_MODE_RESTRICTED)
        {
            if (IsMMSRestrictedMode(g_jmms_context->msg_handle, MMS_SUPPORTED_CONTENT_CLASS) != JC_OK)
            {
                mmi_jmms_uc_proceed_edit_content_after_media_removal();
                return;
            }
        }
    }
    mmi_jmms_uc_edit_message_async_callback(ret_code);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_edit_message_async_callback
 * DESCRIPTION
 *  after parse callback for edit
 * PARAMETERS
 *  ret_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_edit_message_async_callback(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_result_enum ret_mma_code = MMA_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->mms_header_size = 0;
    g_jmms_context->mms_body_size = 0;

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC : edit_message_async_callback(rd:%d) Entry", ret_code);

    if (ret_code == JC_OK)
    {
        MESSAGE_HEADERS *pMsgHeaders = NULL;
        MESSAGE_SEND *send_p = NULL;
        MESSAGE_RETRIEVAL *reterive_p = NULL;
        S32 len = 0;
        JC_RETCODE ret_code_create_list = JC_OK;
        JC_CHAR *dest_fname_p = NULL;

        ret_code = mmi_jmms_jdi_set_msg_type(g_jmms_context->msg_handle, E_TYPE_MMS);
        if (ret_code != JC_OK)
        {
            goto END;
        }

        ret_code = mmi_jmms_jdi_get_msg_headers(g_jmms_context->msg_handle, &pMsgHeaders);
        if (ret_code != JC_OK || pMsgHeaders == NULL)
        {
            ret_code = JC_ERR_STORE_FILE_CORRUPTED;
            goto END;
        }

        if (pMsgHeaders->eMsgType == E_MSG_TYPE_SEND)
        {
            send_p = (MESSAGE_SEND*) (pMsgHeaders->pHeaders);
        }
        else if (pMsgHeaders->eMsgType == E_MSG_TYPE_RECEIVE)
        {
            reterive_p = (MESSAGE_RETRIEVAL*) (pMsgHeaders->pHeaders);
        }

        mmi_jmms_free_addresses_list();

        g_jmms_context->uc_xml_msg_p = (mmi_uc_msg_struct*) jdd_MemAlloc(sizeof(mmi_uc_msg_struct), 1);

        /* /Make the To Addresses list */
        if (send_p != NULL)
        {
            if (send_p->pTo != NULL)
            {
                ret_code_create_list = mmi_jmms_uc_make_address_list((S8*) send_p->pTo, MMI_UC_ADDRESS_GROUP_TYPE_TO);
                if (ret_code_create_list != JC_OK)
                {
                    ret_code = ret_code_create_list;
                    goto END;
                }
            }

            /* /Make the Cc Addresses list */
            if (send_p->pCc != NULL)
            {
                ret_code_create_list = mmi_jmms_uc_make_address_list((S8*) send_p->pCc, MMI_UC_ADDRESS_GROUP_TYPE_CC);
                if (ret_code_create_list != JC_OK)
                {
                    ret_code = ret_code_create_list;
                    goto END;
                }

            }

            /* /Make the BCc Addresses list */

            if (send_p->pBcc != NULL)
            {
                ret_code_create_list = mmi_jmms_uc_make_address_list((S8*) send_p->pBcc, MMI_UC_ADDRESS_GROUP_TYPE_BCC);

                if (ret_code_create_list != NULL)
                {
                    ret_code = ret_code_create_list;
                    goto END;
                }
            }
            /* /Make the subject buffer */
            memset(g_jmms_context->subject_input_buffer, 0x00, (MAX_SUBJECT_LENGTH + 1) * ENCODING_LENGTH);
            if (send_p->pSubject != NULL)
            {
                len = (mmi_ucs2strlen((S8*) (send_p->pSubject))) * ENCODING_LENGTH;
                if (len > (MAX_SUBJECT_LENGTH * ENCODING_LENGTH))
                {
                    memcpy(
                        g_jmms_context->subject_input_buffer,
                        send_p->pSubject,
                        (MAX_SUBJECT_LENGTH * ENCODING_LENGTH));
                }
                else
                {
                    memcpy(g_jmms_context->subject_input_buffer, send_p->pSubject, len);
                }
                mmi_jmms_uc_add_subject_string((JC_CHAR*) g_jmms_context->subject_input_buffer, len);
            }
        }
        /* /Make the To Addresses list */
        if (reterive_p != NULL)
        {
            if (reterive_p->pTo != NULL)
            {
                ret_code_create_list = mmi_jmms_uc_make_address_list((S8*) reterive_p->pTo, MMI_UC_ADDRESS_GROUP_TYPE_TO);

                if (ret_code_create_list != JC_OK)
                {
                    ret_code = ret_code_create_list;
                    goto END;
                }

            }

            /* /Make the Cc Addresses list */
            if (reterive_p->pCc != NULL)
            {
                ret_code_create_list = mmi_jmms_uc_make_address_list((S8*) reterive_p->pCc, MMI_UC_ADDRESS_GROUP_TYPE_CC);

                if (ret_code_create_list != JC_OK)
                {
                    ret_code = ret_code_create_list;
                    goto END;
                }

            }
            /* /Make the Cc Addresses list */
            if (reterive_p->pFrom != NULL)
            {
                ret_code_create_list = mmi_jmms_uc_make_address_list((S8*) reterive_p->pFrom, MMI_UC_ADDRESS_GROUP_TYPE_FROM);

                if (ret_code_create_list != JC_OK)
                {
                    ret_code = ret_code_create_list;
                    goto END;
                }

            }
            /* /Make the subject buffer */
            memset(g_jmms_context->subject_input_buffer, 0x00, (MAX_SUBJECT_LENGTH + 1) * ENCODING_LENGTH);
            if (reterive_p->pSubject != NULL)
            {
                len = (mmi_ucs2strlen((S8*) (reterive_p->pSubject))) * ENCODING_LENGTH;
                if (len > (MAX_SUBJECT_LENGTH * ENCODING_LENGTH))
                {
                    memcpy(
                        g_jmms_context->subject_input_buffer,
                        reterive_p->pSubject,
                        (MAX_SUBJECT_LENGTH * ENCODING_LENGTH));
                }
                else
                {
                    memcpy(g_jmms_context->subject_input_buffer, reterive_p->pSubject, len);
                }
                mmi_jmms_uc_add_subject_string((JC_CHAR*) g_jmms_context->subject_input_buffer, len);
            }
        }
        mmi_jmms_uc_fill_mms_sending_settings();

        if (g_jmms_context->compose_context == NULL)
        {
            g_jmms_context->compose_context =
                (mmi_jmms_compose_context_struct*) jdd_MemAlloc(sizeof(mmi_jmms_compose_context_struct), 1);
            if (g_jmms_context->compose_context == NULL)
            {
                ret_code = JC_ERR_MEMORY_ALLOCATION;
                goto END;
            }
        }
        g_jmms_context->compose_context->curr_page_index = 0;
        g_jmms_context->uc_xml_msg_p->background_color = MMA_DEFAULT_SMIL_BG_COLOR;
        g_jmms_context->uc_xml_msg_p->foreground_color = MMA_DEFAULT_SMIL_FG_COLOR;
        g_jmms_context->uc_xml_msg_p->total_slide_num = 0;
        g_jmms_context->uc_xml_msg_p->total_object_num = 0;

        if (g_jmms_context->uc_creation_mode != MMA_MODE_REPLY &&
            g_jmms_context->uc_creation_mode != MMA_MODE_REPLY_ALL)
        {
            ret_code = mmi_jmms_uc_create_object_list();
            if (ret_code != JC_OK)
            {
                goto END;
            }
        }
        else
        {
            g_jmms_context->uc_xml_msg_p->layout = MMA_LAYOUT_NONE;
        }

        {
            JC_CHAR *temp_file = NULL;
            S8 name[FMGR_MAX_PATH_LEN] = {0, };

            mmi_asc_to_ucs2(name, MMI_JMMS_UC_FOLDER_PATH);
            if (g_jmms_context->jmms_fs_handle == NULL)
            {
                if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
                {
                    ret_code = JC_ERR_FILE_SYS_INIT;
                    goto END;
                }
            }

            if (jdd_FSIsDirExist(g_jmms_context->jmms_fs_handle, (JC_CHAR*) name) == E_FALSE)  /* Folder Does Not Exist */
            {
                JC_RETCODE error_code = JC_OK;

                PRINT_INFORMATION_2(MMI_TRACE_INFO, "edit_message_async_callback creating DIR temp/xml");
                error_code = jdd_FSMakeDir(g_jmms_context->jmms_fs_handle, (U16*) name);
                if (error_code != JC_ERR_FILE_DIR_ALREADY_EXIST && error_code != JC_OK)
                {
                    ret_code = error_code;
                    PRINT_INFORMATION_2(MMI_TRACE_INFO,
                                         "edit_message_async_callback DIR creation failed: %d", error_code);
                    goto END;
                }
            }

            sprintf(name, MMI_JMMS_UC_GET_CONTENT_XML_FILE_PATH);
            jdi_UtilsCharToTchar((JC_CHAR **) & (temp_file), name);

            dest_fname_p = (JC_CHAR*) jdd_FSFileNameTranslate(g_jmms_context->jmms_fs_handle, temp_file);
            ASSERT(dest_fname_p != NULL);

            if (g_jmms_context->jmms_fs_handle != NULL)
            {
                jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
                g_jmms_context->jmms_fs_handle = NULL;
            }
            ret_code = mmi_jmms_uc_create_mms_xml_description_file((U8*) dest_fname_p);
            if (dest_fname_p != NULL)
            {
                jdd_MemFree(dest_fname_p);
            }
            if (temp_file != NULL)
            {
                jdd_MemFree(temp_file);
            }
        }
        g_jmms_context->mms_header_size = wap_mma_uc_calc_header_size(g_jmms_context->uc_xml_msg_p);
        ComputeMessageSize(g_jmms_context->msg_handle);
        mmi_jmms_jdi_get_size(g_jmms_context->msg_handle, 0, &(g_jmms_context->mms_body_size));
    }
  END:

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC : edit_message_async_callback() End");

    ret_mma_code = mmi_jmms_uc_provide_mma_error_code(ret_code);
    mmi_jmms_uc_send_wap_mma_get_content_rsp(ret_mma_code);
    if (g_jmms_context->compose_context != NULL)
    {
        jdd_MemFree(g_jmms_context->compose_context);
        g_jmms_context->compose_context = NULL;
    }
    mmi_jmms_uc_distroy_xml_struct();
    g_jmms_context->is_add_media_warning = 0;
    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_get_mma_content_rsp
 * DESCRIPTION
 *  copy xml to peer buffer
 * PARAMETERS
 *  src_fname_p         [IN]         
 *  buffer_p            [IN]         
 *  buffer_index        [IN]        
 *  xml_size            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mmi_jmms_uc_get_mma_content_rsp(JC_CHAR *src_fname_p, kal_uint8 *buffer_p, U32 buffer_index, U32 xml_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JDD_FILE fh = NULL;
    kal_bool more = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO,
                         "JMMS UC : get_mma_content_rsp(%x %x %d %d)", src_fname_p, buffer_p, buffer_index, xml_size);

    if (g_jmms_context->jmms_fs_handle == NULL)
    {
        if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
        {
            goto END_HANDLE;
        }
    }
    fh = jdd_FSOpen(g_jmms_context->jmms_fs_handle, (U16*) src_fname_p, E_OPEN_READ_MODE);

    if (fh)
    {
        JC_UINT32 byte_read = 0;
        U32 buffer_size = ((xml_size - (MMI_JMMS_UC_MAX_XML_SIZE_IN_PEER_BUFFER * buffer_index)) >
                           MMI_JMMS_UC_MAX_XML_SIZE_IN_PEER_BUFFER) ? MMI_JMMS_UC_MAX_XML_SIZE_IN_PEER_BUFFER
            : (xml_size - (MMI_JMMS_UC_MAX_XML_SIZE_IN_PEER_BUFFER * buffer_index));

        JC_CHAR *file_buffer_p = jdd_MemAlloc(sizeof(JC_CHAR) * buffer_size, 1);

        ASSERT(buffer_p != NULL);

        jdd_FSSeek(fh, MMI_JMMS_UC_MAX_XML_SIZE_IN_PEER_BUFFER * buffer_index, E_FILE_SEEK_SET);
        byte_read = jdd_FSRead(file_buffer_p, buffer_size, 1, fh);
        byte_read = buffer_size;
        jdd_FSClose(fh);

        memcpy((kal_uint8*) buffer_p, (kal_uint8*) file_buffer_p, buffer_size);
        more = (MMI_JMMS_UC_MAX_XML_SIZE_IN_PEER_BUFFER * buffer_index + byte_read < xml_size);
        if (g_jmms_context->jmms_fs_handle != NULL)
        {
            jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
            g_jmms_context->jmms_fs_handle = NULL;
        }
        if (file_buffer_p)
        {
            jdd_MemFree(file_buffer_p);
            file_buffer_p = NULL;
        }
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC : get_mma_content_rsp() more:%d", more);

        return more;
    }
  END_HANDLE:
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC : get_mma_content_rsp() Error");

    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_make_address_list
 * DESCRIPTION
 *  generate address list
 * PARAMETERS
 *  address_str_p       [IN]         
 *  group_type          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_jmms_uc_make_address_list(S8 *address_str_p, mmi_uc_address_group_type_enum group_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = 0;
    S8 *str_p = NULL;
    S32 start_index = 0;
    MMI_BOOL is_email = MMI_FALSE;
    S32 len_to_copy = 0;
    mmi_uc_addr_struct *addr_list_p = NULL;
    mmi_uc_addr_struct *head_address_p = NULL;
    mmi_uc_addr_struct *addr_list_tail_p = NULL;
    U8 count = 0;
    U8 temp_ucs2[(MAX_POSSIBLE_NUMBER_LENGHT_SENT + 1) * ENCODING_LENGTH] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC : make_address_list() Enter gp:%d", group_type);

    /* Getting addresses from one string */
    if (address_str_p != NULL)
    {
        str_p = (S8*) (address_str_p);
        len = 0;
        start_index = 0;

        while (mmi_ucs2cmp(str_p, "\0") != 0)
        {
            is_email = MMI_FALSE;
            while (((*str_p) != ';') && ((*str_p) != '\0'))
            {
                if ((*str_p) == '@')
                {
                    is_email = MMI_TRUE;
                }

                len++;
                str_p = str_p + ENCODING_LENGTH;
            }

            if (is_email == MMI_FALSE && len > (MAX_POSSIBLE_NUMBER_LENGHT_SENT))
            {
                len_to_copy = MAX_POSSIBLE_NUMBER_LENGHT_SENT;
            }
            else if (is_email == MMI_TRUE && len > (MAX_POSSIBLE_EMAIL_LENGHT_SENT))
            {
                len_to_copy = MAX_POSSIBLE_EMAIL_LENGHT_SENT;
            }
            else
            {
                len_to_copy = len;
            }
            count++;
            addr_list_p = (mmi_uc_addr_struct*) jdd_MemAlloc(sizeof(mmi_uc_addr_struct), 1);
            if (addr_list_p == NULL)
            {
                goto ERROR_HANDLE;
            }
            if (is_email == MMI_TRUE)
            {
                addr_list_p->addr = (U8*) jdd_MemAlloc(sizeof(S8), (len_to_copy + 1) * ENCODING_LENGTH);
                if (addr_list_p->addr == NULL)
                {
                    goto ERROR_HANDLE;
                }
                memcpy(
                    (S8*) addr_list_p->addr,
                    (S8*) (address_str_p + start_index * ENCODING_LENGTH),
                    (len_to_copy) * ENCODING_LENGTH);
                addr_list_p->type = MMI_UC_ADDRESS_TYPE_EMAIL;
                addr_list_p->group = group_type;
            }
            else
            {
                mmi_ucs2ncpy((S8*) temp_ucs2, (S8*) (address_str_p + start_index * ENCODING_LENGTH), len_to_copy);
                addr_list_p->addr = (U8*) jdd_MemAlloc(sizeof(S8), (len_to_copy + 1));
                if (addr_list_p->addr == NULL)
                {
                    goto ERROR_HANDLE;
                }
                mmi_ucs2_to_asc((S8*) addr_list_p->addr, (S8*) temp_ucs2);
                addr_list_p->type = MMI_UC_ADDRESS_TYPE_PHONE_NUMBER;
                addr_list_p->group = group_type;
            }

            start_index = start_index + len + 1;
            len = 0;
            if ((*str_p) != '\0')
            {
                str_p = str_p + ENCODING_LENGTH;
            }
            if (is_email == MMI_FALSE && !IsValidPhoneNumber((JC_INT8*) addr_list_p->addr, (JC_CHAR*) temp_ucs2, 0))
            {
                jdd_MemFree(addr_list_p->addr);
                jdd_MemFree(addr_list_p);
                addr_list_p = NULL;
                count--;
                continue;
            }
            /* Make the Addresses list */
            if (head_address_p == NULL)
            {
                head_address_p = addr_list_p;
                addr_list_p->previous = NULL;
                addr_list_tail_p = head_address_p;
            }
            else
            {
                addr_list_tail_p->next = addr_list_p;
                addr_list_p->previous = addr_list_tail_p;
            }
            addr_list_tail_p = addr_list_p;
            addr_list_p->next = NULL;
            addr_list_p = NULL;
        }
    }
    switch (group_type)
    {
        case MMI_UC_ADDRESS_GROUP_TYPE_TO:
        {
            g_jmms_context->uc_xml_msg_p->to_head = head_address_p;
            g_jmms_context->uc_xml_msg_p->to_num = count;
            break;
        }
        case MMI_UC_ADDRESS_GROUP_TYPE_CC:
        {
            g_jmms_context->uc_xml_msg_p->cc_head = head_address_p;
            g_jmms_context->uc_xml_msg_p->cc_num = count;
            break;
        }
        case MMI_UC_ADDRESS_GROUP_TYPE_BCC:
        {
            g_jmms_context->uc_xml_msg_p->bcc_head = head_address_p;
            g_jmms_context->uc_xml_msg_p->bcc_num = count;
            break;
        }
        case MMI_UC_ADDRESS_GROUP_TYPE_FROM:
        {
            g_jmms_context->uc_xml_msg_p->from = head_address_p;
            break;
        }
        default:
            break;
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC : make_address_list() Successful gp:%d", group_type);
    head_address_p = NULL;
    addr_list_tail_p = NULL;
    return JC_OK;
  ERROR_HANDLE:
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC : make_address_list() Error gp:%d", group_type);
    if (addr_list_p != NULL)
    {
        if (addr_list_p->addr != NULL)
        {
            jdd_MemFree(addr_list_p->addr);
        }
        jdd_MemFree(addr_list_p);
        addr_list_p = NULL;
    }
    while (head_address_p)
    {
        addr_list_p = head_address_p->next;
        jdd_MemFree(head_address_p->addr);
        jdd_MemFree(head_address_p);
        head_address_p = addr_list_p;
    }
    return JC_ERR_MEMORY_ALLOCATION;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_add_subject_string
 * DESCRIPTION
 *  add subject in list
 * PARAMETERS
 *  subject_string_p        [IN]         
 *  length                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_add_subject_string(JC_CHAR *subject_string_p, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC: add_subject_string(sb:%x)", subject_string_p);

    memset(g_jmms_context->uc_xml_msg_p->subject, 0, (MMI_UC_MAX_SUBJECT_LEN + 1) * ENCODING_LENGTH);

    if ((g_jmms_context->uc_creation_mode == MMA_MODE_REPLY ||
         g_jmms_context->uc_creation_mode == MMA_MODE_REPLY_ALL ||
         g_jmms_context->uc_creation_mode == MMA_MODE_FORWARD) &&
        ((jdi_UtilsStartsWithTchar
          ((JC_CHAR*) subject_string_p, (JC_CHAR*) GetString(STR_ID_JMMS_VIEW_DEFAULT_FORWARD_STRING)) != 0) &&
         (jdi_UtilsStartsWithTchar
          ((JC_CHAR*) subject_string_p, (JC_CHAR*) GetString(STR_ID_JMMS_VIEW_DEFAULT_REPLY_STRING)) != 0)))
    {
        len = mmi_ucs2strlen((S8*) GetString(STR_ID_JMMS_VIEW_DEFAULT_FORWARD_STRING));
        length += (len * 2);
        if (g_jmms_context->uc_creation_mode == MMA_MODE_FORWARD)
        {
            mmi_ucs2cpy(
                (S8*) g_jmms_context->uc_xml_msg_p->subject,
                (PS8) GetString(STR_ID_JMMS_VIEW_DEFAULT_FORWARD_STRING));
        }
        else
        {
            mmi_ucs2cpy(
                (S8*) g_jmms_context->uc_xml_msg_p->subject,
                (PS8) GetString(STR_ID_JMMS_VIEW_DEFAULT_REPLY_STRING));
        }
        if (length > MMI_UC_MAX_SUBJECT_LEN * ENCODING_LENGTH)
        {
            mmi_ucs2ncat(
                (S8*) g_jmms_context->uc_xml_msg_p->subject,
                (PS8) (subject_string_p),
                (MMI_UC_MAX_SUBJECT_LEN - len));
        }
        else
        {
            mmi_ucs2cat((S8*) g_jmms_context->uc_xml_msg_p->subject, (PS8) (subject_string_p));
        }
    }
    else
    {
        if (length > (MMI_UC_MAX_SUBJECT_LEN * ENCODING_LENGTH))
        {
            mmi_ucs2ncpy((S8*) g_jmms_context->uc_xml_msg_p->subject, (PS8) (subject_string_p), MMI_UC_MAX_SUBJECT_LEN);
        }
        else
        {
            mmi_ucs2cpy((S8*) g_jmms_context->uc_xml_msg_p->subject, (PS8) (subject_string_p));
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_fill_mms_sending_settings
 * DESCRIPTION
 *  fill the sending setting struct to provide to UC
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_fill_mms_sending_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC: fill_mms_sending_settings()");

    if (g_jmms_context && g_jmms_context->uc_xml_msg_p)
    {
        MESSAGE_HEADERS *pMsgHeaders = NULL;

        mmi_jmms_jdi_get_msg_headers(g_jmms_context->msg_handle, &pMsgHeaders);

        if (pMsgHeaders != NULL)
        {
            if (pMsgHeaders->eMsgType == E_MSG_TYPE_SEND)
            {
                MESSAGE_SEND *pMessageSend = NULL;

                pMessageSend = pMsgHeaders->pHeaders;
                g_jmms_context->uc_xml_msg_p->priority = mmi_jmms_uc_conf_get_local_priority(pMessageSend->eMsgPriority);
                g_jmms_context->uc_xml_msg_p->expiry_time = mmi_jmms_uc_conf_get_local_expiry_time(pMessageSend->uiExpiryTime);
                g_jmms_context->uc_xml_msg_p->delivery_report = (pMessageSend->bDeliveryReport == E_OFF) ? FALSE : TRUE;
                g_jmms_context->uc_xml_msg_p->read_report = (pMessageSend->bReadReport == E_OFF) ? FALSE : TRUE;
                g_jmms_context->uc_xml_msg_p->sender_visibility = ((pMessageSend->bHideSender) == E_OFF) ? TRUE : FALSE;
                g_jmms_context->uc_xml_msg_p->delivery_time = mmi_jmms_uc_conf_get_local_delivery_time(pMessageSend->uiDeliveryTime);
                g_jmms_context->uc_xml_msg_p->layout = mmi_jmms_uc_conf_get_mms_resion_layout();
            }
            else if (pMsgHeaders->eMsgType == E_MSG_TYPE_RECEIVE)
            {
                MESSAGE_RETRIEVAL *pMessageReceive = NULL;

                pMessageReceive = pMsgHeaders->pHeaders;
                g_jmms_context->uc_xml_msg_p->priority = mmi_jmms_uc_conf_get_local_priority(pMessageReceive->eMsgPriority);
                g_jmms_context->uc_xml_msg_p->expiry_time = mmi_jmms_uc_conf_get_expiry_time();
                g_jmms_context->uc_xml_msg_p->delivery_report =
                    (pMessageReceive->bDeliveryReport == E_OFF) ? FALSE : TRUE;
                g_jmms_context->uc_xml_msg_p->read_report = (pMessageReceive->bReadReport == E_OFF) ? FALSE : TRUE;
                g_jmms_context->uc_xml_msg_p->sender_visibility =
                    (mmi_jmms_uc_sending_settings_sender_visibility() == E_ON) ? TRUE : FALSE;
                g_jmms_context->uc_xml_msg_p->delivery_time = mmi_jmms_uc_conf_get_delivery_time();
                g_jmms_context->uc_xml_msg_p->layout = mmi_jmms_uc_conf_get_mms_resion_layout();
            }
        }
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_get_text_info
 * DESCRIPTION
 *  APP can use this utility function to get the text info of buffer.
 * PARAMETERS
 *  text_info       [OUT]       
 *  text_buffer     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_get_text_info(mmi_uc_text_object_info_struct *text_info, U8 *text_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 counter;
    U32 len;
    U16 C;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = mmi_ucs2strlen((PS8) text_buffer);
    text_info->char_count = 0;
    text_info->extension_char_count = 0;
    text_info->UCS2_count = 0;

    /* What if the length of the text is more than the buffer the category has for insertion */
    /* We will update context only upto the limit we allow it to be inserted */

    if (len > JMMS_COMPOSE_TEXT_LENGTH)
    {
        len = JMMS_COMPOSE_TEXT_LENGTH;
    }

    text_info->char_count = len;

    for (counter = 0; counter < (len * ENCODING_LENGTH); counter += ENCODING_LENGTH)
    {
        /* text_buffer maybe at odd address so better get into a local */
        C = ((U16) text_buffer[counter + 1] << 8) | ((U8) text_buffer[counter]);
        if (JMMS_TEST_GSM_EXTENDED(C))
        {
            ++text_info->extension_char_count;
        }
        else
        {
            if (text_buffer[counter + 1] != 0x00)
            {
                ++text_info->UCS2_count;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_is_object_present
 * DESCRIPTION
 *  Tells whether the object has been already added.
 * PARAMETERS
 *  object_head_p       [?]         
 *  file_path           [?]         
 *  offset              [IN]        
 * RETURNS
 *  JC_RETCODE
 *****************************************************************************/
mmi_uc_object_struct *mmi_jmms_uc_is_object_present(mmi_uc_object_struct *object_head_p, U16 *file_path, U32 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (object_head_p == NULL)
    {
        return NULL;
    }
    while (object_head_p != NULL)
    {
        if (mmi_ucs2cmp((const S8*)object_head_p->file_path, (const S8*)file_path) == 0 &&
            object_head_p->offset == offset)
        {
            break;
        }
        object_head_p = object_head_p->next;
    }
    return object_head_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_create_object_list
 * DESCRIPTION
 *  It creates the object list of MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  JC_RETCODE
 *****************************************************************************/
JC_RETCODE mmi_jmms_uc_create_object_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_slide_struct *slide_head_p = NULL;
    mmi_uc_slide_struct *slide_tail_p = NULL;
    mmi_uc_slide_struct *slide_data_p = NULL;
    mmi_uc_object_struct *object_head_p = NULL;
    mmi_uc_object_struct *object_p = NULL, *object_tail_p = NULL;
    U8 page_count = 0, object_id_count = 0, inline_media_count = 0, attachment_media_count = 0; /* text_media = 0, video_media = 0, audio_media = 0, image_media = 0; */
    U8 count = 0, count_m = 1;
    mmi_uc_text_object_info_struct text_info_object;
    mmi_uc_object_info_struct media_info_object;
    MEDIA_INFO *media_info_p;
    JC_RETCODE ret_code;
    JC_UINT32 slide_time;
    mmi_uc_attachment_info_struct *attachment_object_p = NULL, *attachment_object_head_p = NULL;
    mmi_uc_attachment_info_struct *attachment_object_tail_p = NULL;
    S8 *dest_fname_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC: create_object_list() mode:%d", g_jmms_context->uc_creation_mode);
    mmi_jmms_jdi_get_total_pages(g_jmms_context->msg_handle, &page_count);

    if (g_jmms_context->uc_creation_mode != MMA_MODE_SEND && g_jmms_context->uc_creation_mode != MMA_MODE_FORWARD)
    {
        for (count = 1; count <= page_count; count++)
        {
            slide_data_p = (mmi_uc_slide_struct*) jdd_MemAlloc(sizeof(mmi_uc_slide_struct), 1);
            if (slide_data_p == NULL)
            {
                ret_code = JC_ERR_MEMORY_ALLOCATION;
                goto ERROR_HANDLE;
            }
            slide_data_p->slide_num = count;
            ret_code = mmi_jmms_jdi_get_media_list(
                        g_jmms_context->msg_handle,
                        count,
                        &media_info_p,
                        &inline_media_count,
                        E_FALSE);
            mmi_jmms_jdi_get_page_timer(g_jmms_context->msg_handle, count, &slide_time);

            slide_data_p->duration = slide_time / 1000;

            PRINT_INFORMATION_2(MMI_TRACE_INFO,
                                 "JMMS UC: create_object_list() pg %d/%d m:%d t:%d", count, page_count,
                                 inline_media_count, slide_data_p->duration);

            for (count_m = 1; count_m <= inline_media_count; count_m++)
            {
                if (media_info_p->pMimeInfo->MimeHeaders.pObjectName == NULL ||
                    media_info_p->eMediaType == E_MEDIA_OTHERS)
                {
                    MMI_ASSERT(0);
                }
                if (media_info_p->eMediaType == E_MEDIA_TEXT &&
                    mmi_ucs2strlen((S8*) media_info_p->pMimeInfo->ContentData.pBuffer) == 0)
                {
                    media_info_p = media_info_p->pNext;
                    continue;
                }
                if (media_info_p->uiMediaID == 0)
                {
                    MMI_ASSERT(0);
                }
                if (media_info_p->eMediaType != E_MEDIA_TEXT)
                {
                    object_p = mmi_jmms_uc_is_object_present(
                                object_head_p,
                                media_info_p->pMimeInfo->ContentData.pFileName,
                                media_info_p->pMimeInfo->ContentData.uiStartOffset);
                }
                if (object_p)
                {
                    switch (media_info_p->eMediaType)
                    {
                        case E_MEDIA_IMAGE:
                        {
                            mmi_jmms_uc_create_media_object_list(&media_info_object, media_info_p->uiMediaID, count);
                            slide_data_p->image = media_info_object;
                            slide_data_p->image.id = object_p->id;
                            slide_data_p->image.object = object_p;
                            break;
                        }
                        case E_MEDIA_AUDIO:
                        {
                            mmi_jmms_uc_create_media_object_list(&media_info_object, media_info_p->uiMediaID, count);
                            slide_data_p->audio = media_info_object;
                            slide_data_p->audio.id = object_p->id;
                            slide_data_p->audio.object = object_p;
                            break;
                        }
                        case E_MEDIA_VIDEO:
                        {
                            mmi_jmms_uc_create_media_object_list(&media_info_object, media_info_p->uiMediaID, count);
                            slide_data_p->video = media_info_object;
                            slide_data_p->video.id = object_p->id;
                            slide_data_p->video.object = object_p;
                            break;
                        }
                    }
                    media_info_p = media_info_p->pNext;
                    object_p->reference_count++;
                    object_p = NULL;
                    continue;
                }
                object_p = (mmi_uc_object_struct*) jdd_MemAlloc(sizeof(mmi_uc_object_struct), 1);
                if (object_p == NULL)
                {
                    ret_code = JC_ERR_MEMORY_ALLOCATION;
                    goto ERROR_HANDLE;
                }

                object_p->file_path = (U16*) jdd_MemAlloc((MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH, 1);
                if (object_p->file_path == NULL)
                {
                    ret_code = JC_ERR_MEMORY_ALLOCATION;
                    goto ERROR_HANDLE;
                }
                memset(object_p->file_path, 0, (MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH);
                object_p->file_name = (U16*) jdd_MemAlloc((MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH, 1);
                if (object_p->file_name == NULL)
                {
                    jdd_MemFree(object_p->file_path);
                    ret_code = JC_ERR_MEMORY_ALLOCATION;
                    goto ERROR_HANDLE;
                }
                memset(object_p->file_name, 0, (MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH);
                object_p->offset = media_info_p->pMimeInfo->ContentData.uiStartOffset;
                // object_p->file_path; /* NULL terminator is needed. */
                if (media_info_p->pMimeInfo->ContentData.pFileName != NULL)
                {
                    mmi_ucs2ncpy(
                        (S8*) object_p->file_path,
                        (S8*) media_info_p->pMimeInfo->ContentData.pFileName,
                        MMA_MAX_INTERNAL_FILENAME_LENGTH);
                }
                /* object_p->file_name; */
                if (media_info_p->pMimeInfo->MimeHeaders.pObjectName != NULL)
                {
                    mmi_ucs2ncpy(
                        (S8*) object_p->file_name,
                        (S8*) media_info_p->pMimeInfo->MimeHeaders.pObjectName,
                        MMA_MAX_INTERNAL_FILENAME_LENGTH);
                }

            #ifdef __DRM_SUPPORT__
                if (media_info_p->eMediaType != E_MEDIA_TEXT)
                {
                    if (jdd_MsgConfigIsDRMTypeSupported((S8*) media_info_p->pMimeInfo->MimeHeaders.pContentType) ==
                        E_TRUE)
                    {
                        JDD_FSHANDLE vFileSysHandle = NULL;
                        JDD_FILE file_handle = NULL;
                        JC_CHAR *vfilename_p = NULL;
                        mma_drm_type_enum drm_method = MMA_DRM_NONE;

                        ret_code = jdd_FSInitialize(&vFileSysHandle);
                        if (JC_OK != ret_code)
                        {
                            ret_code = JC_ERR_FILE_SYS_INIT;
                            goto ERROR_HANDLE;
                        }
                        file_handle = jdd_FSOpen(
                                        (JDD_FSHANDLE) jdd_MsgConfigGetFSHandle(),
                                        object_p->file_path,
                                        E_OPEN_READ_MODE);
                        ret_code = jdd_FSGetVirtualFileName(
                                    file_handle,
                                    &(vfilename_p),
                                    object_p->offset,
                                    media_info_p->pMimeInfo->ContentData.uiTotalOrgSize);

                        drm_method = mmi_jmms_get_drm_method_type((kal_wchar*) vfilename_p);
                        if (drm_method == DRM_METHOD_NONE)
                        {
                            object_p->drm_type = MMA_DRM_NONE;
                        }
                        else if (drm_method == DRM_METHOD_FORWARD_LOCK || drm_method == DRM_METHOD_COMBINED_DELIVERY)
                        {
                            object_p->drm_type = MMA_DRM_FL_CD;
                        }
                        else
                        {
                            U8 permission = DRM_PERMISSION_NONE;

                            if (media_info_p->eMediaType == E_MEDIA_AUDIO || media_info_p->eMediaType == E_MEDIA_VIDEO)
                            {
                                permission = DRM_PERMISSION_PLAY;
                            }
                            else if (media_info_p->eMediaType == E_MEDIA_IMAGE)
                            {
                                permission = DRM_PERMISSION_DISPLAY;
                            }

                            if (mmi_jmms_is_media_drm_permitted((JC_CHAR*) vfilename_p, permission) == E_TRUE)
                            {
                                object_p->drm_type = MMA_DRM_SD;
                            }
                            else
                            {
                                object_p->drm_type = MMA_DRM_SD_NO_RIGHT;
                            }

                        }
                        if (file_handle != NULL)
                        {
                            jdd_FSClose(file_handle);
                        }
                        if (vfilename_p != NULL)
                        {
                            jdd_MemFree(vfilename_p);
                            vfilename_p = NULL;
                        }
                    }
                    else
                    {
                        object_p->drm_type = MMA_DRM_NONE;
                    }
                }
                else
                {
                    object_p->drm_type = MMA_DRM_NONE;
                }
            #else /* __DRM_SUPPORT__ */ 
                object_p->drm_type = MMA_DRM_NONE;
            #endif /* __DRM_SUPPORT__ */ 
                object_p->is_virtual_file = 1;
                object_p->reference_count = 1;

                switch (media_info_p->eMediaType)
                {
                    case E_MEDIA_TEXT:
                    {
                        FS_HANDLE dest_handle;
                        JC_INT8 mms_folder_path_ascii[FMGR_MAX_PATH_LEN] = {0};
                        JC_CHAR mms_folder_path_ucs2[FMGR_MAX_PATH_LEN] = {0};
                        S8 *buffer_p = NULL;    /* size should be JMMS_COMPOSE_TEXT_LENGTH * ENCODING_LENGTH + ENCODING_LENGTH */
                        U32 length, write_len;
                        S32 result;
                        JC_INT32 drive_letter = FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE);

                    #ifdef MMS_IN_LARGE_STORAGE
                        drive_letter = FS_GetDrive(FS_DRIVE_I_SYSTEM, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
                    #endif 
                        sprintf(
                            mms_folder_path_ascii,
                            "%c:\\%s\\T%0.3d.txt",
                            drive_letter,
                            TEMP_ATTACH_FOLDER_PATH,
                            object_id_count);
                        app_asc_str_to_ucs2_str(
                            (kal_int8*) mms_folder_path_ucs2,
                            (kal_int8*) mms_folder_path_ascii);
                        mmi_ucs2ncpy(
                            (S8*) object_p->file_path,
                            (S8*) mms_folder_path_ucs2,
                            MMA_MAX_INTERNAL_FILENAME_LENGTH);
                        memset(mms_folder_path_ascii, 0, FMGR_MAX_PATH_LEN);
                        memset(mms_folder_path_ucs2, 0, FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
                        sprintf(mms_folder_path_ascii, "T%0.3d.txt", object_id_count);
                        app_asc_str_to_ucs2_str(
                            (kal_int8*) mms_folder_path_ucs2,
                            (kal_int8*) mms_folder_path_ascii);
                        mmi_ucs2ncpy(
                            (S8*) object_p->file_name,
                            (S8*) mms_folder_path_ucs2,
                            MMA_MAX_INTERNAL_FILENAME_LENGTH);

                        buffer_p =
                            (S8*) jdd_MemAlloc(
                                    sizeof(S8),
                                    JMMS_COMPOSE_TEXT_LENGTH * ENCODING_LENGTH + ENCODING_LENGTH);
                        dest_handle = FS_Open(object_p->file_path, FS_CREATE_ALWAYS | FS_READ_WRITE);
                        if (dest_handle < 0)
                        {
                            ret_code = JC_ERR_FILE_OPEN;
                            goto ERROR_HANDLE;
                        }
                        length = mmi_chset_ucs2_to_utf8_string(
                                    (kal_uint8*) buffer_p,
                                    JMMS_COMPOSE_TEXT_LENGTH * ENCODING_LENGTH,
                                    (kal_uint8*) media_info_p->pMimeInfo->ContentData.pBuffer);
                        result = FS_Write(dest_handle, buffer_p, length - 1, &write_len);
                        if (result != FS_NO_ERROR)
                        {
                            ret_code = JC_ERR_FILE_WRITE;
                            goto ERROR_HANDLE;
                        }
                        FS_Close(dest_handle);
                        jdd_MemFree(buffer_p);
                        buffer_p = NULL;
                        object_id_count++;
                        object_p->offset = 0;
                        object_p->is_virtual_file = 1;
                        mmi_jmms_uc_create_text_object_list(&text_info_object, media_info_p->uiMediaID, count);
                        if (media_info_p->PresentationInfo.pTextAttributes != NULL)
                        {
                            JC_UINT32 color = MMA_DEFAULT_SMIL_FG_COLOR;

                            color =
                                (JC_UINT32) GetColorValue(media_info_p->PresentationInfo.pTextAttributes->pFontColor);
                            text_info_object.foreground_color = color;
                        }
                        else
                        {
                            text_info_object.foreground_color = MMA_DEFAULT_SMIL_FG_COLOR;
                        }
                        slide_data_p->text = text_info_object;
                        mmi_jmms_uc_get_text_info(&text_info_object, media_info_p->pMimeInfo->ContentData.pBuffer);
                        text_info_object.utf8_msg_len = write_len;      /* Msg Len in UTF8 */
                        slide_data_p->text.id = object_id_count;
                        object_p->id = object_id_count;
                        object_p->type = MMI_UC_OBJECT_TYPE_TEXT;
                        slide_data_p->text.object = object_p;
                        object_p->size = write_len; /* UTF8 size for text object */

                        break;
                    }
                    case E_MEDIA_IMAGE:
                    {
                        object_id_count++;
                        mmi_jmms_uc_create_media_object_list(&media_info_object, media_info_p->uiMediaID, count);
                        slide_data_p->image = media_info_object;
                        slide_data_p->image.id = object_id_count;
                        object_p->id = object_id_count;
                        object_p->type = MMI_UC_OBJECT_TYPE_IMAGE;
                        slide_data_p->image.object = object_p;
                        object_p->size = media_info_p->pMimeInfo->ContentData.uiTotalSize;      /* file size for non-text object. */

                        break;
                    }
                    case E_MEDIA_AUDIO:
                    {
                        object_id_count++;
                        mmi_jmms_uc_create_media_object_list(&media_info_object, media_info_p->uiMediaID, count);
                        slide_data_p->audio = media_info_object;
                        slide_data_p->audio.id = object_id_count;
                        object_p->id = object_id_count;
                        object_p->type = MMI_UC_OBJECT_TYPE_AUDIO;
                        slide_data_p->audio.object = object_p;
                        object_p->size = media_info_p->pMimeInfo->ContentData.uiTotalSize;      /* file size for non-text object. */
                        break;
                    }
                    case E_MEDIA_VIDEO:
                    {
                        object_id_count++;
                        mmi_jmms_uc_create_media_object_list(&media_info_object, media_info_p->uiMediaID, count);
                        slide_data_p->video = media_info_object;
                        slide_data_p->video.id = object_id_count;
                        object_p->id = object_id_count;
                        object_p->type = MMI_UC_OBJECT_TYPE_VIDEO;
                        slide_data_p->video.object = object_p;
                        object_p->size = media_info_p->pMimeInfo->ContentData.uiTotalSize;      /* file size for non-text object. */

                        break;
                    }
                }
                /* Object list creation */
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC: create_object_list() Object:%d", object_id_count);
                if (object_p != NULL)
                {
                    if (object_head_p == NULL)
                    {
                        object_head_p = object_p;
                        object_p->previous = NULL;
                        object_tail_p = object_head_p;
                    }
                    else
                    {
                        object_tail_p->next = object_p;
                        object_p->previous = object_tail_p;
                    }
                    object_tail_p = object_p;
                    object_p->next = NULL;
                    object_p = NULL;
                }
                media_info_p = media_info_p->pNext;

            }
            /* Slide list creation */
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC: create_object_list() Slide:%d", slide_data_p->slide_num);
            if (slide_data_p != NULL)
            {
                if (slide_head_p == NULL)
                {
                    slide_head_p = slide_data_p;
                    slide_data_p->previous = NULL;
                    slide_tail_p = slide_head_p;
                }
                else
                {
                    slide_tail_p->next = slide_data_p;
                    slide_data_p->previous = slide_tail_p;
                }
                slide_tail_p = slide_data_p;
                slide_data_p->next = NULL;
                slide_data_p = NULL;
            }

        }
        g_jmms_context->uc_xml_msg_p->slide_head = slide_head_p;
    }
    else
    {
        for (count = 1; count <= page_count; count++)
        {
            ret_code = mmi_jmms_jdi_get_media_list(
                        g_jmms_context->msg_handle,
                        count,
                        &media_info_p,
                        &inline_media_count,
                        E_FALSE);
            object_id_count = object_id_count + inline_media_count;
        }
    }
    if (page_count > 0)
    {
        JC_UINT32 height, width;
        JC_INT8 *bg_color_str_p;
        JC_UINT32 color = MMA_DEFAULT_SMIL_BG_COLOR;

        ret_code = mmi_jmms_jdi_get_smil_root_layout(g_jmms_context->msg_handle, &height, &width, &bg_color_str_p);
        color = (JC_UINT32) GetColorValue(bg_color_str_p);
        g_jmms_context->uc_xml_msg_p->background_color = color;
    }

    /* Attachment Object list creation */
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC: create_object_list() Attachments");
    ret_code = mmi_jmms_jdi_get_media_list(g_jmms_context->msg_handle, 0, &media_info_p, &attachment_media_count, E_TRUE);
    attachment_media_count =
        (attachment_media_count >
         wap_custom_get_max_mms_attachment())? wap_custom_get_max_mms_attachment() : attachment_media_count;
    for (count_m = 0; count_m < attachment_media_count; count_m++)
    {
        object_p = (mmi_uc_object_struct*) jdd_MemAlloc(sizeof(mmi_uc_object_struct), 1);

        if (object_p != NULL)
        {

            object_p->file_path = (U16*) jdd_MemAlloc((MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH, 1);
            memset(object_p->file_path, 0, (MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH);
            object_p->file_name = (U16*) jdd_MemAlloc((MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH, 1);
            memset(object_p->file_name, 0, (MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH);
            object_p->offset = media_info_p->pMimeInfo->ContentData.uiStartOffset;

            if (g_jmms_context->jmms_fs_handle == NULL)
            {
                if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
                {
                    ret_code = JC_ERR_FILE_SYS_INIT;
                    goto ERROR_HANDLE;
                }
            }
            dest_fname_p =
                (S8*) jdd_FSFileNameTranslate(
                        g_jmms_context->jmms_fs_handle,
                        media_info_p->pMimeInfo->ContentData.pFileName);
            ASSERT(dest_fname_p != NULL);

            if (g_jmms_context->jmms_fs_handle != NULL)
            {
                jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
                g_jmms_context->jmms_fs_handle = NULL;
            }
            /* NULL terminator is needed. */
            mmi_ucs2ncpy(
                (S8*) object_p->file_path,
                (S8*) dest_fname_p, /* media_info_p->pMimeInfo->ContentData.pFileName, */
                MMA_MAX_INTERNAL_FILENAME_LENGTH);
            mmi_ucs2ncpy(
                (S8*) object_p->file_name,
                (S8*) media_info_p->pMimeInfo->MimeHeaders.pObjectName,
                MMA_MAX_INTERNAL_FILENAME_LENGTH);

            jdd_MemFree(dest_fname_p);

            if (media_info_p->pMimeInfo->bIsDRM != 0)
            {
                object_p->drm_type = media_info_p->pMimeInfo->pDRMInfo->eDRMType;       /* mma_drm_type_enum */
            }
            else
            {
                object_p->drm_type = MMA_DRM_NONE;
            }
            object_p->is_virtual_file = 1;
            object_p->reference_count = 1;
            object_id_count++;
            object_p->id = object_id_count;
            object_p->type = MMI_UC_OBJECT_TYPE_ATTACHMENT;
            object_p->size = media_info_p->pMimeInfo->ContentData.uiTotalSize;  /* file size for non-text object. */

            attachment_object_p =
                (mmi_uc_attachment_info_struct*) jdd_MemAlloc(sizeof(mmi_uc_attachment_info_struct), 1);
            if (attachment_object_p == NULL)
            {
                ret_code = JC_ERR_MEMORY_ALLOCATION;
                goto ERROR_HANDLE;
            }
            attachment_object_p->object = object_p;

            if (object_head_p == NULL)
            {
                object_head_p = object_p;
                object_p->previous = NULL;
                object_tail_p = object_head_p;
            }
            else
            {
                object_tail_p->next = object_p;
                object_p->previous = object_tail_p;
            }
            object_tail_p = object_p;
            object_p->next = NULL;
            object_p = NULL;

            if (attachment_object_head_p == NULL)
            {
                attachment_object_head_p = attachment_object_p;
                attachment_object_p->previous = NULL;
                attachment_object_tail_p = attachment_object_head_p;
            }
            else
            {
                attachment_object_tail_p->next = attachment_object_p;
                attachment_object_p->previous = attachment_object_tail_p;
            }
            attachment_object_tail_p = attachment_object_p;
            attachment_object_p->next = NULL;
            attachment_object_p = NULL;
            object_p = NULL;
        }
        else
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto ERROR_HANDLE;
        }
        media_info_p = media_info_p->pNext;
    }

    /* Object id counts */
    g_jmms_context->uc_xml_msg_p->total_object_num = object_id_count;
    g_jmms_context->uc_xml_msg_p->object_head = object_head_p;
    g_jmms_context->uc_xml_msg_p->total_slide_num = page_count;
    g_jmms_context->uc_xml_msg_p->attachment_head = attachment_object_head_p;
    g_jmms_context->uc_xml_msg_p->total_attachment_num = attachment_media_count;
    PRINT_INFORMATION_2(MMI_TRACE_INFO,
                         "JMMS UC: create_object_list() Pass rd:%d att:%d", ret_code, attachment_media_count);
    return ret_code;
  ERROR_HANDLE:
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC: create_object_list() Fail rd:%d", ret_code);
    if (ret_code != JC_OK)
    {
        while (object_head_p)
        {
            mmi_uc_object_struct *temp_object = NULL;

            jdd_MemFree(object_head_p->file_name);
            jdd_MemFree(object_head_p->file_path);
            object_head_p->file_name = NULL;
            object_head_p->file_path = NULL;
            temp_object = object_head_p;
            object_head_p = object_head_p->next;
            jdd_MemFree(temp_object);
        }
        while (slide_head_p)
        {
            mmi_uc_slide_struct *temp_slide = NULL;

            temp_slide = slide_head_p;
            slide_head_p = slide_head_p->next;
            jdd_MemFree(temp_slide);
        }
        while (slide_data_p)
        {
            mmi_uc_slide_struct *temp_slide = NULL;

            temp_slide = slide_data_p;
            slide_data_p = slide_data_p->next;
            jdd_MemFree(temp_slide);
        }
    }
    /* We can try to free list here. */
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_create_text_object_list
 * DESCRIPTION
 *  fill text object attributes
 * PARAMETERS
 *  text_info_object_p      [OUT]         
 *  jmms_media_id           [IN]        
 *  page_index              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_create_text_object_list(
        mmi_uc_text_object_info_struct *text_info_object_p,
        U32 jmms_media_id,
        U8 page_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE err_code = 0;
    JC_UINT32 height, width;
    JC_INT8 *bg_color_str_p;
    JC_UINT32 color = MMA_DEFAULT_SMIL_BG_COLOR;
    JC_UINT32 duration = 0, start_time = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC: create_text_object_list()");

    err_code = mmi_jmms_get_media_time(&start_time, &duration, jmms_media_id, page_index);
    err_code = mmi_jmms_jdi_get_smil_root_layout(g_jmms_context->msg_handle, &height, &width, &bg_color_str_p);
    color = (JC_UINT32) GetColorValue(bg_color_str_p);
    text_info_object_p->background_color = color;
    text_info_object_p->begin = start_time;
    text_info_object_p->end = start_time + duration;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_create_media_object_list
 * DESCRIPTION
 *  fill media attributes in object list
 * PARAMETERS
 *  media_info_object_p     [OUT]       
 *  jmms_media_id           [IN]        
 *  page_index              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_create_media_object_list(
        mmi_uc_object_info_struct *media_info_object_p,
        U32 jmms_media_id,
        U8 page_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 duration = 0, start_time = 0;
    JMMS_COMP_ERRCODE err_code = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC: create_media_object_list()");

    err_code = mmi_jmms_get_media_time(&start_time, &duration, jmms_media_id, page_index);
    media_info_object_p->begin = start_time;
    media_info_object_p->end = start_time + duration;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_create_msg_rsp
 * DESCRIPTION
 *  call create msg responce
 * PARAMETERS
 *  ret_code        [IN]        
 *  msg_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_create_msg_rsp(JC_RETCODE ret_code, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_result_enum mma_error_code = MMA_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC: create_msg_rsp(rt:%d, md:%d)", ret_code, msg_id);

    mma_error_code = mmi_jmms_uc_provide_mma_error_code(ret_code);
    mmi_jmms_uc_wap_mma_create_mms_rsp(mma_error_code, msg_id);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_preview_mms_from_msg_id
 * DESCRIPTION
 *  preview mms from message id
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_preview_mms_from_msg_id(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CONTENT_DATA content = {0, };
    U32 ui_msg_index = 0;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC: preview_mms_from_msg_id( md:%d)", msg_id);

    content.bIsStream = E_TRUE;
    mmi_jmms_get_message_index(g_jmms_context->store_handle, msg_id, &ui_msg_index);
    ret_code = mmi_jmms_uc_get_message(mmi_jmms_get_message_folder_type_from_id(msg_id), &content, ui_msg_index);
    mmi_jmms_deinit_mms_context(g_jmms_context);

    ret_code = mmi_jmms_jdi_parse_msg_buffer(&(g_jmms_context->msg_handle), &content, E_TYPE_MMS, E_FALSE);

    /* Async changes start */
    while (ret_code == JC_ERR_MMS_PARSE_PENDING)
    {
        ret_code = mmi_jmms_jdi_msg_parse_continue(g_jmms_context->msg_handle);
    }
    /* Async changes end */

    if (JC_OK != ret_code)
    {

    }
    mmi_jmms_deinit_view();
    ret_code = mmi_jmms_uc_pre_entery_view(&content);
    if (ret_code == JC_ERR_MMS_PARSE_PENDING)
    {
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_send_progress_ind
 * DESCRIPTION
 *  send progress status to UC
 * PARAMETERS
 *  msgid                       [IN]        
 *  percentage_of_progress      [IN]        
 *  retry                       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_send_progress_ind(U32 msgid, U32 percentage_of_progress, U8 retry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_uc_wap_mma_send_progress_ind(msgid, percentage_of_progress, retry);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_sending_complete
 * DESCRIPTION
 *  call api to send complete send report to UC
 * PARAMETERS
 *  msg_id              [IN]        
 *  result              [IN]        
 *  response_text_p     [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_sending_complete(U32 msg_id, mma_result_enum result, JC_CHAR *response_text_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC: sending_complete(rt:%d, md:%d)", result, msg_id);
    mmi_jmms_uc_wap_mma_send_rsp(msg_id, result, response_text_p);
    mmi_jmms_deinit_mms_context(g_jmms_context);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_sending_complete_rsp_for_cancel_send
 * DESCRIPTION
 *  call api to send complete send report to UC, if cancel by user
 * PARAMETERS
 *  msg_id              [IN]        
 *  result              [IN]        
 *  response_text_p     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_sending_complete_rsp_for_cancel_send(U32 msg_id, JC_BOOLEAN result, JC_CHAR *response_text_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO,
                         "JMMS UC: sending_complete_rsp_for_cancel_send(rt:%d, md:%d)", result, msg_id);
    if (result == E_TRUE)
    {
        mmi_jmms_uc_wap_mma_send_rsp(msg_id, MMA_RESULT_FAIL_USER_CANCEL, response_text_p);
    }
    else
    {
        mmi_jmms_uc_wap_mma_send_rsp(msg_id, MMA_RESULT_FAIL, response_text_p);
    }
    mmi_jmms_deinit_mms_context(g_jmms_context);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_send_stop_ind
 * DESCRIPTION
 *  call api to send rsp of stop indication
 * PARAMETERS
 *  result      [IN]        
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_send_stop_ind(kal_uint8 result, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC: send_stop_ind(rt:%d, md:%d)", result, msg_id);

    mmi_jmms_uc_wap_mma_cancel_send_rsp(result, msg_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_cancel_mms_sending_from_id
 * DESCRIPTION
 *  call api to cancel send of provided msg ID
 * PARAMETERS
 *  req_id      [IN]        
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_cancel_mms_sending_from_id(U32 req_id, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC: cancel_mms_sending_from_id(rd:%d, md:%d)", req_id, msg_id);

    g_jmms_context->uc_cancel_req_id = req_id;
    mmi_jmms_parse_continue_stop_timer();
    mmi_jmms_uc_cancel_mms_sending(msg_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_delete_addr
 * DESCRIPTION
 *  Delete address
 * PARAMETERS
 *  address     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_delete_addr(mmi_uc_addr_struct *address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_addr_struct *addr = address;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC: Enter mmi_jmms_uc_delete_addr()");
    switch (addr->group)
    {
        case MMI_UC_ADDRESS_GROUP_TYPE_TO:
        {
            if (g_jmms_context->uc_xml_msg_p->to_num == 1)
            {
                g_jmms_context->uc_xml_msg_p->to_num = 0;
                g_jmms_context->uc_xml_msg_p->to_head = NULL;
            }
            else
            {
                g_jmms_context->uc_xml_msg_p->to_num--;

                /* The first entry */
                if (addr == g_jmms_context->uc_xml_msg_p->to_head)
                {
                    g_jmms_context->uc_xml_msg_p->to_head = addr->next;
                    addr->next->previous = NULL;
                }
                /* The last entry */
                else if (addr->next == NULL)
                {
                    addr->previous->next = NULL;
                }
                else
                {
                    addr->next->previous = addr->previous;
                    addr->previous->next = addr->next;
                }
            }
        }
            break;

        case MMI_UC_ADDRESS_GROUP_TYPE_CC:
        {
            if (g_jmms_context->uc_xml_msg_p->cc_num == 1)
            {
                g_jmms_context->uc_xml_msg_p->cc_num = 0;
                g_jmms_context->uc_xml_msg_p->cc_head = NULL;
            }
            else
            {
                g_jmms_context->uc_xml_msg_p->cc_num--;

                /* The first entry */
                if (addr == g_jmms_context->uc_xml_msg_p->cc_head)
                {
                    g_jmms_context->uc_xml_msg_p->cc_head = addr->next;
                    addr->next->previous = NULL;
                }
                /* The last entry */
                else if (addr->next == NULL)
                {
                    addr->previous->next = NULL;
                }
                else
                {
                    addr->next->previous = addr->previous;
                    addr->previous->next = addr->next;
                }
            }
        }
            break;

        case MMI_UC_ADDRESS_GROUP_TYPE_BCC:
        {
            if (g_jmms_context->uc_xml_msg_p->bcc_num == 1)
            {
                g_jmms_context->uc_xml_msg_p->bcc_num = 0;
                g_jmms_context->uc_xml_msg_p->bcc_head = NULL;
            }
            else
            {
                g_jmms_context->uc_xml_msg_p->bcc_num--;

                /* The first entry */
                if (addr == g_jmms_context->uc_xml_msg_p->bcc_head)
                {
                    g_jmms_context->uc_xml_msg_p->bcc_head = addr->next;
                    addr->next->previous = NULL;
                }
                /* The last entry */
                else if (addr->next == NULL)
                {
                    addr->previous->next = NULL;
                }
                else
                {
                    addr->next->previous = addr->previous;
                    addr->previous->next = addr->next;
                }
            }
        }
            break;

        case MMI_UC_ADDRESS_GROUP_TYPE_FROM:
        {
            jdd_MemFree(addr);
            g_jmms_context->uc_xml_msg_p->from = NULL;
            return;
        }
            break;

        default:
        {
            MMI_ASSERT(0);
        }
            break;
    }
    jdd_MemFree(addr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_delete_object_from_list
 * DESCRIPTION
 *  delete object from list
 * PARAMETERS
 *  object      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_delete_object_from_list(mmi_uc_object_struct *object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC: Enter mmi_jmms_uc_delete_object_from_list()");
    if (object == g_jmms_context->uc_xml_msg_p->object_head)
    {
        g_jmms_context->uc_xml_msg_p->object_head = object->next;

        if (object->next)
        {
            object->next->previous = NULL;
        }
    }
    else
    {
        if (object->previous)
        {
            object->previous->next = object->next;
        }

        if (object->next)
        {
            object->next->previous = object->previous;
        }
    }
    g_jmms_context->uc_xml_msg_p->total_object_num--;

    if (object->file_name)
    {
        jdd_MemFree(object->file_name);
    }

    if (object->file_path)
    {
        jdd_MemFree(object->file_path);
    }

    jdd_MemFree(object);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_delete_attachment_from_list
 * DESCRIPTION
 *  delete attachment info from list
 * PARAMETERS
 *  att_p     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_delete_attachment_from_list(mmi_uc_attachment_info_struct *att_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC: Enter mmi_jmms_uc_delete_attachment_from_list()");
    if (att_p == g_jmms_context->uc_xml_msg_p->attachment_head)
    {
        g_jmms_context->uc_xml_msg_p->attachment_head = att_p->next;

        if (att_p->next)
        {
            att_p->next->previous = NULL;
        }
    }
    else
    {
        att_p->previous->next = att_p->next;

        if (att_p->next)
        {
            att_p->next->previous = att_p->previous;
        }
    }
    g_jmms_context->uc_xml_msg_p->total_attachment_num--;

    jdd_MemFree(att_p);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_delete_slide
 * DESCRIPTION
 *  delete slide
 * PARAMETERS
 *  slide       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_delete_slide(mmi_uc_slide_struct *slide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC: Enter mmi_jmms_uc_delete_slide()");

    if (slide == g_jmms_context->uc_xml_msg_p->slide_head)
    {
        g_jmms_context->uc_xml_msg_p->slide_head = slide->next;

        if (slide->next)
        {
            slide->next->previous = NULL;
        }
    }
    else
    {
        slide->previous->next = slide->next;

        if (slide->next)
        {
            slide->next->previous = slide->previous;
        }
    }
    g_jmms_context->uc_xml_msg_p->total_slide_num--;

    if (slide->next)
    {
        mmi_uc_slide_struct *update_slide = slide->next;

        while (update_slide)
        {
            update_slide->slide_num--;
            /* mmi_uc_update_text_object_path(update_slide); */
            update_slide = update_slide->next;
        }
    }

    jdd_MemFree(slide);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_delete_slide_with_object
 * DESCRIPTION
 *  delete slide
 * PARAMETERS
 *  slide       [OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_delete_slide_with_object(mmi_uc_slide_struct *slide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC: Enter mmi_jmms_uc_delete_slide_with_object()");
    if (slide->image.object)
    {
        slide->image.object->reference_count--;

        if (slide->image.object->reference_count == 0)
        {
            mmi_jmms_uc_delete_object_from_list(slide->image.object);
        }
    }

    if (slide->audio.object)
    {
        slide->audio.object->reference_count--;

        if (slide->audio.object->reference_count == 0)
        {
            mmi_jmms_uc_delete_object_from_list(slide->audio.object);
        }
    }

    if (slide->video.object)
    {
        slide->video.object->reference_count--;

        if (slide->video.object->reference_count == 0)
        {
            mmi_jmms_uc_delete_object_from_list(slide->video.object);
        }
    }

    if (slide->text.object)
    {
        mmi_jmms_uc_delete_object_from_list(slide->text.object);
    }

    mmi_jmms_uc_delete_slide(slide);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_distroy_xml_struct
 * DESCRIPTION
 *  free memory used in xml structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_distroy_xml_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC: Enter mmi_jmms_uc_distroy_xml_struct()");

    if (g_jmms_context->uc_xml_msg_p != NULL)
    {
        while (g_jmms_context->uc_xml_msg_p->to_head)
        {
            mmi_jmms_uc_delete_addr(g_jmms_context->uc_xml_msg_p->to_head);
        }

        while (g_jmms_context->uc_xml_msg_p->cc_head)
        {
            mmi_jmms_uc_delete_addr(g_jmms_context->uc_xml_msg_p->cc_head);
        }

        while (g_jmms_context->uc_xml_msg_p->bcc_head)
        {
            mmi_jmms_uc_delete_addr(g_jmms_context->uc_xml_msg_p->bcc_head);
        }

        while (g_jmms_context->uc_xml_msg_p->from)
        {
            mmi_jmms_uc_delete_addr(g_jmms_context->uc_xml_msg_p->from);
        }

        while (g_jmms_context->uc_xml_msg_p->slide_head)
        {
            mmi_jmms_uc_delete_slide_with_object(g_jmms_context->uc_xml_msg_p->slide_head);
        }

        while (g_jmms_context->uc_xml_msg_p->attachment_head)
        {
            mmi_jmms_uc_delete_object_from_list(g_jmms_context->uc_xml_msg_p->attachment_head->object);
            mmi_jmms_uc_delete_attachment_from_list(g_jmms_context->uc_xml_msg_p->attachment_head);
        }

        while (g_jmms_context->uc_xml_msg_p->object_head)
        {
            mmi_jmms_uc_delete_object_from_list(g_jmms_context->uc_xml_msg_p->object_head);
        }

        jdd_MemFree(g_jmms_context->uc_xml_msg_p);
        g_jmms_context->uc_xml_msg_p = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_send_message_async_callback
 * DESCRIPTION
 *  callback api to call after parse to send MMS
 * PARAMETERS
 *  ret_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_send_message_async_callback(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO,
                         "JMMS UC: Enter mmi_jmms_uc_send_message_async_callback() with ret_code=%d", ret_code);

    if (ret_code == JC_OK)
    {

        wap_mma_send_req_struct *req_info_p = (wap_mma_send_req_struct*) g_jmms_context->uc_req_rsp_info_holder_p;
        MESSAGE_HEADERS *pMsgHeaders = NULL;
        MESSAGE_SEND *send_p;

        ret_code = mmi_jmms_jdi_set_msg_type(g_jmms_context->msg_handle, E_TYPE_MMS);
        if (ret_code != JC_OK)
        {
            goto END;
        }

        ret_code = mmi_jmms_jdi_set_presentation_type(g_jmms_context->msg_handle, E_PRESENTATION_SMIL);
        if (ret_code != JC_OK)
        {
            goto END;
        }

        ret_code = mmi_jmms_jdi_get_msg_headers(g_jmms_context->msg_handle, &pMsgHeaders);
        if (ret_code != JC_OK || pMsgHeaders == NULL)
        {
            ret_code = JC_ERR_STORE_FILE_CORRUPTED;
            goto END;
        }

        send_p = (MESSAGE_SEND*) (pMsgHeaders->pHeaders);

        /* Test code */
        pMsgHeaders->pHeaders = (MESSAGE_SEND*) send_p;

        if (g_jmms_context->version == NULL)
        {
            g_jmms_context->version = jdd_MemAlloc(sizeof(S8), (MAX_VERSION_LENGTH + 1) * ENCODING_LENGTH);
        }
        if (g_jmms_context->version == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto END;
        }
        strcpy(g_jmms_context->version, (S8*) (send_p->pVersion));
        g_jmms_context->save_mms = MMI_FALSE;

        ret_code = mmi_jmms_uc_send_mms(g_jmms_context->msg_handle, req_info_p->msg_id);
        if (ret_code != JC_OK && ret_code != JC_ERR_MMS_ENCODE_PENDING)
        {
            if (g_jmms_context->parse_content_p != NULL)
            {
                if (g_jmms_context->parse_content_p->pFileName != NULL)
                {
                    jdd_MemFree(g_jmms_context->parse_content_p->pFileName);
                    g_jmms_context->parse_content_p->pFileName = NULL;
                }
                jdd_MemFree(g_jmms_context->parse_content_p);
                g_jmms_context->parse_content_p = NULL;
            }
            if (ret_code != JC_OK)
            {
                if (g_jmms_context->msg_handle != NULL)
                {
                    mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
                    g_jmms_context->msg_handle = NULL;
                }
            }
        }
        return;
    }
  END:
    if (g_jmms_context->parse_content_p != NULL)
    {
        if (g_jmms_context->parse_content_p->pFileName != NULL)
        {
            jdd_MemFree(g_jmms_context->parse_content_p->pFileName);
            g_jmms_context->parse_content_p->pFileName = NULL;
        }
        jdd_MemFree(g_jmms_context->parse_content_p);
        g_jmms_context->parse_content_p = NULL;
    }
    if (ret_code != JC_OK)
    {
        if (g_jmms_context->msg_handle != NULL)
        {
            mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
            g_jmms_context->msg_handle = NULL;
        }

    }
    /* send stop response to UC */
    mmi_jmms_uc_sending_complete(
        ((wap_mma_send_req_struct*) g_jmms_context->uc_req_rsp_info_holder_p)->msg_id,
        MMA_RESULT_FAIL,
        NULL);
    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_delete_screen_from_history_after_rsp
 * DESCRIPTION
 *  clear history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_delete_screen_from_history_after_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC: delete_screen_from_history_after_rsp()");

    DeleteScreenIfPresent(SCR_ID_JMMS_NEW_MMS);
    DeleteScreenIfPresent(SCR_ID_JMMS_RETRIEVED_MMS_PROPERTIES);
    DeleteScreenIfPresent(SCR_ID_JMMS_PREVIEW);

    if (IsScreenPresent(SCR_ID_UM_INBOX))
    {
        DeleteScreenIfPresent(SCR_ID_JMMS_INBOX_OPTIONS);
    }
    else if (IsScreenPresent(SCR_ID_UM_UNSENT))
    {
        DeleteScreenIfPresent(SCR_ID_JMMS_OUTBOX_OPTIONS);
    }
    else if (IsScreenPresent(SCR_ID_UM_SENT))
    {
        DeleteScreenIfPresent(SCR_ID_JMMS_SENT_OPTIONS);
    }
    else if (IsScreenPresent(SCR_ID_UM_DRAFT))
    {
        DeleteScreenIfPresent(SCR_ID_JMMS_DRAFTS_OPTIONS);
    }
    else if (IsScreenPresent(SCR_ID_JMMS_TEMPLATES_OPTIONS))
    {
        DeleteScreenIfPresent(SCR_ID_JMMS_TEMPLATES_OPTIONS);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_create_message_handle_async_callback
 * DESCRIPTION
 *  Create msg_handle for create functionality
 * PARAMETERS
 *  ret_code        [IN]        JC_RETCODE
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_create_message_handle_async_callback(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS UC: create_msg_handle_for_create()");

    if (ret_code == JC_OK)
    {

        mmi_jmms_uc_create_msg_req((void*)g_jmms_context->uc_req_rsp_info_holder_p, mmi_jmms_uc_create_msg_rsp);
        return;
    }
    mmi_jmms_uc_create_msg_rsp(ret_code, 0);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_mma_send_content_rsp_lsk
 * DESCRIPTION
 *  history handling on preview request if current screen call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_mma_send_content_rsp_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_pre_checks_mms_view();
    DeleteScreenIfPresent(SCR_ID_JMMS_PARSING_SUCCESS_SCREEN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_mma_send_content_rsp_scr
 * DESCRIPTION
 *  history handling on preview request if current screen call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_mma_send_content_rsp_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_PARSING_SUCCESS_SCREEN, NULL, mmi_jmms_entry_parse_result_pass, NULL);

    ShowCategory2Screen(
        STR_MMS_MENUENTRY,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        0,
        0,
        STR_ID_MMS_PARSING_SUCCESS,
        NULL);

    SetLeftSoftkeyFunction(mmi_jmms_uc_mma_send_content_rsp_lsk, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_add_preview_rsp_screen
 * DESCRIPTION
 *  history handling on preview request if current screen call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_uc_add_preview_rsp_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history hist;
    U16 k;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&hist, 0, sizeof(history));
    ret = GetNextScrnIdOf(SCR_ID_UC_PROCESSING, &k);
    if (ret == MMI_TRUE)
    {
        hist.scrnID = SCR_ID_JMMS_PARSING_SUCCESS_SCREEN;
        hist.entryFuncPtr = mmi_jmms_uc_mma_send_content_rsp_scr;
        InsertHistoryBeforeThisScrnReference(k, &hist);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_delete_uc_compose_files
 * DESCRIPTION
 *  delete temporary vacrd vcal files
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_delete_uc_compose_files(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_INT8 mms_folder_path_ascii[FMGR_MAX_PATH_LEN] = {0};
    JC_CHAR mms_folder_path_ucs2[FMGR_MAX_PATH_LEN] = {0};
    JC_INT32 drive_letter = FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMS_IN_LARGE_STORAGE
    drive_letter = FS_GetDrive(FS_DRIVE_I_SYSTEM, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
#endif 
    sprintf(mms_folder_path_ascii, "%c:\\%s", drive_letter, TEMP_ATTACH_FOLDER_PATH);
    mmi_asc_to_ucs2((S8*) mms_folder_path_ucs2, (S8*) mms_folder_path_ascii);
    if (g_jmms_context->jmms_fs_handle == NULL)
    {
        if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
        {
            return;
        }
    }
    jdd_FSDelDir(g_jmms_context->jmms_fs_handle, (U16*) mms_folder_path_ucs2);
    jdd_FSMakeDir(g_jmms_context->jmms_fs_handle, (U16*) mms_folder_path_ucs2);
    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
    }
}

#else /* defined (JATAAYU_SUPPORT) && defined (MMS_SUPPORT) && defined (__UNIFIED_COMPOSER_SUPPORT__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_dummy_uc_handling_fun
 * DESCRIPTION
 *  Just to remove warning
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_dummy_uc_handling_fun(void)
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
#endif /* __MMI_JMMSUCHANDLING_C */ 


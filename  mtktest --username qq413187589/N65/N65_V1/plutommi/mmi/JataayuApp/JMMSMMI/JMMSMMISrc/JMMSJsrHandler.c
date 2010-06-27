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
 *  JMMSJsrHandler.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contains the MMS related APIs for interacting with JSR module.
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
#ifndef _MMI_JMMSJSRHANDLER_C
#define _MMI_JMMSJSRHANDLER_C

/***************************************************************************** 
* Include
*****************************************************************************/
#if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT))

#include "JsrTypes.h"
#include "JMMSJSRHandler.h"
#include "SettingProfile.h"
#include "FileManagerGProt.h"   /* file path util function */
#include "Conversions.h"

#include <ddl.h>
#include <jcal.h>
#include <jcalnet.h>
#include "jdi_wspdatatype.h"
#include "jdi_transport.h"
#include "JMMSCoreAPI.h"

/* jataayu files */
#include "ddlbase.h"
#include "jcutils.h"
#include "ddlutils.h"
#include "jdi_MMSErr.h"
#include "jcerror.h"

#include <jdi_communicator.h>

#include <miscutils.h>
#include <MM1DataTypes.h>
#include <MessagingDatatypes.h>
#include <MessagingAPI.h>
#include "JMMSExdcl.h"

#include "JMMSMainMMS.h"
#include "JMMSProtocols.h"
#include "JMMSMessageSettings.h"
#include "JMMSMessageSettingsUtils.h"
#include "JMMSConfig.h"
#include "JMMSResDef.h"
#include "JMMSWriteMMS.h"
#include "JMMSStoreHandling.h"

#include "PrvMessagingDataTypes.h"
#include "MM1Api.h"
#include "Msg_Utils.h"
#include "Msg_Presentation.h"
#include "JMMSPushHandling.h"

#include "JMMSCoreAPI.h"
#include "JMMSDrafts.h"
#include "JMMSExdcl.h"
#include "JMMSCompose.h"
#include "JMMSGprot.h"
#include "JMMSInbox.h"
#include "JMMSJSRHandler.h"
#include "JMMSMainMMS.h"
#include "JMMSMessageSettingsUtils.h"
#include "JMMSOutbox.h"
#include "JMMSProtocols.h"
#include "JMMSPushHandling.h"
#include "JMMSSent.h"
#include "JMMSStoreHandling.h"
#include "JMMSStructs.h"
#include "JMMSTemplates.h"
#include "JMMSUseDetails.h"
#include "JMMSView.h"
#include "JMMSWriteMMS.h"
#include "wapadp.h"
#include "JPushInboxCommonUI.h"
#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageResDef.h"
#include "UnifiedMessageProt.h"
#include "JMMSUMHandling.h"
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

#ifdef __MMI_JMMS_JAVA_MMS_SUPPORT__

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
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/

/* have to declare it here as its decalartion is not present in any .h */
extern int mmi_charset_ucs2_to_utf8_length_in_bytes(const kal_uint8 *raw);
extern int mmi_charset_utf8_to_ucs2_length_in_bytes(const kal_uint8 *raw);
extern em_wap_user_agent_brand_enum wap_get_user_agent_brand(void);

/* AT Command functions */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_folder_name_from_folderId
 * DESCRIPTION
 *  Find the name of Folder corresponding to Folder Id.
 * PARAMETERS
 *  folder_id       [IN]        Id of folder
 *  file_name       [OUT]       Corresponding folder name
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_get_folder_name_from_folderId(U8 folder_id, S8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (folder_id)
    {
        case JSR_INBOX:
            strcpy((S8*) file_name, (S8*) MMI_JMMS_INBOX);
            break;
        case JSR_OUTBOX:
            strcpy((S8*) file_name, (S8*) MMI_JMMS_OUTBOX);
            break;
        case JSR_SENT:
            strcpy((S8*) file_name, (S8*) MMI_JMMS_SENT);
            break;
        case JSR_DRAFTS:
            strcpy((S8*) file_name, (S8*) MMI_JMMS_DRAFTS);
            break;
        case JSR_TEMPLATES:
            strcpy((S8*) file_name, (S8*) MMI_JMMS_TEMPLATES);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_at_get_folder_info
 * DESCRIPTION
 *  Sets the folder information correponding to given Folder Id.
 * PARAMETERS
 *  folder_id           [IN]        Id of Folder
 *  folder_info_p       [OUT]       Folder information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_at_get_folder_info(U8 folder_id, mmi_jsr_folder_info_struct *folder_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FOLDER_INFO *folder_info = NULL;
    FOLDER_LIST *folder_list_p = NULL;
    U32 len = 0;
    S8 *folder_name = NULL;
    S8 fname[100];
    JC_RETCODE ret_code = JC_OK;
    U8 num_of_unread_msg = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(fname, 0, 100);
    mmi_jmms_get_folder_name_from_folderId(folder_id, fname);
    len = (strlen((PS8) fname) + 1) * ENCODING_LENGTH;

    folder_name = (PS8) jdd_MemAlloc(len, sizeof(S8));

    if (NULL == folder_name)
    {
        goto END;
    }

    mmi_asc_to_ucs2((PS8) folder_name, (PS8) fname);

    ret_code = mmi_jmms_get_folder_list(&folder_info);
    if (ret_code != JC_OK)
    {
        goto END;
    }

    folder_list_p = folder_info->pFolderList;

    while (folder_list_p)
    {
        if (mmi_ucs2cmp((S8*) folder_list_p->pFolderName, (S8*) folder_name) == 0)
        {
            folder_info_p->num_of_msg = folder_list_p->uiTotalMessages;
            if (strcmp((S8*) fname, (S8*) MMI_JMMS_INBOX) == 0)
            {
                ret_code = mmi_jmms_get_number_of_unread_messages_in_inbox(&num_of_unread_msg);
                folder_info_p->num_of_unread_msg = num_of_unread_msg;
            }
            else
            {
                folder_info_p->num_of_unread_msg = 0;
            }
            break;
        }
        folder_list_p = folder_list_p->pNext;
    }

  END:

    if (folder_name != NULL)
    {
        jdd_MemFree(folder_name);
        folder_name = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_at_get_address_and_subject
 * DESCRIPTION
 *  Sets the folder information correponding to given Folder Id.
 * PARAMETERS
 *  list        [OUT]       Message information list
 *  index       [IN]        Index of the message
 *  address     [IN]        Address field
 *  subject     [IN]        Subject field
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_at_get_address_and_subject(mmi_jsr_message_info_struct *list, U32 index, S8 *address, S8 *subject)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (address != NULL)
    {
        if (strlen(address) > 39)
        {
            memcpy(list[index].address, address, 39);
        }
        else
        {
            strcpy((S8*) (list[index].address), (S8*) address);
        }
    }
    if (subject != NULL)
    {
        if (strlen(subject) > 39)
        {
            memcpy(list[index].subject, subject, 39);
        }
        else
        {
            strcpy((S8*) (list[index].subject), (S8*) subject);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_at_get_message_list
 * DESCRIPTION
 *  This function creates the message list after getting the message
 *  information from Store module.
 * PARAMETERS
 *  folder_id       [IN]        Id of folder
 *  list            [OUT]       Message list
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_at_get_message_list(U8 folder_id, mmi_jsr_message_info_struct *list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MESSAGE_LIST *message_list_p = NULL;
    MESSAGE_LIST *temp_message_list_p = NULL;
    S8 folder_name[100];
    U32 i = 0;
    S32 msgType = -1;
    U32 len = 0;
    S8 *address = NULL;
    S8 *subject = NULL;
    RETRIEVE_FILTERS retrieve_filter = {0, };
    /* for new phone suite */
    U32 index = 1;
    CONTENT_DATA content_data = {0, };
    JC_RETCODE ret_code = JC_OK;
    S8 *name_p = NULL;
    S8 temp[40];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(folder_name, 0, 100);
    mmi_jmms_get_folder_name_from_folderId(folder_id, folder_name);

    retrieve_filter.uiStartIndex = 1;
    retrieve_filter.uiNumMessage = 0;
    retrieve_filter.eRetrieve = E_RETRIEVE_BY_INDEX;

    mmi_jmms_get_messages_list((S8*) folder_name, &message_list_p, &retrieve_filter);

    temp_message_list_p = message_list_p;

    while (temp_message_list_p)
    {
        memset((S8*) & content_data, 0, sizeof(CONTENT_DATA));
        list[i].msg_id = temp_message_list_p->uiExtraBytes & 0x0FFFFFFF;
        list[i].offset = 0; /* fixed 0 bytes */
        list[i].size = temp_message_list_p->uiBufferLen;
        msgType = temp_message_list_p->pMessageHeaders->eMsgType;
        /* for new phone suite */
        content_data.bIsStream = E_TRUE;

        ret_code = mmi_jmms_jdi_get_msg(g_jmms_context->store_handle, index++, &content_data);
        memset(temp, 0, 40);
        mmi_ucs2_to_asc((S8*) temp, (S8*) content_data.pFileName);
        name_p = strrchr(temp, '\\');
        name_p++;
        strcpy((S8*) list[i].filename, (S8*) name_p);

        switch (msgType)
        {
            case E_MSG_TYPE_SEND:
            {
                MESSAGE_SEND *pHeader = (MESSAGE_SEND*) temp_message_list_p->pMessageHeaders->pHeaders;

                list[i].date = pHeader->uiDate;

                if (pHeader->pFrom != NULL)
                {
                    len = (mmi_charset_ucs2_to_utf8_length_in_bytes((U8*) (pHeader->pFrom)) + 1);
                    address = jdd_MemAlloc(len, sizeof(U8));
                    mmi_chset_ucs2_to_utf8_string((U8*) address, len, (U8*) pHeader->pFrom);
                }
                if (pHeader->pSubject != NULL)
                {
                    len = (mmi_charset_ucs2_to_utf8_length_in_bytes((U8*) (pHeader->pSubject)) + 1);
                    subject = jdd_MemAlloc(len, sizeof(U8));
                    mmi_chset_ucs2_to_utf8_string((U8*) subject, len, (U8*) pHeader->pSubject);
                }
                mmi_jmms_at_get_address_and_subject(list, i, (S8*) address, (S8*) subject);
            }
                break;
            case E_MSG_TYPE_NOTIFICATION:
            {
                MESSAGE_NOTIFICATION *pHeader = (MESSAGE_NOTIFICATION*) temp_message_list_p->pMessageHeaders->pHeaders;

                list[i].date = 0;   /* date is not available in notification. */
                if (pHeader->pFrom != NULL)
                {
                    len = (mmi_charset_ucs2_to_utf8_length_in_bytes((U8*) (pHeader->pFrom)) + 1);
                    address = jdd_MemAlloc(len, sizeof(U8));
                    mmi_chset_ucs2_to_utf8_string((U8*) address, len, (U8*) pHeader->pFrom);
                }
                if (pHeader->pSubject != NULL)
                {
                    len = (mmi_charset_ucs2_to_utf8_length_in_bytes((U8*) (pHeader->pSubject)) + 1);
                    subject = jdd_MemAlloc(len, sizeof(U8));
                    mmi_chset_ucs2_to_utf8_string((U8*) subject, len, (U8*) pHeader->pSubject);
                }
                mmi_jmms_at_get_address_and_subject(list, i, (S8*) address, (S8*) subject);
            }
                break;
            case E_MSG_TYPE_DELIVERY_REPORT:
            {
                DELIVERY_REPORT *pHeader = (DELIVERY_REPORT*) temp_message_list_p->pMessageHeaders->pHeaders;

                list[i].date = pHeader->uiDate;
                /* delivery report doesn't have address and subject. */
                mmi_jmms_at_get_address_and_subject(list, i, NULL, NULL);
            }
                break;
            case E_MSG_TYPE_READ_REPORT:
            {
                READ_REPORT *pHeader = (READ_REPORT*) temp_message_list_p->pMessageHeaders->pHeaders;

                list[i].date = pHeader->uiDate;
                if (pHeader->pFrom != NULL)
                {
                    len = (mmi_charset_ucs2_to_utf8_length_in_bytes((U8*) (pHeader->pFrom)) + 1);
                    address = jdd_MemAlloc(len, sizeof(U8));
                    mmi_chset_ucs2_to_utf8_string((U8*) address, len, (U8*) pHeader->pFrom);
                }
                /* read report doesn't have subject. */
                mmi_jmms_at_get_address_and_subject(list, i, (S8*) address, NULL);
            }
                break;
            case E_MSG_TYPE_RECEIVE:
            {
                MESSAGE_RETRIEVAL *pHeader = (MESSAGE_RETRIEVAL*) temp_message_list_p->pMessageHeaders->pHeaders;

                list[i].date = pHeader->uiDate;
                if (pHeader->pFrom != NULL)
                {
                    len = (mmi_charset_ucs2_to_utf8_length_in_bytes((U8*) (pHeader->pFrom)) + 1);
                    address = jdd_MemAlloc(len, sizeof(U8));
                    mmi_chset_ucs2_to_utf8_string((U8*) address, len, (U8*) pHeader->pFrom);
                }
                if (pHeader->pSubject != NULL)
                {
                    len = (mmi_charset_ucs2_to_utf8_length_in_bytes((U8*) (pHeader->pSubject)) + 1);
                    subject = jdd_MemAlloc(len, sizeof(U8));
                    mmi_chset_ucs2_to_utf8_string((U8*) subject, len, (U8*) pHeader->pSubject);
                }
                mmi_jmms_at_get_address_and_subject(list, i, (S8*) address, (S8*) subject);
            }
                break;
            default:
                break;
        }
        i++;

        if (address != NULL)
        {
            jdd_MemFree(address);
            address = NULL;
        }
        if (subject != NULL)
        {
            jdd_MemFree(subject);
            subject = NULL;
        }
        if (content_data.pFileName != NULL)
        {
            jdd_MemFree(content_data.pFileName);
            content_data.pFileName = NULL;
        }
        temp_message_list_p = temp_message_list_p->pNext;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_at_save_mms
 * DESCRIPTION
 *  This function uploads the MMS into Draft folder of Store module.
 * PARAMETERS
 *  fname       [IN]        Path of MMS file
 *  msg_id      [OUT]       Message id generated after saving the MMS file
 * RETURNS
 *  Return JSR_RESULT_OK in case of success; otherwise proper mmi_jsr_result_enum code.
 *****************************************************************************/
mmi_jsr_result_enum mmi_jmms_at_save_mms(char *fname, U32 *msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 filename_length = 0;
    MSG_HANDLE msg_handle = NULL;
    CONTENT_DATA encapsulated_content = {0, };
    MESSAGE_HEADERS *msg_headers_p = NULL;
    JC_RETCODE ret_code = JC_OK;
    JC_UINT32 msg_index;
    S8 folder_name[100];
    JC_UINT32 file_length = 0;
    JDD_FILE file_handle = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(folder_name, 0, 100);
    mmi_jmms_get_folder_name_from_folderId(JSR_DRAFTS, folder_name);

    /* fname is in ASCII */
    filename_length = (strlen(fname) + 1) * ENCODING_LENGTH;

    encapsulated_content.bIsStream = E_TRUE;
    encapsulated_content.cbWriteCallback = NULL;
    encapsulated_content.cbReadCallback = mmi_jmms_read_callback;
    encapsulated_content.pStream = jdd_MemAlloc(sizeof(S8), filename_length);
    if (encapsulated_content.pStream == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto END;
    }

    mmi_asc_to_ucs2(encapsulated_content.pStream, fname);
    encapsulated_content.pFileName = encapsulated_content.pStream;

    if (g_jmms_context->jmms_fs_handle == NULL)
    {
        if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
        {
            ret_code = JC_ERR_FILE_OPEN;
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "jdd_FSInitialize fails with retcode (%d)", ret_code);
            goto END;
        }
    }

    file_handle = jdd_FSOpen(g_jmms_context->jmms_fs_handle, (JC_CHAR*) encapsulated_content.pStream, E_OPEN_READ_MODE);
    if (file_handle == NULL)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d): jdd_FSOpen fails \n", __FILE__, __LINE__);
        ret_code = JC_ERR_FILE_OPEN;
        goto END;
    }

    ret_code = jdd_FSGetSize(file_handle, &file_length);
    if (JC_OK != ret_code)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d): jdd_FSGetSize fails \n", __FILE__, __LINE__);
        goto END;
    }

    encapsulated_content.uiTotalSize = file_length;

    if (file_handle != NULL)
    {
        jdd_FSClose(file_handle);
        file_handle = NULL;
    }

    if (file_length > mmi_jmms_retrieval_settings_msg_size_filter())
    {
        ret_code = -1;
        goto END;
    }

    ret_code = mmi_jmms_jdi_parse_msg_buffer(&msg_handle, &encapsulated_content, E_TYPE_MMS, E_FALSE);

    /* Async changes start */
    while (ret_code == JC_ERR_MMS_PARSE_PENDING)
    {
        ret_code = mmi_jmms_jdi_msg_parse_continue(msg_handle);
    };
    /* Async changes end */

    if (JC_OK != ret_code)
    {
        *msg_id = 0;
        goto END;
    }
    ret_code = mmi_jmms_jdi_get_msg_headers(msg_handle, &msg_headers_p);
    if (JC_OK != ret_code)
    {
        *msg_id = 0;
        goto END;
    }

    /* TO DO to be discussed. */
    ret_code = mmi_jmms_save_message_buffer_in_Store_ext(
                (S8*) folder_name,
                &msg_index,
                msg_headers_p,
                &encapsulated_content,
                msg_id,
                0);
  END:

    if (msg_handle != NULL)
    {
        mmi_jmms_jdi_msg_deinit_without_header(msg_handle);
        msg_handle = NULL;
    }

    if (JC_OK != ret_code)
    {
        if (encapsulated_content.pStream != NULL)
        {
            /* File System can be deinitialized while parsing the buffer */
            if (g_jmms_context->jmms_fs_handle == NULL)
            {
                if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) == JC_OK)
                {
                    if (file_handle != NULL)
                    {
                        jdd_FSClose(file_handle);
                        file_handle = NULL;
                    }

                    jdd_FSDelete(g_jmms_context->jmms_fs_handle, encapsulated_content.pStream);
                }
            }
        }
    }

    if (file_handle != NULL)
    {
        jdd_FSClose(file_handle);
        file_handle = NULL;
    }

    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
    }

    if (encapsulated_content.pStream != NULL)
    {
        jdd_MemFree(encapsulated_content.pStream);
        encapsulated_content.pStream = NULL;
    }

    return mmi_jmms_java_mms_error(ret_code);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_at_delete_mms
 * DESCRIPTION
 *  This function is used to delete MMS using AT command
 * PARAMETERS
 *  folder_id                   [IN]        Id of folder
 *  msg_id                      [IN]        Message id of MMS
 *  jmms_delete_callback        [IN]        Callback called after deleting MMS.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_at_delete_mms(U8 folder_id, U32 msg_id, void (*jmms_delete_callback) (mmi_jsr_result_enum result))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_index = 0;
    S8 fname[100];
    JC_RETCODE ret_code = JC_OK;
    RETRIEVE_FILTERS retrieve_filter = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (folder_id == 0)
    {
        FOLDER_INFO *folder_info = NULL;
        FOLDER_LIST *folder_list_p = NULL;
        MESSAGE_LIST *message_list_p = NULL;
        MESSAGE_LIST *temp_message_list_p = NULL;
        MMI_BOOL is_message_deleted = MMI_FALSE;
        MMI_BOOL done = MMI_FALSE;

        /* manish adding here */
        MMI_BOOL is_open = MMI_FALSE;

        ret_code = mmi_jmms_get_folder_list(&folder_info);
        if (ret_code != JC_OK)
        {
            jmms_delete_callback(mmi_jmms_java_mms_error(ret_code));
            return;
        }

        folder_list_p = folder_info->pFolderList;
        while (folder_list_p)
        {
            memset(fname, 0, 100);
            msg_index = 0;
            mmi_ucs2_to_asc((S8*) fname, (S8*) folder_list_p->pFolderName);

            /* manish changing here on 2 Feb */
            retrieve_filter.uiStartIndex = 1;
            retrieve_filter.uiNumMessage = 0;
            retrieve_filter.eRetrieve = E_RETRIEVE_BY_INDEX;

            mmi_jmms_get_messages_list((S8*) fname, &message_list_p, &retrieve_filter);

            temp_message_list_p = message_list_p;
            while (temp_message_list_p)
            {
                msg_index++;
                if ((temp_message_list_p->uiExtraBytes & 0x0FFFFFFF) == msg_id) /* msgId is stored in the extra bytes of message list. */
                {

                    is_message_deleted = MMI_TRUE;
                    done = MMI_TRUE;
                    is_open = mmi_jmms_is_msg_open((S8*) fname, msg_id, msg_index);

                    if (is_open == MMI_FALSE)
                    {
                        g_jmms_context->is_at_delete_mms = MMI_TRUE;
                        ret_code = mmi_jmms_delete_message(fname, msg_index);
                        g_jmms_context->is_at_delete_mms = MMI_FALSE;
                        if (ret_code != JC_OK)
                        {
                            is_message_deleted = MMI_FALSE;
                            break;
                        }
                        else
                        {
                            if (strcmp(fname, "Inbox") == 0)
                            {
                                mmi_jmms_free_pending_node_if_present(msg_index);
                                mmi_jmms_delete_msg_status((U8) (msg_index - 1));
                            }
                            is_message_deleted = MMI_TRUE;
                            break;
                        }
                    }
                    else
                    {
                        is_message_deleted = MMI_FALSE;
                        break;
                    }
                }
                temp_message_list_p = temp_message_list_p->pNext;
            }

            if (done == MMI_TRUE)
            {
                break;
            }
            folder_list_p = folder_list_p->pNext;
        }

        if (is_message_deleted == MMI_FALSE)
        {
            ret_code = JC_ERR_STORE_INVALID_MSG_INDEX;
        }
    }
    else
    {
        memset(fname, 0, 100);
        mmi_jmms_get_folder_name_from_folderId((U8) folder_id, (S8*) fname);
        ret_code = mmi_jmms_delete_all_message((S8*) fname);
    }
    /* Call the callback function */
    jmms_delete_callback(mmi_jmms_java_mms_error(ret_code));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_is_msg_open
 * DESCRIPTION
 *  This function is used to determine whether the MMS is Open or not.
 * PARAMETERS
 *  fname           [IN]        Folder name
 *  msg_id          [IN]        Message id of MMS
 *  msg_index       [IN]        Message index of pending MMS list
 * RETURNS
 *  Return MMI_TRUE in case of MMS is open; otherwise MMI_FALSE.
 *****************************************************************************/
MMI_BOOL mmi_jmms_is_msg_open(S8 *fname, U32 msg_id, U32 msg_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_folder_name_enum folder_id;
    MMI_BOOL is_open = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strcmp(fname, "Inbox") == 0)
    {
        folder_id = E_JMMS_INBOX;
    }
    else if (strcmp(fname, "Outbox") == 0)
    {
        folder_id = E_JMMS_OUTBOX;
    }
    else if (strcmp(fname, "Drafts") == 0)
    {
        folder_id = E_JMMS_DRAFTS;
    }
    else if (strcmp(fname, "Sent") == 0)
    {
        folder_id = E_JMMS_SENT;
    }
    else
    {
        return is_open;
    }

    if ((g_jmms_context->msg_open_status[0] == folder_id
         && g_jmms_context->msg_open_status[1] == (U32) (msg_id))
        || (g_jmms_context->msg_open_status[0] == folder_id && g_jmms_context->msg_open_status[1] == 0))
    {
        is_open = MMI_TRUE;
        return is_open;
    }

    if (folder_id == E_JMMS_INBOX)
    {
        if (GetActiveScreenId() == SCR_ID_JMMS_NEW_MMS_IND)
        {

            if (g_jmms_context->pending_mms_info_list != NULL)
            {
                if (g_jmms_context->pending_mms_info_list->index == msg_index)
                {
                    is_open = MMI_TRUE;
                }
            }
        }
    }

    return is_open;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_free_pending_node_if_present
 * DESCRIPTION
 *  This function will delete the pending node of MMS having msg_index
 *  as index from MMS pending messages list.
 * PARAMETERS
 *  msg_index       [IN]        Message index of MMS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_free_pending_node_if_present(U32 msg_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_jmms_pending_mms_info_struct *node = NULL;
    mmi_jmms_pending_mms_info_struct *pre_node = NULL;
    U8 type;
    JC_INT32 index = 0;
    U8 delivery_report_index = 0, read_report_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->pending_mms_info_list == NULL)
    {
        return;
    }

    node = g_jmms_context->pending_mms_info_list;
    pre_node = node;
    while (node != NULL)
    {
        index = (JC_INT32) (node->index);
        type = node->type;

        if (type == E_MSG_TYPE_DELIVERY_REPORT)
        {
            delivery_report_index++;
        }
        else if (type == E_MSG_TYPE_READ_REPORT_RESPONSE)
        {
            read_report_index++;
        }

        if (index == msg_index)
        {
            break;
        }

        pre_node = node;
        node = node->next_p;
    }

    if (node == NULL)
    {
        return;
    }

    if (pre_node == node)
    {
        g_jmms_context->pending_mms_info_list = node->next_p;
    }
    else
    {
        pre_node->next_p = node->next_p;
    }

    if (node->mms_url_p != NULL)
    {
        jdd_MemFree(node->mms_url_p);
    }

    jdd_MemFree(node);
    node = NULL;

    if (type == E_MSG_TYPE_NOTIFICATION || type == E_MSG_TYPE_RECEIVE)
    {
        return;
    }

    switch (type)
    {

        case E_MSG_TYPE_DELIVERY_REPORT:
        {

            mmi_jmms_pending_mms_delivery_reports_struct *node1 = NULL;
            mmi_jmms_pending_mms_delivery_reports_struct *pre_node1 = NULL;

            node1 = g_jmms_context->pending_delivery_reports;
            if (g_jmms_context->pending_delivery_reports == NULL || delivery_report_index == 0)
            {
                return;
            }
            else
            {
                pre_node1 = node1;
                delivery_report_index--;

                while (delivery_report_index != 0 && node1 != NULL)
                {
                    pre_node1 = node1;
                    node1 = node1->next_p;
                    delivery_report_index--;
                }

                if (node1 == NULL)
                {
                    return;
                }

                if (pre_node1 == node1)
                {
                    g_jmms_context->pending_delivery_reports = node1->next_p;
                }
                else
                {
                    pre_node1->next_p = node1->next_p;
                }

                if (node1->to_p != NULL)
                {
                    jdd_MemFree(node1->to_p);
                }

                jdd_MemFree(node1);
                node1 = NULL;

            }

            return;
        }
        case E_MSG_TYPE_READ_REPORT_RESPONSE:
        {

            mmi_jmms_pending_mms_read_reports_struct *node1 = NULL;
            mmi_jmms_pending_mms_read_reports_struct *pre_node1 = NULL;

            node1 = g_jmms_context->pending_read_reports;
            if (g_jmms_context->pending_read_reports == NULL || read_report_index == 0)
            {
                return;
            }
            else
            {
                pre_node1 = node1;
                read_report_index--;

                while (read_report_index != 0 && node1 != NULL)
                {
                    pre_node1 = node1;
                    node1 = node1->next_p;
                    read_report_index--;
                }

                if (node1 == NULL)
                {
                    return;
                }

                if (pre_node1 == node1)
                {
                    g_jmms_context->pending_read_reports = node1->next_p;
                }
                else
                {
                    pre_node1->next_p = node1->next_p;
                }

                if (node1->from_p != NULL)
                {
                    jdd_MemFree(node1->from_p);
                }

                jdd_MemFree(node1);
                node1 = NULL;

            }

            return;
        }

    }   /* /switch(type) */
}

/* /java functions */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_jsr_create_mms
 * DESCRIPTION
 *  This function creates the Java MMS pdu containing the header information.
 * PARAMETERS
 *  message     [IN]        MMS message header information
 *  buffer      [IN]        Header detail infomation
 * RETURNS
 *  Return JSR_RESULT_OK in case of success; otherwise proper mmi_jsr_result_enum code.
 *****************************************************************************/
mmi_jsr_result_enum mmi_jmms_jsr_create_mms(wap_mmc_send_appmms_req_struct *message, U8 *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 datalen = 0;
    JC_RETCODE ret_code = JC_OK;
    MESSAGE_SEND *message_send_p = NULL;
    MESSAGE_HEADERS *msg_headers_p = NULL;
    MSG_HANDLE msg_handle = NULL;
    MM1_HDR_PARAM *content_type_params_p = NULL;    /* For content type */
    MM1_HDR_PARAM *temp_content_type_params_p = NULL;
    MM1_HDR_PARAM *node = NULL;
    S8 *address = NULL;
    S8 *temp_address = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_free_mms_pdu_memory(g_jmms_context);

    ret_code = mmi_jmms_jdi_msg_init(&msg_handle, NULL);
    if (JC_OK != ret_code)
    {
        mmi_jmms_free_mms_pdu_memory(g_jmms_context);

        goto END;

    }
    ret_code = mmi_jmms_jdi_set_msg_type(msg_handle, E_TYPE_MMS);
    if (JC_OK != ret_code)
    {
        mmi_jmms_free_mms_pdu_memory(g_jmms_context);
        goto END;
    }

    if (message->mms_type == 0)
    {
        ret_code = mmi_jmms_jdi_set_presentation_type(msg_handle, E_PRESENTATION_SMIL);
    }
    else if (message->mms_type == 1)
    {
        ret_code = mmi_jmms_jdi_set_presentation_type(msg_handle, E_PRESENTATION_NONE);
    }
    if (JC_OK != ret_code)
    {
        mmi_jmms_free_mms_pdu_memory(g_jmms_context);
        goto END;
    }

    g_jmms_context->msg_headers_p = (MESSAGE_HEADERS*) jdd_MemAlloc(sizeof(MESSAGE_HEADERS), 1);

    if (NULL == g_jmms_context->msg_headers_p)
    {
        mmi_jmms_free_mms_pdu_memory(g_jmms_context);

        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto END;
    }

    g_jmms_context->msg_header_type_p = (MESSAGE_SEND*) jdd_MemAlloc(sizeof(MESSAGE_SEND), 1);
    if (NULL == g_jmms_context->msg_header_type_p)
    {
        mmi_jmms_free_mms_pdu_memory(g_jmms_context);

        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto END;
    }

    msg_headers_p = g_jmms_context->msg_headers_p;
    message_send_p = g_jmms_context->msg_header_type_p;

    ret_code = mmi_jmms_set_mmsc_version();
    if (ret_code != JC_OK)
    {
        mmi_jmms_free_mms_pdu_memory(g_jmms_context);
        goto END;
    }

    message_send_p->pVersion = (JC_INT8*) g_jmms_context->version;

    if (wap_get_user_agent_brand() != EM_WAP_USERAGENT_BRAND_SE)
    {
        message_send_p->uiExpiryTime = MAX_VALIDITY_PERIOD_VALUE;
    }
    else
    {
        message_send_p->uiExpiryTime = 0;
        message_send_p->uiDate = get_current_utc_time();
    }

    /* PMT HIMANSHU START 20060425 */
    /* For fixing the date & time issue */
    if (message->delivery_time > 604800)
    {
        mmi_jmms_free_mms_pdu_memory(g_jmms_context);

        ret_code = E_JMMS_GENERAL_ERROR;
        goto END;

    }
    /* PMT HIMANSHU END 20060425 */

    message_send_p->uiDeliveryTime = message->delivery_time;

    message_send_p->eMsgPriority = (message->priority) + 1;

    message_send_p->bDeliveryReport = E_FALSE;
    message_send_p->bReadReport = E_FALSE;
    message_send_p->bHideSender = E_FALSE;

    message_send_p->bExpiryAbs = E_FALSE;
    message_send_p->bDeliveryAbs = E_FALSE;

    mmi_jmms_free_addresses_list();

    if (buffer != NULL)
    {
        /* Retrieve Subject */
        {
            S8 *subject = NULL;
            U32 subject_len_ucs2 = 0;
            U32 subject_len = *(U32*) buffer;

            if (subject_len > 0)
            {
                subject = (S8*) jdd_MemAlloc(sizeof(S8), subject_len + 1);
                if (NULL == subject)
                {
                    mmi_jmms_free_mms_pdu_memory(g_jmms_context);

                    ret_code = JC_ERR_MEMORY_ALLOCATION;
                    goto END;
                }

                memcpy(subject, buffer + 8, subject_len);
                datalen = subject_len + 8;

                subject_len_ucs2 = mmi_charset_utf8_to_ucs2_length_in_bytes((U8*) subject);

                g_jmms_context->subject_p = (S8*) jdd_MemAlloc(sizeof(S8), (subject_len_ucs2 + ENCODING_LENGTH));
                if (g_jmms_context->subject_p == NULL)
                {
                    mmi_jmms_free_mms_pdu_memory(g_jmms_context);
                    if (subject != NULL)
                    {
                        jdd_MemFree(subject);
                        subject = NULL;
                    }
                    ret_code = JC_ERR_MEMORY_ALLOCATION;
                    goto END;

                }
                mmi_chset_utf8_to_ucs2_string(
                    (U8*) g_jmms_context->subject_p,
                    (subject_len_ucs2 + ENCODING_LENGTH),
                    (U8*) subject);

                message_send_p->pSubject = (JC_CHAR*) g_jmms_context->subject_p;
                if (subject != NULL)
                {
                    jdd_MemFree(subject);
                    subject = NULL;
                }
            }
            else
            {
                datalen = 4;
            }
        }
        /* Retrieve to addresses */
        while (message->to_addr_no > 0)
        {
            U32 address_len = 0;
            U32 addrType = 0;
            U8 ret = 0;

            memcpy(&addrType, (char*)(buffer + datalen), 4);
            memcpy(&address_len, (char*)(buffer + datalen + 4), 4);
            address = jdd_MemAlloc(sizeof(S8), address_len + 1);
            if (NULL == address)
            {
                mmi_jmms_free_mms_pdu_memory(g_jmms_context);

                ret_code = JC_ERR_MEMORY_ALLOCATION;
                goto END;
            }

            memcpy(address, buffer + datalen + 8, address_len);
            datalen += address_len + 8;

            temp_address = jdd_MemAlloc(sizeof(S8), (address_len + 1) * ENCODING_LENGTH);
            if (NULL == temp_address)
            {
                mmi_jmms_free_mms_pdu_memory(g_jmms_context);

                ret_code = JC_ERR_MEMORY_ALLOCATION;
                goto END;
            }

            mmi_asc_to_ucs2((PS8) temp_address, (PS8) address);

            if ((MMI_FALSE == mmi_jmms_check_address_input_format((U8*) temp_address))
                && (MMI_FALSE == mmi_jmms_check_number_input_format((U8*) temp_address)))
            {
                mmi_jmms_free_mms_pdu_memory(g_jmms_context);

                ret_code = JC_ERR_INVALID_PARAMETER;
                goto END;
            }

            g_jmms_context->address_list_flag = E_TO_ADDRESSES;
            ret = mmi_jmms_add_address_in_addresse_list(temp_address);
            if (ret != 0)
            {

                mmi_jmms_free_mms_pdu_memory(g_jmms_context);
                ret_code = JC_ERR_MEMORY_ALLOCATION;

                goto END;

            }
            /* ASSERT(mmcAddrListToMms(addrType, address, &to)); */
            if (address != NULL)
            {
                jdd_MemFree(address);
                address = NULL;
            }
            if (temp_address != NULL)
            {
                jdd_MemFree(temp_address);
                temp_address = NULL;
            }

            message->to_addr_no--;
        }
        if (g_jmms_context->to_address_p != NULL)
        {
            g_jmms_context->to_p = mmi_jmms_get_to_addresses();

            if (g_jmms_context->to_p == NULL)
            {
                mmi_jmms_free_mms_pdu_memory(g_jmms_context);

                ret_code = JC_ERR_MEMORY_ALLOCATION;
                goto END;
            }

            message_send_p->pTo = (JC_CHAR*) g_jmms_context->to_p;
        }
        mmi_jmms_free_addresses_list();

        /* Retrieve cc addresses */
        while (message->cc_addr_no > 0)
        {
            U32 address_len = 0;
            U32 addrType = 0;
            U8 ret = 0;

            memcpy(&addrType, (char*)(buffer + datalen), 4);
            memcpy(&address_len, (char*)(buffer + datalen + 4), 4);

            address = jdd_MemAlloc(sizeof(S8), address_len + 1);
            if (NULL == address)
            {
                mmi_jmms_free_mms_pdu_memory(g_jmms_context);
                ret_code = JC_ERR_MEMORY_ALLOCATION;
                goto END;
            }

            memcpy(address, buffer + datalen + 8, address_len);
            datalen += address_len + 8;

            temp_address = jdd_MemAlloc(sizeof(S8), (address_len + 1) * ENCODING_LENGTH);
            if (NULL == temp_address)
            {
                mmi_jmms_free_mms_pdu_memory(g_jmms_context);
                ret_code = JC_ERR_MEMORY_ALLOCATION;
                goto END;
            }

            mmi_asc_to_ucs2((PS8) temp_address, (PS8) address);

            if ((MMI_FALSE == mmi_jmms_check_address_input_format((U8*) temp_address))
                && (MMI_FALSE == mmi_jmms_check_number_input_format((U8*) temp_address)))
            {
                mmi_jmms_free_mms_pdu_memory(g_jmms_context);
                ret_code = JC_ERR_INVALID_PARAMETER;
                goto END;
            }

            g_jmms_context->address_list_flag = E_CC_ADDRESSES;
            ret = mmi_jmms_add_address_in_addresse_list(temp_address);
            if (ret != 0)
            {
                mmi_jmms_free_mms_pdu_memory(g_jmms_context);
                ret_code = JC_ERR_MEMORY_ALLOCATION;
                goto END;
            }

            if (address != NULL)
            {
                jdd_MemFree(address);
                address = NULL;
            }
            if (temp_address != NULL)
            {
                jdd_MemFree(temp_address);
                temp_address = NULL;
            }
            message->cc_addr_no--;
        }
        if (g_jmms_context->cc_address_p != NULL)
        {

            g_jmms_context->cc_p = mmi_jmms_get_cc_addresses();

            if (g_jmms_context->cc_p == NULL)
            {
                mmi_jmms_free_mms_pdu_memory(g_jmms_context);
                ret_code = JC_ERR_MEMORY_ALLOCATION;
                goto END;
            }

            message_send_p->pCc = (JC_CHAR*) g_jmms_context->cc_p;
        }
        mmi_jmms_free_addresses_list();

        /* Retrieve bcc addresses */
        while (message->bcc_addr_no > 0)
        {
            U32 address_len = 0;
            U32 addrType = 0;
            U8 ret = 0;

            memcpy(&addrType, (char*)(buffer + datalen), 4);
            memcpy(&address_len, (char*)(buffer + datalen + 4), 4);

            address = jdd_MemAlloc(sizeof(S8), address_len + 1);
            if (address == NULL)
            {
                mmi_jmms_free_mms_pdu_memory(g_jmms_context);
                ret_code = JC_ERR_MEMORY_ALLOCATION;
                goto END;
            }
            memcpy(address, buffer + datalen + 8, address_len);
            datalen += address_len + 8;

            temp_address = jdd_MemAlloc(sizeof(S8), (address_len + 1) * ENCODING_LENGTH);
            if (temp_address == NULL)
            {
                mmi_jmms_free_mms_pdu_memory(g_jmms_context);
                ret_code = JC_ERR_MEMORY_ALLOCATION;
                goto END;
            }
            mmi_asc_to_ucs2((PS8) temp_address, (PS8) address);

            if ((MMI_FALSE == mmi_jmms_check_address_input_format((U8*) temp_address))
                && (MMI_FALSE == mmi_jmms_check_number_input_format((U8*) temp_address)))
            {
                mmi_jmms_free_mms_pdu_memory(g_jmms_context);

                ret_code = JC_ERR_INVALID_PARAMETER;
                goto END;
            }

            g_jmms_context->address_list_flag = E_BCC_ADDRESSES;
            ret = mmi_jmms_add_address_in_addresse_list(temp_address);
            if (ret != 0)
            {
                mmi_jmms_free_mms_pdu_memory(g_jmms_context);
                ret_code = JC_ERR_MEMORY_ALLOCATION;
                goto END;
            }
            if (address != NULL)
            {
                jdd_MemFree(address);
                address = NULL;
            }
            if (temp_address != NULL)
            {
                jdd_MemFree(temp_address);
                temp_address = NULL;
            }
            message->bcc_addr_no--;
        }
        if (g_jmms_context->bcc_address_p != NULL)
        {
            g_jmms_context->bcc_p = mmi_jmms_get_bcc_addresses();

            if (g_jmms_context->bcc_p == NULL)
            {
                mmi_jmms_free_mms_pdu_memory(g_jmms_context);
                ret_code = JC_ERR_MEMORY_ALLOCATION;
                goto END;
            }

            message_send_p->pBcc = (JC_CHAR*) g_jmms_context->bcc_p;

        }
        mmi_jmms_free_addresses_list();

    }   /* /if(buffer!=NULL) */

    msg_headers_p->eMsgType = E_MSG_TYPE_SEND;

    msg_headers_p->pHeaders = message_send_p;

    ret_code = mmi_jmms_jdi_set_msg_headers(msg_handle, msg_headers_p);

    if (JC_OK != ret_code)
    {
        mmi_jmms_free_mms_pdu_memory(g_jmms_context);
        goto END;
    }

    /* Content type set here */

    jdi_MsgGetContentTypeParams(msg_handle, &content_type_params_p);
    if (content_type_params_p == NULL)
    {
        content_type_params_p = (MM1_HDR_PARAM*) jdd_MemAlloc(sizeof(MM1_HDR_PARAM), 1);
        if (content_type_params_p == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            mmi_jmms_free_mms_pdu_memory(g_jmms_context);
            goto END;
        }
        content_type_params_p->pszName = jdi_UtilsStrdup("Application-ID");
        content_type_params_p->pszValue = jdi_UtilsStrdup((JC_INT8*) (message->app_id));

        if (message->reply_app_id_len > 0)
        {
            content_type_params_p->pNext = (MM1_HDR_PARAM*) jdd_MemAlloc(sizeof(MM1_HDR_PARAM), 1);
            if (content_type_params_p->pNext == NULL)
            {
                ret_code = JC_ERR_MEMORY_ALLOCATION;
                mmi_jmms_free_mms_pdu_memory(g_jmms_context);

                while (content_type_params_p != NULL)
                {
                    node = content_type_params_p->pNext;

                    if (content_type_params_p->pszName != NULL)
                    {
                        jdd_MemFree(content_type_params_p->pszName);
                        content_type_params_p->pszName = NULL;
                    }
                    if (content_type_params_p->pszValue != NULL)
                    {
                        jdd_MemFree(content_type_params_p->pszValue);
                        content_type_params_p->pszValue = NULL;
                    }
                    jdd_MemFree(content_type_params_p);
                    content_type_params_p = node;
                }
                goto END;
            }

            temp_content_type_params_p = content_type_params_p->pNext;
            temp_content_type_params_p->pszName = jdi_UtilsStrdup("Reply-To-Application-ID");
            temp_content_type_params_p->pszValue = jdi_UtilsStrdup((JC_INT8*) (message->reply_app_id));
        }

        if (message->start_cnt_id_len > 0)
        {
            temp_content_type_params_p->pNext = (MM1_HDR_PARAM*) jdd_MemAlloc(sizeof(MM1_HDR_PARAM), 1);
            if (temp_content_type_params_p->pNext == NULL)
            {
                ret_code = JC_ERR_MEMORY_ALLOCATION;
                mmi_jmms_free_mms_pdu_memory(g_jmms_context);

                while (content_type_params_p != NULL)
                {
                    node = content_type_params_p->pNext;

                    if (content_type_params_p->pszName != NULL)
                    {
                        jdd_MemFree(content_type_params_p->pszName);
                        content_type_params_p->pszName = NULL;
                    }
                    if (content_type_params_p->pszValue != NULL)
                    {
                        jdd_MemFree(content_type_params_p->pszValue);
                        content_type_params_p->pszValue = NULL;
                    }
                    jdd_MemFree(content_type_params_p);
                    content_type_params_p = node;
                }

                goto END;
            }

            temp_content_type_params_p = temp_content_type_params_p->pNext;
            temp_content_type_params_p->pszName = jdi_UtilsStrdup("start");
            temp_content_type_params_p->pszValue = jdi_UtilsStrdup((JC_INT8*) (message->start_cnt_id));
        }

        if (temp_content_type_params_p != NULL)
        {
            temp_content_type_params_p->pNext = NULL;
        }
        jdi_MsgSetContentTypeParams(msg_handle, content_type_params_p);
    }

    /* free any allocated memory */
    if (g_jmms_context->mm1_handle != NULL)
    {
        /* ret_code = jdi_MM1Cleanup(g_jmms_context->mm1_handle, E_FALSE); */
        /* Memory Leak Fix: jdi_MM1Cleanup is allocating memory for data chunk after freeing the context */
        ret_code = jdi_MM1DeInitialize(g_jmms_context->mm1_handle);
        g_jmms_context->mm1_handle = NULL;
    }

    ret_code = jdi_MM1Initialize(&(g_jmms_context->mm1_handle));

    ret_code = mmi_jmms_jsr_form_send_request_pdu(g_jmms_context->mm1_handle, (MESSAGING_HANDLER*) msg_handle);
    if (ret_code != JC_OK)
    {
        mmi_jmms_free_mms_pdu_memory(g_jmms_context);
        goto END;
    }

    if (msg_handle != NULL)
    {
        mmi_jmms_jdi_msg_deinit_without_header(msg_handle);
        msg_handle = NULL;

        /* /manish-changing on 24 May to prevent End Key Bug */
        g_jmms_context->to_p = NULL;
        g_jmms_context->cc_p = NULL;
        g_jmms_context->bcc_p = NULL;
        g_jmms_context->from_p = NULL;
        g_jmms_context->msg_header_type_p = NULL;
        g_jmms_context->msg_headers_p = NULL;
        g_jmms_context->subject_p = NULL;
        g_jmms_context->version = NULL;
    }

    return mmi_jmms_java_mms_error(JC_OK);

  END:

    if (address != NULL)
    {
        jdd_MemFree(address);
        address = NULL;
    }

    if (temp_address != NULL)
    {
        jdd_MemFree(temp_address);
        temp_address = NULL;
    }

    if (msg_handle != NULL)
    {
        mmi_jmms_jdi_msg_deinit_without_header(msg_handle);
        msg_handle = NULL;

        /* /manish adding here on 24 May */
        g_jmms_context->to_p = NULL;
        g_jmms_context->cc_p = NULL;
        g_jmms_context->bcc_p = NULL;
        g_jmms_context->from_p = NULL;
        g_jmms_context->msg_header_type_p = NULL;
        g_jmms_context->msg_headers_p = NULL;
        g_jmms_context->subject_p = NULL;
        g_jmms_context->version = NULL;
    }

    if (g_jmms_context->mm1_handle != NULL)
    {
        /* jdi_MM1Cleanup(g_jmms_context->mm1_handle, E_FALSE); */
        /* Memory Leak Fix: jdi_MM1Cleanup is allocating memory for data chunk after freeing the context */
        jdi_MM1DeInitialize(g_jmms_context->mm1_handle);
        g_jmms_context->mm1_handle = NULL;
    }

    /* /manish adding here on 24 May */
    mmi_jmms_free_addresses_list();

    return mmi_jmms_java_mms_error(ret_code);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_jsr_form_send_request_pdu
 * DESCRIPTION
 *  This function copies the messaging handler information into MM1 handle.
 * PARAMETERS
 *  mm1_handle          [IN]        Handle to MM1
 *  msg_handle_p        [IN]        Pointer to messaging handler
 * RETURNS
 *  Return JC_OK in case of success; otherwise, proper JC_RETCODE error code.
 *****************************************************************************/
JC_RETCODE mmi_jmms_jsr_form_send_request_pdu(MM1_HANDLE mm1_handle, MESSAGING_HANDLER *msg_handle_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    MESSAGE_SEND *send_info_p = NULL;
    JC_INT8 major_version = DEFAULT_MMS_MAJOR_VERSION;
    JC_INT8 minor_version = E_MMS_MINOR_VERSION_2;

   /****** thanik 07-04-06 */
    MM1_HDR_PARAM *content_type_params_p = NULL;    /* For content type */
    MM1_HDR_PARAM *temp_content_type_params_p = NULL;
    MM1_HDR_PARAM *node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /**** thanik**/

    ret_code = jdi_MM1SetMessageType(mm1_handle, E_MMS_SEND_REQUEST_VALUE);
    if (ret_code != JC_OK)
    {
        goto error;
    }
    if (msg_handle_p->pMessageHeaders != NULL)
    {
        send_info_p = (MESSAGE_SEND*) msg_handle_p->pMessageHeaders->pHeaders;
    }
    if (send_info_p != NULL)
    {
        JC_CHAR *pFormattedAddress = NULL;

        if (send_info_p->pVersion)
        {
            major_version = (JC_INT8) (jc_atoi(send_info_p->pVersion));
            minor_version = (JC_INT8) (jc_atoi((send_info_p->pVersion) + 2));
        }
        ret_code = jdi_MM1SetVersion(mm1_handle, major_version, minor_version);
        if (ret_code != JC_OK)
        {
            goto error;
        }
        if (send_info_p->uiDate)
        {
            jdi_MM1SetDate(mm1_handle, send_info_p->uiDate);
        }
        else
        {
            jdi_MM1SetDate(mm1_handle, jdd_TimerGetCurrentTime());
        }
        if (send_info_p->pFrom)
        {
            GetFormattedAddress(&pFormattedAddress, send_info_p->pFrom);
            if (pFormattedAddress != NULL)
            {
                ret_code = jdi_MM1SetFromAddress(mm1_handle, E_FALSE, pFormattedAddress, E_NONE);
                jdd_MemFree(pFormattedAddress);
                pFormattedAddress = NULL;
            }
            else
            {
                ret_code = jdi_MM1SetFromAddress(mm1_handle, E_FALSE, send_info_p->pFrom, E_NONE);
            }
            if (ret_code != JC_OK)
            {
                goto error;
            }
        }
        if (send_info_p->pTo)
        {
            GetFormattedAddress(&pFormattedAddress, send_info_p->pTo);
            if (pFormattedAddress != NULL)
            {
                ret_code = jdi_MM1SetToAddress(mm1_handle, pFormattedAddress, E_NONE);
                jdd_MemFree(pFormattedAddress);
                pFormattedAddress = NULL;
            }
            else
            {
                ret_code = jdi_MM1SetToAddress(mm1_handle, send_info_p->pTo, E_NONE);
            }
            if (ret_code != JC_OK)
            {
                goto error;
            }
        }
        if (send_info_p->pCc)
        {
            GetFormattedAddress(&pFormattedAddress, send_info_p->pCc);
            if (pFormattedAddress != NULL)
            {
                ret_code = jdi_MM1SetCCAddress(mm1_handle, pFormattedAddress, E_NONE);
                jdd_MemFree(pFormattedAddress);
                pFormattedAddress = NULL;
            }
            else
            {
                ret_code = jdi_MM1SetCCAddress(mm1_handle, send_info_p->pCc, E_NONE);
            }
            if (ret_code != JC_OK)
            {
                goto error;
            }
        }
        if (send_info_p->pBcc)
        {
            GetFormattedAddress(&pFormattedAddress, send_info_p->pBcc);
            if (pFormattedAddress != NULL)
            {
                ret_code = jdi_MM1SetBCCAddress(mm1_handle, pFormattedAddress, E_NONE);
                jdd_MemFree(pFormattedAddress);
                pFormattedAddress = NULL;
            }
            else
            {
                ret_code = jdi_MM1SetBCCAddress(mm1_handle, send_info_p->pBcc, E_NONE);
            }
            if (ret_code != JC_OK)
            {
                goto error;
            }
        }
        if (send_info_p->pSubject)
        {
            ret_code = jdi_MM1SetSubject(mm1_handle, send_info_p->pSubject, E_NONE);
            if (ret_code != JC_OK)
            {
                goto error;
            }
        }
        ret_code = jdi_MM1SetMessageClass(mm1_handle, (EMM1MessageClass) send_info_p->eMsgClass);
        if (ret_code != JC_OK)
        {
            goto error;
        }
        if (send_info_p->uiExpiryTime)
        {
            ret_code = jdi_MM1SetExpiryTime(mm1_handle, send_info_p->uiExpiryTime, E_FALSE);
            if (ret_code != JC_OK)
            {
                goto error;
            }
        }
        if (send_info_p->uiDeliveryTime)
        {
            ret_code = jdi_MM1SetDeliveryTime(mm1_handle, send_info_p->uiDeliveryTime, E_FALSE);
            if (ret_code != JC_OK)
            {
                goto error;
            }
        }
        if (send_info_p->eMsgPriority > 0)
        {
            ret_code = jdi_MM1SetPriority(mm1_handle, (EMM1MessagePriority) (send_info_p->eMsgPriority - 1));
        }
        else
        {
            ret_code = jdi_MM1SetPriority(mm1_handle, E_NORMAL_MESSAGE_PRIORITY);
        }
        ret_code = jdi_MM1SetSenderVisibility(mm1_handle, ((send_info_p->bHideSender == E_TRUE) ? E_FALSE : E_TRUE));
        if (ret_code != JC_OK)
        {
            goto error;
        }
        ret_code = jdi_MM1SetDeliveryReport(mm1_handle, send_info_p->bDeliveryReport);
        if (ret_code != JC_OK)
        {
            goto error;
        }
        ret_code = jdi_MM1SetReadReplyReport(mm1_handle, send_info_p->bReadReport);
        if (ret_code != JC_OK)
        {
            goto error;
        }

    #ifdef ENABLE_MMS_VER_1_2
        if (minor_version >= E_MMS_MINOR_VERSION_2 && send_info_p->pMBoxInfo)
        {
            if (send_info_p->pMBoxInfo->bMBoxStore == E_TRUE)
            {
                ret_code = jdi_MM1SetMMStore(mm1_handle, send_info_p->pMBoxInfo->bMBoxStore);
                if (ret_code != JC_OK)
                {
                    goto error;
                }
                ret_code = jdi_MM1SetMMState(mm1_handle, (EMM1StoreStates) send_info_p->pMBoxInfo->eMBoxState);
                if (ret_code != JC_OK)
                {
                    goto error;
                }
            }
            if (send_info_p->pMBoxInfo->pMBoxFlagsType && send_info_p->pMBoxInfo->pMBoxFlagsType->pAddTokens)
            {
                ret_code = jdi_MM1SetMMFlags(mm1_handle, E_ADD, send_info_p->pMBoxInfo->pMBoxFlagsType->pAddTokens, E_UCS_2);
            }
            else if (send_info_p->pMBoxInfo->pMBoxFlagsType && send_info_p->pMBoxInfo->pMBoxFlagsType->pFilterTokens)
            {
                ret_code = jdi_MM1SetMMFlags(
                            mm1_handle,
                            E_REMOVE,
                            send_info_p->pMBoxInfo->pMBoxFlagsType->pFilterTokens,
                            E_UCS_2);
            }
            else if (send_info_p->pMBoxInfo->pMBoxFlagsType && send_info_p->pMBoxInfo->pMBoxFlagsType->pFilterTokens)
            {
                ret_code = jdi_MM1SetMMFlags(
                            mm1_handle,
                            E_FILTER,
                            send_info_p->pMBoxInfo->pMBoxFlagsType->pFilterTokens,
                            E_UCS_2);
            }
            if (ret_code != JC_OK)
            {
                goto error;
            }
        }
    #endif /* ENABLE_MMS_VER_1_2 */ 

        if (minor_version > E_MMS_MINOR_VERSION_0 && send_info_p->pReplyChargingInfo != NULL)
        {
            MM1_REPLY_CHARGING MM1ReplyChargingInfo;

            jc_memset(&MM1ReplyChargingInfo, 0x00, sizeof(MM1_REPLY_CHARGING));
            MM1ReplyChargingInfo.eReplyCharging = (EMM1ReplyCharging) send_info_p->pReplyChargingInfo->eReplyCharging;
            MM1ReplyChargingInfo.uiRelativeTime = send_info_p->pReplyChargingInfo->uiRelativeTime;
            MM1ReplyChargingInfo.uiSize = send_info_p->pReplyChargingInfo->uiSize;
            if (send_info_p->pReplyChargingInfo->eReplyCharging == E_REPLY_CHARGING_NOT_SUPPORTED)      /* i.e, if the message is a reply to a reply-charging req message */
            {
                MM1ReplyChargingInfo.pszReplyId = send_info_p->pReplyChargingInfo->pszReplyId;
            }
            ret_code = jdi_MM1SetReplyCharging(mm1_handle, &MM1ReplyChargingInfo);
            if (ret_code != JC_OK)
            {
                goto error;
            }
        }
      /***** 27-03-06 ***/
        if (msg_handle_p->pParams != NULL)
        {
         /******** Thanik *** 07-04-06***/
            content_type_params_p = (MM1_HDR_PARAM*) jdd_MemAlloc(sizeof(MM1_HDR_PARAM), 1);
            if (content_type_params_p == NULL)
            {
                ret_code = JC_ERR_MEMORY_ALLOCATION;
                goto error;
            }
            content_type_params_p->pszName = jdi_UtilsStrdup(msg_handle_p->pParams->pszName);
            content_type_params_p->pszValue = jdi_UtilsStrdup(msg_handle_p->pParams->pszValue);

            if (msg_handle_p->pParams->pNext != NULL)
            {
                content_type_params_p->pNext = (MM1_HDR_PARAM*) jdd_MemAlloc(sizeof(MM1_HDR_PARAM), 1);
                if (content_type_params_p->pNext == NULL)
                {
                    ret_code = JC_ERR_MEMORY_ALLOCATION;
                    goto error;
                }

                temp_content_type_params_p = content_type_params_p->pNext;
                temp_content_type_params_p->pszName = jdi_UtilsStrdup(msg_handle_p->pParams->pNext->pszName);
                temp_content_type_params_p->pszValue = jdi_UtilsStrdup(msg_handle_p->pParams->pNext->pszValue);
            }

            if (msg_handle_p->pParams->pNext != NULL && msg_handle_p->pParams->pNext->pNext != NULL)
            {
                temp_content_type_params_p->pNext = (MM1_HDR_PARAM*) jdd_MemAlloc(sizeof(MM1_HDR_PARAM), 1);
                if (temp_content_type_params_p->pNext == NULL)
                {
                    ret_code = JC_ERR_MEMORY_ALLOCATION;
                    goto error;
                }

                temp_content_type_params_p = temp_content_type_params_p->pNext;
                temp_content_type_params_p->pszName = jdi_UtilsStrdup(msg_handle_p->pParams->pNext->pNext->pszName);
                temp_content_type_params_p->pszValue = jdi_UtilsStrdup(msg_handle_p->pParams->pNext->pNext->pszValue);
            }

            if (temp_content_type_params_p != NULL)
            {
                temp_content_type_params_p->pNext = NULL;
            }
      /************* Thanik 07-04-06******/
            ret_code = jdi_MM1SetContentType(mm1_handle, NULL, NULL, NULL, content_type_params_p);
        }
      /***** 27-03-06 ***/

    }

    ret_code = JC_OK;

  error:

    if (ret_code != JC_OK)
    {
        while (content_type_params_p != NULL)
        {
            node = content_type_params_p->pNext;

            if (content_type_params_p->pszName != NULL)
            {
                jdd_MemFree(content_type_params_p->pszName);
                content_type_params_p->pszName = NULL;
            }
            if (content_type_params_p->pszValue != NULL)
            {
                jdd_MemFree(content_type_params_p->pszValue);
                content_type_params_p->pszValue = NULL;
            }
            jdd_MemFree(content_type_params_p);
            content_type_params_p = node;
        }
    }

    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_java_mms_error
 * DESCRIPTION
 *  This function maps the JC_RETCODE code with corresponding mmi_jsr_result_enum code.
 * PARAMETERS
 *  error_code      [IN]        Error code
 * RETURNS
 *  Returns properly converted mmi_jsr_result_enum code.
 *****************************************************************************/
mmi_jsr_result_enum mmi_jmms_java_mms_error(JC_RETCODE error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (error_code)
    {
        case JC_OK:
            return JSR_RESULT_OK;

        case JC_ERR_MEMORY_ALLOCATION:
            return JSR_RESULT_INSUFFICIENT_MEMORY;

        case JC_ERR_MSG_MAX_REACHED:
            return JSR_RESULT_EXCEED_MAX_MSGS;

        case JC_ERR_MMS_INVALID_HANDLE:
        case JC_ERR_MMS_INVALID_CONTENT_TYPE:
        case JC_ERR_MMS_INVALID_MMS_VERSION:
        case JC_ERR_MMS_INVALID_MESSAGE_TYPE:
        case JC_ERR_MMS_INVALID_HEADER:
        case JC_ERR_MSG_INVALID_HANDLE:
        case JC_ERR_MSG_INVALID_MESSAGING_TYPE:
        case JC_ERR_MSG_INVALID_PAGE_INDEX:
        case JC_ERR_MSG_INVALID_MEDIA_INDEX:
            return JSR_RESULT_INVALID_MESSAGE;

        case JC_ERR_STORE_INVALID_MSG_INDEX:
            return JSR_RESULT_MESSAGE_ID_NOT_FOUND;

        case JC_ERR_FILE_SYS_INIT:
        case JC_ERR_FILE_MOVE:
        case JC_ERR_FILE_INVALID_SYSTEM_HANDLE:
            return JSR_RESULT_FILE_OPERATION_ERROR;
        default:
            return JSR_RESULT_ERROR;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_jsr_add_media_object
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  message     [IN]        Media object information
 * RETURNS
 *  Returns JSR_RESULT_OK in case of success; otherwise, proper mmi_jsr_result_enum code.
 *****************************************************************************/
mmi_jsr_result_enum mmi_jmms_jsr_add_media_object(wap_mmc_post_appmms_msg_part_res_struct *message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MEDIA_MIME_INFO *media_info_p = NULL;
    JC_UINT32 file_size = 0;
    JC_UINT32 read_cnt = 0;
    FS_HANDLE file_handle;
    JC_RETCODE ret_code = JC_OK;
    JC_INT8 *media_buffer_p = NULL;
    JC_INT8 *temp_buffer_p = NULL;
    JC_CHAR *temp_path_p = NULL;
    JC_CHAR *path_p = NULL;
    JC_INT8 temp_file_path[40] = {0, };
    JDD_FSHANDLE file_sys_handle = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d): Enters function mmi_jmms_jsr_add_media_object() \n", __FILE__,
                         __LINE__);

    if ((message == NULL)
        || (message->filepath_len == 0)
        || (message->content_type_len == 0) || (message->content_id_len == 0 && message->content_location_len == 0))
    {
        return mmi_jmms_java_mms_error(JC_ERR_MSG_INVALID_HANDLE);
    }

    media_info_p = (MEDIA_MIME_INFO*) jdd_MemAlloc(sizeof(MEDIA_MIME_INFO), sizeof(U8));
    if (media_info_p == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }

    /* Initialize the File System Handle */
    ret_code = jdd_FSInitialize(&file_sys_handle);
    if (ret_code != JC_OK)
    {
        goto ERROR_HANDLE;
    }

    jc_sprintf(temp_file_path, "@mms\\temp\\~jsr_temp_file%d", g_jmms_context->media_obj_index);
    (g_jmms_context->media_obj_index)++;    /* increment index for next media object */

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s (%s) \n", "JMMS JSR Add Media File Name", temp_file_path);

    jdi_UtilsCharToTchar((JC_CHAR **) & (temp_path_p), temp_file_path);
    if (temp_path_p == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }

    path_p = jdd_FSFileNameTranslate(file_sys_handle, temp_path_p);
    jdd_MemFree(temp_path_p);
    if (path_p == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }

    ret_code = jdd_FSMove(NULL, (JC_CHAR*) message->filepath, file_sys_handle, (JC_CHAR*) path_p);
    if (ret_code != JC_OK)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d): JMMS JSR Add Media File Move Failed", __FILE__, __LINE__);
        goto ERROR_HANDLE;
    }

    if (file_sys_handle)
    {
        jdd_FSDeinitialize(file_sys_handle);
        file_sys_handle = NULL;
    }

    file_handle = FS_Open((U16*) path_p, FS_READ_ONLY);

    FS_GetFileSize(file_handle, &file_size);

    FS_Close(file_handle);

    if (message->content_id_len > 0)
    {
        media_info_p->MimeHeaders.pContentID = (JC_INT8*) jdd_MemAlloc(sizeof(JC_INT8), message->content_id_len + 1);
        if (media_info_p->MimeHeaders.pContentID == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto ERROR_HANDLE;
        }
        memcpy(media_info_p->MimeHeaders.pContentID, message->content_id, message->content_id_len);
    }

    if (message->content_location_len > 0)
    {
        ret_code = jdi_UtilsCharToTchar(
                    (JC_CHAR **) & (media_info_p->MimeHeaders.pObjectName),
                    (JC_INT8*) message->content_location);
        if (media_info_p->MimeHeaders.pObjectName == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto ERROR_HANDLE;
        }
    }

    media_info_p->MimeHeaders.bIsAttachment = 0;

    if (strstr((S8*) message->content_type, "text/plain") != NULL)
    {
        media_info_p->MimeHeaders.pContentType = jdi_UtilsStrdup((JC_INT8*) ("text/plain"));
        if (media_info_p->MimeHeaders.pContentType == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto ERROR_HANDLE;
        }

        media_info_p->ContentData.uiTotalSize = (file_size) * sizeof(JC_CHAR);
        media_info_p->ContentData.uiCurSize = (file_size) * sizeof(JC_CHAR);

        temp_buffer_p = (JC_INT8*) jdd_MemAlloc(file_size + 1, sizeof(JC_CHAR));
        if (temp_buffer_p == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto ERROR_HANDLE;
        }

        file_handle = FS_Open((U16*) path_p, FS_READ_ONLY);

        if (file_size > 0)
        {
            FS_Read(file_handle, temp_buffer_p, file_size, &read_cnt);
        }

        FS_Close(file_handle);

        if (message->encoding_scheme == MMS_US_ASCII)
        {
            ret_code = jdi_UtilsCharToTchar((JC_CHAR **) & media_buffer_p, (JC_INT8*) temp_buffer_p);
        }
        else if (message->encoding_scheme == MMS_UTF8)
        {
            ret_code = jdi_UtilsUTF8ToTchar((JC_CHAR **) & media_buffer_p, (JC_UINT8*) temp_buffer_p, (JC_UINT32) file_size);

        }

        if (ret_code != JC_OK)
        {
            goto ERROR_HANDLE;
        }

        media_info_p->ContentData.pBuffer = (JC_UINT8*) media_buffer_p;
    }
    else
    {
        if (message->content_type_len > 0)
        {
            media_info_p->MimeHeaders.pContentType =
                (JC_INT8*) jdd_MemAlloc(message->content_type_len + 1, sizeof(JC_INT8));

            if (media_info_p->MimeHeaders.pContentType == NULL)
            {
                ret_code = JC_ERR_MEMORY_ALLOCATION;
                goto ERROR_HANDLE;
            }
            jc_strcpy(media_info_p->MimeHeaders.pContentType, message->content_type);

        }

        media_info_p->ContentData.bIsStream = E_TRUE;
        media_info_p->ContentData.eCopyMemory = E_FALSE;
        media_info_p->ContentData.pBuffer = NULL;
        media_info_p->ContentData.uiCurSize = 0;
        media_info_p->ContentData.uiTotalSize = file_size;
        media_info_p->ContentData.cbReadCallback = mmi_jmms_read_callback;
        media_info_p->ContentData.cbWriteCallback = NULL;
        media_info_p->ContentData.uiStartOffset = 0;
        media_info_p->ContentData.pFileName =
            (JC_CHAR*) jdd_MemAlloc((jc_tcslen((JC_CHAR*) path_p) + 1), sizeof(JC_CHAR));

        if (media_info_p->ContentData.pFileName == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto ERROR_HANDLE;
        }
        jc_tcscpy((UI_character_type*) media_info_p->ContentData.pFileName, (UI_character_type*) path_p);

        media_info_p->ContentData.pStream = media_info_p->ContentData.pFileName;

        /* media_info_p->MimeHeaders.bIsAttachment = 0; */
    }

    /* add media */
    ret_code = AddMediaToMM1Handle(g_jmms_context->mm1_handle, media_info_p, E_TRUE);

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d): JMMS JSR Media Object Added Sucessfully \n", __FILE__, __LINE__);

  ERROR_HANDLE:

    if (ret_code != JC_OK)
    {
        if (media_info_p != NULL)
        {
            if (media_info_p->ContentData.pFileName != NULL)
            {
                jdd_MemFree(media_info_p->ContentData.pFileName);
            }
            if (media_info_p->MimeHeaders.pContentType != NULL)
            {
                jdd_MemFree(media_info_p->MimeHeaders.pContentType);
            }
            if (media_info_p->MimeHeaders.pContentID != NULL)
            {
                jdd_MemFree(media_info_p->MimeHeaders.pContentID);
            }
            if (media_info_p->MimeHeaders.pObjectName != NULL)
            {
                jdd_MemFree(media_info_p->MimeHeaders.pObjectName);
            }
            jdd_MemFree(media_info_p);

        }
    }

    if (temp_buffer_p != NULL)
    {
        jdd_MemFree(temp_buffer_p);
    }

    if (path_p != NULL)
    {
        jdd_MemFree(path_p);
    }

    if (file_sys_handle)
    {
        jdd_FSDeinitialize(file_sys_handle);
        file_sys_handle = NULL;
    }

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "(%d): JMMS JSR Media Object returns with RetCode(%d) \n", __LINE__,
                         ret_code);

    return (mmi_jmms_java_mms_error(ret_code));

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_jsr_delete_temp_media_files
 * DESCRIPTION
 *  Delete all the Temporary Media Files created while sending Java MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_jsr_delete_temp_media_files(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    JC_CHAR *path_p = NULL;
    JC_INT8 temp_file_path[40] = {0, };
    JDD_FSHANDLE file_sys_handle;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_code = jdd_FSInitialize(&file_sys_handle);
    if (JC_OK == ret_code)
    {
        for (i = 1; i < (g_jmms_context->media_obj_index); i++)
        {
            jc_sprintf(temp_file_path, "@mms\\temp\\~jsr_temp_file%d", i);
            jdi_UtilsCharToTchar((JC_CHAR **) & (path_p), temp_file_path);
            if (path_p)
            {
                ret_code = jdd_FSDelete(file_sys_handle, path_p);
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "JSR Media File(%d) Deleted with RetCode(%d):\n", i, ret_code);
                jdd_MemFree(path_p);
                path_p = NULL;
            }
        }
        jdd_FSDeinitialize(file_sys_handle);
    }

    g_jmms_context->media_obj_index = 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_jsr_get_application_string_from_content_type
 * DESCRIPTION
 *  Returns the pointer to starting position of substring in source string
 * PARAMETERS
 *  content_type_p      [IN]        Content type of MMS
 *  str_id              [IN]        Jsr application string id
 * RETURNS
 *  Returns Application Id or Reply To Application Id string based on str_id.
 *****************************************************************************/
S8 *mmi_jmms_jsr_get_application_string_from_content_type(S8 *content_type_p, mmi_jsr_string_id_enum str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *str_pos = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (str_id)
    {
        case JSR_APPLICATION_ID:
            str_pos = strstr(content_type_p, "application-id");
            if (str_pos == NULL)
            {
                str_pos = strstr(content_type_p, "Application-ID");
            }
            break;
        case JSR_REPLY_TO_APPLICATION_ID:
            str_pos = strstr(content_type_p, "reply-to-application-id");
            if (str_pos == NULL)
            {
                str_pos = strstr(content_type_p, "Reply-To-Application-ID");
            }
            break;
    }
    return str_pos;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_java_mms_set_content_type_params
 * DESCRIPTION
 *  This function gets the start field and reply-to-application-id
 *  from content type of MMS.
 * PARAMETERS
 *  resp                [OUT]       Recieve response struct
 *  content_type        [IN]        Content type of MMS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_java_mms_set_content_type_params(wap_mmc_recv_appmms_rsp_struct *resp, JC_INT8 *content_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *str_pos = NULL;
    S8 *temp_str = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((str_pos = strstr(content_type, "start")) != NULL)
    {
        temp_str = str_pos;
        str_pos = strstr(temp_str, "=");
        temp_str = str_pos + 1;
        str_pos = strstr(temp_str, ";");
        if (str_pos == NULL)
        {
            resp->start_cnt_id_len = strlen(temp_str);
        }
        else
        {
            resp->start_cnt_id_len = strlen(temp_str) - strlen(str_pos);
        }
        if (resp->start_cnt_id_len > 99)
        {
            resp->start_cnt_id_len = 99;
        }
        memcpy(resp->start_cnt_id, temp_str, resp->start_cnt_id_len);
    }
    else
    {
        resp->start_cnt_id_len = 0;
        memset(resp->start_cnt_id, 0, 100);
    }

    if ((str_pos = mmi_jmms_jsr_get_application_string_from_content_type(content_type, JSR_REPLY_TO_APPLICATION_ID)) != NULL)
    {
        temp_str = str_pos;
        str_pos = strstr(temp_str, "=");
        temp_str = str_pos + 1;
        str_pos = strstr(temp_str, ";");
        if (str_pos == NULL)
        {
            resp->reply_app_id_len = strlen(temp_str);
        }
        else
        {
            resp->reply_app_id_len = strlen(temp_str) - strlen(str_pos);
        }
        if (resp->reply_app_id_len > 99)
        {
            resp->reply_app_id_len = 99;
        }
        memcpy(resp->reply_app_id, temp_str, resp->reply_app_id_len);
    }
    else
    {
        resp->reply_app_id_len = 0;
        memset(resp->reply_app_id, 0, 100);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_jsr_get_message_details
 * DESCRIPTION
 *  This function will get the MMS details and provide the details to JSR
 *  through callback function.
 * PARAMETERS
 *  msg_id              [IN]        Message id of MMS
 *  recv_callback       [IN]        Callback function of JSR
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_jsr_get_message_details(U32 msg_id, MMI_JMMS_JSR_RETRIEVE_CALLBACK recv_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    JC_RETCODE ret_code = JC_OK;
    JC_UINT32 num_objects = 0;
    MESSAGE_LIST *list = NULL;
    MESSAGE_LIST *list_node = NULL;
    JC_INT32 index = 1;
    U16 result = 0;
    RETRIEVE_FILTERS retrieve_filter = {0, };
    U8 count_msg = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    retrieve_filter.uiStartIndex = 1;
    retrieve_filter.eRetrieve = E_RETRIEVE_BY_INDEX;

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d): JMMS JSR mmi_jmms_jsr_get_message_details. \n", __FILE__, __LINE__);

    g_jmms_context->jsr_mms_receive_callback = recv_callback;

    ret_code = mmi_mms_get_number_of_messages(MMI_JMMS_INBOX, &count_msg);
    if (ret_code != JC_OK)
    {
	    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS JSR mmi_mms_get_number_of_messages.");
        result = JSR_RESULT_ERROR;
        goto END;
    }

    while (count_msg != 0)
    {

        if (count_msg <= NUM_MSGS_IN_ONE_UNIT)  /* read 5 msgs at a time */
        {
            retrieve_filter.uiNumMessage = count_msg;
        }
        else
        {
            retrieve_filter.uiNumMessage = NUM_MSGS_IN_ONE_UNIT;
        }

        ret_code = mmi_jmms_get_messages_list("Inbox", &list, &retrieve_filter);
        if (ret_code != JC_OK || list == NULL)
        {
	        PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS JSR mmi_jmms_get_messages_list.");
            result = JSR_RESULT_ERROR;
            goto END;
        }

        list_node = list;
        while (list_node != NULL)
        {
            if ((list_node->uiExtraBytes & 0x0FFFFFFF) == msg_id)
            {
                break;
            }
            list_node = list_node->pNext;
            index++;

        }
        mmi_jmms_free_messages_list();
        list = NULL;

        retrieve_filter.uiStartIndex = retrieve_filter.uiStartIndex + retrieve_filter.uiNumMessage;
        count_msg = count_msg - retrieve_filter.uiNumMessage;

    }

    if (list_node == NULL)
    {
	    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS JSR list_node == NULL.");
        result = JSR_RESULT_MESSAGE_ID_NOT_FOUND;
        goto END;
    }

    if (g_jmms_context->parse_content_p != NULL)
    {
        jdd_MemFree(g_jmms_context->parse_content_p);
        g_jmms_context->parse_content_p = NULL;
    }
    if (g_jmms_context->parse_content_p == NULL)
    {
        g_jmms_context->parse_content_p = (CONTENT_DATA*) jdd_MemAlloc(sizeof(CONTENT_DATA), 1);
    }

    g_jmms_context->parse_content_p->bIsStream = E_TRUE;
    /* /core itself setting the file name and read callback */
    ret_code = mmi_jmms_get_message("Inbox", g_jmms_context->parse_content_p, index);

    if (ret_code != JC_OK || g_jmms_context->parse_content_p->pFileName == NULL)
    {
	    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_get_message %d (%s). \n", ret_code, g_jmms_context->parse_content_p->pFileName);
        result = JSR_RESULT_ERROR;
        goto END;
    }

    if (g_jmms_context->mm1_handle != NULL)
    {
        /* ret_code = jdi_MM1Cleanup(g_jmms_context->mm1_handle, E_FALSE); */
        /* Memory Leak Fix: jdi_MM1Cleanup is allocating memory for data chunk after freeing the context */
        ret_code = jdi_MM1DeInitialize(g_jmms_context->mm1_handle);
        g_jmms_context->mm1_handle = NULL;
    }

    ret_code = jdi_MM1Initialize(&(g_jmms_context->mm1_handle));

    if (ret_code != JC_OK)
    {
	    PRINT_INFORMATION_2(MMI_TRACE_INFO, "jdi_MM1Initialize fails.");
        result = JSR_RESULT_ERROR;
        goto END;
    }

    /*g_jmms_context->jsr_mms_receive_callback = recv_callback;*/
    ret_code = jdi_MM1Decode(g_jmms_context->mm1_handle, g_jmms_context->parse_content_p, E_PARSE_HEADERS_MIMEPARTS, MsgCtrl_CreateStream, &num_objects);       // TODO:: test it returns ok
    if (ret_code == JC_ERR_MMS_PARSE_PENDING)
    {
        mmi_jmms_mm1_decode_continue_start_timer(num_objects, mmi_jmms_jsr_async_get_message_details_callback);
        return;
    }
    mmi_jmms_jsr_async_get_message_details_callback(ret_code);

  END:

    if (g_jmms_context->jsr_mms_receive_callback != NULL && result != 0)
    {
        wap_mmc_recv_appmms_rsp_struct *resp = NULL;

        resp = (wap_mmc_recv_appmms_rsp_struct*) jdd_MemAlloc(sizeof(wap_mmc_recv_appmms_rsp_struct), 1);

        if (resp != NULL)
        {
	        PRINT_INFORMATION_2(MMI_TRACE_INFO, "result = %d", result);
            resp->result = result;
            g_jmms_context->jsr_mms_receive_callback(resp, NULL, 0);
        }
    }

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
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_jsr_async_get_message_details_callback
 * DESCRIPTION
 *  This function is callback for getting the message details
 *  in asynchronous manner.
 * PARAMETERS
 *  ret_code        [IN]        Return code
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_jsr_async_get_message_details_callback(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMM1MessageType mm1_msg_type = 0;
    JC_UINT32 uiTempVal = 0;
    EMM1MessagePriority eMM1MessagePriority = E_MSG_PRIORITY_NORMAL;
    EMM1Charset eCharset = E_NONE;
    JC_INT8 *content_type = NULL;
    JC_CHAR *subject = NULL;
    JC_UINT32 subject_len = 0;
    MMS_ADDRESS_LIST *p_from_AddressList = NULL;
    MMS_ADDRESS_LIST *p_to_AddressList = NULL;
    MMS_ADDRESS_LIST *p_cc_AddressList = NULL;

    U32 address_len = 0;
    S8 *buf = NULL;
    U16 datalen = 0;
    U16 buf_size = 0;

    wap_mmc_recv_appmms_rsp_struct *resp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_jsr_async_get_message_details_callback");

    resp = (wap_mmc_recv_appmms_rsp_struct*) jdd_MemAlloc(sizeof(wap_mmc_recv_appmms_rsp_struct), 1);

    if (resp == NULL)
    {
        goto END;
    }

    if (ret_code != JC_OK)
    {
        resp->result = JSR_RESULT_ERROR;
        goto END;
    }

    ret_code = jdi_MM1GetMessageType(g_jmms_context->mm1_handle, &mm1_msg_type);
    if (ret_code != JC_OK)
    {
        resp->result = JSR_RESULT_ERROR;
        goto END;
    }

    if (mm1_msg_type != E_MMS_RETRIEVE_CONFIRMATION_VALUE)
    {
        resp->result = JSR_RESULT_INVALID_MESSAGE;
        goto END;
    }

    uiTempVal = jdi_MM1GetDate(g_jmms_context->mm1_handle);
    if (uiTempVal)
    {
        resp->date = uiTempVal;
    }
    ret_code = jdi_MM1GetPriority(g_jmms_context->mm1_handle, &eMM1MessagePriority);
    if (ret_code == JC_OK)
    {
        resp->priority = eMM1MessagePriority;
    }
    else
    {
        resp->priority = 1; /* /E_MSG_PRIORITY_NORMAL */
    }

    if (g_jmms_context->jsr_total_object > 0)
    {
        U8 count = 0;
        MM1_CONTENT MM1Content = {0, };

        for (count = 0; count < g_jmms_context->jsr_total_object; count++)
        {
            jdi_MM1GetContent(g_jmms_context->mm1_handle, &MM1Content, count);
            if (jc_strstr(MM1Content.pszMimeType, "application/smil") != NULL)
            {
                resp->bdy_part_no = (U8) g_jmms_context->jsr_total_object - 1;
                break;
            }
        }

        if (count == g_jmms_context->jsr_total_object)
        {
            resp->bdy_part_no = (U8) g_jmms_context->jsr_total_object;
        }
    }
    else
    {
        resp->bdy_part_no = (U8) g_jmms_context->jsr_total_object;
    }

    content_type = (JC_INT8*) jdi_MM1GetContentType(g_jmms_context->mm1_handle);
    if (content_type == NULL)
    {
        resp->result = JSR_RESULT_ERROR;
        goto END;
    }

    mmi_jmms_java_mms_set_content_type_params(resp, content_type);

    ret_code = jdi_MM1GetSubject(g_jmms_context->mm1_handle, &subject, &eCharset);

    /* subject */
    buf_size += 4;  /* subject_data_len 4bytes; */
    if (subject)
    {
        buf_size += 4;  /* subject_encode_type 4bytes */
        subject_len = mmi_charset_ucs2_to_utf8_length_in_bytes((U8*) subject);
        buf_size += subject_len;
    }

    /* from address  ///from address can be one only */
    ret_code = jdi_MM1GetFromAddress(g_jmms_context->mm1_handle, &p_from_AddressList);
    if (ret_code != JC_OK)
    {
        resp->result = JSR_RESULT_ERROR;
        goto END;
    }
    resp->from_addr_no = 0;
    if (p_from_AddressList != NULL && p_from_AddressList->pAddress != NULL)
    {

        resp->from_addr_no = 1;
        address_len = mmi_ucs2strlen((S8*) (p_from_AddressList->pAddress));
        buf_size += (8 + address_len);
    }

    /* to address */
    ret_code = jdi_MM1GetToAddress(g_jmms_context->mm1_handle, &p_to_AddressList);
    if (ret_code != JC_OK)
    {
        resp->result = JSR_RESULT_ERROR;
        goto END;
    }
    resp->to_addr_no = 0;
    if (p_to_AddressList != NULL)
    {
        MMS_ADDRESS_LIST *to_list = p_to_AddressList;

        while (to_list)
        {
            if (to_list->pAddress)
            {
                resp->to_addr_no += 1;
                address_len = mmi_ucs2strlen((S8*) (to_list->pAddress));
                buf_size += (8 + address_len);
            }
            to_list = to_list->pNext;
        }
    }

    /* cc address */
    ret_code = jdi_MM1GetCCAddress(g_jmms_context->mm1_handle, &p_cc_AddressList);
    if (ret_code != JC_OK)
    {
        resp->result = JSR_RESULT_ERROR;
        goto END;
    }
    resp->cc_addr_no = 0;
    if (p_cc_AddressList != NULL)
    {
        MMS_ADDRESS_LIST *cc_list = p_cc_AddressList;

        while (cc_list)
        {
            if (cc_list->pAddress)
            {
                resp->cc_addr_no += 1;
                address_len = mmi_ucs2strlen((S8*) (cc_list->pAddress));
                buf_size += (8 + address_len);
            }
            cc_list = cc_list->pNext;
        }
    }

    buf = jdd_MemAlloc(sizeof(S8), buf_size);
    if (buf == NULL)
    {

        resp->result = JSR_RESULT_INSUFFICIENT_MEMORY;
        goto END;

    }

    /* Pack subject */
    if (subject)
    {
        S8 *temp_subject = NULL;

        *(U32*) buf = subject_len;
        *(U32*) (buf + 4) = MMI_JMMS_JSR_SUBJECT_ENCODED_VALUE;        /* /MMS_UTF8. Note::: Encoded value used is as given in mms_def.h file in Teleca. */
        /* /TODO:: may need to confirm value */

        temp_subject = jdd_MemAlloc(sizeof(S8), subject_len + 1);
        if (temp_subject == NULL)
        {
            resp->result = JSR_RESULT_INSUFFICIENT_MEMORY;
            goto END;
        }

        mmi_chset_ucs2_to_utf8_string((U8*) temp_subject, (subject_len + 1), (U8*) subject);
        memcpy(buf + 8, temp_subject, subject_len);
        datalen += (8 + subject_len);
        if (temp_subject != NULL)
        {
            jdd_MemFree(temp_subject);
            temp_subject = NULL;
        }

    }
    else
    {
        *(U32*) buf = 0;    /* subject_data_len=0 */
        datalen += 4;
    }
    /* Pack from address field */
    if (resp->from_addr_no == 1)
    {
        U32 temp_address_len = mmi_ucs2strlen((S8*) (p_from_AddressList->pAddress));
        U32 address_type;
        S8 *temp_address = NULL;

        address_type = mmi_jmms_java_map_address_type(p_from_AddressList->eAddressType);
        memcpy((char*)(buf + datalen), &address_type, 4);
        memcpy((char*)(buf + datalen + 4), &temp_address_len, 4);

        temp_address = jdd_MemAlloc(sizeof(S8), temp_address_len + 1);
        if (temp_address == NULL)
        {
            resp->result = JSR_RESULT_INSUFFICIENT_MEMORY;
            goto END;
        }

        mmi_ucs2_to_asc(temp_address, (S8*) (p_from_AddressList->pAddress));
        memcpy((char*)(buf + datalen + 8), temp_address, temp_address_len);
        datalen += (8 + temp_address_len);
        if (temp_address != NULL)
        {
            jdd_MemFree(temp_address);
            temp_address = NULL;
        }
    }

    /* /Pack to address field */
    if (p_to_AddressList)
    {
        MMS_ADDRESS_LIST *to_list = p_to_AddressList;

        while (to_list)
        {
            if (to_list->pAddress)
            {
                U32 temp_address_len = mmi_ucs2strlen((S8*) (to_list->pAddress));
                U32 address_type;
                S8 *temp_address = NULL;

                address_type = mmi_jmms_java_map_address_type(to_list->eAddressType);
                memcpy((char*)(buf + datalen), &address_type, 4);
                memcpy((char*)(buf + datalen + 4), &temp_address_len, 4);

                temp_address = jdd_MemAlloc(sizeof(S8), temp_address_len + 1);
                if (temp_address == NULL)
                {
                    resp->result = JSR_RESULT_INSUFFICIENT_MEMORY;
                    goto END;
                }

                mmi_ucs2_to_asc(temp_address, (S8*) (to_list->pAddress));
                memcpy((char*)(buf + datalen + 8), temp_address, temp_address_len);
                datalen += (8 + temp_address_len);
                if (temp_address != NULL)
                {
                    jdd_MemFree(temp_address);
                    temp_address = NULL;
                }

            }
            to_list = to_list->pNext;
        }
    }
    /* Pack cc address field */
    if (p_cc_AddressList)
    {
        MMS_ADDRESS_LIST *cc_list = p_cc_AddressList;

        while (cc_list)
        {
            if (cc_list->pAddress)
            {
                U32 temp_address_len = mmi_ucs2strlen((S8*) (cc_list->pAddress));
                U32 address_type;
                S8 *temp_address = NULL;

                address_type = mmi_jmms_java_map_address_type(cc_list->eAddressType);
                memcpy((char*)(buf + datalen), &address_type, 4);
                memcpy((char*)(buf + datalen + 4), &temp_address_len, 4);

                temp_address = jdd_MemAlloc(sizeof(S8), temp_address_len + 1);
                if (temp_address == NULL)
                {
                    resp->result = JSR_RESULT_INSUFFICIENT_MEMORY;
                    goto END;
                }
                mmi_ucs2_to_asc(temp_address, (S8*) (cc_list->pAddress));
                memcpy((char*)(buf + datalen + 8), temp_address, temp_address_len);
                datalen += (8 + temp_address_len);
                if (temp_address != NULL)
                {
                    jdd_MemFree(temp_address);
                    temp_address = NULL;
                }
            }
            cc_list = cc_list->pNext;
        }
    }

    resp->result = (U8) mmi_jmms_java_mms_error(JC_OK);

  END:

    if (g_jmms_context->jsr_mms_receive_callback != NULL)
    {
        if (resp != NULL)
        {
            g_jmms_context->jsr_mms_receive_callback(resp, buf, datalen);
        }
    }

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

    if (p_from_AddressList != NULL)
    {
        FreeAddressList(p_from_AddressList);
    }

    if (p_to_AddressList != NULL)
    {
        FreeAddressList(p_to_AddressList);
    }

    if (p_cc_AddressList != NULL)
    {
        FreeAddressList(p_cc_AddressList);
    }

    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_java_map_address_type
 * DESCRIPTION
 *  This function maps the address type of Jataayu MMS type with MMS address type.
 * PARAMETERS
 *  type        [IN]        MMS address type
 * RETURNS
 *  Returns MMS address type
 *****************************************************************************/
mmi_jmms_java_addresses_type_enum mmi_jmms_java_map_address_type(MMSAddressTypes type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case E_PLMN:
            return MMS_PLMN;

        case E_IPV4:
            return MMS_IPV4;

        case E_MAIL:
            return MMS_EMAIL;

        case E_IPV6:
        default:
            return MMS_UNSUPPORTED;
    }

    return MMS_UNSUPPORTED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_jsr_generate_recv_msg_body_part
 * DESCRIPTION
 *  This function creates the temporary media file and provides
 *  the media details to JSR module.
 * PARAMETERS
 *  msg_id              [IN]            Message id of MMS
 *  bdy_part_no         [IN/OUT]        Media object number
 *  total_objects       [IN]            Total media objects in MMS
 *  response            [OUT]           Media object structure
 * RETURNS
 *  Returns MMI_TRUE in case of success; otherwise returns MMI_FALSE.
 *****************************************************************************/
MMI_BOOL mmi_jmms_jsr_generate_recv_msg_body_part(
            U32 msg_id,
            U8 *bdy_part_no,
            U8 total_objects,
            wap_mmc_read_appmms_msg_part_rsp_struct *response)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MM1_CONTENT MM1Content = {0, };
    MM1_HANDLE mm1_handle = NULL;
    JC_RETCODE ret_code = JC_OK;
    S8 *str_pos = NULL;
    S8 *temp_str = NULL;
    int read_handle = -1;
    int write_handle = -1;
    S8 *filename = NULL;
    S8 *media_buffer_p = NULL;
    int result = 0;
    U32 bytes_written = 0;
    S32 file_size = 0;
    S32 buf_size = 0;
    U8 part_no = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS JSR mmi_jmms_jsr_generate_recv_msg_body_part.");

    part_no = (*bdy_part_no - 1);

    if (g_jmms_context->mm1_handle != NULL)
    {
        mm1_handle = g_jmms_context->mm1_handle;
    }
    else
    {
        return FALSE;
    }

    ret_code = jdi_MM1GetContent(mm1_handle, &MM1Content, part_no);
    if (strstr(MM1Content.pszMimeType, "application/smil") != NULL)
    {
        ret_code = jdi_MM1GetContent(mm1_handle, &MM1Content, part_no + 1);
        *bdy_part_no += 1;
    }

    response->result = JSR_RESULT_OK;

    /* for content type: */
    if ((str_pos = strstr((S8*) MM1Content.pszMimeType, ";")) != NULL)
    {
        response->content_type_len = str_pos - MM1Content.pszMimeType;
    }
	else
	{
		str_pos = MM1Content.pszMimeType + strlen(MM1Content.pszMimeType);
		response->content_type_len = str_pos - MM1Content.pszMimeType;
	}

    if (response->content_type_len > 255)
    {
        response->content_type_len = 255;
    }

    memset(response->content_type, 0, response->content_type_len + 1);
    strncpy((S8*) response->content_type, (S8*) MM1Content.pszMimeType, (U8) response->content_type_len);     /* query */
    response->content_type_len = strlen((PS8)response->content_type);

    /* For encoding scheme: */
    temp_str = str_pos + 1;

    if ((str_pos = strstr((S8*) temp_str, "Charset=utf-8")) != NULL)
    {
        response->encoding_scheme = MMS_UTF8;
    }
    else if ((str_pos = strstr((S8*) temp_str, "Charset=iso-8859-1")) != NULL)
    {
        response->encoding_scheme = MMS_ISO_8859_1;
    }
    else if ((str_pos = strstr((S8*) temp_str, "Charset=utf-16")) != NULL)
    {
        response->encoding_scheme = (U8) MMS_UTF16;
    }
    else if ((str_pos = strstr((S8*) temp_str, "Charset=us-ascii")) != NULL)
    {
        response->encoding_scheme = MMS_US_ASCII;
    }
    else
    {
        response->encoding_scheme = MMS_UNKNOWN_CHARSET;
    }

    /* for content id: */
    response->content_id_len = strlen(MM1Content.pszContentID);

    if (response->content_id_len < 100)
    {
        strcpy((S8*) response->content_id, (S8*) MM1Content.pszContentID);    /* query */
    }
    else
    {
        response->content_id_len = 99;
        memset(response->content_id, 0, response->content_id_len + 1);
        strncpy((S8*) response->content_id, (S8*) MM1Content.pszContentID, response->content_id_len); /* query */
    }

    /* for content location: */
    response->content_location_len = strlen(MM1Content.pszObjectName);

    if (response->content_location_len < 100)
    {
        strcpy((S8*) response->content_location, (S8*) MM1Content.pszObjectName);     /* query */
    }
    else
    {
        response->content_location_len = 99;
        memset(response->content_location, 0, response->content_location_len + 1);
        strncpy((S8*) response->content_location, (S8*) MM1Content.pszObjectName, response->content_location_len);    /* query */
    }

    /* for file path: */
    if (MM1Content.MimeData.bIsStream == 1)
    {
        filename = (S8*) jdd_MemAlloc(sizeof(S8), 100);
        if (NULL == filename)
        {
            response->result = JSR_RESULT_INSUFFICIENT_MEMORY;
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d): JMMS JSR Insufficient Memory. \n", __FILE__, __LINE__);
            return FALSE;
        }

        mmi_asc_to_ucs2((S8*) filename, (S8*) (JSR_MEDIA_OBJECT_FILE));

        FS_Delete((U16*) filename);

        write_handle = FS_Open((U16*) (filename), FS_CREATE_ALWAYS | FS_READ_WRITE);
        if (write_handle < 0)
        {
            response->result = JSR_RESULT_FILE_OPERATION_ERROR;
            jdd_MemFree(filename);
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d): JMMS JSR File Operation Error \n", __FILE__, __LINE__);
            return FALSE;
        }

        read_handle = FS_Open(MM1Content.MimeData.pFileName, FS_READ_ONLY);
        if (read_handle < 0)
        {
            response->result = JSR_RESULT_FILE_OPERATION_ERROR;
            jdd_MemFree(filename);
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d): JMMS JSR File Operation Error \n", __FILE__, __LINE__);
            return FALSE;
        }

        media_buffer_p = (S8*) jdd_MemAlloc(sizeof(S8), (512 + 1));
        if (NULL == media_buffer_p)
        {
            response->result = JSR_RESULT_INSUFFICIENT_MEMORY;
            jdd_MemFree(filename);
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d): JMMS JSR Insufficient Memory \n", __FILE__, __LINE__);
            return FALSE;
        }
        FS_Seek(read_handle, MM1Content.MimeData.uiStartOffset, FS_FILE_BEGIN);

        file_size = MM1Content.MimeData.uiTotalSize;
	    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_jsr_generate_recv_msg_body_part file_size %d ", file_size);
        while (file_size)
        {
            if (file_size > 512)
            {
                buf_size = 512;
            }
            else
            {
                buf_size = file_size;
            }

            ASSERT(FS_Read(read_handle, media_buffer_p, buf_size, &bytes_written) == 0);
            result = FS_Write(write_handle, media_buffer_p, buf_size, &bytes_written);
            if (FS_NO_ERROR != result)
            {
                response->result = JSR_RESULT_FILE_OPERATION_ERROR;
                FS_Close(read_handle);
                FS_Close(write_handle);
                jdd_MemFree(filename);
                jdd_MemFree(media_buffer_p);
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_jsr_generate_recv_msg_body_part File Write Error");
                return FALSE;
            }
	        else
	        {
		        PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_jsr_generate_recv_msg_body_part written %d ", bytes_written);
		        PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_jsr_generate_recv_msg_body_part request %d", buf_size);
	        }
            file_size -= buf_size;
        }

        FS_Close(read_handle);
        FS_Close(write_handle);

        response->filepath_len = mmi_ucs2strlen((S8*) filename);
        memset(response->filepath, 0, ((response->filepath_len + 1) * 2));
        mmi_ucs2cpy((S8*) response->filepath, (S8*) filename);
        jdd_MemFree(filename);
        jdd_MemFree(media_buffer_p);

    }
    else
    {
        if (g_jmms_context->jmms_fs_handle == NULL)
        {
            if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
            {
                ret_code = JC_ERR_FILE_SYS_INIT;
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d): JMMS JSR File System Init Error \n", __FILE__, __LINE__);
                return FALSE;
            }
        }

        filename = (S8*) jdd_MemAlloc(sizeof(S8), 100);
        if (NULL == filename)
        {
            response->result = JSR_RESULT_INSUFFICIENT_MEMORY;
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d): JMMS JSR Insufficient Memory \n", __FILE__, __LINE__);
            return FALSE;
        }

        mmi_asc_to_ucs2((S8*) filename, (S8*) (JSR_MEDIA_OBJECT_FILE));

        FS_Delete((U16*) filename);

        write_handle = FS_Open((U16*) (filename), FS_CREATE_ALWAYS | FS_READ_WRITE);
        if (write_handle < 0)
        {
            response->result = JSR_RESULT_FILE_OPERATION_ERROR;
            jdd_MemFree(filename);
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d): JMMS JSR File Operation Error \n", __FILE__, __LINE__);
            return FALSE;
        }

        media_buffer_p = (S8*) jdd_MemAlloc(sizeof(S8), (512 + 1));
        if (NULL == media_buffer_p)
        {
            response->result = JSR_RESULT_INSUFFICIENT_MEMORY;
            jdd_MemFree(filename);
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d): JMMS JSR Insufficient Memory \n", __FILE__, __LINE__);
            return FALSE;
        }

        if (MM1Content.MimeData.uiTotalSize > 0)
        {
            if ((response->encoding_scheme == MMS_US_ASCII) || (response->encoding_scheme == MMS_UTF8))
            {
                response->encoding_scheme = MMS_UTF8;
                buf_size = mmi_charset_ucs2_to_utf8_length_in_bytes((U8*) MM1Content.MimeData.pBuffer);
                mmi_chset_ucs2_to_utf8_string(
                    (U8*) media_buffer_p,
                    (buf_size + 1),
                    (U8*) MM1Content.MimeData.pBuffer);
                result = FS_Write(write_handle, media_buffer_p, buf_size, &bytes_written);
            }
            else
            {
                result = FS_Write(
                            write_handle,
                            MM1Content.MimeData.pBuffer,
                            MM1Content.MimeData.uiTotalSize,
                            &bytes_written);
            }
        }

        if (FS_NO_ERROR != result)
        {
            response->result = JSR_RESULT_FILE_OPERATION_ERROR;
            FS_Close(write_handle);
            jdd_MemFree(filename);
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d): JMMS JSR File Operation Error \n", __FILE__, __LINE__);
            return FALSE;
        }

        FS_Close(write_handle);

        response->filepath_len = mmi_ucs2strlen((S8*) filename);
        memset(response->filepath, 0, ((response->filepath_len + 1) * 2));
        mmi_ucs2cpy((S8*) response->filepath, (S8*) filename);
        jdd_MemFree(filename);
    }

    if (total_objects == *bdy_part_no)
    {
        /* jdi_MM1Cleanup(g_jmms_context->mm1_handle, E_FALSE); */
        jdi_MM1DeInitialize(g_jmms_context->mm1_handle);

        g_jmms_context->mm1_handle = NULL;
    }
    return TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_check_msg_id
 * DESCRIPTION
 *  This function checks the existence of MMS in inbox folder
 *  having message id msg_id.
 * PARAMETERS
 *  msg_id      [IN]        Message id of MMS
 * RETURNS
 *  Returns MMI_TRUE in case of MMS is found; otherwise MMI_FALSE.
 *****************************************************************************/
MMI_BOOL mmi_jmms_check_msg_id(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MESSAGE_LIST *message_list_p = NULL;
    MESSAGE_LIST *temp_message_list_p = NULL;
    S8 fname[100];

    RETRIEVE_FILTERS retrieve_filter = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(fname, 0, 100);
    mmi_jmms_get_folder_name_from_folderId(JSR_INBOX, fname);

    /* /manish chnging here 0n 2 Feb */
    retrieve_filter.uiStartIndex = 1;
    retrieve_filter.uiNumMessage = 0;
    retrieve_filter.eRetrieve = E_RETRIEVE_BY_INDEX;
    mmi_jmms_get_messages_list((S8*) fname, &message_list_p, &retrieve_filter);
    temp_message_list_p = message_list_p;

    while (temp_message_list_p)
    {
        if ((temp_message_list_p->uiExtraBytes & 0x0FFFFFFF) == msg_id)
        {
            return TRUE;
        }
        temp_message_list_p = temp_message_list_p->pNext;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_update_folder
 * DESCRIPTION
 *  This function refreshes the MMS folder while uploading/deleting MMS
 *  through AT command.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_update_folder(void)
{
#ifdef __MMI_UNIFIED_MESSAGE__
    mmi_um_jmms_refresh_ind();
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 screen_id;
    S16 is_screen_update = 1;
    S8 *pFolderName = NULL;
    MESSAGE_LIST *message_list_p = NULL;
    RETRIEVE_FILTERS retrieve_filter = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    void (*entry_folder_screen_callback_hldr) (void) = NULL;

    retrieve_filter.uiStartIndex = 1;
    retrieve_filter.uiNumMessage = 0;
    retrieve_filter.eRetrieve = E_RETRIEVE_BY_INDEX;

    screen_id = GetActiveScreenId();
    switch (screen_id)
    {
        case SCR_ID_JMMS_MAIN_MENU:
            break;
        case SCR_ID_JMMS_INBOX:
            pFolderName = (S8*) MMI_JMMS_INBOX;
            entry_folder_screen_callback_hldr = mmi_jmms_entry_inbox_screen;
            break;
        case SCR_ID_JMMS_OUTBOX:
            pFolderName = (S8*) MMI_JMMS_OUTBOX;
            entry_folder_screen_callback_hldr = mmi_jmms_entry_outbox_screen;
            break;
        case SCR_ID_JMMS_SENT:
            pFolderName = (S8*) MMI_JMMS_SENT;
            entry_folder_screen_callback_hldr = mmi_jmms_entry_sent_screen;
            break;
        case SCR_ID_JMMS_DRAFTS:
            pFolderName = (S8*) MMI_JMMS_DRAFTS;
            entry_folder_screen_callback_hldr = mmi_jmms_entry_drafts_screen;
            break;
        default:
            is_screen_update = 0;
            break;
    }

    if (is_screen_update == 0)
    {
    #ifndef __MMI_UNIFIED_MESSAGE__
        if (IsScreenPresent(SCR_ID_JMMS_INBOX)
            || IsScreenPresent(SCR_ID_JMMS_OUTBOX)
            || IsScreenPresent(SCR_ID_JMMS_SENT) || IsScreenPresent(SCR_ID_JMMS_DRAFTS))
        {
            g_jmms_context->store_context->update_nmsgs_in_current_folder = 1;
        }
    #endif /* __MMI_UNIFIED_MESSAGE__ */ 
        return;
    }
#ifndef __MMI_UNIFIED_MESSAGE__
    g_jmms_context->store_context->update_nmsgs_in_current_folder = 1;
#endif 

    if (pFolderName != NULL)
    {
        mmi_jmms_get_messages_list((S8*) pFolderName, &message_list_p, &retrieve_filter);
        if (message_list_p == NULL)
        {
            GoBackToHistory(SCR_ID_JMMS_MAIN_MENU);
            return;
        }
        entry_folder_screen_callback_hldr();
    }
    else
    {
        mmi_jmms_entry_main_menu();
        DeleteNHistory(1);
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_jsr_delete_msg
 * DESCRIPTION
 *  This function delete the MMS as per message id.
 * PARAMETERS
 *  msg_id      [IN]        Message id of MMS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_jsr_delete_msg(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_delete_message_as_per_id(msg_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_jsr_send_mms
 * DESCRIPTION
 *  This function will send the JSR MMS.
 * PARAMETERS
 *  send_callback       [IN]        Send callback
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_jsr_send_mms(MMI_JMMS_JSR_SEND_CALLBACK send_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    static U32 unique_value = 0;
    JC_INT8 Temp[50] = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PMT HIMANSHU START 20060425 */
    mmi_jmms_set_mms_downloading_busy();
    mmi_jmms_update_status_icon_indicator();
    /* PMT HIMANSHU END 20060425 */

    if (g_jmms_context->mm1_handle == NULL)
    {
        (*send_callback) (mmi_jmms_java_mms_error(JC_ERR_MSG_INVALID_HANDLE));
        return;
    }

    if (g_jmms_context->send_content_p != NULL)
    {
        jdd_MemFree(g_jmms_context->send_content_p);
        g_jmms_context->send_content_p = NULL;
    }
    if (g_jmms_context->send_content_p == NULL)
    {
        g_jmms_context->send_content_p = (CONTENT_DATA*) jdd_MemAlloc(sizeof(CONTENT_DATA), 1);
    }

    g_jmms_context->send_content_p->bIsStream = E_TRUE;
    g_jmms_context->send_content_p->cbWriteCallback = mmi_jmms_write_callback;

    unique_value++;
    if (unique_value > 200000)
    {
        unique_value = 0;
    }

    jc_sprintf(Temp, "%s%d", "@mms\\temp\\jmms_tempJSendBuff", unique_value);

    jdi_UtilsCharToTchar((JC_CHAR **) & (g_jmms_context->send_content_p->pStream), Temp);

    if (g_jmms_context->jmms_fs_handle == NULL)
    {
        if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
        {
            /* return JC_ERR_FILE_SYS_INIT; */
            (*send_callback) (JSR_RESULT_ERROR);
            return;
        }
    }

    jdd_FSDelete(g_jmms_context->jmms_fs_handle, g_jmms_context->send_content_p->pStream);

    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
    }

    g_jmms_context->send_content_p->pFileName = g_jmms_context->send_content_p->pStream;

    g_jmms_context->jsr_mms_send_callback = send_callback;
    ret_code = jdi_MM1GetEncodedStream(g_jmms_context->mm1_handle, g_jmms_context->send_content_p);

    if (ret_code == JC_ERR_MMS_ENCODE_PENDING)
    {
        mmi_jmms_mm1_encode_continue_start_timer();
    }
    else
    {
        mmi_jmms_mm1_send_callback(ret_code);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_mm1_send_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_mm1_send_callback(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *temp = NULL;
    COMM_FETCH_URL fetch_url_info = {0, };
    JC_CHAR *fileptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (JC_OK != ret_code)
    {
        /* jdi_MM1Cleanup(g_jmms_context->mm1_handle, E_FALSE); */
        /* Memory Leak Fix: jdi_MM1Cleanup is allocating memory for data chunk after freeing the context */
        jdi_MM1DeInitialize(g_jmms_context->mm1_handle);
        g_jmms_context->mm1_handle = NULL;
        goto END;
    }
    /* jdi_MM1Cleanup(g_jmms_context->mm1_handle, E_FALSE); */
    /* Memory Leak Fix: jdi_MM1Cleanup is allocating memory for data chunk after freeing the context */
    jdi_MM1DeInitialize(g_jmms_context->mm1_handle);
    g_jmms_context->mm1_handle = NULL;

    fetch_url_info.eContentMode = E_COMM_BUFFER;

    temp = mmi_jmms_get_activated_mmsc_url(g_jmms_context);

    fetch_url_info.pszURL = (JC_CHAR*) temp;

    fetch_url_info.pszContentType = "application/vnd.wap.mms-message";

    if (g_jmms_context->send_content_p->bIsStream == E_FALSE)
    {
        fetch_url_info.bIsFile = E_FALSE;
        fetch_url_info.uUserDataMode.pucPostData = g_jmms_context->send_content_p->pBuffer;
    }
    else
    {
        fetch_url_info.bIsFile = E_TRUE;
        fetch_url_info.uUserDataMode.pmFileName = g_jmms_context->send_content_p->pFileName;
    }

    fetch_url_info.uiPostLen = g_jmms_context->send_content_p->uiTotalSize;
    fetch_url_info.pHeadersInfo = NULL;

    fetch_url_info.eCommFetchType = E_COMM_FETCH_POST;

    g_jmms_context->reference_id = 0;

    ret_code = jdi_CommunicationFetchURL(g_jmms_context->comm_handle, &fetch_url_info, &(g_jmms_context->reference_id));
    if (ret_code == JC_OK)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d):\n", "JMMS JSR Comm Fetch Send", g_jmms_context->reference_id);

        fileptr = jdi_UtilsTcsDup(g_jmms_context->send_content_p->pFileName);
        ret_code = mmi_jmms_add_comm_node(
                    g_jmms_context,
                    g_jmms_context->reference_id,
                    E_TYPE_NEW_JAVA_MMS_SEND,
                    fileptr,
                    0,
                    1,
                    NULL
#ifdef __MMI_UNIFIED_COMPOSER__
                , NULL
#endif
                );
        if (ret_code != JC_OK)
        {
            ret_code = jdi_CommunicationFreeReference(g_jmms_context->comm_handle, g_jmms_context->reference_id);
            g_jmms_context->reference_id = 0;
            ret_code = E_JMMS_GENERAL_ERROR;
            goto END;
        }
    }
    else
    {
        goto END;
    }

  END:

    if (ret_code != JC_OK)
    {
        /* PMT VIKAS START 20060401 */
        mmi_jmms_reset_mms_downloading_busy();
        mmi_jmms_update_status_icon_indicator();
        /* PMT VIKAS END 20060401 */

        if (g_jmms_context->send_content_p != NULL && g_jmms_context->send_content_p->pStream != NULL)
        {

            if (g_jmms_context->jmms_fs_handle == NULL)
            {
                if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
                {
                    /* return JC_ERR_FILE_SYS_INIT; */
                    g_jmms_context->jsr_mms_send_callback(JSR_RESULT_ERROR);
                    return;
                }
            }

            jdd_FSDelete(g_jmms_context->jmms_fs_handle, g_jmms_context->send_content_p->pStream);

            if (g_jmms_context->jmms_fs_handle != NULL)
            {
                jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
                g_jmms_context->jmms_fs_handle = NULL;
            }
        }

        if (fileptr != NULL)
        {
            jdd_MemFree(fileptr);
        }

        g_jmms_context->jsr_mms_send_callback(JSR_RESULT_ERROR);
        return;
    }

    if (g_jmms_context->send_content_p != NULL)
    {
        if (g_jmms_context->send_content_p->pStream != NULL)
        {
            jdd_MemFree(g_jmms_context->send_content_p->pStream);
            g_jmms_context->send_content_p->pStream = NULL;
        }
        jdd_MemFree(g_jmms_context->send_content_p);
        g_jmms_context->send_content_p = NULL;
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_jsr_cancel_send_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id              [IN]        
 *  cancel_callback     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_jsr_cancel_send_mms(U32 msg_id, MMI_JMMS_JSR_SEND_CALLBACK cancel_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_code = jdi_CommunicationStopReq(g_jmms_context->comm_handle, g_jmms_context->reference_id);

    if (ret_code != JC_OK)
    {
        ret_code = jdi_CommunicationFreeReference(g_jmms_context->comm_handle, g_jmms_context->reference_id);
        g_jmms_context->reference_id = 0;
        (*cancel_callback) (JSR_RESULT_ERROR);
        return;
    }
    ret_code = jdi_CommunicationFreeReference(g_jmms_context->comm_handle, g_jmms_context->reference_id);
    g_jmms_context->reference_id = 0;

    g_jmms_context->jsr_mms_send_cancel_callback = cancel_callback;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_content_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  encapsulated_content_p      [IN]        
 *  mms_content_type            [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_jmms_get_content_type(CONTENT_DATA *encapsulated_content_p, JC_INT8 **mms_content_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    JC_RETCODE ret_code = JC_OK;
    MM1_HANDLE mm1_handle = NULL;
    CONTENT_DATA Decode;

    JC_UINT32 num_objects = 0;
    EMM1MessageType mm1_msg_type = 0;

    JC_INT8 *content_type = NULL;
    U32 len = 0;
    JC_INT8 *temp_content_type = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d) Enters mmi_jmms_get_content_type", __FILE__, __LINE__);

    ret_code = jdi_MM1Initialize(&mm1_handle);

    if (ret_code != JC_OK)
    {
        goto END;
    }
    jc_memset(&Decode, 0, sizeof(CONTENT_DATA));

    /* /for file streaming */
    Decode = *encapsulated_content_p;

    ret_code = jdi_MM1Decode(mm1_handle, &Decode, E_PARSE_HEADERS_ONLY, MsgCtrl_CreateStream, &num_objects);    // TODO:: test it returns ok
    while (ret_code == JC_ERR_MMS_PARSE_PENDING)
    {
        mmi_jmms_mm1_decode_continue_start_timer(num_objects, NULL);
    }

    if (ret_code != JC_OK)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;    /* eror type doesn't matter */
        goto END;
    }
    ret_code = jdi_MM1GetMessageType(mm1_handle, &mm1_msg_type);
    if (ret_code != JC_OK)
    {
        goto END;
    }

    if (mm1_msg_type != E_MMS_RETRIEVE_CONFIRMATION_VALUE)
    {
        ret_code = E_JMMS_GENERAL_ERROR;    /* eror type doesn't matter */
        goto END;
    }

    content_type = (JC_INT8*) jdi_MM1GetContentType(mm1_handle);
    if (content_type == NULL)
    {
        ret_code = E_JMMS_GENERAL_ERROR;
        goto END;
    }

    len = strlen((const char*)content_type);
    temp_content_type = (JC_INT8*) jdd_MemAlloc(sizeof(JC_INT8), len + 1);
    if (temp_content_type == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto END;
    }

    *mms_content_type = temp_content_type;

    strcpy((char*)temp_content_type, (const char*)content_type);

  END:

    jdi_MM1DeInitialize(mm1_handle);

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "(%d) Exits mmi_jmms_get_content_type with retcode %d", __LINE__, ret_code);

    return ret_code;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_is_message_found
 * DESCRIPTION
 *  
 * PARAMETERS
 *  folder_id       [IN]        
 *  msg_id          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_jmms_is_message_found(U8 folder_id, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MESSAGE_LIST *message_list_p = NULL;
    MESSAGE_LIST *temp_message_list_p = NULL;
    S8 fname[100];
    RETRIEVE_FILTERS retrieve_filter = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_is_message_found msgID(%X)", msg_id);
    memset(fname, 0, 100);
    mmi_jmms_get_folder_name_from_folderId(folder_id, fname);

    retrieve_filter.uiStartIndex = 1;
    retrieve_filter.uiNumMessage = 0;
    retrieve_filter.eRetrieve = E_RETRIEVE_BY_INDEX;

    mmi_jmms_get_messages_list((S8*) fname, &message_list_p, &retrieve_filter);

    temp_message_list_p = message_list_p;

    while (temp_message_list_p)
    {
	PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_is_message_found msgID(%X)", temp_message_list_p->uiExtraBytes);
        if ((temp_message_list_p->uiExtraBytes & 0x0FFFFFFF) == msg_id)
        {
            return JC_OK;
        }
        temp_message_list_p = temp_message_list_p->pNext;
    }
    return JC_ERR_NOT_FOUND;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_mm1_encode_continue_start_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_mm1_encode_continue_start_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StartTimer(JMMS_ASYNC_SEND_TIMER, JMMS_ASYNC_EVENT_TIME, mmi_jmms_mm1_encode_continue_callback);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_mm1_encode_continue_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_mm1_encode_continue_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(JMMS_ASYNC_SEND_TIMER);
    jdd_MemSetActiveModuleID(E_TASK_MMS_UI);
    ret_code = jdi_MM1EncodeNextPart(g_jmms_context->mm1_handle);
    if (ret_code == JC_ERR_MMS_ENCODE_PENDING)
    {
        StartTimer(JMMS_ASYNC_SEND_TIMER, JMMS_ASYNC_EVENT_TIME, mmi_jmms_mm1_encode_continue_callback);
    }
    else
    {
        mmi_jmms_mm1_send_callback(ret_code);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_mm1_decode_continue_start_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  total_obj       [IN]        
 *  new_err_cb      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_mm1_decode_continue_start_timer(JC_UINT32 total_obj, error_callback new_err_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->async_parse_context.is_re_entrant = 1;
    StartTimer(JMMS_ASYNC_PARSE_TIMER, JMMS_ASYNC_EVENT_TIME, mmi_jmms_mm1_decode_continue_callback);
    g_jmms_context->jsr_total_object = total_obj;
    g_jmms_context->async_parse_context.callback = new_err_cb;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_mm1_decode_continue_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_mm1_decode_continue_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(JMMS_ASYNC_PARSE_TIMER);
    jdd_MemSetActiveModuleID(E_TASK_MMS_UI);
    ret_code = jdi_MM1DecodeNextPart(g_jmms_context->mm1_handle, &g_jmms_context->jsr_total_object);
    if (ret_code == JC_ERR_MMS_PARSE_PENDING)
    {
        StartTimer(JMMS_ASYNC_PARSE_TIMER, JMMS_ASYNC_EVENT_TIME, mmi_jmms_mm1_decode_continue_callback);
    }
    else
    {
        mmi_jmms_parse_call_error_callback(ret_code);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_attachment_filepath
 * DESCRIPTION
 *  This function is written to get the virtual file path, required during the
 *  installation of JAVA.
 * PARAMETERS
 *  filename        [IN]        
 *  msg             [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_get_attachment_filepath(S8 *filename, mms_get_attachment_rsp_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 media_count = 0;
    MEDIA_INFO *media_info;
    MEDIA_MIME_INFO *mime_info_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg->result = 0;
    /* Get the number of attachment with the MMS */
    mmi_jmms_jdi_get_media_count(g_jmms_context->msg_handle, 0, &media_count, E_TRUE);
    /* Atleast 2 files should be there that are .jar and .jad */
    if (media_count < 2)
    {
        return;
    }
    /* Get the MMS attachment information */
    if (mmi_jmms_compose_get_media_list(0, &media_info, &media_count, E_TRUE) == JMMS_COMP_OK)
    {
        U8 count = 0;

        for (count = 0; count < media_count; count++)
        {
            /* Check for the required file */
            if (mmi_ucs2cmp((S8*) filename, (S8*) media_info->pMimeInfo->MimeHeaders.pObjectName) == 0)
            {
                /* File name matched. Set the result as 1. */
                msg->result = 1;
                break;
            }
            /* Move to the next attachment information node */
            media_info = media_info->pNext;
        }
        /* If the required file not found */
        if (msg->result == 0)
        {
            return;
        }
        /* Get the information of required attachment file. */
        mime_info_p = media_info->pMimeInfo;
        /* Get the Virtual file name of the required attachment file. */
        mmi_ucs2cpy((kal_char*) msg->filepath, (kal_char*) mime_info_p->ContentData.pFileName);
    }
}
#endif /* __MMI_JMMS_JAVA_MMS_SUPPORT__ */ 

#endif /* (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT)) */ 

#endif /* _MMI_JMMSJSRHANDLER_C */ 


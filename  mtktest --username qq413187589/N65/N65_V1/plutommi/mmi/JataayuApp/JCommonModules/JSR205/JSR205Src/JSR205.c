/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * JSR205.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
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
#ifndef _MMI_JSR_C
#define _MMI_JSR_C

/*  Include: MMI header file */
#if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT))

#include "ProtocolEvents.h"
#include "Conversions.h"

#include "JsrTypes.h"
#include "JsrProts.h"
#include "JMMSJSRHandler.h"
#include "JMMSGprot.h"
#include "JMMSProtocols.h"
#include "jdd_memapi.h" /* JDD memory allocation functions */
#include "JProfileHandlerTypes.h"
#include "JProfileHandlerProts.h"

#ifdef __MMI_UNIFIED_MESSAGE__
#include "JMMSUMHandling.h"
#endif 

#include "UCS2Prot.h"

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

static mmi_jsr_result_enum mmi_jsr_write_folder_status_to_file(U32 no_of_message, mmi_jsr_message_info_struct *list);
static void mmi_jsr_read_object_list_from_file(void);
static MMI_BOOL mmi_jsr_write_object_list_to_file(void);
static MMI_BOOL mmi_jsr_insert_appid_info_to_list(
                    mmi_jsr_appid_msgid_list **appid_object_list,
                    S8 *string,
                    mmi_jsr_msg_info *msg_list);
static MMI_BOOL mmi_jsr_remove_appid_info_from_list(mmi_jsr_appid_msgid_list **list, S8 *app_id);
static MMI_BOOL mmi_jsr_remove_appid_info_from_list_recursive(mmi_jsr_appid_msgid_list **list);
static MMI_BOOL mmi_jsr_insert_msg_info_to_list(mmi_jsr_msg_info **msg_list, U32 msg_id, U8 ischecked);
static MMI_BOOL mmi_jsr_remove_msg_info_from_list(mmi_jsr_msg_info **list, U32 msg_id);
static MMI_BOOL mmi_jsr_remove_msg_info_from_list_recursive(mmi_jsr_msg_info **list);
static U32 mmi_jsr_get_digit_of_integer(U32 msg_id);
static U32 mmi_jsr_get_current_size_of_object_list(
            mmi_jsr_appid_msgid_list *appid_object_list,
            U32 *max_chrs_in_line);
static void mmi_jsr_read_line_from_file(U32 filehandle, S8 *buffer, U32 buf_length, U32 *line_length, S32 *result);
static MMI_BOOL mmi_jsr_check_appId(S8 *app_id);

/*****************************************************************************
* Global Variable
*****************************************************************************/

mmi_jsr_context_struct g_jsr_cntx;
mmi_jsr_context_struct *g_mmi_jsr_cntx_p = &g_jsr_cntx;

/*****************************************************************************
* Global Function
*****************************************************************************/

extern int mmi_charset_ucs2_to_utf8_length_in_bytes(const kal_uint8 *raw);

//extern kal_int32 mmi_chset_ucs2_to_utf8_string(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src);
//extern void mmi_jmms_reset_mms_downloading_busy(void);
//extern void mmi_jmms_update_status_icon_indicator(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_clean_context
 * DESCRIPTION
 *  Clear the JSR context information.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_clean_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_jsr_cntx_p)
    {
        g_mmi_jsr_cntx_p->op = 0;
        g_mmi_jsr_cntx_p->state = 0;
        g_mmi_jsr_cntx_p->msg_id = 0;
        g_mmi_jsr_cntx_p->curr_media_obj_no = 0;
        g_mmi_jsr_cntx_p->total_media_obj_no = 0;
        g_mmi_jsr_cntx_p->retrievalMode = 0;
    }
}

/* AT COMMANDS API */


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_write_folder_status_to_file
 * DESCRIPTION
 *  Write mms folder status to information file
 * PARAMETERS
 *  no_of_msgs      [IN]        Number of messages
 *  list            [IN]        List of messages
 * RETURNS
 *  Return JSR_RESULT_OK in case of success; otherwise proper mmi_jsr_result_enum code.
 *****************************************************************************/
mmi_jsr_result_enum mmi_jsr_write_folder_status_to_file(U32 no_of_msgs, mmi_jsr_message_info_struct *list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_no = 0;
    int info_file_size = 0;
    int result = JSR_RESULT_ERROR;
    U32 bytes_written = 0;
    mmi_jsr_message_info_struct *msgInfo_p = NULL;

    /* for new phone suite */
    JDD_FSHANDLE file_handle = NULL;
    JC_CHAR *file_name_p = NULL;
    S8 buffer[20];
    JDD_FILE fh = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* for new phone suite */
    if (file_handle == NULL)
    {
        jdd_FSInitialize(&file_handle);
    }

    memset(buffer, 0, 20);

    file_name_p = jdd_MemAlloc(sizeof(S8), 100);
    if (NULL == file_name_p)
    {
        result = JSR_RESULT_INSUFFICIENT_MEMORY;
        goto END;
    }

    mmi_asc_to_ucs2((S8*) file_name_p, (S8*) (JDD_FS_MMS_SYS_FOLDER));
    mmi_asc_to_ucs2((S8*) buffer, (S8*) "\\");
    mmi_ucs2cat((S8*) file_name_p, (S8*) buffer);
    mmi_asc_to_ucs2((S8*) buffer, (S8*) (JSR_INFO));
    mmi_ucs2cat((S8*) file_name_p, (S8*) buffer);

    jdd_FSDelete(file_handle, (JC_CHAR*) file_name_p);

    if (no_of_msgs == 0)
    {
        result = JSR_RESULT_OK;
        goto END;
    }

    fh = jdd_FSOpen(file_handle, (JC_CHAR*) file_name_p, E_CREATE_WRITE_MODE);

    if (fh == NULL)
    {
        result = JSR_RESULT_FILE_OPERATION_ERROR;
        goto END;
    }

    info_file_size = no_of_msgs * sizeof(mmi_jsr_message_info_struct);
    msgInfo_p = (mmi_jsr_message_info_struct*) jdd_MemAlloc(no_of_msgs, sizeof(mmi_jsr_message_info_struct));
    if (NULL == msgInfo_p)
    {
        result = JSR_RESULT_INSUFFICIENT_MEMORY;
        goto END;
    }

    memset(msgInfo_p, 0, (no_of_msgs * sizeof(mmi_jsr_message_info_struct)));

    for (msg_no = 0; msg_no < no_of_msgs; msg_no++)
    {
        msgInfo_p[msg_no].msg_id = list[msg_no].msg_id;
        /* 180406 */
        msgInfo_p[msg_no].offset = list[msg_no].offset;
        msgInfo_p[msg_no].date = list[msg_no].date;
        msgInfo_p[msg_no].size = list[msg_no].size;
        strcpy((S8*) msgInfo_p[msg_no].filename, (S8*) list[msg_no].filename);
        /* write address and subject only when retrieval mode is JSR_FULL */
        if (g_mmi_jsr_cntx_p->retrievalMode == JSR_FULL)
        {
            strcpy((S8*) msgInfo_p[msg_no].address, (S8*) list[msg_no].address);
            strcpy((S8*) msgInfo_p[msg_no].subject, (S8*) list[msg_no].subject);
        }
    }
    bytes_written = jdd_FSWrite(msgInfo_p, 1, info_file_size, fh);
    if (bytes_written != info_file_size)
    {
        jdd_FSDelete(file_handle, (JC_CHAR*) file_name_p);
        result = JSR_RESULT_INSUFFICIENT_MEMORY;
        goto END;
    }

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d): JSR module write folder status to info.db file. \n", __FILE__,
                         __LINE__);

    result = JSR_RESULT_OK;

  END:

    if (fh != NULL)
    {
        jdd_FSClose(fh);
    }

    if (file_handle != NULL)
    {
        jdd_FSDeinitialize(file_handle);
        file_handle = NULL;
    }

    if (msgInfo_p != NULL)
    {
        jdd_MemFree(msgInfo_p);
        msgInfo_p = NULL;
    }

    if (file_name_p != NULL)
    {
        jdd_MemFree(file_name_p);
        file_name_p = NULL;
    }

    return result;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_read_folder_status_req_hldr
 * DESCRIPTION
 *  Create a WAP_MMC_READ_FOLDER_STATUS_REQ_IND primitive to L4
 * PARAMETERS
 *  msg     [IN]        Message received from L4
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_read_folder_status_req_hldr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_read_folder_status_req_ind_struct *Message;
    mmi_jsr_folder_info_struct *folder_info_p = NULL;
    mmi_jsr_message_info_struct *message_list_p = NULL;
    mmi_jsr_result_enum result = JSR_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = (wap_mmc_read_folder_status_req_ind_struct*) msg;

    PRINT_INFORMATION_2(MMI_TRACE_INFO,
                         "%s(%d):  MMI recives a wap_mmc_read_folder_status_req_ind signal, folder:%d and retrieval mode: %d. \n",
                         __FILE__, __LINE__, Message->folderId, Message->retrievalMode);
#if defined(MMS_SUPPORT)
    if (E_FALSE == jmms_is_ready())
    {
        mmi_jsr_read_folder_status_output_req_hldr(JSR_RESULT_MMS_NO_READY, NULL);
        return;
    }
#endif /* defined(MMS_SUPPORT) */ 
    if (g_mmi_jsr_cntx_p->state == JSR_STATE_IDLE)
    {
        if ((Message->folderId == JSR_INBOX)
            || (Message->folderId == JSR_OUTBOX)
            || (Message->folderId == JSR_SENT)
            || (Message->folderId == JSR_DRAFTS) || (Message->folderId == JSR_TEMPLATES))
        {
            if ((Message->retrievalMode == JSR_BASIC) || (Message->retrievalMode == JSR_FULL))
            {
                g_mmi_jsr_cntx_p->state = JSR_STATE_READ_FOLDER;
                g_mmi_jsr_cntx_p->retrievalMode = Message->retrievalMode;
                folder_info_p = (mmi_jsr_folder_info_struct*) jdd_MemAlloc(sizeof(mmi_jsr_folder_info_struct), 1);
                if (folder_info_p == NULL)
                {
                    ASSERT(0);
                }

                memset(folder_info_p, 0, sizeof(mmi_jsr_folder_info_struct));

                /* JMMS function */
                mmi_jmms_at_get_folder_info(Message->folderId, folder_info_p);
                if (folder_info_p->num_of_msg > 0)
                {
                    message_list_p =
                        (mmi_jsr_message_info_struct*) jdd_MemAlloc(
                                                        (folder_info_p->num_of_msg),
                                                        sizeof(mmi_jsr_message_info_struct));
                    if (message_list_p == NULL)
                    {
                        ASSERT(0);
                    }
                    memset(message_list_p, 0, (folder_info_p->num_of_msg) * sizeof(mmi_jsr_message_info_struct));
                }
                /* JMMS function */
                mmi_jmms_at_get_message_list(Message->folderId, message_list_p);
                result = mmi_jsr_write_folder_status_to_file((folder_info_p->num_of_msg), message_list_p);
                if (message_list_p != NULL)
                {
                    jdd_MemFree(message_list_p);
                    message_list_p = NULL;
                }
                /* This block will add the MMS root folder path 
                   and JSR info file path into folderInfo. */
                {
                    int len = 100;
                    JDD_FSHANDLE filehandle = NULL;
                    S8 *in_file_name_p = NULL;
                    S8 *out_file_name_p = NULL;
                    S8 *info_file_path = NULL;

                    /* for new phone suite */
                    if (filehandle == NULL)
                    {
                        jdd_FSInitialize(&filehandle);
                    }

                    in_file_name_p = (S8*) jdd_MemAlloc(sizeof(S8), 40);

                    mmi_asc_to_ucs2((S8*) in_file_name_p, (S8*) "@mms");
                    ASSERT(E_TRUE == jdd_FSGetAbsoluteFilePath(
                                        filehandle,
                                        (JC_CHAR*) in_file_name_p,
                                        (JC_CHAR **) & out_file_name_p));

                    if (filehandle != NULL)
                    {
                        jdd_FSDeinitialize(filehandle);
                        filehandle = NULL;
                    }

                    len = mmi_ucs2strlen((S8*) out_file_name_p) * ENCODING_LENGTH;
                    if (len <= (JSR_MMS_FILE_PATH_LENGTH))
                    {
                        memcpy(folder_info_p->mms_home_directory, out_file_name_p, len);
                    }
                    else
                    {
                        memcpy(folder_info_p->mms_home_directory, out_file_name_p, (JSR_MMS_FILE_PATH_LENGTH));
                        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d):  The path of mms home directory  is too long.\n",
                                             __FILE__, __LINE__);
                    }
                    len = 0;
                    /* for new phone suite */
                    if (filehandle == NULL)
                    {
                        jdd_FSInitialize(&filehandle);
                    }

                    if (out_file_name_p != NULL)
                    {
                        jdd_MemFree(out_file_name_p);
                        out_file_name_p = NULL;
                    }

                    memset(in_file_name_p, 0, 40);

                    mmi_asc_to_ucs2((S8*) in_file_name_p, (S8*) JDD_FS_MMS_SYS_FOLDER);
                    ASSERT(E_TRUE == jdd_FSGetAbsoluteFilePath(
                                        filehandle,
                                        (JC_CHAR*) in_file_name_p,
                                        (JC_CHAR **) & out_file_name_p));
                    info_file_path = jdd_MemAlloc(sizeof(S8), (mmi_ucs2strlen((S8*) out_file_name_p) + 9));
                    mmi_ucs2_to_asc((S8*) info_file_path, (S8*) out_file_name_p);
                    strcat(info_file_path, "\\");
                    strcat(info_file_path, JSR_INFO);

                    if (out_file_name_p != NULL)
                    {
                        jdd_MemFree(out_file_name_p);
                        out_file_name_p = NULL;
                    }

                    out_file_name_p = jdd_MemAlloc(((strlen(info_file_path) + 1) * ENCODING_LENGTH), sizeof(S8));

                    mmi_asc_to_ucs2((S8*) out_file_name_p, (S8*) (info_file_path));
                    if (filehandle != NULL)
                    {
                        jdd_FSDeinitialize(filehandle);
                        filehandle = NULL;
                    }
                    len = mmi_ucs2strlen((S8*) out_file_name_p) * ENCODING_LENGTH;
                    if (len <= (JSR_MMS_FILE_PATH_LENGTH))
                    {
                        memcpy(folder_info_p->info_file_path, out_file_name_p, len);
                    }
                    else
                    {
                        memcpy(folder_info_p->info_file_path, out_file_name_p, (JSR_MMS_FILE_PATH_LENGTH));
                        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d):  The path of info.db file is too long.\n",
                                             __FILE__, __LINE__);
                    }

                    if (in_file_name_p != NULL)
                    {
                        jdd_MemFree(in_file_name_p);
                        in_file_name_p = NULL;
                    }

                    if (info_file_path != NULL)
                    {
                        jdd_MemFree(info_file_path);
                        info_file_path = NULL;
                    }

                    if (out_file_name_p != NULL)
                    {
                        jdd_MemFree(out_file_name_p);
                        out_file_name_p = NULL;
                    }
                }

                mmi_jsr_read_folder_status_output_req_hldr(result, folder_info_p);
            }
            else
            {
                mmi_jsr_read_folder_status_output_req_hldr(JSR_RESULT_INVALID_PARAMETER, NULL);
            }
        }
        else
        {
            mmi_jsr_read_folder_status_output_req_hldr(JSR_RESULT_INVALID_PARAMETER, NULL);
        }
    }
    else
    {
        mmi_jsr_read_folder_status_output_req_hldr(JSR_RESULT_BUSY, NULL);
    }
    if (folder_info_p != NULL)
    {
        jdd_MemFree(folder_info_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_read_folder_status_output_req_hldr
 * DESCRIPTION
 *  Create a WAP_MMC_READ_FOLDER_STATUS_OUTPUT_REQ primitive to L4
 * PARAMETERS
 *  result              [IN]        
 *  folder_info_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_read_folder_status_output_req_hldr(mmi_jsr_result_enum result, mmi_jsr_folder_info_struct *folder_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_read_folder_status_output_req_struct *myMsgPtr;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_mmc_read_folder_status_output_req_struct*)
        OslConstructDataPtr(sizeof(wap_mmc_read_folder_status_output_req_struct));
    if (myMsgPtr)
    {
        memset((char*)(myMsgPtr) + 4, 0x00, (sizeof(wap_mmc_read_folder_status_output_req_struct) - 4));
        myMsgPtr->result = (U8) result;
        if (folder_info_p)
        {
            myMsgPtr->numOfMsg = folder_info_p->num_of_msg;
            myMsgPtr->numOfUnreadMsg = folder_info_p->num_of_unread_msg;

            memset(myMsgPtr->mmsHomeDirectory, 0x00, 100);
            memset(myMsgPtr->infoFilePath, 0x00, 100);

            memcpy(
                myMsgPtr->mmsHomeDirectory,
                folder_info_p->mms_home_directory,
                (mmi_ucs2strlen((char*)folder_info_p->mms_home_directory) * 2));
            memcpy(
                myMsgPtr->infoFilePath,
                folder_info_p->info_file_path,
                (mmi_ucs2strlen((char*)folder_info_p->info_file_path) * 2));
        }

        ilm_ptr = allocate_ilm(MOD_WAP);

        ilm_ptr->src_mod_id = MOD_WAP;
        ilm_ptr->sap_id = MMI_L4C_SAP;
        ilm_ptr->dest_mod_id = MOD_L4C;
        ilm_ptr->local_para_ptr = (local_para_struct*) myMsgPtr;
        ilm_ptr->msg_id = MSG_ID_WAP_MMC_READ_FOLDER_STATUS_OUTPUT_REQ;
        ilm_ptr->peer_buff_ptr = NULL;

        msg_send_ext_queue(ilm_ptr);

        if (result != JSR_RESULT_BUSY)
        {
            mmi_jsr_clean_context();
        }
        PRINT_INFORMATION_2(MMI_TRACE_INFO,
                             "%s(%d): JSR module returns wap_mmc_read_folder_status_output_req with result: %d, nMsg: %d, and nUnreadMsg: %d \n",
                             __FILE__, __LINE__, result, myMsgPtr->numOfMsg, myMsgPtr->numOfUnreadMsg);
    }
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO,
                             "%s(%d): JSR module can't get memory for wap_mmc_upload_msg_output_req_struct \n",
                             __FILE__, __LINE__);
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_upload_msg_req_hldr
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_UPLOAD_MSG_REQ_IND primitive to L4
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_upload_msg_req_hldr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_upload_msg_req_ind_struct *Message;
    int len = 0;
    char *file_name = NULL;
    mmi_jsr_result_enum result = JSR_RESULT_OK;
    U32 msg_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = (wap_mmc_upload_msg_req_ind_struct*) msg;
#if defined(MMS_SUPPORT)        /* Dilip */
    if (E_FALSE == jmms_is_ready())
    {
        mmi_jsr_upload_msg_output_req_hldr(JSR_RESULT_MMS_NO_READY, 0);
        return;
    }
#endif /* defined(MMS_SUPPORT) */ 
    /* Check the MMS folder for Max messages. */

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d):  MMI recives a wap_mmc_upload_msg_req_ind signal. \n", __FILE__,
                         __LINE__);

    if (g_mmi_jsr_cntx_p->state == JSR_STATE_IDLE)
    {
        g_mmi_jsr_cntx_p->op = JSR_OP_UPLOAD_MSG;
        g_mmi_jsr_cntx_p->state = JSR_STATE_UPLOAD_MSG;
        if (Message->filePath)
        {
            len = mmi_charset_ucs2_to_utf8_length_in_bytes(Message->filePath);
            if (len < 100)
            {
                file_name = (S8*) jdd_MemAlloc(sizeof(S8), 100);
                if (NULL == file_name)
                {
                    mmi_jsr_upload_msg_output_req_hldr(JSR_RESULT_INSUFFICIENT_MEMORY, 0);
                    return;
                }
                memset(file_name, 0, 100);
                mmi_chset_ucs2_to_utf8_string((U8*) file_name, (len + 1), (U8*) Message->filePath);
                /* JMMS function call */
                result = mmi_jmms_at_save_mms(file_name, &msg_id);
                mmi_jsr_upload_msg_output_req_hldr(result, msg_id);
                if (file_name != NULL)
                {
                    jdd_MemFree(file_name);
                    file_name = NULL;
                }
            }
            else
            {
                ASSERT(0);  /* File path too long. */
            }
        }
        else
        {
            mmi_jsr_upload_msg_output_req_hldr(JSR_RESULT_INVALID_PARAMETER, 0);
        }
    }
    else
    {
        mmi_jsr_upload_msg_output_req_hldr(JSR_RESULT_BUSY, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_upload_msg_output_req_hldr
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_UPLOAD_MSG_OUTPUT_REQ primitive to L4
 * PARAMETERS
 *  result      [IN]        
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_upload_msg_output_req_hldr(mmi_jsr_result_enum result, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_upload_msg_output_req_struct *myMsgPtr;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_mmc_upload_msg_output_req_struct*)
        OslConstructDataPtr(sizeof(wap_mmc_upload_msg_output_req_struct));
    if (myMsgPtr)
    {
        memset((char*)(myMsgPtr) + 4, 0x00, (sizeof(wap_mmc_upload_msg_output_req_struct) - 4));
        myMsgPtr->result = (U8) result;
        myMsgPtr->msgId = msg_id;

        ilm_ptr = allocate_ilm(MOD_WAP);

        ilm_ptr->src_mod_id = MOD_WAP;
        ilm_ptr->sap_id = MMI_L4C_SAP;
        ilm_ptr->dest_mod_id = MOD_L4C;
        ilm_ptr->local_para_ptr = (local_para_struct*) myMsgPtr;
        ilm_ptr->msg_id = MSG_ID_WAP_MMC_UPLOAD_MSG_OUTPUT_REQ;
        ilm_ptr->peer_buff_ptr = NULL;

        msg_send_ext_queue(ilm_ptr);

        if (result != JSR_RESULT_BUSY)
        {
            mmi_jsr_clean_context();
            if (result == JSR_RESULT_OK)
            {
                /* Refresh the MMS folder menu screen. */
                mmi_jmms_update_folder();
            }
        }
        PRINT_INFORMATION_2(MMI_TRACE_INFO,
                             "%s(%d): JSR module returns wap_mmc_upload_msg_output_req with result %d and msgid %d \n",
                             __FILE__, __LINE__, result, msg_id);
    }
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO,
                             "%s(%d): JSR module can't get memory for wap_mmc_upload_msg_output_req_struct \n",
                             __FILE__, __LINE__);
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_delete_msg_req_hldr
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_DELETE_MSG_REQ_IND primitive to L4
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_delete_msg_req_hldr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_delete_msg_req_ind_struct *Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = (wap_mmc_delete_msg_req_ind_struct*) msg;

    PRINT_INFORMATION_2(MMI_TRACE_INFO,
                         "%s(%d):  MMI recives a wap_mmc_deldete_msg_req_ind signal from l4c, msgid: %d and folderId: %d \n",
                         __FILE__, __LINE__, Message->msgId, Message->folderId);
#if defined(MMS_SUPPORT)        /* Dilip */
    if (E_FALSE == jmms_is_ready())
    {
        mmi_jsr_delete_msg_output_req_hldr(JSR_RESULT_MMS_NO_READY);
        return;
    }
#endif /* defined(MMS_SUPPORT) */ 
    if (g_mmi_jsr_cntx_p->state == JSR_STATE_IDLE)
    {
        g_mmi_jsr_cntx_p->op = JSR_OP_DELETE_MSG;
        g_mmi_jsr_cntx_p->state = JSR_STATE_DELETE_MSG;

        if (Message->folderId != 0)
        {
            if ((Message->folderId == JSR_INBOX)
                || (Message->folderId == JSR_OUTBOX)
                || (Message->folderId == JSR_SENT) || (Message->folderId == JSR_DRAFTS))
            {
                /* JMMS function call */
                mmi_jmms_at_delete_mms(Message->folderId, Message->msgId, mmi_jsr_delete_msg_output_req_hldr);
            }
            else
            {
                mmi_jsr_delete_msg_output_req_hldr(JSR_RESULT_INVALID_FOLDER);
            }
        }
        else
        {
            if (JSR_RESULT_OK == mmi_jmms_java_mms_error(mmi_jmms_is_message_found(JSR_TEMPLATES, Message->msgId)))
            {
                mmi_jsr_delete_msg_output_req_hldr(JSR_RESULT_ACCESS_DENY);
            }
            else
            {
                mmi_jmms_at_delete_mms(Message->folderId, Message->msgId, mmi_jsr_delete_msg_output_req_hldr);
            }
        }
    }
    else
    {
        mmi_jsr_delete_msg_output_req_hldr(JSR_RESULT_BUSY);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_delete_msg_output_req_hldr
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_DELETE_MSG_OUTPUT_REQ primitive to L4
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_delete_msg_output_req_hldr(mmi_jsr_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_delete_msg_output_req_struct *myMsgPtr;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_mmc_delete_msg_output_req_struct*)
        OslConstructDataPtr(sizeof(wap_mmc_delete_msg_output_req_struct));
    if (myMsgPtr)
    {
        memset((char*)(myMsgPtr) + 4, 0x00, (sizeof(wap_mmc_delete_msg_output_req_struct) - 4));
        myMsgPtr->result = (U8) result;

        ilm_ptr = allocate_ilm(MOD_WAP);

        ilm_ptr->src_mod_id = MOD_WAP;
        ilm_ptr->sap_id = MMI_L4C_SAP;
        ilm_ptr->dest_mod_id = MOD_L4C;
        ilm_ptr->local_para_ptr = (local_para_struct*) myMsgPtr;
        ilm_ptr->msg_id = MSG_ID_WAP_MMC_DELETE_MSG_OUTPUT_REQ;
        ilm_ptr->peer_buff_ptr = NULL;

        msg_send_ext_queue(ilm_ptr);

        if (result != JSR_RESULT_BUSY)
        {
            mmi_jsr_clean_context();
            if (result == JSR_RESULT_OK)
            {
                /* Refresh the MMS folder menu screen. */
                mmi_jmms_update_folder();
            }
        }
        PRINT_INFORMATION_2(MMI_TRACE_INFO,
                             "%s(%d): JSR module returns wap_mmc_delete_msg_output_req_struct with result %d \n",
                             __FILE__, __LINE__, result);
    }
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO,
                             "%s(%d): JSR module can't get memory for wap_mmc_delete_msg_output_req_struct \n",
                             __FILE__, __LINE__);
        ASSERT(0);
    }
}

/* JSR MESSAGE HANDLER API */


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_send_appmms_req_hldr
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_SEND_APPMMS_REQ primitive to Java
 * PARAMETERS
 *  msg             [IN]        
 *  mod_src         [IN]        
 *  peer_buf        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_send_appmms_req_hldr(void *msg, int mod_src, void *peer_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_send_appmms_req_struct *Message;
    U16 buffer_length = 0;
    U8 *pdu = NULL;
    peer_buff_struct *peer_ptr = peer_buf;
    mmi_jsr_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = (wap_mmc_send_appmms_req_struct*) msg;

    if (g_mmi_jsr_cntx_p->state != JSR_STATE_IDLE)
    {
        mmi_jsr_send_appmms_rsp(JSR_RESULT_BUSY);
    }
    else
    {
        mmi_jsr_clean_context();
        g_mmi_jsr_cntx_p->op = JSR_OP_SEND_MSG;
        g_mmi_jsr_cntx_p->state = JSR_STATE_PROCESS_SEND_MSG_HDR;
        g_mmi_jsr_cntx_p->total_media_obj_no = Message->bdy_part_no;
        g_mmi_jsr_cntx_p->curr_media_obj_no = 0;

        pdu = (U8*) get_pdu_ptr(peer_ptr, &buffer_length);

        /* JMMS function call */
        result = mmi_jmms_jsr_create_mms(Message, pdu);

        if (result != JSR_RESULT_OK)
        {
            result = JSR_RESULT_ERROR_FAIL_TO_GEN_MMS_HDR;
            mmi_jsr_send_appmms_rsp(result);
        }
        else
        {
            if ((g_mmi_jsr_cntx_p->curr_media_obj_no) < (g_mmi_jsr_cntx_p->total_media_obj_no))
            {
                g_mmi_jsr_cntx_p->state = JSR_STATE_PROCESS_SEND_MSG_BDY;
                mmi_jsr_send_post_appmms_msg_part_ind(JSR_RESULT_OK);
            }
            else
            {
                /* JMMS function call */
                mmi_jmms_jsr_send_mms(mmi_jsr_send_appmms_rsp);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_send_appmms_rsp
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_SEND_APPMMS_RSP primitive to Java
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_send_appmms_rsp(mmi_jsr_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_send_appmms_rsp_struct *myMsgPtr;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_mmc_send_appmms_rsp_struct*) OslConstructDataPtr(sizeof(wap_mmc_send_appmms_rsp_struct));

    myMsgPtr->result = (U8) result;

    ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->src_mod_id = MOD_WAP;
    ilm_ptr->sap_id = J2ME_WAP_SAP;
    ilm_ptr->dest_mod_id = MOD_JASYN;
    ilm_ptr->local_para_ptr = (local_para_struct*) myMsgPtr;
    ilm_ptr->msg_id = MSG_ID_WAP_MMC_SEND_APPMMS_RSP;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

    /* Clean the Jsr Context */
    mmi_jsr_clean_context();

    /* PMT HIMANSHU START 20060425 */
    mmi_jmms_reset_mms_downloading_busy();
    mmi_jmms_update_status_icon_indicator();
    /* PMT HIMANSHU END 20060425 */
    mmi_jmms_jsr_delete_temp_media_files();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_send_post_appmms_msg_part_ind
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_POST_APPMMS_MSG_PART_IND primitive to Java
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_send_post_appmms_msg_part_ind(mmi_jsr_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    wap_mmc_post_appmms_msg_part_ind_struct *myMsgPtr;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_mmc_post_appmms_msg_part_ind_struct*)
        OslConstructDataPtr(sizeof(wap_mmc_post_appmms_msg_part_ind_struct));
    myMsgPtr->result = (U8) result;

    ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->src_mod_id = MOD_WAP;
    ilm_ptr->sap_id = J2ME_WAP_SAP;
    ilm_ptr->dest_mod_id = MOD_JASYN;
    ilm_ptr->local_para_ptr = (local_para_struct*) myMsgPtr;
    ilm_ptr->msg_id = MSG_ID_WAP_MMC_POST_APPMMS_MSG_PART_IND;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_send_post_appmms_msg_part_rsp
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_POST_APPMMS_MSG_PART_RES primitive to Java
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_send_post_appmms_msg_part_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jsr_result_enum result = JSR_RESULT_OK;
    wap_mmc_post_appmms_msg_part_res_struct *Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_jsr_cntx_p->state != JSR_STATE_PROCESS_SEND_MSG_BDY)
    {
        mmi_jsr_send_appmms_rsp(JSR_RESULT_ACCESS_DENY);
        return;
    }
    Message = (wap_mmc_post_appmms_msg_part_res_struct*) msg;

    /* add media object to MMS message */
    result = mmi_jmms_jsr_add_media_object(Message);

    if (result != JSR_RESULT_OK)
    {
        mmi_jsr_send_appmms_rsp(result);
        mmi_jsr_clean_context();
        return;
    }

    /* increment current media object by 1 */
    g_mmi_jsr_cntx_p->curr_media_obj_no = g_mmi_jsr_cntx_p->curr_media_obj_no + 1;

    if ((g_mmi_jsr_cntx_p->curr_media_obj_no) < (g_mmi_jsr_cntx_p->total_media_obj_no))
    {
        g_mmi_jsr_cntx_p->state = JSR_STATE_PROCESS_SEND_MSG_BDY;
        mmi_jsr_send_post_appmms_msg_part_ind(JSR_RESULT_OK);
    }
    else
    {
        /* JMMS function call */
        mmi_jmms_jsr_send_mms(mmi_jsr_send_appmms_rsp);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_check_recv_mms_for_java
 * DESCRIPTION
 *  Check if the message is a java message and send indication to java task.
 * PARAMETERS
 *  content_type_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_jsr_check_recv_mms_for_java(S8 *content_type_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *str_pos = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_check_recv_mms_for_java Content Type ( %s )", content_type_p);
    if ((content_type_p == NULL) ||
        ((str_pos = mmi_jmms_jsr_get_application_string_from_content_type(content_type_p, JSR_APPLICATION_ID)) == NULL))
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "Normal MMS");
        return FALSE;
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "Java MMS");
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_add_recv_java_mms_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id              [IN]        
 *  content_type_p      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_jsr_add_recv_java_mms_content(U32 msg_id, S8 *content_type_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *str_pos = NULL;
    S8 *reply_str_pos = NULL;
    S8 *temp_str = NULL;
    S8 *app_id = NULL;
    U32 length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_add_recv_java_mms_content");
    if ((content_type_p == NULL) ||
        ((str_pos = mmi_jmms_jsr_get_application_string_from_content_type(content_type_p, JSR_APPLICATION_ID)) == NULL))
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "content_type_p == NULL return FALSE");
        return FALSE;
    }
    else
    {
        reply_str_pos = mmi_jmms_jsr_get_application_string_from_content_type(content_type_p, JSR_REPLY_TO_APPLICATION_ID);
        if ((reply_str_pos != NULL) && (reply_str_pos < str_pos))
        {
            str_pos = mmi_jmms_jsr_get_application_string_from_content_type(str_pos + 1, JSR_APPLICATION_ID);
            if (str_pos == NULL)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "str_pos == NULL return FALSE");
                return FALSE;
            }
        }

        temp_str = str_pos;
        str_pos = strstr(temp_str, "=");
        temp_str = str_pos + 1;
        str_pos = strstr(temp_str, ";");
        if (str_pos != NULL)
        {
            length = strlen(temp_str) - strlen(str_pos);
        }
        else
        {
            length = strlen(temp_str);
        }

        app_id = jdd_MemAlloc(sizeof(S8), (length + 1));

        memcpy(app_id, temp_str, length);

        mmi_jsr_insert_msgId_to_appId_list(msg_id, app_id, FALSE);
        if (TRUE == mmi_jsr_check_appId(app_id))
        {
            mmi_jsr_send_appmms_new_mms_ind(app_id, (U32) strlen((S8*) app_id));
        }

        jdd_MemFree(app_id);
        return TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_send_appmms_new_mms_ind
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_APPMMS_NEW_MMS_IND primitive to Java
 * PARAMETERS
 *  app_id      [IN]        
 *  length      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_send_appmms_new_mms_ind(char *app_id, U32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_appmms_new_mms_ind_struct *myMsgPtr;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_send_appmms_new_mms_ind");
    myMsgPtr = (wap_mmc_appmms_new_mms_ind_struct*) OslConstructDataPtr(sizeof(wap_mmc_appmms_new_mms_ind_struct));
    memcpy(myMsgPtr->app_id, app_id, length);
    myMsgPtr->app_id_len = length;

    ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->src_mod_id = MOD_WAP;
    ilm_ptr->sap_id = J2ME_WAP_SAP;
    ilm_ptr->dest_mod_id = MOD_JASYN;
    ilm_ptr->local_para_ptr = (local_para_struct*) myMsgPtr;
    ilm_ptr->msg_id = MSG_ID_WAP_MMC_APPMMS_NEW_MMS_IND;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_insert_msgId_to_appId_list
 * DESCRIPTION
 *  Insert the message information in application object list.
 * PARAMETERS
 *  msg_id          [IN]        
 *  app_id          [IN]        
 *  is_checked      [IN]        
 * RETURNS
 *  MMI_BOOL result
 *****************************************************************************/
MMI_BOOL mmi_jsr_insert_msgId_to_appId_list(U32 msg_id, char *app_id, BOOL is_checked)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jsr_appid_msgid_list *appid_list = NULL;
    mmi_jsr_msg_info *msg_list = NULL;
    MMI_BOOL result = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_insert_msgId_to_appId_list %d %d", msg_id, *app_id);
    if (g_mmi_jsr_cntx_p->jsr_appid_object_list == NULL)
    {
        mmi_jsr_read_object_list_from_file();
    }
    appid_list = g_mmi_jsr_cntx_p->jsr_appid_object_list;

    while (appid_list)
    {
        if ((appid_list->app_id) && (strcmp((S8*) appid_list->app_id, (S8*) app_id) == 0))
        {
            result = mmi_jsr_insert_msg_info_to_list(&(appid_list->msgs), msg_id, is_checked);
            break;
        }
        appid_list = appid_list->next;
    }
    if (appid_list == NULL)
    {
        if (mmi_jsr_insert_msg_info_to_list(&msg_list, msg_id, is_checked))
        {
            result = mmi_jsr_insert_appid_info_to_list(&appid_list, app_id, msg_list);
            g_mmi_jsr_cntx_p->jsr_appid_object_list = appid_list;
        }
    }
    if (result == TRUE)
    {
        mmi_jsr_write_object_list_to_file();
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_remove_msgId_from_appId_list
 * DESCRIPTION
 *  Delete the message information from application object list.
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  MMI_BOOL result
 *****************************************************************************/
MMI_BOOL mmi_jsr_remove_msgId_from_appId_list(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jsr_appid_msgid_list *appid_list = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_jsr_cntx_p->jsr_appid_object_list == NULL)
    {
        mmi_jsr_read_object_list_from_file();
    }
    appid_list = g_mmi_jsr_cntx_p->jsr_appid_object_list;

    while (appid_list)
    {
        if (appid_list->msgs)
        {
            mmi_jsr_msg_info *msg_list = appid_list->msgs;

            while (msg_list)
            {
                if (msg_list->msg_id == msg_id)
                {
                    mmi_jsr_remove_msg_info_from_list(&(appid_list->msgs), msg_id);
                    if (appid_list->msgs == NULL)
                    {
                        mmi_jsr_remove_appid_info_from_list(
                            &(g_mmi_jsr_cntx_p->jsr_appid_object_list),
                            appid_list->app_id);
                    }
                    mmi_jsr_write_object_list_to_file();
                    return TRUE;
                }
                msg_list = msg_list->next;
            }
        }
        appid_list = appid_list->next;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_receive_appmms_req_hldr
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_RECV_APPMMS_REQ primitive to Java
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_receive_appmms_req_hldr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_recv_appmms_req_struct *Message = NULL;
    wap_mmc_recv_appmms_rsp_struct response;
    mmi_jsr_appid_msgid_list *appid_list = NULL;
    S8 *app_id = NULL;
    U32 msg_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_receive_appmms_req_hldr");
    if (g_mmi_jsr_cntx_p->state != JSR_STATE_IDLE)
    {
        memset(&response, 0, sizeof(wap_mmc_recv_appmms_rsp_struct));
        response.result = JSR_RESULT_BUSY;
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "result == JSR_RESULT_BUSY");
        mmi_jsr_receive_appmms_rsp(&response, NULL, 0);
        return;
    }
    Message = (wap_mmc_recv_appmms_req_struct*) msg;
    *(Message->app_id + Message->app_id_len) = '\0';

    app_id = (S8*) Message->app_id;

    g_mmi_jsr_cntx_p->op = JSR_OP_RECV_MSG;
    g_mmi_jsr_cntx_p->state = JSR_STATE_RECV_MSG_HDR;

    if (app_id == NULL)
    {
        response.result = JSR_RESULT_INVALID_PARAMETER;
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "app_id == NULL");
        mmi_jsr_receive_appmms_rsp(&response, NULL, 0);
        mmi_jsr_clean_context();
        return;
    }
    else if (g_mmi_jsr_cntx_p->jsr_appid_object_list == NULL)
    {
        mmi_jsr_read_object_list_from_file();
    }

    appid_list = g_mmi_jsr_cntx_p->jsr_appid_object_list;

    while (appid_list)
    {
        if ((appid_list->app_id) && (strcmp((S8*) appid_list->app_id, (S8*) app_id) == 0))
        {
            ASSERT(appid_list->msgs);
            msg_id = appid_list->msgs->msg_id;
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "receive_appmms_req_hldr msgID(%X)", msg_id);
            if (JSR_RESULT_OK != mmi_jmms_java_mms_error(mmi_jmms_is_message_found(JSR_INBOX, msg_id)))
            {
                mmi_jsr_remove_msgId_from_appId_list(msg_id);
                response.result = JSR_RESULT_ERROR_MSG_CORRUPTED;
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JSR_RESULT_ERROR_MSG_CORRUPTED");
                mmi_jsr_receive_appmms_rsp(&response, NULL, 0);
                mmi_jsr_clean_context();
                return;
            }

            g_mmi_jsr_cntx_p->msg_id = msg_id;
            mmi_jmms_jsr_get_message_details(msg_id, mmi_jsr_receive_appmms_post_req_hldr);
            return;
        }
        appid_list = appid_list->next;
    }
    response.result = JSR_RESULT_NO_MSG_FOR_JAVA;
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JSR_RESULT_NO_MSG_FOR_JAVA");
    mmi_jsr_receive_appmms_rsp(&response, NULL, 0);
    mmi_jsr_clean_context();
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_receive_appmms_post_req_hldr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  resp            [IN]        
 *  buffer          [IN]        
 *  buffer_size     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_receive_appmms_post_req_hldr(void *resp, S8 *buffer, U16 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    wap_mmc_recv_appmms_rsp_struct *response = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_receive_appmms_post_req_hldr");
    response = (wap_mmc_recv_appmms_rsp_struct*) resp;
    /* remove the below statement..forcefully changing the value */
    /* response->result = JSR_RESULT_OK; */
    mmi_jsr_receive_appmms_rsp(response, buffer, buffer_size);

    if (response->bdy_part_no != 0)
    {
        g_mmi_jsr_cntx_p->total_media_obj_no = response->bdy_part_no;
        g_mmi_jsr_cntx_p->curr_media_obj_no = 1;
        g_mmi_jsr_cntx_p->state = JSR_STATE_RECV_MSG_BDY;
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "response->bdy_part_no != 0");
    }
    else
    {
        mmi_jsr_remove_msgId_from_appId_list(g_mmi_jsr_cntx_p->msg_id);
        mmi_jmms_jsr_delete_msg(g_mmi_jsr_cntx_p->msg_id);
        mmi_jsr_clean_context();
        mmi_jmms_update_folder();
    }

    if (response != NULL)
    {
        jdd_MemFree(response);
        response = NULL;
    }
    if (buffer != NULL)
    {
        jdd_MemFree(buffer);
        buffer = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_receive_appmms_rsp
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_RECV_APPMMS_RSP primitive to Java
 * PARAMETERS
 *  response_struct     [IN]        
 *  buffer              [IN]        
 *  buffer_size         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_receive_appmms_rsp(wap_mmc_recv_appmms_rsp_struct *response_struct, S8 *buffer, U16 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_recv_appmms_rsp_struct *myMsgPtr = NULL;
    ilm_struct *ilm_ptr = NULL;
    peer_buff_struct *peer_buff_ptr = NULL;
    U16 peer_pdu_len = 0;
    U8 *peer_pdu = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_mmc_recv_appmms_rsp_struct*) OslConstructDataPtr(sizeof(wap_mmc_recv_appmms_rsp_struct));

    memset((S8*) (myMsgPtr) + 4, 0, (sizeof(wap_mmc_recv_appmms_rsp_struct) - 4));

    myMsgPtr->result = response_struct->result;
    myMsgPtr->priority = response_struct->priority;
    myMsgPtr->date = response_struct->date;
    myMsgPtr->from_addr_no = response_struct->from_addr_no;
    myMsgPtr->to_addr_no = response_struct->to_addr_no;
    myMsgPtr->cc_addr_no = response_struct->cc_addr_no;
    myMsgPtr->bdy_part_no = response_struct->bdy_part_no;
    myMsgPtr->start_cnt_id_len = response_struct->start_cnt_id_len;
    memset(myMsgPtr->start_cnt_id, 0, 100);
    memcpy(myMsgPtr->start_cnt_id, response_struct->start_cnt_id, 100);
    myMsgPtr->reply_app_id_len = response_struct->reply_app_id_len;
    memset(myMsgPtr->reply_app_id, 0, 100);
    memcpy(myMsgPtr->reply_app_id, response_struct->reply_app_id, 100);

    if (buffer)
    {
        peer_buff_ptr = (peer_buff_struct*) construct_peer_buff(buffer_size, 0, 0, TD_CTRL);
        peer_pdu = (U8*) get_pdu_ptr(peer_buff_ptr, &peer_pdu_len);
        if (peer_pdu)
        {
            memcpy(peer_pdu, buffer, buffer_size);
        }
    }

    ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->src_mod_id = MOD_WAP;
    ilm_ptr->sap_id = J2ME_WAP_SAP;
    ilm_ptr->dest_mod_id = MOD_JASYN;
    ilm_ptr->local_para_ptr = (local_para_struct*) myMsgPtr;
    ilm_ptr->msg_id = MSG_ID_WAP_MMC_RECV_APPMMS_RSP;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buff_ptr;

    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_read_appmms_msg_part_req
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_READ_APPMMS_MSG_PART_REQ primitive to Java
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_read_appmms_msg_part_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_read_appmms_msg_part_rsp_struct response = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_read_appmms_msg_part_req");
    if (g_mmi_jsr_cntx_p->state != JSR_STATE_RECV_MSG_BDY)
    {
        memset(&response, 0, sizeof(wap_mmc_read_appmms_msg_part_rsp_struct));
        response.result = JSR_RESULT_ACCESS_DENY;
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JSR_RESULT_ACCESS_DENY");
        mmi_jsr_read_appmms_msg_part_rsp(&response);
    }
    else
    {
        if (mmi_jmms_jsr_generate_recv_msg_body_part(
                g_mmi_jsr_cntx_p->msg_id,
                &(g_mmi_jsr_cntx_p->curr_media_obj_no),
                (g_mmi_jsr_cntx_p->total_media_obj_no),
                &response))
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_jsr_generate_recv_msg_body_part");
            mmi_jsr_read_appmms_msg_part_rsp(&response);
            g_mmi_jsr_cntx_p->curr_media_obj_no = g_mmi_jsr_cntx_p->curr_media_obj_no + 1;
            if (g_mmi_jsr_cntx_p->curr_media_obj_no > g_mmi_jsr_cntx_p->total_media_obj_no)
            {
                mmi_jsr_remove_msgId_from_appId_list(g_mmi_jsr_cntx_p->msg_id);
                mmi_jmms_jsr_delete_msg(g_mmi_jsr_cntx_p->msg_id);
                mmi_jsr_clean_context();
                mmi_jmms_update_folder();
            }
        }
        else
        {
            memset(&response, 0, sizeof(wap_mmc_read_appmms_msg_part_rsp_struct));
            response.result = JSR_RESULT_INSUFFICIENT_PERSISTENT_STORAGE;
            mmi_jsr_read_appmms_msg_part_rsp(&response);
            mmi_jsr_clean_context();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_read_appmms_msg_part_rsp
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_READ_APPMMS_MSG_PART_RSP primitive to Java
 * PARAMETERS
 *  response        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_read_appmms_msg_part_rsp(wap_mmc_read_appmms_msg_part_rsp_struct *response)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_read_appmms_msg_part_rsp_struct *myMsgPtr;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_read_appmms_msg_part_rsp");
    myMsgPtr = (wap_mmc_read_appmms_msg_part_rsp_struct*)
        OslConstructDataPtr(sizeof(wap_mmc_read_appmms_msg_part_rsp_struct));
    myMsgPtr->result = response->result;
    myMsgPtr->encoding_scheme = response->encoding_scheme;
    /* Content-Type */
    myMsgPtr->content_type_value = response->content_type_value;
    myMsgPtr->content_type_len = response->content_type_len;
    memcpy(myMsgPtr->content_type, response->content_type, 100);
    /* Content-Id */
    myMsgPtr->content_id_len = response->content_id_len;
    memcpy(myMsgPtr->content_id, response->content_id, 100);
    /* Content-Location */
    myMsgPtr->content_location_len = response->content_location_len;
    memcpy(myMsgPtr->content_location, response->content_location, 100);
    /* Media object filepath */
    myMsgPtr->filepath_len = response->filepath_len;
    memcpy(myMsgPtr->filepath, response->filepath, 200);

    ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->src_mod_id = MOD_WAP;
    ilm_ptr->sap_id = J2ME_WAP_SAP;
    ilm_ptr->dest_mod_id = MOD_JASYN;
    ilm_ptr->local_para_ptr = (local_para_struct*) myMsgPtr;
    ilm_ptr->msg_id = MSG_ID_WAP_MMC_READ_APPMMS_MSG_PART_RSP;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_cfg_appmms_appid_req
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_CFG_APPMMS_APPID_REQ primitive to Java
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_cfg_appmms_appid_req(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_cfg_appmms_appid_req_struct *Message;
    mmi_jsr_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_cfg_appmms_appid_req");
    Message = (wap_mmc_cfg_appmms_appid_req_struct*) msg;
    result = mmi_jsr_cfg_app_id(Message->app_id, Message->app_id_len, Message->op);
    mmi_jsr_cfg_appmms_appid_rsp(result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_cfg_appmms_appid_rsp
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_CFG_APPMMS_APPID_RSP primitive to Java
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_cfg_appmms_appid_rsp(mmi_jsr_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_cfg_appmms_appid_rsp_struct *myMsgPtr;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_cfg_appmms_appid_rsp");
    myMsgPtr = (wap_mmc_cfg_appmms_appid_rsp_struct*) OslConstructDataPtr(sizeof(wap_mmc_cfg_appmms_appid_rsp_struct));
    myMsgPtr->result = (U8) result;

    ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->src_mod_id = MOD_WAP;
    ilm_ptr->sap_id = J2ME_WAP_SAP;
    ilm_ptr->dest_mod_id = MOD_JASYN;
    ilm_ptr->local_para_ptr = (local_para_struct*) myMsgPtr;
    ilm_ptr->msg_id = MSG_ID_WAP_MMC_CFG_APPMMS_APPID_RSP;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_cfg_app_id
 * DESCRIPTION
 *  Register/Deregister the Java application
 * PARAMETERS
 *  app_id              [IN]        
 *  app_id_length       [IN]        
 *  is_remove           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_jsr_result_enum mmi_jsr_cfg_app_id(U8 *app_id, U8 app_id_length, U8 is_remove)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 app_number = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((app_id == NULL) || (app_id_length == 0))
    {
        return JSR_RESULT_INVALID_PARAMETER;
    }
    if (is_remove == TRUE)
    {
        for (app_number = 0; app_number < JSR_MAX_APP_ID_NUM; app_number++)
        {
            if ((g_mmi_jsr_cntx_p->jsr_appid_db[app_number])
                && (g_mmi_jsr_cntx_p->jsr_appid_db[app_number]->app_id) &&
                (strcmp((S8*) g_mmi_jsr_cntx_p->jsr_appid_db[app_number]->app_id, (S8*) app_id) == 0))
            {
                jdd_MemFree(g_mmi_jsr_cntx_p->jsr_appid_db[app_number]->app_id);
                jdd_MemFree(g_mmi_jsr_cntx_p->jsr_appid_db[app_number]);
                g_mmi_jsr_cntx_p->jsr_appid_db[app_number] = NULL;
                return JSR_RESULT_OK;
            }
        }
        return JSR_RESULT_ERROR_APPID_NOT_FOUND;
    }
    else
    {
        S32 empty_slot = -1;

        for (app_number = 0; app_number < JSR_MAX_APP_ID_NUM; app_number++)
        {
            if (g_mmi_jsr_cntx_p->jsr_appid_db[app_number] == NULL)
            {
                empty_slot = app_number;
                break;
            }
            else
            {
                if ((g_mmi_jsr_cntx_p->jsr_appid_db[app_number]->app_id) &&
                    (strcmp((S8*) g_mmi_jsr_cntx_p->jsr_appid_db[app_number]->app_id, (S8*) app_id) == 0))
                {
                    return JSR_RESULT_ERROR_APPID_EXIST;
                }
            }
        }
        if (empty_slot < 0)
        {
            return JSR_RESULT_ERROR_APPID_FULL;
        }
        else
        {
            g_mmi_jsr_cntx_p->jsr_appid_db[app_number] =
                (mmi_jsr_appid_info_struct*) jdd_MemAlloc(1, sizeof(mmi_jsr_appid_info_struct));
            g_mmi_jsr_cntx_p->jsr_appid_db[app_number]->app_id = (S8*) jdd_MemAlloc(1, app_id_length + 1);
            memcpy(g_mmi_jsr_cntx_p->jsr_appid_db[app_number]->app_id, app_id, app_id_length);
            return JSR_RESULT_OK;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_check_appmms_coming_req
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_CHECK_APPMMS_COMING_REQ primitive to Java
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_check_appmms_coming_req(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_check_appmms_coming_req_struct *Message;
    MMI_BOOL result = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_check_appmms_coming_req");
    Message = (wap_mmc_check_appmms_coming_req_struct*) msg;
    result = mmi_jsr_check_appid_msgs(Message->app_id, Message->app_id_len, (U8) Message->only_new);
    mmi_jsr_check_appmms_coming_rsp(result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_check_appmms_coming_rsp
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_CHECK_APPMMS_COMING_RSP primitive to Java
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_check_appmms_coming_rsp(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_check_appmms_coming_rsp_struct *myMsgPtr;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_check_appmms_coming_rsp");
    myMsgPtr = (wap_mmc_check_appmms_coming_rsp_struct*)
        OslConstructDataPtr(sizeof(wap_mmc_check_appmms_coming_rsp_struct));
    myMsgPtr->result = (result) ? (1) : (0);

    ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->src_mod_id = MOD_WAP;
    ilm_ptr->sap_id = J2ME_WAP_SAP;
    ilm_ptr->dest_mod_id = MOD_JASYN;
    ilm_ptr->local_para_ptr = (local_para_struct*) myMsgPtr;
    ilm_ptr->msg_id = MSG_ID_WAP_MMC_CHECK_APPMMS_COMING_RSP;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_check_appid_msgs
 * DESCRIPTION
 *  Checks the application object list for specific application
 * PARAMETERS
 *  app_id              [IN]        
 *  app_id_length       [IN]        
 *  is_new              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_jsr_check_appid_msgs(U8 *app_id, U8 app_id_length, U8 is_new)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_check_appid_msgs");
    if (g_mmi_jsr_cntx_p->jsr_appid_object_list == NULL)
    {
        mmi_jsr_read_object_list_from_file();
    }
    if (g_mmi_jsr_cntx_p->jsr_appid_object_list)
    {
        mmi_jsr_appid_msgid_list *appid_list = g_mmi_jsr_cntx_p->jsr_appid_object_list;

        while (appid_list)
        {
            if ((appid_list->app_id) && (strcmp((S8*) appid_list->app_id, (S8*) app_id) == 0))
            {
                mmi_jsr_msg_info *msg_list = appid_list->msgs;

                while (msg_list)
                {
                    if (msg_list->is_checked == FALSE)
                    {
                        msg_list->is_checked = TRUE;
                        return (mmi_jsr_write_object_list_to_file());
                    }
                    else
                    {
                        if (is_new == FALSE)
                        {
                            PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_check_appid_msgs is_new == FALSE");
                            return TRUE;
                        }
                    }
                    msg_list = msg_list->next;
                }
                return FALSE;
            }
            appid_list = appid_list->next;
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_abort_appmms_req
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_ABORT_APPMMS_REQ primitive to Java
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_abort_appmms_req(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *file_name_p = NULL;
    U32 file_path_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_abort_appmms_req");
    if ((g_mmi_jsr_cntx_p->op != JSR_OP_SEND_MSG) && (g_mmi_jsr_cntx_p->op != JSR_OP_RECV_MSG))
    {
        mmi_jsr_abort_appmms_rsp(JSR_RESULT_ACCESS_DENY);
    }
    else
    {
        if (g_mmi_jsr_cntx_p->op == JSR_OP_SEND_MSG)
        {
            if ((g_mmi_jsr_cntx_p->state == JSR_STATE_PROCESS_SEND_MSG_HDR)
                || (g_mmi_jsr_cntx_p->state == JSR_STATE_PROCESS_SEND_MSG_BDY))
            {
                file_path_len = (strlen((S8*) (JSR_MEDIA_OBJECT_FILE)) + 1) * ENCODING_LENGTH;
                file_name_p = jdd_MemAlloc(sizeof(S8), file_path_len);
                mmi_asc_to_ucs2((S8*) file_name_p, (S8*) (JSR_MEDIA_OBJECT_FILE));
                mmi_jsr_abort_appmms_rsp(JSR_RESULT_OK);
                /* JMMS function call */
                FS_Delete((U16*) file_name_p);
                mmi_jsr_clean_context();
            }
            else
            {
                /* JMMS function call */
                mmi_jmms_jsr_cancel_send_mms(g_mmi_jsr_cntx_p->msg_id, mmi_jsr_abort_appmms_rsp);
            }
        }
        else
        {
            file_path_len = (strlen((S8*) (JSR_MEDIA_OBJECT_FILE)) + 1) * ENCODING_LENGTH;
            file_name_p = jdd_MemAlloc(sizeof(S8), file_path_len);
            mmi_asc_to_ucs2((S8*) file_name_p, (S8*) (JSR_MEDIA_OBJECT_FILE));
            /* Aborting receiving of Java MMS by Java app. */
            mmi_jsr_abort_appmms_rsp(JSR_RESULT_OK);
            FS_Delete((U16*) file_name_p);
            mmi_jsr_clean_context();
        }
        if (file_name_p != NULL)
        {
            jdd_MemFree(file_name_p);
            file_name_p = NULL;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_abort_appmms_rsp
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_ABORT_APPMMS_RSP primitive to Java
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_abort_appmms_rsp(mmi_jsr_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_abort_appmms_rsp_struct *myMsgPtr;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_abort_appmms_rsp");
    myMsgPtr = (wap_mmc_abort_appmms_rsp_struct*) OslConstructDataPtr(sizeof(wap_mmc_abort_appmms_rsp_struct));
    myMsgPtr->result = (U8) result;

    ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->src_mod_id = MOD_WAP;
    ilm_ptr->sap_id = J2ME_WAP_SAP;
    ilm_ptr->dest_mod_id = MOD_JASYN;
    ilm_ptr->local_para_ptr = (local_para_struct*) myMsgPtr;
    ilm_ptr->msg_id = MSG_ID_WAP_MMC_ABORT_APPMMS_RSP;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);
}

/* JAVA PROFILE SETTINGS API */


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_get_mms_profile_req
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_GET_MMS_PROF_REQ primitive to Java
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_get_mms_profile_req(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_get_mms_prof_req_struct *Message;
    U8 result = 2;  /* invalid prof id. */
    U8 value_length = 0;
    U8 *value = NULL;
    U8 *temp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_get_mms_profile_req");
    Message = (wap_mmc_get_mms_prof_req_struct*) msg;

    switch (Message->access_id)
    {
        case JSR_WAP_MMS_PROF_MMSC_ADDRESS:
        {
            /* U8 mms_profile_id; */
            value = (U8*) jdd_MemAlloc(1, 256);
        #if defined(MMS_SUPPORT)        /* dilip */
            temp = mmi_ph_mms_get_activated_profile_mmsc_url();
            if (NULL == temp)
            {
                result = 1; /* MMS not ready yet. */
                break;
            }
        #endif /* defined(MMS_SUPPORT) */ 
            value_length = strlen((S8*) temp) + 1;
            if (value_length > 256)
            {
                ASSERT(0);  /* memory corruption */
            }
            memcpy(value, temp, value_length);
            result = 0;
            break;
        }
    }

    mmi_jsr_get_mms_profile_rsp(result, value, value_length);

    if (NULL != value)
    {
        jdd_MemFree(value);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_get_mms_profile_rsp
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_GET_MMS_PROF_RSP primitive to Java
 * PARAMETERS
 *  result              [IN]        
 *  value               [IN]        
 *  value_length        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_get_mms_profile_rsp(U8 result, U8 *value, U8 value_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_get_mms_prof_rsp_struct *myMsgPtr = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_get_mms_profile_rsp");
    myMsgPtr = (wap_mmc_get_mms_prof_rsp_struct*) OslConstructDataPtr(sizeof(wap_mmc_get_mms_prof_rsp_struct));
    myMsgPtr->result = result;
    myMsgPtr->value_len = value_length;
    if (value_length > 0 && value != NULL)
    {
        memcpy(myMsgPtr->value, value, value_length);
    }

    ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->src_mod_id = MOD_WAP;
    ilm_ptr->sap_id = J2ME_MMI_SAP;
    ilm_ptr->dest_mod_id = MOD_J2ME;
    ilm_ptr->local_para_ptr = (local_para_struct*) myMsgPtr;
    ilm_ptr->msg_id = MSG_ID_WAP_MMC_GET_MMS_PROF_RSP;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);
}

/* JSR INTERNAL APIs */


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_read_object_list_from_file
 * DESCRIPTION
 *  Read the application object list information from a file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_read_object_list_from_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 file_name[100];
    int filehandle = -1;
    S8 *buffer;
    U32 buf_size = 512;
    U32 line_length;
    S32 result = 0;
    MMI_BOOL update_file = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_read_object_list_from_file");
    mmi_asc_to_ucs2((S8*) file_name, (S8*) (JSR_APPID_LIST_FILE));
    filehandle = FS_Open((U16*) (file_name), FS_READ_ONLY);
    if (filehandle < 0)
    {
        return;
    }

    buffer = (S8*) jdd_MemAlloc(1, buf_size);

    while (1)
    {
        S8 *appid_string = NULL;
        mmi_jsr_msg_info *msg_list = NULL;
        U32 step = 1;

        for (step = 1; step < 4; step++)
        {
            mmi_jsr_read_line_from_file(filehandle, buffer, buf_size, &line_length, &result);
            if ((result == 0) && (line_length == 0))
            {
                FS_Close(filehandle);
                jdd_MemFree(buffer);
                if (update_file == TRUE)
                {
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_read_object_list_from_file update_file == TRUE");
                    mmi_jsr_write_object_list_to_file();
                }
                return;
            }
            else if (result < 0)
            {
                FS_Close(filehandle);
                jdd_MemFree(buffer);
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_read_object_list_from_file result < 0");
                /* File format corrupted, so remove all the appid info. */
                mmi_jsr_remove_appid_info_from_list_recursive(&(g_mmi_jsr_cntx_p->jsr_appid_object_list));
                return;
            }
            ASSERT(line_length > 2);
            /* replace '\r''\n' with '\0''\0' */
            *(buffer + line_length - 1) = '\0';
            *(buffer + line_length - 2) = '\0';

            /* Read appid from file */
            if (step == 1)
            {
                appid_string = (S8*) jdd_MemAlloc(1, (strlen((char*)buffer) + 1));
                ASSERT(appid_string);
                strcpy((S8*) appid_string, (S8*) buffer);
            }
            /* Read msgid and isChecked string */
            else if (step == 2)
            {
                S8 *text = buffer;
                S8 *colon = NULL;
                S8 *next_token = NULL;
                U32 msg_id;
                U8 isChecked;

                while (text)
                {
                    next_token = (S8*) strchr((char*)text, ',');
                    if (next_token != NULL)
                    {
                        *(next_token++) = '\0';
                    }
                    colon = (S8*) strchr((char*)text, ':');
                    ASSERT(colon);
                    *(colon++) = '\0';
                    msg_id = atoi((char*)text);
                    isChecked = atoi((char*)colon);
                    if (mmi_jmms_check_msg_id(msg_id) == TRUE)
                    {
                        PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_check_msg_id(msg_id) returns TRUE");
                        mmi_jsr_insert_msg_info_to_list(&msg_list, msg_id, isChecked);
                    }
                    else
                    {
                        update_file = TRUE;
                    }
                    text = next_token;
                }
            }
            /* '\r' and '\n' */
            else if (step == 3)
            {
                if (msg_list != NULL)
                {
                    mmi_jsr_insert_appid_info_to_list(
                        &(g_mmi_jsr_cntx_p->jsr_appid_object_list),
                        appid_string,
                        msg_list);
                }
                else
                {
                    if (appid_string)
                    {
                        jdd_MemFree(appid_string);
                    }
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_write_object_list_to_file
 * DESCRIPTION
 *  Write the application object list information to file.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL result
 *****************************************************************************/
MMI_BOOL mmi_jsr_write_object_list_to_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 file_name[100];
    S8 orig_file[100];
    S8 *buffer = NULL;
    U32 buf_size = 0;
    U32 filesize = 0;
    U32 datalen = 0;
    int filehandle = -1;
    U32 written = 0;
    S32 result = -1;
    mmi_jsr_appid_msgid_list *appid_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_write_object_list_to_file");
    if (g_mmi_jsr_cntx_p->jsr_appid_object_list == NULL)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_write_object_list_to_file appid_object_list is NULL");
        return FALSE;
    }

    filesize = mmi_jsr_get_current_size_of_object_list(g_mmi_jsr_cntx_p->jsr_appid_object_list, &buf_size);
    ASSERT(filesize);

    mmi_asc_to_ucs2((S8*) orig_file, (S8*) (JSR_APPID_LIST_FILE));
    mmi_asc_to_ucs2((S8*) file_name, (S8*) (JSR_APPID_LIST_FILE_TMP));
    FS_Delete((U16*) file_name);
    filehandle = FS_Open((U16*) file_name, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (filehandle < 0)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_write_object_list_to_file File Open Failed");
        return FALSE;
    }

    buffer = (S8*) jdd_MemAlloc(sizeof(S8), buf_size + 1);
    ASSERT(buffer);
    appid_list = g_mmi_jsr_cntx_p->jsr_appid_object_list;
    while (appid_list)
    {
        ASSERT(appid_list->app_id);
        {
            datalen = 0;
            sprintf((char*)buffer, "%s\r\n", appid_list->app_id);
            datalen = strlen((char*)appid_list->app_id) + 2;
            result = FS_Write(filehandle, buffer, datalen, &written);
            if (result < 0)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_write_object_list_to_file File Write Failed");
                FS_Close(filehandle);
                jdd_MemFree(buffer);
                return FALSE;
            }
        }
        ASSERT(appid_list->msgs);
        {
            mmi_jsr_msg_info *msg_list = appid_list->msgs;

            datalen = 0;
            while (msg_list)
            {
                sprintf((char*)(buffer + datalen), "%d:%1d", msg_list->msg_id, msg_list->is_checked);
                datalen += mmi_jsr_get_digit_of_integer(msg_list->msg_id) + 2;
                if (msg_list->next)
                {
                    sprintf((char*)(buffer + datalen), ",");
                    datalen += 1;
                }
                msg_list = msg_list->next;
            }
            sprintf((char*)(buffer + datalen), "\r\n*\r\n");
            datalen += 5;
            ASSERT(buf_size >= datalen);
            result = FS_Write(filehandle, buffer, datalen, &written);
            if (result < 0)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_write_object_list_to_file File Open Failed 2");
                FS_Close(filehandle);
                jdd_MemFree(buffer);
                return FALSE;
            }
        }
        appid_list = appid_list->next;
    }
    FS_Close(filehandle);
    jdd_MemFree(buffer);
    FS_Delete((U16*) orig_file);
    FS_Rename((U16*) file_name, (U16*) orig_file);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_write_object_list_to_filereturns TRUE");
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_insert_appid_info_to_list
 * DESCRIPTION
 *  Insert the application info to application object list.
 * PARAMETERS
 *  appid_object_list       [IN/OUT]        
 *  string                  [IN]            
 *  msg_list                [IN]            
 * RETURNS
 *  MMI_BOOL result
 *****************************************************************************/
MMI_BOOL mmi_jsr_insert_appid_info_to_list(
            mmi_jsr_appid_msgid_list **appid_object_list,
            S8 *string,
            mmi_jsr_msg_info *msg_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jsr_appid_msgid_list *node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_insert_appid_info_to_list");
    if (appid_object_list == NULL)
    {
        return FALSE;
    }
    node = (mmi_jsr_appid_msgid_list*) jdd_MemAlloc(1, sizeof(mmi_jsr_appid_msgid_list));
    ASSERT(node);
    node->app_id = (S8*) jdd_MemAlloc(1, (strlen((S8*) string) + 1));
    ASSERT(node->app_id);
    strcpy((S8*) node->app_id, (S8*) string);
    node->msgs = msg_list;
    if (*appid_object_list == NULL)
    {
        node->prev = node;
        *appid_object_list = node;
        return TRUE;
    }
    else
    {
        mmi_jsr_appid_msgid_list *tempnode = *appid_object_list;

        while (tempnode->next)
        {
            tempnode = tempnode->next;
        }
        tempnode->next = node;
        node->prev = tempnode;
        return TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_remove_appid_info_from_list
 * DESCRIPTION
 *  Remove the application info from application object list.
 * PARAMETERS
 *  list        [IN/OUT]        
 *  app_id      [IN]            
 * RETURNS
 *  MMI_BOOL result
 *****************************************************************************/
MMI_BOOL mmi_jsr_remove_appid_info_from_list(mmi_jsr_appid_msgid_list **list, S8 *app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jsr_appid_msgid_list *appid_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((list == NULL) || (*(list) == NULL))
    {
        return FALSE;
    }

    appid_list = *list;
    while (appid_list)
    {
        if ((appid_list->app_id) && (app_id) && (strcmp((S8*) appid_list->app_id, (S8*) app_id) == 0))
        {
            if (appid_list == *list)
            {
                *list = appid_list->next;
                if (appid_list->next)
                {
                    appid_list->next->prev = appid_list->next;
                }
            }
            else
            {
                appid_list->prev->next = appid_list->next;
                if (appid_list->next)
                {
                    appid_list->next->prev = appid_list->prev;
                }
            }
            jdd_MemFree(appid_list->app_id);
            mmi_jsr_remove_msg_info_from_list_recursive(&(appid_list->msgs));
            jdd_MemFree(appid_list);
            return TRUE;
        }
        appid_list = appid_list->next;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_remove_appid_info_from_list_recursive
 * DESCRIPTION
 *  Remove the appid info of all the messages in the application object list.
 * PARAMETERS
 *  list        [IN]        
 * RETURNS
 *  MMI_BOOL result
 *****************************************************************************/
MMI_BOOL mmi_jsr_remove_appid_info_from_list_recursive(mmi_jsr_appid_msgid_list **list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jsr_appid_msgid_list *appid_list;
    mmi_jsr_appid_msgid_list *appid_list_temp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_remove_appid_info_from_list_recursive");
    if ((list == NULL) || (*list == NULL))
    {
        return FALSE;
    }

    appid_list = *list;
    while (appid_list)
    {
        appid_list_temp = appid_list->next;
        jdd_MemFree(appid_list->app_id);
        mmi_jsr_remove_msg_info_from_list_recursive(&(appid_list->msgs));
        jdd_MemFree(appid_list);
        appid_list = appid_list_temp;
    }
    *list = NULL;
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_insert_msg_info_to_list
 * DESCRIPTION
 *  Insert the message info to application object list.
 * PARAMETERS
 *  msg_list        [IN]        
 *  msg_id          [IN]        
 *  ischecked       [IN]        
 * RETURNS
 *  MMI_BOOL result
 *****************************************************************************/
MMI_BOOL mmi_jsr_insert_msg_info_to_list(mmi_jsr_msg_info **msg_list, U32 msg_id, U8 ischecked)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jsr_msg_info *node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_insert_msg_info_to_list %d", msg_id);
    if (msg_list == NULL)
    {
        return FALSE;
    }
    node = (mmi_jsr_msg_info*) jdd_MemAlloc(1, sizeof(mmi_jsr_msg_info));
    ASSERT(node);
    node->msg_id = msg_id;
    node->is_checked = ischecked;
    if (*msg_list == NULL)
    {
        node->prev = node;
        *msg_list = node;
        return TRUE;
    }
    else
    {
        mmi_jsr_msg_info *tempnode = *msg_list;

        while (tempnode->next)
        {
            tempnode = tempnode->next;
        }
        tempnode->next = node;
        node->prev = tempnode;
        return TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_remove_msg_info_from_list
 * DESCRIPTION
 *  Remove the message info from application object list.
 * PARAMETERS
 *  list        [IN]        
 *  msg_id      [IN]        
 * RETURNS
 *  MMI_BOOL result
 *****************************************************************************/
MMI_BOOL mmi_jsr_remove_msg_info_from_list(mmi_jsr_msg_info **list, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jsr_msg_info *msg_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_remove_msg_info_from_list %d", msg_id);
    if ((list == NULL) || (*(list) == NULL))
    {
        return FALSE;
    }

    msg_list = *list;

    while (msg_list)
    {
        if (msg_list->msg_id == msg_id)
        {
            if (msg_list == *list)
            {
                *list = msg_list->next;
                if (msg_list->next)
                {
                    msg_list->next->prev = msg_list->next;
                }
            }
            else
            {
                msg_list->prev->next = msg_list->next;
                if (msg_list->next)
                {
                    msg_list->next->prev = msg_list->prev;
                }
            }
            jdd_MemFree(msg_list);
            return TRUE;
        }
        msg_list = msg_list->next;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_remove_msg_info_from_list_recursive
 * DESCRIPTION
 *  Remove the message info of all the messages in the message list.
 * PARAMETERS
 *  list        [IN]        
 * RETURNS
 *  MMI_BOOL result
 *****************************************************************************/
MMI_BOOL mmi_jsr_remove_msg_info_from_list_recursive(mmi_jsr_msg_info **list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jsr_msg_info *msg_list;
    mmi_jsr_msg_info *msg_list_temp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_remove_msg_info_from_list_recursive");
    if ((list == NULL) || (*(list) == NULL))
    {
        return FALSE;
    }

    msg_list = *list;
    while (msg_list)
    {
        msg_list_temp = msg_list->next;
        jdd_MemFree(msg_list);
        msg_list = msg_list_temp;
    }
    *list = NULL;
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_get_digit_of_integer
 * DESCRIPTION
 *  Calculates the number of digits in an integer.
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  U32 length
 *****************************************************************************/
U32 mmi_jsr_get_digit_of_integer(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buffer[11];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((S8*) buffer, "%d", msg_id);
    return strlen((S8*) buffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_get_current_size_of_object_list
 * DESCRIPTION
 *  Calculates the current size of application object list.
 * PARAMETERS
 *  appid_object_list       [IN]        
 *  max_chrs_in_line        [OUT]       
 * RETURNS
 *  U32 size
 *****************************************************************************/
U32 mmi_jsr_get_current_size_of_object_list(mmi_jsr_appid_msgid_list *appid_object_list, U32 *max_chrs_in_line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 sum = 0;
    U32 chrs = 0;
    U32 max_chrs = 0;
    mmi_jsr_appid_msgid_list *appid_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_get_current_size_of_object_list");
    *(max_chrs_in_line) = 0;

    if (appid_object_list == NULL)
    {
        return 0;
    }

    appid_list = appid_object_list;

    while (appid_list)
    {
        if (appid_list->app_id)
        {
            chrs = strlen((S8*) appid_list->app_id) + 2;    /* appid string+\r\n */
            sum += chrs;
            if (chrs > max_chrs)
            {
                max_chrs = chrs;
            }
        }
        chrs = 0;
        if (appid_list->msgs)
        {
            mmi_jsr_msg_info *msg_list = appid_list->msgs;

            while (msg_list)
            {
                /* msgid:isChecked */
                chrs += (mmi_jsr_get_digit_of_integer(msg_list->msg_id) + 2);
                if (msg_list->next)
                {
                    chrs += 1;
                }
                msg_list = msg_list->next;
            }
            chrs += 5;  /* \r\n*\r\n */
            sum += chrs;
            if (chrs > max_chrs)
            {
                max_chrs = chrs;
            }
        }
        appid_list = appid_list->next;
    }

    *max_chrs_in_line = max_chrs;
    return sum;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_read_line_from_file
 * DESCRIPTION
 *  Reads a line from a file and store it in buffer.
 * PARAMETERS
 *  filehandle      [IN]        
 *  buffer          [IN]        
 *  buf_length      [IN]        
 *  line_length     [OUT]       
 *  result          [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_read_line_from_file(U32 filehandle, S8 *buffer, U32 buf_length, U32 *line_length, S32 *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *pos = buffer;
    U32 rd_no = 0;
    U32 count = 0;
    MMI_BOOL CR = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_read_line_from_file");
    memset(buffer, 0, buf_length);
    *line_length = 0;

    while (buf_length)
    {
        *result = FS_Read(filehandle, pos, 1, &rd_no);
        if (*result < 0)
        {
            *line_length = count;
            return;
        }
        else if (rd_no != 1)
        {
            *line_length = count;
            return;
        }
        else
        {
            count++;
            if (*pos == '\r')
            {
                CR = TRUE;
            }
            else if (*pos == '\n')
            {
                if (CR == TRUE)
                {
                    *line_length = count;
                    return;
                }
                else
                {
                    CR = FALSE;
                }
            }
            else
            {
                CR = FALSE;
            }
        }
        buf_length--;
        pos++;
    }
    *result = -1;
    *line_length = rd_no;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_check_appId
 * DESCRIPTION
 *  Checks whether the application is registered or not.
 * PARAMETERS
 *  app_id      [IN]        
 * RETURNS
 *  MMI_BOOL result
 *****************************************************************************/
MMI_BOOL mmi_jsr_check_appId(S8 *app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_check_appId");
    for (i = 0; i < JSR_MAX_APP_ID_NUM; i++)
    {
        if (g_mmi_jsr_cntx_p->jsr_appid_db[i] && g_mmi_jsr_cntx_p->jsr_appid_db[i]->app_id &&
            (strcmp((S8*) g_mmi_jsr_cntx_p->jsr_appid_db[i]->app_id, (S8*) app_id) == 0))
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_check_appId returns TRUE");
            return TRUE;
        }
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_check_appId returns FALSE");
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_is_java_msg
 * DESCRIPTION
 *  Checks whether the message is a Java message or not.
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  MMI_BOOL result
 *****************************************************************************/
MMI_BOOL mmi_jsr_is_java_msg(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_is_java_msg %d", msg_id);
    if (g_mmi_jsr_cntx_p->jsr_appid_object_list == NULL)
    {
        mmi_jsr_read_object_list_from_file();
    }
    if (g_mmi_jsr_cntx_p->jsr_appid_object_list)
    {
        mmi_jsr_appid_msgid_list *appid_list = g_mmi_jsr_cntx_p->jsr_appid_object_list;

        while (appid_list)
        {
            if (appid_list->msgs)
            {
                mmi_jsr_msg_info *msg_list = appid_list->msgs;

                while (msg_list)
                {
                    if (msg_list->msg_id == msg_id)
                    {
                        PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jsr_is_java_msg found");
                        return TRUE;
                    }
                    msg_list = msg_list->next;
                }
            }
            appid_list = appid_list->next;
        }
    }
    return FALSE;
}

#endif /* (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT)) */ // #if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT))
#endif /* _MMI_JSR_C */ 


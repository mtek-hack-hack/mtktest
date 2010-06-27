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
 * MMSJSR205.c
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

#ifdef __MMI_MMS_2__
#if defined(MMS_SUPPORT)

#include "ProtocolEvents.h"

#include "MMSJsrTypes.h"
#include "MMSJsrProts.h"
#include "UnifiedMessageGProt.h"
#include "UCS2Prot.h"
#include "MMSJSRSndRcv.h"
#include "ProfileHandlerTypes.h"
#include "ProfileHandlerProts.h"
#include "MMSViewerAPPDefs.h"
#include "MMSAppGprot.h"
#include "jam_msg_handler.h"
#include "JavaAgencyGProt.h"
#include "MMSAppResDef.h"
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
static JsrResult mmi_jsr_write_folder_status_to_file(U32 no_of_message, JsrMessageInfo *list);
static MMI_BOOL mmi_jsr_write_object_list_to_file(void);
static MMI_BOOL mmi_jsr_insert_appid_info_to_list(
                    jsr_appid_msgid_list **appid_object_list,
                    S8 *string,
                    jsr_msg_info *msg_list);
static MMI_BOOL mmi_jsr_remove_appid_info_from_list(jsr_appid_msgid_list **list, S8 *appId);
static MMI_BOOL mmi_jsr_remove_appid_info_from_list_recursive(jsr_appid_msgid_list **list);
static MMI_BOOL mmi_jsr_insert_msg_info_to_list(jsr_msg_info **msg_list, U32 msgId, U8 ischecked);
static MMI_BOOL mmi_jsr_remove_msg_info_from_list(jsr_msg_info **list, U32 msgId);
static MMI_BOOL mmi_jsr_remove_msg_info_from_list_recursive(jsr_msg_info **list);
static U32 mmi_jsr_get_digit_of_integer(U32 msgId);
static U32 mmi_jsr_get_current_size_of_object_list(jsr_appid_msgid_list *appid_object_list, U32 *max_chrs_in_line);
static void mmi_jsr_read_line_from_file(U32 filehandle, S8 *buffer, U32 buf_length, U32 *line_length, S32 *ret);
static MMI_BOOL mmi_jsr_check_appId(S8 *appId);
//kal_bool wap_mms_get_home_directory(kal_wchar *buffer, kal_uint32 buffer_size);
//kal_bool wap_mms_get_message_file_name(kal_uint32 msg_id, kal_wchar *buffer, kal_uint32 buffer_size);

/*****************************************************************************
* Global Variable
*****************************************************************************/

jsr_context_struct jsr_cntx;
jsr_context_struct *jsr_cntx_p = &jsr_cntx;

jsr_appid_msgid_list *g_jsr_appid_object_list = NULL;
jsr_appid_info_struct *jsr_appid_db[JSR_MAX_APP_ID_NUM];    /* for registered apps */

/*****************************************************************************
* Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_jsr_read_folder_status_req_hldr, MSG_ID_WAP_MMC_READ_FOLDER_STATUS_REQ_IND);
    SetProtocolEventHandler(mmi_jsr_upload_msg_req_hldr, MSG_ID_WAP_MMC_UPLOAD_MSG_REQ_IND);
    SetProtocolEventHandler(mmi_jsr_delete_msg_req_hldr, MSG_ID_WAP_MMC_DELETE_MSG_REQ_IND);

    SetProtocolEventHandler((PsFuncPtr) mmi_jsr_send_appmms_req_hldr, MSG_ID_WAP_MMC_SEND_APPMMS_REQ);
    SetProtocolEventHandler(mmi_jsr_send_post_appmms_msg_part_rsp, MSG_ID_WAP_MMC_POST_APPMMS_MSG_PART_RES);
    SetProtocolEventHandler(mmi_jsr_receive_appmms_req_hldr, MSG_ID_WAP_MMC_RECV_APPMMS_REQ);
    SetProtocolEventHandler(mmi_jsr_read_appmms_msg_part_req, MSG_ID_WAP_MMC_READ_APPMMS_MSG_PART_REQ);

    SetProtocolEventHandler(mmi_jsr_cfg_appmms_appid_req, MSG_ID_WAP_MMC_CFG_APPMMS_APPID_REQ);
    SetProtocolEventHandler(mmi_jsr_check_appmms_coming_req, MSG_ID_WAP_MMC_CHECK_APPMMS_COMING_REQ);
    SetProtocolEventHandler(mmi_jsr_get_mms_profile_req, MSG_ID_WAP_MMC_GET_MMS_PROF_REQ);
    SetProtocolEventHandler(mmi_jsr_abort_appmms_req, MSG_ID_WAP_MMC_ABORT_APPMMS_REQ);

    SetProtocolEventHandler(mmi_jsr_get_active_mms_attachment_req, MSG_ID_MMS_GET_ACTIVE_MMS_ATTACHMENT_REQ);
    mmi_umms_init_jsr_folder();
}


/*****************************************************************************
 * FUNCTION
 *  JsrCleanContext
 * DESCRIPTION
 *  Clear the JSR context information.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void JsrCleanContext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (JSR_CNTX)
    {
        JSR_CNTX->op = 0;
        JSR_CNTX->state = 0;
        JSR_CNTX->msgId = 0;
        JSR_CNTX->curr_media_obj_no = 0;
        JSR_CNTX->total_media_obj_no = 0;
        JSR_CNTX->retrievalMode = 0;

        JSR_CNTX->folderId = 0xFFFF;
        JSR_CNTX->numofMsg = 0;
        JSR_CNTX->numofUnreadMsg = 0;
        JSR_CNTX->counter = 0;

        if (JSR_CNTX->msgIDList)
        {
            umms_free(JSR_CNTX->msgIDList);
            JSR_CNTX->msgIDList = NULL;
        }

        if (JSR_CNTX->msgInfolist)
        {
            umms_free(JSR_CNTX->msgInfolist);
            JSR_CNTX->msgInfolist = NULL;
        }

        JSR_CNTX->req_id = 0;

        JSR_CNTX->xml_file_size = 0;
        JSR_CNTX->buffer_index = 0;

        if (JSR_CNTX->file_handle)
        {
            FS_Close(JSR_CNTX->file_handle);
            JSR_CNTX->file_handle = 0;
        }
        if(JSR_CNTX->object_file)
        {
            umms_free(JSR_CNTX->object_file);
            JSR_CNTX->object_file = NULL;
        }
        if(JSR_CNTX->file_path)
        {
            umms_free(JSR_CNTX->file_path);
            JSR_CNTX->file_path = NULL;
        }
        
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_terminate_req_handler
 * DESCRIPTION
 *  Invokes to handle terminate req from MMA
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_terminate_req_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_java_abort_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(JSR_CNTX->state)
    {
        case JSR_STATE_IDLE:
            return;
        case JSR_STATE_READ_FOLDER:
            mmi_jsr_read_folder_status_output_req_hldr(JSR_RESULT_ERROR, NULL);
            break;
        case JSR_STATE_UPLOAD_MSG:
            mmi_jsr_upload_msg_output_req_hldr(JSR_RESULT_ERROR, 0);
            break;
        case JSR_STATE_DELETE_MSG:
            mmi_jsr_delete_msg_output_req_hldr(JSR_RESULT_ERROR);
            break;
	    /*case JSR_STATE_CREATE_MSG:*/
        case JSR_STATE_PROCESS_SEND_MSG_HDR:
        case JSR_STATE_PROCESS_SEND_MSG_BDY:
        case JSR_STATE_RECV_MSG_HDR:
        case JSR_STATE_RECV_MSG_BDY:
        case JSR_STATE_SEND_MSG:
            
            msg = (mmi_java_abort_req_struct*) OslConstructDataPtr(sizeof(mmi_java_abort_req_struct));
            msg->session_id = 0;
            Message.oslSrcId = MOD_MMI;
            Message.oslDestId = MOD_J2ME;
            Message.oslMsgId = MSG_ID_MMI_JAVA_ABORT_REQ;
            Message.oslDataPtr = (local_para_struct*) msg;
            Message.oslPeerBuffPtr = NULL;
            OslMsgSendExtQueue(&Message);
            
            mmi_jsr_reset_xml_struct_msg();

            break;
        default:
            break;
    }
    JsrCleanContext();
    mmi_umms_init_jsr_folder();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_convert_phsuite_folder_to_jsr_folder
 * DESCRIPTION
 *  Converts Phone Suite folder type to JSR folder type
 * PARAMETERS
 *  S32
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_jsr_convert_phsuite_folder_to_jsr_folder(S32 folder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JsrPhSuiteFolderType phsuite_folder = (JsrPhSuiteFolderType)folder;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(phsuite_folder)
    {
        case JSR_PHSUITE_NONE:
            return JSR_NONE;
        case JSR_PHSUITE_INBOX:
            return (S32)JSR_INBOX;
        case JSR_PHSUITE_OUTBOX:
            return (S32)JSR_OUTBOX;            
        case JSR_PHSUITE_DRAFTS:
            return (S32)JSR_DRAFTS;
        case JSR_PHSUITE_SENT:
            return (S32)JSR_SENT;
        case JSR_PHSUITE_PREDEF_TEMPLATE:
            return (S32)JSR_PREDEF_TEMPLATE;
        default:
            return -1;            
    }
}

/* AT COMMANDS API */


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_read_folder_status_req_hldr
 * DESCRIPTION
 *  Create a WAP_MMC_READ_FOLDER_STATUS_REQ_IND primitive to L4
 * PARAMETERS
 *  msg     [?]     [?]     [?]     Message received from L4
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_read_folder_status_req_hldr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_read_folder_status_req_ind_struct *Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = (wap_mmc_read_folder_status_req_ind_struct*) msg;


	Message->folderId = (U8)mmi_jsr_convert_phsuite_folder_to_jsr_folder((S32)Message->folderId);
	

    PRINT_INFORMATION_2(MMI_TRACE_INFO,
                         "%s(%d):  MMI recives a wap_mmc_read_folder_status_req_ind signal, folder:%d and retrieval mode: %d. \n",
                         __FILE__, __LINE__, Message->folderId, Message->retrievalMode);

    if (FALSE == mmi_um_check_ready())
    {
        mmi_jsr_read_folder_status_output_req_hldr(JSR_RESULT_MMS_NO_READY, NULL);
        return;
    }

    if (JSR_CNTX->state == JSR_STATE_IDLE)
    {
        JsrCleanContext();  /* clean context first */

        if (    /* check for valid folder ID */
               (Message->folderId == JSR_INBOX)
               || (Message->folderId == JSR_OUTBOX)
               || (Message->folderId == JSR_SENT)
               || (Message->folderId == JSR_DRAFTS)
               || (Message->folderId == JSR_PREDEF_TEMPLATE)
               || (Message->folderId == JSR_USRDEF_TEMPLATE) || (Message->folderId == JSR_ARCHIVE))
        {
            if ((Message->retrievalMode == JSR_BASIC) || (Message->retrievalMode == JSR_FULL))
            {
                JSR_CNTX->state = JSR_STATE_READ_FOLDER;
                JSR_CNTX->op = JSR_OP_READ_MSG;
                JSR_CNTX->retrievalMode = Message->retrievalMode;
                JSR_CNTX->folderId = Message->folderId; /* update folder ID */

                /* get message ID list, message info, inbox message number */
                JSR_CNTX->req_id = wap_mma_get_request_id();    /* get request ID here as msg list can be multiple */
                mmi_jsr_get_msg_list_req();
            }
            else
            {   /* wrong retrevial mode */
                mmi_jsr_read_folder_status_output_req_hldr(JSR_RESULT_INVALID_PARAMETER, NULL);
            }
        }
        else
        {   /* wrong folder ID */
            mmi_jsr_read_folder_status_output_req_hldr(JSR_RESULT_INVALID_PARAMETER, NULL);
        }
    }
    else
    {   /* JSR Moduel is busy in processing other commands */
        mmi_jsr_read_folder_status_output_req_hldr(JSR_RESULT_BUSY, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_get_msg_list_req
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMA_GET_MSG_LSIT_REQ primitive to MMA
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_get_msg_list_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_msg_list_req_struct *msglist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msglist = (wap_mma_get_msg_list_req_struct*) OslConstructDataPtr(sizeof(*msglist));

    msglist->app_id = MMA_APP_ID_JSR;
    msglist->req_id = JSR_CNTX->req_id; /* wap_mma_get_request_id(); */
    msglist->folder = JSR_CNTX->folderId;

    mmi_jsr_post_message(
        /* send request for message list */ MOD_MMI,
        MOD_WAP,
        0,
        MSG_ID_WAP_MMA_GET_MSG_LIST_REQ,
        (oslParaType*) msglist,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_get_message_list_rsp
 * DESCRIPTION
 *  Decode MSG_ID_WAP_MMA_GET_MSG_LIST_RSP primitive from MMA
 *  Will come in two states
 *  - Read Folder to get all message list to get the message info
 *  - Delete folder to check if the message id requested is from default templates or not
 * PARAMETERS
 *  msgRsp      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_get_message_list_rsp(void *msgRsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 ifst = 0;
    U32 jnxt = 0;
    JsrResult result;

    wap_mma_get_msg_list_rsp_struct *msgList = (wap_mma_get_msg_list_rsp_struct*) msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (JSR_CNTX->state == JSR_STATE_READ_FOLDER)
    {   /* if state is get folder message info */

        if (msgList->result != JSR_RESULT_OK)
        {   /* if not Ok then send error result */
            mmi_jsr_read_folder_status_output_req_hldr(JSR_RESULT_INVALID_FOLDER, NULL);
            return;
        }

        if (JSR_CNTX->msgIDList == NULL)
        {   /* allocate memory first time only */

            JSR_CNTX->numofMsg = msgList->no_of_msg;

            if (JSR_CNTX->numofMsg == 0)
            {
                result = mmi_jsr_write_folder_status_to_file(JSR_CNTX->numofMsg, JSR_CNTX->msgInfolist);

                if (result != JSR_RESULT_OK)
                {   /* problem in writing folder info in file */
                    mmi_jsr_read_folder_status_output_req_hldr(result, NULL);
                    return;
                }
                /* send folder info resp */
                mmi_jsr_fill_folder_info_output_req();
                return;
            }

            /* allocate memory for message ID list */
            JSR_CNTX->msgIDList = (U32*) umms_malloc(sizeof(U32) * (msgList->no_of_msg));
            if (JSR_CNTX->msgIDList == NULL)
            {
                mmi_jsr_read_folder_status_output_req_hldr(JSR_RESULT_INSUFFICIENT_MEMORY, NULL);
                return;
            }

            memset(JSR_CNTX->msgIDList, 0, ((msgList->no_of_msg) * sizeof(U32)));

            ifst = 0;
            jnxt = 0;

            while (msgList->msg_id[jnxt] != 0)
            {   /* start copying the msgId */
                JSR_CNTX->msgIDList[ifst] = msgList->msg_id[jnxt];
                ifst++;
                jnxt++;
            }

            /* allocate memory for message info list */
            JSR_CNTX->msgInfolist = (JsrMessageInfo*) umms_malloc((msgList->no_of_msg) * sizeof(JsrMessageInfo));
            if (JSR_CNTX->msgInfolist == NULL)
            {
                mmi_jsr_read_folder_status_output_req_hldr(JSR_RESULT_INSUFFICIENT_MEMORY, NULL);
                return;
            }
            memset(JSR_CNTX->msgInfolist, 0, (msgList->no_of_msg) * sizeof(JsrMessageInfo));
        }

        else
        {   /* coming here for succesive message list responses > 399 */
            ifst = 0;
            jnxt = 0;

            while (JSR_CNTX->msgIDList[ifst] != 0)
            {
                ifst++; /* reach to the end of the list */
            }

            while (msgList->msg_id[jnxt] != 0)
            {   /* start copying the msgId at the end of the list */
                JSR_CNTX->msgIDList[ifst] = msgList->msg_id[jnxt];
                ifst++;
                jnxt++;
            }
        }

        if (msgList->more)
        {
            mmi_jsr_get_msg_list_req(); /* more msg ID list send req again */
        }
        else
        {
            mmi_jsr_get_msg_info_req(); /* get message info based on message ID one by one */
        }
    }

    /* if state is Delete message, will come here for Template message ID list */
    else if (JSR_CNTX->state == JSR_STATE_DELETE_MSG)
    {
        ifst = 0;

        if (msgList->result != JSR_RESULT_OK)
        {
            mmi_jsr_delete_msg_output_req_hldr(JSR_RESULT_INVALID_FOLDER);
            return;
        }

        while (msgList->msg_id[ifst] != 0)
        {
            if (msgList->msg_id[ifst] == JSR_CNTX->msgId)
            {
                /* to be deleted message ID matches with default template ID */
                mmi_jsr_delete_msg_output_req_hldr(JSR_RESULT_INVALID_FOLDER);
                return;
            }
            ifst++;
        }

        if (msgList->more)
        {
            mmi_jsr_get_msg_list_req(); /* more msg ID list send req again */
        }
        else
        {
            /* message id to be deleted is not from default template, delete the same */
            JSR_CNTX->folderId = 0;
            mmi_jsr_delete_msg_req(JSR_CNTX->folderId, JSR_CNTX->msgId);
        }
    }
    else    /* shoudl not come here */
    {
        ASSERT(0);
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_get_msg_info_req
 * DESCRIPTION
 *  Send MSG_ID_WAP_MMA_GET_MSG_INFO_REQ primitive to MMA
 * PARAMETERS
 *  void
 *  Global counter of message ID list(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_get_msg_info_req()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_msg_info_req_struct *msgInfo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgInfo = (wap_mma_get_msg_info_req_struct*) OslConstructDataPtr(sizeof(*msgInfo));

    msgInfo->app_id = MMA_APP_ID_JSR;
    msgInfo->req_id = wap_mma_get_request_id();
    msgInfo->msg_id = JSR_CNTX->msgIDList[JSR_CNTX->counter];
    /* send req for message info */
    mmi_jsr_post_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_GET_MSG_INFO_REQ, (oslParaType*) msgInfo, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_get_msg_info_rsp
 * DESCRIPTION
 *  Decode MSG_ID_WAP_MMA_GET_MSG_INFO_RSP primitive from MMA
 * PARAMETERS
 *  msgRsp      [?]     [?]     [?]
 *  msg RSP(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_get_msg_info_rsp(void *msgRsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JsrMessageInfo JsrMsgInfo;
    JsrResult result;
    U8 hfile[JSR_FILENAME_LEN];

    wap_mma_get_msg_info_rsp_struct *msgInfo = (wap_mma_get_msg_info_rsp_struct*) msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgInfo->result != JSR_RESULT_OK)
    {
        mmi_jsr_read_folder_status_output_req_hldr(JSR_RESULT_ERROR_MSG_CORRUPTED, NULL);
        return;
    }

    memset(&JsrMsgInfo, 0, sizeof(JsrMessageInfo));
    JsrMsgInfo.msgId = JSR_CNTX->msgIDList[JSR_CNTX->counter];
    JsrMsgInfo.offset = 0;
    JsrMsgInfo.size = msgInfo->msg_size;
    JsrMsgInfo.date = msgInfo->date;

    /* amit to do   mms_get_message_full_path(kal_uint32 msg_id, char *dest, kal_uint32 dest_len); */
    /* MMAlib_getMessageFullPathExt(JsrMsgInfo.msgId, &JsrMsgInfo.filename, JSR_FILENAME_LEN); */
    wap_mms_get_message_file_name(JsrMsgInfo.msgId, (kal_wchar*)&hfile, JSR_FILENAME_LEN);
    mmi_ucs2_n_to_asc((S8*) JsrMsgInfo.filename, (S8*) & hfile, JSR_FILENAME_LEN * ENCODING_LENGTH);

    if (JSR_CNTX->retrievalMode == JSR_FULL)
    {   /* write address and subject only when retrieval mode is JSR_FULL */


	//	extern int mmi_charset_ucs2_to_utf8_length_in_bytes(const kal_uint8 *raw);
       //mmi_chset_ucs2_to_utf8_string(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src);
       mmi_chset_ucs2_to_utf8_string((U8*)JsrMsgInfo.address, JSR_ADDR_LEN, (U8*)msgInfo->from_address);
       mmi_chset_ucs2_to_utf8_string((U8*)JsrMsgInfo.subject, JSR_SUBJECT_LEN , (U8*)msgInfo->subject);
        
	   //mmi_ucs2_n_to_asc((S8*) JsrMsgInfo.address, (S8*) msgInfo->from_address, JSR_ADDR_LEN * ENCODING_LENGTH);
       //mmi_ucs2_n_to_asc((S8*) JsrMsgInfo.subject, (S8*) msgInfo->subject, JSR_SUBJECT_LEN * ENCODING_LENGTH);
    }

    memcpy(&JSR_CNTX->msgInfolist[JSR_CNTX->counter], &JsrMsgInfo, sizeof(JsrMsgInfo));

    JSR_CNTX->counter++;    /* increment the counter now to point to mext ID */

    if (JSR_CNTX->counter < JSR_CNTX->numofMsg)
        /* check if we have got message info of all the message ID's */
    {
        mmi_jsr_get_msg_info_req();
    }
    else
    {   /* YES: we have got message info of all the Messages */
        result = mmi_jsr_write_folder_status_to_file(JSR_CNTX->numofMsg, JSR_CNTX->msgInfolist);

        if (result != JSR_RESULT_OK)
        {   /* problem in writing folder info in file */
            mmi_jsr_read_folder_status_output_req_hldr(result, NULL);
            return;
        }
        /* folder info properly created */
        if (JSR_CNTX->folderId == JSR_INBOX)
            /* if its inbox get no. of unread msg */
        {
            mmi_jsr_get_msg_num_req();
        }
        else
            /* send folder info resp */
        {
            mmi_jsr_fill_folder_info_output_req();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_get_msg_num_req
 * DESCRIPTION
 *  Send PRT_MSG_ID_MMI_UM_GET_MSG_NUM_REQ primitive to UM
 * PARAMETERS
 *  void
 *  folder ID(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_get_msg_num_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_get_msg_num_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_um_get_msg_num_req_struct*) OslConstructDataPtr(sizeof(*msgReq));
    msgReq->app_id = MMA_APP_ID_JSR;
    msgReq->msg_type = UM_MSG_TYPE_MMS;
    mmi_jsr_post_message(MOD_MMI, MOD_WAP, 0, PRT_MSG_ID_MMI_UM_GET_MSG_NUM_REQ, (oslParaType*) msgReq, NULL);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_get_msg_num_rsp
 * DESCRIPTION
 *  Decode MSG_ID_MMI_UM_GET_MSG_NUM_RSP primitive from UM
 * PARAMETERS
 *  msgRsp      [?]     [?]     [?]
 *  finMsg(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_get_msg_num_rsp(void *msgRsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_get_msg_num_rsp_struct *msgNum = (mmi_um_get_msg_num_rsp_struct*) msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgNum->result != TRUE)
    {
        mmi_jsr_read_folder_status_output_req_hldr(JSR_RESULT_INVALID_FOLDER, NULL);
        return;
    }

    switch (JSR_CNTX->folderId)
    {
        case JSR_INBOX:
            JSR_CNTX->numofUnreadMsg = msgNum->inbox_unread_msg_number;
            break;
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* 0 */ 
        default:
        {
            mmi_jsr_read_folder_status_output_req_hldr(JSR_RESULT_INVALID_FOLDER, NULL);
            return;
        }
    }
    /* got no.of unread message and hence send folder info */
    mmi_jsr_fill_folder_info_output_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_write_folder_status_to_file
 * DESCRIPTION
 *  Write mms folder status to information file
 * PARAMETERS
 *  no_of_msgs      [IN]        Number of messages
 *  list            [?]         [?]         [?]         [?]         List of messages
 * RETURNS
 *  JsrResult
 *****************************************************************************/
JsrResult mmi_jsr_write_folder_status_to_file(U32 no_of_msgs, JsrMessageInfo *list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* U32 msg_no = 0; */
    U32 info_file_size = 0;
    int result = JSR_RESULT_ERROR;
    U32 bytes_written = 0;
    U8 pInFilename[JSR_FILENAME_LEN_MMA];
    FS_HANDLE fh = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(pInFilename, 0, JSR_FILENAME_LEN_MMA);
    MAKE_JSR_INFO_FILE(pInFilename);

    FS_Delete((U16*) pInFilename);

    if (no_of_msgs == 0)
    {   /* if no message then dont write anything in file and return */
        result = JSR_RESULT_OK;
        goto END;
    }

    fh = FS_Open((U16*) pInFilename, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (fh < 0)
    {
        result = JSR_RESULT_FILE_OPERATION_ERROR;
        goto END;
    }

    info_file_size = no_of_msgs * sizeof(JsrMessageInfo);

    result = FS_Write(fh, list, info_file_size, &bytes_written);
    if (result < 0)
    {
        if (bytes_written != info_file_size)
        {
            FS_Delete((U16*) pInFilename);
            result = JSR_RESULT_FILE_OPERATION_ERROR;
            goto END;
        }
    }

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d): JSR module write folder status to info.db file. \n", __FILE__,
                         __LINE__);

    result = JSR_RESULT_OK;

  END:

    if (fh != 0)
    {
        FS_Close(fh);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_fill_folder_info_output_req
 * DESCRIPTION
 *  Fill up folder info from JST COntext global structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_fill_folder_info_output_req()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JsrFolderInfo *folderInfo = NULL;
    U8 pInFilename[JSR_FILENAME_LEN_MMA];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folderInfo = (JsrFolderInfo*) umms_malloc(sizeof(JsrFolderInfo));
    if (folderInfo == NULL)
    {
        mmi_jsr_read_folder_status_output_req_hldr(JSR_RESULT_INSUFFICIENT_MEMORY, NULL);
        return;
    }

    memset(folderInfo, 0, sizeof(JsrFolderInfo));

    memset(pInFilename, 0, JSR_FILENAME_LEN_MMA);
    MAKE_JSR_INFO_FILE(pInFilename);

    mmi_ucs2ncpy((S8*) folderInfo->infoFilePath, (S8*) pInFilename, JSR_FILENAME_LEN_MMA / 2);

    folderInfo->numOfMsg = JSR_CNTX->numofMsg;
    folderInfo->numOfUnreadMsg = JSR_CNTX->numofUnreadMsg;

//    memset(hdir, 0, JSR_FILENAME_LEN_MMA);
    wap_mms_get_home_directory((kal_wchar*)folderInfo->mmsHomeDirectory, JSR_FILENAME_LEN_MMA);

    mmi_jsr_read_folder_status_output_req_hldr(JSR_RESULT_OK, folderInfo);
    umms_free(folderInfo);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_read_folder_status_output_req_hldr
 * DESCRIPTION
 *  Create a WAP_MMC_READ_FOLDER_STATUS_OUTPUT_REQ primitive to L4
 * PARAMETERS
 *  result          [IN]        
 *  folderInfo      [?]         [?]         [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_read_folder_status_output_req_hldr(JsrResult result, JsrFolderInfo *folderInfo)
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
        if (folderInfo)
        {
            myMsgPtr->numOfMsg = folderInfo->numOfMsg;
            myMsgPtr->numOfUnreadMsg = folderInfo->numOfUnreadMsg;

            memset(myMsgPtr->mmsHomeDirectory, 0x00, JSR_FILENAME_LEN_MMA);
            memset(myMsgPtr->infoFilePath, 0x00, JSR_FILENAME_LEN_MMA);

            memcpy(
                myMsgPtr->mmsHomeDirectory,
                folderInfo->mmsHomeDirectory,
                (mmi_ucs2strlen((char*)folderInfo->mmsHomeDirectory) * ENCODING_LENGTH));
            memcpy(
                myMsgPtr->infoFilePath,
                folderInfo->infoFilePath,
                (mmi_ucs2strlen((char*)folderInfo->infoFilePath) * ENCODING_LENGTH));
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
            JsrCleanContext();
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
 *  msg     [?]     [?]     [?]     [?]
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
    S32 handle = -1;
    U32 size;
    U8 ret;
	/*kal_wchar *fname = NULL;*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = (wap_mmc_upload_msg_req_ind_struct*) msg;

    if (FALSE == mmi_um_check_ready())
    {
        mmi_jsr_upload_msg_output_req_hldr(JSR_RESULT_MMS_NO_READY, 0);
        return;
    }
    handle = FS_Open((WCHAR*) Message->filePath, FS_READ_ONLY | FS_OPEN_SHARED);
    
    if(handle < 0)
    {
       mmi_jsr_upload_msg_output_req_hldr(JSR_RESULT_FILE_OPERATION_ERROR, 0);
       return;
    }

    ret = (U8)FS_GetFileSize(handle, &size);
    if(ret != JSR_RESULT_OK)
    {
        mmi_jsr_upload_msg_output_req_hldr(JSR_RESULT_FILE_OPERATION_ERROR, 0);
        FS_Close(handle);
        return;
    }
    if(size > (U32)wap_custom_get_max_mms_msg_size())
    {
        mmi_jsr_upload_msg_output_req_hldr(JSR_RESULT_EXCEED_MAX_MSGS, 0);
        FS_Close(handle);
        return;
    }
    
    FS_Close(handle);

    /* Check the MMS folder for Max messages. */
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d):  MMI recives a wap_mmc_upload_msg_req_ind signal. \n", __FILE__,
                         __LINE__);

    if (JSR_CNTX->state == JSR_STATE_IDLE)
    {
        JsrCleanContext();  /* clean context first */
        JSR_CNTX->op = JSR_OP_UPLOAD_MSG;
        JSR_CNTX->state = JSR_STATE_UPLOAD_MSG;

        if (Message->filePath)
        {
            len = mmi_charset_ucs2_to_utf8_length_in_bytes(Message->filePath);

            if (len < JSR_FILENAME_LEN_MMA * sizeof(kal_wchar))
            {
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
                mmi_jsr_create_mms_msg_req((kal_wchar*) Message->filePath);  /* create message */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            }
            else
            {
                ASSERT(0);  /* File path too long. */
            }
        }
        else
        {
            mmi_jsr_upload_msg_output_req_hldr(JSR_RESULT_INVALID_MESSAGE, 0);
        }
    }
    else
    {
        mmi_jsr_upload_msg_output_req_hldr(JSR_RESULT_BUSY, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_create_mms_msg_req
 * DESCRIPTION
 *  Create a MMS message with file path as specified and save the same in outbox
 * PARAMETERS
 *  fname       [?]     [?]     [?]
 *  msg     [?](?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_create_mms_msg_req(kal_wchar *fname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_create_req_struct *msg_req;

    /* peer_buff_struct *peer_buff_ptr; */
    /* U32 read_size; */
    /* U16 peer_buff_len = 0; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_req = (wap_mma_create_req_struct*) OslConstructDataPtr(sizeof(wap_mma_create_req_struct));
    msg_req->req_id = wap_mma_get_request_id();

    /* reset */
    msg_req->mode = MMA_MODE_UPLOAD;
    msg_req->msg_id = 0;
    msg_req->app_id = MMA_APP_ID_JSR;

    msg_req->buffer_index = 0;
    msg_req->xml_size = 0;
    msg_req->more = FALSE;

    mmi_ucs2cpy((S8*) msg_req->msg_file_path, (S8*) fname);

    /*    peer_buff_ptr = construct_peer_buff((kal_uint16) msg_req->buffer_size, 0, 0, TD_CTRL); */

    mmi_jsr_post_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_CREATE_REQ, (oslParaType*) msg_req, NULL);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_create_mms_msg_rsp
 * DESCRIPTION
 *  Create a MMS message rsp with file path as specified and save the same in outbox
 *  Come in two states
 *  - Upload Message
 *  - Send MMS ...before sending will create MMS
 * PARAMETERS
 *  inMsg       [?]     [?]     [?]
 *  msg     [?](?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_create_mms_msg_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_create_rsp_struct *msg_rsp = (wap_mma_create_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (JSR_CNTX->state == JSR_STATE_UPLOAD_MSG)
    {
        if (msg_rsp->result != JSR_RESULT_OK)
        {
            mmi_jsr_upload_msg_output_req_hldr(JSR_RESULT_ERROR_MSG_CORRUPTED, msg_rsp->msg_id);
        }
        else
        {
            mmi_jsr_upload_msg_output_req_hldr(msg_rsp->result, msg_rsp->msg_id);
            mmi_umms_update_status_icon_indicator();
        }
    }

    else if ((JSR_CNTX->state == JSR_STATE_PROCESS_SEND_MSG_BDY) || (JSR_CNTX->state == JSR_STATE_PROCESS_SEND_MSG_HDR))
    {
        mmi_jsr_create_for_send_mms_rsp(msg_rsp);
    }

    else
    {
        return;  /* shoudl not come here */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_upload_msg_output_req_hldr
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_UPLOAD_MSG_OUTPUT_REQ primitive to L4
 * PARAMETERS
 *  result      [IN]        
 *  msgId       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_upload_msg_output_req_hldr(JsrResult result, U32 msgId)
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
        myMsgPtr->msgId = msgId;

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
            if (result == JSR_RESULT_OK)
            {
                /* Refresh the MMS folder menu screen. */
                /* amit to check mmi_um_jmms_highlight_mms_message_ind */
                mmi_jsr_um_refresh_ind(JSR_DRAFTS); /* new message will always created in draft folder */
            }
            JsrCleanContext();
        }
        PRINT_INFORMATION_2(MMI_TRACE_INFO,
                             "%s(%d): JSR module returns wap_mmc_upload_msg_output_req with result %d and msgid %d \n",
                             __FILE__, __LINE__, result, msgId);
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
 *  mmi_jsr_um_refresh_ind
 * DESCRIPTION
 *  Send refresh Ind to UM
 * PARAMETERS
 *  folderID        [IN]        
 *  msgId(?)        [IN](?)(?)
 *  result(?)       [IN](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_um_refresh_ind(U32 folderID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* ilm_struct *ilm_ptr = NULL; */
    mmi_um_refresh_ind_struct *um_refresh_ind = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    um_refresh_ind =
        (mmi_um_refresh_ind_struct*) construct_local_para((kal_uint16) sizeof(mmi_um_refresh_ind_struct), 0);
    um_refresh_ind->msg_type = UM_MSG_TYPE_MMS;
    /* Below statement overrides all folder ID's sent by JSR and will refresh only current open
       folder. Msg_id and folder_id are not mapped */
    um_refresh_ind->msg_box_type = mmi_um_get_current_msg_box_type();

    mmi_jsr_post_message(MOD_MMI, MOD_MMI, 0, MSG_ID_MMI_UM_REFRESH_IND, (oslParaType*) um_refresh_ind, NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_delete_msg_req_hldr
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_DELETE_MSG_REQ_IND primitive to L4
 * PARAMETERS
 *  msg     [?]     [?]     [?]     [?]
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

    Message->folderId = (U8)mmi_jsr_convert_phsuite_folder_to_jsr_folder((S32)Message->folderId);
	

    PRINT_INFORMATION_2(MMI_TRACE_INFO,
                         "%s(%d):  MMI recives a wap_mmc_deldete_msg_req_ind signal from l4c, msgid: %d and folderId: %d \n",
                         __FILE__, __LINE__, Message->msgId, Message->folderId);

    if (FALSE == mmi_um_check_ready())
    {
        mmi_jsr_delete_msg_output_req_hldr(JSR_RESULT_MMS_NO_READY);
        return;
    }

    if (JSR_CNTX->state == JSR_STATE_IDLE)
    {
        JsrCleanContext();  /* clean context first */

        JSR_CNTX->op = JSR_OP_DELETE_MSG;
        JSR_CNTX->state = JSR_STATE_DELETE_MSG;
        JSR_CNTX->msgId = Message->msgId;
        JSR_CNTX->folderId = Message->folderId;

        if (Message->folderId != 0)
        {   /* delete all messages in folder of that particilar msgID */
            if ((Message->folderId == JSR_INBOX)
                || (Message->folderId == JSR_OUTBOX)
                || (Message->folderId == JSR_SENT)
                || (Message->folderId == JSR_DRAFTS)
                || (Message->folderId == JSR_USRDEF_TEMPLATE) || (Message->folderId == JSR_ARCHIVE))
            {
                /* send request to delete all message of that folder */
                /* amit to check if any MMS i sopen from that particular message Box */
                if (KAL_TRUE == mmi_umms_is_any_mms_opened_in_box((mma_folder_enum) Message->folderId))
                {
                    mmi_jsr_delete_msg_output_req_hldr(JSR_RESULT_ACCESS_DENY);
                }
                else
                {
                    mmi_jsr_delete_msg_req(Message->folderId, Message->msgId);
                }
            }
            else
                /* folder can be from JSR_PREDEF_TEMPLATE  and then is not allowed to delete */
            {
                mmi_jsr_delete_msg_output_req_hldr(JSR_RESULT_INVALID_FOLDER);
            }
        }
        else
        {   /* delete one particular message ID */
            /* to do check if message is opened or folder is template */
            if (KAL_TRUE == mmi_umms_is_mms_in_open_state((U32) Message->msgId))
            {
                mmi_jsr_delete_msg_output_req_hldr(JSR_RESULT_ACCESS_DENY);
            }
            else
            {
                JSR_CNTX->folderId = JSR_PREDEF_TEMPLATE;
                JSR_CNTX->req_id = wap_mma_get_request_id();
                mmi_jsr_get_msg_list_req();
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
 *  mmi_jsr_delete_msg_req
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMA_DELETE_REQ primitive to MMA
 * PARAMETERS
 *  folderId        [IN]        
 *  msgId           [IN]        
 *  msg     [?](?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_delete_msg_req(U32 folderId, U32 msgId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_delete_req_struct *deleteReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    deleteReq = (wap_mma_delete_req_struct*) OslConstructDataPtr(sizeof(wap_mma_delete_req_struct));
    deleteReq->app_id = MMA_APP_ID_JSR;
    deleteReq->req_id = wap_mma_get_request_id();

    /* NOTE: Amit to check if message being are sent or not if folder ID is OUTBOX */
    if (folderId)
    {   /* delete all message in folder */
        deleteReq->msg_id = 0xFFFFFFFF;
        deleteReq->box = folderId;
    }
    else
    {   /* delete specific message only */
        deleteReq->msg_id = msgId;
        deleteReq->box = folderId;
    }

    mmi_jsr_post_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_DELETE_REQ, (oslParaType*) deleteReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_delete_msg_rsp
 * DESCRIPTION
 *  Decodes a MSG_ID_WAP_MMA_DELETE_RSP primitive from MMA
 *  Will come in two states
 *  - Delete message req
 *  - Receive message req
 * PARAMETERS
 *  delmsg      [?]     [?]     [?]
 *  msg(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_delete_msg_rsp(void *delmsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *msg = (wap_mma_rsp_struct*) delmsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* for delete */
    if (JSR_CNTX->state == JSR_STATE_DELETE_MSG)
    {
        if (msg->result != JSR_RESULT_OK)
        {
            mmi_jsr_delete_msg_output_req_hldr(JSR_RESULT_MESSAGE_ID_NOT_FOUND);
        }
        else
        {
            mmi_jsr_delete_msg_output_req_hldr(msg->result);
            mmi_umms_update_status_icon_indicator();
        }
    }
    /* for receive MMS */
    else if (JSR_CNTX->state == JSR_STATE_RECV_MSG_HDR || JSR_CNTX->state == JSR_STATE_RECV_MSG_BDY)
    {
        if (msg->result == JSR_RESULT_OK)
        {
            mmi_jsr_um_refresh_ind(JSR_CNTX->folderId);
            mmi_umms_update_status_icon_indicator();
        }

        JsrCleanContext();
        mmi_jsr_reset_xml_struct_msg();
    }
    /* for Send MMS */
    else if (JSR_CNTX->state == JSR_STATE_PROCESS_SEND_MSG_HDR || JSR_CNTX->state == JSR_STATE_PROCESS_SEND_MSG_BDY
		|| JSR_CNTX->state == JSR_STATE_SEND_MSG)
    {
        if (msg->result == JSR_RESULT_OK)
        {
            mmi_jsr_um_refresh_ind(JSR_DRAFTS);
            mmi_umms_update_status_icon_indicator();
        }

        JsrCleanContext();
    }
    return;
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
void mmi_jsr_delete_msg_output_req_hldr(JsrResult result)
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
            if (result == JSR_RESULT_OK)
            {
                /* Refresh the MMS folder menu screen. */
                mmi_jsr_um_refresh_ind(JSR_CNTX->folderId); /* amit to get the folder ID */
            }
            JsrCleanContext();
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
 *  mmi_jsr_cfg_appmms_appid_req
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_CFG_APPMMS_APPID_REQ primitive to Java
 * PARAMETERS
 *  msg     [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_cfg_appmms_appid_req(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_cfg_appmms_appid_req_struct *Message;
    JsrResult result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = (wap_mmc_cfg_appmms_appid_req_struct*) msg;
    result = mmi_jsr_cfg_app_id(Message->app_id, Message->app_id_len, Message->op);
    mmi_jsr_cfg_appmms_appid_rsp(result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_cfg_app_id
 * DESCRIPTION
 *  Register/Deregister the Java application
 * PARAMETERS
 *  app_id              [?]         [?]         [?]         [?]
 *  app_id_length       [IN]        
 *  is_remove           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
JsrResult mmi_jsr_cfg_app_id(U8 *app_id, U8 app_id_length, U8 is_remove)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((app_id == NULL) || (app_id_length == 0))
    {
        return JSR_RESULT_INVALID_PARAMETER;
    }
    if (is_remove == TRUE)
    {
        for (i = 0; i < JSR_MAX_APP_ID_NUM; i++)
        {
            if ((jsr_appid_db[i])
                && (jsr_appid_db[i]->appId) && (strcmp((S8*) jsr_appid_db[i]->appId, (S8*) app_id) == 0))
            {
                umms_free(jsr_appid_db[i]->appId);
                umms_free(jsr_appid_db[i]);
                jsr_appid_db[i] = NULL;
                return JSR_RESULT_OK;
            }
        }
        return JSR_RESULT_ERROR_APPID_NOT_FOUND;
    }
    else
    {
        S32 empty_slot = -1;

        for (i = 0; i < JSR_MAX_APP_ID_NUM; i++)
        {
            if (jsr_appid_db[i] == NULL)
            {
                empty_slot = i;
                break;
            }
            else
            {
                if ((jsr_appid_db[i]->appId) && (strcmp((S8*) jsr_appid_db[i]->appId, (S8*) app_id) == 0))
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
            jsr_appid_db[i] = (jsr_appid_info_struct*) umms_malloc(sizeof(jsr_appid_info_struct));
            jsr_appid_db[i]->appId = (S8*) umms_malloc(app_id_length + 1);
            memcpy(jsr_appid_db[i]->appId, app_id, app_id_length);
            return JSR_RESULT_OK;
        }
    }
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
void mmi_jsr_cfg_appmms_appid_rsp(JsrResult result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_cfg_appmms_appid_rsp_struct *myMsgPtr;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
 *  mmi_jsr_check_appmms_coming_req
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_CHECK_APPMMS_COMING_REQ primitive to Java
 * PARAMETERS
 *  msg     [?]     [?]     [?]     [?]
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
    Message = (wap_mmc_check_appmms_coming_req_struct*) msg;
    result = mmi_jsr_check_appid_msgs(Message->app_id, Message->app_id_len, (U8) Message->only_new);
    mmi_jsr_check_appmms_coming_rsp(result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_check_appid_msgs
 * DESCRIPTION
 *  Checks the application object list for specific application
 * PARAMETERS
 *  app_id              [?]         [?]         [?]         [?]
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
    if (g_jsr_appid_object_list == NULL)
    {
        mmi_jsr_read_object_list_from_file();
    }
    if (g_jsr_appid_object_list)
    {
        jsr_appid_msgid_list *appid_list = g_jsr_appid_object_list;

        while (appid_list)
        {
            if ((appid_list->appId) && (strcmp((S8*) appid_list->appId, (S8*) app_id) == 0))
            {
                jsr_msg_info *msg_list = appid_list->msgs;

                while (msg_list)
                {
                    if (msg_list->is_checked == FALSE)
                    {
                        msg_list->is_checked = TRUE;
                        mmi_jsr_write_object_list_to_file();
                        return TRUE;
                    }
                    else
                    {
                        if (is_new == FALSE)
                        {
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
 *  mmi_jsr_add_recv_java_mms_content
 * DESCRIPTION
 *  Thsi will be called by MMS applicaiton when JAVA Message is recived
 * PARAMETERS
 *  msgId       [IN]        
 *  app_id      [?]         [?]         [?]
 *  contentType     [?](?)(?)(?)
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_jsr_add_recv_java_mms_content(U32 msgId, U8 *app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (TRUE == mmi_jsr_insert_msgId_to_appId_list(msgId, app_id, FALSE))
    {
        if (TRUE == mmi_jsr_check_appId((S8*) app_id))
        {
            mmi_jsr_send_appmms_new_mms_ind(app_id, (U32) strlen((S8*) app_id));
        }
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_send_appmms_new_mms_ind
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_APPMMS_NEW_MMS_IND primitive to Java
 * PARAMETERS
 *  appId       [?]         [?]         [?]         [?]
 *  length      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_send_appmms_new_mms_ind(U8 *appId, U32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_appmms_new_mms_ind_struct *myMsgPtr;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_mmc_appmms_new_mms_ind_struct*) OslConstructDataPtr(sizeof(wap_mmc_appmms_new_mms_ind_struct));
    memcpy(myMsgPtr->app_id, appId, length);
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

/* JAVA PROFILE SETTINGS API */


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_get_mms_profile_req
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_GET_MMS_PROF_REQ primitive to Java
 * PARAMETERS
 *  msg     [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_get_mms_profile_req(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_get_mms_prof_req_struct *Message;
    nvram_profile_content_struct *profile_data;
    U8 result = 2;  /* invalid prof id. */
    U8 value_length = 0;
    U8 *value = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = (wap_mmc_get_mms_prof_req_struct*) msg;

    switch (Message->access_id)
    {
        case JSR_WAP_MMS_PROF_MMSC_ADDRESS:
        {
            /* U8 mms_profile_id; */
            value = (U8*) umms_malloc(256);

            profile_data = (nvram_profile_content_struct*) mmi_brw_prof_get_activated_mms_profile();
            if (NULL == profile_data)
            {
                result = 1; /* MMS not ready yet. */
                break;
            }
            value_length = strlen((S8*) profile_data->url) + 1;

            if (value_length > 256)
            {
                ASSERT(0);  /* memory corruption */
            }
            memcpy(value, profile_data->url, value_length);
            result = 0;
            break;
        default:    /* will send result as 2 invalid profile */
            break;
        }
    }
    mmi_jsr_get_mms_profile_rsp(result, value, value_length);

    if (NULL != value)
    {
        umms_free(value);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_get_mms_profile_rsp
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_GET_MMS_PROF_RSP primitive to Java
 * PARAMETERS
 *  result              [IN]        
 *  value               [?]         [?]         [?]         [?]
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


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_abort_appmms_req
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_ABORT_APPMMS_REQ primitive to Java
 * PARAMETERS
 *  msg     [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_abort_appmms_req(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 file_name_p[JSR_FILENAME_LEN_MMA];

    /* U32 file_path_len = 0; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((JSR_CNTX->op == JSR_OP_ABORT_SENDING_MSG)||(JSR_CNTX->op == JSR_OP_ABORT_RECIEVING_MSG))||((JSR_CNTX->op != JSR_OP_SEND_MSG) && (JSR_CNTX->op != JSR_OP_RECV_MSG)))
    {
        mmi_jsr_abort_appmms_rsp(JSR_RESULT_ACCESS_DENY);
    }
    else
    {
        if (JSR_CNTX->op == JSR_OP_SEND_MSG)
        {
            if ((JSR_CNTX->state == JSR_STATE_PROCESS_SEND_MSG_HDR)
                || (JSR_CNTX->state == JSR_STATE_PROCESS_SEND_MSG_BDY))
            {
                memset(file_name_p, 0, JSR_FILENAME_LEN_MMA);
                MAKE_JSR_MEDIA_OBJECT_FILE(file_name_p);

                mmi_jsr_abort_appmms_rsp(JSR_RESULT_OK);

                FS_Delete((U16*) file_name_p);
                JsrCleanContext();
                mmi_jsr_reset_xml_struct_msg();
            }
            else
            {
                mmi_jsr_cancel_send_msg_req();
            }
            JSR_CNTX->op = JSR_OP_ABORT_SENDING_MSG;
        }
        else
        {
            /* Aborting receiving of Java MMS by Java app. */
            memset(file_name_p, 0, JSR_FILENAME_LEN_MMA);
            MAKE_JSR_MEDIA_OBJECT_FILE(file_name_p);

            mmi_jsr_abort_appmms_rsp(JSR_RESULT_OK);
            mmi_umms_reset_mms_downloading_busy();
            FS_Delete((U16*) file_name_p);
            JsrCleanContext();
            mmi_jsr_reset_xml_struct_msg();
            JSR_CNTX->op = JSR_OP_ABORT_RECIEVING_MSG;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_cancel_send_msg_req
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMA_CANCEL_SEND_REQ primitive to MMA
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_cancel_send_msg_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_cancel_send_req_struct *msglist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msglist = (wap_mma_cancel_send_req_struct*) OslConstructDataPtr(sizeof(*msglist));

    msglist->app_id = MMA_APP_ID_JSR;
    msglist->req_id = wap_mma_get_request_id();
    msglist->msg_id = JSR_CNTX->msgId;
    msglist->app_id = MMA_APP_ID_JSR;

    /* send request for message list */
    mmi_jsr_post_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_CANCEL_SEND_REQ, (oslParaType*) msglist, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_cancel_send_msg_rsp
 * DESCRIPTION
 *  Decodes a MSG_ID_WAP_MMA_CANCEL_SEND_RSP primitive from MMA
 * PARAMETERS
 *  msgRsp      [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_cancel_send_msg_rsp(void *msgRsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *csRsp = (wap_mma_rsp_struct*) msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (csRsp->result != JSR_RESULT_OK)
    {
        mmi_jsr_abort_appmms_rsp(JSR_RESULT_ERROR_SEND_CANCEL_BY_SYSTEM);
    }
    else
    {
        mmi_jsr_abort_appmms_rsp(csRsp->result);
       /*Send_Rsp fail flow will take care of resetting structures,icons and deleting MMS from drafts*/
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
void mmi_jsr_abort_appmms_rsp(JsrResult result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_abort_appmms_rsp_struct *myMsgPtr;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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

/* JSR INTERNAL APIs */


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_insert_msgId_to_appId_list
 * DESCRIPTION
 *  Insert the message information in application object list when new JAVA MSG Comes.
 * PARAMETERS
 *  msgId           [IN]        
 *  appId           [?]         [?]         [?]         [?]
 *  is_checked      [IN]        
 * RETURNS
 *  MMI_BOOL result
 *****************************************************************************/
MMI_BOOL mmi_jsr_insert_msgId_to_appId_list(U32 msgId, U8 *appId, BOOL is_checked)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jsr_appid_msgid_list *appid_list = NULL;
    jsr_msg_info *msg_list = NULL;
    MMI_BOOL result = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jsr_appid_object_list == NULL)
    {
        mmi_jsr_read_object_list_from_file();
    }
    appid_list = g_jsr_appid_object_list;

    while (appid_list)
    {
        if ((appid_list->appId) && (strcmp((S8*) appid_list->appId, (S8*) appId) == 0))
        {
            result = mmi_jsr_insert_msg_info_to_list(&(appid_list->msgs), msgId, is_checked);
            break;
        }
        appid_list = appid_list->next;
    }
    if (appid_list == NULL)
    {
        if (mmi_jsr_insert_msg_info_to_list(&msg_list, msgId, is_checked))
        {
            result = mmi_jsr_insert_appid_info_to_list(&appid_list, (S8*) appId, msg_list);
            g_jsr_appid_object_list = appid_list;
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
 *  Used in recive Java MMS routines.
 * PARAMETERS
 *  msgId       [IN]        
 * RETURNS
 *  MMI_BOOL result
 *****************************************************************************/
MMI_BOOL mmi_jsr_remove_msgId_from_appId_list(U32 msgId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jsr_appid_msgid_list *appid_list = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jsr_appid_object_list == NULL)
    {
        mmi_jsr_read_object_list_from_file();
    }
    appid_list = g_jsr_appid_object_list;

    while (appid_list)
    {
        if (appid_list->msgs)
        {
            jsr_msg_info *msg_list = appid_list->msgs;

            while (msg_list)
            {
                if (msg_list->msgId == msgId)
                {
                    mmi_jsr_remove_msg_info_from_list(&(appid_list->msgs), msgId);
                    if (appid_list->msgs == NULL)
                    {
                        mmi_jsr_remove_appid_info_from_list(&g_jsr_appid_object_list, appid_list->appId);
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
 *  mmi_jsr_read_object_list_from_file
 * DESCRIPTION
 *  Read the application object list information from a file.
 *  mmi_jsr_add_recv_java_mms_content
 *  mmi_jsr_check_appmms_coming_req
 *  mmi_jsr_receive_appmms_req_hldr
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
    U8 filename[JSR_FILENAME_LEN_MMA];
    int filehandle = -1;
    S8 *buff;
    U32 buf_size = FILE_BUF_SIZE;
    U32 line_length;
    S32 ret;
    MMI_BOOL update_file = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(filename, 0, JSR_FILENAME_LEN_MMA);
    MAKE_JSR_APPID_LIST_FILE(filename);

    filehandle = FS_Open((U16*) (filename), FS_READ_ONLY);
    if (filehandle < 0)
    {
        return;
    }

    buff = (S8*) umms_malloc(buf_size);

    while (1)
    {
        S8 *appid_string = NULL;
        jsr_msg_info *msg_list = NULL;
        U32 step = 1;

        for (step = 1; step < 4; step++)
        {
            /* applib_file_read_line(filehandle, buff, buf_size, &line_length, &ret); */
            mmi_jsr_read_line_from_file(filehandle, buff, buf_size, &line_length, &ret);
            if ((ret == 0) && (line_length == 0))
            {
                FS_Close(filehandle);
                umms_free(buff);
                if (update_file == TRUE)
                {
                    mmi_jsr_write_object_list_to_file();
                }
                return;
            }
            else if (ret < 0)
            {
                FS_Close(filehandle);
                umms_free(buff);
                /* File format corrupted, so remove all the appid info. */
                mmi_jsr_remove_appid_info_from_list_recursive(&g_jsr_appid_object_list);
                return;
            }
            ASSERT(line_length > 2);
            /* replace '\r''\n' with '\0''\0' */
            *(buff + line_length - 1) = '\0';
            *(buff + line_length - 2) = '\0';

            /* Read appid from file */
            if (step == 1)
            {
                appid_string = (S8*) umms_malloc(strlen((char*)buff) + 1);
                ASSERT(appid_string);
                strcpy((S8*) appid_string, (S8*) buff);
            }
            /* Read msgid and isChecked string */
            else if (step == 2)
            {
                S8 *text = buff;
                S8 *colon = NULL;
                S8 *next_token = NULL;
                U32 msgId;
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
                    msgId = atoi((char*)text);
                    isChecked = atoi((char*)colon);
                    if ( /* amit to do mmi_jsr_check_msg_id(msgId) */ 1 == TRUE)
                    {
                        mmi_jsr_insert_msg_info_to_list(&msg_list, msgId, isChecked);
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
                    mmi_jsr_insert_appid_info_to_list(&g_jsr_appid_object_list, appid_string, msg_list);
                }
                else
                {
                    if (appid_string)
                    {
                        umms_free(appid_string);
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
    U8 filename[JSR_FILENAME_LEN_MMA];
    U8 orig_file[JSR_FILENAME_LEN_MMA];
    S8 *buff = NULL;
    U32 buf_size = 0;
    U32 filesize = 0;
    U32 datalen = 0;
    int filehandle = -1;
    U32 written = 0;
    S32 result = -1;
    jsr_appid_msgid_list *appid_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jsr_appid_object_list == NULL)
    {
        memset(orig_file, 0, JSR_FILENAME_LEN_MMA);
        MAKE_JSR_APPID_LIST_FILE(orig_file);
        FS_Delete((U16*) orig_file);
        return FALSE;
    }

    filesize = mmi_jsr_get_current_size_of_object_list(g_jsr_appid_object_list, &buf_size);
    ASSERT(filesize);

    memset(orig_file, 0, JSR_FILENAME_LEN_MMA);
    MAKE_JSR_APPID_LIST_FILE(orig_file);

    memset(filename, 0, JSR_FILENAME_LEN_MMA);
    MAKE_APPID_LIST_FILE_TMP(filename);

    FS_Delete((U16*) filename);

    filehandle = FS_Open((U16*) filename, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (filehandle < 0)
    {
        return FALSE;
    }

    buff = (S8*) umms_malloc(sizeof(S8) * buf_size + 1);
    ASSERT(buff);
    appid_list = g_jsr_appid_object_list;
    while (appid_list)
    {
        ASSERT(appid_list->appId);
        {
            datalen = 0;
            sprintf((char*)buff, "%s\r\n", appid_list->appId);
            datalen = strlen((char*)appid_list->appId) + 2;
            result = FS_Write(filehandle, buff, datalen, &written);
            if (result < 0)
            {
                FS_Close(filehandle);
                umms_free(buff);
                return FALSE;
            }
        }
        ASSERT(appid_list->msgs);
        {
            jsr_msg_info *msg_list = appid_list->msgs;

            datalen = 0;
            while (msg_list)
            {
                sprintf((char*)(buff + datalen), "%d:%1d", msg_list->msgId, msg_list->is_checked);
                datalen += mmi_jsr_get_digit_of_integer(msg_list->msgId) + 2;
                if (msg_list->next)
                {
                    sprintf((char*)(buff + datalen), ",");
                    datalen += 1;
                }
                msg_list = msg_list->next;
            }
            sprintf((char*)(buff + datalen), "\r\n*\r\n");
            datalen += 5;
            ASSERT(buf_size >= datalen);
            result = FS_Write(filehandle, buff, datalen, &written);
            if (result < 0)
            {
                FS_Close(filehandle);
                umms_free(buff);
                return FALSE;
            }
        }
        appid_list = appid_list->next;
    }
    FS_Close(filehandle);
    umms_free(buff);
    FS_Delete((U16*) orig_file);
    FS_Rename((U16*) filename, (U16*) orig_file);
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_insert_appid_info_to_list
 * DESCRIPTION
 *  Insert the application info to application object list.
 * PARAMETERS
 *  appid_object_list       [IN]        
 *  string                  [?]         [?]         [?]         [?]
 *  msg_list                [?]         [?]         [?]         [?]
 * RETURNS
 *  MMI_BOOL result
 *****************************************************************************/
MMI_BOOL mmi_jsr_insert_appid_info_to_list(
            jsr_appid_msgid_list **appid_object_list,
            S8 *string,
            jsr_msg_info *msg_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jsr_appid_msgid_list *node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (appid_object_list == NULL)
    {
        return FALSE;
    }
    node = (jsr_appid_msgid_list*) umms_malloc(sizeof(jsr_appid_msgid_list));
    memset(node, 0, sizeof(jsr_appid_msgid_list));
    ASSERT(node);
    node->appId = (S8*) umms_malloc(strlen((S8*) string) + 1);
    ASSERT(node->appId);
    strcpy((S8*) node->appId, (S8*) string);
    node->msgs = msg_list;
    if (*appid_object_list == NULL)
    {
        node->prev = node;
        *appid_object_list = node;
        return TRUE;
    }
    else
    {
        jsr_appid_msgid_list *tempnode = *appid_object_list;

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
 *  list        [IN]        
 *  appId       [?]         [?]         [?]         [?]
 * RETURNS
 *  MMI_BOOL result
 *****************************************************************************/
MMI_BOOL mmi_jsr_remove_appid_info_from_list(jsr_appid_msgid_list **list, S8 *appId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jsr_appid_msgid_list *appid_list;

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
        if ((appid_list->appId) && (appId) && (strcmp((S8*) appid_list->appId, (S8*) appId) == 0))
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
            umms_free(appid_list->appId);
            mmi_jsr_remove_msg_info_from_list_recursive(&(appid_list->msgs));
            umms_free(appid_list);
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
MMI_BOOL mmi_jsr_remove_appid_info_from_list_recursive(jsr_appid_msgid_list **list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jsr_appid_msgid_list *appid_list;
    jsr_appid_msgid_list *appid_list_temp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((list == NULL) || (*list == NULL))
    {
        return FALSE;
    }

    appid_list = *list;
    while (appid_list)
    {
        appid_list_temp = appid_list->next;
        umms_free(appid_list->appId);
        mmi_jsr_remove_msg_info_from_list_recursive(&(appid_list->msgs));
        umms_free(appid_list);
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
 *  msgId           [IN]        
 *  ischecked       [IN]        
 * RETURNS
 *  MMI_BOOL result
 *****************************************************************************/
MMI_BOOL mmi_jsr_insert_msg_info_to_list(jsr_msg_info **msg_list, U32 msgId, U8 ischecked)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jsr_msg_info *node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL)
    {
        return FALSE;
    }
    node = (jsr_msg_info*) umms_malloc(sizeof(jsr_msg_info));
    memset(node, 0, sizeof(jsr_msg_info));
    ASSERT(node);
    node->msgId = msgId;
    node->is_checked = ischecked;
    if (*msg_list == NULL)
    {
        node->prev = node;
        *msg_list = node;
        return TRUE;
    }
    else
    {
        jsr_msg_info *tempnode = *msg_list;

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
 *  msgId       [IN]        
 * RETURNS
 *  MMI_BOOL result
 *****************************************************************************/
MMI_BOOL mmi_jsr_remove_msg_info_from_list(jsr_msg_info **list, U32 msgId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jsr_msg_info *msg_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((list == NULL) || (*(list) == NULL))
    {
        return FALSE;
    }

    msg_list = *list;

    while (msg_list)
    {
        if (msg_list->msgId == msgId)
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
            umms_free(msg_list);
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
MMI_BOOL mmi_jsr_remove_msg_info_from_list_recursive(jsr_msg_info **list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jsr_msg_info *msg_list;
    jsr_msg_info *msg_list_temp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((list == NULL) || (*(list) == NULL))
    {
        return FALSE;
    }

    msg_list = *list;
    while (msg_list)
    {
        msg_list_temp = msg_list->next;
        umms_free(msg_list);
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
 *  msgId       [IN]        
 * RETURNS
 *  U32 length
 *****************************************************************************/
U32 mmi_jsr_get_digit_of_integer(U32 msgId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buff[16];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((S8*) buff, "%d", msgId);
    return strlen((S8*) buff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_get_current_size_of_object_list
 * DESCRIPTION
 *  Calculates the current size of application object list.
 * PARAMETERS
 *  appid_object_list       [?]     [?]     [?]     [?]
 *  max_chrs_in_line        [?]     [?]     [?]     [?]
 * RETURNS
 *  U32 size
 *****************************************************************************/
U32 mmi_jsr_get_current_size_of_object_list(jsr_appid_msgid_list *appid_object_list, U32 *max_chrs_in_line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 sum = 0;
    U32 chrs = 0;
    U32 max_chrs = 0;
    jsr_appid_msgid_list *appid_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *(max_chrs_in_line) = 0;

    if (appid_object_list == NULL)
    {
        return 0;
    }

    appid_list = appid_object_list;

    while (appid_list)
    {
        if (appid_list->appId)
        {
            chrs = strlen((S8*) appid_list->appId) + 2; /* appid string+\r\n */
            sum += chrs;
            if (chrs > max_chrs)
            {
                max_chrs = chrs;
            }
        }
        chrs = 0;
        if (appid_list->msgs)
        {
            jsr_msg_info *msg_list = appid_list->msgs;

            while (msg_list)
            {
                /* msgid:isChecked */
                chrs += (mmi_jsr_get_digit_of_integer(msg_list->msgId) + 2);
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
 *  buffer          [?]         [?]         [?]         [?]
 *  buf_length      [IN]        
 *  line_length     [?]         [?]         [?]         [?]
 *  ret             [?]         [?]         [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_read_line_from_file(U32 filehandle, S8 *buffer, U32 buf_length, U32 *line_length, S32 *ret)
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
    memset(buffer, 0, buf_length);
    *line_length = 0;

    while (buf_length)
    {
        *ret = FS_Read(filehandle, pos, 1, &rd_no);
        if (*ret < 0)
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
    *ret = -1;
    *line_length = rd_no;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_check_appId
 * DESCRIPTION
 *  Checks whether the application is registered or not.
 * PARAMETERS
 *  appId       [?]     [?]     [?]     [?]
 * RETURNS
 *  MMI_BOOL result
 *****************************************************************************/
MMI_BOOL mmi_jsr_check_appId(S8 *appId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < JSR_MAX_APP_ID_NUM; i++)
    {
        if (jsr_appid_db[i] && jsr_appid_db[i]->appId && (strcmp((S8*) jsr_appid_db[i]->appId, (S8*) appId) == 0))
        {
            return TRUE;
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_post_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MOD_SRC         [IN]        
 *  MOD_DEST        [IN]        
 *  MSG_SAP         [IN]        
 *  MSG_ID          [IN]        
 *  LOCAL           [?]         [?]         [?]
 *  PEER            [?]         [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_post_message(
        module_type MOD_SRC,
        module_type MOD_DEST,
        U8 MSG_SAP,
        const U16 MSG_ID,
        void *LOCAL,
        void *PEER)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_SRC;
    Message.oslDestId = MOD_DEST;
    Message.oslSapId = MSG_SAP;
    Message.oslMsgId = MSG_ID;
    Message.oslDataPtr = LOCAL;
    Message.oslPeerBuffPtr = PEER;
    OslMsgSendExtQueue(&Message);
}

//Testing Stubs start
//wap_mmc_read_folder_status_req_ind_struct folder_status;
//wap_mmc_recv_appmms_rsp_struct recv_struct;
//wap_mmc_delete_msg_req_ind_struct delete_struct;

/* wap_mmc_upload_msg_req_ind_struct upload_struct; */


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_check_recv_mms_for_java
 * DESCRIPTION
 *  Check if the message is a java message and send indication to java task.
 * PARAMETERS
 *  contentType     [?]     [?]     [?]     [?]         [?]
 *  msgId(?)        [IN](?)(?)(?)
 *  char* appId(?)(?)(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_jsr_check_recv_mms_for_java(S8 *contentType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *str_pos = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((contentType == NULL) || ((str_pos = strstr(contentType, "application-id")) == NULL))
    {
        return FALSE;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_is_java_msg
 * DESCRIPTION
 *  Checks whether the message is a Java message or not.
 * PARAMETERS
 *  msgId       [IN]        
 * RETURNS
 *  MMI_BOOL result
 *****************************************************************************/
MMI_BOOL mmi_jsr_is_java_msg(U32 msgId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jsr_appid_object_list == NULL)
    {
        mmi_jsr_read_object_list_from_file();
    }
    if (g_jsr_appid_object_list)
    {
        jsr_appid_msgid_list *appid_list = g_jsr_appid_object_list;

        while (appid_list)
        {
            if (appid_list->msgs)
            {
                jsr_msg_info *msg_list = appid_list->msgs;

                while (msg_list)
                {
                    if (msg_list->msgId == msgId)
                    {
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


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_init_appid_msgid_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_init_appid_msgid_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jsr_appid_object_list == NULL)
    {
        mmi_jsr_read_object_list_from_file();
    }
}

#if 1


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_get_active_mms_attachment_req
 * DESCRIPTION
 *  MSG_ID_MMS_GET_ACTIVE_MMS_ATTACHMENT_REQ
 * PARAMETERS
 *  in_msg      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_get_active_mms_attachment_req(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_get_attachment_req_struct *msg_req;
    mms_get_attachment_rsp_struct *msg_rsp;
    mmi_mv_attachment_info_struct *attachment_list = NULL;
    mmi_mv_attachment_info_struct *temp;
    mmi_mv_object_struct *object_info = NULL;
    U32 num_attachment;

    FS_HANDLE file_handle;
    U16 *object_file = NULL;
    S8 *file_path = NULL;
    MMI_BOOL result;
    MMI_BOOL is_install;
    U8 flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __J2ME__
    is_install = (MMI_BOOL)mmi_java_is_installing();
#else
    is_install = MMI_FALSE;
#endif

    if(is_install)
    {
    JsrCleanContext();
    msg_req = (mms_get_attachment_req_struct*) in_msg;

     mmi_mv_get_attachment_list(&attachment_list, &num_attachment);

    if (num_attachment < 2)
    {
        goto SEND_RSP;
    }

    if (attachment_list != NULL)
    {
        U8 count = 0;

        temp = attachment_list;

        for (count = 0; count < num_attachment; count++)
        {
            object_info = temp->object;

            /* Check for the required file */
            if (mmi_ucs2cmp((S8*) msg_req->filename, (S8*) object_info->file_name) == 0)
            {
                /* File name matched. Set the result as 1. */
                flag = 1;
                break;
            }
            /* Move to the next attachment information node */
            temp = temp->next;
        }
        /* If the required file not found */
        if (flag == 0)
        {
            goto SEND_RSP;
        }
    }
    else
    {
        goto SEND_RSP;
    }

    if (object_info->is_virtual_file)
    {
        object_file = (U16*) umms_malloc(MMI_MV_VFN_NUM_OF_WCHAR*ENCODING_LENGTH);
        file_handle = FS_Open(object_info->file_path, FS_READ_ONLY | FS_OPEN_SHARED);
        MMI_ASSERT(file_handle > 0);

        FS_GenVirtualFileName(
            file_handle,
            object_file,
            (unsigned int)FS_GenVFN_SIZE,
            object_info->offset,
            object_info->size);

        result = mmi_jsr_get_file_name(&file_path,(S8*)object_info->file_name);
        
        if(MMI_FALSE == result)
        {
            goto SEND_RSP;
        }
        FS_Delete((U16*)file_path);
        JSR_CNTX->file_handle = file_handle;
        JSR_CNTX->file_path = file_path;
        JSR_CNTX->object_file = object_file;
        
        
            if(!mmi_umms_is_in_call())
            {
                mmi_umms_set_progress_scr_id(UMMS_SCR_ID_PLEASE_WAIT);
                mmi_umms_progress_screen(); 
            }
       
        mmi_fmgr_send_copy_req(
            FMGR_ACTION_COPY,
            (U8*) object_file,
            (U8*) file_path,
            mmi_jsr_file_copy_callback);
        return;
    }
    else
    {
        msg_rsp = (mms_get_attachment_rsp_struct*) OslConstructDataPtr(sizeof(mms_get_attachment_rsp_struct));
        msg_rsp->result = 1;
        mmi_ucs2cpy((S8*) msg_rsp->filepath, (S8*) object_info->file_path);
        mmi_jsr_post_message(MOD_MMI, MOD_J2ME, 0, MSG_ID_MMS_GET_ACTIVE_MMS_ATTACHMENT_RSP, (oslParaType*) msg_rsp, NULL);
        return;
    }
    }
  SEND_RSP:
    msg_rsp = (mms_get_attachment_rsp_struct*) OslConstructDataPtr(sizeof(mms_get_attachment_rsp_struct));
    msg_rsp->result = 0;
    mmi_jsr_post_message(MOD_MMI, MOD_J2ME, 0, MSG_ID_MMS_GET_ACTIVE_MMS_ATTACHMENT_RSP, (oslParaType*) msg_rsp, NULL);
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_file_copy_callback
 * DESCRIPTION
 *  Temporary File Save response handling and send
 *  MSG_ID_MMS_GET_ACTIVE_MMS_ATTACHMENT_RSP
 * PARAMETERS
 *  msg     [IN]        Variable stores the result of copy
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_file_copy_callback(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_copy_rsp_strcut *msgPtr;
    mms_get_attachment_rsp_struct *msg_rsp;
       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgPtr = (mmi_fmt_copy_rsp_strcut*) msg;
    msg_rsp = (mms_get_attachment_rsp_struct*) OslConstructDataPtr(sizeof(mms_get_attachment_rsp_struct));
    if (msgPtr->result >= 0)
    {
        mmi_ucs2cpy((S8*) msg_rsp->filepath, (S8*) JSR_CNTX->file_path);
        msg_rsp->result = 1;
    }
    else
    {
        msg_rsp->result = 0;
    }

    mmi_jsr_post_message(MOD_MMI, MOD_J2ME, 0, MSG_ID_MMS_GET_ACTIVE_MMS_ATTACHMENT_RSP, (oslParaType*) msg_rsp, NULL);
    JsrCleanContext();   
    DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
    if(SCR_ID_UMMS_PROGRESS == GetActiveScreenId())
    {
        GoBackHistory();
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_get_file_name
 * DESCRIPTION
 *  To generate temp Object File Name
 * PARAMETERS
 *  file_path       [IN]        
 *  file_name       [IN]      
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_jsr_get_file_name(S8 **const file_path, S8 const *const file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 path_buf[(FMGR_MAX_PATH_LEN + 1)] = {0};
    U32 fpath_len = 0;
    S32 fsHandle = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(path_buf, "%c:\\%s\\", MMI_PUBLIC_DRV, JSR_FOLDER_NAME);

    fsHandle = FS_Open((WCHAR*) path_buf, FS_READ_ONLY | FS_OPEN_SHARED | FS_OPEN_DIR);
    if (fsHandle <= 0)
    {
        if (FS_CreateDir(path_buf) < 0)
        {
            return MMI_FALSE;
        }
    }
    else
    {
        FS_Close(fsHandle);
    }

    mmi_ucs2cat((PS8) path_buf, (PS8) ATTACHMENT_FILE);
    fpath_len = (mmi_ucs2strlen((S8*) path_buf) + 1) * ENCODING_LENGTH;
    *file_path = (S8*) umms_malloc(fpath_len);
    if (*file_path == NULL)
    {
        return MMI_FALSE;
    }

    mmi_ucs2cpy((S8*) * file_path, (S8*) path_buf);
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_init_jsr_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_init_jsr_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    S32 result;
    U8 folder_path[MMA_MAX_INTERNAL_FILENAME_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(folder_path, 0, MMA_MAX_INTERNAL_FILENAME_LENGTH);
    MMI_UMMS_MAKE_JSR_FOLDER_PATH(folder_path);
    
    /* if the dir exists, delete it */
    file_handle = FS_Open((WCHAR*)folder_path, FS_OPEN_DIR | FS_READ_ONLY);
    if (file_handle >= 0)
    {            
        FS_Close(file_handle);

        FS_XDelete((WCHAR*)folder_path, 
           FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, 
           NULL, 
           0);
    }
    
    result = FS_CreateDir((WCHAR*)folder_path);
    
    if (result < 0)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[MMSJSR205.c] mmi_umms_init_jsr_folder Create DIR FAIL! *\n");
    }

    FS_SetAttributes((unsigned short*)folder_path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
}

#endif /* 1 */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_testing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_testing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
              /*    wap_mmc_upload_msg_req_ind_struct upload_struct;
           //       mmi_ucs2cpy(upload_struct.filePath,"D\0:\0\\\0t\0e\0m\0p\0.\0m\0");
                 mmi_ucs2cpy((S8*)upload_struct.filePath,(S8*)"D\0:\0\\\0t\0e\0s\0t\0.\0m\0m\0s"); 
                  mmi_jsr_upload_msg_req_hldr(&upload_struct);*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* pre_mmi_jsr_get_msg_content_req(); */
    //{
//        wap_mmc_read_folder_status_req_ind_struct Message;

//        Message.folderId = JSR_INBOX;
//        Message.retrievalMode = JSR_FULL;
//        mmi_jsr_read_folder_status_req_hldr(&Message);
        
//		wap_mmc_upload_msg_req_ind_struct upload_struct;
//		mmi_ucs2cpy((S8*)upload_struct.filePath,(S8*)"C\0:\0\\\0t\0e\0m\0p\0.\0m\0");
//		mmi_jsr_upload_msg_req_hldr(&upload_struct);

//	mmi_jsr_um_refresh_ind(JSR_DRAFTS);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef MMS_IN_LARGE_STORAGE
/* under construction !*/
/* under construction !*/
#else /* MMS_IN_LARGE_STORAGE */ 
/* under construction !*/
#endif /* MMS_IN_LARGE_STORAGE */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef MMS_IN_LARGE_STORAGE
/* under construction !*/
    #else 
/* under construction !*/
    #endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* Testing Stubs end. */
#endif /* defined(MMS_SUPPORT) */ 
#endif /* __MMI_MMS_2__ */ 


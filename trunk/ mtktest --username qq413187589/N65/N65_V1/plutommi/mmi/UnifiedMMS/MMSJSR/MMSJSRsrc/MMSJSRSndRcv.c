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
 * MMSJSRSndRcv.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "MMI_include.h"

#ifdef __MMI_MMS_2__
/*  Include: MMI header file */
#if defined(MMS_SUPPORT)

#include "ProtocolEvents.h"

#include "MMSJsrTypes.h"
#include "MMSJsrProts.h"
#include "UnifiedMessageGProt.h"
#include "UCS2Prot.h"

#include "wapadp.h"
#include "mmsadp.h"
#include "wap_ps_struct.h"
#include "app_mine.h"
#include "MMSJSRSndRcv.h"
#include "app_asyncfile.h"
#include "Conversions.h"
#include "MMSAppGprot.h"

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/
mmi_umms_xml_msg_struct g_jsr_mms_xml_msg;

/* static mmi_umms_xml_msg_struct *g_jsr_mms_xml_msg = &g_jsr_mms_xml_msg_struct; */
static U8 convert_jsr_priority_to_mma(U8 priority);

/***************************************************************************** 
* Local Function
*****************************************************************************/
void *jsr_decoder_mem_alloc(U32 bytes);
void jsr_decoder_mem_free(void *ptr);
void mmi_jsr_fill_header(wap_mmc_recv_appmms_rsp_struct *resp, S8 **buffer, U32 *buf_size);
void mmi_jsr_reset_xml_struct_msg(void);

/*****************************************************************************
* Global Variable
*****************************************************************************/
/* jsr_context_struct jsr_cntx; */
extern jsr_context_struct *jsr_cntx_p;
extern jsr_appid_msgid_list *g_jsr_appid_object_list;


MMI_BOOL mmi_umms_jsr_generate_recv_msg_body_part(
            U32 msgId,
            U8 *bdy_part_no,
            U8 total_objects,
            wap_mmc_read_appmms_msg_part_rsp_struct *response);
/*****************************************************************************
* Global Function
*****************************************************************************/
extern int mmi_charset_utf8_to_ucs2_length_in_bytes(const kal_uint8 *raw);

/* [START Send/Receive functioanlity] */


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_send_appmms_req_hldr
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_SEND_APPMMS_REQ primitive to Java
 * PARAMETERS
 *  msg             [?]         [?]         [?]         [?]
 *  not_used        [IN]        
 *  ilm_p           [?]         [?]
 *  mod_src(?)      [IN](?)
 *  peerBuf     [?]         [?](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_send_appmms_req_hldr(void *msg, int not_used, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_send_appmms_req_struct *Message;
    U16 buffer_length = 0;
    U8 *pdu = NULL;
    peer_buff_struct *peer_ptr = ((ilm_struct*) ilm_p)->peer_buff_ptr;
    JsrResult result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = (wap_mmc_send_appmms_req_struct*) msg;

    if (JSR_CNTX->state != JSR_STATE_IDLE)
    {
        mmi_jsr_send_appmms_rsp(JSR_RESULT_BUSY);
    }
    else
    {
        JsrCleanContext();  /* clean context first */
        memset(&g_jsr_mms_xml_msg, 0, sizeof(g_jsr_mms_xml_msg));       /* reset global buff for MMS data */

        JSR_CNTX->op = JSR_OP_SEND_MSG;
        JSR_CNTX->state = JSR_STATE_PROCESS_SEND_MSG_HDR;
        JSR_CNTX->total_media_obj_no = Message->bdy_part_no;
        JSR_CNTX->curr_media_obj_no = 0;

        pdu = (U8*) get_pdu_ptr(peer_ptr, &buffer_length);  /* system call */
        result = mmi_jsr_decode_mms_header(Message, pdu);   /* retrive header info */
        if (result != JSR_RESULT_OK)
        {
            mmi_jsr_send_appmms_rsp(JSR_RESULT_ERROR_FAIL_TO_GEN_MMS_HDR);
        }
        else
        {
            if ((JSR_CNTX->curr_media_obj_no) < (JSR_CNTX->total_media_obj_no))
            {   /* if more media then get all media first */
                JSR_CNTX->state = JSR_STATE_PROCESS_SEND_MSG_BDY;
                mmi_jsr_send_post_appmms_msg_part_ind(JSR_RESULT_OK);
            }
            else
            {   /* prepare XML fiel and then create MMS to be send */
                kal_wchar xml_file_path[MMA_MAX_INTERNAL_FILENAME_LENGTH];

                memset(xml_file_path, 0, MMA_MAX_INTERNAL_FILENAME_LENGTH * ENCODING_LENGTH);
                /* mmi_jsr_send_appmms_rsp(JSR_RESULT_OK); */
                MAKE_JSR_XML_FILE(xml_file_path);

                mmi_umms_create_mms_xml_description_file(&g_jsr_mms_xml_msg, (U8*) xml_file_path);     /* call extern funciton to make XML */
                mmi_jsr_create_mms_req();   /* send request to MMA to create MMS */
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

void mmi_jsr_send_appmms_rsp(JsrResult result)
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
    
    if (result != JSR_RESULT_BUSY)
    {
    if (JSR_CNTX->msgId != 0)
    {
        mmi_jsr_delete_msg_req(0, JSR_CNTX->msgId);
    }
    else
    {
        JsrCleanContext();  /* Clean the Jsr Context */
    }
    mmi_umms_reset_mms_sending_busy();
    mmi_jsr_reset_xml_struct_msg();
}
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
void mmi_jsr_send_post_appmms_msg_part_ind(JsrResult result)
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
 *  msg     [?]     [?]     [?]     [?]
 *  U8 result(?)(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_send_post_appmms_msg_part_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JsrResult result = JSR_RESULT_OK;
    wap_mmc_post_appmms_msg_part_res_struct *Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (JSR_CNTX->state != JSR_STATE_PROCESS_SEND_MSG_BDY)
    {
        mmi_jsr_send_appmms_rsp(JSR_RESULT_ACCESS_DENY);
        return;
    }
    Message = (wap_mmc_post_appmms_msg_part_res_struct*) msg;
    result = mmi_jsr_add_media_object(Message); /* add media object to MMS message */
    if (result != JSR_RESULT_OK)
    {
        mmi_jsr_send_appmms_rsp(result);
        return;
    }

    /* increment current media object by 1 */
    JSR_CNTX->curr_media_obj_no = JSR_CNTX->curr_media_obj_no + 1;
    if ((JSR_CNTX->curr_media_obj_no) < (JSR_CNTX->total_media_obj_no))
    {
        JSR_CNTX->state = JSR_STATE_PROCESS_SEND_MSG_BDY;
        mmi_jsr_send_post_appmms_msg_part_ind(JSR_RESULT_OK);
    }
    else
    {
        kal_wchar xml_file_path[MMA_MAX_INTERNAL_FILENAME_LENGTH];

        memset(xml_file_path, 0, MMA_MAX_INTERNAL_FILENAME_LENGTH * ENCODING_LENGTH);
        /* mmi_jsr_send_appmms_rsp(JSR_RESULT_OK); */
        MAKE_JSR_XML_FILE(xml_file_path);

        mmi_umms_create_mms_xml_description_file(&g_jsr_mms_xml_msg, (U8*) xml_file_path);
        mmi_jsr_create_mms_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_create_mms_req
 * DESCRIPTION
 *  This function send the request to MMA to generate MMS, for which it sends the content of MMS in XML
 *  format.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_create_mms_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_create_req_struct *msg_req;
    peer_buff_struct *peer_buff_ptr;
    U32 read_size;
    U16 peer_buff_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_req = (wap_mma_create_req_struct*) OslConstructDataPtr(sizeof(wap_mma_create_req_struct));
    msg_req->req_id = wap_mma_get_request_id();
    JSR_CNTX->req_id = msg_req->req_id;

    msg_req->mode = MMA_MODE_RAW; 
    msg_req->msg_id = 0;
    msg_req->app_id = MMA_APP_ID_JSR;

    MAKE_JSR_XML_FILE(msg_req->xml_filepath);   /* get xml file path */
    msg_req->xml_size = applib_get_file_size(msg_req->xml_filepath);    /* get xml file size */
    JSR_CNTX->xml_file_size = msg_req->xml_size;
    msg_req->buffer_index = JSR_CNTX->buffer_index = 0;

    if (msg_req->xml_size <= MMI_UMMS_MAX_XML_SIZE_IN_PEER_BUFFER)
    {   /* if xml size is less then MAX permissible size */
        msg_req->buffer_size = msg_req->xml_size;
        msg_req->more = FALSE;
    }
    else
    {   /* xml size is greater then permissible size, then send MAX size first */
        msg_req->buffer_size = MMI_UMMS_MAX_XML_SIZE_IN_PEER_BUFFER;
        msg_req->more = TRUE;
    }

    peer_buff_ptr = construct_peer_buff((kal_uint16) msg_req->buffer_size, 0, 0, TD_CTRL);

    JSR_CNTX->file_handle = FS_Open(msg_req->xml_filepath, FS_READ_ONLY);
    if (JSR_CNTX->file_handle < 0)
    {
        mmi_jsr_send_appmms_rsp(JSR_RESULT_FILE_OPERATION_ERROR);
        return;
    }

    if (FS_Read(
            JSR_CNTX->file_handle,
            get_pdu_ptr(peer_buff_ptr, &peer_buff_len),
            msg_req->buffer_size,
            &read_size) != FS_NO_ERROR || read_size != msg_req->buffer_size)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[MMSTemplates.c] mmi_umms_create_mms_req read_size=%d buf_size=%d*\n",
                             read_size, msg_req->buffer_size);
		mmi_jsr_send_appmms_rsp(JSR_RESULT_FILE_OPERATION_ERROR);
        return;
    }

    mmi_jsr_post_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_CREATE_REQ, (oslParaType*) msg_req, peer_buff_ptr);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_create_for_send_mms_rsp
 * DESCRIPTION
 *  This function is response handler for create request
 * PARAMETERS
 *  inMsg       [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_create_for_send_mms_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_create_rsp_struct *msg_rsp = (wap_mma_create_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_rsp->req_id == JSR_CNTX->req_id);

    if(JSR_CNTX->op != JSR_OP_SEND_MSG)
    {
        return;
    }
    if (msg_rsp->result != MMA_RESULT_OK)
    {
        mmi_jsr_send_appmms_rsp(JSR_RESULT_ERROR_SEND_CANCEL_BY_SYSTEM);
    }
    else
    {
        if (msg_rsp->msg_id == 0)
        {   /* No message id and hence more XML content needs to send */
            wap_mma_create_req_struct *msg_req;
            peer_buff_struct *peer_buff_ptr;
            U32 read_size;
            S32 remaining_size;
            U16 peer_buff_len = 0;

            MMI_ASSERT(msg_rsp->buffer_index == JSR_CNTX->buffer_index + 1);
            msg_req = (wap_mma_create_req_struct*) OslConstructDataPtr(sizeof(wap_mma_create_req_struct));
            msg_req->req_id = JSR_CNTX->req_id;
            msg_req->app_id = MMA_APP_ID_JSR;

            /* reset */
            msg_req->mode = MMA_MODE_RAW;
            msg_req->msg_id = 0;

            MAKE_JSR_XML_FILE(msg_req->xml_filepath);
            msg_req->xml_size = JSR_CNTX->xml_file_size;

            JSR_CNTX->buffer_index++;
            msg_req->buffer_index = JSR_CNTX->buffer_index;

            remaining_size = JSR_CNTX->xml_file_size - (msg_req->buffer_index * MMI_UMMS_MAX_XML_SIZE_IN_PEER_BUFFER);

            if (remaining_size <= MMI_UMMS_MAX_XML_SIZE_IN_PEER_BUFFER)
            {
                msg_req->buffer_size = remaining_size;
                msg_req->more = KAL_FALSE;
            }
            else
            {
                msg_req->buffer_size = MMI_UMMS_MAX_XML_SIZE_IN_PEER_BUFFER;
                msg_req->more = KAL_TRUE;
            }

            peer_buff_ptr = construct_peer_buff((kal_uint16) msg_req->buffer_size, 0, 0, TD_CTRL);

            if (FS_Read
                (JSR_CNTX->file_handle, get_pdu_ptr(peer_buff_ptr, &peer_buff_len), msg_req->buffer_size,
                 &read_size) != FS_NO_ERROR || read_size != msg_req->buffer_size)
            {
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                     "*[MMSTemplate.c] mmi_umms_create_mms_rsp read_size=%d buf_size=%d*\n",
                                     read_size, msg_req->buffer_size);
				mmi_jsr_send_appmms_rsp(JSR_RESULT_ERROR_SEND_CANCEL_BY_SYSTEM);
				return;
            }

            mmi_jsr_post_message(
                MOD_MMI,
                MOD_WAP,
                0,
                MSG_ID_WAP_MMA_CREATE_REQ,
                (oslParaType*) msg_req,
                peer_buff_ptr);
        }
        /* sending XML content completes */
        else
        {
            FS_Close(JSR_CNTX->file_handle);
            JSR_CNTX->file_handle = 0;
            JSR_CNTX->msgId = msg_rsp->msg_id;
            /* mmi_jsr_reset_xml_struct_msg(); */
            mmi_jsr_send_msg_req((U16) JSR_CNTX->msgId);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_send_msg_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_send_msg_req(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_send_req_struct *msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JSR_CNTX->req_id = wap_mma_get_request_id();
	JSR_CNTX->state = JSR_STATE_SEND_MSG;

    msg_req = (wap_mma_send_req_struct*) OslConstructDataPtr(sizeof(wap_mma_send_req_struct));
    msg_req->req_id = JSR_CNTX->req_id;

    msg_req->app_id = MMA_APP_ID_JSR;
    msg_req->msg_id = msg_id;

    msg_req->send_and_save = KAL_FALSE;
    msg_req->box = 0;

    mmi_umms_set_mms_sending_busy();

    mmi_jsr_post_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_SEND_REQ, (oslParaType*) msg_req, NULL);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_send_msg_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_send_msg_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_send_rsp_struct *msg_rsp = (wap_mma_send_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_rsp->req_id == JSR_CNTX->req_id);
    if (msg_rsp->result != JSR_RESULT_OK)
    {
        mmi_jsr_send_appmms_rsp(JSR_RESULT_ERROR_SEND_CANCEL_BY_SYSTEM);
    }
    else
    {
        mmi_jsr_send_appmms_rsp(msg_rsp->result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_decode_mms_header
 * DESCRIPTION
 *  
 * PARAMETERS
 *  message     [?]     [?]     [?]     [?]     [?]
 *  buffer      [?]     [?]     [?]     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
JsrResult mmi_jsr_decode_mms_header(wap_mmc_send_appmms_req_struct *message, U8 *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 datalen = 0;
    U32 eRet = JSR_RESULT_OK;

    S8 *address = NULL;
    S8 *temp_address = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_jsr_mms_xml_msg, 0, sizeof(mmi_umms_xml_msg_struct));

    if (message->delivery_time > 604800)
    {
        eRet = JSR_RESULT_ERROR;
        goto END;
    }
    g_jsr_mms_xml_msg.background_color = MMI_UMMS_DEFAULT_BG_COLOR;
    g_jsr_mms_xml_msg.foreground_color = MMI_UMMS_DEFAULT_FG_COLOR;
    g_jsr_mms_xml_msg.to_num = message->to_addr_no;
    g_jsr_mms_xml_msg.cc_num = message->cc_addr_no;
    g_jsr_mms_xml_msg.bcc_num = message->bcc_addr_no;
    g_jsr_mms_xml_msg.total_object_num = message->bdy_part_no;
    g_jsr_mms_xml_msg.total_slide_num = 0; //g_jsr_mms_xml_msg.total_object_num;
    g_jsr_mms_xml_msg.priority = convert_jsr_priority_to_mma(message->priority);
    g_jsr_mms_xml_msg.delivery_time = message->delivery_time;
    mmi_asc_to_ucs2((PS8) g_jsr_mms_xml_msg.java_app_id, (PS8) message->app_id);
    mmi_asc_to_ucs2((PS8) g_jsr_mms_xml_msg.java_reply_app_id, (PS8) message->reply_app_id);

    g_jsr_mms_xml_msg.to_head = NULL;
    g_jsr_mms_xml_msg.cc_head = NULL;
    g_jsr_mms_xml_msg.bcc_head = NULL;
    g_jsr_mms_xml_msg.from = NULL;

    g_jsr_mms_xml_msg.read_report = DEFAULT_READ_REPORT_DURING_SENDING;
    g_jsr_mms_xml_msg.delivery_report = DEFAULT_DELIVERY_REPORT_DURING_SENDING;

    g_jsr_mms_xml_msg.expiry_time = DEFAULT_EXPIRY_TIME;
    g_jsr_mms_xml_msg.sender_visibility = DEFAULT_SENDER_VISIBILTY;
    
    if (buffer != NULL)
    {   /* Retrieve Subject */
        {
            S8 *subject = NULL;
            U32 subject_len_ucs2 = 0;
            U32 subject_len = *(U32*) buffer;

            if (subject_len > 0)
            {   /* there is some subject, cal length and then copy it after converting */
                subject = (S8*) umms_malloc(subject_len + 1);
                memset(subject, 0, subject_len + 1);
                if (NULL == subject)
                {
                    eRet = JSR_RESULT_INSUFFICIENT_MEMORY;
                    goto END;
                }

                memcpy(subject, buffer + 8, subject_len);
                datalen = subject_len + 8;
                subject_len_ucs2 = mmi_charset_utf8_to_ucs2_length_in_bytes((U8*) subject);

                if (subject_len_ucs2 > MMI_UMMS_MAX_SUBJECT_LEN * 2)
                {
                    subject_len_ucs2 = MMI_UMMS_MAX_SUBJECT_LEN * 2;
                }

                // amit to check as earlier it was UT8 only
                //                              if (message->subject_encode_type == MMS_UTF8)
                {
                    /* convert subject form UTF8 to UC2 and copy it */
                    mmi_chset_utf8_to_ucs2_string(
                        (U8*) g_jsr_mms_xml_msg.subject,
                        (subject_len_ucs2 + ENCODING_LENGTH),
                        /* (MMI_UMMS_MAX_SUBJECT_LEN), */ (U8*) subject);
                }
                //                              else
                //                              {
                //                                      mmi_asc_to_ucs2((S8 *) g_jsr_mms_xml_msg.subject, (S8*) subject);
                //                              }

                if (subject != NULL)
                {
                    umms_free(subject);
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

            address = (S8*) umms_malloc(address_len + 1);
            memset(address, 0, address_len + 1);

            if (NULL == address)
            {
                eRet = JSR_RESULT_INSUFFICIENT_MEMORY;
                goto END;
            }

            memcpy(address, buffer + datalen + 8, address_len);
            datalen += address_len + 8;

            temp_address = (S8*) umms_malloc((address_len + 1) * ENCODING_LENGTH);
            memset(temp_address, 0, (address_len + 1) * ENCODING_LENGTH);

            if (NULL == temp_address)
            {
                eRet = JSR_RESULT_INSUFFICIENT_MEMORY;
                goto END;
            }

            mmi_asc_to_ucs2((PS8) temp_address, (PS8) address);

            // amit to do   if((MMI_FALSE == mmi_jsr_check_address_input_format((U8*)temp_address))
            //             &&(MMI_FALSE == mmi_jsr_check_number_input_format((U8*)temp_address)))
            //            {
            //                eRet = JSR_RESULT_INSUFFICIENT_MEMORY;
            //                goto END;
            //            }

            ret = mmi_jsr_add_address_in_addresse_list(temp_address, addrType, MMI_UMMS_ADDRESS_GROUP_TYPE_TO);
            if (ret != 0)
            {
                eRet = JSR_RESULT_INSUFFICIENT_MEMORY;
                goto END;
            }

            if (address != NULL)
            {
                umms_free(address);
                address = NULL;
            }
            if (temp_address != NULL)
            {
                umms_free(temp_address);
                temp_address = NULL;
            }

            message->to_addr_no--;
        }

        /* Retrieve cc addresses */
        while (message->cc_addr_no > 0)
        {
            U32 address_len = 0;
            U32 addrType = 0;
            U8 ret = 0;

            memcpy(&addrType, (char*)(buffer + datalen), 4);
            memcpy(&address_len, (char*)(buffer + datalen + 4), 4);

            address = (S8*) umms_malloc(address_len + 1);
            memset(address, 0, address_len + 1);
            if (NULL == address)
            {
                eRet = JSR_RESULT_INSUFFICIENT_MEMORY;
                goto END;
            }

            memcpy(address, buffer + datalen + 8, address_len);
            datalen += address_len + 8;

            temp_address = (S8*) umms_malloc((address_len + 1) * ENCODING_LENGTH);
            memset(temp_address, 0, (address_len + 1) * ENCODING_LENGTH);

            if (NULL == temp_address)
            {
                eRet = JSR_RESULT_INSUFFICIENT_MEMORY;
                goto END;
            }

            mmi_asc_to_ucs2((PS8) temp_address, (PS8) address);

            //            if((MMI_FALSE == mmi_jsr_check_address_input_format((U8*)temp_address))
            //               &&(MMI_FALSE == mmi_jsr_check_number_input_format((U8*)temp_address)))
            //           {
            //                eRet = JC_ERR_INVALID_PARAMETER;
            //                goto END;
            //            }

            ret = mmi_jsr_add_address_in_addresse_list(temp_address, addrType, MMI_UMMS_ADDRESS_GROUP_TYPE_CC);
            if (ret != 0)
            {
                eRet = JSR_RESULT_INSUFFICIENT_MEMORY;
                goto END;
            }

            if (address != NULL)
            {
                umms_free(address);
                address = NULL;
            }
            if (temp_address != NULL)
            {
                umms_free(temp_address);
                temp_address = NULL;
            }
            message->cc_addr_no--;
        }

        /* Retrieve bcc addresses */
        while (message->bcc_addr_no > 0)
        {
            U32 address_len = 0;
            U32 addrType = 0;
            U8 ret = 0;

            memcpy(&addrType, (char*)(buffer + datalen), 4);
            memcpy(&address_len, (char*)(buffer + datalen + 4), 4);

            address = (S8*) umms_malloc(address_len + 1);
            memset(address, 0, address_len + 1);
            if (address == NULL)
            {
                eRet = JSR_RESULT_INSUFFICIENT_MEMORY;
                goto END;
            }
            memcpy(address, buffer + datalen + 8, address_len);
            datalen += address_len + 8;

            temp_address = (S8*) umms_malloc((address_len + 1) * ENCODING_LENGTH);
            memset(temp_address, 0, (address_len + 1) * ENCODING_LENGTH);

            if (temp_address == NULL)
            {
                eRet = JSR_RESULT_INSUFFICIENT_MEMORY;
                goto END;
            }
            mmi_asc_to_ucs2((PS8) temp_address, (PS8) address);

            //            if((MMI_FALSE == mmi_jsr_check_address_input_format((U8*)temp_address))
            //               &&(MMI_FALSE == mmi_jsr_check_number_input_format((U8*)temp_address)))
            //            {

            //                eRet = JC_ERR_INVALID_PARAMETER;
            //                goto END;
            //            }

            ret = mmi_jsr_add_address_in_addresse_list(temp_address, addrType, MMI_UMMS_ADDRESS_GROUP_TYPE_BCC);
            if (ret != 0)
            {
                eRet = JSR_RESULT_INSUFFICIENT_MEMORY;
                goto END;
            }
            if (address != NULL)
            {
                umms_free(address);
                address = NULL;
            }
            if (temp_address != NULL)
            {
                umms_free(temp_address);
                temp_address = NULL;
            }
            message->bcc_addr_no--;
        }
    }

  END:
    if (address != NULL)
    {
        umms_free(address);
        address = NULL;
    }

    if (temp_address != NULL)
    {
        umms_free(temp_address);
        temp_address = NULL;
    }
    return eRet;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_add_address_in_addresse_list
 * DESCRIPTION
 *  Add the input address in address list
 * PARAMETERS
 *  address     [?]         [?]         [?]         [?]     [?]
 *  type        [IN]        
 *  group       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_jsr_add_address_in_addresse_list(
    S8 *address,
    mmi_umms_address_type_enum type,
    mmi_umms_address_group_type_enum group)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_addr_struct *address_temp_p, *address_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    address_node = (mmi_umms_addr_struct*) umms_malloc(sizeof(mmi_umms_addr_struct));
    memset(address_node, 0, sizeof(mmi_umms_addr_struct));

    if (address_node == NULL)
    {
        return JSR_RESULT_INSUFFICIENT_MEMORY;
    }

    address_node->addr = (U8*) umms_malloc((mmi_ucs2strlen(address) + 1) * ENCODING_LENGTH);
    if (address_node->addr == NULL)
    {
        return JSR_RESULT_INSUFFICIENT_MEMORY;
    }

    address_node->type = type;

    if (address_node->type == MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER)
    {
        mmi_ucs2_to_asc((PS8) address_node->addr, (PS8) address);
    }
    else
    {
        mmi_ucs2cpy((PS8) address_node->addr, address);
    }

    address_node->group = group;

    address_node->next = NULL;

    if (group == MMI_UMMS_ADDRESS_GROUP_TYPE_TO)
    {
        if (g_jsr_mms_xml_msg.to_head == NULL)
        {
            address_node->previous = address_node;
            g_jsr_mms_xml_msg.to_head = address_node;
        }
        else
        {
            address_temp_p = g_jsr_mms_xml_msg.to_head;

            while (address_temp_p->next != NULL)
            {
                address_temp_p = address_temp_p->next;
            }

            address_node->previous = address_temp_p;
            address_temp_p->next = address_node;

        }
    }
    else if (group == MMI_UMMS_ADDRESS_GROUP_TYPE_CC)
    {
        if (g_jsr_mms_xml_msg.cc_head == NULL)
        {
            address_node->previous = address_node;
            g_jsr_mms_xml_msg.cc_head = address_node;
        }
        else
        {
            address_temp_p = g_jsr_mms_xml_msg.cc_head;

            while (address_temp_p->next != NULL)
            {
                address_temp_p = address_temp_p->next;
            }

            address_node->previous = address_temp_p;
            address_temp_p->next = address_node;

        }
    }
    else if (group == MMI_UMMS_ADDRESS_GROUP_TYPE_BCC)
    {
        if (g_jsr_mms_xml_msg.bcc_head == NULL)
        {
            address_node->previous = address_node;
            g_jsr_mms_xml_msg.bcc_head = address_node;
        }
        else
        {
            address_temp_p = g_jsr_mms_xml_msg.bcc_head;

            while (address_temp_p->next != NULL)
            {
                address_temp_p = address_temp_p->next;
            }

            address_node->previous = address_temp_p;
            address_temp_p->next = address_node;

        }
    }
    return JSR_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_add_media_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  message     [?]     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_jsr_add_media_object(wap_mmc_post_appmms_msg_part_res_struct *message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *media_buffer_p = NULL;
    U8 *temp_buffer_p = NULL;
    FS_HANDLE file_handle;
    U32 file_size;
    U32 read_cnt;
    U8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((message == NULL)
        || (message->filepath_len == 0)
        || (message->content_type_len == 0) || (message->content_id_len == 0 && message->content_location_len == 0))
    {
        return JSR_RESULT_ERROR_MSG_CORRUPTED;
    }

    //      mmi_asc_to_ucs2((S8*)file_path,(S8*)message->filepath);
    //      file_path = message->filepath;
    if (strstr((S8*) message->content_type, "text/plain") != NULL)
    {
        file_handle = FS_Open((U16*) message->filepath, FS_READ_ONLY);

        if (file_handle < 0)
        {
            return JSR_RESULT_ERROR_MSG_CORRUPTED;
        }

        FS_GetFileSize(file_handle, &file_size);
        temp_buffer_p = (U8*) umms_malloc((file_size + 1));
		memset(temp_buffer_p, 0, file_size + 1);
        media_buffer_p = (U8*) umms_malloc(ENCODING_LENGTH * (file_size + 1));
		memset(media_buffer_p, 0, ENCODING_LENGTH * (file_size + 1));
        if (file_size > 0)
        {
            if(FS_Read(file_handle, temp_buffer_p, file_size, &read_cnt)
				!= FS_NO_ERROR || file_size != read_cnt)
			{
				result = JSR_RESULT_ERROR_MSG_CORRUPTED;
				goto ERROR_HANDLE;
			}
        }

        FS_Close(file_handle);

        if (message->encoding_scheme == MMS_US_ASCII)
        {
            mmi_asc_to_ucs2((S8*) media_buffer_p, (S8*) temp_buffer_p);
        }
        else if (message->encoding_scheme == MMS_UTF8)
        {
            mmi_chset_utf8_to_ucs2_string((U8*) media_buffer_p, (U32) ENCODING_LENGTH * (file_size + 1), (U8*) temp_buffer_p);
        }
	    else
        {
	        result = JSR_RESULT_INVALID_MESSAGE;
	        goto ERROR_HANDLE;
        }
            result = mmi_jsr_insert_text_object(message, media_buffer_p);
            if (result != JSR_RESULT_OK)
            {
			goto ERROR_HANDLE;
        }
    }
    else if (strstr((S8*) message->content_type, "audio/") != NULL)
    {
        result = mmi_jsr_insert_object(message, MMI_UMMS_OBJECT_TYPE_AUDIO);
        if (result != JSR_RESULT_OK)
        {
			goto ERROR_HANDLE;
        }
    }
    else if (strstr((S8*) message->content_type, "video/") != NULL)
    {
        result = mmi_jsr_insert_object(message, MMI_UMMS_OBJECT_TYPE_VIDEO);
        if (result != JSR_RESULT_OK)
        {
			goto ERROR_HANDLE;
        }
    }
    else if (strstr((S8*) message->content_type, "image/") != NULL)
    {
        result = mmi_jsr_insert_object(message, MMI_UMMS_OBJECT_TYPE_IMAGE);
        if (result != JSR_RESULT_OK)
        {
			goto ERROR_HANDLE;
        }
    }
	else
	{
		result = mmi_jsr_insert_object(message, MMI_UMMS_OBJECT_TYPE_UNKNOWN);
        if (result != JSR_RESULT_OK)
        {
			goto ERROR_HANDLE;
	}


	}

ERROR_HANDLE:

    if (temp_buffer_p != NULL)
    {
        umms_free(temp_buffer_p);
    }
    if (media_buffer_p != NULL)
    {
        umms_free(media_buffer_p);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_insert_text_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  media_buffer_p      [?]     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_jsr_insert_text_object(wap_mmc_post_appmms_msg_part_res_struct *message, U8 *media_buffer_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_object_struct *temp_obj, *text_obj;
    U8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    text_obj = (mmi_umms_object_struct*) umms_malloc(sizeof(mmi_umms_object_struct));
    memset(text_obj, 0, sizeof(mmi_umms_object_struct));

    text_obj->file_path = (U16*) umms_malloc(MMA_MAX_INTERNAL_FILENAME_LENGTH * ENCODING_LENGTH + 2);
    text_obj->file_name = (U16*) umms_malloc(MMA_MAX_INTERNAL_FILENAME_LENGTH * ENCODING_LENGTH + 2);

    MAKE_JSR_XML_TEXT_FILE(text_obj->file_path, JSR_CNTX->counter);
    mmi_ucs2cpy((S8*) text_obj->file_name, (S8*) mmi_fmgr_extract_file_name((S8*) text_obj->file_path));

    text_obj->mime_type = (U8*) umms_malloc( (message->content_type_len + 1) * ENCODING_LENGTH);
    memset(text_obj->mime_type, 0, (message->content_type_len+1) * ENCODING_LENGTH);
	mmi_asc_n_to_ucs2((S8*)text_obj->mime_type, (S8*)message->content_type, message->content_type_len);

    text_obj->content_id = (U8*) umms_malloc( (message->content_id_len + 1) * ENCODING_LENGTH);
    memset(text_obj->content_id, 0, (message->content_id_len+1) * ENCODING_LENGTH);
	mmi_asc_n_to_ucs2((S8*)text_obj->content_id, (S8*)message->content_id, message->content_id_len);
	
    text_obj->content_location = (U8*) umms_malloc( message->content_location_len * ENCODING_LENGTH + 2);
	mmi_ucs2cpy((S8*) text_obj->content_location, (S8*)text_obj->file_name);

    result = mmi_umms_fill_text_data(text_obj->file_path, (U16*) media_buffer_p);
    if(result != JSR_RESULT_OK)
    {
        return result;
    }
    text_obj->size = applib_get_file_size((kal_wchar*) text_obj->file_path);

	text_obj->encoding_scheme = message->encoding_scheme;
    
    /* put text data in a file */
    text_obj->id = JSR_CNTX->counter++;
    text_obj->reference_count = 1;
    text_obj->type = MMI_UMMS_OBJECT_TYPE_TEXT;
    text_obj->drm_type = MMA_DRM_NONE;
    text_obj->is_virtual_file = 0;
    text_obj->next = NULL;
    if (g_jsr_mms_xml_msg.object_head == NULL)
    {
        g_jsr_mms_xml_msg.object_head = text_obj;
        text_obj->previous = text_obj;

    }
    else
    {
        temp_obj = g_jsr_mms_xml_msg.object_head;

        while (temp_obj->next != NULL)
        {
            temp_obj = temp_obj->next;
        }

        text_obj->previous = temp_obj;
        temp_obj->next = text_obj;

    }

    mmi_jsr_insert_slide(text_obj, text_obj->type);
    return JSR_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_insert_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  message     [?]         [?]         [?]
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_jsr_insert_object(wap_mmc_post_appmms_msg_part_res_struct *message, mmi_umms_object_type type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_object_struct *obj_head, *temp_obj;
    U8 file_name[MMA_MAX_INTERNAL_FILENAME_LENGTH * ENCODING_LENGTH];
    S32 fh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_obj = (mmi_umms_object_struct*) umms_malloc(sizeof(mmi_umms_object_struct));
    memset(temp_obj, 0, sizeof(mmi_umms_object_struct));

    temp_obj->size = applib_get_file_size((kal_wchar*) message->filepath);

	MAKE_JSR_MEDIA_FILE(file_name, JSR_CNTX->counter);
	fh = (S32)FS_Move(message->filepath, (U16*)file_name, FS_MOVE_KILL | FS_MOVE_OVERWRITE,
        NULL, NULL, 0);
    if(fh < 0)
    {
        return (U8)fh;
    }

    temp_obj->file_path = (U16*) umms_malloc(MMA_MAX_INTERNAL_FILENAME_LENGTH * ENCODING_LENGTH  + 2 );
    mmi_ucs2cpy((S8*) temp_obj->file_path, (S8*) file_name);

	temp_obj->file_name = (U16*) umms_malloc( MMA_MAX_INTERNAL_FILENAME_LENGTH*ENCODING_LENGTH);
	mmi_ucs2cpy((S8*)temp_obj->file_name, (S8*)mmi_fmgr_extract_file_name((S8*) temp_obj->file_path));

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    temp_obj->mime_type = (U8*) umms_malloc( message->content_type_len * ENCODING_LENGTH + 2);
memset(temp_obj->mime_type, 0,message->content_type_len * ENCODING_LENGTH + 2);
	mmi_asc_n_to_ucs2((S8*)temp_obj->mime_type, (S8*)message->content_type, message->content_type_len);

    temp_obj->content_id = (U8*) umms_malloc( message->content_id_len * ENCODING_LENGTH + 2);
	memset(temp_obj->content_id, 0, message->content_id_len * ENCODING_LENGTH + 2);
	mmi_asc_n_to_ucs2((S8*)temp_obj->content_id, (S8*)message->content_id, message->content_id_len);
	
    temp_obj->content_location = (U8*) umms_malloc( message->content_location_len * ENCODING_LENGTH + 2);
	memset(temp_obj->content_location, 0, message->content_location_len * ENCODING_LENGTH + 2);
	mmi_asc_n_to_ucs2((S8*)temp_obj->content_location, (S8*)message->content_location, message->content_location_len);
	
    temp_obj->offset = 0;
    temp_obj->type = type;
    temp_obj->drm_type = MMA_DRM_NONE;
    temp_obj->is_virtual_file = 0;
    temp_obj->reference_count = 1;
    temp_obj->id = JSR_CNTX->counter++;
    temp_obj->next = NULL;

    if (g_jsr_mms_xml_msg.object_head == NULL)
    {
        g_jsr_mms_xml_msg.object_head = temp_obj;
        temp_obj->previous = temp_obj;

    }
    else
    {
        obj_head = g_jsr_mms_xml_msg.object_head;

        while (obj_head->next != NULL)
        {
            obj_head = obj_head->next;
        }

        temp_obj->previous = obj_head;
        obj_head->next = temp_obj;

    }

    mmi_jsr_insert_slide(temp_obj, temp_obj->type);
    return JSR_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_insert_slide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj         [?]         [?]         [?]
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_jsr_insert_slide(mmi_umms_object_struct *obj, mmi_umms_object_type type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_slide_struct *temp_slide, *tslide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return JSR_RESULT_OK;
    temp_slide = (mmi_umms_slide_struct*) umms_malloc(sizeof(mmi_umms_slide_struct));

    /* g_mms_xml_msg->slide_head = (mmi_umms_slide_struct*)OslMalloc(sizeof(mmi_umms_slide_struct)); */
    memset(temp_slide, 0, sizeof(mmi_umms_slide_struct));

    temp_slide->duration = (U8) (DEFAULT_SLIDE_DURATION / 1000);
    temp_slide->slide_num = JSR_CNTX->counter;
    switch (type)
    {
        case MMI_UMMS_OBJECT_TYPE_TEXT:
            memset(&temp_slide->text, 0, sizeof(mmi_umms_text_object_info_struct));
            temp_slide->text.background_color = MMI_UMMS_DEFAULT_BG_COLOR;
            temp_slide->text.foreground_color = MMI_UMMS_DEFAULT_FG_COLOR;
            temp_slide->text.object = obj;
            break;
        case MMI_UMMS_OBJECT_TYPE_AUDIO:
            memset(&temp_slide->audio, 0, sizeof(mmi_umms_object_info_struct));
            temp_slide->audio.object = obj;
            break;
        case MMI_UMMS_OBJECT_TYPE_VIDEO:
            memset(&temp_slide->video, 0, sizeof(mmi_umms_object_info_struct));
            temp_slide->video.object = obj;
            break;
        case MMI_UMMS_OBJECT_TYPE_IMAGE:
            memset(&temp_slide->image, 0, sizeof(mmi_umms_object_info_struct));
            temp_slide->image.object = obj;
            break;
        default:
            return JSR_RESULT_ERROR;
    }

    if (g_jsr_mms_xml_msg.slide_head == NULL)
    {
        g_jsr_mms_xml_msg.slide_head = temp_slide;
        temp_slide->previous = temp_slide;

    }
    else
    {
        tslide = g_jsr_mms_xml_msg.slide_head;

        while (tslide->next != NULL)
        {
            tslide = tslide->next;
        }

        tslide->previous = tslide;
        tslide->next = temp_slide;

    }
    return JSR_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_reset_xml_struct_msg
 * DESCRIPTION
 *  This functions reset the resourses held by xml generation process.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_reset_xml_struct_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_umms_slide_struct *slide, *curr_slide;
    mmi_umms_addr_struct *to, *curr_to;
    mmi_umms_addr_struct *cc, *curr_cc;
    mmi_umms_addr_struct *bcc, *curr_bcc;
    mmi_umms_addr_struct *from;
    mmi_umms_attachment_info_struct *attachment, *curr_attachment;
    U8 xml_file_path[MMA_MAX_INTERNAL_FILENAME_LENGTH * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    slide = g_jsr_mms_xml_msg.slide_head;
    to = g_jsr_mms_xml_msg.to_head;
    cc = g_jsr_mms_xml_msg.cc_head;
    bcc = g_jsr_mms_xml_msg.bcc_head;
    from = g_jsr_mms_xml_msg.from;
    attachment = g_jsr_mms_xml_msg.attachment_head;

    while (slide)
    {
        if (slide->text.object)
        {
            if (slide->text.object->file_path)
            {
                FS_Delete(slide->text.object->file_path);
                umms_free(slide->text.object->file_path);
                /* slide->text.object->file_path = NULL; */
            }
            if (slide->text.object->file_name)
            {
                umms_free(slide->text.object->file_name);
                /* slide->text.object->file_name = NULL; */
            }
            if (slide->text.object->content_id)
            {
                umms_free(slide->text.object->content_id);
                /* slide->text.object->content_id = NULL; */
            }
            if (slide->text.object->content_location)
            {
                umms_free(slide->text.object->content_location);
                /* slide->text.object->content_location = NULL; */
            }
            if (slide->text.object->mime_type)
            {
                umms_free(slide->text.object->mime_type);
                /* slide->text.object->mime_type = NULL; */
            }
            umms_free(slide->text.object);

            //                      slide->text.object->next = NULL;
            //                      slide->text.object->previous = NULL;
        }
        if (slide->text.alt_str)
        {
            umms_free(slide->text.alt_str);
        }

        if (slide->image.object)
        {
            if (slide->image.object->file_path)
            {
                FS_Delete(slide->image.object->file_path);
                umms_free(slide->image.object->file_path);
                /* slide->image.object->file_path = NULL; */
            }
            if (slide->image.object->file_name)
            {
                umms_free(slide->image.object->file_name);
                /* slide->image.object->file_name = NULL; */
            }
            if (slide->image.object->content_id)
            {
                umms_free(slide->image.object->content_id);
                /* slide->image.object->content_id = NULL; */
            }
            if (slide->image.object->content_location)
            {
                umms_free(slide->image.object->content_location);
                /* slide->image.object->content_location = NULL; */
            }
            if (slide->image.object->mime_type)
            {
                umms_free(slide->image.object->mime_type);
                /* slide->image.object->mime_type = NULL; */
            }
            umms_free(slide->image.object);

            //                      slide->image.object->next = NULL;
            //                      slide->image.object->previous = NULL;
        }
        if (slide->image.alt_str)
        {
            umms_free(slide->image.alt_str);
        }

        if (slide->audio.object)
        {
            if (slide->audio.object->file_path)
            {
                FS_Delete(slide->audio.object->file_path);
                umms_free(slide->audio.object->file_path);
                /* slide->audio.object->file_path = NULL; */
            }
            if (slide->audio.object->file_name)
            {
                umms_free(slide->audio.object->file_name);
                /* slide->audio.object->file_name = NULL; */
            }
            if (slide->audio.object->content_id)
            {
                umms_free(slide->audio.object->content_id);
                /* slide->audio.object->content_id = NULL; */
            }
            if (slide->audio.object->content_location)
            {
                umms_free(slide->audio.object->content_location);
                /* slide->audio.object->content_location = NULL; */
            }
            if (slide->audio.object->mime_type)
            {
                umms_free(slide->audio.object->mime_type);
                /* slide->audio.object->mime_type = NULL; */
            }
            umms_free(slide->audio.object);
            //                      slide->audio.object->next = NULL;
            //                      slide->audio.object->previous = NULL;

        }
        if (slide->audio.alt_str)
        {
            umms_free(slide->audio.alt_str);
        }

        if (slide->video.object)
        {
            if (slide->video.object->file_path)
            {
                FS_Delete(slide->video.object->file_path);
                umms_free(slide->video.object->file_path);
                /* slide->video.object->file_path = NULL; */
            }
            if (slide->video.object->file_name)
            {
                umms_free(slide->video.object->file_name);
                /* slide->video.object->file_name = NULL; */
            }
            if (slide->video.object->content_id)
            {
                umms_free(slide->video.object->content_id);
                /* slide->video.object->content_id = NULL; */
            }
            if (slide->video.object->content_location)
            {
                umms_free(slide->video.object->content_location);
                /* slide->video.object->content_location = NULL; */
            }
            if (slide->video.object->mime_type)
            {
                umms_free(slide->video.object->mime_type);
                /* slide->video.object->mime_type = NULL; */
            }
            umms_free(slide->video.object);
            //                      slide->video.object->next = NULL;
            //                      slide->video.object->previous = NULL;

        }

        if (slide->video.alt_str)
        {
            umms_free(slide->video.alt_str);
        }

        curr_slide = slide;
        slide = slide->next;
        umms_free(curr_slide);
        //              curr_slide->next = NULL;
        //              curr_slide->previous = NULL;
    }
    while (to)
    {
        if (to->addr)
        {
            umms_free(to->addr);
        }
        curr_to = to;
        to = to->next;
        umms_free(curr_to);
    }
    while (cc)
    {
        if (cc->addr)
        {
            umms_free(cc->addr);
        }
        curr_cc = cc;
        cc = cc->next;
        umms_free(curr_cc);
    }
    while (bcc)
    {
        if (bcc->addr)
        {
            umms_free(bcc->addr);
        }
        curr_bcc = bcc;
        bcc = bcc->next;
        umms_free(curr_bcc);
    }
    if (from)
    {
        if (from->addr)
        {
            umms_free(from->addr);
        }
        umms_free(from);
    }
    while (attachment)
    {
        if (attachment->object)
        {
            if (attachment->object->file_path)
            {
                FS_Delete(attachment->object->file_path);
                umms_free(attachment->object->file_path);
                /* attachment->object->file_path = NULL; */
            }
            if (attachment->object->file_name)
            {
                umms_free(attachment->object->file_name);
                /* attachment->object->file_name = NULL; */
            }
            if (attachment->object->content_id)
            {
                umms_free(attachment->object->content_id);
                /* attachment->object->content_id = NULL; */
            }
            if (attachment->object->content_location)
            {
                umms_free(attachment->object->content_location);
                /* attachment->object->content_location = NULL; */
            }
            if (attachment->object->mime_type)
            {
                umms_free(attachment->object->mime_type);
                /* attachment->object->mime_type = NULL; */
            }
            umms_free(attachment->object);
        }

        curr_attachment = attachment;
        attachment = attachment->next;
        umms_free(curr_attachment);
    }

    /* umms_free(g_jsr_mms_xml_msg); */
    memset(&g_jsr_mms_xml_msg, 0, sizeof(g_jsr_mms_xml_msg));

    MAKE_JSR_XML_FILE(xml_file_path);
    FS_Delete((U16*) xml_file_path);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_fill_text_data
 * DESCRIPTION
 *  This function fills the text data in a file.
 * PARAMETERS
 *  file_path       [?]     [?]     [?]
 *  subject         [?]     [?]     [?]
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_umms_fill_text_data(U16 *file_path, U16 *subject)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    U32 write_len = 0;
    U32 utf8_buffer_size = (mmi_ucs2strlen((S8*) subject) * 3 + ENCODING_LENGTH);
    U8 *utf8_buffer = (U8*) umms_malloc(utf8_buffer_size);
    U32 utf8_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(utf8_buffer, 0, utf8_buffer_size);
    utf8_len = mmi_chset_ucs2_to_utf8_string(utf8_buffer, utf8_buffer_size, (U8*) subject);

    file_handle = FS_Open((U16*) file_path, FS_CREATE_ALWAYS | FS_READ_WRITE);

    if (file_handle < 0)
    {
        return (U8)file_handle;
    }
    else
    {
        FS_Write(
            file_handle,
            utf8_buffer,
            utf8_len - 1,   /* null terminator */
            &write_len);
        umms_free(utf8_buffer);
        FS_Close(file_handle);
    }
    return JSR_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_receive_appmms_req_hldr
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_RECV_APPMMS_REQ primitive to Java
 * PARAMETERS
 *  msg     [?]     [?]     [?]     [?]
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
    jsr_appid_msgid_list *appid_list = NULL;
    S8 *appId = NULL;
    U32 msgId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&response, 0, sizeof(wap_mmc_recv_appmms_rsp_struct));

    if (JSR_CNTX->state != JSR_STATE_IDLE)
    {
        response.result = JSR_RESULT_BUSY;
        mmi_jsr_receive_appmms_rsp(&response, NULL, 0);
        return;
    }
    JsrCleanContext();  /* clean context first */

    Message = (wap_mmc_recv_appmms_req_struct*) msg;
    *(Message->app_id + Message->app_id_len) = '\0';

    appId = (S8*) Message->app_id;
    JSR_CNTX->op = JSR_OP_RECV_MSG;
    JSR_CNTX->state = JSR_STATE_RECV_MSG_HDR;

    if (appId == NULL)
    {
        response.result = JSR_RESULT_INVALID_PARAMETER;
        mmi_jsr_receive_appmms_rsp(&response, NULL, 0);
        JsrCleanContext();
        return;
    }
    else if (g_jsr_appid_object_list == NULL)
    {
        mmi_jsr_read_object_list_from_file();
    }

    appid_list = g_jsr_appid_object_list;

    while (appid_list)
    {
        if ((appid_list->appId) && (strcmp((S8*) appid_list->appId, (S8*) appId) == 0))
        {
            ASSERT(appid_list->msgs);
            msgId = appid_list->msgs->msgId;
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
        #endif /* 0 */ 
            JSR_CNTX->msgId = msgId;
            JSR_CNTX->counter = 0;  /* reset the count */
            JSR_CNTX->req_id = wap_mma_get_request_id();
            mmi_jsr_get_msg_content_req();
            return;
        }
        appid_list = appid_list->next;
    }
    
    response.result = JSR_RESULT_NO_MSG_FOR_JAVA;
    mmi_jsr_receive_appmms_rsp(&response, NULL, 0);
    JsrCleanContext();
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_get_msg_content_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  buffer_size(?)      [IN](?)(?)
 *  resp            [?](?)(?)(?)
 *  buffer          [?](?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_get_msg_content_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    wap_mma_get_content_req_struct *msgcnt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgcnt = (wap_mma_get_content_req_struct*) OslConstructDataPtr(sizeof(*msgcnt));

    msgcnt->app_id = MMA_APP_ID_JSR;
    msgcnt->req_id = JSR_CNTX->req_id;  /* wap_mma_get_request_id(); */
    msgcnt->msg_id = JSR_CNTX->msgId;
    msgcnt->buffer_index = JSR_CNTX->counter;
    msgcnt->mode = MMA_MODE_RAW; 
    msgcnt->creation_mode = MMA_CREATION_MODE_FREE;
    /* send request for message list */

    mmi_jsr_post_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_GET_CONTENT_REQ, (oslParaType*) msgcnt, NULL);
    mmi_umms_set_mms_downloading_busy();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_get_msg_content_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgRsp      [?]     [?]     [?]
 *  buffer_size(?)      [IN](?)(?)
 *  resp            [?](?)(?)(?)
 *  buffer          [?](?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_get_msg_content_rsp(void *msgRsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    wap_mmc_recv_appmms_rsp_struct response;
    S8 *buffer = NULL;
    U32 buffer_size = 0;

    /* mmi_umms_xml_msg_struct g_jsr_mms_xml_msg; */

    wap_mma_get_content_rsp_struct *msgCnt = (wap_mma_get_content_rsp_struct*) msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&response, 0, sizeof(wap_mmc_recv_appmms_rsp_struct));

    if(JSR_CNTX->op != JSR_OP_RECV_MSG)
    {
        return;
    }
    if (msgCnt->result != JSR_RESULT_OK)
    {   /* if not Ok then send error result */

        mmi_jsr_remove_msgId_from_appId_list(JSR_CNTX->msgId);
        response.result = JSR_RESULT_ERROR_MSG_CORRUPTED;
        mmi_jsr_receive_appmms_rsp(&response, NULL, 0);
        JsrCleanContext();
        return;
    }

    if (msgCnt->more)
    {
        JSR_CNTX->counter++;
        mmi_jsr_get_msg_content_req();
    }
    else
    {
        memset(&g_jsr_mms_xml_msg, 0, sizeof(mmi_umms_xml_msg_struct));
        result = mmi_umms_parse_mms_xml_description_file(
                    msgCnt->xml_filepath,
                    jsr_decoder_mem_alloc,
                    jsr_decoder_mem_free,
                    &g_jsr_mms_xml_msg,
                    0);

        if (result == XML_RESULT_OK)
        {   /* fill header info and send mmi_jsr_receive_appmms_rsp; */
            mmi_jsr_fill_header(&response, (S8 **) & buffer, &buffer_size);
            /* mmi_jsr_receive_appmms_rsp(&response, buffer, buffer_size); */
            mmi_jsr_receive_appmms_post_req_hldr(&response, buffer, buffer_size);
        }
        else
        {
            response.result = JSR_RESULT_ERROR_MSG_CORRUPTED;
            mmi_jsr_receive_appmms_rsp(&response, NULL, 0);
            JsrCleanContext();
            mmi_jsr_reset_xml_struct_msg();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  jsr_decoder_mem_alloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bytes       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *jsr_decoder_mem_alloc(U32 bytes)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (void*)umms_malloc(bytes);
}


/*****************************************************************************
 * FUNCTION
 *  jsr_decoder_mem_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jsr_decoder_mem_free(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    umms_free(ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_receive_appmms_post_req_hldr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  resp            [?]         [?]         [?]         [?]
 *  buffer          [?]         [?]         [?]         [?]
 *  buffer_size     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_receive_appmms_post_req_hldr(void *resp, S8 *buffer, U32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    wap_mmc_recv_appmms_rsp_struct *response = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    response = (wap_mmc_recv_appmms_rsp_struct*) resp;
    response->result = JSR_RESULT_OK;
    mmi_jsr_receive_appmms_rsp(response, buffer, buffer_size);

    if (response->bdy_part_no != 0)
    {
        JSR_CNTX->total_media_obj_no = response->bdy_part_no;
        JSR_CNTX->curr_media_obj_no = 1;
        JSR_CNTX->state = JSR_STATE_RECV_MSG_BDY;
    }
    else
    {
        mmi_jsr_remove_msgId_from_appId_list(JSR_CNTX->msgId);
        mmi_jsr_delete_msg_req(0, JSR_CNTX->msgId);
    }

    //   if (response != NULL)
    //   {
    //       OslMfree(response);
    //       response = NULL;
    //   }
    if (buffer != NULL)
    {
        umms_free((void*)buffer);
        /* OslMfree(buffer); */
        buffer = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_receive_appmms_rsp
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_RECV_APPMMS_RSP primitive to Java
 * PARAMETERS
 *  response_struct     [?]         [?]         [?]         [?]
 *  buffer              [?]         [?]         [?]         [?]
 *  buffer_size         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_receive_appmms_rsp(wap_mmc_recv_appmms_rsp_struct *response_struct, S8 *buffer, U32 buffer_size)
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
        peer_buff_ptr = (peer_buff_struct*) construct_peer_buff((U16) buffer_size, 0, 0, TD_CTRL);
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
    if (response_struct->result != JSR_RESULT_BUSY)
    {
    mmi_umms_reset_mms_downloading_busy();
    }
    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_read_appmms_msg_part_req
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_READ_APPMMS_MSG_PART_REQ primitive to Java
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_read_appmms_msg_part_req(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_read_appmms_msg_part_rsp_struct response;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&response, 0, sizeof(wap_mmc_read_appmms_msg_part_rsp_struct));
    if (JSR_CNTX->state != JSR_STATE_RECV_MSG_BDY)
    {
        memset(&response, 0, sizeof(wap_mmc_read_appmms_msg_part_rsp_struct));
        response.result = JSR_RESULT_ACCESS_DENY;
        mmi_jsr_read_appmms_msg_part_rsp(&response);
    }
    else
    {
        if (mmi_umms_jsr_generate_recv_msg_body_part(
                JSR_CNTX->msgId,
                &(JSR_CNTX->curr_media_obj_no),
                (JSR_CNTX->total_media_obj_no),
                &response))
        {
            mmi_jsr_read_appmms_msg_part_rsp(&response);
            //JSR_CNTX->curr_media_obj_no = JSR_CNTX->curr_media_obj_no + 1;
            if (JSR_CNTX->curr_media_obj_no > JSR_CNTX->total_media_obj_no)
            {
                mmi_jsr_remove_msgId_from_appId_list(JSR_CNTX->msgId);
                mmi_jsr_delete_msg_req(0, JSR_CNTX->msgId);
            }
        }
        else
        {
            memset(&response, 0, sizeof(wap_mmc_read_appmms_msg_part_rsp_struct));
            response.result = JSR_RESULT_INSUFFICIENT_PERSISTENT_STORAGE;
            mmi_jsr_read_appmms_msg_part_rsp(&response);
            JsrCleanContext();
            mmi_jsr_reset_xml_struct_msg();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jsr_read_appmms_msg_part_rsp
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_READ_APPMMS_MSG_PART_RSP primitive to Java
 * PARAMETERS
 *  response        [?]     [?]     [?]     [?]
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
    myMsgPtr = (wap_mmc_read_appmms_msg_part_rsp_struct*)
        OslConstructDataPtr(sizeof(wap_mmc_read_appmms_msg_part_rsp_struct));

	memset((S8*) (myMsgPtr) + 4, 0, (sizeof(wap_mmc_read_appmms_msg_part_rsp_struct) - 4));

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
    memcpy(myMsgPtr->filepath, response->filepath, 100);

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
 *  mmi_jsr_fill_header
 * DESCRIPTION
 *  
 * PARAMETERS
 *  resp            [?]         [?]         [?]
 *  buffer          [IN]        
 *  buf_size        [?]         [?]         [?]
 *  eRet(?)         [IN](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jsr_fill_header(wap_mmc_recv_appmms_rsp_struct *resp, S8 **buffer, U32 *buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*S8 *content_type = NULL;*/
    U32 subject_len = 0;
    mmi_umms_addr_struct *to_list;
    mmi_umms_addr_struct *cc_list;
    /*mmi_umms_addr_struct *bcc_list;*/
    U32 address_len = 0;
    S8 *buf = NULL;
    U16 datalen = 0;

    /* U16 buf_size = 0; */

    /* wap_mmc_recv_appmms_rsp_struct *resp = NULL; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* resp = (wap_mmc_recv_appmms_rsp_struct*) jdd_MemAlloc(sizeof(wap_mmc_recv_appmms_rsp_struct), 1); */

    resp->result = JSR_RESULT_ERROR /* JSR_RESULT_OK */ ;   /* fill default as OK */

    if (resp == NULL)
    {
        resp->result = JSR_RESULT_ERROR_MSG_CORRUPTED;
        goto END;
    }

    /* set priority */
    resp->priority = g_jsr_mms_xml_msg.priority;    /* eMM1MessagePriority; */

    /* Date */
    resp->date = g_jsr_mms_xml_msg.date;

    /* set total number of objects */
    resp->bdy_part_no = (U8) g_jsr_mms_xml_msg.total_object_num;

    mmi_ucs2_to_asc((S8*) resp->reply_app_id, (S8*) g_jsr_mms_xml_msg.java_reply_app_id);
    resp->reply_app_id_len = strlen((S8*) resp->reply_app_id);

    /* amit to check eRet = jdi_MM1GetSubject(g_jsr_context->hMM1, &subject, &eCharset); */
    // amit to do 
    //      g_jsr_mms_xml_msg.start_cnt_id_len = 0;
    //      memset(g_jsr_mms_xml_msg.start_cnt_id, 0 , 100);

    /* subject */
    *buf_size += 4; /* subject_data_len 4bytes; */
    subject_len = mmi_charset_ucs2_to_utf8_length_in_bytes((U8*) g_jsr_mms_xml_msg.subject);
    if (subject_len/*g_jsr_mms_xml_msg.subject*/)
    {
        *buf_size += 4; /* subject_encode_type 4bytes */
        
        *buf_size += subject_len;
    }

    /* from address  ///from address can be one only */
    resp->from_addr_no = 0;
    if (g_jsr_mms_xml_msg.from != NULL)
    {

        resp->from_addr_no = 1;
        if (g_jsr_mms_xml_msg.from->type == MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER)
        {
            address_len = strlen((S8*) (g_jsr_mms_xml_msg.from->addr));
        }
        else
        {
            address_len = mmi_ucs2strlen((S8*) (g_jsr_mms_xml_msg.from->addr));
        }

        *buf_size += (8 + address_len);
    }

    /* to address */
    resp->to_addr_no = 0;
    if (g_jsr_mms_xml_msg.to_head != NULL)
    {
        to_list = g_jsr_mms_xml_msg.to_head;

        while (to_list)
        {
            if (to_list->addr)
            {
                resp->to_addr_no += 1;
                if (to_list->type == MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER)
                {
                    address_len = strlen((S8*) (to_list->addr));
                }
                else
                {
                    address_len = mmi_ucs2strlen((S8*) (to_list->addr));
                }
                *buf_size += (8 + address_len);
            }
            to_list = to_list->next;
        }
    }

    /* cc address */
    resp->cc_addr_no = 0;
    if (g_jsr_mms_xml_msg.cc_head != NULL)
    {
        cc_list = g_jsr_mms_xml_msg.cc_head;

        while (cc_list)
        {
            if (cc_list->addr)
            {
                resp->cc_addr_no += 1;
                if (cc_list->type == MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER)
                {
                    address_len = strlen((S8*) (cc_list->addr));
                }
                else
                {
                    address_len = mmi_ucs2strlen((S8*) (cc_list->addr));
                }
                *buf_size += (8 + address_len);
            }
            cc_list = cc_list->next;
        }
    }

    buf = (S8*) umms_malloc(*buf_size + 1);
    if (buf == NULL)
    {

        resp->result = JSR_RESULT_INSUFFICIENT_MEMORY;
        goto END;

    }

    /* Pack subject */
    if (subject_len/*g_jsr_mms_xml_msg.subject*/)
    {
        S8 *temp_subject = NULL;

        *(U32*) buf = subject_len;
        *(U32*) (buf + 4) = MMI_JSR_SUBJECT_ENCODED_VALUE /* JSR_SUBJECT_ENCODED_VALUE */ ;    /* /MMS_UTF8. Note::: Encoded value used is as given in mms_def.h file in Teleca. */
        /* /TODO:: may need to confirm value */

        /* temp_subject = jdd_MemAlloc(sizeof(S8), subject_len + 1); */
        temp_subject = (S8*) umms_malloc(subject_len + 1);
        if (temp_subject == NULL)
        {
            resp->result = JSR_RESULT_INSUFFICIENT_MEMORY;
            goto END;
        }

        mmi_chset_ucs2_to_utf8_string((U8*) temp_subject, (subject_len + 1), (U8*) g_jsr_mms_xml_msg.subject);
        memcpy(buf + 8, temp_subject, subject_len);
        datalen += (8 + subject_len);
        if (temp_subject != NULL)
        {
            umms_free(temp_subject);
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

        U32 temp_address_len;   /* = mmi_ucs2strlen((S8*) (g_jsr_mms_xml_msg.from->addr)); */
        U32 address_type;
        S8 *temp_address = NULL;

        if (g_jsr_mms_xml_msg.from->type == MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER)
        {
            temp_address_len = strlen((S8*) (g_jsr_mms_xml_msg.from->addr));
        }
        else
        {
            temp_address_len = mmi_ucs2strlen((S8*) (g_jsr_mms_xml_msg.from->addr));
        }

        address_type = g_jsr_mms_xml_msg.from->type;    /* mmi_java_map_address_type(p_from_AddressList->eAddressType); */
        memcpy((char*)(buf + datalen), &address_type, 4);
        memcpy((char*)(buf + datalen + 4), &temp_address_len, 4);

        temp_address = (S8*) umms_malloc(temp_address_len + 1);
        if (temp_address == NULL)
        {
            resp->result = JSR_RESULT_INSUFFICIENT_MEMORY;
            goto END;
        }

        if (address_type == MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER)
        {
            strcpy(temp_address, (S8*) (g_jsr_mms_xml_msg.from->addr));
        }
        else
        {
            mmi_ucs2_to_asc(temp_address, (S8*) (g_jsr_mms_xml_msg.from->addr));

        }

        /* mmi_ucs2_to_asc(temp_address, (S8*) (g_jsr_mms_xml_msg.from->addr)); */
        memcpy((char*)(buf + datalen + 8), temp_address, temp_address_len);
        datalen += (8 + temp_address_len);
        if (temp_address != NULL)
        {
            umms_free(temp_address);
            temp_address = NULL;
        }
    }

    /* /Pack to address field */
    if (g_jsr_mms_xml_msg.to_head)
    {
        to_list = g_jsr_mms_xml_msg.to_head;

        while (to_list)
        {
            if (to_list->addr)
            {
                U32 temp_address_len;   /* = mmi_ucs2strlen((S8*) (to_list->pAddress)); */
                U32 address_type;
                S8 *temp_address = NULL;

                if (to_list->type == MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER)
                {
                    temp_address_len = strlen((S8*) (to_list->addr));
                }
                else
                {
                    temp_address_len = mmi_ucs2strlen((S8*) (to_list->addr));
                }

                address_type = to_list->type;   /* mmi__java_map_address_type(to_list->eAddressType); */
                memcpy((char*)(buf + datalen), &address_type, 4);
                memcpy((char*)(buf + datalen + 4), &temp_address_len, 4);

                temp_address = (S8*) umms_malloc(temp_address_len + 1);
                if (temp_address == NULL)
                {
                    resp->result = JSR_RESULT_INSUFFICIENT_MEMORY;
                    goto END;
                }
                if (to_list->type == MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER)
                {
                    strcpy((S8*) temp_address, (S8*) to_list->addr);
                }
                else
                {
                    mmi_ucs2_to_asc(temp_address, (S8*) (to_list->addr));
                }

                memcpy((char*)(buf + datalen + 8), temp_address, temp_address_len);
                datalen += (8 + temp_address_len);
                if (temp_address != NULL)
                {
                    umms_free(temp_address);
                    temp_address = NULL;
                }

            }
            to_list = to_list->next;
        }
    }
    /* Pack cc address field */
    if (g_jsr_mms_xml_msg.cc_head)
    {
        cc_list = g_jsr_mms_xml_msg.cc_head;

        while (cc_list)
        {
            if (cc_list->addr)
            {
                U32 temp_address_len;   /* = mmi_ucs2strlen((S8*) (cc_list->pAddress)); */
                U32 address_type;
                S8 *temp_address = NULL;

                if (cc_list->type == MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER)
                {
                    temp_address_len = strlen((S8*) (cc_list->addr));
                }
                else
                {
                    temp_address_len = mmi_ucs2strlen((S8*) (cc_list->addr));
                }

                address_type = cc_list->type;   /* mmi_java_map_address_type(cc_list->eAddressType); */
                memcpy((char*)(buf + datalen), &address_type, 4);
                memcpy((char*)(buf + datalen + 4), &temp_address_len, 4);

                temp_address = (S8*) umms_malloc(temp_address_len + 1);        /* jdd_MemAlloc(sizeof(S8), temp_address_len + 1); */

                if (temp_address == NULL)
                {
                    resp->result = JSR_RESULT_INSUFFICIENT_MEMORY;
                    goto END;
                }
                if (cc_list->type == MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER)
                {
                    strcpy((S8*) temp_address, (S8*) cc_list->addr);
                }
                else
                {
                    mmi_ucs2_to_asc(temp_address, (S8*) (cc_list->addr));
                }

                memcpy((char*)(buf + datalen + 8), temp_address, temp_address_len);
                datalen += (8 + temp_address_len);
                if (temp_address != NULL)
                {
                    umms_free(temp_address);
                    temp_address = NULL;
                }
            }
            cc_list = cc_list->next;
        }
    }
    /* amit to check bcc feild */
    *buffer = buf;
    resp->result = JSR_RESULT_OK;
  END:
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_jsr_generate_recv_msg_body_part
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgId               [IN]        
 *  bdy_part_no         [?]         [?]         [?]         [?]         [?]
 *  total_objects       [IN]        
 *  response            [?]         [?]         [?]         [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_jsr_generate_recv_msg_body_part(
            U32 msgId,
            U8 *bdy_part_no,
            U8 total_objects,
            wap_mmc_read_appmms_msg_part_rsp_struct *response)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    int read_handle = -1;
    int write_handle = -1;
    U32 bytes_written = 0;
    U8 part_no = 0;
    mmi_umms_object_struct *object = NULL;
    //applib_mime_type_struct *mime_info = NULL;
    kal_wchar wrtfile[JSR_FILENAME_LEN_MMA];
    U8 media_buffer_p[FILE_BUF_SIZE];
    U32 curr_pos = 0, datalen = 0, read_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    part_no = (*bdy_part_no /* amit to check- 1 */ );
    object = g_jsr_mms_xml_msg.object_head;

    while (object)
    {
        if (object->id == part_no)
        {
            break;
        }
        object = object->next;
    }

    *bdy_part_no += 1;
    response->result = JSR_RESULT_OK;

    /* For encoding scheme: */
    response->encoding_scheme = object->encoding_scheme;

    /* content type */
    /* mime_info = mime_get_file_type(object->file_name); */

    mmi_ucs2_to_asc((S8*) response->content_type, (S8*) object->mime_type);
    response->content_type_len = strlen((S8*) response->content_type);

    if (response->content_type_len > 255)
    {
        response->content_type_len = 255;
    }

    /* For encoding scheme: */
    /* response->encoding_scheme = MMS_UTF8; */
    /* for content id: */
    /* response->content_id_len = ; */

    mmi_ucs2_to_asc((S8*) response->content_id, (S8*) object->content_id);
    response->content_id_len = strlen((S8*) response->content_id);

    if (response->content_id_len < 100)
    {

    }
    else
    {
        response->content_id_len = 99;
        memset(response->content_id, 0, response->content_id_len + 1);
    }


    mmi_ucs2_to_asc((S8*) response->content_location, (S8*) object->content_location);
    response->content_location_len = strlen((S8*) response->content_location);

    /* amit */
    {
        memset(wrtfile, 0, JSR_FILENAME_LEN_MMA);
        MAKE_JSR_MEDIA_OBJECT_FILE(wrtfile);

        FS_Delete((U16*) wrtfile);

        write_handle = FS_Open((U16*) (wrtfile), FS_CREATE_ALWAYS | FS_READ_WRITE);
        if (write_handle < 0)
        {
            response->result = JSR_RESULT_FILE_OPERATION_ERROR;
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d): UMMS JSR File Operation Error \n", __FILE__, __LINE__);
            return FALSE;
        }

        read_handle = FS_Open((U16*) (object->file_path), FS_READ_WRITE);
        if (read_handle < 0)
        {
            response->result = JSR_RESULT_FILE_OPERATION_ERROR;
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d): UMMS JSR File Operation Error \n", __FILE__, __LINE__);
            return FALSE;
        }

        curr_pos = object->offset;
        FS_Seek(read_handle, curr_pos, FS_FILE_BEGIN);

        while (curr_pos < (object->offset + object->size))
        {
            datalen = (object->offset + object->size - curr_pos);
            if (datalen > FILE_BUF_SIZE)
            {
                datalen = FILE_BUF_SIZE;
            }
            /* read data from jsr mms message */
            if (FS_Read(read_handle, &media_buffer_p, datalen, &read_size) != FS_NO_ERROR || (read_size != datalen))
            {
                FS_Close(write_handle);
                FS_Close(read_handle);

                response->result = JSR_RESULT_FILE_OPERATION_ERROR;
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d): UMMS JSR File Operation Error \n", __FILE__, __LINE__);
                return FALSE;
            }
            /* write data to jsr media object */
            if(FS_Write(write_handle, &media_buffer_p, datalen, &bytes_written)<0)
			{
                response->result = JSR_RESULT_FILE_OPERATION_ERROR;
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d): UMMS JSR File Operation Error \n", __FILE__, __LINE__);
                return FALSE;
			}

            curr_pos += datalen;
        }

        FS_Close(write_handle);
        FS_Close(read_handle);

        response->filepath_len = mmi_ucs2strlen((S8*) wrtfile);
        memset(response->filepath, 0, ((response->filepath_len + 1) * 2));
        mmi_ucs2cpy((S8*) response->filepath, (S8*) wrtfile);
    }
    /* end */
    return TRUE;
}

static U8 convert_jsr_priority_to_mma(U8 priority)
{
    return priority+1;
}
#endif /* defined(MMS_SUPPORT) */ 
#endif /* __MMI_MMS_2__ */ 


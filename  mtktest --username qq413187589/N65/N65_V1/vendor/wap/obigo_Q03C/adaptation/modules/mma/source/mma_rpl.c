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
#include "msf_def.h"
#include "msf_cfg.h"
#include "msf_core.h"
#include "msf_dcvt.h"
#include "msf_log.h"
#include "msf_mem.h"
#include "msf_errc.h"

/* MMS */
#include "mms_cfg.h"
#include "mms_def.h"
#include "mms_if.h"
#include "mltypes.h"
#include "msig.h"
#include "fldmgr.h"

/* SLS */
#include "sls_def.h"
#include "sls_cfg.h"
#include "sls_if.h"

/* SMA */
#include "sma_def.h"

/* MMA */
#include "mmsadp.h"
#include "mma_cfg.h"
#include "mma_def.h"
#include "mma_env.h"
#include "mma_intsig.h"
#include "mma_main.h"
#include "mma_send.h"
#include "mma_utils.h"

/* Misc */
#include "widget_extension.h"

void mma_reply_move_message_response(MSF_UINT8 source, MmsResult result)
{
    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, MMA_RPL_E7B51883D2922B8459E38EE99D6C414B, "%s(%d): mma_reply_move_message_response(%d, %d)\n", 
        __FILE__, __LINE__, source, result));

    if(source == MSF_MODID_MMA)
    {
        mma_request_entry_struct *entry = mma_get_entry_by_ilm_msg_id(MSG_ID_WAP_MMA_SAVE_REQ);
        mma_move_mms_info_struct *info = entry->entry_info;
        mma_result_enum ret = translate_mms_result_to_mma(result);
        wap_send_wap_mma_save_rsp(info->app_id, entry->req_id, ret, info->msg_id);
        req_dequeue(entry->req_id);
    }
    else  /* relay: pretend to be MMS service */
    {
        MmsResultSig data;
        MSF_UINT8 source = 0; 

        data.result = result;
        data.responseText="";
        
        if ( !mmsSendSignalExt( MSF_MODID_MMS, source, MMS_SIG_MOV_MSG_REPLY, &data, 
            (MmsIfConvertFunction *)mms_cvt_MmsResult))
        {
            MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, MMA_RPL_0C607E82F7E732A5E2D43AB78E761104, "%s(%d): signal send failed.\n", __FILE__, __LINE__));
        } 
    }
}

void mma_reply_folder_content(MSF_UINT8 source, MmsListOfProperties *p)
{   
    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, MMA_RPL_A1118FAB71332D435E978F9D69836C20, "%s(%d): mma_reply_folder_content(%d)\n", 
        __FILE__, __LINE__, source));
    
    if(source == MSF_MODID_MMA)
    {
        mma_request_entry_struct *entry = mma_get_entry_by_ilm_msg_id(MSG_ID_WAP_MMA_DELETE_REQ);
        mma_delete_mms_info_struct *info = entry->entry_info;
        MmsListOfProperties *list = (MmsListOfProperties*)p;
        MmsListOfProperties *new_list = NULL;
        if (NULL != list)
        {
            MMA_CALLOC(new_list, sizeof(MmsListOfProperties));
            MMSif_copyMmsListOfProperties(new_list, list, MSF_MODID_MMA);
        }

        info->list = new_list;
        info->curr = 0;
        mma_delete_mms(entry);
    }
    else  /* relay: pretend to be MMS service */
    {
        msf_dcvt_t cvtObj;   
        MSF_UINT16 length;     
        void *signalBuffer;  
        void *userBuffer;   
        MmsListOfProperties* properties = p;
        
        msf_dcvt_init(&cvtObj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);        
        if ( !mms_cvt_MmsListOfProperties(&cvtObj, properties))
        {
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, MMA_RPL_7C6C5CB5C722371433C7222564DCC4B1, "%s(%d): Conversion failed.\n", __FILE__, __LINE__));
            return;
        } 
        
        length = (MSF_UINT16)cvtObj.pos;
        signalBuffer = MSF_SIGNAL_CREATE( MMS_SIG_GET_FLDR_REPLY, MSF_MODID_MMS, source, length); 
        if (signalBuffer == NULL) 
        {
            MSF_ERROR( MSF_MODID_MMS, MSF_ERR_SYSTEM_FATAL);
        }
        else
        {
            userBuffer = MSF_SIGNAL_GET_USER_DATA (signalBuffer, &length);
            msf_dcvt_init(&cvtObj, MSF_DCVT_ENCODE, userBuffer, length, MSF_MODID_MMS); 
            if ( !mms_cvt_MmsListOfProperties(&cvtObj, properties))
            {
                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, MMA_RPL_7C6C5CB5C722371433C7222564DCC4B1, "%s(%d): Conversion failed.\n", __FILE__, __LINE__));
                MSF_SIGNAL_DESTRUCT( MSF_MODID_MMS, MMS_SIG_GET_FLDR_REPLY, signalBuffer);
            }
            else
            {
                MSF_SIGNAL_SEND(signalBuffer); 
            } 
        }  
    }
} 

void mma_reply_create_message_response(MSF_UINT8 source, MmsResult result, MmsMsgId msgId)								
{
    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, MMA_RPL_591347C4B5D73AD2D948689D704A88FC, "%s(%d): mmaReplyCreateMessageResponse(%d, %d, %d)\n", 
        __FILE__, __LINE__, source, result, msgId));
    
    if(source == MSF_MODID_MMA)
    {
        mma_request_entry_struct *entry = mma_get_entry_by_ilm_msg_id(MSG_ID_WAP_MMA_CREATE_REQ);
        mma_create_mms_info_struct *info = entry->entry_info;
        if(result == MMS_RESULT_OK)
        {
            info->msg_id = msgId;
            mma_create_mms(entry);
        }
        else
        {
            wap_send_wap_mma_create_rsp(info->app_id, entry->req_id, translate_mms_result_to_mma(result), 0, 
                info->buffer_index);
            req_dequeue(entry->req_id);
        }
    }
    else  /* relay: pretend to be MMS service */
    {
        MmsMsgReplySig data;
        data.result = result;
        data.msgId = msgId;
        if ( !mmsSendSignalExt( MSF_MODID_MMS, source, MMS_SIG_CREATE_MSG_REPLY,
            &data, (MmsIfConvertFunction *)mms_cvt_MmsMsgReply))
        {
            MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, 
                MMA_RPL_0C607E82F7E732A5E2D43AB78E761104, "%s(%d): signal send failed.\n", __FILE__, __LINE__));
        } 
    }
}  

void mma_reply_create_message_done_response(MSF_UINT8 source, MmsResult result, MmsMsgId msgId)
{
	MmsMsgReplySig data;

    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, MMA_RPL_4B054EA3FAD20C6B8BF9D14FB043D937, "%s(%d): mma_reply_create_message_done_response(%d, %d, %d)\n", 
        __FILE__, __LINE__, source, result, msgId));

    if(source == MSF_MODID_MMA)
    {
        mma_request_entry_struct *entry = mma_get_entry_by_ilm_msg_id(MSG_ID_WAP_MMA_CREATE_REQ);
        mma_create_mms_info_struct *info = entry->entry_info;
        if(result == MMS_RESULT_OK)
        {
            mma_create_mms(entry);
        }
        else
        {
            fldrMgrDeleteMessage(info->msg_id);
            wap_send_wap_mma_create_rsp(info->app_id, entry->req_id, translate_mms_result_to_mma(result), 0, 
                info->buffer_index);
            req_dequeue(entry->req_id);
        }
    }
    else
    {
        data.result = result;
        data.msgId = msgId;
        if ( !mmsSendSignalExt( MSF_MODID_MMS, source, MMS_SIG_MSG_DONE_REPLY,
            &data, (MmsIfConvertFunction *)mms_cvt_MmsMsgReply))
        {
            MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, 
                MMA_RPL_0C607E82F7E732A5E2D43AB78E761104, "%s(%d): signal send failed.\n", __FILE__, __LINE__));
        } 
    }
}  

void mma_reply_send_message_response(MSF_UINT8 source, MmsResult result, long responseStatus, char* responseText, 
    MmsMsgId msgId)
{
    mma_send_request_entry_struct *entry = mma_get_send_entry_by_msg_id(msgId);

    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, MMA_RPL_3F2B2F938F1AD31FC157F9441F56DD59, "%s(%d): mma_reply_send_message_response(%d, %d, %s)\n", 
        __FILE__, __LINE__, source, result, responseText));

    ASSERT(entry != NULL);
    if(source == MSF_MODID_MMA)
    {
        kal_wchar response_text[256];
        if(responseText != NULL)
        {
            widget_utf8_to_ucs2_string((kal_uint8*) response_text, 256 * sizeof(kal_wchar), (kal_uint8*) responseText);
        }
        else
        {
            response_text[0] = 0;
        }

        wap_send_wap_mma_send_rsp(entry->app_id, entry->req_id, translate_mms_result_to_mma(result), entry->msg_id, 
            0, response_text, entry->folder, entry->send_and_save);
    }
    else  /* relay: pretend to be MMS service */
    {
        MmsResultSig data;
    
        data.result = result;
        data.responseStatus=responseStatus;
         if(responseText!=NULL)
        {
            data.responseText=responseText;
        }
        else
        {
            data.responseText="";
        }
        if ( !mmsSendSignalExt( MSF_MODID_MMS, source, MMS_SIG_SEND_MSG_REPLY, &data, 
            (MmsIfConvertFunction *)mms_cvt_MmsResult))
        {
            MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, 
                MMA_RPL_0C607E82F7E732A5E2D43AB78E761104, "%s(%d): signal send failed.\n", __FILE__, __LINE__));
        } 
    }
    send_dequeue(entry->id);
} 

void mma_reply_cancel_send_message_response(MSF_UINT8 source, MmsResult result, long responseStatus, char* responseText,
    MmsMsgId msgId)
{
    if(source == MSF_MODID_MMA)  /* cancel response, send response */
    {
        mma_request_entry_struct *entry = mma_get_entry_by_ilm_msg_id(MSG_ID_WAP_MMA_CANCEL_SEND_REQ);
        mma_cancel_send_mms_info_struct *info = entry->entry_info;
        wap_send_wap_mma_cancel_send_rsp(info->app_id, entry->req_id, translate_mms_result_to_mma(result), msgId);
        req_dequeue(entry->req_id);  /* MMA cancel send request */
    }
    else
    {
        ASSERT(0);
    }
} 

void mma_reply_progress_status(MSF_UINT8 source, MSF_UINT8 operation, MSF_UINT8 state, MmsMsgId msgId,
    MSF_UINT32 progress, MSF_UINT32 totalLength, MSF_UINT8 queueLength)
{
    if(source == MSF_MODID_MMA)
    {
        switch (operation)
        {
        case MMS_PROGRESS_STATUS_SEND:
            if(state == MMS_PROGRESS_STATUS_START)
            {
            }
            else
            {
                mma_send_request_entry_struct *entry = mma_send_get_sending_entry();
                kal_uint32 percent = 0;
                if (totalLength > 0)
                {
                    percent = (progress * 100) / totalLength;
                }
                
                entry->percent = (entry->percent > percent) ? entry->percent : percent;                
                /* don't set as 100 til send responese is received */
                entry->percent = (entry->percent >= 100) ? 99 : entry->percent;
                wap_send_wap_mma_send_ind(entry->app_id, entry->req_id, entry->msg_id, entry->retry, entry->percent);
            }
            break;
            
        case MMS_PROGRESS_STATUS_RETRIEVE:
            if(state == MMS_PROGRESS_STATUS_START)
            {
            }
            else
            {
                mma_request_entry_struct *entry = mma_get_entry_by_ilm_msg_id(MSG_ID_WAP_MMA_DOWNLOAD_REQ);
                mma_download_mms_info_struct *info = NULL;
                kal_uint8 percent = 0, last_percent = 0;

                ASSERT(entry != NULL);
                info = (mma_download_mms_info_struct *)entry->entry_info;
                last_percent = info->percent;

                info->bytes_received = progress;
                if (totalLength > 0)
                {
                    percent = (progress * 100) / totalLength;
                }
                info->percent = (info->percent > percent) ? info->percent : percent;                
                /* don't set as 100 til send responese is received */
                info->percent = (info->percent >= 100) ? 99 : info->percent;
                if (last_percent == 0)  /* except 1st time, user should use res to request status */
                {
                    wap_send_wap_mma_download_ind(info->app_id, entry->req_id, info->notif_id, 0, info->percent, 
                        progress);
                }
            }
            break;
        
        default:
            ASSERT(0);
            break;
        }
    }
    else
    {
        MmsProgressStatus data;
    
        if (progress>totalLength)
        {
            totalLength = progress;
        }
    
        memset( &data, 0, sizeof(data));
        data.operation = operation;
        data.state = state;
        data.msgId = msgId;
        data.progress = progress;
        data.totalLength = totalLength;
        data.queueLength = queueLength;
    
        if ( !mmsSendSignalExt( MSF_MODID_MMS, source, MMS_SIG_PROGRESS_STATUS_REPLY,
            &data, (MmsIfConvertFunction *)mms_cvt_MmsProgressStatus))
        {
            MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, 
                MMA_RPL_0C607E82F7E732A5E2D43AB78E761104, "%s(%d): signal send failed.\n", __FILE__, __LINE__));
        } 
    }
} 

void mma_reply_retrieve_message_response(MSF_UINT8 source, MmsResult result, MmsMsgId msgId)								
{
    MSF_LOG_MSG(( MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, "%s(%d): mma_reply_retrieve_message_response(%d, %d, %d)\n", 
        __FILE__, __LINE__, source, result, msgId));
    
    if(source == MSF_MODID_MMA)
    {
        mma_request_entry_struct *entry = mma_get_entry_by_ilm_msg_id(MSG_ID_WAP_MMA_DOWNLOAD_REQ);
        mma_download_mms_info_struct *info = entry->entry_info;
        msgId = (result != MMS_RESULT_OK) ? 0 : msgId;
        wap_send_wap_mma_download_rsp(info->app_id, entry->req_id, translate_mms_result_to_mma(result), msgId);
        req_dequeue(entry->req_id);
    }
    else  /* Only for BGSR */
    {
        ASSERT(0);
    }
}  

void mma_reply_retrieve_cancel_response(MSF_UINT8 source, MmsResult result, MmsMsgId notif_id)								
{
    MSF_LOG_MSG(( MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, "%s(%d): mma_reply_retrieve_cancel_response(%d, %d, %d)\n", 
        __FILE__, __LINE__, source, result, notif_id));
    
    if(source == MSF_MODID_MMA)
    {
        mma_request_entry_struct *entry = mma_get_entry_by_ilm_msg_id(MSG_ID_WAP_MMA_CANCEL_DOWNLOAD_REQ);
        mma_cancel_download_info_struct *info = entry->entry_info;
        wap_send_wap_mma_cancel_download_rsp(info->app_id, entry->req_id, translate_mms_result_to_mma(result), notif_id);
        req_dequeue(entry->req_id);
    }
    else  /* Only for BGSR */
    {
        ASSERT(0);
    }
}  

void mma_reply_send_rr_response(MSF_UINT8 source, MmsResult result, MmsMsgId msgId, MmsMsgId rrId)
{
    mma_send_request_entry_struct *entry = mma_get_send_entry_by_msg_id(msgId);

    MSF_LOG_MSG(( MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, "%s(%d): mma_reply_send_rr_response(%d, %d, %d)\n", 
        __FILE__, __LINE__, source, result, rrId));

    ASSERT(entry != NULL);
    if(source == MSF_MODID_MMA)
    {
        wap_send_wap_mma_send_rsp(entry->app_id, entry->req_id, translate_mms_result_to_mma(result), entry->msg_id, 
            rrId, NULL, entry->folder, entry->send_and_save);
    }
    else  /* relay: pretend to be MMS service */
    {
        MmsRRReplySig data;

        data.result = result;
        data.rrId = rrId;
        data.msgId = msgId;
        if ( !mmsSendSignalExt( MSF_MODID_MMS, source, MMS_SIG_SEND_RR_REPLY, &data, 
            (MmsIfConvertFunction *)mms_cvt_MmsRRReplySig))
        {
            MSF_LOG_MSG(( MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, 
                "%s(%d): signal send failed.\n", __FILE__, __LINE__));
        }     
    }
    send_dequeue(entry->id);
} 

void mma_reply_default_response(MSF_UINT16 signal, void *p)
{
    MmsIfConvertFunction *func = NULL;
    
    switch(signal)
    {
        case MMS_SIG_NOTIFICATION:
            func = (MmsIfConvertFunction *)mms_cvt_MmsMsgNotificationMsg;
            break;

        case MMS_SIG_ERROR:
        case MMS_SIG_DELETE_MSG_REPLY:
            func = (MmsIfConvertFunction *)mms_cvt_MmsResult;
            break;
            
        case MMS_SIG_READ_REPORT_IND:
            func = (MmsIfConvertFunction *)mms_cvt_MmsMsgReadReport;
            break;

        case MMS_SIG_DELIVERY_REPORT:
            func = (MmsIfConvertFunction *)mms_cvt_MmsMsgDeliveryReport;
            break;

        case MMS_SIG_RETRIEVE_MSG_REPLY:
            func = (MmsIfConvertFunction *)mms_cvt_MmsMsgReply;
            break;

        case MMS_SIG_SEND_RR_REPLY:
            func = (MmsIfConvertFunction *)mms_cvt_MmsRRReplySig;
            break;

        case MMS_SIG_GET_MSG_INFO_REPLY:
            func = (MmsIfConvertFunction *)mms_cvt_MmsListOfProperties;
            break;

    }

    if ( !mmsSendSignalExt( MSF_MODID_MMS, MSF_MODID_MEA, signal,
        p, (MmsIfConvertFunction *)func))
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, MMA_RPL_BB509C696D3A5C5A72BC955535F04736, "%s(%d): mma_reply_default_response()\n", __FILE__, __LINE__));
    } 
}


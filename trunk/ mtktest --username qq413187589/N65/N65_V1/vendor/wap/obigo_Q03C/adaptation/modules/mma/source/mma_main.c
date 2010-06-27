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
#include "msf_core.h"
#include "msf_int.h"
#include "msf_mem.h"
#include "msf_file.h"
#include "msf_log.h"
#include "msf_dcvt.h"
#include "msf_wid.h"
#include "msf_chrs.h"
    
/* MMS */
#include "mms_def.h"
#include "mms_cfg.h"
#include "mms_if.h"
#include "mmsl_if.h"
#include "mltypes.h"
#include "mlfetch.h"
#include "msig.h"
#include "fldmgr.h"
#include "mms_aapp.h"

    
/* SLS */
#include "sls_def.h"
#include "sls_cfg.h"
#include "sls_if.h"

/* SMA */
#include "sma_def.h"
#include "sma_if.h"

/* MEA */
#include "meal_if.h"

/* MMA */
#include "mmsadp.h"
#include "mma_cfg.h"
#include "mma_def.h"
#include "mma_env.h"
#include "mma_intsig.h"
#include "mma_send.h"
#include "mma_conf.h"
#include "mma_utils.h"
#include "mma_utils_xml.h"
#include "mma_if_wrapper.h"

/* Misc */
#include "wap.h"
#include "widget_extension.h"

#ifndef __MMI_MMS_TEMPLATES_NUM__
#define __MMI_MMS_TEMPLATES_NUM__ 10
#endif

static mma_request_entry_struct req_queue[MMA_CFG_REQUEST_QUEUE_SIZE];
static MSF_UINT32 req_num;

/******************************************************************************
 * Extern variables/functions
 ******************************************************************************/
#ifdef __GEMINI__
extern kal_bool is_test_sim(kal_uint8 simInterface);
#else
extern kal_bool is_test_sim(void);
#endif
extern int msm_get_module_status(MSF_UINT8 modId);
extern MSF_BOOL smaIsRunning(void);
extern MSF_BOOL mmcIsJSRMsg(MSF_UINT32 msgId);
extern MSF_BOOL mmcRemoveMsgIdFromJSRIndex(MSF_UINT32 msgId);
extern MSF_UINT32 HDIa_timeLocalToUTC(MSF_UINT32 local_time);
extern MSF_BOOL copyContentType( MSF_UINT8 modId, MmsContentType *toContent, const MmsContentType *fromContent);
extern void mmsUpdateIndicator(void);
/*****************************************************************************
 * FUNCTION
 *  req_free_info
 * DESCRIPTION
 *  free request info struct from the queue
 * PARAMETERS
 *  msg_id      [IN]        
 *  req_info    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void req_free_info(mma_request_entry_struct *entry)
{
    switch(entry->ilm_msg_id)
    {
        case MSG_ID_WAP_MMA_GET_CONTENT_REQ:
        {
            mma_get_content_info_struct *info = entry->entry_info;
            HDI_FileNameFree((kal_uint8 *)info->xml_filepath);
            MMSlib_freeMmsGetHeader(MSF_MODID_MMA, info->header->header.g_header);
            mma_free_unref_list(&info->body->unref_list);
            mma_free_slide_list(&info->body->slides);
            mma_free_object_list(&info->body->objects);
            MMA_FREE(info->header);
            MMA_FREE(info->body);
            MMA_FREE(info);
            break;
        }

        case MSG_ID_WAP_MMA_CREATE_REQ:
        {
            mma_create_mms_info_struct *info = (mma_create_mms_info_struct *) entry->entry_info;
            if (info->xml_filepath)
            {
                MMA_FREE(info->xml_filepath);
            }
            
            if (info->header)
            {
                MMSlib_freeMmsSetHeader(MSF_MODID_MMA, info->header->header.s_header);
                MMA_FREE(info->header);
            }

            if (info->o_header)
            {
                MMSlib_freeMmsGetHeader(MSF_MODID_MMA, info->o_header);
            }

            if (info->body)
            {
                mma_free_unref_list(&info->body->unref_list);
                mma_free_slide_list(&info->body->slides);
                mma_free_object_list(&info->body->objects);
                MMA_FREE(info->body);
            }
            
            if (info->t_handle)
            {
                (void)MMSlib_transactionClose(MSF_MODID_MMA, &info->t_handle);
            }

            if (info->m_handle)
            {
                (void)MMSlib_messageClose(MSF_MODID_MMA, &info->m_handle);
            }

            if (info->r_handle)
            {
                MSF_FILE_CLOSE(info->r_handle);
            }

            if (info->w_handle)
            {
                MSF_FILE_CLOSE(info->w_handle);
            }

            if (info->result != MMA_RESULT_OK)
            {
                fldrMgrDeleteMessage(info->msg_id);
            }
            
            MMA_FREE(info);
            break;
        }

        case MSG_ID_WAP_MMA_PREVIEW_REQ:
        {
            mma_preview_mms_info_struct *info = (mma_preview_mms_info_struct *) entry->entry_info;
            MMA_FREE(info);
            break;
        }

        case MSG_ID_WAP_MMA_SAVE_REQ:
        {
            mma_move_mms_info_struct *info = (mma_move_mms_info_struct *) entry->entry_info;
            MMA_FREE(info);
            break;
        }

        case MSG_ID_WAP_MMA_CANCEL_SEND_REQ:
        {
            mma_cancel_send_mms_info_struct *info = (mma_cancel_send_mms_info_struct *) entry->entry_info;
            MMA_FREE(info);
            break;
        }
        
        case MSG_ID_WAP_MMA_DOWNLOAD_REQ:
        {
            mma_download_mms_info_struct *info = (mma_download_mms_info_struct *) entry->entry_info;
            MMA_FREE(info);
            break;
        }

        case MSG_ID_WAP_MMA_CANCEL_DOWNLOAD_REQ:
        {
            mma_cancel_download_info_struct *info = (mma_cancel_download_info_struct *) entry->entry_info;
            MMA_FREE(info);
            break;
        }

        case MSG_ID_WAP_MMA_DELETE_REQ:
        {
            mma_delete_mms_info_struct *info = (mma_delete_mms_info_struct *) entry->entry_info;
            MMSif_freeMmsListOfProperties(info->list, MSF_MODID_MMA);
            MMA_FREE(info->list);
            MMA_FREE(info);
            break;
        }
    }
    return;
}

/*****************************************************************************
 * FUNCTION
 *  req_enqueue
 * DESCRIPTION
 *  Add request to the queue
 * PARAMETERS
 *  ilm_sender    [IN]        
 *  ilm_msg       [IN]        
 *  req_id        [IN]        
 *  entry_info    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void req_enqueue(mma_request_entry_struct *entry)
{
    int i;
    ASSERT(req_num < MMA_CFG_REQUEST_QUEUE_SIZE);  /* queue overflow check */

    for(i = 0; i < MMA_CFG_REQUEST_QUEUE_SIZE; i++)
    {
        if(req_queue[i].req_id == 0)
            break;
    }

    ASSERT(i < MMA_CFG_REQUEST_QUEUE_SIZE);  
    req_queue[i].ilm_sender = entry->ilm_sender;
    req_queue[i].ilm_msg_id = entry->ilm_msg_id;
    req_queue[i].req_id = entry->req_id;
    req_queue[i].entry_info = entry->entry_info;
    req_num++;
}

/*****************************************************************************
 * FUNCTION
 *  req_dequeue
 * DESCRIPTION
 *  remove request from the queue
 * PARAMETERS
 *  ilm_sender    [IN]        
 *  ilm_msg       [IN]        
 *  req_id        [IN]        
 *  entry_info    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void req_dequeue(kal_uint32 req_id)
{
    int i;
    ASSERT(req_num > 0);  /* queue underflow check */

    for(i = 0; i < MMA_CFG_REQUEST_QUEUE_SIZE; i++)
    {
        if(req_queue[i].req_id == req_id)
            break;
    }

    ASSERT(i < MMA_CFG_REQUEST_QUEUE_SIZE);  /* cannot find the request */
    req_free_info(&req_queue[i]);
    req_queue[i].ilm_sender = 0;
    req_queue[i].ilm_msg_id = 0;
    req_queue[i].req_id = 0;
    req_queue[i].entry_info = NULL;
    req_num--;
}

/*****************************************************************************
 * FUNCTION
 *  mma_get_entry_by_req_id
 * DESCRIPTION
 *  get request entry from the queue by request ID
 * PARAMETERS
 *  req_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mma_request_entry_struct *mma_get_entry_by_req_id(kal_uint32 req_id)
{
    int i;

    for(i = 0; i < MMA_CFG_REQUEST_QUEUE_SIZE; i++)
    {
        if(req_queue[i].req_id == req_id)
            break;
    }

    ASSERT(i < MMA_CFG_REQUEST_QUEUE_SIZE);  /* cannot find the request */
    return &req_queue[i];
}

/*****************************************************************************
 * FUNCTION
 *  mma_get_entry_by_ilm_msg_id
 * DESCRIPTION
 *  get earliest request entry from the queue by ILM message ID
 * PARAMETERS
 *  req_id        [IN]        
 * RETURNS
 *  1st entry address. NULL if not found
 *****************************************************************************/
mma_request_entry_struct *mma_get_entry_by_ilm_msg_id(kal_uint32 ilm_msg_id)
{
    int i;
    mma_request_entry_struct *found = NULL;

    for(i = 0; i < MMA_CFG_REQUEST_QUEUE_SIZE; i++)
    {
        if(req_queue[i].ilm_msg_id == ilm_msg_id)
        {
            if(found == NULL)
            {
                found = &req_queue[i];
            }
            else
            {
                int id = mma_compare_request_id(found->req_id, req_queue[i].req_id);
                found = &req_queue[id];
            }
        }
    }

    return found;
}

/*****************************************************************************
 * FUNCTION
 *  mma_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mma_init()
{
    mma_signal_init();
    mma_send_init();
    mma_if_wrapper_init();
    memset(req_queue, 0x00, sizeof(mma_request_entry_struct) * MMA_CFG_REQUEST_QUEUE_SIZE);
    req_num = 0;
}

/*****************************************************************************
 * FUNCTION
 *  mma_get_mms_content_rsp
 * DESCRIPTION
 *  wap_send_wap_mma_get_content_rsp wrapper for successful response with XML content 
 * PARAMETERS
 *  entry        [IN]        
 * RETURNS
 *  TRUE: more XML content to be sent; FALSE: all XML content were read
 *****************************************************************************/
static kal_bool mma_get_mms_content_rsp(mma_request_entry_struct *entry)
{
    int fh;
    mma_get_content_info_struct *info = NULL;
    kal_char file_path[MMA_MAX_INTERNAL_FILENAME_LENGTH];
    kal_bool more = KAL_FALSE;
    
    info = entry->entry_info;
    MMA_GET_MMS_XML_FILEPATH(file_path, 0);
    fh = MSF_FILE_OPEN(MSF_MODID_MMA, file_path, MSF_FILE_SET_RDONLY | HDI_FILE_SET_CUSTOM_BLOCKING, 0);
    if (fh > 0)
    {
        char *buffer = NULL;
        long byte_read = 0;
        
        MMA_CALLOC(buffer, 2000);
        ASSERT(buffer != NULL);
        MSF_FILE_SEEK(fh, 2000 * info->buffer_index, HDI_FILE_SEEK_SET);
        byte_read = MSF_FILE_READ(fh, buffer, 2000);
        more = (2000 * info->buffer_index + byte_read < info->xml_size);
        wap_send_wap_mma_get_content_rsp(info->app_id, entry->req_id, MMA_RESULT_OK, info->msg_id, info->header_size, 
            info->body_size, info->xml_size, info->xml_filepath, info->buffer_index, byte_read, more, buffer);
        MMA_FREE(buffer);
        MSF_FILE_CLOSE(fh);

        return more;
    }
    else
    {
        wap_send_wap_mma_get_content_rsp(info->app_id, entry->req_id, MMA_RESULT_FAIL_FILE_IO, info->msg_id, 0, 0,
            0, NULL, info->buffer_index, 0, FALSE, NULL);
    }

    return more;
}

/*****************************************************************************
 * FUNCTION
 *  mma_get_mms_content_fsm
 * DESCRIPTION
 *  Get mms content by specified information
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mma_result_enum mma_get_mms_content_fsm(mma_get_content_info_struct *info)
{
    int ret = MMA_RESULT_OK;

    ASSERT(info != NULL);

    switch(info->state)
    {
    case PARSE_STATE_STARTED:
        info->state = PARSE_STATE_MMS_HEADER_PARSING;
        /* fall through */
    case PARSE_STATE_MMS_HEADER_PARSING:
        switch(info->sub_state)  /* Here, sub_state is used to handle delayed file I/O */
        {
        case 0:
            if ((ret = MMSlib_transactionOpen(MSF_MODID_MMA, &info->t_handle)) != MMS_RESULT_OK)
            {
                ret = translate_mms_result_to_mma(ret);
                info->state = PARSE_STATE_FINISHED;
                goto parse_fsm_finished;
            } 
            else if ((ret = MMSlib_messageOpen(MSF_MODID_MMA, info->msg_id, fldrGetFileSuffix(info->msg_id), &info->m_handle)) 
                != MMS_RESULT_OK)
            {
                (void)MMSlib_transactionClose(MSF_MODID_MMA, &info->t_handle);
                ret = translate_mms_result_to_mma(ret);
                info->state = PARSE_STATE_FINISHED;
                goto parse_fsm_finished;
            } 
            else if (info->header == NULL)
            {
                MMA_CALLOC(info->header, sizeof(mma_header_struct));
                ASSERT(info->header != NULL);
                MMA_CALLOC(info->header->header.g_header, sizeof(MmsGetHeader));
                ASSERT(info->header->header.g_header != NULL);
            }
            info->sub_state = 1;
            
        case 1:
            if((ret = MMSlib_getMessageHeader(MSF_MODID_MMA, info->header->header.g_header, &info->m_handle, &info->t_handle)) == 
                MMS_RESULT_DELAYED)
            {
                ret = translate_mms_result_to_mma(ret);
                goto parse_fsm_finished;
            }
            else if (ret != MMS_RESULT_OK)
            {
                (void)MMSlib_messageClose(MSF_MODID_MMA, &info->m_handle);
                (void)MMSlib_transactionClose(MSF_MODID_MMA, &info->t_handle);
                ret = translate_mms_result_to_mma(ret);
                info->state = PARSE_STATE_FINISHED;
                goto parse_fsm_finished;
            }
            info->header_size = getHeaderSize((MmsMessage *)info->m_handle);
            info->body_size = info->header->header.g_header->bodyInfoList.size;
            (void)MMSlib_messageClose(MSF_MODID_MMA, &info->m_handle);
            (void)MMSlib_transactionClose(MSF_MODID_MMA, &info->t_handle);
            info->sub_state = 2;
            
        case 2:
            info->header->multipart_type = mma_get_multipart_type(info->header->header.g_header);
            info->header->body_no = info->header->header.g_header->bodyInfoList.numOfEntries;
            mma_remove_invalid_address(info->header->header.g_header);

            ASSERT(info->body == NULL);
            MMA_CALLOC(info->body, sizeof(mma_body_struct));
            ASSERT(info->body != NULL);

            {
                MmsBodyInfoList *mo = &info->header->header.g_header->bodyInfoList;
                mma_object_struct *obj_tail = NULL;
                while (mo)
                {
                    const char *mime = mma_get_mime_type_from_mmsContentType(mo->contentType);

                    /* Do not handle SMIL and nodes which has sub-nodes in order to make a simple list */
                    if (mo->numOfEntries == 0 && strcmp(mime, MMS_MEDIA_TYPE_STRING_SMIL) != 0)
                    {
                        if (info->body->objects == NULL)
                        {
                            info->body->objects = mma_create_object_from_mo(info->msg_id, mo);
                            obj_tail = info->body->objects;
                        }
                        else
                        {
                            obj_tail->next = mma_create_object_from_mo(info->msg_id, mo);
                            obj_tail = obj_tail->next;
                        }
                    }
                    mo = mo->next;
                }
            }
        }
        info->state = PARSE_STATE_SLS_ACTIVATING;
        info->sub_state = 0;
        /* fallthrough */
        
    case PARSE_STATE_SLS_ACTIVATING:
        if (info->mode == MMA_MODE_REPLY || info->mode == MMA_MODE_REPLY_ALL)
        {
            ret = MMA_RESULT_CONTINUE;
            info->state = PARSE_STATE_XML_CREATING;
        }
        else if (info->header->multipart_type == MMA_SMIL && msm_get_module_status(MSF_MODID_SLS) != MODULE_STATUS_NULL)
        {
            ret = MMA_RESULT_FAIL_BUSY;
            info->state = PARSE_STATE_FINISHED;
        }
        else if (info->header->multipart_type == MMA_UNSUPPORTED)
        {
            ret = MMA_RESULT_FAIL_UNSUPPORT_CONTENT;
            info->state = PARSE_STATE_FINISHED;
        }
        else if (info->header->multipart_type == MMA_PLAIN_TEXT || info->header->multipart_type == MMA_MULTIPART_MIXED ||
            info->header->multipart_type == MMA_MULTIPART_ALTERNATIVE)  /* Mixed MMS */
        {
            if (info->mode == MMA_MODE_FORWARD || info->mode == MMA_MODE_SEND)
            {
                ret = MMA_RESULT_CONTINUE;
                info->state = PARSE_STATE_XML_CREATING;
            }
            else
            {
                ret = MMA_RESULT_CONTINUE;
                info->state = PARSE_STATE_CONTENT_FILTERING;
            }
        }
        else  /* SMIL MMS */
        {
            MSF_MODULE_START(MSF_MODID_MMA, MSF_MODID_SLS, NULL, NULL, NULL);
            ret = MMA_RESULT_DELAYED;
            info->state = PARSE_STATE_SMIL_OPENING;
        }
        break;

    case PARSE_STATE_SMIL_OPENING:  /* SLS is now started, let's open the SMIL. */
        ASSERT(info->body != NULL);
        
        if((ret = SLSif_openSmil(MSF_MODID_MMA, info->msg_id, fldrGetFileSuffix(info->msg_id))) != SLS_RESULT_OK)
        {
            MSF_MODULE_TERMINATE(MSF_MODID_MMA, MSF_MODID_SLS);
            ret = translate_sls_result_to_mma(ret);
            info->state = PARSE_STATE_ABORTED;
        }
        else
        {
            ret = MMA_RESULT_DELAYED;
            info->state = PARSE_STATE_SLIDE_CONTENT_PARSING;
        }
        break;

    case PARSE_STATE_SLIDE_CONTENT_PARSING:
        if(info->mode == MMA_MODE_FORWARD || info->mode == MMA_MODE_SEND)
        {
            (void)SLSif_closeSmil(MSF_MODID_MMA);
            ret = MMA_RESULT_DELAYED;
            info->state = PARSE_STATE_SLS_DEACTIVATING;
        }
        else if((ret = SLSif_getSlideInfo(MSF_MODID_MMA, 0)) != SLS_RESULT_OK)
        {
            MSF_MODULE_TERMINATE(MSF_MODID_MMA, MSF_MODID_SLS);
            ret = translate_sls_result_to_mma(ret);
            info->state = PARSE_STATE_ABORTED;
        }
        else
        {
            ret = MMA_RESULT_DELAYED;
            info->state = PARSE_STATE_SLIDE_CONTENT_DONE;
        }
        break;
        
    case PARSE_STATE_SLIDE_CONTENT_DONE:
    {
        kal_int32 slide_index = mma_get_slide_index(info->body, info->body->current_slide);
        
        if(slide_index >= info->body->slide_no - 1 || slide_index >= wap_custom_get_max_mms_slide() || slide_index < 0)
        {
            mma_update_unref_list(info->body);
            (void)SLSif_closeSmil(MSF_MODID_MMA);
            ret = MMA_RESULT_DELAYED;
            info->state = PARSE_STATE_SLS_DEACTIVATING;
        }
        else if((ret = SLSif_getSlideInfo(MSF_MODID_MMA, (MSF_UINT8)slide_index + 1)) != SLS_RESULT_OK)
        {
            MSF_MODULE_TERMINATE(MSF_MODID_MMA, MSF_MODID_SLS);
            ret = translate_sls_result_to_mma(ret);
            info->state = PARSE_STATE_ABORTED;
        }
        else
        {
            ret = MMA_RESULT_DELAYED;
            info->state = PARSE_STATE_SLIDE_CONTENT_DONE;
        }
        break;
    }
    
    case PARSE_STATE_SLS_DEACTIVATING:
        MSF_MODULE_TERMINATE(MSF_MODID_MMA, MSF_MODID_SLS);
        ret = MMA_RESULT_DELAYED;
        info->state = PARSE_STATE_SLS_DEACTIVATED;
        break;

    case PARSE_STATE_SLS_DEACTIVATED:
        if (info->mode == MMA_MODE_FORWARD || info->mode == MMA_MODE_SEND)
        {
            info->state = PARSE_STATE_XML_CREATING;
            ret = MMA_RESULT_CONTINUE;
            break;
        }
        else
        {
#ifdef __MMI_OBIGO_Q03C_MMS_USER_DEFINED_TEMPLATES__
            info->state = PARSE_STATE_CONTENT_FILTERING;
            ret = MMA_RESULT_CONTINUE;
            break;
#else
            if (0 < info->msg_id && info->msg_id <= __MMI_MMS_TEMPLATES_NUM__)
            {
                info->state = PARSE_STATE_TEMPLATE_CONTENT_REPLACING;
                /* fallthrough */
            }
            else
            {
                info->state = PARSE_STATE_CONTENT_FILTERING;
                ret = MMA_RESULT_CONTINUE;
                break;
            }
#endif
        }

#ifndef __MMI_OBIGO_Q03C_MMS_USER_DEFINED_TEMPLATES__
    case PARSE_STATE_TEMPLATE_CONTENT_REPLACING:
    {
        char *ucs2_str = NULL, *utf8_str = NULL; 
        char filepath[MMA_MAX_INTERNAL_FILENAME_LENGTH];
        int size = 0, fh = 0;

        /* Subject */        
        ucs2_str = GetString((MSF_UINT16)(info->msg_id + MMS_STR_ID_TEMPLATES_TITLE_01 - 1));
        info->header->header.g_header->subject.charset = MMS_UTF8;
        size = widget_ucs2_to_utf8_length_in_bytes((kal_uint8*)ucs2_str) + 1;
        MMA_CALLOC(utf8_str, size);
        widget_ucs2_to_utf8_string((kal_uint8*)utf8_str, size, (kal_uint8*)ucs2_str);
        MMA_FREE(info->header->header.g_header->subject.text);
        info->header->header.g_header->subject.text = utf8_str;

        /* Content */
        MMA_GET_MMS_TEMPLATE_TEXT_FILEPATH(filepath);
        MSF_FILE_REMOVE(filepath);
        fh = MSF_FILE_OPEN(MSF_MODID_MMA, filepath, 
            MSF_FILE_SET_CREATE | MSF_FILE_SET_WRONLY | HDI_FILE_SET_CUSTOM_BLOCKING,0);
        if (fh < 0)
        {
            ret = MMA_RESULT_FAIL_FILE_IO;
            info->state = PARSE_STATE_FINISHED;
            break;
        }
        
        if(MSF_FILE_WRITE(fh, utf8_str, size - 1) != size - 1)
        {
            MSF_FILE_CLOSE(fh);
            ret = MMA_RESULT_FAIL_FILE_IO;
            info->state = PARSE_STATE_FINISHED;
            break;
        }
        MMA_FREE(info->body->slides->text.obj->filePath);
        info->body->slides->text.obj->filePath = msf_cmmn_strdup(MSF_MODID_MMA, filepath);
        info->body->slides->text.obj->isVirtualFile = KAL_FALSE;
        info->body->slides->text.obj->offset = 0;
        MSF_FILE_CLOSE(fh);
        info->state = PARSE_STATE_CONTENT_FILTERING;
        /* fallthrough */
    }
#endif
    
    case PARSE_STATE_CONTENT_FILTERING:
    {
        mma_object_struct *obj = info->body->objects;

        /* 1. remove object of which size equals to 0 
           2. remove unsupported object */
        while (obj)
        {
            mma_object_struct *tmp_o = obj->next;
#ifdef __DRM_SUPPORT__
            char *mime = (obj->type == SLS_DRM_CONTENT) ? obj->drmMimeType : obj->mimeType;
#else
            char *mime = obj->mimeType;
#endif
            if (obj->size == 0 || (mime == NULL || strstr(MMA_OPEN_ATTACHMENT_TYPES, mime) == NULL))
            {
                if(info->header->multipart_type == MMA_SMIL)
                {
                    /* 1. update slide */
                    mma_remove_object_in_slide(info->body->slides, obj);
                    /* 2. update attachment list */
                    mma_remove_object_in_unref_list(&info->body->unref_list, obj);
                }
                
                mma_remove_object_list_entry(&info->body->objects, obj);
                mma_free_object(&obj);
            }
            obj = tmp_o;
        }

        /* creation mode filtering: user may choose to remove unrestricted objects to edit */
        obj = info->body->objects;
        if(info->creation_mode == MMA_CREATION_MODE_RESTRICTED)
        {  
            char *mms_path = MMSlib_getMessageFullPath(MSF_MODID_MMA, info->msg_id, fldrGetFileSuffix(info->msg_id));
            if(MSF_FILE_GETSIZE(mms_path) > MMA_RESTRICTED_MESSAGE_SIZE)
            {
                ret = MMA_RESULT_FAIL_CREATION_MODE_MAX_MSG_SIZE_REACHED;
                info->state = PARSE_STATE_FINISHED;
                MMA_FREE(mms_path);
                break;
            }

            while (obj)
            {
                mma_object_struct *tmp_o = obj->next;
                if(mma_is_restricted_type_vf(mms_path, obj->mimeType, obj->offset, obj->size) != KAL_TRUE)
                {
                    if(info->header->multipart_type == MMA_SMIL)
                    {
                        /* 1. update slide */
                        mma_remove_object_in_slide(info->body->slides, obj);
                        /* 2. update attachment list */
                        mma_remove_object_in_unref_list(&info->body->unref_list, obj);
                    }
                    
                    mma_remove_object_list_entry(&info->body->objects, obj);
                    mma_free_object(&obj);
                }
                obj = tmp_o;
            }
            MMA_FREE(mms_path);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        if(info->header->multipart_type == MMA_SMIL)
        {
            ret = MMA_RESULT_CONTINUE;
            info->state = PARSE_STATE_XML_CREATING;
            break;
        }
        else
        {
            info->state = PARSE_STATE_SMIL_ADDING;
            /* fallthrough */
        }
    }
        
    case PARSE_STATE_SMIL_ADDING:
    {
        MsfDeviceProperties dp;

        ASSERT(info->header != NULL && info->header->header.g_header != NULL && info->body != NULL);

        (void)MSF_WIDGET_DEVICE_GET_PROPERTIES(&dp);
        info->body->layout = MMA_LAYOUT_NONE;
        info->body->unref_list = NULL;
        info->body->root_layout.bgColor = MEAlib_getDefaultSmilBgColor();
        info->body->root_layout.cx.value = dp.displaySize.width;
        info->body->root_layout.cy.value = dp.displaySize.height;
        
        if(info->body->objects != NULL)
        {
            mma_object_struct *obj = info->body->objects;
            while(obj)
            {
                mma_slide_struct *slide = NULL;
                SlsMediaObjectType gType = mma_get_slsMediaObjectType_from_slsMediaType(obj->type);

#ifdef __DRM_SUPPORT__
                if(gType == SLS_OBJECT_TYPE_DRM)  /* check the real type of the DRM object */
                {
                    gType = mma_get_slsMediaObjectType_from_slsMediaType(obj->drmType);
                }
#endif
                /* make non-image/video/audio/text media object as unref item */
                if(gType == SLS_OBJECT_TYPE_NONE || gType == SLS_OBJECT_TYPE_ATTACMENT || gType == SLS_OBJECT_TYPE_DRM)
                {
                    obj->isAttachment = KAL_TRUE;
                    (void)mma_insert_unref_item_to_tail(info->body, obj);
                }
                else
                {
                    obj->isAttachment = KAL_FALSE;
                    slide = mma_insert_slide(info->body);
                    (void)mma_insert_slide_obj(gType, slide, obj);
                }            
                obj = obj->next;
            }
        }

        if (info->body->slide_no == 0)  /* Add empty slide */
        {
            (void)mma_insert_slide(info->body);
        }
        else if (info->body->slide_no > wap_custom_get_max_mms_slide())
        {
#if SLS_ALWAYS_VIEW_MAX_NBR_OF_SLIDES
            /* remove extra slide to edit */
            while (info->body->slide_no > wap_custom_get_max_mms_slide())
            {
                mma_remove_slide_by_index(info->body, info->body->slide_no - 1);
            }
#else
            /* edit not allowed */
            ret = MMA_RESULT_FAIL_MAX_SLIDE_NUM_REACHED;
            info->state = PARSE_STATE_FINISHED;
            break;
#endif
        }

        ret = MMA_RESULT_CONTINUE;
        info->state = PARSE_STATE_XML_CREATING;
        break;
    }

    case PARSE_STATE_XML_CREATING:
    {
        if(mma_xml_create_mms_description_file(info) != HDI_FILE_OK)
        {
            ret = MMA_RESULT_FAIL_FILE_IO;
            info->state = PARSE_STATE_FINISHED;
        }
        else
        {
            /* info->xml_filepath, info->xml_size is already set */
            ret = MMA_RESULT_OK;
            info->state = PARSE_STATE_FINISHED;
        }
        break;
    }

    /* The last state can only be PARSE_STATE_ABORTED or PARSE_STATE_FINISHED */
    case PARSE_STATE_ABORTED:
        ret = MMA_RESULT_OK;
        break;
    case PARSE_STATE_FINISHED:
        ret = MMA_RESULT_OK;
        break;
    }

parse_fsm_finished:
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MAIN_87AA91EF1ED7F611EC411317F634728C, "(%s) (%d) mma_get_mms_content_fsm(): state %d-%d, ret %d\n", 
            __FILE__, __LINE__, info->state, info->sub_state, ret));
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mma_get_mms_content
 * DESCRIPTION
 *  Get mms content by specified information
 * PARAMETERS
 *  entry    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_get_mms_content(mma_request_entry_struct *entry)
{
    mma_result_enum ret = MMA_RESULT_OK;
    mma_get_content_info_struct *info = NULL;

    ASSERT(entry != NULL && entry->entry_info != NULL);
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MAIN_6DBD2B03FC47A4DCCDFD166D2151E417, "(%s) (%d) mma_get_mms_content(%d)\n", __FILE__, __LINE__, 
        entry->req_id));

    info = entry->entry_info;
    if (info->state == PARSE_STATE_STARTED)  /* request for new request or next XML response content */
    {
        mma_request_entry_struct *o_entry = NULL;
        mma_get_content_info_struct *o_info = NULL;

        if((o_entry = mma_get_entry_by_ilm_msg_id(entry->ilm_msg_id)) != NULL)  /* a request already accepted */
        {
            o_info = (mma_get_content_info_struct *) o_entry->entry_info;
            if(entry->req_id != o_entry->req_id)  /* reject the new request */
            {
                wap_send_wap_mma_get_content_rsp(info->app_id, entry->req_id, MMA_RESULT_FAIL_BUSY, info->msg_id, 0, 0,
                    0, NULL, info->buffer_index, 0, FALSE, NULL);
            }
            else if(o_info != NULL && info->buffer_index == o_info->buffer_index + 1) /* sending next XML response: buffer_index = 1+ */
            {
                o_info->buffer_index++;
                if (mma_get_mms_content_rsp(o_entry) == FALSE)
                {
                    req_dequeue(entry->req_id);
                }
            }
            else
            {
                ASSERT(0);
            }

            return;
        }
        else  /* accept the new request */
        {
            MMA_CALLOC(info, sizeof(mma_get_content_info_struct));
            memcpy(info, entry->entry_info, sizeof(mma_get_content_info_struct));
            entry->entry_info = info;
            req_enqueue(entry);
            entry = mma_get_entry_by_req_id(entry->req_id);
        }
    }

    /* Start Get Content FSM */
    while((ret = mma_get_mms_content_fsm(info)) == MMA_RESULT_CONTINUE);

    switch(ret)
    {
        case MMA_RESULT_OK:  /* return successful signal or delete aborted entry */
        {
            ASSERT(info->buffer_index == 0);
            ASSERT(info->state == PARSE_STATE_ABORTED || info->state == PARSE_STATE_FINISHED);
            if (info->state == PARSE_STATE_ABORTED)
            {
                req_dequeue(entry->req_id);
            }
            else
            {
                if (mma_get_mms_content_rsp(entry) == FALSE)
                {
                    req_dequeue(entry->req_id);
                }
            }
            break;
        }
        case MMA_RESULT_DELAYED:
            break;
        default:  /* return failed signal */
        {
            wap_send_wap_mma_get_content_rsp(info->app_id, entry->req_id, ret, info->msg_id, 0, 0, 0, NULL, 
                info->buffer_index, 0, FALSE, NULL);
            if(info->state != PARSE_STATE_ABORTED)  /* if aborted, entry cannot be deleted until finishing aborting procedure */
            {
                req_dequeue(entry->req_id);
            }
            break;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_create_mms_encode_subject
 * DESCRIPTION
 *  Encode subject
 *    1. Apply application encoding setting
 *    2. Adjust string for IOT
 * PARAMETERS
 *  subject        [IN/OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_create_mms_encode_subject(MmsEncodedText *subject)
{
    /* Adjust UTF8 subject */
    if ((NULL != subject->text) && (strlen(subject->text) > 0))
    {
        switch (MEAlib_getSubjectCharset())  /* Obey charset setting, so convert... */
        {
        case MMS_US_ASCII:
        {
            char *ascii_subject = NULL;
            long ascii_len = 0, utf8_len = 0;

            utf8_len = strlen(subject->text);
            if (0 != msf_charset_utf8_to_ascii(subject->text, &utf8_len, NULL, &ascii_len)) /* Get ASCII size */
            {
                break;  /* skip */
            }
            
            MMA_CALLOC(ascii_subject, ascii_len + 1);
            if (0 != msf_charset_utf8_to_ascii(subject->text, &utf8_len, ascii_subject, &ascii_len))
            {
                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MAIN_7649E2B7CCFCBB68235991EDCF3699A6, "(%s) (%d) Subject conversion failed!\n", 
                    __FILE__, __LINE__));
            }
            else
            {   
                *(ascii_subject + ascii_len) = '\0';
                MMA_FREE(subject->text);
                subject->text = ascii_subject;
                subject->charset = MMS_US_ASCII;

                /* IOT: Convert CRLF to space (RFC822: no CRLF for E-mail subject) */
                {
                    int i = 0, j = 0;
                    char *new_subject_p = msf_cmmn_strdup(MSF_MODID_MMA, subject->text);
                    
                    while(i < ascii_len + 1)
                    {
                        if(*(new_subject_p + i) == 0xD && *(new_subject_p + i + 1) == 0xA)
                        {
                            *(subject->text + j) = 0x20;
                            i++;
                        }
                        else
                        {
                            *(subject->text + j) = *(new_subject_p + i);
                        }
                        i++;
                        j++;
                    }
                    MMA_FREE(new_subject_p);
                }
            }
            break;
        }
        
        case MMS_UTF8:
        {
            int i = 0, len = 0;
            char *new_subject_p=NULL;

            ASSERT(subject->charset == MMS_UTF8);
            subject->charset=MMS_US_ASCII;
            len = strlen(subject->text);

            /* Add <Quote> tag if the 1st char value is between 128-255 (WAP_230_WSP_Spec) */
            if((unsigned short)*(subject->text) > 0x7F)
            {
                MMA_CALLOC(new_subject_p, len + 2);  /* Quote + NULL termination char */
                *new_subject_p = 0x7F;
                strcpy(new_subject_p + 1, subject->text);
                MMA_FREE(subject->text);
                subject->text = new_subject_p;
            }

            /* When text is of only ascii characters, set charset from utf-8 to us-ascii */
            while(i < len)
            {
                if((unsigned short)*(subject->text + i) > 0x7F)
                {
                    subject->charset = MMS_UTF8;                                     
                    break;
                }
                i++;
            }
            break;
        }
        
        default:
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, MMA_MAIN_0BE486F427E0DCF4EA37100F36A14487, "(%s) (%d) unsupported subject charset\n", 
                __FILE__, __LINE__));
            ASSERT(0);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_create_mms_create_smil
 * DESCRIPTION
 *  Create mms by specified information
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mma_result_enum mma_create_mms_create_smil(mma_body_struct *body, char **buffer, unsigned int *size)
{
    char            *smilBuffer = NULL;
    mma_slide_struct *curr;
    mma_result_enum ret = MMA_RESULT_OK;

    SlsRegion   textRegion;
    SlsRegion   imageRegion;
    SlsCreateSmilHandle handle = NULL;

    SlsMediaObject  *textObject;
    SlsMediaObject  *imageObject;
    SlsMediaObject  *audioObject;
    SlsMediaObject  *videoObject;
    
    *buffer = NULL;
    *size = 0;
    
    /* Set regions */
    textRegion.position.cx.value   = 0;
    textRegion.size.cx.value       = 100; 
    textRegion.position.cx.type    = SLS_REL;
    textRegion.position.cy.type    = SLS_REL;
    textRegion.size.cx.type        = SLS_REL;
    textRegion.size.cy.type        = SLS_REL;
    textRegion.fit = SLS_ATTR_SCROLL;

    imageRegion.position.cx.value  = 0;
    imageRegion.size.cx.value      = 100;
    imageRegion.position.cx.type   = SLS_REL;
    imageRegion.position.cy.type   = SLS_REL;
    imageRegion.size.cx.type       = SLS_REL;
    imageRegion.size.cy.type       = SLS_REL;
    imageRegion.fit = SLS_ATTR_MEET;

    if (body->layout == MMA_LAYOUT_TEXT_ON_TOP)
    {
        /* Text on top, image at the bottom */
        textRegion.position.cy.value   = 0;
        textRegion.size.cy.value       = 50;
        imageRegion.position.cy.value  = 50;
        imageRegion.size.cy.value      = 50;
    }
    else if (body->layout == MMA_LAYOUT_IMAGE_ON_TOP)
    {
        /* Image on top, text at the bottom */
        textRegion.position.cy.value   = 50;
        textRegion.size.cy.value       = 50;
        imageRegion.position.cy.value  = 0;
        imageRegion.size.cy.value      = 50;
    }
    else
    {
        /* Only one text or image region is displayed on each slide*/
        textRegion.position.cy.value   = 0;
        textRegion.size.cy.value       = 100;
        imageRegion.position.cy.value  = 0;
        imageRegion.size.cy.value      = 100;
    }
    
    /* Create the SMIL presentation */
    if (SLS_RESULT_OK != SLSlib_createSmil(MSF_MODID_MMA, &handle, &body->root_layout))
    {
        return MMA_RESULT_FAIL;
    }
    else if (SLS_RESULT_OK != SLSlib_createRegion(MSF_MODID_MMA, &handle, &imageRegion, 
        MEAlib_getSmilImageRegionName()))
    {
        (void)SLSlib_cancelCreateSmil(MSF_MODID_MMA, &handle);
        return MMA_RESULT_FAIL;
    }
    else if (SLS_RESULT_OK != SLSlib_createRegion(MSF_MODID_MMA, &handle, &textRegion, MEAlib_getSmilTextRegionName()))
    {
        (void)SLSlib_cancelCreateSmil(MSF_MODID_MMA, &handle);
        return MMA_RESULT_FAIL;
    }

    /* Get the first slide */
    curr = body->slides;
    
    /* Go through all slides */
    while (NULL != curr && ret != MMA_RESULT_FAIL)
    {
        /* Text */
        textObject = NULL;
        textObject = mma_create_sls_object_from_mma_slide_object(&curr->text);

        /* Image */
        imageObject = NULL;
        imageObject = mma_create_sls_object_from_mma_slide_object(&curr->image);

        /* Audio */
        audioObject = NULL;
        audioObject = mma_create_sls_object_from_mma_slide_object(&curr->audio);

        /* Video */
        videoObject = NULL;
        videoObject = mma_create_sls_object_from_mma_slide_object(&curr->video);

        /* Create the slide */
        if (SLS_RESULT_OK != SLSlib_createSlide(MSF_MODID_MMA, &handle, (int)curr->duration, textObject, imageObject, 
            videoObject, audioObject))
        {
            (void)SLSlib_cancelCreateSmil(MSF_MODID_MMA, &handle);
            ret = MMA_RESULT_FAIL;
        }

        /* Free Text object */
        if (textObject != NULL)
        {
            mma_free_sls_media_object(&textObject);
        }
        /* Free Image object */
        if (imageObject != NULL)
        {
           mma_free_sls_media_object(&imageObject);
        }
        /* Free Audio object */
        if (audioObject != NULL)
        {
           mma_free_sls_media_object(&audioObject);
        }
        /* Free Video object */
        if (videoObject != NULL)
        {
           mma_free_sls_media_object(&videoObject);
        }
        curr = curr->next;
    }

    if (ret != MMA_RESULT_FAIL)
    {
        if (SLS_RESULT_OK != SLSlib_generateSmil(MSF_MODID_MMA, &handle, (char **)&smilBuffer))
        {
            (void)SLSlib_cancelCreateSmil(MSF_MODID_MMA, &handle);
            ret = MMA_RESULT_FAIL;
        }
    }
    
    if (ret == MMA_RESULT_OK)
    {
        *buffer = smilBuffer;
        *size   = strlen(smilBuffer);
    }
    return ret;
} /* createSmil */

/*****************************************************************************
 * FUNCTION
 *  mma_create_mms_replace_fta_text
 * DESCRIPTION
 *  Replace the short-code text with FTA specified text
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_create_mms_replace_fta_text(mma_object_struct *obj)
{
    int fh = MSF_FILE_OPEN(MSF_MODID_MMA, obj->filePath, MSF_FILE_SET_RDONLY, 0);
    char *buffer =NULL;

    if (fh < 0)
    {
        return;
    }
    
    if (obj->isVirtualFile)
    {
        if (MSF_FILE_SEEK(fh, obj->offset, MSF_FILE_SEEK_SET) < 0)
        {
            MSF_FILE_CLOSE(fh);
            return;
        }
    }

    MMA_CALLOC(buffer, obj->size + 1);
    MSF_FILE_READ(fh, buffer, obj->size);
    MSF_FILE_CLOSE(fh);

    if(msf_cmmn_strcmp_nc(buffer,"fta_utf8") == 0)
    {
        const unsigned char mms_fta_utf[]={
            0x46, 0x72, 0x65, 0x6E, 0x63, 0x68, 0x20, 0xC3, 0xAA, 0x20, 0x68, 0x61, 0x73, 0x20, 0x61, 0x20,
            0x72, 0x6F, 0x6F, 0x66, 0x20, 0x6F, 0x76, 0x65, 0x72, 0x20, 0x74, 0x68, 0x65, 0x20, 0x65, 0x2E, 
            0x20, 0x47, 0x65, 0x72, 0x6D, 0x61, 0x6E, 0x20, 0xC3, 0xBC, 0x20, 0x69, 0x73, 0x20, 0x61, 0x20, 
            0x75, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x74, 0x77, 0x6F, 0x20, 0x64, 0x6F, 0x74, 0x73, 0x2E,
            0x20, 0x50, 0x6F, 0x6C, 0x69, 0x73, 0x68, 0x20, 0xC5, 0x82, 0x20, 0x69, 0x73, 0x20, 0x61, 0x6E,
            0x20, 0x6C, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x61, 0x20, 0x2F, 0x20, 0x61, 0x63, 0x72, 0x6F,
            0x73, 0x73, 0x2E, 0x00};
        int fh = MSF_FILE_OPEN(MSF_MODID_MMA, obj->filePath, MSF_FILE_SET_WRONLY, 0);  /* overwrite */

        if (fh < 0)
        {
            return;
        }
        MSF_FILE_WRITE(fh, (void *)mms_fta_utf, strlen((char *)mms_fta_utf) + 1);
        MSF_FILE_CLOSE(fh);
        obj->charset = MMS_UTF8;
        obj->size = strlen((char *)mms_fta_utf);
    }
    else if(msf_cmmn_strcmp_nc(buffer,"fta_usascii") == 0)
    {
        const unsigned char mms_fta_usascii[]={
            0x54, 
            0x68, 0x65, 0x20, 0x71, 0x75, 0x69, 0x63, 0x6B, 0x20, 0x62, 0x72, 0x6F, 0x77, 0x6E, 0x20, 0x66,
            0x6F, 0x78, 0x20, 0x6A, 0x75, 0x6D, 0x70, 0x65, 0x64, 0x20, 0x6F, 0x76, 0x65, 0x72, 0x20, 0x74,
            0x68, 0x65, 0x20, 0x6C, 0x61, 0x7A, 0x79, 0x20, 0x64, 0x6F, 0x67, 0x20, 0x31, 0x32, 0x33, 0x34,
            0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x2F, 0x21, 0x28, 0x29, 0x0D, 0x0A, 0x00};
            
        int fh = MSF_FILE_OPEN(MSF_MODID_MMA, obj->filePath, MSF_FILE_SET_WRONLY, 0);  /* overwrite */
        
        if (fh < 0)
        {
            return;
        }
        MSF_FILE_WRITE(fh, (void *)mms_fta_usascii, strlen((char *)mms_fta_usascii) + 1);
        MSF_FILE_CLOSE(fh);
        obj->charset = MMS_US_ASCII;
        obj->size = strlen((char *)mms_fta_usascii);
    }
    MMA_FREE(buffer);
}

/*****************************************************************************
 * FUNCTION
 *  mma_create_mms_init_mms
 * DESCRIPTION
 *  Initialize MMS the to-be-created MMS content
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_create_mms_init_mms(mma_create_mms_info_struct *info)
{
    info->header->header.s_header->fromType = MMS_FROM_INSERT_ADDRESS;

    /* set date here before setting other time-related fields */
    info->header->header.s_header->date = MSF_TIME_GET_CURRENT();
    info->header->header.s_header->date = HDIa_timeLocalToUTC(info->header->header.s_header->date);

    /* Set the layout */
    info->body->root_layout.bgColor = MEAlib_getDefaultSmilBgColor();
    info->body->root_layout.cx.type  = SLS_ABS;
    info->body->root_layout.cx.value = (MSF_UINT16)MEAlib_getDisplayWidth();
    info->body->root_layout.cy.type  = SLS_ABS;
    info->body->root_layout.cy.value = (MSF_UINT16)MEAlib_getDisplayHeight();
}

/*****************************************************************************
 * FUNCTION
 *  mma_create_mms_fsm
 * DESCRIPTION
 *  Create mms by specified information
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mma_result_enum mma_create_mms_fsm(mma_create_mms_info_struct *info)
{
    MmsSetHeader *s_header = NULL;
    int ret = MMA_RESULT_OK;

    ASSERT(info != NULL);

    switch(info->state)
    {
    case CREATE_STATE_STARTED:
    case CREATE_STATE_XML_PARSING:
        MMA_CALLOC(info->header, sizeof(mma_header_struct));
        MMA_CALLOC(info->header->header.s_header, sizeof(MmsSetHeader));
        MMA_CALLOC(info->body, sizeof(mma_body_struct));
        mma_create_mms_init_mms(info);
            
        if(mma_xml_parse_mms_xml_description_file(info) == MMA_RESULT_OK)
        {
             info->state = CREATE_STATE_CREATION_PREPROCESSING;
             /* fall-through */
        }
        else
        {
            ret = MMA_RESULT_FAIL_PARSE;
            break;
        }

    case CREATE_STATE_CREATION_PREPROCESSING:
    {
        mma_object_struct *obj = info->body->objects;
        while (obj)
        {
            if (mma_is_ascii_string(obj->fileName) == KAL_FALSE)  /* need to rename */
            {
                char *new_name = mma_create_name_from_nonascii_name(obj->fileName, KAL_FALSE);
                while(mma_get_object_from_name(info->body, new_name))
                {
                    MMA_FREE(new_name);
                    new_name = mma_create_name_from_nonascii_name(obj->fileName, KAL_TRUE);
                }
                MMA_FREE(obj->fileName);
                obj->fileName = new_name;
            }
            obj = obj->next;
        }
        info->state = CREATE_STATE_CREATING;
        /* fall-through */
    }

    case CREATE_STATE_CREATING:
        MMA_createMessage(MSF_MODID_MMA, MMS_SUFFIX_SEND_REQ);
        if(info->mode == MMA_MODE_SEND || info->mode == MMA_MODE_FORWARD)
        {
            info->state = CREATE_STATE_MMS_HEADER_PARSING;
        }
        else
        {
            info->state = CREATE_STATE_MMS_HEADER_CREATING;
        }
        ret = MMA_RESULT_DELAYED;
        break;

    case CREATE_STATE_MMS_HEADER_PARSING:
        switch(info->sub_state)  /* Here, sub_state is used to handle delayed file I/O */
        {
        case 0:
            if ((ret = MMSlib_transactionOpen(MSF_MODID_MMA, &info->t_handle)) != MMS_RESULT_OK)
            {
                ret = translate_mms_result_to_mma(ret);
                goto create_fsm_finished;
            } 
            else if ((ret = MMSlib_messageOpen(MSF_MODID_MMA, info->o_msg_id, fldrGetFileSuffix(info->o_msg_id), 
                &info->m_handle)) != MMS_RESULT_OK)
            {
                ret = translate_mms_result_to_mma(ret);
                goto create_fsm_finished;
            } 
            info->sub_state = 1;
            
        case 1:
            MMA_CALLOC(info->o_header, sizeof(MmsGetHeader));
            if((ret = MMSlib_getMessageHeader(MSF_MODID_MMA, info->o_header, &info->m_handle, &info->t_handle)) == 
                MMS_RESULT_DELAYED)
            {
                ret = translate_mms_result_to_mma(ret);
                goto create_fsm_finished;
            }
            else if (ret != MMS_RESULT_OK)
            {
                ret = translate_mms_result_to_mma(ret);
                goto create_fsm_finished;
            }
            (void)MMSlib_messageClose(MSF_MODID_MMA, &info->m_handle);
            (void)MMSlib_transactionClose(MSF_MODID_MMA, &info->t_handle);
        }
        info->state = CREATE_STATE_MMS_HEADER_CREATING;
        info->sub_state = 0;
        /* fallthrough */

    case CREATE_STATE_MMS_HEADER_CREATING:
        ASSERT(info->header != NULL && info->header->header.s_header != NULL && info->msg_id != 0);
        s_header = info->header->header.s_header;
        MMA_CALLOC(s_header->contentType, sizeof(MmsContentType));

        switch(info->sub_state)  /* Here, sub_state is used to handle delayed file I/O */
        {
        case 0:  /* Set body_no, contentType */
            if(info->mode == MMA_MODE_SEND || info->mode == MMA_MODE_FORWARD)
            {
                info->header->body_no = info->o_header->bodyInfoList.numOfEntries;
                copyContentType(MSF_MODID_MMA, s_header->contentType, info->o_header->bodyInfoList.contentType);
            }
            else
            {
                info->header->body_no = mma_get_total_item_count(info->body);
                if(info->body->slide_no > 0)  /* SMIL: multipart.related */
                {
                    info->header->body_no++;  /* Add SMIL presentation part */
                    s_header->contentType->knownValue = MMS_VND_WAP_MULTIPART_RELATED;
    
                    mma_add_param_string(&s_header->contentType->params, MMS_START_REL, MEAlib_getSmilContentId());
                    mma_add_param_string(&s_header->contentType->params, MMS_TYPE_REL, MMS_MEDIA_TYPE_STRING_SMIL);
                }
                else  /* Mixed: multipart.mixed */
                {
                    s_header->contentType->knownValue = MMS_VND_WAP_MULTIPART_MIXED;
                }
            }
            info->sub_state = 1;
            /* fall through */

        case 1:
            mma_create_mms_encode_subject(&s_header->subject);  /* adjust subject string */
            info->sub_state = 2;
            /* fall through */
            
        case 2:
            if ((ret = MMSlib_transactionOpen(MSF_MODID_MMA, &info->t_handle)) != MMS_RESULT_OK)
            {
                ret = translate_mms_result_to_mma(ret);
                goto create_fsm_finished;
            } 
            else if ((ret = MMSlib_messageOpen(MSF_MODID_MMA, info->msg_id, fldrGetFileSuffix(info->msg_id), 
                &info->m_handle)) != MMS_RESULT_OK)
            {
                ret = translate_mms_result_to_mma(ret);
                goto create_fsm_finished;
            } 
            info->sub_state = 3;
            /* fall through */
            
        case 3:
            ret = MMSlib_setMessageHeader(MSF_MODID_MMA, info->header->body_no, s_header, mma_conf_get_mmsc_version(),
                &info->m_handle, &info->t_handle);
            if (MMS_RESULT_DELAYED == ret)
            {
                ret = translate_mms_result_to_mma(ret);
                goto create_fsm_finished;
            }
            else if (MMS_RESULT_OK != ret)
            {
                ret = translate_mms_result_to_mma(ret);
                goto create_fsm_finished;
            }
//            (void)MMSlib_messageClose(MSF_MODID_MMA, &info->m_handle);
            (void)MMSlib_transactionClose(MSF_MODID_MMA, &info->t_handle);
        }

        if(info->mode == MMA_MODE_SEND || info->mode == MMA_MODE_FORWARD)
        {
            ret = MMA_RESULT_CONTINUE;
            info->state = CREATE_STATE_MMS_BODY_COPYING;
        }
        else
        {
            ret = MMA_RESULT_CONTINUE;
            info->state = CREATE_STATE_MMS_SMIL_CREATING;
        }
        info->sub_state = 0;
        break;
        
    case CREATE_STATE_MMS_BODY_COPYING:
    {
        switch (info->sub_state)
        {
        case 0:
        {
            char *r_path = NULL, *w_path = NULL;
            
            ASSERT(info->r_handle == 0 && info->w_handle == 0);
            r_path = MMSlib_getMessageFullPath(MSF_MODID_MMA, info->o_msg_id, fldrGetFileSuffix(info->o_msg_id));
            w_path = MMSlib_getMessageFullPath(MSF_MODID_MMA, info->msg_id, fldrGetFileSuffix(info->msg_id));

            info->r_handle = MSF_FILE_OPEN(MSF_MODID_MMA, r_path, MSF_FILE_SET_RDONLY, 0);
            MMA_FREE(r_path);
            if(info->r_handle < 0)
            {
                ret = MMA_RESULT_FAIL_FILE_IO;
                goto create_fsm_finished;
            }
            
            info->w_handle = MSF_FILE_OPEN(MSF_MODID_MMA, w_path, MSF_FILE_SET_WRONLY | MSF_FILE_SET_CREATE | 
                MSF_FILE_SET_APPEND, 0);  /* append */
            MMA_FREE(w_path);
            if (info->w_handle < 0)
            {
                ret = MMA_RESULT_FAIL_FILE_IO;
                goto create_fsm_finished;
            }

            info->sub_state = 1;
            /* fall through */
        }            

        case 1:
            /* SMIL or Multipart/Mixed message: skip the nEntries field because it's already added by 
               MMSlib_setMessageHeader(). Actually, it's not simply add/minus 1, should use uintvar length TO-DO!*/
            if (info->header->body_no > 0)
            {
                info->r_byte = info->o_header->bodyInfoList.size - 1;
                if (MSF_FILE_SEEK(info->r_handle, info->o_header->bodyInfoList.startPos + 1, MSF_FILE_SEEK_SET) < 0)
                {
                    ret = MMA_RESULT_FAIL_FILE_IO;
                    goto create_fsm_finished;
                }
            }
            else  /* Text/Plain Message, just copy */
            {
                info->r_byte = info->o_header->bodyInfoList.size;
                if (MSF_FILE_SEEK(info->r_handle, info->o_header->bodyInfoList.startPos, MSF_FILE_SEEK_SET) < 0)
                {
                    ret = MMA_RESULT_FAIL_FILE_IO;
                    goto create_fsm_finished;
                }
            }
            info->w_byte = info->r_byte;
            info->sub_state = 2;
            /* fall through */
            
        case 2:
        {
            char *buffer = NULL;
            kal_int32 to_read = (info->r_byte < MMS_MAX_CHUNK_SIZE) ? info->r_byte : MMS_MAX_CHUNK_SIZE;
            MMA_CALLOC(buffer, to_read);
            if (MSF_FILE_READ(info->r_handle, buffer, to_read) < 0 || 
                MSF_FILE_WRITE(info->w_handle, buffer, to_read) < 0)
            {
                MMA_FREE(buffer);
                ret = MMA_RESULT_FAIL_FILE_IO;
                goto create_fsm_finished;
            }
            info->r_byte -= to_read;
            info->w_byte -= to_read;
            if (info->r_byte == 0 && info->w_byte == 0)  /* Copy done! */
            {
                MMA_FREE(buffer);
                MSF_FILE_CLOSE(info->r_handle);
                MSF_FILE_CLOSE(info->w_handle);
                info->r_handle = 0;
                info->w_handle = 0;
                info->state = CREATE_STATE_MMS_INFO_CREATING;
                ret = MMA_RESULT_CONTINUE;
            }
            else
            {
                /* We don't finish all I/O at one time, but divide as several rounds... */
                MMA_SIGNAL_SENDTO(MMA_SIG_CREATE_CONTINUE);
                MMA_FREE(buffer);
                ret = MMA_RESULT_DELAYED;
            }
            break;
        }
        }
        break;
    }

    case CREATE_STATE_MMS_SMIL_CREATING:
    {
        kal_char *smil_buffer = NULL;
        MmsBodyParams *param = NULL;
        kal_uint32 size = 0;
        if ((ret = mma_create_mms_create_smil(info->body, (char **)&smil_buffer, &size)) != MMA_RESULT_OK)
        {
            ret = MMA_RESULT_FAIL;
            break;
        }
        else if ((param = mma_create_body_params(MMS_VALUE_AS_STRING, (char *)MMS_MEDIA_TYPE_STRING_SMIL, 
            (unsigned char *)MEAlib_getSmilFileName(), MMS_UTF8)) == NULL)  /* Create body params */
        {
            MMA_FREE(smil_buffer);
            ret = MMA_RESULT_FAIL;
            break;
        }
        else if ((ret = MMSlib_transactionOpen(MSF_MODID_MMA, &info->t_handle)) != MMS_RESULT_OK)  /* Write message */
        {
            MMA_FREE(smil_buffer);
            mma_free_body_params(&param);
            ret = translate_mms_result_to_mma(ret);
            break;
        } 
        else if ((ret = MMSlib_setMessageBody(MSF_MODID_MMA, param, (unsigned char *)smil_buffer, size, &info->m_handle, 
            &info->t_handle)) != MMS_RESULT_OK)
        {
            MMA_FREE(smil_buffer);
            mma_free_body_params(&param);
            ret = translate_mms_result_to_mma(ret);
            break;
        }
        
        MMA_FREE(smil_buffer);
        mma_free_body_params(&param);
        if ((ret = MMSlib_transactionClose(MSF_MODID_MMA, &info->t_handle)) != MMS_RESULT_OK)
        {
            ret = translate_mms_result_to_mma(ret);
            break;
        }
        
        info->body->current_object = info->body->objects;
        info->state = CREATE_STATE_MMS_BODY_CREATING;
        /* fall-througfh */
    }
    
    case CREATE_STATE_MMS_BODY_CREATING:
    {
        MmsBodyParams *param = NULL;

        if (info->body->current_object == NULL)
        {
            info->state = CREATE_STATE_MMS_INFO_CREATING;
            /* fall-through */
        }
        else if (info->body->current_object->size == 0)
        {
            info->body->current_object = info->body->current_object->next;
            MMA_SIGNAL_SENDTO(MMA_SIG_CREATE_CONTINUE);
            ret = MMA_RESULT_DELAYED;
            break;
        }
        else
        {
            switch (info->sub_state)
            {
            case 0:
            {
                MmsKnownMediaType type = mma_get_mmsKnownMediaType_from_mime_type(info->body->current_object->mimeType);
        
                /* For FTA test only */
#ifdef __GEMINI__
                if(is_test_sim(0x00) && info->body->current_object->type == SLS_TEXT_PLAIN)
#else
                if(is_test_sim() && info->body->current_object->type == SLS_TEXT_PLAIN)
#endif
                {
                    mma_create_mms_replace_fta_text(info->body->current_object);
                }
        
                /* Create body params if they are not previously created */
                if (NULL == (param = mma_create_body_params(type, info->body->current_object->mimeType, 
                    (unsigned char *)info->body->current_object->fileName, info->body->current_object->charset)))
                {
                    ret = MMA_RESULT_FAIL;
                    goto create_fsm_finished;;
                }
                else if ((ret = MMSlib_transactionOpen(MSF_MODID_MMA, &info->t_handle)) != MMS_RESULT_OK)  /* Write message */
                {
                    mma_free_body_params(&param);
                    ret = translate_mms_result_to_mma(ret);
                    goto create_fsm_finished;;
                } 
    
                info->sub_state = 1;
                /* fall through */
            }
            
            case 1:  /* write body entry header */
                ASSERT(info->r_handle == 0 && info->r_byte == 0);

                info->r_handle = MSF_FILE_OPEN(MSF_MODID_MMA, info->body->current_object->filePath, 
                    MSF_FILE_SET_RDONLY, 0);

                if (info->r_handle < 0)
                {
                    mma_free_body_params(&param);
                    ret = translate_fs_result_to_mma(info->r_handle);
                    goto create_fsm_finished;;
                }
                else if (info->body->current_object->isVirtualFile == KAL_TRUE)
                {
                    if (MSF_FILE_SEEK(info->r_handle, info->body->current_object->offset, MSF_FILE_SEEK_SET) < 0)
                    {
                        mma_free_body_params(&param);
                        ret = MMA_RESULT_FAIL_FILE_IO;
                        goto create_fsm_finished;;
                    }
                }

                if ((ret = MMSlib_setMessageBody(MSF_MODID_MMA, param, NULL, info->body->current_object->size, 
                    &info->m_handle, &info->t_handle)) != MMS_RESULT_OK)  /* only finish state 1~2 */
                {
                    mma_free_body_params(&param);
                    ret = MMA_RESULT_FAIL_FILE_IO;
                    goto create_fsm_finished;;
                }
                mma_free_body_params(&param);
                info->sub_state = 2;
                /* fall through */
                
            case 2:  /* write body data; may re-enter... */
            {
                char *buffer = NULL;
                int to_read = 0, byte_read = 0;
                MmsBodyParams dummy;
                
                to_read = ((info->body->current_object->size - info->r_byte) > MMS_MAX_CHUNK_SIZE) ? 
                    MMS_MAX_CHUNK_SIZE : (info->body->current_object->size - info->r_byte);
                if (to_read > 0)
                {
                    MMA_CALLOC(buffer, to_read);
                    if ((byte_read = MSF_FILE_READ(info->r_handle, buffer, to_read)) < 0)
                    {
                        MMA_FREE(buffer);
                        ret = MMA_RESULT_FAIL_FILE_IO;
                        goto create_fsm_finished;;
                    }
                    else
                    {
                        ASSERT(byte_read == to_read);
                        info->r_byte += byte_read;
                    }

                    ASSERT(((MmsTransaction *)info->t_handle)->state == 3);
                    /* Manually set value for MMSlib_setMessageBody() state 3, a little bit dirty... */
                    ((MmsTransaction*)info->t_handle)->bufferPos = buffer;
                    ((MmsTransaction*)info->t_handle)->bytesLeft = byte_read;
                    ((MmsTransaction*)info->t_handle)->filePos = -1;
                    
                    if ((ret = MMSlib_setMessageBody(MSF_MODID_MMA, &dummy, (unsigned char *)buffer, byte_read, &info->m_handle, 
                        &info->t_handle)) != MMS_RESULT_OK)
                    {
                        MMA_FREE(buffer);
                        ret = MMA_RESULT_FAIL_FILE_IO;
                        goto create_fsm_finished;;
                    }
                }

                if (info->r_byte >= info->body->current_object->size) /* proceed to next object */
                {
                    if ((ret = MMSlib_transactionClose(MSF_MODID_MMA, &info->t_handle)) != MMS_RESULT_OK)
                    {
                        ret = translate_mms_result_to_mma(ret);
                        goto create_fsm_finished;
                    }

                    MSF_FILE_CLOSE(info->r_handle);
                    info->r_handle = 0;
                    info->r_byte = 0;
                    info->sub_state = 0;
                    info->body->current_object = info->body->current_object->next;
                    MMA_SIGNAL_SENDTO(MMA_SIG_CREATE_CONTINUE);

                    MMA_FREE(buffer);
                    ret = MMA_RESULT_DELAYED;
                    goto create_fsm_finished;;
                }
                else  /* we need next write for this object... */
                {
                    MMA_SIGNAL_SENDTO(MMA_SIG_CREATE_CONTINUE);
                    MMA_FREE(buffer);
                    ret = MMA_RESULT_DELAYED;
                    goto create_fsm_finished;;
                }
            }
            }
        }
    }

    case CREATE_STATE_MMS_INFO_CREATING:
        if((ret = MMSlib_messageClose(MSF_MODID_MMA, &info->m_handle)) != MMS_RESULT_OK)
        {
            ret = translate_mms_result_to_mma(ret);
            break;
        }
        MMA_createMessageDone(MSF_MODID_MMA, info->msg_id, MMS_HIDDEN);
        info->state = CREATE_STATE_MMS_FINALIZING;
        ret = MMA_RESULT_DELAYED;
        break;

    case CREATE_STATE_MMS_FINALIZING:
        genChkSumFile((MmsMsgId)info->msg_id);
        /* fall-through */
        
    case CREATE_STATE_FINISHED:
        ret = MMA_RESULT_OK;
        break;
    }

create_fsm_finished:
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MAIN_CA41DE149BE6FAA46D7A2910F3D81B01, "(%s) (%d) mma_create_mms_fsm(): state %d, ret %d\n", 
            __FILE__, __LINE__, info->state, ret));
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mma_create_mms
 * DESCRIPTION
 *  Create mms content by specified information
 * PARAMETERS
 *  entry    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_create_mms(mma_request_entry_struct *entry)
{
    mma_create_mms_info_struct *info = NULL;

    ASSERT(entry != NULL && entry->entry_info != NULL);
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MAIN_1870B8DB0ACCB52081D30C26DFC988F9, "(%s) (%d) mma_create_mms(%d)\n", __FILE__, __LINE__, 
        entry->req_id));

    info = entry->entry_info;
    if (info->state == CREATE_STATE_STARTED)
    {
        mma_request_entry_struct *o_entry = NULL;
        mma_create_mms_info_struct *o_info = NULL;
        if ((o_entry = mma_get_entry_by_ilm_msg_id(entry->ilm_msg_id)) != NULL)
        {
            o_info = (mma_create_mms_info_struct *) o_entry->entry_info;
            if(entry->req_id != o_entry->req_id)  /* Only one CREATE_REQ at a time */
            {
                wap_send_wap_mma_create_rsp(info->app_id, entry->req_id, MMA_RESULT_FAIL_BUSY, 0, info->buffer_index);
                return;
            }
            else if(o_info != NULL && info->buffer_index == o_info->buffer_index + 1) /* buffer_index = 1+ */
            {
                o_info->buffer_index++;
            }
            else
            {
                ASSERT(0);
            }
        }
        else if(info->buffer_index == 0) /* buffer_index = 0 */
        {
            kal_uint8 *ucs2_path = NULL;
            
            MMA_CALLOC(info, sizeof(mma_create_mms_info_struct));
            memcpy(info, entry->entry_info, sizeof(mma_create_mms_info_struct));
            
            if(info->mode == MMA_MODE_SEND || info->mode == MMA_MODE_FORWARD)
            {
                ASSERT(info->o_msg_id != 0);
            }
            else
            {
                ASSERT(info->o_msg_id == 0);
            }

            ucs2_path = (kal_uint8 *)info->xml_filepath;
            info->xml_filepath = (kal_wchar *)widget_ucs2_strdup(MSF_MODID_MMA, ucs2_path);

            entry->entry_info = info;
            req_enqueue(entry);
            entry = mma_get_entry_by_req_id(entry->req_id);
        }
        else
        {
            ASSERT(0);
        }
        
        if(info->more == KAL_TRUE)
        {
            wap_send_wap_mma_create_rsp(info->app_id, entry->req_id, MMA_RESULT_OK, 0, info->buffer_index + 1);
            return;
        }
        else if(mma_get_mmi_file_size(info->xml_filepath) != info->xml_size)
        {
            ASSERT(0);
        }
        else
        {
            entry = mma_get_entry_by_ilm_msg_id(entry->ilm_msg_id);
            info = (mma_create_mms_info_struct *) entry->entry_info;
        }
    }

    /* Srart Create FSM */
    while((info->result = mma_create_mms_fsm(info)) == MMA_RESULT_CONTINUE);

    switch(info->result)
    {
        case MMA_RESULT_DELAYED:
            break;
        default:
        {
            wap_send_wap_mma_create_rsp(info->app_id, entry->req_id, info->result, info->msg_id, info->buffer_index);
            req_dequeue(entry->req_id);
            break;
        }
    }

}

/*****************************************************************************
 * FUNCTION
 *  mma_preview_mms_fsm
 * DESCRIPTION
 *  Preview mms by specified information
 * PARAMETERS
 *  entry    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mma_result_enum mma_preview_mms_fsm(mma_preview_mms_info_struct *info)
{
    int ret = MMA_RESULT_OK;

    ASSERT(info != NULL);
    switch(info->state)
    {
    case PREVIEW_STATE_STARTED:
        if(smaIsRunning() == TRUE)
        {
            ret = MMA_RESULT_FAIL_BUSY;
            info->state = PREVIEW_STATE_FINISHED;
            break;
        }
        info->state = PREVIEW_STATE_SMA_ACTIVATING;
        /* fallthrough*/
        
    case PREVIEW_STATE_SMA_ACTIVATING:
        MSF_MODULE_START(MSF_MODID_MMA, MSF_MODID_SMA, NULL, NULL, NULL);
        ret = MMA_RESULT_DELAYED;
        info->state = PREVIEW_STATE_SMIL_PLAYING;
        break;
        
    case PREVIEW_STATE_SMIL_PLAYING:
        (void)SMAif_playSmil(MSF_MODID_MMA, info->msg_id, fldrGetFileSuffix(info->msg_id));
        ret = MMA_RESULT_DELAYED;
        /* state evolvement depends on SMA response: SMA_SIG_PLAY_SMIL_RSP or SMA_SIG_PLAY_SMIL_IND */
        break;
        
    case PREVIEW_STATE_SMIL_PLAYED:
    case PREVIEW_STATE_SMA_DEACTIVATING:
        MSF_MODULE_TERMINATE(MSF_MODID_MMA, MSF_MODID_SMA);
        ret = MMA_RESULT_DELAYED;
        info->state = PREVIEW_STATE_SMA_DEACTIVATED;
        break;
    case PREVIEW_STATE_SMA_DEACTIVATED:
        info->state = PREVIEW_STATE_FINISHED;
        /* fallthrough */
    case PREVIEW_STATE_FINISHED:
        ret = MMA_RESULT_OK;
    }
    
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MAIN_BCEA77DFF7BB875EAF22D7DDCB9DCD91, "(%s) (%d) mma_preview_mms_fsm(): state %d, ret %d\n", 
            __FILE__, __LINE__, info->state, ret));
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mma_preview_mms
 * DESCRIPTION
 *  Preview mms by specified information
 * PARAMETERS
 *  entry    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_preview_mms(mma_request_entry_struct *entry)
{
    mma_result_enum ret = MMA_RESULT_OK;
    mma_preview_mms_info_struct *info = NULL;

    ASSERT(entry != NULL && entry->entry_info != NULL);
    info = entry->entry_info;

    if(info->state == PREVIEW_STATE_STARTED)
    {
        if(mma_get_entry_by_ilm_msg_id(entry->ilm_msg_id) != NULL)  /* Only one PREVIEW_REQ at a time */
        {
            wap_send_wap_mma_preview_rsp(info->app_id, entry->req_id, MMA_RESULT_FAIL_BUSY, info->msg_id);
            return;
        }
        else
        {
            MMA_CALLOC(info, sizeof(mma_preview_mms_info_struct));
            memcpy(info, entry->entry_info, sizeof(mma_preview_mms_info_struct));
            entry->entry_info = info;
            req_enqueue(entry);
            entry = mma_get_entry_by_req_id(entry->req_id);
        }
    }

    /* Start Preview FSM */
    while((ret = mma_preview_mms_fsm(info)) == MMA_RESULT_CONTINUE);
    switch(ret)
    {
        case MMA_RESULT_DELAYED:
            break;
        case MMA_RESULT_OK:
            /*Response send when SMA_SIG_PLAY_SMIL_IND*/
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MAIN_283332148DD3F1214595F7FE8A453698, "(%s) (%d) mma_preview_mms(%d): msg %d, ret %d\n", 
                __FILE__, __LINE__, entry->req_id, info->msg_id, ret));
            req_dequeue(entry->req_id);
            break;
        default:  /* Failed */
        {
            wap_send_wap_mma_preview_rsp(info->app_id, entry->req_id, ret, info->msg_id);
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MAIN_283332148DD3F1214595F7FE8A453698, "(%s) (%d) mma_preview_mms(%d): msg %d, ret %d\n", 
                __FILE__, __LINE__, entry->req_id, info->msg_id, ret));
            req_dequeue(entry->req_id);
            break;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_move_mms
 * DESCRIPTION
 *  Move mms to specified folder
 * PARAMETERS
 *  entry    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_move_mms(mma_request_entry_struct *entry)
{
    mma_move_mms_info_struct *info = NULL;

    ASSERT(entry != NULL && entry->entry_info != NULL);
    
    MMA_CALLOC(info, sizeof(mma_move_mms_info_struct));
    memcpy(info, entry->entry_info, sizeof(mma_move_mms_info_struct));
    entry->entry_info = info;
    req_enqueue(entry);
    entry = mma_get_entry_by_req_id(entry->req_id);

    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MAIN_BAB2AEDA345BFA820F6E8E9251232EC3, "(%s) (%d) mma_move_mms(%d): msg %d, folder %d\n", 
        __FILE__, __LINE__, entry->req_id, info->msg_id, info->folder));

    if(MMA_IS_FOLDER_EXIST(info->folder) != KAL_TRUE)
    {
        wap_send_wap_mma_save_rsp(info->app_id, entry->req_id, MMA_RESULT_FAIL_FOLDER_NOT_FOUND, info->msg_id);
        req_dequeue(entry->req_id);
    }
    else
    {
        MMA_moveMessage(MSF_MODID_MMA, info->msg_id, wap_translate_mma_folder_2_mms_folder(info->folder));
        mmsUpdateIndicator();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_cancel_send_mms
 * DESCRIPTION
 *  Cancel mms sending by specified information
 *  Only one request at a time since it would be handled immediately and alter original request handling order
 * PARAMETERS
 *  entry    [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
void mma_cancel_send_mms(mma_request_entry_struct *entry)
{
    mma_cancel_send_mms_info_struct *info = NULL;

    ASSERT(entry != NULL && entry->entry_info != NULL);
    if(mma_get_entry_by_ilm_msg_id(entry->ilm_msg_id) != NULL)  /* Only one CANCEL_SEND_REQ at a time */
    {
        info = entry->entry_info;
        wap_send_wap_mma_cancel_send_rsp(info->app_id, entry->req_id, MMA_RESULT_FAIL_BUSY, info->msg_id);
        return;
    }
    else
    {
        MMA_CALLOC(info, sizeof(mma_move_mms_info_struct));
        memcpy(info, entry->entry_info, sizeof(mma_move_mms_info_struct));
        entry->entry_info = info;
        req_enqueue(entry);
        MMA_sendCancel(MSF_MODID_MMA, info->msg_id);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_download_mms
 * DESCRIPTION
 *  Start a deferred download
 * PARAMETERS
 *  entry    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_download_mms(mma_request_entry_struct *entry)
{
    mma_download_mms_info_struct *info = NULL;

    ASSERT(entry != NULL && entry->entry_info != NULL);
    info = entry->entry_info;
    if(mma_get_entry_by_ilm_msg_id(entry->ilm_msg_id) != NULL)  /* Only one DOWNLOAD_REQ at a time */
    {
        wap_send_wap_mma_download_rsp(info->app_id, entry->req_id, MMA_RESULT_FAIL_BUSY, 0);
    }
/* modify by travis */
    else if (fldrGetFileSuffix((MmsMsgId)((kal_uint32)info->notif_id)) != MMS_SUFFIX_NOTIFICATION)
    {
        wap_send_wap_mma_download_rsp(info->app_id, entry->req_id, MMA_RESULT_FAIL_FILE_NOT_FOUND, 0);
    }
    else
    {
        MMA_CALLOC(info, sizeof(mma_download_mms_info_struct));
        memcpy(info, entry->entry_info, sizeof(mma_download_mms_info_struct));
        entry->entry_info = info;
        req_enqueue(entry);
    
        MSF_LOG_MSG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, "mma_download_mms(%d): msg %d\n", entry->req_id, 
            info->notif_id));
        MMSif_retrieveMessage(MSF_MODID_MMA, info->notif_id);  /* exclusive from MEA usage, so no need for wrapper */
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_cancel_download_mms
 * DESCRIPTION
 *  Cancel the current deferred download
 * PARAMETERS
 *  entry    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_cancel_download_mms(mma_request_entry_struct *entry)
{
    mma_request_entry_struct *dl_entry = NULL;
    mma_download_mms_info_struct *dl_info = NULL;
    mma_cancel_download_info_struct *info = NULL;

    ASSERT(entry != NULL && entry->entry_info != NULL);
    info = entry->entry_info;
    if(mma_get_entry_by_ilm_msg_id(entry->ilm_msg_id) != NULL)  /* Only one CANCEL_DOWNLOAD_REQ at a time */
    {
        wap_send_wap_mma_cancel_download_rsp(info->app_id, entry->req_id, MMA_RESULT_FAIL_BUSY, 0);
    }
    else if (fldrGetFileSuffix((MmsMsgId)info->msg_id != MMS_SUFFIX_NOTIFICATION))
    {
        wap_send_wap_mma_cancel_download_rsp(info->app_id, entry->req_id, MMA_RESULT_FAIL_FILE_NOT_FOUND, 0);
    }
    else if (((dl_entry = mma_get_entry_by_ilm_msg_id(MSG_ID_WAP_MMA_DOWNLOAD_REQ)) == NULL) || 
        ((dl_info = dl_entry->entry_info) == NULL) || (dl_info->notif_id != info->msg_id))
    {
        wap_send_wap_mma_cancel_download_rsp(info->app_id, entry->req_id, MMA_RESULT_FAIL_INVALID_MSGID, 0);
    }
    else
    {
        mma_cancel_download_info_struct *info = NULL;
        MMA_CALLOC(info, sizeof(mma_cancel_download_info_struct));
        memcpy(info, entry->entry_info, sizeof(mma_cancel_download_info_struct));
        entry->entry_info = info;
        req_enqueue(entry);
    
        MSF_LOG_MSG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, "mma_cancel_download_mms(%d): msg %d\n", 
            entry->req_id, info->msg_id));
        
        MMSif_retrieveCancel(MSF_MODID_MMA, info->msg_id);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_check_mms
 * DESCRIPTION
 *  Check mms existence by msg ID
 * PARAMETERS
 *  entry    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_check_mms(mma_request_entry_struct *entry)
{
    mma_check_mms_info_struct *info = NULL;
    kal_uint8 *exist_list = NULL, *exist_ptr = NULL;
    kal_uint16 *box_list = NULL, *box_ptr = NULL;
    kal_uint32 *check_ptr = NULL;
    kal_uint32 i = 0;

    ASSERT(entry != NULL && entry->entry_info != NULL);
    info = entry->entry_info;
    
    MMA_CALLOC(exist_list, MMA_MAX_MSG_ARRAY_NUM * sizeof(kal_uint8));
    MMA_CALLOC(box_list, MMA_MAX_MSG_ARRAY_NUM * sizeof(kal_uint16));
    check_ptr = info->msg_id_list;
    exist_ptr = exist_list;
    box_ptr = box_list;
    for(;i < MMA_MAX_MSG_ARRAY_NUM; i++, check_ptr++, exist_ptr++, box_ptr++)
    {
        if (*check_ptr)
        {
            *exist_ptr = checkMsgId(*check_ptr);
            *box_ptr = wap_translate_mms_folder_2_mma_folder(fldrGetFolderId(*check_ptr));
        }
    }
    wap_send_wap_mma_msg_is_valid_rsp(info->app_id, entry->req_id, MMA_RESULT_OK, exist_list, box_list);
    MMA_FREE(exist_list);
    MMA_FREE(box_list);
}

/*****************************************************************************
 * FUNCTION
 *  mma_delete_mms_fsm
 * DESCRIPTION
 *  Delete mms by specified information
 * PARAMETERS
 *  entry    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mma_result_enum mma_delete_mms_fsm(mma_delete_mms_info_struct *info)
{
    MmsResult mms_ret = MMS_RESULT_OK;
    int ret = MMA_RESULT_OK;
    kal_uint32 msg_id = info->msg_id;

    ASSERT(info != NULL);
    switch(info->state)
    {
    case DELETE_STATE_STARTED:
        if (info->msg_id == 0)
        {
            info->state = DELETE_STATE_FINISHED;
            ret = MMA_RESULT_FAIL_FILE_NOT_FOUND;
        }
        else if(info->msg_id == 0xFFFFFFFF)  /* all message should be deleted */
        {
            info->state = DELETE_STATE_FOLDER_LIST_GETTING;
            ret = MMA_RESULT_CONTINUE;
        }
        else
        {
            info->state = DELETE_STATE_DELETING;
            ret = MMA_RESULT_CONTINUE;
        }
        break;

    case DELETE_STATE_FOLDER_LIST_GETTING:
        MMA_getFolderContent(MSF_MODID_MMA, wap_translate_mma_folder_2_mms_folder(info->box), 0, mma_conf_get_max_mms_no());
        info->state = DELETE_STATE_FOLDER_LIST_DELETING_LOOP;
        ret = MMA_RESULT_DELAYED;
        break;
        
    case DELETE_STATE_FOLDER_LIST_DELETING_LOOP:
        if(info->list == NULL || info->curr >= info->list->noOfElements)
        {
            info->state = DELETE_STATE_FINISHED;
            ret = MMA_RESULT_OK;
            break;
        }
        else
        {
            msg_id = info->list->msgPropertyList[info->curr++].msgFolderInfo.msgId;
            info->state = DELETE_STATE_DELETING;
            /* fallthrough */
        }
        
    case DELETE_STATE_DELETING:
        if(mma_send_is_msg_sending(msg_id) == KAL_TRUE || mma_send_is_msg_pending(msg_id) == KAL_TRUE)
        {
            info->state = DELETE_STATE_FINISHED;
            ret = MMA_RESULT_FAIL_FILE_IN_USE;
        }
        else if((mms_ret = fldrMgrDeleteMessage(msg_id)) != MMS_RESULT_OK)
        {
            info->state = DELETE_STATE_FINISHED;
            ret = translate_mms_result_to_mma(mms_ret);
        }
        else
        {
#ifdef MMS_FILE_PROTECT_SUPPORT
            delChkSumFile(msg_id);
#endif        
            if(mmcIsJSRMsg(msg_id))
            {
                mmcRemoveMsgIdFromJSRIndex(msg_id);
            }

            if(info->list != NULL)
            {
                info->state = DELETE_STATE_FOLDER_LIST_DELETING_LOOP;
                ret = MMA_RESULT_CONTINUE;
            }
            else
            {
                mmsUpdateIndicator();
                info->state = DELETE_STATE_FINISHED;
                ret = MMA_RESULT_OK;
            }
        }
        break;
    case DELETE_STATE_FINISHED:
        break;
    }

    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MAIN_A1AB028DA7BD2066D9539CB0E3695E72, "(%s) (%d) mma_delete_mms_fsm(): state %d, ret %d\n", 
            __FILE__, __LINE__, info->state, ret));
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mma_delete_mms
 * DESCRIPTION
 *  Delete mms by specified information
 * PARAMETERS
 *  entry    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_delete_mms(mma_request_entry_struct *entry)
{
    mma_result_enum ret = MMA_RESULT_OK;
    mma_delete_mms_info_struct *info = NULL;
 
    ASSERT(entry != NULL && entry->entry_info != NULL);

    info = entry->entry_info;
    if (info->state == DELETE_STATE_STARTED)
    {
        MMA_CALLOC(info, sizeof(mma_delete_mms_info_struct));
        memcpy(info, entry->entry_info, sizeof(mma_delete_mms_info_struct));
        entry->entry_info = info;
        req_enqueue(entry);
        entry = mma_get_entry_by_req_id(entry->req_id);
    }

    /* Start delete FSM */
    while((ret = mma_delete_mms_fsm(info)) == MMA_RESULT_CONTINUE);
    switch(ret)
    {
        case MMA_RESULT_DELAYED:
            break;
        case MMA_RESULT_OK:  /* successful or failed case go here */
        default:
        {
            wap_send_wap_mma_delete_rsp(info->app_id, entry->req_id, ret, info->msg_id);
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MAIN_17717FECC624C069300C202537CF9DED, "(%s) (%d) mma_delete_mms(%d): msg %d, ret %d\n", 
                __FILE__, __LINE__, entry->req_id, info->msg_id, ret));
            req_dequeue(entry->req_id);
            break;
        }
    }

}

/*****************************************************************************
 * FUNCTION
 *  mma_main_signal_handler
 * DESCRIPTION
 *  nternal signal handler
 * PARAMETERS
 *  sig    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_main_signal_handler( MmaSignal *sig)
{
    mma_request_entry_struct *entry = NULL;
    
    switch (sig->type) 
    {
    case MMA_SIG_CREATE_CONTINUE:
        entry = mma_get_entry_by_ilm_msg_id(MSG_ID_WAP_MMA_CREATE_REQ);
        mma_create_mms(entry);
        break;
    default:
        MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, 
            MMA_MAIN_95A8E844CEDF99AF00FA655FFBAA9E7B, "mma_main_signal_handler(): Received unknown signal: %d\n", sig->type));
    }
    mma_signal_delete(sig);
}



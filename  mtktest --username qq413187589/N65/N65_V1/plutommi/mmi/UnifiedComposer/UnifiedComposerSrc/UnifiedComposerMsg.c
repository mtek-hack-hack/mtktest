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
 * UnifiedComposerMsg.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements handlers to process primitives.
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
#ifndef _MMI_UNIFIED_COMPOSER_MSG_C
#define _MMI_UNIFIED_COMPOSER_MSG_C

#ifdef __MMI_UNIFIED_COMPOSER__

#include "FileManagerGProt.h"
#include "FileMgr.h"
#include "mdi_datatype.h"

/* micha1230 */
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"
#include "MessagesResourceData.h"

/* other files */
#include "ProtocolEvents.h"
#include "SettingProfile.h"
#include "IdleAppProt.h"

#include "AlarmFrameWorkProt.h"

#include "Conversions.h"

#include "DataAccountResDef.h"
#include "PhoneBookGprot.h"

#include "GpioInc.h"
#include "ProfileGprots.h"

#include "MemPoolContainerProt.h"
#include "CommonScreens.h"

#include "MessagesMiscell.h"
#include "SmsPsHandler.h"
#include "app_asyncfile.h"

#include "wapadp.h"
#include "mmsadp.h"
#include "wap_ps_struct.h"
#include "custom_wap_config.h"
#include "xml_def.h"

#include "customer_ps_inc.h"
#include "custom_uc_config.h"
#include "UnifiedComposerResDef.h"
#include "UnifiedComposerGProt.h"
#include "UnifiedComposerProt.h"

#if (defined(__MMI_MMS_2__) || defined(__MMI_MMS_BGSR_SUPPORT__))
#include "MMSViewerAPPDefs.h"
extern void mmi_umms_entry_send_msg(const U32 msg_id);
#endif /* __MMI_MMS_2__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_set_protocol_event_handler
 * DESCRIPTION
 *  Set protocol event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_set_protocol_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_uc_start_req, MSG_ID_WAP_MMA_UC_START_REQ);
    SetProtocolEventHandler(mmi_uc_get_mms_setting_rsp, MSG_ID_WAP_MMA_GET_SETTING_RSP);
    SetProtocolEventHandler(mmi_uc_preview_mms_rsp, MSG_ID_WAP_MMA_PREVIEW_RSP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_start_req
 * DESCRIPTION
 *  Handler for start UC request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_start_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_uc_start_req_struct *msg_req = (wap_mma_uc_start_req_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetExitScrnID() == SCR_ID_UC_EDITOR || IsScreenPresent(SCR_ID_UC_EDITOR))
    {
        mmi_uc_start_rsp(MMA_RESULT_FAIL_BUSY, msg_req->msg_id, msg_req->mode);
    } 
    else
    {
        mmi_uc_reset_msg();
        g_uc_p->main.state = mmi_uc_convert_mms_app_mode_to_uc_state(msg_req->mode);
        g_uc_p->send_info.existed_msg_id = msg_req->msg_id;
        g_uc_p->send_info.existed_msg_type = MMI_UC_MSG_TYPE_MMS_PREFER;
        
        mmi_uc_start_rsp(MMA_RESULT_OK, msg_req->msg_id, msg_req->mode);
        
        g_uc_p->msg_type.setting_msg_type = mmi_uc_get_setting_msg_type();        
        g_uc_p->msg_type.curr_msg_type = g_uc_p->msg_type.setting_msg_type;
        g_uc_p->msg_type.caller_specific_msg_type = MMI_UC_MSG_TYPE_DEFAULT;
        g_uc_p->msg_type.backup_msg_type = MMI_UC_MSG_TYPE_DEFAULT;
        
        mmi_uc_process_entry_write_msg();        
    }

    return;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_uc_start_rsp
 * DESCRIPTION
 *  Handler for start UC response
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_start_rsp(U16 result, U32 msg_id, U16 app_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_uc_start_rsp_struct *msg_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    msg_rsp = (wap_mma_uc_start_rsp_struct*) construct_local_para(sizeof(wap_mma_uc_start_rsp_struct), TD_CTRL | TD_RESET);
    
    msg_rsp->result = result;
    msg_rsp->mode = app_mode;
    msg_rsp->msg_id = msg_id;
    
    mmi_uc_send_message(
        MOD_MMI,
        MOD_WAP,
        0,
        MSG_ID_WAP_MMA_UC_START_RSP,
        (oslParaType*) msg_rsp,
        NULL);
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_get_mms_setting_req
 * DESCRIPTION
 *  Get MMS setting request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_get_mms_setting_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_setting_req_struct *msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->send_info.request_id = wap_mma_get_request_id();
    
    msg_req = (wap_mma_get_setting_req_struct*) construct_local_para(sizeof(wap_mma_get_setting_req_struct), TD_CTRL | TD_RESET);
    msg_req->req_id = g_uc_p->send_info.request_id;
    
    mmi_uc_send_message(
        MOD_MMI,
        MOD_WAP,
        0,
        MSG_ID_WAP_MMA_GET_SETTING_REQ,
        (oslParaType*) msg_req,
        NULL);
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_get_mms_setting_rsp
 * DESCRIPTION
 *  Get MMS setting response
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_get_mms_setting_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_setting_rsp_struct *msg_rsp = (wap_mma_get_setting_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*MMI_ASSERT(g_uc_p->send_info.request_id == msg_rsp->req_id);*/
    if (g_uc_p->send_info.request_id != msg_rsp->req_id)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                        "*---mmi_uc_get_mms_setting_rsp UC_ERROR---*\n");
        return;
    }
    
    if (msg_rsp->result != MMA_RESULT_OK)
    {
        mmi_uc_display_mma_result_popup(msg_rsp->result);
        DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);        
        return;
    }
    else
    {
        g_uc_p->mms_info.creation_mode = msg_rsp->creation_mode;
        g_uc_p->mms_info.priority = msg_rsp->priority;
        g_uc_p->mms_info.validity_period = msg_rsp->validity_period;
        g_uc_p->mms_info.delivery_time = msg_rsp->delivery_time;
        g_uc_p->mms_info.delivery_report = msg_rsp->delivery_report;
        g_uc_p->mms_info.read_report = msg_rsp->read_report;
        g_uc_p->mms_info.max_mms_size = msg_rsp->max_mms_size;
        g_uc_p->mms_info.best_page_duration = msg_rsp->best_page_duration;  /*E_OFF=0/E_ON=1*/
        memcpy(&g_uc_p->mms_info.image_resize, &msg_rsp->image_resize, sizeof(msg_rsp->image_resize));
        memcpy(&g_uc_p->mms_info.sliding_time, &msg_rsp->sliding_time, sizeof(msg_rsp->sliding_time));
        /*g_uc_p->mms_info.sender_visibility = msg_rsp->sender_visibility;*/ /*may add sender_visibility in get setting rsp*/
        g_uc_p->mms_info.sender_visibility = !(msg_rsp->hide_sender);
        mmi_uc_reset_mms_signature();

        if ((g_uc_p->mms_info.signature.enable = msg_rsp->signature.enable) == TRUE)
        {
            U32 file_path_len;
        
            if ((file_path_len = mmi_ucs2strlen((S8*)msg_rsp->signature.text_file)) > 0)
            {
                g_uc_p->mms_info.signature.text_file = kal_adm_alloc(g_uc_p->main.mem_pool_id, 
                                                                     (file_path_len + 1) * ENCODING_LENGTH);

                mmi_ucs2ncpy((S8*)g_uc_p->mms_info.signature.text_file, 
                                  (S8*)msg_rsp->signature.text_file,
                                  file_path_len);
            }
            if ((file_path_len = mmi_ucs2strlen((S8*)msg_rsp->signature.img_file)) > 0)
            {
                g_uc_p->mms_info.signature.img_file = kal_adm_alloc(g_uc_p->main.mem_pool_id, 
                                                                     (file_path_len + 1) * ENCODING_LENGTH);
            
                mmi_ucs2ncpy((S8*)g_uc_p->mms_info.signature.img_file, 
                                  (S8*)msg_rsp->signature.img_file,
                                  file_path_len);
            }
            if ((file_path_len = mmi_ucs2strlen((S8*)msg_rsp->signature.audio_file)) > 0)
            {
                g_uc_p->mms_info.signature.audio_file = kal_adm_alloc(g_uc_p->main.mem_pool_id, 
                                                                      (file_path_len + 1) * ENCODING_LENGTH);
            
                mmi_ucs2ncpy((S8*)g_uc_p->mms_info.signature.audio_file, 
                                  (S8*)msg_rsp->signature.audio_file,
                                  file_path_len);
            }
            if ((file_path_len = mmi_ucs2strlen((S8*)msg_rsp->signature.video_file)) > 0)
            {
                g_uc_p->mms_info.signature.video_file = kal_adm_alloc(g_uc_p->main.mem_pool_id, 
                                                                      (file_path_len + 1) * ENCODING_LENGTH);
             
                mmi_ucs2ncpy((S8*)g_uc_p->mms_info.signature.video_file, 
                                  (S8*)msg_rsp->signature.video_file,
                                  file_path_len);
            }
        }        
    }
    
    g_uc_p->msg.read_report = g_uc_p->mms_info.read_report;
    g_uc_p->msg.delivery_report = g_uc_p->mms_info.delivery_report;
    g_uc_p->msg.priority = g_uc_p->mms_info.priority;
    g_uc_p->msg.expiry_time = mmi_uc_convert_mms_expiry_time_to_uc(g_uc_p->mms_info.validity_period);
    g_uc_p->msg.delivery_time = mmi_uc_convert_mms_delivery_time_to_uc(g_uc_p->mms_info.delivery_time);
    g_uc_p->msg.slide_timing = g_uc_p->mms_info.sliding_time.value;
    g_uc_p->msg.sender_visibility = g_uc_p->mms_info.sender_visibility;
    g_uc_p->msg.best_page_duration = g_uc_p->mms_info.best_page_duration;
    g_uc_p->msg.background_color = MMI_UC_DEFAULT_BG_COLOR;
    g_uc_p->msg.foreground_color = MMI_UC_DEFAULT_FG_COLOR;
                
    switch (g_uc_p->main.state)
    {
        case MMI_UC_STATE_WRITE_NEW_MSG:
        {            
            /* If enter from mmi_uc_entry_write_msg_with_content, the first slide is ready. */
            if (g_uc_p->msg.total_slide_num == 0)
            {
                g_uc_p->msg.current_slide = mmi_uc_insert_slide(NULL);
                g_uc_p->msg.current_slide_num = g_uc_p->msg.current_slide->slide_num;

                /* Set duration of current slide as the value of MMS slide setting */
                g_uc_p->msg.current_slide->duration = g_uc_p->msg.slide_timing;
            }
            else
            {
                U8 mmi_uc_image_path[MMI_UC_MAX_TEMP_FILE_LEN];
                U16* filePath = (U16*)g_uc_p->main.file_path;

                memset(mmi_uc_image_path, 0x00, MMI_UC_MAX_TEMP_FILE_LEN);
                /* Set duration of current slide as the value of MMS slide setting */
                /*mmi_uc_insert_object_to_slide below will use g_uc_p->msg.current_slide->duration, and also maybe change this value*/
                g_uc_p->msg.current_slide->duration = g_uc_p->msg.slide_timing;

                if (g_uc_p->main.file_path)
                {
                    mma_insert_check_struct check_result;
                    S32 result;
                    mmi_uc_object_struct* object;
                    mmi_uc_object_type object_type;

                    memset(&check_result,0,sizeof(check_result));
                    wap_mma_uc_insert_object_check(
                                    g_uc_p->mms_info.creation_mode,
                                    (kal_wchar*)g_uc_p->main.file_path, 
                                    MMA_INSERT_UNKNOWN, 
                                    g_uc_p->msg.msg_size, 
                                    g_uc_p->mms_info.max_mms_size,
                                    &check_result);
                    
                    
                    if (!(check_result.result) && 
                        ((MMA_RESULT_FAIL_FILE_IO == check_result.detail_result) || 
                         (MMA_RESULT_FAIL_FILE_CORRUPTED == check_result.detail_result))
                       )
                    {
                        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                        "*---mmi_uc_get_mms_setting_rsp wap_mma_uc_insert_object_check return F, corrupt/IO---*\n");
                        result = mmi_uc_convert_mms_check_result(&check_result);
                        mmi_uc_display_popup(result);
                        kal_adm_free(g_uc_p->main.mem_pool_id, g_uc_p->main.file_path);
                        g_uc_p->main.file_path = NULL;
                        mmi_uc_reset_msg();
                        DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);                        
                        return;
                    }

                    /* Treat .txt files as attachments */
                    if (check_result.insert_type == MMA_INSERT_TEXT)
                    {
                        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                                "*[UnifiedComposerMsg.c] mmi_uc_get_mms_setting_rsp Treat .txt files as attachments *\n");
                 
                        check_result.insert_type = MMA_INSERT_ATTACHMENT;
                    }
        
                    if (!(check_result.result) && 
                    	!(check_result.insert_type == MMA_INSERT_IMAGE && g_uc_p->mms_info.image_resize.enable))
                    {
                        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                        "*---mmi_uc_get_mms_setting_rsp wap_mma_uc_insert_object_check return F---*\n");
                        result = mmi_uc_convert_mms_check_result(&check_result);
                        mmi_uc_display_popup(result);
                        kal_adm_free(g_uc_p->main.mem_pool_id, g_uc_p->main.file_path);
                        g_uc_p->main.file_path = NULL;
                        mmi_uc_reset_msg();
                        DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);                        
                        return;
                    }

                    object_type = mmi_uc_convert_mms_insert_type_to_uc(check_result.insert_type);

                    if (object_type == MMI_UC_OBJECT_TYPE_IMAGE)
                    {
                        if (g_uc_p->mms_info.image_resize.enable)
                        {                                
                            S32 resize_result;
                            mma_insert_check_struct check_image_result;

                            /* Check if it is DRM file */                    
                            wap_mma_uc_insert_object_check(g_uc_p->mms_info.creation_mode,
                                                           filePath, 
                                                           check_result.insert_type, 
                                                           g_uc_p->msg.msg_size, 
                                                           g_uc_p->mms_info.max_mms_size,
                                                           &check_image_result);
                            
                            /* SD and SD without right DRM files cannot be resized. */
                            if (check_image_result.result == MMI_TRUE && 
                                (check_image_result.drm_type == MMA_DRM_SD_NO_RIGHT || check_image_result.drm_type == MMA_DRM_SD))
                            {
                                /* allows inserted but display default image for thumbnail for MMA_DRM_SD_NO_RIGHT. */
                            }
                            else
                            {                                
                                if (!mmi_uc_is_valid_image(filePath))
                                {
                                    mmi_uc_display_resize_result_popup((U16)MMI_UC_RESIZING_FAILED_IN_GDI_FAILED);
                                    kal_adm_free(g_uc_p->main.mem_pool_id, g_uc_p->main.file_path);
                                    g_uc_p->main.file_path = NULL;                                    
                                    mmi_uc_reset_msg();                                    
                                    DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
                                    return;
                                }
                                
                                memset(&check_image_result, 0 ,sizeof(check_image_result));
                                MMI_UC_MAKE_IMAGE_FILE_PATH(mmi_uc_image_path, ++g_uc_p->main.image_no);
                                resize_result = mmi_uc_resize_image(
                                                        (U8*) filePath, 
                                                        mmi_uc_image_path, 
                                                        g_uc_p->mms_info.image_resize.width,
                                                        g_uc_p->mms_info.image_resize.height);
                        
                                /* Error ! */
                                if (resize_result < 0)
                                {                                
                                    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                           "*mmi_uc_get_mms_setting_rspmmi_uc_resize_image fail, w=%d, h=%d ---*\n",g_uc_p->mms_info.image_resize.width,g_uc_p->mms_info.image_resize.height);
                                    mmi_uc_display_resize_result_popup((U16)resize_result);
                                    kal_adm_free(g_uc_p->main.mem_pool_id, g_uc_p->main.file_path);
                                    g_uc_p->main.file_path = NULL;                                    
                                    mmi_uc_reset_msg();                                    
                                    DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
                                    return;
                                }
                                /* resized */
                                else if (resize_result)
                                {
                                    filePath = (PU16)mmi_uc_image_path;
                                }
                                /* resize_result == 0 means no need to resize */

                                memset(&check_image_result, 0 ,sizeof(check_image_result));
                            }
                            /* The img size may exceed limitation even if it is resized. */                    
                            wap_mma_uc_insert_object_check(g_uc_p->mms_info.creation_mode,
                                                           filePath, 
                                                           check_result.insert_type, 
                                                           g_uc_p->msg.msg_size, 
                                                           g_uc_p->mms_info.max_mms_size,
                                                           &check_image_result);

                            if (!(check_image_result.result))
                            {
                                result = mmi_uc_convert_mms_check_result(&check_image_result);
                                mmi_uc_display_popup(result);
                                kal_adm_free(g_uc_p->main.mem_pool_id, g_uc_p->main.file_path);
                                g_uc_p->main.file_path = NULL;
                                mmi_uc_reset_msg();
                                DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);                        
                                return;
                            }
                            
                        }
                    }
                    
                    object = mmi_uc_insert_object((S8*) filePath, object_type);
                    object->drm_type = check_result.drm_type;
                    
                    if (object_type == MMI_UC_OBJECT_TYPE_ATTACHMENT)
                    {
                        mmi_uc_attachment_info_struct* att;
                        att = mmi_uc_insert_attachment();
                        mmi_uc_insert_object_to_attachment(object, att);
                    }
                    else
                    {
                        mmi_uc_insert_object_to_slide(object, g_uc_p->msg.current_slide, object_type);
                    }
                    
                    /* Determine layout */
                    if (object_type == MMI_UC_OBJECT_TYPE_IMAGE || object_type == MMI_UC_OBJECT_TYPE_VIDEO)
                    {
                        if (g_uc_p->msg.layout == MMI_UC_LAYOUT_DEFAULT)
                        {
                            if (g_uc_p->msg.current_slide->text.char_count)
                            {
                                g_uc_p->msg.layout = MMI_UC_LAYOUT_THUMBNAIL_AT_BOTTOM;
                            }
                            else
                            {
                                g_uc_p->msg.layout = MMI_UC_LAYOUT_THUMBNAIL_AT_TOP;
                            }
                        }
                    }   
                    
                    kal_adm_free(g_uc_p->main.mem_pool_id, g_uc_p->main.file_path);
                    g_uc_p->main.file_path = NULL;
                }
                mmi_uc_change_msg_type_if_needed();
            }

            mmi_uc_insert_signature_check();
            mmi_uc_switch_slide(g_uc_p->msg.current_slide);
            mmi_uc_update_msg_size();            
            mmi_uc_entry_write_msg();
        }
        break;

        case MMI_UC_STATE_EDIT_EXISTED_MSG:
        case MMI_UC_STATE_FORWARD:
        case MMI_UC_STATE_SEND:
        case MMI_UC_STATE_REPLY:
        case MMI_UC_STATE_REPLY_ALL:
        {
            if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
            {

                mmi_uc_change_msg_type_if_needed();

                if (g_uc_p->main.state == MMI_UC_STATE_EDIT_EXISTED_MSG ||
                    g_uc_p->main.state == MMI_UC_STATE_REPLY||
                    g_uc_p->main.state == MMI_UC_STATE_REPLY_ALL)
                {
                    mmi_uc_insert_signature_check();
                    
                    mmi_uc_switch_slide(g_uc_p->msg.current_slide);
                    mmi_uc_entry_write_msg();                    
                }
                else
                {
                    g_uc_p->done.pre_msg_type = g_uc_p->msg_type.curr_msg_type;
                    
                    /* tricky! disallow to insert signature for forward and send case */
                    g_uc_p->msg.signature_inserted = MMI_TRUE; 
                    
                    mmi_uc_entry_done();
                    DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
                }                
            }
            else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
            {
                mmi_uc_get_mms_content_req();
            }
            else
            {
                MMI_ASSERT(0);
            }            
        }
        break;

        default:
        {
            MMI_ASSERT(0);
        }
        break;
    }   
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_get_mms_content_req
 * DESCRIPTION
 *  Get MMS content request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_get_mms_content_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_content_req_struct *msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->send_info.request_id = wap_mma_get_request_id();
    
    msg_req = (wap_mma_get_content_req_struct*) construct_local_para(sizeof(wap_mma_get_content_req_struct), TD_CTRL | TD_RESET);
    
    msg_req->req_id = g_uc_p->send_info.request_id;
    msg_req->msg_id = g_uc_p->send_info.existed_msg_id;
    msg_req->buffer_index = g_uc_p->send_info.buffer_index = 0;

    /* For Forward and Re-send MMS cases, the MMS msg may become SMS message before send */
    /* so the msg content should be gotten besides addresses */
    //msg_req->mode = mmi_uc_convert_uc_state_to_mms_app_mode(g_uc_p->main.state);
    if (g_uc_p->main.state == MMI_UC_STATE_REPLY)
    {
        msg_req->mode = MMA_MODE_REPLY;
    }
    else if (g_uc_p->main.state == MMI_UC_STATE_REPLY_ALL)
    {
        msg_req->mode = MMA_MODE_REPLY_ALL;
    }
    else if (g_uc_p->main.state == MMI_UC_STATE_FORWARD)
    {
        msg_req->mode = MMA_MODE_FORWARD;
    }
    else if (g_uc_p->main.state == MMI_UC_STATE_SEND)
    {
        msg_req->mode = MMA_MODE_SEND;
    }
    else
    {
        msg_req->mode = MMA_MODE_EDIT;
    }
    
    msg_req->creation_mode = g_uc_p->mms_info.creation_mode;

    mmi_uc_send_message(
        MOD_MMI,
        MOD_WAP,
        0,
        MSG_ID_WAP_MMA_GET_CONTENT_REQ,
        (oslParaType*) msg_req,
        NULL);
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_get_mms_content_rsp
 * DESCRIPTION
 *  Get MMS content response
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_get_mms_content_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_content_rsp_struct *msg_rsp = (wap_mma_get_content_rsp_struct*) inMsg;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*MMI_ASSERT(g_uc_p->send_info.request_id == msg_rsp->req_id);*/
    if (msg_rsp->req_id != g_uc_p->send_info.request_id)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                        "*---mmi_uc_get_mms_content_rsp UC_ERROR---*\n");
        return;
    }
    MMI_ASSERT(msg_rsp->msg_id == g_uc_p->send_info.existed_msg_id);
    MMI_ASSERT(msg_rsp->buffer_index == g_uc_p->send_info.buffer_index);    

    if (msg_rsp->result != MMA_RESULT_OK)
    {
        mmi_uc_display_mma_result_popup(msg_rsp->result);
        
        DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);        
    }
    else if (mmi_uc_check_if_exceed_MMS_size_limitation(msg_rsp->mms_header_size + msg_rsp->mms_body_size))
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
            "*-mmi_uc_get_mms_content_rsp, size over ---*\n");
        mmi_uc_display_popup(MMI_UC_SIZE_EXCEEDS);
        DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);  
    }
    else
    {
        g_uc_p->msg.msg_body_size = msg_rsp->mms_body_size;
        g_uc_p->msg.msg_size = msg_rsp->mms_header_size + msg_rsp->mms_body_size;

        if (msg_rsp->more)
        {
            /*----------------------------------------------------------------*/
            /* Local Variables                                                */
            /*----------------------------------------------------------------*/
            wap_mma_get_content_req_struct *msg_req;

            /*----------------------------------------------------------------*/
            /* Code Body                                                      */
            /*----------------------------------------------------------------*/            
            msg_req = (wap_mma_get_content_req_struct*) construct_local_para(sizeof(wap_mma_get_content_req_struct), TD_CTRL | TD_RESET);
 
            g_uc_p->send_info.buffer_index++;

            msg_req->req_id = g_uc_p->send_info.request_id;
            msg_req->msg_id = g_uc_p->send_info.existed_msg_id;
            msg_req->buffer_index = g_uc_p->send_info.buffer_index;
            msg_req->mode = mmi_uc_convert_uc_state_to_mms_app_mode((U16)g_uc_p->main.state);

            mmi_uc_send_message(
                MOD_MMI,
                MOD_WAP,
                0,
                MSG_ID_WAP_MMA_GET_CONTENT_REQ,
                (oslParaType*) msg_req,
                NULL);

        }
        else
        {
            g_uc_p->send_info.xml_file_size = msg_rsp->xml_size;

            mmi_uc_editor_initialize();

            /* parse the XML file*/
            result = mmi_uc_parse_mms_xml_description_file(msg_rsp->xml_filepath);

            if (result != MMI_UC_OK)
            {
                mmi_uc_display_popup(result);
                DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
                mmi_uc_reset_msg();
            }
            else
            {
                switch (g_uc_p->main.state)
                {
                    case MMI_UC_STATE_EDIT_EXISTED_MSG:
                    case MMI_UC_STATE_REPLY:
                    case MMI_UC_STATE_REPLY_ALL:
                    {   
                        /* In reply case, there is no content. */
                        if (g_uc_p->msg.total_slide_num == 0)
                        {
                            g_uc_p->msg.current_slide = mmi_uc_insert_slide(NULL);
                        }
                        else
                        {
                            g_uc_p->msg.current_slide = g_uc_p->msg.slide_head;            
                        }                        
                        
                        g_uc_p->msg.current_slide_num = g_uc_p->msg.current_slide->slide_num;

                        mmi_uc_change_msg_type_if_needed();

                        /* Reset slide time if the msg type is changed to SMS */
                        if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                        {
                            g_uc_p->msg.current_slide->duration = g_uc_p->mms_info.sliding_time.value;
                        }
                        
                        mmi_uc_insert_signature_check();

                        /* (MMS template -> write msg) should be taken as write new msg case */
                        if (g_uc_p->main.state == MMI_UC_STATE_EDIT_EXISTED_MSG &&
                            (wap_mma_get_box(g_uc_p->send_info.existed_msg_id) == MMA_FOLDER_TEMPLATE ||
                             wap_mma_get_box(g_uc_p->send_info.existed_msg_id) == MMA_FOLDER_USRDEF_TEMPLATE))
                        {
                            g_uc_p->main.state = MMI_UC_STATE_WRITE_NEW_MSG;
                        }

                    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
                        /* Editing archive MMS should be taken as write new msg case */
                        if (g_uc_p->main.state == MMI_UC_STATE_EDIT_EXISTED_MSG &&
                            wap_mma_get_box(g_uc_p->send_info.existed_msg_id) == MMA_FOLDER_ARCHIVE)
                        {
                            g_uc_p->main.state = MMI_UC_STATE_WRITE_NEW_MSG;
                        }                        
                    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

                        //mmi_uc_change_msg_type_if_needed();
                        
                        mmi_uc_switch_slide(g_uc_p->msg.current_slide);
                        mmi_uc_update_msg_size();

                        if (GetExitScrnID() == SCR_ID_UC_PROCESSING)
                        {
                            mmi_uc_entry_write_msg();
                        }
                        else
                        {
                            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[UnifiedComposerMsg.c] mmi_uc_get_mms_content_rsp Interrupt happens!!  *\n");

                            if (IsScreenPresent(SCR_ID_UC_PROCESSING))
                            {
                                HistoryReplace(SCR_ID_UC_PROCESSING, SCR_ID_UC_EDITOR, mmi_uc_entry_write_msg);
                            }
                            else
                            {
                                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[UnifiedComposerMsg.c] mmi_uc_get_mms_content_rsp Interrupt Do Nothing!!  *\n");
                            }
                        }
                    }
                    break;

                    case MMI_UC_STATE_FORWARD:
                    case MMI_UC_STATE_SEND:
                    {
                        g_uc_p->msg.current_slide = g_uc_p->msg.slide_head;            
                        
                        /* In forward case, there is no content. */
                        if (g_uc_p->msg.current_slide)
                        {
                            g_uc_p->msg.current_slide_num = g_uc_p->msg.current_slide->slide_num;
                        }
                        
                        //mmi_uc_change_msg_type_if_needed();
                        g_uc_p->msg_type.caller_specific_msg_type = MMI_UC_MSG_TYPE_MMS_ONLY;                        
                        g_uc_p->msg_type.curr_msg_type = MMI_UC_MSG_TYPE_MMS_PREFER;
                                                        
                        g_uc_p->done.pre_msg_type = g_uc_p->msg_type.curr_msg_type;
                        
                        /* tricky! disallow to insert signature for forward and send case */
                        g_uc_p->msg.signature_inserted = MMI_TRUE; 
                        
                        mmi_uc_switch_slide(g_uc_p->msg.current_slide);
                        mmi_uc_update_msg_size();

                        if (GetExitScrnID() == SCR_ID_UC_PROCESSING)
                        {
                            mmi_uc_entry_done();
                        }
                        else
                        {
                            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[UnifiedComposerMsg.c] mmi_uc_get_mms_content_rsp Interrupt happens!!  *\n");

                            if (IsScreenPresent(SCR_ID_UC_PROCESSING))
                            {
                                HistoryReplace(SCR_ID_UC_PROCESSING, SCR_ID_UC_OPT_DONE, mmi_uc_entry_done);
                            }
                            else
                            {
                                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[UnifiedComposerMsg.c] mmi_uc_get_mms_content_rsp Interrupt Do Nothing!!  *\n");
                            }
                        }                        
                        DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
                    }
                    break;

                    default:
                    {
                        MMI_ASSERT(0);
                    }
                    break;
                }   
                return;
            }

        }               
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_create_mms_req
 * DESCRIPTION
 *  Create MMS msg request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_create_mms_req(void)
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
    g_uc_p->send_info.request_id = wap_mma_get_request_id();
    
    msg_req = (wap_mma_create_req_struct*) construct_local_para(sizeof(wap_mma_create_req_struct), TD_CTRL | TD_RESET);
    msg_req->req_id = g_uc_p->send_info.request_id;

    /* reset */
    msg_req->mode = MMA_MODE_EDIT;
    msg_req->msg_id = 0;

    if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER )
    {
        if (g_uc_p->main.state == MMI_UC_STATE_FORWARD)
        {
            msg_req->msg_id = g_uc_p->send_info.existed_msg_id;
            msg_req->mode = MMA_MODE_FORWARD;
        }
        else if (g_uc_p->main.state == MMI_UC_STATE_SEND)
        {
            msg_req->msg_id = g_uc_p->send_info.existed_msg_id;
            msg_req->mode = MMA_MODE_SEND;
        }
    }
    
    MMI_UC_MAKE_MMS_XML_FILE_PATH(msg_req->xml_filepath, 0);
    msg_req->xml_size = g_uc_p->send_info.xml_file_size = applib_get_file_size(msg_req->xml_filepath);
    msg_req->buffer_index = g_uc_p->send_info.buffer_index = 0;

    if (msg_req->xml_size <= MMI_UC_MAX_XML_SIZE_IN_PEER_BUFFER)
    {
        msg_req->buffer_size = msg_req->xml_size;
        msg_req->more = KAL_FALSE;
    }
    else
    {
        msg_req->buffer_size = MMI_UC_MAX_XML_SIZE_IN_PEER_BUFFER;
        msg_req->more = KAL_TRUE;
    }

    peer_buff_ptr = construct_peer_buff((kal_uint16) msg_req->buffer_size, 0, 0, TD_CTRL);
    
    g_uc_p->send_info.fs = FS_Open(msg_req->xml_filepath, FS_READ_ONLY );
    
    if( FS_Read( g_uc_p->send_info.fs, get_pdu_ptr(peer_buff_ptr, &peer_buff_len), msg_req->buffer_size, &read_size ) != FS_NO_ERROR ||
        read_size != msg_req->buffer_size)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                 "*[UnifiedComposerMsg.c] mmi_uc_create_mms_req read_size=%d buf_size=%d*\n",
                 read_size, msg_req->buffer_size);
    }
    
    mmi_uc_send_message(
        MOD_MMI,
        MOD_WAP,
        0,
        MSG_ID_WAP_MMA_CREATE_REQ,
        (oslParaType*) msg_req,
        peer_buff_ptr);
    
    return;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_uc_create_mms_rsp
 * DESCRIPTION
 *  Create MMS msg response
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_create_mms_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_create_rsp_struct *msg_rsp = (wap_mma_create_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_rsp->req_id != g_uc_p->send_info.request_id)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[UnifiedComposerMsg.c] mmi_uc_create_mms_rsp REQ_ID NOT MATCH! msg_rsp->req_id=%d g_uc_p->send_info.req_id=%d*\n",
                         msg_rsp->req_id, g_uc_p->send_info.request_id);
        return;
    }
    
    if (msg_rsp->result != MMA_RESULT_OK)
    {
        FS_Close( g_uc_p->send_info.fs);

        if (g_uc_p->send_info.action != MMI_UC_ACTION_SAVE_IN_BACKGROUND)
        {
            mmi_uc_display_mma_result_popup(msg_rsp->result);
        }
        else
        {
            mmi_uc_reset_msg();
        }

        DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);

        /* reset state */
        g_uc_p->send_info.action = MMI_UC_ACTION_IDLE;
    }
    else
    {
        /* More XML content needs to send */
        if (msg_rsp->msg_id == 0)
        {
            wap_mma_create_req_struct *msg_req;
            peer_buff_struct *peer_buff_ptr;
            U32 read_size;
            S32 remaining_size;
            U16 peer_buff_len = 0;

            MMI_ASSERT(msg_rsp->buffer_index == g_uc_p->send_info.buffer_index + 1);
            msg_req = (wap_mma_create_req_struct*) construct_local_para(sizeof(wap_mma_create_req_struct), TD_CTRL | TD_RESET);
            msg_req->req_id = g_uc_p->send_info.request_id;

            /* reset */
            msg_req->mode = MMA_MODE_EDIT;
            msg_req->msg_id = 0;

            if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER )
            {
                if (g_uc_p->main.state == MMI_UC_STATE_FORWARD ||
                    g_uc_p->main.state == MMI_UC_STATE_SEND)
                {
                    msg_req->msg_id = g_uc_p->send_info.existed_msg_id;
                }

                if (g_uc_p->main.state == MMI_UC_STATE_FORWARD)
                {        
                    msg_req->mode = MMA_MODE_FORWARD;
                }
                else if (g_uc_p->main.state == MMI_UC_STATE_SEND)
                {        
                    msg_req->mode = MMA_MODE_SEND;
                }
            }            
            MMI_UC_MAKE_MMS_XML_FILE_PATH(msg_req->xml_filepath, 0);
            msg_req->xml_size = g_uc_p->send_info.xml_file_size;
            g_uc_p->send_info.buffer_index++;
            msg_req->buffer_index = g_uc_p->send_info.buffer_index;

            remaining_size  = g_uc_p->send_info.xml_file_size - 
                              (msg_req->buffer_index * MMI_UC_MAX_XML_SIZE_IN_PEER_BUFFER);

            if (remaining_size <= MMI_UC_MAX_XML_SIZE_IN_PEER_BUFFER)
            {
                msg_req->buffer_size = remaining_size;
                msg_req->more = KAL_FALSE;
            }
            else
            {
                msg_req->buffer_size = MMI_UC_MAX_XML_SIZE_IN_PEER_BUFFER;
                msg_req->more = KAL_TRUE;
            }

            peer_buff_ptr = construct_peer_buff((kal_uint16) msg_req->buffer_size, 0, 0, TD_CTRL);
            
            if( FS_Read( g_uc_p->send_info.fs, get_pdu_ptr(peer_buff_ptr, &peer_buff_len), msg_req->buffer_size, &read_size ) != FS_NO_ERROR ||
                read_size != msg_req->buffer_size)
            {
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[UnifiedComposerMsg.c] mmi_uc_create_mms_rsp read_size=%d buf_size=%d*\n",
                         read_size, msg_req->buffer_size);
            }
            
            mmi_uc_send_message(
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
            FS_Close(g_uc_p->send_info.fs);
            g_uc_p->send_info.new_msg_id = msg_rsp->msg_id;
            
            if (g_uc_p->send_info.action != MMI_UC_ACTION_SAVE_IN_BACKGROUND)
            {
                if (GetExitScrnID() != SCR_ID_UC_PROCESSING)
                {
                    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[UnifiedComposerMsg.c] mmi_uc_create_mms_rsp Interrupt happens!!  *\n");
                    
                    mmi_uc_set_processing_screen(STR_UC_PLEASE_WAIT_ID, STR_UC_PLEASE_WAIT_ID, IMG_GLOBAL_PROGRESS, 0);
                    g_uc_p->send_info.action = MMI_UC_ACTION_DELETE_IN_BACKGROUND;

                    mmi_uc_delete_mms_req(g_uc_p->send_info.new_msg_id);
                    g_uc_p->send_info.new_msg_id = 0;
                    return;
                }
            }
            
            switch (g_uc_p->send_info.action)
            {
                case MMI_UC_ACTION_SEND:
                {
#ifdef __MMI_MMS_BGSR_SUPPORT__
                    /*This case should not happened is BGSR is enabled*/
                    MMI_ASSERT(0);
#endif
                    mmi_uc_send_mms();
                    DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);                    
                }
                break;
                
                case MMI_UC_ACTION_SEND_AND_SAVE:
                {
#ifdef __MMI_MMS_BGSR_SUPPORT__
                    /*This case should not happened if BGSR is enabled*/
                    MMI_ASSERT(0);
#endif
                    mmi_uc_send_and_save_mms();
                    DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);                    
                }
                break;

                case MMI_UC_ACTION_SAVE:
                {
                    UmMsgBoxType msg_box = mmi_um_get_current_msg_box_type();
                    
                    if (g_uc_p->main.state == MMI_UC_STATE_EDIT_EXISTED_MSG &&
                        msg_box == UM_MSG_BOX_TYPE_DRAFT)
                    {
                        mmi_uc_set_processing_screen(
                                    STR_GLOBAL_SAVING, 
                                    STR_UC_PLEASE_WAIT_ID, 
                                    IMG_GLOBAL_PROGRESS, 
                                    0);
                        
                        mmi_uc_entry_processing_generic();
                        
                        /* save msg from MMS to SMS. Save new one and then delete original one. */
                        if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                        {                                
                            mmi_uc_save_mms_req(g_uc_p->send_info.new_msg_id, MMA_FOLDER_DRAFT);
                        }
                        /* save msg from MMS to MMS. Delete original one and then save new one. */
                        else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                        {
                            mmi_uc_delete_existed_mms();
                        }
                        else
                        {
                            MMI_ASSERT(0);
                        }
                    }
                    else
                    {
                        mmi_uc_save_mms();
                    }
                    DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);                    
                }
                break;

            #if defined(__MMI_MMS_2__) || defined(__MMI_OBIGO_Q03C_MMS_USER_DEFINED_TEMPLATES__)
                case MMI_UC_ACTION_SAVE_AS_TEMPLATE:
                {
                    /* Handle save as template case as save new mms msg */
                    g_uc_p->send_info.action = MMI_UC_ACTION_SAVE;
                    g_uc_p->main.state = MMI_UC_STATE_WRITE_NEW_MSG;
                    
                    mmi_uc_save_mms_to_folder(MMA_FOLDER_USRDEF_TEMPLATE);
                    DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);                    
                }
                break;
            #endif /* __MMI_MMS_2__ */

                case MMI_UC_ACTION_SAVE_IN_BACKGROUND:
                {
                    mmi_uc_save_mms_req(g_uc_p->send_info.new_msg_id, MMA_FOLDER_DRAFT);
                }
                break;

                case MMI_UC_ACTION_PREVIEW:
                {
                    mmi_uc_preview_mms();
                    DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
                }
                break;
           #if (defined(__MMI_MMS_2__) || defined(__MMI_MMS_BGSR_SUPPORT__))
                case MMI_UC_ACTION_SEND_IN_BACKGROUND:
                {
                    wap_mms_send_msg(g_uc_p->send_info.new_msg_id);
                    
                    if (g_uc_p->main.state == MMI_UC_STATE_FORWARD ||
                        g_uc_p->main.state == MMI_UC_STATE_SEND)
                    {
                        mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE, SCR_ID_UC_PROCESSING);
                    }
                    else
                    {
                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                    }
                    
                    mmi_uc_action_fsm(MMI_UC_ACTION_SEND, MMA_RESULT_OK);
                }
                break;
            #endif /* __MMI_MMS_2__ */

                default:
                {
                    MMI_ASSERT(0);
                }
            }                
        }
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_send_mms_req
 * DESCRIPTION
 *  Send MMS msg request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_send_mms_req(BOOL send_and_save, U16 msg_box_to_save)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_send_req_struct *msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->send_info.request_id = wap_mma_get_request_id();
    
    msg_req = (wap_mma_send_req_struct*) construct_local_para(sizeof(wap_mma_send_req_struct), TD_CTRL | TD_RESET);
    msg_req->req_id = g_uc_p->send_info.request_id;

    msg_req->msg_id = g_uc_p->send_info.new_msg_id;

    if (send_and_save)
    {
        msg_req->send_and_save = KAL_TRUE;
        msg_req->box = msg_box_to_save;
    }
    else
    {
        msg_req->send_and_save = KAL_FALSE;
        msg_req->box = 0;
    }
    
    mmi_uc_send_message(
        MOD_MMI,
        MOD_WAP,
        0,
        MSG_ID_WAP_MMA_SEND_REQ,
        (oslParaType*) msg_req,
        NULL);
    
    return;
}


    
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_send_mms_ind_hdlr
 * DESCRIPTION
 *  Send MMS message indication handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_send_mms_ind_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_send_ind_struct *msg_ind = (wap_mma_send_ind_struct*) inMsg;;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_uc_p->send_info.request_id != msg_ind->req_id ||
        g_uc_p->send_info.new_msg_id != msg_ind->msg_id )
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMsg.c] mmi_uc_send_mms_ind_hdlr IGNORE! *\n");
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                     "*[UnifiedComposerMain.c] mmi_uc_send_mms_ind_hdlr IGNORE! req_id=%d new_msg_id=%d *\n",
                     g_uc_p->send_info.request_id, g_uc_p->send_info.new_msg_id);

        return;
    }

    
    mmi_uc_update_sending_mms_percent_and_retry(msg_ind->percent, msg_ind->retry);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_send_mms_rsp
 * DESCRIPTION
 *  Send MMS msg response
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_send_mms_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_send_rsp_struct *msg_rsp = (wap_mma_send_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_ASSERT(g_uc_p->send_info.request_id == msg_rsp->req_id );
    MMI_ASSERT(g_uc_p->send_info.new_msg_id == msg_rsp->msg_id);

    g_uc_p->send_info.send_result = msg_rsp->result;

    if (g_uc_p->send_info.fail_cause)
    {
        kal_adm_free(g_uc_p->main.mem_pool_id, g_uc_p->send_info.fail_cause);
        g_uc_p->send_info.fail_cause = NULL;
    } 

    if (msg_rsp->result != MMA_RESULT_OK && mmi_ucs2strlen((S8*)msg_rsp->response_text))
    {
        U32 str_len = mmi_ucs2strlen((S8*)msg_rsp->response_text);

        g_uc_p->send_info.fail_cause = kal_adm_alloc(g_uc_p->main.mem_pool_id, (str_len + 1) * ENCODING_LENGTH);
        if (g_uc_p->send_info.fail_cause != NULL)
        {
            memset(g_uc_p->send_info.fail_cause , 0, (str_len + 1) * ENCODING_LENGTH);
            mmi_ucs2ncpy((S8*)g_uc_p->send_info.fail_cause,  (S8*)msg_rsp->response_text, str_len);
        }
        else
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[UnifiedComposerMsg.c] mmi_uc_send_mms_rsp fail_cause memory not allocated! len=%d*\n",
                             str_len);
        }
    }
    
    mmi_uc_action_fsm(MMI_UC_ACTION_SEND, msg_rsp->result);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_delete_mms_req
 * DESCRIPTION
 *  Delete MMS msg request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_delete_mms_req(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_delete_req_struct *msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->send_info.request_id = wap_mma_get_request_id();

    MMI_ASSERT(msg_id);
    
    msg_req = (wap_mma_delete_req_struct*) construct_local_para(sizeof(wap_mma_delete_req_struct), TD_CTRL | TD_RESET);
    msg_req->req_id = g_uc_p->send_info.request_id;

    msg_req->msg_id = msg_id;
    
    mmi_uc_send_message(
        MOD_MMI,
        MOD_WAP,
        0,
        MSG_ID_WAP_MMA_DELETE_REQ,
        (oslParaType*) msg_req,
        NULL);
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_delete_mms_rsp
 * DESCRIPTION
 *  Delete MMS msg response
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_delete_mms_rsp(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *msg_rsp = (wap_mma_rsp_struct*) in_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_ASSERT(g_uc_p->send_info.request_id == msg_rsp->req_id );

    if (g_uc_p->send_info.request_id == msg_rsp->req_id)
    {
        mmi_uc_action_fsm(MMI_UC_ACTION_DELETE, msg_rsp->result);    
    }
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                     "*[UnifiedComposerMain.c] mmi_uc_delete_mms_rsp IGNORE! req_id=%d *\n",
                     g_uc_p->send_info.request_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_save_mms_req
 * DESCRIPTION
 *  Save MMS msg request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_save_mms_req(U32 msg_id, U16 msg_box)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_save_req_struct *msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->send_info.request_id = wap_mma_get_request_id();
    
    msg_req = (wap_mma_save_req_struct*) construct_local_para(sizeof(wap_mma_save_req_struct), TD_CTRL | TD_RESET);
    msg_req->req_id = g_uc_p->send_info.request_id;
    msg_req->msg_id = msg_id;
    msg_req->box = msg_box;
    
    mmi_uc_send_message(
        MOD_MMI,
        MOD_WAP,
        0,
        MSG_ID_WAP_MMA_SAVE_REQ,
        (oslParaType*) msg_req,
        NULL);
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_save_mms_rsp
 * DESCRIPTION
 *  Save MMS msg response
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_save_mms_rsp(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *msg_rsp = (wap_mma_rsp_struct*) in_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*MMI_ASSERT(g_uc_p->send_info.request_id == msg_rsp->req_id);*/
    if (g_uc_p->send_info.request_id != msg_rsp->req_id)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                        "*---mmi_uc_save_mms_rsp UC_ERROR---*\n");
        return;
    }
    mmi_uc_action_fsm(MMI_UC_ACTION_SAVE, msg_rsp->result);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_abort_send_mms_req
 * DESCRIPTION
 *  Abort sending MMS msg request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_abort_send_mms_req(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_cancel_send_req_struct *msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->send_info.request_id = wap_mma_get_request_id();
    
    msg_req = (wap_mma_cancel_send_req_struct*) construct_local_para(sizeof(wap_mma_cancel_send_req_struct), TD_CTRL | TD_RESET);
    msg_req->req_id = g_uc_p->send_info.request_id;
    msg_req->msg_id = msg_id;
    
    mmi_uc_send_message(
        MOD_MMI,
        MOD_WAP,
        0,
        MSG_ID_WAP_MMA_CANCEL_SEND_REQ,
        (oslParaType*) msg_req,
        NULL);
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_abort_send_mms_rsp
 * DESCRIPTION
 *  Abort MMS msg response
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_abort_send_mms_rsp(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *msg_rsp = (wap_mma_rsp_struct*) in_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*MMI_ASSERT(g_uc_p->send_info.request_id == msg_rsp->req_id);*/
    if (g_uc_p->send_info.request_id != msg_rsp->req_id)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                        "*---mmi_uc_abort_send_mms_rsp UC_ERROR---*\n");
        return;
    }

    if (g_uc_p->send_info.abort == MMI_UC_ABORT_NORMAL)
    {
        /* Do nothing */
    }
    else if (g_uc_p->send_info.abort == MMI_UC_ABORT_BY_END_KEY)
    {
        /* Do nothing */
    }
    else if (g_uc_p->send_info.abort == MMI_UC_ABORT_NONE)
    {
        /* Do nothing */
    }
    else 
    {
        MMI_ASSERT(0);
    }        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_preview_mms_req
 * DESCRIPTION
 *  Preview MMS msg request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_preview_mms_req()
{
#ifdef __MMI_MMS_2__
    mmi_mv_preview_msg(g_uc_p->send_info.new_msg_id, SCR_ID_UC_PROCESSING, mmi_uc_show_preview_slide_list, STR_UC_PREVIEW_GOTO);
#else /* __MMI_MMS_2__ */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_preview_req_struct *msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->send_info.request_id = wap_mma_get_request_id();

    MMI_ASSERT(g_uc_p->send_info.new_msg_id);
    
    msg_req = (wap_mma_preview_req_struct*) construct_local_para(sizeof(wap_mma_preview_req_struct), TD_CTRL | TD_RESET);
     
    msg_req->req_id = g_uc_p->send_info.request_id;
    msg_req->msg_id = g_uc_p->send_info.new_msg_id;
    
    mmi_uc_send_message(
        MOD_MMI,
        MOD_WAP,
        0,
        MSG_ID_WAP_MMA_PREVIEW_REQ,
        (oslParaType*) msg_req,
        NULL);
    
    return;
#endif /* __MMI_MMS_2__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_preview_mms_rsp
 * DESCRIPTION
 *  Preview MMS msg response
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_preview_mms_rsp(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *msg_rsp = (wap_mma_rsp_struct*) in_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_uc_p->send_info.request_id != msg_rsp->req_id )
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                     "*[UnifiedComposerMain.c] mmi_uc_preview_mms_rsp IGNORE! req_id=%d *\n",
                     g_uc_p->send_info.request_id);        
        return;
    }
    
    MMI_ASSERT(g_uc_p->send_info.new_msg_id == msg_rsp->msg_id);

    if (msg_rsp->result != MMA_RESULT_OK)
    {
        DisplayPopup(
                (PU8) GetString(STR_GLOBAL_UNFINISHED),
                IMG_GLOBAL_UNFINISHED,
                1,
                MMI_UC_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
        
    }
    
    DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_send_message
 * DESCRIPTION
 *  Common function for sending message
 * PARAMETERS
 *  MOD_SRC         [IN]        Source module
 *  MOD_DEST        [IN]        Destination module
 *  MSG_SAP         [IN]        Message SAP
 *  MSG_ID          [IN]        Message ID
 *  LOCAL           [IN]        Local parameter
 *  PEER            [IN]        Peer buffer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_send_message(
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

#endif /* __MMI_UNIFIED_COMPOSER__ */ 
#endif /* _MMI_UNIFIED_COMPOSER_MSG_C */ 


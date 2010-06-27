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
 *
 *
 * Project:
 * --------
 *  MAUI
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
 
#include "MMI_include.h"

#if defined (__MMI_DOWNLOAD_AGENT__)

#include "CommonScreens.h"
#include "ProtocolEvents.h"
#include "app_mine.h"
#include "FileMgr.h"

#include "drm_def.h"                    /* DRM_PROC_RESULT_OK */
#include "drm_gprot.h"
#include "DLAgentDef.h"
#include "DLAgentGprot.h"
#include "DLAgentprot.h"
#include "DLAgentResDef.h"
#include "DLAgentWPS.h"

#include "SimDetectionDef.h"            /* SCR_SIM_INSERTION and SCR_SIM_BLOCK */
#include "IdleAppDef.h"                 /* IDLE_SCREEN_ID */
#include "MessagesResourceData.h"       /* IMG_NEW_MESSAGE_NOTIFICATION_MSG */
#include "FileManagerGProt.h"           /* GetFileSystemErrorString */
#include "settingProfile.h"
#include "FileManagerDef.h"
#include "imageViewerResDef.h"
#include "SettingDefs.h"
#include "CallManagementGprot.h"
#include "IdleAppProt.h"                /* mmi_idle_is_on_idle_screen */

#include "wap_ps_struct.h"
#include "wapadp.h"
#include "Conversions.h"

#include "UnicodeStrgprot.h"
#include "ProfileGprots.h"              /* stopRequestedTone*/
#include "USBDeviceGprot.h"             /* mmi_usb_is_in_mass_storage_mode */
#include "gpioInc.h"                    /* TurnOnBacklight */

/****************************************************************************
* Define
*****************************************************************************/

/****************************************************************************
* Define - Macro
*****************************************************************************/

#define DA_SHOW_INFO(dst, format, tag_src, value_src) \
    kal_wsprintf((unsigned short*)(dst + mmi_ucs2strlen((S8*)dst)),(format),(tag_src), (value_src))

#define DA_INVALID_SESSION_ID   9999

/****************************************************************************
* Typedef - Struct
*****************************************************************************/

typedef struct
{
    /* attribute provide by lower layer */
    S8          *url_ptr;
    S8          *mime_type_ptr;
    U32         size;

    S8          *content;
    U32         content_len;
    S8          *header;
    U32         header_len;

    /* run-time variable */
    U16			*filepath;  /* full pathname */
    S32	        session_id;
    U32         curr_size;
    U32         dl_start_tick;
    U32         dl_latest_tick;

    mmi_da_abort_callback_type          abort_callback;

#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    /* resume */
    wps_session_handle      session;
#endif    
   
} mmi_da_normal_dl_job_struct;

/****************************************************************************
* Static Variable
*****************************************************************************/

/****************************************************************************
* Global Variable
*****************************************************************************/

static void mmi_da_http_init_module(void);
static BOOL mmi_da_http_free_job(mmi_da_job_struct* job);
static U16* mmi_da_http_get_item_filepath(const mmi_da_job_struct* job, U16* buffer, U32 buffer_len);
static U32 mmi_da_http_get_item_progress(const mmi_da_job_struct* job, mmi_da_item_progress_struct *info);
static void mmi_da_http_abort_job(mmi_da_job_struct* job, S32 prev_state, BOOL pauseOnly,
                                  mmi_da_abort_callback_type end_callback);
static void mmi_da_http_dispatch_job(const mmi_da_job_struct* job);
static S16 mmi_da_http_get_job_id(const mmi_da_job_struct* job);
static void mmi_da_http_get_setting(const mmi_da_job_struct* job, mmi_da_setting_struct *setting_data);
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
static void mmi_da_http_resume_job(mmi_da_job_struct* job);
static S32 mmi_da_http_move_job(mmi_da_job_struct* job, U16* new_filepath);
#endif
const mmi_da_module_funcptr_table mm_da_http_module =
{
    mmi_da_http_init_module

    ,mmi_da_http_get_item_filepath
    ,mmi_da_http_get_item_progress
    ,mmi_da_http_get_job_id
    ,mmi_da_http_get_setting
    
    ,mmi_da_http_free_job
    ,mmi_da_http_abort_job
    ,mmi_da_http_dispatch_job
    
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    ,mmi_da_http_resume_job
    ,mmi_da_http_move_job
#endif    
};

/****************************************************************************
* Function Forward Declaration
*****************************************************************************/

static void mmi_da_recv_wap_file_dl_ind(void *MsgStruct, int mod_src, void *ilm_p);
static void mmi_da_recv_wap_file_dl_progress_ind(void *MsgStruct, int mod_src, void *ilm_p);
static void mmi_da_recv_wap_file_stop_rsp(void *MsgStruct, int mod_src, void *ilm_p);
static void mmi_da_send_wap_file_dl_res(S32 session_id, S32 error, U16* filepath);
static void mmi_da_send_wap_file_dl_progress_res(S32 session_id, U32 seq_num);

#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
static BOOL mmi_da_http_job_match_url_func(const mmi_da_job_struct* job, U32 criteria);
#endif

static void mmi_da_http_set_confirm_msg(U32 criteria, U16 *out);
static void mmi_da_http_job_confirm_dl_callback(U32 criteria);
static void mmi_da_http_job_cancel_dl_callback(U32 criteria, BOOL in_delete);

static BOOL mmi_da_http_filename_done(U32 criteria, U16* filepath, BOOL canback, BOOL canpopup);

#ifdef __DRM_SUPPORT__
static void mmi_da_http_drm_process_callback(mmi_da_job_struct* job,
                                             U16 *new_filepath, U16 err_string_id);
//static S32 mmi_da_http_process_drm_buffer(mmi_da_job_struct* job);
#endif

#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
static void mmi_da_http_wps_created_callback(wps_session_handle session, U32 arg);
static void mmi_da_http_wps_http_response_callback(U32 arg, U8 result, U16 status, 
                                                  S8 *content_type, U32 context_len);
static void mmi_da_http_wps_http_auth_ind_callback(U32 arg);
static void mmi_da_http_wps_dl_progress_callback(U32 arg, U8 status, U32 curr_size, S32 cause);
static void mmi_da_http_wps_session_aborted_callback(U32 arg);
static void mmi_da_http_wps_session_resume_aborted_callback(U32 arg);
#endif

#define END_OF_FUNCTION_DECLARATION
/****************************************************************************
* Function 
*****************************************************************************/

static void mmi_da_http_init_module(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetProtocolEventHandler((PsFuncPtr) mmi_da_recv_wap_file_dl_ind,            MSG_ID_WAP_MMI_FILE_DL_IND);
    SetProtocolEventHandler((PsFuncPtr) mmi_da_recv_wap_file_dl_progress_ind,   MSG_ID_WAP_MMI_FILE_DL_PROGRESS_IND);
    SetProtocolEventHandler((PsFuncPtr) mmi_da_recv_wap_file_stop_rsp,          MSG_ID_WAP_MMI_FILE_DL_STOP_RSP);
}

#define RECV_WAP_FILE_DL

#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
static void _mmi_da_http_display_list(void)
{
    mmi_da_display_job_list(NULL, FALSE);
}
#endif

static void mmi_da_recv_wap_file_dl_ind(void *MsgStruct, int mod_src, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmi_file_dl_ind_struct *msg = (wap_mmi_file_dl_ind_struct*)MsgStruct;
    ilm_struct *mmi_ilm_ptr = (ilm_struct*) ilm_p;

    mmi_da_job_struct           *job;
    mmi_da_normal_dl_job_struct *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DA_TRACE_FUNC(mmi_da_recv_wap_file_dl_ind);

#ifdef __USB_IN_NORMAL_MODE__
    /* check is in mass storage mode */
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* phone drive is exported, cant use this app */
        mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        mmi_da_send_wap_file_dl_res(msg->session_id, WAP_DL_ERROR_FILE_ACCESS, NULL);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */


    if(mmi_da_is_in_voice_call())
    {
        mmi_da_send_wap_file_dl_res(msg->session_id, WAP_DL_ERROR_CANCELLED, NULL);
        return;
    }

#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    job = mmi_da_find_job(mmi_da_http_job_match_url_func, (U32)msg->url);
#ifdef __MMI_OMA_DD_DOWNLOAD__
    if(!job)
        job = mmi_da_oma_find_job_by_dd((S8*)msg->url);
#endif

    if(job)
    {
        mmi_da_send_wap_file_dl_res(msg->session_id, WAP_DL_ERROR_CANCELLED, NULL);
        mmi_da_click_job(job);
        return;
    }
#endif /* __MMI_DOWNLOAD_AGENT_MULTI_DL__ */

    // TODO: check for max dl count.

    /* parse message & allocate a new job */
    job = mmi_da_job_create(MMI_DA_JOB_TYPE_NORMAL, NULL);

#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
#ifdef __DRM_SUPPORT__
    if(!job && mmi_da_get_last_error() == MMI_DA_IERROR_EXCEED_MAX_JOB)
    {
        const applib_mime_type_struct* mimetype;
        mimetype = mmi_da_util_lookup_mime_type((U8*)msg->mime_type, 
                                              mmi_da_util_get_extension((U16*)msg->file_name), 
                                              0, 0);
        
        if( mmi_da_is_drm_right(mimetype) ||
            mmi_da_is_drm_roap(mimetype) )
        {
            job = mmi_da_job_create_ex(MMI_DA_JOB_TYPE_NORMAL, NULL);
        }
    }
#endif
#endif


    if(!job)
    {
        mmi_da_send_wap_file_dl_res(msg->session_id, WAP_DL_ERROR_CANCELLED, NULL);
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
        switch(mmi_da_get_last_error())
        {
        case MMI_DA_IERROR_EXCEED_MAX_JOB:
            DisplayPopupCallBack((PU8) GetString(STR_ID_DA_PROMPT_EXCEED_MAX_JOB), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME,
                         (U8) ERROR_TONE, _mmi_da_http_display_list);
            break;
        case MMI_DA_IERROR_EXCEED_MAX_DL:
            DisplayPopupCallBack((PU8) GetString(STR_ID_DA_PROMPT_EXCEED_MAX_DL), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME,
                         (U8) ERROR_TONE, _mmi_da_http_display_list);
            break;
        }
#endif        
        return;
    }

    job_data = (mmi_da_normal_dl_job_struct*)OslMalloc(sizeof(mmi_da_normal_dl_job_struct));
    memset(job_data, 0, sizeof(mmi_da_normal_dl_job_struct));

    job->data_ptr = job_data;

    job_data->session_id = msg->session_id;
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    job_data->session = MMI_DA_INVALID_SESSION_HANDLE;
#endif    
    ANSI_STR_MALLOC_COPY(job_data->url_ptr, msg->url);
    ANSI_STR_MALLOC_COPY(job_data->mime_type_ptr, msg->mime_type);
    UCS2_STR_MALLOC_COPY(job_data->filepath, msg->file_name);
    job_data->size = msg->file_length;

    job->mime_type = mmi_da_util_lookup_mime_type((U8*)msg->mime_type, 
                                                  mmi_da_util_get_extension((U16*)msg->file_name), 
                                                  0, 0);

    DA_TRACE1(MMI_TRC_DA_MIMETYPE, job->mime_type ? job->mime_type->mime_string : "");
    
    job->type_handler = mmi_da_search_mime_type_handler(job->mime_type);

    job_data->content = NULL;
    job_data->content_len = 0;
    job_data->header = NULL;
    job_data->header_len = 0;
    
    if (mmi_ilm_ptr->peer_buff_ptr)
    {
        wap_mmi_file_dl_var_struct buffer;
        kal_uint16 len;

        if( wps_pun_var_part(
                WPS_PUN_UNPACK,
                MSG_ID_WAP_MMI_FILE_DL_IND,
                &buffer,
                get_pdu_ptr(mmi_ilm_ptr->peer_buff_ptr, &len)) > 0)
        {

            if( buffer.header_len > 0 )
            {
                job_data->header_len = buffer.header_len;
                job_data->header = (S8*)get_ctrl_buffer(buffer.header_len+1);
                
                memcpy(job_data->header, buffer.header, buffer.header_len);
                job_data->header[job_data->header_len] = 0;
            }

            if( buffer.content_len > 0 )
            {
                job_data->content_len = buffer.content_len;
                job_data->content = (S8*)get_ctrl_buffer(buffer.content_len+1);
                memcpy(job_data->content, buffer.content, buffer.content_len);
                job_data->content[job_data->content_len] = 0;
            }
        }
    }

#if 0 //def __DRM_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


#ifdef __DRM_SUPPORT__
    /* DRM Rights is auto-install */
    if( mmi_da_is_drm_right(job->mime_type) ||
        mmi_da_is_drm_roap(job->mime_type))
    {
        mmi_da_http_job_confirm_dl_callback((U32)job);
        return;
    }
#endif

    /* Show confirm screen */
    mmi_da_scr_confirm_download((U32)job, mmi_da_http_set_confirm_msg, 
        mmi_da_http_job_confirm_dl_callback, mmi_da_http_job_cancel_dl_callback,
        MMI_TRUE, APP_WAP);
}

static void mmi_da_http_job_cancel_dl_callback(U32 criteria, BOOL in_delete)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* cancel, free resource */
    mmi_da_job_cancel((mmi_da_job_struct*)criteria);
}

static void mmi_da_http_job_confirm_dl_callback(U32 criteria)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_job_struct           *job;
    mmi_da_normal_dl_job_struct *job_data;
    mmi_da_setting_struct       *setting_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    job = (mmi_da_job_struct*)criteria;
    job_data = (mmi_da_normal_dl_job_struct*)job->data_ptr;

    /* retrieve setting */
    setting_data = mmi_da_get_setting_buffer();
    mmi_da_http_get_setting(job, setting_data);

    /* store setting */
    mmi_da_copy_setting(job, setting_data);

    /* prepare storage parameter */
    {
        mmi_da_scr_storage_parameter_struct para;

        memset(&para, 0, sizeof(para));
        
        para.drv = setting_data->drv;
        para.storage = setting_data->storage;
        para.select_storage = setting_data->storage == MMI_DA_STORAGE_NONE ? TRUE : FALSE;

        para.folder = setting_data->folder;

        if(!setting_data->default_filename && setting_data->filename[0])
        {
            mmi_da_extract_filepath(setting_data->filename, para.filename, para.fileext);
        }
        else if(job_data->filepath && mmi_ucs2strlen((S8*)job_data->filepath))
        {
            mmi_da_extract_filepath(job_data->filepath, para.filename, para.fileext);
        }
        else            
        {
            mmi_da_extract_filepath_ascii(job_data->url_ptr, para.filename, para.fileext);
        }
        
        para.select_filename = (!setting_data->default_filename && setting_data->filename[0] == 0) ? TRUE : FALSE;

        para.filesize = job_data->size;
        
#ifdef __DRM_SUPPORT__
        /* DRM V1.0 content require twice space */
        if( job->mime_type && 
            (job->mime_type->mime_subtype == MIME_SUBTYPE_DRM_CONTENT ||
             job->mime_type->mime_subtype == MIME_SUBTYPE_DRM_MESSAGE) )
        {
            para.filesize *= 2;
        }
#endif

        /* if app control (provide filepath callback), skip file size checking */
        if(job->setting_info.filepath_hdlr)
            para.filesize = 0;

        if(job->mime_type)
            para.ext = (S8*)job->mime_type->file_ext;
        para.filecheck_func = (void*)mmi_da_find_job_by_filepath;
    
        /* confirmed, select storage now. */
        mmi_da_scr_select_storage(mmi_da_http_filename_done, &para, (U32)job, APP_WAP);
    }
}

static BOOL mmi_da_http_filename_done(U32 criteria, U16* filepath, BOOL canback, BOOL canpopup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_job_struct           *job;
    mmi_da_normal_dl_job_struct *job_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    job = (mmi_da_job_struct*)criteria;
    job_data = (mmi_da_normal_dl_job_struct*)job->data_ptr;
    
    if(!filepath)
    {
        /* user cancel, free resource */
        mmi_da_job_cancel(job);
        return TRUE;
    }

    /* notify client if required */
    if(job->setting_info.filepath_hdlr)
    {
        ASSERT(job->mime_type);
        if(!job->setting_info.filepath_hdlr(DA_MAKE_UNIQUE_ID(job, job_data->session_id),
                                            job->mime_type->mime_type,
                                            job->mime_type->mime_subtype,
                                            filepath))
        {
            /* App cancel */
            if(!canback)
                mmi_da_job_cancel(job);        
            return FALSE;
        }
    }

    /* assign final path */
    UCS2_STR_MALLOC_COPY(job_data->filepath, filepath);

    /* notify DLS for path */
    mmi_da_send_wap_file_dl_res(job_data->session_id, WAP_DL_ERROR_OK, job_data->filepath);

    /* starting download */
    job->state = MMI_DA_JOB_STATE_DOWNLOADING;
    job_data->curr_size = 0;
    kal_get_time(&job_data->dl_start_tick);

    /* download is starting!, push it into list */
    mmi_da_job_start(job);
    
#ifdef __DRM_SUPPORT__
    if( mmi_da_is_drm_right(job->mime_type) ||
        mmi_da_is_drm_roap(job->mime_type))
    {
        return TRUE;
    }
#endif

#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    if(job->setting_info.can_minimize)
    {
        /* bring up list screen */
        mmi_da_display_job_list(job, TRUE);
    }
    else
#endif
    {
        /* directly go to job detail */
        mmi_da_display_job_detail(job);
    }
    return TRUE;
}

/*****************************************************************************
* FUNCTION
*   mmi_da_set_cfm_msg
* DESCRIPTION
*   construct the confirm message
* PARAMETERS
*   out     [OUT]   the confirm message,
*                   the memory space should prepared by whom use it
* RETURNS
*   void
*****************************************************************************/
static void mmi_da_http_set_confirm_msg(U32 criteria, U16 *out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_job_struct           *job;
    mmi_da_normal_dl_job_struct *job_data;
    U32 estimated_secs;
    U16 buffer[MMI_DA_UTIL_ESTIMATED_TIME_FORMAT_LEN]; /* xx min. xx sec. */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    job = (mmi_da_job_struct*)criteria;
    job_data = (mmi_da_normal_dl_job_struct*)job->data_ptr;

    out[0] = 0;
    if(job_data->size)
    {
        DA_SHOW_INFO(out, "%w: %s\n", GetString(STR_ID_DA_PROMPT_SIZE), mmi_da_util_format_size(job_data->size));

        /* calculte the time require to DL */
        estimated_secs = mmi_da_util_get_estimated_time(job_data->size);
        if(MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN != estimated_secs)
        {
            mmi_da_util_format_time(buffer, estimated_secs);
            DA_SHOW_INFO(out, "%w: %w\n", GetString(STR_ID_DA_PROMPT_ESTIMATED), buffer);
        }
    }
    else
    {
        DA_SHOW_INFO(out, "%w: %w\n", GetString(STR_ID_DA_PROMPT_SIZE), GetString(STR_ID_DA_PROMPT_UNKNOWN));
    }

    if(job->mime_type)
    {
        DA_SHOW_INFO(out, "%w: %s\n", GetString(STR_ID_DA_PROMPT_TYPE), job->mime_type->mime_string);
    }
    else if(job_data->mime_type_ptr)
    {
        DA_SHOW_INFO(out, "%w: %s\n", GetString(STR_ID_DA_PROMPT_TYPE), job_data->mime_type_ptr);
    }
    else
    {
        DA_SHOW_INFO(out, "%w: %w\n", GetString(STR_ID_DA_PROMPT_TYPE), GetString(STR_ID_DA_PROMPT_UNKNOWN));
    }

    if(!job->mime_type)
    {
        U16 *ptr;
        mmi_ucs2cat((S8*)out, (S8*)L"\n");
        mmi_ucs2cat((S8*)out, GetString(STR_ID_DA_PROMPT_NOT_SUPPORT));
        mmi_ucs2cat((S8*)out, (S8*)FMGR_DEFAULT_FOLDER_RECEIVED);
        ptr = out + (mmi_ucs2strlen((S8*)out)-1);
        if(*ptr == '\\')
            *ptr = 0;
    }

}


/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_da_send_wap_file_dl_res(S32 session_id, S32 error, U16* filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmi_file_dl_res_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg = (wap_mmi_file_dl_res_struct*) OslConstructDataPtr(sizeof(wap_mmi_file_dl_res_struct));

    msg->session_id = session_id;
    msg->result = error;
    if(filepath)
    {
        mmi_ucs2ncpy((S8*)msg->file_path, (S8*)filepath, sizeof(msg->file_path));
    }
    else
    {
        msg->file_path[0] = msg->file_path[1] = 0;
    }
    mmi_da_send_ilm(msg, NULL, MSG_ID_WAP_MMI_FILE_DL_RES, MOD_WAP);
}

#define RECV_WAP_FILE_DL_PROGRESS

static void mmi_da_recv_wap_file_dl_progress_ind(void *MsgStruct, int mod_src, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmi_file_dl_progress_ind_struct *msg = (wap_mmi_file_dl_progress_ind_struct*) MsgStruct;
    mmi_da_job_struct           *job;
    mmi_da_normal_dl_job_struct *job_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* search from job list for session id */
    job = mmi_da_find_job(mmi_da_job_match_id_func, 
        (U32)DA_MAKE_UNIQUE_ID_EX(MMI_DA_JOB_TYPE_NORMAL, msg->session_id));
    if(!job)
        return;
    job_data = (mmi_da_normal_dl_job_struct*)job->data_ptr;

    /* communicate with lower layer */
    mmi_da_send_wap_file_dl_progress_res(msg->session_id, msg->seq_num);

    /* state checking */
    if(job->state == MMI_DA_JOB_STATE_ABORTING)
        return;
    if(job->state != MMI_DA_JOB_STATE_DOWNLOADING)
    {
        ASSERT(0);
        return;
    }
  
    /* update status */
    job_data->curr_size = msg->acc_size;
    kal_get_time(&job_data->dl_latest_tick);
    job->error_cause = mmi_da_wap_error_transfer(msg->cause);

    switch(msg->status)
    {
        case WAP_DL_STATUS_CANCELLED:
            
            ASSERT(0);
            job->state = MMI_DA_JOB_STATE_ABORTED;
            break;
            
        case WAP_DL_STATUS_ABORTED:
            
            if(job->setting_info.report_hdlr)
            {
                job->state = MMI_DA_JOB_STATE_ABORTED;
                break;
            }
            
#ifndef __MMI_DOWNLOAD_AGENT_MULTI_DL__
            job->popup_str_id = mmi_da_util_get_wap_error_string_id(msg->cause);
            if(job->popup_str_id)
            {
                DisplayPopup((PU8) GetString((U16) job->popup_str_id), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME,
                             (U8) ERROR_TONE);
                job->popup_str_id = 0;
            }
            job->state = MMI_DA_JOB_STATE_ABORTED;
#else
            /* update state */
            if(job->setting_info.can_minimize)
            {
                switch(msg->cause)
                {
                case WAP_DL_ERROR_CONNECTION_CLOSED:
                case WAP_DL_ERROR_DISK_FULL:
                    job->state = MMI_DA_JOB_STATE_PAUSED;
                    break;

                default:
                    job->state = MMI_DA_JOB_STATE_FAILED;
                }
            }
            else
            {
                /* remove job, regardless of popup already. */
                job->state = MMI_DA_JOB_STATE_ABORTED;
            }
            
            /* update popup info */
            job->popup_str_id = mmi_da_util_get_wap_error_string_id(msg->cause);
            if(job->popup_str_id && mmi_da_is_in_foreground_state())
            {
                DisplayPopup((PU8) GetString((U16) job->popup_str_id), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME,
                             (U8) ERROR_TONE);
                job->popup_str_id = 0;
                
                if(job->state == MMI_DA_JOB_STATE_FAILED)
                {
                    job->state = MMI_DA_JOB_STATE_ABORTED;
                }
            }
#endif            
            break;
            
        case WAP_DL_STATUS_COMPLETE:
            job->state = MMI_DA_JOB_STATE_COMPLETED;

#ifdef __DRM_SUPPORT__
            /* parse DRM type first */
            if(mmi_da_is_drm_require_processing(job->mime_type))
            {
                mmi_da_drm_process_file(job, job_data->filepath, 
                                        mmi_da_http_drm_process_callback);
                return;
            }
#endif
            break;
            
        case WAP_DL_STATUS_DOWNLOADING:
            job->state = MMI_DA_JOB_STATE_DOWNLOADING;
            break;
    }

    mmi_da_update_job_status(job);

    if(mmi_da_is_job_valid(job) && job->state != MMI_DA_JOB_STATE_DOWNLOADING)
        job_data->session_id = DA_INVALID_SESSION_ID;
    
}

/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_da_send_wap_file_dl_progress_res(S32 session_id, U32 seq_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmi_file_dl_progress_res_struct * msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (wap_mmi_file_dl_progress_res_struct*) OslConstructDataPtr(sizeof(wap_mmi_file_dl_progress_res_struct));
    msg->session_id = session_id;
    msg->seq_num = seq_num;
    mmi_da_send_ilm(msg, NULL, MSG_ID_WAP_MMI_FILE_DL_PROGRESS_RES, MOD_WAP);
}

static void mmi_da_recv_wap_file_stop_rsp(void *MsgStruct, int mod_src, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmi_file_dl_stop_rsp_struct *msg;
    mmi_da_job_struct               *job;
    mmi_da_normal_dl_job_struct     *job_data;
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    U32                             size;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (wap_mmi_file_dl_stop_rsp_struct*) MsgStruct;
    job = mmi_da_find_job(mmi_da_job_match_id_func, 
        (U32)DA_MAKE_UNIQUE_ID_EX(MMI_DA_JOB_TYPE_NORMAL, msg->session_id));
    if(!job)
        return;
    job_data = (mmi_da_normal_dl_job_struct*)job->data_ptr;
    ASSERT(job->state == MMI_DA_JOB_STATE_ABORTING);
    job->state = MMI_DA_JOB_STATE_ABORTED;
    job_data->session_id = DA_INVALID_SESSION_ID;
    
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    size = mmi_da_util_get_file_size(job_data->filepath);
    if(size)
        job_data->curr_size = size;
#endif

    job_data->abort_callback(job, 0);
    // After callback, job may be removed, do not use it.
}

#define JOB_TABLE

static BOOL mmi_da_http_free_job(mmi_da_job_struct* job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_normal_dl_job_struct *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(job->type != MMI_DA_JOB_TYPE_NORMAL)
        return FALSE;
    
    job_data = (mmi_da_normal_dl_job_struct*)job->data_ptr;

    if(job->state == MMI_DA_JOB_STATE_INIT)
        mmi_da_send_wap_file_dl_res(job_data->session_id, WAP_DL_ERROR_CANCELLED, NULL);

#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    if(job_data->session != MMI_DA_INVALID_SESSION_HANDLE)
    {
        mmi_da_wps_close_session(job_data->session, NULL);
        job_data->session = MMI_DA_INVALID_SESSION_HANDLE;
    }
#endif

    if(job->state != MMI_DA_JOB_STATE_COMPLETED && job_data->filepath && !job->setting_info.report_hdlr)
        FS_Delete(job_data->filepath);
    
    DA_FREE_BUFFER(job_data->url_ptr);
    DA_FREE_BUFFER(job_data->mime_type_ptr);
    DA_FREE_BUFFER(job_data->filepath);
    DA_FREE_BUFFER(job_data->content);
    DA_FREE_BUFFER(job_data->header);

    OslMfree(job_data);
    job->data_ptr = NULL;
    
    DA_TRACE_ENDFUNC(mmi_da_http_free_job);
    return TRUE;
}

static U16* mmi_da_http_get_item_filepath(const mmi_da_job_struct* job, U16* buffer, U32 buffer_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_normal_dl_job_struct *job_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(job->type == MMI_DA_JOB_TYPE_NORMAL);
    job_data = (mmi_da_normal_dl_job_struct*)job->data_ptr;
    return (U16*) mmi_ucs2ncpy((S8*)buffer, (S8*)job_data->filepath, buffer_len);
}

static U32 mmi_da_http_get_item_progress(const mmi_da_job_struct* job, mmi_da_item_progress_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_normal_dl_job_struct *job_data;
    U32 secs;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(job->type == MMI_DA_JOB_TYPE_NORMAL);
    job_data = (mmi_da_normal_dl_job_struct*)job->data_ptr;

    info->fileSize = job_data->size;
    info->currSize = job_data->curr_size;
    info->processing_string = NULL;
    secs = (U32)((job_data->dl_latest_tick - job_data->dl_start_tick) * 4.615 / 1000);
    if(job_data->size && job_data->curr_size && secs)
    {
        info->secs_remain = secs * (job_data->size - job_data->curr_size) / job_data->curr_size;
    }
    else
    {
        info->secs_remain = MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN;
    }

    if(job_data->size)
        return ((U64)job_data->curr_size * 100) / job_data->size;
    else
    {
        if(job->state == MMI_DA_JOB_STATE_COMPLETED)
            return 100;
        else
            return MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN;
    }
}

static void mmi_da_http_abort_job(mmi_da_job_struct* job, S32 prev_state, BOOL pauseOnly,
                                  mmi_da_abort_callback_type end_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmi_file_dl_stop_req_struct* msg;
    mmi_da_normal_dl_job_struct *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(prev_state == MMI_DA_JOB_STATE_DOWNLOADING);
    ASSERT(job->state == MMI_DA_JOB_STATE_ABORTING);
    job_data = (mmi_da_normal_dl_job_struct*)job->data_ptr;

    job_data->abort_callback = end_callback;
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    if(job_data->session != MMI_DA_INVALID_SESSION_HANDLE)
    {
        /* Resuming */
        mmi_da_wps_close_session(job_data->session, mmi_da_http_wps_session_aborted_callback);
    }
    else 
#endif        
    if(job_data->session_id != -1)
    {
        msg = (wap_mmi_file_dl_stop_req_struct*) OslConstructDataPtr(sizeof(wap_mmi_file_dl_stop_req_struct));
        msg->session_id = job_data->session_id;
        mmi_da_send_ilm(msg, NULL,MSG_ID_WAP_MMI_FILE_DL_STOP_REQ, MOD_WAP);
    }
    else
    {
        ASSERT(0);
    }
}

static void mmi_da_http_dispatch_job(const mmi_da_job_struct* job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_normal_dl_job_struct *job_data;
    S32 index;
    mmi_da_hook_dispatch_hdlr hook_hdlr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(job->type == MMI_DA_JOB_TYPE_NORMAL);
    job_data = (mmi_da_normal_dl_job_struct*)job->data_ptr;

    index = 0;
    while(1)
    {
        index = mmi_da_search_hook_handler(job->mime_type, index, &hook_hdlr);
        if(index == -1)
            break;

        DA_TRACE_FUNC1(mmi_da_call_hook_func_index, index);
        if(hook_hdlr && TRUE == hook_hdlr(DA_MAKE_UNIQUE_ID(job, job_data->session_id),
                                     job->mime_type->mime_type,
                                     job->mime_type->mime_subtype,
                                     MMI_DA_WAP_DOWNLOAD,
                                     job_data->filepath,
                                     job_data->url_ptr,
                                     job_data->mime_type_ptr))
        {
            // someone return TRUE
            DA_TRACE_FUNC(mmi_da_func_is_hooked);
            return;
        }
    }
    
    job->type_handler->dispatch_hdlr(DA_MAKE_UNIQUE_ID(job, job_data->session_id),
                                     job->mime_type->mime_type,
                                     job->mime_type->mime_subtype,
                                     MMI_DA_WAP_DOWNLOAD,
                                     job_data->filepath,
                                     job_data->url_ptr,
                                     job_data->mime_type_ptr);
}

static S16 mmi_da_http_get_job_id(const mmi_da_job_struct* job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_normal_dl_job_struct *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(job->type == MMI_DA_JOB_TYPE_NORMAL);
    job_data = (mmi_da_normal_dl_job_struct*)job->data_ptr;

#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    if(job_data->session != MMI_DA_INVALID_SESSION_HANDLE)
    {
        return mmi_da_wps_get_session_id(job_data->session);
    }
#endif
    return job_data->session_id;
}

#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__

static void mmi_da_http_resume_job(mmi_da_job_struct* job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_normal_dl_job_struct *job_data;
    U32                         size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(job->type == MMI_DA_JOB_TYPE_NORMAL);
    ASSERT(job->state == MMI_DA_JOB_STATE_PAUSED);
    job_data = (mmi_da_normal_dl_job_struct*)job->data_ptr;

    /* Before resume, check the file length again */
    size = mmi_da_util_get_file_size(job_data->filepath);
    if(size)
        job_data->curr_size = size;

    if(job_data->session != MMI_DA_INVALID_SESSION_HANDLE)
    {
        mmi_da_wps_close_session(job_data->session, NULL);
        job_data->session = MMI_DA_INVALID_SESSION_HANDLE;
    }

    /* DLS do not support resume, so we use WPS session */
    mmi_da_wps_create_session((U32)job, mmi_da_http_wps_created_callback,
                              mmi_da_http_wps_http_response_callback,
                              mmi_da_http_wps_http_auth_ind_callback,
                              mmi_da_http_wps_dl_progress_callback);   
}

static S32 mmi_da_http_move_job(mmi_da_job_struct* job, U16* new_filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_normal_dl_job_struct *job_data;
	S32                         result = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(job->type == MMI_DA_JOB_TYPE_NORMAL);
    ASSERT(job->state == MMI_DA_JOB_STATE_COMPLETED);
    job_data = (mmi_da_normal_dl_job_struct*)job->data_ptr;

    if(mmi_ucs2icmp((S8*)new_filepath, (S8*)job_data->filepath) != 0)
    {
        /* Prevent Read Only */
        result = FS_Move(job_data->filepath, new_filepath, FS_MOVE_KILL, NULL, NULL, 0);
        if(result >= 0)
            UCS2_STR_MALLOC_COPY(job_data->filepath, new_filepath);
    }
    return result;
}
#endif

static void mmi_da_http_get_setting(const mmi_da_job_struct* job, mmi_da_setting_struct *setting_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_normal_dl_job_struct *job_data;
    mmi_da_setting_hdlr         setting_hdlr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    ASSERT(job->type == MMI_DA_JOB_TYPE_NORMAL);
    job_data = (mmi_da_normal_dl_job_struct*)job->data_ptr;

    setting_hdlr = mmi_da_default_setting;
    ASSERT(job->type_handler);
    if(job->type_handler->setting_hdlr)
        setting_hdlr = job->type_handler->setting_hdlr;

    setting_hdlr(
        DA_MAKE_UNIQUE_ID(job, job_data->session_id),
        job->mime_type ? job->mime_type->mime_type : 0,
        job->mime_type ? job->mime_type->mime_subtype : 0,
        MMI_DA_WAP_DOWNLOAD,
        job_data->size,
        job_data->url_ptr,
        job_data->mime_type_ptr,
        job_data->content_len,
        job_data->content,
        setting_data
    );

    MMI_TRACE(MMI_DA_TRACE_GROUP, MMI_DA_GET_SETTING,
        setting_data->bypass,
        setting_data->default_filename,
        setting_data->drv,
        setting_data->keepfile,
        setting_data->percentage_bar,
        setting_data->storage);
    ASSERT(mmi_da_setting_check(setting_data));
}
#define DRM_PROC

#ifdef __DRM_SUPPORT__
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

static void mmi_da_http_drm_process_callback(mmi_da_job_struct* job,
                                             U16 *new_filepath, U16 err_string_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_normal_dl_job_struct *job_data;
    S32                         ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(job->type == MMI_DA_JOB_TYPE_NORMAL);
    job_data = (mmi_da_normal_dl_job_struct*)job->data_ptr;

    if(!new_filepath)
    {
        if(mmi_da_is_in_foreground_state() || err_string_id == 0)
        {
            if(err_string_id)
            {
                DisplayPopup((PU8) GetString((U16) err_string_id), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME,
                             (U8) ERROR_TONE);
            }
            job->state = MMI_DA_JOB_STATE_ABORTED;
            mmi_da_update_job_status(job);
        }
        else
        {
            job->popup_str_id = (U16) err_string_id;
            job->state = MMI_DA_JOB_STATE_FAILED;
            mmi_da_update_job_status(job);
        }
        return;
    }

    /* delete old file */
    if(mmi_ucs2icmp((S8*)job_data->filepath, (S8*)new_filepath))
        ret = FS_Delete(job_data->filepath);

#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    DA_FREE_BUFFER(job_data->filepath);
    job_data->filepath = new_filepath;
    job->state = MMI_DA_JOB_STATE_COMPLETED;
    mmi_da_update_job_status(job);
#else
    {
        /* emulate a SAVE AS push */
        mmi_da_dispatch_file_req_struct *p;

        p = (mmi_da_dispatch_file_req_struct*) construct_local_para(sizeof(mmi_da_dispatch_file_req_struct), TD_CTRL | TD_RESET);

        EntryNewScreen(SCR_ID_DA_DISPATCH_DUMMY, NULL, NULL, NULL);
        p->action = MMI_DA_ACT_INTERNAL_SAVE_AS;
#ifdef __DRM_V02__
        if(job->drm.drm_method == DRM_METHOD_V2)
            p->action |= MMI_DA_ACT_INTERNAL_SAVE_AS_NORMAL;
#endif
        mmi_ucs2ncpy((S8*)p->filepath, (S8*)new_filepath, FMGR_MAX_PATH_LEN);
        mmi_ucs2ncpy((S8*)p->filename, (S8*)mmi_da_util_get_filename(job_data->filepath), FMGR_MAX_FILE_LEN);
        p->mime_type = job->mime_type ? job->mime_type->mime_type : MIME_TYPE_UNKNOWN;
        p->mime_subtype = job->mime_type ? job->mime_type->mime_subtype : MIME_SUBTYPE_UNRECOGNIZED;
        if(job_data->url_ptr)
            strncpy(p->mime_type_string+1, job_data->url_ptr, 500);
        mmi_da_send_ilm(p, NULL, MSG_ID_MMI_DA_DISPATCH_FILE_REQ, MOD_MMI);

        DA_FREE_BUFFER(job_data->filepath);
        DA_FREE_BUFFER(new_filepath);
        job->state = MMI_DA_JOB_STATE_ABORTED;
        mmi_da_job_error_cleanup(job);        
    }
#endif
}


#endif /* __DRM_SUPPORT__ */

#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
static BOOL mmi_da_http_job_match_url_func(const mmi_da_job_struct* job, U32 criteria)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_normal_dl_job_struct *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if(job->type != MMI_DA_JOB_TYPE_NORMAL)
        return FALSE;
        
    job_data = (mmi_da_normal_dl_job_struct*)job->data_ptr;
    if(job_data && strcmp(job_data->url_ptr, (S8*)criteria) == 0)
        return TRUE;

    return FALSE;
}

#define DLS_RESUME_WPS

static void mmi_da_http_please_wait_abort_callback(U32 criteria, BOOL in_delete)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_job_struct           *job;
    mmi_da_normal_dl_job_struct *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = (mmi_da_job_struct*)criteria;
    ASSERT(mmi_da_is_job_valid(job));
    ASSERT(job->type == MMI_DA_JOB_TYPE_NORMAL);
    ASSERT(job->state == MMI_DA_JOB_STATE_PAUSED);
    job_data = (mmi_da_normal_dl_job_struct*)job->data_ptr;

    if(!in_delete)
    {
        EntryNewScreen(SCR_ID_DA_CONFIRM_DUMMY, NULL, NULL, NULL);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    }
    ASSERT(job_data->session != MMI_DA_INVALID_SESSION_HANDLE);
    mmi_da_wps_close_session(job_data->session, mmi_da_http_wps_session_resume_aborted_callback);
    
}

static void mmi_da_http_wps_created_callback(wps_session_handle session, U32 arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_job_struct           *job;
    mmi_da_normal_dl_job_struct *job_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = (mmi_da_job_struct*)arg;
    ASSERT(job && job->type == MMI_DA_JOB_TYPE_NORMAL);
    job_data = (mmi_da_normal_dl_job_struct*)job->data_ptr;

    if(!session)
    {
        DisplayPopup((PU8) GetString(STR_ID_DA_ERROR_RESUME_FAIL), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
        return;
    }

    job_data->session = session;

    /* send request */
    mmi_da_scr_entry_please_wait((U32)job, mmi_da_http_please_wait_abort_callback, APP_WAP);
    /* send request */
    if(!mmi_da_wps_http_req(job_data->session, WPS_HTTP_METHOD_GET,
                        job_data->url_ptr, NULL, job_data->filepath, 0))
    {
        ASSERT(0);
    }
}

static void mmi_da_http_wps_http_response_callback(U32 arg, U8 result, U16 status, 
                                                   S8 *content_type, U32 content_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_job_struct           *job;
    mmi_da_normal_dl_job_struct *job_data;
    BOOL                        enter_job_list;
    const applib_mime_type_struct *mime_type;
    U16                         stringID;
    BOOL                        fatal_error = TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DA_TRACE_FUNC3(mmi_da_http_http_response, result, status, content_len);
    
    job = (mmi_da_job_struct*)arg;
    ASSERT(job && job->type == MMI_DA_JOB_TYPE_NORMAL);
    ASSERT(job->state == MMI_DA_JOB_STATE_PAUSED);
    job_data = (mmi_da_normal_dl_job_struct*)job->data_ptr;

    enter_job_list = (GetActiveScreenId() == SCR_ID_DA_SCREEN_PLEASE_WAIT) ? TRUE : FALSE;
    EntryNewScreen(SCR_ID_DA_DUMMY, NULL, NULL, NULL);    
    mmi_da_scr_close_please_wait();

    stringID = STR_ID_DA_ERROR_RESUME_FAIL;

    /* check result */
    if(result != WPS_OK)
    {
        if(result == WPS_ERROR_REQ_ABORT)
            fatal_error = FALSE;
        goto error_cleanup;
    }
    if (status == 401 || status == 407)
    {
        goto error_cleanup;
    }
    if (status >= 300 || status < 200)
    {
        goto error_cleanup;
    }
    
    /* check content len */
    if (status != 206)
    {
        /* full content */
        if(job_data->size == 0)
           job_data->size = content_len;
        if(content_len != job_data->size)
        {
            DA_TRACE_FUNC1(mmi_da_http_http_response_error, 1);
            goto error_cleanup;
        }
    }
    else
    {
        if(job_data->size == 0 && content_len)
           job_data->size = job_data->curr_size + content_len;
        
        if(content_len && content_len + job_data->curr_size != job_data->size)
        {
            DA_TRACE_FUNC1(mmi_da_http_http_response_error, 2);
            goto error_cleanup;
        }
    }
    
    /* check mimetype */
    mime_type = mmi_da_util_lookup_mime_type((U8*)content_type, 
                                                  mmi_da_util_get_extension((U16*)job_data->filepath), 
                                                  0, 0);
    /* only need to check if file is typed */
    if(job->mime_type && 
        (!mime_type || 
         mime_type->mime_type != job->mime_type->mime_type || 
         mime_type->mime_subtype != job->mime_type->mime_subtype) )
    {
        DA_TRACE_FUNC1(mmi_da_http_http_response_error, 99);
        goto error_cleanup;
    }
    
    /* its all ok now, Download start! */
    job->state = MMI_DA_JOB_STATE_DOWNLOADING;

    if(status != 206)   /* full content, so reset size */
        job_data->curr_size = 0;
    
    mmi_da_job_start(job);
    kal_get_time(&job_data->dl_start_tick);

    if(enter_job_list)
    {
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
        if(job->setting_info.can_minimize)
        {
            /* bring up list screen */
            mmi_da_display_job_list(job, FALSE);
        }
        else
#endif        
        {
            /* directly go to job detail */
            mmi_da_display_job_detail(job);
        }
    }

    if(GetActiveScreenId() == SCR_ID_DA_DUMMY)
        GoBackHistory();
    return;
    
error_cleanup:
    if(fatal_error)
    {
        if(enter_job_list)
            DisplayPopup((PU8) GetString(stringID), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
        if(GetActiveScreenId() == SCR_ID_DA_DUMMY)
            GoBackHistory();

        job->state = MMI_DA_JOB_STATE_ABORTED;
        mmi_da_update_job_status(job);
    }
    else
    {
        job->popup_str_id = stringID;
        job->state = MMI_DA_JOB_STATE_ABORTING;
        EntryNewScreen(SCR_ID_DA_CONFIRM_DUMMY, NULL, NULL, NULL);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ASSERT(job_data->session != MMI_DA_INVALID_SESSION_HANDLE);
        mmi_da_wps_close_session(job_data->session, mmi_da_http_wps_session_resume_aborted_callback);
    }    
}
                                                  
static void mmi_da_http_wps_http_auth_ind_callback(U32 arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_job_struct           *job;
    mmi_da_normal_dl_job_struct *job_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = (mmi_da_job_struct*)arg;
    ASSERT(job && job->type == MMI_DA_JOB_TYPE_NORMAL);
    job_data = (mmi_da_normal_dl_job_struct*)job->data_ptr;

    // Temp solution, remove job
    DisplayPopup((PU8) GetString(STR_ID_DA_ERROR_RESUME_FAIL), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
    mmi_da_scr_close_please_wait();
    job->state = MMI_DA_JOB_STATE_ABORTED;
    mmi_da_update_job_status(job);
}
    
static void mmi_da_http_wps_dl_progress_callback(U32 arg, U8 status, U32 curr_size, S32 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_job_struct           *job;
    mmi_da_normal_dl_job_struct *job_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = (mmi_da_job_struct*)arg;
    ASSERT(job && job->type == MMI_DA_JOB_TYPE_NORMAL);
    job_data = (mmi_da_normal_dl_job_struct*)job->data_ptr;

    /* state checking */
    if(job->state == MMI_DA_JOB_STATE_ABORTING)
        return;
    if(job->state != MMI_DA_JOB_STATE_DOWNLOADING)
    {
        ASSERT(0);
        return;
    }
  
    /* update status */
    job_data->curr_size = curr_size;
    kal_get_time(&job_data->dl_latest_tick);

    switch(status)
    {
        case WPS_DL_STATUS_ABORT:
            if(cause < 0 && mmi_da_is_in_foreground_state())
            {
                /* FS error */
                DisplayPopup((PU8) GetString((U16) GetFileSystemErrorString(cause)), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME,
                             (U8) ERROR_TONE);
            }
            if(job->setting_info.can_minimize)
                job->state = MMI_DA_JOB_STATE_PAUSED;
            else
                job->state = MMI_DA_JOB_STATE_ABORTED;

            if(job_data->session != MMI_DA_INVALID_SESSION_HANDLE)
            {
                mmi_da_wps_close_session(job_data->session, NULL);
                job_data->session = MMI_DA_INVALID_SESSION_HANDLE;
            }
            break;
            
        case WPS_DL_STATUS_COMPLETE:
            job->state = MMI_DA_JOB_STATE_COMPLETED;

            // close session
            if(job_data->session != MMI_DA_INVALID_SESSION_HANDLE)
            {
                mmi_da_wps_close_session(job_data->session, NULL);
                job_data->session = MMI_DA_INVALID_SESSION_HANDLE;
            }
            
#ifdef __DRM_SUPPORT__
            /* parse DRM type first */
            if(mmi_da_is_drm_require_processing(job->mime_type))
            {
                mmi_da_drm_process_file(job, job_data->filepath, 
                                        mmi_da_http_drm_process_callback);
                return;
            }
#endif
            break;
            
        case WPS_DL_STATUS_DOWNLOADING:
            job->state = MMI_DA_JOB_STATE_DOWNLOADING;
            break;

        default:
            ASSERT(0);
            break;
    }

    mmi_da_update_job_status(job);
}

static void mmi_da_http_wps_session_aborted_callback(U32 arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_job_struct           *job;
    mmi_da_normal_dl_job_struct *job_data;
    U32                         size;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = (mmi_da_job_struct*)arg;
    ASSERT(job && job->type == MMI_DA_JOB_TYPE_NORMAL);
    job_data = (mmi_da_normal_dl_job_struct*)job->data_ptr;

    /* session closed */
    job_data->session = MMI_DA_INVALID_SESSION_HANDLE;
    
    ASSERT(job->state == MMI_DA_JOB_STATE_ABORTING);
    job->state = MMI_DA_JOB_STATE_ABORTED;
    
    size = mmi_da_util_get_file_size(job_data->filepath);
    if(size)
        job_data->curr_size = size;

    if(job_data->abort_callback)
        job_data->abort_callback(job, 0);
    // After callback, job may be removed, do not use it.
}

static void mmi_da_http_wps_session_resume_aborted_callback(U32 arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_job_struct           *job;
    mmi_da_normal_dl_job_struct *job_data;
    U32                         size;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = (mmi_da_job_struct*)arg;
    ASSERT(job && job->type == MMI_DA_JOB_TYPE_NORMAL);
    job_data = (mmi_da_normal_dl_job_struct*)job->data_ptr;

    if(job->popup_str_id)
    {
        DisplayPopup((PU8) GetString(job->popup_str_id), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
        job->popup_str_id = 0;
    }

    if(GetActiveScreenId() == SCR_ID_DA_CONFIRM_DUMMY)
        GoBackHistory();

    /* session closed */
    job_data->session = MMI_DA_INVALID_SESSION_HANDLE;

    /* if state != PAUSED, it means we have receive data before aborted, need handle such case */    
    if(job->state != MMI_DA_JOB_STATE_PAUSED)
    {
        size = mmi_da_util_get_file_size(job_data->filepath);
        if(size)
            job_data->curr_size = size;
        job->state = MMI_DA_JOB_STATE_PAUSED;
    }
    mmi_da_update_job_status(job);
}

#endif

#define DLS_EXPORT_API

const S8* mmi_da_http_get_header(mmi_da_job_struct *job, U32* header_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_normal_dl_job_struct *job_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(job && job->type == MMI_DA_JOB_TYPE_NORMAL);
    job_data = (mmi_da_normal_dl_job_struct*)job->data_ptr;

    if(header_len)
        *header_len = job_data->header_len;
    return job_data->header;
}


#endif /* __MMI_DOWNLOAD_AGENT__ */


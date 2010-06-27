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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/

#include "MMI_include.h"

#if defined (__MMI_OMA_DD_DOWNLOAD__)

#include "CommonScreens.h"
#include "ProtocolEvents.h"
#include "app_mine.h"
#include "FileMgr.h"
#include "drm_def.h"
#include "DLAgentDef.h"
#include "DLAgentGprot.h"
#include "DLAgentprot.h"
#include "DLAgentResDef.h"
#include "DLAgentWPS.h"
#include "DLAgentOMA.h"
#include "XML_def.h"

#include "SettingDefs.h"                /* ST_NOTIFICATION */
#include "SettingProfile.h"             /* ERROR_TONE */
#include "PhoneBookDef.h"               /* IMG_PROCESSING_PHONEBOOK */

#include "Wap_ps_struct.h"
#include "Wapadp.h"
#include "FileManagerGProt.h"           /* PUBLIC PRIVATE DRV */
#include "wgui_categories_inputs.h "    /* INPUT_TYPE_USE_ONLY_ENGLISH_MODES */
#include "Conversions.h"
#include "FileManagerDef.h"             /*FMGR_FS_ACCESS_DENIED_TEXT*/

#if defined(__MMI_OMA_DD2_DOWNLOAD__)

/****************************************************************************
* Define
*****************************************************************************/

#define MMI_DA_OMA_SAVE_DRV MMI_PUBLIC_DRV
#ifdef JATAAYU_SUPPORT
#define MMI_DA_OMA_SAVE_PATH    "Received"
#else
#define MMI_DA_OMA_SAVE_PATH    "Download"
#endif

/****************************************************************************
* Define - Macro
*****************************************************************************/

#define DA_SHOW_INFO(dst, format, tag_src, value_src) \
    kal_wsprintf((unsigned short*)(dst + mmi_ucs2strlen((S8*)dst)),(format),(tag_src), (value_src))

#define DA_GET_STRING(str_src) \
    (str_src == NULL || mmi_ucs2strlen(str_src) == 0) ? GetString(STR_ID_DA_PROMPT_UNKNOWN) : (str_src)
    
/****************************************************************************
* Typedef - Enum
*****************************************************************************/

/****************************************************************************
* Typedef - Struct
*****************************************************************************/

typedef struct
{
    /* dd info */
	mmi_da_oma_dd2_struct dd_info;

    S8          *dd_url;
    U16         *dd_filepath;
    S8          *dd_content_string;

    /* run-time variable */
    U16			*filepath;  /* mo full pathname */
    U32         curr_size;
    U32         dl_start_tick;
    U32         dl_latest_tick;

    wps_session_handle  session;

    /* report error */
    MMI_BOOL                 enter_sending_report;   /* prevent reentry, a debug only variable */
    mmi_da_oma_report_struct *report_obj;            /* do not free */
    
    /* authentication */
    U16         *auth_username;
    U16         *auth_password;
    S32         auth_request_id;

    /* other */
    mmi_da_abort_callback_type          abort_callback;
    
} mmi_da_omadl2_job_struct;

typedef struct
{
    mmi_da_job_struct   *curr_job;

} mmi_da_oma2_context_struct;

/****************************************************************************
* Static Variable
*****************************************************************************/

static mmi_da_oma2_context_struct da_oma2_context;

/****************************************************************************
* Global Variable
*****************************************************************************/

static void mmi_da_oma_init_module(void);

static U16* mmi_da_oma_get_item_filepath(const mmi_da_job_struct* job, U16* buffer, U32 buffer_len);
static U32  mmi_da_oma_get_item_progress(const mmi_da_job_struct* job, mmi_da_item_progress_struct *info);
static S16 mmi_da_oma_get_job_id(const mmi_da_job_struct* job);

static BOOL mmi_da_oma_free_job(mmi_da_job_struct* job);
static void mmi_da_oma_abort_job(mmi_da_job_struct* job, S32 prev_state, BOOL pauseOnly,
                                  mmi_da_abort_callback_type end_callback);
static void mmi_da_oma_dispatch_job(const mmi_da_job_struct* job);

#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
static S32 mmi_da_oma_move_job(mmi_da_job_struct* job, U16* new_filepath);
#endif

const mmi_da_module_funcptr_table mm_da_oma2_module =
{
    mmi_da_oma_init_module

    ,mmi_da_oma_get_item_filepath
    ,mmi_da_oma_get_item_progress
    ,mmi_da_oma_get_job_id
    ,NULL

    ,mmi_da_oma_free_job
    ,mmi_da_oma_abort_job
    ,mmi_da_oma_dispatch_job
    
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    ,NULL
    ,mmi_da_oma_move_job
#endif    
};

/****************************************************************************
* Global Function
*****************************************************************************/

extern kal_int8 mime_stricmp(kal_char *src, kal_char *dest);
extern kal_uint8 mime_strnicmp(kal_char *src, kal_char *dest, kal_int32 maxlen);

/****************************************************************************
* Function Forward Declaration
*****************************************************************************/

static void mmi_da_session_created_callback(wps_session_handle session, U32 arg);
static void mmi_da_session_http_response_callback(U32 arg, U8 result, U16 status, 
                                                  S8 *content_type, U32 context_len);
static void mmi_da_session_http_auth_ind_callback(U32 arg);
static void mmi_da_session_dl_progress_callback(U32 arg, U8 status, U32 curr_size, S32 cause);

static void mmi_da_oma_send_report_callback(mmi_da_job_struct* job, U8 result, U16 status);

static void mmi_da_oma_please_wait_abort_callback(U32 criteria);

/* UI related */
static void mmi_da_oma_job_cancel_dl_callback(U32 criteria);
static void mmi_da_oma_job_confirm_dl(void);
static void mmi_da_oma_set_confirm_msg(U32 criteria, U16 *out);
static void mmi_da_oma_highlight_download(void);
static void mmi_da_oma_highlight_view_dd(void);

static BOOL mmi_da_oma_filename_done(U32 criteria, U16* filepath, BOOL canback, BOOL canpopup);

static void mmi_da_oma_job_confirm_option_callback(U32 criteria);
static void mmi_da_oma_entry_download_option(void);
static void mmi_da_oma_entry_download_view_dd(void);

/* Tool API */
static void mmi_da_oma_close_session(mmi_da_job_struct* job);
static MMI_BOOL mmi_da_oma_popup_and_send_report(mmi_da_job_struct *job, S32 error, BOOL end_job, BOOL bpopup);

#ifdef __DRM_SUPPORT__
static void mmi_da_oma_drm_process_callback(mmi_da_job_struct* job,
                                            U16 *new_filepath, U16 err_string_id);
#endif                                            

static void _mmi_da_oma_get_current_obj(mmi_da_omadl2_job_struct* job_data,
                                        mmi_da_oma_dd2_product_struct** pproduct,
                                        mmi_da_oma_dd2_mo_struct** pmo,
                                        mmi_da_oma_dd2_meta_struct** pmeta);


typedef mmi_da_omadl2_job_struct CURR_JOB_TYPE;
#define CURR_JOB_TYPE_ENUM       MMI_DA_JOB_TYPE_OMADL2

#define END_OF_FUNCTION_DECLARATION
/****************************************************************************
* Function Section
*****************************************************************************/

/*****************************************************************************
* FUNCTION
*   mmi_da_oma_init_module
* DESCRIPTION
* PARAMETERS
* RETURNS
*   void
*****************************************************************************/
static void mmi_da_oma_init_module(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    da_oma2_context.curr_job = NULL;
}

/*****************************************************************************
* FUNCTION
*   mmi_da_oma_setting
* DESCRIPTION
*   When the file is downloaded from WAP browser, we set it as oma download
*   else, we save it to file system only.
* PARAMETERS
* RETURNS
*   void
*****************************************************************************/
void mmi_da_oma2_setting(
    S32 session_id,
    S32 mime_type,                  /* applib_mime_type_enum */
    S32 mime_subtype,               /* applib_mime_subtype_enum */
	S32 action,
    U32 filesize,
    S8  *url,                        /* WAP_DL_MAX_URL_LEN */
    S8  *mime_type_string,           /* WAP_DL _MAX_MIME_TYPE_LEN */
    U32 content_len,
    S8  *content,
    mmi_da_setting_struct * setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if( action == MMI_DA_WAP_DOWNLOAD ) /* OMA DL */
    {
        mmi_da_bypass_setting(
            session_id, mime_type, mime_subtype, action,
            filesize, url, mime_type_string, content_len,
            content, setting);
    }
    else    /* treat this as normal file, dont dispatch */
    {
        mmi_da_default_setting(
            session_id, mime_type, mime_subtype, action,
            filesize, url, mime_type_string, content_len,
            content, setting);
        setting->do_dispatch = FALSE;
    }

}

/*************************************************************************
* FUNCTION
*   mmi_da_oma_process_dd_file
* DESCRIPTION
*   Start to handle dd file
* PARAMETERS
*   mime_type   [IN]    the mime type of file
*   mime_subtype[IN]    the sub mime type of file
*   action_type [IN]    defined in Download agent
*   filename    [IN]    the filepath of file
*   download_url[IN]    the source of file, normally is a link
*   mime_type_string    [IN]    the originaly mime type string get from server
* RETURNS
*   void
*************************************************************************/
void mmi_da_oma_process_dd2_file(S32 session_id, S32 mime_type, S32 mime_subtype,
                                 S32 action_type, PU16 filename, PS8 download_url,
                                 PS8 mime_type_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_job_struct           *job;
    CURR_JOB_TYPE               *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* parse message & allocate a new job */
    job = mmi_da_job_create(CURR_JOB_TYPE_ENUM, NULL);
    if(!job)
    {
        /* 1. there is another job setuping, 2. no Multi DL, 3. no memory */
        mmi_da_oma_popup_and_send_report(NULL, MMI_DA_OMA_LOSS_OF_SERVICE, TRUE, TRUE);
        return;
    }

    DA_ALLOC_OBJ(job_data, CURR_JOB_TYPE);

    job->data_ptr = job_data;
    
    UCS2_STR_MALLOC_COPY(job_data->dd_filepath, filename);
    ANSI_STR_MALLOC_COPY(job_data->dd_url, download_url);
    
    /* create connection */
    mmi_da_wps_create_session((U32)job, mmi_da_session_created_callback,
                              mmi_da_session_http_response_callback,
                              mmi_da_session_http_auth_ind_callback,
                              mmi_da_session_dl_progress_callback);
    
}

static void mmi_da_session_created_callback(wps_session_handle session, U32 arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_job_struct           *job;
    CURR_JOB_TYPE               *job_data;
    mmi_da_oma_dd2_struct       *dd_info;
    
    mmi_da_oma_dd2_product_struct   *product = NULL;
    mmi_da_oma_dd2_mo_struct        *mo = NULL;
    mmi_da_oma_dd2_meta_struct      *meta;
    
    MMI_BOOL                    bRet;
    S32                         i;
    S32                         size, installSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    job = (mmi_da_job_struct*)arg;
    ASSERT(job && job->type == CURR_JOB_TYPE_ENUM);
    job_data = (CURR_JOB_TYPE*)job->data_ptr;

    if(!session)
    {
        /* fail to create section */
        mmi_da_oma_popup_and_send_report(job, MMI_DA_OMA_LOSS_OF_SERVICE, TRUE, TRUE);
        return;
    }
    job_data->session = session;

    /* parse DD */
    bRet = mmi_da_oma_parse_dd2(job_data->dd_filepath, job, &(job_data->dd_info), job_data->dd_url);
    if(!bRet)
    {
        mmi_da_oma_popup_and_send_report(job, MMI_DA_OMA_INVALID_DESCRIPTOR, TRUE, TRUE);
        return;
    }

    dd_info = &job_data->dd_info;

    /*------------ check DD content ------------*/

    /* only support "2.0" */
    if (dd_info->DDVersion != DD2_VERSION)
    {
        DA_TRACE_FUNC1(mmi_da_oma_parse_dd2, 1);
        mmi_da_oma_popup_and_send_report(job, MMI_DA_OMA_INVALID_DDVSERSION, TRUE, TRUE);
        return;
    }

    /* for each mo, the objectURI / size / type should be checked */
    size = installSize = 0;
    product = dd_info->product_list;
    while(product)
    {
        mo = product->mo_list;
        while(mo)
        {
            size += mo->size;
            installSize += mo->installSize;
            
            /* object */
            if(!mo->objectURI)
            {
                DA_TRACE_FUNC1(mmi_da_oma_parse_dd2, 2);
                mmi_da_oma_popup_and_send_report(job, MMI_DA_OMA_LOADER_ERROR, TRUE, TRUE);
                return;
            }

            /* size */
            if(!mo->size)
            {
                DA_TRACE_FUNC1(mmi_da_oma_parse_dd2, 3);
                mmi_da_oma_popup_and_send_report(job, MMI_DA_OMA_INVALID_DESCRIPTOR, TRUE, TRUE);
                return;
            }

            /* type */
            if(!mo->type[0])
            {
                DA_TRACE_FUNC1(mmi_da_oma_parse_dd2, 4);
                mmi_da_oma_popup_and_send_report(job, MMI_DA_OMA_INVALID_DESCRIPTOR, TRUE, TRUE);
                return;
            }
            
            /* content-type check */
            for(i=0;i<4;i++)    /* make sure type is supported */
            {
                if(mo->type[i] && !mime_type_look_up((kal_char *)mo->type[i], NULL, 0, 0))
                {
                    DA_TRACE_FUNC1(mmi_da_oma_parse_dd2, 5);
                    mmi_da_oma_popup_and_send_report(job,  MMI_DA_OMA_NON_ACCEPTABLE_CONTENT, TRUE, TRUE);
                    return;
                }
            }

            break;
//            mo = mo->next;
        }
        break;
//        product = product->next;
    }

    meta = mo->meta_info ? mo->meta_info : product->meta_info;

    if(!size)
    {
        /* no MO in DD */
        DA_TRACE_FUNC1(mmi_da_oma_parse_dd2, 6);
        mmi_da_oma_popup_and_send_report(job, MMI_DA_OMA_INVALID_DESCRIPTOR, TRUE, TRUE);
        return;
    }

    /* check available space */
    // TODO: if there are multi MO/Product, and not enough space to store ALL, Should 
    // Inform user, let them select which to save
    // Right now, we only support ALL or Nothing.

    // TODO: DRM should x 2?
    if(mmi_da_util_check_free_space(MMI_PUBLIC_DRV, size+installSize) == MMI_FALSE &&
        mmi_da_util_check_free_space(MMI_CARD_DRV, size+installSize) == MMI_FALSE)
    {
        DA_TRACE_FUNC1(mmi_da_oma_parse_dd2, 7);
        mmi_da_oma_popup_and_send_report(job, MMI_DA_OMA_INSUFFICIENT_STORAGE, TRUE, TRUE);
        return;
    }

    job->mime_type = mmi_da_util_lookup_mime_type_ascii((U8*)mo->type[0], 
                                                  mmi_da_util_get_extension_ascii((S8*)mo->objectURI),
                                                  0, 0);
    job->type_handler = mmi_da_search_mime_type_handler(job->mime_type);

    da_oma2_context.curr_job = job;
    if(meta && meta->suppressUserConfirmation)
    {
        mmi_da_oma_job_confirm_dl();
    }
    else
    {
        /* show confirm UI */
        mmi_da_scr_confirm_download((U32)job, mmi_da_oma_set_confirm_msg,
            mmi_da_oma_job_confirm_option_callback, mmi_da_oma_job_cancel_dl_callback, MMI_FALSE, APP_WAP);
    }
}


#define JOB_CONFIRM

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
static void mmi_da_oma_set_confirm_msg(U32 criteria, U16 *out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_job_struct           *job;
    CURR_JOB_TYPE               *job_data;
    const mmi_da_oma_dd2_struct *dd_info;

    S32 i;
    U32 estimated_secs;
    U16 buffer[MMI_DA_UTIL_ESTIMATED_TIME_FORMAT_LEN]; /* xx min. xx sec. */

    mmi_da_oma_dd2_mo_struct        *mo;
    mmi_da_oma_dd2_meta_struct      *meta;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    job = (mmi_da_job_struct*)criteria;
    job_data = (CURR_JOB_TYPE*)job->data_ptr;
    
    dd_info = &job_data->dd_info;

    _mmi_da_oma_get_current_obj(job_data, NULL, &mo, &meta);

    out[0] = 0;
    /* name */
    if(meta && meta->name)
    {
        DA_SHOW_INFO(out, "%w: %w\n", GetString(STR_ID_DA_PROMPT_NAME), meta->name);
    }

    /* vendor */
    

    /* size */
    if(mo->size != 0)
    {
        DA_SHOW_INFO(out, "%w: %s\n", GetString(STR_ID_DA_PROMPT_SIZE), mmi_da_util_format_size(mo->size));
    }
    else
    {
        DA_SHOW_INFO(out, "%w: %w\n", GetString(STR_ID_DA_PROMPT_SIZE), GetString(STR_ID_DA_PROMPT_UNKNOWN));
    }

    /* type */
    for(i=0; i<4; i++)
    {
        if(mo->type[i])  /* type is Ascii */
        {
            DA_SHOW_INFO(out, "%w: %s\n", GetString(STR_ID_DA_PROMPT_TYPE), mo->type[i]);
        }
    }
            
    /* description */
    if(meta && meta->description)
    {
        DA_SHOW_INFO(out, "%w: %w\n", GetString(STR_ID_DA_PROMPT_DESC), meta->description);
    }


    /* attach estimated time */
    estimated_secs = mmi_da_util_get_estimated_time(mo->size);
    if(MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN != estimated_secs)
    {
        mmi_da_util_format_time(buffer, estimated_secs);
        DA_SHOW_INFO(out, "%w: %w\n", GetString(STR_ID_DA_PROMPT_ESTIMATED), buffer);
    }

}

static void mmi_da_oma_job_cancel_dl_callback(U32 criteria, BOOL in_delete)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!in_delete)
    {
        EntryNewScreen(SCR_ID_DA_DUMMY, NULL, NULL, NULL);
        DeleteScreenIfPresent(SCR_ID_DA_OMA_DOWNLOAD_VIEW_DD);
        DeleteScreenIfPresent(SCR_ID_DA_OMA_DOWNLOAD_OPTION);
	    GoBackHistory();
    }
    
    /* cancel, free resource */
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_da_oma_popup_and_send_report((mmi_da_job_struct*)criteria, MMI_DA_OMA_USER_CANCELLED, TRUE, (BOOL)(!in_delete));
}

static void mmi_da_oma_job_confirm_option_callback(U32 criteria)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(!da_oma2_context.curr_job || da_oma2_context.curr_job == (mmi_da_job_struct*)criteria);
    da_oma2_context.curr_job = (mmi_da_job_struct*)criteria;
    mmi_da_oma_entry_download_option();
}

static void mmi_da_oma_entry_download_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[3];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;         /* Stores no of children in the submenu */
    U8 *guiBuffer;          /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_ID_DA_OMA_DOWNLOAD_OPTION, NULL, mmi_da_oma_entry_download_option, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_DA_OMA_DOWNLOAD_OPTION);

    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild_Ext(MENU_ID_DA_OMA_DL_OPTION);

    ASSERT(nNumofItem == 2);
    /* 4. Get attribute of menu to be displayed */

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(MENU_ID_DA_OMA_DL_OPTION, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU_ID_DA_OMA_DL_OPTION);

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetHiliteHandler(MENU_ID_DA_OMA_DL_OPTION_DOWNLOAD_NOW, mmi_da_oma_highlight_download);
    SetHiliteHandler(MENU_ID_DA_OMA_DL_OPTION_VIEW_DD, mmi_da_oma_highlight_view_dd);

    /* 8 Construct the Hints List - no need */

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        mmi_da_util_get_icon_from_appid(APP_WAP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        NULL,
        0, 0,
        guiBuffer);

    /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}

static void mmi_da_oma_highlight_download(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetKeyHandler(mmi_da_oma_job_confirm_dl, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_da_oma_job_confirm_dl, KEY_EVENT_UP);
}

static void mmi_da_oma_highlight_view_dd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetKeyHandler(mmi_da_oma_entry_download_view_dd, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_da_oma_entry_download_view_dd, KEY_EVENT_UP);
}

static void mmi_da_oma_exit_download_view_dd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CURR_JOB_TYPE *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(da_oma2_context.curr_job);
    job_data = (CURR_JOB_TYPE*)da_oma2_context.curr_job->data_ptr;

    /* Free content */
    DA_FREE_BUFFER(job_data->dd_content_string);
}

static void mmi_da_oma_entry_download_view_dd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CURR_JOB_TYPE           *job_data;
    U8          *guiBuffer;
    S8          *ddcontent = NULL;
    S8          *ddcontent2 = NULL;
    FS_HANDLE   hd = -1;
    UINT        fileSize, sizeRead;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(da_oma2_context.curr_job);
    job_data = (CURR_JOB_TYPE*)da_oma2_context.curr_job->data_ptr;
    
    /* load text from DD */
    if ((hd = FS_Open(job_data->dd_filepath, FS_READ_ONLY)) < 0)
        goto errorFs;

    if(FS_GetFileSize(hd, &fileSize) < 0)
        goto errorFs;

    ddcontent = OslMalloc(fileSize +1);
    ddcontent[fileSize] = 0;
    ddcontent2 = OslMalloc((fileSize+1)*ENCODING_LENGTH);

    if(!ddcontent || !ddcontent2)
        goto errorFs;

    if(FS_Read(hd, ddcontent, fileSize, &sizeRead)<0)
        goto errorFs;

    FS_Close(hd);
    hd = -1;

    mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (S8*)ddcontent, (S8*)ddcontent2, (fileSize + 1)*ENCODING_LENGTH);
    OslMfree(ddcontent);
    ddcontent = NULL;

    /* Save UCS2 content in context */    
    if(job_data->dd_content_string)
    {
        OslMfree(job_data->dd_content_string);
        job_data->dd_content_string = NULL;
    }
    job_data->dd_content_string = ddcontent2;

    /* Entry New Screen */
    EntryNewScreen(SCR_ID_DA_OMA_DOWNLOAD_VIEW_DD, mmi_da_oma_exit_download_view_dd, mmi_da_oma_entry_download_view_dd, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DA_OMA_DOWNLOAD_VIEW_DD);
   
    ShowCategory74Screen(
        STR_ID_DA_OMA_VIEW_DD,
        mmi_da_util_get_icon_from_appid(APP_WAP),
        STR_ID_DA_LSK_DL,
        0,
        STR_GLOBAL_BACK,
        0,
        (U8*) job_data->dd_content_string,
        fileSize,
        guiBuffer);
    
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_da_oma_job_confirm_dl, KEY_EVENT_UP);
    SetKeyHandler(mmi_da_oma_job_confirm_dl, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    return;

    /* clean up if there is error */
errorFs:
    DisplayPopup((PU8) GetString(GetFileSystemErrorString(hd)), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
    if(hd >= 0)
        FS_Close(hd);
    if(ddcontent)
        OslMfree(ddcontent);
    if(ddcontent2)
        OslMfree(ddcontent2);
    return;
}

static void mmi_da_oma_get_setting(mmi_da_job_struct *job, mmi_da_setting_struct *setting_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_setting_hdlr         setting_hdlr;
    CURR_JOB_TYPE               *job_data;
    mmi_da_oma_dd2_mo_struct        *mo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job_data = (CURR_JOB_TYPE*)job->data_ptr;

    _mmi_da_oma_get_current_obj(job_data, NULL, &mo, NULL);

    /* get setting */
    setting_hdlr = mmi_da_default_setting;
    ASSERT(job->type_handler);
    if(job->type_handler->setting_hdlr)
        setting_hdlr = job->type_handler->setting_hdlr;

    setting_hdlr(
        0, 
        job->mime_type ? job->mime_type->mime_type : 0,
        job->mime_type ? job->mime_type->mime_subtype : 0,
        MMI_DA_OMA_DOWNLOAD,
        mo->size,
        mo->objectURI,
        mo->type[0],
        0,
        NULL,
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

    /* store setting */
    mmi_da_copy_setting(job, setting_data);
}

static void mmi_da_oma_job_confirm_dl(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_job_struct           *job;
    CURR_JOB_TYPE               *job_data;
    mmi_da_setting_struct       *setting_data;
    
    mmi_da_oma_dd2_mo_struct        *mo;
    mmi_da_oma_dd2_meta_struct      *meta;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(da_oma2_context.curr_job);

    job = da_oma2_context.curr_job;
    job_data = (CURR_JOB_TYPE*)job->data_ptr;

    _mmi_da_oma_get_current_obj(job_data, NULL, &mo, &meta);
    
    /* clean up screen */
    EntryNewScreen(SCR_ID_DA_DUMMY, NULL, NULL, NULL);
    DeleteScreenIfPresent(SCR_ID_DA_OMA_DOWNLOAD_VIEW_DD);
    DeleteScreenIfPresent(SCR_ID_DA_OMA_DOWNLOAD_OPTION);
    mmi_da_scr_confirm_download_delete();
    da_oma2_context.curr_job = NULL;

    /* retrieve setting */
    setting_data = mmi_da_get_setting_buffer();
    mmi_da_oma_get_setting(job, setting_data);

    // TODO: if suppress userconfirm, we have to store to default/temp location

    /* prepare storage parameter */
    {
        mmi_da_scr_storage_parameter_struct para;

        memset(&para, 0, sizeof(para));
        
        para.drv = setting_data->drv;
        para.storage = setting_data->storage;
        para.select_storage = setting_data->storage == MMI_DA_STORAGE_NONE ? TRUE : FALSE;

        para.folder = setting_data->folder;

        if(setting_data->default_filename || setting_data->filename[0] == 0)
        {
            mmi_da_extract_filepath_ascii(mo->objectURI, para.filename, para.fileext);
        }
        else
        {
            mmi_da_extract_filepath(setting_data->filename, para.filename, para.fileext);
        }
        para.select_filename = (!setting_data->default_filename && setting_data->filename[0] == 0) ? TRUE : FALSE;
        para.filesize = mo->size;

#ifdef __DRM_SUPPORT__
        /* DRM processing require twice space */
        if( job->mime_type && 
            (job->mime_type->mime_subtype == MIME_SUBTYPE_DRM_CONTENT ||
             job->mime_type->mime_subtype == MIME_SUBTYPE_DRM_MESSAGE) )
        {
            para.filesize *= 2;
        }
#endif

        if(job->mime_type)
            para.ext = (S8*)job->mime_type->file_ext;
        para.filecheck_func = (void*)mmi_da_find_job_by_filepath;
    
        /* confirmed, select storage now. */
        mmi_da_scr_select_storage(mmi_da_oma_filename_done, &para, (U32)job, APP_WAP);
    }

    /* after confirm, show nextURL regardless of success or failure */
    if(job_data->dd_info.nextURL)
    {
        wap_start_browser(WAP_BROWSER_GOTO_URL_BACKGROUND,(kal_uint8 *) job_data->dd_info.nextURL);
    }
}

#define STORAGE_SEL

/*************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*************************************************************************/
static BOOL mmi_da_oma_filename_done(U32 criteria, U16* filepath, BOOL canback, BOOL canpopup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_job_struct               *job;
    CURR_JOB_TYPE                   *job_data;

    mmi_da_oma_dd2_mo_struct        *mo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    job = (mmi_da_job_struct*)criteria;
    
    if(filepath == NULL)
    {
        mmi_da_oma_popup_and_send_report(job, MMI_DA_OMA_USER_CANCELLED, TRUE, canpopup);
        return TRUE;
    }

    job_data = (CURR_JOB_TYPE*)job->data_ptr;
    
    UCS2_STR_MALLOC_COPY(job_data->filepath, filepath);

    // TODO: oma dont need filepath notify??    

    mmi_da_scr_entry_please_wait((U32)job, mmi_da_oma_please_wait_abort_callback, APP_WAP);

    _mmi_da_oma_get_current_obj(job_data, NULL, &mo, NULL);

    /* send request */
    if(!mmi_da_wps_http_req(job_data->session, WPS_HTTP_METHOD_GET,
                        mo->objectURI, NULL, job_data->filepath, 0))
    {
        ASSERT(0);
    }
    return MMI_TRUE;
}

#define OMA_SEND_REQUEST

static void mmi_da_oma_please_wait_abort_callback(U32 criteria, BOOL in_delete)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_job_struct           *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = (mmi_da_job_struct*)criteria;
    ASSERT(mmi_da_is_job_valid(job));
    ASSERT(job->type == CURR_JOB_TYPE_ENUM && job->state == MMI_DA_JOB_STATE_INIT);

    mmi_da_oma_popup_and_send_report(job, MMI_DA_OMA_USER_CANCELLED, TRUE, (BOOL)(!in_delete));
}

static void mmi_da_session_http_response_callback(U32 arg, U8 result, U16 status, 
                                               S8 *content_type, U32 content_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_job_struct           *job;
    CURR_JOB_TYPE               *job_data;
    S32                         i;
    BOOL                        enter_job_list;

    mmi_da_oma_dd2_mo_struct        *mo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DA_TRACE_FUNC2(mmi_da_oma2_http_response, 0, content_len);

    job = (mmi_da_job_struct*)arg;
    ASSERT(mmi_da_is_job_valid(job));
    ASSERT(job->type == CURR_JOB_TYPE_ENUM &&
        job->state == MMI_DA_JOB_STATE_INIT);
    job_data = (CURR_JOB_TYPE*)job->data_ptr;

    enter_job_list = (GetActiveScreenId() == SCR_ID_DA_SCREEN_PLEASE_WAIT) ? TRUE : FALSE;
    EntryNewScreen(SCR_ID_DA_DUMMY, NULL, NULL, NULL);    
    mmi_da_scr_close_please_wait();

    _mmi_da_oma_get_current_obj(job_data, NULL, &mo, NULL);
    
    /* check result */
    if(result != WPS_OK)
    {
        DA_TRACE_FUNC2(mmi_da_oma2_http_response, 1, result);
        if( result == WPS_ERROR_FILE_ACCESS )
            mmi_da_oma_popup_and_send_report(job, MMI_DA_OMA_FILE_ACCESS_ERROR, TRUE, TRUE);
        else
            mmi_da_oma_popup_and_send_report(job, MMI_DA_OMA_LOADER_ERROR, TRUE, TRUE);
        return;
    }
    else if (status == 401 || status == 407)
    {
        /* check status code */
        DA_TRACE_FUNC2(mmi_da_oma2_http_response, 2, status);
        mmi_da_oma_popup_and_send_report(job, MMI_DA_OMA_AUTHORIZATION_FAIL, TRUE, TRUE);
        return;
    }
    else if (status >= 300 || status < 200)
    {
        DA_TRACE_FUNC2(mmi_da_oma2_http_response, 3, status);
        mmi_da_oma_popup_and_send_report(job, MMI_DA_OMA_LOADER_ERROR, TRUE, TRUE);
        return;
    }
    else if(mo->size != content_len)
    {
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
        if(content_len)
            mo->size = content_len;
        // TODO: if content_len == 0, need prompt and stop??
#endif        
	}
    else
    {
        DA_TRACE1(MMI_TRC_DA_MIMETYPE, content_type);
        
        /* update content type */
        job->mime_type = mmi_da_util_lookup_mime_type((U8*)content_type, 
                                                  mmi_da_util_get_extension((U16*)job_data->filepath),
                                                  0, 0);
        if(!job->mime_type)
        {
            DA_TRACE_FUNC1(mmi_da_oma2_http_response, 4);
            mmi_da_oma_popup_and_send_report(job, MMI_DA_OMA_ATTRIBUTE_MISMATCH, TRUE, TRUE);
            return;
        }
        
        /* check Type match? */
        for(i=0; i<4 ;i++)
        {
            if(mo->type[i] && 
                job->mime_type == mmi_da_util_lookup_mime_type((U8*)mo->type[i], 
                                                           mmi_da_util_get_extension((U16*)job_data->filepath),
                                                           0x00, 0x00))
                break;
        }

        if(i == 4)
        {
            DA_TRACE_FUNC1(mmi_da_oma2_http_response, 5);
            mmi_da_oma_popup_and_send_report(job, MMI_DA_OMA_ATTRIBUTE_MISMATCH, TRUE, TRUE);
            return;
        }            
    }

    /* its all ok now, Download start! */
    job->state = MMI_DA_JOB_STATE_DOWNLOADING;

    job_data->curr_size = 0;
    mmi_da_job_start(job);
    kal_get_time(&job_data->dl_start_tick);

    if(!enter_job_list)
        return;

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
}

static void mmi_da_oma_user_auth_callback(U32 criteria, U16* username, U16* password, BOOL in_delete)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_job_struct           *job;
    CURR_JOB_TYPE               *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    job = (mmi_da_job_struct*)criteria;
    ASSERT(job && job->type == CURR_JOB_TYPE_ENUM);
    job_data = (CURR_JOB_TYPE*)job->data_ptr;

    if(!username || !password)
    {
        /* cancel */
        ASSERT(job->state == MMI_DA_JOB_STATE_INIT);
        mmi_da_oma_popup_and_send_report(job, MMI_DA_OMA_USER_CANCELLED, TRUE, (BOOL)(!in_delete));
    }
    else
    {
        mmi_da_wps_session_auth_UCS2(job_data->session, username, password);
        GoBackHistory();
    }

}

static void mmi_da_session_http_auth_ind_callback(U32 arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_job_struct           *job;
    CURR_JOB_TYPE               *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    job = (mmi_da_job_struct*)arg;
    ASSERT(job && job->type == CURR_JOB_TYPE_ENUM);
    job_data = (CURR_JOB_TYPE*)job->data_ptr;

    mmi_da_scr_user_auth(mmi_da_oma_user_auth_callback, (U32)job, APP_WAP);
}

static void mmi_da_session_dl_progress_callback(U32 arg, U8 status, U32 curr_size, S32 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_job_struct           *job;
    CURR_JOB_TYPE               *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    job = (mmi_da_job_struct*)arg;
    ASSERT(job && job->type == CURR_JOB_TYPE_ENUM);
    job_data = (CURR_JOB_TYPE*)job->data_ptr;

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
    
    // TODO: handle pausing here, how to distinguish from pause & abort?
    switch(status)
    {
        case WPS_DL_STATUS_ABORT:
            job->state = MMI_DA_JOB_STATE_ABORTED;
            if(cause < 0)
                cause = -cause;
            else
                cause = MMI_DA_OMA_LOSS_OF_SERVICE;
            mmi_da_oma_popup_and_send_report(job, cause, TRUE, TRUE);
            break;
            
        case WPS_DL_STATUS_COMPLETE:
            job->state = MMI_DA_JOB_STATE_COMPLETED;
            mmi_da_oma_close_session(job);

            if(mmi_da_oma_popup_and_send_report(job, MMI_DA_OMA_SUCCESS, TRUE, TRUE))
            {
                job->state = MMI_DA_JOB_STATE_PROCESSING;
                break;
            }

#ifdef __DRM_SUPPORT__
            /* parse DRM type first */
            if(mmi_da_is_drm_require_processing(job->mime_type))
            {
                mmi_da_drm_process_file(job, job_data->filepath, 
                                        mmi_da_oma_drm_process_callback);
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

static void mmi_da_session_session_aborted_callback(U32 arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_job_struct           *job;
    CURR_JOB_TYPE               *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    job = (mmi_da_job_struct*)arg;
    ASSERT(job && job->type == CURR_JOB_TYPE_ENUM);
    job_data = (CURR_JOB_TYPE*)job->data_ptr;

    /* session closed */
    job_data->session = MMI_DA_INVALID_SESSION_HANDLE;
    
    ASSERT(job->state == MMI_DA_JOB_STATE_ABORTING);
    job->state = MMI_DA_JOB_STATE_ABORTED;
    mmi_da_oma_popup_and_send_report(job, MMI_DA_OMA_USER_CANCELLED, FALSE, TRUE);
    
    if(job_data->abort_callback)
        job_data->abort_callback(job, 0);

}

static void mmi_da_oma_close_session(mmi_da_job_struct* job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CURR_JOB_TYPE                *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(job->type == CURR_JOB_TYPE_ENUM);
        
    job_data = (CURR_JOB_TYPE*)job->data_ptr;
    if(job_data->session != MMI_DA_INVALID_SESSION_HANDLE)
    {
        mmi_da_wps_close_session(job_data->session, NULL);
        job_data->session = MMI_DA_INVALID_SESSION_HANDLE;
    }
}

#define OMA_JOB_TABLE

static BOOL mmi_da_oma_free_job(mmi_da_job_struct* job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CURR_JOB_TYPE               *job_data;
    mmi_da_oma_dd2_struct       *dd_info;
    S32                         i;
    
    mmi_da_oma_dd2_product_struct   *product, *next_product;
    mmi_da_oma_dd2_mo_struct        *mo, *next_mo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(job->type != CURR_JOB_TYPE_ENUM)
        return FALSE;
        
    job_data = (CURR_JOB_TYPE*)job->data_ptr;

    ASSERT(job_data->session == MMI_DA_INVALID_SESSION_HANDLE);
    
    if(job->state != MMI_DA_JOB_STATE_COMPLETED && job_data->filepath)
        FS_Delete(job_data->filepath);
    /* always delte DD file */
    FS_Delete(job_data->dd_filepath);
    
    /* free DD info */
    dd_info = &job_data->dd_info;

    product = dd_info->product_list;
    while(product)
    {
        next_product = product->next;

        /* free product */
        mo = product->mo_list;
        while(mo)
        {
            next_mo = mo->next;

            /* free mo */
            if(mo->meta_info)
            {
                DA_FREE_BUFFER(mo->meta_info->name);
                DA_FREE_BUFFER(mo->meta_info->description);
                DA_FREE_BUFFER(mo->meta_info->infoURL);
                DA_FREE_BUFFER(mo->meta_info->installParam);
                DA_FREE_BUFFER(mo->meta_info->installNotifyURI);
                DA_FREE_BUFFER(mo->meta_info->environment);
                DA_FREE_BUFFER(mo->meta_info->downloadNotifyURI);
                DA_FREE_BUFFER(mo->meta_info->deleteNotifyURI);
                DA_FREE_BUFFER(mo->meta_info->mediaURI);
            }
            DA_FREE_BUFFER(mo->meta_info);
            DA_FREE_BUFFER(mo->objectId);
            DA_FREE_BUFFER(mo->objectVersion);
            DA_FREE_BUFFER(mo->objectURI);
            DA_FREE_BUFFER(mo->more_objectURI);
            for(i=0; i<4; i++)
                DA_FREE_BUFFER(mo->type[i]);
            DA_FREE_BUFFER(mo);

            mo = next_mo;
        }

        if(product->meta_info)
        {
            DA_FREE_BUFFER(product->meta_info->name);
            DA_FREE_BUFFER(product->meta_info->description);
            DA_FREE_BUFFER(product->meta_info->infoURL);
            DA_FREE_BUFFER(product->meta_info->installParam);
            DA_FREE_BUFFER(product->meta_info->installNotifyURI);
            DA_FREE_BUFFER(product->meta_info->environment);
            DA_FREE_BUFFER(product->meta_info->downloadNotifyURI);
            DA_FREE_BUFFER(product->meta_info->deleteNotifyURI);
            DA_FREE_BUFFER(product->meta_info->mediaURI);
        }
        DA_FREE_BUFFER(product->meta_info);
        DA_FREE_BUFFER(product);

        product = next_product;
    }

    DA_FREE_BUFFER(dd_info->vendorName);
    DA_FREE_BUFFER(dd_info->vendorHome);
    DA_FREE_BUFFER(dd_info->vendorLogo);
    DA_FREE_BUFFER(dd_info->vendorSupport);
    DA_FREE_BUFFER(dd_info->nextURL);
    DA_FREE_BUFFER(dd_info->updatedDDURI);

    DA_FREE_BUFFER(job_data->dd_url);
    DA_FREE_BUFFER(job_data->dd_filepath);
    DA_FREE_BUFFER(job_data->dd_content_string);
    DA_FREE_BUFFER(job_data->filepath);
    DA_FREE_BUFFER(job_data->auth_username);
    DA_FREE_BUFFER(job_data->auth_password);

    OslMfree(job_data);
    job->data_ptr = NULL;
    return TRUE;
}

static U16* mmi_da_oma_get_item_filepath(const mmi_da_job_struct* job, U16* buffer, U32 buffer_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CURR_JOB_TYPE *job_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(job->type == CURR_JOB_TYPE_ENUM);
    job_data = (CURR_JOB_TYPE*)job->data_ptr;
    return (U16*) mmi_ucs2ncpy((S8*)buffer, (S8*)job_data->filepath, buffer_len);
}

static U32  mmi_da_oma_get_item_progress(const mmi_da_job_struct* job, mmi_da_item_progress_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CURR_JOB_TYPE                   *job_data;
    U32                             secs;

    mmi_da_oma_dd2_mo_struct        *mo;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(job->type == CURR_JOB_TYPE_ENUM);
    job_data = (CURR_JOB_TYPE*)job->data_ptr;

    _mmi_da_oma_get_current_obj(job_data, NULL, &mo, NULL);

    info->fileSize = mo->size;
    info->currSize = job_data->curr_size;
    if(job->state == MMI_DA_JOB_STATE_PROCESSING)
        info->processing_string = (U16*)GetString(STR_ID_DA_OMA_SEND_REPORT);
    else
        info->processing_string = NULL;
    secs = (U32)((job_data->dl_latest_tick - job_data->dl_start_tick) * 4.615 / 1000);
    if(job_data->curr_size && secs)
    {
        info->secs_remain = secs * (mo->size - job_data->curr_size) / job_data->curr_size;
    }
    else
    {
        info->secs_remain = MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN;
    }

    return ((U64)job_data->curr_size * 100) / mo->size;
}

static void mmi_da_oma_abort_job(mmi_da_job_struct* job, S32 prev_state, BOOL pauseOnly,
                                  mmi_da_abort_callback_type end_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CURR_JOB_TYPE *job_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(job->type == CURR_JOB_TYPE_ENUM);
    ASSERT(job->state == MMI_DA_JOB_STATE_ABORTING);
    job_data = (CURR_JOB_TYPE*)job->data_ptr;

    switch(prev_state)
    {
    case MMI_DA_JOB_STATE_DOWNLOADING:
        ASSERT(job_data->session != MMI_DA_INVALID_SESSION_HANDLE);

        job_data->abort_callback = end_callback;
        mmi_da_wps_close_session(job_data->session, mmi_da_session_session_aborted_callback);
        break;

    case MMI_DA_JOB_STATE_PROCESSING:   // abort when sending report.
        ASSERT(job_data->report_obj);
        job_data->report_obj->job = NULL;   // so that it wont callback later.

        mmi_da_wps_close_session(job_data->report_obj->session, NULL);
        DA_FREE_BUFFER(job_data->report_obj->installNotifyURI);
        DA_FREE_BUFFER(job_data->report_obj);

        job->state = MMI_DA_JOB_STATE_PROCESSING;
        mmi_da_oma_send_report_callback(job, 0xFF, 0xFFFF);
        break;

    default:
        ASSERT(0);
        break;
    }
}

static void mmi_da_oma_dispatch_job(const mmi_da_job_struct* job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CURR_JOB_TYPE *job_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(job->type == CURR_JOB_TYPE_ENUM);
    job_data = (CURR_JOB_TYPE*)job->data_ptr;

    // TODO: dispatch
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
}

static S16 mmi_da_oma_get_job_id(const mmi_da_job_struct* job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CURR_JOB_TYPE *job_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(job->type == CURR_JOB_TYPE_ENUM);
    job_data = (CURR_JOB_TYPE*)job->data_ptr;

    return mmi_da_wps_get_session_id(job_data->session);
}

#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
static S32 mmi_da_oma_move_job(mmi_da_job_struct* job, U16* new_filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CURR_JOB_TYPE               *job_data;
	S32                         result = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(job->type == CURR_JOB_TYPE_ENUM);
    ASSERT(job->state == MMI_DA_JOB_STATE_COMPLETED);
    job_data = (CURR_JOB_TYPE*)job->data_ptr;

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

#define SEND_REPORT

static void _mmi_da_report_session_created_callback(wps_session_handle session, U32 arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_oma_report_struct    *report_obj;
    S8                          *string = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    report_obj = (mmi_da_oma_report_struct*)arg;

    report_obj->session = session;

    mmi_da_oma_report_map_string(report_obj->error, NULL, &string);
    ASSERT(string);

    mmi_da_wps_http_req(session, WPS_HTTP_METHOD_POST, report_obj->installNotifyURI, string, NULL, 0);
}

static void _mmi_da_report_http_response_callback(U32 arg, U8 result, U16 status, 
                                               S8 *content_type, U32 context_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_oma_report_struct    *report_obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    report_obj = (mmi_da_oma_report_struct*)arg;

    if(report_obj->job)
        mmi_da_oma_send_report_callback(report_obj->job, result, status);

    /* close session and clean up */
    mmi_da_wps_close_session(report_obj->session, NULL);
    DA_FREE_BUFFER(report_obj->installNotifyURI);
    DA_FREE_BUFFER(report_obj);
}

/*****************************************************************************
* FUNCTION
*   mmi_da_oma_popup_and_send_report
* DESCRIPTION
*   Send status report to server. After finish, we will destory the channel.
* PARAMETERS
*   error   IN  status code
* RETURNS
*   void
*****************************************************************************/
static MMI_BOOL mmi_da_oma_popup_and_send_report(mmi_da_job_struct *job, S32 error, BOOL end_job, BOOL bpopup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CURR_JOB_TYPE               *job_data = NULL;
    U16                         stringID;
    mmi_da_oma_report_struct    *report_obj;
    mmi_da_oma_dd2_product_struct   *product;
    mmi_da_oma_dd2_mo_struct        *mo;
    mmi_da_oma_dd2_meta_struct      *meta;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DA_TRACE_FUNC1(mmi_da_oma2_popup_and_send_report, error);

    /* if need do status report */
    if(job)
    {
        job_data = (CURR_JOB_TYPE*)job->data_ptr;

        ASSERT(!job_data->enter_sending_report);
        if(job_data->enter_sending_report)
            return MMI_FALSE;
        job_data->enter_sending_report = MMI_TRUE;

        _mmi_da_oma_get_current_obj(job_data, &product, &mo, &meta);

        if(mo->meta_info && mo->meta_info->installNotifyURI)
        {
            DA_ALLOC_OBJ(report_obj, mmi_da_oma_report_struct);
            report_obj->error = error;
            report_obj->session = MMI_DA_INVALID_SESSION_HANDLE;
            ANSI_STR_MALLOC_COPY(report_obj->installNotifyURI, mo->meta_info->installNotifyURI);

            if(error == MMI_DA_OMA_SUCCESS)
                report_obj->job = job;

            mmi_da_wps_create_session((U32)report_obj, 
                                      _mmi_da_report_session_created_callback,
                                      _mmi_da_report_http_response_callback,
                                      NULL, NULL);
            
            if(error == MMI_DA_OMA_SUCCESS)
            {
                job_data->report_obj = report_obj; /* save the reference for later aborting */
                return MMI_TRUE;
            }
        }
    }

    /* popup error */
    if(error != MMI_DA_OMA_SUCCESS)
    {
        /* popup error */
        if(bpopup)
        {
            mmi_da_oma_report_map_string(error, &stringID, NULL);
            DisplayPopup((PU8) GetString(stringID), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
        }

        if(job_data && job_data->filepath)
            FS_Delete(job_data->filepath);
        
        if(job)
            mmi_da_oma_close_session(job);

        if(job && end_job)
        {
            if(job->state == MMI_DA_JOB_STATE_INIT)
            {
                mmi_da_job_cancel(job);
            }
            else if(job->state == MMI_DA_JOB_STATE_ABORTED)
            {
                mmi_da_job_error_cleanup(job);
            }
            else
            {
                /* still not aborted????? */
                ASSERT(0);
            }
        }
    }
    else
    {
        ASSERT(job && job->state == MMI_DA_JOB_STATE_COMPLETED);
        /* clean up process will be done after dispatching */
    }
    return MMI_FALSE;
}

static void mmi_da_oma_send_report_callback(mmi_da_job_struct* job, U8 result, U16 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CURR_JOB_TYPE           *job_data;
    U16                     err_stringid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(job->state == MMI_DA_JOB_STATE_PROCESSING);
    ASSERT(job->type == CURR_JOB_TYPE_ENUM);
    job_data = (CURR_JOB_TYPE*)job->data_ptr;
    job_data->report_obj = NULL;

    err_stringid = 0;
    if (result == 0xFF && status == 0xFFFF)
        err_stringid = STR_ID_DA_OMA_ERROR_SEND_REPORT_CANCEL;
    else if (result != WPS_OK)
        err_stringid = STR_ID_DA_OMA_ERROR_SEND_REPORT_FAIL;
    else if(status == 401 || status == 407)
        err_stringid = STR_ID_DA_OMA_ERROR_SEND_REPORT_FAIL_AUTH;
    else if(status >= 300 || status < 200)
        err_stringid = STR_ID_DA_OMA_ERROR_SEND_REPORT_FAIL;

    if(err_stringid)
    {
        DisplayPopup((PU8) GetString(err_stringid), IMG_GLOBAL_ERROR, 1,
                     UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
        /* remove the file */
        FS_Delete(job_data->filepath);

        job->state = MMI_DA_JOB_STATE_ABORTED;
        mmi_da_job_error_cleanup(job);
    }
    else
    {
        /* ok, continue */
        job->state = MMI_DA_JOB_STATE_COMPLETED;
        
#ifdef __DRM_SUPPORT__
        /* parse DRM type first */
        if(mmi_da_is_drm_require_processing(job->mime_type))
        {
            mmi_da_drm_process_file(job, job_data->filepath, 
                                    mmi_da_oma_drm_process_callback);
            return;
        }
#endif

        mmi_da_update_job_status(job);
    }

}

#define DRM_PROC

#ifdef __DRM_SUPPORT__
static void mmi_da_oma_drm_process_callback(mmi_da_job_struct* job,
                                            U16 *new_filepath, U16 err_string_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CURR_JOB_TYPE            *job_data;
    S32                      ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(job->type == CURR_JOB_TYPE_ENUM);
    job_data = (CURR_JOB_TYPE*)job->data_ptr;

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
            mmi_da_job_error_cleanup(job);
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
		strcpy(p->url, "oma2");
        mmi_da_send_ilm(p, NULL, MSG_ID_MMI_DA_DISPATCH_FILE_REQ, MOD_MMI);

        DA_FREE_BUFFER(job_data->filepath);
        DA_FREE_BUFFER(new_filepath);
        job->state = MMI_DA_JOB_STATE_ABORTED;
        mmi_da_job_error_cleanup(job);        
    }
#endif
}

#endif /* __DRM_SUPPORT__ */

#define UTIL_API
static void _mmi_da_oma_get_current_obj(mmi_da_omadl2_job_struct* job_data,
                                        mmi_da_oma_dd2_product_struct** pproduct,
                                        mmi_da_oma_dd2_mo_struct** pmo,
                                        mmi_da_oma_dd2_meta_struct** pmeta)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_oma_dd2_product_struct   *product;
    mmi_da_oma_dd2_mo_struct        *mo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    // TODO: first MO only
    product = job_data->dd_info.product_list;
    ASSERT(product);
    mo = product->mo_list;
    ASSERT(mo);
    if(pmeta)
        *pmeta = mo->meta_info ? mo->meta_info : product->meta_info;
    if(pmo)
        *pmo = mo;
    if(pproduct)
        *pproduct = product;

}


#endif /* __MMI_OMA_DD2_DOWNLOAD__ */
#endif /* __MMI_OMA_DD_DOWNLOAD__ */


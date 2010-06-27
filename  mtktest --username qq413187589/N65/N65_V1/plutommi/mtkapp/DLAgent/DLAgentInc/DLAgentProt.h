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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
  ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef DOWNLOAD_AGENT_PROT_H
#define DOWNLOAD_AGENT_PROT_H

#ifndef _FILE_MGR_H_
#error "Please include FileMgr.h first"
#endif

#ifndef DOWNLOAD_AGENT_DEF_H
#error "Please include DLAgentDef.h first"
#endif

#ifndef DOWNLOAD_AGENT_GPROT_H
#error "Please include DLAgentGprot.h first"
#endif

#ifdef __DRM_SUPPORT__
#ifndef DRM_DEF_H
#error "Please include drm_def.h first"
#endif
#endif


//#define __MMI_OMA_DD2_DOWNLOAD__


/****************************************************************************
* Define
*****************************************************************************/

#define MMI_DA_TRACE_GROUP                      MMI_CONN_TRC_G1_DLAGENT

#define MMI_DA_MAX_JOB                          4
#define MMI_DA_MAX_DL                           2

#define MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN      0xFFFFFFFF
#define MMI_DA_UTIL_ESTIMATED_TIME_FORMAT_LEN   20

/****************************************************************************
* Macro
*****************************************************************************/

#define DA_FREE_BUFFER(buffer)    \
    do { \
    if( buffer ) \
    {           \
        OslMfree( buffer ); \
        buffer = NULL;      \
    } \
    } while(0) 

#define ANSI_STR_MALLOC_COPY(out, in)    \
    do { \
    DA_FREE_BUFFER(out);	\
    if( in  && strlen((kal_char*)in) > 0){  \
        out = (PS8) OslMalloc(strlen((kal_char*)in)+1); \
        strcpy((kal_char*)(out), (kal_char*)in);\
    } \
    } while(0) 

#define UCS2_STR_MALLOC_COPY(out, in)    \
    do { \
    DA_FREE_BUFFER(out);	\
    out = NULL; \
    if( in && mmi_ucs2strlen((const S8*)in) > 0 ){  \
        out = (PU16) OslMalloc((mmi_ucs2strlen((S8*)in)+1)*ENCODING_LENGTH); \
        mmi_ucs2cpy((S8*)(out), (S8*)in);\
    } \
    } while(0) 

#define DA_MAKE_UNIQUE_ID(thejob, localid) \
    ((localid) | (thejob->type << 16))

#define DA_MAKE_UNIQUE_ID_EX(type, localid) \
    ((localid) | (type << 16))

#define DA_ALLOC_OBJ(trg, struct_type) \
    trg = (struct_type*)OslMalloc(sizeof(struct_type)); \
    memset(trg, 0, sizeof(struct_type))

#define DA_TRACE_FUNC(func)                 mmi_da_trace_func(DA_TRACE_##func)
#define DA_TRACE_FUNC1(func, p1)            mmi_da_trace_func_ex(DA_TRACE_##func, p1, 0, 0)
#define DA_TRACE_FUNC2(func, p1, p2)        mmi_da_trace_func_ex(DA_TRACE_##func, p1, p2, 0)
#define DA_TRACE_FUNC3(func, p1, p2, p3)    mmi_da_trace_func_ex(DA_TRACE_##func, p1, p2, p3)

#define DA_TRACE_ENDFUNC(func)              mmi_da_trace_endfunc(DA_TRACE_##func)

#define DA_TRACE1(trace_enum, p1)           MMI_TRACE(MMI_DA_TRACE_GROUP, trace_enum, p1)

/****************************************************************************
* Typedef - Enum
*****************************************************************************/

typedef enum
{
    MMI_DA_JOB_TYPE_NORMAL,
#ifdef __MMI_OMA_DD_DOWNLOAD__
    MMI_DA_JOB_TYPE_OMADL,  /* DLOTA 1.0 */
#ifdef __MMI_OMA_DD2_DOWNLOAD__
    MMI_DA_JOB_TYPE_OMADL2, /* DLOTA 2.0 */
#endif
#endif   
    MMI_DA_JOB_TYPE_TOTAL,

    MMI_DA_JOB_TYPE_PUSH
    
} mmi_da_job_type_enum;

typedef enum
{
    MMI_DA_JOB_STATE_INIT,
    MMI_DA_JOB_STATE_DOWNLOADING,
    MMI_DA_JOB_STATE_ABORTING,
    MMI_DA_JOB_STATE_ABORTED,
    MMI_DA_JOB_STATE_PAUSED,
    MMI_DA_JOB_STATE_PROCESSING,
#ifdef __DRM_SUPPORT__
    MMI_DA_JOB_STATE_DRM_PROCESSING,
#endif
    MMI_DA_JOB_STATE_COMPLETED,
    
    MMI_DA_JOB_STATE_FAILED,
   
    MMI_DA_JOB_STATE_TOTAL
    
} mmi_da_job_state_enum;

typedef enum
{
    MMI_DA_IERROR_OK = 0,
    MMI_DA_IERROR_EXCEED_MAX_JOB,
    MMI_DA_IERROR_EXCEED_MAX_DL,
    MMI_DA_IERROR_ANOTHER_JOB,   // already has a job on screen setuping.
    MMI_DA_IERROR_NO_MEMORY,

    MMI_DA_IERROR_NUM
} mmi_da_internal_error_enum;

typedef enum
{
    MMI_DA_ACT_INTERNAL_BASE = 0x0F,

    MMI_DA_ACT_INTERNAL_SAVE_AS = 0x10,
    MMI_DA_ACT_INTERNAL_SAVE_AS_NORMAL = 0x01,  // For ODF files, Treat as normal file regardless of mime_type
    MMI_DA_ACT_INTERNAL_SAVE_AS_MOVE = 0x02,    // For Move/SaveAs option

    MMI_DA_ACT_INTERNAL_TOTAL
} mmi_da_action_internal_enum;

enum
{
    DA_TRACE_mmi_da_recv_dispatch_file_req = 0,
    DA_TRACE_mmi_da_recv_wap_notify_ind,

    /* job api */
    DA_TRACE_mmi_da_job_create = 0x00010000,
    DA_TRACE_mmi_da_job_cancel,
    DA_TRACE_mmi_da_job_start,
    DA_TRACE_mmi_da_job_error_cleanup,
    DA_TRACE_mmi_da_display_job_list,
    DA_TRACE_mmi_da_display_job_detail,
    DA_TRACE_mmi_da_update_job_status,
    DA_TRACE_mmi_da_job_list_option_lsk_hdlr,
    DA_TRACE_mmi_da_click_job,
    DA_TRACE__mmi_da_free_job,
    DA_TRACE_mmi_da_suspend_all_job,

    DA_TRACE_mmi_da_curr_job_abort_hdlr,

    DA_TRACE_mmi_da_entry_job_list = 0x00010100,
    DA_TRACE_mmi_da_entry_job_list_option,
    DA_TRACE_mmi_da_entry_job_detail,
    DA_TRACE_mmi_da_entry_dispatch_confirm,

    DA_TRACE_mmi_da_job_make_filestamp = 0x00010200,
    DA_TRACE_mmi_da_job_check_filestamp,

    /* Hook_patch */
    DA_TRACE_mmi_da_call_hook_func_index = 0x00010300,
    DA_TRACE_mmi_da_func_is_hooked,

    /* push api */
    DA_TRACE_mmi_da_push_free_item = 0x00020000,
    DA_TRACE_mmi_da_push_filename_done,
    DA_TRACE_mmi_da_entry_new_push,

    /* DLAgent exported api */
    DA_TRACE_mmi_da_stop_dl = 0x00030000,
    DA_TRACE_mmi_da_enter_idle_screen_notify,
    DA_TRACE_mmi_da_usb_mode_on,
    DA_TRACE_mmi_da_entry_new_push_ind,

    /* drm process */
    DA_TRACE_mmi_da_drm_process_file_abort = 0x00040000,
    DA_TRACE_mmi_da_drm_process_file,
    DA_TRACE_mmi_da_drm_process_callback,
    DA_TRACE_mmi_da_drm_process_file_finish,

    /* Screen */
    DA_TRACE_mmi_da_scr_select_storage = 0x00050000,
    DA_TRACE_mmi_da_scr_get_drive_callback,
    DA_TRACE_mmi_da_scr_delete_callback,
    DA_TRACE_mmi_da_scr_storage_callback,

    /* DLS api */
    DA_TRACE_mmi_da_recv_wap_file_dl_ind = 0x00060000,
    DA_TRACE_mmi_da_http_free_job,
    DA_TRACE_mmi_da_http_http_response,
    DA_TRACE_mmi_da_http_http_response_error,
    
    /* OMA api */
    DA_TRACE_mmi_da_oma_parse_dd = 0x00070000,
    DA_TRACE_mmi_da_oma_http_response,
    DA_TRACE_mmi_da_oma_popup_and_send_report,

    /* OMA2.0 api */
    DA_TRACE_mmi_da_oma_parse_dd2 = 0x00080000,
    DA_TRACE_mmi_da_oma2_http_response,
    DA_TRACE_mmi_da_oma2_popup_and_send_report,

    /* OMA util */
    DA_TRACE__dd_read_data_element = 0x00090000,
    DA_TRACE__dd2_read_data_element,

    /* WPS */
    DA_TRACE_WPS = 0x000A0000,
    /* See DLAgentWPS.c */


    /* ----------------------------------------------- */
    DA_TRACE_end = 0x7FFFFFFF
}; /* this enum is for TRACE usage */

/****************************************************************************
* Typedef - Struct
*****************************************************************************/

typedef struct
{
    S32                     mime_type;
    S32                     mime_subtype;
    mmi_da_dispatch_hdlr    dispatch_hdlr;
    mmi_da_setting_hdlr     setting_hdlr;
} mmi_da_type_handler_struct;

/* Hook_patch */
typedef struct
{
    S32 mime_type;
    S32 mime_subtype;
    mmi_da_hook_dispatch_hdlr hook_hdlr;
} mmi_da_hook_handler_struct;

#ifdef __DRM_SUPPORT__
typedef struct 
{
    void                *callback;  /* callback function */
    
    drm_info_struct     *drm_info;
    S32                 drm_method;
    S32                 drm_right_is_permitted;
    U16                 *drm_filepath;
    U8                  drm_serial;
} mmi_da_drm_struct;
#endif

typedef struct
{
    BOOL    do_dispatch;
    BOOL    confirm_dispatch;
    BOOL    confirm_push;
    BOOL    can_minimize;

    mmi_da_filepath_hdlr    filepath_hdlr;
    mmi_da_report_hdlr      report_hdlr;
} mmi_da_job_setting_struct;

typedef struct
{
    U32     curr_size;

} mmi_da_job_filestamp_struct;

typedef struct _da_job_struct
{
    struct _da_job_struct   *next_job;  /* ponter to next job,     NULL if last job */
    struct _da_job_struct   *prev_job;  /* ponter to previous job, NULL if first job */
    
    mmi_da_job_type_enum    type;
    mmi_da_job_state_enum   state;
    BOOL                    notifyed_complete;
    
    U16                     popup_str_id;
    S32                     error_cause;

    void                    *data_ptr;  /* pointer to job struct, depend on type */
    
#ifdef __DRM_SUPPORT__
    mmi_da_drm_struct       drm;
#endif

    mmi_da_job_setting_struct           setting_info;

    const mmi_da_type_handler_struct    *type_handler;
    const applib_mime_type_struct       *mime_type;

#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    mmi_da_job_filestamp_struct         filestamp;
#endif
} mmi_da_job_struct;

typedef struct
{
    S32     drv;
    S32     storage;                    /* mmi_da_storage_enum */
    
    U16     filename[FMGR_MAX_FILE_LEN + 1];
    U16     fileext[FMGR_MAX_EXT_LEN + 1];
    
    U16     *folder;                    /* must not null */
    U32     filesize;                   /* for checking capacity, 0 if not checking */
    U16     *original_filepath;         /* if provide original filepath, overwrite will not prompt if match */
    void    *filecheck_func;

    const S8* ext;                      /* default extension if filename do not have , can be NULL */
    
    BOOL    select_storage;             /* user select storage */
    BOOL    select_filename;            /* user input filename, if TRUE will check overwrite */

} mmi_da_scr_storage_parameter_struct;

typedef struct
{
    U32 secs_remain;
    U32 fileSize;
    U32 currSize;
    U16* processing_string;
} mmi_da_item_progress_struct;

    

/****************************************************************************
*                       Typedef - function
*****************************************************************************/

/* ===============--------------- Src ---------------=============== */
typedef void (*mmi_da_abort_callback_type)(mmi_da_job_struct* job, U16 string_id);
typedef BOOL (*mmi_da_job_match_funcptr_type)(const mmi_da_job_struct* job, U32 criteria);


typedef void (*mmi_da_init_module_funcptr_type)     (void);

typedef U16* (*mmi_da_job_get_filepath_funcptr_type)(const mmi_da_job_struct* job, 
                                                     U16* buffer, U32 buffer_len);
typedef U32  (*mmi_da_job_get_progress_funcptr_type)(const mmi_da_job_struct* job,
                                                     mmi_da_item_progress_struct *info);  // return percentage
typedef S16  (*mmi_da_job_get_id_funcptr_type)      (const mmi_da_job_struct* job);
typedef void (*mmi_da_job_get_setting_funcptr_type) (const mmi_da_job_struct* job, mmi_da_setting_struct *setting_data);

typedef BOOL (*mmi_da_job_free_data_funcptr_type)   (mmi_da_job_struct* job);
typedef void (*mmi_da_job_stop_funcptr_type)        (mmi_da_job_struct* job, S32 prev_state, BOOL pauseOnly,
                                                     mmi_da_abort_callback_type end_callback);
typedef void (*mmi_da_job_dispatch_funcptr_type)    (const mmi_da_job_struct* job);

typedef void (*mmi_da_job_resume_funcptr_type)      (mmi_da_job_struct* job);
typedef S32  (*mmi_da_job_move_funcptr_type)        (mmi_da_job_struct* job, U16* new_filepath);

typedef struct
{
    /* Init module */
    mmi_da_init_module_funcptr_type         init;

    /* Query API */
    mmi_da_job_get_filepath_funcptr_type    get_filepath;   /* get job file fullpath */
    mmi_da_job_get_progress_funcptr_type    get_progress;   /* get job progress */
    mmi_da_job_get_id_funcptr_type          get_id;         /* get job unique id */
    mmi_da_job_get_setting_funcptr_type     get_setting;

    /* Operation API */
    mmi_da_job_free_data_funcptr_type       free;
    mmi_da_job_stop_funcptr_type            stop;
    mmi_da_job_dispatch_funcptr_type        dispatch;
    
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    mmi_da_job_resume_funcptr_type          resume;
    mmi_da_job_move_funcptr_type            move;
#endif   
} mmi_da_module_funcptr_table;

#ifdef __DRM_SUPPORT__
/* -----===== DRM API =====----- */

typedef void (*mmi_da_drm_process_callback_type)(mmi_da_job_struct* job,
                                                 U16 *new_filepath, U16 err_string_id);

#endif

/* ===============--------------- Screen ---------------=============== */

typedef void (*mmi_da_confirm_funcptr_type)(U32 criteria);
typedef void (*mmi_da_confirm_format_msg_funcptr_type)(U32 criteria, U16* buffer);

typedef BOOL (*mmi_da_scr_storage_callback_type)(U32 criteria, U16*, BOOL, BOOL);
typedef mmi_da_job_struct* (*mmi_da_scr_storage_filecheck_funcptr_type)(U16* filepath, BOOL bpopup);
    
typedef void (*mmi_da_scr_auth_callback_type)(U32 criteria, U16*, U16*, BOOL in_delete);

typedef void (*mmi_da_scr_abort_funcptr_type)(U32 criteria, BOOL in_delete);

/****************************************************************************
*                       Global Function
*****************************************************************************/

/* ===============--------------- Src ---------------=============== */
extern void mmi_da_init_job_list(void);
extern mmi_da_setting_struct* mmi_da_get_setting_buffer(void);

extern mmi_da_job_struct* mmi_da_job_create(mmi_da_job_type_enum type, void *obj);
extern mmi_da_job_struct* mmi_da_job_create_ex(mmi_da_job_type_enum type, void *obj);
extern BOOL mmi_da_job_cancel(mmi_da_job_struct* job);  // Cancel before started (state = INIT)
extern BOOL mmi_da_job_start(mmi_da_job_struct* job);   // Start a job (state = DOWNLOADING)
extern BOOL mmi_da_job_error_cleanup(mmi_da_job_struct* job); // When there is a error, (state = ABORTED)

extern U32 mmi_da_get_last_error(void);

/* -----===== Src Tool =====----- */

/* find the first job that TRUE == func(criteria) */
extern mmi_da_job_struct* mmi_da_find_job(mmi_da_job_match_funcptr_type func, U32 criteria);
extern mmi_da_job_struct* mmi_da_find_job_by_filepath(U16* filepath, BOOL bpopup);   // check if there is already a job
extern U32 mmi_da_count_job(mmi_da_job_match_funcptr_type func, U32 criteria);

extern BOOL mmi_da_job_match_id_func(const mmi_da_job_struct* job, U32 criteria);

extern BOOL mmi_da_is_job_valid(const mmi_da_job_struct* job);

extern void mmi_da_copy_setting(mmi_da_job_struct* job, const mmi_da_setting_struct* setting);

extern void mmi_da_displaypopup(const mmi_da_job_struct* job, U8* string, U16 imageId);

extern BOOL mmi_da_is_in_foreground_state(void);


/* -----===== Src API =====----- */

extern void mmi_da_display_job_list(mmi_da_job_struct* job, BOOL check_complete);
extern void mmi_da_display_job_detail(mmi_da_job_struct* job);
extern void mmi_da_update_job_status(const mmi_da_job_struct* job);

extern void mmi_da_click_job(mmi_da_job_struct* job);

#ifdef __DRM_SUPPORT__
/* -----===== DRM API =====----- */

extern void mmi_da_drm_process_file(mmi_da_job_struct* job, U16 *filepath,
                                    mmi_da_drm_process_callback_type callback);
extern BOOL mmi_da_drm_process_file_abort(mmi_da_job_struct* job);
#endif

/* -----===== TRACE API =====----- */
extern void mmi_da_trace_func(S32 func_enum);
extern void mmi_da_trace_func_ex(S32 func_enum, S32 p1, S32 p2, S32 p3);
extern void mmi_da_trace_endfunc(S32 func_enum);

/* ===============--------------- Screen ---------------=============== */
extern void mmi_da_scr_init(void);

extern void mmi_da_scr_confirm_download(U32 criteria,
                                        mmi_da_confirm_format_msg_funcptr_type msg_hdlr,
                                        mmi_da_confirm_funcptr_type yes_hdlr, 
                                        mmi_da_scr_abort_funcptr_type no_hdlr,
                                        MMI_BOOL auto_delete,
                                        U16 app_id);
extern void mmi_da_scr_confirm_download_delete(void);    // use when auto_delete = FALSE

extern void mmi_da_scr_select_storage(mmi_da_scr_storage_callback_type callback,
                                      const mmi_da_scr_storage_parameter_struct* parameter,
                                      U32 criteria,
                                      U16 app_id);

extern void mmi_da_scr_user_auth(mmi_da_scr_auth_callback_type callback, U32 criteria, U16 app_id);

extern void mmi_da_scr_enter_idle_screen_notify(void);

extern void mmi_da_scr_entry_please_wait(U32 criteria, mmi_da_scr_abort_funcptr_type callback, U16 app_id);
extern void mmi_da_scr_close_please_wait(void);
    
/* ===============--------------- Config ---------------=============== */
extern const mmi_da_type_handler_struct* mmi_da_search_mime_type_handler(const applib_mime_type_struct * type);
extern UI_string_ID_type mmi_da_search_mime_type_string(const applib_mime_type_struct * type);

extern const mmi_da_type_handler_struct* mmi_da_get_default_mime_type_handler(void);

extern BOOL mmi_da_setting_check(const mmi_da_setting_struct *setting);

/* Hook_patch */
extern S32 mmi_da_search_hook_handler(const applib_mime_type_struct *type, 
                                      S32 s_index, 
                                      mmi_da_hook_dispatch_hdlr* p_hdlr);

/* ===============--------------- Utility ---------------=============== */
extern void mmi_da_send_ilm(void *local_para_ptr, void *peer_buff_ptr, msg_type msg_id, S32 dst_id);

extern BOOL mmi_da_is_in_voice_call(void);
extern BOOL mmi_da_is_in_idle_screen(void);

extern S32  mmi_da_wap_error_transfer(S32 error);
extern S32  mmi_da_util_state_transfer(mmi_da_job_state_enum state);

extern U16  mmi_da_util_get_wap_error_string_id(S32 dls_error);

/* access file system */
extern BOOL mmi_da_util_check_free_space(S32 drv, U64 need_space);
extern S32  mmi_da_util_create_file_dir(PU16 filepath, BOOL is_filepath);
extern BOOL mmi_da_util_does_file_exist(U16* path);
extern U32  mmi_da_util_get_file_size(U16* filepath);

/* filename related */
extern void mmi_da_replace_file_extension(U16 **ppath, const applib_mime_type_struct * mime_type, BOOL second_ext);
extern U16 *mmi_da_util_get_extension(U16* filepath);
extern S8 *mmi_da_util_get_extension_ascii(S8* filepath);
extern U16 *mmi_da_util_get_filename(U16 * filepath);
extern S8  *mmi_da_util_get_filename_ascii(S8 *filepath);
extern BOOL mmi_da_util_get_temp_filename(U16* pathname, U16* filename, U32 filename_len);
extern void mmi_da_util_get_ok_filepath(U16* filepath, U16** pfilepath);

extern U16* mmi_da_util_pathname_replace(U16* old_filepath, U16* folder, U16* filename, U16* fileext);
extern U16* mmi_da_util_pathname_replace_ex(U16* old_filepath, U16* folder, U16* filename, const applib_mime_type_struct* mime_type);

extern BOOL mmi_da_util_is_valid_filename(U16 *filepath);

extern applib_mime_type_struct* mmi_da_util_lookup_mime_type(U8* mime_string, U16* ext,
                                                             applib_mime_type_enum mime_type,
                                                             applib_mime_subtype_enum mime_subtype);
extern applib_mime_type_struct* mmi_da_util_lookup_mime_type_ascii(U8* mime_string, S8* ext,
                                                             applib_mime_type_enum mime_type,
                                                             applib_mime_subtype_enum mime_subtype);
extern void mmi_da_extract_filepath(U16* filepath, U16* filename, U16* fileext);
extern void mmi_da_extract_filepath_ascii(S8* filepath, U16* filename, U16* fileext);

#ifdef __DRM_SUPPORT__
extern BOOL mmi_da_is_drm_require_processing( const applib_mime_type_struct *type );
extern BOOL mmi_da_is_drm_file( const applib_mime_type_struct *type );
extern BOOL mmi_da_is_drm_right( const applib_mime_type_struct *type );
extern BOOL mmi_da_is_drm_content( const applib_mime_type_struct *type );
extern BOOL mmi_da_is_drm_roap( const applib_mime_type_struct *type );
extern BOOL mmi_da_drm_get_delivery_time(S8* header, S32* value);
#endif

extern void mmi_da_util_format_time(U16 *buffer, U32 total_secs);
extern U32  mmi_da_util_get_estimated_time(U32 file_size);

extern S8  *mmi_da_util_format_size_total(U32 curr, U32 total);
extern S8  *mmi_da_util_format_size(U32 size);

extern U16  mmi_da_util_get_icon_from_appid(S32 app_id);
extern S32  mmi_da_util_get_appid_from_icon(U16 icon_id);

/* ===============--------------- HTTP ---------------=============== */
const S8* mmi_da_http_get_header(mmi_da_job_struct *job, U32* header_len);

#ifdef __MMI_OMA_DD_DOWNLOAD__
/* ===============--------------- OMA ---------------=============== */
extern void mmi_da_oma_process_dd_file(S32 session_id, S32 mime_type, S32 mime_subtype, S32 action_type, PU16 filename,
                                       PS8 download_url,PS8 mime_type_string);
extern void mmi_da_oma_setting(S32 session_id, S32 mime_type, S32 mime_subtype, S32 action, 
                               U32 filesize, PS8 url, PS8 mime_type_string, U32 content_len,
                               PS8 content, mmi_da_setting_struct * setting);
extern mmi_da_job_struct* mmi_da_oma_find_job_by_dd(S8* dd_url);

/* ===============--------------- OMA2 ---------------=============== */
extern void mmi_da_oma_process_dd2_file(S32 session_id, S32 mime_type, S32 mime_subtype, S32 action_type, PU16 filename,
                                        PS8 download_url,PS8 mime_type_string);
extern void mmi_da_oma2_setting(S32 session_id, S32 mime_type, S32 mime_subtype, S32 action, 
                                U32 filesize, PS8 url, PS8 mime_type_string, U32 content_len,
                                PS8 content, mmi_da_setting_struct * setting);
#endif

#endif /* DOWNLOAD_AGENT_PROT_H */


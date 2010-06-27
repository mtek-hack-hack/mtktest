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

/*******************************************************************************
 * Filename:
 * ---------
 * aud_vr_main.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes vr service functions
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES =========*/
#include "stack_config.h"
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"
#include "fat_fs.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_equipment.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_main.h"
#include "aud_main.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

#ifdef __MED_VR_MOD__
typedef struct
{
    volatile int cnt;
    volatile module_type tid;
    volatile kal_mutexid mutex;
} aud_vr_mutex_struct;

/* VR context */
aud_vr_context_struct vr_ctx;

/* VR mutex */
static aud_vr_mutex_struct vr_mutex;

/* latest session id used for alloc a unique session id */
static kal_uint32 vr_session_id;


/*****************************************************************************
 * FUNCTION
 *  aud_vr_mutex_init
 * DESCRIPTION
 *  init mutex for vr
 * PARAMETERS
 *  M           [?]     
 *  name        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vr_mutex_init(aud_vr_mutex_struct *M, kal_char *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    M->mutex = kal_create_mutex(name);
    M->cnt = 0;
    M->tid = MOD_NIL;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_mutex_lock
 * DESCRIPTION
 *  mutex lock operation
 * PARAMETERS
 *  M       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vr_mutex_lock(aud_vr_mutex_struct *M)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (stack_int_get_active_module_id() != M->tid)
    {
        kal_take_mutex(M->mutex);
        M->tid = stack_int_get_active_module_id();
    }
    ++(M->cnt);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_mutex_unlock
 * DESCRIPTION
 *  mutex unlock operation
 * PARAMETERS
 *  M       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vr_mutex_unlock(aud_vr_mutex_struct *M)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    --(M->cnt);

    if (M->cnt == 0)
    {
        M->tid = MOD_NIL;
        kal_give_mutex(M->mutex);
    }
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vr_new_session_id
 * DESCRIPTION
 *  alloc a unique session id. this function might be invoked by different task so
 *  the read/write access is protected by a mutex
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
kal_uint32 media_aud_vr_new_session_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_vr_mutex_lock(&vr_mutex);
    vr_session_id++;
    aud_vr_mutex_unlock(&vr_mutex);

    return vr_session_id;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_check_db_folder
 * DESCRIPTION
 *  check or create vr database folder
 * PARAMETERS
 *  folder_name     [?]         
 *  mode            [IN]        
 *  lang            [IN]        
 *  group_id        [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool aud_vr_check_db_folder(kal_uint16 *folder_name, kal_uint8 mode, kal_uint8 lang, kal_uint8 group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mode)
    {
        case MED_VR_ISD_MODE:
            kal_wsprintf(folder_name, "%c:\\VRDB\\ISD\\%d\\", (kal_uint8) vr_ctx.db_drive, group_id);
            break;
        case MED_VR_CSI_MODE:
            folder_name[0] = 0;
            break;
        case MED_VR_PSI_MODE:
            folder_name[0] = 0;
            break;
        default:
            folder_name[0] = 0;
            break;
    }

    if (folder_name[0] != 0)
    {
        kal_int32 res = aud_create_full_path_folder(folder_name);

        result = (res == FS_FILE_EXISTS || res == FS_NO_ERROR);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_startup
 * DESCRIPTION
 *  initialize vr module
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool aud_vr_startup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vr_ctx.state = AUD_VR_STATE_IDLE;
    vr_ctx.src_mod = MOD_NIL;
    vr_ctx.db_drive = FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE);       /* system drive */
    /* vr_ctx.db_drive = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM); // public drive */
    aud_vr_mutex_init(&vr_mutex, "VR mutex");

    if (!aud_vr_sd_startup())
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_main
 * DESCRIPTION
 *  vr request dispatch
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vr_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_MEDIA_VR_GET_VERSION_REQ:
            aud_vr_get_version_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VR_GET_PARAM_REQ:
            aud_vr_get_param_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VR_SET_PARAM_REQ:
            aud_vr_set_param_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VR_INIT_RCG_REQ:
            aud_vr_init_rcg_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VR_INIT_TRN_REQ:
            aud_vr_init_trn_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VR_RCG_PROCESS_REQ:   /* SD callback */
            aud_vr_sd_rcg_process();
            break;
        case MSG_ID_MEDIA_VR_TRN_PROCESS_REQ:   /* SD callback */
            aud_vr_sd_trn_process();
            break;
        case MSG_ID_MEDIA_VR_VOICE_IN_REQ:
            aud_vr_voice_in_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VR_DEL_TAG_REQ:
            aud_vr_del_tag_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VR_CHECK_TAG_REQ:
            aud_vr_check_tag_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VR_SYNC_DB_REQ:
            aud_vr_sync_db_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VR_PLAY_TAG_REQ:
            aud_vr_play_tag_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VR_GET_DIR_REQ:
            aud_vr_get_dir_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VR_ADD_TAG_REQ:
            aud_vr_add_tag_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VR_ABORT_REQ:
            aud_vr_abort_req_hdlr(ilm_ptr);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_get_version_req_hdlr
 * DESCRIPTION
 *  vr get version
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vr_get_version_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vr_get_version_req_struct *msg_p = (media_vr_get_version_req_struct*) ilm_ptr->local_para_ptr;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_p->mode)
    {
        case MED_VR_ISD_MODE:
            result = VR_GetEngineVer();
            break;
        case MED_VR_CSI_MODE:
            result = -1;
            break;
        case MED_VR_PSI_MODE:
            result = -1;
            break;
        default:
            result = -1;
            break;
    }

    aud_set_result(result);

    AUD_SET_EVENT(AUD_EVT_VR_GET_VER);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_get_param_req_hdlr
 * DESCRIPTION
 *  vr get parameters
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vr_get_param_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vr_get_param_req_struct *msg_p = (media_vr_get_param_req_struct*) ilm_ptr->local_para_ptr;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_p->mode)
    {
        case MED_VR_ISD_MODE:
            if (VR_GetParameters(msg_p->sim, msg_p->diff, msg_p->rej) == VR_OK)
            {
                result = MED_RES_OK;
            }
            else
            {
                result = MED_RES_FAIL;
            }
            break;
        case MED_VR_CSI_MODE:
            result = MED_RES_PARAM_ERROR;
            break;
        case MED_VR_PSI_MODE:
            result = MED_RES_PARAM_ERROR;
            break;
        default:
            result = MED_RES_PARAM_ERROR;
            break;
    }

    aud_set_result(result);

    AUD_SET_EVENT(AUD_EVT_VR_GET_PARAM);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_set_param_req_hdlr
 * DESCRIPTION
 *  vr set parameters
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vr_set_param_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vr_set_param_req_struct *msg_p = (media_vr_set_param_req_struct*) ilm_ptr->local_para_ptr;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_p->mode)
    {
        case MED_VR_ISD_MODE:
            if (VR_SetParemeters(msg_p->sim, msg_p->diff, msg_p->rej) == VR_OK)
            {
                result = MED_RES_OK;
            }
            else
            {
                result = MED_RES_FAIL;
            }
            break;
        case MED_VR_CSI_MODE:
            result = MED_RES_PARAM_ERROR;
            break;
        case MED_VR_PSI_MODE:
            result = MED_RES_PARAM_ERROR;
            break;
        default:
            result = MED_RES_PARAM_ERROR;
            break;
    }

    aud_set_result(result);

    AUD_SET_EVENT(AUD_EVT_VR_SET_PARAM);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_init_rcg_req_hdlr
 * DESCRIPTION
 *  vr initialize a recognition session
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vr_init_rcg_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vr_init_rcg_req_struct *msg_p = (media_vr_init_rcg_req_struct*) ilm_ptr->local_para_ptr;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_VR_INIT_RCG_REQ_HDLR);

    /* not allow cross another session */
    if (vr_ctx.state == AUD_VR_STATE_IDLE)
    {
        vr_ctx.src_mod = ilm_ptr->src_mod_id;
        vr_ctx.session_id = msg_p->session_id;
        vr_ctx.mode = msg_p->mode;
        vr_ctx.lang = msg_p->language;
        vr_ctx.group_id = msg_p->group_id;

        /* check not exceed max group id */
        if (vr_ctx.group_id >= VR_SD_MAX_GROUP_NUM)
        {
            result = MED_RES_PARAM_ERROR;
        }
        else if (aud_vr_check_db_folder(vr_ctx.db_path, vr_ctx.mode, vr_ctx.lang, vr_ctx.group_id))
        {
            switch (vr_ctx.mode)
            {
                case MED_VR_ISD_MODE:
                    result = aud_vr_sd_init_rcg();
                    break;
                case MED_VR_CSI_MODE:
                    result = MED_RES_PARAM_ERROR;
                    break;
                case MED_VR_PSI_MODE:
                    result = MED_RES_PARAM_ERROR;
                    break;
                default:
                    result = MED_RES_PARAM_ERROR;
                    break;
            }
        }
        else
        {
            result = MED_RES_OPEN_FILE_FAIL;
        }
    }
    else
    {
        result = MED_RES_BUSY;
    }

    AUD_VALUE_TRACE(result, vr_ctx.state, -1);
    aud_set_result(result);

    AUD_SET_EVENT(AUD_EVT_VR_INIT_RCG);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_init_trn_req_hdlr
 * DESCRIPTION
 *  vr initialize a training session
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vr_init_trn_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vr_init_trn_req_struct *msg_p = (media_vr_init_trn_req_struct*) ilm_ptr->local_para_ptr;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_VR_INIT_TRN_REQ_HDLR);
    
    /* not allow cross another session */
    if (vr_ctx.state == AUD_VR_STATE_IDLE)
    {
        vr_ctx.src_mod = ilm_ptr->src_mod_id;
        vr_ctx.session_id = msg_p->session_id;
        vr_ctx.mode = msg_p->mode;
        vr_ctx.lang = msg_p->language;
        vr_ctx.group_id = msg_p->group_id;
        vr_ctx.word_id = msg_p->word_id;

        /* check not exceed max group id */
        if (vr_ctx.group_id >= VR_SD_MAX_GROUP_NUM)
        {
            result = MED_RES_PARAM_ERROR;
        }
        else if (aud_vr_check_db_folder(vr_ctx.db_path, vr_ctx.mode, vr_ctx.lang, vr_ctx.group_id))
        {
            switch (vr_ctx.mode)
            {
                case MED_VR_ISD_MODE:
                    result = aud_vr_sd_init_trn();
                    break;
                case MED_VR_CSI_MODE:
                    result = MED_RES_PARAM_ERROR;
                    break;
                case MED_VR_PSI_MODE:
                    result = MED_RES_PARAM_ERROR;
                    break;
                default:
                    result = MED_RES_PARAM_ERROR;
                    break;
            }
        }
        else
        {
            result = MED_RES_OPEN_FILE_FAIL;
        }
    }
    else
    {
        result = MED_RES_BUSY;
    }

    AUD_VALUE_TRACE(result, vr_ctx.state, -1);
    aud_set_result(result);

    AUD_SET_EVENT(AUD_EVT_VR_INIT_TRN);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_voice_in_req_hdlr
 * DESCRIPTION
 *  vr voice in notification
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vr_voice_in_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vr_voice_in_req_struct *msg_p = (media_vr_voice_in_req_struct*) ilm_ptr->local_para_ptr;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_VR_VOICE_IN_REQ_HDLR);
    
    /* check which session is the voice in for */
    if (vr_ctx.state == AUD_VR_STATE_RCG_SESSION && vr_ctx.session_id == msg_p->session_id)
    {
        /* recognition session */
        switch (vr_ctx.mode)
        {
            case MED_VR_ISD_MODE:
                result = aud_vr_sd_rcg_voice_in();
                break;
            case MED_VR_CSI_MODE:
                result = MED_RES_PARAM_ERROR;
                break;
            case MED_VR_PSI_MODE:
                result = MED_RES_PARAM_ERROR;
                break;
            default:
                result = MED_RES_PARAM_ERROR;
                break;
        }
    }
    else if (vr_ctx.state == AUD_VR_STATE_TRN_SESSION && vr_ctx.session_id == msg_p->session_id)
    {
        /* training session */
        switch (vr_ctx.mode)
        {
            case MED_VR_ISD_MODE:
                result = aud_vr_sd_trn_voice_in(msg_p->seq_no);
                break;
            case MED_VR_CSI_MODE:
                result = MED_RES_PARAM_ERROR;
                break;
            case MED_VR_PSI_MODE:
                result = MED_RES_PARAM_ERROR;
                break;
            default:
                result = MED_RES_PARAM_ERROR;
                break;
        }
    }
    else
    {
        result = MED_RES_FAIL;
    }

    AUD_VALUE_TRACE(result, vr_ctx.state, -1);
    aud_set_result(result);

    AUD_SET_EVENT(AUD_EVT_VR_VOICE_IN);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_del_tag_req_hdlr
 * DESCRIPTION
 *  vr delete tag
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vr_del_tag_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vr_del_tag_req_struct *msg_p = (media_vr_del_tag_req_struct*) ilm_ptr->local_para_ptr;
    kal_uint16 db_path[VR_MAX_DB_PATH_LEN + 1];
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_VR_DEL_TAG_REQ_HDLR);
    
    /* not allow to delete a tag during session */
    if (vr_ctx.state == AUD_VR_STATE_IDLE)
    {
        /* check not exceed max group id */
        if (msg_p->group_id >= VR_SD_MAX_GROUP_NUM)
        {
            result = MED_RES_PARAM_ERROR;
        }
        else if (aud_vr_check_db_folder(db_path, msg_p->mode, msg_p->language, msg_p->group_id))
        {
            switch (vr_ctx.mode)
            {
                case MED_VR_ISD_MODE:
                    result = aud_vr_sd_delete_tag(msg_p->group_id, msg_p->word_id);
                    break;
                case MED_VR_CSI_MODE:
                    result = MED_RES_PARAM_ERROR;
                    break;
                case MED_VR_PSI_MODE:
                    result = MED_RES_PARAM_ERROR;
                    break;
                default:
                    result = MED_RES_PARAM_ERROR;
                    break;
            }
        }
        else
        {
            result = MED_RES_OPEN_FILE_FAIL;
        }
    }
    else
    {
        result = MED_RES_BUSY;
    }

    AUD_VALUE_TRACE(result, vr_ctx.state, -1);
    aud_set_result(result);

    AUD_SET_EVENT(AUD_EVT_VR_DEL_TAG);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_check_tag_req_hdlr
 * DESCRIPTION
 *  vr check does tag exist
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vr_check_tag_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vr_check_tag_req_struct *msg_p = (media_vr_check_tag_req_struct*) ilm_ptr->local_para_ptr;
    kal_int32 result;
    kal_uint16 db_path[VR_MAX_DB_PATH_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_VR_CHECK_TAG_REQ_HDLR);

    /* check not exceed max group id */
    if (msg_p->group_id >= VR_SD_MAX_GROUP_NUM)
    {
        result = MED_RES_PARAM_ERROR;
    }
    else if (aud_vr_check_db_folder(db_path, msg_p->mode, msg_p->language, msg_p->group_id))
    {
        switch (msg_p->mode)
        {
            case MED_VR_ISD_MODE:
                if (aud_vr_sd_find_word_id(msg_p->group_id, msg_p->word_id) >= 0)
                {
                    result = MED_RES_ID_EXIST;
                }
                else
                {
                    result = MED_RES_NO_MATCH;
                }
                break;
            case MED_VR_CSI_MODE:
                result = MED_RES_PARAM_ERROR;
                break;
            case MED_VR_PSI_MODE:
                result = MED_RES_PARAM_ERROR;
                break;
            default:
                result = MED_RES_PARAM_ERROR;
                break;
        }
    }
    else
    {
        result = MED_RES_NO_MATCH;
    }

    AUD_VALUE_TRACE(result, vr_ctx.state, -1);
    aud_set_result(result);

    AUD_SET_EVENT(AUD_EVT_VR_CHECK_TAG);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_sync_db_req_hdlr
 * DESCRIPTION
 *  vr sync database
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vr_sync_db_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vr_sync_db_req_struct *msg_p = (media_vr_sync_db_req_struct*) ilm_ptr->local_para_ptr;
    kal_uint16 db_path[VR_MAX_DB_PATH_LEN + 1];
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_VR_SYNC_DB_REQ_HDLR);
    
    /* not allow to sync database during session */
    if (vr_ctx.state == AUD_VR_STATE_IDLE)
    {
        /* check not exceed max group id */
        if (msg_p->group_id >= VR_SD_MAX_GROUP_NUM)
        {
            result = MED_RES_PARAM_ERROR;
        }
        else if (aud_vr_check_db_folder(db_path, msg_p->mode, msg_p->language, msg_p->group_id))
        {
            switch (vr_ctx.mode)
            {
                case MED_VR_ISD_MODE:
                    result = aud_vr_sd_sync_db(msg_p->group_id, msg_p->id_length_p, msg_p->id_array);
                    break;
                case MED_VR_CSI_MODE:
                    result = MED_RES_PARAM_ERROR;
                    break;
                case MED_VR_PSI_MODE:
                    result = MED_RES_PARAM_ERROR;
                    break;
                default:
                    result = MED_RES_PARAM_ERROR;
                    break;
            }
        }
        else
        {
            result = MED_RES_OPEN_FILE_FAIL;
        }
    }
    else
    {
        result = MED_RES_BUSY;
    }

    AUD_VALUE_TRACE(result, vr_ctx.state, -1);
    aud_set_result(result);

    AUD_SET_EVENT(AUD_EVT_VR_SYNC_DB);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_play_tag_req_hdlr
 * DESCRIPTION
 *  vr play tag
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vr_play_tag_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vr_play_tag_req_struct *msg_p = (media_vr_play_tag_req_struct*) ilm_ptr->local_para_ptr;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_VR_PLAY_TAG_REQ_HDLR);
    
    /* not allow to play a tag during session */
    if (vr_ctx.state == AUD_VR_STATE_IDLE)
    {
        vr_ctx.src_mod = ilm_ptr->src_mod_id;
        vr_ctx.mode = msg_p->mode;
        vr_ctx.lang = msg_p->language;
        vr_ctx.group_id = msg_p->group_id;
        vr_ctx.word_id = msg_p->word_id;
        aud_context_p->identifier = msg_p->identifier;

        /* check not exceed max group id */
        if (vr_ctx.group_id >= VR_SD_MAX_GROUP_NUM)
        {
            result = MED_RES_PARAM_ERROR;
        }
        else if (aud_vr_check_db_folder(vr_ctx.db_path, vr_ctx.mode, vr_ctx.lang, vr_ctx.group_id))
        {
            switch (vr_ctx.mode)
            {
                case MED_VR_ISD_MODE:
                    result = aud_vr_sd_play_tag();
                    break;
                case MED_VR_CSI_MODE:
                    result = MED_RES_PARAM_ERROR;
                    break;
                case MED_VR_PSI_MODE:
                    result = MED_RES_PARAM_ERROR;
                    break;
                default:
                    result = MED_RES_PARAM_ERROR;
                    break;
            }
        }
        else
        {
            result = MED_RES_OPEN_FILE_FAIL;
        }
    }
    else
    {
        result = MED_RES_BUSY;
    }

    AUD_VALUE_TRACE(result, vr_ctx.state, -1);
    aud_set_result(result);

    AUD_SET_EVENT(AUD_EVT_VR_PLAY_TAG);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_get_dir_req_hdlr
 * DESCRIPTION
 *  vr get database dir
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vr_get_dir_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vr_get_dir_req_struct *msg_p = (media_vr_get_dir_req_struct*) ilm_ptr->local_para_ptr;
    kal_int32 result;
    kal_uint16 db_path[VR_MAX_DB_PATH_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_VR_GET_DIR_REQ_HDLR);

    msg_p->folder_name[0] = 0;

    /* check not exceed max group id */
    if (msg_p->group_id >= VR_SD_MAX_GROUP_NUM)
    {
        result = MED_RES_PARAM_ERROR;
    }
    else if (aud_vr_check_db_folder(db_path, msg_p->mode, msg_p->language, msg_p->group_id))
    {
        switch (msg_p->mode)
        {
            case MED_VR_ISD_MODE:
                kal_wstrcpy(msg_p->folder_name, db_path);
                result = MED_RES_OK;
                break;
            case MED_VR_CSI_MODE:
                result = MED_RES_PARAM_ERROR;
                break;
            case MED_VR_PSI_MODE:
                result = MED_RES_PARAM_ERROR;
                break;
            default:
                result = MED_RES_PARAM_ERROR;
                break;
        }
    }
    else
    {
        result = MED_RES_OPEN_FILE_FAIL;
    }

    AUD_VALUE_TRACE(result, vr_ctx.state, -1);
    aud_set_result(result);

    AUD_SET_EVENT(AUD_EVT_VR_GET_DIR);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_add_tag_req_hdlr
 * DESCRIPTION
 *  vr add tag
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vr_add_tag_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vr_add_tag_req_struct *msg_p = (media_vr_add_tag_req_struct*) ilm_ptr->local_para_ptr;
    kal_uint16 db_path[VR_MAX_DB_PATH_LEN + 1];
    kal_int32 result;
    kal_int32 id_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_VR_ADD_TAG_REQ_HDLR);
    
    /* not allow to add tags during session */
    if (vr_ctx.state == AUD_VR_STATE_IDLE)
    {
        /* check not exceed max group id */
        if (msg_p->group_id >= VR_SD_MAX_GROUP_NUM)
        {
            result = MED_RES_PARAM_ERROR;
        }
        else if (aud_vr_check_db_folder(db_path, msg_p->mode, msg_p->language, msg_p->group_id))
        {
            id_length = (msg_p->id_length <= VR_MAX_ADD_ONCE_NUM) ? msg_p->id_length : VR_MAX_ADD_ONCE_NUM;
            switch (vr_ctx.mode)
            {
                case MED_VR_ISD_MODE:
                    result = aud_vr_sd_add_tag(msg_p->group_id, msg_p->id_array, id_length);
                    break;
                case MED_VR_CSI_MODE:
                    result = MED_RES_PARAM_ERROR;
                    break;
                case MED_VR_PSI_MODE:
                    result = MED_RES_PARAM_ERROR;
                    break;
                default:
                    result = MED_RES_PARAM_ERROR;
                    break;
            }
        }
        else
        {
            result = MED_RES_OPEN_FILE_FAIL;
        }
    }
    else
    {
        result = MED_RES_BUSY;
    }

    AUD_VALUE_TRACE(result, vr_ctx.state, -1);
    aud_set_result(result);

    AUD_SET_EVENT(AUD_EVT_VR_ADD_TAG);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_abort_req_hdlr
 * DESCRIPTION
 *  vr abort a session
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vr_abort_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_VR_ABORT_REQ_HDLR);

    if (vr_ctx.state != AUD_VR_STATE_IDLE)
    {
        switch (vr_ctx.mode)
        {
            case MED_VR_ISD_MODE:
                aud_vr_sd_abort();
                break;
            case MED_VR_CSI_MODE:
                break;
            case MED_VR_PSI_MODE:
                break;
            default:
                break;
        }
    }

    AUD_SET_EVENT(AUD_EVT_VR_ABORT);
}

#endif /* __MED_VR_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 


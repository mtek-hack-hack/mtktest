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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#if defined (__MMI_DOWNLOAD_AGENT__)

#include "CommonScreens.h"
#include "ProtocolEvents.h"
#include "app_mine.h"

#include "FileMgr.h"                    /* FMGR */
#include "FileManagerGProt.h"
#include "FileManagerDef.h"             /* for FMGR string id */

#include "drm_def.h"                    /* DRM_PROC_RESULT_OK */
#include "drm_gprot.h"
#include "DLAgentDef.h"
#include "DLAgentGprot.h"
#include "DLAgentprot.h"
#include "DLAgentResDef.h"

#include "SimDetectionDef.h"            /* SCR_SIM_INSERTION and SCR_SIM_BLOCK */
#include "IdleAppDef.h"                 /* IDLE_SCREEN_ID */
#include "CallManagementGprot.h"        /* GetCmMarkerScrnID() */

#include "wapadp.h"

#include "SimDetectionGprot.h"          /* for EDGE status */

#include "inet_msg_api.h"               /*inet_msg_get_header_field */

/*****************************************************************************
* FUNCTION
*   mmi_da_oma_send_ilm
* DESCRIPTION
*   Send ilm
* PARAMETERS
*
* RETURNS
*   void
*****************************************************************************/
void mmi_da_send_ilm(void *local_para_ptr, void *peer_buff_ptr, msg_type msg_id, S32 dst_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = dst_id;
    Message.oslMsgId = msg_id;
    Message.oslDataPtr = (local_para_struct *) local_para_ptr;
    Message.oslPeerBuffPtr = (peer_buff_struct *) peer_buff_ptr;

    if(dst_id == MOD_WAP)
    {
        Message.oslSapId = WAP_MMI_SAP;
    }
    else
    {
        Message.oslSapId = INVALID_SAP;
    }

    OslMsgSendExtQueue(&Message);
}

/*************************************************************************
* FUNCTION
*   mmi_da_is_in_voice_call
* DESCRIPTION
*   this function use to detect taht current have voice call or not
* PARAMETERS
*   void
* RETURNS
*   KAL_TRUE or KAL_FALSE
*************************************************************************/
BOOL mmi_da_is_in_voice_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (  isInCall() == FALSE || (isInCall() && GetWapCallPresent() && !isIncomingCall()) )
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;

//    return IsScreenPresent(GetCmMarkerScrnID());
}

/*****************************************************************************
* FUNCTION
*   mmi_da_is_in_idle_screen
* DESCRIPTION
*   check if the screen is in idle screen
* PARAMETERS
*   void
* RETURNS
*   void
*****************************************************************************/
BOOL mmi_da_is_in_idle_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_shutdown_is_in_power_off_period() == MMI_TRUE)
    {
        return MMI_FALSE;
    }

    if (IsScreenPresent(SCR_SIM_INSERTION)      /* is sim insertion IN history ? */
        || IsScreenPresent(IDLE_SCREEN_ID)      /* is idle screen IN history ? */
        || IsScreenPresent(SCR_SIM_BLOCK))      /* is sim block IN history ? */
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}

#ifdef __DRM_SUPPORT__
/*****************************************************************************
* FUNCTION
*   mmi_da_is_drm_file
* DESCRIPTION
*   check if it is a drm_file which require pre-processing
* PARAMETERS
*   Void
* RETURNS
*   TRUE/FALSE
*****************************************************************************/
BOOL mmi_da_is_drm_require_processing( const applib_mime_type_struct *type )
{
    return mmi_da_is_drm_file(type);
}


/*****************************************************************************
* FUNCTION
*   mmi_da_is_drm_file
* DESCRIPTION
*   check if it is a drm_file
* PARAMETERS
*   Void
* RETURNS
*   TRUE/FALSE
*****************************************************************************/

BOOL mmi_da_is_drm_file( const applib_mime_type_struct *type )
{
    if (type &&
        (
    #ifdef __DRM_V01__
         type->mime_subtype == MIME_SUBTYPE_DRM_MESSAGE ||
         type->mime_subtype == MIME_SUBTYPE_DRM_RIGHTS_XML ||
         type->mime_subtype == MIME_SUBTYPE_DRM_RIGHTS_WBXML ||
         type->mime_subtype == MIME_SUBTYPE_DRM_CONTENT ||
    #endif
    #ifdef __DRM_V02__
         type->mime_subtype == MIME_SUBTYPE_DRM_CONTENT_V2 ||
         type->mime_subtype == MIME_SUBTYPE_ROAP_PDU ||
         type->mime_subtype == MIME_SUBTYPE_ROAP_TRIGGER ||
         type->mime_subtype == MIMI_SUBTYPE_PROTECTED_RO ||
    #endif
         MMI_FALSE ))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

/*****************************************************************************
* FUNCTION
*   mmi_da_is_drm_right
* DESCRIPTION
*   check if it is a drm_file
* PARAMETERS
*   Void
* RETURNS
*   TRUE/FALSE
*****************************************************************************/
BOOL mmi_da_is_drm_right( const applib_mime_type_struct *type )
{
    if (type &&
        (
    #ifdef __DRM_V01__
          type->mime_subtype == MIME_SUBTYPE_DRM_RIGHTS_XML ||
          type->mime_subtype == MIME_SUBTYPE_DRM_RIGHTS_WBXML ||
    #endif
    #ifdef __DRM_V02__
          type->mime_subtype == MIMI_SUBTYPE_PROTECTED_RO ||
    #endif
          MMI_FALSE ))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

/*****************************************************************************
* FUNCTION
*   mmi_da_is_drm_content
* DESCRIPTION
*   check if it is a drm_file
* PARAMETERS
*   Void
* RETURNS
*   TRUE/FALSE
*****************************************************************************/
BOOL mmi_da_is_drm_content( const applib_mime_type_struct *type )
{
    if (type &&
        (
    #ifdef __DRM_V01__
          type->mime_subtype == MIME_SUBTYPE_DRM_MESSAGE ||
          type->mime_subtype == MIME_SUBTYPE_DRM_CONTENT ||
    #endif
     #ifdef __DRM_V02__
          type->mime_subtype == MIME_SUBTYPE_DRM_CONTENT_V2 ||
     #endif
          MMI_FALSE))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

/*****************************************************************************
* FUNCTION
*   mmi_da_is_drm_content
* DESCRIPTION
*   check if it is a drm_file
* PARAMETERS
*   Void
* RETURNS
*   TRUE/FALSE
*****************************************************************************/
BOOL mmi_da_is_drm_roap(const applib_mime_type_struct *type )
{
    if (type && (
     #ifdef __DRM_V02__
          type->mime_subtype == MIME_SUBTYPE_ROAP_PDU ||
          type->mime_subtype == MIME_SUBTYPE_ROAP_TRIGGER ||
     #endif
          MMI_FALSE))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

static void* _drm_get_buffer(kal_uint32 size)
{
    return OslMalloc(size);
}
static void _drm_free_buffer(void* buffer)
{
    OslMfree(buffer);
}

#define DRM_DELIVERY_ATTRIBUTE "X-Oma-Drm-Separate-Delivery"
/*****************************************************************************
* FUNCTION
*   mmi_da_drm_get_delivery_time
* DESCRIPTION
*   Process the http header, and get the drm header attribute
* PARAMETERS
*   Void
* RETURNS
*   MMI_TRUE:   have this attribute
*   MMI_FALSE:  do not have this attribute
*****************************************************************************/
BOOL mmi_da_drm_get_delivery_time(S8* header, S32* value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    inet_message_struct     inet_msg;
    inet_mem_func_struct    mem_func;
    S8                      *value_string;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if( header == NULL )
        return FALSE;

    mem_func.alloc_fn = _drm_get_buffer;
    mem_func.free_fn = _drm_free_buffer;

    if ( INET_RESULT_OK != inet_msg_initialize(INET_MSG_APP_HTTP, &mem_func, &inet_msg) )
    {
        return FALSE;
    }

    if( INET_RESULT_OK != inet_msg_unpack(&inet_msg, INET_MSG_APP_HTTP,
                                          INET_MSG_UNPACK_HEADER,
                                          header, strlen(header),
                                          NULL, NULL))
    {
        inet_msg_deinitialize(&inet_msg);
        return FALSE;
    }

    if( INET_RESULT_OK != inet_msg_get_header_field(INET_MSG_APP_HTTP, &inet_msg,
                                                    INET_MSG_PROCESS_HEADER, 0, 0, 
                                                    INET_HDR_UNRECOGNIZED, DRM_DELIVERY_ATTRIBUTE, 
                                                    INET_MSG_HDR_VAL_STRING,
                                                    (kal_uint32*) &value_string))
    {
        inet_msg_deinitialize(&inet_msg);
        return FALSE;
    }

    *value = atoi(value_string);
    return TRUE;
}


#endif



/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
S32 mmi_da_wap_error_transfer(S32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* original error code in DL , do not transfer */
    if(error < -1000)
        return error;

    switch(error)
    {

        case WAP_DL_ERROR_OK:
            return MMI_DA_SUCCESS;
        case WAP_DL_ERROR_CANCELLED:
            return MMI_DA_ERROR_CANCELLED;
        case WAP_DL_ERROR_INVALID_SESSION_ID:
            return MMI_DA_ERROR_INVALID_SESSION_ID;
        case WAP_DL_ERROR_CONNECTION_CLOSED:
            return MMI_DA_ERROR_CONNECTION_CLOSED;
        case WAP_DL_ERROR_INVALID_FILE:
            return MMI_DA_ERROR_INVALID_FILE;
        case FS_DISK_FULL:
        case WAP_DL_ERROR_DISK_FULL:
            return MMI_DA_ERROR_DISK_FULL;
        case WAP_DL_ERROR_FILE_ACCESS:
            return MMI_DA_ERROR_FILE_ACCESS;
        default:
            return MMI_DA_ERROR_FAIL;
    }

}

/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
U16  mmi_da_util_get_wap_error_string_id(S32 dls_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if(dls_error < 0)
        return (U16)GetFileSystemErrorString(dls_error);
        
    switch(dls_error)
    {
    case WAP_DL_ERROR_CONNECTION_CLOSED:    string_id = STR_ID_DA_ERROR_CONNECT_CLOSED;    break;
    case WAP_DL_ERROR_INVALID_FILE:         string_id = FMGR_FS_INVALID_FILENAME_TEXT;      break;
    case WAP_DL_ERROR_DISK_FULL:            string_id = FMGR_FS_DISK_FULL_TEXT;             break;
    case WAP_DL_ERROR_FILE_ACCESS:          string_id = FMGR_FS_ACCESS_DENIED_TEXT;         break;
    case WAP_DL_ERROR_FILE_READ_ONLY:       string_id = FMGR_FS_READ_ONLY_ERROR_TEXT;       break;

    case WAP_DL_ERROR_CANCELLED:
    case WAP_DL_ERROR_INVALID_SESSION_ID:
    case WAP_DL_ERROR_OK:
    default:
        string_id = STR_GLOBAL_ERROR;
    }

    return string_id;
}

S32 mmi_da_util_state_transfer(mmi_da_job_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: revise the state
    switch(state)
    {
    case MMI_DA_JOB_STATE_INIT:
        return MMI_DA_STATE_INIT;

    case MMI_DA_JOB_STATE_ABORTING:
#ifdef __DRM_SUPPORT__
    case MMI_DA_JOB_STATE_DRM_PROCESSING:
#endif
    case MMI_DA_JOB_STATE_PROCESSING:
    case MMI_DA_JOB_STATE_DOWNLOADING:
        return MMI_DA_STATE_DOWNLOADING;
        
    case MMI_DA_JOB_STATE_PAUSED:
    case MMI_DA_JOB_STATE_ABORTED:
    case MMI_DA_JOB_STATE_FAILED:
        return MMI_DA_STATE_ABORT;
        
    case MMI_DA_JOB_STATE_COMPLETED:
        return MMI_DA_STATE_COMPLETE;

    default:
        ASSERT(0);
        return MMI_DA_STATE_INIT;
    }
}


#define API_FILE

/*****************************************************************************
* FUNCTION
*   mmi_da_util_check_free_space
* DESCRIPTION
*   check if have enought space to save file
* PARAMETERS
*   drv         [IN]    Check which storage
*   need_space  [IN]    how many space we need.
* RETURNS
*   MMI_TRUE or MMI_FALSE
*****************************************************************************/

BOOL mmi_da_util_check_free_space(S32 drv, U64 need_space)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32         fs_ret;
    FS_DiskInfo disk_info;
    U16         path[4];
    U64         disk_free_space = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    path[0] = drv;
    path[1] = ':';
    path[2] = '\\';
    path[3] = 0;
    
    fs_ret = FS_GetDiskInfo((PU16) path, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
    if (fs_ret >= 0)
    {
        disk_free_space = (U64)disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;

        if(disk_free_space == 0)
            return FALSE;
        
        if (disk_free_space < need_space)
        {
            return MMI_FALSE;
        }
        else
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
U32 mmi_da_util_get_file_size(U16* filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE   filehandle;
    UINT        size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!filepath)
        return 0;
    filehandle = FS_Open(filepath, FS_READ_ONLY);
    if(filehandle >= 0)
    {
        FS_GetFileSize(filehandle, &size);
        FS_Close(filehandle);
    }
    return (U32)size;
}

/*****************************************************************************
* FUNCTION
*   mmi_da_replace_file_extension
* DESCRIPTION
*   replace the extension file name
* PARAMETERS
*   path        IN  File path
*   mime_type   IN  The extension file name you want to replace
*                   If this parameter is NULL, we use "tmp" to replace.
* RETURNS
*   void
*****************************************************************************/
void mmi_da_replace_file_extension(U16 **ppath, const applib_mime_type_struct * mime_type, BOOL second_ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16             *ptr;
    U16             temp[FMGR_MAX_PATH_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(ppath && *ppath);

    mmi_ucs2cpy((S8*)temp, (S8*)(*ppath));

    ptr = mmi_da_util_get_extension(temp);
    if (ptr == NULL)
    {
        ptr = temp + mmi_ucs2strlen((S8 *) temp);
    }

    if (mime_type == NULL)
    {
        mmi_asc_to_ucs2((S8 *) ptr, "tmp");
    }
    else
    {
        mmi_asc_to_ucs2((S8 *) ptr, mime_type->file_ext);
    }

    UCS2_STR_MALLOC_COPY(*ppath, temp);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_da_util_does_file_exist
 * DESCRIPTION
 *  check whether does a file exist
 * PARAMETERS
 *  path        [IN]
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_da_util_does_file_exist(U16 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE hd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((hd = FS_Open((PU16) path, FS_READ_ONLY)) >= 0)
    {
        FS_Close(hd);
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
* FUNCTION
*   mmi_da_create_file_dir()
* DESCRIPTION
*   create directly from a file path (resursivly)
* PARAMETERS
*   filepath      IN          file path to create, coding in UCS2
* RETURNS
*   >=0 success
*   < 0 fail
*****************************************************************************/
S32 mmi_da_util_create_file_dir(U16 *filepath, BOOL is_filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_createpath[128];
    S8 buf_filepath[(FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH];
    S32 str_len;
    S32 cmp_ret;
    S32 i;
    U16 *ptr;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_ucs2cpy((PS8) buf_filepath, (PS8) filepath);

    if(is_filepath)
    {
        ptr = mmi_da_util_get_filename((U16*)buf_filepath);
        *ptr = 0;
    }
    
    file_handle = FS_Open((U16 *) buf_filepath, FS_OPEN_DIR | FS_READ_ONLY);

    /* path already exist */
    if (file_handle >= 0)
    {
        FS_Close(file_handle);
        return file_handle;
    }
    
    /* path not exist */
    if( FS_FILE_NOT_FOUND == file_handle)
    {
        /* create directory if it is not there */
        str_len = mmi_ucs2strlen((PS8) buf_filepath);
        str_len *= ENCODING_LENGTH;

        /* skip drive. "C:\" */
        for (i = 3 * ENCODING_LENGTH; i < str_len; i += ENCODING_LENGTH)
        {
            cmp_ret = mmi_ucs2ncmp((PS8) & buf_filepath[i], (PS8) L"\\", 1);
            if (cmp_ret == 0)
            {
                mmi_ucs2ncpy((PS8) buf_createpath, (PS8) buf_filepath, i / ENCODING_LENGTH);

                /* remove '\' */
                buf_createpath[i] = buf_createpath[i + 1] = '\0';

                file_handle = FS_CreateDir((PU16) buf_createpath);

                if (file_handle < 0)
                {
                    /* error */
                    return file_handle;
                }

                /* if this is temp folder, set hidden */
                if( mmi_ucs2ncmp((S8*)buf_createpath + 3 * ENCODING_LENGTH , (S8*)FMGR_DEFAULT_FOLDER_TEMP,
                                        mmi_ucs2strlen((S8*)FMGR_DEFAULT_FOLDER_TEMP)-1) == 0)
                {
                    FS_SetAttributes((unsigned short*)buf_createpath, FS_ATTR_DIR | FS_ATTR_HIDDEN);
                }
            }
        }
    }
    
    return file_handle;
}

/*****************************************************************************
* FUNCTION
*  mmi_da_util_get_extension
* DESCRIPTION
*  get extension file name of a file path
* PARAMETERS
*  filepath   IN  The file path
* RETURNS
*  Return the pointer where the extension file name start.
*   Return NULL if the filepath do not have extension file name.
*****************************************************************************/
U16 *mmi_da_util_get_extension(U16 * filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 length, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = mmi_ucs2strlen((S8 *) filepath);

    /* search from head ... mp3.log.tmp */
    for (i = length - 1; i >= 0; i--)
    {
        if (filepath[i] == '.')
        {
            return &filepath[i + 1];
        }
        else if( filepath[i] == '\\' || filepath[i] == '/' )
        {
            return NULL;
        }
    }
    return NULL;
}

/*****************************************************************************
* FUNCTION
*  mmi_da_util_get_extension
* DESCRIPTION
*  get extension file name of a file path
* PARAMETERS
*  filepath   IN  The file path
* RETURNS
*  Return the pointer where the extension file name start.
*   Return NULL if the filepath do not have extension file name.
*****************************************************************************/
S8 *mmi_da_util_get_extension_ascii(S8 * filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 length, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = strlen(filepath);

    /* search from head ... mp3.log.tmp */
    for (i = length - 1; i >= 0; i--)
    {
        if (filepath[i] == '.')
        {
            return &filepath[i + 1];
        }
        else if( filepath[i] == '\\' || filepath[i] == '/' )
        {
            return NULL;
        }
    }
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  mmi_da_get_filename
* DESCRIPTION
*  get file name of a file path
* PARAMETERS
*  filepath   IN  File path
* RETURNS
*  return the pointer where file name start
*****************************************************************************/
U16 *mmi_da_util_get_filename(U16 * filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 length, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = mmi_ucs2strlen((S8 *) filepath);

    for (i = length - 1; i >= 0; i--)
    {
        if (filepath[i] == '\\' || filepath[i] == '/')
        {
            return &filepath[i + 1];
        }
    }
    return filepath;
}

/*****************************************************************************
* FUNCTION
*  mmi_da_get_filename
* DESCRIPTION
*  get file name of a file path
* PARAMETERS
*  filepath   IN  File path
* RETURNS
*  return the pointer where file name start
*****************************************************************************/
S8 *mmi_da_util_get_filename_ascii(S8 *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 length, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = strlen(filepath);

    for (i = length - 1; i >= 0; i--)
    {
        if (filepath[i] == '\\' || filepath[i] == '/')
        {
            return &filepath[i + 1];
        }
    }
    return filepath;
}

/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
BOOL mmi_da_util_get_temp_filename(U16* pathname, U16* filename, U32 filename_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE       ffh;
    U32             seed, length;
    U16             temp[20];

    U16             retry_count = 5;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_get_time(&seed);
    srand(seed);
    length = mmi_ucs2strlen((S8*)pathname);
    ASSERT(filename_len > length + 9);  /* daxxxxx.* = 9 digits */
    
    do { 
        /* compose a random name first */
        seed = rand();
        
        kal_wsprintf(filename, "%wda%05d.*", pathname, seed % 100000); /* use last 5 digit */

        /* check if the file exist */
        ffh = FS_FindFirst(filename, 0, 0, NULL, (U16*) temp, 20);
        if(ffh == FS_FILE_NOT_FOUND || ffh == FS_NO_MORE_FILES)
        {
            filename[length + 7] = 0;
            return TRUE;
        }

        FS_FindClose(ffh);
        
    } while(retry_count--);

    return FALSE;
}

/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_da_util_get_ok_filepath(U16* filepath, U16** pfilepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16             temp[FMGR_MAX_PATH_LEN+1];
    U16             ext[FMGR_MAX_EXT_LEN*2+1];
    U16             *ptr;
    U16             i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(filepath || *pfilepath);
    if(filepath)
        mmi_ucs2ncpy((S8*)temp, (S8*)(filepath), FMGR_MAX_PATH_LEN);
    else if(*pfilepath)
        mmi_ucs2ncpy((S8*)temp, (S8*)(*pfilepath), FMGR_MAX_PATH_LEN);
    else
        return;

    ptr = mmi_da_util_get_extension(temp);
    if(ptr)
    {
        ptr--;
        mmi_ucs2ncpy((S8*)ext, (S8*)ptr, FMGR_MAX_EXT_LEN*2);
    }
    else
    {
        ptr = temp + mmi_ucs2strlen((S8*)temp);
        ext[0] = 0;
    }

    for(i=1;i<1000;i++)
    {
        kal_wsprintf(ptr, "(%d)%w", i, ext);
        
        if(!mmi_da_util_does_file_exist(temp))
            break;
    }
    ASSERT(i<1000); // Prevent infinite loop

    if(filepath)
    {
        mmi_ucs2cpy((S8*)(filepath), (S8*)temp);
    }
    else
    {
        UCS2_STR_MALLOC_COPY(*pfilepath, temp);
    }
}

BOOL mmi_da_util_is_valid_filename(U16 *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!mmi_fmgr_is_filename_valid((S8*)filepath))
        return FALSE;

    /* FS check */
    if( FS_GetAttributes(filepath) == FS_INVALID_FILENAME)
        return FALSE;

    return TRUE;
}

/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
U16* mmi_da_util_pathname_replace(U16* old_filepath, U16* folder, U16* filename, U16* fileext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    // TODO: big stack buffer
    U16             temp[FMGR_MAX_PATH_LEN];
    U16             *ptr, *ext;
    S8              drv;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(old_filepath && !filename && folder);
    
    drv = (S8)old_filepath[0];
    ptr = mmi_da_util_get_filename(old_filepath);
    ext = fileext ? fileext : mmi_da_util_get_extension(ptr);

    kal_wsprintf(temp, "%c:\\%w%w", drv, folder, ptr);

    ext = mmi_da_util_get_extension(temp);
    if(fileext)
    {
        if(fileext[0])
        {
            if(ext)
                mmi_ucs2cpy((S8*)ext, (S8*)fileext);
            else
            {
                kal_wsprintf(temp + mmi_ucs2strlen((S8*)temp), ".%w", fileext);
            }
        }
        else
        {
            if(ext)
                *(ext-1) = 0;
        }
    }

	ptr = NULL;
	UCS2_STR_MALLOC_COPY(ptr, temp);
	return ptr;
}

/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
U16* mmi_da_util_pathname_replace_ex(U16* old_filepath, U16* folder, U16* filename, const applib_mime_type_struct* mime_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16                         ext_buffer[FMGR_MAX_EXT_LEN+1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mime_type)
    {
        mmi_asc_n_to_ucs2((S8*)ext_buffer, mime_type->file_ext, FMGR_MAX_EXT_LEN);
        ext_buffer[FMGR_MAX_EXT_LEN] = 0;
    }
    else
    {
        ext_buffer[0] = 0;
    }
    return mmi_da_util_pathname_replace(old_filepath, folder, filename, ext_buffer);
}

/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
applib_mime_type_struct* mmi_da_util_lookup_mime_type(U8* mime_string, U16* ext,
                            applib_mime_type_enum mime_type,
                            applib_mime_subtype_enum mime_subtype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8                      ext_ascii[FMGR_MAX_EXT_LEN+1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(ext_ascii, 0, FMGR_MAX_EXT_LEN+1);
    if(ext)
    {
        mmi_ucs2_n_to_asc((S8*)ext_ascii, (S8*)ext, FMGR_MAX_EXT_LEN*2);
        return mmi_da_util_lookup_mime_type_ascii(mime_string, ext_ascii, mime_type, mime_subtype);
    }

    return mmi_da_util_lookup_mime_type_ascii(mime_string, NULL, mime_type, mime_subtype);
}

/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
applib_mime_type_struct* mmi_da_util_lookup_mime_type_ascii(U8* mime_string, S8* ext,
                            applib_mime_type_enum mime_type,
                            applib_mime_subtype_enum mime_subtype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mime_type_struct *result = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if( mime_string && ext )
        result = mime_type_look_up((kal_char *) mime_string, ext, mime_type, mime_subtype);
    if( !result )
        result = mime_type_look_up((kal_char *) mime_string, NULL, mime_type, mime_subtype);
    if( !result && ext )
        result = mime_type_look_up(NULL, ext, 0, 0);
    return result;
}

void mmi_da_extract_filepath(U16* filepath, U16* filename, U16* fileext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16     *name, *ext;
    S16     len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    name = mmi_da_util_get_filename(filepath);
    ext = mmi_da_util_get_extension(name);

    if(ext)
    {
        len = (S16)(ext - name) - 1;
        if(len > FMGR_MAX_FILE_LEN)
            len = FMGR_MAX_FILE_LEN;
        mmi_ucs2ncpy((S8*)fileext, (S8*)ext, FMGR_MAX_EXT_LEN);
    }
    else
    {
        len = FMGR_MAX_FILE_LEN;
        fileext[0] = 0;
    }

    mmi_ucs2ncpy((S8*)filename, (S8*)name, len);
}

void mmi_da_extract_filepath_ascii(S8* filepath, U16* filename, U16* fileext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8      *name, *ext;
    S16     len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    name = mmi_da_util_get_filename_ascii(filepath);
    ext = mmi_da_util_get_extension_ascii(name);

    if(ext)
    {
        len = (S16)(ext - name) - 1;
        if(len > FMGR_MAX_FILE_LEN)
            len = FMGR_MAX_FILE_LEN;
        
        mmi_asc_n_to_ucs2((S8*)fileext, (S8*)ext, FMGR_MAX_EXT_LEN);
        fileext[FMGR_MAX_EXT_LEN] = 0;
    }
    else
    {
        len = FMGR_MAX_FILE_LEN;
        fileext[0] = 0;
    }

    mmi_asc_n_to_ucs2((S8*)filename, (S8*)name, len);
    filename[len] = 0;
}


#define API_ESTIMATED

#if defined(__PS_SERVICE__)
/* 5k bytes/sec (GPRS average speed) */
#define GPRS_DL_SPEED (1024*5)
/* 12k bytes/sec (EDGE average speed) */
#define EDGE_DL_SPEED (1024*12)
#endif

/*****************************************************************************
* FUNCTION
*   mmi_da_util_get_estimated_time
* DESCRIPTION
*   calculate estimated time
* PARAMETERS
*   file_size [IN]    file size                
* RETURNS
*   U32     total seconds estimated
*****************************************************************************/
U32 mmi_da_util_get_estimated_time(U32 file_size)
{
#if defined(__PS_SERVICE__)
    U32 current_speed;
    
    if(file_size == 0)
        return 0xFFFFFFFF;

    current_speed = mmi_netset_is_cell_support_egprs() ? EDGE_DL_SPEED : GPRS_DL_SPEED;
    return file_size / current_speed;
#else
    return 0xFFFFFFFF;
#endif
}

/*****************************************************************************
* FUNCTION
*   mmi_da_util_format_estimated_time
* DESCRIPTION
*   format output string buffer according to input time
* PARAMETERS
*   buffer  [OUT]   the formated time message,
*   total_secs [IN]    time                
* RETURNS
*   void
*****************************************************************************/
void mmi_da_util_format_time(U16 *buffer, U32 total_secs)
{
    U32 mins, secs;

    if(!buffer)
        return;

    buffer[0] = 0;
    
    if(total_secs == 0xFFFFFFFF)
        return;

    if(total_secs == 0)
    {
        kal_wsprintf(buffer, "<1%w", GetString(STR_ID_DA_PROMPT_SEC));
        return;
    }
    
    mins = total_secs / 60;
    secs = total_secs % 60;

    if(mins > 99)
    {
        kal_wsprintf(buffer, ">99%w59%w", GetString(STR_ID_DA_PROMPT_MIN), GetString(STR_ID_DA_PROMPT_SEC));
        secs = 0;
    }
    else if(mins > 0)
        kal_wsprintf(buffer, "%d%w", mins, GetString(STR_ID_DA_PROMPT_MIN));

    if(mins == 0 || secs != 0)
        kal_wsprintf(buffer + mmi_ucs2strlen((S8*)buffer), "%d%w", secs, GetString(STR_ID_DA_PROMPT_SEC));
}

/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
S8 *mmi_da_util_format_size_total(U32 curr, U32 total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static S8       buffer[21];
    S8*             ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    strcpy(buffer, mmi_da_util_format_size(curr));

    if(total)
    {
        ptr = buffer + strlen(buffer);
        ptr[0] = '/';
        ptr++;
        strcpy(ptr, mmi_da_util_format_size(total));
    }
    ASSERT(strlen(buffer) < 21);
    buffer[20] = 0;        
    return buffer;
}

S8  *mmi_da_util_format_size(U32 size)
{
#if (MAIN_LCD_DEVICE_WIDTH > 128)
    #define DA_DISPLAY_UNIT 1024
#else
    #define DA_DISPLAY_UNIT 1000
#endif
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static S8       buffer[10]; /* Max display is "65536.9G", which is 8 bytes long */
    S8              unit;
    U16             remain;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(size >= DA_DISPLAY_UNIT*1024*1024)
    {
        size = size / (1024*1024);
        unit = 'G';
    }
    else if(size >= DA_DISPLAY_UNIT*1024)
    {
        size = size / 1024;
        unit = 'M';
    }
    else if(size >= DA_DISPLAY_UNIT)
    {
        unit = 'K';
    }
    else
        unit = 'B';

    if(size >= DA_DISPLAY_UNIT)
    {
        remain = (U16)((size % 1024) / 103);
        size = size / 1024;
    }
    else
        remain = 0;    

#if (MAIN_LCD_DEVICE_WIDTH > 128)
    if(remain)
#else
    if(remain && size < 100)    /* 128 width, size is limited to 3 or 2.1digits */
#endif
        sprintf(buffer, "%d.%d%c", (U16)size, (U16)remain, unit);
    else
        sprintf(buffer, "%d%c", (U16)size, unit);

    ASSERT(strlen(buffer) < 10);
    return buffer;
}

/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
U16 mmi_da_util_get_icon_from_appid(S32 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(app_id)
    {
    case APP_WAP:
        return GetRootTitleIcon(SERVICES_WAP_MENU_ID);

    case APP_MESSAGES:
        return GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID);

    default:
        return 0;
    }
}


/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
S32 mmi_da_util_get_appid_from_icon(U16 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(icon_id == GetRootTitleIcon(SERVICES_WAP_MENU_ID))
        return APP_WAP;
    if(icon_id == GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID))
        return APP_MESSAGES;

    return APP_DOWNLOADAGENT;
}

#endif

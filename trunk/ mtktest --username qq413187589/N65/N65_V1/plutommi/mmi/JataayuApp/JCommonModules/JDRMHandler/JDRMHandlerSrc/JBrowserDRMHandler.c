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
 * JBrowserDRMHandler.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is DRM handler file for Browser
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef _JBROWSERDRMHANDLER_C_
#define _JBROWSERDRMHANDLER_C_

#ifdef __DRM_SUPPORT__
#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)

#include "jBrowserDRMHandler.h"
#include "JBrowserMMITypes.h"
#include "drm_gprot.h"
#include "jdd_MessagingConfig.h"
#include "miscutils.h"

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

/***************************************************************************** 
* Global Variable
*****************************************************************************/
mmi_jbrowser_drm_context_struct g_brw_drm_cntx;

/***************************************************************************** 
* Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_jbrowser_drm_indication_handler
 * DESCRIPTION
 *  Handles the DRM indication from DRM engine.
 * PARAMETERS
 *  drm_arg_p               [IN]            Pointer to DRM argument
 *  mime_type_p             [IN]            Mime type of object
 *  st_mime_content_p       [IN]            Mime content of object
 *  response_handler_cb     [IN]            Response callback handler
 *  drm_more_content_cb     [IN]            More content callback handler
 *  app_arg_p               [IN]            Pointer to application argument
 *  drm_ref_id_p            [OUT]           DRM reference id
 *  st_drm_info_p           [IN/OUT]        Pointer to parsed DRM info
 * RETURNS
 *  Return JC_ERR_ASYNC_CALL as it is asynchronous event.
 *****************************************************************************/
JC_RETCODE mmi_jbrowser_drm_indication_handler(
            void *drm_arg_p,
            JC_INT8 *mime_type_p,
            ST_MIME_CONTENT *st_mime_content_p,
            CB_DRM_RESPONSE_HANDLER response_handler_cb,
            CB_DRM_MORE_CONTENT_HANDLER drm_more_content_cb,
            void *app_arg_p,
            JC_UINT32 *drm_ref_id_p,
            ST_DRM_PARSED_INFO *st_drm_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d) In mmi_jbrowser_drm_indication_handler()", __FILE__, __LINE__);

    g_brw_drm_cntx.drm_arg = drm_arg_p;
    g_brw_drm_cntx.drm_content = st_mime_content_p;
    g_brw_drm_cntx.drm_response_callback = response_handler_cb;
    g_brw_drm_cntx.drm_app_arg = app_arg_p;

    if (jdi_CUtilsStrStartsWith(mime_type_p, APPLICATION_VND_OMA_DRM_MESSAGE) == E_TRUE)
    {
        g_brw_drm_cntx.drm_type = DRM_TYPE_MESSAGE;
    }
    else if (jdi_CUtilsStrStartsWith(mime_type_p, APPLICATION_VND_OMA_DRM_CONTENT) == E_TRUE)
    {
        g_brw_drm_cntx.drm_type = DRM_TYPE_CONTENT;
    }

    *drm_ref_id_p = (JC_UINT32) g_brw_drm_cntx.drm_content->uData.pmFileName;
    g_brw_drm_cntx.drm_ref_id = *drm_ref_id_p;

    mmi_jbrowser_send_parse_drm_event();

    return JC_ERR_ASYNC_CALL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jbrowser_send_parse_drm_event
 * DESCRIPTION
 *  Sends the DRM parse event into queue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jbrowser_send_parse_drm_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_EVENT_DATA event_data = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jc_memset(&event_data, 0, sizeof(JC_EVENT_DATA));

    event_data.pEventInfo = NULL;
    event_data.uiEventInfoSize = 0;
    event_data.iEventType = E_BRW_PARSE_DRM_EVENT;

    event_data.destTaskInfo.iAppID = E_TASK_BROWSER_UI;
    event_data.destTaskInfo.iTaskID = E_TASK_BROWSER_UI;

    event_data.srcTaskInfo.iAppID = E_TASK_BROWSER_UI;
    event_data.srcTaskInfo.iTaskID = E_TASK_BROWSER_UI;

    jdd_QueueSend(&event_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jbrowser_parse_drm_content
 * DESCRIPTION
 *  Parses the DRM content
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jbrowser_parse_drm_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    ST_DRM_PARSED_INFO parsed_drm_info = {0};
    JC_RETCODE ret_code = JC_OK;
    JC_CHAR *drm_content_fname = NULL;
    JDD_FSHANDLE fs_handle = NULL;
    JC_CHAR *new_path = NULL;
    S32 drm_ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d) In mmi_jbrowser_parse_drm_content()", __FILE__, __LINE__);

    ret_code = jdd_FSInitialize(&fs_handle);
    if (ret_code != JC_OK)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d) File System Initialization Failure", __FILE__, __LINE__);
        goto ERROR_HANDLE;
    }

    drm_content_fname =
        (JC_CHAR*) jdd_FSFileNameTranslate(fs_handle, (JC_CHAR*) g_brw_drm_cntx.drm_content->uData.pmFileName);
    if (drm_content_fname == NULL)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d) Memory Allocation Failure", __FILE__, __LINE__);
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        jdd_FSDeinitialize(fs_handle);
        goto ERROR_HANDLE;
    }

    jdd_FSDeinitialize(fs_handle);
    fs_handle = NULL;

    parsed_drm_info.pstRightsObject = (ST_DRM_RIGHTS_OBJECT*) jdd_MemAlloc(sizeof(ST_DRM_RIGHTS_OBJECT), 1);

    if (parsed_drm_info.pstRightsObject == NULL)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d) Memory Allocation Failure", __FILE__, __LINE__);
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }

    /* Initialize parsed_drm_info with defalut values */
    parsed_drm_info.pstRightsObject->pcContentID = NULL;
    parsed_drm_info.pstRightsObject->eStatusCode = E_DRM_STATUS_OK;
    parsed_drm_info.pstRightsObject->bIsRender = FALSE;
    parsed_drm_info.pstRightsObject->bIsForwardLock = TRUE;
    parsed_drm_info.pstRightsObject->uiStartTime = 0;
    parsed_drm_info.pstRightsObject->uiDuration = 0;
    parsed_drm_info.pstRightsObject->pstNext = NULL;

    parsed_drm_info.pcContentType = NULL;

    parsed_drm_info.stMimeContent.pucHeader = NULL;
    parsed_drm_info.stMimeContent.uiHeaderLen = 0;
    parsed_drm_info.stMimeContent.bIsBinaryHeader = FALSE;
    parsed_drm_info.stMimeContent.eDataType = E_MIME_FILENAME;
    parsed_drm_info.stMimeContent.uData.pucBuffer = NULL;
    parsed_drm_info.stMimeContent.uData.pmFileName = NULL;
    parsed_drm_info.stMimeContent.uiBufferLen = 0;
    parsed_drm_info.stMimeContent.bHasMoreData = FALSE;

    new_path =
        (JC_CHAR*) jdd_MemAlloc(
                    (jc_tcslen(drm_content_fname) * ENCODING_LENGTH) + (5 * ENCODING_LENGTH) + ENCODING_LENGTH,
                    1);
    if (new_path == NULL)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d) Memory Allocation Failure", __FILE__, __LINE__);
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }

    jc_tcscpy(new_path, drm_content_fname);
    jdi_UtilsTcsStrCat(new_path, ".temp");

    if (g_brw_drm_cntx.drm_type == DRM_TYPE_MESSAGE)
    {
        drm_ret = DRM_process_virtual_file(
                    (kal_uint8*) APPLICATION_VND_OMA_DRM_MESSAGE,
                    (kal_wchar*) drm_content_fname,
                    (kal_wchar*) new_path);

        if (drm_ret == DRM_RESULT_OK)
        {
            FS_HANDLE file_handle = NULL;

            file_handle = DRM_open_file((kal_wchar*) new_path, FS_READ_ONLY, DRM_PERMISSION_NONE);
            if (file_handle <= 0)
            {
                DRM_close_file(file_handle);
                ret_code = JC_ERR_UNKNOWN;
                goto ERROR_HANDLE;
            }
            parsed_drm_info.pstRightsObject->bIsRender = TRUE;
            parsed_drm_info.pcContentType = jdi_UtilsStrdup((JC_INT8*) DRM_get_content_type(file_handle, NULL));
            if (parsed_drm_info.pcContentType == NULL)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d) Memory Allocation Failure", __FILE__, __LINE__);
                DRM_close_file(file_handle);
                ret_code = JC_ERR_MEMORY_ALLOCATION;
                goto ERROR_HANDLE;
            }
            parsed_drm_info.stMimeContent.uData.pmFileName = new_path;
            DRM_file_size(file_handle, &parsed_drm_info.stMimeContent.uiBufferLen);
            DRM_close_file(file_handle);
        }
        else
        {
            ret_code = JC_ERR_UNKNOWN;
            goto ERROR_HANDLE;
        }
    }
    else if (g_brw_drm_cntx.drm_type == DRM_TYPE_CONTENT)
    {
        drm_ret = DRM_process_virtual_file(
                    (kal_uint8*) APPLICATION_VND_OMA_DRM_CONTENT,
                    (kal_wchar*) drm_content_fname,
                    (kal_wchar*) new_path);
        if (new_path != NULL)
        {
            jdd_MemFree(new_path);
            new_path = NULL;
        }
    }
    else
    {
        ret_code = JC_ERR_UNKNOWN;
        goto ERROR_HANDLE;
    }

  ERROR_HANDLE:
    if (drm_content_fname != NULL)
    {
        jdd_MemFree(drm_content_fname);
        drm_content_fname = NULL;
    }
    if (ret_code != JC_OK)
    {
        if (new_path != NULL)
        {
            jdd_MemFree(new_path);
            new_path = NULL;
        }
    }

    (g_brw_drm_cntx.drm_response_callback) (g_brw_drm_cntx.drm_app_arg, g_brw_drm_cntx.drm_ref_id, &parsed_drm_info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jbrowser_drm_rights_update_handler
 * DESCRIPTION
 *  Updates the DRM rights
 * PARAMETERS
 *  drm_ref_id              [IN]            DRM reference id
 *  st_rights_object_p      [IN/OUT]        Pointer to rights object
 *  is_rendered             [IN]            Flag to determine rendering state
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jbrowser_drm_rights_update_handler(
        JC_UINT32 drm_ref_id,
        ST_DRM_RIGHTS_OBJECT *st_rights_object_p,
        JC_BOOLEAN is_rendered)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jbrowser_drm_more_content_handler
 * DESCRIPTION
 *  Parses the DRM content in case of aynchronous parsing
 * PARAMETERS
 *  app_arg_p           [IN]        Pointer to application argument
 *  drm_ref_id          [IN]        DRM reference id
 *  buffer_p            [IN]        Pointer to DRM object buffer
 *  buffer_length       [IN]        Buffer length of DRM object
 *  is_more_data        [IN]        Flag to tell if it has more data or not
 * RETURNS
 *  Return JC_OK in case of success; otherwise, proper error code.
 *****************************************************************************/
JC_RETCODE mmi_jbrowser_drm_more_content_handler(
            void *app_arg_p,
            JC_UINT32 drm_ref_id,
            JC_UINT8 *buffer_p,
            JC_UINT32 buffer_length,
            JC_BOOLEAN is_more_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return JC_OK;
}

#endif /* defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT) */ 
#endif /* __DRM_SUPPORT__ */ 
#endif /* _JBROWSERDRMHANDLER_C_ */ 


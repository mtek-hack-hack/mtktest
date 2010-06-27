/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  JMMSDRMHandler.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This is DRM handler file for MMS
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _JMMSDRMHANDLER_C
#define _JMMSDRMHANDLER_C

/***************************************************************************** 
* Include
*****************************************************************************/
#ifdef __DRM_SUPPORT__
#if defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT)

#include "JMMSDRMHandler.h"


#include "drm_gprot.h"
#include "miscutils.h"
#include "JMMSCompose.h"
#include "JMMSGprot.h"
#include "jdi_MMSErr.h"
#include "jdd_MessagingConfig.h"
#include "app_mine.h"

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

/***************************************************************************** 
* Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_drm_indication_handler
 * DESCRIPTION
 *  This function handles the indication for DRM content.
 * PARAMETERS
 *  msg_handle              [IN]        Message handle
 *  app_cb_arg_p            [IN]        Application callback argument
 *  drm_content_p           [IN]        Pointer to DRM content
 *  content_type_p          [IN]        Content type
 *  ref_id_p                [OUT]       Reference id
 *  st_drm_info_p           [OUT]       DRM info state
 *  drm_ind_response_cb     [IN]        Response callback
 * RETURNS
 *  Return JC_OK in case of success; otherwise, proper error code.
 *****************************************************************************/
JC_RETCODE mmi_jmms_drm_indication_handler(
            MSG_HANDLE msg_handle,
            void *app_cb_arg_p,
            CONTENT_DATA *drm_content_p,
            JC_INT8 *content_type_p,
            JC_INT8 **ref_id_p,
            ST_DRM_INFO **st_drm_info_p,
            DRM_IND_RESPONSE_CB drm_ind_response_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    ST_DRM_INFO *drm_info_p = NULL;
    MESSAGING_HANDLER *msg_handle_p = (MESSAGING_HANDLER*) msg_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d) In mmi_jmms_drm_indication_handler()", __FILE__, __LINE__);
    if (drm_content_p != NULL && content_type_p != NULL)
    {   /* content not-parsed. Parse and return rights */
        ret_code = mmi_jmms_drm_parse_content(drm_content_p, content_type_p, msg_handle_p->mms_file_handle, &drm_info_p);
        *st_drm_info_p = drm_info_p;
        *ref_id_p = jdi_UtilsStrdup((const JC_INT8*)drm_content_p->pFileName);
        if (ret_code != JC_OK)
        {
            goto ERROR_HANDLE;
        }
    }
    else
    {
        ret_code = JC_ERR_UNKNOWN;
        goto ERROR_HANDLE;
    }
  ERROR_HANDLE:
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_drm_rights_update_handler
 * DESCRIPTION
 *  This function handles the updation of DRM rights.
 * PARAMETERS
 *  msg_handle          [IN]        Message handle
 *  app_cb_arg_p        [IN]        Application callback argument
 *  ref_id_p            [OUT]       Reference id
 *  is_render           [IN]        Rendering flag
 * RETURNS
 *  Return JC_OK in case of success; otherwise, proper error code.
 *****************************************************************************/
JC_RETCODE mmi_jmms_drm_rights_update_handler(
            MSG_HANDLE msg_handle,
            void *app_cb_arg_p,
            JC_INT8 *ref_id_p,
            JC_BOOLEAN is_render)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "In mmi_jmms_drm_rights_update_handler()");
    return JC_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_drm_info_list_ind_handler
 * DESCRIPTION
 *  Callback Function to handle DRM Info List.
 * PARAMETERS
 *  msg_handle          [IN]        Message handle
 *  callback_arg        [IN]        Callback argument
 *  drm_info_list_p     [IN]        Pointer to DRM media list
 * RETURNS
 *  Return JC_OK in case of success; otherwise, proper error code.
 *****************************************************************************/
JC_RETCODE mmi_jmms_drm_info_list_ind_handler(
            MSG_HANDLE msg_handle,
            void *callback_arg,
            DRM_MEDIA_LIST *drm_info_list_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "In mmi_jmms_drm_info_list_ind_handler()");
    return JC_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_drm_cancel_parse_handler
 * DESCRIPTION
 *  Cancels the parsing of DRM content.
 * PARAMETERS
 *  msg_handle          [IN]        Message handle
 *  app_cb_arg_p        [IN]        Application callback argument
 * RETURNS
 *  Return JC_OK in case of success; otherwise, proper error code.
 *****************************************************************************/
JC_RETCODE mmi_jmms_drm_cancel_parse_handler(MSG_HANDLE msg_handle, void *app_cb_arg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "In mmi_jmms_drm_cancel_parse_handler()");
    return JC_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_drm_compose_handler
 * DESCRIPTION
 *  This function is the handler for composing a DRM media object.
 * PARAMETERS
 *  msg_handle          [IN]        Message handle
 *  app_cb_arg_p        [IN]        Application callback argument
 *  media_mime_p        [IN]        Pointer to media mime info
 *  drm_mime_p          [OUT]       Pointer to DRM media mime info
 * RETURNS
 *  Return JC_OK in case of success; otherwise, proper error code.
 *****************************************************************************/
JC_RETCODE mmi_jmms_drm_compose_handler(
            MSG_HANDLE msg_handle,
            void *app_cb_arg_p,
            MEDIA_MIME_INFO *media_mime_p,
            MEDIA_MIME_INFO **drm_mime_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    MEDIA_MIME_INFO *drm_mime_info = NULL;
    JC_CHAR *dst_file_name = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "In mmi_jmms_drm_compose_handler()");
    drm_mime_info = (MEDIA_MIME_INFO*) jdd_MemAlloc(sizeof(MEDIA_MIME_INFO), 1);
    *drm_mime_p = drm_mime_info;

    if (drm_mime_info == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto error_handle;
    }

    drm_mime_info->MimeHeaders.pContentType = jdi_UtilsStrdup(APPLICATION_VND_OMA_DRM_MESSAGE);
    if (drm_mime_info->MimeHeaders.pContentType == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto error_handle;
    }

    drm_mime_info->MimeHeaders.pObjectName =
        (JC_CHAR*) jdi_UtilsTcsDup((const JC_CHAR*)media_mime_p->MimeHeaders.pObjectName);
    if (drm_mime_info->MimeHeaders.pObjectName == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto error_handle;
    }

    drm_mime_info->MimeHeaders.pContentID = jdi_UtilsStrdup(media_mime_p->MimeHeaders.pContentID);
    if (drm_mime_info->MimeHeaders.pContentID == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto error_handle;
    }

    dst_file_name = jdd_MemAlloc(
                        (jc_tcslen(media_mime_p->ContentData.pStream) + jc_strlen(DRM_COMPOSE_IDENTIFIER) + jc_strlen(media_mime_p->MimeHeaders.pContentType) + 1) * ENCODING_LENGTH,
                        1);
    if (dst_file_name == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto error_handle;
    }

    jc_tcscpy(dst_file_name, media_mime_p->ContentData.pStream);
    jdi_UtilsTcsStrCat(dst_file_name, DRM_COMPOSE_IDENTIFIER);
    jdi_UtilsTcsStrCat(dst_file_name, media_mime_p->MimeHeaders.pContentType);

    drm_mime_info->MimeHeaders.bIsAttachment = media_mime_p->MimeHeaders.bIsAttachment;
    drm_mime_info->MimeHeaders.pOtherHeaders = NULL;
    drm_mime_info->ContentData.uiTotalSize =
        (media_mime_p->ContentData.uiTotalSize +
         jc_strlen(DRM_HEADER_BOUNDARY) +
         jc_strlen(DRM_HEADER_MIME_TYPE) +
         jc_strlen(media_mime_p->MimeHeaders.pContentType) + jc_strlen(DRM_HEADER_ENCODING) + jc_strlen(DRM_FOOTER));

    drm_mime_info->ContentData.uiCurSize = 0;
    drm_mime_info->ContentData.bIsStream = E_TRUE;
    drm_mime_info->ContentData.pBuffer = NULL;
    drm_mime_info->ContentData.eCopyMemory = E_FALSE;
    drm_mime_info->ContentData.pStream = dst_file_name;
    drm_mime_info->ContentData.pFileName = dst_file_name;
    drm_mime_info->ContentData.uiStartOffset = 0;
    drm_mime_info->ContentData.virtualMediaOffset = 0;
    drm_mime_info->ContentData.cbReadCallback = mmi_jmms_drm_encapsulate_callback;
    drm_mime_info->ContentData.cbWriteCallback = NULL;

    drm_mime_info->pDRMInfo = NULL;

    return JC_OK;

  error_handle:

    if (drm_mime_info->MimeHeaders.pContentType)
    {
        jdd_MemFree(drm_mime_info->MimeHeaders.pContentType);
    }
    if (drm_mime_info->MimeHeaders.pObjectName)
    {
        jdd_MemFree(drm_mime_info->MimeHeaders.pObjectName);
    }
    if (drm_mime_info->MimeHeaders.pContentID)
    {
        jdd_MemFree(drm_mime_info->MimeHeaders.pContentID);
    }
    if (dst_file_name)
    {
        jdd_MemFree(dst_file_name);
    }
    if (drm_mime_info)
    {
        jdd_MemFree(drm_mime_info);
    }

    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_drm_parse_content
 * DESCRIPTION
 *  This function is used for parsing the DRM content
 * PARAMETERS
 *  content_data_p      [IN]        Pointer to content data
 *  content_type_p      [IN]        Content type of media
 *  mms_file_handle     [IN]        File handle
 *  drm_info_p          [OUT]       Pointer to DRM media info
 * RETURNS
 *  Return JC_OK in case of successful parsing; otherwise, proper error code
 *****************************************************************************/
JC_RETCODE mmi_jmms_drm_parse_content(
            CONTENT_DATA *content_data_p,
            JC_INT8 *content_type_p,
            JDD_FILE mms_file_handle,
            ST_DRM_INFO **drm_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    S32 drm_ret = 0;
    JC_CHAR *new_path = NULL;
    JC_CHAR *temp_path = NULL;
    ST_DRM_INFO *drm_info = NULL;
    U32 content_length = 0;
    JC_CHAR *file_name_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "In mmi_jmms_drm_parse_content()");

    if (jdi_CUtilsStrStartsWith(content_type_p, APPLICATION_VND_OMA_DRM_MESSAGE) == E_TRUE)
    {
        jdd_FSGetDownloadFileName(&temp_path);
        if (temp_path == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto ERROR_HANDLE;
        }

        new_path = jdd_MemAlloc((jc_tcslen(temp_path) * ENCODING_LENGTH) + (5 * ENCODING_LENGTH) + ENCODING_LENGTH, 1);
        if (new_path == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto ERROR_HANDLE;
        }

        jc_tcscpy(new_path, temp_path);
        jdi_UtilsTcsStrCat(new_path, ".temp");

        drm_ret = DRM_process_direct_file(
                    (kal_uint8*) APPLICATION_VND_OMA_DRM_MESSAGE,
                    (kal_wchar*) content_data_p->pFileName,
                    (kal_wchar*) new_path,
                    &content_length);
    }
    else if (jdi_CUtilsStrStartsWith(content_type_p, APPLICATION_VND_OMA_DRM_CONTENT) == E_TRUE)
    {
        new_path = jdd_MemAlloc(
                    (jc_tcslen(content_data_p->pFileName) * ENCODING_LENGTH) + (5 * ENCODING_LENGTH) + ENCODING_LENGTH,
                    1);
        if (new_path == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto ERROR_HANDLE;
        }

        jc_tcscpy(new_path, content_data_p->pFileName);
        jdi_UtilsTcsStrCat(new_path, ".temp");

        DRM_process_virtual_file(
            (kal_uint8*) APPLICATION_VND_OMA_DRM_CONTENT,
            (kal_wchar*) content_data_p->pFileName,
            (kal_wchar*) new_path);
        drm_ret = DRM_RESULT_OK;
    }
#ifdef __DRM_ODF_SUPPORT__
    else if (jdi_CUtilsStrStartsWith(content_type_p, APPLICATION_VND_OMA_DRM_CONTENT_V2) == E_TRUE)
    {
        drm_ret = DRM_RESULT_OK;
    }
#endif /* __DRM_ODF_SUPPORT__ */ 
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Not a DRM content-type");
        ASSERT(0);
    }

    /* Fill ST_DRM_INFO struct to return to core */
    drm_info = (ST_DRM_INFO*) jdd_MemAlloc(sizeof(ST_DRM_INFO), 1);
    *drm_info_p = drm_info;

    if (drm_info == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }

    /* Fill ST_RIGHTS_OBJECT in ST_DRM_INFO */
    drm_info->pstRightsObject = (ST_RIGHTS_OBJECT*) jdd_MemAlloc(sizeof(ST_RIGHTS_OBJECT), 1);
    if (drm_info->pstRightsObject == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }

    drm_info->pstRightsObject->pContentId = NULL;
    drm_info->pstRightsObject->bIsRender = E_FALSE;
    drm_info->pstRightsObject->eErrorCode = 0;
    drm_info->pstRightsObject->eDRMType = E_DRM_NONE;
    drm_info->pstRightsObject->pNext = NULL;

    drm_info->MimeHeaders.pContentType = NULL;
    drm_info->MimeHeaders.pObjectName = NULL;
    drm_info->MimeHeaders.pContentID = NULL;
    drm_info->MimeHeaders.bIsAttachment = E_FALSE;
    drm_info->MimeHeaders.pOtherHeaders = NULL;

    drm_info->ContentData.uiTotalSize = 0;
    drm_info->ContentData.uiCurSize = 0;
    drm_info->ContentData.bIsStream = E_FALSE;
    drm_info->ContentData.pBuffer = NULL;
    drm_info->ContentData.eCopyMemory = E_FALSE;
    drm_info->ContentData.pStream = NULL;
    drm_info->ContentData.pFileName = NULL;
    drm_info->ContentData.uiStartOffset = 0;
    drm_info->ContentData.virtualMediaOffset = 0;
    drm_info->ContentData.cbReadCallback = mmi_jmms_read_callback;
    drm_info->ContentData.cbWriteCallback = NULL;

    if (jdi_CUtilsStrStartsWith(content_type_p, APPLICATION_VND_OMA_DRM_MESSAGE) == E_TRUE)
    {
        drm_info->MimeHeaders.pContentType =
            (JC_INT8*) mmi_mms_get_mms_content_type_file((JC_CHAR*) new_path, E_MEDIA_OTHERS);
        if (drm_info->MimeHeaders.pContentType == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto ERROR_HANDLE;
        }

        if (drm_ret >= DRM_RESULT_OK)
        {
            drm_info->pstRightsObject->bIsRender = E_TRUE;
            drm_info->ContentData.uiTotalSize = content_length;
            drm_info->ContentData.uiCurSize = content_length;
            drm_info->ContentData.bIsStream = E_TRUE;
            drm_info->ContentData.pStream = new_path;
            drm_info->ContentData.pFileName = new_path;
        }
        else
        {
            drm_info->pstRightsObject->bIsRender = E_FALSE;
            drm_info->pstRightsObject->eErrorCode = E_DRM_ERR_RIGHT_COUNT_EXCEEDED;
            drm_info->pstRightsObject->eDRMType = E_DRM_FWD_LOCK;
        }
    }
    else if (jdi_CUtilsStrStartsWith(content_type_p, APPLICATION_VND_OMA_DRM_CONTENT) == E_TRUE)
    {
        drm_info->MimeHeaders.pContentType =
            (JC_INT8*) mmi_mms_get_mms_content_type_file((JC_CHAR*) new_path, E_MEDIA_OTHERS);
        if (drm_info->MimeHeaders.pContentType == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto ERROR_HANDLE;
        }

        if (DRM_RESULT_OK == drm_ret)
        {
            if (E_TRUE == mmi_jmms_check_drm_rights(new_path))
            {
                drm_info->pstRightsObject->bIsRender = E_TRUE;
            }
            else
            {
                drm_info->pstRightsObject->bIsRender = E_FALSE;
                drm_info->pstRightsObject->eErrorCode = E_DRM_ERR_RIGHT_COUNT_EXCEEDED;
                drm_info->pstRightsObject->eDRMType = E_DRM_SEPARATE_DELIVERY;
            }
            file_name_p = jdi_UtilsTcsDup(new_path);
            if (file_name_p == NULL)
            {
                ret_code = JC_ERR_MEMORY_ALLOCATION;
                goto ERROR_HANDLE;
            }
            drm_info->ContentData.uiTotalSize = 50;
            drm_info->ContentData.uiCurSize = 50;
            drm_info->ContentData.bIsStream = E_TRUE;
            drm_info->ContentData.pStream = file_name_p;
            drm_info->ContentData.pFileName = file_name_p;
        }
        else
        {
            drm_info->pstRightsObject->bIsRender = E_FALSE;
            drm_info->pstRightsObject->eErrorCode = E_DRM_ERR_RIGHT_COUNT_EXCEEDED;
            drm_info->pstRightsObject->eDRMType = E_DRM_SEPARATE_DELIVERY;
        }

        if (new_path != NULL)
        {
            jdd_MemFree(new_path);
            new_path = NULL;
        }
    }
#ifdef __DRM_ODF_SUPPORT__
    else if (jdi_CUtilsStrStartsWith(content_type_p, APPLICATION_VND_OMA_DRM_CONTENT_V2) == E_TRUE)
    {
        JC_CHAR *file_name = NULL;

        if (mmi_jmms_drm_is_multi_part_odf_content(content_data_p->pFileName) == E_TRUE)
        {
            drm_info->MimeHeaders.pContentType =
                (JC_INT8*) mmi_mms_get_mms_content_type_file((JC_CHAR*) content_data_p->pFileName, E_MEDIA_OTHERS);
        }
        else
        {
            JC_INT8 *file_ext = NULL;
            S8 content_type[32] = {0};

            file_ext = mmi_jmms_drm_odf_get_content_ext(content_data_p->pFileName);
            jc_snprintf(content_type, (sizeof(content_type) - 1), "A.%s", file_ext);
            jdi_UtilsCharToTchar((JC_CHAR **) & file_name, content_type);
            drm_info->MimeHeaders.pContentType =
                (JC_INT8*) mmi_mms_get_mms_content_type_file((JC_CHAR*) file_name, E_MEDIA_OTHERS);

        }
        if (drm_info->MimeHeaders.pContentType == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto ERROR_HANDLE;
        }

        if (DRM_RESULT_OK == drm_ret)
        {
            if (E_TRUE == mmi_jmms_check_drm_rights(content_data_p->pFileName))
            {
                drm_info->pstRightsObject->bIsRender = E_TRUE;
            }
            else
            {
                drm_info->pstRightsObject->bIsRender = E_FALSE;
                drm_info->pstRightsObject->eErrorCode = E_DRM_ERR_RIGHT_COUNT_EXCEEDED;
                drm_info->pstRightsObject->eDRMType = E_DRM_SEPARATE_DELIVERY;
            }
            file_name_p = jdi_UtilsTcsDup(content_data_p->pFileName);
            if (file_name_p == NULL)
            {
                ret_code = JC_ERR_MEMORY_ALLOCATION;
                goto ERROR_HANDLE;
            }
            drm_info->ContentData.uiTotalSize = 50;
            drm_info->ContentData.uiCurSize = 50;
            drm_info->ContentData.bIsStream = E_TRUE;
            drm_info->ContentData.pStream = file_name_p;
            drm_info->ContentData.pFileName = file_name_p;
        }
        if (file_name != NULL)
        {
            jdd_MemFree(file_name);
        }
    }
#endif /* __DRM_ODF_SUPPORT__ */ 
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Not a DRM content-type");
        ASSERT(0);
    }

  ERROR_HANDLE:
    if (ret_code != NULL)
    {
        if (new_path != NULL)
        {
            jdd_MemFree(new_path);
        }
        if (file_name_p != NULL)
        {
            jdd_MemFree(file_name_p);
        }
    }
    return ret_code;
}

/* vishal start */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_drm_method_type
 * DESCRIPTION
 *  This function get the drm method type from file path
 * PARAMETERS
 *  filePath        [IN]        Filepath of media
 * RETURNS
 *  Return the method type of the DRM content
 *****************************************************************************/
drm_method_enum mmi_jmms_get_drm_method_type(JC_CHAR *filePath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d) In mmi_jmms_get_drm_method_type()", __FILE__, __LINE__);
    return (DRM_get_object_method(NULL, (kal_wchar*) filePath));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_check_drm_rights
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filePath        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
JC_BOOLEAN mmi_jmms_check_drm_rights(JC_CHAR *filePath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle = NULL;
    JC_BOOLEAN is_permitted = E_FALSE;
    applib_mime_type_struct *mime_info = NULL;
    U8 permission = DRM_PERMISSION_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d) In mmi_jmms_check_drm_rights()", __FILE__, __LINE__);
    mime_info = mime_get_file_type(filePath);

#ifdef __DRM_ODF_SUPPORT__
    if ((mime_info != NULL)
        && (jdi_UtilsStrStartsWith(mime_info->mime_string, APPLICATION_VND_OMA_DRM_CONTENT_V2) == E_TRUE)
        && (mmi_jmms_drm_is_multi_part_odf_content(filePath) == E_FALSE))
    {
        JC_INT8 *file_ext = NULL;

        file_ext = mmi_jmms_drm_odf_get_content_ext(filePath);
        mime_info = mime_type_look_up(NULL, file_ext, NULL, NULL);
    }
#endif /* __DRM_ODF_SUPPORT__ */ 

    if (mime_info != NULL)
    {
        if (jdi_UtilsStrStartsWith(mime_info->mime_string, "image/"))
        {
            permission = DRM_PERMISSION_DISPLAY;
        }
        else if (jdi_UtilsStrStartsWith(mime_info->mime_string, "audio/"))
        {
            permission = DRM_PERMISSION_PLAY;
        }
        else if (jdi_UtilsStrStartsWith(mime_info->mime_string, "video/"))
        {
            permission = DRM_PERMISSION_PLAY;
        }
        else
        {
            return E_TRUE;
        }
    }

    if ((file_handle = DRM_open_file((PU16) filePath, FS_READ_ONLY, permission)) >= FS_NO_ERROR)
    {
        if (DRM_validate_permission(file_handle, NULL, permission))
        {
            is_permitted = E_TRUE;
        }
        DRM_close_file(file_handle);
    }
    else if (file_handle < -1)  /* file open error but not DRM related problem */
    {
        is_permitted = E_TRUE;
    }

    return is_permitted;
}

/* vishal end */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_process_drm_object
 * DESCRIPTION
 *  This is used for determining whether the file is DRM forwardable or not
 * PARAMETERS
 *  filePath                [IN]        File path of media
 *  permission              [IN]        Permission in which file to be opened
 *  can_fwd                 [OUT]       Flag which tell whether the media can be forwarded
 *  is_drm_permitted        [IN]        Flag which tell whether media is drm permitted
 * RETURNS
 *  Return E_TRUE if the content is DRM object, otherwise E_FALSE.
 *****************************************************************************/
JC_BOOLEAN mmi_jmms_process_drm_object(
            JC_CHAR *filePath,
            JC_UINT8 permission,
            JC_BOOLEAN *can_fwd,
            JC_BOOLEAN *is_drm_permitted)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle = NULL;
    JC_BOOLEAN is_drm_file = E_FALSE;
    U8 method = DRM_METHOD_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *can_fwd = E_TRUE;
    *is_drm_permitted = E_FALSE;

    file_handle = DRM_open_file((PU16) filePath, FS_READ_ONLY, permission);
    if (file_handle >= FS_NO_ERROR)
    {
        if ((method = DRM_get_object_method(file_handle, NULL)) != DRM_METHOD_NONE)
        {
            is_drm_file = E_TRUE;

            if ((method & DRM_METHOD_SEPARATE_DELIVERY) || (method & DRM_METHOD_V2))
            {
                if (DRM_validate_permission(file_handle, NULL, permission))
                {
                    *is_drm_permitted = E_TRUE;
                }
                *can_fwd = E_TRUE;
            }
            else
            {
                *can_fwd = E_FALSE;
            }
        }
        else
        {
            /* non DRM file, can forward to anywhere */
            *can_fwd = E_TRUE;
            is_drm_file = E_FALSE;
        }
        DRM_close_file(file_handle);
    }
    else
    {
        *can_fwd = E_FALSE;
        /* CD or FL without right */
        if (file_handle == DRM_RESULT_NO_PERMISSION)
        {
            is_drm_file = E_TRUE;
        }
        else
        {
            is_drm_file = E_FALSE;
        }
    }
    return is_drm_file;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_is_media_drm_permitted
 * DESCRIPTION
 *  This function determines whether the file has DRM permission or not.
 * PARAMETERS
 *  file_path       [IN]        Path of DRM file
 *  permission      [IN]        Permission
 * RETURNS
 *  Return E_TRUE if the media is DRM permitted, otherwise E_FALSE.
 *****************************************************************************/
JC_BOOLEAN mmi_jmms_is_media_drm_permitted(JC_CHAR *file_path, JC_UINT8 permission)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle = 0;
    JC_BOOLEAN is_permitted = E_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d) In mmi_jmms_is_media_drm_permitted()", __FILE__, __LINE__);

    if ((file_handle = DRM_open_file((PU16) file_path, FS_READ_ONLY, permission)) >= FS_NO_ERROR)
    {
        if (DRM_validate_permission(file_handle, NULL, permission))
        {
            is_permitted = E_TRUE;
        }
        DRM_close_file(file_handle);
    }
    else if (file_handle < -1)  /* file open error but not DRM related problem */
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "DRM_open_file() Failed: %d", file_handle);
        is_permitted = E_TRUE;
    }

    return is_permitted;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_drm_encapsulate_callback
 * DESCRIPTION
 *  This function is used for encapsulating a media file into DRM media file.
 * PARAMETERS
 *  stream_p        [IN]        Media object as buffer
 *  offset          [IN]        Offset
 *  ui_size         [IN]        Size of buffer
 *  buffer_p        [OUT]       Buffer containing DRM media object
 *  size_read_p     [OUT]       Actual buffer size of DRM media object
 * RETURNS
 *  Return JC_OK in case of success; otherwise, proper error code.
 *****************************************************************************/
JC_RETCODE mmi_jmms_drm_encapsulate_callback(
            void *stream_p,
            JC_INT32 offset,
            JC_UINT32 ui_size,
            JC_UINT8 *buffer_p,
            JC_UINT32 *size_read_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    JDD_FSHANDLE fs_handle = NULL;
    JDD_FILE file_handle = NULL;
    JC_UINT32 drm_header_len = 0;
    JC_UINT32 drm_footer_len = 0;
    JC_INT32 index = 0;
    JC_CHAR *stream_temp_p = NULL;
    JC_CHAR *content_type_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "In mmi_jmms_drm_encapsulate_callback()");
    if (stream_p == NULL || buffer_p == NULL)
    {
        ret_code = JC_ERR_INVALID_PARAMETER;
        goto error;
    }

    memset(buffer_p, 0, ui_size);
    drm_footer_len = jc_strlen(DRM_FOOTER);

    if (ui_size <= drm_footer_len)
    {
        JC_UINT8 *tmp_str = (JC_UINT8*) DRM_FOOTER;

        memcpy(buffer_p, tmp_str + (drm_footer_len - ui_size), ui_size);
        *size_read_p = ui_size;
        goto error;
    }

    if (jdd_FSInitialize(&fs_handle) != JC_OK)
    {
        ret_code = JC_ERR_FILE_OPEN;
        goto error;
    }

    index = jdi_UtilsIndexOfSubStringChar(stream_p, DRM_COMPOSE_IDENTIFIER, 0);

    if (index > -1)
    {
        stream_temp_p = jdd_MemAlloc((index * ENCODING_LENGTH) + ENCODING_LENGTH, 1);
        if (stream_temp_p == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto error;
        }
        memcpy(stream_temp_p, stream_p, index * ENCODING_LENGTH);
    }

    content_type_p = jdi_UtilsTcsCopyIndexNum(
                        stream_p,
                        (index + jc_strlen(DRM_COMPOSE_IDENTIFIER)),
                        (jc_tcslen(stream_p) - jc_strlen(DRM_COMPOSE_IDENTIFIER) - index));
    if (content_type_p == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto error;
    }

    drm_header_len = jc_strlen(DRM_HEADER_BOUNDARY) + jc_strlen(DRM_HEADER_MIME_TYPE) + jc_tcslen(content_type_p) +
        jc_strlen(DRM_HEADER_ENCODING);

    if (offset == 0)
    {
        jc_strcpy(buffer_p, DRM_HEADER_BOUNDARY);
        jc_strcat(buffer_p, DRM_HEADER_MIME_TYPE);
        jdi_UtilsStrTcsCat((JC_INT8*) buffer_p, content_type_p);
        jc_strcat(buffer_p, DRM_HEADER_ENCODING);
    }

    file_handle = jdd_FSOpen(fs_handle, (JC_CHAR*) stream_temp_p, E_OPEN_READ_MODE);

    if (file_handle == NULL)
    {
        ret_code = JC_ERR_FILE_OPEN;
        goto error;
    }

    if (offset > 0)
    {
        ret_code = jdd_FSSeek(file_handle, offset - drm_header_len, E_FILE_SEEK_SET);
        if (ret_code != JC_OK)
        {
            goto error;
        }
    }

    if (offset == 0)
    {
        *size_read_p = jdd_FSRead((buffer_p + drm_header_len), sizeof(JC_INT8), ui_size - drm_header_len, file_handle);
        *size_read_p += drm_header_len;
    }
    else
    {
        *size_read_p = jdd_FSRead(buffer_p, sizeof(JC_INT8), ui_size, file_handle);
    }

    if (*size_read_p != ui_size)
    {
        if ((ui_size - *size_read_p) == drm_footer_len)
        {
            memcpy(buffer_p + (*size_read_p), DRM_FOOTER, drm_footer_len);
            *size_read_p += drm_footer_len;
        }
        else if ((ui_size - *size_read_p) < drm_footer_len)
        {
            memcpy(buffer_p + (*size_read_p), DRM_FOOTER, (ui_size - *size_read_p));
            *size_read_p += (ui_size - *size_read_p);
        }
        else
        {
            ret_code = JC_ERR_FILE_READ;
        }
    }

  error:
    if (file_handle != NULL)
    {
        jdd_FSClose(file_handle);
    }
    if (fs_handle != NULL)
    {
        jdd_FSDeinitialize(fs_handle);
        fs_handle = NULL;
    }
    if (stream_temp_p)
    {
        jdd_MemFree(stream_temp_p);
    }
    if (content_type_p)
    {
        jdd_MemFree(content_type_p);
    }

    return ret_code;
}

#ifdef __DRM_ODF_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_drm_is_multi_part_odf_content
 * DESCRIPTION
 *  This function determines whether the file is a multipart odf or not.
 * PARAMETERS
 *  file_path       [IN]        Path of DRM file
 * RETURNS
 *  Return E_TRUE if the media is DRM permitted, otherwise E_FALSE.
 *****************************************************************************/
JC_BOOLEAN mmi_jmms_drm_is_multi_part_odf_content(JC_CHAR *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (DRM_is_archive(NULL, file_path))
    {
        return E_TRUE;
    }
    return E_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_drm_odf_get_content_ext
 * DESCRIPTION
 *  This function finds the content type of actual media inside the
 *  single part odf file.
 * PARAMETERS
 *  file_path       [IN]        Path of DRM file
 * RETURNS
 *  Returns content type of actual media.
 *****************************************************************************/
kal_char *mmi_jmms_drm_odf_get_content_ext(JC_CHAR *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return DRM_get_content_ext(NULL, file_path);
}

#endif /* __DRM_ODF_SUPPORT__ */ 

#endif /* defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT) */ 
#endif /* __DRM_SUPPORT__ */ /* #ifdef __DRM_SUPPORT__ */
#endif /* _JMMSDRMHANDLER_C */ 


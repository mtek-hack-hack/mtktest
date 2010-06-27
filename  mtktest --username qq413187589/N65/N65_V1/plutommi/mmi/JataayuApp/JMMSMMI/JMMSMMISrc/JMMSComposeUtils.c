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
 * JMMSComposeUtils.C
 *
 * Project:
 * --------
 *   MAUI
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT))

/*  Include: MMI header file */
#include "JMMSConfig.h"
#include "JMMSCompose.h"
#include "JMMSResDef.h"
#include "JMMSWriteMMS.h"
#include "JMMSExdcl.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "MessagesResourceData.h"
#include "FileManagerDef.h"
#include "FileManagerGProt.h"
#include "FileMgr.h"
#include "jdd_memapi.h"
/* jataayu files */
#include "ddl.h"
#include "jcal.h"
#include "messagingdatatypes.h"
#include "JMMSCoreAPI.h"
#include "JMMSMainMMS.h"
#include "JMMSView.h"
#include "ddlbase.h"
#include "JMMSExdcl.h"
#include "jcutils.h"
#include "ddlutils.h"
#include "jdi_MMSErr.h"
#include "jcerror.h"
#include "miscutils.h"
#include "JMMSMessageSettingsUtils.h"
// #include "jdi_miscutils.h"
#include "JMMSGprot.h"
#include "jdd_MessagingConfig.h"
#include "JMMSView.h"

#include "JMMSInbox.h"
#include "JMMSProtocols.h"
#include "PhoneBookGprot.h"
#include "prvmessagingdatatypes.h"
#include "app_mine.h"
#include "jdd_fileapi.h"
#include "custom_wap_config.h"
#ifdef __DRM_SUPPORT__
#include "JMMSDRMHandler.h"
#endif 

#include "mdi_datatype.h"       /* dependent headers for AudioPlayerProt.h" */
#if defined(__MMI_AUDIO_PLAYER__)
#include "AudioPlayerProt.h"
#include "mdi_audio.h"
#endif /* defined(__MMI_AUDIO_PLAYER__) */ 
#ifdef __MMI_VIDEO_PLAYER__
#include "mdi_video.h"
#include "jdd_videoapi.h"
#endif /* __MMI_VIDEO_PLAYER__ */ 

#include "SATDefs.h"

#ifdef __DRM_SUPPORT__
#include "DRM_gprot.h"
#endif 

#include "wapadp.h"     /* compiler warning removal */
#include "med_api.h"
#include "PrvViewDataTypes.h"
#include "ViewMiscUtils.h"
#include "mdi_audio.h"
#include "JMMSCompose.h"

#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageResDef.h"
#endif /* __MMI_UNIFIED_MESSAGE__ */

/* JDD Header Files */
#include "jdd_ui_datatypes.h"
#include "jdd_ui_utils.h"
#include "app_str.h"

/*  Include: PS header file */
/* ... Add More PS header */

/***************************************************************************** 
* Define
*****************************************************************************/
#define STRING_TEXT "Text"
#define STRING_IMAGE "Image"
#define STRING_AUDIO "Audio"
#define STRING_ATTACHMENT "Attachment"
/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local static Variable
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
extern kal_wchar *mime_get_extension(kal_wchar *file_path_p);  /* compiler warning removal */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_fill_default_values_slide_settings
 * DESCRIPTION
 *  Initialization function of MMS compose.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_compose_fill_default_values_slide_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->compose_context->duration[g_jmms_context->compose_context->curr_page_index - 1].txt_dur_max_set = 1;
    g_jmms_context->compose_context->duration[g_jmms_context->compose_context->curr_page_index - 1].img_dur_max_set = 1;
    g_jmms_context->compose_context->duration[g_jmms_context->compose_context->curr_page_index - 1].audio_dur_max_set =
        1;
    g_jmms_context->compose_context->duration[g_jmms_context->compose_context->curr_page_index - 1].video_dur_max_set =
        1;

    g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.italic = 0;
    g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.bold = 0;
    g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.size = MEDIUM_FONT;
    g_jmms_context->compose_context->curr_slide_info.slide_prop.slide_time = 0;
    g_jmms_context->compose_context->curr_slide_info.slide_prop.text_color = g_jmms_color_RGB_list[COLOR_BLACK];
    g_jmms_context->compose_context->curr_slide_info.img_info.img_x = 0;
    g_jmms_context->compose_context->curr_slide_info.img_info.img_y = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_new_mms
 * DESCRIPTION
 *  function of writing a new MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
JMMS_COMP_ERRCODE mmi_jmms_compose_new_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Deepali: use setting API's */
    JC_RETCODE ret_code = JC_OK;
    JMMS_COMP_ERRCODE err_code;
    U8 config_arg = JMMS_CONFIG_PREVIEW;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_compose_new_mms");
    if (g_jmms_context->msg_handle != NULL)
    {
        ret_code = mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
    }

    if (ret_code == JC_OK)
    {
        g_jmms_context->msg_handle = NULL;
        ret_code = mmi_jmms_jdi_msg_init(&(g_jmms_context->msg_handle), (void*)config_arg);
    }
    if (ret_code == JC_ERR_MEMORY_ALLOCATION)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Fail to create msg handle");
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }

    if (ret_code == JC_OK)
    {
        ret_code = mmi_jmms_jdi_set_content_class(g_jmms_context->msg_handle, MMS_SUPPORTED_CONTENT_CLASS);
    }
    if (ret_code == JC_OK)
    {
        ret_code = mmi_jmms_jdi_set_creation_mode(g_jmms_context->msg_handle, mmi_jmms_compose_settings_creation_mode());
    }
    if (ret_code == JC_OK)
    {
        ret_code = mmi_jmms_jdi_set_msg_type(g_jmms_context->msg_handle, E_TYPE_MMS);
    }
    if (ret_code == JC_OK)
    {
        ret_code = mmi_jmms_jdi_set_presentation_type(g_jmms_context->msg_handle, E_PRESENTATION_SMIL);
    }
    if (ret_code == JC_OK)
    {
        ret_code = mmi_jmms_jdi_set_max_pages(g_jmms_context->msg_handle, (U8) mmi_jmms_compose_settings_max_no_pages());
    }
    if (ret_code == JC_OK)
    {
        ret_code = mmi_jmms_jdi_msg_register_callback(
                    g_jmms_context->msg_handle,
                    E_CB_ERROR_IND,
                    (void*)mmi_jmms_error_ind_cb);
    }

  ERROR_HANDLE:
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "Fail to create msg error= %d", ret_code);
    err_code = mmi_jmms_compose_handle_error(ret_code, 0);

    return err_code;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_error_ind_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h_msg               [IN]        
 *  callback_arg_p      [IN]        
 *  cb_struct_p         [IN]        
 *  error               [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_jmms_error_ind_cb(MSG_HANDLE h_msg, void *callback_arg_p, void *cb_struct_p, ErrorCode error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* DIlip 30 aug 2006 commented to handel Is media already exist error indicator call back */
    /*   g_jmms_context->is_add_media_warning = 0; */
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_error_ind_cb %d", error);
    switch (error)
    {
        case E_WARNING_CREATION_MODE:
            g_jmms_context->is_add_media_warning = 1;
            break;
        case E_WARNING_DRM_FORWARD_RESTRICTED:
            ret_code = JC_ERR_MSG_DRM_FORWARD_RESTRICTED;
            break;
    }
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_add_media_as_file_offset
 * DESCRIPTION
 *  fn to add media.
 * PARAMETERS
 *  path_p              [IN]
 *  offset              [IN]        
 *  file_name_p         [IN]         
 *  type                [IN]        
 *  is_attachment       [IN]        
 *  page_index          [IN]        
 *  size                [IN]        
 *  drm_media_type      [IN]        
 *  media_id            [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
JC_RETCODE mmi_jmms_compose_add_media_as_file_offset(
            JC_CHAR *path_p,
            S32 offset,
            JC_CHAR *file_name_p,
            EMediaType type,
            U8 is_attachment,
            U8 page_index,
            S32 size,
            E_DRM_TYPE drm_media_type,
            U32 *media_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MEDIA_INFO *media_info_p;

    /* FS_HANDLE  file_handle; */
    JC_RETCODE ret_code = JC_OK;

    if (drm_media_type == E_DRM_FWD_LOCK)
    {
        g_jmms_context->is_add_media_as_drm = 1;
    }
    else
    {
        g_jmms_context->is_add_media_as_drm = 0;
    }

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_jmms_compose_add_media");
    media_info_p = (MEDIA_INFO*) jdd_MemAlloc(sizeof(MEDIA_INFO), sizeof(U8));
    if (media_info_p == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }
    media_info_p->pMimeInfo = (MEDIA_MIME_INFO*) jdd_MemAlloc(sizeof(MEDIA_MIME_INFO), sizeof(U8));
    if (media_info_p->pMimeInfo == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }
    media_info_p->eMediaType = type;
    if (is_attachment == E_FALSE && (type == E_MEDIA_IMAGE || type == E_MEDIA_VIDEO))
    {
        U8 size;

        size = strlen(STRING_IMAGE);
        media_info_p->PresentationInfo.pRegionName = (JC_CHAR*) jdd_MemAlloc(sizeof(JC_CHAR), size + 1);
        if (media_info_p->PresentationInfo.pRegionName == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto ERROR_HANDLE;
        }
        mmi_asc_to_ucs2((PS8) (media_info_p->PresentationInfo.pRegionName), (PS8) (STRING_IMAGE));
    }
    media_info_p->pMimeInfo->ContentData.bIsStream = E_TRUE;
    media_info_p->pMimeInfo->bIsDRM = g_jmms_context->is_add_media_as_drm;
    media_info_p->pMimeInfo->ContentData.eCopyMemory = E_FALSE;
    media_info_p->pMimeInfo->ContentData.pBuffer = NULL;
    media_info_p->pMimeInfo->ContentData.uiCurSize = 0;
    media_info_p->pMimeInfo->ContentData.uiTotalSize = size;
    media_info_p->pMimeInfo->ContentData.cbReadCallback = mmi_jmms_read_callback;
    media_info_p->pMimeInfo->ContentData.cbWriteCallback = NULL;
    media_info_p->pMimeInfo->ContentData.uiStartOffset = offset;
    media_info_p->pMimeInfo->ContentData.pFileName =
        (JC_CHAR*) jdd_MemAlloc((jc_tcslen((JC_CHAR*) path_p) + 1), sizeof(JC_CHAR));
    if (media_info_p->pMimeInfo->ContentData.pFileName == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }
    jc_tcscpy((UI_character_type*) media_info_p->pMimeInfo->ContentData.pFileName, (UI_character_type*) path_p);
    media_info_p->pMimeInfo->ContentData.pStream = media_info_p->pMimeInfo->ContentData.pFileName;
    media_info_p->pMimeInfo->MimeHeaders.bIsAttachment = is_attachment;
    media_info_p->pMimeInfo->MimeHeaders.pObjectName =
        (JC_CHAR*) jdd_MemAlloc((jc_tcslen((JC_CHAR*) file_name_p) + 1), sizeof(JC_CHAR));
    if (media_info_p->pMimeInfo->MimeHeaders.pObjectName == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }
    jc_tcscpy((JC_CHAR*) media_info_p->pMimeInfo->MimeHeaders.pObjectName, (JC_CHAR*) file_name_p);
#ifdef __DRM_SUPPORT__
    if (drm_media_type == E_DRM_SEPARATE_DELIVERY)  /* && (mmi_jmms_compose_settings_creation_mode() == E_CREATION_MODE_RESTRICTED)) */
    {
        media_info_p->pMimeInfo->MimeHeaders.pContentType = jdi_UtilsStrdup(APPLICATION_VND_OMA_DRM_CONTENT);
    }
    else
    {
#endif /* __DRM_SUPPORT__ */ 
        media_info_p->pMimeInfo->MimeHeaders.pContentType =
            (JC_INT8*) mmi_mms_get_mms_content_type_file((UI_character_type*) file_name_p, type);
    #ifdef __DRM_SUPPORT__
    }
    #endif 
    if (media_info_p->pMimeInfo->MimeHeaders.pContentType == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }
    if (strcmp((char*)media_info_p->pMimeInfo->MimeHeaders.pContentType, (char*)"audio/mid") == 0)
    {
        jdd_MemFree(media_info_p->pMimeInfo->MimeHeaders.pContentType);
        media_info_p->pMimeInfo->MimeHeaders.pContentType = (JC_INT8*) jdi_UtilsStrdup((char*)"audio/midi");
    }

    /* add media */
    ret_code = mmi_jmms_jdi_add_media(g_jmms_context->msg_handle, media_info_p, page_index, media_id);
    if (ret_code != JC_OK)
    {
        goto ERROR_HANDLE;
    }
#ifdef __DRM_SUPPORT__
    if (g_jmms_context->is_add_media_as_drm)
    {
        ret_code = jdi_MsgSetMediaDRMType(
                    g_jmms_context->msg_handle,
                    page_index,
                    *media_id,
                    E_DRM_FWD_LOCK,
                    media_info_p->pMimeInfo->MimeHeaders.bIsAttachment);
        mmi_jmms_jdi_msg_register_callback(
            g_jmms_context->msg_handle,
            E_CB_DRM_COMPOSE,
            (void*)mmi_jmms_drm_compose_handler);
        g_jmms_context->is_add_media_as_drm = MMI_FALSE;
    }
    else
    {
        ret_code = jdi_MsgSetMediaDRMType(
                    g_jmms_context->msg_handle,
                    page_index,
                    *media_id,
                    E_DRM_NONE,
                    media_info_p->pMimeInfo->MimeHeaders.bIsAttachment);
    }
#endif /* __DRM_SUPPORT__ */ 
  ERROR_HANDLE:
    if (ret_code != JC_OK)
    {
        if (media_info_p != NULL)
        {
            if (media_info_p->pMimeInfo != NULL)
            {
                if (media_info_p->pMimeInfo->ContentData.pFileName != NULL)
                {
                    jdd_MemFree(media_info_p->pMimeInfo->ContentData.pFileName);
                }

                if (media_info_p->pMimeInfo->MimeHeaders.pContentType != NULL)
                {
                    jdd_MemFree(media_info_p->pMimeInfo->MimeHeaders.pContentType);
                }
                if (media_info_p->pMimeInfo->MimeHeaders.pObjectName != NULL)
                {
                    jdd_MemFree(media_info_p->pMimeInfo->MimeHeaders.pObjectName);
                }

                jdd_MemFree(media_info_p->pMimeInfo);
            }
            if (media_info_p->PresentationInfo.pRegionName != NULL)
            {
                jdd_MemFree(media_info_p->PresentationInfo.pRegionName);
            }
            jdd_MemFree(media_info_p);
            media_info_p = NULL;
        }
    }
    if (media_info_p != NULL)
    {
        jdd_MemFree(media_info_p);
        media_info_p = NULL;
    }
    return ret_code;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_add_media_template
 * DESCRIPTION
 *  fn to add media.
 * PARAMETERS
 *  buffer_p            [IN]        
 *  content_type_p      [IN]        
 *  size                [IN]        
 *  type                [IN]        
 *  is_attachment       [IN]        
 *  page_index          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
JMMS_COMP_ERRCODE mmi_jmms_compose_add_media_template(
                    U8 *buffer_p,
                    U8 *content_type_p,
                    U32 size,
                    U8 type,
                    U8 is_attachment,
                    U8 page_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MEDIA_INFO *media_info_p;
    JC_RETCODE ret_code = JC_OK;
    JMMS_COMP_ERRCODE err_code;
    U32 media_id;
    U8 *media_buffer_p = NULL;
    U8 extention[20] = {0, };
    U8 tremp_str[10] = {0, };
    U8 region_size = 0;
    U8 object_name_size = 0;
    applib_mime_type_struct *mime = NULL;
    U8 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_jmms_compose_add_media_template");
    media_info_p = (MEDIA_INFO*) jdd_MemAlloc(sizeof(MEDIA_INFO), sizeof(U8));
    if (media_info_p == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }

    media_info_p->pMimeInfo = (MEDIA_MIME_INFO*) jdd_MemAlloc(sizeof(MEDIA_MIME_INFO), sizeof(U8));
    if (media_info_p->pMimeInfo == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }

    media_info_p->eMediaType = type;

    if (is_attachment == E_FALSE && (type == E_MEDIA_IMAGE || type == E_MEDIA_VIDEO))
    {
        region_size = strlen(STRING_IMAGE);
        media_info_p->PresentationInfo.pRegionName = (JC_CHAR*) jdd_MemAlloc(sizeof(JC_CHAR), region_size + 1);
        if (media_info_p->PresentationInfo.pRegionName == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto ERROR_HANDLE;
        }
        mmi_asc_to_ucs2((PS8) (media_info_p->PresentationInfo.pRegionName), (PS8) (STRING_IMAGE));
    }

    media_info_p->pMimeInfo->ContentData.bIsStream = E_FALSE;
    media_info_p->pMimeInfo->ContentData.eCopyMemory = E_FALSE;

    media_buffer_p = (U8*) jdd_MemAlloc(size, sizeof(U8));
    if (media_buffer_p == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }
    memcpy(media_buffer_p, buffer_p, size);

    media_info_p->pMimeInfo->ContentData.pBuffer = media_buffer_p;

    media_info_p->pMimeInfo->ContentData.uiCurSize = size;
    media_info_p->pMimeInfo->ContentData.uiTotalSize = size;
    media_info_p->pMimeInfo->ContentData.cbReadCallback = NULL;
    media_info_p->pMimeInfo->ContentData.cbWriteCallback = NULL;
    media_info_p->pMimeInfo->ContentData.uiStartOffset = 0;
    media_info_p->pMimeInfo->ContentData.pFileName = NULL;

    media_info_p->pMimeInfo->MimeHeaders.bIsAttachment = is_attachment;

    if (is_attachment == E_FALSE && (type == E_MEDIA_IMAGE || type == E_MEDIA_VIDEO || type == E_MEDIA_AUDIO))
    {
        mime = mime_type_look_up((kal_char*) content_type_p, NULL, 0, 0);
        if (mime)
        {
            len = strlen(mime->file_ext);
        }
    }
    if (is_attachment == E_FALSE && (type == E_MEDIA_IMAGE || type == E_MEDIA_VIDEO))
    {
        object_name_size = strlen(STRING_IMAGE) + len;
    }
    else if (is_attachment == E_FALSE)
    {
        object_name_size = strlen(STRING_AUDIO) + len;
    }
    else
    {
        object_name_size = strlen(STRING_ATTACHMENT);
    }

    media_info_p->pMimeInfo->MimeHeaders.pObjectName = (JC_CHAR*) jdd_MemAlloc(sizeof(JC_CHAR), object_name_size + 1);
    if (media_info_p->pMimeInfo->MimeHeaders.pObjectName == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }

    if (is_attachment == E_FALSE && (type == E_MEDIA_IMAGE || type == E_MEDIA_VIDEO))
    {
        mmi_asc_to_ucs2((PS8) (media_info_p->pMimeInfo->MimeHeaders.pObjectName), (PS8) (STRING_IMAGE));
        sprintf((S8*) tremp_str, "%c%s", '.', mime->file_ext);
        mmi_asc_to_ucs2((PS8) extention, (PS8) tremp_str);
        mmi_ucs2cat((PS8) (media_info_p->pMimeInfo->MimeHeaders.pObjectName), (PS8) extention);
    }
    else if (is_attachment == E_FALSE)
    {
        mmi_asc_to_ucs2((PS8) (media_info_p->pMimeInfo->MimeHeaders.pObjectName), (PS8) (STRING_AUDIO));
        sprintf((S8*) tremp_str, "%c%s", '.', mime->file_ext);
        mmi_asc_to_ucs2((PS8) extention, (PS8) tremp_str);
        mmi_ucs2cat((PS8) (media_info_p->pMimeInfo->MimeHeaders.pObjectName), (PS8) extention);
    }
    else
    {
        mmi_asc_to_ucs2((PS8) (media_info_p->pMimeInfo->MimeHeaders.pObjectName), (PS8) (STRING_ATTACHMENT));
    }

    media_info_p->pMimeInfo->MimeHeaders.pContentType =
        (JC_INT8*) jdd_MemAlloc(sizeof(JC_INT8), strlen((S8*) content_type_p) + 1);
    if (media_info_p->pMimeInfo->MimeHeaders.pContentType == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }
    strcpy((S8*) media_info_p->pMimeInfo->MimeHeaders.pContentType, (S8*) content_type_p);

    /* add media */
    ret_code = mmi_jmms_jdi_add_media(g_jmms_context->msg_handle, media_info_p, page_index, &media_id);

  ERROR_HANDLE:
    err_code = mmi_jmms_compose_handle_error(ret_code, 0);

    switch (err_code)
    {
        case JMMS_COMP_FAIL:
        case JMMS_COMP_OUT_MEMORY:  /* deallocate memory for new slide and out of mmeory case. */
        {
            if (media_info_p != NULL)
            {
                if (media_info_p->pMimeInfo != NULL)
                {
                    if (media_info_p->pMimeInfo->ContentData.pFileName != NULL)
                    {
                        jdd_MemFree(media_info_p->pMimeInfo->ContentData.pFileName);
                    }

                    if (media_info_p->pMimeInfo->MimeHeaders.pContentType != NULL)
                    {
                        jdd_MemFree(media_info_p->pMimeInfo->MimeHeaders.pContentType);
                    }

                    if (media_info_p->pMimeInfo->MimeHeaders.pObjectName != NULL)
                    {
                        jdd_MemFree(media_info_p->pMimeInfo->MimeHeaders.pObjectName);
                    }
                    jdd_MemFree(media_info_p->pMimeInfo);
                }
                if (media_info_p->PresentationInfo.pRegionName != NULL)
                {
                    jdd_MemFree(media_info_p->PresentationInfo.pRegionName);
                }
                jdd_MemFree(media_info_p);
                media_info_p = NULL;
            }

        }
            err_code = JMMS_COMP_FAIL;
            break;
    }

    mmi_jmms_set_region_list();

    if (media_info_p != NULL)
    {
        jdd_MemFree(media_info_p);
        media_info_p = NULL;
    }
    return err_code;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_add_text_media
 * DESCRIPTION
 *  fn to add text.
 * PARAMETERS
 *  page_index              [IN]        
 *  text_font               [IN]        
 *  txt_color               [IN]        
 *  display_error           [IN]        
 *  media_id                [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
/* U8 media_buffer_p[3000]; */
JMMS_COMP_ERRCODE mmi_jmms_compose_add_text_media(
                    U8 page_index,
                    UI_font_type text_font,
                    U32 txt_color,
                    S32 display_error,
                    U32 *media_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MEDIA_INFO *media_info_p;
    JC_RETCODE ret_code = JC_OK;
    JMMS_COMP_ERRCODE err_code;
    U32 buffer_size;
    U8 size;
    U8 *media_buffer_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_jmms_compose_add_text");
    media_info_p = (MEDIA_INFO*) jdd_MemAlloc(sizeof(MEDIA_INFO), sizeof(U8));
    if (media_info_p == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }

    media_info_p->pMimeInfo = (MEDIA_MIME_INFO*) jdd_MemAlloc(sizeof(MEDIA_MIME_INFO), sizeof(U8));
    if (media_info_p->pMimeInfo == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }

    media_info_p->eMediaType = E_MEDIA_TEXT;

    media_info_p->PresentationInfo.pTextAttributes =
        (TEXT_ATTRIBUTES*) jdd_MemAlloc(sizeof(TEXT_ATTRIBUTES), sizeof(U8));
    if (media_info_p->PresentationInfo.pTextAttributes == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }

    if (text_font->bold == 1)
    {
        media_info_p->PresentationInfo.pTextAttributes->bIsBold = E_TRUE;
    }
    if (text_font->italic == 1)
    {
        media_info_p->PresentationInfo.pTextAttributes->bIsItalic = E_TRUE;
    }

    media_info_p->PresentationInfo.pTextAttributes->pFontColor =
        (JC_INT8*) jdd_MemAlloc((strlen("#rrggbb") + 1), sizeof(JC_INT8));
    if (media_info_p->PresentationInfo.pTextAttributes->pFontColor == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }
    mmi_jmms_convert_u32To_hash_col_string(txt_color, media_info_p->PresentationInfo.pTextAttributes->pFontColor);

    switch (text_font->size)
    {
        case SMALL_FONT:
            media_info_p->PresentationInfo.pTextAttributes->uiFontSize = mmi_jdd_ui_get_font_info(SMALL_FONT_SIZE);
            break;
        case LARGE_FONT:
            media_info_p->PresentationInfo.pTextAttributes->uiFontSize = mmi_jdd_ui_get_font_info(LARGE_FONT_SIZE);
            break;
        case MEDIUM_FONT:
            media_info_p->PresentationInfo.pTextAttributes->uiFontSize = mmi_jdd_ui_get_font_info(MEDIUM_FONT_SIZE);
            break;
    }

    media_info_p->pMimeInfo->MimeHeaders.pContentType =
        (JC_INT8*) jdd_MemAlloc(jc_strlen("text/plain") + 1, sizeof(JC_INT8));
    if (media_info_p->pMimeInfo->MimeHeaders.pContentType == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }

    jc_strcpy(media_info_p->pMimeInfo->MimeHeaders.pContentType, "text/plain");

    size = strlen(STRING_TEXT);
    media_info_p->PresentationInfo.pRegionName = (JC_CHAR*) jdd_MemAlloc(sizeof(JC_CHAR), size + 1);
    if (media_info_p->PresentationInfo.pRegionName == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }
    mmi_asc_to_ucs2((PS8) (media_info_p->PresentationInfo.pRegionName), (PS8) (STRING_TEXT));

    buffer_size = jc_tcslen((UI_character_type*) g_jmms_context->compose_context->curr_slide_info.edit_content_buffer) *
        sizeof(JC_CHAR);
    media_info_p->pMimeInfo->ContentData.uiTotalSize = buffer_size;
    media_info_p->pMimeInfo->ContentData.uiCurSize = buffer_size;

    media_buffer_p = (U8*) jdd_MemAlloc(buffer_size + 1, sizeof(U16));
    if (media_buffer_p == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }

    jc_tcscpy(
        (UI_character_type*) media_buffer_p,
        (UI_character_type*) g_jmms_context->compose_context->curr_slide_info.edit_content_buffer);

    media_info_p->pMimeInfo->ContentData.pBuffer = media_buffer_p;

    ret_code = mmi_jmms_jdi_add_media(g_jmms_context->msg_handle, media_info_p, page_index, media_id);

  ERROR_HANDLE:
    if (display_error)
    {
        err_code = mmi_jmms_compose_handle_error(ret_code, 0);
    }
    else
    {
        if (ret_code == JC_OK)
        {
            err_code = JMMS_COMP_OK;
        }
        else
        {
            err_code = JMMS_COMP_FAIL;
        }
    }
    if (err_code == JMMS_COMP_FAIL || err_code == JMMS_COMP_OUT_MEMORY)
    {
        if (media_info_p != NULL)
        {
            if (media_info_p->pMimeInfo != NULL)
            {
                if (media_info_p->pMimeInfo->MimeHeaders.pContentType != NULL)
                {
                    jdd_MemFree(media_info_p->pMimeInfo->MimeHeaders.pContentType);
                }
                jdd_MemFree(media_info_p->pMimeInfo);
            }
            if (media_info_p->PresentationInfo.pRegionName != NULL)
            {
                jdd_MemFree(media_info_p->PresentationInfo.pRegionName);
            }
            if (media_info_p->PresentationInfo.pTextAttributes != NULL)
            {
                jdd_MemFree(media_info_p->PresentationInfo.pTextAttributes);
            }
            jdd_MemFree(media_info_p);
            media_info_p = NULL;
        }

        if (media_buffer_p != NULL)
        {
            jdd_MemFree(media_buffer_p);
        }
        err_code = JMMS_COMP_FAIL;
    }
    if (media_info_p != NULL)
    {
        jdd_MemFree(media_info_p);
        media_info_p = NULL;
    }
    if (display_error)
    {
        return err_code;
    }
    else
    {
        return ret_code;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_add_text
 * DESCRIPTION
 *  fn to add text.
 * PARAMETERS
 *  page_index          [IN]        
 *  text_font           [IN]        
 *  txt_color           [IN]        
 *  update_text_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
/* U8 media_buffer_p[3000]; */
JMMS_COMP_ERRCODE mmi_jmms_compose_add_text(U8 page_index, UI_font_type text_font, U32 txt_color, S32 update_text_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE err_code = JC_OK;
    U32 media_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    err_code = mmi_jmms_compose_add_text_media(page_index, text_font, txt_color, 1, &media_id);
    if (update_text_id && (err_code == JMMS_COMP_OK || err_code == JMMS_COMP_POPUP_OK))
    {
        g_jmms_context->compose_context->curr_slide_info.text_id = media_id;
    }
    mmi_jmms_set_region_list();
    return err_code;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_update_text
 * DESCRIPTION
 *  fn to update text media.
 * PARAMETERS
 *  page_index      [IN]        
 *  media_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
/* U8 media_buffer_p[3000]; */
JMMS_COMP_ERRCODE mmi_jmms_compose_update_text(U8 page_index, U32 media_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_UINT8 *media_buffer_p;
    U32 buffer_size;
    JC_RETCODE ret_code = JC_OK;
    JMMS_COMP_ERRCODE err_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_jmms_compose_update_text");
    buffer_size = jc_tcslen((JC_CHAR*) g_jmms_context->compose_context->curr_slide_info.edit_content_buffer) * sizeof(JC_CHAR);
    media_buffer_p = (U8*) jdd_MemAlloc(buffer_size + 1, sizeof(JC_CHAR));
    if (media_buffer_p == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }
    jc_tcscpy(
        (JC_CHAR*) media_buffer_p,
        (JC_CHAR*) g_jmms_context->compose_context->curr_slide_info.edit_content_buffer);

    ret_code = mmi_jmms_jdi_update_inline_text(
                g_jmms_context->msg_handle,
                (JC_UINT8*) media_buffer_p,
                buffer_size,
                page_index,
                media_id);

  ERROR_HANDLE:
    err_code = mmi_jmms_compose_handle_error(ret_code, 0);

    switch (err_code)
    {
        case JMMS_COMP_FAIL:
        case JMMS_COMP_OUT_MEMORY:  /* deallocate memory for new slide and out of mmeory case. */
            if (media_buffer_p != NULL)
            {
                jdd_MemFree(media_buffer_p);
            }
            err_code = JMMS_COMP_FAIL;
            break;
    }
    return err_code;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_media_type_convert_in_app_mime_type
 * DESCRIPTION
 *  returns the content type of media file.
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  applib_mime_type_enum
 *****************************************************************************/
applib_mime_type_enum mmi_jmms_media_type_convert_in_app_mime_type(EMediaType type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case E_MEDIA_IMAGE:
            return MIME_TYPE_IMAGE;

        case E_MEDIA_AUDIO:
            return MIME_TYPE_AUDIO;

        case E_MEDIA_VIDEO:
            return MIME_TYPE_VIDEO;

        default:
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_get_mms_content_type_file
 * DESCRIPTION
 *  returns the content type of media file.
 * PARAMETERS
 *  file_name_p     [IN]        
 *  type            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 *mmi_mms_get_mms_content_type_file(JC_CHAR *file_name_p, EMediaType type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *content_type_p = NULL;
    applib_mime_type_struct *mime_info_p = NULL;
    kal_wchar *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s t:%d", "Inside mmi_mms_get_mms_content_type_file", type);
    ptr = mime_get_extension(file_name_p);
    if (ptr)
    {
        kal_char file_ext[32] = {0, };
        app_ucs2_str_n_to_asc_str((kal_int8*) file_ext, (kal_int8*) ptr, 31 * ENCODING_LENGTH);
        mime_info_p = mime_type_look_up(NULL, file_ext, mmi_jmms_media_type_convert_in_app_mime_type(type), 0);
        if (mime_info_p == NULL)
        {
            content_type_p = (U8*) jdi_UtilsStrdup("application/octet-stream");
        }
        else
        {
            content_type_p = (U8*) jdi_UtilsStrdup(mime_info_p->mime_string);
        }
    }
    else
    {
        content_type_p = (U8*) jdi_UtilsStrdup("application/octet-stream");
    }
    return content_type_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_is_mime_found_in_g_content_type_list
 * DESCRIPTION
 *  returns the content type of media file.
 * PARAMETERS
 *  psz_content_type_p      [IN]        
 * RETURNS
 *  JC_BOOLEAN
 *****************************************************************************/
JC_BOOLEAN mmi_jmms_is_mime_found_in_g_content_type_list(JC_INT8 *psz_content_type_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 uh_counter = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*(g_content_type_list[uh_counter][0]) != 0)
    {
        if (strcmp(psz_content_type_p, (PS8) (g_content_type_list[uh_counter][0])) == 0)
        {
            return E_TRUE;
        }
        uh_counter++;
    }
    return E_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_delete_media
 * DESCRIPTION
 *  fn to delete media.
 * PARAMETERS
 *  media_id            [IN]        
 *  page_index          [IN]        
 *  is_attachment       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
/* U8 media_buffer_p[3000]; */
JMMS_COMP_ERRCODE mmi_jmms_compose_delete_media(U32 media_id, U8 page_index, U8 is_attachment)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    JMMS_COMP_ERRCODE err_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_jmms_compose_delete_media");
    ret_code = mmi_jmms_jdi_delete_media(g_jmms_context->msg_handle, page_index, media_id, is_attachment);

    err_code = mmi_jmms_compose_handle_error(ret_code, 0);
    return err_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_delete_page
 * DESCRIPTION
 *  fn to delete media.
 * PARAMETERS
 *  page_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
/* U8 media_buffer_p[3000]; */
JMMS_COMP_ERRCODE mmi_jmms_compose_delete_page(U8 page_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    JMMS_COMP_ERRCODE err_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_jmms_compose_delete_page");
    ret_code = mmi_jmms_jdi_delete_page(g_jmms_context->msg_handle, page_index);

    err_code = mmi_jmms_compose_handle_error(ret_code, 1);

    return err_code;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_get_media_list
 * DESCRIPTION
 *  fn to delete media.
 * PARAMETERS
 *  page_index          [IN]        
 *  media_info_p        [IN]        
 *  media_count_p       [IN]        
 *  is_attachment       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
/* U8 media_buffer_p[3000]; */
JMMS_COMP_ERRCODE mmi_jmms_compose_get_media_list(
                    U8 page_index,
                    MEDIA_INFO **media_info_p,
                    U8 *media_count_p,
                    U8 is_attachment)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    JMMS_COMP_ERRCODE err_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_jmms_compose_get_media_list");
    ret_code = mmi_jmms_jdi_get_media_list(g_jmms_context->msg_handle, page_index, media_info_p, media_count_p, is_attachment);

    err_code = mmi_jmms_compose_handle_error(ret_code, 0);
    if (*media_count_p == 0)
    {
        err_code = JMMS_COMP_FAIL;
    }
    return err_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_insert_new_slide
 * DESCRIPTION
 *  This fn inserts a slide.
 * PARAMETERS
 *  duration        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
JC_RETCODE mmi_jmms_compose_insert_new_slide(S32 duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_compose_insert_new_slide: %d %d", duration,
                         g_jmms_context->compose_context->curr_page_index);

    ret_code = mmi_jmms_jdi_add_page(
                g_jmms_context->msg_handle,
                (U8) (g_jmms_context->compose_context->curr_page_index + 1));
    if (ret_code == JC_OK)
    {
        g_jmms_context->compose_context->curr_page_index++;
        mmi_jmms_compose_fill_default_values_slide_settings();
        ret_code = mmi_jmms_jdi_set_page_timer(
                    g_jmms_context->msg_handle,
                    g_jmms_context->compose_context->curr_page_index,
                    duration * 1000);
    }
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_insert_slide
 * DESCRIPTION
 *  This fn inserts a slide.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
JMMS_COMP_ERRCODE mmi_jmms_compose_insert_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    JMMS_COMP_ERRCODE err_code;
    U8 max_page = 0, count = 0;
    U32 slide_time = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_jmms_compose_insert_slide");
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d %d",
                         "Previous Set Values: Text Size of compose context and inline item is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.size,
                         g_jmms_context->jmms_inline_items.text_settings_items.size_selected);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d %d",
                         "Previous Set Values: Italic Selection of compose context and inline item is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.italic,
                         g_jmms_context->jmms_inline_items.text_settings_items.italic_selected);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d %d",
                         "Previous Set Values: Bold Selection of compose context and inline item is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.bold,
                         g_jmms_context->jmms_inline_items.text_settings_items.bold_selected);

    max_page = (U8) mmi_jmms_compose_settings_max_no_pages();

    if (max_page > g_jmms_context->compose_context->curr_page_index)
    {
        ret_code = mmi_jmms_jdi_add_page(
                    g_jmms_context->msg_handle,
                    (U8) (g_jmms_context->compose_context->curr_page_index + 1));
    }
    else
    {
        ret_code = JC_ERR_MSG_MAX_REACHED;
    }

    err_code = mmi_jmms_compose_handle_error(ret_code, 1);

    switch (err_code)
    {
        case JMMS_COMP_OK:
        {
            g_jmms_context->compose_context->curr_page_index++;
            /* shuffling of compose_context->duration handling array  */
            for (count = MAX_POSSIBLE_SLIDES - 1; count >= g_jmms_context->compose_context->curr_page_index; count--)
            {
                g_jmms_context->compose_context->duration[count].txt_dur_max_set =
                    g_jmms_context->compose_context->duration[count - 1].txt_dur_max_set;
                g_jmms_context->compose_context->duration[count].img_dur_max_set =
                    g_jmms_context->compose_context->duration[count - 1].img_dur_max_set;
                g_jmms_context->compose_context->duration[count].audio_dur_max_set =
                    g_jmms_context->compose_context->duration[count - 1].audio_dur_max_set;
                g_jmms_context->compose_context->duration[count].video_dur_max_set =
                    g_jmms_context->compose_context->duration[count - 1].video_dur_max_set;
            }
            mmi_jmms_compose_fill_default_values_slide_settings();
            slide_time = mmi_jmms_compose_settings_default_slide_time();
            err_code = mmi_jmms_save_page_time(slide_time);
            if (err_code == JMMS_COMP_OK)
            {
                g_jmms_context->compose_context->curr_slide_info.slide_prop.slide_time = slide_time;
            }

            memset(
                g_jmms_context->compose_context->curr_slide_info.edit_content_buffer,
                0,
                (JMMS_COMPOSE_TEXT_LENGTH + 1) * ENCODING_LENGTH);
            g_jmms_context->compose_context->curr_slide_info.text_id = 0;
            g_jmms_context->compose_context->curr_slide_info.image_id = 0;
            g_jmms_context->compose_context->curr_slide_info.audio_id = 0;
            g_jmms_context->compose_context->curr_slide_info.video_id = 0;

            /* shuffling of is_image_first handling array  */
            for (count = MAX_POSSIBLE_SLIDES - 1; count >= g_jmms_context->compose_context->curr_page_index; count--)
            {
                g_jmms_context->compose_context->is_image_first[count] =
                    g_jmms_context->compose_context->is_image_first[count - 1];
            }

            g_jmms_context->compose_context->is_image_first[g_jmms_context->compose_context->curr_page_index - 1] = 0;

        }
            break;
    }

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d %d",
                         "After Set Values: Text Size of compose context and inline item is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.size,
                         g_jmms_context->jmms_inline_items.text_settings_items.size_selected);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d %d",
                         "After Set Values: Italic Selection of compose context and inline item is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.italic,
                         g_jmms_context->jmms_inline_items.text_settings_items.italic_selected);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d %d",
                         "After Set Values: Bold Selection of compose context and inline item is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.bold,
                         g_jmms_context->jmms_inline_items.text_settings_items.bold_selected);

    return err_code;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_exit_curr_slide
 * DESCRIPTION
 *  This fn inserts a slide.
 * PARAMETERS
 *  void
 * RETURNS
 *  JMMS_COMP_ERRCODE
 *****************************************************************************/
JMMS_COMP_ERRCODE mmi_jmms_exit_curr_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_jmms_exit_curr_slide");
    if (g_jmms_context->compose_context->exit_conpose_screen == 0 &&
        g_jmms_context->compose_context->curr_page_index > 0)
    {
        /* Deepali: If while adding or deleting the text media some poup comes then this is done to prevent re-entry in infinite loop for this fn. */
        g_jmms_context->compose_context->exit_conpose_screen = 1;

        if ((jc_tcslen((UI_character_type*) g_jmms_context->compose_context->curr_slide_info.edit_content_buffer) != 0)
            && g_jmms_context->compose_context->curr_slide_info.text_id == 0)
        {
            err_code = mmi_jmms_compose_add_text(
                        g_jmms_context->compose_context->curr_page_index,
                        &(g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font),
                        g_jmms_context->compose_context->curr_slide_info.slide_prop.text_color,
                        1);
        }
        else if ((jc_tcslen((UI_character_type*) g_jmms_context->compose_context->curr_slide_info.edit_content_buffer)
                  != 0) && g_jmms_context->compose_context->curr_slide_info.text_id != 0)
        {
            err_code = mmi_jmms_compose_update_text(
                        g_jmms_context->compose_context->curr_page_index,
                        g_jmms_context->compose_context->curr_slide_info.text_id);
        }
        else if ((jc_tcslen((UI_character_type*) g_jmms_context->compose_context->curr_slide_info.edit_content_buffer)
                  == 0) && g_jmms_context->compose_context->curr_slide_info.text_id != 0)
        {
            err_code = mmi_jmms_compose_delete_media(
                        g_jmms_context->compose_context->curr_slide_info.text_id,
                        g_jmms_context->compose_context->curr_page_index,
                        E_FALSE);

            if (err_code == JMMS_COMP_OK || err_code == JMMS_COMP_POPUP_OK)
            {
                g_jmms_context->compose_context->curr_slide_info.text_id = 0;
                mmi_jmms_set_region_list();
            }
        }
        g_jmms_context->compose_context->exit_conpose_screen = 0;
    }
    return err_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_extract_slide_media_info
 * DESCRIPTION
 *  extract curretn slide media info..
 * PARAMETERS
 *  page_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
JMMS_COMP_ERRCODE mmi_jmms_extract_slide_media_info(U8 page_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MEDIA_INFO *media_info_p;
    U8 media_count, is_image_first = 0;
    JC_RETCODE ret_code;
    JMMS_COMP_ERRCODE err_code;
    U8 count = 0;
    mmi_jmms_context_slide_node_struct *slide_info_p;
    JC_UINT32 slide_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_jmms_extract_slide_media_info");
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d %d",
                         "Previous Set Values: Text Size of compose context and inline item is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.size,
                         g_jmms_context->jmms_inline_items.text_settings_items.size_selected);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d %d",
                         "Previous Set Values: Italic Selection of compose context and inline item is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.italic,
                         g_jmms_context->jmms_inline_items.text_settings_items.italic_selected);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d %d",
                         "Previous Set Values: Bold Selection of compose context and inline item is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.bold,
                         g_jmms_context->jmms_inline_items.text_settings_items.bold_selected);

    ret_code = mmi_jmms_jdi_get_media_list(g_jmms_context->msg_handle, page_index, &media_info_p, &media_count, E_FALSE);

    err_code = mmi_jmms_compose_handle_error(ret_code, 0);

    if (err_code == JMMS_COMP_OK)
    {
        memset(
            g_jmms_context->compose_context->curr_slide_info.edit_content_buffer,
            0,
            (JMMS_COMPOSE_TEXT_LENGTH + 1) * ENCODING_LENGTH);
        g_jmms_context->compose_context->curr_slide_info.text_id = 0;
        g_jmms_context->compose_context->curr_slide_info.image_id = 0;
        g_jmms_context->compose_context->curr_slide_info.audio_id = 0;
        g_jmms_context->compose_context->curr_slide_info.video_id = 0;

        slide_info_p = &(g_jmms_context->compose_context->curr_slide_info);

        mmi_jmms_jdi_get_page_timer(g_jmms_context->msg_handle, page_index, &slide_time);
        slide_info_p->slide_prop.slide_time = slide_time / 1000;
        slide_info_p->slide_prop.text_font.italic = 0;
        slide_info_p->slide_prop.text_font.bold = 0;
        slide_info_p->slide_prop.text_font.size = MEDIUM_FONT;
        slide_info_p->slide_prop.text_color = g_jmms_color_RGB_list[COLOR_BLACK];

        mmi_jmms_get_region_list(page_index, &is_image_first);

        for (count = 0; count < media_count; count++)
        {
            switch (media_info_p->eMediaType)
            {
                case E_MEDIA_TEXT:
                    slide_info_p->text_id = media_info_p->uiMediaID;

                    /* sandeep start to fix MAUI_00227858 */
                    if (jc_tcslen((UI_character_type*) media_info_p->pMimeInfo->ContentData.pBuffer) <
                        JMMS_COMPOSE_TEXT_LENGTH)
                    {
                        jc_tcscpy(
                            (UI_character_type*) slide_info_p->edit_content_buffer,
                            (UI_character_type*) media_info_p->pMimeInfo->ContentData.pBuffer);
                    }
                    else
                    {
                        jc_tcsncpy(
                            (UI_character_type*) slide_info_p->edit_content_buffer,
                            (UI_character_type*) media_info_p->pMimeInfo->ContentData.pBuffer,
                            JMMS_COMPOSE_TEXT_LENGTH);
                    }
                    /* sandeep end to fix MAUI_00227858 */
                    if (media_info_p->PresentationInfo.pTextAttributes != NULL)
                    {
                        slide_info_p->slide_prop.text_font.bold =
                            media_info_p->PresentationInfo.pTextAttributes->bIsBold;
                        slide_info_p->slide_prop.text_font.italic =
                            media_info_p->PresentationInfo.pTextAttributes->bIsItalic;

                        if (media_info_p->PresentationInfo.pTextAttributes->uiFontSize == mmi_jdd_ui_get_font_info(SMALL_FONT_SIZE))
                        {
                            slide_info_p->slide_prop.text_font.size = SMALL_FONT;
                        }
                        else if (media_info_p->PresentationInfo.pTextAttributes->uiFontSize == mmi_jdd_ui_get_font_info(MEDIUM_FONT_SIZE))
                        {
                            slide_info_p->slide_prop.text_font.size = MEDIUM_FONT;
                        }
                        else if (media_info_p->PresentationInfo.pTextAttributes->uiFontSize == mmi_jdd_ui_get_font_info(LARGE_FONT_SIZE))
                        {
                            slide_info_p->slide_prop.text_font.size = LARGE_FONT;
                        }

                        mmi_jmms_convert_hash_col_string_toU32((PS8) media_info_p->PresentationInfo.pTextAttributes->pFontColor, &slide_info_p->slide_prop.text_color, 16);     /* deepali: put correct values. */
                    }
                    break;
                case E_MEDIA_IMAGE:
                    slide_info_p->image_id = media_info_p->uiMediaID;

                    g_jmms_context->compose_context->is_image_first[page_index - 1] = is_image_first;
                    if (media_info_p->pMimeInfo->ContentData.pFileName != NULL)
                    {
                        slide_info_p->img_info.file_name_p = (PU8) media_info_p->pMimeInfo->ContentData.pFileName;
                    }
                    break;
                case E_MEDIA_AUDIO:
                    slide_info_p->audio_id = media_info_p->uiMediaID;
                    break;
                case E_MEDIA_VIDEO:
                    slide_info_p->video_id = media_info_p->uiMediaID;

                    g_jmms_context->compose_context->is_image_first[page_index - 1] = is_image_first;
                    if (media_info_p->pMimeInfo->ContentData.pFileName != NULL)
                    {
                        slide_info_p->img_info.file_name_p = (PU8) media_info_p->pMimeInfo->ContentData.pFileName;
                    }
                    break;
            }
            media_info_p = media_info_p->pNext;

        };

    }

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d %d",
                         "After Set Values: Text Size of compose context and inline item is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.size,
                         g_jmms_context->jmms_inline_items.text_settings_items.size_selected);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d %d",
                         "After Set Values: Italic Selection of compose context and inline item is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.italic,
                         g_jmms_context->jmms_inline_items.text_settings_items.italic_selected);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d %d",
                         "After Set Values: Bold Selection of compose context and inline item is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.bold,
                         g_jmms_context->jmms_inline_items.text_settings_items.bold_selected);
    return err_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_save_page_time
 * DESCRIPTION
 *  set page time in message handle.
 * PARAMETERS
 *  slide_time      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
JMMS_COMP_ERRCODE mmi_jmms_save_page_time(U32 slide_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code;
    JMMS_COMP_ERRCODE err_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_code = mmi_jmms_jdi_set_page_timer(
                g_jmms_context->msg_handle,
                g_jmms_context->compose_context->curr_page_index,
                slide_time * 1000);
    err_code = mmi_jmms_compose_handle_error(ret_code, 1);
    return err_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_text_attributes
 * DESCRIPTION
 *  set text attributes
 * PARAMETERS
 *  media_id                [IN]        
 *  page_index              [IN]        
 *  curr_slide_prop_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
JMMS_COMP_ERRCODE mmi_jmms_set_text_attributes(
                    U32 media_id,
                    U8 page_index,
                    mmi_jmms_slide_prop_struct *curr_slide_prop_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code;
    JMMS_COMP_ERRCODE err_code;
    MEDIA_PRESENTATION_INFO media_presentation_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_jdi_get_presentation_info(g_jmms_context->msg_handle, page_index, media_id, &media_presentation_p);

    if (media_presentation_p.pTextAttributes == NULL)
    {
        media_presentation_p.pTextAttributes = (TEXT_ATTRIBUTES*) jdd_MemAlloc(sizeof(TEXT_ATTRIBUTES), sizeof(U8));
        if (media_presentation_p.pTextAttributes == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto ERROR_HANDLE;
        }
    }

    if (curr_slide_prop_p->text_font.bold == 1)
    {
        media_presentation_p.pTextAttributes->bIsBold = E_TRUE;
    }
    else
    {
        media_presentation_p.pTextAttributes->bIsBold = E_FALSE;
    }

    if (curr_slide_prop_p->text_font.italic == 1)
    {
        media_presentation_p.pTextAttributes->bIsItalic = E_TRUE;
    }
    else
    {
        media_presentation_p.pTextAttributes->bIsItalic = E_FALSE;
    }

    if (media_presentation_p.pTextAttributes->pFontColor == NULL)
    {
        media_presentation_p.pTextAttributes->pFontColor =
            (JC_INT8*) jdd_MemAlloc((strlen("#rrggbb") + 1), sizeof(JC_INT8));
        if (media_presentation_p.pTextAttributes->pFontColor == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto ERROR_HANDLE;
        }
    }

    mmi_jmms_convert_u32To_hash_col_string(
        curr_slide_prop_p->text_color,
        media_presentation_p.pTextAttributes->pFontColor);

    switch (curr_slide_prop_p->text_font.size)
    {
        case SMALL_FONT:
            media_presentation_p.pTextAttributes->uiFontSize = mmi_jdd_ui_get_font_info(SMALL_FONT_SIZE);
            break;
        case LARGE_FONT:
            media_presentation_p.pTextAttributes->uiFontSize = mmi_jdd_ui_get_font_info(LARGE_FONT_SIZE);
            break;
        case MEDIUM_FONT:
            media_presentation_p.pTextAttributes->uiFontSize = mmi_jdd_ui_get_font_info(MEDIUM_FONT_SIZE);
            break;
    }

    ret_code = mmi_jmms_jdi_set_media_presentation_info(
                g_jmms_context->msg_handle,
                page_index,
                media_id,
                &media_presentation_p);

  ERROR_HANDLE:
    err_code = mmi_jmms_compose_handle_error(ret_code, 0);
    return err_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_media_time_no_error_handling
 * DESCRIPTION
 *  set media time in message handle.
 * PARAMETERS
 *  start_time      [IN]        
 *  duration        [IN]        
 *  media_id        [IN]        
 *  page_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
JC_RETCODE mmi_jmms_set_media_time_no_error_handling(U32 start_time, U32 duration, U32 media_id, U8 page_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code;
    MEDIA_TIMER media_timer_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_set_media_time_no_error_handling: %d, %d, %d",
                         start_time, duration, media_id, page_index);
    media_timer_p.uiBegin = start_time * 1000;
    media_timer_p.uiDuration = duration * 1000;

    ret_code = mmi_jmms_jdi_set_media_timer(g_jmms_context->msg_handle, page_index, media_id, media_timer_p);

    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_media_time
 * DESCRIPTION
 *  set media time in message handle.
 * PARAMETERS
 *  start_time      [IN]        
 *  duration        [IN]        
 *  media_id        [IN]        
 *  page_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
JMMS_COMP_ERRCODE mmi_jmms_set_media_time(U32 start_time, U32 duration, U32 media_id, U8 page_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code;
    JMMS_COMP_ERRCODE err_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_code = mmi_jmms_set_media_time_no_error_handling(start_time, duration, media_id, page_index);
    err_code = mmi_jmms_compose_handle_error(ret_code, 0);
    return err_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_media_time
 * DESCRIPTION
 *  get media time in message handle.
 * PARAMETERS
 *  start_time_p        [OUT]       
 *  duration_p          [OUT]       
 *  media_id            [IN]        
 *  page_index          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
JMMS_COMP_ERRCODE mmi_jmms_get_media_time(U32 *start_time_p, U32 *duration_p, U32 media_id, U8 page_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code;
    JMMS_COMP_ERRCODE err_code;
    MEDIA_TIMER media_timer_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_code = mmi_jmms_jdi_get_media_timer(g_jmms_context->msg_handle, page_index, media_id, &media_timer_p);

    err_code = mmi_jmms_compose_handle_error(ret_code, 0);

    if (err_code == JMMS_COMP_OK)
    {
        *start_time_p = media_timer_p.uiBegin / 1000;
        *duration_p = media_timer_p.uiDuration / 1000;
    }

    return err_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_convert_u32To_hash_col_string
 * DESCRIPTION
 *  Converts U32 value to Hash color string
 * PARAMETERS
 *  ip_color        [IN]        
 *  op_colstr_p     [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_convert_u32To_hash_col_string(U32 ip_color, PS8 op_colstr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_UINT8 temp_color_str[10];
    JC_UINT8 color_list[3];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    color_list[0] = (U8) ((0xFF000000 & ip_color) >> 24);
    color_list[1] = (U8) ((0x00FF0000 & ip_color) >> 16);
    color_list[2] = (U8) ((0x0000FF00 & ip_color) >> 8);

    strcpy(op_colstr_p, "#");

    memset(temp_color_str, 0, 10);
    sprintf((S8*) temp_color_str, "%X", color_list[0]);
    if (strlen((S8*) temp_color_str) < 2)
    {
        sprintf((S8*) temp_color_str, "0%X", color_list[0]);
    }
    strncat(op_colstr_p, (S8*) temp_color_str, 2);
    memset((S8*) temp_color_str, 0, 10);
    sprintf((S8*) temp_color_str, "%X", color_list[1]);
    if (strlen((S8*) temp_color_str) < 2)
    {
        sprintf((S8*) temp_color_str, "0%X", color_list[1]);
    }
    strncat(op_colstr_p, (S8*) temp_color_str, 2);
    memset((S8*) temp_color_str, 0, 10);
    sprintf((S8*) temp_color_str, "%X", color_list[2]);
    if (strlen((S8*) temp_color_str) < 2)
    {
        sprintf((S8*) temp_color_str, "0%X", color_list[2]);
    }
    strncat(op_colstr_p, (S8*) temp_color_str, 2);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_convert_hash_col_string_toU32
 * DESCRIPTION
 *  Converts Hash color string to U32 value
 * PARAMETERS
 *  ip_colstr_p     [IN]        
 *  op_color_p      [OUT]       
 *  base            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_convert_hash_col_string_toU32(PS8 ip_colstr_p, U32 *op_color_p, U8 base)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_INT8 temp_str[10];
    JC_INT32 color_list[3];
    JC_INT8 *color_start = NULL;
    JC_INT8 color_start_jump = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    color_start = jc_strstr(ip_colstr_p, "#");
    if (color_start == NULL)
    {
        color_start_jump = 0;
    }
    else
    {
        color_start_jump = 1;
    }
    memset(temp_str, 0, 10);
    jc_strncpy(temp_str, (ip_colstr_p + color_start_jump), 2);
    color_list[0] = (U8) jc_strtol(temp_str, NULL, base);

    color_start_jump += 2;
    memset(temp_str, 0, 10);
    jc_strncpy(temp_str, (ip_colstr_p + color_start_jump), 2);
    color_list[1] = (U8) jc_strtol(temp_str, NULL, base);

    color_start_jump += 2;
    memset(temp_str, 0, 10);
    jc_strncpy(temp_str, (ip_colstr_p + color_start_jump), 2);
    color_list[2] = (U8) jc_strtol(temp_str, NULL, base);

    *op_color_p = 0;
    *op_color_p |= 0x00000064;
    *op_color_p |= (((U32) color_list[0]) << 24);
    *op_color_p |= (((U32) color_list[1]) << 16);
    *op_color_p |= (((U32) color_list[2]) << 8);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_bg_color_no_error_handling
 * DESCRIPTION
 *  set mms bg color in message handle.
 * PARAMETERS
 *  bg_color        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
JC_RETCODE mmi_jmms_set_bg_color_no_error_handling(U32 bg_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_INT8 bg_color_str[10];
    U32 height, width;
    DeviceCharacteristics dev_ch = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jdd_MMIGetDeviceCharacteristics(&dev_ch);

    height = dev_ch.uiRenderingWidth;
    width = dev_ch.uiRenderingHeight;

    mmi_jmms_convert_u32To_hash_col_string(bg_color, bg_color_str);

    return mmi_jmms_jdi_set_smil_root_layout(g_jmms_context->msg_handle, height, width, bg_color_str);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_bg_color
 * DESCRIPTION
 *  set mms bg color in message handle.
 * PARAMETERS
 *  bg_color        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
JMMS_COMP_ERRCODE mmi_jmms_set_bg_color(U32 bg_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code;
    JMMS_COMP_ERRCODE err_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_code = mmi_jmms_set_bg_color_no_error_handling(bg_color);

    err_code = mmi_jmms_compose_handle_error(ret_code, 0);
    return err_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_bg_color
 * DESCRIPTION
 *  set mms bg color in message handle.
 * PARAMETERS
 *  bg_color_p      [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
JMMS_COMP_ERRCODE mmi_jmms_get_bg_color(JC_INT32 *bg_color_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_INT8 *bg_color_str_p;
    U32 height, width;
    JC_RETCODE ret_code;
    JMMS_COMP_ERRCODE err_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_code = mmi_jmms_jdi_get_smil_root_layout(g_jmms_context->msg_handle, &height, &width, &bg_color_str_p);

    err_code = mmi_jmms_compose_handle_error(ret_code, 0);

    if (err_code == JMMS_COMP_OK && bg_color_str_p != NULL)
    {
        *bg_color_p = GetColorValue(bg_color_str_p);
        if (*bg_color_p >= 0)
        {
            *bg_color_p <<= 8;
            *bg_color_p |= 0x00000064;
        }
    }
    else
    {
        *bg_color_p = g_jmms_color_RGB_list[COLOR_WHITE];
    }
    return JMMS_COMP_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_potrait_region_list
 * DESCRIPTION
 *  set mms bg color in message handle.
 * PARAMETERS
 *  image_on_top        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
JC_RETCODE mmi_jmms_set_potrait_region_list(U32 image_on_top)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    REGION_LAYOUT region_layout1, region_layout2;
    DeviceCharacteristics dev_ch = {0};
    U8 size;
    JC_RECT display_rect;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_jmms_set_region_list");
    region_layout1.pRegionName = NULL;
    region_layout2.pRegionName = NULL;

    jdd_MMIGetDeviceCharacteristics(&dev_ch);

    display_rect.iLeft = dev_ch.uiLeftMargin;
    display_rect.iTop = dev_ch.uiTopMargin;
    display_rect.uiHeight = dev_ch.uiRenderingHeight;
    display_rect.uiWidth = dev_ch.uiRenderingWidth;
    region_layout1.uiTop = display_rect.iTop;
    region_layout1.uiLeft = display_rect.iLeft;
    region_layout1.uiWidth = (JC_UINT32) (display_rect.uiWidth) - (2 * display_rect.iLeft);
    region_layout1.uiHeight =
        (JC_UINT32) ((display_rect.uiHeight - (2 * display_rect.iTop) - JMMS_VIEW_DEFAULT_MEDIA_SPACING) * 0.5);
    region_layout1.eFit = E_CONFIG_REGION_MEET;
    region_layout2.uiTop = region_layout1.uiHeight + JMMS_VIEW_DEFAULT_MEDIA_SPACING;
    region_layout2.uiLeft = display_rect.iLeft;
    region_layout2.uiWidth = (JC_UINT32) (display_rect.uiWidth) - (2 * display_rect.iLeft);
    region_layout2.uiHeight = (JC_UINT32) (display_rect.uiHeight - region_layout2.uiTop - display_rect.iTop);
    region_layout2.eFit = E_CONFIG_REGION_MEET;
    if (image_on_top)
    {
        /* Image/Video is first */
        size = strlen(STRING_IMAGE);
        region_layout1.pRegionName = (JC_CHAR*) jdd_MemAlloc(sizeof(JC_CHAR), size + 1);
        if (region_layout1.pRegionName == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto ERROR_HANDLE;
        }
        mmi_asc_to_ucs2((PS8) (region_layout1.pRegionName), (PS8) (STRING_IMAGE));

        size = strlen(STRING_TEXT);
        region_layout2.pRegionName = (JC_CHAR*) jdd_MemAlloc(sizeof(JC_CHAR), size + 1);
        if (region_layout2.pRegionName == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto ERROR_HANDLE;
        }
        mmi_asc_to_ucs2((PS8) (region_layout2.pRegionName), (PS8) (STRING_TEXT));
    }
    else
    {
        /* Text is first */
        size = strlen(STRING_TEXT);
        region_layout1.pRegionName = (JC_CHAR*) jdd_MemAlloc(sizeof(JC_CHAR), size + 1);
        if (region_layout1.pRegionName == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto ERROR_HANDLE;
        }
        mmi_asc_to_ucs2((PS8) (region_layout1.pRegionName), (PS8) (STRING_TEXT));

        size = strlen(STRING_IMAGE);
        region_layout2.pRegionName = (JC_CHAR*) jdd_MemAlloc(sizeof(JC_CHAR), size + 1);
        if (region_layout2.pRegionName == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto ERROR_HANDLE;
        }
        mmi_asc_to_ucs2((PS8) (region_layout2.pRegionName), (PS8) (STRING_IMAGE));
    }
    ret_code = mmi_jmms_jdi_add_smil_region_layout(g_jmms_context->msg_handle, &region_layout1);
    if (ret_code == JC_OK)
    {
        ret_code = mmi_jmms_jdi_add_smil_region_layout(g_jmms_context->msg_handle, &region_layout2);
    }
  ERROR_HANDLE:
    if (region_layout1.pRegionName != NULL)
    {
        jdd_MemFree(region_layout1.pRegionName);
        region_layout1.pRegionName = NULL;
    }

    if (region_layout2.pRegionName != NULL)
    {
        jdd_MemFree(region_layout2.pRegionName);
        region_layout2.pRegionName = NULL;
    }

    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_region_list
 * DESCRIPTION
 *  set mms bg color in message handle.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
JMMS_COMP_ERRCODE mmi_jmms_set_region_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;
    REGION_LAYOUT region_layout1, region_layout2;
    MEDIA_INFO *media_info_p;
    DeviceCharacteristics dev_ch = {0};
    U8 size;
    JC_RECT display_rect;
    U8 media_count = 0, page_count = 0, temp_page_count;
    mmi_jmms_media_type_enum first_region_media = MEDIA_AUDIO;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_jmms_set_region_list");
    region_layout1.pRegionName = NULL;
    region_layout2.pRegionName = NULL;

    /* Check that any media exists on slide other then audio */
    mmi_jmms_jdi_get_total_pages(g_jmms_context->msg_handle, &page_count);
    for (temp_page_count = 1; (media_count == 0 && temp_page_count <= page_count); temp_page_count++)
    {
        mmi_jmms_compose_get_media_list(temp_page_count, &media_info_p, &media_count, MMI_FALSE);
        if (media_count != 0)
        {
            if (media_info_p != NULL)
            {
                first_region_media = media_info_p->eMediaType;
                if (media_info_p->eMediaType == MEDIA_AUDIO && media_count > 1)
                {
                    first_region_media = media_info_p->pNext->eMediaType;
                }
            }
            break;
        }
    }
    if ((media_count != 0 && first_region_media != MEDIA_AUDIO) &&
        temp_page_count >= g_jmms_context->compose_context->curr_page_index)
    {
        jdd_MMIGetDeviceCharacteristics(&dev_ch);

        display_rect.iLeft = dev_ch.uiLeftMargin;
        display_rect.iTop = dev_ch.uiTopMargin;

        /* Deepali: Here they want regions as rendering area, excluding scroll bar. */
        display_rect.uiHeight = dev_ch.uiRenderingHeight;
        display_rect.uiWidth = dev_ch.uiRenderingWidth;

        /* Now Template will always be Viewed in PORTRAIT mode */

        if (IsScreenPresent(SCR_ID_JMMS_TEMPLATES) || (g_jmms_context->layout == CUSTOM_LAYOUT) ||
            (U8) mmi_jmms_compose_settings_layout() == (U8) E_MMS_LAYOUT_POTRAIT)
        {
            region_layout1.uiTop = display_rect.iTop;
            region_layout1.uiLeft = display_rect.iLeft;
            region_layout1.uiWidth = (JC_UINT32) (display_rect.uiWidth) - (2 * display_rect.iLeft);
            region_layout1.uiHeight =
                (JC_UINT32) ((display_rect.uiHeight - (2 * display_rect.iTop) - JMMS_VIEW_DEFAULT_MEDIA_SPACING) * 0.5);
            region_layout1.eFit = E_CONFIG_REGION_MEET;

            region_layout2.uiTop = region_layout1.uiHeight + JMMS_VIEW_DEFAULT_MEDIA_SPACING;
            region_layout2.uiLeft = display_rect.iLeft;
            region_layout2.uiWidth = (JC_UINT32) (display_rect.uiWidth) - (2 * display_rect.iLeft);
            region_layout2.uiHeight = (JC_UINT32) (display_rect.uiHeight - region_layout2.uiTop - display_rect.iTop);
            region_layout2.eFit = E_CONFIG_REGION_MEET;
        }
        else
        {
            region_layout1.uiTop = display_rect.iTop;
            region_layout1.uiLeft = display_rect.iLeft;
            region_layout1.uiWidth =
                (JC_UINT32) ((display_rect.uiWidth - (2 * display_rect.iLeft) - JMMS_VIEW_DEFAULT_MEDIA_SPACING) * 0.5);
            region_layout1.uiHeight = (JC_UINT32) ((display_rect.uiHeight - (2 * display_rect.iTop)) * 10);
            region_layout1.eFit = E_CONFIG_REGION_MEET;

            region_layout2.uiTop = display_rect.iTop;
            region_layout2.uiLeft = region_layout1.uiLeft + region_layout1.uiWidth + JMMS_VIEW_DEFAULT_MEDIA_SPACING;
            region_layout2.uiWidth = (JC_UINT32) (display_rect.uiWidth - region_layout2.uiLeft - display_rect.iLeft);
            region_layout2.uiHeight = (JC_UINT32) ((display_rect.uiHeight - (2 * display_rect.iTop)) * 10);
            region_layout2.eFit = E_CONFIG_REGION_MEET;
        }

        if ((g_jmms_context->compose_context->
             is_image_first[temp_page_count - 1] == 0) && first_region_media == MEDIA_TEXT)
        {
            /* Text is first */
            size = strlen(STRING_TEXT);
            region_layout1.pRegionName = (JC_CHAR*) jdd_MemAlloc(sizeof(JC_CHAR), size + 1);
            if (region_layout1.pRegionName == NULL)
            {
                ret_code = JC_ERR_MEMORY_ALLOCATION;
                goto ERROR_HANDLE;
            }
            mmi_asc_to_ucs2((PS8) (region_layout1.pRegionName), (PS8) (STRING_TEXT));

            size = strlen(STRING_IMAGE);
            region_layout2.pRegionName = (JC_CHAR*) jdd_MemAlloc(sizeof(JC_CHAR), size + 1);
            if (region_layout2.pRegionName == NULL)
            {
                ret_code = JC_ERR_MEMORY_ALLOCATION;
                goto ERROR_HANDLE;
            }
            mmi_asc_to_ucs2((PS8) (region_layout2.pRegionName), (PS8) (STRING_IMAGE));
        }
        else
        {
            /* Image/Video is first */
            size = strlen(STRING_IMAGE);
            region_layout1.pRegionName = (JC_CHAR*) jdd_MemAlloc(sizeof(JC_CHAR), size + 1);
            if (region_layout1.pRegionName == NULL)
            {
                ret_code = JC_ERR_MEMORY_ALLOCATION;
                goto ERROR_HANDLE;
            }
            mmi_asc_to_ucs2((PS8) (region_layout1.pRegionName), (PS8) (STRING_IMAGE));

            size = strlen(STRING_TEXT);
            region_layout2.pRegionName = (JC_CHAR*) jdd_MemAlloc(sizeof(JC_CHAR), size + 1);
            if (region_layout2.pRegionName == NULL)
            {
                ret_code = JC_ERR_MEMORY_ALLOCATION;
                goto ERROR_HANDLE;
            }
            mmi_asc_to_ucs2((PS8) (region_layout2.pRegionName), (PS8) (STRING_TEXT));
        }
    #ifdef FIT_REGION_HANDLING_SUPPORT
        if (mmi_jmms_jdi_smil_create_check(g_jmms_context->msg_handle, &region_layout1))
        {
    #endif /* FIT_REGION_HANDLING_SUPPORT */ 
            ret_code = mmi_jmms_jdi_add_smil_region_layout(g_jmms_context->msg_handle, &region_layout1);

            if (ret_code == JC_OK)
            {
                ret_code = mmi_jmms_jdi_add_smil_region_layout(g_jmms_context->msg_handle, &region_layout2);
            }
        #ifdef FIT_REGION_HANDLING_SUPPORT
        }
        #endif 
    }
  ERROR_HANDLE:
    err_code = mmi_jmms_compose_handle_error(ret_code, 0);

    if (region_layout1.pRegionName != NULL)
    {
        jdd_MemFree(region_layout1.pRegionName);
        region_layout1.pRegionName = NULL;
    }

    if (region_layout2.pRegionName != NULL)
    {
        jdd_MemFree(region_layout2.pRegionName);
        region_layout2.pRegionName = NULL;
    }

    return err_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_region_list
 * DESCRIPTION
 *  get smil region list.
 * PARAMETERS
 *  page_index          [IN]        
 *  is_image_first      [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
JMMS_COMP_ERRCODE mmi_jmms_get_region_list(U8 page_index, U8 *is_image_first)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    S8 temp_string[25] = {0, };
    REGION_LAYOUT *region_layout1_p;
    REGION_LAYOUT *top_region_layout1_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_jmms_get_region_list");
    ret_code = mmi_jmms_jdi_get_smil_region_layout(g_jmms_context->msg_handle, &region_layout1_p);
    if (ret_code == JC_OK && region_layout1_p && region_layout1_p->pNext)
    {
        if (region_layout1_p->uiTop == region_layout1_p->pNext->uiTop)
        {
            if (region_layout1_p->uiLeft < region_layout1_p->pNext->uiLeft)
            {
                top_region_layout1_p = region_layout1_p;
            }
            else
            {
                top_region_layout1_p = region_layout1_p->pNext;
            }
        }
        else
        {
            if (region_layout1_p->uiTop < region_layout1_p->pNext->uiTop)
            {
                top_region_layout1_p = region_layout1_p;
            }
            else
            {
                top_region_layout1_p = region_layout1_p->pNext;
            }
        }
        mmi_asc_to_ucs2((PS8) (temp_string), (PS8) (STRING_IMAGE));
        if (mmi_ucs2cmp((S8*) top_region_layout1_p->pRegionName, (S8*) temp_string) == 0)
        {
            *is_image_first = 1;
        }
        else
        {
            *is_image_first = 0;
        }
    }
    else
    {
        *is_image_first = 0;
    }
    return JMMS_COMP_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_mms_media_type_from_file
 * DESCRIPTION
 *  returns the content type of media file.
 * PARAMETERS
 *  file_name_p     [IN]        
 *  type            [IN]        
 * RETURNS
 *  mmi_jmms_media_type_enum.
 *****************************************************************************/
mmi_jmms_media_type_enum mmi_jmms_get_mms_media_type_from_file(JC_CHAR *file_name_p, EMediaType type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_jmms_media_type_enum media_type_p = MEDIA_OTHER;
    U8 i;
    JC_CHAR *temp_file_name_p = NULL;
    S8 media_string_ansi[MEDIA_OTHER][10] = { "text", "image", "audio", "video" };

    applib_mime_type_struct *mime_info_p = NULL;
    kal_wchar *ptr = NULL;

#ifdef __DRM_ODF_SUPPORT__
    U32 drm_method = DRM_METHOD_NONE;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s t:%d", "Inside mmi_jmms_get_mms_media_type_from_file", type);
    jdd_MemSetActiveModuleID(E_TASK_MMS_UI);
#ifdef __DRM_ODF_SUPPORT__
    drm_method = mmi_jmms_get_drm_method_type(file_name_p);
#endif 
    if ((type == E_MEDIA_OTHERS) && (file_name_p)
#ifdef __DRM_ODF_SUPPORT__
        && (drm_method != DRM_METHOD_V2)
#endif 
        )
    {
        U32 iIndex = 0;

        iIndex = jdi_UtilsLastIndexOfTchar('.', file_name_p, jc_tcslen(file_name_p) - 1);
        if (iIndex > 0 && jc_tcslen(file_name_p) != (U32) iIndex)
        {
            U16 uh_counter = 0;

            iIndex++;
            temp_file_name_p =
                (JC_CHAR*) jdd_MemAlloc(mmi_ucs2strlen((S8*) file_name_p) * ENCODING_LENGTH + ENCODING_LENGTH, 1);
            if (temp_file_name_p == NULL)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "OUT OF MEMORY in file name generation");
                DisplayPopup(
                    (PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    ERROR_TONE);
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "media Type = %d", media_type_p);
                return media_type_p;
            }
            mmi_ucs2cpy((S8*) temp_file_name_p, (S8*) file_name_p);
            temp_file_name_p = jdi_UtilsTcsUpperToLower((JC_CHAR*) temp_file_name_p);
            while (*(g_content_type_list[uh_counter][0]) != 0)
            {
                if (jdi_UtilsTcsStrCmp(temp_file_name_p + iIndex, g_content_type_list[uh_counter][1]) == 0)
                {
                    for (i = 0; i < MEDIA_OTHER; i++)
                    {
                        if (strncmp
                            (media_string_ansi[i], g_content_type_list[uh_counter][0],
                             strlen((PS8) media_string_ansi[i])) == 0)
                        {
                            media_type_p = i;
                            if (temp_file_name_p != NULL)
                            {
                                jdd_MemFree(temp_file_name_p);
                                temp_file_name_p = NULL;
                            }
                            PRINT_INFORMATION_2(MMI_TRACE_INFO, "media Type = %d", media_type_p);
                            return media_type_p;
                        }
                    }
                }
                uh_counter++;
            }
        }
    }
    if (temp_file_name_p != NULL)
    {
        jdd_MemFree(temp_file_name_p);
        temp_file_name_p = NULL;
    }

    if ((ptr = mime_get_extension(file_name_p)) != NULL)
    {
        kal_char file_ext[32] = {0, };
        app_ucs2_str_n_to_asc_str((kal_int8*) file_ext, (kal_int8*) ptr, 31 * ENCODING_LENGTH);
        mime_info_p = mime_type_look_up(NULL, file_ext, mmi_jmms_media_type_convert_in_app_mime_type(type), 0);
    #ifdef __DRM_ODF_SUPPORT__
        if (jdi_UtilsStrStartsWith(mime_info_p->mime_string, APPLICATION_VND_OMA_DRM_CONTENT_V2))
        {
            if(mmi_jmms_drm_is_multi_part_odf_content(file_name_p) == E_FALSE)
            {
                jc_strncpy((kal_int8*) file_ext, (kal_int8*) mmi_jmms_drm_odf_get_content_ext(file_name_p), 31);
                mime_info_p = mime_type_look_up(NULL, file_ext, mmi_jmms_media_type_convert_in_app_mime_type(type), 0);
            }
            else
            {
                return MEDIA_OTHER;
            }
        }
    #endif /* __DRM_ODF_SUPPORT__ */ 
    }

    if (mime_info_p != NULL)
    {
        switch (mime_info_p->mime_type)
        {
            case MIME_TYPE_IMAGE:
                media_type_p = MEDIA_IMAGE;
                break;
            case MIME_TYPE_AUDIO:
                media_type_p = MEDIA_AUDIO;
                break;
            case MIME_TYPE_VIDEO:
                media_type_p = MEDIA_VIDEO;
                break;
            case MIME_TYPE_TEXT:
                media_type_p = MEDIA_TEXT;
                break;
        }
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "media Type = %d", media_type_p);
    return media_type_p;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_convert_chinese_english_filename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_filename_p      [OUT]       
 *  src_filename_p      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_jmms_convert_chinese_english_filename(JC_CHAR **dst_filename_p, JC_CHAR *src_filename_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_CHAR *tmp_file_ext_p = NULL;
    JC_RETCODE ret_code = JC_OK;
    MESSAGING_HANDLER *msg_handle_p = g_jmms_context->msg_handle;
    MEDIA_MIME_LIST *mime_list_p;
    MEDIA_MIME_INFO *target_mime_p = NULL;
    U8 isDuplicate = 1;
    U32 ch_transaction_id = mmi_jmms_get_chinese_file_name_id_from_nvram();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (src_filename_p != NULL && isDuplicate == 1)
    {
        U32 index = 0;
        S8 temp_str[50];
        JC_CHAR *dst_temp_file_name = NULL;

        index = jdi_UtilsLastIndexOfTchar('.', src_filename_p, jc_tcslen(src_filename_p) - 1);
        tmp_file_ext_p = &src_filename_p[index];

        sprintf(temp_str, "%s%d", JMMS_CHINESE_FILE_NAME_PRE_STRING, ++ch_transaction_id);

        ret_code = jdi_UtilsCharToTchar(&dst_temp_file_name, temp_str);

        if (ret_code != JC_OK)
        {
            return ret_code;
        }

        *dst_filename_p =
            (JC_CHAR*) jdd_MemAlloc((jc_tcslen(dst_temp_file_name) + jc_tcslen(tmp_file_ext_p) + 1), sizeof(JC_CHAR));

        if (*dst_filename_p == NULL)
        {
            jdd_MemFree(dst_temp_file_name);
            return JC_ERR_MEMORY_ALLOCATION;
        }

        jc_tcscpy((JC_CHAR*) * dst_filename_p, (JC_CHAR*) dst_temp_file_name);
        jc_tcscat(*dst_filename_p, tmp_file_ext_p);

        jdd_MemFree(dst_temp_file_name);

        /* Check for duplicate filename */
        isDuplicate = 0;

        mime_list_p = msg_handle_p->pMimeList;
        while (mime_list_p != NULL)
        {
            target_mime_p = mime_list_p->pMimeInfo;

            if (jc_tcscmp(target_mime_p->MimeHeaders.pObjectName, *dst_filename_p) == 0)
            {
                isDuplicate = 1;
                jdd_MemFree(*dst_filename_p);
                break;
            }

            mime_list_p = mime_list_p->pNext;
        }
    }

    mmi_jmms_set_chinese_file_name_id_to_nvram(ch_transaction_id);
    return ret_code;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_chinese_file_name_id_from_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_jmms_get_chinese_file_name_id_from_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U64 ch_file_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_JMMS_CHINESE_TRANSACTION_ID, &ch_file_num, DS_DOUBLE, &error);
    if (ch_file_num > (0xFFFFFFFF)) /* compiler warning removal */
    {
        ch_file_num = 0;
        WriteValue(NVRAM_JMMS_CHINESE_TRANSACTION_ID, &ch_file_num, DS_DOUBLE, &error);
    }

    return (U32) ch_file_num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_chinese_file_name_id_to_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tr_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_set_chinese_file_name_id_to_nvram(U32 tr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U64 ch_file_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ch_file_num = tr_id;
    if (ch_file_num == 0x00000000FFFFFFFF)
    {
        ch_file_num = 0;
    }
    WriteValue(NVRAM_JMMS_CHINESE_TRANSACTION_ID, &ch_file_num, DS_DOUBLE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  is_extended_char_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer_p        [IN]        
 * RETURNS
 * BOOL
 *****************************************************************************/
pBOOL is_extended_char_present(S8 *buffer_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL is_extended = FALSE;
    U8 i = 0, buffer_len = 0;
    UI_character_type ch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ch = 0x00FF & (UI_character_type) buffer_p[i];
    buffer_len = mmi_ucs2strlen(buffer_p) * ENCODING_LENGTH;
    for (i = 0; i < buffer_len; i += 2)
    {
        if ((0x00FF & (UI_character_type) buffer_p[i]) >= 0x80 &&
            (0x00FF & (UI_character_type) buffer_p[i + 1] == 0x00))
        {
            is_extended = TRUE;
            break;
        }
    }
    return is_extended;
}

#ifdef __DRM_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_is_drm_fwd_lock_media_in_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  messaging_handle_p      [IN]        
 *  check_for_edit          [IN]        
 * RETURNS
 *  JC_BOOLEAN
 *****************************************************************************/
JC_BOOLEAN mmi_jmms_is_drm_fwd_lock_media_in_mms(MESSAGING_HANDLER *messaging_handle_p, JC_BOOLEAN check_for_edit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MEDIA_MIME_LIST *temp_mime_list_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_is_drm_fwd_lock_media_in_mms");
    if (messaging_handle_p->pMimeList != NULL)
    {
        temp_mime_list_p = messaging_handle_p->pMimeList;
    }
    while (temp_mime_list_p != NULL)
    {
        if (jdi_CUtilsStrStartsWith
            (temp_mime_list_p->pMimeInfo->MimeHeaders.pContentType, APPLICATION_VND_OMA_DRM_MESSAGE) == E_TRUE)
        {
            if (check_for_edit)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_JMMS_FORWARD_LOCK_DRM_CANT_EDIT),
                    IMG_GLOBAL_WARNING,
                    1,
                    JMMS_POPUP_TIME,
                    WARNING_TONE);
            }
            else
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_JMMS_FORWARD_LOCK_DRM),
                    IMG_GLOBAL_WARNING,
                    1,
                    JMMS_POPUP_TIME,
                    WARNING_TONE);
            }
            return E_TRUE;
        }
        temp_mime_list_p = temp_mime_list_p->pNext;
    }
    return E_FALSE;
}
#endif /* __DRM_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_is_corrupted_video_media_in_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  messaging_handle_p          [IN]        
 *  need_resolution_check       [IN]        
 * RETURNS
 *  JC_BOOLEAN
 *****************************************************************************/
JC_BOOLEAN mmi_jmms_is_corrupted_video_media_in_mms(
            MESSAGING_HANDLER *messaging_handle_p,
            JC_BOOLEAN need_resolution_check)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PAGE *temp_page_list_p = NULL;
    JC_UINT32 audio_du = 0;
    S32 img_widthv, img_heightv;

#ifdef __MMI_VIDEO_PLAYER__
    MDI_RESULT result_video = 0;
#endif 
    JC_BOOLEAN result_media = E_FALSE, image_resolution_support = E_TRUE;
    GDI_RESULT image_result;
    S32 audio_result = 0;
    COMMON_MEDIA_INFO *media_list_p = NULL;
    S32 p_count = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_jmms_is_corrupted_video_media_in_mms");
    if (messaging_handle_p->pPageList != NULL)
    {
        temp_page_list_p = messaging_handle_p->pPageList;
        while (temp_page_list_p->pPrev != NULL)
        {
            temp_page_list_p = temp_page_list_p->pPrev;
        }
    }
    while (temp_page_list_p != NULL)
    {
        S32 m_count = 1;

        media_list_p = temp_page_list_p->pMediaList;
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "p_count:%d", p_count);
        while (media_list_p != NULL)
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "m_count:%d", m_count);
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "media_list_p->eMediaType:%d", media_list_p->eMediaType);
            switch (media_list_p->eMediaType)
            {
                case E_MEDIA_IMAGE:
            #ifdef __DRM_SUPPORT__
                    if (jdi_CUtilsStrStartsWith
                        (media_list_p->pMimeInfo->MimeHeaders.pContentType, APPLICATION_DRM_VALUE) != E_TRUE)
            #endif /* __DRM_SUPPORT__ */ 
                    {
                        image_result = gdi_image_get_dimension_file(
                                        (S8*) media_list_p->pMimeInfo->ContentData.pFileName,
                                        &img_widthv,
                                        &img_heightv);
                        if (image_result != GDI_SUCCEED || (img_widthv * img_heightv) == 0)
                        {
                            result_media = E_TRUE;
                        }
                        else if (need_resolution_check == E_TRUE)
                        {
                            U32 media_size = 0;

                            mmi_jmms_get_media_file_size(
                                (S8*) media_list_p->pMimeInfo->ContentData.pFileName,
                                &media_size);
                            image_resolution_support = mmi_jdd_check_for_image_size_and_resolution(
                                                        (S8*) media_list_p->pMimeInfo->ContentData.pFileName,
                                                        img_widthv,
                                                        img_heightv,
                                                        media_size);
                            if (image_resolution_support == E_FALSE)
                            {
                                result_media = E_TRUE;
                            }
                        }
                    }
                    break;

                case E_MEDIA_AUDIO:
                #ifdef __DRM_SUPPORT__
                    if (jdi_CUtilsStrStartsWith
                        (media_list_p->pMimeInfo->MimeHeaders.pContentType, APPLICATION_DRM_VALUE) != E_TRUE)
                #endif /* __DRM_SUPPORT__ */ 
                    {
                        audio_result = mdi_audio_get_duration(
                                        (S8*) media_list_p->pMimeInfo->ContentData.pFileName,
                                        &audio_du);
                        if (audio_result != GDI_SUCCEED)
                        {
                            result_media = E_TRUE;
                        }
                    }
                    break;
                #ifdef __MMI_VIDEO_PLAYER__
                case E_MEDIA_VIDEO:
                #ifdef __DRM_SUPPORT__
                    if (jdi_CUtilsStrStartsWith
                        (media_list_p->pMimeInfo->MimeHeaders.pContentType, APPLICATION_DRM_VALUE) != E_TRUE)
                #endif /* __DRM_SUPPORT__ */ 
                    {
                        result_video = mmi_jdd_videoapp_get_video_file_size_info(
                                        (S8*) media_list_p->pMimeInfo->ContentData.pFileName,
                                        (JC_UINT32*) & img_widthv,
                                        (JC_UINT32*) & img_heightv);
                        PRINT_INFORMATION_2(MMI_TRACE_INFO, "result_video:%d h%d w%d", result_video, img_heightv,
                                             img_widthv);
                        if (result_video == MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED)
                        {
                            result_media = E_TRUE;
                        }
                        PRINT_INFORMATION_2(MMI_TRACE_INFO, "result_media:%d", result_media);
                    }
                    break;
                #endif /* __MMI_VIDEO_PLAYER__ */ 
            }
            if (result_media == E_TRUE)
            {
            #ifdef __MMI_UNIFIED_MESSAGE__
                g_jmms_context->edit_error_code = -1;
            #endif 
                if (image_resolution_support == E_FALSE)
                {
                    DisplayPopup(
                        (PU8) GetString(STR_GLOBAL_UNSUPPORTED_FORMAT),
                        IMG_GLOBAL_ERROR,
                        1,
                        JMMS_POPUP_TIME,
                        ERROR_TONE);
                }
                else
                {
                    DisplayPopup(
                        (PU8) GetString(STR_ID_JMMS_CORRUPTED_MEDIA_FILE),
                        IMG_GLOBAL_ERROR,
                        1,
                        JMMS_POPUP_TIME,
                        ERROR_TONE);
                }
                return E_TRUE;
            }
            media_list_p = media_list_p->pNext;
            m_count++;
        }
        p_count++;
        temp_page_list_p = temp_page_list_p->pNext;
    }
    return E_FALSE;
}

/* PMT VIKAS END 20060403 */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_handle_error
 * DESCRIPTION
 *  error handling fn.
 * PARAMETERS
 *  ret_code        [IN]        
 *  is_page         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
JMMS_COMP_ERRCODE mmi_jmms_compose_handle_error(JC_RETCODE ret_code, U8 is_page)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_compose_handle_error");
    if ((ret_code == JC_ERR_MSG_MMS_AUDIO_EXISTS) || (ret_code == JC_ERR_MSG_MMS_IMAGE_EXISTS) ||
        (ret_code == JC_ERR_MSG_MMS_VIDEO_EXISTS) || (ret_code == JC_ERR_MSG_MMS_MEDIA_TYPE_EXISTS))
    {
        U8 total_pages = 0;

        mmi_jmms_jdi_get_total_pages(g_jmms_context->msg_handle, &total_pages);
        if (total_pages == mmi_jmms_compose_settings_max_no_pages())
        {
            is_page = 1;
            ret_code = JC_ERR_MSG_MAX_REACHED;
        }
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_compose_handle_error = %d", ret_code);
    switch (ret_code)
    {
        case JC_OK:
            if (g_jmms_context->is_add_media_warning == 1 && !g_jmms_context->disable_warning_popup)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_JMMS_WARNING_MODE_MEDIA),
                    IMG_GLOBAL_WARNING,
                    1,
                    JMMS_POPUP_TIME,
                    WARNING_TONE);
                err_code = JMMS_COMP_POPUP_OK;
            }
            else
            {
                err_code = JMMS_COMP_OK;
            }
            break;
        case JC_ERR_MSG_INVALID_HANDLE:
            DisplayPopup(
                (PU8) GetString(STR_ID_JMMS_INVALID_MESSAGE_HANDLE),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                ERROR_TONE);
            break;
        case JC_ERR_MSG_INVALID_PAGE_INDEX:
            DisplayPopup(
                (PU8) GetString(STR_ID_JMMS_INVALID_PAGE_INDEX),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                ERROR_TONE);
            break;
        case JC_ERR_MSG_INVALID_MEDIA_INDEX:
            DisplayPopup(
                (PU8) GetString(STR_ID_JMMS_INVALID_MEDIA_ID),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                ERROR_TONE);
            break;
        case JC_ERR_MSG_MEDIA_RESTRICTED:
            DisplayPopup(
                (PU8) GetString(STR_ID_JMMS_RESTRICTED_MODE_MEDIA),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                ERROR_TONE);
            err_code = JMMS_COMP_FAIL;
            break;
        case JC_ERR_MSG_MEDIA_WARNING:
            if (!g_jmms_context->disable_warning_popup)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_JMMS_WARNING_MODE_MEDIA),
                    IMG_GLOBAL_WARNING,
                    1,
                    JMMS_POPUP_TIME,
                    WARNING_TONE);
                err_code = JMMS_COMP_POPUP_OK;
            }
            else
            {
                err_code = JMMS_COMP_OK;
            }
            break;
        case JC_ERR_MSG_MAX_REACHED:

            if (is_page == 1)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_JMMS_EDIT_CONTENT_MAX_SLIDE_REACHED),
                    IMG_GLOBAL_WARNING,
                    1,
                    JMMS_POPUP_TIME,
                    WARNING_TONE);
            }
            else
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_JMMS_MAX_MSG_REACHED),
                    IMG_GLOBAL_WARNING,
                    1,
                    JMMS_POPUP_TIME,
                    WARNING_TONE);
            }

            break;
        case JC_ERR_UNSUPPORTED:
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_UNSUPPORTED_FORMAT),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                ERROR_TONE);
            break;
        case JC_ERR_MSG_MMS_UNSUPPORTED_TYPE:
            DisplayPopup(
                (PU8) GetString(STR_ID_JMMS_INVALID_MEDIA_TYPE),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                ERROR_TONE);
            break;
        case JC_ERR_MSG_MMS_AUDIO_EXISTS:
            if (g_jmms_context->is_add_media_warning != 1)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_JMMS_AUDIO_EXISTS_NEW_SLIDE),
                    IMG_GLOBAL_WARNING,
                    1,
                    JMMS_POPUP_TIME,
                    WARNING_TONE);
            }
            err_code = JMMS_COMP_NEW_SLIDE;
            break;
        case JC_ERR_MSG_MMS_IMAGE_EXISTS:
            if (g_jmms_context->is_add_media_warning != 1)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_JMMS_IMAGE_EXISTS_NEW_SLIDE),
                    IMG_GLOBAL_WARNING,
                    1,
                    JMMS_POPUP_TIME,
                    WARNING_TONE);
            }
            err_code = JMMS_COMP_NEW_SLIDE;
            break;
        case JC_ERR_MSG_MMS_VIDEO_EXISTS:
            if (g_jmms_context->is_add_media_warning != 1)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_JMMS_VIDEO_EXISTS_NEW_SLIDE),
                    IMG_GLOBAL_WARNING,
                    1,
                    JMMS_POPUP_TIME,
                    WARNING_TONE);
            }
            err_code = JMMS_COMP_NEW_SLIDE;
            break;
        case JC_ERR_MSG_MMS_MEDIA_TYPE_EXISTS:
            if (g_jmms_context->is_add_media_warning != 1)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_JMMS_SAME_MEDIA_EXISTS_NEW_SLIDE),
                    IMG_GLOBAL_WARNING,
                    1,
                    JMMS_POPUP_TIME,
                    WARNING_TONE);
            }
            err_code = JMMS_COMP_NEW_SLIDE;
            break;
        case JC_ERR_MSG_INVALID_MEDIA_INFO:
            DisplayPopup(
                (PU8) GetString(STR_ID_JMMS_INVALID_MEDIA_INFO),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                ERROR_TONE);
            break;
        case JC_ERR_MSG_MMS_CONTENT_CLASS:
            err_code = JMMS_CONTENT_CLASS;
            break;
            /*
             * merge     case JC_ERR_MSG_MULTIPLE_REFERENCE: 
             * err_code=JMMS_COMP_OK;
             * break;
             */
        case JC_ERR_FILE_SYS_INIT:
        case JC_ERR_MEMORY_ALLOCATION:
            DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
            err_code = JMMS_COMP_OUT_MEMORY;
            break;
        case JC_ERR_NULL_POINTER:
            DisplayPopup(
                (PU8) GetString(STR_ID_JMMS_INVALID_POINTER),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                ERROR_TONE);
            break;
        case JC_ERR_FILE_OPEN:
            if (jdd_FSGetMMSFolderFreeSpace() == 0)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_JMMS_FILE_SYSTEM_FULL),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    ERROR_TONE);
            }
            else
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_JMMS_FILE_SYSTEM_ERROR),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    ERROR_TONE);
            }
            break;
        case JC_ERR_MSG_EMPTY_FILE:
            DisplayPopup((PU8) GetString(STR_ID_JMMS_EMPTY_FILE), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
            break;
        default:
            /* DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE); */
        {
            U8 error_str[20];
            S8 temp[10] = {0, };

            memset(error_str, 0x00, 20);
            sprintf((S8*) temp, "%d", ret_code);

            mmi_asc_to_ucs2((PS8) (error_str), (PS8) temp);

            DisplayPopup((PU8) (error_str), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);

            break;
        }
    }

    if (g_jmms_context->is_add_media_warning == 1)
    {
        g_jmms_context->is_add_media_warning = 0;
    }

    return err_code;

}

/* PMT VIKAS END 20060403 */
#ifndef __MMI_UNIFIED_COMPOSER__
/* PMT VIKAS START 20060405 */
// #ifdef __MMI_MMS_SIGNATURE__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_display_auto_signature_error_popup
 * DESCRIPTION
 *  display popup for autosignature error check
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_display_auto_signature_error_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (U8*) GetString(STR_ID_AUTO_SIGNATURE_ERROR_TOO_MANY_SLIDES),
        IMG_GLOBAL_ERROR,
        1,
        JMMS_POPUP_TIME,
        (U8) ERROR_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_pre_check_for_auto_signature
 * DESCRIPTION
 *  insert the auto signature slide
 * PARAMETERS
 *  void
 * RETURNS
 *  JC_BOOLEAN
 *****************************************************************************/
JC_BOOLEAN mmi_jmms_pre_check_for_auto_signature(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 page_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_jmms_compose_settings_auto_sign_status() == E_ON && mmi_jmms_is_message_to_fwd() == E_FALSE)
    {
        mmi_jmms_jdi_get_total_pages(g_jmms_context->msg_handle, &page_count);
        if (page_count >= mmi_jmms_compose_settings_max_no_pages())
        {
            return E_FALSE;
        }
    }
    return E_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_insert_auto_signature
 * DESCRIPTION
 *  insert the auto signature slide
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_insert_auto_signature(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 page_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_jmms_insert_auto_signature");
    if (mmi_jmms_compose_settings_auto_sign_status() == E_ON &&
        mmi_jmms_is_message_to_fwd() == E_FALSE &&
        (g_jmms_context->store_context->current_folder_name == E_JMMS_INBOX ||
         g_jmms_context->store_context->current_folder_name == E_JMMS_SENT ||
         g_jmms_context->store_context->current_folder_name == E_JMMS_WRITE_MMS ||
         g_jmms_context->store_context->current_folder_name == E_JMMS_TEMPLATES ||
         g_jmms_context->store_context->current_folder_name == E_JMMS_DRAFTS))
    {
        mmi_jmms_jdi_get_total_pages(g_jmms_context->msg_handle, &page_count);
        if (page_count < mmi_jmms_compose_settings_max_no_pages())
        {

            mmi_jmms_insert_auto_signature_slide(page_count);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_auto_signature_mms
 * DESCRIPTION
 *  function of writing a new signature MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
JMMS_COMP_ERRCODE mmi_jmms_compose_auto_signature_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Deepali: use setting API's */
    JC_RETCODE ret_code = JC_OK;
    JMMS_COMP_ERRCODE err_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_jmms_compose_auto_signature_mms");
    ret_code = mmi_jmms_jdi_set_content_class(g_jmms_context->msg_handle, MMS_SUPPORTED_CONTENT_CLASS);

    if (ret_code == JC_OK)
    {
        ret_code = mmi_jmms_jdi_set_creation_mode(g_jmms_context->msg_handle, mmi_jmms_compose_settings_creation_mode());
    }
    if (ret_code == JC_OK)
    {
        ret_code = mmi_jmms_jdi_set_msg_type(g_jmms_context->msg_handle, E_TYPE_MMS);
    }
    if (ret_code == JC_OK)
    {
        ret_code = mmi_jmms_jdi_set_presentation_type(g_jmms_context->msg_handle, E_PRESENTATION_SMIL);
    }
    if (ret_code == JC_OK)
    {
        ret_code = mmi_jmms_jdi_set_max_pages(g_jmms_context->msg_handle, (U8) mmi_jmms_compose_settings_max_no_pages());
    }

    if (ret_code == JC_OK)
    {
        ret_code = mmi_jmms_jdi_msg_register_callback(
                    g_jmms_context->msg_handle,
                    E_CB_ERROR_IND,
                    (void*)mmi_jmms_error_ind_cb);
    }
    err_code = mmi_jmms_compose_handle_error(ret_code, 0);

    return err_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_insert_auto_signature_slide
 * DESCRIPTION
 *  insert the auto signature slide
 * PARAMETERS
 *  page_count      [IN]        
 * RETURNS
 *  JMMS_COMP_ERRCODE.
 *****************************************************************************/
JMMS_COMP_ERRCODE mmi_jmms_insert_auto_signature_slide(U8 page_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    U8 *orig_edit_content_buffer_p;
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;
    stFontAttribute text_font;
    MMI_BOOL context_to_free = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_jmms_insert_auto_signature_slide");
    text_font.italic = 0;
    text_font.bold = 0;
    text_font.size = MEDIUM_FONT;
    if (g_jmms_context->compose_context == NULL)
    {
        context_to_free = MMI_TRUE;
        g_jmms_context->compose_context =
            (mmi_jmms_compose_context_struct*) jdd_MemAlloc(sizeof(mmi_jmms_compose_context_struct), 1);
        if (g_jmms_context->compose_context == NULL)
        {
            DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
            return err_code;
        }
    }
    orig_edit_content_buffer_p = (U8*) jdd_MemAlloc(sizeof(U8), (JMMS_COMPOSE_TEXT_LENGTH + 1) * ENCODING_LENGTH);
    memcpy(
        orig_edit_content_buffer_p,
        g_jmms_context->compose_context->curr_slide_info.edit_content_buffer,
        (JMMS_COMPOSE_TEXT_LENGTH + 1) * ENCODING_LENGTH);
    if (page_count == 0)
    {
        if (JMMS_COMP_OK == mmi_jmms_compose_auto_signature_mms())
        {
            g_jmms_context->compose_context->mms_bg_color = g_jmms_color_RGB_list[COLOR_WHITE];
            /* PMT HIMANSHU START 20060425 */
            /* Added by Deepali for root layout. */
            err_code = mmi_jmms_set_bg_color(g_jmms_context->compose_context->mms_bg_color);
            if ((err_code == JMMS_COMP_OUT_MEMORY) || (err_code == JMMS_COMP_FAIL))
            {
                mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
                return JMMS_COMP_OUT_MEMORY;
            }
            /* PMT HIMANSHU END 20060425 */
            ret_code = mmi_jmms_jdi_add_page(g_jmms_context->msg_handle, (U8) (page_count + 1));        /* mmi_jmms_compose_insert_slide(); */
            err_code = mmi_jmms_compose_handle_error(ret_code, 1);
            if ((err_code == JMMS_COMP_OUT_MEMORY) || (err_code == JMMS_COMP_FAIL))
            {
                mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
                return JMMS_COMP_OUT_MEMORY;
            }
            else
            {
                /* Added By RAJ KUMAR GUPTA on Augest 26, 2006 */
                /* Changes are made to add the default slide time with Signature slide */
                U32 slide_time = 0;

                g_jmms_context->compose_context->curr_page_index = page_count + 1;
                mmi_jmms_compose_fill_default_values_slide_settings();
                slide_time = mmi_jmms_compose_settings_default_slide_time();
                err_code = mmi_jmms_save_page_time(slide_time);
                if (err_code == JMMS_COMP_OK)
                {
                    g_jmms_context->compose_context->curr_slide_info.slide_prop.slide_time = slide_time;
                }
                g_jmms_context->auto_signature_added = MMI_TRUE;
                mmi_ucs2cpy(
                    (S8*) g_jmms_context->compose_context->curr_slide_info.edit_content_buffer,
                    (S8*) g_jmms_context->nvram_compose_settings.auto_signature_content);
                g_jmms_context->disable_warning_popup = 1;
                mmi_jmms_compose_add_text((U8) (page_count + 1), &(text_font), g_jmms_color_RGB_list[COLOR_BLACK], 0);
                g_jmms_context->disable_warning_popup = 0;
            }
        }
    }
    else
    {
        ret_code = mmi_jmms_jdi_add_page(g_jmms_context->msg_handle, (U8) (page_count + 1));
        err_code = mmi_jmms_compose_handle_error(ret_code, 1);
        if ((err_code == JMMS_COMP_OUT_MEMORY) || (err_code == JMMS_COMP_FAIL))
        {
            mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
            return JMMS_COMP_OUT_MEMORY;
        }
        else
        {
            /* Added By RAJ KUMAR GUPTA on Augest 26, 2006 */
            /* Changes are made to add the default slide time with Signature slide */
            U32 slide_time = 0;

            g_jmms_context->compose_context->curr_page_index = page_count + 1;
            mmi_jmms_compose_fill_default_values_slide_settings();
            slide_time = mmi_jmms_compose_settings_default_slide_time();
            err_code = mmi_jmms_save_page_time(slide_time);
            if (err_code == JMMS_COMP_OK)
            {
                g_jmms_context->compose_context->curr_slide_info.slide_prop.slide_time = slide_time;
            }
            g_jmms_context->auto_signature_added = MMI_TRUE;
            mmi_ucs2cpy(
                (S8*) g_jmms_context->compose_context->curr_slide_info.edit_content_buffer,
                (S8*) g_jmms_context->nvram_compose_settings.auto_signature_content);
            g_jmms_context->disable_warning_popup = 1;
            mmi_jmms_compose_add_text((U8) (page_count + 1), &(text_font), g_jmms_color_RGB_list[COLOR_BLACK], 0);
            g_jmms_context->disable_warning_popup = 0;
        }
    }
    memcpy(
        g_jmms_context->compose_context->curr_slide_info.edit_content_buffer,
        orig_edit_content_buffer_p,
        (JMMS_COMPOSE_TEXT_LENGTH + 1) * ENCODING_LENGTH);
    jdd_MemFree(orig_edit_content_buffer_p);

    if (context_to_free == MMI_TRUE)
    {
        context_to_free = MMI_FALSE;
        if (g_jmms_context->compose_context != NULL)
        {
            jdd_MemFree(g_jmms_context->compose_context);
            g_jmms_context->compose_context = NULL;
        }
    }
    return err_code;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_del_inserted_auto_signature_slide
 * DESCRIPTION
 *  delete the auto signature slide
 * PARAMETERS
 *  void
 * RETURNS
 *  JMMS_COMP_ERRCODE.
 *****************************************************************************/
JMMS_COMP_ERRCODE mmi_jmms_del_inserted_auto_signature_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MEDIA_INFO *media_info_p;
    U8 media_count, page_count = 0;
    JMMS_COMP_ERRCODE err_code = JC_OK;
    MMI_BOOL is_sig_existed = E_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_jmms_del_inserted_auto_signature_slide");
    if (mmi_jmms_compose_settings_auto_sign_status() == E_ON && g_jmms_context->auto_signature_added == MMI_TRUE &&
        mmi_jmms_is_message_to_fwd() == MMI_FALSE &&
        (g_jmms_context->store_context->current_folder_name == E_JMMS_INBOX ||
         g_jmms_context->store_context->current_folder_name == E_JMMS_WRITE_MMS ||
         g_jmms_context->store_context->current_folder_name == E_JMMS_TEMPLATES ||
         g_jmms_context->store_context->current_folder_name == E_JMMS_DRAFTS))
    {
        /* Check that any slide exists */
        mmi_jmms_jdi_get_total_pages(g_jmms_context->msg_handle, &page_count);
        if (page_count != 0)
        {
            /* Check if the last slide is signature */
            err_code = mmi_jmms_compose_get_media_list(page_count, &media_info_p, &media_count, MMI_FALSE);
            if (media_count == 1 && media_info_p->eMediaType == E_MEDIA_TEXT)
            {
                if (mmi_ucs2cmp
                    ((S8*) (UI_character_type*) media_info_p->pMimeInfo->ContentData.pBuffer,
                     (S8*) g_jmms_context->nvram_compose_settings.auto_signature_content) == 0)
                {
                    is_sig_existed = TRUE;
                }
            }

            /* Delete signature slide */
            if (is_sig_existed)
            {
                /* Free all data in the slide */
                mmi_jmms_compose_delete_page(page_count);
                /* g_jmms_context->compose_context will be NULL in case of Drafts->Option->Send */
                if (g_jmms_context->compose_context)
                {
                    g_jmms_context->compose_context->curr_page_index--;
                }
            }
        }
        g_jmms_context->auto_signature_added = MMI_FALSE;
    }
    return err_code;
}

//#endif /* __MMI_MMS_SIGNATURE__ */ 
//PMT VIKAS END 20060405
//PMT VIKAS START 20060403


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_add_media
 * DESCRIPTION
 *  fn to add media.
 * PARAMETERS
 *  path_p              [IN]        
 *  type                [IN]        
 *  is_attachment       [IN]        
 *  page_index          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
JMMS_COMP_ERRCODE mmi_jmms_compose_add_media(void *path_p, U8 type, U8 is_attachment, U8 page_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MEDIA_INFO *media_info_p;
    S8 *file_name_p;
    U32 file_size = 0;

    /* FS_HANDLE  file_handle; */
    JC_RETCODE ret_code = JC_OK;
    JMMS_COMP_ERRCODE err_code;
    JMMS_COMP_ERRCODE err_code_time;
    U32 media_id;
    JDD_FILE file_handle;

#ifdef __DRM_SUPPORT__
    U32 drm_method = DRM_METHOD_NONE;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_jmms_compose_add_media");
    media_info_p = (MEDIA_INFO*) jdd_MemAlloc(sizeof(MEDIA_INFO), sizeof(U8));
    if (media_info_p == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }

    if (g_jmms_context->jmms_fs_handle == NULL)
    {
        if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
        {
            ret_code = JC_ERR_FILE_SYS_INIT;
            goto ERROR_HANDLE;
        }
    }

    file_name_p = mmi_fmgr_extract_file_name((S8*) path_p);

    file_handle = jdd_FSOpen(g_jmms_context->jmms_fs_handle, (U16*) path_p, E_OPEN_READ_MODE);

    if (file_handle == NULL)
    {
        ret_code = JC_ERR_FILE_OPEN;
        goto ERROR_HANDLE;
    }

    jdd_FSGetSize(file_handle, &file_size);

    jdd_FSClose(file_handle);

    media_info_p->pMimeInfo = (MEDIA_MIME_INFO*) jdd_MemAlloc(sizeof(MEDIA_MIME_INFO), sizeof(U8));
    if (media_info_p->pMimeInfo == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }

    media_info_p->eMediaType = type;

    if (is_attachment == E_FALSE && (type == E_MEDIA_IMAGE || type == E_MEDIA_VIDEO))
    {
        U8 size;

        size = strlen(STRING_IMAGE);
        media_info_p->PresentationInfo.pRegionName = (JC_CHAR*) jdd_MemAlloc(sizeof(JC_CHAR), size + 1);
        if (media_info_p->PresentationInfo.pRegionName == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto ERROR_HANDLE;
        }
        mmi_asc_to_ucs2((PS8) (media_info_p->PresentationInfo.pRegionName), (PS8) (STRING_IMAGE));
    }

    media_info_p->pMimeInfo->ContentData.bIsStream = E_TRUE;

    media_info_p->pMimeInfo->bIsDRM = g_jmms_context->is_add_media_as_drm;  /**Added by Vikas for checking whether media id added as DRM or not**/

    media_info_p->pMimeInfo->ContentData.eCopyMemory = E_FALSE;
    media_info_p->pMimeInfo->ContentData.pBuffer = NULL;
    media_info_p->pMimeInfo->ContentData.uiCurSize = 0;
    media_info_p->pMimeInfo->ContentData.uiTotalSize = file_size;
    media_info_p->pMimeInfo->ContentData.cbReadCallback = mmi_jmms_read_callback;
    media_info_p->pMimeInfo->ContentData.cbWriteCallback = NULL;
    media_info_p->pMimeInfo->ContentData.uiStartOffset = 0;
    media_info_p->pMimeInfo->ContentData.pFileName =
        (JC_CHAR*) jdd_MemAlloc((jc_tcslen((JC_CHAR*) path_p) + 1), sizeof(JC_CHAR));

    if (media_info_p->pMimeInfo->ContentData.pFileName == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }
    jc_tcscpy((UI_character_type*) media_info_p->pMimeInfo->ContentData.pFileName, (UI_character_type*) path_p);
    media_info_p->pMimeInfo->ContentData.pStream = media_info_p->pMimeInfo->ContentData.pFileName;

    media_info_p->pMimeInfo->MimeHeaders.bIsAttachment = is_attachment;

    if ((GetUCS2Flag((S8*) file_name_p) == FALSE) && (is_extended_char_present((S8*) file_name_p) == FALSE))
    {
        media_info_p->pMimeInfo->MimeHeaders.pObjectName =
            (JC_CHAR*) jdd_MemAlloc((jc_tcslen((JC_CHAR*) file_name_p) + 1), sizeof(JC_CHAR));

        if (media_info_p->pMimeInfo->MimeHeaders.pObjectName == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto ERROR_HANDLE;
        }

        jc_tcscpy((JC_CHAR*) media_info_p->pMimeInfo->MimeHeaders.pObjectName, (JC_CHAR*) file_name_p);
    }
    else
    {
        ret_code = mmi_jmms_convert_chinese_english_filename(
                    (JC_CHAR **) & (media_info_p->pMimeInfo->MimeHeaders.pObjectName),
                    (JC_CHAR*) file_name_p);
        if (ret_code != JC_OK)
        {
            goto ERROR_HANDLE;
        }
    }

#ifdef __DRM_SUPPORT__
    drm_method = mmi_jmms_get_drm_method_type(path_p);
#ifdef __DRM_ODF_SUPPORT__
    if (drm_method == DRM_METHOD_V2)
    {
        media_info_p->pMimeInfo->MimeHeaders.pContentType = jdi_UtilsStrdup(APPLICATION_VND_OMA_DRM_CONTENT_V2);
    }
    else
#endif /* __DRM_ODF_SUPPORT__ */ 
    {
        if (drm_method == DRM_METHOD_SEPARATE_DELIVERY)
        {
            media_info_p->pMimeInfo->MimeHeaders.pContentType = jdi_UtilsStrdup(APPLICATION_VND_OMA_DRM_CONTENT);
        }
        else
#endif /* __DRM_SUPPORT__ */ 
        {
            media_info_p->pMimeInfo->MimeHeaders.pContentType =
                (JC_INT8*) mmi_mms_get_mms_content_type_file((UI_character_type*) file_name_p, type);
        }
    #ifdef __DRM_SUPPORT__
    }
    #endif 
    if (media_info_p->pMimeInfo->MimeHeaders.pContentType == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }

    /* add media */
    ret_code = mmi_jmms_jdi_add_media(g_jmms_context->msg_handle, media_info_p, page_index, &media_id);
    if (ret_code != JC_OK)
    {
        goto ERROR_HANDLE;
    }
#ifdef __DRM_SUPPORT__
    if (g_jmms_context->is_add_media_as_drm)
    {
        ret_code = jdi_MsgSetMediaDRMType(
                    g_jmms_context->msg_handle,
                    page_index,
                    media_id,
                    E_DRM_FWD_LOCK,
                    media_info_p->pMimeInfo->MimeHeaders.bIsAttachment);
        mmi_jmms_jdi_msg_register_callback(
            g_jmms_context->msg_handle,
            E_CB_DRM_COMPOSE,
            (void*)mmi_jmms_drm_compose_handler);

        g_jmms_context->is_add_media_as_drm = MMI_FALSE;
    }
    else
    {
        ret_code = jdi_MsgSetMediaDRMType(
                    g_jmms_context->msg_handle,
                    page_index,
                    media_id,
                    E_DRM_NONE,
                    media_info_p->pMimeInfo->MimeHeaders.bIsAttachment);
    }
#endif /* __DRM_SUPPORT__ */ 
  ERROR_HANDLE:
    err_code = mmi_jmms_compose_handle_error(ret_code, 0);

    switch (err_code)
    {
        case JMMS_COMP_OK:
        case JMMS_COMP_POPUP_OK:
        {
            if (is_attachment == E_FALSE)
            {
                U32 start_time = 0;
                U32 duration = 0, audio_duration = 0;
                U32 max = 999;

            #ifdef __MMI_VIDEO_PLAYER__
                U64 video_duration = 0;
            #endif 

                switch (type)
                {
                    case E_MEDIA_IMAGE:
                    {
                        g_jmms_context->compose_context->curr_slide_info.image_id = media_id;
                        g_jmms_context->compose_context->curr_slide_info.img_info.file_name_p =
                            (U8*) media_info_p->pMimeInfo->ContentData.pFileName;
                        break;
                    }
                    case E_MEDIA_AUDIO:
                        g_jmms_context->compose_context->curr_slide_info.audio_id = media_id;
                        mdi_audio_get_duration((S8*) path_p, &audio_duration);
                        duration = audio_duration / 1000;
                        duration = (duration >= max) ? max : ((audio_duration % 1000) > 0) ? (duration + 1) : duration;
                        err_code_time = mmi_jmms_set_media_time(
                                            start_time,
                                            duration,
                                            g_jmms_context->compose_context->curr_slide_info.audio_id,
                                            g_jmms_context->compose_context->curr_page_index);
                        break;
                    case E_MEDIA_VIDEO:
                        g_jmms_context->compose_context->curr_slide_info.video_id = media_id;
                        g_jmms_context->compose_context->curr_slide_info.img_info.file_name_p =
                            (U8*) media_info_p->pMimeInfo->ContentData.pFileName;
                #ifdef __MMI_VIDEO_PLAYER__
                        video_duration = mmi_jdd_videoapp_get_video_file_duration_info((S8*) path_p);
                        duration = (U32) (video_duration / 1000);
                        duration = (duration >= max) ? max : ((video_duration % 1000) > 0) ? (duration + 1) : duration;
                        err_code_time = mmi_jmms_set_media_time(
                                            start_time,
                                            duration,
                                            g_jmms_context->compose_context->curr_slide_info.video_id,
                                            g_jmms_context->compose_context->curr_page_index);
                #endif /* __MMI_VIDEO_PLAYER__ */ 
                        break;
                }
            }
            else
            {
                g_jmms_context->num_attachments++;
            }
        }
            break;
        case JMMS_COMP_FAIL:
        case JMMS_COMP_OUT_MEMORY:  /* deallocate memory for new slide and out of mmeory case. */
        {
            if (media_info_p != NULL)
            {
                if (media_info_p->pMimeInfo != NULL)
                {
                    if (media_info_p->pMimeInfo->ContentData.pFileName != NULL)
                    {
                        jdd_MemFree(media_info_p->pMimeInfo->ContentData.pFileName);
                    }

                    if (media_info_p->pMimeInfo->MimeHeaders.pContentType != NULL)
                    {
                        jdd_MemFree(media_info_p->pMimeInfo->MimeHeaders.pContentType);
                    }
                    if (media_info_p->pMimeInfo->MimeHeaders.pObjectName != NULL)
                    {
                        jdd_MemFree(media_info_p->pMimeInfo->MimeHeaders.pObjectName);
                    }

                    jdd_MemFree(media_info_p->pMimeInfo);
                }
                if (media_info_p->PresentationInfo.pRegionName != NULL)
                {
                    jdd_MemFree(media_info_p->PresentationInfo.pRegionName);
                }
                jdd_MemFree(media_info_p);
                media_info_p = NULL;
            }

        }
            err_code = JMMS_COMP_FAIL;
            break;
        case JMMS_COMP_NEW_SLIDE:
        {
            JMMS_COMP_ERRCODE temp_err_code;

            if (media_info_p != NULL)
            {
                if (media_info_p->pMimeInfo != NULL)
                {
                    if (media_info_p->pMimeInfo->ContentData.pFileName != NULL)
                    {
                        jdd_MemFree(media_info_p->pMimeInfo->ContentData.pFileName);
                    }

                    if (media_info_p->pMimeInfo->MimeHeaders.pContentType != NULL)
                    {
                        jdd_MemFree(media_info_p->pMimeInfo->MimeHeaders.pContentType);
                    }
                    if (media_info_p->pMimeInfo->MimeHeaders.pObjectName != NULL)
                    {
                        jdd_MemFree(media_info_p->pMimeInfo->MimeHeaders.pObjectName);
                    }

                    jdd_MemFree(media_info_p->pMimeInfo);
                }
                if (media_info_p->PresentationInfo.pRegionName != NULL)
                {
                    jdd_MemFree(media_info_p->PresentationInfo.pRegionName);
                }
                jdd_MemFree(media_info_p);
                media_info_p = NULL;
            }

            temp_err_code = mmi_jmms_compose_insert_slide();
            if (temp_err_code == JMMS_COMP_OK)
            {
                HistoryReplace(SCR_ID_JMMS_EDIT_CONTENT, SCR_ID_JMMS_EDIT_CONTENT, mmi_jmms_entry_edit_content_screen); /* to delete guibuffer details as entering new slide. */
                temp_err_code = mmi_jmms_compose_add_media(path_p, type, is_attachment, (U8) (page_index + 1));
            }
            if (temp_err_code != JMMS_COMP_OK)
            {
                err_code = temp_err_code;
            }
            else
            {
                err_code = JMMS_COMP_POPUP_OK;
            }
        }
            break;
    }

    mmi_jmms_set_region_list();

    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
    }
    if (media_info_p != NULL)
    {
        jdd_MemFree(media_info_p);
        media_info_p = NULL;
    }
    return err_code;

}

/* Dilip Start 14th sept for slide time issue */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_save_post_entry_edit_content_slide_timing
 * DESCRIPTION
 *  fn check the slide timings after user return from Media timing setting and try to reduce slide time.
 *  We are setting as custom if media start time is made greater than equal to slide time and maximum is set for that media
 * PARAMETERS
 *  slide_time      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
JMMS_COMP_ERRCODE mmi_jmms_save_post_entry_edit_content_slide_timing(U32 slide_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

    U32 start_time_text, start_time_image, start_time_audio, start_time_video;
    U32 text_duration, image_duration, audio_duration, video_duration;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (slide_time == 0)
    {
        return err_code;
    }

    if (g_jmms_context->compose_context->curr_slide_info.text_id > 0)
    {
        err_code = mmi_jmms_get_media_time(
                    &start_time_text,
                    &text_duration,
                    g_jmms_context->compose_context->curr_slide_info.text_id,
                    g_jmms_context->compose_context->curr_page_index);
        if (err_code == JMMS_COMP_OK)
        {
            if (start_time_text >= slide_time)
            {
                return JMMS_COMP_FAIL;
            }
        }

    }

    if (g_jmms_context->compose_context->curr_slide_info.image_id > 0)
    {
        err_code = mmi_jmms_get_media_time(
                    &start_time_image,
                    &image_duration,
                    g_jmms_context->compose_context->curr_slide_info.image_id,
                    g_jmms_context->compose_context->curr_page_index);
        if (err_code == JMMS_COMP_OK)
        {
            if (start_time_image >= slide_time)
            {
                return JMMS_COMP_FAIL;
            }
        }
    }

    if (g_jmms_context->compose_context->curr_slide_info.audio_id > 0)
    {
        err_code = mmi_jmms_get_media_time(
                    &start_time_audio,
                    &audio_duration,
                    g_jmms_context->compose_context->curr_slide_info.audio_id,
                    g_jmms_context->compose_context->curr_page_index);
        if (err_code == JMMS_COMP_OK)
        {
            if (start_time_audio >= slide_time)
            {
                return JMMS_COMP_FAIL;
            }

        }
    }

    if (g_jmms_context->compose_context->curr_slide_info.video_id > 0)
    {

        err_code = mmi_jmms_get_media_time(
                    &start_time_video,
                    &video_duration,
                    g_jmms_context->compose_context->curr_slide_info.video_id,
                    g_jmms_context->compose_context->curr_page_index);
        if (err_code == JMMS_COMP_OK)
        {
            if (start_time_video >= slide_time)
            {
                return JMMS_COMP_FAIL;
            }
        }
    }
    return err_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_create_mms_for_file
 * DESCRIPTION
 *  Checks whether file need to be added as DRM fwd-lock
 * PARAMETERS
 *  content_source_p        [IN]        
 *  callback                [IN]        
 *  callback_param_p        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 g_media_type;
static JC_CHAR *g_content_file_name;
void mmi_jmms_create_mms_for_file(JC_CHAR *content_source_p, fwd_callback callback, void *callback_param_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_create_mms_for_file");
    mmi_jmms_create_mms_for_general_insert(NULL, NULL, content_source_p, NULL, callback, callback_param_p);
    return;
}

/* HIMANSHU 05122006 START */
#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  check_for_image_resize
 * DESCRIPTION
 *  If the image resizing is being set to TRUE then it calls function to resize the
 *  image.
 *  tries to resize the image.
 * PARAMETERS
 *  content_source_p        [IN]        
 *  dest_fname_p            [OUT]       
 * RETURNS
 *  JMMS_IMAGE_RESIZE_FAILED if image can't be resized
 *  JMMS_IMAGE_RESIZE_UNCHANGED if iamge original size is less than the image resize settings
 *  JMMS_IMAGE_RESIZE_SUCCEED otherwise.
 *****************************************************************************/
S16 check_for_image_resize(JC_CHAR *content_source_p, JC_CHAR **dest_fname_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 image_resize_option = E_IMAGE_RESIZE_OFF;
    S32 resize_width = 0;
    S32 resize_height = 0;
    JC_RETCODE ret_code = JC_OK;
    JC_CHAR *temp_file_p = NULL;
    S16 resize_result = JMMS_IMAGE_RESIZE_UNCHANGED;
    JDD_FSHANDLE fs_handle = NULL;
    JDD_FILE fh = NULL;
    GDI_RESULT gdi_ret = GDI_FAILED;
    S32 img_width = 0, img_height = 0;
    S8 name[40] = {0, };
    kal_uint32 unique_value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside check_for_image_resize");
    image_resize_option = g_jmms_context->nvram_compose_settings.image_resize_option;

    if (image_resize_option != E_IMAGE_RESIZE_OFF)
    {
        switch (image_resize_option)
        {
            case E_IMAGE_RESIZE_160x120:
                resize_width = 160;
                resize_height = 120;
                break;

            case E_IMAGE_RESIZE_320x240:
                resize_width = 320;
                resize_height = 240;
                break;

            case E_IMAGE_RESIZE_640x480:
                resize_width = 640;
                resize_height = 480;
                break;

            default:
                ASSERT(0);
        }

        gdi_ret = gdi_image_get_dimension_file((PS8) content_source_p, &img_width, &img_height);
        if (img_width > resize_width || img_height > resize_height)
        {
            ret_code = jdd_FSInitialize(&fs_handle);
            if (ret_code != JC_OK)
            {
                /* return JMMS_IMAGE_RESIZE_FAILED; */
                resize_result = JMMS_IMAGE_RESIZE_FAILED;
                goto END;
            }

            /* Himanshu Fix PMTSW00006574 START */
            /* Creation of @mms\\temp\\resize folder */
            mmi_asc_to_ucs2(name, "@mms\\temp\\resize\\");
            fh = jdd_FSOpen(fs_handle, (U16*) name, E_OPEN_READ_MODE);

            if (fh == NULL) /* Folder Does Not Exist */
            {
                jdd_FSMakeDir(fs_handle, (U16*) name);
            }
            else
            {
                jdd_FSClose(fh);
            }

            kal_get_time(&unique_value);
            sprintf(name, "@mms\\temp\\resize\\img%d.%s", unique_value, "jpg");
            jdi_UtilsCharToTchar((JC_CHAR **) & (temp_file_p), name);
            /* Himanshu Fix PMTSW00006574 END */

            *dest_fname_p = (JC_CHAR*) jdd_FSFileNameTranslate(fs_handle, temp_file_p);
            if (*dest_fname_p == NULL)
            {
                /* return JMMS_IMAGE_RESIZE_FAILED; */
                resize_result = JMMS_IMAGE_RESIZE_FAILED;
                goto END;
            }

            mmi_jmms_ext_display_image_animation();

            resize_result = mmi_jmms_ext_image_resizing(content_source_p, *dest_fname_p, resize_width, resize_height);

            //jdd_MemFree(temp_file_p);
            //jdd_FSDeinitialize(fs_handle);

            switch (resize_result)
            {
                case JMMS_IMAGE_RESIZE_UNCHANGED:
                case JMMS_IMAGE_RESIZE_SUCCEED:
                    ClearKeyEvents();   /* Flush all the Key Events */
                    break;

                case JMMS_IMAGE_RESIZING_FAILED_IN_GDI_ENCODER_ERR_DISK_FULL:
                    DisplayPopup(
                        (PU8) GetString(STR_ID_JMMS_STORAGE_FULL),
                        IMG_GLOBAL_ERROR,
                        1,
                        JMMS_POPUP_TIME,
                        ERROR_TONE);
                    /* GoBackHistory(); */
                    break;

                case JMMS_IMAGE_RESIZING_FAILED_IN_INSUFFICIENT_DRAWING_BUF:
                case JMMS_IMAGE_RESIZING_FAILED_IN_NO_QUOTA:
                    DisplayPopup(
                        (PU8) GetString(STR_ID_JMMS_FAILED_RESOURCES_EXHAUSTED),
                        IMG_GLOBAL_ERROR,
                        1,
                        JMMS_POPUP_TIME,
                        ERROR_TONE);
                    /* GoBackHistory(); */
                    break;

                case JMMS_IMAGE_RESIZING_FAILED_IN_UNKNOWN_DIMENSION:
                    DisplayPopup(
                        (PU8) GetString(STR_ID_JMMS_CORRUPTED_MEDIA_FILE),
                        IMG_GLOBAL_ERROR,
                        1,
                        JMMS_POPUP_TIME,
                        ERROR_TONE);
                    /* GoBackHistory(); */
                    break;

                case JMMS_IMAGE_RESIZING_FAILED_IN_GDI_FAILED:
                case JMMS_IMAGE_RESIZING_FAILED_IN_GDI_ENCODER_ERR_NO_DISK:
                case JMMS_IMAGE_RESIZING_FAILED_IN_GDI_ENCODER_ERR_WRITE_PROTECTION:
                default:
                    DisplayPopup(
                        (PU8) GetString(STR_ID_JMMS_IMAGE_RESIZE_FAILED),
                        IMG_GLOBAL_ERROR,
                        1,
                        JMMS_POPUP_TIME,
                        ERROR_TONE);
                    /* GoBackHistory(); */
                    break;
            }
        }
    }

  END:
    if (temp_file_p != NULL)
    {
        jdd_MemFree(temp_file_p);
    }
    if (fs_handle != NULL)
    {
        jdd_FSDeinitialize(fs_handle);
    }
    return resize_result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_ext_display_image_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_ext_display_image_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->resize_animation_disable_status = RESIZE_ANIMATION_DISABLE_ON;
    mmi_jmms_display_resize_image_animation();
    g_jmms_context->resize_animation_disable_status = RESIZE_ANIMATION_DISABLE_OFF;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_display_resize_image_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_display_resize_image_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_JMMS_IMAGE_RESIZE_TRANSITION))
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, " %s(%d) DisplayImageTransitionAnimation() - already exist\n", __FILE__,
                             __LINE__);
        return;
    }

    PRINT_INFORMATION_2(MMI_TRACE_INFO, " %s(%d) DisplayImageTransitionAnimation()\n", __FILE__, __LINE__);

    mmi_jmms_entry_resize_image_animation();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_resize_image_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_resize_image_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_IMAGE_RESIZE_TRANSITION, NULL, mmi_jmms_entry_resize_image_animation, NULL);

    /* draw the blank softkey if no softkey button */
    show_softkey_background();

    ShowCategory66Screen(
        STR_MMS_MENUENTRY,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_ID_SETTINGS_IMAGE_RESIZE),
        IMG_ID_JMMS_PROGRESS,
        0);

    ClearAllKeyHandler();   /* End key is still valid */
    if (g_jmms_context->resize_animation_disable_status == RESIZE_ANIMATION_DISABLE_ON)
    {
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_ext_image_resizing
 * DESCRIPTION
 *  This function does the resizing of image.
 * PARAMETERS
 *  source_file_p       [IN]        
 *  dest_file_p         [IN]        
 *  resize_width        [IN]        
 *  resize_height       [IN]        
 * RETURNS
 *  JMMS_IMAGE_RESIZE_FAILED if image can't be resized
 *  JMMS_IMAGE_RESIZE_UNCHANGED if iamge original size is less than the image resize settings
 *  JMMS_IMAGE_RESIZE_SUCCEED otherwise.
 *****************************************************************************/
S16 mmi_jmms_ext_image_resizing(JC_CHAR *source_file_p, JC_CHAR *dest_file_p, S32 resize_width, S32 resize_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 img_width = 0, img_height = 0;
    S32 temp_width = 0, temp_height = 0;
    GDI_RESULT gdi_ret = GDI_FAILED;
    S32 buf_size = 0;
    U8 *buf_ptr_p;
    S16 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(source_file_p != NULL);
    ASSERT(dest_file_p != NULL);

    PRINT_INFORMATION_2(MMI_TRACE_INFO, " %s(%d) Image Resizing Starts \n", __FILE__, __LINE__);

    /* Get the image dimension */
    gdi_ret = gdi_image_get_dimension_file((PS8) source_file_p, &img_width, &img_height);
    if ((img_width >= 0) && (img_height >= 0))
    {
        /* calculate the dimension of the resize JPEG */
        if ((img_width > resize_width) || (img_height > resize_height))
        {
            /* need to resize */
            if ((img_width * resize_height) > (img_height * resize_width))
            {
                temp_width = resize_width;
                temp_height = img_height * resize_width / img_width;
                if (temp_height == 0)
                {
                    temp_height = 1;
                }
            }
            else
            {
                temp_width = img_width * resize_height / img_height;
                temp_height = resize_height;
                if (temp_width == 0)
                {
                    temp_width = 1;
                }
            }

            /* resize the image and encode to jpef file */
            buf_size = (temp_width * temp_height * 16) >> 3;
            buf_size = ((buf_size + 3) / 4) * 4;
            if (buf_size > 0)
            {
                media_get_ext_buffer(MOD_MMI, (void **)&buf_ptr_p, buf_size);
                if (buf_ptr_p != NULL)
                {
                    gdi_ret = gdi_image_encode_file_to_jpeg(
                                (PS8) source_file_p,
                                (PS8) dest_file_p,
                                temp_width,
                                temp_height,
                                buf_ptr_p,
                                buf_size);
                    media_free_ext_buffer(MOD_MMI, (void **)&buf_ptr_p);
                }
                switch (gdi_ret)
                {
                    case GDI_SUCCEED:
                        ret = JMMS_IMAGE_RESIZE_SUCCEED;
                        break;
                    case GDI_IMAGE_ENCODER_ERR_DISK_FULL:
                        ret = JMMS_IMAGE_RESIZING_FAILED_IN_GDI_ENCODER_ERR_DISK_FULL;
                        break;
                    case GDI_IMAGE_ENCODER_ERR_WRITE_PROTECTION:
                        ret = JMMS_IMAGE_RESIZING_FAILED_IN_GDI_ENCODER_ERR_WRITE_PROTECTION;
                        break;
                    case GDI_IMAGE_ENCODER_ERR_NO_DISK:
                        ret = JMMS_IMAGE_RESIZING_FAILED_IN_GDI_ENCODER_ERR_NO_DISK;
                        break;
                    default:
                        ret = JMMS_IMAGE_RESIZE_FAILED;
                }
            }
            else
            {
                ret = JMMS_IMAGE_RESIZING_FAILED_IN_INSUFFICIENT_DRAWING_BUF;
            }
        }
        else
        {
            /* the dimension of the original image is smaller */
            ret = JMMS_IMAGE_RESIZE_UNCHANGED;
        }
    }
    else
    {
        ret = JMMS_IMAGE_RESIZING_FAILED_IN_UNKNOWN_DIMENSION;
    }

    PRINT_INFORMATION_2(MMI_TRACE_INFO, " (%d) Image Resizing returns with code(%d) \n", __LINE__, ret);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_delete_resized_temp_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name_p     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_delete_resized_temp_file(S8 *file_name_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JDD_FSHANDLE fs_handle = NULL;
    S8 *temp_file_p = NULL;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_file_p = (S8*) jdd_MemAlloc(mmi_ucs2strlen((PS8) file_name_p) + 1, 1);
    if (temp_file_p != NULL)
    {
        mmi_ucs2_to_asc((PS8) temp_file_p, (PS8) file_name_p);
        if ((strstr((PS8) temp_file_p, (PS8) "@mms\\temp\\resize")) != NULL)
        {
            ret_code = jdd_FSInitialize(&fs_handle);
            if (ret_code == JC_OK)
            {
                jdd_FSDelete(fs_handle, (JC_CHAR*) file_name_p);
                jdd_FSDeinitialize(fs_handle);
            }
        }
        jdd_MemFree(temp_file_p);
    }
}

#endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 
/* HIMANSHU 05122006 END */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_create_mms_to_address
 * DESCRIPTION
 *  Add the file content to MMS according to their Media type.
 * PARAMETERS
 *  address_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_create_mms_to_address(JC_CHAR *address_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_create_mms_to_address");
    mmi_jmms_create_mms_for_general_insert(address_p, NULL, NULL, NULL, NULL, NULL);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_create_mms_for_barcode
 * DESCRIPTION
 *  This function is written to add the subject and text of 2D Barcode into
 *  the new MMS.
 * PARAMETERS
 *  subject_p       [IN]        
 *  subject_len     [IN]        
 *  test_p          [IN]        
 *  text_len        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_BARCODEREADER__

void mmi_jmms_create_mms_for_barcode(JC_CHAR *subject_p, U32 subject_len, JC_CHAR *test_p, U32 text_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_create_mms_for_barcode");
    mmi_jmms_create_mms_for_general_insert_internal(
        NULL,
        subject_p,
        subject_len * ENCODING_LENGTH,
        NULL,
        test_p,
        text_len * ENCODING_LENGTH,
        NULL,
        NULL);
    return;
}
#endif /* __MMI_BARCODEREADER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_general_mms
 * DESCRIPTION
 *  Add the content to MMS according to their Media type.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_compose_general_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    JMMS_COMP_ERRCODE err_code1 = JMMS_COMP_OK, err_code2 = JMMS_COMP_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearAllKeyHandler();
    if (mmi_ucs2strlen((S8*) g_jmms_context->compose_context->curr_slide_info.edit_content_buffer) != 0)
    {
        /* To add the text with the MMS */
        err_code1 = mmi_jmms_compose_add_text(
                        g_jmms_context->compose_context->curr_page_index,
                        &(g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font),
                        g_jmms_context->compose_context->curr_slide_info.slide_prop.text_color,
                        1);
    }
    if (g_content_file_name != NULL)
    {
        switch (g_media_type)
        {
            case MEDIA_IMAGE:
                err_code2 = mmi_jmms_compose_add_media(
                                g_content_file_name,
                                E_MEDIA_IMAGE,
                                0,
                                g_jmms_context->compose_context->curr_page_index);
                break;
            case MEDIA_AUDIO:
                err_code2 = mmi_jmms_compose_add_media(
                                g_content_file_name,
                                E_MEDIA_AUDIO,
                                0,
                                g_jmms_context->compose_context->curr_page_index);
                break;
            case MEDIA_VIDEO:
                err_code2 = mmi_jmms_compose_add_media(
                                g_content_file_name,
                                E_MEDIA_VIDEO,
                                0,
                                g_jmms_context->compose_context->curr_page_index);
                break;
            case MEDIA_OTHER:
            default:
                err_code2 = mmi_jmms_compose_add_media(g_content_file_name, E_MEDIA_OTHERS, E_TRUE, 0);
                mmi_jmms_compose_delete_page(g_jmms_context->compose_context->curr_page_index);
                g_jmms_context->compose_context->curr_page_index--;
                break;
        }
        if ((err_code1 == JMMS_COMP_OK || err_code1 == JMMS_COMP_POPUP_OK) &&
            (err_code2 == JMMS_COMP_OK || err_code2 == JMMS_COMP_POPUP_OK))
        {
            /* to overcome 200KB size file acting restricted mode media instead of warning mode */
            if (g_media_type == E_MEDIA_IMAGE || g_media_type == E_MEDIA_VIDEO)
            {
                /* to overcome 200KB size file acting restricted mode media instead of warning mode */
                g_jmms_context->compose_context->curr_slide_info.img_info.custom_img_display = 1;

                if (mmi_ucs2strlen((S8*) g_jmms_context->compose_context->curr_slide_info.edit_content_buffer) == 0)
                {
                    g_jmms_context->compose_context->is_image_first[g_jmms_context->compose_context->curr_page_index -
                                                                    1] = 1;
                }
                else
                {
                    g_jmms_context->compose_context->is_image_first[g_jmms_context->compose_context->curr_page_index -
                                                                    1] = 0;
                }
            }

            g_jmms_context->g_write_mms_right_soft_key = STR_GLOBAL_DONE;
            if (err_code1 == JMMS_COMP_POPUP_OK || err_code2 == JMMS_COMP_POPUP_OK)
            {
                mmi_jmms_entry_write_message_screen_in_history();
            }
            else
            {
                mmi_jmms_entry_write_message_screen();
            }
        }
        else
        {
            mmi_jmms_deinit_mms_context(g_jmms_context);
        }
    }
    else
    {
        g_jmms_context->g_write_mms_right_soft_key = STR_GLOBAL_DONE;
        mmi_jmms_entry_write_message_screen();
    }

    if (g_content_file_name != NULL)
    {
        jdd_MemFree(g_content_file_name);
        g_content_file_name = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_create_mms_for_general_insert
 * DESCRIPTION
 *  This function is written to compose a general insert call
 *  the new MMS.
 * PARAMETERS
 *  address_p               [IN]        Address
 *  subject_p               [IN]        Subject
 *  content_source_p        [IN]        File path
 *  text_p                  [IN]        Text
 *  callback                [IN]        Application callback
 *  callback_param_p        [IN]        Callback parameter
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_create_mms_for_general_insert(
        JC_CHAR *address_p,
        JC_CHAR *subject_p,
        JC_CHAR *content_source_p,
        JC_CHAR *text_p,
        fwd_callback callback,
        void *callback_param_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 subject_len = 0;
    U32 text_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (subject_p != NULL)
    {
        subject_len = (U8) (mmi_ucs2strlen((S8*) subject_p) * ENCODING_LENGTH);
    }
    if (text_p != NULL)
    {
        text_len = (U8) (mmi_ucs2strlen((S8*) text_p) * ENCODING_LENGTH);
    }
    mmi_jmms_create_mms_for_general_insert_internal(
        address_p,
        subject_p,
        subject_len,
        content_source_p,
        text_p,
        text_len,
        callback,
        callback_param_p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_create_mms_for_general_insert_internal
 * DESCRIPTION
 *  This function is written to compose a general insert call
 *  the new MMS.
 * PARAMETERS
 *  address_p               [IN]        Address
 *  subject_p               [IN]        Subject
 *  subject_len             [IN]        Subject length
 *  content_source_p        [IN]        File path
 *  text_p                  [IN]        Text
 *  text_len                [IN]        Text length
 *  callback                [IN]        Application callback
 *  callback_param_p        [IN]        Callback parameter
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_create_mms_for_general_insert_internal(
        JC_CHAR *address_p,
        JC_CHAR *subject_p,
        U32 subject_len,
        JC_CHAR *content_source_p,
        JC_CHAR *text_p,
        U32 text_len,
        fwd_callback callback,
        void *callback_param_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    JC_CHAR *content_file_name_p = content_source_p;
    U8 media_type = 0;

#ifdef __MMI_VIDEO_PLAYER__
    MDI_RESULT result_video = 0;
#endif 
    MMI_BOOL result_media = MMI_TRUE;
    GDI_RESULT image_result;
    S32 audio_result = 0;
    S32 img_widthv = 0, img_heightv = 0, audio_du;

#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
    JC_CHAR *dest_fname_p = NULL;
    U32 resize_result = 0;
#endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 
#ifdef __DRM_SUPPORT__
    JC_BOOLEAN is_drm_content = E_FALSE;
    JC_BOOLEAN is_forwardable = E_TRUE;
    JC_BOOLEAN permission = E_FALSE;
    JC_UINT8 check_permission = DRM_PERMISSION_NONE;
#endif /* __DRM_SUPPORT__ */ 
    U32 media_size = 0;
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_create_mms_for_general_insert");
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "Arg: a:%x s:%x fp:%x t:%x fn:%x fa:%x", address_p, subject_p,
                         content_source_p, text_p, callback, callback_param_p);
    jdd_MemSetActiveModuleID(E_TASK_MMS_UI);
    mmi_jmms_reset_fw_flag_of_message();
    g_jmms_context->is_add_media_as_drm = MMI_FALSE;
    if (mmi_jmms_is_ready_without_store(1))
    {
        return;
    }
    if (mms_is_re_entrant())
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_AVAILABLE), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, (U8) ERROR_TONE);
        return;
    }
    if (address_p != NULL)
    {
        if (MMI_FALSE == mmi_jmms_check_number_input_format((U8*) address_p))
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_JMMS_INPUT_FORMAT_ERROR),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                ERROR_TONE);
            return;
        }
    }

    mmi_jmms_init_msg_context_struct(); /* this will different for different ways */
    if (g_jmms_context->compose_context == NULL)
    {
        g_jmms_context->compose_context =
            (mmi_jmms_compose_context_struct*) jdd_MemAlloc(sizeof(mmi_jmms_compose_context_struct), 1);
        if (g_jmms_context->compose_context == NULL)
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "OUT OF MEMORY: Fail to create compose Context");
            DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto error;
        }

    }

    if (content_file_name_p != NULL)
    {
        if (mmi_ucs2str((S8*) content_file_name_p, (S8*) L"3gp") != NULL ||
            mmi_ucs2str((S8*) content_file_name_p, (S8*) L"mp4") != NULL)
        {
            if (mdi_audio_is_pure_audio(content_file_name_p) == KAL_TRUE)
            {
                media_type = E_MEDIA_AUDIO;
            }
            else
            {
                media_type = 0;
            }
        }
        media_type = mmi_jmms_get_mms_media_type_from_file(content_file_name_p, media_type);
    #ifdef __DRM_SUPPORT__
        if (media_type == MEDIA_IMAGE)
        {
            check_permission = DRM_PERMISSION_DISPLAY;
        }
        else if ((media_type == MEDIA_AUDIO) || (media_type == MEDIA_VIDEO))
        {
            check_permission = DRM_PERMISSION_PLAY;
        }
        else
        {
            check_permission = DRM_PERMISSION_NONE;
        }
        is_drm_content = mmi_jmms_process_drm_object(content_file_name_p, check_permission, &is_forwardable, &permission);
        if ((is_drm_content == E_FALSE) || ((is_drm_content == E_TRUE) && (permission == E_TRUE)))
    #endif /* __DRM_SUPPORT__ */ 
        {
        #ifdef __MMI_VIDEO_PLAYER__
            if (media_type == MEDIA_VIDEO)
            {
                result_video = mmi_jdd_videoapp_get_video_file_size_info(
                                (S8*) content_file_name_p,
                                (JC_UINT32*) & img_widthv,
                                (JC_UINT32*) & img_heightv);
                if (result_video == MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED)
                {
                    result_media = MMI_FALSE;
                }
            }
        #endif /* __MMI_VIDEO_PLAYER__ */ 
            if (media_type == MEDIA_IMAGE)
            {
                image_result = gdi_image_get_dimension_file((S8*) content_file_name_p, &img_widthv, &img_heightv);
                if (image_result != GDI_SUCCEED || (img_widthv * img_heightv) == 0)
                {
                    result_media = MMI_FALSE;
                }
            }

            if (media_type == MEDIA_AUDIO)
            {
                audio_result = mdi_audio_get_duration((S8*) content_source_p, (U32*) & audio_du);     /* compiler warning removal */
                if (audio_result != GDI_SUCCEED)
                {
                    result_media = MMI_FALSE;
                }
            }
            if (result_media == MMI_FALSE)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_JMMS_CORRUPTED_MEDIA_FILE),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    ERROR_TONE);
                ret_code = JC_ERR_UNKNOWN;
                goto error;
            }
        }
        if ((media_type == MEDIA_VIDEO || media_type == MEDIA_AUDIO) &&
            mmi_jmms_selected_media_valid_size_check_for_mms(
                (S8*) content_file_name_p,
                MMI_FALSE,
                &media_size,
                E_FALSE) != E_TRUE)
        {
            ret_code = JC_ERR_UNKNOWN;
            goto error;
        }
        else if ((media_type == MEDIA_IMAGE) &&
                 mmi_jmms_selected_media_valid_size_check_for_mms(
                    (S8*) content_file_name_p,
                    MMI_FALSE,
                    &media_size,
                    E_TRUE) != E_TRUE)
        {
            ret_code = JC_ERR_UNKNOWN;
            goto error;
        }

        if ((media_type == MEDIA_IMAGE) &&
            (mmi_jmms_check_for_image_size_and_resolution
             ((S8*) content_file_name_p, img_widthv, img_heightv, media_size) != E_TRUE))
        {
            ret_code = JC_ERR_UNKNOWN;
            goto error;
        }

    #ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
    #ifdef __DRM_SUPPORT__
        if ((is_drm_content == E_FALSE) && (media_type == MEDIA_IMAGE))
    #else 
        if (media_type == MEDIA_IMAGE)
    #endif 
        {
            /* Check if image resizing needs to be done. */
            resize_result = check_for_image_resize(content_file_name_p, &dest_fname_p);

            if (resize_result == JMMS_IMAGE_RESIZE_SUCCEED)
            {
                content_file_name_p = dest_fname_p;
            }
            else if (resize_result == JMMS_IMAGE_RESIZE_UNCHANGED)
            {
                /* content_file_name_p = content_source_p; */
            }
            else
            {
                ret_code = JC_ERR_UNKNOWN;
                goto error;
            }
        }
    #endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 
    }

    g_jmms_context->g_use_local_send_setings = 0;
    if (text_p != NULL || content_file_name_p != NULL)
    {
        mmi_jmms_fill_mms_sending_settings();
    }
    g_jmms_context->store_context->current_folder_name = E_JMMS_WRITE_MMS;
    g_jmms_context->compose_context->curr_page_index = 0;

    if (JMMS_COMP_OK == mmi_jmms_compose_new_mms())
    {
        U32 slide_time = 0;

        if (address_p != NULL)
        {
            g_jmms_context->address_list_flag = E_TO_ADDRESSES;
            ret_code = mmi_jmms_add_address_in_addresse_list((S8*) address_p);
            if (ret_code != 0)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_JMMS_MEMORY_FULL),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    (U8) ERROR_TONE);
                mmi_jmms_deinit_mms_context(g_jmms_context);
                return;
            }
        }
        if (text_p != NULL || content_file_name_p != NULL)
        {
            g_jmms_context->compose_context->mms_bg_color = g_jmms_color_RGB_list[COLOR_WHITE];
            /* Added for root layout. */
            err_code = mmi_jmms_set_bg_color(g_jmms_context->compose_context->mms_bg_color);
            if ((err_code == JMMS_COMP_OUT_MEMORY) || (err_code == JMMS_COMP_FAIL))
            {
                mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
                return;
            }
            err_code = mmi_jmms_compose_handle_error(mmi_jmms_jdi_add_page(g_jmms_context->msg_handle, 1), 1);
            if ((err_code == JMMS_COMP_OUT_MEMORY) || (err_code == JMMS_COMP_FAIL))
            {
                mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
                return;
            }
            g_jmms_context->compose_context->curr_page_index++;
            mmi_jmms_compose_fill_default_values_slide_settings();
            slide_time = mmi_jmms_compose_settings_default_slide_time();
            err_code = mmi_jmms_save_page_time(slide_time);
            if (err_code == JMMS_COMP_OK)
            {
                g_jmms_context->compose_context->curr_slide_info.slide_prop.slide_time = slide_time;
            }
            g_jmms_context->g_write_mms_right_soft_key = STR_GLOBAL_DONE;
        }

        /* To copy the subject content into the buffer */
        if (subject_p != NULL)
        {
            if (subject_len > (MAX_SUBJECT_LENGTH * ENCODING_LENGTH))
            {
                memcpy(g_jmms_context->subject_input_buffer, (S8*) subject_p, (MAX_SUBJECT_LENGTH * ENCODING_LENGTH));
            }
            else
            {
                memcpy(g_jmms_context->subject_input_buffer, (S8*) subject_p, subject_len);
            }

        }

        /* To copy the MMS content into the buffer. */
        if (text_p != NULL)
        {

            if (text_len > (JMMS_COMPOSE_TEXT_LENGTH * ENCODING_LENGTH))
            {
                memcpy(
                    g_jmms_context->compose_context->curr_slide_info.edit_content_buffer,
                    (S8*) text_p,
                    (JMMS_COMPOSE_TEXT_LENGTH * ENCODING_LENGTH));
            }
            else
            {
                memcpy(g_jmms_context->compose_context->curr_slide_info.edit_content_buffer, (S8*) text_p, text_len);
            }
        }

        if (content_file_name_p != NULL)
        {
            g_media_type = media_type;
            g_content_file_name = jdi_UtilsTcsDup(content_file_name_p);
            if (g_content_file_name == NULL)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "OUT OF MEMORY: Fail to create compose Context");
                DisplayPopup(
                    (PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    ERROR_TONE);
                ret_code = JC_ERR_MEMORY_ALLOCATION;
                goto error;
            }
        #ifdef __DRM_SUPPORT__
            if (mmi_jmms_is_compose_add_as_drm(content_source_p) && (is_drm_content == E_FALSE))
            {
                mmi_jmms_confirm_add_drm_media(mmi_jmms_compose_general_mms);
            }
            else
        #endif /* __DRM_SUPPORT__ */ 
            {
                mmi_jmms_compose_general_mms();
            }
        }
        else
        {
            mmi_jmms_compose_general_mms();
        }
    }
    g_jmms_context->content_fwd_callback = callback;
    g_jmms_context->content_fwd_callback_param = callback_param_p;

  error:

    if (ret_code != JC_OK)
    {
        if (callback)
        {
            callback(callback_param_p);
        }
    }
#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
#ifdef __DRM_SUPPORT__
    if ((is_drm_content == E_FALSE) && (media_type == MEDIA_IMAGE))
#else 
    if (media_type == MEDIA_IMAGE)
#endif 
    {
        if (dest_fname_p != NULL)
        {
            jdd_MemFree(dest_fname_p);
            dest_fname_p = NULL;
        }

        DeleteScreenIfPresent(SCR_ID_JMMS_IMAGE_RESIZE_TRANSITION);
    }
#endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_replace_media
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path_p              [IN]        
 *  type                [IN]        
 *  is_attachment       [IN]        
 *  page_index          [IN]        
 *  uiOldMediaID        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JMMS_COMP_ERRCODE mmi_jmms_compose_replace_media(
                    void *path_p,
                    U8 type,
                    U8 is_attachment,
                    U8 page_index,
                    JC_UINT32 uiOldMediaID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MEDIA_INFO *media_info_p;
    S8 *file_name_p;
    U32 file_size = 0;

    /* FS_HANDLE  file_handle; */
    JC_RETCODE ret_code = JC_OK;
    JMMS_COMP_ERRCODE err_code;
    JMMS_COMP_ERRCODE err_code_time;
    U32 media_id;
    JDD_FILE file_handle;

#ifdef __DRM_SUPPORT__
    U32 drm_method = DRM_METHOD_NONE;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Inside mmi_jmms_compose_replace_media");
    media_info_p = (MEDIA_INFO*) jdd_MemAlloc(sizeof(MEDIA_INFO), sizeof(U8));
    if (media_info_p == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }

    if (g_jmms_context->jmms_fs_handle == NULL)
    {
        if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
        {
            ret_code = JC_ERR_FILE_SYS_INIT;
            goto ERROR_HANDLE;
        }
    }

    file_name_p = mmi_fmgr_extract_file_name((S8*) path_p);

    file_handle = jdd_FSOpen(g_jmms_context->jmms_fs_handle, (U16*) path_p, E_OPEN_READ_MODE);

    if (file_handle == NULL)
    {
        ret_code = JC_ERR_FILE_OPEN;
        goto ERROR_HANDLE;
    }

    jdd_FSGetSize(file_handle, &file_size);

    jdd_FSClose(file_handle);

    media_info_p->pMimeInfo = (MEDIA_MIME_INFO*) jdd_MemAlloc(sizeof(MEDIA_MIME_INFO), sizeof(U8));
    if (media_info_p->pMimeInfo == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }

    media_info_p->eMediaType = type;

    if (is_attachment == E_FALSE && (type == E_MEDIA_IMAGE || type == E_MEDIA_VIDEO))
    {
        U8 size;

        size = strlen(STRING_IMAGE);
        media_info_p->PresentationInfo.pRegionName = (JC_CHAR*) jdd_MemAlloc(sizeof(JC_CHAR), size + 1);
        if (media_info_p->PresentationInfo.pRegionName == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto ERROR_HANDLE;
        }
        mmi_asc_to_ucs2((PS8) (media_info_p->PresentationInfo.pRegionName), (PS8) (STRING_IMAGE));
    }

    media_info_p->pMimeInfo->ContentData.bIsStream = E_TRUE;
    media_info_p->pMimeInfo->ContentData.eCopyMemory = E_FALSE;
    media_info_p->pMimeInfo->ContentData.pBuffer = NULL;
    media_info_p->pMimeInfo->ContentData.uiCurSize = 0;
    media_info_p->pMimeInfo->ContentData.uiTotalSize = file_size;
    media_info_p->pMimeInfo->ContentData.cbReadCallback = mmi_jmms_read_callback;
    media_info_p->pMimeInfo->ContentData.cbWriteCallback = NULL;
    media_info_p->pMimeInfo->ContentData.uiStartOffset = 0;
    media_info_p->pMimeInfo->ContentData.pFileName =
        (JC_CHAR*) jdd_MemAlloc((jc_tcslen((JC_CHAR*) path_p) + 1), sizeof(JC_CHAR));

    if (media_info_p->pMimeInfo->ContentData.pFileName == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }
    jc_tcscpy((UI_character_type*) media_info_p->pMimeInfo->ContentData.pFileName, (UI_character_type*) path_p);
    media_info_p->pMimeInfo->ContentData.pStream = media_info_p->pMimeInfo->ContentData.pFileName;

    media_info_p->pMimeInfo->MimeHeaders.bIsAttachment = is_attachment;

    if ((GetUCS2Flag((S8*) file_name_p) == FALSE) && (is_extended_char_present((S8*) file_name_p) == FALSE))
    {
        media_info_p->pMimeInfo->MimeHeaders.pObjectName =
            (JC_CHAR*) jdd_MemAlloc((jc_tcslen((JC_CHAR*) file_name_p) + 1), sizeof(JC_CHAR));

        if (media_info_p->pMimeInfo->MimeHeaders.pObjectName == NULL)
        {
            ret_code = JC_ERR_MEMORY_ALLOCATION;
            goto ERROR_HANDLE;
        }

        jc_tcscpy((JC_CHAR*) media_info_p->pMimeInfo->MimeHeaders.pObjectName, (JC_CHAR*) file_name_p);
    }
    else
    {
        ret_code = mmi_jmms_convert_chinese_english_filename(
                    (JC_CHAR **) & (media_info_p->pMimeInfo->MimeHeaders.pObjectName),
                    (JC_CHAR*) file_name_p);
        if (ret_code != JC_OK)
        {
            goto ERROR_HANDLE;
        }
    }

#ifdef __DRM_SUPPORT__
    drm_method = mmi_jmms_get_drm_method_type(path_p);
#ifdef __DRM_ODF_SUPPORT__
    if (drm_method == DRM_METHOD_V2)
    {
        media_info_p->pMimeInfo->MimeHeaders.pContentType = jdi_UtilsStrdup(APPLICATION_VND_OMA_DRM_CONTENT_V2);
    }
    else
#endif /* __DRM_ODF_SUPPORT__ */ 
    {
        if (drm_method == DRM_METHOD_SEPARATE_DELIVERY)
        {
            media_info_p->pMimeInfo->MimeHeaders.pContentType = jdi_UtilsStrdup(APPLICATION_VND_OMA_DRM_CONTENT);
        }
        else
#endif /* __DRM_SUPPORT__ */ 
        {
            media_info_p->pMimeInfo->MimeHeaders.pContentType =
                (JC_INT8*) mmi_mms_get_mms_content_type_file((UI_character_type*) file_name_p, type);
        }
    #ifdef __DRM_SUPPORT__
    }
    #endif 
    if (media_info_p->pMimeInfo->MimeHeaders.pContentType == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto ERROR_HANDLE;
    }

    /* add media */
    ret_code = mmi_jmms_jdi_replace_media(g_jmms_context->msg_handle, media_info_p, uiOldMediaID, page_index, &media_id);
    if (ret_code != JC_OK)
    {
        goto ERROR_HANDLE;
    }
#ifdef __DRM_SUPPORT__
    if (g_jmms_context->is_add_media_as_drm)
    {
        ret_code = jdi_MsgSetMediaDRMType(
                    g_jmms_context->msg_handle,
                    page_index,
                    media_id,
                    E_DRM_FWD_LOCK,
                    media_info_p->pMimeInfo->MimeHeaders.bIsAttachment);
        mmi_jmms_jdi_msg_register_callback(
            g_jmms_context->msg_handle,
            E_CB_DRM_COMPOSE,
            (void*)mmi_jmms_drm_compose_handler);

        g_jmms_context->is_add_media_as_drm = MMI_FALSE;
    }
    else
    {
        ret_code = jdi_MsgSetMediaDRMType(
                    g_jmms_context->msg_handle,
                    page_index,
                    media_id,
                    E_DRM_NONE,
                    media_info_p->pMimeInfo->MimeHeaders.bIsAttachment);
    }
#endif /* __DRM_SUPPORT__ */ 

  ERROR_HANDLE:
    err_code = mmi_jmms_compose_handle_error(ret_code, 0);

    switch (err_code)
    {
        case JMMS_COMP_OK:
        case JMMS_COMP_POPUP_OK:
        {
            if (is_attachment == E_FALSE)
            {
                U32 start_time = 0;
                U32 duration = 0, audio_duration = 0;
                U32 max = 999;

            #ifdef __MMI_VIDEO_PLAYER__
                U64 video_duration = 0;
            #endif 
                switch (type)
                {
                    case E_MEDIA_IMAGE:
                    {
                        g_jmms_context->compose_context->curr_slide_info.image_id = media_id;
                        g_jmms_context->compose_context->curr_slide_info.img_info.file_name_p =
                            (U8*) media_info_p->pMimeInfo->ContentData.pFileName;
                        break;
                    }
                    case E_MEDIA_AUDIO:
                        g_jmms_context->compose_context->curr_slide_info.audio_id = media_id;
                        mdi_audio_get_duration((S8*) path_p, &audio_duration);
                        duration = audio_duration / 1000;
                        duration = (duration >= max) ? max : ((audio_duration % 1000) > 0) ? (duration + 1) : duration;
                        err_code_time = mmi_jmms_set_media_time(
                                            start_time,
                                            duration,
                                            g_jmms_context->compose_context->curr_slide_info.audio_id,
                                            g_jmms_context->compose_context->curr_page_index);
                        break;
                    case E_MEDIA_VIDEO:
                        g_jmms_context->compose_context->curr_slide_info.video_id = media_id;
                        g_jmms_context->compose_context->curr_slide_info.img_info.file_name_p =
                            (U8*) media_info_p->pMimeInfo->ContentData.pFileName;
                #ifdef __MMI_VIDEO_PLAYER__
                        video_duration = mmi_jdd_videoapp_get_video_file_duration_info((S8*) path_p);
                        duration = (U32) (video_duration / 1000);
                        duration = (duration >= max) ? max : ((video_duration % 1000) > 0) ? (duration + 1) : duration;
                        err_code_time = mmi_jmms_set_media_time(
                                            start_time,
                                            duration,
                                            g_jmms_context->compose_context->curr_slide_info.video_id,
                                            g_jmms_context->compose_context->curr_page_index);
                #endif /* __MMI_VIDEO_PLAYER__ */ 
                        break;
                }
            }
            else
            {
                g_jmms_context->num_attachments++;
            }
        }
            break;
        case JMMS_COMP_FAIL:
        case JMMS_COMP_OUT_MEMORY:  /* deallocate memory for new slide and out of mmeory case. */
        {
            if (media_info_p != NULL)
            {
                if (media_info_p->pMimeInfo != NULL)
                {
                    if (media_info_p->pMimeInfo->ContentData.pFileName != NULL)
                    {
                        jdd_MemFree(media_info_p->pMimeInfo->ContentData.pFileName);
                    }

                    if (media_info_p->pMimeInfo->MimeHeaders.pContentType != NULL)
                    {
                        jdd_MemFree(media_info_p->pMimeInfo->MimeHeaders.pContentType);
                    }
                    if (media_info_p->pMimeInfo->MimeHeaders.pObjectName != NULL)
                    {
                        jdd_MemFree(media_info_p->pMimeInfo->MimeHeaders.pObjectName);
                    }

                    jdd_MemFree(media_info_p->pMimeInfo);
                }
                if (media_info_p->PresentationInfo.pRegionName != NULL)
                {
                    jdd_MemFree(media_info_p->PresentationInfo.pRegionName);
                }
                jdd_MemFree(media_info_p);
                media_info_p = NULL;
            }

        }
            err_code = JMMS_COMP_FAIL;
            break;
    }

    mmi_jmms_set_region_list();

    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
    }
    if (media_info_p != NULL)
    {
        jdd_MemFree(media_info_p);
        media_info_p = NULL;
    }
    return err_code;

}
#endif /* __MMI_UNIFIED_COMPOSER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_copy_with_dot
 * DESCRIPTION
 *  Append three dots to the end of string
 * PARAMETERS
 *  dest        [IN/OUT]        Destination buffer.
 *  source      [IN]            Source buffer.
 *  max_len     [IN]            Max characters can be put in destination buffer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_copy_with_dot(S8 *dest, S8 *source, S32 max_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 g_uc_three_dot[] = { '.', '\0', '.', '\0', '.', '\0', '\0', '\0' };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen(source) <= max_len)
    {
        mmi_ucs2cpy((S8*) dest, (S8*) source);
    }
    else
    {
        /* do not clear end of string because mmi_ucs2ncpy will auto set NULL terminate */
        mmi_ucs2ncpy((S8*) dest, (S8*) source, max_len - 3);
        mmi_ucs2cat((S8*) dest, (S8*) g_uc_three_dot);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_convert_u32_to_color
 * DESCRIPTION
 *  convert u32 value of color to colr struct
 * PARAMETERS
 *  out_color_p     [OUT]       
 *  incolor_32      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_convert_u32_to_color(color *out_color_p, U32 incolor_32)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    out_color_p->r = (U8) ((0xFF000000 & incolor_32) >> 24);
    out_color_p->g = (U8) ((0x00FF0000 & incolor_32) >> 16);
    out_color_p->b = (U8) ((0x0000FF00 & incolor_32) >> 8);
    out_color_p->alpha = (U8) ((0x000000FF & incolor_32));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_is_from_jmms
 * DESCRIPTION
 *  tells external application if the request is from jmms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_jmms_is_from_jmms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context != NULL && g_jmms_context->compose_context != NULL)
    {
        return g_jmms_context->compose_context->from_jmms_app;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_delete_compose_temp_files
 * DESCRIPTION
 *  delete temporary vacrd vcal files
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_delete_compose_temp_files(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ucs2_file_name[(50) * ENCODING_LENGTH];  /* 30 for @mms\\temp\\vobj\\.vcf */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context != NULL && g_jmms_context->compose_context != NULL)
    {
        memset(ucs2_file_name, 0, (50) * ENCODING_LENGTH);

        mmi_asc_to_ucs2((S8*) ucs2_file_name, (S8*) "@mms\\temp\\vobj\\");
        if (g_jmms_context->jmms_fs_handle == NULL)
        {
            if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
            {
                return;
            }
        }

        jdd_FSDelDir(g_jmms_context->jmms_fs_handle, (U16*) ucs2_file_name);

    #ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
        /* Delete the temporary resized jpg files */
        memset(ucs2_file_name, 0x00, sizeof(ucs2_file_name));
        mmi_asc_to_ucs2((PS8) ucs2_file_name, (PS8) "@mms\\temp\\resize\\");
        jdd_FSDelDir(g_jmms_context->jmms_fs_handle, (U16*) ucs2_file_name);
    #endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 

        if (g_jmms_context->jmms_fs_handle != NULL)
        {
            jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
            g_jmms_context->jmms_fs_handle = NULL;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_media_file_size
 * DESCRIPTION
 *  check size when user select a media.
 * PARAMETERS
 *  path_p              [IN]        
 *  media_size_p        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
JC_BOOLEAN mmi_jmms_get_media_file_size(void *path_p, U32 *media_size_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 file_size = 0;
    JDD_FILE file_handle;

    /* U32 msg_max_size = 0; */
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->jmms_fs_handle == NULL)
    {
        if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
        {
            ret_code = JC_ERR_FILE_SYS_INIT;
            goto END_HANDLE;
        }
    }

    file_handle = jdd_FSOpen(g_jmms_context->jmms_fs_handle, (U16*) path_p, E_OPEN_READ_MODE);
    if (file_handle == NULL)
    {
        ret_code = JC_ERR_FILE_OPEN;
        goto END_HANDLE;
    }

    jdd_FSGetSize(file_handle, &file_size);
    jdd_FSClose(file_handle);

    *media_size_p = file_size;

  END_HANDLE:
    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
    }
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_selected_media_valid_size_check_for_mms
 * DESCRIPTION
 *  check size when user select a media.
 * PARAMETERS
 *  path_p              [IN]        
 *  is_short            [IN]        
 *  media_size_p        [IN]        
 *  is_media_image      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
JC_BOOLEAN mmi_jmms_selected_media_valid_size_check_for_mms(
            void *path_p,
            int is_short,
            U32 *media_size_p,
            JC_BOOLEAN is_media_image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 file_size = 0;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_code = mmi_jmms_get_media_file_size(path_p, &file_size);
    *media_size_p = file_size;

    if (ret_code != JC_OK)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
        return E_FALSE;
    }

    if (file_size > MAX_ALLOWED_INDIVIDUAL_MEDIA_SIZE * 1024)
    {
        S8 tmp_str_ascii[20] = {0, };
        S8 tmp_str_ucs2[40] = {0};
        U8 error_string[60] = {0};

        memset(error_string, 0, sizeof(error_string));
    #ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
        if ((is_media_image == E_TRUE) &&
            (g_jmms_context->nvram_compose_settings.image_resize_option != E_IMAGE_RESIZE_OFF))
        {
            mmi_ucs2cpy((S8*) error_string, (S8*) GetString(STR_ID_JMMS_IMAGE_RESIZE_LIMIT));
        }
        else
        {
    #endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 
            mmi_ucs2cpy((S8*) error_string, (S8*) GetString(STR_ID_JMMS_MAX_INDIVIDUAL_MEDIA_SIZE));
        #ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
        }
        #endif 

        sprintf(tmp_str_ascii, " %d ", MAX_ALLOWED_INDIVIDUAL_MEDIA_SIZE);
        mmi_asc_to_ucs2(tmp_str_ucs2, tmp_str_ascii);
        mmi_ucs2cat((S8*) error_string, (S8*) tmp_str_ucs2);
        mmi_ucs2cat((S8*) error_string, (S8*) GetString(STR_ID_JMMS_KB));
        DisplayPopup((PU8) (error_string), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
        return E_FALSE;
    }
    return E_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_error
 * DESCRIPTION
 *  Handles all the error codes encountered while composing the MMS
 * PARAMETERS
 *  ret_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_handle_error(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ret_code)
    {
            /* Do Nothing in case of Success */
        case JC_OK:
            break;

            /* To Do: Need to display the correct File Operation string */
        case JC_ERR_FILE_SYS_INIT:
        case JC_ERR_FILE_CREATEDIR:
        case JC_ERR_FILE_CLOSE:
            DisplayPopup(
                (PU8) GetString(STR_ID_JMMS_FILE_SYSTEM_ERROR),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                ERROR_TONE);
            break;

        case JC_ERR_FILE_FULL:
            DisplayPopup(
                (PU8) GetString(STR_ID_JMMS_FILE_SYSTEM_FULL),
                IMG_GLOBAL_ERROR,
                1,
                JMMS_POPUP_TIME,
                ERROR_TONE);
            break;

        case JC_ERR_MEMORY_ALLOCATION:
            DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
            break;

        default:
            DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_show_error_popup
 * DESCRIPTION
 *  Displays the popup with particular StringId while composing the MMS
 * PARAMETERS
 *  str_id      [IN]        String id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_compose_show_error_popup(U16 str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img_id = IMG_GLOBAL_ERROR;
    U8 tone_id = ERROR_TONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (str_id)
    {
        case STR_GLOBAL_DRM_PROHIBITED:
        {
            img_id = IMG_GLOBAL_WARNING;
            tone_id = WARNING_TONE;
        }
            break;
    }
    DisplayPopup((PU8) GetString(str_id), img_id, 1, JMMS_POPUP_TIME, tone_id);
}

#endif /* (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT)) */ 


/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 * JMMSDRMHandler.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is DRM handler file for MMS
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/
#ifndef _JMMSDRMHANDLER_H_
#define _JMMSDRMHANDLER_H_

#ifdef __DRM_SUPPORT__
#include "ddl.h"
#include "jcal.h"
#include "ddlbase.h"
#include "jdi_mimeinfo.h"
#include "MessagingDataTypes.h"
#include "fs_type.h"
#include "drm_def.h"

#define  E_MMS_PARSE_DRM_BUFFER_EVENT  10

#define DRM_HEADER_BOUNDARY     "--boundary-1\r\n"
#define DRM_HEADER_MIME_TYPE    "Content-Type: "
#define DRM_HEADER_ENCODING     "\r\nContent-Transfer-Encoding: binary\r\n\r\n"
#define DRM_FOOTER              "\r\n--boundary-1--\r\n"
#define DRM_COMPOSE_IDENTIFIER  "<*DRM*>"

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

extern JC_RETCODE mmi_jmms_drm_indication_handler(
                    MSG_HANDLE msg_handle,
                    void *app_cb_arg_p,
                    CONTENT_DATA *drm_content_p,
                    JC_INT8 *content_type_p,
                    JC_INT8 **ref_id_p,
                    ST_DRM_INFO **st_drm_info_p,
                    DRM_IND_RESPONSE_CB drm_ind_response_cb);

extern JC_RETCODE mmi_jmms_drm_parse_content(
                    CONTENT_DATA *content_data_p,
                    JC_INT8 *content_type_p,
                    JDD_FILE mms_file_handle,
                    ST_DRM_INFO **drm_info_p);

extern JC_RETCODE mmi_jmms_drm_rights_update_handler(
                    MSG_HANDLE msg_handle,
                    void *app_cb_arg_p,
                    JC_INT8 *ref_id_p,
                    JC_BOOLEAN is_render);

extern JC_RETCODE mmi_jmms_drm_info_list_ind_handler(
                    MSG_HANDLE msg_handle,
                    void *callback_arg,
                    DRM_MEDIA_LIST *drm_info_list_p);

extern JC_RETCODE mmi_jmms_drm_cancel_parse_handler(MSG_HANDLE msg_handle, void *app_cb_arg_p);

extern JC_RETCODE mmi_jmms_drm_compose_handler(
                    MSG_HANDLE msg_handle,
                    void *app_cb_arg_p,
                    MEDIA_MIME_INFO *media_mime_p,
                    MEDIA_MIME_INFO **drm_mime_p);

extern JC_BOOLEAN mmi_jmms_is_media_drm_permitted(JC_CHAR *file_path, JC_UINT8 permission);
extern JC_BOOLEAN mmi_jmms_check_drm_rights(JC_CHAR *filePath);
extern drm_method_enum mmi_jmms_get_drm_method_type(JC_CHAR *filePath);
extern JC_BOOLEAN mmi_jmms_process_drm_object(
                    JC_CHAR *filePath,
                    JC_UINT8 permission,
                    JC_BOOLEAN *can_fwd,
                    JC_BOOLEAN *is_drm_permitted);

#ifdef __DRM_ODF_SUPPORT__
extern JC_BOOLEAN mmi_jmms_drm_is_multi_part_odf_content(JC_CHAR *file_path);
extern kal_char *mmi_jmms_drm_odf_get_content_ext(JC_CHAR *file_path);
#endif /* __DRM_ODF_SUPPORT__ */ 

extern JC_RETCODE mmi_jmms_drm_encapsulate_callback(
                    void *stream_p,
                    JC_INT32 offset,
                    JC_UINT32 ui_size,
                    JC_UINT8 *buffer_p,
                    JC_UINT32 *size_read_p);

#endif /* __DRM_SUPPORT__ */ 
#endif /* _JMMSDRMHANDLER_H_ */ 


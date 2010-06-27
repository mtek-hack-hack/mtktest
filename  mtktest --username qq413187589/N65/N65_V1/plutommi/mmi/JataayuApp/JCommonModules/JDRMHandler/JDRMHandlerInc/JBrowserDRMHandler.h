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
 * JBrowserDRMHandler.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _JBROWSERDRMHANDLER_H_
#define _JBROWSERDRMHANDLER_H_

#ifdef __DRM_SUPPORT__
#include "ddl.h"
#include "jcal.h"
#include "jdi_communicator.h"
#include "jdi_browserinterface.h"

typedef enum
{
    DRM_TYPE_MESSAGE,
    DRM_TYPE_CONTENT
} mmi_jbrowser_drm_type_enum;

typedef struct
{
    void *drm_arg;
    mmi_jbrowser_drm_type_enum drm_type;
    ST_MIME_CONTENT *drm_content;
    CB_DRM_RESPONSE_HANDLER drm_response_callback;
    void *drm_app_arg;
    JC_UINT32 drm_ref_id;
} mmi_jbrowser_drm_context_struct;

extern JC_RETCODE mmi_jbrowser_drm_indication_handler(
                    void *drm_arg_p,
                    JC_INT8 *mime_type_p,
                    ST_MIME_CONTENT *st_mime_content_p,
                    CB_DRM_RESPONSE_HANDLER response_handler_cb,
                    CB_DRM_MORE_CONTENT_HANDLER drm_more_content_cb,
                    void *app_arg_p,
                    JC_UINT32 *drm_ref_id_p,
                    ST_DRM_PARSED_INFO *st_drm_info_p);

extern void mmi_jbrowser_drm_rights_update_handler(
                JC_UINT32 drm_ref_id,
                ST_DRM_RIGHTS_OBJECT *st_rights_object_p,
                JC_BOOLEAN is_rendered);

extern JC_RETCODE mmi_jbrowser_drm_more_content_handler(
                    void *app_arg_p,
                    JC_UINT32 drm_ref_id,
                    JC_UINT8 *buffer_p,
                    JC_UINT32 buffer_length,
                    JC_BOOLEAN is_more_data);

extern void mmi_jbrowser_send_parse_drm_event(void);

extern void mmi_jbrowser_parse_drm_content(void);

#endif /* __DRM_SUPPORT__ */ 
#endif /* _JBROWSERDRMHANDLER_H_ */ 


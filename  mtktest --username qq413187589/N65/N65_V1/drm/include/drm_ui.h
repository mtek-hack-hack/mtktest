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
 *  drm_ui.h
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef DRM_UI_H
#define DRM_UI_H
#ifdef __DRM_SUPPORT__
#include "drm_util.h"
#define DRM_UI_DEBUG(x,y)     kal_trace y

#ifndef MMI_ON_HARDWARE_P
#define MMI_ON_HARDWARE_P
#endif 
#include "PixtelDataTypes.h"
#include "RightsMgrResDef.h"
#include "GlobalDefs.h"

#define __SHOW_BY_APP__

typedef enum
{
    DRMT_MBError_Text = 0,  /* An error message display */
    DRMT_MBError_Popup,     /* An error message popup */
    DRMT_MBInfo,            /* Helpful info for the user */
    DRMT_MBWarning,         /* warning popup */
    DRMT_MBNotify,          /* normal popup */
    DRMT_MBYesNo_Text,      /* Obtain user consent... Yes, No */
    DRMT_MBYesNo_Popup
} drmt_message_box_type;

typedef enum
{
    DRMT_ALERT_ERROR,
    DRMT_ALERT_WARNING,
    DRMT_ALERT_OK,
    DRMT_ALERT_DONE
} drmt_alert_type;

typedef enum
{
    DRMT_SESSION_NONE,
    DRMT_SESSION_REGISTER_AGENT,
    DRMT_SESSION_ACQUIRE_RO,
    DRMT_SESSION_DOMAIN_JOIN,
    DRMT_SESSION_DOMAIN_LEAVE,
    DRMT_SESSION_PREVIEW_DOWNLOAD,
    DRMT_SESSION_SILENT_DOWNLOAD,
    DRMT_SESSION_TIME_SYNC
} drmt_get_session_enum;

typedef enum
{
    DRMT_CONFIRM_TEXT_VIEW_CATEGORY,
    DRMT_CONFIRM_NOTIFICATION_CATEGORY
} drmt_get_confirm_category_enum;

typedef enum
{
    DRMT_CONFIRM_NO,
    DRMT_CONFIRM_YES,
    DRMT_CONFIRM_CANCEL
} drmt_get_confirm_result_enum;

typedef enum
{
    DRMT_BROWSER_GOTO_URL,
    DRMT_BROWSER_GOTO_URL_BACKGROUND
} drmt_browser_option_enum;

typedef enum
{
    DRMT_BROWSER_NO_ERROR,
    DRMT_BROWSER_ERROR
} drmt_browser_error_enum;

typedef void (*drmt_mmi_get_auth_cb) (const kal_uint8 *username, kal_int32 name_len, const kal_uint8 *password,
                                      kal_int32 pass_len);
typedef void (*drmt_mmi_dl_progress_cb) (void);
typedef void (*drmt_mmi_alert_user_cb) (void);
typedef void (*drmt_mmi_notify_info_cb) (void);
typedef void (*drmt_mmi_get_confirm_cb) (drmt_get_confirm_result_enum result);
typedef void (*drmt_mmi_get_folder_cb) (const kal_wchar *folder);
typedef void (*drmt_mmi_get_filename_cb) (const kal_wchar *filename);
typedef void (*drmt_mmi_open_url_cb) (kal_uint8 result);

extern kal_bool drmt_mmi_send_get_auth_req(drmt_mmi_get_auth_cb callback);
extern kal_bool drmt_mmi_recv_get_auth_cnf(ilm_struct *current_ilm);
extern kal_bool drmt_mmi_send_dl_progress_ind(
                    kal_int32 total_size,
                    kal_int32 current_size,
                    const kal_wchar *info,
                    drmt_mmi_dl_progress_cb callback);
extern kal_bool drmt_mmi_send_get_user_confirm_req(
                    kal_uint16 session,
                    kal_uint16 title,
                    kal_uint16 image,
                    kal_uint16 category,
                    const kal_wchar *info,
                    drmt_mmi_get_confirm_cb callback);
extern kal_bool drmt_mmi_recv_get_user_confirm_cnf(ilm_struct *current_ilm);
extern kal_bool drmt_mmi_send_alert_user_ind(kal_int8 type, const kal_wchar *info, drmt_mmi_alert_user_cb callback);
extern kal_bool drmt_mmi_recv_alert_user_rsp(ilm_struct *current_ilm);
extern kal_bool drmt_mmi_send_notify_info_ind(
                    kal_uint16 title,
                    kal_uint16 image,
                    const kal_wchar *info,
                    drmt_mmi_notify_info_cb callback);
extern kal_bool drmt_mmi_recv_notify_info_rsp(ilm_struct *current_ilm);
extern kal_bool drmt_mmi_send_get_folder_req(drmt_mmi_get_folder_cb callback);
extern kal_bool drmt_mmi_recv_get_folder_cnf(ilm_struct *current_ilm);
extern kal_bool drmt_mmi_send_get_filename_req(const kal_wchar *default_filename, drmt_mmi_get_filename_cb callback);
extern kal_bool drmt_mmi_recv_get_filename_cnf(ilm_struct *current_ilm);
extern kal_bool drmt_mmi_send_open_url_req(kal_uint8 option, const kal_char *url, drmt_mmi_open_url_cb callback);
extern kal_bool drmt_mmi_recv_open_url_cnf(ilm_struct *current_ilm);
extern kal_int32 drmt_mmi_display_msg(kal_uint16 session, const kal_wchar *message, int UIType);
extern kal_int32 drmt_mmi_open_url(const kal_char *url);
extern kal_wchar *drmt_mmi_get_string(kal_uint16 string_id);
extern kal_int32 drmt_mmi_clean_screen(void);
#endif /*__DRM_SUPPORT__*/
#endif /* DRM_UI_H */ 


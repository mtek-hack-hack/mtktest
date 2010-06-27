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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef DOWNLOAD_AGENT_RES_DEF_H
#define DOWNLOAD_AGENT_RES_DEF_H

#include "MMI_features.h"   /* add if you use any compile options defined in MMI_features.h */

#if defined (__MMI_DOWNLOAD_AGENT__)

#include "MMIDataType.h"    /* for resource base */

/***************************************************************************** 
 * Typedef for Resource Enum
 *****************************************************************************/
/* Screen IDs */
typedef enum
{
    SCR_ID_DA_BASE = DL_AGENT_BASE,
    /* add new screen ID below this line */
    
    SCR_DA_APP,

    /* Kernal */
    SCR_ID_DA_JOB_LIST,
    SCR_ID_DA_JOB_OPTION,
    SCR_ID_DA_JOB_DETAIL,
    SCR_ID_DA_JOB_CALLBACK_CONFIRM,
    SCR_ID_DA_JOB_SUSPEND_CONFIRM,
    
    SCR_ID_DA_NEW_PUSH_IND,
    
//    SCR_ID_DA_PERCENTAGE_BAR,
//    SCR_ID_DA_DOWNLOAD_CONFIRM,
    SCR_ID_DA_DRM_PROCESSING,

    /* Screen */
    SCR_ID_DA_SCREEN_DOWNLOAD_CONFIRM,

    SCR_ID_DA_SCREEN_STORAGE_BEGIN,
    SCR_ID_DA_SCREEN_STORAGE_MARKER,
    SCR_ID_DA_SCREEN_STORAGE_SEL_DRV,
    SCR_ID_DA_SCREEN_STORAGE_FILENAME,
    SCR_ID_DA_SCREEN_STORAGE_FILENAME_OPTION,
    SCR_ID_DA_SCREEN_STORAGE_END,

    SCR_ID_DA_SCREEN_AUTH,
    
    SCR_ID_DA_SCREEN_PLEASE_WAIT,
    
    /* OMA */
    SCR_ID_DA_OMA_DOWNLOAD_OPTION,
    SCR_ID_DA_OMA_DOWNLOAD_VIEW_DD,
    SCR_ID_DA_OMA_INSTALLING,
    SCR_ID_DA_OMA_SENDING_REPORT,

    /* dummy */
    SCR_ID_DA_DUMMY,
    SCR_ID_DA_DISPATCH_DUMMY,
    SCR_ID_DA_CONFIRM_DUMMY,

    /* add new screen ID above this line */
    SCR_ID_DA_END
} DA_SCREEN_ID;

/* String IDs */
typedef enum
{
    STR_ID_DA_BASE = DL_AGENT_BASE,
    /* add new string ID below this line */

    STR_DA_APP,
    STR_DA_TEXT_FILE,
    STR_DA_IMAGE_FILE,
    STR_DA_AUDIO_FILE,
    STR_DA_VIDEO_FILE,
    STR_DA_APP_FILE,
    STR_DA_MSG_FILE,
    STR_DA_MULTI_FILE,
    STR_DA_UNKNOWN_FILE,
    STR_DA_VCARD_FILE,
    STR_DA_VCALENDAR_FILE,
    STR_DA_EBOOK_FILE,
    
    STR_DA_EMPTY_USERNAME,  // Used by Java, do not change
    
    STR_ID_DA_NEW_PUSH,
    STR_ID_DA_REPLACE_FILE,
    STR_ID_DA_FILENAME_EDITOR,
    STR_ID_DA_CALLBACK_NOW,

    /* OMA */
    STR_ID_DA_OMA_INSUFFICIENT_MEM_MSG,
    STR_ID_DA_OMA_USER_CANCELLED_MSG,
    STR_ID_DA_OMA_LOSS_OF_SERVICE_MSG,
    STR_ID_DA_OMA_ATTRIBUTE_MISMATCH_MSG,
    STR_ID_DA_OMA_INVALID_DESCRIPTOR_MSG,
    STR_ID_DA_OMA_INVALID_DDVSERSION_MSG,
    STR_ID_DA_OMA_DEVICE_ABORTED_MSG,
    STR_ID_DA_OMA_NON_ACCEPTABLE_CONTENT_MSG,
    STR_ID_DA_OMA_LOADER_ERROR_MSG,
    STR_ID_DA_OMA_INSUFFICIENT_STORAGE_MSG,
    STR_ID_DA_OMA_AUTHORIZATION_FAILURE_MSG,
    STR_ID_DA_OMA_SEND_REPORT,

    STR_ID_DA_OMA_ERROR_SEND_REPORT_FAIL,
    STR_ID_DA_OMA_ERROR_SEND_REPORT_FAIL_AUTH,
    STR_ID_DA_OMA_ERROR_SEND_REPORT_CANCEL,
    STR_ID_DA_OMA_VIEW_DD,

    /* Job List related */    
    STR_ID_DA_JOB_LIST,
    STR_ID_DA_JOB_VIEW_DETAIL,
    STR_ID_DA_JOB_CANCEL,           // abort download and remove.
    STR_ID_DA_JOB_SUSPEND,          // Pause.
    STR_ID_DA_JOB_RESUME,
    STR_ID_DA_JOB_UPDATE,
    STR_ID_DA_JOB_USE,              // Use now?
    STR_ID_DA_JOB_SAVE_AS,          // Save to another location
    STR_ID_DA_JOB_REMOVE,           // Remove a complete job
    STR_ID_DA_JOB_REMOVE_ALL,       // Remove all complete jobs
    STR_ID_DA_JOB_EXIST,

    /* Prompt */
    STR_ID_DA_PROMPT_SIZE,
    STR_ID_DA_PROMPT_TYPE,
    STR_ID_DA_PROMPT_NAME,
    STR_ID_DA_PROMPT_VENDOR,
    STR_ID_DA_PROMPT_DESC,
    STR_ID_DA_PROMPT_INFOURL,
    
    STR_ID_DA_PROMPT_ESTIMATED,
    STR_ID_DA_PROMPT_UNKNOWN,
    STR_ID_DA_PROMPT_SEC,
    STR_ID_DA_PROMPT_MIN,

    STR_ID_DA_PROMPT_TIME_REMAIN,

    STR_ID_DA_PROMPT_NOT_SUPPORT,
    STR_ID_DA_PROMPT_DL_COMPLETE,
    STR_ID_DA_PROMPT_DL_COMPLETE_ASK,
    STR_ID_DA_PROMPT_DL_OK,         // For small screen such as 128x128

    STR_ID_DA_PROMPT_EXCEED_MAX_DL,
    STR_ID_DA_PROMPT_EXCEED_MAX_JOB,

    /* Error message */
    STR_ID_DA_ERROR_FILE_MISMATCH,
    STR_ID_DA_ERROR_TEMP_UNAVAILABLE,  // Temporary unavailable
    STR_ID_DA_ERROR_RESUME_FAIL,
    STR_ID_DA_ERROR_CONNECT_CLOSED,
    STR_ID_DA_ERROR_INSUFFICIENT_STORAGE,

    /* Popup string */
    STR_ID_DA_POPUP_SUSPENDED,

    STR_ID_DA_POPUP_CANCEL_ASK,
    STR_ID_DA_POPUP_SEND_ASK,

    /* Softkey string */
    STR_ID_DA_LSK_DL,
    
    /* add new string ID above this line */
    STR_ID_DA_END
} DA_STRING_LIST;

/* Image IDs */
typedef enum
{
    IMG_ID_DA_BASE = DL_AGENT_BASE,
    /* add new image ID below this line */
    
    IMG_ID_DA_DOWNLOAD_ICON,
    IMG_ID_DA_DOWNLOAD_PROGRESS_BANNER,
    
    IMG_ID_DA_DOWNLOAD_STATE_COMPLETE,
    IMG_ID_DA_DOWNLOAD_STATE_LOADING,
    IMG_ID_DA_DOWNLOAD_STATE_PAUSE,
    IMG_ID_DA_DOWNLOAD_STATE_PROCESSING,
    
    /* add new image ID above this line */
    IMG_ID_DA_END
} DA_IMAGE_LIST;

#endif
#endif /* DOWNLOAD_AGENT_RES_DEF_H */


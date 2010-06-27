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
 * UnifiedComposerDef.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines resource ID for Unified Composer
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef _MMI_UNIFIED_COMPOSER_DEF_H
#define _MMI_UNIFIED_COMPOSER_DEF_H

#include "MMIDataType.h"

#ifdef __MMI_UNIFIED_COMPOSER__

typedef enum
{
    STR_UC_INSERT_ID = (UNIFIED_COMPOSER_BASE + 1),
    STR_UC_REMOVE_ID,
    STR_UC_REPLACE_ID,
    STR_UC_PREVIEW_ID,
    STR_UC_SLIDE_OPTION_ID,
    STR_UC_SEND_OPTION_ID,
    STR_UC_MESSAGE_DETAIL_ID,
    STR_UC_MESSAGE_TYPE_ID,
    STR_UC_ADD_NUMBER_ID,
    STR_UC_ADD_EMAIL_ID,
    STR_UC_ADD_NUMBER_BY_GROUP_ID,
    STR_UC_ADD_EMAIL_BY_GROUP_ID,
    STR_UC_SEND_AND_SAVE_ID,
    STR_UC_BACK_TO_EDIT_MSG_ID,
    STR_UC_EXIT_ID,
    STR_UC_RESEND_ID,
    STR_UC_IMAGE_ID,
    STR_UC_AUDIO_ID,
    STR_UC_VIDEO_ID,
    STR_UC_TEXT_TEMPLATE_ID,
    STR_UC_ATTACHMENT_ID,
    STR_UC_INSERT_NEW_SLIDE_ID,
    STR_UC_DELETE_SLIDE_ID,
    STR_UC_PREVIOUS_SLIDE_ID,
    STR_UC_NEXT_SLUIDE_ID,
    STR_UC_SLIDE_TIMING_ID,
    STR_UC_TO_ID,
    STR_UC_CC_ID,
    STR_UC_BCC_ID,
    STR_UC_SUBJECT_ID,
    STR_UC_RECIPIENTS_ID,
    STR_UC_CHANGED_TO_TEXT_MSG_ID,
    STR_UC_CHANGED_TO_MULTIMEDIA_MSG_ID,
    STR_UC_TO_OPTION_ID,
    STR_UC_CC_OPTION_ID,
    STR_UC_BCC_OPTION_ID,
    STR_UC_MSG_SIZE_EXCEED_ID,
    STR_UC_SIZE_NOT_ENOUGH_FOR_REC_VIDEO_ID,
    STR_UC_ADDR_LENGTH_EXCEED_ID,
    STR_UC_TEXT_MESSAGE_ID,
    STR_UC_MULTIMEDIA_MESSAGE_ID,
    STR_UC_PAGES_ID,
    STR_UC_TOTAL_MESSAGES_ID,
    STR_UC_SIZE_ID,
    STR_UC_FORWARD_ID,
    STR_UC_SEND_ID,
    STR_UC_PROHIBIT_BY_CREATION_MODE_ID,
    STR_UC_NO_SPACE_ID,
    STR_UC_REMOVED_ID,
    STR_UC_PLEASE_WAIT_ID,
    STR_UC_MMS_ID,
    STR_UC_STORAGE_FULL_ID,
    STR_UC_READ_REPORT_ID,
    STR_UC_DELIVERY_REPORT_ID,
    STR_UC_PRIORITY_ID,
    STR_UC_VALIDITY_PERIOD_ID,
    STR_UC_DELIVERY_TIME_ID,
    STR_UC_PRIORITY_LOW_ID,
    STR_UC_PRIORITY_MEDIUM_ID,
    STR_UC_PRIORITY_HIGH_ID,
    STR_UC_VALIDITY_PERIOD_1_HOUR_ID,
    STR_UC_VALIDITY_PERIOD_6_HOUR_ID,
    STR_UC_VALIDITY_PERIOD_12_HOUR_ID,
    STR_UC_VALIDITY_PERIOD_1_DAY_ID,
    STR_UC_VALIDITY_PERIOD_1_WEEK_ID,
    STR_UC_VALIDITY_PERIOD_MAX_ID,
    STR_UC_DELIVERY_TIME_IMMEDIATE_ID,
    STR_UC_DELIVERY_TIME_1_HOUR_ID,
    STR_UC_DELIVERY_TIME_12_HOUR_ID,
    STR_UC_DELIVERY_TIME_24_HOUR_ID,
    STR_UC_FAIL_TO_INSERT_SIGNATURE_ID,
    STR_UC_DISCARD_EDITED_MSG_ID,
    STR_UC_WRITE_MSG_ID,
    STR_UC_STORAGE_FULL_DELETE_FILE_ID,
    STR_UC_MAX_TEMPLATE_ALREADY_PRESENT_ID,
    STR_UC_STORAGE_FILE_IO_ERROR_ID,
    STR_UC_STORAGE_FULL_MSG_CONTENT_LOSS_ID,
    STR_UC_NO_RECEPIENT_ADDR_ID,
    STR_UC_CREATING_ID,
    STR_UC_SENDING_MMS_ID,
    STR_UC_SENT_ID,
    STR_UC_ABORT_FAIL_ID,
    STR_UC_ABORTED_ID,
    STR_UC_SEND_SUCCESS_SAVE_SUCCESS,
    STR_UC_SEND_SUCCESS_SAVE_FAIL,
    STR_UC_SEND_FAIL_SAVE_SUCCESS,
    STR_UC_SEND_FAIL_SAVE_FAIL,
    STR_UC_CONTENT_ERROR_ID,
    STR_UC_ALLOW_ID,
    STR_UC_NOT_ALLOW_ID,
    STR_UC_ADDRESS_NUMBER_EXCEED_ID,
    STR_UC_GO_TO_SOME_SLIDE_ID,
    STR_UC_MSG_DETAIL_RECIPIENTS_ID,
    STR_UC_DUPLICATE_ADDRESS_ID,
    STR_UC_PHB_NUMBER_ID,
    STR_UC_PHB_NAME_ID,
    STR_UC_BOOKMARK_ID,
    STR_UC_NOT_SUPPORT_ID,
    STR_UC_PREVIEW_SLIDE_LIST,
    STR_UC_PREVIEW_GOTO,
    STR_UC_PREVIEW_SLIDE,
    STR_UC_CAN_NOT_PLAY_COMPLETE,
    STR_UC_UNSUPPORT_CONTENT_ID,
    STR_UC_CREATION_MODE_MAX_MSG_SIZE_REACHED_ID,
    STR_UC_MAX_SLIDE_NUM_REACHED_ID,
    STR_UC_TOO_MANY_MSG_ID,
    STR_UC_CONFIG_ERROR_ID,
    STR_UC_CONNECT_ERROR_ID,
    STR_UC_SERVER_TIMEOUT_ID,
    STR_UC_SERVER_ERROR_ID,
    STR_UC_SERVICE_DENIED_ID,
    STR_UC_UNSUPPORT_CONTENT_BY_SERVER_ID,
    STR_UC_UNKNOWN_APN_ID,
    STR_UC_UNAUTHORIZED_ID,
    STR_UC_SEND_FAIL_ID,
    STR_UC_SYSTEM_RESOURCES_EXHAUSTED_ID,
    STR_UC_FILE_CORRUPT_ID,
    STR_UC_FILE_EMPTY_ID,
    STR_UC_FAIL_TO_RESIZE_IMAGE_ID,
    STR_UC_SLIDE_TEXT_TIMING_ID,
    STR_UC_SLIDE_IMAGE_TIMING_ID,
    STR_UC_SLIDE_AUDIO_TIMING_ID,
    STR_UC_SLIDE_VIDEO_TIMING_ID,
    STR_UC_START_TIME_ID,
    STR_UC_END_TIME_ID,
    STR_UC_EXCEED_SLIDE_TIME_ID,
    STR_UC_NEW_IMAGE_ID,
    STR_UC_NEW_AUDIO_ID,
    STR_UC_NEW_VIDEO_ID,
    STR_UC_INSERT_NEW_SLIDE_BEFORE_ID,
    STR_UC_INSERT_NEW_SLIDE_AFTER_ID,
    STR_UC_SAVE_AS_TEMPLATE_ID,
    STR_UC_ADDR_LENGTH_TOO_SHORT_ID,
    STR_UC_LESS_THAN_MEDIA_TIME_ID,
    STR_UC_MMS_SIZE_CONFIRM_MSG_1,
    STR_UC_MMS_SIZE_CONFIRM_MSG_2,
    STR_UC_INTERVAL_PREFIX_ID,
    STR_UC_INTERVAL_INFIX_ID,    
    STR_UC_SERVER_ID,  //tsaiml_server
    STR_UC_TOTAL_ID
} uc_str_id_enum;

typedef enum
{
    IMG_UC_SETTING_MSG_TYPE_ID = (UNIFIED_COMPOSER_BASE + 1),
    IMG_UC_ENTRY_SCRN_CAPTION_ID,
    IMG_UC_TO_ID,
    IMG_UC_CC_ID,
    IMG_UC_BCC_ID,
    IMG_UC_SUBJECT_ID,
    IMG_UC_MSG_DETAIL_ID,
    IMG_UC_DRM_THUMBNAIL_ID,
    IMG_UC_VALIDITY_PERIOD_ID,    
    IMG_UC_DELIVERY_REPORT_ID,    
    IMG_UC_READ_REPORT_ID,
    IMG_UC_PRIORITY_ID,
    IMG_UC_DELIVERY_TIME_ID,
    
    IMG_UC_TOTAL_ID
} uc_img_id_enum;

typedef enum
{
    SCR_ID_UC_START = (UNIFIED_COMPOSER_BASE + 1),
    SCR_ID_UC_PROCESSING,
    SCR_ID_UC_EDITOR,
    SCR_ID_UC_OPT,
    SCR_ID_UC_OPT_DONE,
    SCR_ID_UC_OPT_DONE_ADDR_LIST,
    SCR_ID_UC_OPT_DONE_ADDR_OPT,
    SCR_ID_UC_OPT_DONE_ADDR_OPT_ADD_NUMBER,
    SCR_ID_UC_OPT_DONE_ADDR_OPT_ADD_EMAIL,
    SCR_ID_UC_OPT_DONE_ADDR_OPT_EDIT,
    SCR_ID_UC_MSG_DETAIL,
    SCR_ID_UC_MSG_PREVIEW,
    SCR_ID_UC_OPT_DONE_OPT,
    SCR_ID_UC_OPT_INSERT,
    SCR_ID_UC_OPT_REMOVE,
    SCR_ID_UC_OPT_REPLACE,
    SCR_ID_UC_OPT_ATTACHMENT_LIST,
    SCR_ID_UC_OPT_SLIDE_OPT,
    SCR_ID_UC_OPT_SLIDE_OPT_SLIDE_TIMING,
    SCR_ID_UC_OPT_SLIDE_OPT_GOTO,
    SCR_ID_UC_OPT_MSG_TYPE_OPT,
    SCR_ID_UC_OPT_SEND_OPT,
    SCR_ID_UC_PREFERRED_MSG_TYPE,
    SCR_ID_UC_SENDING,
    SCR_ID_UC_EXIT_OPT,
    SCR_ID_UC_PREVIEW_SLIDE_LIST,
    SCR_ID_UC_OPT_SLIDE_OPT_TIMING,
    SCR_ID_UC_OPT_INSERT_NEW_MM_OBJECT,

    SCR_ID_UC_SUBJECT_EDITOR, 
    /* add new items before this line */
    SCR_ID_UC_END
} uc_src_id_enum;

typedef enum
{
    UC_OPT_DONE,
    UC_OPT_INSERT,
    UC_OPT_REMOVE,
    UC_OPT_REPLACE,
    UC_OPT_PREVIEW,
    UC_OPT_SLIDE_OPT,
    UC_OPT_MSG_TYPE,
    UC_OPT_SEND_OPT,
    UC_OPT_MSG_DETAIL,
    UC_OPT_INPUT_METHOD,
        
    UC_OPT_TOTAL_NUM
} uc_opt_menu_enum;

typedef enum
{
    UC_OPT_ADDR_DONE,
    UC_OPT_ADDR_ADD_NUMBER,
    UC_OPT_ADDR_ADD_EMAIL,
    UC_OPT_ADDR_EDIT,
    UC_OPT_ADDR_DELETE,
    UC_OPT_ADDR_DELETE_ALL,
    UC_OPT_ADDR_ADD_NUMBER_GROUP,
    UC_OPT_ADDR_ADD_EMAIL_GROUP,
        
    UC_OPT_ADDR_TOTAL_NUM
} uc_addr_menu_enum;

typedef enum
{    
    UC_OPT_DONE_SEND,
    UC_OPT_DONE_SEND_AND_SAVE,
    UC_OPT_DONE_SAVE,
    UC_OPT_DONE_BACK_TO_EDIT_MSG,
    UC_OPT_DONE_MSG_TYPE,
    UC_OPT_DONE_SEND_OPT,
    UC_OPT_DONE_EXIT,
        
    UC_OPT_DONE_TOTAL_NUM
} uc_done_menu_enum;

typedef enum
{    
    UC_OPT_INSERT_IMAGE,
    UC_OPT_INSERT_AUDIO,
    UC_OPT_INSERT_VIDEO,
    UC_OPT_INSERT_TEXT_TEMPLATE,
    UC_OPT_INSERT_ATTACHMENT,      
    UC_OPT_INSERT_PHB_NUMBER,
    UC_OPT_INSERT_PHB_NAME,
    UC_OPT_INSERT_BOOKMARK,
    
    UC_OPT_INSERT_TOTAL_NUM
} uc_insert_menu_enum;

typedef enum
{    
    UC_OPT_REMOVE_IMAGE,
    UC_OPT_REMOVE_AUDIO,
    UC_OPT_REMOVE_VIDEO,
    UC_OPT_REMOVE_ATTACHMENT,
    
    UC_OPT_REMOVE_TOTAL_NUM
} uc_remove_menu_enum;

typedef enum
{    
    UC_OPT_REPLACE_IMAGE,
    UC_OPT_REPLACE_AUDIO,
    UC_OPT_REPLACE_VIDEO,
    UC_OPT_REPLACE_ATTACHMENT,    
    
    UC_OPT_REPLACE_TOTAL_NUM
} uc_replace_menu_enum;

typedef enum
{    
    UC_OPT_SLIDE_OPT_INSERT,
    UC_OPT_SLIDE_OPT_DELETE,
    UC_OPT_SLIDE_OPT_PREVIOUS,
    UC_OPT_SLIDE_OPT_NEXT,
    UC_OPT_SLIDE_OPT_GO_TO,
    UC_OPT_SLIDE_OPT_TIMING,
    
    UC_OPT_SLIDE_OPT_TOTAL_NUM
} uc_slide_opt_menu_enum;



#endif /* __MMI_UNIFIED_COMPOSER__ */ 
#endif /* _MMI_UNIFIED_COMPOSER_DEF_H */ 


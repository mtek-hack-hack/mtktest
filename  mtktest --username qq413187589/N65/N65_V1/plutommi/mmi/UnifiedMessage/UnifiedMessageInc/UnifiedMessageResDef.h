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
 * UnifiedMessageResDef.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines resource ID for Unified Message
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_UNIFIED_MESSAGE_DEF_H
#define _MMI_UNIFIED_MESSAGE_DEF_H

#include "MMIDataType.h"

#ifdef __MMI_UNIFIED_MESSAGE__

typedef enum
{
    STR_UM_MAIN_ID = (UNIFIED_MESSAGE_BASE + 1),
    STR_UM_WRITE_MSG_ID,
    STR_UM_INBOX_ID,
    STR_UM_UNSENT_ID,
    STR_UM_SENT_ID,
    STR_UM_DRAFT_ID,
    STR_UM_SIM_ID,
    STR_UM_DELETE_FOLDER_ID,
    STR_UM_TEMPLATE_ID,
    STR_UM_SETTING_ID,
    STR_UM_DELETE_FOLDER_INBOX_ID,
    STR_UM_DELETE_FOLDER_UNSENT_ID,
    STR_UM_DELETE_FOLDER_SENT_ID,
    STR_UM_DELETE_FOLDER_DRAFT_ID,
    STR_UM_DELETE_FOLDER_SIM_ID,
    STR_UM_DELETE_FOLDER_ALL_ID,
    STR_UM_DELETE_FOLDER_UNSENT_WITHOUT_SENDING_ID,
    STR_UM_DELETE_FOLDER_ALL_WITHOUT_SENDING_ID,
    STR_UM_DELETING_ID,
    STR_UM_LOADING_ID,
    STR_UM_MSG_ID,
    STR_UM_NEW_MSG_ID,
    STR_UM_UNREAD_MSG_NUMBER_ID,
    STR_UM_SEND_FAILED_SAVE_SUCCESS_ID,
    STR_UM_EMPTY_SUBJECT_ID,
    STR_UM_MAIN_MENU_TITLE_ID,
    STR_UM_INCOMPLETE_ID,
    STR_UM_NOT_SUPPORT_ID,
    STR_UM_SMS_ID,
    STR_UM_MMS_ID,
    STR_UM_SEND_SAVE_SUCCESS_ID,
    STR_UM_ARCHIVE_ID,
    STR_UM_DELETE_FOLDER_ARCHIVE_ID,
    STR_UM_NOT_AVAILABLE,

    STR_UM_TOTAL_ID
} um_str_id_enum;

typedef enum
{
    IMG_UM_WRITE_MSG_ID = (UNIFIED_MESSAGE_BASE + 1),
    IMG_UM_INBOX_ID,
    IMG_UM_UNSENT_ID,
    IMG_UM_SENT_ID,
    IMG_UM_DRAFT_ID,
    IMG_UM_SIM_ID,
    IMG_UM_DELETE_FOLDER_ID,
    IMG_UM_TEMPLATE_ID,
    IMG_UM_SETTING_ID,
    IMG_UM_DELETE_FOLDER_ALL_ID,
    IMG_UM_ENTRY_SCRN_CAPTION,
    IMG_UM_MAIN_ID,
    IMG_UM_ARCHIVE_ID,

    IMG_UM_TOTAL_ID
} um_img_id_enum;

typedef enum
{
    SCR_ID_UM_START = (UNIFIED_MESSAGE_BASE + 1),
    SCR_ID_UM_MAIN,
    SCR_ID_UM_WRITE_MSG,
    SCR_ID_UM_DELETE_FOLDER,
    SCR_ID_UM_TEMPLATE,
    SCR_ID_UM_SETTING,
    SCR_ID_UM_PROCESSING,
    SCR_ID_UM_INBOX,
    SCR_ID_UM_UNSENT,
    SCR_ID_UM_SENT,
    SCR_ID_UM_DRAFT,
    SCR_ID_UM_NEW_MSG_IND,
    SCR_ID_UM_NEW_MSG_DUMMY_IND,
    SCR_ID_UM_ARCHIVE,
    SCR_ID_UM_SIM,    

    /* add new items before this line */
    SCR_ID_UM_END
} um_src_id_enum;

typedef enum
{
    UM_MENU_WRTIE_MSG,
    UM_MENU_INBOX,
    UM_MENU_UNSENT,
    UM_MENU_SENT,
    UM_MENU_DRAFT,
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    UM_MENU_SIM,
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    UM_MENU_DELETE_FOLDER,
    UM_MENU_TEMPLATE,
    UM_MENU_SETTING,

    UM_MENU_TOTAL_NUM
} um_main_menu_enum;

typedef enum
{
    UM_SUPPORT_TYPE_SMS,
    UM_SUPPORT_TYPE_MMS,    /* including MMS and WAP push */

    UM_SUPPORT_TYPE_TOTAL_NUM
} um_support_msg_type_enum;

typedef enum
{
    UM_MSG_DELETE_FOLDER_INBOX,
    UM_MSG_DELETE_FOLDER_UNSENT,
    UM_MSG_DELETE_FOLDER_SENT,
    UM_MSG_DELETE_FOLDER_DRAFT,
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__    
    UM_MSG_DELETE_FOLDER_ARCHIVE,
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    UM_MSG_DELETE_FOLDER_SIM,
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

    UM_MSG_DELETE_FOLDER_TOTAL_NUM,
    UM_MSG_FOLDER_TOTAL_NUM = UM_MSG_DELETE_FOLDER_TOTAL_NUM
} um_msg_delete_folder_enum;

#endif /* __MMI_UNIFIED_MESSAGE__ */ 
#endif /* _MMI_UNIFIED_MESSAGE_DEF_H */ 


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
 *  VoiceMemoResDef.h
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
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef VOICE_MEMO_RESDEF_H
#define VOICE_MEMO_RESDEF_H

#include "MMI_features.h"   /* add if you use any compile options defined in MMI_features.h */

#ifdef __MMI_VOICE_MEMO__
#include "gui_data_types.h"
#include "MMIDataType.h"    /* for resource base */

enum VOICE_MEMO_RES_ID
{
    VOICE_MEMO_TITLE_TEXT = VOICE_MEMO_BASE + 1,
    VOICE_MEMO_TITLE_ICON,
    VOICE_MEMO_LSK_TEXT,
    VOICE_MEMO_RSK_TEXT,
    VOICE_MEMO_LSK_ICON,
    VOICE_MEMO_RSK_ICON,
    VOICE_MEMO_OPTION_TEXT,
    VOICE_MEMO_OPTION_ICON,

    VM_RECORD_TITLE_TEXT,
    VM_RECORD_TITLE_ICON,
    VM_RECORD_LSK_TEXT,
    VM_RECORD_RSK_TEXT,
    VM_RECORD_LSK_ICON,
    VM_RECORD_RSK_ICON,
    VM_RESUME_LSK_TEXT,
    VM_RESUME_LSK_ICON,

    VM_PLAY_TITLE_TEXT,
    VM_PLAY_TITLE_ICON,
    VM_PLAY_LSK_TEXT,
    VM_PLAY_RSK_TEXT,
    VM_PLAY_LSK_ICON,
    VM_PLAY_RSK_ICON,

    VM_APPEND_TITLE_TEXT,
    VM_APPEND_TITLE_ICON,
    VM_APPEND_LSK_TEXT,
    VM_APPEND_RSK_TEXT,
    VM_APPEND_LSK_ICON,
    VM_APPEND_RSK_ICON,

    VM_DELETE_TITLE_TEXT,
    VM_DELETE_TITLE_ICON,
    VM_DELETE_LSK_TEXT,
    VM_DELETE_RSK_TEXT,
    VM_DELETE_LSK_ICON,
    VM_DELETE_RSK_ICON,

    VM_DELETE_ALL_TITLE_TEXT,
    VM_DELETE_ALL_TITLE_ICON,
    VM_DELETE_ALL_LSK_TEXT,
    VM_DELETE_ALL_RSK_TEXT,
    VM_DELETE_ALL_LSK_ICON,
    VM_DELETE_ALL_RSK_ICON,

    VM_RENAME_TITLE_TEXT,
    VM_RENAME_TITLE_ICON,
    VM_RENAME_LSK_TEXT,
    VM_RENAME_RSK_TEXT,
    VM_RENAME_LSK_ICON,
    VM_RENAME_RSK_ICON,

    VM_RENAME_OPTION_TEXT,
    VM_RENAME_OPTION_ICON,
    VM_RENAME_OPTION_SAVE_TEXT,
    VM_RENAME_OPTION_SAVE_ICON,
    VM_RENAME_OPTION_INPUT_METHOD_TEXT,
    VM_RENAME_OPTION_INPUT_METHOD_ICON,

    VM_DELETE_QUERY_TEXT,
    VM_DELETE_ALL_QUERY_TEXT,
    VM_SAVE_QUERY_TEXT,
    VM_ABORT_QUERY_TEXT,
    VM_NOTICE_ERROR_TEXT,
    VM_NOTICE_WARNING_TEXT,
    VM_NOTICE_SUCCESS_TEXT,
    VM_DISC_FULL_TEXT,
    VM_OPEN_FILE_ERROR_TEXT,
    VM_DELETING_TEXT,
    VM_DELETE_FINISH_TEXT,
    VM_DEVICE_BUSY_TEXT,
    VM_NO_RECORD_TEXT,
    VM_RECORDING_TEXT,
    VM_PAUSED_TEXT,
    VM_PLAYING_TEXT,
    VM_RECORDING_IMG,
    VM_RECORDING_PAUSED_IMG,
    VM_PLAYING_IMG,
    VM_PLAYING_PAUSED_IMG,
    VM_EMPTY_TEXT
};

#endif 

#endif /* VOICE_MEMO_DEF_H */ 


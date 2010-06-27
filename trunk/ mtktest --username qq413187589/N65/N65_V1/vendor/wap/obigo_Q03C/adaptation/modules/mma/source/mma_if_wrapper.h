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
#ifndef _mma_if_wrapper_h
#define _mma_if_wrapper_h

/**********************************************************************
 * Constant definition
 **********************************************************************/
typedef enum
{
    MMA_WRAPPER_NONE,
    MMA_WRAPPER_CREATE,
    MMA_WRAPPER_CREATE_DONE,
    MMA_WRAPPER_GET_FOLDER,
    MMA_WRAPPER_MOVE,
    MMA_WRAPPER_SEND,
    MMA_WRAPPER_SEND_CANCEL,

    /* End */
    MMA_WRAPPER_END
}mma_wrapper_type_enum;

typedef enum
{
    MMA_WRAPPER_STATE_NULL,
    MMA_WRAPPER_STATE_QUEUED,
    MMA_WRAPPER_STATE_ACTIVE,

    /* End */
    MMA_WRAPPER_STATE_TOTAL
}mma_wrapper_state_enum;

/**********************************************************************
 * Structure definition
 **********************************************************************/
typedef struct 
{
    mma_wrapper_type_enum type;
    kal_uint8 sender;
    void *entry_info;
}mma_wrapper_entry_struct;

typedef struct 
{
    MmsMsgId msg_id;
    MmsFolderType folder;
}mma_wrapper_create_done_struct;

typedef struct 
{
    MmsFolderType folder;
    kal_uint32 from;
    kal_uint32 to;
}mma_wrapper_get_folder_struct;

typedef struct 
{
    MmsMsgId msg_id;
    MmsFolderType folder;
}mma_wrapper_move_struct;

/**********************************************************************
 * Function declarations
 **********************************************************************/
mma_wrapper_entry_struct *mma_wrapper_get_active_entry(mma_wrapper_type_enum type);
void mma_wrapper_schedule(mma_wrapper_type_enum type);

void MMA_createMessage(MSF_UINT8 source, MmsFileType fileType);
void MMA_createMessageDone(MSF_UINT8 source, MmsMsgId msgId, MmsFolderType folder);
void MMA_getFolderContent(MSF_UINT8 source, MmsFolderType folder, int from, int to);
void MMA_moveMessage(MSF_UINT8 source, MmsMsgId msg_id, MmsFolderType folder);
void MMA_sendMessage(MSF_UINT8 source, MmsMsgId msgId);
void MMA_sendCancel(MSF_UINT8 source, MmsMsgId msgId);

#endif

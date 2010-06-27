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
/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */

/*!\file mamh.h
 * \brief The logic of the message folder content handler for the MEA.
 */

#ifndef _MAMH_H_
#define _MAMH_H_


/******************************************************************************
 * Constants
 *****************************************************************************/

/*! \enum MeaMhSignals 
 *  Signals used to communicate with MH logic */
typedef enum
{
    /*! View folder content..
     *
     * u_param1 = folder
     */
    MEA_SIG_MH_ACTIVATE,

    /*! Remove the GUI for the message handler, and terminate application.
     *
     */
    MEA_SIG_MH_DEACTIVATE,

    /*!
     * u_param1 = the folder to activate
     */
    MEA_SIG_MH_SET_FOLDER,
    
    /*!
     * Update the current folder.
     * i_param = folder to update.
     *            MEA_FOLDER_NONE to refresh current folder.
     */
    MEA_SIG_MH_UPDATE_FOLDER,
    
    /*! The response from the MMS Service when deleting a message
     *
     */
    MEA_SIG_MH_DELETE_MESSAGE_RESPONSE,

    /*! The response from the MMS Service when listing a message folder.
     * p_param = MmsListOfProperties - the message folder list.
     */ 
    MEA_SIG_MH_FOLDER_LIST_RESPONSE,

    /*! Signal received when a message has been sent.
     *
     * u_param1 = The response, see #MeaConfirmDialogResult.
     */
    MEA_SIG_MH_SEND_RESPONSE,

    /*! Close the MEA?
     *
     * u_param = MEA_CONFIRM_DIALOG_OK or MEA_CONFIRM_DIALOG_CANCEL
     */
    MEA_SIG_MH_CLOSE_MEA,

    /*! Delete a message.
     * 
     * u_param1 = MEA_CONFIRM_DIALOG_OK or MEA_CONFIRM_DIALOG_CANCEL
     * u_param2 = msgId
     */
    MEA_SIG_MH_DELETE_MSG,

#ifdef WAP_SUPPORT
    /*! Delete all messages.
     * u_param1 = MEA_CONFIRM_DIALOG_OK or MEA_CONFIRM_DIALOG_CANCEL
     * u_param2 = msgId
     */
    MEA_SIG_MH_DELETE_ALL_MSG,

    MEA_SIG_MH_NUMBER_OPTION,
    /*! Make call response
     * u_param1 TRUE/FALSE result 
     */
    MEA_SIG_MH_MAKE_CALL_RSP,
#endif /* WAP_SUPPORT */
	/*! Navigation menu */
    /* Activate the navigation menu for the message handler.
     */
    MEA_SIG_MH_NAV_ACTIVATE,

    /*! Remove the navigation menu for the message handler.
     */
    MEA_SIG_MH_NAV_DEACTIVATE,
    MEA_SIG_MH_FORWARD_WITH_EDIT,
    MEA_SIG_MH_MOVE_TO_ARCHIVE,
    MEA_SIG_MH_SEND_MSG_MR_START,
    MEA_SIG_MH_SEND_MSG_MR_DONE,
    MEA_SIG_MH_SEND_MSG_ADD_RECIPIENT, /* add recipient when send a MM without it */
    MEA_SIG_MH_SEND_MSG,
    MEA_SIG_MH_SAVE_AS_TEMPLATE_FINISHED,
    MEA_SIG_MH_CREATE_DEF_TEMP,
    MEA_SIG_MH_CREATE_DEF_TEMP_FINISHED,
    MEA_SIG_MH_CREATE_DEF_TEMP_FINISHED_CONTINUE,
    MEA_SIG_MH_UM_GET_FOLDER_LIST,
    MEA_SIG_MH_UM_GET_MSG_INFO,
    MEA_SIG_MH_UM_READ_MSG,
    MEA_SIG_MH_UM_DELETE_ALL_MSG_REQ,
    MEA_SIG_MH_BGSR_CANCEL_SEND,
    MEA_SIG_MH_BGSR_DELETE_MSG,    
	MEA_SIG_MH_NAV_ACTIVATE_BGSR_RSP,
    MEA_SIG_MH_BGSR_CANCEL_DOWNLOAD,
    MEA_SIG_MH_BGSR_CANCEL_ALL_DOWNLOAD,
    MEA_SIG_MH_BGSR_MOVE_TO_DRAFT,
    MEA_SIG_MH_BGSR_MOVE_TO_DRAFT_RSP,    
    MEA_SIG_MH_BGSR_DELETE_ALL_MSG_REQ,
    MEA_SIG_MH_BGSR_DOWNLOAD_GET_MSG_INFO,
    MEA_SIG_MH_BGSR_DOWNLOAD_MSG_TYPE_RSP,
    MEA_SIG_MH_BGSR_DOWNLOAD_CONFIRM_RSP,
    MEA_SIG_MH_BGSR_DOWNLOAD_NOTIF_FILE_NOTIFY_RSP,
    MEA_SIG_MH_BGSR_DOWNLOAD_REQ,
    MEA_SIG_MH_SEND_SIZE_CONFIRM,
    MEA_SIG_MH_SLS_RSP
}MeaMhSignals;

/*! \enum MeaMhNavMenuItem
 *  Items that is displayed in the context sensitive navigation menu for the MH
 */
typedef enum
{
    MEA_MH_NEW_SMIL,       /*!< Create new SMIL message */
    MEA_MH_INBOX,          /*!< Change message folder to the Inbox folder */
    MEA_MH_OUTBOX,         /*!< Change message folder to the Outbox folder */
#if defined(MEA_MERGE_SENT)
    MEA_MH_DRAFTS,           /*!< Change message folder to the Sent folder */
#elif defined(MEA_MERGE_OUTBOX)
    MEA_MH_SENT,           /*!< Change message folder to the Sent folder */
#else
    MEA_MH_DRAFTS,         /*!< Change message folder to the Drafts folder */
    MEA_MH_SENT,           /*!< Change message folder to the Sent folder */
#endif /* defined(MEA_MERGE_SENT) */
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    MEA_MH_ARCHIVE,         /*!< Change message folder to the ARCHIVE folder */
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    MEA_MH_TEMPLATE,       /*!< Change message folder to the Template folder */
    MEA_MH_SETTINGS,       /*!< Configure the MEA */
    MEA_MH_MENU_COUNT,
    MEA_MH_VIEW_MM = MEA_MH_MENU_COUNT,        /*!< View selected message */
    MEA_MH_USING_TEMPLATE, /*!< Create a message from template */
    MEA_MH_DELETE_MM,      /*!< Delete selected message */
    MEA_MH_EDIT_MM,        /*!< Edit selected message */
    MEA_MH_UPDATE,         /*!< Refresh current folder */
    MEA_MH_SEND,           /*!< Send selected message */
    MEA_MH_DOWNLOAD,       /*!< Download selected message */
    MEA_MH_BACK,           /*!< Go back */
    MEA_MH_FORWARD,        /*!< Forward selected message */
    MEA_MH_REPLY,          /*!< Reply to selected message */
    MEA_MH_REPLY_SMS,
    MEA_MH_REPLY_ALL,      /*!< Reply-to-all to selected message */
    MEA_MH_DELETE_MM_ALL, /*!< Delete all messages */
    MEA_MH_MOVE_TO_ARCHIVE,   /*!<Move to archive*/
    MEA_MH_SAVE_AS_TEMPLATE,
    MEA_MH_PROPERTIES,
    MEA_MH_USE_NUMBER, 
    MEA_MH_CANCEL_SEND,
    MEA_MH_CANCEL_DOWNLOAD,
    MEA_MH_MOVE_TO_DRAFT,
    MEA_MH_SHOW_STATUS,
    MEA_MH_NAV_MENU_COUNT
}MeaMhNavMenuItem;

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
typedef enum
{
    MEA_MH_DEF_TEMP_RESULT_MEM_FULL = -3,
    MEA_MH_DEF_TEMP_RESULT_MAX_NUM = -2,
    MEA_MH_DEF_TEMP_RESULT_FAILED = -1,
    MEA_MH_DEF_TEMP_RESULT_OK = 0
}MeaMhCreateDefTemplateResult;
#endif

/******************************************************************************
 * Data-types
 *****************************************************************************/
typedef struct
{
    MmsMsgId        msgId;
    MmsFileType     fileType;
    MSF_BOOL        forwardLock;
}MeaMsgInfo;

/******************************************************************************
 * Prototype declarations
 *****************************************************************************/

MeaFolder meaGetCurrentFolder(void);
void meaMhInit(void);
#ifdef WAP_SUPPORT
void meaSetActiveMmId(MmsMsgId id);
MeaMsgInfo *meaGetMessageInfo(int index);
void meaMhSetOrigFolderType(MmsFolderType folderId);
#endif /* WAP_SUPPORT */
void meaSetActiveMm(int listIndex);
void meaMhTerminate(void);
MeaMsgInfo *meaGetActiveMm(void);

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
void meaCreateTemplatesFolderList(void);
void meaDeleteTemplatesFolderList(void);
void meaDeleteMhInst(void);
#endif

#endif /* _MAMH_H_ */


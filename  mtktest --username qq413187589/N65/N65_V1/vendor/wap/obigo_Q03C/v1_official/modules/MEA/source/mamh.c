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

/*! \file mamh.c
 *  \brief Logic for the MH view.
 */

/* MSF */
#include "msf_int.h"
#include "msf_core.h"
#include "msf_log.h"
#include "msf_cfg.h"
#include "msf_mem.h"
#include "msf_lib.h"
#include "msf_wid.h"
#include "msf_file.h"

/* MMS Service */
#include "mms_cfg.h"
#include "mms_def.h"
#include "mms_if.h"
#ifdef WAP_SUPPORT
#include "mmsl_if.h"
#include "mms_aApp.h"
#include "msig.h"  /* for fldmgr.h */
#include "fldmgr.h"  /* for fldrGetFolderId */
#include "wapadp.h"    /* WAP_DBG_ASSERT */
#endif

/* SLS */
#include "sls_cfg.h"
#include "sls_def.h"
#include "sls_if.h"

/* MEA */
#include "mea_rc.h"
#include "mea_def.h"
#include "mea_cfg.h"
#include "mamem.h"
#include "maintsig.h"
#ifdef WAP_SUPPORT
#include "matypes.h"
#include "mamr.h"  /* for mame.h */
#include "mame.h"
#include "mamv.h"
#endif 
#include "mamh.h"
#include "mauimh.h"
#include "macore.h"
#include "macomm.h"
#include "mauidia.h"
#include "mauicmn.h"
#include "maaddr.h"
#include "madel.h"
#include "maconf.h"
#ifdef __UNIFIED_MSG_SUPPORT__
#include "wap_um.h"
#include "mauimv.h"
#include "mautils.h"
#include "mamob.h"
extern void wap_send_mmi_mms_refresh_ind(MeaFolder folder);
#endif
#ifdef __UNIFIED_COMPOSER_SUPPORT__
#include "mammv.h"
#include "mmsadp.h"
#include "mma_if_wrapper.h"

extern void wap_send_mmi_mms_start_uc_req(kal_uint8 mode, kal_uint32 msg_id);
extern MSF_BOOL smaIsRunning(void);
#endif

#include "widget_extension.h"

extern MSF_BOOL mmcRemoveMsgIdFromJSRIndex(MSF_UINT32 msgId);
extern MSF_BOOL mmcIsJSRMsg(MSF_UINT32 msgId);
extern void wap_um_highlight_mms_message_ind(kal_uint32 msg_id, MeaFolder mea_box);
#ifdef __MMI_MMS_BGSR_SUPPORT__
#include "MMSBGSRGprot.h"
#include "widget.h"
#include "mea_int.h"
#include "manotif.h"
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
/******************************************************************************
 * Data-types
 *****************************************************************************/

typedef struct
{
    MmsListOfProperties     *mmsItems;      /*!< */
    MeaMsgInfo              *msgList;       /* not used in UM folders except template */
    MeaFolder               currentFolder;  /*!< */
    MeaFolder               newFolder;      /* not used in UM folders except template */
    MeaMsgInfo              activeMsg;      /*!< */
    int                     pendingUpdates; /* not used in UM folders except template */
}MeaMhFolderInfo;

#ifdef __UNIFIED_MSG_SUPPORT__
typedef struct
{
    MeaFolder folder;
    MSF_UINT16 startIndex;
} MeaMhUmFolderInfo;

static MeaMhUmFolderInfo *umfolderInfo = NULL;
#endif

#ifdef WAP_SUPPORT
static MSF_BOOL gMeaDeleteAllFlag = FALSE;
static MmsFolderType origFolderType= MMS_NO_FOLDER;
#endif

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
#define MEA_MH_CREATE_DEF_TEMP_TIMER_DUR    10
static MSF_UINT32 gDefTemplatesIndex = 0;
static MSF_BOOL gCheckingDefTemplates = FALSE;
extern U16 gCurrLangIndex;
#endif

/******************************************************************************
 * Static variables
 *****************************************************************************/
/*! The current folder information */
static MeaMhFolderInfo *folderInfo;
static MSF_UINT32 meaUmMsgIdx = 0;
#ifdef __MMI_MMS_BGSR_SUPPORT__
static mmi_mms_bgsr_msg_info_struct *bgsr_msg_info;
static MSF_UINT32 downloadLength;
MmsMsgId downloadMsgId;
static MmsFileType downloadMsgType;
static MeaGetNotifInstance *getNotifInstance;
#endif /*__MMI_MMS_BGSR_SUPPORT__*/

/******************************************************************************
 * Prototypes
 *****************************************************************************/
static void meaGetFolderList(MeaMhFolderInfo *fInfo, MeaFolder folder);
static void meaMhSignalHandler(MeaSignal *sig);
static void setNewFolderList(MeaFolder folder, MeaMhFolderInfo *fInfo, 
    MmsListOfProperties *newList);
static void updateView(MeaMhFolderInfo *fInfo, MeaFolder folder, 
    int forceUpdate);
static MSF_BOOL createFolderInstance(MeaMhFolderInfo **fInfo);
static void deleteFolderInstance(MeaMhFolderInfo **fInfo);
static void deleteMessageList(MeaMhFolderInfo *fInfo);
static MSF_UINT16 meaGetMmIdxFromMmId( MSF_UINT32 msg_id);
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
static MSF_BOOL meaIsNeedRecreateDefTemplates(void);
static void meaCreateDefaultTemplates(void);
static MSF_BOOL meaIsSysLangChanged(void);
static void updateLangfile(void);
static MSF_BOOL meaIsDefTemplatesLost(void);
static void meaDeleteAllDefaultTemplates(void);
static void meaDeleteAllDefaultTemplatesContinue(MmsListOfProperties *list);
static void meaIncreaseDefTemplatesIndex(void);
static MSF_UINT32 meaGetDefTemplatesIndex(void);
static void meaResetDefTemplatesIndex(void);
#endif

/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*! Creates a folder info instance
 *
 *****************************************************************************/
static MSF_BOOL createFolderInstance(MeaMhFolderInfo **fInfo)
{
    MeaMhFolderInfo *nInfo;
    if (NULL == *fInfo)
    {
        nInfo = MEA_ALLOC(sizeof(MeaMhFolderInfo));
        memset(nInfo, 0, sizeof(MeaMhFolderInfo));
        nInfo->pendingUpdates = 0;
        /* Default values for global variables */
        nInfo->currentFolder = MEA_FOLDER_INBOX;
        nInfo->newFolder = MEA_FOLDER_INBOX;
        nInfo->mmsItems = NULL;
        *fInfo = nInfo;
        return TRUE;
    }
    else
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAMH_A576367F8A15F1852B502ED381291D83, "(%s) (%d) MH instance is busy!\n", __FILE__, __LINE__));
        return FALSE;
    }
}

/*! \brief Converts a #MmsListOfProperties to a #MeaMsgInfo list.
 *
 *****************************************************************************/
static MeaMsgInfo *mmsFolderToMsgList(MmsListOfProperties **prop)
{
    unsigned int i;
    MeaMsgInfo *mInfo = NULL;
    unsigned int size;
    MmsMessageFolderInfo *fInfo;

    if (NULL != *prop)
    {
        size = sizeof(MeaMsgInfo)*((*prop)->noOfElements + 1);
        mInfo = MEA_ALLOC(size);
        memset(mInfo, 0, size);
        for (i = 0; i < (*prop)->noOfElements; i++)
        {
            fInfo = &((*prop)->msgPropertyList[i].msgFolderInfo);

            mInfo[i].msgId       = fInfo->msgId;
            mInfo[i].fileType    = (MmsFileType)fInfo->suffix;
            mInfo[i].forwardLock = fInfo->forwardLock;
        }
        MMSif_freeMmsListOfProperties(*prop, MSF_MODID_MEA);
        MEA_FREE(*prop);
        *prop = NULL;
    }
    return mInfo;
}

/*! Deletes the folder info instance
 *
 *****************************************************************************/
static void deleteFolderInstance(MeaMhFolderInfo **fInfo)
{
    MeaMhFolderInfo *nInfo;
    if (NULL != *fInfo)
    {
        nInfo = *fInfo;
        MMSif_freeMmsListOfProperties(nInfo->mmsItems, MSF_MODID_MEA);
        MEA_FREE(nInfo->mmsItems);
        MEA_FREE(nInfo->msgList);
        MEA_FREE(nInfo);
        *fInfo = NULL;
    }
}

/*!
 * \brief Deletes the current list of messages.
 *****************************************************************************/
static void deleteMessageList(MeaMhFolderInfo *fInfo)
{
    if (fInfo)
    {
        if (fInfo->mmsItems)
        {
            MMSif_freeMmsListOfProperties(fInfo->mmsItems, MSF_MODID_MEA);
            MEA_FREE(fInfo->mmsItems);
            fInfo->mmsItems = NULL;
        }
    }
}

/*!
 * \brief Gets the id of the message that is currently selected.
 *
 * \return The ID of the message that is currently selected, 0 if no valid 
 *         message is selected.
 *****************************************************************************/
MeaMsgInfo *meaGetActiveMm(void)
{
    if (NULL != folderInfo)
    {
        return &(folderInfo->activeMsg);
    }
    return 0;
}


/*!
 * \brief Gets the list of messages in a specific folder.
 * Note, This function call results in a external signal.
 *
 * \param folder The folder where messages is listed.
 *****************************************************************************/
static void meaGetFolderList(MeaMhFolderInfo *fInfo, MeaFolder folder)
{
    /* Convert the folder type from MEA to MMS */
    MmsFolderType mmsFolder = MMS_INBOX;
    switch(folder)
    {
    case MEA_FOLDER_INBOX:
        mmsFolder = (MmsFolderType)(MMS_INBOX | MMS_NOTIFY);
        break;
    case MEA_FOLDER_DRAFTS:
        mmsFolder = MMS_DRAFTS;
        break;
    case MEA_FOLDER_SENT:
        mmsFolder = MMS_SENT;
        break;
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    case MEA_FOLDER_ARCHIVE:
        mmsFolder = MMS_ARCHIVE;
        break;
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    case MEA_FOLDER_TEMPLATE:
        mmsFolder = MMS_TEMPLATES; /* The first free folder 
                                                       is used for the Template
                                                       folder */
        break;

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
    case MEA_FOLDER_USER_TEMPLATE:
        mmsFolder = MMS_USRDEF_TEMPLATES;
        break;
#endif

    case MEA_FOLDER_OUTBOX:
#if defined(MEA_MERGE_SENT)
        mmsFolder = (MmsFolderType)(MMS_OUTBOX | MMS_SENT);
#elif defined(MEA_MERGE_OUTBOX)
        mmsFolder = (MmsFolderType)(MMS_OUTBOX | MMS_DRAFTS);
#else
        mmsFolder = MMS_OUTBOX;
#endif /* defined(MEA_MERGE_SENT) */
        break;
    case MEA_FOLDER_NONE:
    case MEA_FOLDER_COUNT:
    default:
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAMH_91A18DAF90D6462C45305D582418BD32, "(%s) (%d) meaGetFolderList invalid folder (%d)\n", __FILE__, 
            __LINE__, folder));
        return;
    }
    fInfo->newFolder = folder;
    /* Get all messages from the service */
#ifdef __UNIFIED_COMPOSER_SUPPORT__
    MMA_getFolderContent(MSF_MODID_MEA, mmsFolder, 0, MMS_MAX_NO_OF_MSG - 1);
#else
    MMSif_getFolderContent(MSF_MODID_MEA, mmsFolder, 0, MMS_MAX_NO_OF_MSG - 1);
#endif
}

/*!
 * \brief Initiates the MH.
 *
 *****************************************************************************/
void meaMhInit(void)
{
    /* set sig-handler */
    meaSignalRegisterDst(MEA_MH_FSM, meaMhSignalHandler);
    folderInfo = NULL;
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, MAMH_66B5AC0B927631CBE04936FBB4FA5EBC, "MEA MH: initialized\n"));
}

#ifdef WAP_SUPPORT
void meaSetActiveMmId(MmsMsgId id)
{
    extern MmsMessageFolderInfo *fldrMgrGetMsgInfo(MSF_UINT32 msgId);
    if (NULL != folderInfo)
    {
        MmsMessageFolderInfo *msgInfo = (MmsMessageFolderInfo *)fldrMgrGetMsgInfo(id);
        folderInfo->activeMsg.msgId = id;
        folderInfo->activeMsg.fileType = msgInfo->suffix;
        folderInfo->activeMsg.forwardLock = msgInfo->forwardLock;
    }
}

MeaMsgInfo *meaGetMessageInfo(int index)
{
    MeaMsgInfo *mInfo = NULL;
    unsigned int size;
    //MmsMessageFolderInfo *fInfo;

    size = sizeof(MeaMsgInfo);
    mInfo = MEA_ALLOC(size);
    memset(mInfo, 0, size);
    mInfo->msgId       = folderInfo->msgList[index].msgId;
    mInfo->fileType    = folderInfo->msgList[index].fileType;
    mInfo->forwardLock = folderInfo->msgList[index].forwardLock;
    return mInfo;
}

void meaMhSetOrigFolderType(MmsFolderType folderId)
{
    origFolderType= folderId;
}

void meaMMCUpdateFolder(void)
{
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAMH_22805202FFA14830AD2EB718861D6270, "MH: MEA MMC Delete or Create MESSAGE RESPONSE received\n"));
        (void)MEA_SIGNAL_SENDTO_I(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER, 
            MEA_FOLDER_NONE);
}

/*!
 * \brief Check if delete all operation should be performed
 *
 * \return TRUE: Delete all operation had been performed no matter succeeded or not
 *            FALSE: Delete all operaton had not been performed
 *****************************************************************************/
static MSF_BOOL meaMhDeleteAll(MmsListOfProperties *list)
{
    if (gMeaDeleteAllFlag)
    {
        int i;
#ifdef __MMI_MMS_BGSR_SUPPORT__
        int download_id = mmi_mms_bgsr_get_downloading_msg_id();
        int send_id = mmi_mms_bgsr_get_sending_msg_id();
#endif /*__MMI_MMS_BGSR_SUPPORT__*/

        gMeaDeleteAllFlag = FALSE;

#ifndef __UNIFIED_MSG_SUPPORT__
        HDIa_widgetExtEnterDeleteAllScreenNoInterrupt();
#endif

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
    #ifdef __UNIFIED_MSG_SUPPORT__
        if (meaGetCurrentFolder() == MEA_FOLDER_USER_TEMPLATE)
        {
            HDIa_widgetExtDisplayTransitionAnimation(TRUE);
        }
    #endif
#endif

        HDIa_widgetExtClearMMS();

        if(list->noOfElements == 0)
        {
#ifdef __UNIFIED_MSG_SUPPORT__
    #ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
            HDIa_widgetExtCloseTransitionAnimation();
    #endif
            wap_send_mmi_mms_delete_folder_rsp(TRUE);
#else
            HDIa_widgetExtLeaveDeleteAllScreen();
#endif
            return TRUE;
        }

        for(i=0;i < ((int)(list->noOfElements)-1);i++)
        {
            MmsMsgId msgId = list->msgPropertyList[i].msgFolderInfo.msgId;
#ifdef __MMI_MMS_BGSR_SUPPORT__
            if(msgId == download_id || msgId == send_id)
            {
                continue;
            }
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
            if (meaDeleteMsgEmergency(msgId) != TRUE)
            {
#ifdef __UNIFIED_MSG_SUPPORT__
    #ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
            HDIa_widgetExtCloseTransitionAnimation();
    #endif
                wap_send_mmi_mms_delete_folder_rsp(FALSE);
#else
                HDIa_widgetExtLeaveDeleteAllScreen();
/*                meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_ERROR), MEA_DIALOG_ERROR);*/
#endif
/*                return TRUE;*/
            }
#ifndef __UNIFIED_MSG_SUPPORT__  /* This would cause UM timeout and MMI use timer to update screen */
            HDIa_widgetExtGiveControlToMMI();    /* widget need to update progressing screen */
#endif
        }

#ifdef __MMI_MMS_BGSR_SUPPORT__
        if(list->msgPropertyList[list->noOfElements-1].msgFolderInfo.msgId == download_id ||
           list->msgPropertyList[list->noOfElements-1].msgFolderInfo.msgId == send_id )
        {
#ifdef __UNIFIED_MSG_SUPPORT__
    #ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
            HDIa_widgetExtCloseTransitionAnimation();
    #endif
            wap_send_mmi_mms_delete_folder_rsp(FALSE);
#else /*__UNIFIED_MSG_SUPPORT__*/
            HDIa_widgetExtLeaveDeleteAllScreen();
#endif /*__UNIFIED_MSG_SUPPORT__*/ 
            return TRUE;
        }

#endif /*__MMI_MMS_BGSR_SUPPORT__*/

#ifdef __UNIFIED_MSG_SUPPORT__
    #ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        if (meaGetCurrentFolder() == MEA_FOLDER_USER_TEMPLATE)
        {
            HDIa_widgetExtCloseTransitionAnimation();
            meaDeleteMsg(list->msgPropertyList[list->noOfElements-1].msgFolderInfo.msgId);  /* Reply from MMS, so folder is updated */
        }
        else
        {
    #endif
        if(meaDeleteMsgSilent(list->msgPropertyList[list->noOfElements-1].msgFolderInfo.msgId) == TRUE)
        {
            wap_send_mmi_mms_delete_folder_rsp(TRUE);
        }
        else
        {
            wap_send_mmi_mms_delete_folder_rsp(FALSE);
        }
    #ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        }
    #endif
#else
        HDIa_widgetExtLeaveDeleteAllScreen();
        meaDeleteMsg(list->msgPropertyList[list->noOfElements-1].msgFolderInfo.msgId);  /* Reply from MMS, so folder is updated */
#endif
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
#endif /* WAP_SUPPORT */

#ifdef __UNIFIED_MSG_SUPPORT__
static MSF_BOOL createUmFolderInstance(MeaMhUmFolderInfo **fInfo)
{
    MeaMhUmFolderInfo *nInfo;
    if (NULL == *fInfo)
    {
        nInfo = MEA_ALLOC(sizeof(MeaMhUmFolderInfo));
        memset(nInfo, 0, sizeof(MeaMhUmFolderInfo));
        nInfo->folder = MEA_FOLDER_INBOX;
        nInfo->startIndex = 0;
        *fInfo = nInfo;
        return TRUE;
    }
    else
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAMH_7DEDB5710FFFDD6FC18C3D9D9974E659, "(%s) (%d) MH UM instance is busy!\n", __FILE__, __LINE__));
        return FALSE;
    }
}

/*! Deletes the UM folder info instance
 *
 *****************************************************************************/
static void deleteUmFolderInstance(MeaMhUmFolderInfo **fInfo)
{
    MeaMhUmFolderInfo *nInfo;
    if (NULL != *fInfo)
    {
        nInfo = *fInfo;
        MEA_FREE(nInfo);
        *fInfo = NULL;
    }
}
#endif

/*!
 * \brief Signal handler for the message handler view.
 *
 * \param sig The signal received.
 *****************************************************************************/
static void meaMhSignalHandler(MeaSignal *sig)
{
    MmsListOfProperties *list;
    int ret;
    
    switch(sig->type)
    {
#ifdef __MMS_FORWARD_WITH_EDIT__
    case    MEA_SIG_MH_FORWARD_WITH_EDIT:
        {
            if ((MeaConfirmDialogResult)sig->u_param1 == MEA_CONFIRM_DIALOG_OK)
            {
                if(meaGetActiveMm()->forwardLock)
                {
                    HDIa_widgetExtShowPopup(MSF_MODID_MEA, MEA_GET_STR_ID(MEA_STR_ID_FAILED_FORWARD_LOCK), MsfError, 0);
                }
                else if(fldrGetMsgSize(meaGetActiveMm()->msgId) > MEA_CFG_MESSAGE_SIZE_MAXIMUM)
                {
                    HDIa_widgetExtShowPopup(MSF_MODID_MEA, MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_EDIT), MsfError, 0);
                }
                else
                {
                    (void)MEA_SIGNAL_SENDTO_IUU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, 
                        meaGetActiveMm()->fileType, MEA_ME_STARTUP_EDIT, 
                        (unsigned int)meaGetActiveMm()->msgId);
#ifndef __UNIFIED_COMPOSER_SUPPORT__
                    (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);
#endif
                }
            }
            else
            {
                (void)MEA_SIGNAL_SENDTO_IUU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, 
                    meaGetActiveMm()->fileType, MEA_ME_STARTUP_FORWARD, 
                    (unsigned long)meaGetActiveMm()->msgId);
            }
        }
        break;
#endif /*__MMS_FORWARD_WITH_EDIT__*/            
#ifdef __MMI_MMS_BGSR_SUPPORT__
        case MEA_SIG_MH_BGSR_DELETE_ALL_MSG_REQ:
        {
            mmi_mms_bgsr_msg_struct *data;
            if ((MeaConfirmDialogResult)sig->u_param1 == MEA_CONFIRM_DIALOG_OK)
            {
                data = MSF_MEM_ALLOCTYPE(MSF_MODID_WIDGET, mmi_mms_bgsr_msg_struct);
                memset((S8*)data, 0, sizeof(mmi_mms_bgsr_msg_struct));
                switch((MeaFolder)sig->u_param2)
                {
                    case MEA_FOLDER_INBOX:
                        data->op = MMI_MMS_BGSR_OP_DELETE_ALL_INBOX;
                        break;
                    case MEA_FOLDER_OUTBOX:
                        data->op = MMI_MMS_BGSR_OP_DELETE_ALL_OUTBOX;
                        break;
                    default:
                        ASSERT(0);
                }
                widget_execute_MMI_p(MEAa_chagneMessageReq, data, FALSE);
            }
            break;
        }

        case MEA_SIG_MH_BGSR_DELETE_MSG:
        {
            if ((MeaConfirmDialogResult)sig->u_param1 == MEA_CONFIRM_DIALOG_OK)
            {

                if(folderInfo->currentFolder == MEA_FOLDER_INBOX ||
                   folderInfo->currentFolder == MEA_FOLDER_OUTBOX )
                {
                    mmi_mms_bgsr_msg_struct *data;

                    data = MSF_MEM_ALLOCTYPE(MSF_MODID_WIDGET, mmi_mms_bgsr_msg_struct);
                    memset((S8*)data, 0, sizeof(mmi_mms_bgsr_msg_struct));
                    data->msg_id = (MmsMsgId)sig->u_param2;
                    switch(folderInfo->currentFolder)
                    {
                        case MEA_FOLDER_INBOX:
                            data->folder = MMI_MMS_BGSR_FOLDER_INBOX;
                            break;
                        case MEA_FOLDER_OUTBOX:
                            data->folder = MMI_MMS_BGSR_FOLDER_OUTBOX;
                            break;
                        default:
                            ASSERT(0);
                    }
                    data->op = MMI_MMS_BGSR_OP_DELETE;
                                   
                    widget_execute_MMI_p(MEAa_chagneMessageReq, data, FALSE);
                }
                else
                {
                    (void)MEA_SIGNAL_SENDTO_UU(MEA_MH_FSM, MEA_SIG_MH_DELETE_MSG, 
                    0, (MmsMsgId)sig->u_param2);
                }
            }
        }
        break;

    	case MEA_SIG_MH_NAV_ACTIVATE_BGSR_RSP:
     	{
            MmsMsgId msg_id = meaGetActiveMm()->msgId;
            if(bgsr_msg_info->result == MMI_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND)
            {
	            if (!meaCreateMhNavMenu(folderInfo->currentFolder, msg_id, 
	                meaGetActiveMm()->fileType, meaGetActiveMm()->forwardLock, NULL))
	            {
	                meaDeleteMhNavMenu();
	                (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_ERROR), 
	                    MEA_DIALOG_ERROR);
	            }
            }
            else if(msg_id != meaGetActiveMm()->msgId)
            {
                break;
            }
            else
            {
	            if (!meaCreateMhNavMenu(folderInfo->currentFolder, msg_id, 
	                meaGetActiveMm()->fileType, meaGetActiveMm()->forwardLock, bgsr_msg_info))
	            {
	                meaDeleteMhNavMenu();
	                (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_ERROR), 
	                    MEA_DIALOG_ERROR);
	            }
            }
	        break;
		}

        case MEA_SIG_MH_BGSR_DOWNLOAD_GET_MSG_INFO:
        {
            if(sig->u_param2 > 0)
            {
                downloadMsgId = (MmsMsgId)sig->u_param2;
                meaSrhGetMessageInfo(MEA_MH_FSM, 
                    MEA_SIG_MH_BGSR_DOWNLOAD_MSG_TYPE_RSP, (MmsMsgId)sig->u_param2);
            }
            break;
        }
        case MEA_SIG_MH_BGSR_DOWNLOAD_MSG_TYPE_RSP:
        {
            if((MeaConfirmDialogResult)sig->u_param1 == MEA_CONFIRM_DIALOG_OK)
            {
                if ((NULL != sig->p_param) && 
                    ((((MmsMessageFolderInfo *)sig->p_param)->suffix == MMS_SUFFIX_NOTIFICATION) ||
                    (((MmsMessageFolderInfo *)sig->p_param)->suffix == MMS_SUFFIX_IMMEDIATE)))
                {
                    /* The msg type is ok, save on move on */
                    downloadMsgType = 
                        ((MmsMessageFolderInfo *)sig->p_param)->suffix;
                
                    ret = meaGetNotifLength(downloadMsgId, downloadMsgType, &downloadLength);
                    if (MEA_READ_NOTIF_DELAYED == ret) 
                    {   /* async, lets wait for file notify */
                        MSF_LOG_MSG((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA,
                            "(%s) (%d) delayed file operation\n", __FILE__, __LINE__));
                        break; 
                    }
                    else if (MEA_READ_NOTIF_DONE != ret) /* something went wrong */
                    {
                        (void)meaShowDialog(MEA_GET_STR_ID(
                            MEA_STR_ID_FAILED_TO_DISPLAY_NOTIF), MEA_DIALOG_ERROR);
                        break;
                    }
                    {
                        if (meaGetConfig()->roamingStatus &&
                            (MEA_RETRIEVAL_MODE_ROAMING_AUTOMATIC != 
                            meaGetConfig()->retrievalModeRoam ||
                            MEA_RETRIEVAL_MODE_ALWAYS_ASK == 
                            meaGetConfig()->retrievalMode))
                        {           
                            (void)meaShowRoamingRetrievalDialog(MEA_MH_FSM, MEA_SIG_MH_BGSR_DOWNLOAD_CONFIRM_RSP, 
                                downloadLength);  
                        }
                        else
                        {
                            (void)meaShowHomeRetrievalDialog(MEA_MH_FSM, MEA_SIG_MH_BGSR_DOWNLOAD_CONFIRM_RSP, 
                             downloadLength);        
                        }
                    }
                    MEA_FREE(sig->p_param);
                    sig->p_param = NULL;
                }
            }
            break;
        
        }
        case MEA_SIG_MH_BGSR_DOWNLOAD_CONFIRM_RSP:
        {
            if((MeaConfirmDialogResult)sig->u_param1 == MEA_CONFIRM_DIALOG_OK)
            {
                getNotifInstance = NULL;            
                meaCreateGetNotifInstance(&getNotifInstance, 
                downloadMsgId, downloadMsgType, MEA_MH_FSM,
                MEA_SIG_MH_BGSR_DOWNLOAD_NOTIF_FILE_NOTIFY_RSP);

                MEA_SIGNAL_SENDTO(MEA_MH_FSM, 
                    MEA_SIG_MH_BGSR_DOWNLOAD_NOTIF_FILE_NOTIFY_RSP);
            }
            break;
        }
        case  MEA_SIG_MH_BGSR_DOWNLOAD_NOTIF_FILE_NOTIFY_RSP:
        {
            ret = meaGetNotifFSM(getNotifInstance);
            if (MEA_READ_NOTIF_DELAYED == ret) 
            {   /* async, lets wait for file notify */
                MSF_LOG_MSG((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA,
                    "(%s) (%d) delayed file operation\n", __FILE__, __LINE__));
                break; 
            }
            else if (MEA_READ_NOTIF_DONE != ret) /* something went wrong */
            {
                (void)meaShowDialog(MEA_GET_STR_ID(
                    MEA_STR_ID_FAILED_TO_DISPLAY_NOTIF), MEA_DIALOG_ERROR);
                break;
            }
            /* verify roaming/retrieval modes (immediate, delayed, restricted...)*/

            if ((U64)downloadLength > (U64)msm_get_disk_free_space(WAP_STORAGE_MMS))
            {
                meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_STORAGE_FULL), MEA_DIALOG_ERROR);
                break;
            }

            if((U64)downloadLength > (U64)wap_custom_get_max_mms_msg_size())
            {
                meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_RETR_SIZE_EXCEEDED), MEA_DIALOG_ERROR);
                break;
            }
            {
                MmsMessageFolderInfo *MmsMFInfo = (MmsMessageFolderInfo *)fldrMgrGetMsgInfo(downloadMsgId);
                if(HDIa_timeUTCToLocal(getNotifInstance->notif->expiryTime + MmsMFInfo->date) < HDIa_timeGetCurrent())
                {
                    meaShowConfirmDialog(MEA_STR_ID_DOWNLOAD_EXPIRED_MM_CONFIRM, NULL, MEA_MH_FSM, MEA_SIG_MH_BGSR_DOWNLOAD_REQ, 0);
                    break;
                }
            }
            MEA_SIGNAL_SENDTO_UU(MEA_MH_FSM, MEA_SIG_MH_BGSR_DOWNLOAD_REQ, 0, downloadLength); 
            break;
        }
        case MEA_SIG_MH_BGSR_DOWNLOAD_REQ:
        {
            MmsMessageFolderInfo *MmsMFInfo = (MmsMessageFolderInfo *)fldrMgrGetMsgInfo((MmsMsgId)downloadMsgId);

            if ((MeaConfirmDialogResult)sig->u_param1 == MEA_CONFIRM_DIALOG_OK)
            {
                mmi_mms_bgsr_msg_struct *dl_data;

                dl_data = MSF_MEM_ALLOCTYPE(MSF_MODID_WIDGET, mmi_mms_bgsr_msg_struct);
                memset((S8*)dl_data, 0, sizeof(mmi_mms_bgsr_msg_struct));
                dl_data->msg_id = (MmsMsgId)downloadMsgId;
    		    dl_data->expire_time = 
                    getNotifInstance->notif->expiryTime - ( HDIa_timeGetCurrent() - HDIa_timeUTCToLocal(MmsMFInfo->date));
    		    dl_data->size = downloadLength;
                widget_execute_MMI_p(MEAa_downloadMessageReq, dl_data, FALSE);
            }
            break;
        }
        case MEA_SIG_MH_BGSR_CANCEL_DOWNLOAD:
        {
            if ((MeaConfirmDialogResult)sig->u_param1 == MEA_CONFIRM_DIALOG_OK)
                if (0 != meaGetActiveMm()->msgId)
                {

                    mmi_mms_bgsr_msg_struct *data;

                    data = MSF_MEM_ALLOCTYPE(MSF_MODID_WIDGET, mmi_mms_bgsr_msg_struct);
                    memset((S8*)data, 0, sizeof(mmi_mms_bgsr_msg_struct));
                    data->msg_id = meaGetActiveMm()->msgId;
                                      
                    widget_execute_MMI_p(MEAa_cancelDownloadMessageReq, data, FALSE);
                    /* Bring down the navigation menu */
                    (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);
                }
            break;
        }
        case MEA_SIG_MH_BGSR_CANCEL_ALL_DOWNLOAD:
        {
            mmi_mms_bgsr_msg_struct *data;

            data = MSF_MEM_ALLOCTYPE(MSF_MODID_WIDGET, mmi_mms_bgsr_msg_struct);
            memset((S8*)data, 0, sizeof(mmi_mms_bgsr_msg_struct));
            data->op = MMI_MMS_BGSR_OP_CANCEL_ALL_INBOX;

            widget_execute_MMI_p(MEAa_chagneMessageReq, data, FALSE);
            /* Bring down the navigation menu */
            (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);
            
            break;
        }
        case MEA_SIG_MH_BGSR_CANCEL_SEND:
        {
            if ((MeaConfirmDialogResult)sig->u_param1 == MEA_CONFIRM_DIALOG_OK)
                if (0 != meaGetActiveMm()->msgId)
                {

                    mmi_mms_bgsr_msg_struct *data;

                    data = MSF_MEM_ALLOCTYPE(MSF_MODID_WIDGET, mmi_mms_bgsr_msg_struct);
                    memset((S8*)data, 0, sizeof(mmi_mms_bgsr_msg_struct));
                    data->msg_id = meaGetActiveMm()->msgId;
                                      
                    widget_execute_MMI_p(MEAa_cancelSendMessageReq, data, FALSE);
                    /* Bring down the navigation menu */
                    (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);
                }
            break;
        }
        case MEA_SIG_MH_BGSR_MOVE_TO_DRAFT:
        {
            if ((MeaConfirmDialogResult)sig->u_param1 == MEA_CONFIRM_DIALOG_OK)
                if (0 != meaGetActiveMm()->msgId)
                {
                    mmi_mms_bgsr_msg_struct *data;

                    data = MSF_MEM_ALLOCTYPE(MSF_MODID_WIDGET, mmi_mms_bgsr_msg_struct);
                    memset((S8*)data, 0, sizeof(mmi_mms_bgsr_msg_struct));
                    data->msg_id = meaGetActiveMm()->msgId;
                    data->folder = MMI_MMS_BGSR_FOLDER_OUTBOX;
                    data->op = MMI_MMS_BGSR_OP_MOVE_TO_FOLDER;
                                   
                    widget_execute_MMI_p(MEAa_chagneMessageReq, data, FALSE);
                }
            break;
        }
        case MEA_SIG_MH_BGSR_MOVE_TO_DRAFT_RSP:
        {
            if ((MeaConfirmDialogResult)sig->u_param1 == MEA_CONFIRM_DIALOG_OK)
                if (0 != meaGetActiveMm()->msgId)
                {
#ifdef __UNIFIED_COMPOSER_SUPPORT__
                    MMA_moveMessage(MSF_MODID_MEA, (MmsMsgId)sig->u_param2, MMS_DRAFTS);
#else
                    MMSif_moveMessage(MSF_MODID_MEA, (MmsMsgId)sig->u_param2, MMS_DRAFTS);
#endif
                	MEA_SIGNAL_SENDTO_I(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER, 
                   MEA_FOLDER_OUTBOX);
                    MEA_SIGNAL_SENDTO_I(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER, 
                   MEA_FOLDER_DRAFTS);

                    meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_DONE), MEA_DIALOG_PROMPT_DONE);
#ifdef __UNIFIED_MSG_SUPPORT__
            /* for notification prop/Dr/Rr screen (option menu is from these screen)*/
                    (void)MEA_SIGNAL_SENDTO(MEA_MV_FSM, MEA_SIG_MV_DEACTIVATE);
#endif
            /* Bring down the navigation menu */
                    (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);
                }       
            
            break;
        }
#endif /*__MMI_MMS_BGSR_SUPPORT__*/

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MEA_SIG_MH_MOVE_TO_ARCHIVE:
        {
            if ((MeaConfirmDialogResult)sig->u_param1 == MEA_CONFIRM_DIALOG_OK)
                if (0 != meaGetActiveMm()->msgId)
                {
#ifdef __UNIFIED_COMPOSER_SUPPORT__
                    MMA_moveMessage(MSF_MODID_MEA, (MmsMsgId)sig->u_param2, MMS_ARCHIVE);
#else
                    MMSif_moveMessage(MSF_MODID_MEA, (MmsMsgId)sig->u_param2, MMS_ARCHIVE);
#endif
                	MEA_SIGNAL_SENDTO_I(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER, 
                   MEA_FOLDER_INBOX);
                    MEA_SIGNAL_SENDTO_I(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER, 
                   MEA_FOLDER_ARCHIVE);

                    meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_DONE), MEA_DIALOG_PROMPT_DONE);
#ifdef __UNIFIED_MSG_SUPPORT__
            /* for notification prop/Dr/Rr screen (option menu is from these screen)*/
                    (void)MEA_SIGNAL_SENDTO(MEA_MV_FSM, MEA_SIG_MV_DEACTIVATE);
                    /* Stop MOB(player) -> it'll evoke MEA_SIG_MMV_DEACTIVATE */
	                (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_DEACTIVATE);

#endif
            /* Bring down the navigation menu */
                    (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);
                }       
        }
        break;
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    /* MH view */
    case MEA_SIG_MH_ACTIVATE:
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        if ((MeaFolder)sig->u_param1 == MEA_FOLDER_TEMPLATE)
        {
            if (meaIsNeedRecreateDefTemplates())
            {
                /* start creating default templates*/
                meaCreateDefaultTemplates();
                break;
            }
        }
#endif
        if (!createFolderInstance(&folderInfo))
        {
#ifndef __UNIFIED_MSG_SUPPORT__  /* In UM, folder instance may be created when MEA_SIG_MH_UM_GET_FOLDER_LIST */
            (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_DEACTIVATE);
            break;
#endif
        }
        meaGetFolderList(folderInfo, (MeaFolder)sig->u_param1);
        break;
    case MEA_SIG_MH_DEACTIVATE:
#ifndef __UNIFIED_MSG_SUPPORT__
        if (MEA_STARTUP_MODE_DEFAULT == meaGetStartupMode())
        {
            meaSignalDelete(sig);
            /* Long jump */
            MEA_TERMINATE;
        }
        else
#endif
        {
            meaDeleteMhNavMenu();
            meaDeleteMhView();
            /* Delete folder content */
            deleteFolderInstance(&folderInfo);

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
            if (GetActiveScreenId() != WAP_SCREEN_WIDGET)
            {
                meaDeleteTemplatesFolderListView();
            }
            MSF_TIMER_RESET(MSF_MODID_MEA, MEA_MH_CREATE_DEF_TEMP_TIMER_ID);
#endif
        }
#ifdef __MMI_MMS_BGSR_SUPPORT__
        MEA_FREE(bgsr_msg_info);
        bgsr_msg_info = NULL;
#endif /*__MMI_MMS_BGSR_SUPPORT__*/        
        break;
    case MEA_SIG_MH_SET_FOLDER:
        updateView(folderInfo, (MeaFolder)sig->u_param1, FALSE);
        break;
    case MEA_SIG_MH_UPDATE_FOLDER:
#ifndef __UNIFIED_MSG_SUPPORT__
        /* Check if the current folder needs to be refreshed */
        if (meaMhIsActive())
        {
            /*
             *	We keep count of the update requests so we know if we should
             *  update the list again if several notifications has arrived
             *  when the GUI was busy. NOTE: This counter can only be increased
             *  when we know a signal will be sent to the MMS service.
             */
            folderInfo->pendingUpdates++;
            if (sig->i_param == MEA_FOLDER_NONE)
            {
                updateView(folderInfo, meaGetCurrentFolder(), TRUE);
            }
            else if (sig->i_param == meaGetCurrentFolder())
            {
                updateView(folderInfo, (MeaFolder)sig->i_param, TRUE);
            }
        }

        if (meaGetStartupMode() ==MEA_STARTUP_MODE_MENU && !gMeaDeleteAllFlag)
        {
            updateHintList();
        }
    #ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        updateTemplatesFolderListHint();
    #endif
#else
#ifdef __MMI_MMS_BGSR_SUPPORT__
            {
                MSF_UINT32 msg_id = (MmsMsgId)sig->u_param1;
                MSF_UINT32 result = (mmi_mms_bgsr_result_enum)sig->u_param2;
                MSF_UINT16 msg_idx = 0;
                if(result == MMI_MMS_BGSR_RESULT_OK)
                {
                    msg_idx = meaGetMmIdxFromMmId(msg_id);
                    wap_um_send_highlight_decided_by_um_ind(meaGetCurrentFolder() , msg_idx);                    
                }
                
            }
#endif /*__MMI_MMS_BGSR_SUPPORT__*/

    #ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        if (meaGetCurrentFolder() == MEA_FOLDER_USER_TEMPLATE)
        {
            if (meaMhIsActive())
            {
                /*
                 *	We keep count of the update requests so we know if we should
                 *  update the list again if several notifications has arrived
                 *  when the GUI was busy. NOTE: This counter can only be increased
                 *  when we know a signal will be sent to the MMS service.
                 */
                folderInfo->pendingUpdates++;
                if (sig->i_param == MEA_FOLDER_NONE)
                {
                    updateView(folderInfo, meaGetCurrentFolder(), TRUE);
                }
                else if (sig->i_param == meaGetCurrentFolder())
                {
                    updateView(folderInfo, (MeaFolder)sig->i_param, TRUE);
                }
            }

            if (meaGetStartupMode() ==MEA_STARTUP_MODE_MENU && !gMeaDeleteAllFlag)
                updateHintList();
        }
        else
        {
    #endif
        wap_send_mmi_mms_refresh_ind(meaGetCurrentFolder());

    #ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        }
    #endif
        
    #ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        updateTemplatesFolderListHint();
    #endif
    
#endif
        mmsUpdateIndicator();

        break;
    case MEA_SIG_MH_FOLDER_LIST_RESPONSE:
        list = sig->p_param;
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA,
            MAMH_E7CF09F4A9E54E6D48B2D089FE36AA88, "(%s) (%d)MEA_SIG_MH_FOLDER_LIST_RESPONSE received\n", __FILE__, 
            __LINE__));

        if(meaMhDeleteAll(list))
        {
            break;
        }

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        if (gCheckingDefTemplates)
        {
            meaDeleteAllDefaultTemplatesContinue(list);
            break;
        }
#endif

        if (!folderInfo) 
        {
            WAP_DBG_ASSERT(0);
            break; 
        }
		/*memset(&folderInfo->activeMsg, 0, sizeof(MeaMsgInfo));*/
#ifdef __UNIFIED_MSG_SUPPORT__
        if(umfolderInfo != NULL)
        {
            /* Set current folder */
            setNewFolderList(umfolderInfo->folder, folderInfo, list);
            wap_send_mmi_mms_get_msg_list_rsp(TRUE, meaGetCurrentFolder(), umfolderInfo->startIndex, folderInfo->mmsItems);    
            deleteUmFolderInstance(&umfolderInfo);
        }
        else
#endif
        {
        /* Set the new list as the current*/
        setNewFolderList(folderInfo->newFolder, folderInfo, list);
        if (folderInfo->pendingUpdates > 0)
        {
            folderInfo->pendingUpdates = 1;
            updateView(folderInfo, meaGetCurrentFolder(), TRUE); /* Display content */
        }
        else
        {
            folderInfo->pendingUpdates = 0;
            if (list->noOfElements==0) //if edit message and sent, don't show empty
            {
                if (folderInfo->currentFolder == MEA_FOLDER_TEMPLATE
#if defined(MEA_CFG_USER_TEMPLATE_SUPPORT) && defined(__UNIFIED_MSG_SUPPORT__)
                    || folderInfo->currentFolder == MEA_FOLDER_USER_TEMPLATE
#endif
                    )
                {
        	      (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_EMPTY), MEA_DIALOG_PROMPT_EMPTY);
                }
                meaDeleteMhNavMenu();
                meaDeleteMhView();
                deleteFolderInstance(&folderInfo);
            }
            else
            {	
                /* When back to version without User Defined Templates, there will be too many Default templates*/
#ifndef MEA_CFG_USER_TEMPLATE_SUPPORT
  #if defined(__MMI_MMS_TEMPLATES_NUM__) && (__MMI_MMS_TEMPLATES_NUM__ > 0)
                if (list->noOfElements > __MMI_MMS_TEMPLATES_NUM__)
                    list->noOfElements = __MMI_MMS_TEMPLATES_NUM__;
  #endif
#endif
                updateView(folderInfo, meaGetCurrentFolder(), FALSE);
            }
        }
        }
        break;
    case MEA_SIG_MH_DELETE_MESSAGE_RESPONSE:
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAMH_095F0E4FF5B649471572D98463948221, "MH: MEA_SIG_MH_DELETE_MESSAGE_RESPONSE received\n"));
        if (MEA_STARTUP_MODE_DELETE == meaGetStartupMode())
        {
            /* The MEA is started in delete mode, stop the application after
               the delete operation*/
            meaSignalDelete(sig);
            MEA_TERMINATE;
        }
        else
        {
            (void)MEA_SIGNAL_SENDTO_I(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER, 
                MEA_FOLDER_NONE);
        }
        meaShowDialog(MEA_GET_STR_ID(BRA_STR_ID_DELETED), MEA_DIALOG_PROMPT_DONE);
        break;
        
    /* Navigation menu */
    case MEA_SIG_MH_NAV_ACTIVATE:
        {
        /* Set active message */
#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
        meaSetActiveMm((int)sig->u_param2);
#else
        meaSetActiveMm(meaGetSelectedMhItem());
#endif
#ifdef __MMI_MMS_BGSR_SUPPORT__
            if(folderInfo->currentFolder == MEA_FOLDER_OUTBOX || 
               folderInfo->currentFolder == MEA_FOLDER_INBOX )
            {
                if(bgsr_msg_info == NULL)
                {
                    bgsr_msg_info = MSF_MEM_ALLOCTYPE(MSF_MODID_MEA, mmi_mms_bgsr_msg_info_struct);
                }
                memset((S8*)bgsr_msg_info, 0, sizeof(mmi_mms_bgsr_msg_info_struct));
                bgsr_msg_info->msg_id = meaGetActiveMm()->msgId;
                                  
                widget_execute_MMI_p(MEAa_getMessageInfo, bgsr_msg_info, FALSE);
/*	            (void)meaShowDialog(MEA_GET_STR_ID(WIDGET_STR_ID_PLEASE_WAIT), 
	                MEA_DIALOG_INFO);*/
                
            }
            else
#endif /*__MMI_MMS_BGSR_SUPPORT__*/                
            {
        if (!meaCreateMhNavMenu(folderInfo->currentFolder, meaGetActiveMm()->msgId, 
    	            meaGetActiveMm()->fileType, meaGetActiveMm()->forwardLock
#ifdef __MMI_MMS_BGSR_SUPPORT__
    	            , NULL
#endif /*__MMI_MMS_BGSR_SUPPORT__*/    	            
    	            ))
        {
            meaDeleteMhNavMenu();
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_ERROR), 
                MEA_DIALOG_ERROR);
        }
        meaUmMsgIdx = meaGetActiveMm()->msgId;
            }
        break;
    	}
    case MEA_SIG_MH_NAV_DEACTIVATE:
#ifdef __MMI_MMS_BGSR_SUPPORT__        
        if( bgsr_msg_info != NULL)
        {
            memset(bgsr_msg_info, 0, sizeof(mmi_mms_bgsr_msg_info_struct));
        }
#endif /*__MMI_MMS_BGSR_SUPPORT__*/        
        meaDeleteMhNavMenu();
        break;

    case MEA_SIG_MH_SEND_RESPONSE:
    {
        MeaSendResult sendResult = (MeaSendResult)sig->u_param1;
        if ((sendResult == MEA_SEND_CANCELLED && (origFolderType == MMS_DRAFTS || origFolderType == MMS_OUTBOX))
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            || origFolderType == MMS_ARCHIVE
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
        )
        {
#ifdef __UNIFIED_COMPOSER_SUPPORT__
            MMA_moveMessage(MSF_MODID_MEA, (MmsMsgId)sig->u_param2, origFolderType);
#else
            MMSif_moveMessage(MSF_MODID_MEA, (MmsMsgId)sig->u_param2, origFolderType);
#endif
        }
        else
        {
#ifndef __MMI_MMS_BGSR_SUPPORT__
            if (sig->p_param)
            {
                meaShowSendDialogWithText((MeaSendResult)sig->u_param1, (char *)sig->p_param);
                MEA_FREE(sig->p_param);
                sig->p_param = NULL;
            }
            else
            {
                meaShowSendDialog(sendResult, MEA_NOTUSED_FSM, 0);
            }
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
            (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);
        }
        
        origFolderType = MMS_NO_FOLDER;
        if ((sendResult != MEA_SEND_CANCELLED && sendResult != MEA_SEND_OK ) && folderInfo->currentFolder == MEA_FOLDER_DRAFTS)
        {
            (void)MEA_SIGNAL_SENDTO_I(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER, 
                MEA_FOLDER_NONE);
        }
    }
        break;
    case MEA_SIG_MH_CLOSE_MEA:
        if (MEA_CONFIRM_DIALOG_OK == sig->u_param1)
        {
            /* Close the application */
            (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_DEACTIVATE);
        }
        break;
    case MEA_SIG_MH_DELETE_MSG:
        if ((MeaConfirmDialogResult)sig->u_param1 == MEA_CONFIRM_DIALOG_OK)
        {
#ifdef __UNIFIED_MSG_SUPPORT__
            /* for notification prop/Dr/Rr screen (option menu is from these screen)*/
            (void)MEA_SIGNAL_SENDTO(MEA_MV_FSM, MEA_SIG_MV_DEACTIVATE);
            /* Stop MOB(player) -> it'll evoke MEA_SIG_MMV_DEACTIVATE */
	        (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_DEACTIVATE);
#endif
            /* Bring down the navigation menu */
            (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);

            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MAMH_0BBA7C6428843FB2001464D022D95171, "(%s) (%d) Trying to delete msgId=%d\n", __FILE__, __LINE__, 
                sig->u_param2));
            meaDeleteMsg((MmsMsgId)sig->u_param2);
        }
        else
        {
            /* Close the application if delete mode is active*/
            if (MEA_STARTUP_MODE_DELETE == meaGetStartupMode())
            {
                (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, 
                    MEA_SIG_CORE_TERMINATE_APP);
            }
        }
        break;

    case MEA_SIG_MH_DELETE_ALL_MSG:
        if ((MeaConfirmDialogResult)sig->u_param1 == MEA_CONFIRM_DIALOG_OK)
        {
            gMeaDeleteAllFlag = TRUE;
#ifdef __UNIFIED_MSG_SUPPORT__
  #ifdef __UNIFIED_COMPOSER_SUPPORT__
            MMA_getFolderContent(MSF_MODID_MEA, meaFolder2MmsFolder((MeaFolder)sig->u_param2), 0, MMS_MAX_NO_OF_MSG);
  #else
            MMSif_getFolderContent(MSF_MODID_MEA, meaFolder2MmsFolder((MeaFolder)sig->u_param2), 0, MMS_MAX_NO_OF_MSG);
  #endif
  #ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
            (void)MEA_SIGNAL_SENDTO(MEA_MV_FSM, MEA_SIG_MV_DEACTIVATE);
	        (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_DEACTIVATE);
  #endif
#else
            meaGetFolderList(folderInfo, (MeaFolder)sig->u_param2);   
#endif
            /* Bring down the navigation menu */
            (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);
        }
        break;
    case MEA_SIG_MH_NUMBER_OPTION:
        meaMhCreateUseDetailNavMenu();
        break;
    case MEA_SIG_MH_MAKE_CALL_RSP:
        /* sig->u_param1 has a TRUE/FALSE result */
        /* deliberately ignored since srh handles error dialogs for us */        
        break;

    case MEA_SIG_MH_SEND_MSG_MR_START:
    {
        MmsMsgId msgId = (MmsMsgId)sig->u_param1;
        meaStartMr(MEA_MR_STARTUP_NORMAL, msgId, fldrGetFileSuffix(msgId), MEA_MH_FSM, MEA_SIG_MH_SEND_MSG_MR_DONE);
        (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);
        break;
    }
    
    case MEA_SIG_MH_SEND_MSG_MR_DONE:
    {
        MeaMessage *message = (MeaMessage *)sig->p_param;

        if((MeaMrResult)sig->u_param1 != MEA_MR_OK || message == NULL || message->smilInfo == NULL)
        {
            meaFreeMessage(&message);
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_SEND), MEA_DIALOG_ERROR);
            break;
        }
            
        if(meaConfGetCreationMode() != MEA_CREATION_MODE_FREE)
        {
            char *filename = NULL;
            MeaMoDataItem *mo = NULL;
            MSF_BOOL isRestricted = TRUE;

            mo = message->smilInfo->mediaObjects;
            while(mo)
            {
                if(mo->isRestricted == FALSE)
                {
                    isRestricted = FALSE;
                }
                mo = mo->next;
            }

            mo = message->unrefList;
            while(mo)
            {
                if(mo->isRestricted == FALSE)
                {
                    isRestricted = FALSE;
                }
                mo = mo->next;
            }
            filename = MMSlib_getMessageFullPath(MSF_MODID_MEA, message->msgId, message->fileType);
            if(isRestricted == FALSE || MSF_FILE_GETSIZE(filename) > MEA_RESTRICTED_MESSAGE_SIZE)
            {
                (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_RESTRICTED_MODE_FAIL_TO_SEND), MEA_DIALOG_ERROR);
                MEA_FREE(filename);
                meaFreeMessage(&message);
                break;   
            }
            MEA_FREE(filename);
        }

        if(message->msgProperties->to == NULL && message->msgProperties->cc == NULL && message->msgProperties->bcc == NULL)
        {
            if (IsReachMEAMaxNumofMsg(MMS_MAX_NO_OF_MSG-1))
            {
                (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_MAX_NUMBER_OF_MSG), MEA_DIALOG_ERROR);            
            }
            else
            {
#ifdef __UNIFIED_COMPOSER_SUPPORT__
            wap_send_mmi_mms_start_uc_req(MMA_MODE_SEND, message->msgId);
#else
            (void)meaShowDialogWithConfirm(MsfWarning, MEA_STR_ID_OK, 0, MEA_STR_ID_ADD_RECIPIENT, 
                            MEA_MH_FSM, MEA_SIG_MH_SEND_MSG_ADD_RECIPIENT, message->msgId);     
#endif
            }
        }
        else
        {
#ifdef __MMS_SIZE_CONFIRM_BEFORE_SEND__
            meaSrhGetMessageInfo(MEA_MH_FSM, MEA_SIG_MH_SEND_SIZE_CONFIRM, (unsigned long)message->msgId);
#else /*__MMS_SIZE_CONFIRM_BEFORE_SEND__*/
            (void)MEA_SIGNAL_SENDTO_UU(MEA_MH_FSM, MEA_SIG_MH_SEND_MSG, 0, (unsigned long)message->msgId);
#endif /*__MMS_SIZE_CONFIRM_BEFORE_SEND__*/
        }
        meaFreeMessage(&message);
        break;   
    }
    case MEA_SIG_MH_SEND_MSG_ADD_RECIPIENT:
    {

        (void)MEA_SIGNAL_SENDTO_IUU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, MMS_SUFFIX_SEND_REQ, MEA_ME_STARTUP_EDIT, 
            sig->u_param2);
        (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);
        break;
    }
#ifdef __MMS_SIZE_CONFIRM_BEFORE_SEND__
    case MEA_SIG_MH_SEND_SIZE_CONFIRM:
    {
        int send_size = ((MmsMessageFolderInfo *)sig->p_param)->size;

        if (send_size > 0 )
        {
            const kal_uint8 * pstr1, *pstr2 ;
            kal_uint8  *p_msg_ucs, *p_msg_utf;
            kal_int32 temp_string_len = 12;
            kal_uint8  temp_string[12];
            int size_ucs, size_utf;
#ifdef __UNIFIED_COMPOSER_SUPPORT__
            float32  mms_size;
#else /*__UNIFIED_COMPOSER_SUPPORT__*/
            MSF_UINT32 mms_size;
#endif /*__UNIFIED_COMPOSER_SUPPORT__*/

            pstr1 = HDIa_widgetExtStringGetPredefinedUCS2buffer(MEA_STR_ID_MSGSIZE_PROMPT_1);
            pstr2 = HDIa_widgetExtStringGetPredefinedUCS2buffer(MEA_STR_ID_MSGSIZE_PROMPT_2);
            size_ucs = (widget_ucs2_length(pstr1) + widget_ucs2_length(pstr2) + temp_string_len) * 2;
            p_msg_ucs = (kal_uint8  *)MEA_ALLOC(size_ucs);

            widget_ucs2_strcpy(p_msg_ucs, pstr1);
#ifdef __UNIFIED_COMPOSER_SUPPORT__
            mms_size = (FLOAT)send_size/ (FLOAT) 1024.0;;
            sprintf((char*)temp_string, " %.1f ", mms_size);
#else /*__UNIFIED_COMPOSER_SUPPORT__*/
            mms_size = (MSF_UINT32)((sendInstance->size + (MEA_1_KB - 1)) / MEA_1_KB);
            sprintf((char*)temp_string, " %ld ", mms_size);
#endif /*__UNIFIED_COMPOSER_SUPPORT__*/
            widget_ucs2str_append_utf8(MSF_MODID_MEA, p_msg_ucs, &size_ucs, temp_string);
            widget_ucs2str_append_ucs2(MSF_MODID_MEA, p_msg_ucs, &size_ucs, pstr2);

            size_utf = widget_ucs2_length(p_msg_ucs) * 3 + 1;
            p_msg_utf = (kal_uint8  *)MEA_ALLOC(size_utf);
            widget_ucs2_to_utf8_string(p_msg_utf, size_utf, p_msg_ucs);

            (void)meaShowConfirmDialog(0, (char*)p_msg_utf, 
                MEA_MH_FSM, MEA_SIG_MH_SEND_MSG, 
                ((MmsMessageFolderInfo *)sig->p_param)->msgId);

            MEA_FREE(p_msg_ucs);
            MEA_FREE(p_msg_utf);
        }
        else
        {
            (void)MEA_SIGNAL_SENDTO_UU(MEA_MH_FSM, MEA_SIG_MH_SEND_MSG, 0, (unsigned long)((MmsMessageFolderInfo *)sig->p_param)->msgId);
        }
        break;
    }
#endif /*__MMS_SIZE_CONFIRM_BEFORE_SEND__*/
    case MEA_SIG_MH_SEND_MSG:
    {
        if ((MeaConfirmDialogResult)sig->u_param1 == MEA_CONFIRM_DIALOG_OK)
        {
            MmsMsgId msgId = (MmsMsgId)sig->u_param2;
            meaMhSetOrigFolderType(fldrGetFolderId(msgId));
    #ifdef WAP_SUPPORT
      #ifdef __UNIFIED_COMPOSER_SUPPORT__
            if(smaIsRunning())
            {
                meaModuleStop(MSF_MODID_SMA, FALSE);
            }
            else
            {
                (void)MEA_SIGNAL_SENDTO(MEA_MMV_FSM, MEA_SIG_MMV_NAV_DEACTIVATE);
                (void)MEA_SIGNAL_SENDTO(MEA_MMV_FSM, MEA_SIG_MMV_DEACTIVATE);
                (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_DEACTIVATE);
            }
      #else
            if (fldrGetFolderId(msgId) != MMS_OUTBOX && meaConfGetAutoSignature())  /*ex. in MMS_DRAFTS */
            {
                char *fullPath = MMSlib_getMessageFullPath(MSF_MODID_MEA, msgId, meaGetActiveMm()->fileType);
                MSF_INT32 mmsFileSize = MSF_FILE_GETSIZE(fullPath);
                MSF_INT32 sigFileSize;
                MEA_FREE(fullPath);
                if (mmsFileSize < 0 || (sigFileSize = MSF_FILE_GETSIZE(MEA_SIG_TEXT_FILE)) < 0 ||
                    mmsFileSize + sigFileSize > MEA_CFG_MESSAGE_SIZE_MAXIMUM)
                {
	                meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_AUTO_SIGNATURE_ERROR_SIZE_TOO_LARGE), MEA_DIALOG_ERROR);
	                break;
                }
                else
                {
                    (void)MEA_SIGNAL_SENDTO_IUU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, 0,
                        MEA_ME_STARTUP_APPEND_SIGNATURE, msgId);
                    break;
                }
            }
      #endif
    #endif /* WAP_SUPPORT */
    #ifndef __MMI_MMS_BGSR_SUPPORT__
            meaSendMessage(MEA_MH_FSM, MEA_SIG_MH_SEND_RESPONSE, msgId, TRUE);
    #else /*__MMI_MMS_BGSR_SUPPORT__*/
            {
                mmi_mms_bgsr_msg_struct *send_data;

                send_data = MSF_MEM_ALLOCTYPE(MSF_MODID_WIDGET, mmi_mms_bgsr_msg_struct);
                memset((S8*)send_data, 0, sizeof(mmi_mms_bgsr_msg_struct));
                send_data->msg_id = msgId;
                send_data->is_rr = 0; 
                send_data->send_setting = (meaGetConfig()->saveOnSend?
                                  MMI_MMS_BGSR_SETTING_SAVE_AND_SEND:
                                  MMI_MMS_BGSR_SETTING_SEND_ONLY);
                              
                widget_execute_MMI_p(MEAa_sendMessageReq, send_data, FALSE);
    #ifdef __UNIFIED_COMPOSER_SUPPORT__
                MMA_moveMessage(MSF_MODID_MEA, msgId, MMS_OUTBOX);
    #else
                MMSif_moveMessage(MSF_MODID_MEA, msgId, MMS_OUTBOX);
    #endif        
                (void)MEA_SIGNAL_SENDTO_I(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER, 
                MEA_FOLDER_NONE);
            }
    #endif /*__MMI_MMS_BGSR_SUPPORT__*/
        }
        break;
    }

#ifdef __UNIFIED_MSG_SUPPORT__
    case MEA_SIG_MH_UM_GET_FOLDER_LIST:
    {
        MeaFolder folder = (MeaFolder)sig->u_param1;
        MSF_UINT16 start = (MSF_UINT16)sig->u_param2;

        (void)createFolderInstance(&folderInfo);  /* In UM, folder instance won't be deleted when exiting folders except template folder */
        (void)createUmFolderInstance(&umfolderInfo);
        umfolderInfo->folder = folder;
        umfolderInfo->startIndex = start;
#ifdef __UNIFIED_COMPOSER_SUPPORT__
        MMA_getFolderContent(MSF_MODID_MEA, meaFolder2MmsFolder(folder), 0, MMS_MAX_NO_OF_MSG - 1);
#else
        MMSif_getFolderContent(MSF_MODID_MEA, meaFolder2MmsFolder(folder), 0, MMS_MAX_NO_OF_MSG - 1);
#endif
        break;
    }

    case MEA_SIG_MH_UM_GET_MSG_INFO:  /* receive after MEA_SIG_MH_UM_GET_FOLDER_LIST */
    {
        MSF_UINT16 max = (MSF_UINT16)sig->i_param;
        MeaFolder folder = (MeaFolder)sig->u_param1;
        MSF_UINT16 start = (MSF_UINT16)sig->u_param2;
        if(folder == meaGetCurrentFolder() && folderInfo->mmsItems != NULL)  /* current folder was set when receiving MEA_SIG_MH_UM_GET_FOLDER_LIST */
        {
            if(meaUmMsgIdx != folderInfo->activeMsg.msgId && meaUmMsgIdx != 0 && folderInfo->activeMsg.msgId !=0)
            {
                wap_um_highlight_mms_message_ind(0, meaGetCurrentFolder());
                meaUmMsgIdx = 0;
            }
            wap_send_mmi_mms_get_msg_info_rsp(TRUE, meaGetCurrentFolder(), start, max, folderInfo->mmsItems);
        }
        else
        {
            ASSERT(0);
        }
        break;
    }

    case MEA_SIG_MH_UM_READ_MSG:
    {
        MeaFolder folder = (MeaFolder)sig->u_param1;
        MSF_UINT16 msgIndex = (MSF_UINT16)sig->u_param2;
    	 if(folder == meaGetCurrentFolder())
    	 {
    	     MmsFileType fileType = MMS_SUFFIX_ERROR;
    	     MmsMsgId msgId = 0;
    	     
    	     meaSetActiveMm(msgIndex);
    	     msgId = meaGetActiveMm()->msgId;
    	     fileType = (MmsFileType)meaGetActiveMm()->fileType;

            if(!isValidMmsMSg(msgId))
            {
                (void)meaShowConfirmDialog(MEA_STR_ID_REMOVE_CORRUPT_MESSAGE_REQ, NULL, 
                    MEA_MH_FSM, MEA_SIG_MH_DELETE_MSG, msgId);
            }
            else if(fileType == MMS_SUFFIX_NOTIFICATION || fileType == MMS_SUFFIX_IMMEDIATE)
            {
                (void)MEA_SIGNAL_SENDTO_U(MEA_MV_FSM, MEA_SIG_MV_NOTIF, msgId);
            }
            else
            {
                (void)MEA_SIGNAL_SENDTO_IU(MEA_MV_FSM, MEA_SIG_MV_ACTIVATE, fileType, msgId);
            }
    	 }
        else
        {
            ASSERT(0);
        }
        break;
    }

    case MEA_SIG_MH_UM_DELETE_ALL_MSG_REQ:
    {
        if((MeaConfirmDialogResult)sig->u_param1 == MEA_CONFIRM_DIALOG_OK)
        {
            /* for notification prop/Dr/Rr screen (option menu is from these screen)*/
            (void)MEA_SIGNAL_SENDTO(MEA_MV_FSM, MEA_SIG_MV_DEACTIVATE);
            /* Stop MOB(player) -> it'll evoke MEA_SIG_MMV_DEACTIVATE */
	        (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_DEACTIVATE);
            (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);
            wap_send_mmi_mms_delete_all_ind((MeaFolder)sig->u_param2);
        }
        break;
    }
#endif

    case MEA_SIG_MH_SLS_RSP:
        meaSetUseNumberMsgID(meaGetActiveMm()->msgId);
        SLSif_openSmil(MSF_MODID_MEA, meaGetActiveMm()->msgId, meaGetActiveMm()->fileType);
        break;

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
    case MEA_SIG_MH_SAVE_AS_TEMPLATE_FINISHED:
        (void)meaShowDialog(MEA_GET_STR_ID(BRA_STR_ID_SAVED), 
                MEA_DIALOG_PROMPT_DONE);
        break;

    case MEA_SIG_MH_CREATE_DEF_TEMP:
        {
            MSF_UINT32 index;

            index = meaGetDefTemplatesIndex();
            
            if (index < __MMI_MMS_TEMPLATES_NUM__)
            {
                (void)MEA_SIGNAL_SENDTO_IUU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, 0,
                        MEA_ME_STARTUP_CREATE_DEF_TEMP, index);
            }
            else
            {
                ASSERT(0);
            }
        }
        break;

    case MEA_SIG_MH_CREATE_DEF_TEMP_FINISHED:
        {
            long   error;

            error = sig->i_param;

            if (error == MEA_MH_DEF_TEMP_RESULT_MEM_FULL)
            {
                (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_STORAGE_FULL),
                    MEA_DIALOG_ERROR);
                HDIa_widgetExtCloseTransitionAnimation();
                break;
            }
            else if (error == MEA_MH_DEF_TEMP_RESULT_MAX_NUM)
            {
                HDIa_widgetExtCloseTransitionAnimation();
                break;
            }
            else if (error == MEA_MH_DEF_TEMP_RESULT_FAILED)
            {
                (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_FAILED_ENTER_DEF_TEMPLATE),
                    MEA_DIALOG_ERROR);
                HDIa_widgetExtCloseTransitionAnimation();
                break;
            }
            
            MSF_TIMER_SET (MSF_MODID_MEA, MEA_MH_CREATE_DEF_TEMP_TIMER_ID, 
                MEA_MH_CREATE_DEF_TEMP_TIMER_DUR);
            
        }
        break;

    case MEA_SIG_MH_CREATE_DEF_TEMP_FINISHED_CONTINUE:
        {
            MSF_UINT32 index;
    
            meaIncreaseDefTemplatesIndex();
            index = meaGetDefTemplatesIndex();
            
            if (index < __MMI_MMS_TEMPLATES_NUM__)
            {
                (void)MEA_SIGNAL_SENDTO_IUU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, 0,
                        MEA_ME_STARTUP_CREATE_DEF_TEMP, index);
            }
            else
            {
                updateLangfile();
                (void)MEA_SIGNAL_SENDTO_U(MEA_MH_FSM, MEA_SIG_MH_ACTIVATE, 
                        MEA_FOLDER_TEMPLATE);
            }
        }
        break;
        
#endif

    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
            MAMH_0895AF14B74D7EA4D7AAAD999E3FC00B, "(%s) (%d)meaMhSignalHandler(%d): unknown signal\n", __FILE__, 
            __LINE__, sig->type));
        break;
    }
    meaSignalDelete(sig);
}

/*!
 * \brief Gets the folder that are currently active.
 *
 * \return The folder that is currently active.
 *****************************************************************************/
MeaFolder meaGetCurrentFolder()
{
    if (NULL != folderInfo)
    {
        return folderInfo->currentFolder;
    }
    return MEA_FOLDER_NONE;
}

/*!
 * \brief Free all resources for the MH.
 *
 *****************************************************************************/
void meaMhTerminate(void)
{
    /* remove sig-handler */
    meaSignalDeregister(MEA_MH_FSM); 
    /* Delete all views */
    meaDeleteMhNavMenu();
    meaDeleteMhStartupMenu();
    meaDeleteMhView();
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
    meaDeleteTemplatesFolderListView();
    gCheckingDefTemplates = FALSE;
    MSF_TIMER_RESET(MSF_MODID_MEA, MEA_MH_CREATE_DEF_TEMP_TIMER_ID);
#endif
    meaDeleteNumberListView();
    /* Delete folder content */
    deleteFolderInstance(&folderInfo);
#ifdef __UNIFIED_MSG_SUPPORT__
    deleteUmFolderInstance(&umfolderInfo);
#endif

    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, MAMH_43F70F7DFDDF633518E495172F76CD2F, "MEA MH: terminated\n"));
}

/*!
 * \brief Sets the active message.
 *
 * \param listIndex The index (of the folderItems->msg[]) of the msg to set as 
 *                  active.
 * \return The ID of the message that is currently selected, 0 if no valid 
 *         message is selected.
 *****************************************************************************/
void meaSetActiveMm(int listIndex)
{
    memset(&folderInfo->activeMsg, 0, sizeof(MeaMsgInfo));
    if (NULL != folderInfo->msgList)
    {
        /* Copy the active message instance */
        folderInfo->activeMsg.msgId = folderInfo->msgList[listIndex].msgId;
        folderInfo->activeMsg.fileType = 
            folderInfo->msgList[listIndex].fileType;
        folderInfo->activeMsg.forwardLock = 
            folderInfo->msgList[listIndex].forwardLock;
    }
#ifdef __UNIFIED_MSG_SUPPORT__
    else if(NULL != folderInfo->mmsItems && NULL != folderInfo->mmsItems->msgPropertyList)  /* UM: we don't have folderInfo->msgList*/
    {
        MmsMessageFolderInfo *msgInfo = &folderInfo->mmsItems->msgPropertyList[listIndex].msgFolderInfo;
        /* Copy the active message instance */
        folderInfo->activeMsg.msgId = msgInfo->msgId;
        folderInfo->activeMsg.fileType = msgInfo->suffix;
        folderInfo->activeMsg.forwardLock = msgInfo->forwardLock;
    }
#endif
}

/*!
 * \brief Sets a new folder list as to active one, the old one is released.
 *
 * \folder The folder which the message list applies to.
 * \newList The list of messages in a folder.
 *****************************************************************************/
static void setNewFolderList(MeaFolder folder, MeaMhFolderInfo *fInfo, 
    MmsListOfProperties *newList)
{
    if (NULL != fInfo)
    {
#ifdef __UNIFIED_MSG_SUPPORT__
        MmsListOfProperties *descList = NULL;
#endif
        /* Delete previous list*/
        deleteMessageList(fInfo);

#ifdef __UNIFIED_MSG_SUPPORT__
        /* Reverse list order from ascending to descending */
        if(umfolderInfo != NULL)
        {
            MSF_UINT32 i;
        
            MEA_CALLOC(descList, sizeof(MmsListOfProperties));
            if (newList == NULL || descList == NULL)
            {
                return;
            }
        
            descList->noOfElements = newList->noOfElements;
            if (descList->noOfElements > 0)
            {
                MEA_CALLOC(descList->msgPropertyList, sizeof(MmsMessageProperties) * descList->noOfElements);
                ASSERT(NULL != descList->msgPropertyList);
                
                for(i=0; i<descList->noOfElements; i++)
                {
                    if (!MMSif_copyMmsMessageProperties(&(descList->msgPropertyList[i]), &(newList->msgPropertyList[descList->noOfElements - i - 1]), MSF_MODID_MEA))
                    {
                        MSF_MEM_FREE(MSF_MODID_MEA, descList->msgPropertyList);
                        descList->msgPropertyList = NULL;
                    }
                }
            }
            else
            {
                descList->msgPropertyList = NULL;
            }

            MMSif_freeMmsListOfProperties(newList, MSF_MODID_MEA);
            MEA_FREE(newList);
            newList = descList;
        }
#endif

        fInfo->mmsItems      = newList;
        fInfo->currentFolder = folder;
#ifdef __UNIFIED_MSG_SUPPORT__
        if(umfolderInfo == NULL)
#endif
        {
            fInfo->pendingUpdates--;
        }
    }
}

/*! \brief Update the message folder content.
 *
 * \param folder  The folder to display.
 * \param forceUpdate TRUE if a new list of messages should be retrieved from the
 *                MMS Service, otherwise FALSE.
 *****************************************************************************/
static void updateView(MeaMhFolderInfo *fInfo, MeaFolder folder, 
    int forceUpdate)
{
    if ((folderInfo->currentFolder != folder) || forceUpdate)
    {
        if (MEA_FOLDER_NONE != folder)
        {
            /* Get folder items from the MMS Service */
            meaGetFolderList(fInfo, folder);
        }
        else
        {
            /* If the folder is set to "NONE" get the current folder again */
            meaGetFolderList(fInfo, folderInfo->currentFolder);
        }
    }
    /* Check weather the GUI is displayed */
    else if (meaMhIsActive())  
    {
        int noOfMessages = folderInfo->mmsItems->noOfElements;

        /* After the update the list is not needed anymore */
        MEA_FREE(fInfo->msgList);
        if (NULL == (fInfo->msgList = mmsFolderToMsgList(&(fInfo->mmsItems))))
        {
            MEA_TERMINATE;
        }

        if (folder != MEA_FOLDER_TEMPLATE)
            meaMhUpdateDynamicList(noOfMessages, folderInfo->currentFolder);
    }
    /* Create GUI if not previously created */
    else
    {
        /* Create new list */
        if (!meaCreateMhView(folderInfo->mmsItems, folderInfo->currentFolder))
        {
            MEA_TERMINATE;
        }
        MEA_FREE(fInfo->msgList);
        if (NULL == (fInfo->msgList = mmsFolderToMsgList(&(fInfo->mmsItems))))
        {
            MEA_TERMINATE;
        }
    }
}


/*! \brief get message index from message id
 *
 * \param message id  The message id 
 *****************************************************************************/
static MSF_UINT16 meaGetMmIdxFromMmId( MSF_UINT32 msg_id)
{
    MSF_UINT16 i;
    MmsMessageFolderInfo *msgInfo;
    int max_msg_num = wap_custom_get_max_mms_num();

    if(folderInfo != NULL && 
        NULL != folderInfo->mmsItems && 
        NULL != folderInfo->mmsItems->msgPropertyList)  /* UM: we don't have folderInfo->msgList*/
    {
        for(i = 0; i < max_msg_num;i++)
        {
            msgInfo = &folderInfo->mmsItems->msgPropertyList[i].msgFolderInfo;
            if(msgInfo->msgId == msg_id)        
            {
                return i;
            }
        }
    }
    return 0;
}


#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
void meaCreateTemplatesFolderList(void)
{
    meaCreateTemplatesFolderListView();
}

void meaDeleteTemplatesFolderList(void)
{
    meaDeleteTemplatesFolderListView();
}

void meaDeleteMhInst(void)
{
    meaDeleteMhNavMenu();
    meaDeleteMhView();
    /* Delete folder content */
    deleteFolderInstance(&folderInfo);
}

static MSF_BOOL meaIsSysLangChanged(void)
{
    int openMode = MSF_FILE_SET_RDONLY|HDI_FILE_SET_CUSTOM_BLOCKING;
    int fileHandle;
    U16 langIndex;
    U16 curLang;
    long result;
    
    fileHandle = MSF_FILE_OPEN(MSF_MODID_MEA, MEA_MH_LANG_FILE, openMode, 0);
    if (fileHandle <= 0)
    {
        updateLangfile();
        return TRUE;
    }
    /* read lang from file*/
    result = MSF_FILE_READ(fileHandle, &langIndex, sizeof(langIndex));
    MSF_FILE_CLOSE(fileHandle);

    if (result < 0)
    {
        updateLangfile();
        return TRUE;
    }
    
    /* get cur lang from setting*/
    curLang = gCurrLangIndex;
    
    if (curLang == langIndex)
    {        
        return FALSE;
    }

    updateLangfile();
    return TRUE;
}

static void updateLangfile(void)
{
    int openMode = HDI_FILE_SET_CREATE | HDI_FILE_SET_RDWR |
        HDI_FILE_SET_CUSTOM_BLOCKING;
    int fileHandle;
    U16 curLang;
    long result;
    
    /* get cur lang from setting*/
    curLang = gCurrLangIndex;
    
    fileHandle = MSF_FILE_OPEN(MSF_MODID_MEA, MEA_MH_LANG_FILE, openMode, 0);
    if (fileHandle <= 0)
        return;
    
    result = MSF_FILE_WRITE(fileHandle, &curLang, sizeof(curLang));
    MSF_FILE_CLOSE(fileHandle);
}

static MSF_BOOL meaIsDefTemplatesLost(void)
{
    MSF_UINT16 templates = 0, dummy = 0;
    
    fldrMgrGetNumberOfMessages(MMS_TEMPLATES, &templates, &dummy);
    
    return (templates != __MMI_MMS_TEMPLATES_NUM__);
}

static MSF_BOOL meaIsNeedRecreateDefTemplates(void)
{
    if (meaIsDefTemplatesLost() || meaIsSysLangChanged())
    {
        return TRUE;
    }
    return FALSE;
}

static void meaCreateDefaultTemplates(void)
{
    HDIa_widgetExtDisplayTransitionAnimation(TRUE);
    /* Delete all first*/
    meaDeleteAllDefaultTemplates();
    gCheckingDefTemplates = TRUE;
}

static void meaDeleteAllDefaultTemplates(void)
{
    /* Get message ids from MMS*/
//    MMSif_getFolderContent(MSF_MODID_MEA, MMS_TEMPLATES, 0, MMS_MAX_NO_OF_MSG);
#ifdef __UNIFIED_COMPOSER_SUPPORT__
    MMA_getFolderContent(MSF_MODID_MEA, MMS_TEMPLATES, 0, MMS_MAX_NO_OF_MSG - 1);
#else
    MMSif_getFolderContent(MSF_MODID_MEA, MMS_TEMPLATES, 0, MMS_MAX_NO_OF_MSG - 1);
#endif
}

static void meaDeleteAllDefaultTemplatesContinue(MmsListOfProperties *list)
{
    int i;

    if (!list)
    {
        gCheckingDefTemplates = FALSE;
        meaResetDefTemplatesIndex();
        (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_CREATE_DEF_TEMP);
        return;
    }
    
    for(i=0; i < (int)(list->noOfElements); i++)
    {
        MmsMsgId msgId = list->msgPropertyList[i].msgFolderInfo.msgId;

        if (meaDeleteMsgEmergency(msgId) != TRUE)
        {
            continue;
        }
    }

    gCheckingDefTemplates = FALSE;
    meaResetDefTemplatesIndex();
    (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_CREATE_DEF_TEMP);
}

static void meaIncreaseDefTemplatesIndex(void)
{
    gDefTemplatesIndex++;
}

static MSF_UINT32 meaGetDefTemplatesIndex(void)
{
    return gDefTemplatesIndex;
}

static void meaResetDefTemplatesIndex(void)
{
    gDefTemplatesIndex = 0;
}



#endif

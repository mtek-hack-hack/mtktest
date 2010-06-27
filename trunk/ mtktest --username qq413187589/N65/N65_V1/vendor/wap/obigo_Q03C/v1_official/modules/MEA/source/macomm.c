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

/* !\file macomm.c
 * Network communication handling.
 */

/* MSF */
#include "msf_core.h"
#include "msf_mem.h"
#include "msf_int.h"
#include "msf_log.h"
#include "msf_lib.h"
#include "msf_wid.h"
#include "msf_cmmn.h"

/* MMS */
#include "mms_def.h"
#include "mms_cfg.h"
#include "mms_if.h"
#ifdef WAP_SUPPORT
#include "mms_def.h"
#include "msig.h"     //for fldmgr.h
#include "fldmgr.h"  //for fldrMgrDeleteMessage
#endif /* WAP_SUPPORT */

/* SLS */
#include "sls_cfg.h"
#include "sls_def.h"
#include "sls_if.h"

/* MEA */
#include "maintsig.h"
#include "mea_rc.h"
#include "mea_def.h"
#include "matypes.h"
#include "mamem.h"
#include "mamh.h"
#include "mauipm.h"
#include "macomm.h"
#include "maconf.h"
#include "madel.h"
#include "mautils.h"
#include "mauicmn.h"
#include "mauidia.h"
#include "macore.h"
#include "masrh.h"
#include "mea_cfg.h"
#include "mauicomm.h"
#include "manotif.h"
#include "mauimenu.h"
#ifdef WAP_SUPPORT
#include "mamv.h"  //for mvClearMvInstance
#include "mauimh.h" //for meaMhIsActive
#include "mauipm.h" //for meaPmIsActive

  #ifdef MMS_FILE_PROTECT_SUPPORT
#include "MMS_aApp.h"
  #endif

  #ifdef __UNIFIED_COMPOSER_SUPPORT__
#include "mma_if_wrapper.h"
  #endif

#include "wapdef.h" //for MMS_STATUS_NEW_MESSAGE
#include "widget_extension.h" //for msm_get_disk_free_space  
#include "l3_inc_enums.h"  /* for bearer error code, ex. UNKNOWN_APN*/
#endif /* WAP_SUPPORT */


#ifdef __MMS_DUAL_SIM_SUPPORT__
#include "bra_cmn.h"
#include "wap_ps_struct.h"
#include "MTPNP_PFAL_Master_Def.h"
#include "gv.h"
#include "tst_def.h"
#include "wap_cmn.h"
#endif /*__MMS_DUAL_SIM_SUPPORT__*/

extern MSF_BOOL mmcIsRecvMMSForJava(MSF_UINT32 msgId);
extern MSF_INT32 HDIa_getLastError(void);
extern MmsMessageFolderInfo *fldrMgrGetMsgInfo(MSF_UINT32 msgId);
/******************************************************************************
 * Data-structures
 *****************************************************************************/

/*! \struct MeaSendInstance
 * Message sending data */
typedef struct
{
    MmsMsgId        msgId;        /* The ID of the message to send */
    MeaStateMachine resultFsm;    /* The FSM to send the response to */
    int             resultSignal; /* The signals that is sent to the 
                                     resultFsm */
    MSF_BOOL        showWarning;  /* Whether to show warning if size breaks
                                     conformance */
    MSF_UINT32      size;         /* Message size */
#ifdef __UNIFIED_MSG_SUPPORT__
    MmsMsgId        origMsgId;        /* The message ID the sending msg edited from (For deletion in end key handling)*/
#endif
#if MEA_CFG_SEND_TIMEOUT
    MSF_BOOL        timerActive;
#endif
}MeaSendInstance;

/*! \struct MeaDownloadInstance
 *  Message retrieval */
typedef struct
{
    MmsMsgId        msgId;        /* The ID of the notification */
    MmsFileType      msgType;      /* The ID of the notification */
    MeaStateMachine resultFsm;    /* The FSM to send the response to */
    int             resultSignal; /* The signals that is sent to the 
                                     resultFsm */
    MeaGetNotifInstance *getNotifInstance;  /* notification instance */
}MeaDownloadInstance;

#ifdef WAP_SUPPORT
typedef struct
{
    //MSF_UINT32 downloadLength;
    //MmsMsgId downloadMsgId;
    //MmsMsgType downloadMsgType;
    MeaStateMachine returnState;
    int returnSignal;
}MeaDownloadConfirmInstance;
#endif /* WAP_SUPPORT */
/******************************************************************************
 * Variables
 *****************************************************************************/

static MeaSendInstance *sendInstance;
static MeaDownloadInstance *downloadInstance;
#ifdef WAP_SUPPORT
static MSF_UINT32 downloadLength;
static MmsMsgId downloadMsgId;
static MmsFileType downloadMsgType;
static MeaDownloadConfirmInstance downloadConfirmInstance; //ToDo change *downloadConfirmInstance
//static MeaStateMachine downloadReturnState;
//static int downloadReturnSignal;
static unsigned int progressPercent = 0;
static MSF_BOOL meaRetryFlag;
#endif /* WAP_SUPPORT */

/******************************************************************************
 * Prototypes
 *****************************************************************************/
static unsigned int calculateProgress(unsigned int progress, 
    unsigned int totalSize);
static void cleanupSendInstance(MeaSendResult result, char *responseText);
static MSF_BOOL createSendInstance(MeaStateMachine fsm, unsigned int signal, 
    MmsMsgId msgId, MSF_BOOL showWarning);
static void cleanupDownloadInstance(MeaDownloadResult result);
static MSF_BOOL createDownloadInstance(MeaStateMachine fsm, 
    unsigned int signal, MmsMsgId msgId);
static void commSignalHandler(MeaSignal *sig);
static void handleProgress(const MmsProgressStatus *pStatus);

/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*! Calculates the current progress in per cent
 *
 * \param progress The current progress in bytes
 * \param totalSize The current size in bytes
 * \return The current progress in per cent 
 *****************************************************************************/
static unsigned int calculateProgress(unsigned int progress, 
    unsigned int totalSize)
{
    unsigned int perCent;
    /* Calculate the current progress */
    perCent = 0;
    if (totalSize > 0)
    {
        perCent = (progress*100)/totalSize;
    }
#ifdef WAP_SUPPORT
    (perCent < progressPercent)?
        (perCent = progressPercent):(progressPercent = perCent);
    if (perCent >= 100)
        return 99;  // don't show 100 because server may not send responese package
#else
    if (perCent > 100)
    {
        return 100;
    }
#endif /* WAP_SUPPORT */
    return perCent;
}

/*!
 * \brief Handles the download progress.
 *
 * \param pStatus The current progress from the MMS Service.
 *****************************************************************************/
static void handleProgress(const MmsProgressStatus *pStatus)
{
    char *initialStr = NULL;
    unsigned int percentage = 0;

    if (pStatus != NULL)
    {
        switch (pStatus->operation)
        {
        case MMS_PROGRESS_STATUS_SEND:
            if ((NULL != sendInstance) && 
                (sendInstance->msgId == pStatus->msgId))
            {
                /* Create progress text */
                initialStr = meaGetStringFromHandle(MEA_GET_STR_ID(WIDGET_STR_ID_PLEASE_WAIT));
                percentage = calculateProgress(pStatus->progress, pStatus->totalLength);
                if(meaRetryFlag == TRUE)
                {
                    char *endStr = NULL;
                    char *percent_str = NULL;

                    endStr = meaGetStringFromHandle(MEA_GET_STR_ID(MEA_STR_ID_RESEND));
                    percent_str = MEA_ALLOC(40);
                    sprintf(percent_str, " %d%%", percentage);
                    percent_str = msf_cmmn_strcat(MSF_MODID_MEA, endStr, percent_str);
                    meaPmSetProgressWithText(percentage, initialStr, percent_str);
                    MEA_FREE(endStr);
                    MEA_FREE(percent_str);
                }
                else
                {
                    meaPmSetProgressWithText(percentage, initialStr, ((percentage == 0)? "0%" : NULL));
                }
                MEA_FREE(initialStr);

#if MEA_CFG_SEND_TIMEOUT
                if (pStatus->progress == pStatus->totalLength && sendInstance->timerActive != TRUE)
                {
                    MSF_TIMER_SET(MSF_MODID_MEA, MEA_COMM_TIMER_ID, MEA_CFG_SEND_TIMEOUT * 10);
                    sendInstance->timerActive = TRUE;
                }
#endif                
            }
            break;
        case MMS_PROGRESS_STATUS_RETRIEVE:
            if (NULL != downloadInstance)
            {
                /* Create progress text */
                initialStr = meaGetStringFromHandle(MEA_GET_STR_ID(MEA_STR_ID_DOWNLOADING_MM));
                percentage = calculateProgress(pStatus->progress, pStatus->totalLength);
                meaPmSetProgressWithText(percentage, initialStr, ((percentage == 0)? "0%" : NULL));
                MEA_FREE(initialStr);
            }
            break;
        case MMS_PROGRESS_STATUS_IMMRETRIEVE:
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
                MACOMM_FFDA6C595AB0A6E0BA8FC696EB001279, "(%s) (%d) Immediate retrieval, progress=%x, "
                "totalLength=%x, state=%d\n", __FILE__, __LINE__, 
                pStatus->progress, pStatus->totalLength, pStatus->state));
            break;
        default:
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
                MACOMM_1A2EB79B6E72FEF9670559FC48554AF6, "(%s) (%d) Erroneous operation type, operation=%d.\n",
                __FILE__, __LINE__, pStatus->operation));
            break;
        }
    }
}

/*!
 * \brief Initiates the communication signal handler
 *****************************************************************************/
void meaCommInit(void)
{
    /* Register queue */
    sendInstance     = NULL;
    downloadInstance = NULL;
    meaSignalRegisterDst(MEA_COMM_FSM, commSignalHandler);
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, MACOMM_1E2F93223B960E8CF72BCCDA03680EAC, "COMM initialised\n"));
}

/*!
 * \brief Terminates the communication handler.
 *****************************************************************************/
void meaCommTerminate(void)
{
    /* Deregister queue */
    meaSignalDeregister(MEA_COMM_FSM);
    cleanupSendInstance(MEA_SEND_TERMINATE_SILENT, NULL);
    cleanupDownloadInstance(MEA_DOWNLOAD_TERMINATE_SILENT);
}

/*!
 * \brief  Check network settings and show an error dialog upon any errors
 *
 * \param signal The signal that is sent when closing the error dialog 
 * \return TRUE if settings are OK, FALSE if they are not and dialog is present
 *****************************************************************************/
static MSF_BOOL checkSettings()
{
    if (strlen(meaGetConfig()->proxyHost ? meaGetConfig()->proxyHost : ""))
    {
        /* all checks OK */
        return TRUE;
    }
#ifdef __MMS_DUAL_SIM_SUPPORT__
    if (strlen(meaGetConfig()->slaveProxyHost ? meaGetConfig()->slaveProxyHost : ""))
    {
        /* all checks OK */
        return TRUE;
    }
#endif /*__MMS_DUAL_SIM_SUPPORT__*/    
    return FALSE;
}

/*!
 * \brief  Activates FSM and sends a message.
 *
 * \param fsm    The fsm to post the result to.
 * \param retSig The signal that is sent as a result of the operation.
 * \param msgId  The message identity of the message to send.
 * \param showWarning Whether to show conformance warning
 *****************************************************************************/
void meaSendMessage(MeaStateMachine fsm, unsigned int retSig, MmsMsgId msgId, 
                    MSF_BOOL showWarning)
{
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
        MACOMM_FFAC4D9DB9C5D7F8320D701123C10E9B, "(%s) (%d) Send message initiated, msgId=%d\n", __FILE__, __LINE__, 
        msgId));

    /* verify network settings, and fail on faulty settings */
    if (!checkSettings())
    {
        (void)MEA_SIGNAL_SENDTO_UU(fsm, retSig, MEA_SEND_FAILED_SETTING, msgId);
        return;
    }
    
    if (!createSendInstance(fsm, retSig, msgId, showWarning) || msgId < 1) 
    {
        cleanupSendInstance(MEA_SEND_FAILED, NULL);
        return;
    } /* if */

    /* refresh roaming/bearer status */
    meaUpdateNetworkStatusInfo(MEA_COMM_FSM,  
        MEA_SIG_COMM_SEND_NETWORK_STATUS_RSP);                
}

/*!
 * \brief Creates a instance for sending a message.
 *
 * \param fsm    The fsm to post the result to.
 * \param signal The signal that is sent as a result of the operation.
 * \param msgId  The message identity of the message to send.
 * \param showWarning If a warning when breaking conformance should be shown
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL createSendInstance(MeaStateMachine fsm, unsigned int signal, 
    MmsMsgId msgId, MSF_BOOL showWarning)
{
    /* Check that a instance can be created */
    if (NULL != sendInstance) 
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MACOMM_6AC1A1B8B4EE2CA0D99DA38B7641ACF8, "(%s) (%d) unable to create instance.\n", __FILE__, __LINE__));
        return FALSE;
    }
    else
    {
        /* Create instance */
        sendInstance = MEA_ALLOC(sizeof(MeaSendInstance));
        memset(sendInstance, 0, sizeof(MeaSendInstance));
        sendInstance->msgId        = msgId;
        sendInstance->showWarning  = showWarning;
        sendInstance->resultFsm    = fsm;
        sendInstance->resultSignal = (int)signal;
#ifdef __UNIFIED_MSG_SUPPORT__
        sendInstance->origMsgId = 0;        /* end key handling */
#endif
        meaRetryFlag = FALSE;
        return TRUE;
    }
}

/*!
 * \brief Deallocates the current "send" instance and its resources.
 *
 * \param result The result to send back to the originating FSM.
 *****************************************************************************/
static void cleanupSendInstance(MeaSendResult result, char *responseText)
{
    if (NULL != sendInstance)
    {
        /* Remove progress meter */
        meaPmViewRemove();

        if (MEA_SEND_TERMINATE_SILENT != result)
        {
            /* Send response to the originating FSM, *if called for* */
            if (MEA_NOTUSED_FSM != sendInstance->resultFsm) 
            {
                char *response_text = NULL;
                if(responseText != NULL)
                {
                    MEA_CALLOC(response_text, strlen(responseText) + 1);
                    strcpy(response_text, responseText);
                }
                (void)MEA_SIGNAL_SENDTO_UUP(sendInstance->resultFsm, 
                    sendInstance->resultSignal, result, sendInstance->msgId, response_text);
            }
            else
            {
                /* No caller to report to, show dialog */
                if (responseText)
                {
                    meaShowSendDialogWithText(result, responseText);
                }
                else
                {
                meaShowSendDialog(result, MEA_NOTUSED_FSM, 0);
                }
                if ((!meaGetConfig()->saveOnSend && (MEA_SEND_OK == result)) || 
                    (MEA_SEND_CANCELLED== result || MEA_SEND_FAILED== result)) 
                {
                    meaDeleteMsgEmergency(sendInstance->msgId);
                }
            }
        }
        else /* press END key */
        {
#ifdef __UNIFIED_COMPOSER_SUPPORT__
            MMA_sendCancel(MSF_MODID_MEA, sendInstance->msgId);
            MMA_moveMessage(MSF_MODID_MEA, sendInstance->msgId, MMS_OUTBOX);  
#else
            MMSif_sendCancel(MSF_MODID_MEA, sendInstance->msgId);
            MMSif_moveMessage(MSF_MODID_MEA, sendInstance->msgId, MMS_OUTBOX);	
#endif
            meaMhSetOrigFolderType(MMS_NO_FOLDER);
#ifdef __UNIFIED_MSG_SUPPORT__
            if(sendInstance->origMsgId != 0)  /* delete original msg */
            {
                meaDeleteMsgEmergency(sendInstance->origMsgId);
            }
#endif
        }
        /*
         *	Check if we should delete the message after sending.
         */
        if (!meaGetConfig()->saveOnSend && (MEA_SEND_OK == result))
        {
            meaDeleteMsgEmergency(sendInstance->msgId);
        }

        MEA_FREE(sendInstance);
        sendInstance = NULL;
        meaRetryFlag = FALSE;
    }
}

/*!
 * \brief  Downloads a message.
 *
 * \param fsm    The fsm to post the result to.
 * \param retSig The signal that is sent as a result of the operation.
 * \param msgId  The message identity of the message to send.
 *****************************************************************************/
void meaDownloadMessage(MeaStateMachine fsm, unsigned int retSig, 
    MmsMsgId msgId)
{
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
        MACOMM_5C92C5AD7392008388FC91E5D51967AF, "(%s) (%d) Message download initiated, msgId=%d\n", __FILE__, __LINE__, 
        msgId));
#ifdef WAP_SUPPORT
  #ifdef MMS_FILE_PROTECT_SUPPORT
	if(!isValidMmsMSg(msgId))
	{   
		meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_MESSAGE_CORRUPT),MEA_DIALOG_ERROR);			
		return;
	}	
  #endif /* MMS_FILE_PROTECT_SUPPORT */
    (void)MEA_SIGNAL_SENDTO_IUU(MEA_COMM_FSM, MEA_SIG_COMM_DOWNLOAD_CONFIRM, 
        (long)retSig, (unsigned int)fsm, msgId);
#else
    (void)MEA_SIGNAL_SENDTO_IUU(MEA_COMM_FSM, MEA_SIG_COMM_DOWNLOAD, 
        (long)retSig, (unsigned int)fsm, msgId);
#endif /* WAP_SUPPPORT */
}

/*!
 * \brief Creates a instance for message download.
 *
 * \param fsm    The fsm to post the result to.
 * \param signal The signal that is sent as a result of the operation.
 * \param msgId  The message identity of the message to download.
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL createDownloadInstance(MeaStateMachine fsm, 
    unsigned int signal, MmsMsgId msgId)
{
    /* Check that a instance can be created */
    if (NULL != downloadInstance) 
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MACOMM_06624A97B5E3BD092A1651C972B6097A, "(%s) (%d) unable to create download instance.\n", __FILE__, 
            __LINE__));
        return FALSE;
    }
    else
    {
        /* Create instance */
        downloadInstance = MEA_ALLOC(sizeof(MeaDownloadInstance));
        memset(downloadInstance, 0, sizeof(MeaDownloadInstance));
        downloadInstance->msgId        = msgId;
        downloadInstance->resultFsm    = fsm;
        downloadInstance->resultSignal = (int)signal;
        /* Display the progress meter */
        if (!meaPmViewShow(MEA_STR_ID_DOWNLOADING_MM, TRUE,
            TRUE, MEA_COMM_FSM, MEA_SIG_COMM_DOWNLOAD_CANCEL))
        {
            meaPmViewRemove();
            MEA_FREE(downloadInstance);
            downloadInstance = NULL;
            return FALSE;
        }
        return TRUE;
    }
}

/*!
 * \brief Deallocates the current download instance and its resources.
 *
 * \param result The result to send back to the originating FSM.
 *****************************************************************************/
static void cleanupDownloadInstance(MeaDownloadResult result)
{
    if (NULL != downloadInstance)
    {
        if ((MEA_NOTUSED_FSM != downloadInstance->resultFsm) && 
            (MEA_DOWNLOAD_TERMINATE_SILENT != result))
        {
            /* Send response to the originating FSM */
            (void)MEA_SIGNAL_SENDTO_UU(downloadInstance->resultFsm, 
                downloadInstance->resultSignal, result, 
                downloadInstance->msgId);
        }
#ifdef WAP_SUPPORT
        else if (MEA_DOWNLOAD_TERMINATE_SILENT == result)
            MMSif_retrieveCancel(MSF_MODID_MEA, 
                downloadInstance->getNotifInstance->msgId);
#endif /* WAP_SUPPORT */
        else
        {
            /* Handle error dialogs if no other FSM is retrieving the result */
            if (MEA_DOWNLOAD_OK != result)
            {
                (void)meaShowDownloadErrorDialog(result, 
                    downloadInstance->resultFsm, 
                    downloadInstance->resultSignal);
            }
        }
 
        if (downloadInstance->getNotifInstance)
        {
            meaCleanupGetNotifInstance(&downloadInstance->getNotifInstance);            
        }

        MEA_FREE(downloadInstance);
        downloadInstance = NULL;
        /* Remove progress meter */
        meaPmViewRemove();
    }
#ifdef WAP_SUPPORT
    else
    {  /* Press cancel ? */
        if (result != MEA_DOWNLOAD_OK && result != MEA_DOWNLOAD_TERMINATE_SILENT &&
            !meaMhIsActive() && MEA_STARTUP_MODE_DOWNLOAD == meaGetStartupMode())
            (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP);
    }
#endif
}

/*!
 * \brief Verify roaming status and possibly ask user what to do
 *
 * \param signal What signal to send to comm when done.
 *****************************************************************************/
static void verifySendMode(int signal)
{
    /* show cost warning dialog when roaming and not immediate retrieval */
    if (meaGetConfig()->roamingStatus &&
        MEA_RETRIEVAL_MODE_ROAMING_RESTRICTED == 
        meaGetConfig()->retrievalModeRoam)
    {
        (void)meaShowRoamingSendDialog(MEA_COMM_FSM, signal, 
            sendInstance->size);  
    }
    else
    {
        (void)MEA_SIGNAL_SENDTO_UU(MEA_COMM_FSM,
            signal, MEA_CONFIRM_DIALOG_OK, 0);
    }      
}


/*!
 * \brief Verify roaming status and possibly ask user what to do
 *
 * \param signal What signal to send to comm when done.
 *****************************************************************************/
static void verifySendModeExt(int signal, MSF_UINT32 simId)
{
    int roamingStatusVerify;
    
#ifdef __MMS_DUAL_SIM_SUPPORT__
    if(simId == MMS_SIM_CARD_MASTER)
    {
        roamingStatusVerify = meaGetConfig()->roamingStatus;
    }
    else
    {
        roamingStatusVerify = meaGetConfig()->slaveRoamingStatus;
    }
#else
        roamingStatusVerify = meaGetConfig()->roamingStatus;        
#endif /*__MMS_DUAL_SIM_SUPPORT__*/    

    /* show cost warning dialog when roaming and not immediate retrieval */
    if (roamingStatusVerify &&
        MEA_RETRIEVAL_MODE_ROAMING_RESTRICTED == 
        meaGetConfig()->retrievalModeRoam)
    {
        (void)meaShowRoamingSendDialogExt(MEA_COMM_FSM, signal, 
            sendInstance->size, simId);  
    }
    else
    {
        (void)MEA_SIGNAL_SENDTO_UU(MEA_COMM_FSM,
            signal, MEA_CONFIRM_DIALOG_OK, simId);
    }      
}

#ifdef WAP_SUPPORT
#ifdef __UNIFIED_MSG_SUPPORT__
void meaSendEditedMessage(MeaStateMachine fsm, unsigned int retSig, MmsMsgId msgId, MmsMsgId origMsgId, MSF_BOOL showWarning)
{
    meaSendMessage(fsm, retSig, msgId, showWarning);
    if(sendInstance)
    {
        sendInstance->origMsgId = origMsgId;
    }
}
#endif
static MeaSendResult translateMmsSendResultToMea(MmsResult result)
{
    switch(result)
    {
    case MMS_RESULT_OK:
        return MEA_SEND_OK;
    case MMS_RESULT_BUSY:
        return MEA_SEND_BUSY;
    case MMS_RESULT_COMM_UNSUPPORTED_MEDIA_TYPE:
        return MEA_SEND_FAILED_REFUSED;
    case MMS_RESULT_CANCELLED_BY_USER:
        return MEA_SEND_CANCELLED;
	case MMS_RESULT_COMM_TIMEOUT:
		return MEA_SEND_TIMEOUT;
    case MMS_RESULT_COMM_ADDRESS_UNRESOLVED:
        return MEA_SEND_COMM_ADDRESS_UNRESOLVED;
    case MMS_RESULT_COMM_BAD_GATEWAY:
        return MEA_SEND_COMM_BAD_GATEWAY;
    case MMS_RESULT_COMM_ENTITY_TOO_LARGE:
        return MEA_SEND_COMM_ENTITY_TOO_LARGE;
    case MMS_RESULT_COMM_FAILED:
        return MEA_SEND_COMM_FAILED;
    case MMS_RESULT_COMM_FILE_NOT_FOUND:
        return MEA_SEND_COMM_FILE_NOT_FOUND;
    case MMS_RESULT_COMM_FORBIDDEN:
        return MEA_SEND_COMM_FORBIDDEN;
    case MMS_RESULT_COMM_HEADER_TAG:
        return MEA_SEND_COMM_HEADER_TAG;
    case MMS_RESULT_COMM_ILLEGAL_PDU:
        return MEA_SEND_COMM_ILLEGAL_PDU;
    case MMS_RESULT_COMM_LIMITATIONS_NOT_MET:
        return MEA_SEND_COMM_LIMITATIONS_NOT_MET;
    case MMS_RESULT_COMM_PROXY_ERROR:
        return MEA_SEND_COMM_PROXY_ERROR;
    case MMS_RESULT_COMM_MMSC_VERSION:
        return MEA_SEND_COMM_MMSC_VERSION;
    case MMS_RESULT_COMM_SECURITY_ERROR:
        return MEA_SEND_COMM_SECURITY_ERROR;
    case MMS_RESULT_COMM_SERVER_ERROR:
        return MEA_SEND_COMM_SERVER_ERROR;
    case MMS_RESULT_COMM_STATUS:
        return MEA_SEND_COMM_STATUS;
    case MMS_RESULT_COMM_TRANSACTION_ID:
        return MEA_SEND_COMM_TRANSACTION_ID;
    case MMS_RESULT_COMM_UNAUTHORIZED:
        return MEA_SEND_COMM_UNAUTHORIZED;
    case MMS_RESULT_COMM_UNAVAILABLE:
        return MEA_SEND_COMM_UNAVAILABLE;
    case MMS_RESULT_COMM_UNEXPECTED_MESSAGE:
        return MEA_SEND_COMM_UNEXPECTED_MESSAGE;
//    case MMS_RESULT_COMM_UNSUPPORTED_MEDIA_TYPE:
    case MMS_RESULT_COMM_UNSUPPORTED_VERSION:
        return MEA_SEND_COMM_UNSUPPORTED_VERSION;
    case MMS_RESULT_COMM_URI_TOO_LARGE:
        return MEA_SEND_COMM_URI_TOO_LARGE;
    case MMS_RESULT_COMM_WRONG_MMS_VERSION:
        return MEA_SEND_FAILED_COMM;
    default:
        return MEA_SEND_FAILED;
    }
}

/*! \brief Displays an error dialog with server responsed text
 *
 * \param result The #MeaDownloadResult.
 * \param responseText    The callback FSM.
 * \param fsm    The callback FSM.
 * \param signal The callback signal.
 *****************************************************************************/
void meaShowSendDialogWithText(MeaSendResult result, char *responseText)
{
    switch(result)
    {
    case MEA_SEND_OK:
        if (meaGetConfig()->saveOnSend)
        {
            (void)meaShowDialogWithCallback(MEA_GET_STR_ID(MEA_STR_ID_SAVED_AND_SENT), MEA_DIALOG_PROMPT_DONE, 
            MEA_NOTUSED_FSM, 0);
        }
        else
        {
            (void)meaShowDialogWithCallback(MEA_GET_STR_ID(MEA_STR_ID_MESSAGE_SENT), MEA_DIALOG_PROMPT_DONE, 
            MEA_NOTUSED_FSM, 0);
        }
        break;
        
    case MEA_SEND_CANCELLED:
        break;

    case MEA_SEND_FAILED_REFUSED:
    case MEA_SEND_FAILED_COMM:
        {
            char *prefix = NULL, *str = NULL;
            if (NULL == (prefix = meaGetStringFromHandle(MEA_GET_STR_ID(MEA_STR_ID_SERVER))))
            {
                str = msf_cmmn_strdup(MSF_MODID_MEA, responseText);
            }
            else
            {
                str = msf_cmmn_str3cat(MSF_MODID_MEA, prefix, (char *)": ", responseText);
            }
            showErrorDlg(str);
            MEA_FREE(str);
            MEA_FREE(prefix);
        }
        break;

    default:
        (void)meaShowDialogWithCallback(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_SEND), MEA_DIALOG_ERROR, MEA_NOTUSED_FSM, 0);
        break;
    }
}

//reset progress percent
void clearProgressPercent(void)
{
    progressPercent = 0;
}

static void cleanupDownloadConfirmInstance(/*MeaDownloadResult result*/)
{
    downloadMsgId = 0;
    mvClearMvInstance();
}

/*!
 * \brief Verify retrieval mode/roaming status and possibly ask user what to do
 * \param signal What signal to send to comm when done.
 * \param size size to download. 
 *****************************************************************************/
void verifyDownload(int signal, MSF_UINT32 size, MmsMsgId msgId)
{
    int roamingStatusVerify;
    downloadLength = size;
    downloadMsgId = msgId;
#ifdef __MMS_DUAL_SIM_SUPPORT__
    if(fldrGetMessageSimId(msgId) == MMS_SIM_CARD_MASTER)
    {
        int sim_status = wap_get_sim_status();
        if(sim_status != WAP_SIM_ID_DUAL_SIM && 
           sim_status != WAP_SIM_ID_SIM1)
        {
            meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_CALL_NO_NETWORK),MEA_DIALOG_ERROR);         
            MEA_SIGNAL_SENDTO_U(MEA_COMM_FSM, signal, 1);
            return;
        }
        roamingStatusVerify = meaGetConfig()->roamingStatus;
    }
    else
    {
        int sim_status = wap_get_sim_status();
        if(sim_status != WAP_SIM_ID_DUAL_SIM && 
           sim_status != WAP_SIM_ID_SIM2)
        {
            meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_CALL_NO_NETWORK),MEA_DIALOG_ERROR);         
            MEA_SIGNAL_SENDTO_U(MEA_COMM_FSM, signal, 1);
            return;
        }
        roamingStatusVerify = meaGetConfig()->slaveRoamingStatus;
    }
#else
        roamingStatusVerify = meaGetConfig()->roamingStatus;        
#endif /*__MMS_DUAL_SIM_SUPPORT__*/    
    /* show cost warning dialog when roaming and not immediate retrieval */
    if (roamingStatusVerify &&
        (MEA_RETRIEVAL_MODE_ROAMING_AUTOMATIC != 
        meaGetConfig()->retrievalModeRoam ||
        MEA_RETRIEVAL_MODE_ALWAYS_ASK == 
        meaGetConfig()->retrievalMode))
    {           
#ifdef __MMS_DUAL_SIM_SUPPORT__ 
        (void)meaShowRoamingRetrievalDialogExt(MEA_COMM_FSM, signal, 
            downloadLength, fldrGetMessageSimId(msgId));          
#else
        (void)meaShowRoamingRetrievalDialog(MEA_COMM_FSM, signal, 
            downloadLength);  
#endif /*__MMS_DUAL_SIM_SUPPORT__*/
    }
    else
    {
#ifdef __MMS_DUAL_SIM_SUPPORT__
        (void)meaShowHomeRetrievalDialogExt(MEA_COMM_FSM, signal, 
            downloadLength, fldrGetMessageSimId(msgId));        
#else
        (void)meaShowHomeRetrievalDialog(MEA_COMM_FSM, signal, 
            downloadLength);        
#endif /*__MMS_DUAL_SIM_SUPPORT__*/
    }        
}
#endif /* WAP_SUPPORT */

/*!
 * \brief Verify retrieval mode/roaming status and possibly ask user what to do
 *
 * \param signal What signal to send to comm when done.
 *****************************************************************************/
static void verifyRetrievalMode(int signal)
{
#ifndef WAP_SUPPORT
    /* show cost warning dialog when roaming and not immediate retrieval */
    if (meaGetConfig()->roamingStatus &&
        (MEA_RETRIEVAL_MODE_ROAMING_AUTOMATIC != 
        meaGetConfig()->retrievalModeRoam ||
        MEA_RETRIEVAL_MODE_ALWAYS_ASK == 
        meaGetConfig()->retrievalMode))
    {           
        (void)meaShowRoamingRetrievalDialog(MEA_COMM_FSM, signal, 
            downloadInstance->getNotifInstance->notif->length);  
    }
    else if (!meaGetConfig()->roamingStatus &&
        MEA_RETRIEVAL_MODE_ALWAYS_ASK == 
        meaGetConfig()->retrievalMode)
    {
        (void)meaShowHomeRetrievalDialog(MEA_COMM_FSM, signal, 
            downloadInstance->getNotifInstance->notif->length);        
    }
    else
#endif /* WAP_SUPPORT */
    {
        (void)MEA_SIGNAL_SENDTO_UU(MEA_COMM_FSM,
            signal, MEA_CONFIRM_DIALOG_OK, 0);
    }      
}

#ifdef __MMS_DUAL_SIM_SUPPORT__
static void navMenuSignalConverter(MeaNavAction actionType)
{
    if (MEA_NAV_ACTION_BACK == actionType)
    {
        cleanupSendInstance(MEA_SEND_CANCELLED, NULL);
        (void)MEA_SIGNAL_SENDTO(MEA_COMM_FSM, MEA_SIG_COMM_NAV_MENU_DEACTIVATE);
    }

    if (MEA_NAV_ACTION_OK == actionType)
    {
        switch(meaGetNavMenuItem())
        {
        case MEA_COMM_CHOOSE_SIM_1:
            (void)MEA_SIGNAL_SENDTO_U(MEA_COMM_FSM, MEA_SIG_COMM_CHOOSE_SIM_TO_SEND, MMS_SIM_CARD_MASTER);
            break;
        case MEA_COMM_CHOOSE_SIM_2:       /*!< Add MO to the message */
            (void)MEA_SIGNAL_SENDTO_U(MEA_COMM_FSM, MEA_SIG_COMM_CHOOSE_SIM_TO_SEND, MMS_SIM_CARD_SLAVE);
            break;
        default:
            break;
        }
        (void)MEA_SIGNAL_SENDTO(MEA_COMM_FSM, MEA_SIG_COMM_NAV_MENU_DEACTIVATE);

    }

}
/*!
 *  \brief Creates the context sensitive menu for the message handler.
 *
 *  \param folder The folder that i currently active.
 *  \param activeMsgId Message ID of the active message
 *  \param msgType The type of the active message. See #MmsFileType.
 *  \param forwardLock TRUE if the current message has a forward lock, 
 *                     otherwise FALSE.
 *  \return TRUE if the operation was successful, otherwise FALSE.
 *****************************************************************************/
static int createMenuItems()
{
    {
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_SIM_1), MEA_COMM_CHOOSE_SIM_1))//MEA_SIG_MV_ACTIVATE
            return FALSE;	
    }

    /* Delete only if a message is selected */
    {
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_SIM_2), MEA_COMM_CHOOSE_SIM_2))//MEA_SIG_MV_ACTIVATE
            return FALSE;	
    }
    
    return TRUE;
}

MSF_BOOL meaCommChooseSimMenu()
{
    if (!meaCreateNavMenu(0, navMenuSignalConverter))
    {
        meaRemoveNavMenu();
        return FALSE;
    }else if (!createMenuItems())
    {
        meaRemoveNavMenu();
        return FALSE;
    }else if (!meaShowNavMenu())
    {
        meaRemoveNavMenu();
        return FALSE;
    }
    return TRUE;

}
#endif /*__MMS_DUAL_SIM_SUPPORT__*/

/*!
 * \brief Signal handler for the comm FSM.
 *
 * \param sig The received signal
 *****************************************************************************/
static void commSignalHandler(MeaSignal *sig)
{
    MmsProgressStatus       *msgStatus;
    int ret;

    switch(sig->type)
    {
/******************************************************************************
 *  Send signals	
 *****************************************************************************/
    case MEA_SIG_COMM_NAV_MENU_DEACTIVATE:
        meaRemoveNavMenu();
        break;
    case MEA_SIG_COMM_SEND_NETWORK_STATUS_RSP:
        meaSrhGetMessageInfo(MEA_COMM_FSM, 
            MEA_SIG_COMM_SEND_MESSAGE_INFO_RETRIEVED, sendInstance->msgId);
        break;

    case MEA_SIG_COMM_SEND_MESSAGE_INFO_RETRIEVED:
        sendInstance->size = ((MmsMessageFolderInfo *)sig->p_param)->size;
#ifdef __MMS_SIZE_CONFIRM_BEFORE_SEND__
        if (sendInstance->size > 0 )
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
            mms_size = (FLOAT)sendInstance->size/ (FLOAT) 1024.0;;
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
                MEA_COMM_FSM, MEA_SIG_COMM_SEND_MESSAGE_SIZE_OK, 
                ((MmsMessageFolderInfo *)sig->p_param)->msgId);

            MEA_FREE(p_msg_ucs);
            MEA_FREE(p_msg_utf);
        }
        else
#endif /*__MMS_SIZE_CONFIRM_BEFORE_SEND__*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        {   /* fake dialog OK */
            MEA_SIGNAL_SENDTO_UU(MEA_COMM_FSM, 
                MEA_SIG_COMM_SEND_MESSAGE_SIZE_OK, MEA_CONFIRM_DIALOG_OK, 
                ((MmsMessageFolderInfo *)sig->p_param)->msgId);
        } /* if */
        MEA_FREE(sig->p_param);
        sig->p_param = NULL;
        break; 

    case MEA_SIG_COMM_SEND_MESSAGE_SIZE_OK:
#ifdef __MMS_DUAL_SIM_SUPPORT__
        {
            wap_sim_info_notify_ind_struct  *wap_sim_info;

            wap_sim_info = (wap_sim_info_notify_ind_struct *) OslConstructDataPtr(sizeof(wap_sim_info_notify_ind_struct));
            wap_sim_info->sim_status = wap_get_sim_status();
            wap_sim_info->setting_mode = wap_get_sim_setting_mode();
            
            if(wap_sim_info->sim_status == WAP_SIM_ID_DUAL_SIM && wap_sim_info->setting_mode == WAP_SIM_ID_DUAL_SIM)
            {
                meaCommChooseSimMenu();
            }
            else if(wap_sim_info->sim_status == WAP_SIM_ID_SIM1 && wap_sim_info->setting_mode == WAP_SIM_ID_SIM1 ||
                wap_sim_info->sim_status == WAP_SIM_ID_SIM1 && wap_sim_info->setting_mode == WAP_SIM_ID_DUAL_SIM ||
                wap_sim_info->sim_status == WAP_SIM_ID_DUAL_SIM && wap_sim_info->setting_mode == WAP_SIM_ID_SIM1)
            {
                verifySendModeExt(MEA_SIG_COMM_SEND_VERIFICATION_RSP, MMS_SIM_CARD_MASTER);
            }
            else if(wap_sim_info->sim_status == WAP_SIM_ID_SIM2 && wap_sim_info->setting_mode == WAP_SIM_ID_SIM2 ||
                wap_sim_info->sim_status == WAP_SIM_ID_SIM2 && wap_sim_info->setting_mode == WAP_SIM_ID_DUAL_SIM ||
                wap_sim_info->sim_status == WAP_SIM_ID_DUAL_SIM && wap_sim_info->setting_mode == WAP_SIM_ID_SIM2)
            {
                verifySendModeExt(MEA_SIG_COMM_SEND_VERIFICATION_RSP, MMS_SIM_CARD_SLAVE);
            }
            else
            {
                cleanupSendInstance(MEA_SEND_FAILED_SETTING, NULL);
            }
        }
#else
        if ((MeaConfirmDialogResult)sig->u_param1 == MEA_CONFIRM_DIALOG_OK)
        {
            verifySendMode(MEA_SIG_COMM_SEND_VERIFICATION_RSP);
        }
        else
        {
            cleanupSendInstance(MEA_SEND_CANCELLED, NULL);            
        } /* if */
#endif /*__MMS_DUAL_SIM_SUPPORT__*/        
        break;
	case MEA_SIG_COMM_CHOOSE_SIM_TO_SEND:
        if( sig->u_param1 == MMS_SIM_CARD_MASTER)
        {
			/*SIM 1*/
            verifySendModeExt(MEA_SIG_COMM_SEND_VERIFICATION_RSP, MMS_SIM_CARD_MASTER);
        }
        else
        {
			/*SIM 2*/
            verifySendModeExt(MEA_SIG_COMM_SEND_VERIFICATION_RSP, MMS_SIM_CARD_SLAVE);
        }
		break;

    case MEA_SIG_COMM_SEND_VERIFICATION_RSP:
        if ((MeaConfirmDialogResult)sig->u_param1 == MEA_CONFIRM_DIALOG_OK)
        {
            if (!meaPmViewShow(MEA_STR_ID_SENDING_MSG, TRUE, TRUE, MEA_COMM_FSM, 
                MEA_SIG_COMM_SEND_CANCEL))
            {
                meaPmViewRemove();
                cleanupSendInstance(MEA_SEND_FAILED, NULL);
                return;
            }            
#ifdef __UNIFIED_COMPOSER_SUPPORT__
            MMA_sendMessage(MSF_MODID_MEA, sendInstance->msgId);
#else
    #ifdef __MMS_DUAL_SIM_SUPPORT__
            MMSif_sendMessageExt(MSF_MODID_MEA, sendInstance->msgId, sig->u_param2);
    #else
            MMSif_sendMessage(MSF_MODID_MEA, sendInstance->msgId);
    #endif /*__MMS_DUAL_SIM_SUPPORT__*/    
#endif
        }
        else
        {
            cleanupSendInstance(MEA_SEND_CANCELLED, NULL);            
        } /* if */
        break;
        
    case MEA_SIG_COMM_SEND_MSG_RESPONSE:
#if MEA_CFG_SEND_TIMEOUT
        MSF_TIMER_RESET(MSF_MODID_MEA, MEA_COMM_TIMER_ID);
        sendInstance->timerActive = FALSE;
#endif
        /* the message is in hidden folder now */
        if ((MMS_RESULT_OK != (MmsResult)sig->u_param1) &&
            (MMS_RESULT_CANCELLED_BY_USER != (MmsResult)sig->u_param1))
        {
#ifdef __UNIFIED_COMPOSER_SUPPORT__
            MMA_moveMessage(MSF_MODID_MEA, sendInstance->msgId, MMS_OUTBOX);
#else
            MMSif_moveMessage(MSF_MODID_MEA, sendInstance->msgId, MMS_OUTBOX);
#endif
        }

        if (MMS_RESULT_OK == (MmsResult)sig->u_param1)
        {
            cleanupSendInstance(MEA_SEND_OK, NULL);
            /* Update current folder */
            (void)MEA_SIGNAL_SENDTO_I(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER, 
                MEA_FOLDER_NONE);
        }
        else 
        {
            MeaSendResult ret = translateMmsSendResultToMea((MmsResult)sig->u_param1);
            char *responseText = (char *)sig->p_param;
            sig->p_param = NULL;
            cleanupSendInstance(ret, responseText);
            MEA_FREE(responseText);
        }
        break;

    case MEA_SIG_COMM_SEND_CANCEL:
        if (NULL != sendInstance)
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MACOMM_F76CDBBFCFE88982379B9EAE402406A1, "(%s) (%d) cancelling a send operation!\n", __FILE__, 
                __LINE__));
#ifdef __UNIFIED_COMPOSER_SUPPORT__
            MMA_sendCancel(MSF_MODID_MEA, sendInstance->msgId);
#else
            MMSif_sendCancel(MSF_MODID_MEA, sendInstance->msgId);
#endif
        }
        else
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MACOMM_834B0E5CE6D44AF1424A6CC3D7C3E3E4, "(%s) (%d) Failed to cancel a send operation\n", __FILE__, 
                __LINE__));
        }
        /* will generate a SEND_MSG_RESPONSE with result CANCELLED_BY_USER */
        break;

/******************************************************************************
 *  Download signals	
 *****************************************************************************/
    case MEA_SIG_COMM_DOWNLOAD:
        /* init instance, get message info */
        if (sig->u_param2 > 0)
        {
            if (createDownloadInstance((MeaStateMachine)sig->u_param1, 
                (unsigned int )sig->i_param, sig->u_param2))
            {
                /* Get the message type */
                meaSrhGetMessageInfo(MEA_COMM_FSM, 
                    MEA_SIG_COMM_DOWNLOAD_MSG_TYPE_RSP, downloadInstance->msgId);
            }
            else
            {
                cleanupDownloadInstance(MEA_DOWNLOAD_FAILED);
            }
        }
        else
        {
            cleanupDownloadInstance(MEA_DOWNLOAD_FAILED);
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MACOMM_9C2AD4776537D783BA7E1FBEEE91AC72, "(%s) (%d) erroneous message ID!\n", __FILE__, __LINE__));
        }
        break;
#ifdef WAP_SUPPORT		
    case MEA_SIG_COMM_DOWNLOAD_CONFIRM:
        /* init instance, get message info */
        if (sig->u_param2 > 0)
        {
            downloadMsgId =(MmsMsgId)sig->u_param2;
            downloadConfirmInstance.returnSignal=(int)sig->i_param;
            downloadConfirmInstance.returnState=(MeaStateMachine)sig->u_param1;
            /* verify network settings, and fail on faulty settings */
            if (!checkSettings())
            {
                if (!meaShowSettingsErrorDialog(MEA_COMM_FSM, MEA_SIG_COMM_SETTINGS_FAILED_DIALOG_RSP))
                {
                    (void)MEA_SIGNAL_SENDTO(MEA_COMM_FSM, MEA_SIG_COMM_SETTINGS_FAILED_DIALOG_RSP);
                }
                cleanupDownloadConfirmInstance();
                break;
            }
            /* Get the message type */
            meaSrhGetMessageInfo(MEA_COMM_FSM, 
                MEA_SIG_COMM_DOWNLOAD_MSG_TYPE_RSP, downloadMsgId);
        }
        break;
    case 	MEA_SIG_COMM_DOWNLOAD_CONFIRM_RSP:
        if (MEA_CONFIRM_DIALOG_OK != sig->u_param1)
        {
            //cleanupDownloadConfirmInstance(/*MEA_DOWNLOAD_CANCELLED*/);
            downloadMsgId = 0;
            mvClearMvInstanceForCancelDownload();
            break;
        }

        if ((U64)downloadLength > (U64)msm_get_disk_free_space(WAP_STORAGE_MMS))
        {
            meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_STORAGE_FULL), MEA_DIALOG_ERROR);
            cleanupDownloadConfirmInstance(/*MEA_DOWNLOAD_CANCELLED*/);
            break;
        }

        if((U64)downloadLength > (U64)wap_custom_get_max_mms_msg_size())
        {
            meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_RETR_SIZE_EXCEEDED), MEA_DIALOG_ERROR);
            cleanupDownloadConfirmInstance(/*MEA_DOWNLOAD_CANCELLED*/);
            break;
        }

        MEA_SIGNAL_SENDTO_IUU(MEA_COMM_FSM, MEA_SIG_COMM_DOWNLOAD,
            (long)downloadConfirmInstance.returnSignal, (unsigned int)downloadConfirmInstance.returnState, 
            downloadMsgId);
        downloadMsgId = 0;
        break;

    case 	MEA_SIG_COMM_DOWNLOAD_MODE_RSP:
        if (MEA_CONFIRM_DIALOG_OK != sig->u_param1)
        {
            cleanupDownloadConfirmInstance(/*MEA_DOWNLOAD_CANCELLED*/);
            break;
        }

        if ((U64)downloadLength > (U64)msm_get_disk_free_space(WAP_STORAGE_MMS))
        {
            meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_STORAGE_FULL), MEA_DIALOG_ERROR);
            (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP);
            break;
        }

        if((U64)downloadLength > (U64)wap_custom_get_max_mms_msg_size())
        {
            meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_RETR_SIZE_EXCEEDED), MEA_DIALOG_ERROR);
            cleanupDownloadConfirmInstance(/*MEA_DOWNLOAD_CANCELLED*/);
            break;
        }

        MEA_SIGNAL_SENDTO_IUU(MEA_COMM_FSM, MEA_SIG_COMM_DOWNLOAD,
            (long)MEA_SIG_MV_DOWNLOAD_RSP, (unsigned int)MEA_MV_FSM, downloadMsgId);
        downloadMsgId = 0;
        break;

#endif /* WAP_SUPPORT */

    case MEA_SIG_COMM_DOWNLOAD_MSG_TYPE_RSP:
#ifdef WAP_SUPPORT
        if (downloadMsgId >0)
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
                    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA,
                        MACOMM_E5F8075D5DCF9E5F2E98B1AE9BDA1FCC, "(%s) (%d) delayed file operation\n", __FILE__, __LINE__));
                    break; 
                }
                else if (MEA_READ_NOTIF_DONE != ret) /* something went wrong */
                {
                    (void)meaShowDialog(MEA_GET_STR_ID(
                        MEA_STR_ID_FAILED_TO_DISPLAY_NOTIF), MEA_DIALOG_ERROR);
                    cleanupDownloadConfirmInstance(/*MEA_DOWNLOAD_CANCELLED*/);
                    break;
                }
                /* verify roaming/retrieval modes (immediate, delayed, restricted...)*/
                verifyDownload(MEA_SIG_COMM_DOWNLOAD_CONFIRM_RSP, downloadLength, downloadMsgId);

                MEA_FREE(sig->p_param);
                sig->p_param = NULL;
            }
            else
            {
                cleanupDownloadConfirmInstance(/*MEA_DOWNLOAD_CANCELLED*/);
            }
            break;
        }
#endif /* WAP_SUPPORT */
        if ((NULL != sig->p_param) && 
            ((((MmsMessageFolderInfo *)sig->p_param)->suffix == MMS_SUFFIX_NOTIFICATION) ||
            (((MmsMessageFolderInfo *)sig->p_param)->suffix == MMS_SUFFIX_IMMEDIATE)))
        {
            /* The msg type is ok, save on move on */
            downloadInstance->msgType = 
                ((MmsMessageFolderInfo *)sig->p_param)->suffix;
            /* refresh roaming/bearer status */
            meaUpdateNetworkStatusInfo(MEA_COMM_FSM,
                MEA_SIG_COMM_DOWNLOAD_NETWORK_STATUS_RSP);
            MEA_FREE(sig->p_param);
            sig->p_param = NULL;
        }
        else
        {
            cleanupDownloadInstance(MEA_DOWNLOAD_FAILED);
        }
        break;

    case MEA_SIG_COMM_DOWNLOAD_NETWORK_STATUS_RSP:
        /* We should read a notification */
        if (!meaCreateGetNotifInstance(&downloadInstance->getNotifInstance, 
            downloadInstance->msgId, downloadInstance->msgType, MEA_COMM_FSM,
            MEA_SIG_COMM_DOWNLOAD_NOTIF_FILE_NOTIFY_RSP))
        {
            cleanupDownloadInstance(MEA_DOWNLOAD_FAILED);
            break;
        }

        MEA_SIGNAL_SENDTO(MEA_COMM_FSM, 
            MEA_SIG_COMM_DOWNLOAD_NOTIF_FILE_NOTIFY_RSP);
        break;

    case MEA_SIG_COMM_DOWNLOAD_NOTIF_FILE_NOTIFY_RSP:
        ret = meaGetNotifFSM(downloadInstance->getNotifInstance);
        if (MEA_READ_NOTIF_DELAYED == ret) 
        {   /* async, lets wait for file notify */
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA,
                MACOMM_E5F8075D5DCF9E5F2E98B1AE9BDA1FCC, "(%s) (%d) delayed file operation\n", __FILE__, __LINE__));
            break; 
        }
        else if (MEA_READ_NOTIF_DONE != ret) /* something went wrong */
        {
            (void)meaShowDialog(MEA_GET_STR_ID(
                MEA_STR_ID_FAILED_TO_DISPLAY_NOTIF), MEA_DIALOG_ERROR);
            cleanupDownloadInstance(MEA_DOWNLOAD_FAILED);
            break;
        }
        /* verify roaming/retrieval modes (immediate, delayed, restricted...)*/
        verifyRetrievalMode(MEA_SIG_COMM_DOWNLOAD_VERIFICATION_RSP);
        break;

    case MEA_SIG_COMM_DOWNLOAD_VERIFICATION_RSP:
        /* End user has chosen whether to download message or not */
        if (MEA_CONFIRM_DIALOG_OK != sig->u_param1)
        {
            cleanupDownloadInstance(MEA_DOWNLOAD_CANCELLED);
            break;
        }
        else
        {
            MmsMessageFolderInfo *MmsMFInfo = (MmsMessageFolderInfo *)fldrMgrGetMsgInfo(downloadInstance->getNotifInstance->msgId);
            if(HDIa_timeUTCToLocal(downloadInstance->getNotifInstance->notif->expiryTime + MmsMFInfo->date) < HDIa_timeGetCurrent())
            {
                meaShowConfirmDialog(MEA_STR_ID_DOWNLOAD_EXPIRED_MM_CONFIRM, NULL, MEA_COMM_FSM, MEA_SIG_COMM_DOWNLOAD_EXPIRED_MM, 0);
                break;
            }
        }
        {
        MMSif_retrieveMessage(MSF_MODID_MEA, 
            downloadInstance->getNotifInstance->msgId);
        }
        break;
    case MEA_SIG_COMM_DOWNLOAD_EXPIRED_MM:

        /* End user has chosen whether to download an expired message or not */
        if (MEA_CONFIRM_DIALOG_OK != sig->u_param1)
        {
            cleanupDownloadInstance(MEA_DOWNLOAD_CANCELLED);
            break;
        }
        MMSif_retrieveMessage(MSF_MODID_MEA, 
            downloadInstance->getNotifInstance->msgId);
        break;

    case MEA_SIG_COMM_DOWNLOAD_RESPONSE:
        /* Check whether the download was successful */
        if (sig->u_param1 == MMS_RESULT_OK)
        {
#ifdef WAP_SUPPORT  /* Delete the notification file. Don't need response */
            fldrMgrDeleteMessage(downloadInstance->getNotifInstance->msgId);
  #ifdef MMS_FILE_PROTECT_SUPPORT
            delChkSumFile(downloadInstance->getNotifInstance->msgId);
  #endif /* MMS_FILE_PROTECT_SUPPORT */
#endif /* WAP_SUPPORT */
            /* Set the new msgId */
            downloadInstance->msgId = (MmsMsgId)sig->u_param2;
#ifdef MMS_SUPPORT
            mmcIsRecvMMSForJava(downloadInstance->msgId);
#endif            
#ifdef MMS_FILE_PROTECT_SUPPORT
            if (genChkSumFile(downloadInstance->msgId)==MMS_RESULT_INSUFFICIENT_PERSISTENT_STORAGE)
            {
                cleanupDownloadInstance(MEA_DOWNLOAD_FAILED_NO_SPACE_LEFT);
                fldrMgrDeleteMessage(downloadInstance->msgId);
            }
            else
#endif /* MMS_FILE_PROTECT_SUPPORT */
                /* Send the response */            
                cleanupDownloadInstance(MEA_DOWNLOAD_OK);
        }
        else if (sig->u_param1 == MMS_RESULT_CANCELLED_BY_USER)
        {
            cleanupDownloadInstance(MEA_DOWNLOAD_CANCELLED);
        }
        else if (sig->u_param1 == MMS_RESULT_INSUFFICIENT_PERSISTENT_STORAGE)
        {
            cleanupDownloadInstance(MEA_DOWNLOAD_FAILED_NO_SPACE_LEFT);
        }
		else if (sig->u_param1 == MMS_RESULT_TOO_MANY_MSG) 
		{
			cleanupDownloadInstance(MEA_DOWNLOAD_TOO_MANY_MSG);
		}
        else if (sig->u_param1 == MMS_RESULT_BUSY)
        {
            cleanupDownloadInstance(MEA_DOWNLOAD_BUSY);
        }
        else if (sig->u_param1 == MMS_RESULT_MAX_RETRIEVAL_SIZE_EXCEEDED)
        {
            cleanupDownloadInstance(MEA_DOWNLOAD_FAILED_MAX_RETRIEVAL_SIZE_EXCEEDED);
        }
        else if(sig->u_param1 == MMS_RESULT_COMM_ILLEGAL_PDU)
        {
            cleanupDownloadInstance(MEA_DOWNLOAD_FAILED_ILLEGAL_PDU);
        }
        else
        {
            cleanupDownloadInstance(MEA_DOWNLOAD_FAILED);
        }
        break;
        
    case MEA_SIG_COMM_DOWNLOAD_CANCEL:
        if (NULL != downloadInstance)
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MACOMM_B4962716AEEAD06F75DC34A8EE0B51BD, "(%s) (%d) Download cancel received, msgId = %d!\n", __FILE__,
                __LINE__, downloadInstance->getNotifInstance->msgId));
            MMSif_retrieveCancel(MSF_MODID_MEA, 
                downloadInstance->getNotifInstance->msgId);
            /* The cleanup is handled when the MEA_SIG_COMM_DOWNLOAD_RESPONSE
               is received */
        }
        else
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MACOMM_F514319DD62F3B3FB3D1ACCDD84557C4, "(%s) (%d) erroneous operation! no instance exists!\n", 
                __FILE__, __LINE__));   
        }
        break;
    case MEA_SIG_COMM_PROGRESS_STATUS:
        msgStatus = (MmsProgressStatus *)sig->p_param;
#ifdef WAP_SUPPORT
        if (meaPmIsActive())
#endif /* WAP_SUPPORT */
        {
            if(msgStatus->state == MMS_PROGRESS_STATUS_RETRY)
            {
                meaRetryFlag = TRUE;
                progressPercent = 0;
                msgStatus->progress = 0;
            }
            handleProgress(msgStatus);
        }
        MEA_FREE(sig->p_param);
        sig->p_param = NULL;
        break;

    case MEA_SIG_COMM_SETTINGS_FAILED_DIALOG_RSP:
        cleanupDownloadInstance(MEA_DOWNLOAD_FAILED);
        break;

    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
            MACOMM_E2BFC1C36BA2F291451551F89629EFAA, "(%s) (%d) Unhandled signal received (%d).\n", __FILE__, __LINE__,
            sig->type));
    }
    /* Remove signal data */
    meaSignalDelete(sig);
}

/*! \brief Displays an error dialog that corresponds with the download result
 *         code.
 *
 * \param result The #MeaDownloadResult.
 * \param fsm    The callback FSM.
 * \param signal The callback signal.
 *****************************************************************************/
MSF_BOOL meaShowDownloadErrorDialog(MeaDownloadResult result, MeaStateMachine fsm,
    int signal)
{
    switch(result)
    {
    case MEA_DOWNLOAD_FAILED:
    {
        MSF_INT32 detail_error = HDIa_getLastError();
        switch(detail_error) {
        case UNKNOWN_APN:
            (void)meaShowDialogWithCallback(MEA_GET_STR_ID(BRA_STR_ID_ERROR_GPRS_UNKNOWN_APN), 
                MEA_DIALOG_ERROR, fsm, signal);
            break;
        case AUTHENTICATION_FAILURE:
            (void)meaShowDialogWithCallback(MEA_GET_STR_ID(BRA_STR_ID_ERROR_GPRS_AUTHENTICATION_FAILURE), 
                MEA_DIALOG_ERROR, fsm, signal);
            break;
        case UNSUPPORTED_SERVICE_OPTION:
            (void)meaShowDialogWithCallback(MEA_GET_STR_ID(BRA_STR_ID_ERROR_GPRS_UNSUPPORTED_SERVICE_OPTION), 
                MEA_DIALOG_ERROR, fsm, signal);
            break;
        case UNSUBSCRIBED_SERVICE_OPTION:
            (void)meaShowDialogWithCallback(MEA_GET_STR_ID(BRA_STR_ID_ERROR_GPRS_UNSUBSCRIBED_SERVICE_OPTION), 
                MEA_DIALOG_ERROR, fsm, signal);
            break;
        default:
            (void)meaShowDialogWithCallback(MEA_GET_STR_ID(MEA_STR_ID_DOWNLOAD_FAILED), 
                MEA_DIALOG_ERROR, fsm, signal);
            break;
        }
        return TRUE;
    }
    case MEA_DOWNLOAD_FAILED_NO_SPACE_LEFT:
        (void)meaShowDialogWithCallback(
            MEA_GET_STR_ID(MEA_STR_ID_NO_PERSISTENT_STORAGE), MEA_DIALOG_ERROR, 
            fsm, signal);
        return TRUE;
	case MEA_DOWNLOAD_TOO_MANY_MSG:
		(void)meaShowDialogWithCallback(
            MEA_GET_STR_ID(MEA_STR_ID_MAX_NUMBER_OF_MSG), MEA_DIALOG_ERROR, 
            fsm, signal);
        return TRUE;
    case MEA_DOWNLOAD_BUSY:
        (void)meaShowDialogWithCallback(MEA_GET_STR_ID(MEA_STR_ID_TOO_MANY_CONNECTIONS), 
            MEA_DIALOG_ERROR, fsm, signal);
        return TRUE;
    case MEA_DOWNLOAD_FAILED_MAX_RETRIEVAL_SIZE_EXCEEDED:
        (void)meaShowDialogWithCallback(MEA_GET_STR_ID(MEA_STR_ID_MESSAGE_SIZE_MAXIMUM_REACHED), 
            MEA_DIALOG_ERROR, fsm, signal);
        return TRUE;
    case MEA_DOWNLOAD_FAILED_ILLEGAL_PDU:
        (void)meaShowDialogWithCallback(MEA_GET_STR_ID(MEA_STR_ID_DOWNLOAD_FAILED_ILLEGAL_PDU), 
            MEA_DIALOG_ERROR, fsm, signal);
        return TRUE;
    default:
        return FALSE;
    }
}

/*! \brief Displays an error dialog that corresponds with the download result
 *         code.
 *
 * \param result The #MeaDownloadResult.
 * \param fsm    The callback FSM.
 * \param signal The callback signal.
 *****************************************************************************/
void meaShowSendDialog(MeaSendResult result, MeaStateMachine fsm,
    int signal)
{
    switch(result)
    {
    case MEA_SEND_OK:
        if (meaGetConfig()->saveOnSend)
            (void)meaShowDialogWithCallback(MEA_GET_STR_ID(MEA_STR_ID_SAVED_AND_SENT), 
                MEA_DIALOG_PROMPT_DONE, fsm, signal);
        else
            (void)meaShowDialogWithCallback(MEA_GET_STR_ID(MEA_STR_ID_MESSAGE_SENT), 
                MEA_DIALOG_PROMPT_DONE, fsm, signal);
        break;
    case MEA_SEND_FAILED_REFUSED:
        (void)meaShowDialogWithCallback(
            MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_SEND_REFUSED), MEA_DIALOG_ERROR, 
            fsm, signal);
        break;

	case MEA_SEND_TIMEOUT:
		(void)meaShowDialogWithCallback(
            MEA_GET_STR_ID(MEA_STR_ID_SERVER_TIMEOUT), MEA_DIALOG_ERROR, 
            fsm, signal);
        break;
    case MEA_SEND_BUSY:
        (void)meaShowDialogWithCallback(
            MEA_GET_STR_ID(MEA_STR_ID_NOT_AVAILABLE), MEA_DIALOG_ERROR, 
            fsm, signal);
        break;

    case MEA_SEND_FAILED_COMM:
    {
        MSF_INT32 detail_error = HDIa_getLastError();
        switch(detail_error) {
        case UNKNOWN_APN:
            (void)meaShowDialogWithCallback(MEA_GET_STR_ID(BRA_STR_ID_ERROR_GPRS_UNKNOWN_APN), 
                MEA_DIALOG_ERROR, fsm, signal);
            break;
        case AUTHENTICATION_FAILURE:
            (void)meaShowDialogWithCallback(MEA_GET_STR_ID(BRA_STR_ID_ERROR_GPRS_AUTHENTICATION_FAILURE), 
                MEA_DIALOG_ERROR, fsm, signal);
            break;
        case UNSUPPORTED_SERVICE_OPTION:
            (void)meaShowDialogWithCallback(MEA_GET_STR_ID(BRA_STR_ID_ERROR_GPRS_UNSUPPORTED_SERVICE_OPTION), 
                MEA_DIALOG_ERROR, fsm, signal);
            break;
        case UNSUBSCRIBED_SERVICE_OPTION:
            (void)meaShowDialogWithCallback(MEA_GET_STR_ID(BRA_STR_ID_ERROR_GPRS_UNSUBSCRIBED_SERVICE_OPTION), 
                MEA_DIALOG_ERROR, fsm, signal);
            break;
        default:
            if(meaGetCurrentFolder() != MEA_FOLDER_OUTBOX)
            {
                (void)meaShowDialogWithCallback(MEA_GET_STR_ID(MEA_STR_ID_FAILED_CONNECTION), 
                    MEA_DIALOG_ERROR, fsm, signal);
            }
            else
            {
                (void)meaShowDialogWithCallback(MEA_GET_STR_ID(BRA_STR_ID_ERROR_COMMUNICATION), 
                    MEA_DIALOG_ERROR, fsm, signal);
            }
            break;
        }
        break;
    }

    case MEA_SEND_CANCELLED:
        /* Do not display any dialog for cancel */
        break;
    case MEA_SEND_FAILED_SETTING:
        meaShowDialogWithCallback(MEA_GET_STR_ID(MEA_STR_ID_INVALID_NETWORK_SETTINGS), MEA_DIALOG_ERROR, MEA_NOTUSED_FSM, 0);
        break;
    default:
        (void)meaShowDialogWithCallback(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_SEND), 
            MEA_DIALOG_ERROR, fsm, signal);
        break;
    }
}





















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

/*! \file mamv.c
 *  \brief Message viewer control logic. 
 */

/* MSF */
#include "msf_log.h"
#include "msf_lib.h"
#include "msf_wid.h"
#include "msf_mem.h"
#include "msf_core.h"
#include "msf_cmmn.h"

/* MMS */
#include "mms_cfg.h"
#include "mms_def.h"
#include "mms_if.h"
#ifdef __UNIFIED_MSG_SUPPORT__
#include "msig.h"  /* for fldmgr.h */
#include "fldmgr.h"  /* for fldrGetFileSuffix */
#endif

/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"

/* MEA */
#include "mea_rc.h"
#include "mea_cfg.h"
#include "mea_def.h"
#include "matypes.h"
#include "mea_env.h"
#include "maintsig.h"
#include "mamh.h"
#include "mamv.h"
#include "mammv.h"
#include "mamr.h"
#include "mauimv.h"
#include "mamem.h"
#include "macrh.h"
#include "mauidia.h"
#include "mauipm.h"
#include "macore.h"
#include "macomm.h"
#include "manotif.h"
#include "maaddr.h"
#include "mapbh.h"
#include "mauicmn.h"
#include "masrh.h"
#include "maconf.h"
#ifdef WAP_SUPPORT
#include "mase.h"
#include "mame.h"
#include "mauise.h"  //for meaSmilEditorIsActive
#include "mauimh.h"
#include "WapDef.h"
#include "mms_aApp.h"
#include "mamob.h"

/* widget */
#include "widget_extension.h"
#endif /* WAP_SUPPORT */
#ifdef __DRM_SUPPORT__
  #ifdef __FS_QM_SUPPORT__
#include "fs_type.h"    //for BYTE
#include "fs_func.h"	//for FS_QmGetFree
#include "../../drm/include/drm_def.h" //for DRM_MMS_PATH
  #endif /* __FS_QM_SUPPORT__ */
#endif /* __DRM_SUPPORT__ */
#ifdef __MMI_MMS_BGSR_SUPPORT__
#include "MMSBGSRGprot.h"
#include "widget.h"
#include "mea_int.h"
#include "manotif.h"
#endif /*__MMI_MMS_BGSR_SUPPORT__*/

extern MSF_BOOL mmcIsJSRMsg(MSF_UINT32 msgId);
/*!\enum MeaMvInstance
 */
typedef struct MeaMvInstanceSt 
{
    MeaMessage              *theMessage;
    MeaGetNotifInstance     *getNotifInstance;
    MmsMessageFolderInfo    *fInfo;
}MeaMvInstance;

/******************************************************************************
 * Constants
 *****************************************************************************/

/******************************************************************************
 * Static variables
 *****************************************************************************/
static MeaMvInstance *mvInstance;
#ifdef WAP_SUPPORT
static MmsMsgId mvActiveMsgId = 0;

static MSF_BOOL plySmilFailed = FALSE;
#endif /* WAP_SUPPORT */

/******************************************************************************
 * Prototypes
 *****************************************************************************/
static void activatePropertyView(const MeaMvInstance *inst);
static void handleReadReport(MeaMvInstance *inst, MmsMsgReadReport *rr);
static void handleDeliveryReport(MeaMvInstance *inst, 
    MmsMsgDeliveryReportInd *dr);
static void handleActivate(const MmsMessageFolderInfo *info);
static void meaViewer(MeaSignal *sig);

/******************************************************************************
 * Function implementations
 *****************************************************************************/

/*!
 * \brief       Deals with opening of read reports 
 *
 * \param rr    The read report
 *****************************************************************************/
static void handleReadReport(MeaMvInstance *inst, MmsMsgReadReport *rr)
{
    MSF_UINT32 status;
    
    if (NULL == rr)
    {
        return;
    }
#ifndef WAP_SUPPORT
    if ((NULL == inst) || (NULL == inst->fInfo) || 
        (inst->fInfo->msgId != rr->msgIdFile))
    {
        /* This is not a valid request */
        MEA_FREE(rr->address);
        MEA_FREE(rr->serverMessageId);
        MEA_FREE(rr->text);
        MEA_FREE(rr);
        return;
    }
#endif /* ~WAP_SUPPORT*/
    /* Create text for the status field */
    switch(rr->readStatus)
    {
    case MMS_READ_STATUS_READ:
        status = MEA_STR_ID_READ;
        break;
    case MMS_READ_STATUS_DELETED_WITHOUT_BEING_READ:
        status = MEA_STR_ID_NOT_READ;
        break;
    default:
        status = MEA_STR_ID_UNKOWN;
        break;
    }

    /* Crete GUI */
    if (!meaCreateMvRrDrView(MEA_STR_ID_READ_REPORT, rr->address, MmsGetSubjectFromSerMsgId(rr->serverMessageId), 
        status, rr->date))
    {
        /* Delete the GUI so that all resources are de-allocated */
        meaDeleteMvRrDrView();
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_ERROR), 
            MEA_DIALOG_ERROR);
    }
    (void)MEA_SIGNAL_SENDTO_I(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER, 
        MEA_FOLDER_NONE);
    
    if (0 != rr->msgIdFile)
    {
        /* Set the read report as "read" */
        MMSif_setReadMark(MSF_MODID_MEA, rr->msgIdFile, TRUE);
    }

    MEA_FREE(rr->address);
    MEA_FREE(rr->serverMessageId);
    MEA_FREE(rr->text);
    /*lint -e{774} */
    MEA_FREE(rr);
    meaPmViewRemove();
}

/*!
 * \brief       Deals with opening of delivery reports 
 *
 * \param dr    The delivery report
 *****************************************************************************/
static void handleDeliveryReport(MeaMvInstance *inst, 
    MmsMsgDeliveryReportInd *dr)
{
    MSF_UINT32 status;

    if (NULL == dr)
    {
        return;
    }
    if ((NULL == inst) || (NULL == inst->fInfo) || 
        (inst->fInfo->msgId != dr->msgIdFile))
    {
        /* This is not a valid request */
        MEA_FREE(dr->address);
        MEA_FREE(dr->serverMsgId);
        MEA_FREE(dr);
        return;
    }
    
    switch (dr->status)
    {
    case MMS_STATUS_EXPIRED:
        status = MEA_STR_ID_EXPIRED;
        break;
    case MMS_STATUS_RETRIEVED:
        status = MEA_STR_ID_RETRIEVED;
        break;
    case MMS_STATUS_REJECTED:
        status = MEA_STR_ID_REJECTED;
        break;
    case MMS_STATUS_DEFERRED:
        status = MEA_STR_ID_DEFERRED;
        break;
    case MMS_STATUS_UNRECOGNIZED:
        status = MEA_STR_ID_UNRECOGNIZED;
        break;
    case MMS_STATUS_INDETERMINATE:
        status = MEA_STR_ID_INDETERMINATE;
        break;
    case MMS_STATUS_FORWARDED:
        status = MEA_STR_ID_FORWARDED;
        break;
    default:
        status = MEA_STR_ID_UNKOWN;
        break;
    }

    /* Show GUI */
    if (!meaCreateMvRrDrView(MEA_STR_ID_DELIV_REPORT, dr->address, MmsGetSubjectFromSerMsgId(dr->serverMsgId),
        status, dr->date))
    {
        /* Delete the GUI so that all resources are de-allocated */
        meaDeleteMvRrDrView();
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_ERROR), MEA_DIALOG_ERROR);
    }
    /* Set the message read */
    if (0 != dr->msgIdFile)
    {
        MMSif_setReadMark(MSF_MODID_MEA, dr->msgIdFile, TRUE);
    }
    (void)MEA_SIGNAL_SENDTO_I(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER, 
        MEA_FOLDER_NONE);

    MEA_FREE(dr->address);
    MEA_FREE(dr->serverMsgId);
    MEA_FREE(dr->text);
    /*lint -e{774} */
    MEA_FREE(dr);
    meaPmViewRemove();
}

/*!
 * \brief           Handles activation of the viewer, i.e. what to do once the 
 *                  user has decided to view a message.
 * \param info      Information about the message to open/view
 *****************************************************************************/
static void handleActivate(const MmsMessageFolderInfo *info)
{
    switch (info->suffix)
    {
    case MMS_SUFFIX_READREPORT:
    case MMS_SUFFIX_DELIVERYREPORT:
        MMSif_getReport(MSF_MODID_MEA, info->msgId);
        break;
    case MMS_SUFFIX_SEND_REQ:
    case MMS_SUFFIX_MSG:
    case MMS_SUFFIX_TEMPLATE:
//#ifdef WAP_SUPPORT
//    MMSif_setReadMark(MSF_MODID_MEA, theMessage->msgId, TRUE);
//    (void)MEA_SIGNAL_SENDTO_I(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER, 
//        MEA_FOLDER_NONE);
//		(void)MEA_SIGNAL_SENDTO(MEA_MV_FSM, MEA_SIG_MV_PROP_OK);
//#else
        meaStartMr(MEA_MR_STARTUP_VIEW, info->msgId, info->suffix,
            MEA_MV_FSM, MEA_SIG_MV_MR_DONE);
//#endif
        break;
    case MMS_SUFFIX_NOTIFICATION:
    case MMS_SUFFIX_IMMEDIATE:
#ifndef __MMI_MMS_BGSR_SUPPORT__
        meaDownloadMessage(MEA_MV_FSM, MEA_SIG_MV_DOWNLOAD_RSP, info->msgId);
#else /*__MMI_MMS_BGSR_SUPPORT__*/
        (void)MEA_SIGNAL_SENDTO_UU(MEA_MH_FSM, 
                                   MEA_SIG_MH_BGSR_DOWNLOAD_GET_MSG_INFO,
                                   0,
                                   info->msgId);
        (void)MEA_SIGNAL_SENDTO(MEA_MV_FSM, MEA_SIG_MV_DEACTIVATE);
#endif /*__MMI_MMS_BGSR_SUPPORT__*/

         break; 
    case MMS_SUFFIX_INFO:
    case MMS_SUFFIX_ERROR:
    default:
        meaPmViewRemove();        
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_WRONG_MESSAGE_TYPE), 
            MEA_DIALOG_ERROR);
        (void)MEA_SIGNAL_SENDTO(MEA_MV_FSM, MEA_SIG_MV_DEACTIVATE);
        break;
    }
}

/*! \brief
 *	
 * \param inst
 *****************************************************************************/
static void deActivate(MeaMvInstance **inst)
{
    if (inst && *inst)
    {
        MEA_FREE((*inst)->fInfo);
        (*inst)->fInfo = NULL;
        meaFreeMessage(&(*inst)->theMessage);
        if ((*inst)->getNotifInstance) 
        {
            meaCleanupGetNotifInstance(&(*inst)->getNotifInstance);
        } /* if */
        MEA_FREE((*inst));
        *inst = NULL;
    }
    meaDeleteMvPropView();
    meaDeleteMvRrDrView();
    //meaPmViewRemove();
    meaPmViewRemoveFromMV();
#ifdef __UNIFIED_MSG_SUPPORT__
    {
        extern void meaRemovePropNavMenu(void);
        meaRemovePropNavMenu();
    }
#endif
    mvActiveMsgId = 0;
    if ( (MEA_STARTUP_MODE_VIEW == meaGetStartupMode() || 
        MEA_STARTUP_MODE_DOWNLOAD == meaGetStartupMode()) &&
        !meaMhIsActive())
    {
        //back to message list
        meaSetStartupFsm(MEA_MH_FSM);
        (void)MEA_SIGNAL_SENDTO_U(MEA_MH_FSM, MEA_SIG_MH_ACTIVATE, 
                MEA_FOLDER_INBOX);
    }    
    else
    {
        (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);
    }

    if (meaMobIsActive())
    {
        (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_DEACTIVATE);
    }
    
  #ifdef __DRM_SUPPORT__
    #ifdef __FS_QM_SUPPORT__
	/* Because the disk support Quota management, assume that disk full is allowed*/
	if (FS_QmGetFree((BYTE*)DRM_MMS_PATH) < MMS_DEFAULT_MAX_MSG_SIZE)
    #else
	if (msm_get_disk_free_space(0) < MMS_DEFAULT_MAX_MSG_SIZE)
    #endif /* __FS_QM_SUPPORT__ */
    {
        msm_remove_files_under_dir(MMS_DRM_FOLDER);
    }
  #endif /* __DRM_SUPPORT__ */
}

/*!
 * \brief Activates the property view.
 * 
 *\param inst The current instance, see #MeaMessage.
 *****************************************************************************/
static void activatePropertyView(const MeaMvInstance *inst)
{
    MeaMessage  *theMessage = inst->theMessage;
    char        *str        = NULL;

    if (!inst || !inst->theMessage || !inst->theMessage->msgProperties) 
    {
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_DISPLAY_MM), 
            MEA_DIALOG_ERROR);
        (void)MEA_SIGNAL_SENDTO(MEA_MV_FSM, MEA_SIG_MV_DEACTIVATE);
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAMV_C3FFEC54F7133A9803CE0D3A6E6A612E, "(%s) (%d) erroneous message header\n", __FILE__, __LINE__));
        return;
    } /* if */

    /* If come here second time, and MEA mode is MEA_STARTUP_MODE_VIEW,
        will view message directly, or will popup MEA_STR_ID_FAILED_TO_DISPLAY_MM.
        Because this is after transform to smil*/
    if (!meaNoPropView() && 
        MEA_STARTUP_MODE_VIEW == meaGetStartupMode())
    {
        (void)MEA_SIGNAL_SENDTO(MEA_MV_FSM, MEA_SIG_MV_PROP_OK);
    }
    else
    {
        /* Name lookup */
        meaNameLookup(theMessage->msgProperties->from, (MeaStateMachine)0, (int)0);
        meaNameLookup(theMessage->msgProperties->to, (MeaStateMachine)0, (int)0);
        meaNameLookup(theMessage->msgProperties->cc, (MeaStateMachine)0, (int)0);

        /* Display the form */
        if (!meaCreateMvPropView(inst->theMessage->msgId, TRUE))
        {
            meaDeleteMvPropView();
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_DISPLAY_MM), 
                MEA_DIALOG_ALERT);
            (void)MEA_SIGNAL_SENDTO(MEA_MV_FSM, MEA_SIG_MV_DEACTIVATE);
            return;
        }
        /*lint -e{774} */
        MEA_FREE(str);
        str = NULL;
    }

    MMSif_setReadMark(MSF_MODID_MEA, theMessage->msgId, TRUE);
    (void)MEA_SIGNAL_SENDTO_I(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER, MEA_FOLDER_NONE);

#if MEA_CFG_REQ_RR_AFTER_READ_FINISH == 0
    /* Check for read report. Message must be of type MMS_SUFFIX_MSG */
    if (theMessage->msgProperties->readReport && 
        MMS_SUFFIX_MSG == theMessage->fileType && 
        NULL != theMessage->msgProperties->from &&
        FALSE == inst->fInfo->read)
    {
        if (MEA_SEND_READ_REPORT_ON_REQUEST == (MeaSendReadReportType)meaGetConfig()->sendReadReport)
        {
            /* ask End User whether or not to send a read report */
            (void)meaShowConfirmDialog(MEA_STR_ID_READ_REPORT_SEND,
                NULL, MEA_MV_FSM, MEA_SIG_MV_SEND_READ_REPORT, 0);
            return;
        }
        else if (MEA_SEND_READ_REPORT_ALWAYS == (MeaSendReadReportType)meaGetConfig()->sendReadReport)
        {
            /* send a read report without asking */
            (void)MEA_SIGNAL_SENDTO_U(MEA_MV_FSM, MEA_SIG_MV_SEND_READ_REPORT,
                (MeaConfirmDialogResult)MEA_CONFIRM_DIALOG_OK);
            return;
        }
    }

    (void)MEA_SIGNAL_SENDTO_I(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER, MEA_FOLDER_NONE);
#endif
}

/*!
 * \brief Signal handler for the message viewer set of views
 * \param sig The received signal 
 *****************************************************************************/
static void meaViewer(MeaSignal *sig)
{
    MmsMsgId    id;
    MeaAddrItem *tmpAddrItem;
    
    switch ((MeaMvSignalId) sig->type)
    {
    case MEA_SIG_MV_ACTIVATE: /* IU = type, id */
        if (mvActiveMsgId > 0)
        {
            break;
        }
        
        id = sig->u_param1;
        
        if (id < 1) 
        {/* Nothing to view */
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_DISPLAY_MM), 
                MEA_DIALOG_ERROR);
            break; 
        } /* if */               

#ifdef WAP_SUPPORT
        meaMvSetActiveMsgId(id);
#endif /* WAP_SUPPORT */
        /* always request msginfo (read-status, etc) */
        meaSrhGetMessageInfo(MEA_MV_FSM, MEA_SIG_MV_GET_MSG_TYPE_RSP, id);
        break;

    case MEA_SIG_MV_GET_MSG_TYPE_RSP:
        if (NULL == sig->p_param) 
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MAMV_CBE098C3D3B4DD4755B7B3F81C9EDCC1, "(%s) (%d) Failed to retrieve message information\n", 
                __FILE__, __LINE__));            
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_DISPLAY_MM), 
                MEA_DIALOG_ERROR);
            (void)MEA_SIGNAL_SENDTO(MEA_MV_FSM, MEA_SIG_MV_DEACTIVATE);
            break;
        } /* if */

        MEA_CALLOC(mvInstance, sizeof(MeaMvInstance));
        mvInstance->fInfo = (MmsMessageFolderInfo *)sig->p_param;
#ifdef MMS_SUPPORT
        if(mmcIsJSRMsg(mvInstance->fInfo->msgId))
        {
#ifdef __UNIFIED_MSG_SUPPORT__
            (void)meaShowDialogWithConfirm(MsfError, MEA_STR_ID_OK, 0, MEA_STR_ID_FAILED_TO_DISPLAY_JSR_MMS, 
                MEA_MV_FSM, MEA_SIG_MV_PROP_VIEW_CONFIRM, mvInstance->fInfo->msgId);            
#else
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_DISPLAY_JSR_MMS), MEA_DIALOG_ERROR);
#endif
            /* mvInstance is not useful any more, release it.*/
            (void)MEA_SIGNAL_SENDTO(MEA_MV_FSM, MEA_SIG_MV_DEACTIVATE);
            break;
        }
#endif        
        handleActivate(mvInstance->fInfo);
        break;
       
    case MEA_SIG_MV_MR_DONE:
        /* A message has been loaded by MR! */
        mvInstance->theMessage = sig->p_param;
        meaPmViewRemove();
        if (MEA_MR_OK != sig->u_param1)
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MAMV_416E055D9FBD63FD20D07D4FB5143070, "(%s) (%d) failed to create instance\n", __FILE__, __LINE__));
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_DISPLAY_MM), 
                MEA_DIALOG_ERROR);
            (void)MEA_SIGNAL_SENDTO(MEA_MV_FSM, MEA_SIG_MV_DEACTIVATE);
            break;
        }
#ifdef WAP_SUPPORT
        if (MEA_STARTUP_MODE_VIEW != meaGetStartupMode())
        {
#if MEA_CFG_REQ_RR_AFTER_READ_FINISH == 0
	        /* Check for read report. Message must be of type MMS_SUFFIX_MSG */
            if (mvInstance->theMessage->msgProperties->readReport && 
                MMS_SUFFIX_MSG == mvInstance->theMessage->fileType && 
                NULL != mvInstance->theMessage->msgProperties->from &&
                FALSE == mvInstance->fInfo->read)
            {
                if (MEA_SEND_READ_REPORT_ON_REQUEST == (MeaSendReadReportType)meaGetConfig()->sendReadReport)
                {
                    /* ask End User whether or not to send a read report */
                    (void)meaShowConfirmDialog(MEA_STR_ID_READ_REPORT_SEND,
                        NULL, MEA_MV_FSM, MEA_SIG_MV_SEND_READ_REPORT, 0);
                }
                else if (MEA_SEND_READ_REPORT_ALWAYS == (MeaSendReadReportType)meaGetConfig()->sendReadReport)
                {
                    /* send a read report without asking */
                    (void)MEA_SIGNAL_SENDTO_U(MEA_MV_FSM, MEA_SIG_MV_SEND_READ_REPORT,
                        (MeaConfirmDialogResult)MEA_CONFIRM_DIALOG_OK);
                }
            }
#endif
            if (!(mvInstance->fInfo->read)
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
                && meaGetCurrentFolder() != MEA_FOLDER_USER_TEMPLATE
#endif
                )
            {
                MMSif_setReadMark(MSF_MODID_MEA, mvInstance->theMessage->msgId, TRUE);
#if MEA_CFG_REQ_RR_AFTER_READ_FINISH == 0
                mvInstance->fInfo->read = TRUE;  /* In case meaRestartMr() is called, rr would be sent again... */
#endif
                (void)MEA_SIGNAL_SENDTO_I(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER, MEA_FOLDER_NONE);
            }

            (void)MEA_SIGNAL_SENDTO(MEA_MV_FSM, MEA_SIG_MV_PROP_OK);            
        }
        else
#endif /* WAP_SUPPORT */
            (void)MEA_SIGNAL_SENDTO(MEA_MV_FSM, MEA_SIG_MV_PROP_ACTIVATE);
        break;

    case MEA_SIG_MV_DR:
        /* A delivery report has been read! */
        handleDeliveryReport(mvInstance, (MmsMsgDeliveryReportInd *)sig->p_param);
        break;
        
    case MEA_SIG_MV_RR:
        /* A read reply has been read! */
        handleReadReport(mvInstance, (MmsMsgReadReport *)sig->p_param);
        break;        

#ifdef __UNIFIED_MSG_SUPPORT__
    case MEA_SIG_MV_NOTIF:
        if(fldrGetFileSuffix((MmsMsgId)sig->u_param1)== MMS_SUFFIX_NOTIFICATION ||
            fldrGetFileSuffix((MmsMsgId)sig->u_param1)== MMS_SUFFIX_IMMEDIATE)
        {
            meaCreateMvNotifPropView((MmsMsgId)sig->u_param1);
        }
        break;
#endif
        
    case MEA_SIG_MV_DEACTIVATE:            
        {
            /* BGSR will send msgId to close the specified message viewer.
               For other situations, no msgId provide and deActivate directly.*/
            MmsMsgId msgId = (MmsMsgId)sig->u_param1;

            if ((msgId != 0) && mvInstance && mvInstance->theMessage)
            {
                if (msgId == mvInstance->theMessage->msgId)
                {
                    deActivate(&mvInstance);
                }
            }
            else
            {
                deActivate(&mvInstance);
            }
        }
        break;
        
    case MEA_SIG_MV_VIEW_SMIL:
        meaPlaySmil(mvInstance->theMessage->msgId, (MmsFileType)
            mvInstance->theMessage->fileType, MEA_MV_FSM, MEA_SIG_MV_PLAY_DONE);
        break;

    case MEA_SIG_MV_SEND_READ_REPORT:
        if ((MeaConfirmDialogResult)sig->u_param1 == MEA_CONFIRM_DIALOG_OK
            && mvInstance && mvInstance->theMessage)
        {
#ifdef WAP_SUPPORT
			if(getMMSVersion(MSF_MODID_MEA, mvInstance->theMessage->msgId)==MMS_VERSION_10)
				setMmscVersion("VER10");
#endif
#ifdef __UNIFIED_MSG_SUPPORT__
            set10RrAllStringRes();  /* Since MEA become static startup, apply current language string resource here */
#endif
            /* Send the read report */
#ifndef __MMI_MMS_BGSR_SUPPORT__
            MMSif_sendReadReport(MSF_MODID_MEA, mvInstance->theMessage->msgId, 
                MMS_READ_STATUS_READ);
#else /*__MMI_MMS_BGSR_SUPPORT__*/
            {
                mmi_mms_bgsr_msg_struct *send_data;

                send_data = MSF_MEM_ALLOCTYPE(MSF_MODID_WIDGET, mmi_mms_bgsr_msg_struct);
                memset((S8*)send_data, 0, sizeof(mmi_mms_bgsr_msg_struct));
                send_data->msg_id = mvInstance->theMessage->msgId;
                send_data->is_rr = 1; 
                send_data->send_setting = MMI_MMS_BGSR_SETTING_SEND_ONLY;
                                  
                widget_execute_MMI_p(MEAa_sendMessageReq, send_data, FALSE);
            }
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MAMV_CC1BFA10AA2B4E10CE2BADCEB4B49CE4, "(%s) (%d) read report sent!\n", __FILE__, __LINE__));
        }
        else
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MAMV_B93AE523055CD5A4490C60AA242E1078, "(%s) (%d) read report not requested by the End User\n", 
                __FILE__, __LINE__));
        }
#if MEA_CFG_REQ_RR_AFTER_READ_FINISH == 1
        if (meaNoPropView())
        {
            (void)MEA_SIGNAL_SENDTO(MEA_MV_FSM, MEA_SIG_MV_DEACTIVATE);
        }
#endif
        break;
        
    case MEA_SIG_MV_PROP_ACTIVATE:
        activatePropertyView(mvInstance);
        break;

#ifdef WAP_SUPPORT
    case MEA_SIG_MV_ACTIVATE_CONFIRM:		
        if ((MeaConfirmDialogResult)sig->u_param1 == MEA_CONFIRM_DIALOG_OK)
        {
            id = sig->u_param2;
            if (id < 1) 
            {  //ask MMI to show error msg
                (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_DISPLAY_MM), 
                    MEA_DIALOG_ERROR);
                break; 
            } /* if */
		#ifdef MMS_SUPPORT
            if(mmcIsJSRMsg(id))
            {
                (void)meaShowDialogWithConfirm(MsfError, MEA_STR_ID_OK, 0, 
                    MEA_STR_ID_FAILED_TO_DISPLAY_JSR_MMS, MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP, sig->u_param2);            
                break;
            }
		#endif            

  #ifdef MMS_FILE_PROTECT_SUPPORT
            if(!isValidMmsMSg(id))
            {
                meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_MESSAGE_CORRUPT),MEA_DIALOG_ERROR);
                break;
            }
  #endif /* MMS_FILE_PROTECT_SUPPORT */
  
            mvActiveMsgId = id;
            
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MAMV_F6144CA0235CDDE24B25B897B3D7D1E2, "(%s) (%d) Trying to view msgId=%d\n", __FILE__, __LINE__, 
                sig->u_param2));
            meaSrhGetMessageInfo(MEA_MV_FSM, MEA_SIG_MV_GET_MSG_TYPE_RSP, id);
        }
        else
        {
            /* Close the application */
            if (MEA_STARTUP_MODE_VIEW == meaGetStartupMode())
            {
                (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, 
                    MEA_SIG_CORE_TERMINATE_APP);
            }
        }
        break;

    case MEA_SIG_MV_PROP_VIEW_CONFIRM:
        meaCreateMvPropView((MmsMsgId)sig->u_param2, FALSE);
		break;
        
	case MEA_SIG_MV_PROP_VIEW:
        meaCreateMvPropView((MmsMsgId)sig->u_param1, FALSE);
		break;
#ifdef __MMI_MMS_BGSR_SUPPORT__
    case MEA_SIG_MV_STATUS_VIEW:
        meaCreateMvStatusView(sig->i_param, sig->u_param1, sig->u_param2);
        break;
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
#endif /* WAP_SUPPORT */
/* user selected VIEW in menu or Ok in prop menu */
    case MEA_SIG_MV_VIEW_CONTENT:
    case MEA_SIG_MV_PROP_OK:
        if (MEA_MR_SMIL == mvInstance->theMessage->msgType) 
        {
            /* SMIL! Let SMA handle it. */
            (void)MEA_SIGNAL_SENDTO(MEA_MV_FSM, MEA_SIG_MV_VIEW_SMIL);
        }
        else if (MEA_MR_MULTIPART_MIXED == mvInstance->theMessage->msgType || 
            MEA_MR_PLAIN_TEXT == mvInstance->theMessage->msgType) /* Use mixed MMS player to render empty MMS */
        {
            /* Not SMIL, but has attachments we've found and decided we can 
             * handle. Start multipart/mixed viewer (also handles plain/text
             */
            (void)MEA_SIGNAL_SENDTO_P(MEA_MMV_FSM, MEA_SIG_MMV_ACTIVATE,
                mvInstance->theMessage);                
        }
        else  /* ex. MEA_MR_UNSUPPORTED */
        {
            if (mvInstance->theMessage->smilInfo != NULL && mvInstance->theMessage->smilInfo->mediaObjects != NULL
                && mvInstance->theMessage->smilInfo->mediaObjects->size > 0)
            {
                (void)MEA_SIGNAL_SENDTO_P(MEA_MMV_FSM, MEA_SIG_MMV_ACTIVATE, mvInstance->theMessage);                
            }
            else
            {
                meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_NO_CONTENT), MEA_DIALOG_INFO);
                (void)MEA_SIGNAL_SENDTO(MEA_MV_FSM, MEA_SIG_MV_DEACTIVATE);            
            }
        }
        break;

    case MEA_SIG_MV_PLAY_DONE:
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MAMV_9F2EDEFE3171554C548241074D12B193, "(%s) (%d) Done playing the MMS\n", __FILE__, __LINE__));
        
        if (plySmilFailed)
        {
            meaMvTransformToMixed();
            wap_task_sleep(500);
            plySmilFailed = FALSE;
        }
        else if (mvInstance != NULL) /* playing finished */
        {
#if MEA_CFG_REQ_RR_AFTER_READ_FINISH == 1
            /* Check for read report. Message must be of type MMS_SUFFIX_MSG */
            if (mvInstance->theMessage->msgProperties->readReport && 
                MMS_SUFFIX_MSG == mvInstance->theMessage->fileType && 
                NULL != mvInstance->theMessage->msgProperties->from &&
                FALSE == mvInstance->fInfo->read)
            {
                mvInstance->fInfo->read = TRUE;
                if (MEA_SEND_READ_REPORT_ON_REQUEST == (MeaSendReadReportType)meaGetConfig()->sendReadReport)
                {
                    /* ask End User whether or not to send a read report */
                    (void)meaShowConfirmDialog(MEA_STR_ID_READ_REPORT_SEND,
                        NULL, MEA_MV_FSM, MEA_SIG_MV_SEND_READ_REPORT, 0);
                    (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_CREATE_PROP_RR_CONFIRM);
                    break;
                    
                }
                else if (MEA_SEND_READ_REPORT_ALWAYS == (MeaSendReadReportType)meaGetConfig()->sendReadReport)
                {
                    /* send a read report without asking */
                    (void)MEA_SIGNAL_SENDTO_U(MEA_MV_FSM, MEA_SIG_MV_SEND_READ_REPORT,
                        (MeaConfirmDialogResult)MEA_CONFIRM_DIALOG_OK);
                    break;
                }
            }
#endif
            if (meaNoPropView())
            {
                (void)MEA_SIGNAL_SENDTO(MEA_MV_FSM, MEA_SIG_MV_DEACTIVATE);
            }
        }
        break;

    case MEA_SIG_MV_DOWNLOAD_RSP:
        /* Check if the download operation was successful */
        if (MEA_DOWNLOAD_OK != (MeaDownloadResult)sig->u_param1)
        {
#ifdef WAP_SUPPORT
            if (MEA_STARTUP_MODE_DOWNLOAD == meaGetStartupMode() &&
                (MeaDownloadResult)sig->u_param1 != MEA_DOWNLOAD_TERMINATE_SILENT && !meaMhIsActive())
            {
                meaShowDownloadErrorDialog((MeaDownloadResult)sig->u_param1, 
                    MEA_NOTUSED_FSM, 0);
                /* Terminate if started in download mode. mvInstance will be cleared */
                (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP);
            }
            else
            {
                meaShowDownloadErrorDialog((MeaDownloadResult)sig->u_param1, 
                    MEA_NOTUSED_FSM, 0 /*MEA_SIG_MV_DEACTIVATE*/);
                mvClearMvInstance();   //for not display LSK "Ok"
            }
#endif /* WAP_SUPPORT */
            break; 
        }
        else
        {
            if(MEA_STARTUP_MODE_DOWNLOAD == meaGetStartupMode())
            {
           	#ifdef MMS_SUPPORT
            	if (mmcIsJSRMsg(sig->u_param2))
				{            	
                	(void)meaShowDialogWithConfirm(MsfError, MEA_STR_ID_OK, 0, 
                    	MEA_STR_ID_FAILED_TO_DISPLAY_JSR_MMS, MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP, sig->u_param2);
                	break;
				}
			#endif                	
            }
        }
        /* Deallocate the the current instance and start with again with the 
           new msgId */
#ifdef WAP_SUPPORT
        deActivate(&mvInstance);
  #ifdef MMS_FILE_PROTECT_SUPPORT
        if (!isValidMmsMSg(sig->u_param2))
            meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_MESSAGE_CORRUPT),MEA_DIALOG_ERROR);	
        else
  #endif
        {
            /* If the download was successful show the message */
            (void)MEA_SIGNAL_SENDTO_IU(MEA_MV_FSM, MEA_SIG_MV_ACTIVATE, 
                MMS_SUFFIX_MSG, sig->u_param2);
			meaSetActiveMmId(sig->u_param2);	
        }
#else
        deActivate(&mvInstance);
        /* If the download was successful show the message */
        (void)MEA_SIGNAL_SENDTO_IU(MEA_MV_FSM, MEA_SIG_MV_ACTIVATE, 
            MMS_SUFFIX_MSG, sig->u_param2);
#endif /* WAP_SUPPORT */
        /* Update folders */
        (void)MEA_SIGNAL_SENDTO_I(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER, 
            MEA_FOLDER_NONE);
        break;

    case MEA_SIG_MV_NAME_LOOKUP_RSP:
        if (NULL != mvInstance->theMessage)

        {
            /* Marge the name with the current items */
            meaAddrItemMerge(mvInstance->theMessage->msgProperties->to, 
                sig->p_param);
            meaAddrItemMerge(mvInstance->theMessage->msgProperties->cc, 
                sig->p_param);
            /* Update the message properties */
            if (!meaSetMvProperties(mvInstance->theMessage->msgProperties))
            {
                MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
                    MAMV_FA6A498543205CF8BC63FF697417C426, "(%s) (%d) failed to display message properties\n", 
                    __FILE__, __LINE__));
                (void)MEA_SIGNAL_SENDTO(MEA_MV_FSM, MEA_SIG_MV_DEACTIVATE);
            }
        }
        if (NULL != sig->p_param)
        {
            tmpAddrItem = sig->p_param;
            meaAddrListFree(&tmpAddrItem);
        }
        break;

    default :
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAMV_656094C204631DD375F7F8599D24293F, "(%s) (%d) MV: Unknown signal recieved(%d)\n", __FILE__, __LINE__,
            sig->type));
        break;
    } 
    meaSignalDelete(sig);
}

#ifdef WAP_SUPPORT
/*! \brief
 * \param inst
 *****************************************************************************/

void meaMvTransformToMixed(void)
{
    if (mvInstance)
    {
	    MmsMessageFolderInfo *info = mvInstance->fInfo;
	    meaFreeMessage(&mvInstance->theMessage);
	    if (mvInstance->getNotifInstance) 
	    {
	        meaCleanupGetNotifInstance(&mvInstance->getNotifInstance);
	    } /* if */
	    meaRestartMr(MEA_MR_STARTUP_VIEW, info->msgId, info->suffix,
	        MEA_MV_FSM, MEA_SIG_MV_MR_DONE);
    }
}

MSF_BOOL hasMvInstance(void)
{
	if (mvInstance)
		return TRUE;
    return FALSE;
}

void mvClearMvInstance(void)
{
        if (mvInstance) 
            deActivate(&mvInstance);
}

void mvClearMvInstanceForCancelDownload(void)
{
    if (!mvInstance)
        return;

    MEA_FREE(mvInstance->fInfo);
    mvInstance->fInfo = NULL;
    meaFreeMessage(&(mvInstance->theMessage));
    if (mvInstance->getNotifInstance) 
    {
        meaCleanupGetNotifInstance(&(mvInstance->getNotifInstance));
    } /* if */
    MEA_FREE(mvInstance);
    mvInstance = NULL;

    meaPmViewRemove();
    mvActiveMsgId = 0;

    if (meaNoPropView())
    {
        (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);
    }
}

void meaMvSetActiveMsgId(MmsMsgId msgId)
{
    mvActiveMsgId = msgId;
}

void meaMvSetPlySmilFailed(MSF_BOOL flag)
{
    plySmilFailed = flag;

}
#endif /* WAP_SUPPORT */
#if defined(WAP_SUPPORT) || defined(__DRM_SUPPORT__)
MmsMsgId meaMMCGetCurrentActiveMsg(void)
{
    if (meaSmilEditorIsActive() && meaGetCurrentFolder() == MEA_FOLDER_TEMPLATE)
        return mvActiveMsgId;
    else if (meaGetActiveMm())
        return meaGetActiveMm()->msgId;
    else
        return mvActiveMsgId;
}
#endif /* defined(WAP_SUPPORT) || defined(__DRM_SUPPORT__) */
/*!
 * \brief Registers signal handler
 *****************************************************************************/
void meaMvInit(void)
{
    mvInstance = NULL;
    meaSignalRegisterDst(MEA_MV_FSM, meaViewer); /* set sig-handler */
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
        MAMV_C2AA87C4F54A1AD228111021ECC71C84, "MEA MV: initialized\n"));
}

/*!
 * \brief Terminates, by de-registering signal handler
 *****************************************************************************/
void meaMvTerminate(void)
{
    deActivate(&mvInstance);
    /* Deregister signal handler */
    meaSignalDeregister(MEA_MV_FSM);
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, MAMV_D2C35F41E9DB10238FFD42372E0EE9BA, "MEA MV: terminated\n"));

}











































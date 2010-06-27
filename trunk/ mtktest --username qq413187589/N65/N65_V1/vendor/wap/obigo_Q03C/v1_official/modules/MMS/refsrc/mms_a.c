/*
 * Copyright (C) Obigo AB, 2002-2005.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */
 
/*! \file mms_a.c
 * \brief  In this file is the adapter functions in protyped in mms_int.h 
 *         implemented as reference code (example code). This functions
 *         needs to integrated in the target device envrionment. 
 */

/*--- Include files ---*/
#include "msf_log.h"    /* MSF: Signal logging */ 
#include "mms_def.h"    /* MMS: Exported types in adapter/connector functions */
#include "mms_int.h"    /* MMS: MMS Exported Adapter functions */ 
#include "msf_log.h"    /* MSF: Signal logging */ 
#include "msf_core.h" /* MSF: Signal encapsulation */
#include "msf_mem.h"

#include "mms_aApp.h"		
#include "WapDef.h"
#include "widget_extension.h"
#include "mconfig.h"
#include "mms_cfg.h"  //for MMS_MAX_NO_OF_MSG
#include "mms_if.h"
#include "msig.h"  /* for fldmgr.h */
#include "fldmgr.h" /* for MmsMessageFolderInfo */

extern int MSF_moduleIsRunning(MSF_UINT8 modId);
extern void meaSetCorruptedMsgId(MmsMsgId msgId);
extern MmsResult fldrMgrDeleteMessage(MSF_UINT32 msgId);
extern void HDIa_socketDiscBearerById(MSF_INT32 networkAccountID);
#ifdef MMS_SUPPORT
extern MSF_BOOL mmcIsRecvMMSForJava(MSF_UINT32 msgId);
#endif
#ifdef __MMS_DUAL_SIM_SUPPORT__
void MMSa_addSRInstance(MmsMsgId msgId, MmsSimCardEnum simId);
#else
void MMSa_addSRInstance(MmsMsgId msgId);
#endif
void MMSa_delSRInstance(MmsMsgId msgId);

#ifdef __UNIFIED_MSG_SUPPORT__
extern MmsMessageFolderInfo *fldrMgrGetMsgInfo(MSF_UINT32 msgId);
extern void wap_send_mmi_mms_new_msg_ind(kal_uint32 timestamp);
#endif
static int mmsUsingAccId = -1;

#ifdef __MMI_MMS_BGSR_SUPPORT__
#include "mea_def.h"
#include "maintsig.h"
#include "mamh.h"
#include "masrh.h"
#endif /*__MMI_MMS_BGSR_SUPPORT__*/

typedef struct srInstanceStruct
{
    MmsMsgId msgId;
#ifdef __MMS_DUAL_SIM_SUPPORT__
    MmsSimCardEnum simId;
#endif
    struct srInstanceStruct *next;
}srInstance;

srInstance *instances = NULL;
/*--- Definitions/Declarations ---*/

/*--- Types ---*/

/*--- Constants ---*/

/*--- Forwards ---*/

/*--- Externs ---*/

/*--- Macros ---*/

/*--- Global variables ---*/

/*--- Static variables ---*/

/*--- Prototypes ---*/

/*****************************************************************************/

/*
 * Informs that a message, notification or read report has been recived
 * 
 * Please note: Doxygen dokumentation, see file description in top of file.
 *****************************************************************************/




void MMSa_newMessage(MmsFileType msgType, MmsMsgId msgId, 
    MmsAddress *from, MmsEncodedText *subject, MSF_UINT32 size,
    MSF_UINT32 numOfMsg,   MSF_UINT32 numOfUnreadMsg,
    MSF_UINT32 numOfNotif, MSF_UINT32 numOfUnreadNotif,
    MSF_UINT32 numOfRR,    MSF_UINT32 numOfUnreadRR,
    MSF_UINT32 numOfDR,    MSF_UINT32 numOfUnreadDR,
    MmsNotificationReason reason
    )
{
    MSF_LOG_FC_BEGIN(MMSa_newMessage)
        MSF_LOG_FC_UINT32(numOfMsg, NULL); 
        MSF_LOG_FC_UINT32(numOfUnreadMsg, NULL); 
        MSF_LOG_FC_UINT32(numOfNotif, NULL); 
        MSF_LOG_FC_UINT32(numOfUnreadNotif, NULL); 
        MSF_LOG_FC_UINT32(numOfRR, NULL); 
        MSF_LOG_FC_UINT32(numOfUnreadRR, NULL); 
        MSF_LOG_FC_UINT32(numOfDR, NULL); 
        MSF_LOG_FC_UINT32(numOfUnreadDR, NULL); 
        MSF_LOG_FC_PRE_IMPL
        
    MSF_LOG_MSG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, 
        "MMSa_newMessage: Received, type=%d, msgId=%lu, from=%s, subject=%s, size=%lu\n",
        (int)msgType, (unsigned long)msgId, 
        (from != NULL && from->address != NULL) ? from->address : "NULL", 
        (subject != NULL && subject->text != NULL) ? subject->text : "NULL", 
        (unsigned long)size));
    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, 
        MMS_A_B3B9DADE07C50B4EE28F91098997F11E, "MMSa_newMessage: Received, numOfMsg=%d, numOfUnread=%d numOfNotif=%d reason = %d\n",
        (int)numOfMsg, (int)numOfUnreadMsg, (int)numOfNotif, (int)reason));

    /*
     * Update this switch with calling ring tone etc. depending on type 
     * of received message. 
     */
    switch (msgType) 
    { 
        case MMS_SUFFIX_MSG :           /* Message received, immediate */
        {
#ifdef MMS_SUPPORT
        		mmcIsRecvMMSForJava(msgId);
#endif
#ifdef MMS_FILE_PROTECT_SUPPORT
			if (genChkSumFile(msgId) != MMS_RESULT_OK)
			{
				if (!MSF_moduleIsRunning(MSF_MODID_MEA))
					fldrMgrDeleteMessage(msgId);
				else
					meaSetCorruptedMsgId(msgId);
			}
			else
#endif
            {
                mmsUpdateIndicator(); /* In idle screen, we need to do it ourselves. 
                                       * For UM, do it before send indication for screen refresh issue 
                                       */
#ifdef __UNIFIED_MSG_SUPPORT__
                wap_send_mmi_mms_new_msg_ind(((MmsMessageFolderInfo *)fldrMgrGetMsgInfo(msgId))->date);
#endif
			    HDIa_widgetExtRegisterNewMMS((kal_uint32)msgId, WIDGET_MMS_NEW_MSG, size);
            }
			break;						
        }
		case MMS_SUFFIX_IMMEDIATE :     /* Notification received, immediate */

        case MMS_SUFFIX_NOTIFICATION :  /* Notification received, delayed */  	
			
#if MMS_CHECK_DUPLICATE_NOTIFICATION
			checkDuplicateMsg(msgId,MMS_SUFFIX_NOTIFICATION); 			
#endif			
            {
#ifdef MMS_FILE_PROTECT_SUPPORT
				MmsResult retChksum = genChkSumFile(msgId);
				if (retChksum == MMS_RESULT_INSUFFICIENT_PERSISTENT_STORAGE ||
					retChksum ==MMS_RESULT_FILE_WRITE_ERROR ||
					retChksum ==MMS_RESULT_ERROR)
				{
					if (!MSF_moduleIsRunning(MSF_MODID_MEA))
						fldrMgrDeleteMessage(msgId);
					else
						meaSetCorruptedMsgId(msgId);
				}
				else
#endif
                {
                mmsUpdateIndicator(); /* In idle screen, we need to do it ourselves. 
                                       * For UM, do it before send indication for screen refresh issue 
                                       */
#ifdef __UNIFIED_MSG_SUPPORT__
                wap_send_mmi_mms_new_msg_ind(((MmsMessageFolderInfo *)fldrMgrGetMsgInfo(msgId))->date);
#endif
				HDIa_widgetExtRegisterNewMMS((kal_uint32)msgId, WIDGET_MMS_NOTIFICATION, size);
#ifdef __MMI_MMS_BGSR_SUPPORT__
                meaSrhGetMessageInfo(MEA_MH_FSM, 
                    MEA_SIG_MH_BGSR_DOWNLOAD_MSG_TYPE_RSP, msgId);
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
                }
            }
			break;
			
		case MMS_SUFFIX_READREPORT :    /* Read Report received */ 
#ifdef MMS_FILE_PROTECT_SUPPORT
			genChkSumFile(msgId);
#endif
            mmsUpdateIndicator(); /* In idle screen, we need to do it ourselves. 
                                   * For UM, do it before send indication for screen refresh issue 
                                   */
#ifdef __UNIFIED_MSG_SUPPORT__
            wap_send_mmi_mms_new_msg_ind(((MmsMessageFolderInfo *)fldrMgrGetMsgInfo(msgId))->date);
#endif
			HDIa_widgetExtRegisterNewMMS((kal_uint32)msgId, WIDGET_MMS_READ_REPORT, size);
			break;						

		case MMS_SUFFIX_DELIVERYREPORT :/* Delivery Report received */     
#ifdef MMS_FILE_PROTECT_SUPPORT
			genChkSumFile(msgId);
#endif
            mmsUpdateIndicator(); /* In idle screen, we need to do it ourselves. 
                                   * For UM, do it before send indication for screen refresh issue 
                                   */
#ifdef __UNIFIED_MSG_SUPPORT__
            wap_send_mmi_mms_new_msg_ind(((MmsMessageFolderInfo *)fldrMgrGetMsgInfo(msgId))->date);
#endif
			HDIa_widgetExtRegisterNewMMS((kal_uint32)msgId, WIDGET_MMS_DELIVERY_REPORT, size);
			break;						

		default: 
            break; 
    } /* switch */ 
    /*
     * Update this function to handle change of unread messages status. 
     */
    MSF_LOG_FC_END
        
} /* MMSa_newMessage */ 


/*
 * Informs that a message, notification or read report has been recived
 * 
 * Please note: Doxygen dokumentation, see file description in top of file.
 *****************************************************************************/
void MMSa_messageStatus(
                        MSF_UINT32 numOfMsg,   MSF_UINT32 numOfUnreadMsg,
                        MSF_UINT32 numOfNotif, MSF_UINT32 numOfUnreadNotif,
                        MSF_UINT32 numOfRR,    MSF_UINT32 numOfUnreadRR,
                        MSF_UINT32 numOfDR,    MSF_UINT32 numOfUnreadDR)
{
    MSF_LOG_FC_BEGIN(MMSa_messageStatus)
        MSF_LOG_FC_UINT32(numOfMsg, NULL); 
        MSF_LOG_FC_UINT32(numOfUnreadMsg, NULL); 
        MSF_LOG_FC_UINT32(numOfNotif, NULL); 
        MSF_LOG_FC_UINT32(numOfUnreadNotif, NULL); 
        MSF_LOG_FC_UINT32(numOfRR, NULL); 
        MSF_LOG_FC_UINT32(numOfUnreadRR, NULL); 
        MSF_LOG_FC_UINT32(numOfDR, NULL); 
        MSF_LOG_FC_UINT32(numOfUnreadDR, NULL); 
    MSF_LOG_FC_PRE_IMPL

    MSF_LOG_MSG_OFF(( MSF_LOG_DETAIL_HIGH, MSF_MODID_MMS, 
        MMS_A_2C21AEEA418A77A26A5DBC3DE5F82F94, "MMSa_messageStatus: Received, numOfMsg=%d, numOfUnreadMsg=%d", (int)numOfMsg, (int)numOfUnreadMsg));
    MSF_LOG_MSG_OFF(( MSF_LOG_DETAIL_HIGH, MSF_MODID_MMS, 
        MMS_A_9EFB59552EEC01AFE66EA2F53055189A, "MMSa_messageStatus: Continued, numOfMsg=%d, numOfUnreadMsg=%d", (int)numOfNotif, (int)numOfUnreadNotif));
    MSF_LOG_MSG_OFF(( MSF_LOG_DETAIL_HIGH, MSF_MODID_MMS, 
        MMS_A_9EFB59552EEC01AFE66EA2F53055189A, "MMSa_messageStatus: Continued, numOfMsg=%d, numOfUnreadMsg=%d", (int)numOfDR, (int)numOfUnreadRR));
    MSF_LOG_MSG_OFF(( MSF_LOG_DETAIL_HIGH, MSF_MODID_MMS, 
        MMS_A_9EFB59552EEC01AFE66EA2F53055189A, "MMSa_messageStatus: Continued, numOfMsg=%d, numOfUnreadMsg=%d", (int)numOfDR, (int)numOfUnreadRR));
    
    MSF_LOG_FC_END
        
} /* MMSa_messageStatus */ 

/*
 * Informs that a message, notification or read report has been recived
 * 
 * Please note: Doxygen dokumentation, see file description in top of file.
 *****************************************************************************/
void MMSa_progressStatus(MmsProgressStatus *progressData)
{
    /*
     * Here the integration should implement any reporting
     * of progress status of MMS download/upload.
     *
     * The structure progressData supplies information about
     * the operation in progress.
     *
     * The status variable informs about lifespan and can
     * be used to allocate/free data for progress tracking.
     */
    MSF_LOG_FC_BEGIN(MMSa_progressStatus)

    MSF_LOG_FC_UINT32(progressData->msgId, NULL); 
    MSF_LOG_FC_UINT8(progressData->operation, NULL); 
    MSF_LOG_FC_UINT32(progressData->progress, NULL); 
    MSF_LOG_FC_UINT8(progressData->queueLength, NULL); 
    MSF_LOG_FC_UINT8(progressData->state, NULL); 
    MSF_LOG_FC_UINT32(progressData->totalLength, NULL); 
    MSF_LOG_FC_PRE_IMPL

#ifdef __MMS_DUAL_SIM_SUPPORT__
    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, MMS_A_848A3F97D1A371D522C0D5CFD7175679, "MMSa_progressStatus: accId=%d, state=%d, msgId=%d\n", 
    fldrGetMessageSimId(progressData->msgId), progressData->state, progressData->msgId));
#else
    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, MMS_A_848A3F97D1A371D522C0D5CFD7175679, "MMSa_progressStatus: accId=%d, state=%d, msgId=%d\n", 
    cfgGetInt(MMS_CFG_NETWORK_ACCOUNT), progressData->state, progressData->msgId));
#endif

#ifndef __MMS_DUAL_SIM_SUPPORT__
    if (mmsUsingAccId >= 0 && mmsUsingAccId != cfgGetInt(MMS_CFG_NETWORK_ACCOUNT))  /* User is changing account ID */
    {
        HDIa_socketDiscBearerById(mmsUsingAccId);
        MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, MMS_A_8ABD6F1729FEC76BB25C4D7464B11F3E, "HDIa_socketDiscBearerById(old %d)\n", mmsUsingAccId));
    }
#endif



	if (progressData->state == MMS_PROGRESS_STATUS_START || progressData->state == MMS_PROGRESS_STATUS_PROGRESS)
	{
	    if (progressData->msgId > 0)  /* exclude notify response */
        {
#ifdef __MMS_DUAL_SIM_SUPPORT__
            mmsUsingAccId = mmsWapGetAccountIdOfMessage(progressData->msgId);
            MMSa_addSRInstance(progressData->msgId, fldrGetMessageSimId(progressData->msgId));
#else
            mmsUsingAccId = cfgGetInt(MMS_CFG_NETWORK_ACCOUNT);
            MMSa_addSRInstance(progressData->msgId);
#endif
            mmsUpdateIndicator();
        }
	}
	else if (progressData->state == MMS_PROGRESS_STATUS_COMPLETED || progressData->state == MMS_PROGRESS_STATUS_STOP)
	{
    	/* MMS could configure to disconnect and call HDIa_socketDiscBearer() to inform SOC*/
        mmsUsingAccId = -1;
        if (progressData->msgId > 0)
        {
            MMSa_delSRInstance(progressData->msgId);
        }
        mmsUpdateIndicator();
#ifndef __MMS_DUAL_SIM_SUPPORT__
        HDIa_socketDiscBearerById(cfgGetInt(MMS_CFG_NETWORK_ACCOUNT));
#endif
        MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, MMS_A_52393E3E00791A155FAA8458825CB634, "HDIa_socketDiscBearerById(%d)\n", cfgGetInt(MMS_CFG_NETWORK_ACCOUNT)));
	}
        
    MSF_LOG_FC_END
}


/*
 * An error has occured when no application was connected to the MMS Service. 
 * 
 * Please note: Doxygen dokumentation, see file description in top of file.
 *****************************************************************************/
void MMSa_error(MmsResult errorCode)
{
    /* 
     * Update this code to the report error
     */ 
	mmsHandleErrors(errorCode); 

    MSF_LOG_MSG_OFF(( MSF_LOG_DETAIL_HIGH, MSF_MODID_MMS, 
        MMS_A_CB11217942A85A0E21112FB568FF354C, "MMS: An Error occured when no application was connectd (%d)\n",
        errorCode));
} /* MMSa_error */


void MMSa_resetProgressStatus(void)
{
    instances = NULL;
    mmsUsingAccId = -1;
}

MSF_BOOL isMMSBusy(void)
{
    return (instances != NULL);
}

#ifdef __MMS_DUAL_SIM_SUPPORT__
void MMSa_addSRInstance(MmsMsgId msgId, MmsSimCardEnum simId)
#else
void MMSa_addSRInstance(MmsMsgId msgId)
#endif
{
    srInstance *inst = NULL, *ptr = instances, *prev = NULL;
    while (ptr)
    {
        if (ptr->msgId == msgId)
        {
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }

    inst = (srInstance *)MSF_MEM_ALLOC(MSF_MODID_MMS, sizeof(srInstance));
    inst->msgId = msgId;
#ifdef __MMS_DUAL_SIM_SUPPORT__
    inst->simId = simId;
#endif
    inst->next = NULL;
    if (instances == NULL)
    {
        instances = inst;
    }
    else
    {
        prev->next = inst;
    }
}

void MMSa_delSRInstance(MmsMsgId msgId)
{
    srInstance *inst = NULL, *ptr = instances, *prev = NULL;
    while (ptr)
    {
        if (ptr->msgId == msgId)
        {
            if (prev == NULL)
            {
                instances = ptr->next;
            }
            else
            {
                prev->next = ptr->next;
            }
            MSF_MEM_FREE(MSF_MODID_MMS, ptr);
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }
}

#ifdef __MMS_DUAL_SIM_SUPPORT__
MSF_BOOL IsMasterSIMBusy(void)
{
    srInstance *ptr = instances;
    while (ptr)
    {
        if (ptr->simId == MMS_SIM_CARD_MASTER)
        {
            return TRUE;
        }
        ptr = ptr->next;
    }

    return FALSE;
}

MSF_BOOL IsSlaveSIMBusy(void)
{
    srInstance *ptr = instances;
    while (ptr)
    {
        if (ptr->simId == MMS_SIM_CARD_SLAVE)
        {
            return TRUE;
        }
        ptr = ptr->next;
    }

    return FALSE;
}
#endif /*__MMS_DUAL_SIM_SUPPORT__*/
#ifdef MSF_LOG_FC  
/*
MSF_LOG_FC_DISPATCH_MAP_ENTRY_BEGIN(MMSa_messageStatus)
MMSa_messageStatus( 1, 1);
MSF_LOG_FC_DISPATCH_MAP_ENTRY_END
*/
#endif /* MSF_LOG_FC */
















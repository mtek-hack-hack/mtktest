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

/*!\file manotif.c
 * \brief Reads a MMS notification. 
 */

/* MSF */
#include "msf_log.h"
#include "msf_lib.h"
#include "msf_mem.h"

/* MMS */
#include "mms_def.h"
#include "mmsl_if.h"

/* MEA */
#include "mea_rc.h"
#include "maintsig.h"
#include "manotif.h"
#include "mamem.h"
#include "maasync.h"
#ifdef WAP_SUPPORT
#include "macomm.h"
#endif /* WAP_SUPPORT */

/******************************************************************************
 * Constants
 *****************************************************************************/

/******************************************************************************
 * Types
 *****************************************************************************/

/******************************************************************************
 * Prototypes
 *****************************************************************************/

/******************************************************************************
 * Function implementations
 *****************************************************************************/

/*! \brief Retrieves the notification information
 *
 * \param inst The current instance.
 * \return The result of the operation, see #MeaReadNotifResult.
 *****************************************************************************/
MeaReadNotifResult meaGetNotifFSM(MeaGetNotifInstance *inst)
{
    int fileHandle;
    if (NULL == inst)
    {
        return MEA_READ_NOTIF_ERROR;
    }
   
    switch (inst->state) 
    {
    case MEA_MAL_OPEN_NOTIF: 
        inst->mmsRes = MMSlib_messageOpen(MSF_MODID_MEA, inst->msgId, 
            inst->msgType, &inst->msgHandle);
        if (MMS_RESULT_OK != inst->mmsRes)
        {
            return MEA_READ_NOTIF_ERROR;
        }
        inst->mmsRes = MMSlib_transactionOpen(MSF_MODID_MEA, &inst->tr);
        if (MMS_RESULT_OK != inst->mmsRes)
        {
            return MEA_READ_NOTIF_ERROR;
        }
        inst->state = MEA_MAL_READ_NOTIF;
        /*lint -fallthrough */
        
    case MEA_MAL_READ_NOTIF:
        /* Read the notification */
        inst->mmsRes = MMSlib_getNotification(MSF_MODID_MEA, inst->notif, 
            &inst->msgHandle, &inst->tr);
        if (MMS_RESULT_DELAYED == inst->mmsRes)
        {
            fileHandle = MMSlib_getFileHandle(MSF_MODID_MEA, &inst->tr);
            meaAsyncRegister(fileHandle, inst->notifyFsm, inst->notifySignal, 
                0);            
            return MEA_READ_NOTIF_DELAYED; /* Async! */
        }
        else if (MMS_RESULT_OK != inst->mmsRes)
        {
            return MEA_READ_NOTIF_ERROR;
        } 
        (void)MMSlib_transactionClose(MSF_MODID_MEA, &inst->tr);
        (void)MMSlib_messageClose(MSF_MODID_MEA, &inst->msgHandle);
        return MEA_READ_NOTIF_DONE;
    default:
        break;
    }
    return MEA_READ_NOTIF_ERROR;
}

#ifdef WAP_SUPPORT
/*! \brief Retrieves the notification length
 * \param msgId The current download msgId.
 * \return The result of the operation, see #MeaReadNotifResult.
 *****************************************************************************/
MeaReadNotifResult meaGetNotifLength(MmsMsgId msgId, MmsFileType msgType, MSF_UINT32 *msgLength)
{
    //int fileHandle;
    MeaReadNotifStates state =MEA_MAL_OPEN_NOTIF;
    MmsResult mmsRes;
    MmsMsgHandle msgHandle;
    MmsTransactionHandle tr;
    MmsNotification *notif;
    if (msgId < 1)
    {
        return MEA_READ_NOTIF_ERROR;
    }
   
    switch (state) 
    {
    case MEA_MAL_OPEN_NOTIF: 
        mmsRes = MMSlib_messageOpen(MSF_MODID_MEA, msgId, 
            msgType, &msgHandle);
        if (MMS_RESULT_OK != mmsRes)
        {
            return MEA_READ_NOTIF_ERROR;
        }
        mmsRes = MMSlib_transactionOpen(MSF_MODID_MEA, &tr);
        if (MMS_RESULT_OK != mmsRes)
        {
            return MEA_READ_NOTIF_ERROR;
        }
        state = MEA_MAL_READ_NOTIF;
        /*lint -fallthrough */
        
    case MEA_MAL_READ_NOTIF:
        /* Read the notification */
        notif = MEA_ALLOC(sizeof(MmsNotification));
        memset(notif, 0, sizeof(MmsNotification));
        mmsRes = MMSlib_getNotification(MSF_MODID_MEA, notif, 
            &msgHandle, &tr);
        /*
        if (MMS_RESULT_DELAYED == mmsRes)
        {
            fileHandle = MMSlib_getFileHandle(MSF_MODID_MEA, &tr);
            // signal should be changed
            meaAsyncRegister(fileHandle, MEA_COMM_FSM,
                MEA_SIG_COMM_DOWNLOAD_NOTIF_FILE_NOTIFY_RSP, 0);
            if (NULL != notif)
            {
                MEA_FREE(notif);
                notif = NULL;
            }
			
            return MEA_READ_NOTIF_DELAYED; // Async!
        }
        else */
        if (MMS_RESULT_OK != mmsRes)
        {
            if (NULL != notif)
            {
                MEA_FREE(notif);
                notif = NULL;
            }
            return MEA_READ_NOTIF_ERROR;
        } 
        (void)MMSlib_transactionClose(MSF_MODID_MEA, &tr);
        (void)MMSlib_messageClose(MSF_MODID_MEA, &msgHandle);

        if (NULL != notif) //MMS_RESULT_OK
        {
            *msgLength = (MSF_UINT32)notif->length;
            MMSlib_freeMmsNotification(MSF_MODID_MEA, notif);
            MEA_FREE(notif);
            notif = NULL;
        }
		
        return MEA_READ_NOTIF_DONE;
    default:
        break;
    }
    return MEA_READ_NOTIF_ERROR;
}
#endif /* WAP_SUPPORT */
/*! \brief Creates a instance for handling a notification.
 *
 * \param inst The new instance.
 * \param msgId The msgId of the notification to open.
 * \param fsm The callback FSM for async operations.
 * \param signal The callback signal for async operations.
 * \return 
 *****************************************************************************/
MSF_BOOL meaCreateGetNotifInstance(MeaGetNotifInstance **inst, MmsMsgId msgId,
    MmsFileType msgType, MeaStateMachine fsm, int signal)
{
    MeaGetNotifInstance *getNotifInstance;
    if (NULL != *inst)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MANOTIF_14E4E651417CA25289FB04D3A1CE8964, "(%s) (%d) instance busy\n", __FILE__, __LINE__));
        return FALSE;
    }
    else
    {
        getNotifInstance = MEA_ALLOC(sizeof(MeaGetNotifInstance));
        *inst = getNotifInstance;
        memset(getNotifInstance, 0, sizeof(MeaGetNotifInstance));
        getNotifInstance->notif = MEA_ALLOC(sizeof(MmsNotification));
        memset(getNotifInstance->notif, 0, sizeof(MmsNotification));
        /* Initial state */
        getNotifInstance->msgId         = msgId;
        getNotifInstance->msgType       = msgType;
        getNotifInstance->state         = MEA_MAL_OPEN_NOTIF;
        getNotifInstance->notifyFsm     = fsm;
        getNotifInstance->notifySignal  = signal;
    }
    return TRUE;
}

/*! \brief De-allocates the structure for handling notifications.
 *
 * \param inst The current instance.
 *****************************************************************************/
void meaCleanupGetNotifInstance(MeaGetNotifInstance **inst)
{
    MeaGetNotifInstance *getNotifInstance;

    if (NULL != *inst)
    {
        getNotifInstance = *inst;
        if (NULL != getNotifInstance->notif)
        {
            MMSlib_freeMmsNotification(MSF_MODID_MEA, getNotifInstance->notif);
            MEA_FREE(getNotifInstance->notif);
            getNotifInstance->notif = NULL;
        }

        /* Close message if previously opened */
        if (NULL != getNotifInstance->msgHandle)
        {
            (void)MMSlib_messageClose(MSF_MODID_MEA, 
                &getNotifInstance->msgHandle);
            getNotifInstance->msgHandle = NULL;
        }
        /* Close transaction if previously created */
        if (NULL != getNotifInstance->tr)
        {
            (void)MMSlib_transactionClose(MSF_MODID_MEA, 
                &getNotifInstance->tr);
            getNotifInstance->tr = NULL;
        }
        MEA_FREE(getNotifInstance);
        getNotifInstance = NULL;
        *inst = NULL;
    }
}



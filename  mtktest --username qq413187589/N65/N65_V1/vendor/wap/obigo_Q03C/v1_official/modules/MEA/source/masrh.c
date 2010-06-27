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

/*! \file masrh.c
 * !\brief Handles the signal routing case where one interface function can be 
 *         called from multiple FSM's, .i.e., when the response signal needs to 
 *         be routed to more than one destination.
 */

/* MSF */
#include "msf_core.h"
#include "msf_log.h"
#include "msf_cfg.h"
#include "msf_lib.h"
#include "msf_mem.h"
#include "msf_tel.h"

#include "msf_wid.h"

/* MMS Service */
#include "mms_cfg.h"
#include "mms_def.h"
#include "mms_if.h"

/* MEA*/
#include "mea_rc.h"
#include "mea_def.h"
#include "mea_cfg.h"
#include "mamem.h"
#include "maintsig.h"
#include "macore.h"

#include "mauicmn.h"
#include "mauidia.h"


/******************************************************************************
 * Constants
 *****************************************************************************/
#define MEA_SRH_ITEM_COUNT   3   /*!< Concurrent routing operations */
#ifdef __MMI_MMS_BGSR_SUPPORT__
extern MmsMsgId downloadMsgId;
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
/******************************************************************************
 * Data-types
 *****************************************************************************/

/*! \enum MeaSrhOp
 *  Contains the different types of signal routing this module can handle
 */
typedef enum
{
    MEA_SRH_GET_MSG_INFO,   /*!< Get message info operation */
    MEA_SRH_MAKE_CALL       /*!< Make call operation */
}MeaSrhOp;

/*! \struct MeaSrhItem
 *  The information kept for every ongoing operation
 */
typedef struct 
{
    MeaStateMachine         fsm;            /*!< The callback FSM */
    int                     signal;         /*!< The callback signal */
    MeaSrhOp                operation;      /*!< The current operation type */
    MSF_UINT16              id;             /*!< Current operation id-number */
}MeaSrhItem;

/******************************************************************************
 * Static variables
 *****************************************************************************/
MeaSrhItem   *srhItems[MEA_SRH_ITEM_COUNT];     /* Slots for open operations */

/******************************************************************************
 * Prototypes
 *****************************************************************************/
static MSF_UINT16 srhAddItem(MeaStateMachine fsm, int signal, MeaSrhOp op);
static void srhDeleteItem(int index);
static MeaSrhItem *srhFindItem(MeaSrhOp op, int id);

/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*! \brief Initiates the signal routing handler
 *
 *****************************************************************************/
void meaSrhInit(void)
{
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
        MASRH_B9585B0261FF75D520BCAF9242AC360C, "(%s) (%d) Initiating the signal router.\n", __FILE__, __LINE__));
    memset(srhItems, 0, sizeof(MeaSrhItem*)*MEA_SRH_ITEM_COUNT);
} /* meaSrhInit */

/*! \brief Terminates the signal routing handler.
 *
 *****************************************************************************/
void meaSrhTerminate(void)
{
    int i;
    for (i=0; i < MEA_SRH_ITEM_COUNT; i++)
    {
        /* Delete all open items */
        srhDeleteItem(i);
    }
    memset(srhItems, 0, sizeof(MeaSrhItem*)*MEA_SRH_ITEM_COUNT);
} /* meaSrhTerminate */

/*!\brief Adds an item to the list of operations
 *
 * \param fsm The callback FSM.
 * \param signal The callback signal.
 * \param op The current operation.
 *****************************************************************************/
static MSF_UINT16 srhAddItem(MeaStateMachine fsm, int signal, MeaSrhOp op)
{
    int i;
    for (i = 0; i < MEA_SRH_ITEM_COUNT; i++)
    {
        /* Find an empty slot */
        if (NULL == srhItems[i])
        {
            /* Create a new item */
            MEA_CALLOC(srhItems[i], sizeof(MeaSrhItem));
            srhItems[i]->fsm        = fsm;
            srhItems[i]->signal     = signal;
            srhItems[i]->operation  = op;
            srhItems[i]->id         = (MSF_UINT16)(((unsigned int)fsm) | 
                ((unsigned int)signal << 8));
            return srhItems[i]->id;
        }
    }
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
        MASRH_3E6E7F6AF8E8349604641229C4D5BD5D, "(%s) (%d) the number of concurrent signal routing operations are to"
        "low!\n", __FILE__, __LINE__));
    MEA_TERMINATE;
    return 0;
} /* srhAddItem */

/*! \brief Deletes a signal routing item from a specific "slot"
 *
 * \param index The index to delete starting from 0.
 *****************************************************************************/
static void srhDeleteItem(int index)
{
    if (NULL != srhItems[index])
    {
        MEA_FREE(srhItems[index]);
        srhItems[index] = NULL;
    }
} /* srhDeleteItem */

/*! \brief Extracts an operation from the list of ongoing operations.
 *
 * \param op The operation to find.
 * \param id The id of the operation to find or zero if irrelevant
 * \return The current operation, the caller is responsible for de-allocating 
 *         the data.
 *****************************************************************************/
static MeaSrhItem *srhFindItem(MeaSrhOp op, int id)
{
    int i;
    MeaSrhItem *ret;
    for (i = 0; i < MEA_SRH_ITEM_COUNT; i++)
    {
        /* Find matching slot, only match on id if non-zero */
        if ((NULL != srhItems[i]) && (op == srhItems[i]->operation) &&
            ((0 == id) || (id == srhItems[i]->id)))
        {
            ret = srhItems[i];
            srhItems[i] = NULL; /* Assume caller deallocates this entry */
            return ret;
        }
    }
    return NULL;
} /* srhFindItem */

/*! \brief Calls the MMS interface function #MMSif_getMessageInfo
 *
 * \param fsm The callback FSM.
 * \param signal The callback signal.
 * \param msgId The message identity of the message to get information about.
 *****************************************************************************/
void meaSrhGetMessageInfo(MeaStateMachine fsm, int signal, MmsMsgId msgId)
{
    (void)srhAddItem(fsm, signal, MEA_SRH_GET_MSG_INFO);
    /* Call the interface function */
    MMSif_getMessageInfo(MSF_MODID_MEA, msgId);
#ifdef __MMI_MMS_BGSR_SUPPORT__
    downloadMsgId = msgId;
#endif /*__MMI_MMS_BGSR_SUPPORT__*/    
} /* meaSrhGetMessageInfo */

/*! \brief Handles the response signal for the MMSif_getMessageInfo operation.
 *
 * \param list The response data.
 *****************************************************************************/
void meaSrhGetMessageInfoRsp(const MmsListOfProperties *list)
{
    MeaSrhItem *item;
    MmsMessageFolderInfo *fInfo = NULL;
    /* Get the callback data */
    item = srhFindItem(MEA_SRH_GET_MSG_INFO, 0);
    
    if (NULL != item)
    {
        if ((NULL != list) && (1 == list->noOfElements))
        {
            /* Copy the signal data */
            fInfo = MEA_ALLOC(sizeof(MmsMessageFolderInfo));
            memcpy(fInfo, &(list->msgPropertyList[0].msgFolderInfo), sizeof(MmsMessageFolderInfo));
        }
        /* Send the response */
        (void)MEA_SIGNAL_SENDTO_P(item->fsm, item->signal, fInfo);
        /*lint -e{774} */
        MEA_FREE(item);
    }
}

/*!
 * \brief Calls the MSF Telephone API function MSF_TEL_MAKE_CALL. 
 *        Result is passed as TRUE/FALSE in u_param1 using the requested 
 *        return signal. Multiple calls using the same callback FSM/signal 
 *        combination is not possible!
 * 
 * \param fsm       The callback FSM.
 * \param signal    The callback signal.
 * \param number    The number to call
 * \param id        The id of this call operation
 *****************************************************************************/
void meaSrhMakeCall(MeaStateMachine fsm, int signal, const char *number)
{
/*    MSF_TEL_MAKE_CALL((MSF_UINT8)MSF_MODID_MEA, 
        srhAddItem(fsm, signal, MEA_SRH_MAKE_CALL), number); */
    extern void wtai_telMakeCall(MSF_UINT8 modId, MSF_UINT16 telId, const char *number);
    wtai_telMakeCall((MSF_UINT8)MSF_MODID_MEA, srhAddItem(fsm, signal, MEA_SRH_MAKE_CALL), number);
} /* meaSrhMakeCall */

/*!
 * \brief Handles the response signal for the MSF_TEL_MAKE_CALL operation
 * 
 * \param callRsp   The response data
 *****************************************************************************/
void meaSrhMakeCallRsp(const msf_tel_make_call_resp_t *callRsp)
{
    MeaSrhItem *item;
    MSF_BOOL ret;

    /* Get the callback data */
    item = srhFindItem(MEA_SRH_MAKE_CALL, 
        (NULL != callRsp) ? callRsp->telId : 0);

    /* Analyze the callback data */
    ret = (NULL != item) && (NULL != callRsp) && 
        (MSF_TEL_OK == callRsp->result);

    /* Send the response */
    if (NULL != item)
    {
        (void)MEA_SIGNAL_SENDTO_U(item->fsm, item->signal, (unsigned)ret);
    }

    /* Show dialogs on error */
    if ((FALSE == ret) && (NULL != callRsp))
    {
#ifndef WAP_SUPPORT //wtai and MMI would show error msg
        switch (callRsp->result)
        {
        case MSF_TEL_ERROR_CALLED_PARTY_IS_BUSY:
            /* The called party is busy*/
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_CALL_BUSY), 
                MEA_DIALOG_ERROR);    
            break;
        case MSF_TEL_ERROR_NETWORK_NOT_AVAILABLE:
            /*The network is not available.*/
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_CALL_NO_NETWORK), 
                MEA_DIALOG_ERROR);    
            break;
        case MSF_TEL_ERROR_CALLED_PARTY_NO_ANSWER:
            /*The called party did not answer.*/
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_CALL_NO_ANSWER), 
                MEA_DIALOG_ERROR);    
            break;
        case MSF_TEL_ERROR_INVALID:
            /* The number parameter is not a phone-number */
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_CALL_NOT_A_NUMBER), 
                MEA_DIALOG_ERROR);    
            break;

        case MSF_TEL_ERROR_UNSPECIFIED:
        default:
            /* Unspecified error.*/
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_CALL_ERROR), 
                MEA_DIALOG_ERROR);    
            break;
        } /* switch */
#endif /* WAP_SUPPORT */
    }
    else if (NULL == callRsp)
    {
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_CALL_ERROR), 
            MEA_DIALOG_ERROR);    
    } /* if */

    MEA_FREE(item);
} /* meaSrhMakeCallRsp */



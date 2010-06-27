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

/* \file mamcr.h
 * \brief Message Creation FSM
 */

#ifndef _MAMCR_H_
#define _MAMCR_H_

/******************************************************************************
* Constants
*****************************************************************************/

/*!\enum MeaMcrSignalId
 * Signals for the MCR FSM */
typedef enum 
{
    /*! Creates a message
     * p_param = pointer to a MeaCreateMessageSignal data-structure
     */
    MEA_SIG_MCR_CREATE_MESSAGE,

    /*! A delayed file operation can be retrieved again
     *
     */
    MEA_SIG_MCR_FILE_NOTIFY,

    /*! 
     *  Execution can continue again
     */
    MEA_SIG_MCR_CONTINUE,

    /*! An ASIO read operation has finished
     *  u_param1 = result, see #MeaAsioResult
     *  u_param2 = bytes read
     */
    MEA_SIG_MCR_ASIO_READ_RSP,

    /*! An ASIO write operation has finished
     *  u_param1 = result, see #MeaAsioResult
     */
    MEA_SIG_MCR_ASIO_WRITE_RSP,

    /*! Handling of "create message" response from the MMS Service
     *
     * u_param1 = result
     * u_param2 = msgId
     */
    MEA_SIG_MCR_CREATE_MSG_RESPONSE,

    /*! Handling of "create message done" response from the MMS Service
     *
     * u_param1 = result
     * u_param2 = msgId
     */
	MEA_SIG_MCR_CREATE_MSG_READ_MO_FINISHED,
    MEA_SIG_MCR_CREATE_MSG_DONE_RESPONSE

} MeaMcrSignalId;

/*!\enum MeaMcrResult 
 * Response signal data for message creation */
typedef enum
{
    MEA_MCR_OK,             /*!< The message was created successfully */
    MEA_MCR_TOO_MANY_MSG,
    MEA_MCR_STORAGE_FULL,
    MEA_MCR_FAILED,         /*!< Failed to create the message */
    MEA_MCR_CLEANUP_SILENT, /*!< Only used internally */
    MEA_MCR_WAIT_RSP,       /*!< Only used internally */
    MEA_MCR_DELAYED,        /*!< Only used internally */
    MEA_MCR_DONE            /*!< Only used internally */
}MeaMcrResult;

/******************************************************************************
 * Data-types
 *****************************************************************************/

/*!\struct MeaCreateMessageSignal
 * \brief Data-structure used when creating a message.
 */
typedef struct 
{
    MeaStateMachine fsm;         /*!< FSM to send response to */
    int             retSig;      /*!< The response signal */
    MeaMessage      *message;    /*!< The message to send */
    /* Information about original message */
    MmsFileType     origFileType;/*!< File type of original message */
    MmsMsgId        origMsgId;   /*!< The original msg if relevant */
    MSF_BOOL        del;         /*!< Whether to delete the original message 
                                      after successful creation of a new one */
    MmsFolderType   folder;      /*!< The folder to save the message in */
    MSF_BOOL        forwardMode; /*!< Tells if this is a forward operation */
}MeaCreateMessageSignal;

/******************************************************************************
 * Defines 
 *****************************************************************************/

/******************************************************************************
 * Prototype declarations 
 *****************************************************************************/

void meaMcrInit(void); 
void meaMcrTerminate(void);
void meaCreateMessage(MeaStateMachine fsm, unsigned int retSig, MeaMessage *msg, 
    MmsMsgId origId, MSF_BOOL del, MmsFolderType folder, 
    MmsFileType origFileType, MSF_BOOL forward);

#endif /* _MAMCR_H_ */



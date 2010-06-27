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

/* \file macrh.c
 * \brief Content routing handler.
 */

/* MSF */
#include "msf_log.h"    /* MSF: Signal logging */ 
#include "msf_int.h"
#include "msf_core.h"
#include "msf_mem.h"
#include "msf_pipe.h"
#include "msf_lib.h"    /* MSF: ANSI Standard libs allowed to use */

/* MMS */
#include "mms_def.h"
#include "mmsl_if.h"

/* MEA */
#include "mea_cfg.h"
#include "mea_def.h"
#include "mea_rc.h"
#include "macrh.h"
#include "maintsig.h"
#include "mamem.h"
#include "maasync.h"
#include "macore.h"

/******************************************************************************
 * Constants
 *****************************************************************************/

/*! The pipe-name */
#define MEA_PIPE_NAME "mea-crh-pipe"

/*! The length of a integer expressed as a string */
#define MEA_CRH_INTEGER_LENGTH      9

/*! Buffer size when read from file and writing to pipe */
#define MEA_CRH_BUFFER_SIZE         512

/*! \enum MeaCrhState
 *  Defines whether the CRH are in init or processing state */
typedef enum
{
    MEA_CRH_STATE_INIT,    /* !< Collecting information */
    MEA_CRH_STATE_PROCESS  /* !< Reading a body-part and writing to a pipe */
}MeaCrhState;

/*! \enum MeaCrhPipeResult
 *  Result codes when writing to the pipe */
typedef enum
{
    MEA_CRH_TERMINATE,       /* !< Internal termination */
    MEA_CRH_WRITE_ERROR,     /* !< Failed to write to pipe */
    MEA_CRH_WRITE_DONE,      /* !< Done writing to the pipe */
    MEA_CRH_WRITE_MORE_DATA,  /* !< More data is needed in order to write more 
                                    to the pipe */
    MEA_CRH_PIPE_DELAYED     /* !< Waiting for a pipe notify */
}MeaCrhPipeResult;

/******************************************************************************
 * Data-types
 *****************************************************************************/
/*! \struct CrhRequest
 *  Content routing request data */
typedef struct
{
    MeaCrhState    state;
    unsigned char  buffer[MEA_CRH_BUFFER_SIZE];
    int            sizeToWrite;
    int            hPipe;
    int            writePos;
    MeaCrhBodyPart *bodyPartToRead;
    MmsMsgHandle    msgHandle;    /* !< Message handle using the MMS lib  */
    MmsTransactionHandle transactionHandle; /* !< Transaction handle when using
                                                  the MMS lib */
    MmsGetHeader getHead;
}CrhRequest;

/******************************************************************************
 * Static variables
 *****************************************************************************/

static CrhRequest   *crhInstance;
static int          sequenceNumber; 

/******************************************************************************
 * Function prototypes
 *****************************************************************************/

static void  crhInitContentRouting(char *fileName);
static void  crhMain(MeaSignal *sig);
static int   crhCreateInstance(void);
static void  crhCleanupInstance(int result);
static MeaCrhPipeResult crhWriteToPipe(void);
static void  crhPipeNotify(MSF_INT32 handle, MSF_INT16 eventType);
static void  crhReadBodyPart(CrhRequest *req);
static int   crhGetHeader(void);

/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*!
 *\brief Initiates the content routing handler
 *
 *****************************************************************************/

void meaCrhInit(void)
{
    meaSignalRegisterDst(MEA_CRH_FSM, crhMain);
    crhInstance = NULL;
    sequenceNumber = 0;
}

/*!
 *\brief Terminates the content routing handler
 *
 *****************************************************************************/

void meaCrhTerminate(void)
{
    /* Remove any instance data */
    crhCleanupInstance(MEA_CRH_TERMINATE);
    
    meaSignalDeregister(MEA_CRH_FSM);
}

/*!
 *\brief Signal handler for the content routing FSM.
 *
 * \param sig The signal received.
 *****************************************************************************/

static void crhMain(MeaSignal *sig)
{
    if (NULL == sig)
    {
        meaPanic(TRUE);
        return;
    }
    if ((sig->type != MEA_SIG_CRH_START) && (NULL == crhInstance))
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MACRH_40161465EE234C2892643D1BC846B15A, "(%s) (%d) No instance!\n", __FILE__, __LINE__));
        return;
    }
    switch (sig->type)
    {
    case MEA_SIG_CRH_START:
        if (!crhCreateInstance())
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MACRH_416E055D9FBD63FD20D07D4FB5143070, "(%s) (%d) failed to create instance\n", __FILE__, __LINE__));
            /* Delete signal data */
            MEA_FREE(sig->p_param);
            sig->p_param = NULL;
        }
        /* Init state */
        crhInstance->state = MEA_CRH_STATE_INIT;
        /* Copy signal data */
        crhInstance->bodyPartToRead = (MeaCrhBodyPart *)sig->p_param;
        sig->p_param = NULL;
        crhInitContentRouting(crhInstance->bodyPartToRead->fileName);
        break;
    case MEA_SIG_CRH_FILE_NOTIFY:
        switch (crhInstance->state)
        {
        case MEA_CRH_STATE_INIT:
            /* The previous get header was delayed, try again */
            if (crhGetHeader())
            {
                (void)MEA_SIGNAL_SENDTO(MEA_CRH_FSM, 
                    MEA_SIG_CRH_READ_BODYPART);
                crhInstance->state = MEA_CRH_STATE_PROCESS;
            }
            break;
        case MEA_CRH_STATE_PROCESS:
            /* The previous get body-part was delayed, try again */
            crhReadBodyPart(crhInstance);
            break;
        }
        break;
    case MEA_SIG_CRH_READ_BODYPART:
        /* Read body-part */
        crhReadBodyPart(crhInstance);
        break;
    case MEA_SIG_CRH_CANCEL:
        /* Cleanup if the operation was cancelled */
        crhCleanupInstance(MEA_CRH_VIEW_ATTACH_OK);
        break;
    case MEA_SIG_CRH_NOTIFY:
        /* */
        crhPipeNotify((MSF_INT32)sig->u_param1, (MSF_INT16)sig->i_param);
        break;
    case MEA_SIG_CRH_SEND_RSP:
        /* Check wheter the content can be handled */
        if (MSF_CONTENT_STATUS_FAILED == sig->u_param1)
        {
            /* End content routing */
            crhCleanupInstance(MEA_CRH_VIEW_ATTACH_NO_HANDLER);
        }
        else
        {
            /* Open message */ 
            if (MMS_RESULT_OK != MMSlib_messageOpen(MSF_MODID_MEA, 
                crhInstance->bodyPartToRead->mmsMsgId, 
                crhInstance->bodyPartToRead->fileType , &crhInstance->msgHandle))
            {
                crhCleanupInstance(MEA_CRH_VIEW_ATTACH_ERROR);
                break;
            }
            /* Open transaction */
            if (MMS_RESULT_OK != MMSlib_transactionOpen(MSF_MODID_MEA, 
                &(crhInstance->transactionHandle)))
            {
                crhCleanupInstance(MEA_CRH_VIEW_ATTACH_ERROR);
                break;
            }

            /* Show progress meter */
            /*(void)meaPmViewShow(MEA_STR_ID_SHOW_ATTACH_PROGRESS, FALSE,
                TRUE, MEA_CRH_FSM, MEA_SIG_CRH_CANCEL);*/
            /* Get header */
            if (crhGetHeader())
            {
                /* If the header was successfully retrieved start to read
                   the requested bodypart */
                (void)MEA_SIGNAL_SENDTO(MEA_CRH_FSM, MEA_SIG_CRH_READ_BODYPART);
                crhInstance->state = MEA_CRH_STATE_PROCESS;
            }
        }
        break;
    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
            MACRH_39E08AA63293875A5025796ECF3C5CBA, "(%s) (%d) unhandled signal\n", __FILE__, __LINE__));
        break;            
    }
    /* Deallocate the signal */
    meaSignalDelete(sig);
}

/*!
 * \brief Initiates data-structures for a content routing session
 *
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/

static int crhCreateInstance(void)
{
    /* Check that no operation is in progress */
    if (NULL != crhInstance)
    {
        return FALSE;
    }
    /* Allocate memory */
    crhInstance = MEA_ALLOC(sizeof(CrhRequest));
    memset(crhInstance, 0, sizeof(CrhRequest));
    /* Setup initial data */
    crhInstance->state       = MEA_CRH_STATE_INIT;
    crhInstance->hPipe       = -1;
    crhInstance->sizeToWrite = 0;
    crhInstance->writePos    = 0;
    return TRUE;
}

/*!
 * \brief Cleanup of the current content routing request.
 *
 * \param result The result that is sent back to the originating fsm, if
 *               the result is MEA_CRH_TERMINATE no signal is sent back.
 *****************************************************************************/
static void crhCleanupInstance(int result)
{
    if (NULL == crhInstance)
    {
        return;
    }
    else
    {
        if (MEA_CRH_TERMINATE != result)
        {
            (void)MEA_SIGNAL_SENDTO_U(
                (MeaStateMachine)crhInstance->bodyPartToRead->fsm, 
                crhInstance->bodyPartToRead->signal, (unsigned)result);
        }
        if (crhInstance)
        {
            if (crhInstance->hPipe != -1)
            {
                (void)MSF_PIPE_CLOSE(crhInstance->hPipe);
                crhInstance->hPipe = -1;
            }
            if (NULL != crhInstance->transactionHandle)
            {
                (void)MMSlib_transactionClose(MSF_MODID_MEA, 
                    &crhInstance->transactionHandle);
                crhInstance->transactionHandle = NULL;
            }


            if (NULL != crhInstance->msgHandle)
            {
                (void)MMSlib_messageClose(MSF_MODID_MEA, &crhInstance->msgHandle);
                crhInstance->msgHandle = NULL;
            }
            MEA_FREE(crhInstance->bodyPartToRead);
            crhInstance->bodyPartToRead = NULL;
            MEA_FREE(crhInstance);
            crhInstance = NULL;
        }
        /* Delete progress meter */
        /*meaPmViewRemove();*/
    }
}

/*!
 * \brief Read the header of the message to retrieve a body-part from
 * \param req The content routing request data
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
static void crhReadBodyPart(CrhRequest *req)
{
    unsigned long size = MEA_CRH_BUFFER_SIZE;
    MmsResult res;
    /* Check if the transaction has been opened */
    if (NULL == req->transactionHandle)
    {
        /* Open transaction */
        if (MMS_RESULT_OK != MMSlib_transactionOpen(MSF_MODID_MEA, 
            &req->transactionHandle))
        {
            crhCleanupInstance(MEA_CRH_VIEW_ATTACH_ERROR);
            return;
        }
    }
    /* Read body-part */
    res = MMSlib_getBodyPart(MSF_MODID_MEA, req->bodyPartToRead->index, 
        req->buffer, &size, &req->msgHandle, 
        &req->transactionHandle);
    /*lint -e{788} */
    switch (res)
    {
    case MMS_RESULT_OK:
    case MMS_RESULT_BUFFER_FULL:
        req->bodyPartToRead->readPos += size;
        req->sizeToWrite = (signed)size;
        switch (crhWriteToPipe())
        {
        case MEA_CRH_WRITE_DONE:
                /* Done */
                crhCleanupInstance(MEA_CRH_VIEW_ATTACH_OK);
            break;
        
        case MEA_CRH_WRITE_ERROR:
                /* Failed */
                crhCleanupInstance(MEA_CRH_VIEW_ATTACH_ERROR);
            break;
        case MEA_CRH_WRITE_MORE_DATA:
            (void)MEA_SIGNAL_SENDTO(MEA_CRH_FSM, MEA_SIG_CRH_READ_BODYPART);
            break;

		case MEA_CRH_PIPE_DELAYED:
            /* A pipe notify is generated when the pipe can be read again */
			break;

        default:
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
                MACRH_D5ACEAD4EA5BF3C5AA3960BD4D04ABCE, "(%s) (%d) Unhandled pipe result\n", __FILE__, __LINE__));
            return;
        }
        break;
    case MMS_RESULT_DELAYED:
        meaAsyncRegister(MMSlib_getFileHandle(MSF_MODID_MEA, 
            req->transactionHandle), 
            MEA_CRH_FSM, MEA_SIG_CRH_READ_BODYPART, 0);
        break;
    default:
        /* Major fault */
        crhCleanupInstance(MEA_CRH_VIEW_ATTACH_ERROR);
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
            MACRH_AAD39B378E27C013B68735CA95448AD8, "(%s) (%d) erroneous read result\n", __FILE__, __LINE__));
        break;
    }
}

/*!
 * \brief Read the header of the message to retrieve a bodypart from.
 *
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
static int crhGetHeader()
{
    MmsResult res;
    struct MmsBodyInfoStruct *bl;

    res = MMSlib_getMessageHeader(MSF_MODID_MEA, &crhInstance->getHead, 
        &crhInstance->msgHandle, &crhInstance->transactionHandle);
    /*lint -e{788} */
    switch(res)
    {
    case MMS_RESULT_DELAYED:
        meaAsyncRegister(MMSlib_getFileHandle(MSF_MODID_MEA,
            &(crhInstance->transactionHandle)), MEA_CRH_FSM, 
            MEA_SIG_CRH_FILE_NOTIFY, 0);
        return FALSE;
    case MMS_RESULT_BUFFER_FULL:
    case MMS_RESULT_OK:
        bl = &(crhInstance->getHead.bodyInfoList);
        while((bl != NULL) && 
            (crhInstance->bodyPartToRead->index != bl->number))
        {
            bl = bl->next;
        }
        if (bl != NULL)
        {
            crhInstance->bodyPartToRead->totalSize = bl->size;
        }
        else
        {
            return FALSE;
        }
        /* The header is only needed in order to read body-parts later */    
        MMSlib_freeMmsGetHeader(MSF_MODID_MEA, 
            &crhInstance->getHead);
        /* Close transaction */
        (void)MMSlib_transactionClose(MSF_MODID_MEA, 
            &crhInstance->transactionHandle);
        crhInstance->transactionHandle = NULL;
        return TRUE;
    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MACRH_66775C6E694AC4DBEB7555436903960E, "(%s) (%d) unhandled result code from MMSlib_getMessageHeader"));
        break;
    }
    return FALSE;
}

/*! \brief Initiates content routing. A content routing request is sent 
 *         and a pipe is created.
 * 
 *****************************************************************************/
static void crhInitContentRouting(char *fileName)
{
    /* Bug in Content Mgr prevents using same pipe name */
    msf_content_data_t  contentData;
    char pipeName[sizeof(MEA_PIPE_NAME)+MEA_CRH_INTEGER_LENGTH];

    sprintf( pipeName, "%s%d", MEA_PIPE_NAME, ++sequenceNumber);
    
    if ((crhInstance->hPipe = MSF_PIPE_CREATE(MSF_MODID_MEA, pipeName)) > -1)
    {
        contentData.routingFormat        = MSF_ROUTING_TYPE_MIME;
        contentData.routingIdentifier    = 
            crhInstance->bodyPartToRead->contentType;
        contentData.contentUrl        = fileName;
        contentData.contentSource     = pipeName;
        contentData.contentHeaders    = 
            crhInstance->bodyPartToRead->contentHeaders;
        contentData.networkAccountId  = 0;
        contentData.contentParameters = NULL;
        contentData.contentDataType   = MSF_CONTENT_DATA_PIPE;
        contentData.contentDataLength = 0;
        contentData.contentData       = NULL;
        /* Send content to the router id=0 */
        MSF_CONTENT_SEND(MSF_MODID_MEA, MSF_MODID_MSM, NULL, 
            &contentData, 1, MEA_CRH_SEND_ID);       
    } /* if */
}

/*!\brief Handles a pipe notification.
 *
 * \param handle The handle of the pipe generated the notification.
 * \param eventType The type of event that was generated.
 *****************************************************************************/
static void crhPipeNotify(MSF_INT32 handle, MSF_INT16 eventType)
{
    if (crhInstance->hPipe != handle)
    {
        /* Wrong pipe?!?!?! */
        return;
    }
    
    switch (eventType)
    {
    case MSF_PIPE_EVENT_WRITE:
        /*lint -e{788} */
        switch (crhWriteToPipe())
        {
        case MEA_CRH_WRITE_DONE:
            /* Failed or done */
            crhCleanupInstance(MEA_CRH_VIEW_ATTACH_OK);
            break;
        case MEA_CRH_WRITE_ERROR:
            /* Failed*/
            crhCleanupInstance(MEA_CRH_VIEW_ATTACH_ERROR);
            break;
        case MEA_CRH_WRITE_MORE_DATA:
            crhReadBodyPart(crhInstance);
            break;
        default:
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                MACRH_A5B0F1DFA826CF62B2DA7FFAB4672C76, "(%s) (%d) erroneous pipe event\n", __FILE__, __LINE__));
            break;
        }
        break;

       
    case MSF_PIPE_EVENT_CLOSED:
        /* We are done */
        crhCleanupInstance(MEA_CRH_VIEW_ATTACH_OK);
        break;
    default:
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MACRH_A5B0F1DFA826CF62B2DA7FFAB4672C76, "(%s) (%d) erroneous pipe event\n", __FILE__, __LINE__));
        break;
    }
}

/*!
 * \brief Writes data to the pipe
 *
 * \return See #MeaCrhPipeResult.
 *****************************************************************************/
static MeaCrhPipeResult crhWriteToPipe()
{
    int bytesWritten = 1;
    
    while (crhInstance->writePos < crhInstance->sizeToWrite && 
        bytesWritten > 0)
    {
        bytesWritten = MSF_PIPE_WRITE(crhInstance->hPipe, 
            &crhInstance->buffer[crhInstance->writePos], 
            crhInstance->sizeToWrite - crhInstance->writePos);
        
        if (bytesWritten > 0)
        {
            crhInstance->writePos += bytesWritten;
        }
        
    } /* while */

    if (bytesWritten == MSF_PIPE_ERROR_BAD_HANDLE)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MACRH_E27A545C478A9B8189C14618FFCC6FC3, "%s(%d): Bad handle\n", 
            __FILE__, __LINE__));
        return MEA_CRH_WRITE_ERROR;
    }
    else if (bytesWritten == MSF_PIPE_ERROR_CLOSED)
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                     MACRH_443B91882A56DE3C15FE6CC2C0785869, "%s(%d): Pipe closed at read end\n", 
                     __FILE__, __LINE__));
        return MEA_CRH_WRITE_ERROR;
    }
    else if (crhInstance->bodyPartToRead->totalSize == 
        (unsigned int)(crhInstance->bodyPartToRead->readPos))
    {
        /* The operation is performed ok */
        return MEA_CRH_WRITE_DONE;
    }
    else if (crhInstance->sizeToWrite == 
            crhInstance->writePos)
    {
        crhInstance->writePos = 0;
        return MEA_CRH_WRITE_MORE_DATA;
    }
    else if (bytesWritten == MSF_PIPE_ERROR_DELAYED)
    {
        /* More work to do later */
        (void)MSF_PIPE_POLL(crhInstance->hPipe);
        return MEA_CRH_PIPE_DELAYED;
    }
    
    return MEA_CRH_WRITE_ERROR;
}



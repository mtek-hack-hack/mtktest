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
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2003.
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
 ******************************************************************************
 *
 * File:            $Workfile:   sapipe.c  $
 *  
 * Date:            $Date:   May 17 2005 03:06:22  $
 *
 * Revision:        $Revision:   1.9  $
 *
 * Description:     Handling of links. 
 *
 *****************************************************************************/

/*! \file salnk.c
 */

/* MSF */
#include "msf_log.h"
#include "msf_lib.h"
#include "msf_mem.h"
#include "msf_cmmn.h"
#include "msf_pipe.h"

/* SMA */
#include "sma_cfg.h"
#include "saintsig.h"
#include "samem.h"
#include "saasync.h"
#include "sapipe.h"


/******************************************************************************
 * Defines
 *****************************************************************************/

/******************************************************************************
 * Types
 *****************************************************************************/

typedef enum
{
	SMA_PIPE_OK,
	SMA_PIPE_DELAYED,
	SMA_PIPE_ERROR
} SmaPipeResult;

typedef struct 
{
	int pipeHandle;
	char *pipeName;
}PipeInstance;


typedef struct 
{
	SmaAsyncOperationHandle asioHandle;
	char *buffer;
	MSF_UINT32 readPos;
	MSF_UINT32 leftToRead;
	char *writePos;
	MSF_UINT32 leftToWrite;
	MSF_UINT32 bufferSize;
	PipeInstance *pipeInst;
	SmaStateMachine retFsm;
	MSF_UINT32 retSig;
    MSF_BOOL sendResult;
} CopyInstance;

/******************************************************************************
 * Constants
 *****************************************************************************/
static PipeInstance pipeInst;
static CopyInstance copyInst;

/******************************************************************************
 * Prototypes
 *****************************************************************************/
static void sigHandler(SmaSignal *sig);
static MSF_BOOL handleReadOperation(CopyInstance *instance, int bytesRead, 
	SmaAsioResult result);
static SmaPipeResult writeToPipe(CopyInstance *instance);
static void freeCopyInstance(CopyInstance *instance);
static void handlePipeNotify(MSF_INT32 handle, MSF_INT16 eventType);

/******************************************************************************
 * Function implementations
 *****************************************************************************/

/*!
 * \brief Initialize the SMA_FSM_PIPE.
 *****************************************************************************/
void smaPipeInit(void)
{
    smaSignalRegisterDst(SMA_FSM_PIPE, sigHandler);
   
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
        SAPIPE_B2D23932EBF3893D5CB14E9ED142A185, "SMA_FSM_PIPE: initialized\n"));
} /* smaPipeInit */

/*!
 * \brief Terminate the M_FSM_CORE_MAIN FSM.
 *****************************************************************************/
void smaPipeTerminate(void)
{
	smaSignalDeregister(SMA_FSM_PIPE);
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
        SAPIPE_68D04F6604C7976F571E81336815342D, "SMA_FSM_PIPE: terminated\n"));
} /* smaPipeTerminate */

/*!
 * \brief Signal handler for the SMA_FSM_PIPE.
 *****************************************************************************/
static void sigHandler(SmaSignal *sig)
{
	int bytesRead;
	MSF_UINT32 bytesToRead;
	SmaAsioResult asioResult;

    switch (sig->type)
    {
	case SMA_SIG_PIPE_NOTIFY:
		handlePipeNotify((MSF_INT32)sig->u_param1, (MSF_INT16)sig->u_param2);
		break;
	case SMA_SIG_PIPE_FILE_READ_RSP:
		/* async readopearation is complete */
		bytesRead = (int)sig->u_param2;
		asioResult = (SmaAsioResult)sig->u_param1;

		if (!handleReadOperation(&copyInst, (int)bytesRead, asioResult))
        {
			/* read operation failed - ERROR */
			/* send success signal */
			(void)SMA_SIGNAL_SENDTO_I(SMA_FSM_PIPE, SMA_FSM_PIPE_COPY_COMPLETE, FALSE);
		}
		else
		{
			/* read operation successfull */
			/* write data to pipe */
			copyInst.writePos = copyInst.buffer;
			copyInst.leftToWrite = (MSF_UINT32)bytesRead;
			(void)SMA_SIGNAL_SENDTO(SMA_FSM_PIPE, SMA_SIG_PIPE_WRITE_PIPE);
		}
		break;
	case SMA_SIG_PIPE_WRITE_PIPE:
		/* write data to pipe */
		switch (writeToPipe(&copyInst))
		{
		case SMA_PIPE_OK:
			if (copyInst.leftToRead > 0)
			{
				/* more to read */
				bytesToRead = copyInst.bufferSize;
				if (copyInst.leftToRead < copyInst.bufferSize)
				{
					bytesToRead = copyInst.leftToRead;
				} /* if */
				smaAsyncRead(copyInst.asioHandle, (MSF_INT32)copyInst.readPos,
					copyInst.buffer, bytesToRead);
			}
			else
			{
				/* send success signal */
				(void)SMA_SIGNAL_SENDTO_I(SMA_FSM_PIPE, 
					SMA_FSM_PIPE_COPY_COMPLETE, TRUE);
			} /* if */
			break;
		case SMA_PIPE_DELAYED:
			/* noting to do, just wait for signal from MSF */
			break;
		case SMA_PIPE_ERROR:
		default:
			/* send error signal */
			(void)SMA_SIGNAL_SENDTO_I(SMA_FSM_PIPE, 
					SMA_FSM_PIPE_COPY_COMPLETE, TRUE);
			break;
		} /* switch */
		break;
	case SMA_FSM_PIPE_COPY_COMPLETE:
		if (copyInst.sendResult)
        {
            (void)SMA_SIGNAL_SENDTO_I(copyInst.retFsm, (int)copyInst.retSig, sig->i_param);
        } /* if */
		freeCopyInstance(&copyInst);
		break;
	default:
		MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA,
            SAPIPE_E9246D38A5CC29619489D058E1DD44AB, "(%s) (%d) Erroneous signal recieved in SMA_FSM_PIPE:sigHandler\n", 
            __FILE__, __LINE__));
        break;
    } /* switch */
	smaSignalDelete(sig);
} /* sigHandler */

static void freeCopyInstance(CopyInstance *instance)
{
	if (instance == NULL)
	{
		return;
	} /* if */
	
    if (instance->pipeInst != NULL)
    {
#ifdef WAP_SUPPORT
	    if (instance->pipeInst->pipeHandle >= 0)
#else
	    if (instance->pipeInst->pipeHandle > 0)
#endif /* WAP_SUPPORT */
	    {
		    /* close pipe */
		    /* nothing to do if close failes */
		    (void)MSF_PIPE_CLOSE(instance->pipeInst->pipeHandle);
#ifdef WAP_SUPPORT
		    instance->pipeInst->pipeHandle = -1;
#else
		    instance->pipeInst->pipeHandle = 0;
#endif /* WAP_SUPPORT */
	    } /* if */
        
        if (instance->pipeInst->pipeName != NULL)
        {
            SMA_FREE(instance->pipeInst->pipeName);
            instance->pipeInst->pipeName = NULL;
        }
    }

	if (instance->buffer)
	{
		SMA_FREE(instance->buffer);
	} /* if */
	
	if (instance->asioHandle != 0)
	{
		smaAsyncOperationStop(&(instance->asioHandle));
	} /* if */
} /* freeCopyInstance */


/*!
 * \brief Creates a named pipe
 * \param pipeName the name for the pipe.
 *
 * \return TRUE if creation is successfull, else FALSE
 *****************************************************************************/
MSF_BOOL smaCreatePipeOperation(const char *pipeName)
{
	MSF_BOOL ret;
	if (pipeName == NULL)
	{
		/* unable to create the pipe without a name */
		return FALSE;
	} /* if */

	/* store pipename */
	pipeInst.pipeName = msf_cmmn_strdup(MSF_MODID_SMA, pipeName);
	
	pipeInst.pipeHandle = MSF_PIPE_CREATE(MSF_MODID_SMA, pipeName);

#ifdef WAP_SUPPORT
	if (pipeInst.pipeHandle < 0)
#else
	if (pipeInst.pipeHandle == 0)
#endif /* WAP_SUPPORT */
	{
		/* failed to create the pipe */
		ret = FALSE;
	}
	else 
	{
		ret = TRUE;
	} /* if */
	
	return ret;
} /* smaCreatePipeOperation */


void smaClosePipeOperation(void)
{
	if (pipeInst.pipeName != NULL)
	{
#ifdef WAP_SUPPORT
        MSF_PIPE_CLOSE(pipeInst.pipeHandle);
#endif /* WAP_SUPPORT */
		/* nothing to do if delete failes */
		(void)MSF_PIPE_DELETE(pipeInst.pipeName);
		SMA_FREE(pipeInst.pipeName);
#ifdef WAP_SUPPORT
		pipeInst.pipeHandle = -1;
#else
		pipeInst.pipeHandle = 0;
#endif /* WAP_SUPPORT */
		pipeInst.pipeName = NULL;
	} /* if */
} /* smaDeletePipeOperation */


void smaCopyFileToPipe(const char *fileName, MSF_UINT32 offset, MSF_UINT32 size, 
	MSF_BOOL sendResult, SmaStateMachine retFsm, MSF_UINT32 retSig)
{
	/* save return information */
	copyInst.retFsm = retFsm;
	copyInst.retSig = retSig;
    copyInst.sendResult = sendResult;

	if (size < SMA_MAX_CHUNK_SIZE)
	{
		copyInst.bufferSize = size;
	}
	else
	{
		copyInst.bufferSize = SMA_MAX_CHUNK_SIZE;
	} /* if */

	copyInst.pipeInst = &pipeInst;

	copyInst.buffer = SMA_ALLOC(copyInst.bufferSize);
	memset(copyInst.buffer, 0x00, copyInst.bufferSize);

	copyInst.leftToRead = size;
	copyInst.readPos = offset;
	
	/* initialize async operation */
	copyInst.asioHandle = 
		smaAsyncOperationStart(fileName, SMA_FSM_PIPE, 0L, 
	    SMA_SIG_PIPE_FILE_READ_RSP, SMA_ASYNC_MODE_READ);

	/* start reading data */
	smaAsyncRead(copyInst.asioHandle, (MSF_INT32)copyInst.readPos,
		    copyInst.buffer, copyInst.bufferSize);
} /* smaCopyFileToPipe */


/*!\brief Handles a pipe notification.
 *
 * \param handle The handle of the pipe generated the notification.
 * \param eventType The type of event that was generated.
 *****************************************************************************/
static void handlePipeNotify(MSF_INT32 handle, MSF_INT16 eventType)
{
    if (pipeInst.pipeHandle != handle)
    {
        /* Wrong pipe?!?!?! */
        return;
    }
    
    switch (eventType)
    {
    case MSF_PIPE_EVENT_WRITE:
        (void)SMA_SIGNAL_SENDTO(SMA_FSM_PIPE, SMA_SIG_PIPE_WRITE_PIPE);
        break;
	case MSF_PIPE_EVENT_CLOSED:
        /* Error, if this signal is received, the other side has 
			unexpectedly closed the pipe */
        (void)SMA_SIGNAL_SENDTO_I(SMA_FSM_PIPE, SMA_FSM_PIPE_COPY_COMPLETE, FALSE);
        break;
    default:
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SAPIPE_A5B0F1DFA826CF62B2DA7FFAB4672C76, "(%s) (%d) erroneous pipe event\n", __FILE__, __LINE__));
        break;
    } /* switch */
} /* handlePipeNotify */




/*!
 *\brief Checks the result of the read operation.
 *
 * \param instance Instance information, e.g. information about the 
 *         current transaction.
 * \param bytesRead Number of bytes read in last read operation.
 * \param result Result of the read operation operation
 *
 * \return TRUE if successful, else FALSE
 *****************************************************************************/
static MSF_BOOL handleReadOperation(CopyInstance *instance, 
    int bytesRead, SmaAsioResult result)
{
    MSF_BOOL status = TRUE;
    
    switch(result)
    {
        case SMA_ASIO_RESULT_OK:
        case SMA_ASIO_RESULT_EOF:
            /* write data to file */
            instance->readPos += (MSF_UINT32)bytesRead;
            instance->leftToRead -= (MSF_UINT32)bytesRead;
            status = TRUE;
            break;
        case SMA_ASIO_RESULT_FILE_NOT_FOUND:
        case SMA_ASIO_RESULT_ERROR:
        case SMA_ASIO_RESULT_INSUFFICIENT_PERSISTENT_STORAGE:
            status = FALSE;
            break;
        case SMA_ASIO_RESULT_DELAYED:
            /*lint -fallthrough */
        default:
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA,
                SAPIPE_81C91ED67CDAA0DE61EC86DEA482DD3C, "handleReadOperation invalid result code (%d)\n", 
                result));
            status = FALSE;
    } /* switch */
    return status;
} /* handleReadOperation */



static SmaPipeResult writeToPipe(CopyInstance *instance)
{
	MSF_INT32 bytesWritten = 0;
	SmaPipeResult ret = SMA_PIPE_OK;

	while ((instance->leftToWrite > 0) && (bytesWritten >= 0)) 
    {
        bytesWritten = MSF_PIPE_WRITE(instance->pipeInst->pipeHandle, 
            instance->writePos, (MSF_INT32)instance->leftToWrite);
        
        if (bytesWritten > 0)
        {
            instance->writePos += bytesWritten;
			instance->leftToWrite -= (MSF_UINT32)bytesWritten;
        } /* if */
    } /* while */

	if (bytesWritten == MSF_PIPE_ERROR_BAD_HANDLE)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SAPIPE_E27A545C478A9B8189C14618FFCC6FC3, "%s(%d): Bad handle\n", 
            __FILE__, __LINE__));
        
		ret = SMA_PIPE_ERROR;
    }
    else if (bytesWritten == MSF_PIPE_ERROR_CLOSED)
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                     SAPIPE_443B91882A56DE3C15FE6CC2C0785869, "%s(%d): Pipe closed at read end\n", 
                     __FILE__, __LINE__));
        
		ret = SMA_PIPE_ERROR;
    }
	else if(bytesWritten == MSF_PIPE_ERROR_DELAYED)
	{
		 /* More work to do later */
        (void)MSF_PIPE_POLL(instance->pipeInst->pipeHandle);
		ret = SMA_PIPE_DELAYED;
	}
	else if (bytesWritten == 0)
	{
		/* we are done */
		ret = SMA_PIPE_OK;
	} /* if */

	return ret;
} /* writeToPipe */



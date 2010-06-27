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

/*! \file maasync.c
 * \brief Implementation of the state machine wrapping the asynchronous File 
 *  API. The reason why we need this state machine is because MSF return a
 *  signal as a response to SELECT and the only way of identifying what 
 *  operation it is related to is the file handle and hence we must keep all
 *  open fileHandles in one place.
 */

/*--- Include files ---*/
#include "msf_lib.h"    /* MSF: ANSI Standard libs allowed to use */
#include "msf_cfg.h"    /* MSF: Module definition */
#include "msf_def.h"    /* MSF: Global definitions */ 
#include "msf_log.h"    /* MSF: Signal logging */ 
#include "msf_mem.h"    /* MSF: Memory handling */
#include "msf_core.h"   /* MSF: MSF macros, signals and types */
#include "msf_file.h"   /* MSF: MSF File API */ 
#ifdef WAP_SUPPORT
#include "mea_cfg.h"
#endif /* WAP_SUPPORT */
#ifdef MMS_SLIM_MEM
#include "msf_pipe.h"
#endif /* MMS_SLIM_MEM */

#include "mms_def.h"

#include "maintsig.h"   /* MMS: Signal handling functions */
#include "mamem.h"      /* MMS: Memory handling functions */
#include "maasync.h"     /* MMS: Async file handling functions */
#include "macore.h"

/*--- Definitions/Declarations ---*/
#define ASYNC_POOL_SIZE 6
#ifdef MMS_SLIM_MEM
#define MEA_MAX_CHUNK_SIZE 2048
#endif /* MMS_SLIM_MEM */

/*--- Types ---*/

/*! \enum OperState
 *  Used to indicate the different states an operation can be in.
 */
typedef enum
{
    OPER_STATE_FREE = 0,    /*!< The asynchronous operation is not used. */
    OPER_STATE_OPENED       /*!< The file is opened */
} OperState;

/*! \struct AsyncOperation 
 *  Data needed to handle asynchronous file operations from other state 
    machines */
typedef struct AsyncOper
{   /* Double linked list */
    struct AsyncOper *next; /*!< Next asynchronous operation in queue */
    struct AsyncOper *previous; /*!< Previous asynchronous operation in 
                                     queue */
    OperState state;        /*!< State for the file in question */
    MeaAsyncMode mode;      /*!< The type of operation see #MeaAsyncMode */

    MeaStateMachine fsm;    /*!< FSM originally ordering the operation */
    long instance;          /*!< FSM instance */
    MSF_UINT32 signal;      /*!< Response signal ID */

    int fileHandle;         /*!< File handle as returned from MSF */
    MSF_UINT32 totalLen;    /*!< Total number of bytes read/written */
    unsigned char *pos;     /*!< Current buffer position for reading/writing */
    unsigned char *buffer;  /*!< Buffer to read/write to/from */
    MSF_UINT32 dataLen;     /*!< Length of data to read/write to/from current 
                             *   buffer. */
} AsyncOperation;

#ifdef MMS_SLIM_MEM
typedef enum
{
	MEA_PIPE_OK,
	MEA_PIPE_DELAYED,
	MEA_PIPE_ERROR
} MeaPipeResult;

typedef struct 
{
	int pipeHandle;
	char *pipeName;
}PipeInstance;

typedef struct 
{
	MeaAsyncOperationHandle asioHandle;
	char *buffer;
	MSF_UINT32 readPos;
	MSF_UINT32 leftToRead;
	char *writePos;
	MSF_UINT32 leftToWrite;
	MSF_UINT32 bufferSize;
	PipeInstance *pipeInst;
} MeaCopyInstance;

static PipeInstance pipeInst;
static MeaCopyInstance copyInst;
#endif /* MMS_SLIM_MEM */
/*--- Constants ---*/ 

/*--- Forwards ---*/ 

/*--- Externs ---*/ 

/*--- Macros ---*/ 

/*--- Global variables ---*/ 

/*--- Static variables ---*/ 
/*lint -esym(956,myOperations,myPoolSize,myCaller) */
/* Non const, non volatile static or external variable. Not a problem since 
 * we're not running anything multithreaded. */

/*! List with all ongoing file operations. */
static AsyncOperation *myOperationPool;
static int myPoolSize;

/*--- Prototypes ---*/ 
static void asyncMain(MeaSignal *sig);
static void doRead(AsyncOperation *op);
static void doSeek(const AsyncOperation *op, MSF_INT32 startPos);
static void doWrite(AsyncOperation *op);
static void handleNotify(int fileHandle, int operationType);
static MeaAsioResult translateFileError(int fileError);
#ifdef MMS_SLIM_MEM
static void handlePipeNotify(int pipeHandle, int operationType);
#endif /* MMS_SLIM_MEM */

/******************************************************************************/

/*!
 * \brief Initialize the Async File API FSM.
 * \return TRUE if succesful, FALSE otherwise
 *****************************************************************************/
MSF_BOOL meaAsyncInit(void)
{
    int i;
    AsyncOperation *previous = NULL;
    AsyncOperation *aNew = NULL;

    meaSignalRegisterDst(MEA_ASYNC_FSM, asyncMain);
    
    myOperationPool = NULL;
    myPoolSize = 0;
    for (i = 0; i < ASYNC_POOL_SIZE; ++i)
    {
        /* Do not use exception during initiation */
        if ((aNew = MEA_ALLOC_NE(sizeof(AsyncOperation))) == NULL)
        {
            MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                MAASYNC_736AA7E57F3B3AC2F0CDB7D20DAB3308, "%s(%d): Insufficient memory during initialization\n", 
                __FILE__, __LINE__));
            return FALSE;
        } /* if */

        memset( aNew, 0, sizeof(AsyncOperation));
        aNew->state = OPER_STATE_FREE;
        if (myOperationPool == NULL)
        {
            myOperationPool = aNew;
            myOperationPool->next = NULL;
            myOperationPool->previous = NULL;
            previous = aNew;
        }
        else 
        {
            if (previous != NULL)
            {
                previous->next = aNew;
            } /* if */

            aNew->previous = previous;
            aNew->next = NULL;
            previous = aNew;
        } /* if */
    } /* for */

    myPoolSize = i;

    MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
        MAASYNC_88905B0179B02A35C13152DE3A792FDF, "MMS FSM Async: initialized\n"));

    return TRUE;
} /* asyncInit */

#ifdef MMS_SLIM_MEM
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
static MSF_BOOL handleReadOperation(MeaCopyInstance *instance, 
    int bytesRead, MeaAsioResult result)
{
    MSF_BOOL status = TRUE;
    
    switch(result)
    {
        case MEA_ASIO_RESULT_OK:
        case MEA_ASIO_RESULT_EOF:
            /* write data to file */
            instance->readPos += (MSF_UINT32)bytesRead;
            instance->leftToRead -= (MSF_UINT32)bytesRead;
            status = TRUE;
            break;
        case MEA_ASIO_RESULT_FILE_NOT_FOUND:
        case MEA_ASIO_RESULT_ERROR:
        case MEA_ASIO_RESULT_INSUFFICIENT_PERSISTENT_STORAGE:
            status = FALSE;
            break;
        case MEA_ASIO_RESULT_DELAYED:
            /*lint -fallthrough */
        default:
            status = FALSE;
    } /* switch */
    return status;
} /* handleReadOperation */

static MeaPipeResult writeToPipe(MeaCopyInstance *instance)
{
	MSF_INT32 bytesWritten = 0;
	MeaPipeResult ret = MEA_PIPE_OK;

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
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAASYNC_E27A545C478A9B8189C14618FFCC6FC3, "%s(%d): Bad handle\n", 
            __FILE__, __LINE__));
        
		ret = MEA_PIPE_ERROR;
    }
    else if (bytesWritten == MSF_PIPE_ERROR_CLOSED)
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                     MAASYNC_443B91882A56DE3C15FE6CC2C0785869, "%s(%d): Pipe closed at read end\n", 
                     __FILE__, __LINE__));
        
		ret = MEA_PIPE_ERROR;
    }
	else if(bytesWritten == MSF_PIPE_ERROR_DELAYED)
	{
		 /* More work to do later */
        (void)MSF_PIPE_POLL(instance->pipeInst->pipeHandle);
		ret = MEA_PIPE_DELAYED;
	}
	else if (bytesWritten == 0)
	{
		/* we are done */
		ret = MEA_PIPE_OK;
	} /* if */

	return ret;
} /* writeToPipe */

static void freeCopyInstance(MeaCopyInstance *instance)
{
	if (instance == NULL)
	{
		return;
	} /* if */
	
    if (instance->pipeInst != NULL)
    {
	    if (instance->pipeInst->pipeHandle >= 0)
	    //if (instance->pipeInst->pipeHandle > 0)
	    {
		    /* close pipe */
		    /* nothing to do if close failes */
		    (void)MSF_PIPE_CLOSE(instance->pipeInst->pipeHandle);
		    instance->pipeInst->pipeHandle = -1;
	    } /* if */
        
        if (instance->pipeInst->pipeName != NULL)
        {
            MEA_FREE(instance->pipeInst->pipeName);
            instance->pipeInst->pipeName = NULL;
        }
    }

	if (instance->buffer)
	{
		MEA_FREE(instance->buffer);
		instance -> buffer = NULL;
	} /* if */
	
	if (instance->asioHandle != 0)
	{
		meaAsyncOperationStop(&(instance->asioHandle));
	} /* if */
} /* freeCopyInstance */

/*!
 * \brief Takes care of a NOTIFY signal (response to an MSF_FILE_SELECT operation)
 *
 * \param fileHandle File that the signal is related to
 * \param operationType that the notification was related to
 *****************************************************************************/
static void handlePipeNotify(int pipeHandle, int operationType)
{
   /* Only opened files can cause NOTIFY signals */
    if (pipeInst.pipeHandle == pipeHandle)
    {
        switch (operationType)
        {
        case MSF_PIPE_EVENT_WRITE:
            (void)MEA_SIGNAL_SENDTO(MEA_ASYNC_FSM, MEA_SIG_ASYNC_PIPE_WRITE_PIPE);
            break;
	    case MSF_PIPE_EVENT_CLOSED:
            /* Error, if this signal is received, the other side has 
			    unexpectedly closed the pipe */
            (void)MEA_SIGNAL_SENDTO_I(MEA_ASYNC_FSM, MEA_SIG_ASYNC_PIPE_COPY_COMPLETE, FALSE);
            break;
        } /* switch */
        return;
    } /* if */

    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, 
        MAASYNC_1B0754A6338F4F2DC7B0EFA93E946749, "%s(%d): Couldn't find handle\n", __FILE__, __LINE__));
} /* handlePipeNotify */

/*!
 * \brief Creates a named pipe
 * \param pipeName the name for the pipe.
 *
 * \return TRUE if creation is successfull, else FALSE
 *****************************************************************************/
MSF_BOOL meaCreatePipeOperation(const char *pipeName)
{
	MSF_BOOL ret;
	if (pipeName == NULL)
	{
		/* unable to create the pipe without a name */
		return FALSE;
	} /* if */

	/* store pipename */
	pipeInst.pipeName = msf_cmmn_strdup(MSF_MODID_MEA, pipeName);
	
	pipeInst.pipeHandle = MSF_PIPE_CREATE(MSF_MODID_MEA, pipeName);

	if (pipeInst.pipeHandle < 0)
	{
		/* failed to create the pipe */
		ret = FALSE;
	}
	else 
	{
		ret = TRUE;
	} /* if */
	
	return ret;
} /* meaCreatePipeOperation */

void meaCopyFileToPipe(const char* pipeName, const char *fileName, MSF_UINT32 offset, MSF_UINT32 size//, 
//	MSF_BOOL sendResult, MeaStateMachine retFsm, MSF_UINT32 retSig)
	)
{
	/* save return information */
	//copyInst.retFsm = retFsm;
	//copyInst.retSig = retSig;
    //copyInst.sendResult = sendResult;

	if (size < MEA_MAX_CHUNK_SIZE)
	{
		copyInst.bufferSize = size;
	}
	else
	{
		copyInst.bufferSize = MEA_MAX_CHUNK_SIZE;
	} /* if */

	copyInst.pipeInst = &pipeInst;

	copyInst.buffer = MEA_ALLOC(copyInst.bufferSize);
	memset(copyInst.buffer, 0x00, copyInst.bufferSize);

	copyInst.leftToRead = size;
	copyInst.readPos = offset;
	
	/* initialize async operation */
	copyInst.asioHandle = 
		meaAsyncOperationStart(fileName, MEA_ASYNC_FSM, 0L, 
	    MEA_SIG_ASYNC_PIPE_FILE_READ_RSP, MEA_ASYNC_MODE_READ);

	/* start reading data */
	meaAsyncRead(copyInst.asioHandle, (MSF_INT32)copyInst.readPos,
		    copyInst.buffer, copyInst.bufferSize);
} /* meaCopyFileToPipe */
#endif /* MMS_SLIM_MEM */

/*!
 * \brief Main function for Async File API FSM
 * 
 * \param sig Incoming signal to the FSM
 *****************************************************************************/
static void asyncMain(MeaSignal *sig)
{
#ifdef MMS_SLIM_MEM
	int bytesRead;
	MSF_UINT32 bytesToRead;
	MeaAsioResult asioResult;
#endif /* MMS_SLIM_MEM */
    switch (sig->type)
    {
    case MEA_SIG_ASYNC_NOTIFY :
        handleNotify( (int)sig->u_param1, sig->i_param);
        break;
#ifdef MMS_SLIM_MEM
    case MEA_SIG_ASYNC_PIPE_NOTIFY :
        handlePipeNotify( (int)sig->u_param1, sig->i_param);
        break;
	case MEA_SIG_ASYNC_PIPE_FILE_READ_RSP:
		/* async readopearation is complete */
		bytesRead = (int)sig->u_param2;
		asioResult = (MeaAsioResult)sig->u_param1;

		if (!handleReadOperation(&copyInst, (int)bytesRead, asioResult))
        {
			/* read operation failed - ERROR */
			/* send success signal */
			(void)MEA_SIGNAL_SENDTO_I(MEA_ASYNC_FSM, MEA_SIG_ASYNC_PIPE_COPY_COMPLETE, FALSE);
		}
		else
		{
			/* read operation successfull */
			/* write data to pipe */
			copyInst.writePos = copyInst.buffer;
			copyInst.leftToWrite = (MSF_UINT32)bytesRead;
			(void)MEA_SIGNAL_SENDTO(MEA_ASYNC_FSM, MEA_SIG_ASYNC_PIPE_WRITE_PIPE);
		}
		break;
	case MEA_SIG_ASYNC_PIPE_WRITE_PIPE:
		switch (writeToPipe(&copyInst))
		{
		case MEA_PIPE_OK:
			if (copyInst.leftToRead > 0)
			{
				/* more to read */
				bytesToRead = copyInst.bufferSize;
				if (copyInst.leftToRead < copyInst.bufferSize)
				{
					bytesToRead = copyInst.leftToRead;
				} /* if */
				meaAsyncRead(copyInst.asioHandle, (MSF_INT32)copyInst.readPos,
					copyInst.buffer, bytesToRead);
			}
			else
			{
				/* send success signal */
				(void)MEA_SIGNAL_SENDTO_I(MEA_ASYNC_FSM, 
					MEA_SIG_ASYNC_PIPE_COPY_COMPLETE, TRUE);
			} /* if */
			break;
		case MEA_PIPE_DELAYED:
			/* noting to do, just wait for signal from MSF */
			break;
		case MEA_PIPE_ERROR:
		default:
			/* send error signal ?*/
			(void)MEA_SIGNAL_SENDTO_I(MEA_ASYNC_FSM, 
					MEA_SIG_ASYNC_PIPE_COPY_COMPLETE, TRUE);
			break;
		}
		break;
	case MEA_SIG_ASYNC_PIPE_COPY_COMPLETE:
		freeCopyInstance(&copyInst);
		break;

#endif /* MMS_SLIM_MEM */
    default:
        /* Unknown signal: just ignore. */
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAASYNC_3B4C0F70716834074C79EB3BF034A2AA, "%s(%d): received unknown signal %d\n", __FILE__, __LINE__,
            sig->type));
        break;
    } /* switch */
    
    meaSignalDelete(sig);
} /* asyncMain */

/*!
 * \brief Start a new asynchronous file operation
 *
 *  Whenever an asynchronous file operations is finished or shall be aborted, 
 *  it must be stopped with a call to #asyncOperationStop.
 *
 * \param fileName  Name of file operating on. 
 * \param fsm       FSM ordering the operation
 * \param instance  FSM instance ordering the operation
 * \param signal    FSMs requested response signal
 * \param mode      Read, write or both?
 * \return AsyncOperationHandle, i.e. ptr to item in array with operations,
 *         NULL if no free
 *****************************************************************************/
MeaAsyncOperationHandle meaAsyncOperationStart(const char *fileName, 
    MeaStateMachine fsm, long instance, MSF_UINT32 signal, MeaAsyncMode mode)
{
    AsyncOperation *anOper = myOperationPool;
    AsyncOperation *last = NULL;
    int fileHandle;
    int openMode;

    /* Search a free operation */
    while (anOper != NULL && anOper->state != OPER_STATE_FREE)
    {
        last = anOper;
        anOper = anOper->next;
    } /* for */

    /* If we didn't we find a free then increase the queue */
    if (anOper == NULL)
    {
        if ((anOper = MEA_ALLOC(sizeof(AsyncOperation))) == NULL)
        {
            MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                MAASYNC_B6E8ADEE4237B4D9AFFADE08687C05AB, "MMS FSM Async: No free async operations\n"));

            return NULL;
        } /* if */
        /*lint -e{794} */
        last->next = anOper;
        anOper->previous = last;
        anOper->next = NULL;
        ++myPoolSize;
    } /* if */
    /*lint -e{788} */
    switch (mode)
    {
    case MEA_ASYNC_MODE_READ :
        openMode = MSF_FILE_SET_RDONLY;
        break;
    case MEA_ASYNC_MODE_WRITE :
        openMode = MSF_FILE_SET_WRONLY | MSF_FILE_SET_CREATE;
        break;
    case MEA_ASYNC_MODE_APPEND :
        openMode = MSF_FILE_SET_WRONLY | MSF_FILE_SET_CREATE |
            MSF_FILE_SET_APPEND;
        break;
    case MEA_ASYNC_MODE_READ_WRITE :
        /* NOTE! We cannot use MSF_FILE_SET_APPEND here since seek is not
         * allowed when using this flag */
        openMode = MSF_FILE_SET_RDWR | MSF_FILE_SET_CREATE;
        break;
    default :
        MSF_LOG_MSG_OFF(( MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
            MAASYNC_7542532AEB0C356E90A2FB2EB3BC5670, "%s(%d): Illegal open mode %d\n", __FILE__, __LINE__, 
            mode));

        openMode = MSF_FILE_SET_RDWR | MSF_FILE_SET_CREATE;
        break;
    } /* switch */

    fileHandle = MSF_FILE_OPEN(MSF_MODID_MEA, fileName, openMode, 0);

    if (fileHandle < 0) /* i.e. ERROR! */
    {
        MSF_LOG_MSG_OFF(( MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
            MAASYNC_931FF487F3913B5C9F3B92FA51A77322, "%s(%d): Failed to open file <%s>, %d\n", __FILE__, __LINE__, 
            fileName == NULL ? "NULL" : fileName, fileHandle));
    } /* if */

    anOper->fsm = fsm;
    anOper->instance = instance;
    anOper->signal = signal;
    anOper->fileHandle = fileHandle;
    anOper->state = OPER_STATE_OPENED;
    anOper->buffer = NULL;
    anOper->dataLen = 0;
    anOper->mode = mode;

    return anOper;
} /* asyncOperationStart */

/*!
 * \brief Register a delayed file operation, when the file operation can be
 *        executed again a signal will be sent to the registered FSM.
 *
 * \param fileHandle
 * \param fsm The fsm to send a signal to when a file operation can be executed 
 *            again.
 * \param instance FSM instance ordering the operation
 * \param signal FSMs requested response signal.
 *****************************************************************************/
void meaAsyncRegister(int fileHandle, int fsm, int signal, int instance)
{
    AsyncOperation *anOper = myOperationPool;
    AsyncOperation *last = NULL;

    /* Search a free operation */
    while (anOper != NULL && anOper->state != OPER_STATE_FREE)
    {
        last = anOper;
        anOper = anOper->next;
    } /* for */

    /* If we didn't we find a free then increase the queue */
    if (anOper == NULL)
    {
        if ((anOper = MEA_ALLOC(sizeof(AsyncOperation))) == NULL)
        {
            MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                MAASYNC_B6E8ADEE4237B4D9AFFADE08687C05AB, "MMS FSM Async: No free async operations\n"));

            MEA_TERMINATE;
        } /* if */
        /*lint -e{794} */
        last->next = anOper;
        /*lint -e{613} */
        anOper->previous = last;
        /*lint -e{613} */
        anOper->next = NULL;
        ++myPoolSize;
    } /* if */

    if (fileHandle < 0) /* i.e. ERROR! */
    {
        MSF_LOG_MSG_OFF(( MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
            MAASYNC_B6B52380D6255D6EF216EBE39A03810D, "%s(%d): Erroneous file handle <%d>\n", __FILE__, __LINE__, 
            fileHandle));
        return;
    } /* if */

    /*lint -e{613} */
    anOper->fsm = (MeaStateMachine)fsm;
    /*lint -e{613} */
    anOper->instance = instance;
    /*lint -e{613} */
    anOper->signal = (unsigned)signal;
    /*lint -e{613} */
    anOper->fileHandle = fileHandle;
    /*lint -e{613} */
    anOper->buffer = NULL;
    /*lint -e{613} */
    anOper->dataLen = 0;
    /*lint -e{613} */
    anOper->mode = MEA_ASYNC_MODE_DISPATCH;
}

/*!
 * \brief Deregisters a delayed file operation previously ordered with a call
 *        to meaAsyncRegister.
 *
 * \param fileHandle The fileHandle of the ongoing operation that is to be 
 *                   cancelled.
 */

void meaAsyncDeregister(int fileHandle)
{
    AsyncOperation *op = myOperationPool;

    while((op != NULL) && (op->fileHandle != fileHandle))
        op = op->next;
    if (NULL == op)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAASYNC_DA0B746C42DB20A6CBBF34401DC6A779, "%s(%d): Invalid async oper handle op=%d\n", 
            __FILE__, __LINE__, op));
        return;
    }

    if (myPoolSize > ASYNC_POOL_SIZE)
    {
        if (op->previous != NULL)
        {
            op->previous->next = op->next;
        } /* if */

        if (op->next != NULL)
        {
            op->next->previous = op->previous;
        } /* if */
        /*lint -e{774} */
        MEA_FREE(op);

        --myPoolSize;
    } /* if */
}


/*!
 * \brief Halts and cleanup a previously started asynchronous file operation
 *
 * \param oper Handle to an async operation
 *****************************************************************************/
void meaAsyncOperationStop(MeaAsyncOperationHandle *oper)
{
    AsyncOperation *op = (AsyncOperation *)*oper;

    if (op == NULL)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAASYNC_DA0B746C42DB20A6CBBF34401DC6A779, "%s(%d): Invalid async oper handle op=%d\n", 
            __FILE__, __LINE__, op));

        return;
    } /* if */

    if (op->state == OPER_STATE_OPENED && op->fileHandle > 0)
    {
        (void)MSF_FILE_CLOSE(op->fileHandle);
    } /* if */

    op->state = OPER_STATE_FREE;
    op->fileHandle = 0;

    if (myPoolSize > ASYNC_POOL_SIZE)
    {
        if (op->previous != NULL)
        {
            op->previous->next = op->next;
        } /* if */

        if (op->next != NULL)
        {
            op->next->previous = op->previous;
        } /* if */
        /*lint -e{774} */
        MEA_FREE(op);

        --myPoolSize;
    } /* if */

    *oper = NULL;
} /* asyncOperationStop */

/*!
 * \brief Start a new read operation
 *
 * A read operation is started. The read operation will continue until
 * bufSize bytes is read. If the bufSize is larger than what is available,
 * the read operation will stop and send a EOF to the caller.
 *
 * \param oper Handle to an async operation
 * \param startPos At what position in the file that the read will start,
 *        -1 indicates at EOF.
 * \param buffer Where to store read data
 * \param bufSize Size of the buffer
 *****************************************************************************/
void meaAsyncRead(MeaAsyncOperationHandle oper, MSF_INT32 startPos, 
    void *buffer, MSF_UINT32 bufSize)
{
    AsyncOperation *op = (AsyncOperation *)oper;

    if (op == NULL || op->state != OPER_STATE_OPENED)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAASYNC_474CA7F3EECC206B8C7568F28AC495D3, "%s(%d): Wrong handle or state for read, op=%d, state=%d\n", 
            __FILE__, __LINE__, op, op == NULL ? -1 : op->state));

        return;
    }
    else if (op->fileHandle < 0)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAASYNC_C046CCB045C84026B3589E1593D78CF7, "%s(%d): File was not opened, check previous errors, op=%d," 
            "state=%d\n", 
            __FILE__, __LINE__, op, op == NULL ? -1 : op->state));

        (void)MEA_SIGNAL_SENDTO_IUU( op->fsm, (int)op->signal, op->instance, 
            MEA_ASIO_RESULT_FILE_NOT_FOUND, op->totalLen);
        return;
    } /* if */

    /* OK, file is opened. Prepare for reading */
    op->totalLen = 0;
    op->pos = buffer;
    op->buffer = buffer;
    op->dataLen = bufSize;

    doSeek(op, startPos);
    doRead(op);
} /* asyncRead */

/*!
 * \brief Continues a previously started read operation
 *
 * A read operation has been stopped with type BUFFER_FULL. The caller 
 * indicates that more data can be read to the buffer.
 *
 * \param oper Handle to an async operation
 * \param bufSize Size of the buffer
 *****************************************************************************/
void meaAsyncReadContinue(MeaAsyncOperationHandle oper, MSF_UINT32 bufSize)
{
    AsyncOperation *op = (AsyncOperation *)oper;

    if (op == NULL || op->state != OPER_STATE_OPENED)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAASYNC_8606FF210DB7DF3C237E013BDC43598D, "%s(%d): Wrong handle or state for readContinue, op=%d, state=%d\n"
            , __FILE__, __LINE__, op, op == NULL ? -1 : op->state));

        return;
    }
    else if (op->fileHandle < 0)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAASYNC_BB181C4C2CE439187166ABD22B9ACB3D, "%s(%d): File was not opened, check previous errors, op=%d, "
            "state=%d\n", 
            __FILE__, __LINE__, op, op == NULL ? -1 : op->state));

        (void)MEA_SIGNAL_SENDTO_IUU(op->fsm, (int)op->signal, op->instance, 
            MEA_ASIO_RESULT_FILE_NOT_FOUND, op->totalLen);
        return;
    } /* if */

    op->dataLen = bufSize;
    doRead(op);
} /* asyncReadContinue */

/*!
 * \brief Start a new write operation
 *
 * A write operation is started. The write operation will continue until
 * bufSize bytes is written. At this time, the write operation will stop 
 * and send MMS_RESULT_OK to the caller.
 *
 * \param oper Handle to an async operation
 * \param startPos At what position in the file that the write will start,
 *        -1 indicates append.
 * \param buffer Data to write to file
 * \param bufSize Size of the buffer where to fetch data to write
 *****************************************************************************/
void meaAsyncWrite(MeaAsyncOperationHandle oper, MSF_INT32 startPos, 
                   void *buffer, MSF_UINT32 bufSize)
{
    AsyncOperation *op = (AsyncOperation *)oper;

    if (op == NULL || op->state != OPER_STATE_OPENED)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAASYNC_43DC7120C388CADADC82B3703E7A5021, "%s(%d): Wrong handle or state for write, op=%d, state=%d\n", 
            __FILE__, __LINE__, op, op == NULL ? -1 : op->state));

        return;
    }
    else if (op->fileHandle < 0)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAASYNC_BB181C4C2CE439187166ABD22B9ACB3D, "%s(%d): File was not opened, check previous errors, op=%d, state=%d\n", 
            __FILE__, __LINE__, op, op == NULL ? -1 : op->state));

        (void)MEA_SIGNAL_SENDTO_IUU(op->fsm, (int)op->signal, op->instance, 
            MEA_ASIO_RESULT_FILE_NOT_FOUND, op->totalLen);
        return;
    } /* if */

    /* OK, file is opened. Prepare for reading */
    op->totalLen = 0;
    op->pos = buffer;
    op->buffer = buffer;
    op->dataLen = bufSize;

#ifdef WAP_SUPPORT
    /* Do not seek in append mode  */
    if (op->mode != MEA_ASYNC_MODE_APPEND)
#endif /* WAP_SUPPORT */
        doSeek(op, startPos);
    doWrite(op);
} /* asyncWrite */

/*!
 * \brief Continues a previously started write operation
 *
 * A write operation has been stopped with type BUFFER_EMPTY. The caller 
 * indicates that more data to write is available in the buffer.
 *
 * \param oper Handle to an async operation
 * \param bufSize Size of the buffer where to fetch data to write
*****************************************************************************/
void meaAsyncWriteContinue(MeaAsyncOperationHandle oper, MSF_UINT32 bufSize)
{
    AsyncOperation *op = (AsyncOperation *)oper;

    if (op == NULL || op->state != OPER_STATE_OPENED)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAASYNC_358A5A2A195321741A74C1789913DCBE, "%s(%d): Wrong handle or state for writeContinue, op=%d, state=%d\n", 
            __FILE__, __LINE__, op, op == NULL ? -1 : op->state));

        return;
    }
    else if (op->fileHandle < 0)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAASYNC_BB181C4C2CE439187166ABD22B9ACB3D, "%s(%d): File was not opened, check previous errors, op=%d, state=%d\n", 
            __FILE__, __LINE__, op, op == NULL ? -1 : op->state));

        (void)MEA_SIGNAL_SENDTO_IUU(op->fsm, (int)op->signal, op->instance, 
            MEA_ASIO_RESULT_FILE_NOT_FOUND, op->totalLen);
        return;
    } /* if */

    op->dataLen = bufSize;
    doWrite(op);
} /* asyncWriteContinue */

/*!
 * \brief Do the actual read
 *
 * \param op Data for an async operation
 *****************************************************************************/
static void doRead(AsyncOperation *op)
{
    int ret;
    long length;

    length = op->buffer - op->pos + (long)op->dataLen;

    /* File is opened and we're positioned so we can start to read */
    for (;;)
    {
        if (length <= 0) /* We have read everything that we should */
        {
            (void)MEA_SIGNAL_SENDTO_IUU(op->fsm, (int)op->signal, op->instance, 
                MEA_ASIO_RESULT_OK, op->totalLen);
            return;
        } /* if */

        ret = MSF_FILE_READ( op->fileHandle, op->pos, length);
        switch (ret)
        {
        case 0 :
        case MSF_FILE_ERROR_EOF :
            (void)MEA_SIGNAL_SENDTO_IUU(op->fsm, (int)op->signal, op->instance, 
                MEA_ASIO_RESULT_EOF, op->totalLen);
            return;

        case MSF_FILE_ERROR_ACCESS :
            MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                MAASYNC_E92995BC353D6D26B6BBD3A731CEBB77, "%s(%d): Read returned %d\n", __FILE__, __LINE__, ret));

            (void)MEA_SIGNAL_SENDTO_IUU(op->fsm, (int)op->signal, op->instance, 
                translateFileError(ret), op->totalLen);
            return;

        case MSF_FILE_ERROR_DELAYED :
            MSF_FILE_SELECT( op->fileHandle, MSF_FILE_EVENT_READ);
            return;

        default :
            if (ret < 0)
            {
                MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                    MAASYNC_D4FD45BD4DCDB884139BD7371682204F, "%s(%d): Unhandled file error %d\n",
                    __FILE__, __LINE__, ret));
                (void)MEA_SIGNAL_SENDTO_IUU(op->fsm, (int)op->signal, 
                    op->instance, translateFileError(ret), op->totalLen);

                return; 
            } /* if */

            op->totalLen += (MSF_UINT32)ret;
            op->pos += ret;
            length -= ret;
            break;
        } /* switch */
    } /* for */
} /* doRead */

/*!
 * \brief Do the actual seek
 *
 * \param op Data for an async operation
 * \param startPos Position in file to start reading/writing
 *****************************************************************************/
static void doSeek(const AsyncOperation *op, MSF_INT32 startPos)
{
    int seekMode;
    long seekOffset;
    long ret;

    if (op && (MEA_ASYNC_MODE_APPEND == op->mode)) 
    {
        /* Seek is not allowed when in append mode */
        return;
    }
    if (startPos == -1)
    {
        seekMode = MSF_FILE_SEEK_END;
        seekOffset = 0;
    }
    else
    {
        seekMode = MSF_FILE_SEEK_SET;
        seekOffset = startPos;
    } /* if */

    if (op && (ret = MSF_FILE_SEEK( op->fileHandle, seekOffset, seekMode)) < 0)
    {
        (void)MEA_SIGNAL_SENDTO_IUU(op->fsm, (int)op->signal, op->instance, 
            translateFileError(ret), op->totalLen);

        MSF_LOG_MSG_OFF(( MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
            MAASYNC_233C80169081FC2385D6F959C3201D4A, "%s(%d): Failed to seek file %d, mode=%d, pos=%d, ret=%d\n", 
            __FILE__, __LINE__, op->fileHandle, seekMode, seekOffset, ret));

        return;
    } /* if */
} /* doSeek */

/*!
 * \brief Do the actual write
 *
 * \param op Data for an async operation
 *****************************************************************************/
static void doWrite(AsyncOperation *op)
{
    int ret;
    int length;

    length = op->buffer - op->pos + (long)op->dataLen;

    /* File is opened and we're positioned so we can start to write */
    for (;;)
    {
        if (length <= 0)    /* Have we written everything from the buffer? */
        {
            (void)MEA_SIGNAL_SENDTO_IUU(op->fsm, (int)op->signal, op->instance, 
                MEA_ASIO_RESULT_OK, op->totalLen);
            return;
        } /* if */

        ret = MSF_FILE_WRITE( op->fileHandle, op->pos, length);
        switch (ret)
        {
        case 0 :
        case MSF_FILE_ERROR_EOF :
        case MSF_FILE_ERROR_ACCESS :
        case MSF_FILE_ERROR_FULL :
            MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                MAASYNC_9AA9D6B0B8AF1672098ECCDE8BEBE5DE, "%s(%d): Write returned %d\n", __FILE__, __LINE__, ret));

            (void)MEA_SIGNAL_SENDTO_IUU(op->fsm, (int)op->signal, op->instance, 
                translateFileError(ret), op->totalLen);
            return;

        case MSF_FILE_ERROR_DELAYED :
            MSF_FILE_SELECT( op->fileHandle, MSF_FILE_EVENT_WRITE);
            return;

        default :
            if (ret < 0)
            {
                MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                    MAASYNC_D4FD45BD4DCDB884139BD7371682204F, "%s(%d): Unhandled file error %d\n",
                    __FILE__, __LINE__, ret));
                (void)MEA_SIGNAL_SENDTO_IUU(op->fsm, (int)op->signal, 
                    op->instance, translateFileError(ret), op->totalLen);

                return; 
            } /* if */

            op->totalLen += (unsigned long)ret;
            op->pos += ret;
            length -= ret;
            break;
        } /* switch */
    } /* for */
} /* doWrite */

/*!
 * \brief Takes care of a NOTIFY signal (response to an MSF_FILE_SELECT operation)
 *
 * \param fileHandle File that the signal is related to
 * \param operationType that the notification was related to
 *****************************************************************************/
static void handleNotify(int fileHandle, int operationType)
{
    AsyncOperation *anOper = myOperationPool;

    while (anOper != NULL)
    {   /* Only opened files can cause NOTIFY signals */
        if (anOper->fileHandle == fileHandle &&
            anOper->mode == MEA_ASYNC_MODE_DISPATCH)
        {
            switch (operationType)
            {
            case MSF_FILE_READ_READY :
            case MSF_FILE_WRITE_READY :
                (void)MEA_SIGNAL_SENDTO_IU(anOper->fsm, (int)anOper->signal, 
                    anOper->instance, MEA_ASIO_RESULT_OK); 
                meaAsyncDeregister(fileHandle);
                break;
            default :
                MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                    MAASYNC_5AAD0A2BE0991231D47AB9A0A5FCD32C, "%s(%d): Illegal operationType %d\n", __FILE__, __LINE__,
                    operationType));
                break;
            } /* switch */

            return;
        }

        if (anOper->state == OPER_STATE_OPENED && 
            anOper->fileHandle == fileHandle)
        {
            switch (operationType)
            {
            case MSF_FILE_READ_READY :
                meaAsyncReadContinue(anOper, anOper->dataLen);
                break;
            case MSF_FILE_WRITE_READY :
                meaAsyncWriteContinue(anOper, anOper->dataLen);
                break;
            default :
                MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                    MAASYNC_5AAD0A2BE0991231D47AB9A0A5FCD32C, "%s(%d): Illegal operationType %d\n", __FILE__, __LINE__,
                    operationType));
                break;
            } /* switch */

            return;
        } /* if */

        anOper = anOper->next;
    } /* while */
    /*lint -e{774} */
    if (anOper == NULL)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAASYNC_1B0754A6338F4F2DC7B0EFA93E946749, "%s(%d): Couldn't find handle\n", __FILE__, __LINE__));
    } /* if */
} /* handleNotify */

/*!
 * \brief Takes care of a TERMINATE signal
 *****************************************************************************/
void meaAsyncTerminate(void)
{
    AsyncOperation *anOper = myOperationPool;
    AsyncOperation *next = NULL;

    myOperationPool = NULL;
    myPoolSize = 0;
    
    while (anOper != NULL)
    {
        next = anOper->next;
        MEA_FREE(anOper);
        anOper = next;
    } /* while */

    meaSignalDeregister(MEA_ASYNC_FSM);
} /* handleTerminate */

/*!
 * \brief Translates an MSF File Error to an MMS Result
 *
 * \param fileError Error as given from call to MSF FILE function
 *****************************************************************************/
static MeaAsioResult translateFileError(int fileError)
{
    MeaAsioResult ret = MEA_ASIO_RESULT_ERROR;

    switch (fileError)
    {
    case MSF_FILE_OK :
        ret = MEA_ASIO_RESULT_OK;
        break;
    case MSF_FILE_ERROR_ACCESS : /* e.g. file opened in wrong mode */
        ret = MEA_ASIO_RESULT_ERROR;
        break;
    case MSF_FILE_ERROR_DELAYED :
        ret = MEA_ASIO_RESULT_DELAYED;
        break;
    case MSF_FILE_ERROR_PATH :
        ret = MEA_ASIO_RESULT_FILE_NOT_FOUND;
        break;
    case MSF_FILE_ERROR_INVALID : /* e.g. illegal file name */
        ret = MEA_ASIO_RESULT_ERROR;
        break;
    case MSF_FILE_ERROR_SIZE :
        ret = MEA_ASIO_RESULT_INSUFFICIENT_PERSISTENT_STORAGE;
        break;
    case MSF_FILE_ERROR_FULL :
        ret = MEA_ASIO_RESULT_INSUFFICIENT_PERSISTENT_STORAGE;
        break;
    case MSF_FILE_ERROR_EOF :
        ret = MEA_ASIO_RESULT_EOF;
        break;
    default :
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAASYNC_F04A54693E8FD2C3774261A6897AE790, "%s(%d): Unknown fileError %d\n", __FILE__, __LINE__,
            fileError));
        break;
    } /* switch */

    return ret;
} /* translateFileError */


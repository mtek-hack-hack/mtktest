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

/*! \file masync.c
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

#include "sma_if.h"
#include "saintsig.h"   /* SMA: Internal statemachine */
#include "saasync.h"     /* MMS: Async file handling functions */
#include "samem.h"
/*--- Definitions/Declarations ---*/
#define ASYNC_POOL_SIZE 6

/*--- Types ---*/

/*! \enum OperState
 *  Used to indicate the different states an operation can be in.
 */
typedef enum
{
    OPER_STATE_FREE = 0,    /*!< The asynchronous operation is not used. */
    OPER_STATE_OPENED       /*!< The file is opened */
} OperState;

/*! \struct SmaAsyncOperation 
 *  Data needed to handle asyncronous file operations from other state machines */
typedef struct AsyncOper
{   /* Double linked list */
    struct AsyncOper *next; /*!< Next asynchronous operation in queue */
    struct AsyncOper *previous; /*!< Previous asynchronous operation in queue */
    OperState state;        /*!< State for the file in question */

    SmaStateMachine fsm;    /*!< FSM originally ordering the operation */
    long instance;          /*!< FSM instance */
    int signal;             /*!< Response signal ID */

    int fileHandle;         /*!< File handle as returned from MSF */
    MSF_UINT32 totalLen;    /*!< Total number of bytes read/written */
    unsigned char *pos;     /*!< Current buffer position for reading/writing */
    unsigned char *buffer;  /*!< Buffer to read/write to/from */
    MSF_UINT32 dataLen;     /*!< Length of data to read/write to/from current 
                             *   buffer. */
} SmaAsyncOperation;


/*--- Constants ---*/ 

/*--- Forwards ---*/ 

/*--- Externs ---*/ 

/*--- Macros ---*/ 

/*--- Global variables ---*/ 

/*--- Static variables ---*/ 

/*! List with all ongoing file operations. */
static SmaAsyncOperation *myOperationPool;
static int myPoolSize;

/*--- Prototypes ---*/ 
static void smaAsyncMain(SmaSignal *sig);
static void doRead(SmaAsyncOperation *op);
static void doSeek(const SmaAsyncOperation *op, MSF_INT32 startPos);
static void doWrite(SmaAsyncOperation *op);
static void handleNotify(int fileHandle, int operationType);
static SmaAsioResult translateFileError(int fileError);

/******************************************************************************/

/*!
 * \brief Cleanup everything as fast as possible.
 *
 * Due to something really severe (like no more memory), cleanup as fast as 
 * possible. Memory cleanup is postponed until later (MSF_MEM_FREE_ALL).
 *****************************************************************************/
void smaAsyncEmergencyAbort(void)
{
    SmaAsyncOperation *anOper = myOperationPool;

    smaSignalDeregister( SMA_FSM_ASYNC);

    /* Close all open files */
    while (anOper != NULL)
    {
        if (anOper->state == OPER_STATE_OPENED && anOper->fileHandle > 0)
        {
            (void)MSF_FILE_CLOSE(anOper->fileHandle);
            anOper->fileHandle = 0;
        } /* if */

        anOper->state = OPER_STATE_FREE;
        anOper = anOper->next;
    } /* while */
} /* smaAsyncEmergencyAbort */

/*!
 * \brief Initialize the Async File API FSM.
 * \return TRUE if succesfull, FALSE otherwise
 *****************************************************************************/
MSF_BOOL smaAsyncInit(void)
{
    int i;
    SmaAsyncOperation *previous = NULL;
    SmaAsyncOperation *aNew = NULL;


    smaSignalRegisterDst( SMA_FSM_ASYNC, smaAsyncMain);
    
    myOperationPool = NULL;
    myPoolSize = 0;
    for (i = 0; i < ASYNC_POOL_SIZE; ++i)
    {
        if ((aNew = SMA_ALLOC(sizeof(SmaAsyncOperation))) == NULL)
        {
            MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                SAASYNC_736AA7E57F3B3AC2F0CDB7D20DAB3308, "%s(%d): Insufficient memory during initialization\n", 
                __FILE__, __LINE__));
            return FALSE;
        } /* if */

        memset( aNew, 0, sizeof(SmaAsyncOperation));
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

    MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
        SAASYNC_8637EEABA308283AC08B53E3926A8F8E, "SMA FSM Async: initialized\n"));

    return TRUE;
} /* asyncInit */

/*!
 * \brief Main function for Async File API FSM
 * 
 * \param sig Incoming signal to the FSM
 *****************************************************************************/
static void smaAsyncMain(SmaSignal *sig)
{
    switch (sig->type)
    {
    case SMA_SIG_ASYNC_NOTIFY :
        handleNotify( (int)sig->u_param1, sig->i_param);
        break;
    default:
        /* Unknown signal: just ignore. */
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SAASYNC_3B4C0F70716834074C79EB3BF034A2AA, "%s(%d): received unknown signal %d\n", __FILE__, __LINE__,
            sig->type));
        break;
    } /* switch */
    
    smaSignalDelete(sig);
} /* smaAsyncMain */

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
 * \return SmaAsyncOperationHandle, i.e. ptr to item in array with operations,
 *         NULL if no free
 *****************************************************************************/
SmaAsyncOperationHandle smaAsyncOperationStart(const char *fileName, 
    SmaStateMachine fsm, long instance, int signal, SmaAsyncMode mode)
{
    SmaAsyncOperation *anOper = myOperationPool;
    SmaAsyncOperation *last = NULL;
    int fileHandle;
    int openMode;

    last = anOper;

    /* Search a free operation */
    while (anOper != NULL && anOper->state != OPER_STATE_FREE)
    {
        last = anOper;
        anOper = anOper->next;
    } /* for */

    /* If we didn't find a free item then increase the queue */
    if (anOper == NULL)
    {
        if ((anOper = SMA_ALLOC(sizeof(SmaAsyncOperation))) == NULL)
        {
            MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                SAASYNC_34F871CB7B69BE3A5EBD266084083B46, "SMA FSM Async: No free async operations\n"));

            return NULL;
        } /* if */

        last->next = anOper;
        anOper->previous = last;
        anOper->next = NULL;
        ++myPoolSize;
    } /* if */

    switch (mode)
    {
    case SMA_ASYNC_MODE_READ :
        openMode = HDI_FILE_SET_RDONLY;
        break;
    case SMA_ASYNC_MODE_WRITE :
        openMode = HDI_FILE_SET_WRONLY | HDI_FILE_SET_CREATE;
        break;
    case SMA_ASYNC_MODE_READ_WRITE :
        openMode = HDI_FILE_SET_RDWR | HDI_FILE_SET_CREATE;
        break;
    default :
        MSF_LOG_MSG_OFF(( MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, 
            SAASYNC_7542532AEB0C356E90A2FB2EB3BC5670, "%s(%d): Illegal open mode %d\n", __FILE__, __LINE__, 
            mode));

        openMode = HDI_FILE_SET_RDWR | HDI_FILE_SET_CREATE;
        break;
    } /* switch */

    fileHandle = MSF_FILE_OPEN( MSF_MODID_SMA, fileName, openMode, 0);

    if (fileHandle < 0) /* i.e. ERROR! */
    {
        MSF_LOG_MSG_OFF(( MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, 
            SAASYNC_931FF487F3913B5C9F3B92FA51A77322, "%s(%d): Failed to open file <%s>, %d\n", __FILE__, __LINE__, 
            fileName == NULL ? "NULL" : fileName, fileHandle));
    } /* if */

    anOper->fsm = fsm;
    anOper->instance = instance;
    anOper->signal = signal;
    anOper->fileHandle = fileHandle;
    anOper->state = OPER_STATE_OPENED;
    anOper->buffer = NULL;
    anOper->dataLen = 0;

    return anOper;
} /* smaAsyncOperationStart */

/*!
 * \brief Halts and cleanup a previously started asynchronous file operation
 *
 * \param oper Pointer to handle to an async operation
 *****************************************************************************/
void smaAsyncOperationStop( SmaAsyncOperationHandle *oper)
{
    SmaAsyncOperation *op = (SmaAsyncOperation *)*oper;

    if (op == NULL)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SAASYNC_DA0B746C42DB20A6CBBF34401DC6A779, "%s(%d): Invalid async oper handle op=%d\n", 
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

        SMA_FREE(op);

        --myPoolSize;
    } /* if */

    *oper = NULL;
} /* smaAsyncOperationStop */

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
void smaAsyncRead(SmaAsyncOperationHandle oper, MSF_INT32 startPos, 
    void *buffer, MSF_UINT32 bufSize)
{
    SmaAsyncOperation *op = (SmaAsyncOperation *)oper;

    if (op == NULL || op->state != OPER_STATE_OPENED)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SAASYNC_474CA7F3EECC206B8C7568F28AC495D3, "%s(%d): Wrong handle or state for read, op=%d, state=%d\n", 
            __FILE__, __LINE__, op, op == NULL ? -1 : op->state));

        return;
    }   
    else if (op->fileHandle < 0)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SAASYNC_BB181C4C2CE439187166ABD22B9ACB3D, "%s(%d): File was not opened, check previous errors, op=%d, state=%d\n", 
            __FILE__, __LINE__, op, op == NULL ? -1 : op->state));

        (void)SMA_SIGNAL_SENDTO_IUU( op->fsm, op->signal, op->instance, 
            SMA_ASIO_RESULT_FILE_NOT_FOUND, op->totalLen);
        return;
    } /* if */

    /* OK, file is opened. Prepare for reading */
    op->totalLen = 0;
    op->pos = buffer;
    op->buffer = buffer;
    op->dataLen = bufSize;

    doSeek(op, startPos);
    doRead(op);
} /* smaAsyncRead */

/*!
 * \brief Continues a previously started read operation
 *
 * A read operation has been stopped with type BUFFER_FULL. The caller 
 * indicates that more data can be read to the buffer. The reading
 * will continue from the current file position.
 *
 * \param oper Handle to an async operation
 * \param bufSize Size of the buffer
 *****************************************************************************/
void smaAsyncReadContinue(SmaAsyncOperationHandle oper, MSF_UINT32 bufSize)
{
    SmaAsyncOperation *op = (SmaAsyncOperation *)oper;

    if (op == NULL || op->state != OPER_STATE_OPENED)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SAASYNC_8606FF210DB7DF3C237E013BDC43598D, "%s(%d): Wrong handle or state for readContinue, op=%d, state=%d\n", 
            __FILE__, __LINE__, op, op == NULL ? -1 : op->state));

        return;
    }
    else if (op->fileHandle < 0)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SAASYNC_BB181C4C2CE439187166ABD22B9ACB3D, "%s(%d): File was not opened, check previous errors, op=%d, state=%d\n", 
            __FILE__, __LINE__, op, op == NULL ? -1 : op->state));

        (void)SMA_SIGNAL_SENDTO_IUU( op->fsm, op->signal, op->instance, 
            SMA_ASIO_RESULT_FILE_NOT_FOUND, op->totalLen);
        return;
    } /* if */

    op->totalLen = 0;
    op->pos = op->buffer;
    op->dataLen = bufSize;
    doRead(op);
} /* smaAsyncReadContinue */

/*!
 * \brief Terminate the Async FSM.
 * 
 * \param fsm       FSM originally ordering the termination
 * \param signal    Response signal ID
 * \param instance  FSM instance
 *****************************************************************************/

/*!
 * \brief Takes care of a TERMINATE signal
 *****************************************************************************/
void smaAsyncTerminate(void)
{
    SmaAsyncOperation *anOper = myOperationPool;
    SmaAsyncOperation *next = NULL;

    myOperationPool = NULL;
    myPoolSize = 0;
    
    while (anOper != NULL)
    {
        next = anOper->next;
        SMA_FREE(anOper);
        anOper = next;
    } /* while */

    smaSignalDeregister( SMA_FSM_ASYNC);
} /* smaAsyncTerminate */


/*!
 * \brief Start a new write operation
 *
 * A write operation is started. The write operation will continue until
 * bufSize bytes is written. At this time, the write operation will stop 
 * and send SMA_RESULT_OK to the caller.
 *
 * \param oper Handle to an async operation
 * \param startPos At what position in the file that the write will start,
 *        -1 indicates append.
 * \param buffer Data to write to file
 * \param bufSize Size of the buffer where to fetch data to write
 *****************************************************************************/
void smaAsyncWrite(SmaAsyncOperationHandle oper, MSF_INT32 startPos, void *buffer, 
    MSF_UINT32 bufSize)
{
    SmaAsyncOperation *op = (SmaAsyncOperation *)oper;

    if (op == NULL || op->state != OPER_STATE_OPENED)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SAASYNC_43DC7120C388CADADC82B3703E7A5021, "%s(%d): Wrong handle or state for write, op=%d, state=%d\n", 
            __FILE__, __LINE__, op, op == NULL ? -1 : op->state));

        return;
    }
    else if (op->fileHandle < 0)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SAASYNC_BB181C4C2CE439187166ABD22B9ACB3D, "%s(%d): File was not opened, check previous errors, op=%d, state=%d\n", 
            __FILE__, __LINE__, op, op == NULL ? -1 : op->state));

        (void)SMA_SIGNAL_SENDTO_IUU( op->fsm, op->signal, op->instance, 
            SMA_ASIO_RESULT_FILE_NOT_FOUND, op->totalLen);
        return;
    } /* if */

    /* OK, file is opened. Prepare for reading */
    op->totalLen = 0;
    op->pos = buffer;
    op->buffer = buffer;
    op->dataLen = bufSize;

    doSeek(op, startPos);
    doWrite(op);
} /* asyncWrite */

/*!
 * \brief Continues a previously started write operation
 *
 * A write operation has been stopped with type BUFFER_EMPTY. The caller 
 * indicates that more data to write is available in the buffer. The writing
 * will continue from the current file position.
 *
 * \param oper Handle to an async operation
 *****************************************************************************/
void smaAsyncWriteContinue(SmaAsyncOperationHandle oper, MSF_UINT32 bufSize)
{
    SmaAsyncOperation *op = (SmaAsyncOperation *)oper;

    if (op == NULL || op->state != OPER_STATE_OPENED)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SAASYNC_358A5A2A195321741A74C1789913DCBE, "%s(%d): Wrong handle or state for writeContinue, op=%d, state=%d\n", 
            __FILE__, __LINE__, op, op == NULL ? -1 : op->state));

        return;
    }
    else if (op->fileHandle < 0)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SAASYNC_BB181C4C2CE439187166ABD22B9ACB3D, "%s(%d): File was not opened, check previous errors, op=%d, state=%d\n", 
            __FILE__, __LINE__, op, op == NULL ? -1 : op->state));

        (void)SMA_SIGNAL_SENDTO_IUU( op->fsm, op->signal, op->instance, 
            SMA_ASIO_RESULT_FILE_NOT_FOUND, op->totalLen);
        return;
    } /* if */

    op->totalLen = 0;
    op->pos = op->buffer;
    op->dataLen = bufSize;
    doWrite(op);
} /* asyncWriteContinue */

/*!
 * \brief Do the actual read
 *
 * \param op Data for an async operation
 *****************************************************************************/
static void doRead(SmaAsyncOperation *op)
{
    int ret;
    long length;

    length = op->buffer - op->pos + (long)op->dataLen;

    /* File is opened and we're positioned so we can start to read */
    for (;;)
    {
        if (length <= 0) /* We have read everything that we should */
        {
            (void)SMA_SIGNAL_SENDTO_IUU( op->fsm, op->signal, op->instance, 
                SMA_RESULT_OK, op->totalLen);
            return;
        } /* if */

        ret = MSF_FILE_READ( op->fileHandle, op->pos, length);
        switch (ret)
        {
        case 0 :
        case MSF_FILE_ERROR_EOF :
            (void)SMA_SIGNAL_SENDTO_IUU( op->fsm, op->signal, op->instance, 
                SMA_ASIO_RESULT_EOF, op->totalLen);
            return;

        case MSF_FILE_ERROR_ACCESS :
            MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                SAASYNC_E92995BC353D6D26B6BBD3A731CEBB77, "%s(%d): Read returned %d\n", __FILE__, __LINE__, ret));

            (void)SMA_SIGNAL_SENDTO_IUU( op->fsm, op->signal, op->instance, 
                translateFileError(ret), op->totalLen);
            return;

        case MSF_FILE_ERROR_DELAYED :
            MSF_FILE_SELECT( op->fileHandle, MSF_FILE_EVENT_READ);
            return;

        default :
            if (ret < 0)
            {
                MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                    SAASYNC_D4FD45BD4DCDB884139BD7371682204F, "%s(%d): Unhandled file error %d\n",
                    __FILE__, __LINE__, ret));
                (void)SMA_SIGNAL_SENDTO_IUU( op->fsm, op->signal, op->instance, 
                    translateFileError(ret), op->totalLen);

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
static void doSeek(const SmaAsyncOperation *op, MSF_INT32 startPos)
{
    int seekMode;
    long seekOffset;
    long ret;

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

    if ((ret = MSF_FILE_SEEK( op->fileHandle, seekOffset, seekMode)) < 0)
    {
        (void)SMA_SIGNAL_SENDTO_IUU( op->fsm, op->signal, op->instance, 
            translateFileError(ret), op->totalLen);

        MSF_LOG_MSG_OFF(( MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, 
            SAASYNC_233C80169081FC2385D6F959C3201D4A, "%s(%d): Failed to seek file %d, mode=%d, pos=%d, ret=%d\n", 
            __FILE__, __LINE__, op->fileHandle, seekMode, seekOffset, ret));

        return;
    } /* if */
} /* doSeek */

/*!
 * \brief Do the actual write
 *
 * \param op Data for an async operation
 *****************************************************************************/
static void doWrite(SmaAsyncOperation *op)
{
    int ret;
    int length;

    length = op->buffer - op->pos + (long)op->dataLen;

    /* File is opened and we're positioned so we can start to write */
    for (;;)
    {
        if (length <= 0)    /* Have we written everything from the buffer? */
        {
            (void)SMA_SIGNAL_SENDTO_IUU( op->fsm, op->signal, op->instance, 
                SMA_RESULT_OK, op->totalLen);
            return;
        } /* if */

        ret = MSF_FILE_WRITE( op->fileHandle, op->pos, length);
        switch (ret)
        {
        case 0 :
        case MSF_FILE_ERROR_EOF :
        case MSF_FILE_ERROR_ACCESS :
        case MSF_FILE_ERROR_FULL :
            MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                SAASYNC_9AA9D6B0B8AF1672098ECCDE8BEBE5DE, "%s(%d): Write returned %d\n", __FILE__, __LINE__, ret));

            (void)SMA_SIGNAL_SENDTO_IUU( op->fsm, op->signal, op->instance, 
                translateFileError(ret), op->totalLen);
            return;

        case MSF_FILE_ERROR_DELAYED :
            MSF_FILE_SELECT( op->fileHandle, MSF_FILE_EVENT_WRITE);
            return;

        default :
            if (ret < 0)
            {
                MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                    SAASYNC_D4FD45BD4DCDB884139BD7371682204F, "%s(%d): Unhandled file error %d\n",
                    __FILE__, __LINE__, ret));
                (void)SMA_SIGNAL_SENDTO_IUU( op->fsm, op->signal, op->instance, 
                    translateFileError(ret), op->totalLen);

                return; 
            } /* if */

            op->totalLen += (MSF_UINT32)ret;
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
    SmaAsyncOperation *anOper = myOperationPool;

    if (anOper == NULL)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SAASYNC_1B0754A6338F4F2DC7B0EFA93E946749, "%s(%d): Couldn't find handle\n", __FILE__, __LINE__));

        return;
    } /* if */

    while (anOper != NULL)
    {   /* Only opened files can cause NOTIFY signals */
        if (anOper->state == OPER_STATE_OPENED && 
            anOper->fileHandle == fileHandle)
        {
            switch (operationType)
            {
            case MSF_FILE_READ_READY :
                doRead(anOper);
                break;
            case MSF_FILE_WRITE_READY :
                doWrite(anOper);
                break;
            default :
                MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                    SAASYNC_5AAD0A2BE0991231D47AB9A0A5FCD32C, "%s(%d): Illegal operationType %d\n", __FILE__, __LINE__,
                    operationType));
                break;
            } /* switch */

            return;
        } /* if */

        anOper = anOper->next;
    } /* while */

    
} /* handleNotify */


/*!
 * \brief Translates an MSF File Error to an MMS Result
 *
 * \param fileError Error as given from call to MSF FILE function
 *****************************************************************************/
static SmaAsioResult translateFileError(int fileError)
{
    SmaAsioResult ret = SMA_ASIO_RESULT_ERROR;

    switch (fileError)
    {
    case MSF_FILE_OK :
        ret = SMA_ASIO_RESULT_OK;
        break;
    case MSF_FILE_ERROR_ACCESS : /* e.g. file opened in wrong mode */
        ret = SMA_ASIO_RESULT_ERROR;
        break;
    case MSF_FILE_ERROR_PATH :
        ret = SMA_ASIO_RESULT_FILE_NOT_FOUND;
        break;
    case MSF_FILE_ERROR_INVALID : /* e.g. illegal file name */
        ret = SMA_ASIO_RESULT_ERROR;
        break;
    case MSF_FILE_ERROR_SIZE :
        ret = SMA_ASIO_RESULT_INSUFFICIENT_PERSISTENT_STORAGE;
        break;
    case MSF_FILE_ERROR_FULL :
        ret = SMA_ASIO_RESULT_INSUFFICIENT_PERSISTENT_STORAGE;
        break;
    case MSF_FILE_ERROR_EOF :
        ret = SMA_ASIO_RESULT_EOF;
        break;
    default :
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SAASYNC_F04A54693E8FD2C3774261A6897AE790, "%s(%d): Unknown fileError %d\n", __FILE__, __LINE__,
            fileError));
        break;
    } /* switch */

    return ret;
} /* translateFileError */



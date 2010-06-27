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

/*! \file maasync.h
 * \brief Definitions needed for the Asynchronous File API wrapping state 
 *        machine.
 */

#ifndef _MAASYNC_H_
#define _MAASYNC_H_

/*--- Definitions/Declarations ---*/

/*--- Types ---*/
typedef void* MeaAsyncOperationHandle;

/*! \enum MeaAsyncMode
 *  Read-write mode for an asynchronous operation.
 */
typedef enum
{
    MEA_ASYNC_MODE_READ,
    MEA_ASYNC_MODE_WRITE,
    MEA_ASYNC_MODE_APPEND,
    MEA_ASYNC_MODE_READ_WRITE,
    MEA_ASYNC_MODE_DISPATCH
} MeaAsyncMode;

/**********************************************************************
 * Here is signals handled by the Async FSM.
 *
 * The values in this enum corresponds to the second parameter in the
 * MEA_SIGNAL_SENDTO macros.
 **********************************************************************/
/*!\enum MeaAsyncSignalId Signals used with the Async FSM */
typedef enum
{
#ifdef WAP_SUPPORT
    /*! Call to MSF_PIPE_SELECT has trigged an event
     *  - Param I : eventType
     *  - Param U1: pipeHandle that the event is related to
     *  - Param U2: -
     *  - Param P : -
     */
    MEA_SIG_ASYNC_PIPE_NOTIFY,
    MEA_SIG_ASYNC_PIPE_FILE_READ_RSP,
    MEA_SIG_ASYNC_PIPE_COPY_COMPLETE,
    MEA_SIG_ASYNC_PIPE_WRITE_PIPE,
#endif /* WAP_SUPPORT */
    /*! Call to MSF_FILE_SELECT has triggered an event
     *  - Param I : eventType (MSF_FILE_READ_READY or MSF_FILE_WRITE_READY)
     *  - Param U1: fileHandle that the event is related to
     *  - Param U2: -
     *  - Param P : -
     */
    MEA_SIG_ASYNC_NOTIFY
}MeaAsyncSignalId;

/*!\enum MeaAsioResult Result codes from ASIO FSM */
typedef enum
{
    MEA_ASIO_RESULT_OK,
    MEA_ASIO_RESULT_EOF,
    MEA_ASIO_RESULT_ERROR,
    MEA_ASIO_RESULT_DELAYED,
    MEA_ASIO_RESULT_FILE_NOT_FOUND,
    MEA_ASIO_RESULT_INSUFFICIENT_PERSISTENT_STORAGE
}MeaAsioResult;

/*--- Constants ---*/

/*! 
 *  This define is used to determine the size of the buffer used when
 *  performing a Async IO copy between two files 
 */
#define MEA_ASIO_COPY_BUFFER_SIZE 1024

/*--- Forwards ---*/

/*--- Externs ---*/

/*--- Macros ---*/

/*--- Prototypes ---*/
MSF_BOOL meaAsyncInit(void);
#ifdef MMS_SLIM_MEM
MSF_BOOL meaCreatePipeOperation(const char *pipeName);
void meaCopyFileToPipe(const char* pipeName, const char *fileName, MSF_UINT32 offset, MSF_UINT32 size);
#endif /* MMS_SLIM_MEM */
MeaAsyncOperationHandle meaAsyncOperationStart(const char *fileName, 
    MeaStateMachine fsm, long instance, MSF_UINT32 signal, MeaAsyncMode mode);
void meaAsyncOperationStop(MeaAsyncOperationHandle *oper);
void meaAsyncRead(MeaAsyncOperationHandle oper, MSF_INT32 startPos,
    void *buffer, MSF_UINT32 bufSize);
void meaAsyncReadContinue(MeaAsyncOperationHandle oper, MSF_UINT32 bufSize);
void meaAsyncDeregister(int fileHandle);
void meaAsyncRegister(int fileHandle, int fsm, int signal, int instance);
void meaAsyncTerminate(void);
void meaAsyncWrite(MeaAsyncOperationHandle oper, MSF_INT32 startPos, 
                   void *buffer, MSF_UINT32 bufSize);
void meaAsyncWriteContinue(MeaAsyncOperationHandle oper, MSF_UINT32 bufSize);
#endif /* _MAASYNC_H */



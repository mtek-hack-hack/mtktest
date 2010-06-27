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

/*! \file saasync.h
 * \brief Definitions needed for the Asynchronous File API wrapping state machine.
 */

#ifndef _SAASYNC_H
#define _SAASYNC_H

#ifndef _SAINTSIG_H
#error saintsig.h must be included berfore saasync.h!
#endif

/*--- Definitions/Declarations ---*/

/*--- Types ---*/
typedef void* SmaAsyncOperationHandle;

/*! \enum AsyncMode
 *  Read-write mode for an asynchronous operation.
 */
typedef enum
{
    SMA_ASYNC_MODE_READ,
    SMA_ASYNC_MODE_WRITE,
    SMA_ASYNC_MODE_READ_WRITE
} SmaAsyncMode;

/* Result codes from ASIO FSM */
typedef enum
{
    SMA_ASIO_RESULT_OK,
    SMA_ASIO_RESULT_EOF,
    SMA_ASIO_RESULT_ERROR,
    SMA_ASIO_RESULT_DELAYED,
    SMA_ASIO_RESULT_FILE_NOT_FOUND,
    SMA_ASIO_RESULT_INSUFFICIENT_PERSISTENT_STORAGE
}SmaAsioResult;

/**********************************************************************
 * Here is signals handled by the Asynch FSM.
 *
 * The values in this enum corresponds to the second parameter in the
 * M_SIGNAL_SENDTO macros.
 **********************************************************************/
/*! \enum SmaAsyncSignalId Signals used with the Async FSM */
typedef enum
{
    /*! Call to MSF_FILE_SELECT has trigged an event
     *  - Param I : eventType (MSF_FILE_READ_READY or MSF_FILE_WRITE_READY)
     *  - Param U1: fileHandle that the event is related to
     *  - Param U2: -
     *  - Param P : -
     */
    SMA_SIG_ASYNC_NOTIFY
} SmaAsyncSignalId;

/*--- Constants ---*/

/*--- Forwards ---*/

/*--- Externs ---*/

/*--- Macros ---*/

/*--- Prototypes ---*/
void smaAsyncEmergencyAbort(void);
MSF_BOOL smaAsyncInit(void);
SmaAsyncOperationHandle smaAsyncOperationStart(const char *fileName, 
    SmaStateMachine fsm, long instance, int signal, SmaAsyncMode mode);
void smaAsyncOperationStop(SmaAsyncOperationHandle *oper);
void smaAsyncRead(SmaAsyncOperationHandle oper, MSF_INT32 startPos,
    void *buffer, MSF_UINT32 bufSize);
void smaAsyncReadContinue( SmaAsyncOperationHandle oper, MSF_UINT32 bufSize);
void smaAsyncTerminate(void);
void smaAsyncWrite( SmaAsyncOperationHandle oper, MSF_INT32 startPos, void *buffer, 
    MSF_UINT32 bufSize);
void smaAsyncWriteContinue(SmaAsyncOperationHandle oper, MSF_UINT32 bufSize);

#endif /* _MASYNC_H */



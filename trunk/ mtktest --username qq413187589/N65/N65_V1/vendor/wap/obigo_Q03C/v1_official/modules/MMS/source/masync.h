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





#ifndef _MASYNC_H
#define _MASYNC_H




typedef void* AsyncOperationHandle;




typedef enum
{
    ASYNC_MODE_READ,
    ASYNC_MODE_WRITE,
    ASYNC_MODE_READ_WRITE
} AsyncMode;








typedef enum
{
    





    MMS_SIG_ASYNC_NOTIFY,

    





    MMS_SIG_ASYNC_INT_TERMINATE

    







    

    







    
} MmsAsyncSignalId;










void asyncEmergencyAbort(void);
MSF_BOOL asyncInit(void);
AsyncOperationHandle asyncOperationStart(const char *fileName, 
    MmsStateMachine fsm, long instance, MSF_UINT32 signal, AsyncMode mode);
void asyncOperationStop(AsyncOperationHandle *oper);
void asyncRead(AsyncOperationHandle oper, MSF_INT32 startPos,
    void *buffer, MSF_UINT32 bufSize);
void asyncReadContinue(AsyncOperationHandle oper, MSF_UINT32 bufSize);
void asyncTerminate( MmsStateMachine fsm, MSF_UINT32 signal, long instance);
void asyncWrite(AsyncOperationHandle oper, MSF_INT32 startPos, void *buffer, 
    MSF_UINT32 bufSize);
void asyncWriteContinue(AsyncOperationHandle oper, MSF_UINT32 bufSize);

#endif 



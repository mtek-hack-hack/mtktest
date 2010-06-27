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





#ifndef _MCGET_H
#define _MCGET_H












typedef enum
{
    





    MMS_SIG_COH_GET_CANCEL,

    





    MMS_SIG_COH_GET_MSG,

    





    MMS_SIG_COH_GET_RSP,

    







    

    


    MMS_SIG_COH_GET_CONNECTED,

    


    MMS_SIG_COH_GET_DISCONNECTED,

    





    MMS_SIG_COH_GET_DATA_COLLECTED,

    






    MMS_SIG_COH_GET_PIPE_NOTIFY,

    


    M_FSM_COH_GET_ASYNC_WRITE_FINISHED
} MmsCohGetSignalId;



typedef struct
{
    MmsMsgId        msgId;          
    char            *path;          
    char            *uri;           
    char            *transactionId; 
    unsigned long   size;           
    MSF_BOOL        isImmediate;    
} MmsSigCohGetParam;



typedef struct
{
    MmsMsgId        msgId;          
    MmsResult       result;         
    unsigned long   size;           
    char            *transactionId; 
} MmsSigCohGetResultParam;










void cohGetCancel(MmsMsgId msgId);
void cohGetEmergencyAbort(void);
void cohGetInit(void);
long cohGetInstance(MmsRequestId id);
MSF_BOOL cohGetIsPipeOwner(int handle);
void cohGetTerminate(void);

#endif 



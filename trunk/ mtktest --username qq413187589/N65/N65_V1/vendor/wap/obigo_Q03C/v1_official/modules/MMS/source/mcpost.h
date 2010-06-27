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





#ifndef _MCPOST_H
#define _MCPOST_H






typedef enum
{
    





    MMS_SIG_COH_POST,

    





    MMS_SIG_COH_POST_RSP,

    





    MMS_SIG_COH_POST_DATA_COLLECTED,

    






    MMS_SIG_COH_POST_PIPE_NOTIFY,

    





    MMS_SIG_COH_POST_CANCEL,

    







    

    


    MMS_SIG_COH_POST_ASYNC_READ_FINISHED,
    
    


    MMS_SIG_COH_POST_CONNECTED,

    


    MMS_SIG_COH_POST_DISCONNECTED
} MmsCohPostSignalId;




typedef struct
{
    unsigned long   length; 
    unsigned char   *packet;
} MmsCohPostPduParam;




typedef struct
{
    long   responseStatus; 
    char*       responseText;
} MmsCohPostResponseParam;



typedef struct
{
#ifdef __MMS_DUAL_SIM_SUPPORT__
    MmsSimCardEnum simId;
#endif
    
    MSF_BOOL        isResponseRequested;
    MmsMessageType  type;   
    union
    {
        MmsMsgId            msgId;  
        MmsCohPostPduParam  pdu;    
    } data;
} MmsSigCohPostParam;










void cohPostCancel(MmsMsgId msgId);
void cohPostEmergencyAbort(void);
void cohPostInit(void);
long cohPostInstance(MmsRequestId id);
MSF_BOOL cohPostIsPipeOwner(int handle);
void cohPostMore(long instance);
void cohPostTerminate(void);

#endif 



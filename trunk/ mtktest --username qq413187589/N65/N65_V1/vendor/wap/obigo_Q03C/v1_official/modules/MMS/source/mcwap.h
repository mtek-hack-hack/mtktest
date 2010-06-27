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





#ifndef _MCWAP_H
#define _MCWAP_H






typedef enum
{
    MMS_COMM_GET,   
    MMS_COMM_POST   
} MmsCommMethod;



typedef struct
{
    
    MmsRequestId id;    
    
    
    MmsResult errorNo;
    
    
    MSF_INT16 dataType;

    
    MSF_INT32 dataLen;      
    
    
    union
    {
        char *fileName;
        char *pipeName;
        char *buffer;
    } data;
} MmsHttpContent;


typedef enum
{
    





    MMS_SIG_COH_WAP_START,

    





    MMS_SIG_COH_WAP_START_RESPONSE,

    





    MMS_SIG_COH_WAP_STOP,

    





    MMS_SIG_COH_WAP_STOP_RESPONSE

    







    

    







    
} MmsCohWapSignalId;




#ifdef __MMS_DUAL_SIM_SUPPORT__
void mmsWapChannelDisconnect(MSF_UINT32 simId);
void mmsWapHttpGet(MSF_UINT32 simId, MmsRequestId requestId, const char *uri);
void mmsWapHttpPostFile(MSF_UINT32 simId, MmsRequestId requestId, const char *uri, char *fileName);
void mmsWapHttpPostPipe(MSF_UINT32 simId, MmsRequestId requestId, const char *uri, char *pipeName, 
    MSF_INT32 dataLen);
void mmsWapHttpPostPdu(MSF_UINT32 simId, MmsRequestId requestId, const char *uri, void *pdu, 
    MSF_INT32 size);
void mmsWapRemoveStartReqFromWaitingQueue(MSF_INT32 fsm, long instance);
MSF_INT32 mmsWapIsUsingBearer(void);
#else
void mmsWapChannelDisconnect(void);
long mmsWapGetTransactionId(void);
void mmsWapHttpGet(MmsRequestId requestId, const char *uri);
void mmsWapHttpPostFile(MmsRequestId requestId, const char *uri, char *fileName);
void mmsWapHttpPostPipe(MmsRequestId requestId, const char *uri, char *pipeName, 
    MSF_INT32 dataLen);
void mmsWapHttpPostPdu(MmsRequestId requestId, const char *uri, void *pdu, 
    MSF_INT32 size);
#endif /*__MMS_DUAL_SIM_SUPPORT__*/



void mmsWapChannelIsDisconnected(void);
void mmsWapConnectionCheck(void);
void mmsWapEmergencyAbort(void);
MmsRequestId mmsWapGetRequestId(void);
long mmsWapGetTransactionId(void);
void mmsWapFreeContentParams(MmsHttpContent *cont);
void mmsWapHttpCancel(MmsRequestId requestId);
void mmsWapHttpResponse(MmsRequestId id, MSF_INT16 status, MSF_INT16 dataType, 
    MSF_INT32 dataLen, void *data);
void mmsWapInit(void);
void mmsWapTerminate(void);
MmsResult mmsWapTranslateError(MSF_INT32 error);
MmsResult mmsWapTranslateResponseStatus(MmsResponseStatus status);
MmsResult mmsWapTranslateRetrieveStatus(MmsRetrieveStatus status);

#endif 



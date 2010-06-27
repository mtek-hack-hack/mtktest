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





#ifndef _MNOTIFY_H
#define _MNOTIFY_H





typedef enum
{
    






    MMS_SIG_MSR_NOTIFICATION,

    MMS_SIG_MSR_NOTIFY_FILE_CREATED,
        
    


    MMS_SIG_MSR_NOTIFY_ASYNC_WRITE_FINISHED,

    

    MMS_SIG_MSR_NOTIFY_MMT_RSP
} MmsNotifySignalId;



typedef struct
{
#ifdef __MMS_DUAL_SIM_SUPPORT__
    MmsSimCardEnum simId;
#endif
    MSF_BOOL isSmsBearer;
    MmsStatus msgStatus;
    unsigned int deliveryReportFlag;
    char *transactionId;
    MmsVersion version;
} MmsNotifIndInfo;









void msrNotifyEmergencyAbort(void);
void msrNotifyTerminate(void);
void msrNotifyInit(void);
#ifdef __MMS_DUAL_SIM_SUPPORT__
void sendNotifyIndRsp( MmsSimCardEnum simId, MSF_BOOL isSmsBearer, const char *trId, MmsStatus mgsStatus,
    MmsClassIdentifier msgClass, MmsVersion version);
#else
void sendNotifyIndRsp( MSF_BOOL isSmsBearer, const char *trId, MmsStatus mgsStatus,
    MmsClassIdentifier msgClass, MmsVersion version);
#endif
MmsResult mmsPromoteNotifToDelayed(MSF_UINT32 notifId);

#endif 



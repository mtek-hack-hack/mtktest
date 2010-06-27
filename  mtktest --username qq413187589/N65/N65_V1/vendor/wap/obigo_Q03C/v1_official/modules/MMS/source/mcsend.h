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





#ifndef _MCSEND_H
#define _MCSEND_H












typedef enum
{
    





    MMS_SIG_COH_SEND,

    


    MMS_SIG_COH_SEND_POST_RSP
} MmsCohSendSignalId;



typedef struct
{   
    MmsMsgId    msgId;      
} MmsSigCohSendParam;










void cohSendEmergencyAbort(void);
void cohSendInit(void);
void cohSendTerminate(void);

#endif 



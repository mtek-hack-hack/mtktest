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





#ifndef _MMS_CONT_H
#define _MMS_CONT_H












typedef enum
{
    





    MMS_SIG_CONT_START,

    





    MMS_SIG_CONT_NOTIF
} MmsContSignalId;










void contEmergencyAbort(void);
void contInit(void);
void contTerminate(void);
void contQueue(msf_content_data_t* sig);
void contDeQueue(void);

#endif 



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
 




#ifndef _MMAIN_H
#define _MMAIN_H


#define MMS_MAIN_FIRST_START_ELEMENT        1
#define MMS_MAIN_FIRST_TERMINATE_ELEMENT    1







typedef enum
{
    






    MMS_SIG_MAIN_START,

    






    MMS_SIG_MAIN_TERMINATE,

    





    MMS_SIG_MAIN_EXECUTE_COMMAND
} MmsCoreMainSignalId;










void coreMainEmergencyAbort(void);
void coreMainInit(void);
void coreMainTerminate(void);

#endif 



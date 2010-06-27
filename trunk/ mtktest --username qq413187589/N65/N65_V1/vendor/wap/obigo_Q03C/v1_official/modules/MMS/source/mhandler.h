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





#ifndef _MMHANDLER_H
#define _MMHANDLER_H




typedef enum
{
    







    M_FSM_MMH_GET_HEADER,
  
    






    M_FSM_MMH_INT_CREATE_INFO_LIST,

    






    M_FSM_MMH_CREATE_INFO_LOOP,

    






    M_FSM_MMH_CREATE_INFO_LIST,
     
    







     M_FSM_MMH_READ_HDR_FINISHED,
      
    





     M_FSM_MMH_CREATE_RR,

    







     M_FSM_MMH_MSG_RR_CREATED,

    






     M_FSM_MMH_RR_WRITE,

    




     
     M_FSM_MMH_RR_INFO_FILE_CREATED,
 
    





 
     M_FSM_MMH_CREATE_RR_GOT_HEADER,

    






 
    M_FSM_MMH_GOT_REPORT

} MmsMmhSignalId;












void mmhEmergencyAbort(void);
void mmhInit(void);
void mmhTerminate(void);
MmsResult mmhCreateInfoList( MSF_UINT32 msgId, long instance);
void sendReportWithError(MmsFileType fileType, MmsResult res); 

#endif 



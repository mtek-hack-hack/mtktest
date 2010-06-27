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





#ifndef _FLDMGR_H
#define _FLDMGR_H



typedef enum
{
    STATE_FOLDER_STOPPED = 0,   
        STATE_FOLDER_IDLE,          
        STATE_FOLDER_READING,       
        STATE_FOLDER_WRITING,       
        STATE_FOLDER_RESTORING,     
        STATE_FOLDER_TERMINATING    
} MmsFmState;


#define MMS_FILE        "mms"             
#define MMS_MMTTMP      "mms.tp"          
#define MMS_MMTBACK     "mms.bk"             
#define MMS_MMT         "mms.cn"          
#define MMS_INFO_SUFFIX "i"               
#define MMS_MESSAGE_SUFFIX "m"            
#define MMS_FOLDER      "/mms/"          
#define MMS_MMT_BACKUP_FILE MMS_FOLDER MMS_MMTBACK  
#define MMS_MMT_TMP_FILE MMS_FOLDER MMS_MMTTMP 
#define MMS_MMT_FILE    MMS_FOLDER MMS_MMT  
#define MMS_FILE_LEN    13                
#define MMS_PATH_LEN    (sizeof(MMS_FOLDER) + MMS_FILE_LEN)   



typedef struct
{
    MmsFileType     suffix;     
    MmsFolderType   location;   
    MSF_UINT32      size;       
#ifdef __MMS_DUAL_SIM_SUPPORT__
    MmsSimCardEnum simId;
#endif
} MmsFmgCreateParam;



typedef struct
{
    MmsMsgId   msgId;   
} MmsFmgDeleteParam;



typedef enum
{
    


    M_FSM_MMT_OPERATION_FINISHED,
   
    





    MMS_SIG_FMG_TERMINATE,

    

    MMS_SIG_FMG_CREATE_MSG,
    
    



    MMS_SIG_FMG_MOVE_MSG, 
    
    


    MMS_SIG_FMG_DELETE_MSG, 
    
    





    MMS_SIG_FMG_GET_LIST, 

    


    MMS_SIG_FMG_GET_MSG_INFO,

    


    MMS_SIG_FMG_GET_NO_MSG,




    
    



  
    MMS_SIG_FMG_INT_CLEAN_UP, 
    
    


    MMS_SIG_FMG_INT_NOTIF_WRITE_MMT,

    

    MMS_SIG_FMG_INT_WRITE_MMT,

    

    MMS_SIG_FMG_INT_MMT_RESTORE, 

    





    MMS_SIG_FMG_INT_CREATE_MSG,

    





    MMS_SIG_FMG_INT_DELETE_MSG,

    







    MMS_SIG_FMG_INT_INF_DONE,

    





 
    MMS_SIG_FMG_INT_NOTIF_DONE,

    





 
    MMS_SIG_FMG_INT_RR_PDU_RESTORE,
    
    





 
    MMS_SIG_FMG_INT_DR_RESTORE

    







    

    







    

    







    

    







    
} MmsFldrMgrSignalId;










void fldrEmergencyAbort(void);
void fldrInit(void);
MmsFmState fldrGetWorkingState(void);
char *fldrMsgId2Name(MSF_UINT32 msgId, MmsFileType suffix);

void fldrTerminate( MmsStateMachine fsm, MSF_UINT32 signal, long instance);

MSF_BOOL fldrSetServerMsgId(MmsMsgId msgId, const char *serverMsgId);

void fldrMgrSetHeader(MmsMsgId msgId, const MmsGetHeader *mhead, MSF_UINT32 mFileSize,
                        const char *messageId);

void fldrMgrSetReadMark(MmsMsgId msgId, MSF_UINT8 value);

MSF_BOOL checkMsgId(MSF_UINT32 msgId);

MmsResult moveMessage(MSF_UINT32 folder, MSF_UINT32 msgId);

MmsFileType fldrGetFileSuffix(MmsMsgId msgId);

MSF_UINT32 fldrGetMsgSize(MmsMsgId msgId);

MmsFolderType fldrGetFolderId(MmsMsgId msgId);

void fldrMgrSetNotify(MmsMsgId msgId, const MmsNotification *mmsNotification,
                    MSF_UINT32 mFileSize);

unsigned char *fldrGetServerMsgId(MmsMsgId msgId);

MSF_UINT32 fldrUpdateMmtDelReport (MSF_UINT32 msgId, const char *srvMsgId, 
	const char *addr, MSF_UINT32 date, MSF_UINT32 size);

MSF_UINT32 fldrUpdateMmtReadReport(MSF_UINT32 msgId, 
    const MmsReadOrigInd *mmsOrigInd, MSF_UINT32 size);

MSF_UINT32 fldrMgrSearchMsgId(MSF_UINT32 startMsgId, const char *srvMsgId, MmsFileType suffix);

void fldrMgrSetDRsent(MSF_UINT32 msgId);

void fldrMgrSetRRsent(MSF_UINT32 msgId);

#ifdef __MMS_DUAL_SIM_SUPPORT__
MSF_UINT32 fldrMgrSearchImmNotif(MSF_BOOL skip_sim1, MSF_BOOL skip_sim2);
#else
MSF_UINT32 fldrMgrSearchImmNotif(void);
#endif      


MSF_UINT32 mmsCountNotifInQueue(void);

MmsFileType getMsgType (MSF_UINT32 msgId);

void fldrGetFolderStatus(MSF_UINT32 *usedMsgBytes, MSF_UINT32 *numOfMsg, 
      MSF_UINT32 *totalFolderSize, MSF_UINT32 folderMask);

MSF_UINT32 fldrGetNoOfFreeMsg(void);

void createFolder( void);

void fldrGetInboxStatus(MSF_UINT32 *numOfMsg,   MSF_UINT32 *numOfUnreadMsg,
                        MSF_UINT32 *numOfNotif, MSF_UINT32 *numOfUnreadNotif,
                        MSF_UINT32 *numOfRR,    MSF_UINT32 *numOfUnreadRR,
                        MSF_UINT32 *numOfDR,    MSF_UINT32 *numOfUnreadDR);




#ifdef __MMS_DUAL_SIM_SUPPORT__
void fldrMgrGetNumberOfMessagesExt(MSF_UINT16 folderId,
                               MSF_UINT16 *nMsgsMasterSim,
                               MSF_UINT16 *nUnreadMsgsMasterSim,
                               MSF_UINT16 *nMsgsSlaveSim,
                               MSF_UINT16 *nUnreadMsgsSlaveSim,
                               MSF_UINT16 *nMsgs,
                               MSF_UINT16 *nUnreadMsgs);
#endif /*__MMS_DUAL_SIM_SUPPORT__*/
void fldrMgrGetNumberOfMessages(MSF_UINT16 folderId,
                                MSF_UINT16 *nMsgs,
                                MSF_UINT16 *nUnreadMsgs);
MmsResult fldrMgrDeleteMessage(MSF_UINT32 msgId);

MmsResult mmsChangeMsgType(MSF_UINT32 msgId, MmsFileType newSuffix);
MmsResult mmsFldrMgrSetFolderQuiet(MSF_UINT32 msgId, MSF_UINT32 folder);

void mmsShowAllImmediateNotif(void);
#ifdef __MMS_DUAL_SIM_SUPPORT__
MmsSimCardEnum fldrGetMessageSimId(MSF_UINT32 msgId);
MSF_BOOL fldrChangeMessageSimId(MSF_UINT32 msgId, MmsSimCardEnum simId);
#endif

#endif 


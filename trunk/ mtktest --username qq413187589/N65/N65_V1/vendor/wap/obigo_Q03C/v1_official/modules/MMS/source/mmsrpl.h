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











#ifndef _MMSRPL_H
#define _MMSRPL_H






          



























void replyCreateMessageResponse(MmsResult result, MmsMsgId msgId);













void replyDeleteMessageResponse(MmsResult result);














void replyGetNumberOfMessagesResponse(MmsResult result, MSF_UINT32 number, 
    MmsFolderType folder);













void replyMoveMessageResponse(MmsResult result);


















void replyNotificationReceived(MmsNotificationType type, MmsMsgId notifId,
                               MmsAddress *from, MmsEncodedText *subject, MSF_UINT32 size,
                               MmsNotificationReason reason);













void replyReadReportIndication(MmsReadOrigInd *mmsOrigInd, MSF_UINT32 msgId,
                               MSF_UINT32 msgIdFile);













void notifyReadReportIndication(MmsReadOrigInd *mmsOrigInd, MSF_UINT32 msgId,
                               MSF_UINT32 msgIdFile);













void replyRetrieveMessageResponse(MmsResult result, MmsMsgId msgId);













void replySendMessageResponse(MmsResult result,long responseStatus,char* responseText);













void replySendReadReportResponse(MmsResult result, MmsMsgId rrId, MmsMsgId msgId);




















void replyDeliveryReportReceived(char *serverMsgId, MmsAddress *to, 
                                MmsTimeSec date, MmsStatus status,
                                MSF_UINT32 msgId, MSF_UINT32 msgIdFile);






















void notifyDeliveryReportReceived(char *serverMsgId, MmsAddress *to, 
                                  MmsTimeSec date, MmsStatus status, MSF_UINT32 msgId, MSF_UINT32 msgIdFile);














void replyError(MmsResult result);













void replyForwardReqResponse(MmsResult result,long responseStatus,char* responseText);





void replyFolderContent(void  *ptr);





void replyMsgInfo(MSF_UINT8 modId, void  *ptr);






void replyProgressStatus(MSF_UINT8 operation, MSF_UINT8 state,
    MmsMsgId msgId,
    MSF_UINT32 progress, MSF_UINT32 totalLength,
    MSF_UINT32 *lastTime);












void replyCreateMessageDoneResponse(MmsResult result, MmsMsgId msgId);

#endif  

